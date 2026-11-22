<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Control Center Dashboard</title>
<style>
:root{--bg:#b9b9b9;--shell:#f5f3ef;--panel:#fbfaf8;--line:#e6e2dc;--muted:#898985;--text:#171717;--green:#13a879;--yellow:#e7bd26;--red:#e24c4c;--shadow:0 2px 10px #0000000a}
*{box-sizing:border-box}body{margin:0;background:var(--bg);font:14px Inter,-apple-system,BlinkMacSystemFont,"Segoe UI",sans-serif;color:var(--text);min-height:100vh;display:grid;place-items:center;padding:22px}
button,input,select{font:inherit}button{cursor:pointer}
.app{width:min(1280px,100%);height:min(900px,calc(100vh - 44px));min-height:650px;background:var(--shell);border:1px solid #dedbd5;border-radius:15px;overflow:hidden;box-shadow:0 18px 55px #00000018;display:flex;flex-direction:column}
.topbar{height:43px;border-bottom:1px solid var(--line);display:flex;align-items:center;justify-content:space-between;padding:0 15px 0 18px;flex-shrink:0}
.brand{display:flex;align-items:center;gap:10px;font-size:12px}.brandmark{width:13px;height:13px;border:1px solid #aaa;border-radius:3px;display:inline-block;position:relative}.brandmark:after{content:"";position:absolute;left:5px;top:0;bottom:0;border-left:1px solid #aaa}
.top-actions{display:flex;align-items:center;gap:17px;color:#777}.top-actions button{border:0;background:none;color:inherit;padding:4px}.share{background:#111!important;color:#fff!important;border-radius:8px;padding:7px 13px!important}
.body{display:flex;min-height:0;flex:1}.rail{width:42px;border-right:1px solid var(--line);display:flex;align-items:center;flex-direction:column;gap:15px;padding:14px 0;color:#777;flex-shrink:0}.rail button{border:0;background:none;color:inherit;font-size:17px;width:28px;height:24px;border-radius:6px}.rail button:hover{background:#eae7e1}
.sidebar{width:66px;border-right:1px solid var(--line);padding:10px 8px 8px;display:flex;flex-direction:column;overflow:auto;flex-shrink:0}.group-title{font-size:10px;color:#888;margin:3px 5px 8px;text-transform:uppercase;letter-spacing:.04em}.nav{display:flex;align-items:center;justify-content:center;gap:0;width:100%;border:0;background:transparent;text-align:left;padding:7px 8px;border-radius:7px;color:#171717;font-size:12px;margin-bottom:2px}.nav:hover,.nav.active{background:#eae7e1}.nav .ico{width:18px;height:18px;color:#777;display:flex;align-items:center;justify-content:center}.nav .ico svg{width:17px;height:17px;stroke:currentColor;fill:none;stroke-width:1.65;stroke-linecap:round;stroke-linejoin:round}.nav .count{display:none}.nav-label{display:none}.sidebar .group-title{display:none}.sidebar .nav{height:38px;margin:2px 0}.sidebar .nav-section{margin-top:9px}.group-title{font-size:0;height:7px;margin:4px 0 7px}.nav-section{margin-top:10px}.upgrade{display:none}.nav .count{margin-left:auto;font-size:11px;color:#555}.nav .green{color:var(--green)}.nav-section{margin-top:12px}.upgrade{margin-top:auto;background:linear-gradient(120deg,#f1e9f2,#e8dce9);border:1px solid #e2d4e4;border-radius:9px;padding:10px;font-size:11px;line-height:1.45}.upgrade strong{font-size:12px}.upgrade button{float:right;background:#8f4bb0;color:#fff;border:0;border-radius:7px;padding:6px 9px;font-size:10px}
.main{flex:1;min-width:0;overflow:auto;padding:14px 20px 22px}.content{max-width:850px;margin:0 auto}.page-title{font-size:14px;font-weight:600;margin:0 0 14px}
.cards3{display:grid;grid-template-columns:repeat(3,minmax(0,1fr));gap:8px}.panel{background:var(--panel);border:1px solid var(--line);border-radius:11px;box-shadow:var(--shadow)}.metric{padding:12px 12px 10px;min-height:93px}.metric-head{font-size:9px;color:#858580;display:flex;justify-content:space-between;text-transform:uppercase;letter-spacing:.03em}.metric-value{font-size:12px;font-weight:600;margin-top:22px}.metric-value span{color:#858580;font-weight:400}.meter{height:5px;background:#e7e5e0;border-radius:8px;margin-top:8px;overflow:hidden}.meter i{display:block;height:100%;border-radius:8px}.metric-foot{font-size:9px;color:#888;margin-top:7px}
.activity{margin-top:8px;padding:12px 10px 10px}.panel-head{display:flex;align-items:center;justify-content:space-between;font-size:12px;font-weight:600}.panel-head small{font-size:10px;color:#888;font-weight:400}.month-nav{display:flex;align-items:center;gap:9px;color:#888;font-size:11px}.month-nav button{border:0;background:none;color:#888}
.heat-wrap{display:flex;gap:8px;margin-top:16px}.days{display:flex;flex-direction:column;justify-content:space-around;color:#888;font-size:9px;padding:9px 0}.heatmap{flex:1;display:grid;grid-template-columns:repeat(26,1fr);grid-template-rows:repeat(5,10px);gap:4px 5px;min-width:0}.heat{background:#f0efec;border-radius:1px}.heat.l1{background:#c5e9dd}.heat.l2{background:#7fd2b5}.heat.l3{background:#37b98e}.heat.l4{background:#07996e}
.two{display:grid;grid-template-columns:1fr 1fr;gap:8px;margin-top:8px}.chart{padding:12px 10px 9px;min-height:215px}.chart-title{display:flex;justify-content:space-between;font-size:11px;font-weight:600}.tabs{display:flex;gap:8px;color:#888;font-size:10px}.tabs span{padding:3px 5px;border-radius:5px}.tabs .selected{background:#eeece7;color:#222}.sub{font-size:10px;color:#888;margin-top:7px}.chart svg{width:100%;height:125px;margin-top:8px;overflow:visible}.axis{fill:none;stroke:#e8e5df;stroke-width:1}.line{fill:none;stroke:#d77a24;stroke-width:1.7}.dot{fill:#fff;stroke:#555;stroke-width:1}.bar{fill:#eeece8}.quick{margin-top:8px;padding:12px 10px}.quick-actions{display:flex;align-items:center;gap:15px;margin-top:12px;flex-wrap:wrap}.quick-actions button{border:0;background:none;color:#777;font-size:11px;padding:5px}.quick-actions .primary{background:#111;color:#fff;border-radius:7px;margin-left:auto;padding:7px 11px}
.integrations{display:grid;grid-template-columns:1fr 1fr;gap:8px;margin-top:8px}.integration{padding:11px 10px}.integration h3{font-size:12px;margin:0 0 7px}.integration p{font-size:10px;color:#888;margin:0 0 12px}.connect-row{border-top:1px solid var(--line);padding:10px 6px;display:flex;align-items:center;justify-content:space-between;font-size:11px}.connect-row small{display:block;color:#888;margin-top:4px}.connect-row button,.small-btn{border:1px solid #dedbd5;background:#fff;border-radius:6px;padding:5px 9px;font-size:10px}
.page{display:none}.page.active{display:block}.section-panel{padding:15px;margin-bottom:10px}.section-panel h3{font-size:13px;margin:0 0 12px}.section-panel p{font-size:11px;color:#888}.toolbar{display:flex;gap:8px;align-items:center;margin:12px 0}.toolbar input{flex:1;min-width:100px}.field{border:1px solid #e1ded8;border-radius:7px;background:#fff;padding:8px 10px;font-size:11px;color:#222}.action{background:#111;color:#fff;border:0;border-radius:7px;padding:8px 12px;font-size:11px}.table{width:100%;border-collapse:collapse;font-size:11px}.table th{text-align:left;color:#888;font-weight:500;padding:10px 8px;border-bottom:1px solid var(--line)}.table td{padding:11px 8px;border-bottom:1px solid #efede9}.pill{font-size:9px;border-radius:20px;padding:4px 7px;background:#e7f5ef;color:#07865f}.pill.warn{background:#fbf3d9;color:#99750b}.pill.red{background:#fae9e7;color:#c24c42}
.stats{display:grid;grid-template-columns:repeat(3,1fr);gap:8px;margin-bottom:10px}.stat{padding:13px}.stat b{font-size:19px}.stat small{display:block;color:#888;font-size:10px;margin-top:5px}
.overlay{position:fixed;inset:0;background:#0006;display:none;align-items:center;justify-content:center;padding:18px;z-index:5}.overlay.show{display:flex}.modal{width:min(420px,100%);background:#fbfaf8;border:1px solid #ddd8d0;border-radius:13px;padding:18px;box-shadow:0 20px 70px #0004}.modal h2{font-size:15px;margin:0 0 14px}.modal label{display:block;font-size:10px;color:#777;margin:11px 0 5px}.modal input,.modal select{width:100%}.modal-actions{display:flex;justify-content:flex-end;gap:8px;margin-top:17px}.toast{position:fixed;bottom:20px;left:50%;transform:translateX(-50%);background:#171717;color:#fff;padding:9px 14px;border-radius:8px;font-size:11px;display:none;z-index:8}
@media(max-width:850px){body{padding:0}.app{height:100vh;min-height:0;border-radius:0}.sidebar{width:205px}.main{padding:13px}.cards3{grid-template-columns:1fr}.metric{min-height:75px}.metric-value{margin-top:12px}.two,.integrations{grid-template-columns:1fr}}
@media(max-width:560px){.rail{display:none}.sidebar{width:58px;padding:9px 5px}.nav{font-size:0;padding:9px 5px}.main{padding:12px 9px}.two{grid-template-columns:1fr}.topbar{height:42px}.brand{font-size:10px}.cards3{grid-template-columns:1fr}.stats{grid-template-columns:1fr 1fr}.heatmap{gap:3px 2px}.quick-actions{gap:4px}.quick-actions .primary{margin-left:0}}
.ui-icon{width:17px;height:17px;stroke:currentColor;fill:none;stroke-width:1.65;stroke-linecap:round;stroke-linejoin:round;vertical-align:middle}.top-actions button{display:flex;align-items:center;justify-content:center}\n
body{background:var(--bg)}
.login-screen{width:min(1060px,calc(100vw - 48px));min-height:600px;height:min(760px,calc(100vh - 48px));background:#0b0b0b;border:7px solid #1b1b1b;outline:1px solid #292929;display:grid;grid-template-columns:1fr 1.12fr;overflow:hidden;color:#f5f5f5;position:relative}
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
.pillar{position:absolute;bottom:-10px;width:24%;height:95%;opacity:.76;background:radial-gradient(circle,#aaa 0.7px,transparent 1px) 0 0/5px 5px,linear-gradient(90deg,transparent 12%,#888 13%,transparent 16%,transparent 27%,#aaa 28%,transparent 31%,transparent 67%,#999 68%,transparent 71%);mask-image:linear-gradient(to bottom,transparent 0%,#000 16%,#000 85%,transparent 100%)}
.pillar:before{content:"";position:absolute;left:-18%;top:8%;width:136%;height:13%;border:2px dotted #888;border-bottom:0;border-radius:50% 50% 0 0}
.pillar:after{content:"";position:absolute;left:-25%;bottom:0;width:150%;height:17%;background:radial-gradient(ellipse at center,#888 0 1px,transparent 1.5px) 0 0/5px 5px}
.pillar.one{left:7%;height:100%;width:29%}.pillar.two{left:39%;height:81%;width:25%}.pillar.three{right:5%;height:100%;width:27%}
@media(max-width:700px){.login-screen{width:100vw;height:100vh;min-height:0;border:0;outline:0;grid-template-columns:1fr}.login-left{padding:35px 28px}.login-form{max-width:340px}.login-logo{margin-bottom:48px}.login-art{display:none}}
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
@media(max-width:560px){.theme-grid{grid-template-columns:repeat(2,minmax(0,1fr))}}


/* Login page */
body{background:#080808}
.app{display:none}
.login-screen{width:min(1060px,calc(100vw - 48px));height:min(760px,calc(100vh - 48px));min-height:560px;background:#0b0b0b;border:7px solid #1b1b1b;outline:1px solid #292929;display:grid;grid-template-columns:1fr 1.12fr;overflow:hidden;color:#f5f5f5}
.login-left{display:flex;align-items:center;justify-content:center;padding:42px}
.login-form{width:min(320px,100%)}
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
.key-row{word-break:break-all}.key-actions{display:flex;gap:6px}
@media(max-width:700px){.login-screen{width:100vw;height:100vh;min-height:0;border:0;outline:0;grid-template-columns:1fr}.login-left{padding:35px 28px}.login-form{max-width:340px}.login-logo{margin-bottom:48px}.login-art{display:none}}


.time-row{display:grid;grid-template-columns:1fr 2fr;align-items:center;gap:12px;margin-top:12px}
.time-row label{margin:0}
.time-row select{width:100%}
#generatorModal .modal{max-width:470px}
#keyToolsModal .modal{max-width:400px}
#generatorModal .modal>label{margin-top:12px}
#generatorModal .sub{line-height:1.45}
@media(max-width:480px){.time-row{grid-template-columns:90px 1fr}}


.time-value-row{display:grid;grid-template-columns:minmax(0,1fr) auto;align-items:center;gap:12px;margin-top:8px}
.time-value-row input{width:100%;min-width:0}
.time-value-row span{min-width:64px;font-size:13px;color:var(--text);font-weight:600;text-transform:lowercase}

</style>
</head>
<body data-theme="light">

<svg aria-hidden="true" width="0" height="0" style="position:absolute;overflow:hidden">
 <symbol id="i-grid" viewBox="0 0 24 24"><rect x="3" y="3" width="7" height="7" rx="1.5"/><rect x="14" y="3" width="7" height="7" rx="1.5"/><rect x="3" y="14" width="7" height="7" rx="1.5"/><rect x="14" y="14" width="7" height="7" rx="1.5"/></symbol>
 <symbol id="i-box" viewBox="0 0 24 24"><path d="m12 3 8 4.5v9L12 21l-8-4.5v-9L12 3Z"/><path d="m4.5 7.7 7.5 4.4 7.5-4.4M12 12v9"/></symbol>
 <symbol id="i-key" viewBox="0 0 24 24"><circle cx="8" cy="15" r="5"/><path d="m11.5 11.5 8-8 2 2-2 2 2 2-3 3-2-2-2 2"/></symbol>
 <symbol id="i-chart" viewBox="0 0 24 24"><path d="M4 19V5M4 19h17"/><path d="m7 15 4-4 3 2 6-7"/></symbol>
 <symbol id="i-building" viewBox="0 0 24 24"><rect x="4" y="3" width="16" height="18" rx="1"/><path d="M8 7h2m4 0h2M8 11h2m4 0h2M8 15h2m4 0h2M10 21v-3h4v3"/></symbol>
 <symbol id="i-wallet" viewBox="0 0 24 24"><rect x="3" y="5" width="18" height="15" rx="2"/><path d="M3 9h18M16 14h2"/><path d="M6 5V3h12v2"/></symbol>
 <symbol id="i-settings" viewBox="0 0 24 24"><circle cx="12" cy="12" r="3"/><path d="m19.4 15 .1.1 1.2 1-1.4 2.4-1.5-.6a8 8 0 0 1-1.8 1l-.3 1.6h-2.8l-.3-1.6a8 8 0 0 1-1.8-1l-1.5.6-1.4-2.4 1.2-1a8 8 0 0 1 0-2l-1.2-1 1.4-2.4 1.5.6a8 8 0 0 1 1.8-1l.3-1.6h2.8l.3 1.6a8 8 0 0 1 1.8 1l1.5-.6 1.4 2.4-1.2 1a8 8 0 0 1 0 2Z"/></symbol>
 <symbol id="i-clock" viewBox="0 0 24 24"><circle cx="12" cy="12" r="9"/><path d="M12 7v5l3 2"/></symbol>
 <symbol id="i-lock" viewBox="0 0 24 24"><rect x="4" y="10" width="16" height="11" rx="2"/><path d="M8 10V7a4 4 0 0 1 8 0v3"/></symbol>
 <symbol id="i-archive" viewBox="0 0 24 24"><path d="M4 4h16v4H4zM6 8v12h12V8M10 12h4"/></symbol>
 <symbol id="i-trash" viewBox="0 0 24 24"><path d="M4 7h16M9 7V4h6v3m3 0-1 14H7L6 7m3 4v6m6-6v6"/></symbol>
 <symbol id="i-globe" viewBox="0 0 24 24"><circle cx="12" cy="12" r="9"/><path d="M3 12h18M12 3a15 15 0 0 1 0 18M12 3a15 15 0 0 0 0 18"/></symbol>
 <symbol id="i-help" viewBox="0 0 24 24"><circle cx="12" cy="12" r="9"/><path d="M9.5 9a2.6 2.6 0 1 1 4.6 1.7c-1.1 1.1-2.1 1.4-2.1 3M12 17h.01"/></symbol>
 <symbol id="i-book" viewBox="0 0 24 24"><path d="M4 5.5A2.5 2.5 0 0 1 6.5 3H20v17H6.5A2.5 2.5 0 0 0 4 22z"/><path d="M4 5.5v14A2.5 2.5 0 0 1 6.5 17H20"/></symbol>
 <symbol id="i-message" viewBox="0 0 24 24"><path d="M4 5h16v12H9l-5 4z"/></symbol>
 <symbol id="i-log-out" viewBox="0 0 24 24"><path d="M10 17l5-5-5-5m5 5H3"/><path d="M12 3h7a2 2 0 0 1 2 2v14a2 2 0 0 1-2 2h-7"/></symbol>
 <symbol id="i-bell" viewBox="0 0 24 24"><path d="M18 9a6 6 0 0 0-12 0c0 7-3 7-3 9h18c0-2-3-2-3-9M10 21h4"/></symbol>
 <symbol id="i-sun" viewBox="0 0 24 24"><circle cx="12" cy="12" r="4"/><path d="M12 2v2m0 16v2M4.9 4.9l1.4 1.4m11.4 11.4 1.4 1.4M2 12h2m16 0h2M4.9 19.1l1.4-1.4M17.7 6.3l1.4-1.4"/></symbol>
 <symbol id="i-file" viewBox="0 0 24 24"><path d="M6 3h8l5 5v13H6zM14 3v6h5"/></symbol>
 <symbol id="i-plus" viewBox="0 0 24 24"><path d="M12 5v14M5 12h14"/></symbol>
 <symbol id="i-terminal" viewBox="0 0 24 24"><rect x="3" y="4" width="18" height="16" rx="2"/><path d="m7 9 3 3-3 3m6 0h4"/></symbol>
 <symbol id="i-code" viewBox="0 0 24 24"><path d="m8 8-4 4 4 4m8-8 4 4-4 4m-3-11-2 14"/></symbol>
 <symbol id="i-chevron" viewBox="0 0 24 24"><path d="m9 18 6-6-6-6"/></symbol>
 <symbol id="i-spark" viewBox="0 0 24 24"><path d="m12 2 1.8 7.2L21 12l-7.2 2.8L12 22l-1.8-7.2L3 12l7.2-2.8z"/></symbol>
</svg>



<div class="login-screen" id="loginScreen">
 <div class="login-left">
  <form class="login-form" id="loginForm" autocomplete="off" onsubmit="doLogin(); return false;">
   <div class="login-logo" aria-hidden="true"></div>
   <label for="loginUser">Username</label>
   <div class="login-input-wrap"><svg viewBox="0 0 24 24"><circle cx="12" cy="8" r="4"/><path d="M4 21c.8-4 3.4-6 8-6s7.2 2 8 6"/></svg><input id="loginUser" placeholder="Enter username" autocomplete="username" required></div>
   <label for="loginPass">Password</label>
   <div class="login-input-wrap"><svg viewBox="0 0 24 24"><rect x="4" y="10" width="16" height="11" rx="2"/><path d="M8 10V7a4 4 0 0 1 8 0v3"/></svg><input id="loginPass" type="password" placeholder="Enter password" autocomplete="current-password" required></div>
   <button class="login-submit" type="button" onclick="doLogin()">Login</button>
   <div class="login-error" id="loginError" role="alert"></div>
  </form>
 </div>
 <div class="login-art" aria-hidden="true"><div class="pillar one"></div><div class="pillar two"></div><div class="pillar three"></div></div>
</div>

<div class="app">
  <header class="topbar">
    <div class="brand"><svg width="15" height="15" viewBox="0 0 24 24" fill="none" stroke="#888" stroke-width="1.6"><rect x="3" y="3" width="18" height="18" rx="3"/><path d="M9 3v18"/></svg><span style="color:#888">AB</span><strong>Control Center</strong><span style="color:#888">⌄</span></div>
    <div class="top-actions"><button title="Notifications"><svg class="ui-icon"><use href="#i-bell"/></svg></button><button title="Appearance"><svg class="ui-icon"><use href="#i-sun"/></svg></button><button title="Documents"><svg class="ui-icon"><use href="#i-file"/></svg></button><button class="share" id="shareBtn">Share</button></div>
  </header>
  <div class="body">
    <aside class="rail"><button title="Dashboard"><svg class="ui-icon"><use href="#i-grid"/></svg></button><button title="Projects"><svg class="ui-icon"><use href="#i-box"/></svg></button><button title="Activity"><svg class="ui-icon"><use href="#i-chart"/></svg></button><button title="Access"><svg class="ui-icon"><use href="#i-lock"/></svg></button></aside>
    <aside class="sidebar">
      <div class="group-title">Core product</div>
      <button class="nav active" data-page="overview"><span class="ico"><svg><use href="#i-grid"/></svg></span><span class="nav-label">Overview</span></button>
      <button class="nav" data-page="sandbox"><span class="ico"><svg><use href="#i-box"/></svg></span><span class="nav-label">Sandbox</span> <span class="count">7 / 12</span></button>
      <button class="nav" data-page="keys"><span class="ico"><svg><use href="#i-key"/></svg></span><span class="nav-label">API Keys</span> <span class="count">3 / 4</span></button>
      <button class="nav" data-page="readiness"><span class="ico"><svg><use href="#i-chart"/></svg></span><span class="nav-label">Agent Readiness</span> <span class="count">82%</span></button>
      <div class="nav-section group-title">Organization</div>
      <button class="nav" data-page="organizations"><span class="ico"><svg><use href="#i-building"/></svg></span><span class="nav-label">Organizations</span> <span class="count">46 / 50</span></button>
      <div class="nav-section group-title">Billing</div>
      <button class="nav" data-page="billing"><span class="ico"><svg><use href="#i-wallet"/></svg></span><span class="nav-label">Billing</span> <span class="count green">$48.20</span></button>
      <div class="nav-section group-title">Settings</div>
      <button class="nav" data-page="general"><span class="ico"><svg><use href="#i-settings"/></svg></span><span class="nav-label">General</span></button>
      <button class="nav" data-page="sessions"><span class="ico"><svg><use href="#i-clock"/></svg></span><span class="nav-label">Sessions</span> <span class="count green">3 / 12</span></button>
      <button class="nav" data-page="privacy"><span class="ico"><svg><use href="#i-lock"/></svg></span><span class="nav-label">Privacy</span></button>
      <button class="nav" data-page="archived"><span class="ico"><svg><use href="#i-archive"/></svg></span><span class="nav-label">Archived Agent sessions</span></button>
      <button class="nav" data-page="deleted"><span class="ico"><svg><use href="#i-trash"/></svg></span><span class="nav-label">Recently Deleted</span></button>
      <div class="nav-section group-title">Other</div>
      <button class="nav" data-page="language"><span class="ico"><svg><use href="#i-globe"/></svg></span><span class="nav-label">Language</span></button>
      <button class="nav" data-page="help"><span class="ico"><svg><use href="#i-help"/></svg></span><span class="nav-label">Get help</span></button>
      <button class="nav" data-page="learn"><span class="ico"><svg><use href="#i-book"/></svg></span><span class="nav-label">Learn more</span></button>
      <button class="nav" data-page="feedback"><span class="ico"><svg><use href="#i-message"/></svg></span><span class="nav-label">Feedback</span></button>
      <button class="nav" data-page="signout" id="signout"><span class="ico" style="color:#d44"><svg><use href="#i-log-out"/></svg></span><span class="nav-label" style="color:#d44">Sign out</span></button>
      <div class="upgrade"><button onclick="toast('Upgrade options opened')">Upgrade</button><strong>Get 5x More with Pro</strong><br>Keep building without limits</div>
    </aside>
    <main class="main"><div class="content">
      <section class="page active" id="page-overview">
        <h1 class="page-title">Overview</h1>
        <div class="cards3">
          <div class="panel metric"><div class="metric-head"><svg class="ui-icon"><use href="#i-wallet"/></svg> Cost &amp; billing <span>›</span></div><div class="metric-value">$48.20 <span>/ $100.00 (1.2M tokens)</span></div><div class="meter"><i style="width:48%;background:var(--green)"></i></div><div class="metric-foot">Next invoice: Apr 1, 2026 ↗</div></div>
          <div class="panel metric"><div class="metric-head"><svg class="ui-icon"><use href="#i-box"/></svg> Sandboxes <span>›</span></div><div class="metric-value">3 / 20 active</div><div class="meter"><i style="width:72%;background:var(--yellow)"></i></div><div class="metric-foot">20 slots / $1,200 ↗</div></div>
          <div class="panel metric"><div class="metric-head"><svg class="ui-icon"><use href="#i-building"/></svg> Organization <span>›</span></div><div class="metric-value">46 / 50 seats (92%)</div><div class="meter"><i style="width:92%;background:var(--red)"></i></div><div class="metric-foot">2 active now · 5 pending ↗</div></div>
        </div>
        <div class="panel activity"><div class="panel-head">Activity <div class="month-nav"><button>‹</button>Jan - Jul 2026<button>›</button></div></div><div class="sub">Peak: <b style="color:#222">3.2k tokens (Jan 14)</b> ⓘ</div><div class="heat-wrap"><div class="days"><span>Mon</span><span>Wed</span><span>Fri</span></div><div class="heatmap" id="heatmap"></div></div></div>
        <div class="two">
          <div class="panel chart"><div class="chart-title">Additional Tokens <div class="tabs"><span>All</span><span class="selected">7d</span><span>1m</span><span>6m</span><span>1y</span></div></div><div class="sub">Avg 5.42K (23$)</div><svg viewBox="0 0 330 145" preserveAspectRatio="none"><path class="axis" d="M30 8V125H320 M30 95H320 M30 65H320 M30 35H320"/><g fill="#888" font-size="9"><text x="1" y="128">0</text><text x="0" y="98">250k</text><text x="0" y="68">500k</text><text x="0" y="38">750k</text><text x="0" y="11">1.25M</text><text x="35" y="141">Mon</text><text x="90" y="141">Tue</text><text x="145" y="141">Wed</text><text x="200" y="141">Thu</text><text x="255" y="141">Fri</text><text x="300" y="141">Sun</text></g><path class="line" d="M30 124 C65 122 85 116 110 105 S150 77 180 76 S225 70 248 88 S286 83 320 48"/><circle class="dot" cx="180" cy="76" r="2.7"/></svg></div>
          <div class="panel chart"><div class="chart-title">Usage by Model <div class="tabs"><span>All</span><span class="selected">7d</span><span>1m</span><span>6m</span><span>1y</span></div></div><div class="sub">Avg 5.42K (23$)</div><svg viewBox="0 0 330 145" preserveAspectRatio="none"><path class="axis" d="M28 8V125H320 M28 95H320 M28 65H320 M28 35H320"/><g fill="#888" font-size="9"><text x="0" y="128">0</text><text x="0" y="98">10k</text><text x="0" y="68">20k</text><text x="0" y="38">30k</text><text x="0" y="11">50k</text></g><g><rect class="bar" x="42" y="70" width="22" height="55"/><rect class="bar" x="82" y="40" width="22" height="85"/><rect class="bar" x="122" y="62" width="22" height="63"/><rect class="bar" x="162" y="83" width="22" height="42"/><rect class="bar" x="202" y="94" width="22" height="31"/><rect class="bar" x="242" y="77" width="22" height="48"/><rect class="bar" x="282" y="88" width="22" height="37"/></g><g font-size="15"><circle cx="53" cy="59" r="4" fill="none" stroke="#777"/><rect x="90" y="27" width="9" height="9" rx="2" fill="none" stroke="#777"/><path d="m136 48 5 5-5 5-5-5z" fill="none" stroke="#777"/><path d="M169 70h8m-4-4v8" stroke="#777"/><circle cx="213" cy="83" r="4" fill="none" stroke="#777"/><path d="m250 64 6 6-6 6-6-6z" fill="none" stroke="#777"/><path d="M288 77h9m-9 4h9" stroke="#777"/></g></svg><div class="sub">Claude 3.5: 32.4k tokens (64% of total volume)</div></div>
        </div>
        <div class="panel quick"><div class="panel-head">Quick Actions</div><div class="quick-actions"><button onclick="toast('Logs panel opened')"><svg class="ui-icon"><use href="#i-terminal"/></svg> View Logs ›</button><button onclick="toast('Playground opened')"><svg class="ui-icon"><use href="#i-code"/></svg> Open playground ›</button><button onclick="toast('Budget alert settings opened')"><svg class="ui-icon"><use href="#i-bell"/></svg> Set Budget Alert ›</button><button class="primary" onclick="openModal('generatorModal')"><svg class="ui-icon"><use href="#i-plus"/></svg> Create API Key</button></div></div>
        <div class="integrations">
          <div class="panel integration"><h3>◉ GitHub</h3><p>Manage your repository access and team sync</p><div class="connect-row"><div>▤ Organization<small>2 installations · 7 repositories connected</small></div><span>›</span></div><div class="connect-row"><div>♙ Personal<small>Access your personal repositories</small></div><button onclick="toast('GitHub connected')">Connect</button></div></div>
          <div class="panel integration"><h3>◆ GitLab</h3><p>Manage your repository access and team sync</p><div class="connect-row"><div>▤ Organization<small>Sync projects and shared usage</small></div><button onclick="toast('GitLab connected')">Connect</button></div><div class="connect-row"><div>♙ Personal<small>Access your personal projects</small></div><button onclick="toast('GitLab connected')">Connect</button></div></div>
        </div>
      </section>
      <section class="page" id="page-sandbox"><h1 class="page-title">Sandbox</h1><div class="stats"><div class="panel stat"><b>7 / 12</b><small>Sandbox environments</small></div><div class="panel stat"><b>3</b><small>Currently active</small></div><div class="panel stat"><b>9</b><small>Available slots</small></div></div><div class="panel section-panel"><h3>Sandbox environments</h3><div class="toolbar"><input class="field" placeholder="Search sandboxes..."><button class="action" onclick="toast('New sandbox created')">＋ New sandbox</button></div><table class="table"><thead><tr><th>Name</th><th>Status</th><th>Region</th><th>Last active</th><th></th></tr></thead><tbody><tr><td>Development-01</td><td><span class="pill">Active</span></td><td>US East</td><td>2 min ago</td><td>•••</td></tr><tr><td>Testing-02</td><td><span class="pill">Active</span></td><td>EU West</td><td>18 min ago</td><td>•••</td></tr><tr><td>Staging-01</td><td><span class="pill warn">Idle</span></td><td>US West</td><td>Yesterday</td><td>•••</td></tr></tbody></table></div></section>
      <section class="page" id="page-keys">
 <h1 class="page-title">Key Management</h1>
 <div class="stats">
  <div class="panel stat"><b id="keyTotal">0</b><small>Total keys</small></div>
  <div class="panel stat"><b id="keyActive">0</b><small>Active keys</small></div>
  <div class="panel stat"><b id="keyDevices">—</b><small>Device limit</small></div>
 </div>
 <div class="panel section-panel">
  <h3>Key Generator</h3>
  <p>Create keys with a duration and a custom device limit.</p>
  <div class="toolbar"><button class="action" onclick="openModal('generatorModal')"><svg class="ui-icon"><use href="#i-plus"/></svg> Generate Key</button><button class="small-btn" onclick="openModal('keyToolsModal')">Key Tools</button></div>
 </div>
 <div class="panel section-panel">
  <h3>Key List</h3>
  <div class="toolbar"><input class="field" id="keySearch" placeholder="Search keys..." oninput="renderKeys()"><button class="small-btn" onclick="exportKeys()">Export all</button></div>
  <div style="overflow-x:auto"><table class="table"><thead><tr><th>Key</th><th>Duration</th><th>Max devices</th><th>Created</th><th>Status</th><th></th></tr></thead><tbody id="keyRows"></tbody></table></div>
  <p id="emptyKeys" class="sub">No keys yet. Generate a key or import a TXT file.</p>
 </div>
</section>
<section class="page" id="page-readiness"><h1 class="page-title">Agent Readiness</h1><div class="panel section-panel"><h3>Readiness score</h3><div style="font-size:42px;font-weight:650">82<span style="font-size:18px;color:#888">%</span></div><div class="meter"><i style="width:82%;background:var(--green)"></i></div><p>Your workspace is nearly ready. Complete the remaining checks to improve reliability.</p></div><div class="panel section-panel"><h3>Checklist</h3><table class="table"><tbody><tr><td>API key configured</td><td><span class="pill">Complete</span></td></tr><tr><td>Sandbox environment</td><td><span class="pill">Complete</span></td></tr><tr><td>Usage limits</td><td><span class="pill warn">Review</span></td></tr><tr><td>Team access</td><td><span class="pill">Complete</span></td></tr></tbody></table></div></section>
      <section class="page" id="page-organizations"><h1 class="page-title">Organizations</h1><div class="stats"><div class="panel stat"><b>46 / 50</b><small>Seats used</small></div><div class="panel stat"><b>2</b><small>Active now</small></div><div class="panel stat"><b>5</b><small>Pending invites</small></div></div><div class="panel section-panel"><h3>Members</h3><div class="toolbar"><input class="field" placeholder="Search members..."><button class="action" onclick="toast('Invite form opened')">＋ Invite member</button></div><table class="table"><tbody><tr><td>Alex Morgan</td><td>Owner</td><td><span class="pill">Active</span></td></tr><tr><td>Sam Lee</td><td>Admin</td><td><span class="pill">Active</span></td></tr><tr><td>Jordan Kim</td><td>Member</td><td><span class="pill warn">Pending</span></td></tr></tbody></table></div></section>
      <section class="page" id="page-billing"><h1 class="page-title">Billing</h1><div class="stats"><div class="panel stat"><b>$48.20</b><small>Current usage</small></div><div class="panel stat"><b>$100.00</b><small>Monthly budget</small></div><div class="panel stat"><b>1.2M</b><small>Tokens used</small></div></div><div class="panel section-panel"><h3>Payment overview</h3><p>Next invoice: April 1, 2026</p><div class="meter"><i style="width:48%;background:var(--green)"></i></div><div class="toolbar"><button class="action" onclick="toast('Billing settings opened')">Manage billing</button><button class="small-btn" onclick="toast('Invoices downloaded')">Download invoices</button></div></div></section>
      <section class="page" id="page-general"><h1 class="page-title">General Settings</h1><div class="panel section-panel"><h3>Workspace preferences</h3><label>Workspace name</label><input class="field" style="width:100%" value="My Workspace"><label>Default region</label><select class="field" style="width:100%"><option>US East</option><option>EU West</option><option>Asia Pacific</option></select><label>Appearance · 8 themes</label>
<div class="theme-grid" id="themeGrid">
<button class="theme-choice selected" data-theme="light"><span class="swatches"><i></i><i></i><i></i></span>Light</button>
<button class="theme-choice" data-theme="midnight"><span class="swatches"><i></i><i></i><i></i></span>Midnight</button>
<button class="theme-choice" data-theme="graphite"><span class="swatches"><i></i><i></i><i></i></span>Graphite</button>
<button class="theme-choice" data-theme="ocean"><span class="swatches"><i></i><i></i><i></i></span>Ocean</button>
<button class="theme-choice" data-theme="forest"><span class="swatches"><i></i><i></i><i></i></span>Forest</button>
<button class="theme-choice" data-theme="lavender"><span class="swatches"><i></i><i></i><i></i></span>Lavender</button>
<button class="theme-choice" data-theme="rose"><span class="swatches"><i></i><i></i><i></i></span>Rose</button>
<button class="theme-choice" data-theme="sand"><span class="swatches"><i></i><i></i><i></i></span>Sand</button>
</div><div class="toolbar"><button class="action" onclick="toast('Settings saved')">Save changes</button></div></div></section>
      <section class="page" id="page-sessions"><h1 class="page-title">Sessions</h1><div class="panel section-panel"><h3>Active sessions · 3 / 12</h3><table class="table"><tbody><tr><td>This device</td><td>iOS · Current session</td><td><span class="pill">Active</span></td></tr><tr><td>MacBook Pro</td><td>Chrome · 2 hours ago</td><td><button class="small-btn" onclick="toast('Session ended')">Revoke</button></td></tr><tr><td>Windows PC</td><td>Edge · Yesterday</td><td><button class="small-btn" onclick="toast('Session ended')">Revoke</button></td></tr></tbody></table></div></section>
      <section class="page" id="page-privacy"><h1 class="page-title">Privacy</h1><div class="panel section-panel"><h3>Privacy controls</h3><p>Manage how your workspace data is stored and shared.</p><label><input type="checkbox" checked> Allow usage analytics</label><label><input type="checkbox"> Share diagnostics to improve reliability</label><label><input type="checkbox" checked> Require confirmation for external sharing</label><div class="toolbar"><button class="action" onclick="toast('Privacy preferences saved')">Save preferences</button></div></div></section>
      <section class="page" id="page-archived"><h1 class="page-title">Archived Agent Sessions</h1><div class="panel section-panel"><h3>Archived sessions</h3><p>Sessions you archive will appear here.</p><table class="table"><tbody><tr><td>Research assistant run</td><td>Nov 20, 2026</td><td><button class="small-btn" onclick="toast('Session restored')">Restore</button></td></tr><tr><td>Code review agent</td><td>Nov 18, 2026</td><td><button class="small-btn" onclick="toast('Session restored')">Restore</button></td></tr></tbody></table></div></section>
      <section class="page" id="page-deleted"><h1 class="page-title">Recently Deleted</h1><div class="panel section-panel"><h3>Recently deleted items</h3><p>Deleted items may be restored for a limited time.</p><table class="table"><tbody><tr><td>Old test session</td><td>Deleted Nov 21, 2026</td><td><button class="small-btn" onclick="toast('Item restored')">Restore</button></td></tr></tbody></table></div></section>
      <section class="page" id="page-language"><h1 class="page-title">Language</h1><div class="panel section-panel"><h3>Display language</h3><p>Choose the language used throughout the dashboard.</p><select class="field" style="width:100%" id="languageSelect"><option>English</option><option>Türkçe</option><option>Azərbaycan dili</option><option>Русский</option></select><div class="toolbar"><button class="action" onclick="toast('Language preference saved')">Save language</button></div></div></section>
      <section class="page" id="page-help"><h1 class="page-title">Get Help</h1><div class="panel section-panel"><h3>How can we help?</h3><p>Browse support topics or contact the workspace support team.</p><button class="action" onclick="toast('Support center opened')">Open support center</button></div></section>
      <section class="page" id="page-learn"><h1 class="page-title">Learn More</h1><div class="panel section-panel"><h3>Resources</h3><p>Explore setup guides, API documentation, and best practices.</p><button class="small-btn" onclick="toast('Documentation opened')">API documentation ↗</button></div></section>
      <section class="page" id="page-feedback"><h1 class="page-title">Feedback</h1><div class="panel section-panel"><h3>Share your feedback</h3><textarea class="field" style="width:100%;min-height:100px" placeholder="Tell us what you think..."></textarea><div class="toolbar"><button class="action" onclick="toast('Thanks for your feedback!')">Send feedback</button></div></div></section>
    </div></main>
  </div>
</div>
<div class="overlay" id="generatorModal"><div class="modal">
 <h2>Generate DARKIOS Key</h2>
 <label>Custom Key</label>
 <input class="field" id="customCode" placeholder="Leave empty for automatic key" style="width:100%">
 <div class="time-row">
  <label for="durationType">Time</label>
  <select class="field" id="durationType">
   <option value="day">Day</option><option value="week">Week</option><option value="month">Month</option><option value="year">Year</option><option value="hour">Hour</option><option value="minute">Minute</option>
  </select>
 </div>
 <div class="time-value-row">
  <input class="field" id="durationAmount" type="number" min="1" step="1" value="100" aria-label="Time amount">
  <span id="durationUnitLabel">Day</span>
 </div>
 <label>Maximum devices</label>
 <input class="field" id="deviceLimit" type="number" min="1" value="1" style="width:100%">
 <p class="sub">Custom Key daxil edilərsə, nəticə həmin mətn olacaq. Boş saxlanarsa DARKIOS formatı yaradılacaq.</p>
 <div class="modal-actions"><button class="small-btn" onclick="closeModal('generatorModal')">Cancel</button><button class="action" onclick="generateKey()">Generate</button></div>
 </div></div>
<div class="overlay" id="keyToolsModal"><div class="modal">
 <h2>Key Tools</h2>
 <p class="sub">Export və import əməliyyatlarını buradan idarə et.</p>
 <div class="toolbar" style="flex-wrap:wrap">
  <button class="action" onclick="exportKeys()">Export TXT</button>
  <button class="small-btn" onclick="document.getElementById('importFile').click()">Import TXT</button>
  <input id="importFile" type="file" accept=".txt,text/plain" hidden>
 </div>
 <div class="modal-actions"><button class="small-btn" onclick="closeModal('keyToolsModal')">Close</button></div>
 </div></div>
<div class="toast" id="toast"></div>


<script>
const navs=document.querySelectorAll('.nav[data-page]');
navs.forEach(btn=>{btn.title=btn.querySelector('.nav-label')?.textContent || btn.dataset.page;btn.setAttribute('aria-label',btn.title);btn.addEventListener('click',()=>{
  navs.forEach(n=>n.classList.remove('active'));btn.classList.add('active');
  document.querySelectorAll('.page').forEach(p=>p.classList.remove('active'));
  const page=document.getElementById('page-'+btn.dataset.page);if(page)page.classList.add('active');
  document.querySelector('.main').scrollTop=0;
});});
const heat=document.getElementById('heatmap');
for(let i=0;i<130;i++){const d=document.createElement('span');d.className='heat';const v=Math.random();if(v>.83)d.classList.add('l4');else if(v>.68)d.classList.add('l3');else if(v>.48)d.classList.add('l2');else if(v>.3)d.classList.add('l1');heat.appendChild(d)}
function openModal(id){document.getElementById(id).classList.add('show')}
function closeModal(id){document.getElementById(id).classList.remove('show')}
function toast(msg){const t=document.getElementById('toast');t.textContent=msg;t.style.display='block';clearTimeout(window.toastTimer);window.toastTimer=setTimeout(()=>t.style.display='none',2300)}

const KEY_STORE='darkios_generated_keys_v1';
let keyRecords=[];
try{keyRecords=JSON.parse(localStorage.getItem(KEY_STORE)||'[]');if(!Array.isArray(keyRecords))keyRecords=[]}catch(e){keyRecords=[]}
function saveKeys(){localStorage.setItem(KEY_STORE,JSON.stringify(keyRecords));renderKeys()}
function durationCode(type,amount){
 const n=Number(amount);
 const map={day:'D',week:'W',month:'M',year:'Y',hour:'H',minute:'MIN'};
 return String(n)+map[type];
}
function randomBlock(){const chars='ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';let out='';for(let i=0;i<12;i++)out+=chars[Math.floor(Math.random()*chars.length)];return out}
function generateKey(){
 const type=document.getElementById('durationType').value;
 const amount=Math.max(1,Math.floor(Number(document.getElementById('durationAmount').value)||1));
 const devices=Math.max(1,Math.floor(Number(document.getElementById('deviceLimit').value)||1));
 const custom=document.getElementById('customCode').value.trim();
 const code=durationCode(type,amount);
 const key=custom ? custom : 'DARKIOS-'+code+'-'+randomBlock();
 if(keyRecords.some(k=>k.key===key)){toast('Duplicate key. Generate again.');return}
 keyRecords.unshift({key,duration:custom?'Custom':durationCode(type,amount),devices,created:new Date().toLocaleDateString(),status:'Active'});
 saveKeys();closeModal('generatorModal');toast('Key generated');
}
function renderKeys(){
 const tbody=document.getElementById('keyRows');if(!tbody)return;
 const q=(document.getElementById('keySearch')?.value||'').toLowerCase();
 const filtered=keyRecords.filter(k=>k.key.toLowerCase().includes(q));
 tbody.innerHTML='';
 filtered.forEach((k)=>{
  const tr=document.createElement('tr');tr.className='key-row';
  const vals=[k.key,k.duration,String(k.devices),k.created,k.status];
  vals.forEach((v,i)=>{const td=document.createElement('td');td.textContent=v;if(i===4){const pill=document.createElement('span');pill.className='pill';pill.textContent=v;td.textContent='';td.appendChild(pill)}tr.appendChild(td)});
  const action=document.createElement('td');const remove=document.createElement('button');remove.className='small-btn';remove.textContent='Delete';remove.addEventListener('click',()=>{keyRecords=keyRecords.filter(x=>x.key!==k.key);saveKeys()});action.appendChild(remove);tr.appendChild(action);tbody.appendChild(tr);
 });
 document.getElementById('emptyKeys').style.display=filtered.length?'none':'block';
 document.getElementById('keyTotal').textContent=keyRecords.length;
 document.getElementById('keyActive').textContent=keyRecords.filter(k=>k.status==='Active').length;
 document.getElementById('keyDevices').textContent=keyRecords.reduce((a,k)=>a+Number(k.devices||0),0);
}
function exportKeys(){
 const content=keyRecords.map(k=>k.key).join('\n');
 if(!content){toast('No keys to export');return}
 const blob=new Blob([content+'\n'],{type:'text/plain'});
 const url=URL.createObjectURL(blob);const a=document.createElement('a');a.href=url;a.download='darkios-keys.txt';a.click();URL.revokeObjectURL(url);toast('TXT export ready');
}
document.getElementById('importFile').addEventListener('change',async function(){
 const file=this.files[0];if(!file)return;
 const text=await file.text();const lines=text.split(/\r?\n/).map(x=>x.trim()).filter(Boolean);
 let added=0;
 for(const key of lines){
  if(!keyRecords.some(k=>k.key===key)){
   keyRecords.push({key,duration:'Imported',devices:1,created:new Date().toLocaleDateString(),status:'Active'});added++;
  }
 }
 saveKeys();this.value='';toast(added+' new keys imported; existing keys kept');
});
function doLogin(){
 const userInput=document.getElementById('loginUser');
 const passInput=document.getElementById('loginPass');
 const error=document.getElementById('loginError');
 const screen=document.getElementById('loginScreen');
 const app=document.querySelector('.app');
 const username=(userInput.value||'').trim();
 const password=passInput.value||'';
 if(username==='dark' && password==='wear5555'){
  error.textContent='';
  screen.style.display='none';
  app.style.display='flex';
  renderKeys();
  return true;
 }
 error.textContent='Username or password is incorrect.';
 passInput.value='';
 passInput.focus();
 return false;
}
document.getElementById('shareBtn').addEventListener('click',()=>toast('Share link copied (demo)'));
document.getElementById('signout').addEventListener('click',()=>toast('Sign out action (demo)'));
document.querySelectorAll('.overlay').forEach(o=>o.addEventListener('click',e=>{if(e.target===o)o.classList.remove('show')}));

renderKeys();
document.querySelectorAll('.theme-choice').forEach(btn=>btn.addEventListener('click',()=>{
 document.body.dataset.theme=btn.dataset.theme;
 document.querySelectorAll('.theme-choice').forEach(b=>b.classList.toggle('selected',b===btn));
}));


const timeSelect=document.getElementById('durationType');
const timeUnitLabel=document.getElementById('durationUnitLabel');
function syncTimeUnitLabel(){
 if(!timeSelect||!timeUnitLabel)return;
 const labels={day:'day',week:'week',month:'month',year:'year',hour:'hour',minute:'minute'};
 timeUnitLabel.textContent=labels[timeSelect.value]||'day';
}
timeSelect?.addEventListener('change',syncTimeUnitLabel);
syncTimeUnitLabel();

</script>
</body>
</html>
