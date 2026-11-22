<?php
header('Content-Type: application/json; charset=utf-8');
header('Access-Control-Allow-Origin: *');
header('Access-Control-Allow-Methods: POST, GET, OPTIONS');
header('Access-Control-Allow-Headers: Content-Type, Accept, X-Admin-Pass');

if ($_SERVER['REQUEST_METHOD'] === 'OPTIONS') {
    http_response_code(200);
    exit;
}

$ADMIN_USER = 'dark';
$ADMIN_PASS = 'wear5555';
$DATA_FILE  = __DIR__ . '/darkos_data.json';

function loadData($file) {
    if (!file_exists($file)) {
        $init = ['keys' => []];
        file_put_contents($file, json_encode($init, JSON_PRETTY_PRINT | JSON_UNESCAPED_UNICODE));
        return $init;
    }
    $raw = file_get_contents($file);
    $data = json_decode($raw, true);
    if (!is_array($data) || !isset($data['keys'])) {
        $data = ['keys' => []];
    }
    return $data;
}

function saveData($file, $data) {
    $fp = fopen($file, 'c+');
    if ($fp) {
        flock($fp, LOCK_EX);
        ftruncate($fp, 0);
        fwrite($fp, json_encode($data, JSON_PRETTY_PRINT | JSON_UNESCAPED_UNICODE));
        fflush($fp);
        flock($fp, LOCK_UN);
        fclose($fp);
    }
}

function addAudit(&$keyObj, $text) {
    if (!isset($keyObj['audit']) || !is_array($keyObj['audit'])) {
        $keyObj['audit'] = [];
    }
    array_unshift($keyObj['audit'], [
        'time' => date('Y-m-d H:i:s'),
        'text' => $text
    ]);
    $keyObj['audit'] = array_slice($keyObj['audit'], 0, 100);
}

function getClientIp() {
    if (!empty($_SERVER['HTTP_X_FORWARDED_FOR'])) {
        $parts = explode(',', $_SERVER['HTTP_X_FORWARDED_FOR']);
        return trim($parts[0]);
    }
    return $_SERVER['REMOTE_ADDR'] ?? '0.0.0.0';
}

function unitToSeconds($unit, $amount) {
    $n = max(1, (int)$amount);
    switch (strtolower($unit)) {
        case 'minute': case 'min': return $n * 60;
        case 'hour':   case 'h':   return $n * 3600;
        case 'day':    case 'd':   return $n * 86400;
        case 'week':   case 'w':   return $n * 604800;
        case 'month':  case 'm':   return $n * 2592000;
        case 'year':   case 'y':   return $n * 31536000;
        default:                   return $n * 86400;
    }
}

function unitCode($unit, $amount) {
    $n = max(1, (int)$amount);
    $map = ['minute'=>'MIN','hour'=>'H','day'=>'D','week'=>'W','month'=>'M','year'=>'Y'];
    return $n . ($map[strtolower($unit)] ?? 'D');
}

function checkAdmin($input, $user, $pass) {
    $u = $input['admin_user'] ?? ($_SERVER['HTTP_X_ADMIN_USER'] ?? '');
    $p = $input['admin_pass'] ?? ($_SERVER['HTTP_X_ADMIN_PASS'] ?? '');
    return ($u === $user && $p === $pass);
}

$rawBody = file_get_contents('php://input');
$input = json_decode($rawBody, true);
if (!is_array($input)) {
    $input = $_POST;
}

$action = $input['action'] ?? ($_GET['action'] ?? '');
$data = loadData($DATA_FILE);
$now = time();

// =========================================================================
// 1. iOS TWEAK LOGIN ENDPOINT (LicenseAuth.mm -> action: "player_login")
// =========================================================================
if ($action === 'player_login') {
    $keyStr   = trim((string)($input['key'] ?? ''));
    $deviceId = trim((string)($input['device_id'] ?? ''));
    $devName  = trim((string)($input['device_name'] ?? 'iOS Device'));
    $battery  = trim((string)($input['battery'] ?? ''));
    $location = trim((string)($input['location'] ?? ''));
    $ip       = getClientIp();

    if ($keyStr === '' || $deviceId === '') {
        echo json_encode(['success' => false, 'message' => 'Açar və ya cihaz ID boşdur.', 'remaining_seconds' => 0]);
        exit;
    }

    $foundIndex = -1;
    foreach ($data['keys'] as $idx => $k) {
        if (strcasecmp($k['key'], $keyStr) === 0) {
            $foundIndex = $idx;
            break;
        }
    }

    if ($foundIndex === -1) {
        echo json_encode(['success' => false, 'message' => 'Açar tapılmadı.', 'remaining_seconds' => 0]);
        exit;
    }

    $k = &$data['keys'][$foundIndex];

    // Status yoxlaması
    if (($k['status'] ?? 'Active') === 'Banned') {
        echo json_encode(['success' => false, 'message' => 'Bu açar bloklanıb (Banned).', 'remaining_seconds' => 0]);
        exit;
    }

    if (($k['status'] ?? 'Active') === 'Paused') {
        $pauseUntil = (int)($k['pause_until'] ?? 0);
        if ($pauseUntil > 0 && $now >= $pauseUntil) {
            $k['status'] = 'Active';
            $k['pause_until'] = 0;
            addAudit($k, 'Müvəqqəti dayandırma müddəti bitdi, açar yenidən aktiv oldu.');
        } else {
            echo json_encode(['success' => false, 'message' => 'Açar müvəqqəti dayandırılıb.', 'remaining_seconds' => 0]);
            exit;
        }
    }

    // İlk aktivləşmə və ya müddət yoxlaması
    $durationSec = (int)($k['duration_seconds'] ?? 86400);
    if (empty($k['expires_at'])) {
        $k['expires_at'] = $now + $durationSec;
        addAudit($k, 'Açar ilk dəfə aktivləşdirildi.');
    }

    $rem = (int)$k['expires_at'] - $now;
    if ($rem <= 0) {
        $k['status'] = 'Expired';
        saveData($DATA_FILE, $data);
        echo json_encode(['success' => false, 'message' => 'Açarın vaxtı bitib.', 'remaining_seconds' => 0]);
        exit;
    }

    if (!isset($k['approved_devices']) || !is_array($k['approved_devices'])) $k['approved_devices'] = [];
    if (!isset($k['pending_devices']) || !is_array($k['pending_devices']))   $k['pending_devices'] = [];

    // Artıq təsdiqlənmiş cihazdırmı?
    foreach ($k['approved_devices'] as &$dev) {
        if ($dev['device_id'] === $deviceId) {
            $dev['last_seen'] = date('Y-m-d H:i:s');
            $dev['ip'] = $ip;
            if ($devName !== '')  $dev['name'] = $devName;
            if ($battery !== '')  $dev['battery'] = $battery;
            if ($location !== '') $dev['location'] = $location;
            $dev['active'] = true;
            saveData($DATA_FILE, $data);
            echo json_encode([
                'success' => true,
                'message' => 'Giriş uğurludur',
                'remaining_seconds' => $rem
            ]);
            exit;
        }
    }
    unset($dev);

    // Yeni cihazdır: limit yoxla
    $maxDev = max(1, (int)($k['max_devices'] ?? 1));
    if (count($k['approved_devices']) < $maxDev) {
        $k['approved_devices'][] = [
            'device_id' => $deviceId,
            'name'      => $devName ?: 'iOS Device',
            'battery'   => $battery ?: '—',
            'location'  => $location ?: '—',
            'ip'        => $ip,
            'last_seen' => date('Y-m-d H:i:s'),
            'active'    => true
        ];
        addAudit($k, "Yeni cihaz qoşuldu: {$deviceId} ({$ip})");
        saveData($DATA_FILE, $data);
        echo json_encode([
            'success' => true,
            'message' => 'Cihaz qeydə alındı və giriş verildi',
            'remaining_seconds' => $rem
        ]);
        exit;
    }

    // Limit dolub -> Pending siyahısına sal (Default: DENIED)
    $alreadyPending = false;
    foreach ($k['pending_devices'] as &$pDev) {
        if ($pDev['device_id'] === $deviceId) {
            $pDev['last_seen'] = date('Y-m-d H:i:s');
            $pDev['ip'] = $ip;
            if ($devName !== '')  $pDev['name'] = $devName;
            if ($battery !== '')  $pDev['battery'] = $battery;
            if ($location !== '') $pDev['location'] = $location;
            $alreadyPending = true;
            break;
        }
    }
    unset($pDev);

    if (!$alreadyPending) {
        $k['pending_devices'][] = [
            'device_id' => $deviceId,
            'name'      => $devName ?: 'iOS Device',
            'battery'   => $battery ?: '—',
            'location'  => $location ?: '—',
            'ip'        => $ip,
            'last_seen' => date('Y-m-d H:i:s')
        ];
        addAudit($k, "Limit dolduğu üçün yeni cihaz təsdiq gözləyir: {$deviceId}");
    }

    saveData($DATA_FILE, $data);
    echo json_encode([
        'success' => false,
        'message' => 'Cihaz limiti dolub. Admin təsdiqi gözlənilir.',
        'remaining_seconds' => 0
    ]);
    exit;
}

// =========================================================================
// 2. ADMIN PANEL ENDPOINTS (KeyPanel.php)
// =========================================================================
if ($action === 'admin_login') {
    if (checkAdmin($input, $ADMIN_USER, $ADMIN_PASS)) {
        echo json_encode(['success' => true]);
    } else {
        echo json_encode(['success' => false, 'message' => 'Username or password is incorrect.']);
    }
    exit;
}

if (!checkAdmin($input, $ADMIN_USER, $ADMIN_PASS)) {
    http_response_code(401);
    echo json_encode(['success' => false, 'message' => 'Unauthorized']);
    exit;
}

if ($action === 'list_keys') {
    foreach ($data['keys'] as &$k) {
        if (($k['status'] ?? '') === 'Active' && !empty($k['expires_at']) && $k['expires_at'] <= $now) {
            $k['status'] = 'Expired';
        }
    }
    unset($k);
    saveData($DATA_FILE, $data);
    echo json_encode(['success' => true, 'keys' => $data['keys'], 'server_time' => $now]);
    exit;
}

if ($action === 'create_key') {
    $custom   = trim((string)($input['custom_key'] ?? ''));
    $unit     = trim((string)($input['unit'] ?? 'day'));
    $amount   = max(1, (int)($input['amount'] ?? 1));
    $maxDev   = max(1, (int)($input['max_devices'] ?? 1));

    $code = unitCode($unit, $amount);
    $secs = unitToSeconds($unit, $amount);

    if ($custom !== '') {
        $keyStr = $custom;
        $durLabel = 'Custom (' . $code . ')';
    } else {
        $chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';
        $rnd = '';
        for ($i = 0; $i < 12; $i++) $rnd .= $chars[random_int(0, strlen($chars) - 1)];
        $keyStr = 'DARKIOS-' . $code . '-' . $rnd;
        $durLabel = $code;
    }

    foreach ($data['keys'] as $ex) {
        if (strcasecmp($ex['key'], $keyStr) === 0) {
            echo json_encode(['success' => false, 'message' => 'Bu açar artıq mövcuddur.']);
            exit;
        }
    }

    $newKey = [
        'key'              => $keyStr,
        'duration_label'   => $durLabel,
        'duration_seconds' => $secs,
        'max_devices'      => $maxDev,
        'created'          => date('Y-m-d H:i'),
        'expires_at'       => null,
        'status'           => 'Active',
        'pause_until'      => 0,
        'approved_devices' => [],
        'pending_devices'  => [],
        'audit'            => []
    ];
    addAudit($newKey, "Açar yaradıldı (Limit: {$maxDev}, Müddət: {$durLabel})");
    array_unshift($data['keys'], $newKey);
    saveData($DATA_FILE, $data);
    echo json_encode(['success' => true, 'key' => $newKey]);
    exit;
}

if ($action === 'import_keys') {
    $lines = $input['keys'] ?? [];
    $added = 0;
    foreach ($lines as $raw) {
        $kStr = trim((string)$raw);
        if ($kStr === '') continue;
        $exists = false;
        foreach ($data['keys'] as $ex) {
            if (strcasecmp($ex['key'], $kStr) === 0) { $exists = true; break; }
        }
        if (!$exists) {
            $item = [
                'key' => $kStr,
                'duration_label' => 'Imported',
                'duration_seconds' => 86400 * 30,
                'max_devices' => 1,
                'created' => date('Y-m-d H:i'),
                'expires_at' => null,
                'status' => 'Active',
                'pause_until' => 0,
                'approved_devices' => [],
                'pending_devices' => [],
                'audit' => []
            ];
            addAudit($item, 'TXT faylından import edildi.');
            $data['keys'][] = $item;
            $added++;
        }
    }
    saveData($DATA_FILE, $data);
    echo json_encode(['success' => true, 'added' => $added]);
    exit;
}

// Hədəf açarı tap (qalan əməliyyatlar üçün)
$targetKey = trim((string)($input['key'] ?? ''));
$idx = -1;
foreach ($data['keys'] as $i => $item) {
    if ($item['key'] === $targetKey) { $idx = $i; break; }
}
if ($idx === -1) {
    echo json_encode(['success' => false, 'message' => 'Açar tapılmadı.']);
    exit;
}

if ($action === 'delete_key') {
    array_splice($data['keys'], $idx, 1);
    saveData($DATA_FILE, $data);
    echo json_encode(['success' => true]);
    exit;
}

$k = &$data['keys'][$idx];

if ($action === 'set_limit') {
    $newLimit = max(1, (int)($input['max_devices'] ?? 1));
    $force    = !empty($input['force']);
    $activeCount = count($k['approved_devices'] ?? []);
    if ($newLimit < $activeCount && !$force) {
        echo json_encode(['success' => false, 'need_confirm' => true, 'message' => "Hazırda {$activeCount} aktiv cihaz var. Limiti aşağı salmaq artıq cihazları çıxaracaq."]);
        exit;
    }
    if ($newLimit < $activeCount && $force) {
        $k['approved_devices'] = array_slice($k['approved_devices'], 0, $newLimit);
    }
    $k['max_devices'] = $newLimit;
    addAudit($k, "Maksimum cihaz limiti dəyişdirildi: {$newLimit}");
}
elseif ($action === 'extend_duration') {
    $unit   = $input['unit'] ?? 'day';
    $amount = max(1, (int)($input['amount'] ?? 1));
    $addSec = unitToSeconds($unit, $amount);
    if (!empty($k['expires_at']) && $k['expires_at'] > $now) {
        $k['expires_at'] += $addSec;
    } else {
        $k['duration_seconds'] = (int)($k['duration_seconds'] ?? 0) + $addSec;
        if (!empty($k['expires_at'])) {
            $k['expires_at'] = $now + $addSec;
        }
    }
    if (($k['status'] ?? '') === 'Expired') $k['status'] = 'Active';
    addAudit($k, "Müddət uzadıldı: +{$amount} {$unit}");
}
elseif ($action === 'ban_key') {
    $k['status'] = 'Banned';
    addAudit($k, 'Açar admin tərəfindən BAN edildi.');
}
elseif ($action === 'unban_key') {
    $k['status'] = 'Active';
    addAudit($k, 'Açarın BAN statusu ləğv edildi.');
}
elseif ($action === 'pause_key') {
    $until = trim((string)($input['pause_until'] ?? ''));
    $k['status'] = 'Paused';
    $k['pause_until'] = $until !== '' ? (int)strtotime($until) : 0;
    addAudit($k, 'Açar müvəqqəti dayandırıldı (Paused).');
}
elseif ($action === 'resume_key') {
    $k['status'] = 'Active';
    $k['pause_until'] = 0;
    addAudit($k, 'Açar yenidən aktivləşdirildi (Resumed).');
}
elseif ($action === 'approve_device') {
    $devId = trim((string)($input['device_id'] ?? ''));
    $raiseLimit = !empty($input['raise_limit']);
    $pIdx = -1;
    foreach ($k['pending_devices'] as $pi => $pd) {
        if ($pd['device_id'] === $devId) { $pIdx = $pi; break; }
    }
    if ($pIdx === -1) {
        echo json_encode(['success' => false, 'message' => 'Sorğu tapılmadı.']);
        exit;
    }
    $maxDev = max(1, (int)$k['max_devices']);
    if (count($k['approved_devices']) >= $maxDev) {
        if ($raiseLimit) {
            $k['max_devices'] = count($k['approved_devices']) + 1;
        } else {
            echo json_encode(['success' => false, 'need_raise' => true, 'message' => 'Cihaz limiti doludur. Limiti 1 vahid artırıb təsdiqləmək istəyirsiniz?']);
            exit;
        }
    }
    $devObj = $k['pending_devices'][$pIdx];
    $devObj['active'] = true;
    $devObj['last_seen'] = date('Y-m-d H:i:s');
    $k['approved_devices'][] = $devObj;
    array_splice($k['pending_devices'], $pIdx, 1);
    addAudit($k, "Yeni cihaz təsdiqləndi: {$devId}");
}
elseif ($action === 'decline_device') {
    $devId = trim((string)($input['device_id'] ?? ''));
    $k['pending_devices'] = array_values(array_filter($k['pending_devices'], fn($d) => $d['device_id'] !== $devId));
    addAudit($k, "Yeni cihaz sorğusu rədd edildi: {$devId}");
}
elseif ($action === 'reset_devices') {
    $k['approved_devices'] = [];
    $k['pending_devices'] = [];
    addAudit($k, 'Bütün cihazlar sıfırlandı (Reset Devices).');
}

saveData($DATA_FILE, $data);
echo json_encode(['success' => true, 'key' => $k]);
