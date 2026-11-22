<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Control Center Dashboard</title>
<style>
:root{--bg:#b9b9b9;--shell:#f5f3ef;--panel:#fbfaf8;--line:#e6e2dc;--muted:#898985;--text:#171717;--accent:#111111;--accent-text:#ffffff;--green:#13a879;--yellow:#e7bd26;--red:#e24c4c;--shadow:0 2px 10px #0000000a}
*{box-sizing:border-box}body{margin:0;background:#080808;font:14px Inter,-apple-system,BlinkMacSystemFont,"Segoe UI",sans-serif;color:var(--text);min-height:100vh;display:grid;place-items:center;padding:22px}
button,input,select{font:inherit}button{cursor:pointer}
.app{width:min(1280px,100%);height:min(900px,calc(100vh - 44px));min-height:650px;background:var(--shell);border:1px solid var(--line);border-radius:15px;overflow:hidden;box-shadow:0 18px 55px #00000018;display:none;flex-direction:column}
.topbar{height:43px;border-bottom:1px solid var(--line);display:flex;align-items:center;justify-content:space-between;padding:0 15px 0 18px;flex-shrink:0}
.brand{display:flex;align-items:center;gap:10px;font-size:12px}
.top-actions{display:flex;align-items:center;gap:14px;color:var(--muted)}.top-actions button{border:0;background:none;color:inherit;padding:4px;display:flex;align-items:center;justify-content:center}.share{background:var(--accent)!important;color:var(--accent-text)!important;border-radius:8px;padding:7px 13px!important;font-size:12px}
.body{display:flex;min-height:0;flex:1}.rail{width:42px;border-right:1px solid var(--line);display:flex;align-items:center;flex-direction:column;gap:15px;padding:14px 0;color:var(--muted);flex-shrink:0}.rail button{border:0;background:none;color:inherit;font-size:17px;width:28px;height:24px;border-radius:6px}.rail button:hover{background:var(--line)}
.sidebar{width:66px;border-right:1px solid var(--line);padding:10px 8px 8px;display:flex;flex-direction:column;gap:8px;overflow:auto;flex-shrink:0}
.nav{display:flex;align-items:center;justify-content:center;width:100%;height:38px;border:0;background:transparent;padding:7px 8px;border-radius:7px;color:var(--text);font-size:12px;margin:2px 0}.nav:hover,.nav.active{background:var(--line)}.nav .ico{width:18px;height:18px;color:var(--muted);display:flex;align-items:center;justify-content:center}.nav .ico svg{width:17px;height:17px;stroke:currentColor;fill:none;stroke-width:1.65;stroke-linecap:round;stroke-linejoin:round}
.main{flex:1;min-width:0;overflow:auto;padding:14px 20px 22px}.content{max-width:960px;margin:0 auto}.page-title{font-size:14px;font-weight:600;margin:0 0 14px}
.panel{background:var(--panel);border:1px solid var(--line);border-radius:11px;box-shadow:var(--shadow)}
.page{display:none}.page.active{display:block}.section-panel{padding:15px;margin-bottom:10px}.section-panel h3{font-size:13px;margin:0 0 12px}.section-panel p{font-size:11px;color:var(--muted)}
.toolbar{display:flex;gap:8px;align-items:center;margin:12px 0;flex-wrap:wrap}.toolbar input{flex:1;min-width:120px}.field{border:1px solid var(--line);border-radius:7px;background:var(--panel);padding:8px 10px;font-size:11px;color:var(--text)}.action{background:var(--accent);color:var(--accent-text);border:0;border-radius:7px;padding:8px 12px;font-size:11px;display:inline-flex;align-items:center;gap:6px}.small-btn{border:1px solid var(--line);background:var(--panel);border-radius:6px;padding:5px 9px;font-size:10px;color:var(--text)}.small-btn.danger{border-color:#efc7c4;color:#c24c42;background:#fff8f7}.small-btn.warn{border-color:#ecd9a2;color:#99750b;background:#fffdf5}
.table{width:100%;border-collapse:collapse;font-size:11px}.table th{text-align:left;color:var(--muted);font-weight:500;padding:10px 8px;border-bottom:1px solid var(--line);white-space:nowrap}.table td{padding:10px 8px;border-bottom:1px solid var(--line);vertical-align:middle}
.pill{font-size:9px;border-radius:20px;padding:4px 8px;background:#e7f5ef;color:#07865f;display:inline-block;font-weight:600}.pill.warn{background:#fbf3d9;color:#99750b}.pill.red{background:#fae9e7;color:#c24c42}
.stats{display:grid;grid-template-columns:repeat(3,1fr);gap:8px;margin-bottom:10px}.stat{padding:13px}.stat b{font-size:19px}.stat small{display:block;color:var(--muted);font-size:10px;margin-top:5px}
.overlay{position:fixed;inset:0;background:#0006;display:none;align-items:center;justify-content:center;padding:18px;z-index:20}.overlay.show{display:flex}.modal{width:min(620px,100%);max-height:90vh;overflow:auto;background:var(--panel);border:1px solid var(--line);border-radius:13px;padding:18px;box-shadow:0 20px 70px #0004;color:var(--text)}.modal h2{font-size:15px;margin:0 0 12px}.modal label{display:block;font-size:10px;color:var(--muted);margin:10px 0 4px}.modal input,.modal select{width:100%}.modal-actions{display:flex;justify-content:flex-end;gap:8px;margin-top:16px}
.toast{position:fixed;bottom:20px;left:50%;transform:translateX(-50%);background:var(--accent);color:var(--accent-text);padding:9px 14px;border-radius:8px;font-size:11px;display:none;z-index:40}
.ui-icon{width:16px;height:16px;stroke:currentColor;fill:none;stroke-width:1.65;stroke-linecap:round;stroke-linejoin:round;vertical-align:middle}
.key-cell{display:flex;align-items:center;gap:7px;font-family:ui-monospace,SFMono-Regular,monospace;font-size:11px;word-break:break-all}
.pending-dot{width:16px;height:16px;border-radius:50%;background:#e24c42;color:#fff;font-size:9px;font-weight:700;display:inline-flex;align-items:center;justify-content:center;border:0;flex-shrink:0;box-shadow:0 0 0 2px #fae9e7;animation:pulse 1.5s infinite}
@keyframes pulse{0%{transform:scale(1)}50%{transform:scale(1.12)}100%{transform:scale(1)}}
.manage-box{border:1px solid var(--line);background:var(--shell);border-radius:9px;padding:11px;margin-top:10px}
.manage-box h4{margin:0 0 8px;font-size:12px}
.manage-grid{display:grid;grid-template-columns:1fr 1fr;gap:10px}
.dev-card{border:1px solid var(--line);border-radius:8px;padding:8px 10px;margin-bottom:6px;font-size:11px;display:flex;justify-content:space-between;align-items:center;gap:8px;background:var(--panel)}
.audit-item{font-size:10px;padding:5px 0;border-bottom:1px solid var(--line);color:var(--muted)}
.time-combined-row{display:grid;grid-template-columns:62px minmax(0,1fr) minmax(76px,.72fr);align-items:center;gap:10px;margin-top:14px}
.time-combined-row label{margin:0!important}
.overview-welcome{min-height:180px;display:flex;flex-direction:column;justify-content:center}.overview-welcome h2{margin:0 0 8px;font-size:22px}.overview-welcome p{color:var(--muted);margin:0 0 18px}

/* 50 Theme Grid */
.theme-grid{display:grid;grid-template-columns:repeat(5,minmax(0,1fr));gap:7px;margin-top:9px;max-height:340px;overflow:auto;padding-right:4px}
.theme-choice{border:1px solid var(--line);border-radius:8px;background:var(--shell);color:var(--text);padding:8px 7px;text-align:left;font-size:10px;display:flex;flex-direction:column;gap:5px}
.theme-choice.selected{outline:2px solid var(--accent);outline-offset:1px}
.swatches{display:flex;gap:3px;height:16px}.swatches i{display:block;height:100%;flex:1;border-radius:3px;border:1px solid #0002}

/* Login Screen */
.login-screen{width:min(1060px,calc(100vw - 48px));height:min(760px,calc(100vh - 48px));min-height:560px;background:#0b0b0b;border:7px solid #1b1b1b;outline:1px solid #292929;display:grid;grid-template-columns:1fr 1.12fr;overflow:hidden;color:#f5f5f5}
.login-left{display:flex;align-items:center;justify-content:center;padding:42px}.login-form{width:min(320px,100%)}
.login-logo{width:58px;height:58px;border:4px solid #f5f5f5;border-radius:50%;margin:0 auto 64px;position:relative}
.login-logo:after{content:"";position:absolute;width:62px;height:4px;background:#f5f5f5;left:-6px;top:25px;transform:rotate(-32deg);border-radius:5px}
.login-form label{display:block;font-size:12px;margin:17px 0 8px;color:#eee}
.login-input-wrap{height:43px;background:#1b1b1b;border:1px solid #292929;display:flex;align-items:center;padding:0 12px;gap:10px}
.login-input-wrap svg{width:15px;height:15px;stroke:#858585;fill:none;stroke-width:1.7}
.login-input-wrap input{background:transparent;border:0;outline:0;color:#fff;width:100%;font-size:12px}
.login-submit{width:100%;height:43px;background:#f7f7f7;color:#080808;border:0;margin-top:35px;font-size:13px}
.login-error{min-height:18px;color:#ff7777;font-size:11px;margin-top:12px}
.login-art{position:relative;overflow:hidden;background:#0a0a0a}
.pillar{position:absolute;bottom:-10px;width:24%;height:95%;opacity:.76;background:radial-gradient(circle,#aaa .7px,transparent 1px) 0 0/5px 5px,linear-gradient(90deg,transparent 12%,#888 13%,transparent 16%,transparent 27%,#aaa 28%,transparent 31%,transparent 67%,#999 68%,transparent 71%);mask-image:linear-gradient(to bottom,transparent 0%,#000 16%,#000 85%,transparent 100%)}
.pillar:before{content:"";position:absolute;left:-18%;top:8%;width:136%;height:13%;border:2px dotted #888;border-bottom:0;border-radius:50% 50% 0 0}
.pillar:after{content:"";position:absolute;left:-25%;bottom:0;width:150%;height:17%;background:radial-gradient(ellipse at center,#888 0 1px,transparent 1.5px) 0 0/5px 5px}
.pillar.one{left:7%;height:100%;width:29%}.pillar.two{left:39%;height:81%;width:25%}.pillar.three{right:5%;height:100%;width:27%}

@media(max-width:800px){.theme-grid{grid-template-columns:repeat(3,minmax(0,1fr))}}
@media(max-width:700px){body{padding:0}.app{height:100vh;min-height:0;border-radius:0}.login-screen{width:100vw;height:100vh;min-height:0;border:0;grid-template-columns:1fr}.login-art{display:none}.manage-grid{grid-template-columns:1fr}.rail{display:none}.sidebar{width:54px;padding:8px 4px}.main{padding:12px 9px}.theme-grid{grid-template-columns:repeat(2,minmax(0,1fr))}}
</style>
</head>
<body>

<svg aria-hidden="true" width="0" height="0" style="position:absolute;overflow:hidden">
 <symbol id="i-grid" viewBox="0 0 24 24"><rect x="3" y="3" width="7" height="7" rx="1.5"/><rect x="14" y="3" width="7" height="7" rx="1.5"/><rect x="3" y="14" width="7" height="7" rx="1.5"/><rect x="14" y="14" width="7" height="7" rx="1.5"/></symbol>
 <symbol id="i-key" viewBox="0 0 24 24"><circle cx="8" cy="15" r="5"/><path d="m11.5 11.5 8-8 2 2-2 2 2 2-3 3-2-2-2 2"/></symbol>
 <symbol id="i-settings" viewBox="0 0 24 24"><circle cx="12" cy="12" r="3"/><path d="m19.4 15 .1.1 1.2 1-1.4 2.4-1.5-.6a8 8 0 0 1-1.8 1l-.3 1.6h-2.8l-.3-1.6a8 8 0 0 1-1.8-1l-1.5.6-1.4-2.4 1.2-1a8 8 0 0 1 0-2l-1.2-1 1.4-2.4 1.5.6a8 8 0 0 1 1.8-1l.3-1.6h2.8l.3 1.6a8 8 0 0 1 1.8 1l1.5-.6 1.4 2.4-1.2 1a8 8 0 0 1 0 2Z"/></symbol>
 <symbol id="i-log-out" viewBox="0 0 24 24"><path d="M10 17l5-5-5-5m5 5H3"/><path d="M12 3h7a2 2 0 0 1 2 2v14a2 2 0 0 1-2 2h-7"/></symbol>
 <symbol id="i-bell" viewBox="0 0 24 24"><path d="M18 9a6 6 0 0 0-12 0c0 7-3 7-3 9h18c0-2-3-2-3-9M10 21h4"/></symbol>
 <symbol id="i-sun" viewBox="0 0 24 24"><circle cx="12" cy="12" r="4"/><path d="M12 2v2m0 16v2M4.9 4.9l1.4 1.4m11.4 11.4 1.4 1.4M2 12h2m16 0h2M4.9 19.1l1.4-1.4M17.7 6.3l1.4-1.4"/></symbol>
 <symbol id="i-plus" viewBox="0 0 24 24"><path d="M12 5v14M5 12h14"/></symbol>
</svg>

<div class="login-screen" id="loginScreen">
 <div class="login-left">
  <form class="login-form" id="loginForm" autocomplete="off" onsubmit="doLogin(); return false;">
   <div class="login-logo" aria-hidden="true"></div>
   <label for="loginUser" data-i18n="username">Username</label>
   <div class="login-input-wrap"><svg viewBox="0 0 24 24"><circle cx="12" cy="8" r="4"/><path d="M4 21c.8-4 3.4-6 8-6s7.2 2 8 6"/></svg><input id="loginUser" placeholder="Username" autocomplete="username" required></div>
   <label for="loginPass" data-i18n="password">Password</label>
   <div class="login-input-wrap"><svg viewBox="0 0 24 24"><rect x="4" y="10" width="16" height="11" rx="2"/><path d="M8 10V7a4 4 0 0 1 8 0v3"/></svg><input id="loginPass" type="password" placeholder="Password" autocomplete="current-password" required></div>
   <button class="login-submit" type="submit" data-i18n="loginBtn">Login</button>
   <div class="login-error" id="loginError" role="alert"></div>
  </form>
 </div>
 <div class="login-art" aria-hidden="true"><div class="pillar one"></div><div class="pillar two"></div><div class="pillar three"></div></div>
</div>

<div class="app" id="appShell">
  <header class="topbar">
    <div class="brand"><svg width="15" height="15" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1.6"><rect x="3" y="3" width="18" height="18" rx="3"/><path d="M9 3v18"/></svg><span style="color:var(--muted)">DARKIOS</span><strong id="brandTitle">Control Center</strong></div>
    <div class="top-actions">
      <button title="Refresh" onclick="fetchKeys()"><svg class="ui-icon"><use href="#i-bell"/></svg></button>
      <button title="Settings" onclick="showPage('general')"><svg class="ui-icon"><use href="#i-sun"/></svg></button>
      <button class="share" id="shareBtn" data-i18n="copyEndpoint">Copy Endpoint</button>
      <button title="Sign out" id="signout"><svg class="ui-icon"><use href="#i-log-out"/></svg></button>
    </div>
  </header>
  <div class="body">
    <aside class="rail">
      <button title="Overview" onclick="showPage('overview')"><svg class="ui-icon"><use href="#i-grid"/></svg></button>
      <button title="Keys" onclick="showPage('keys')"><svg class="ui-icon"><use href="#i-key"/></svg></button>
      <button title="Settings" onclick="showPage('general')"><svg class="ui-icon"><use href="#i-settings"/></svg></button>
    </aside>
    <aside class="sidebar">
      <button class="nav active" data-page="overview" title="Overview"><span class="ico"><svg><use href="#i-grid"/></svg></span></button>
      <button class="nav" data-page="keys" title="Key Management"><span class="ico"><svg><use href="#i-key"/></svg></span></button>
      <button class="nav" data-page="general" title="Settings"><span class="ico"><svg><use href="#i-settings"/></svg></span></button>
    </aside>
    <main class="main"><div class="content">

      <section class="page active" id="page-overview">
        <h1 class="page-title" data-i18n="overview">Overview</h1>
        <div class="panel section-panel overview-welcome">
          <h2>DARKIOS Control Center</h2>
          <p data-i18n="overviewDesc">Server-connected license & device management console.</p>
          <div class="toolbar">
            <button class="action" onclick="openModal('generatorModal')"><svg class="ui-icon"><use href="#i-plus"/></svg> <span data-i18n="genKey">Generate Key</span></button>
            <button class="small-btn" onclick="showPage('keys')" data-i18n="openKeyList">Open Key List</button>
            <button class="small-btn" onclick="showPage('general')" data-i18n="settings">Settings</button>
          </div>
        </div>
      </section>

      <section class="page" id="page-keys">
        <h1 class="page-title" data-i18n="keyMgmt">Key Management</h1>
        <div class="stats">
          <div class="panel stat"><b id="keyTotal">0</b><small data-i18n="totalKeys">Total keys</small></div>
          <div class="panel stat"><b id="keyActive">0</b><small data-i18n="activeKeys">Active keys</small></div>
          <div class="panel stat"><b id="keyPending">0</b><small data-i18n="pendingApprovals">Pending device approvals</small></div>
        </div>
        <div class="panel section-panel">
          <h3 data-i18n="keyGen">Key Generator</h3>
          <p data-i18n="keyGenDesc">Create keys with duration (DAY, WEEK, MONTH, YEAR, LIFETIME) and device limit.</p>
          <div class="toolbar">
            <button class="action" onclick="openModal('generatorModal')"><svg class="ui-icon"><use href="#i-plus"/></svg> <span data-i18n="genKey">Generate Key</span></button>
            <button class="small-btn" onclick="openModal('keyToolsModal')" data-i18n="keyTools">Key Tools</button>
            <button class="small-btn" onclick="fetchKeys()" data-i18n="syncServer">↻ Sync Server</button>
          </div>
        </div>
        <div class="panel section-panel">
          <h3 data-i18n="keyList">Key List</h3>
          <div class="toolbar">
            <input class="field" id="keySearch" placeholder="Search keys..." oninput="renderKeys()">
            <button class="small-btn" onclick="exportKeys()" data-i18n="exportTxt">Export TXT</button>
          </div>
          <div style="overflow-x:auto">
            <table class="table">
              <thead>
                <tr>
                  <th data-i18n="thKey">Key</th>
                  <th data-i18n="thDuration">Duration / Remaining</th>
                  <th data-i18n="thDevices">Devices</th>
                  <th data-i18n="thStatus">Status</th>
                  <th data-i18n="thActions">Actions</th>
                </tr>
              </thead>
              <tbody id="keyRows"></tbody>
            </table>
          </div>
          <p id="emptyKeys" class="sub" style="display:none" data-i18n="noKeys">No keys yet. Generate a key or import a TXT file.</p>
        </div>
      </section>

      <section class="page" id="page-general">
        <h1 class="page-title" data-i18n="generalSettings">General Settings</h1>
        <div class="panel section-panel">
          <h3 data-i18n="workspacePrefs">Workspace preferences</h3>

          <label for="langSelect" data-i18n="language">Interface Language</label>
          <select class="field" id="langSelect" onchange="setLanguage(this.value)" style="max-width:260px">
            <option value="en">English</option>
            <option value="tr">Türkçe</option>
          </select>

          <label style="margin-top:16px" id="themeLabel">Appearance · 50 Themes</label>
          <div class="theme-grid" id="themeGrid"></div>

          <div class="toolbar">
            <button class="action" onclick="toast(t('saved'))" data-i18n="saveChanges">Save changes</button>
          </div>
        </div>
      </section>

    </div></main>
  </div>
</div>

<!-- Generator Modal -->
<div class="overlay" id="generatorModal"><div class="modal">
  <h2 data-i18n="genTitle">Generate DARKIOS Key</h2>
  <label data-i18n="customKey">Custom Key</label>
  <input class="field" id="customCode" placeholder="Leave empty for automatic key">
  <div class="time-combined-row">
    <label for="durationType" data-i18n="time">Time</label>
    <select class="field" id="durationType" onchange="toggleAmountField()">
      <option value="day" data-i18n="uDay">Day (1DAY)</option>
      <option value="week" data-i18n="uWeek">Week (1WEEK)</option>
      <option value="month" data-i18n="uMonth">Month (1MONTH)</option>
      <option value="year" data-i18n="uYear">Year (1YEAR)</option>
      <option value="hour" data-i18n="uHour">Hour (1HOUR)</option>
      <option value="minute" data-i18n="uMinute">Minute (1MINUTE)</option>
      <option value="lifetime" data-i18n="uLifetime">Lifetime (LIFETIME)</option>
    </select>
    <input class="field" id="durationAmount" type="number" min="1" step="1" value="1">
  </div>
  <label data-i18n="maxDevices">Maximum devices</label>
  <input class="field" id="deviceLimit" type="number" min="1" value="1">
  <div class="modal-actions">
    <button class="small-btn" onclick="closeModal('generatorModal')" data-i18n="cancel">Cancel</button>
    <button class="action" onclick="generateKey()" data-i18n="generate">Generate</button>
  </div>
</div></div>

<!-- Key Tools Modal -->
<div class="overlay" id="keyToolsModal"><div class="modal">
  <h2 data-i18n="keyTools">Key Tools</h2>
  <p class="sub" data-i18n="txtHint">Export/Import preserves remaining time, max devices, status (Active/Paused/Banned), and devices.</p>
  <div class="toolbar">
    <button class="action" onclick="exportKeys()" data-i18n="exportTxt">Export TXT</button>
    <button class="small-btn" onclick="document.getElementById('importFile').click()" data-i18n="importTxt">Import TXT</button>
    <input id="importFile" type="file" accept=".txt,text/plain" hidden>
  </div>
  <div class="modal-actions"><button class="small-btn" onclick="closeModal('keyToolsModal')" data-i18n="close">Close</button></div>
</div></div>

<!-- Manage Key & Devices Modal -->
<div class="overlay" id="manageModal"><div class="modal" id="manageContent"></div></div>

<div class="toast" id="toast"></div>

<script>
const API_URL = 'backend.php';
const THEME_STORE = 'darkios_theme_50_v1';
const LANG_STORE = 'darkios_lang_v1';
const ALLOWED_USER = 'Ayxan';
const ALLOWED_PASS = 'Wear5555';

const THEMES_50 = [
  ['Light Cream','#b9b9b9','#f5f3ef','#fbfaf8','#e6e2dc','#171717','#898985','#111111','#ffffff'],
  ['Pure Snow','#cbd2d9','#f8fafc','#ffffff','#e2e8f0','#0f172a','#64748b','#0f172a','#ffffff'],
  ['Warm Alabaster','#c7c0b4','#f7f4ee','#fffdf9','#e5dfd5','#1f1c18','#7c7468','#2b2620','#ffffff'],
  ['Midnight Slate','#080b10','#111622','#182030','#283449','#f1f5f9','#94a3b8','#38bdf8','#06121c'],
  ['Graphite Dark','#0b0b0c','#17181a','#202226','#32363e','#f3f4f6','#9ca3af','#e5e7eb','#111214'],
  ['Obsidian Void','#030304','#090a0d','#111318','#222630','#f8fafc','#8b95a5','#a855f7','#ffffff'],
  ['Nordic Frost','#b8c4d0','#eceff4','#f8fafc','#d8dee9','#2e3440','#5e6778','#5e81ac','#ffffff'],
  ['Nordic Night','#141923','#2e3440','#3b4252','#4c566a','#eceff4','#a3b1c6','#88c0d0','#141923'],
  ['Dracula Night','#12101a','#1e1b2e','#28243d','#3b3559','#f8f8f2','#a69fc9','#bd93f9','#12101a'],
  ['Cyber Neon','#050814','#0b1024','#121936','#22305c','#e0f2fe','#7dd3fc','#00f5d4','#041214'],
  ['Emerald Forest','#9eb3a6','#e6efe9','#f5faf7','#c8dcd0','#132a1e','#527361','#15803d','#ffffff'],
  ['Deep Pine','#07140e','#0f241a','#173326','#264d3b','#ecfdf5','#86b39c','#22c55e','#05180d'],
  ['Ocean Breeze','#9bb8cc','#e3f0f8','#f4faff','#c4dceb','#0c2d48','#4a7391','#0284c7','#ffffff'],
  ['Abyssal Navy','#050d18','#0b192c','#122640','#1f3d63','#e6f1ff','#7ea4cc','#3b82f6','#ffffff'],
  ['Royal Violet','#b5a8cc','#efeaf7','#faf8fd','#d8cee9','#231736','#6e5b8c','#7c3aed','#ffffff'],
  ['Velvet Plum','#140a1f','#211233','#2d1945','#47286b','#f5efff','#b89fd9','#c084fc','#180826'],
  ['Crimson Rose','#cfa6ae','#f9ecef','#fff8f9','#ebd0d6','#3b121c','#8f5563','#e11d48','#ffffff'],
  ['Blood Ruby','#1a060b','#2b0c14','#3d121d','#5c1c2c','#ffe4e9','#c98395','#f43f5e','#ffffff'],
  ['Sunset Amber','#cfb28f','#fbf0e1','#fffaf2','#ead4b7','#382209','#8f6a3d','#d97706','#ffffff'],
  ['Copper Rust','#1a0f0a','#2b1911','#3d2419','#5c3828','#ffede4','#c99780','#ea580c','#ffffff'],
  ['Sandstone','#c4b7a3','#f2ece1','#fcf9f3','#ddd2c0','#2e261b','#7d705d','#854d0e','#ffffff'],
  ['Sage Olive','#b2baa6','#edf0e8','#f8faf5','#d3d9c8','#242b1c','#68735b','#4d7c0f','#ffffff'],
  ['Lavender Mist','#bdb5d4','#efecf8','#faf8ff','#d7d0ec','#261f3d','#6d638f','#6366f1','#ffffff'],
  ['Mint Fresh','#9ec7be','#e3f4f0','#f4fcfa','#c2e3dc','#0e332c','#4a786f','#0d9488','#ffffff'],
  ['Peach Blossom','#d4b0a5','#fcf0ec','#fff9f7','#edd5cd','#3b1d14','#8f5c4d','#f97316','#ffffff'],
  ['Coral Reef','#cfaba4','#faece9','#fff8f7','#ebd1cc','#3b1610','#8f544a','#ef4444','#ffffff'],
  ['Teal Lagoon','#96bdbd','#e1f1f1','#f3fafa','#bedede','#0c2f2f','#467373','#0f766e','#ffffff'],
  ['Indigo Dusk','#9ea8cc','#e6eaf7','#f5f7fc','#c6cfe8','#171f3d','#525f8c','#4338ca','#ffffff'],
  ['Charcoal Gold','#14120c','#1c1911','#262218','#3d3626','#fef9e7','#b8aa82','#eab308','#14120c'],
  ['Carbon Lime','#0c120b','#141c12','#1c291a','#2d422a','#eefbe9','#8ab082','#84cc16','#0c120b'],
  ['Tokyo Night','#10121d','#1a1b26','#24283b','#363d5c','#c0caf5','#7982a9','#7aa2f7','#10121d'],
  ['Catppuccin Mocha','#11111b','#1e1e2e','#28283d','#3b3b54','#cdd6f4','#9399b2','#cba6f7','#11111b'],
  ['Catppuccin Latte','#bcc2d1','#eff1f5','#e6e9ef','#ccd0da','#4c4f69','#7c7f93','#8839ef','#ffffff'],
  ['Gruvbox Dark','#141210','#1d2021','#282828','#3c3836','#ebdbb2','#a89984','#fabd2f','#1d2021'],
  ['Gruvbox Light','#c7ba9f','#fbf1c7','#f9f5d7','#ebdbb2','#3c3836','#7c6f64','#b57614','#ffffff'],
  ['Solarized Dark','#001e26','#002b36','#073642','#134b5a','#fdf6e3','#839496','#2aa198','#002b36'],
  ['Solarized Light','#c9c2ad','#fdf6e3','#eee8d5','#dcd4bc','#073642','#657b83','#268bd2','#ffffff'],
  ['Monokai Pro','#141214','#19181a','#221f22','#363237','#fcfcfa','#939293','#ff6188','#ffffff'],
  ['Rose Pine Moon','#191724','#232136','#2a273f','#3e3a59','#e0def4','#908caa','#eb6f92','#191724'],
  ['Rose Pine Dawn','#d4c9c2','#faf4ed','#fffaf3','#e8ddd4','#575279','#797593','#d7827e','#ffffff'],
  ['Iceberg','#b4c0d4','#e8edf5','#f5f8fc','#cfd9e8','#1e2536','#5b6782','#3b82f6','#ffffff'],
  ['Cobalt Deep','#050d24','#091638','#0f2252','#1c3778','#e8f0ff','#7b96cc','#60a5fa','#051029'],
  ['Maroon Wine','#1a080e','#290e17','#3a1421','#572033','#fce8ef','#bd7e93','#fb7185','#1f0710'],
  ['Olive Drab','#10140c','#1a2014','#242c1c','#37422c','#eef2e6','#94a187','#a3e635','#121a08'],
  ['Titanium Gray','#9fa4ab','#e4e7eb','#f3f4f6','#cbd0d6','#1f2937','#6b7280','#374151','#ffffff'],
  ['Bronze Dusk','#17120e','#241c16','#33281f','#4d3d30','#f5ebe0','#ab9786','#d97706','#ffffff'],
  ['Cyan Pulse','#05161c','#09242e','#0f3442','#1a4e61','#e0f7fa','#75b3c4','#06b6d4','#04161c'],
  ['Magenta Glow','#1a0919','#290e27','#3b1438','#592055','#fae8fa','#bd7ebb','#e879f9','#1f071e'],
  ['Silver Mist','#bcc0c7','#eceef2','#f7f8fa','#d5d9e0','#1c1f24','#6c727d','#2563eb','#ffffff'],
  ['Pitch Black','#000000','#050505','#0c0c0c','#1f1f1f','#ffffff','#8e8e93','#0a84ff','#ffffff']
];

const I18N = {
  en: {
    username: 'Username',
    password: 'Password',
    loginBtn: 'Login',
    wrongCreds: 'Invalid username or password.',
    copyEndpoint: 'Copy Endpoint',
    overview: 'Overview',
    overviewDesc: 'Server-connected license & device management console.',
    genKey: 'Generate Key',
    openKeyList: 'Open Key List',
    settings: 'Settings',
    keyMgmt: 'Key Management',
    totalKeys: 'Total keys',
    activeKeys: 'Active keys',
    pendingApprovals: 'Pending device approvals',
    keyGen: 'Key Generator',
    keyGenDesc: 'Create keys with duration (DAY, WEEK, MONTH, YEAR, LIFETIME) and device limit.',
    keyTools: 'Key Tools',
    syncServer: '↻ Sync Server',
    keyList: 'Key List',
    exportTxt: 'Export TXT',
    importTxt: 'Import TXT',
    txtHint: 'Export/Import preserves remaining time, max devices, status (Active/Paused/Banned), and devices.',
    thKey: 'Key',
    thDuration: 'Duration / Remaining',
    thDevices: 'Devices',
    thStatus: 'Status',
    thActions: 'Actions',
    noKeys: 'No keys yet. Generate a key or import a TXT file.',
    generalSettings: 'General Settings',
    workspacePrefs: 'Workspace preferences',
    language: 'Interface Language',
    saveChanges: 'Save changes',
    genTitle: 'Generate DARKIOS Key',
    customKey: 'Custom Key',
    time: 'Time',
    uDay: 'Day (1DAY)',
    uWeek: 'Week (1WEEK)',
    uMonth: 'Month (1MONTH)',
    uYear: 'Year (1YEAR)',
    uHour: 'Hour (1HOUR)',
    uMinute: 'Minute (1MINUTE)',
    uLifetime: 'Lifetime (LIFETIME)',
    maxDevices: 'Maximum devices',
    cancel: 'Cancel',
    generate: 'Generate',
    close: 'Close',
    saved: 'Settings saved',
    copied: 'Copied',
    notStarted: 'Not activated yet',
    expired: 'Expired',
    lifetime: 'LIFETIME',
    copy: 'Copy',
    manage: 'Manage',
    del: 'Delete',
    manageTitle: 'Manage Key',
    pendingQueue: 'Pending Requests',
    accept: 'Accept',
    decline: 'Decline',
    devLimit: 'Device Limit',
    save: 'Save',
    extDur: 'Extend Duration',
    add: 'Add',
    statusCtrl: 'Status Control',
    banKey: 'Ban Key',
    unbanKey: 'Unban Key',
    tempStop: 'Temporary Stop',
    resumeKey: 'Resume Key',
    connDevs: 'Connected Devices',
    resetDevs: 'Reset Devices',
    auditHist: 'Audit History',
    noDevs: 'No connected devices yet.',
    noAudit: 'No audit records.',
    confirmDel: 'Delete this key permanently?',
    confirmReset: 'Reset all approved devices for this key?'
  },
  tr: {
    username: 'Kullanıcı Adı',
    password: 'Parola',
    loginBtn: 'Giriş Yap',
    wrongCreds: 'Kullanıcı adı veya parola hatalı.',
    copyEndpoint: 'Endpoint Kopyala',
    overview: 'Genel Bakış',
    overviewDesc: 'Sunucu bağlantılı lisans ve cihaz yönetim paneli.',
    genKey: 'Anahtar Oluştur',
    openKeyList: 'Anahtar Listesini Aç',
    settings: 'Ayarlar',
    keyMgmt: 'Anahtar Yönetimi',
    totalKeys: 'Toplam anahtar',
    activeKeys: 'Aktif anahtarlar',
    pendingApprovals: 'Bekleyen cihaz onayları',
    keyGen: 'Anahtar Oluşturucu',
    keyGenDesc: 'DAY, WEEK, MONTH, YEAR, LIFETIME süresi ve cihaz limiti ile anahtar oluşturun.',
    keyTools: 'Anahtar Araçları',
    syncServer: '↻ Sunucuyu Yenile',
    keyList: 'Anahtar Listesi',
    exportTxt: 'TXT Dışa Aktar',
    importTxt: 'TXT İçe Aktar',
    txtHint: 'TXT Dışa/İçe Aktarım kalan süreyi, cihaz limitini, durumu (Active/Paused/Banned) ve cihazları korur.',
    thKey: 'Anahtar',
    thDuration: 'Süre / Kalan',
    thDevices: 'Cihazlar',
    thStatus: 'Durum',
    thActions: 'İşlemler',
    noKeys: 'Henüz anahtar yok. Anahtar oluşturun veya TXT dosyası içe aktarın.',
    generalSettings: 'Genel Ayarlar',
    workspacePrefs: 'Çalışma alanı tercihleri',
    language: 'Arayüz Dili',
    saveChanges: 'Değişiklikleri kaydet',
    genTitle: 'DARKIOS Anahtarı Oluştur',
    customKey: 'Özel Anahtar',
    time: 'Süre',
    uDay: 'Gün (1DAY)',
    uWeek: 'Hafta (1WEEK)',
    uMonth: 'Ay (1MONTH)',
    uYear: 'Yıl (1YEAR)',
    uHour: 'Saat (1HOUR)',
    uMinute: 'Dakika (1MINUTE)',
    uLifetime: 'Sınırsız (LIFETIME)',
    maxDevices: 'Maksimum cihaz',
    cancel: 'İptal',
    generate: 'Oluştur',
    close: 'Kapat',
    saved: 'Ayarlar kaydedildi',
    copied: 'Kopyalandı',
    notStarted: 'Henüz aktifleşmedi',
    expired: 'Süresi doldu',
    lifetime: 'LIFETIME',
    copy: 'Kopyala',
    manage: 'Yönet',
    del: 'Sil',
    manageTitle: 'Anahtarı Yönet',
    pendingQueue: 'Bekleyen Cihaz İstekleri',
    accept: 'Onayla',
    decline: 'Reddet',
    devLimit: 'Cihaz Limiti',
    save: 'Kaydet',
    extDur: 'Süre Uzat',
    add: 'Ekle',
    statusCtrl: 'Durum Kontrolü',
    banKey: 'Anahtarı Yasakla',
    unbanKey: 'Yasağı Kaldır',
    tempStop: 'Geçici Durdur',
    resumeKey: 'Devam Ettir',
    connDevs: 'Bağlı Cihazlar',
    resetDevs: 'Cihazları Sıfırla',
    auditHist: 'İşlem Geçmişi',
    noDevs: 'Henüz bağlı cihaz yok.',
    noAudit: 'İşlem kaydı yok.',
    confirmDel: 'Bu anahtar kalıcı olarak silinsin mi?',
    confirmReset: 'Bu anahtarın tüm onaylı cihazları sıfırlansın mı?'
  }
};

let currentLang = localStorage.getItem(LANG_STORE) || 'en';
function t(k){ return (I18N[currentLang] || I18N.en)[k] || I18N.en[k] || k; }

function setLanguage(lang){
  currentLang = I18N[lang] ? lang : 'en';
  localStorage.setItem(LANG_STORE, currentLang);
  document.documentElement.lang = currentLang;
  applyLanguage();
  renderKeys();
}

function applyLanguage(){
  document.querySelectorAll('[data-i18n]').forEach(el => {
    el.textContent = t(el.dataset.i18n);
  });
  document.getElementById('langSelect').value = currentLang;
  document.getElementById('themeLabel').textContent =
    currentLang === 'tr' ? `Görünüm · ${THEMES_50.length} Tema` : `Appearance · ${THEMES_50.length} Themes`;
  document.getElementById('keySearch').placeholder =
    currentLang === 'tr' ? 'Anahtar ara...' : 'Search keys...';
  document.getElementById('customCode').placeholder =
    currentLang === 'tr' ? 'Otomatik anahtar için boş bırakın' : 'Leave empty for automatic key';
  document.getElementById('loginUser').placeholder = t('username');
  document.getElementById('loginPass').placeholder = t('password');
}

function toggleAmountField(){
  const isLife = document.getElementById('durationType').value === 'lifetime';
  const amt = document.getElementById('durationAmount');
  amt.disabled = isLife;
  amt.style.opacity = isLife ? '.45' : '1';
}

function applyThemeByIndex(idx){
  const item = THEMES_50[idx] || THEMES_50[0];
  const [, bg, shell, panel, line, text, muted, accent, accentText] = item;
  const root = document.documentElement.style;
  root.setProperty('--bg', bg);
  root.setProperty('--shell', shell);
  root.setProperty('--panel', panel);
  root.setProperty('--line', line);
  root.setProperty('--text', text);
  root.setProperty('--muted', muted);
  root.setProperty('--accent', accent);
  root.setProperty('--accent-text', accentText);
  localStorage.setItem(THEME_STORE, String(idx));
  document.querySelectorAll('.theme-choice').forEach((b, i) => b.classList.toggle('selected', i === idx));
  if (document.getElementById('appShell').style.display !== 'none') {
    document.body.style.background = bg;
  }
}

function renderThemeGrid(){
  const savedIdx = Math.max(0, Math.min(THEMES_50.length - 1, Number(localStorage.getItem(THEME_STORE) || 0)));
  const grid = document.getElementById('themeGrid');
  grid.innerHTML = THEMES_50.map((th, i) => `
    <button type="button" class="theme-choice ${i === savedIdx ? 'selected' : ''}" onclick="applyThemeByIndex(${i})">
      <span class="swatches">
        <i style="background:${th[2]}"></i>
        <i style="background:${th[3]}"></i>
        <i style="background:${th[7]}"></i>
      </span>
      <span>${i + 1}. ${esc(th[0])}</span>
    </button>
  `).join('');
  applyThemeByIndex(savedIdx);
}

let authCreds = { user: '', pass: '' };
let keyRecords = [];
let serverNow = Math.floor(Date.now() / 1000);
let currentManageKey = null;

function esc(s) {
  return String(s ?? '').replace(/[&<>"']/g, c => ({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;',"'":'&#39;'}[c]));
}

function showPage(name) {
  document.querySelectorAll('.nav[data-page]').forEach(n => n.classList.toggle('active', n.dataset.page === name));
  document.querySelectorAll('.page').forEach(p => p.classList.toggle('active', p.id === 'page-' + name));
}
document.querySelectorAll('.nav[data-page]').forEach(btn => btn.addEventListener('click', () => showPage(btn.dataset.page)));

function openModal(id) { document.getElementById(id).classList.add('show'); }
function closeModal(id) { document.getElementById(id).classList.remove('show'); }
function toast(msg) {
  const el = document.getElementById('toast');
  el.textContent = msg; el.style.display = 'block';
  clearTimeout(window.toastTimer);
  window.toastTimer = setTimeout(() => el.style.display = 'none', 2500);
}

async function api(action, payload = {}) {
  const res = await fetch(API_URL, {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({
      action,
      admin_user: authCreds.user,
      admin_pass: authCreds.pass,
      ...payload
    })
  });
  return await res.json();
}

async function doLogin() {
  const u = document.getElementById('loginUser').value.trim();
  const p = document.getElementById('loginPass').value;
  const err = document.getElementById('loginError');

  if (u !== ALLOWED_USER || p !== ALLOWED_PASS) {
    err.textContent = t('wrongCreds');
    return;
  }

  try {
    const res = await api('admin_login', { admin_user: u, admin_pass: p });
    if (res.success) {
      authCreds = { user: u, pass: p };
      sessionStorage.setItem('darkios_admin', JSON.stringify(authCreds));
      err.textContent = '';
      document.getElementById('loginScreen').style.display = 'none';
      document.getElementById('appShell').style.display = 'flex';
      const idx = Number(localStorage.getItem(THEME_STORE) || 0);
      document.body.style.background = (THEMES_50[idx] || THEMES_50[0])[1];
      await fetchKeys();
    } else {
      err.textContent = t('wrongCreds');
    }
  } catch (e) {
    err.textContent = t('wrongCreds');
  }
}

async function fetchKeys() {
  const res = await api('list_keys');
  if (res.success) {
    keyRecords = res.keys || [];
    serverNow = res.server_time || Math.floor(Date.now() / 1000);
    renderKeys();
    if (currentManageKey && document.getElementById('manageModal').classList.contains('show')) {
      openManage(currentManageKey);
    }
  }
}

function formatExpiry(k) {
  if (k.lifetime || k.duration_label === 'LIFETIME') return t('lifetime');
  if (!k.expires_at) return `${esc(k.duration_label)} (${t('notStarted')})`;
  const rem = k.expires_at - serverNow;
  if (rem <= 0) return t('expired');
  const d = Math.floor(rem / 86400);
  const h = Math.floor((rem % 86400) / 3600);
  const m = Math.floor((rem % 3600) / 60);
  return `${d}d ${h}h ${m}m`;
}

function pillClass(st) {
  if (st === 'Active') return 'pill';
  if (st === 'Paused') return 'pill warn';
  return 'pill red';
}

function renderKeys() {
  const tbody = document.getElementById('keyRows');
  const q = (document.getElementById('keySearch').value || '').toLowerCase();
  const filtered = keyRecords.filter(k => k.key.toLowerCase().includes(q));
  tbody.innerHTML = '';

  let pendingTotal = 0;
  keyRecords.forEach(k => pendingTotal += (k.pending_devices?.length || 0));

  filtered.forEach(k => {
    const tr = document.createElement('tr');
    const pendingCount = k.pending_devices?.length || 0;
    const approvedCount = k.approved_devices?.length || 0;

    tr.innerHTML = `
      <td>
        <div class="key-cell">
          <span>${esc(k.key)}</span>
          ${pendingCount > 0 ? `<button class="pending-dot" title="${pendingCount} pending" onclick="openManage('${esc(k.key)}')">${pendingCount}</button>` : ''}
        </div>
      </td>
      <td>${formatExpiry(k)}</td>
      <td>${approvedCount} / ${k.max_devices}</td>
      <td><span class="${pillClass(k.status)}">${esc(k.status)}</span></td>
      <td style="display:flex;gap:5px;flex-wrap:wrap">
        <button class="small-btn" onclick="copyText('${esc(k.key)}')">${t('copy')}</button>
        <button class="action" style="padding:5px 9px;font-size:10px" onclick="openManage('${esc(k.key)}')">${t('manage')}</button>
        <button class="small-btn danger" onclick="deleteKey('${esc(k.key)}')">${t('del')}</button>
      </td>
    `;
    tbody.appendChild(tr);
  });

  document.getElementById('emptyKeys').style.display = filtered.length ? 'none' : 'block';
  document.getElementById('keyTotal').textContent = keyRecords.length;
  document.getElementById('keyActive').textContent = keyRecords.filter(k => k.status === 'Active').length;
  document.getElementById('keyPending').textContent = pendingTotal;
}

async function generateKey() {
  const res = await api('create_key', {
    custom_key: document.getElementById('customCode').value.trim(),
    unit: document.getElementById('durationType').value,
    amount: document.getElementById('durationAmount').value,
    max_devices: document.getElementById('deviceLimit').value
  });
  if (res.success) {
    document.getElementById('customCode').value = '';
    closeModal('generatorModal');
    toast(res.key.key);
    await fetchKeys();
  } else {
    toast(res.message || 'Error');
  }
}

async function deleteKey(key) {
  if (!confirm(t('confirmDel'))) return;
  const res = await api('delete_key', { key });
  if (res.success) { toast(t('del')); await fetchKeys(); }
}

function openManage(keyStr) {
  currentManageKey = keyStr;
  const k = keyRecords.find(x => x.key === keyStr);
  if (!k) return;

  const approved = k.approved_devices || [];
  const pending = k.pending_devices || [];
  const audit = k.audit || [];

  const pendingHtml = pending.length ? pending.map(d => `
    <div class="dev-card" style="border-color:#e24c4c">
      <div>
        <b>${esc(d.name || 'iOS Device')}</b> <span class="pill red">Pending</span><br>
        <small>ID: ${esc(d.device_id)} · IP: ${esc(d.ip)} · Bat: ${esc(d.battery)} · Loc: ${esc(d.location)}</small>
      </div>
      <div style="display:flex;gap:5px">
        <button class="action" style="padding:4px 8px;font-size:10px" onclick="approvePending('${esc(k.key)}','${esc(d.device_id)}')">${t('accept')}</button>
        <button class="small-btn danger" onclick="declinePending('${esc(k.key)}','${esc(d.device_id)}')">${t('decline')}</button>
      </div>
    </div>
  `).join('') : `<p style="font-size:10px;color:var(--muted);margin:0">${t('noDevs')}</p>`;

  const approvedHtml = approved.length ? approved.map(d => `
    <div class="dev-card">
      <div>
        <b>${esc(d.name || 'iOS Device')}</b> <span class="pill">Approved</span><br>
        <small>ID: ${esc(d.device_id)} · IP: ${esc(d.ip)} · Bat: ${esc(d.battery)} · Loc: ${esc(d.location)} · Seen: ${esc(d.last_seen)}</small>
      </div>
    </div>
  `).join('') : `<p style="font-size:10px;color:var(--muted);margin:0">${t('noDevs')}</p>`;

  const auditHtml = audit.length ? audit.map(a => `<div class="audit-item"><b>${esc(a.time)}</b> — ${esc(a.text)}</div>`).join('') : `<div class="audit-item">${t('noAudit')}</div>`;

  document.getElementById('manageContent').innerHTML = `
    <h2>${t('manageTitle')}</h2>
    <div style="font-family:monospace;font-size:12px;margin-bottom:8px"><b>${esc(k.key)}</b> · <span class="${pillClass(k.status)}">${esc(k.status)}</span></div>
    <p style="font-size:11px;color:var(--muted);margin:0 0 10px">${t('thDuration')}: <b>${formatExpiry(k)}</b> · ${t('thDevices')}: <b>${approved.length} / ${k.max_devices}</b></p>

    ${pending.length ? `<div class="manage-box" style="border-color:#e24c4c"><h4>${t('pendingQueue')} (${pending.length})</h4>${pendingHtml}</div>` : ''}

    <div class="manage-grid">
      <div class="manage-box">
        <h4>${t('devLimit')}</h4>
        <div style="display:flex;gap:6px">
          <input class="field" id="mLimitInput" type="number" min="1" value="${k.max_devices}">
          <button class="action" onclick="updateLimit('${esc(k.key)}')">${t('save')}</button>
        </div>
      </div>
      <div class="manage-box">
        <h4>${t('extDur')}</h4>
        <div style="display:flex;gap:6px">
          <input class="field" id="mExtVal" type="number" min="1" value="1" style="width:65px">
          <select class="field" id="mExtUnit">
            <option value="day">${t('uDay')}</option>
            <option value="week">${t('uWeek')}</option>
            <option value="month">${t('uMonth')}</option>
            <option value="year">${t('uYear')}</option>
            <option value="hour">${t('uHour')}</option>
            <option value="minute">${t('uMinute')}</option>
            <option value="lifetime">${t('uLifetime')}</option>
          </select>
          <button class="action" onclick="extendDuration('${esc(k.key)}')">${t('add')}</button>
        </div>
      </div>
    </div>

    <div class="manage-box">
      <h4>${t('statusCtrl')}</h4>
      <div style="display:flex;gap:6px;flex-wrap:wrap;align-items:center">
        ${k.status === 'Banned'
          ? `<button class="action" onclick="keyAction('unban_key','${esc(k.key)}')">${t('unbanKey')}</button>`
          : `<button class="small-btn danger" onclick="keyAction('ban_key','${esc(k.key)}')">${t('banKey')}</button>`}
        ${k.status === 'Paused'
          ? `<button class="action" onclick="keyAction('resume_key','${esc(k.key)}')">${t('resumeKey')}</button>`
          : `<button class="small-btn warn" onclick="pauseKey('${esc(k.key)}')">${t('tempStop')}</button>`}
        <input class="field" id="mPauseUntil" type="datetime-local" style="width:auto">
      </div>
    </div>

    <div class="manage-box">
      <div style="display:flex;justify-content:space-between;align-items:center;margin-bottom:8px">
        <h4 style="margin:0">${t('connDevs')} (${approved.length})</h4>
        <button class="small-btn danger" onclick="resetDevices('${esc(k.key)}')">${t('resetDevs')}</button>
      </div>
      ${approvedHtml}
    </div>

    <div class="manage-box">
      <h4>${t('auditHist')}</h4>
      <div style="max-height:130px;overflow:auto">${auditHtml}</div>
    </div>

    <div class="modal-actions">
      <button class="small-btn" onclick="closeModal('manageModal')">${t('close')}</button>
    </div>
  `;
  openModal('manageModal');
}

async function updateLimit(key) {
  const max_devices = document.getElementById('mLimitInput').value;
  let res = await api('set_limit', { key, max_devices });
  if (res.need_confirm) {
    if (!confirm(res.message)) return;
    res = await api('set_limit', { key, max_devices, force: true });
  }
  if (res.success) { toast(t('saved')); await fetchKeys(); }
}

async function extendDuration(key) {
  const amount = document.getElementById('mExtVal').value;
  const unit = document.getElementById('mExtUnit').value;
  const res = await api('extend_duration', { key, amount, unit });
  if (res.success) { toast(t('saved')); await fetchKeys(); }
}

async function pauseKey(key) {
  const pause_until = document.getElementById('mPauseUntil').value;
  const res = await api('pause_key', { key, pause_until });
  if (res.success) { toast(t('saved')); await fetchKeys(); }
}

async function keyAction(action, key) {
  const res = await api(action, { key });
  if (res.success) { toast(t('saved')); await fetchKeys(); }
}

async function approvePending(key, device_id) {
  let res = await api('approve_device', { key, device_id });
  if (res.need_raise) {
    if (!confirm(res.message)) return;
    res = await api('approve_device', { key, device_id, raise_limit: true });
  }
  if (res.success) { toast(t('saved')); await fetchKeys(); }
}

async function declinePending(key, device_id) {
  const res = await api('decline_device', { key, device_id });
  if (res.success) { toast(t('saved')); await fetchKeys(); }
}

async function resetDevices(key) {
  if (!confirm(t('confirmReset'))) return;
  const res = await api('reset_devices', { key });
  if (res.success) { toast(t('saved')); await fetchKeys(); }
}

function copyText(tMsg) { navigator.clipboard?.writeText(tMsg); toast(t('copied')); }

function toBase64Utf8(str) {
  const bytes = new TextEncoder().encode(str);
  let bin = '';
  for (let i = 0; i < bytes.length; i++) bin += String.fromCharCode(bytes[i]);
  return btoa(bin);
}

function fromBase64Utf8(b64) {
  const bin = atob(b64);
  const bytes = new Uint8Array(bin.length);
  for (let i = 0; i < bin.length; i++) bytes[i] = bin.charCodeAt(i);
  return new TextDecoder().decode(bytes);
}

function exportKeys() {
  if (!keyRecords.length) { toast(t('noKeys')); return; }
  const lines = keyRecords.map(k => {
    const remSec = k.expires_at ? Math.max(0, Number(k.expires_at) - serverNow) : Number(k.duration_seconds || 0);
    const meta = {
      key: k.key,
      lifetime: !!k.lifetime || k.duration_label === 'LIFETIME',
      duration_label: k.duration_label || '1DAY',
      duration_seconds: Number(k.duration_seconds || 0),
      remaining_seconds: remSec,
      expires_at: k.expires_at || null,
      max_devices: Number(k.max_devices || 1),
      status: k.status || 'Active',
      pause_until: Number(k.pause_until || 0),
      created: k.created || '',
      approved_devices: k.approved_devices || [],
      pending_devices: k.pending_devices || [],
      audit: k.audit || []
    };
    return `${k.key}|DARKIOS_META|${toBase64Utf8(JSON.stringify(meta))}`;
  });
  const blob = new Blob([lines.join('\n') + '\n'], { type: 'text/plain' });
  const url = URL.createObjectURL(blob);
  const a = document.createElement('a'); a.href = url; a.download = 'darkios-keys.txt'; a.click();
  URL.revokeObjectURL(url);
  toast(t('exportTxt'));
}

document.getElementById('importFile').addEventListener('change', async function() {
  const file = this.files[0]; if (!file) return;
  const text = await file.text();
  const lines = text.split(/\r?\n/).map(x => x.trim()).filter(Boolean);
  const entries = [];

  for (const line of lines) {
    if (line.includes('|DARKIOS_META|')) {
      const parts = line.split('|DARKIOS_META|');
      try {
        const parsed = JSON.parse(fromBase64Utf8(parts[1]));
        parsed.key = parsed.key || parts[0].trim();
        entries.push(parsed);
      } catch (e) {
        entries.push({ key: parts[0].trim() });
      }
    } else {
      entries.push({ key: line });
    }
  }

  const res = await api('import_keys_full', { entries });
  this.value = '';
  if (res.success) {
    toast(`+${res.added} / ~${res.updated}`);
    await fetchKeys();
  }
});

document.getElementById('shareBtn').addEventListener('click', () => {
  const endpoint = location.origin + location.pathname.replace(/[^/]+$/, 'backend.php');
  copyText(endpoint);
});

document.getElementById('signout').addEventListener('click', () => {
  sessionStorage.removeItem('darkios_admin');
  location.reload();
});

document.querySelectorAll('.overlay').forEach(o => o.addEventListener('click', e => { if (e.target === o) o.classList.remove('show'); }));

renderThemeGrid();
applyLanguage();
toggleAmountField();

const saved = sessionStorage.getItem('darkios_admin');
if (saved) {
  try {
    const parsed = JSON.parse(saved);
    if (parsed.user === ALLOWED_USER && parsed.pass === ALLOWED_PASS) {
      authCreds = parsed;
      document.getElementById('loginScreen').style.display = 'none';
      document.getElementById('appShell').style.display = 'flex';
      const idx = Number(localStorage.getItem(THEME_STORE) || 0);
      document.body.style.background = (THEMES_50[idx] || THEMES_50[0])[1];
      fetchKeys();
    } else {
      sessionStorage.removeItem('darkios_admin');
    }
  } catch(e) {}
}
</script>
</body>
</html>
