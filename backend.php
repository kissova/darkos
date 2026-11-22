<?php
header('Content-Type: application/json; charset=utf-8');
header('Access-Control-Allow-Origin: *');
header('Access-Control-Allow-Methods: POST, GET, OPTIONS');
header('Access-Control-Allow-Headers: Content-Type, Accept');

if ($_SERVER['REQUEST_METHOD'] === 'OPTIONS') {
    http_response_code(200);
    exit;
}

$ADMIN_USER = 'Ayxan';
$ADMIN_PASS = 'Wear5555';
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
    $u = strtolower(trim((string)$unit));
    if ($u === 'lifetime') return 0;
    $n = max(1, (int)$amount);
    switch ($u) {
        case 'minute': case 'min': return $n * 60;
        case 'hour':   case 'h':   return $n * 3600;
        case 'day':    case 'd':   return $n * 86400;
        case 'week':   case 'w':   return $n * 604800;
        case 'month':  case 'm':   return $n * 2592000;
        case 'year':   case 'y':   return $n * 31536000;
        default:                   return $n * 86400;
    }
}

function durationTag($unit, $amount) {
    $u = strtolower(trim((string)$unit));
    if ($u === 'lifetime') return 'LIFETIME';
    $n = max(1, (int)$amount);
    $map = [
        'minute' => 'MINUTE',
        'min'    => 'MINUTE',
        'hour'   => 'HOUR',
        'h'      => 'HOUR',
        'day'    => 'DAY',
        'd'      => 'DAY',
        'week'   => 'WEEK',
        'w'      => 'WEEK',
        'month'  => 'MONTH',
        'm'      => 'MONTH',
        'year'   => 'YEAR',
        'y'      => 'YEAR'
    ];
    return $n . ($map[$u] ?? 'DAY');
}

function checkAdmin($input, $user, $pass) {
    $u = (string)($input['admin_user'] ?? '');
    $p = (string)($input['admin_pass'] ?? '');
    return hash_equals($user, $u) && hash_equals($pass, $p);
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
// 1. iOS TWEAK LOGIN ENDPOINT
// =========================================================================
if ($action === 'player_login') {
    $keyStr   = trim((string)($input['key'] ?? ''));
    $deviceId = trim((string)($input['device_id'] ?? ''));
    $devName  = trim((string)($input['device_name'] ?? 'iOS Device'));
    $battery  = trim((string)($input['battery'] ?? ''));
    $location = trim((string)($input['location'] ?? ''));
    $ip       = getClientIp();

    if ($keyStr === '' || $deviceId === '') {
        echo json_encode(['success' => false, 'message' => 'Key or device ID is empty.', 'remaining_seconds' => 0]);
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
        echo json_encode(['success' => false, 'message' => 'License key not found.', 'remaining_seconds' => 0]);
        exit;
    }

    $k = &$data['keys'][$foundIndex];

    if (($k['status'] ?? 'Active') === 'Banned') {
        echo json_encode(['success' => false, 'message' => 'This license key is banned.', 'remaining_seconds' => 0]);
        exit;
    }

    if (($k['status'] ?? 'Active') === 'Paused') {
        $pauseUntil = (int)($k['pause_until'] ?? 0);
        if ($pauseUntil > 0 && $now >= $pauseUntil) {
            $k['status'] = 'Active';
            $k['pause_until'] = 0;
            addAudit($k, 'Temporary stop expired, key resumed automatically.');
        } else {
            echo json_encode(['success' => false, 'message' => 'This license key is temporarily stopped.', 'remaining_seconds' => 0]);
            exit;
        }
    }

    $isLifetime = !empty($k['lifetime']) || (($k['duration_label'] ?? '') === 'LIFETIME');
    if ($isLifetime) {
        $rem = 999999999;
    } else {
        $durationSec = (int)($k['duration_seconds'] ?? 86400);
        if (empty($k['expires_at'])) {
            $k['expires_at'] = $now + $durationSec;
            addAudit($k, 'Key activated for the first time.');
        }
        $rem = (int)$k['expires_at'] - $now;
        if ($rem <= 0) {
            $k['status'] = 'Expired';
            saveData($DATA_FILE, $data);
            echo json_encode(['success' => false, 'message' => 'License key has expired.', 'remaining_seconds' => 0]);
            exit;
        }
    }

    if (!isset($k['approved_devices']) || !is_array($k['approved_devices'])) $k['approved_devices'] = [];
    if (!isset($k['pending_devices']) || !is_array($k['pending_devices']))   $k['pending_devices'] = [];

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
                'message' => 'Login successful',
                'remaining_seconds' => $rem
            ]);
            exit;
        }
    }
    unset($dev);

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
        addAudit($k, "Device approved & registered: {$deviceId} ({$ip})");
        saveData($DATA_FILE, $data);
        echo json_encode([
            'success' => true,
            'message' => 'Device registered and login successful',
            'remaining_seconds' => $rem
        ]);
        exit;
    }

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
        addAudit($k, "Device limit reached; pending approval added: {$deviceId}");
    }

    saveData($DATA_FILE, $data);
    echo json_encode([
        'success' => false,
        'message' => 'Device limit reached. Waiting for admin approval.',
        'remaining_seconds' => 0
    ]);
    exit;
}

// =========================================================================
// 2. ADMIN LOGIN & PROTECTED ACTIONS (ONLY Ayxan / Wear5555)
// =========================================================================
if ($action === 'admin_login') {
    if (checkAdmin($input, $ADMIN_USER, $ADMIN_PASS)) {
        echo json_encode(['success' => true]);
    } else {
        http_response_code(401);
        echo json_encode(['success' => false, 'message' => 'Invalid username or password.']);
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
        $isLife = !empty($k['lifetime']) || (($k['duration_label'] ?? '') === 'LIFETIME');
        if (!$isLife && ($k['status'] ?? '') === 'Active' && !empty($k['expires_at']) && $k['expires_at'] <= $now) {
            $k['status'] = 'Expired';
        }
        if (($k['status'] ?? '') === 'Paused' && !empty($k['pause_until']) && (int)$k['pause_until'] <= $now) {
            $k['status'] = 'Active';
            $k['pause_until'] = 0;
        }
    }
    unset($k);
    saveData($DATA_FILE, $data);
    echo json_encode(['success' => true, 'keys' => $data['keys'], 'server_time' => $now]);
    exit;
}

if ($action === 'create_key') {
    $custom = trim((string)($input['custom_key'] ?? ''));
    $unit   = trim((string)($input['unit'] ?? 'day'));
    $amount = max(1, (int)($input['amount'] ?? 1));
    $maxDev = max(1, (int)($input['max_devices'] ?? 1));

    $isLife = (strtolower($unit) === 'lifetime');
    $tag    = durationTag($unit, $amount);
    $secs   = $isLife ? 0 : unitToSeconds($unit, $amount);

    if ($custom !== '') {
        $keyStr   = $custom;
        $durLabel = $isLife ? 'LIFETIME' : ('Custom (' . $tag . ')');
    } else {
        $chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';
        $rnd = '';
        for ($i = 0; $i < 12; $i++) $rnd .= $chars[random_int(0, strlen($chars) - 1)];
        $keyStr   = 'DARKIOS-' . $tag . '-' . $rnd;
        $durLabel = $tag;
    }

    foreach ($data['keys'] as $ex) {
        if (strcasecmp($ex['key'], $keyStr) === 0) {
            echo json_encode(['success' => false, 'message' => 'Key already exists.']);
            exit;
        }
    }

    $newKey = [
        'key'              => $keyStr,
        'lifetime'         => $isLife,
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
    addAudit($newKey, "Key created (Duration: {$durLabel}, Max Devices: {$maxDev})");
    array_unshift($data['keys'], $newKey);
    saveData($DATA_FILE, $data);
    echo json_encode(['success' => true, 'key' => $newKey]);
    exit;
}

if ($action === 'import_keys_full') {
    $entries = $input['entries'] ?? [];
    $added = 0;
    $updated = 0;

    foreach ($entries as $ent) {
        if (!is_array($ent)) continue;
        $kStr = trim((string)($ent['key'] ?? ''));
        if ($kStr === '') continue;

        $isLife   = !empty($ent['lifetime']) || (($ent['duration_label'] ?? '') === 'LIFETIME');
        $durSec   = max(0, (int)($ent['duration_seconds'] ?? 86400));
        $durLabel = trim((string)($ent['duration_label'] ?? ($isLife ? 'LIFETIME' : '1DAY')));
        $maxDev   = max(1, (int)($ent['max_devices'] ?? 1));
        $status   = in_array($ent['status'] ?? 'Active', ['Active', 'Paused', 'Banned', 'Expired'], true) ? $ent['status'] : 'Active';
        $pauseUntil = (int)($ent['pause_until'] ?? 0);

        $expAt = null;
        if (!$isLife) {
            if (isset($ent['remaining_seconds']) && (int)$ent['remaining_seconds'] > 0) {
                $expAt = $now + (int)$ent['remaining_seconds'];
            } elseif (!empty($ent['expires_at']) && (int)$ent['expires_at'] > $now) {
                $expAt = (int)$ent['expires_at'];
            }
        }

        $record = [
            'key'              => $kStr,
            'lifetime'         => $isLife,
            'duration_label'   => $durLabel,
            'duration_seconds' => $durSec,
            'max_devices'      => $maxDev,
            'created'          => (string)($ent['created'] ?? date('Y-m-d H:i')),
            'expires_at'       => $expAt,
            'status'           => $status,
            'pause_until'      => $pauseUntil,
            'approved_devices' => is_array($ent['approved_devices'] ?? null) ? $ent['approved_devices'] : [],
            'pending_devices'  => is_array($ent['pending_devices'] ?? null) ? $ent['pending_devices'] : [],
            'audit'            => is_array($ent['audit'] ?? null) ? $ent['audit'] : []
        ];
        addAudit($record, "Imported from TXT (Status: {$status}, Max Devices: {$maxDev})");

        $found = -1;
        foreach ($data['keys'] as $i => $ex) {
            if (strcasecmp($ex['key'], $kStr) === 0) { $found = $i; break; }
        }
        if ($found >= 0) {
            $data['keys'][$found] = $record;
            $updated++;
        } else {
            array_unshift($data['keys'], $record);
            $added++;
        }
    }

    saveData($DATA_FILE, $data);
    echo json_encode(['success' => true, 'added' => $added, 'updated' => $updated]);
    exit;
}

$targetKey = trim((string)($input['key'] ?? ''));
$idx = -1;
foreach ($data['keys'] as $i => $item) {
    if ($item['key'] === $targetKey) { $idx = $i; break; }
}
if ($idx === -1) {
    echo json_encode(['success' => false, 'message' => 'Key not found.']);
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
        echo json_encode(['success' => false, 'need_confirm' => true, 'message' => "{$activeCount} active device(s) connected. Lowering limit will remove extra devices. Continue?"]);
        exit;
    }
    if ($newLimit < $activeCount && $force) {
        $k['approved_devices'] = array_slice($k['approved_devices'], 0, $newLimit);
    }
    $k['max_devices'] = $newLimit;
    addAudit($k, "Device limit changed to {$newLimit}");
}
elseif ($action === 'extend_duration') {
    $unit   = $input['unit'] ?? 'day';
    $amount = max(1, (int)($input['amount'] ?? 1));
    if (strtolower($unit) === 'lifetime') {
        $k['lifetime'] = true;
        $k['expires_at'] = null;
        $k['duration_label'] = 'LIFETIME';
        $k['duration_seconds'] = 0;
        if (($k['status'] ?? '') === 'Expired') $k['status'] = 'Active';
        addAudit($k, 'Duration set to LIFETIME');
    } else {
        $k['lifetime'] = false;
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
        addAudit($k, "Duration extended by +{$amount} " . strtoupper($unit));
    }
}
elseif ($action === 'ban_key') {
    $k['status'] = 'Banned';
    addAudit($k, 'Key banned by administrator');
}
elseif ($action === 'unban_key') {
    $k['status'] = 'Active';
    addAudit($k, 'Key unbanned by administrator');
}
elseif ($action === 'pause_key') {
    $until = trim((string)($input['pause_until'] ?? ''));
    $k['status'] = 'Paused';
    $k['pause_until'] = $until !== '' ? (int)strtotime($until) : 0;
    addAudit($k, 'Key temporarily stopped (Paused)');
}
elseif ($action === 'resume_key') {
    $k['status'] = 'Active';
    $k['pause_until'] = 0;
    addAudit($k, 'Key resumed (Active)');
}
elseif ($action === 'approve_device') {
    $devId = trim((string)($input['device_id'] ?? ''));
    $raiseLimit = !empty($input['raise_limit']);
    $pIdx = -1;
    foreach ($k['pending_devices'] as $pi => $pd) {
        if ($pd['device_id'] === $devId) { $pIdx = $pi; break; }
    }
    if ($pIdx === -1) {
        echo json_encode(['success' => false, 'message' => 'Request not found.']);
        exit;
    }
    $maxDev = max(1, (int)$k['max_devices']);
    if (count($k['approved_devices']) >= $maxDev) {
        if ($raiseLimit) {
            $k['max_devices'] = count($k['approved_devices']) + 1;
        } else {
            echo json_encode(['success' => false, 'need_raise' => true, 'message' => 'Device limit reached. Increase limit by 1 and accept?']);
            exit;
        }
    }
    $devObj = $k['pending_devices'][$pIdx];
    $devObj['active'] = true;
    $devObj['last_seen'] = date('Y-m-d H:i:s');
    $k['approved_devices'][] = $devObj;
    array_splice($k['pending_devices'], $pIdx, 1);
    addAudit($k, "Approved device: {$devId}");
}
elseif ($action === 'decline_device') {
    $devId = trim((string)($input['device_id'] ?? ''));
    $k['pending_devices'] = array_values(array_filter($k['pending_devices'], fn($d) => $d['device_id'] !== $devId));
    addAudit($k, "Declined device request: {$devId}");
}
elseif ($action === 'reset_devices') {
    $k['approved_devices'] = [];
    $k['pending_devices'] = [];
    addAudit($k, 'All approved devices reset');
}

saveData($DATA_FILE, $data);
echo json_encode(['success' => true, 'key' => $k]);
