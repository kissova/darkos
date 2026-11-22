<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Control Center Dashboard</title>
<style>
:root{--bg:#b9b9b9;--shell:#f5f3ef;--panel:#fbfaf8;--line:#e6e2dc;--muted:#898985;--text:#171717;--green:#13a879;--yellow:#e7bd26;--red:#e24c4c;--shadow:0 2px 10px #0000000a}
*{box-sizing:border-box}body{margin:0;background:#080808;font:14px Inter,-apple-system,BlinkMacSystemFont,"Segoe UI",sans-serif;color:var(--text);min-height:100vh;display:grid;place-items:center;padding:22px}
button,input,select{font:inherit}button{cursor:pointer}
.app{width:min(1280px,100%);height:min(900px,calc(100vh - 44px));min-height:650px;background:var(--shell);border:1px solid #dedbd5;border-radius:15px;overflow:hidden;box-shadow:0 18px 55px #00000018;display:none;flex-direction:column}
.topbar{height:43px;border-bottom:1px solid var(--line);display:flex;align-items:center;justify-content:space-between;padding:0 15px 0 18px;flex-shrink:0}
.brand{display:flex;align-items:center;gap:10px;font-size:12px}
.top-actions{display:flex;align-items:center;gap:14px;color:#777}.top-actions button{border:0;background:none;color:inherit;padding:4px;display:flex;align-items:center;justify-content:center}.share{background:#111!important;color:#fff!important;border-radius:8px;padding:7px 13px!important;font-size:12px}
.body{display:flex;min-height:0;flex:1}.rail{width:42px;border-right:1px solid var(--line);display:flex;align-items:center;flex-direction:column;gap:15px;padding:14px 0;color:#777;flex-shrink:0}.rail button{border:0;background:none;color:inherit;font-size:17px;width:28px;height:24px;border-radius:6px}.rail button:hover{background:#eae7e1}
.sidebar{width:66px;border-right:1px solid var(--line);padding:10px 8px 8px;display:flex;flex-direction:column;gap:8px;overflow:auto;flex-shrink:0}
.nav{display:flex;align-items:center;justify-content:center;width:100%;height:38px;border:0;background:transparent;padding:7px 8px;border-radius:7px;color:#171717;font-size:12px;margin:2px 0}.nav:hover,.nav.active{background:#eae7e1}.nav .ico{width:18px;height:18px;color:#777;display:flex;align-items:center;justify-content:center}.nav .ico svg{width:17px;height:17px;stroke:currentColor;fill:none;stroke-width:1.65;stroke-linecap:round;stroke-linejoin:round}
.main{flex:1;min-width:0;overflow:auto;padding:14px 20px 22px}.content{max-width:960px;margin:0 auto}.page-title{font-size:14px;font-weight:600;margin:0 0 14px}
.panel{background:var(--panel);border:1px solid var(--line);border-radius:11px;box-shadow:var(--shadow)}
.page{display:none}.page.active{display:block}.section-panel{padding:15px;margin-bottom:10px}.section-panel h3{font-size:13px;margin:0 0 12px}.section-panel p{font-size:11px;color:#888}
.toolbar{display:flex;gap:8px;align-items:center;margin:12px 0;flex-wrap:wrap}.toolbar input{flex:1;min-width:120px}.field{border:1px solid #e1ded8;border-radius:7px;background:#fff;padding:8px 10px;font-size:11px;color:#222}.action{background:#111;color:#fff;border:0;border-radius:7px;padding:8px 12px;font-size:11px;display:inline-flex;align-items:center;gap:6px}.small-btn{border:1px solid #dedbd5;background:#fff;border-radius:6px;padding:5px 9px;font-size:10px;color:#222}.small-btn.danger{border-color:#efc7c4;color:#c24c42;background:#fff8f7}.small-btn.warn{border-color:#ecd9a2;color:#99750b;background:#fffdf5}
.table{width:100%;border-collapse:collapse;font-size:11px}.table th{text-align:left;color:#888;font-weight:500;padding:10px 8px;border-bottom:1px solid var(--line);white-space:nowrap}.table td{padding:10px 8px;border-bottom:1px solid #efede9;vertical-align:middle}
.pill{font-size:9px;border-radius:20px;padding:4px 8px;background:#e7f5ef;color:#07865f;display:inline-block;font-weight:600}.pill.warn{background:#fbf3d9;color:#99750b}.pill.red{background:#fae9e7;color:#c24c42}
.stats{display:grid;grid-template-columns:repeat(3,1fr);gap:8px;margin-bottom:10px}.stat{padding:13px}.stat b{font-size:19px}.stat small{display:block;color:#888;font-size:10px;margin-top:5px}
.overlay{position:fixed;inset:0;background:#0006;display:none;align-items:center;justify-content:center;padding:18px;z-index:20}.overlay.show{display:flex}.modal{width:min(620px,100%);max-height:90vh;overflow:auto;background:#fbfaf8;border:1px solid #ddd8d0;border-radius:13px;padding:18px;box-shadow:0 20px 70px #0004;color:#171717}.modal h2{font-size:15px;margin:0 0 12px}.modal label{display:block;font-size:10px;color:#777;margin:10px 0 4px}.modal input,.modal select{width:100%}.modal-actions{display:flex;justify-content:flex-end;gap:8px;margin-top:16px}
.toast{position:fixed;bottom:20px;left:50%;transform:translateX(-50%);background:#171717;color:#fff;padding:9px 14px;border-radius:8px;font-size:11px;display:none;z-index:40}
.ui-icon{width:16px;height:16px;stroke:currentColor;fill:none;stroke-width:1.65;stroke-linecap:round;stroke-linejoin:round;vertical-align:middle}
.key-cell{display:flex;align-items:center;gap:7px;font-family:ui-monospace,SFMono-Regular,monospace;font-size:11px;word-break:break-all}
.pending-dot{width:16px;height:16px;border-radius:50%;background:#e24c4c;color:#fff;font-size:9px;font-weight:700;display:inline-flex;align-items:center;justify-content:center;border:0;flex-shrink:0;box-shadow:0 0 0 2px #fae9e7;animation:pulse 1.5s infinite}
@keyframes pulse{0%{transform:scale(1)}50%{transform:scale(1.12)}100%{transform:scale(1)}}
.manage-box{border:1px solid #e6e2dc;background:#fff;border-radius:9px;padding:11px;margin-top:10px}
.manage-box h4{margin:0 0 8px;font-size:12px}
.manage-grid{display:grid;grid-template-columns:1fr 1fr;gap:10px}
.dev-card{border:1px solid #ece8e2;border-radius:8px;padding:8px 10px;margin-bottom:6px;font-size:11px;display:flex;justify-content:space-between;align-items:center;gap:8px;background:#fbfaf8}
.audit-item{font-size:10px;padding:5px 0;border-bottom:1px solid #f0ede8;color:#555}
.time-combined-row{display:grid;grid-template-columns:62px minmax(0,1fr) minmax(76px,.72fr);align-items:center;gap:10px;margin-top:14px}
.time-combined-row label{margin:0!important}
.overview-welcome{min-height:180px;display:flex;flex-direction:column;justify-content:center}.overview-welcome h2{margin:0 0 8px;font-size:22px}.overview-welcome p{color:var(--muted);margin:0 0 18px}

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

/* Themes */
body[data-theme="light"]{--shell:#f5f3ef;--panel:#fbfaf8;--line:#e6e2dc;--text:#171717;--bg:#b9b9b9}
body[data-theme="midnight"]{--shell:#171a21;--panel:#20242d;--line:#343a46;--text:#f1f3f7;--bg:#0d1016}
body[data-theme="graphite"]{--shell:#252525;--panel:#303030;--line:#454545;--text:#f4f4f4;--bg:#111}
body[data-theme="ocean"]{--shell:#eaf2f7;--panel:#f8fcff;--line:#d3e1eb;--text:#142b3b;--bg:#b6cad8}
body[data-theme="forest"]{--shell:#edf2ed;--panel:#f9fcf8;--line:#d5e0d5;--text:#1b3024;--bg:#b8c8b9}
body[data-theme="lavender"]{--shell:#f1eef7;--panel:#fcfaff;--line:#dfd8ec;--text:#2a213a;--bg:#c9bfd9}
body[data-theme="rose"]{--shell:#f8eeee;--panel:#fffafa;--line:#eadada;--text:#382323;--bg:#d6bcbc}
body[data-theme="sand"]{--shell:#f3eee4;--panel:#fffdf8;--line:#e4dac9;--text:#332b20;--bg:#cbbda6}
body[data-theme="midnight"] .nav,body[data-theme="graphite"] .nav{color:var(--text)}
body[data-theme="midnight"] .nav:hover,body[data-theme="midnight"] .nav.active,body[data-theme="graphite"] .nav:hover,body[data-theme="graphite"] .nav.active{background:#343a46}
body[data-theme="midnight"] .field,body[data-theme="graphite"] .field{background:#171a21;color:#f1f3f7;border-color:#3c424e}
body[data-theme="midnight"] .table td,body[data-theme="graphite"] .table td{border-color:#343a46}
.theme-grid{display:grid;grid-template-columns:repeat(4,minmax(0,1fr));gap:8px;margin-top:9px}
.theme-choice{border:1px solid var(--line);border-radius:8px;background:var(--panel);color:var(--text);padding:9px 7px;text-align:left;font-size:10px}
.theme-choice.selected{outline:2px solid #777;outline-offset:1px}
.swatches{display:flex;gap:3px;margin-bottom:7px}.swatches i{display:block;height:18px;flex:1;border-radius:3px;background:#f5f3ef;border:1px solid #ddd}
.theme-choice[data-theme="midnight"] .swatches i{background:#171a21;border-color:#454b58}
.theme-choice[data-theme="graphite"] .swatches i{background:#303030;border-color:#555}
.theme-choice[data-theme="ocean"] .swatches i{background:#dceaf3;border-color:#b8d0df}
.theme-choice[data-theme="forest"] .swatches i{background:#dce9dc;border-color:#b6cbb8}
.theme-choice[data-theme="lavender"] .swatches i{background:#e7dff2;border-color:#cbbde0}
.theme-choice[data-theme="rose"] .swatches i{background:#f0dede;border-color:#dfc2c2}
.theme-choice[data-theme="sand"] .swatches i{background:#e9ddc9;border-color:#d6c4a8}

@media(max-width:700px){body{padding:0}.app{height:100vh;min-height:0;border-radius:0}.login-screen{width:100vw;height:100vh;min-height:0;border:0;grid-template-columns:1fr}.login-art{display:none}.manage-grid{grid-template-columns:1fr}.rail{display:none}.sidebar{width:54px;padding:8px 4px}.main{padding:12px 9px}}
</style>
</head>
<body data-theme="light">

<svg aria-hidden="true" width="0" height="0" style="position:absolute;overflow:hidden">
 <symbol id="i-grid" viewBox="0 0 24 24"><rect x="3" y="3" width="7" height="7" rx="1.5"/><rect x="14" y="3" width="7" height="7" rx="1.5"/><rect x="3" y="14" width="7" height="7" rx="1.5"/><rect x="14" y="14" width="7" height="7" rx="1.5"/></symbol>
 <symbol id="i-box" viewBox="0 0 24 24"><path d="m12 3 8 4.5v9L12 21l-8-4.5v-9L12 3Z"/><path d="m4.5 7.7 7.5 4.4 7.5-4.4M12 12v9"/></symbol>
 <symbol id="i-key" viewBox="0 0 24 24"><circle cx="8" cy="15" r="5"/><path d="m11.5 11.5 8-8 2 2-2 2 2 2-3 3-2-2-2 2"/></symbol>
 <symbol id="i-chart" viewBox="0 0 24 24"><path d="M4 19V5M4 19h17"/><path d="m7 15 4-4 3 2 6-7"/></symbol>
 <symbol id="i-settings" viewBox="0 0 24 24"><circle cx="12" cy="12" r="3"/><path d="m19.4 15 .1.1 1.2 1-1.4 2.4-1.5-.6a8 8 0 0 1-1.8 1l-.3 1.6h-2.8l-.3-1.6a8 8 0 0 1-1.8-1l-1.5.6-1.4-2.4 1.2-1a8 8 0 0 1 0-2l-1.2-1 1.4-2.4 1.5.6a8 8 0 0 1 1.8-1l.3-1.6h2.8l.3 1.6a8 8 0 0 1 1.8 1l1.5-.6 1.4 2.4-1.2 1a8 8 0 0 1 0 2Z"/></symbol>
 <symbol id="i-lock" viewBox="0 0 24 24"><rect x="4" y="10" width="16" height="11" rx="2"/><path d="M8 10V7a4 4 0 0 1 8 0v3"/></symbol>
 <symbol id="i-log-out" viewBox="0 0 24 24"><path d="M10 17l5-5-5-5m5 5H3"/><path d="M12 3h7a2 2 0 0 1 2 2v14a2 2 0 0 1-2 2h-7"/></symbol>
 <symbol id="i-bell" viewBox="0 0 24 24"><path d="M18 9a6 6 0 0 0-12 0c0 7-3 7-3 9h18c0-2-3-2-3-9M10 21h4"/></symbol>
 <symbol id="i-sun" viewBox="0 0 24 24"><circle cx="12" cy="12" r="4"/><path d="M12 2v2m0 16v2M4.9 4.9l1.4 1.4m11.4 11.4 1.4 1.4M2 12h2m16 0h2M4.9 19.1l1.4-1.4M17.7 6.3l1.4-1.4"/></symbol>
 <symbol id="i-plus" viewBox="0 0 24 24"><path d="M12 5v14M5 12h14"/></symbol>
</svg>

<div class="login-screen" id="loginScreen">
 <div class="login-left">
  <form class="login-form" id="loginForm" autocomplete="off" onsubmit="doLogin(); return false;">
   <div class="login-logo" aria-hidden="true"></div>
   <label for="loginUser">Username</label>
   <div class="login-input-wrap"><svg viewBox="0 0 24 24"><circle cx="12" cy="8" r="4"/><path d="M4 21c.8-4 3.4-6 8-6s7.2 2 8 6"/></svg><input id="loginUser" placeholder="Enter username" autocomplete="username" required></div>
   <label for="loginPass">Password</label>
   <div class="login-input-wrap"><svg viewBox="0 0 24 24"><rect x="4" y="10" width="16" height="11" rx="2"/><path d="M8 10V7a4 4 0 0 1 8 0v3"/></svg><input id="loginPass" type="password" placeholder="Enter password" autocomplete="current-password" required></div>
   <button class="login-submit" type="submit">Login</button>
   <div class="login-error" id="loginError" role="alert"></div>
  </form>
 </div>
 <div class="login-art" aria-hidden="true"><div class="pillar one"></div><div class="pillar two"></div><div class="pillar three"></div></div>
</div>

<div class="app" id="appShell">
  <header class="topbar">
    <div class="brand"><svg width="15" height="15" viewBox="0 0 24 24" fill="none" stroke="#888" stroke-width="1.6"><rect x="3" y="3" width="18" height="18" rx="3"/><path d="M9 3v18"/></svg><span style="color:#888">DARKIOS</span><strong>Control Center</strong></div>
    <div class="top-actions">
      <button title="Refresh Keys" onclick="fetchKeys()"><svg class="ui-icon"><use href="#i-bell"/></svg></button>
      <button title="Settings" onclick="showPage('general')"><svg class="ui-icon"><use href="#i-sun"/></svg></button>
      <button class="share" id="shareBtn">Copy Endpoint</button>
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
        <h1 class="page-title">Overview</h1>
        <div class="panel section-panel overview-welcome">
          <h2>DARKIOS Control Center</h2>
          <p>Server-connected license & device management console.</p>
          <div class="toolbar">
            <button class="action" onclick="openModal('generatorModal')"><svg class="ui-icon"><use href="#i-plus"/></svg> Generate Key</button>
            <button class="small-btn" onclick="showPage('keys')">Open Key List</button>
            <button class="small-btn" onclick="showPage('general')">Settings</button>
          </div>
        </div>
      </section>

      <section class="page" id="page-keys">
        <h1 class="page-title">Key Management</h1>
        <div class="stats">
          <div class="panel stat"><b id="keyTotal">0</b><small>Total keys</small></div>
          <div class="panel stat"><b id="keyActive">0</b><small>Active keys</small></div>
          <div class="panel stat"><b id="keyPending">0</b><small>Pending device approvals</small></div>
        </div>
        <div class="panel section-panel">
          <h3>Key Generator</h3>
          <p>Create keys with a duration and custom device limit synced with backend.php.</p>
          <div class="toolbar">
            <button class="action" onclick="openModal('generatorModal')"><svg class="ui-icon"><use href="#i-plus"/></svg> Generate Key</button>
            <button class="small-btn" onclick="openModal('keyToolsModal')">Key Tools</button>
            <button class="small-btn" onclick="fetchKeys()">↻ Sync Server</button>
          </div>
        </div>
        <div class="panel section-panel">
          <h3>Key List</h3>
          <div class="toolbar">
            <input class="field" id="keySearch" placeholder="Search keys..." oninput="renderKeys()">
            <button class="small-btn" onclick="exportKeys()">Export TXT</button>
          </div>
          <div style="overflow-x:auto">
            <table class="table">
              <thead>
                <tr>
                  <th>Key</th>
                  <th>Duration / Expiry</th>
                  <th>Devices</th>
                  <th>Status</th>
                  <th>Actions</th>
                </tr>
              </thead>
              <tbody id="keyRows"></tbody>
            </table>
          </div>
          <p id="emptyKeys" class="sub" style="display:none">No keys yet. Generate a key or import a TXT file.</p>
        </div>
      </section>

      <section class="page" id="page-general">
        <h1 class="page-title">General Settings</h1>
        <div class="panel section-panel">
          <h3>Workspace preferences</h3>
          <label>Appearance · 8 themes</label>
          <div class="theme-grid" id="themeGrid">
            <button class="theme-choice selected" data-theme="light"><span class="swatches"><i></i><i></i><i></i></span>Light</button>
            <button class="theme-choice" data-theme="midnight"><span class="swatches"><i></i><i></i><i></i></span>Midnight</button>
            <button class="theme-choice" data-theme="graphite"><span class="swatches"><i></i><i></i><i></i></span>Graphite</button>
            <button class="theme-choice" data-theme="ocean"><span class="swatches"><i></i><i></i><i></i></span>Ocean</button>
            <button class="theme-choice" data-theme="forest"><span class="swatches"><i></i><i></i><i></i></span>Forest</button>
            <button class="theme-choice" data-theme="lavender"><span class="swatches"><i></i><i></i><i></i></span>Lavender</button>
            <button class="theme-choice" data-theme="rose"><span class="swatches"><i></i><i></i><i></i></span>Rose</button>
            <button class="theme-choice" data-theme="sand"><span class="swatches"><i></i><i></i><i></i></span>Sand</button>
          </div>
        </div>
      </section>

    </div></main>
  </div>
</div>

<!-- Generator Modal -->
<div class="overlay" id="generatorModal"><div class="modal">
  <h2>Generate DARKIOS Key</h2>
  <label>Custom Key</label>
  <input class="field" id="customCode" placeholder="Leave empty for automatic key">
  <div class="time-combined-row">
    <label for="durationType">Time</label>
    <select class="field" id="durationType">
      <option value="day">Day</option><option value="week">Week</option><option value="month">Month</option><option value="year">Year</option><option value="hour">Hour</option><option value="minute">Minute</option>
    </select>
    <input class="field" id="durationAmount" type="number" min="1" step="1" value="1">
  </div>
  <label>Maximum devices</label>
  <input class="field" id="deviceLimit" type="number" min="1" value="1">
  <div class="modal-actions">
    <button class="small-btn" onclick="closeModal('generatorModal')">Cancel</button>
    <button class="action" onclick="generateKey()">Generate</button>
  </div>
</div></div>

<!-- Key Tools Modal -->
<div class="overlay" id="keyToolsModal"><div class="modal">
  <h2>Key Tools</h2>
  <div class="toolbar">
    <button class="action" onclick="exportKeys()">Export TXT</button>
    <button class="small-btn" onclick="document.getElementById('importFile').click()">Import TXT</button>
    <input id="importFile" type="file" accept=".txt,text/plain" hidden>
  </div>
  <div class="modal-actions"><button class="small-btn" onclick="closeModal('keyToolsModal')">Close</button></div>
</div></div>

<!-- Manage Key & Devices Modal -->
<div class="overlay" id="manageModal"><div class="modal" id="manageContent"></div></div>

<div class="toast" id="toast"></div>

<script>
const API_URL = 'backend.php';
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
  const t = document.getElementById('toast');
  t.textContent = msg; t.style.display = 'block';
  clearTimeout(window.toastTimer);
  window.toastTimer = setTimeout(() => t.style.display = 'none', 2500);
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
  try {
    const res = await api('admin_login', { admin_user: u, admin_pass: p });
    if (res.success) {
      authCreds = { user: u, pass: p };
      sessionStorage.setItem('darkios_admin', JSON.stringify(authCreds));
      err.textContent = '';
      document.getElementById('loginScreen').style.display = 'none';
      document.getElementById('appShell').style.display = 'flex';
      document.body.style.background = 'var(--bg)';
      await fetchKeys();
    } else {
      err.textContent = res.message || 'Username or password is incorrect.';
    }
  } catch (e) {
    err.textContent = 'Backend connection error.';
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
  if (!k.expires_at) return `${esc(k.duration_label)} (Not activated yet)`;
  const rem = k.expires_at - serverNow;
  if (rem <= 0) return 'Expired';
  const d = Math.floor(rem / 86400);
  const h = Math.floor((rem % 86400) / 3600);
  const m = Math.floor((rem % 3600) / 60);
  return `${d}d ${h}h ${m}m left`;
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
          ${pendingCount > 0 ? `<button class="pending-dot" title="${pendingCount} pending device request(s)" onclick="openManage('${esc(k.key)}', true)">${pendingCount}</button>` : ''}
        </div>
      </td>
      <td>${formatExpiry(k)}</td>
      <td>${approvedCount} / ${k.max_devices}</td>
      <td><span class="${pillClass(k.status)}">${esc(k.status)}</span></td>
      <td style="display:flex;gap:5px;flex-wrap:wrap">
        <button class="small-btn" onclick="copyText('${esc(k.key)}')">Copy</button>
        <button class="action" style="padding:5px 9px;font-size:10px" onclick="openManage('${esc(k.key)}')">Manage</button>
        <button class="small-btn danger" onclick="deleteKey('${esc(k.key)}')">Delete</button>
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
    toast('Key created: ' + res.key.key);
    await fetchKeys();
  } else {
    toast(res.message || 'Error');
  }
}

async function deleteKey(key) {
  if (!confirm('Delete this key permanently?')) return;
  const res = await api('delete_key', { key });
  if (res.success) { toast('Key deleted'); await fetchKeys(); }
}

function openManage(keyStr, focusPending = false) {
  currentManageKey = keyStr;
  const k = keyRecords.find(x => x.key === keyStr);
  if (!k) return;

  const approved = k.approved_devices || [];
  const pending = k.pending_devices || [];
  const audit = k.audit || [];

  const pendingHtml = pending.length ? pending.map(d => `
    <div class="dev-card" style="border-color:#e24c4c;background:#fff8f7">
      <div>
        <b>${esc(d.name || 'iOS Device')}</b> <span class="pill red">Pending</span><br>
        <small>ID: ${esc(d.device_id)} · IP: ${esc(d.ip)} · Bat: ${esc(d.battery)} · Loc: ${esc(d.location)}</small>
      </div>
      <div style="display:flex;gap:5px">
        <button class="action" style="padding:4px 8px;font-size:10px" onclick="approvePending('${esc(k.key)}','${esc(d.device_id)}')">Accept</button>
        <button class="small-btn danger" onclick="declinePending('${esc(k.key)}','${esc(d.device_id)}')">Decline</button>
      </div>
    </div>
  `).join('') : '<p style="font-size:10px;color:#888;margin:0">No pending requests.</p>';

  const approvedHtml = approved.length ? approved.map(d => `
    <div class="dev-card">
      <div>
        <b>${esc(d.name || 'iOS Device')}</b> <span class="pill">Approved</span><br>
        <small>ID: ${esc(d.device_id)} · IP: ${esc(d.ip)} · Bat: ${esc(d.battery)} · Loc: ${esc(d.location)} · Seen: ${esc(d.last_seen)}</small>
      </div>
    </div>
  `).join('') : '<p style="font-size:10px;color:#888;margin:0">No connected devices yet.</p>';

  const auditHtml = audit.length ? audit.map(a => `<div class="audit-item"><b>${esc(a.time)}</b> — ${esc(a.text)}</div>`).join('') : '<div class="audit-item">No audit records.</div>';

  document.getElementById('manageContent').innerHTML = `
    <h2>Manage Key</h2>
    <div style="font-family:monospace;font-size:12px;margin-bottom:8px"><b>${esc(k.key)}</b> · <span class="${pillClass(k.status)}">${esc(k.status)}</span></div>
    <p style="font-size:11px;color:#666;margin:0 0 10px">Expiry: <b>${formatExpiry(k)}</b> · Active Devices: <b>${approved.length} / ${k.max_devices}</b></p>

    ${pending.length ? `<div class="manage-box" style="border-color:#e24c4c"><h4>🔴 New-Device Approval Queue (${pending.length})</h4>${pendingHtml}</div>` : ''}

    <div class="manage-grid">
      <div class="manage-box">
        <h4>1. Device Limit</h4>
        <div style="display:flex;gap:6px">
          <input class="field" id="mLimitInput" type="number" min="1" value="${k.max_devices}">
          <button class="action" onclick="updateLimit('${esc(k.key)}')">Save</button>
        </div>
      </div>
      <div class="manage-box">
        <h4>2. Extend Duration</h4>
        <div style="display:flex;gap:6px">
          <input class="field" id="mExtVal" type="number" min="1" value="1" style="width:65px">
          <select class="field" id="mExtUnit">
            <option value="day">Day</option><option value="week">Week</option><option value="month">Month</option><option value="year">Year</option><option value="hour">Hour</option><option value="minute">Minute</option>
          </select>
          <button class="action" onclick="extendDuration('${esc(k.key)}')">Add</button>
        </div>
      </div>
    </div>

    <div class="manage-box">
      <h4>3 & 4. Status Control (Ban / Temporary Stop)</h4>
      <div style="display:flex;gap:6px;flex-wrap:wrap;align-items:center">
        ${k.status === 'Banned'
          ? `<button class="action" onclick="keyAction('unban_key','${esc(k.key)}')">Unban Key</button>`
          : `<button class="small-btn danger" onclick="keyAction('ban_key','${esc(k.key)}')">Ban Key</button>`}
        ${k.status === 'Paused'
          ? `<button class="action" onclick="keyAction('resume_key','${esc(k.key)}')">Resume Key</button>`
          : `<button class="small-btn warn" onclick="pauseKey('${esc(k.key)}')">Temporary Stop</button>`}
        <input class="field" id="mPauseUntil" type="datetime-local" style="width:auto" title="Optional stop-until date/time">
      </div>
    </div>

    <div class="manage-box">
      <div style="display:flex;justify-content:space-between;align-items:center;margin-bottom:8px">
        <h4 style="margin:0">5 & 7. Connected Devices (${approved.length})</h4>
        <button class="small-btn danger" onclick="resetDevices('${esc(k.key)}')">Reset Devices</button>
      </div>
      ${approvedHtml}
    </div>

    <div class="manage-box">
      <h4>8. Audit History</h4>
      <div style="max-height:130px;overflow:auto">${auditHtml}</div>
    </div>

    <div class="modal-actions">
      <button class="small-btn" onclick="closeModal('manageModal')">Close</button>
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
  if (res.success) { toast('Device limit updated'); await fetchKeys(); }
}

async function extendDuration(key) {
  const amount = document.getElementById('mExtVal').value;
  const unit = document.getElementById('mExtUnit').value;
  const res = await api('extend_duration', { key, amount, unit });
  if (res.success) { toast('Duration extended'); await fetchKeys(); }
}

async function pauseKey(key) {
  const pause_until = document.getElementById('mPauseUntil').value;
  const res = await api('pause_key', { key, pause_until });
  if (res.success) { toast('Key paused'); await fetchKeys(); }
}

async function keyAction(action, key) {
  const res = await api(action, { key });
  if (res.success) { toast('Updated'); await fetchKeys(); }
}

async function approvePending(key, device_id) {
  let res = await api('approve_device', { key, device_id });
  if (res.need_raise) {
    if (!confirm(res.message)) return;
    res = await api('approve_device', { key, device_id, raise_limit: true });
  }
  if (res.success) { toast('Device approved'); await fetchKeys(); }
}

async function declinePending(key, device_id) {
  const res = await api('decline_device', { key, device_id });
  if (res.success) { toast('Device declined'); await fetchKeys(); }
}

async function resetDevices(key) {
  if (!confirm('Reset all approved devices for this key? They will need to authenticate again.')) return;
  const res = await api('reset_devices', { key });
  if (res.success) { toast('Devices reset'); await fetchKeys(); }
}

function copyText(t) {
  navigator.clipboard?.writeText(t);
  toast('Copied');
}

function exportKeys() {
  const content = keyRecords.map(k => k.key).join('\n');
  if (!content) { toast('No keys to export'); return; }
  const blob = new Blob([content + '\n'], { type: 'text/plain' });
  const url = URL.createObjectURL(blob);
  const a = document.createElement('a'); a.href = url; a.download = 'darkios-keys.txt'; a.click();
  URL.revokeObjectURL(url);
}

document.getElementById('importFile').addEventListener('change', async function() {
  const file = this.files[0]; if (!file) return;
  const text = await file.text();
  const lines = text.split(/\r?\n/).map(x => x.trim()).filter(Boolean);
  const res = await api('import_keys', { keys: lines });
  this.value = '';
  if (res.success) { toast(res.added + ' keys imported'); await fetchKeys(); }
});

document.getElementById('shareBtn').addEventListener('click', () => {
  const endpoint = location.origin + location.pathname.replace(/[^/]+$/, 'backend.php');
  copyText(endpoint);
  toast('API Endpoint copied: ' + endpoint);
});

document.getElementById('signout').addEventListener('click', () => {
  sessionStorage.removeItem('darkios_admin');
  location.reload();
});

document.querySelectorAll('.overlay').forEach(o => o.addEventListener('click', e => { if (e.target === o) o.classList.remove('show'); }));
document.querySelectorAll('.theme-choice').forEach(btn => btn.addEventListener('click', () => {
  document.body.dataset.theme = btn.dataset.theme;
  document.querySelectorAll('.theme-choice').forEach(b => b.classList.toggle('selected', b === btn));
}));

// Auto-restore session
const saved = sessionStorage.getItem('darkios_admin');
if (saved) {
  try {
    authCreds = JSON.parse(saved);
    document.getElementById('loginScreen').style.display = 'none';
    document.getElementById('appShell').style.display = 'flex';
    document.body.style.background = 'var(--bg)';
    fetchKeys();
  } catch(e) {}
}
</script>
</body>
</html>
