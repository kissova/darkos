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


.time-combined-row{display:grid;grid-template-columns:62px minmax(0,1fr) minmax(76px,.72fr);align-items:center;gap:10px;margin-top:14px}
.time-combined-row label{margin:0!important}
.time-combined-row select,.time-combined-row input{width:100%;min-width:0}
.time-combined-row input{text-align:center}
.overview-welcome{min-height:180px;display:flex;flex-direction:column;justify-content:center}
.overview-welcome h2{margin:0 0 8px;font-size:22px}
.overview-welcome p{color:var(--muted);margin:0 0 18px}
.sidebar{gap:8px}
@media(max-width:480px){.time-combined-row{grid-template-columns:48px minmax(0,1fr) 82px;gap:7px}}

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
 <button class="nav active" data-page="overview" title="Overview" aria-label="Overview"><span class="ico"><svg><use href="#i-grid"/></svg></span></button>
 <button class="nav" data-page="keys" title="Key Management" aria-label="Key Management"><span class="ico"><svg><use href="#i-key"/></svg></span></button>
 <button class="nav" data-page="general" title="Settings" aria-label="Settings"><span class="ico"><svg><use href="#i-settings"/></svg></span></button>
</aside>
    <main class="main"><div class="content">
<section class="page active" id="page-overview">
 <h1 class="page-title">Overview</h1>
 <div class="panel section-panel overview-welcome">
  <h2>Control Center</h2>
  <p>Manage your DARKIOS keys and workspace appearance.</p>
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
</div></main>
  </div>
</div>
<div class="overlay" id="generatorModal"><div class="modal">
 <h2>Generate DARKIOS Key</h2>
 <label>Custom Key</label>
 <input class="field" id="customCode" placeholder="Leave empty for automatic key" style="width:100%">
 <div class="time-combined-row">
  <label for="durationType">Time</label>
  <select class="field" id="durationType">
   <option value="day">Day</option><option value="week">Week</option><option value="month">Month</option><option value="year">Year</option><option value="hour">Hour</option><option value="minute">Minute</option>
  </select>
  <input class="field" id="durationAmount" type="number" min="1" step="1" value="100" aria-label="Duration number">
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
function showPage(name){
 const navsNow=document.querySelectorAll('.nav[data-page]');
 navsNow.forEach(n=>n.classList.toggle('active',n.dataset.page===name));
 document.querySelectorAll('.page').forEach(p=>p.classList.toggle('active',p.id==='page-'+name));
 const main=document.querySelector('.main');if(main)main.scrollTop=0;
}
const navs=document.querySelectorAll('.nav[data-page]');
navs.forEach(btn=>{btn.title=btn.querySelector('.nav-label')?.textContent || btn.dataset.page;btn.setAttribute('aria-label',btn.title);btn.addEventListener('click',()=>showPage(btn.dataset.page));});
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


</script>
</body>
</html>


<!--
===============================================================================
DARKIOS — FEATURE SPECIFICATION / PROJECT NOTES
This comment block is documentation only. It does not execute and does not
change the dashboard's existing HTML, CSS, JavaScript, storage, or behavior.
===============================================================================

A. CURRENT DASHBOARD FEATURES IN THIS FRONT-END BUILD
- Login screen with the configured demo username/password check.
- Overview page with shortcuts to Key Management and Settings.
- Key Management page.
- Key generator:
  * Custom key text: when provided, the custom text is the entire key.
  * Automatic DARKIOS key format when Custom Key is left empty.
  * Duration units: day, week, month, year, hour, minute.
  * Numeric duration field.
  * Maximum-device limit field.
- Key list with search.
- Key export as TXT, one key per line.
- TXT import; duplicate keys are skipped and existing keys are retained.
- Key deletion.
- Settings page with theme selection.
- Browser-local storage for the current front-end demo.

B. REQUESTED KEY MANAGEMENT FEATURES — IMPLEMENTATION SPECIFICATION
Each existing key should have a Manage action opening its own detail window.
The key's current settings and device state should be shown there.

1. Increase device limit
   - Show current maximum device count.
   - Allow an administrator to enter a new limit.
   - Do not allow the new limit to be lower than the number of already-approved
     active devices unless the administrator confirms a forced removal.

2. Extend key duration
   - Show the current expiry date/time and remaining duration.
   - Allow adding a chosen number of days, weeks, months, years, hours, or
     minutes.
   - Record the change in the key's activity history.

3. Ban key
   - Change the key status to Banned.
   - Deny future activation and device approval while banned.
   - Provide an administrator-only unban action.

4. Temporary stop
   - Pause a key without deleting it.
   - While paused, deny new logins and new device approvals.
   - Provide Resume and optional stop-until date/time actions.

5. Connected-device list
   - Show approved devices and their current session state.
   - For each device, show only information the client has explicitly
     permission to share: device label/name, battery level, approximate or
     shared location, IP address, last-seen time, and active/inactive state.
   - Do not silently collect location, battery, device identifiers, or IP
     details. The app/client must disclose collection and obtain any required
     permission/consent.

6. New-device approval queue
   - When a key has reached its device limit, a new device must not be allowed
     in automatically.
   - Add a pending request with the key name and the requesting device's
     consented/shared details.
   - Display a red circular pending-request indicator beside the key.
   - Selecting the indicator opens the request details.
   - Provide Accept and Decline actions.
   - Pending means DENIED by default: if the administrator does nothing, the
     requesting device remains blocked.
   - Accept only if the administrator explicitly approves and the device
     limit policy permits it (or the administrator explicitly raises the
     limit).
   - Decline keeps the device blocked and records the decision.

7. Reset key devices
   - Provide a Reset Devices action for each key.
   - Revoke all active sessions/tokens for that key.
   - Remove all approved device registrations for that key.
   - All previously connected devices must authenticate and be approved again.
   - Ask for confirmation before resetting.

8. Audit history
   - Record key creation, duration changes, device-limit changes, ban/unban,
     pause/resume, approval/decline, and device reset events.
   - Include timestamp and administrator action.

C. IMPORTANT IMPLEMENTATION BOUNDARY
The current HTML-only dashboard is a browser-side prototype. Browser localStorage
cannot securely enforce a key limit across different users/devices, revoke
sessions on other devices, verify a device's identity, or securely protect
administrator actions. Real multi-device enforcement requires a backend API,
database, authenticated admin sessions, server-side expiry/status checks,
device registration, and revocable session tokens. Device details must come
from an explicitly configured client/app and must respect user consent.
Do not treat this documentation block as proof that backend enforcement exists.

===============================================================================
END OF DARKIOS FEATURE SPECIFICATION
===============================================================================
-->
