// HMOOD__TG@i_8_f


#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <sys/utsname.h>
#include <chrono>
#include <atomic>
#include <array>
#include <unordered_map>
#include <utility>
#import <Metal/Metal.h>
#include <string>
#import "LicenseAuth.h"
#import "Engine.h"
#import "mahoa.h"
#include "Tools.h"
#import "PubgLoad.h"
#include "imgui.h"
#include "imgui_internal.h"
#include "font_awesome_5.h"
#include "fa_solid_900.h"
#include "ini_rw.h"
#include "menu.h"
#import <sys/sysctl.h>
#import <sys/stat.h>
#include <dlfcn.h>
#include <mach-o/dyld.h>
#include <pthread.h>
#include "ESP/menu_detail_assets.h"
#include "ESP/menu_navigation_assets.h"
#include <cmath>
#include <cfloat>
#include <cstdio>
#include <cstring>
#include <vector>
#include <mach/mach.h>
#include <mach/mach_host.h>
#include <mach/vm_statistics.h>

// HMOOD__TG@i_8_f


using namespace SDK;

extern std::string SDKvaT(const std::string& __in);
extern bool hideNameKillMsg;
extern bool textBorder;
extern bool hideHacker;
extern bool Enable;
extern bool 自动开火;
extern float 追踪概率;
extern bool ifismembotenable;
extern bool MagicSDK;
extern bool IsFastSwitch;
extern bool IsFastDrop;
extern bool chaynhanhv2;
extern bool IsNocamerashake;
extern bool IsNorecoil2;
extern bool IsFastshoot;
extern bool IsCrossHair;
extern bool isSpinning;
extern bool WideView;
extern bool MemoryFastScope, MemoryZoom, MemoryDamage, MemoryRainbow, MemoryCrossSpin;
extern float MemoryZoomFov;
extern float MemoryRainbowSpeed, MemoryCrossSpinSpeed;
extern bool HitX;
extern int WideValue;
extern float tocdoquay;
extern float crosshairSizeSlider;

extern float ESPMaxDistance;
extern float globalHpAlphaF;
extern int IsStyle;
extern float AlertRadius;
extern float strokeIntensity;
extern float SilentAimMaxDistance;
extern float Cross;
extern float AimSmooth;
extern float magicX;
extern float magicY;
extern float magicZ;

extern ImU32 COLOR_Distance;
extern ImColor bgColor;
extern INI* config;
extern ASTExtraPlayerController* localPlayerController;
extern void ResetGuestAccount();
extern ImFont* mainFont;


bool MenDeal = false;
bool IsLogin = false;
ImFont* cyberMenuFont = nullptr;

static ImFont* SafeMenuFont() {
    if (ImGui::GetCurrentContext() && ImGui::GetIO().Fonts && !ImGui::GetIO().Fonts->Fonts.empty()) {
        ImFont* f = ImGui::GetFont();
        if (f) return f;
        return ImGui::GetIO().Fonts->Fonts[0];
    }
    return nullptr;
}

// HMOOD__TG@i_8_f
UIImage* GetMenuBadgeImage() {
    static UIImage* badge = nil;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        if (!kCyberDetailedBrand) return;
        NSData* data = [[NSData alloc] initWithBase64EncodedString:
            [NSString stringWithUTF8String:kCyberDetailedBrand] options:0];
        UIImage* source = data ? [UIImage imageWithData:data] : nil;
        if (!source.CGImage) return;
        CGImageRef crop = CGImageCreateWithImageInRect(source.CGImage, CGRectMake(44, 134, 448, 448));
        if (!crop) return;
        if (CGImageGetWidth(crop) == 0 || CGImageGetHeight(crop) == 0) {
            CGImageRelease(crop);
            return;
        }
        UIImage* circle = [UIImage imageWithCGImage:crop];
        UIGraphicsImageRendererFormat* format = [UIGraphicsImageRendererFormat defaultFormat];
        format.scale = 1.f;
        format.opaque = NO;
        UIGraphicsImageRenderer* renderer = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(448, 448) format:format];
        if (renderer) {
            badge = [renderer imageWithActions:^(UIGraphicsImageRendererContext* context) {
                (void)context;
                [[UIBezierPath bezierPathWithOvalInRect:CGRectMake(0, 0, 448, 448)] addClip];
                [circle drawInRect:CGRectMake(0, 0, 448, 448)];
            }];
        }
        CGImageRelease(crop);
    });
    return badge;
}

// HMOOD__TG@i_8_f


typedef int (*ptrace_ptr_t)(int, pid_t, caddr_t, int);
#define PT_DENY_ATTACH 31
static void pg_deny_debugger(void) {
    void* handle = dlopen(0, RTLD_GLOBAL | RTLD_NOW);
    if (!handle) return;
    ptrace_ptr_t pt = (ptrace_ptr_t)dlsym(handle, "ptrace");
    if (pt)
        pt(PT_DENY_ATTACH, 0, 0, 0);
}

@interface PauseGuard : NSObject
+ (void)installInWindow:(UIWindow*)window;
@end

@implementation PauseGuard
+ (void)installInWindow:(UIWindow*)window {
    (void)window;
    pg_deny_debugger();
}
@end

// HMOOD__TG@i_8_f


namespace ImGui {
    inline void MergeIconsWithLatestFont(float font_size, bool FontDataOwnedByAtlas = false) {
        if (!GetIO().Fonts || GetIO().Fonts->Fonts.empty()) return;
        static const ImWchar icons_ranges[] = {ICON_MIN_FA, ICON_MAX_FA, 0};
        ImFontConfig icons_config;
        icons_config.MergeMode = true;
        icons_config.PixelSnapH = true;
        icons_config.FontDataOwnedByAtlas = FontDataOwnedByAtlas;
        GetIO().Fonts->AddFontFromMemoryTTF((void*)fa_solid_900, sizeof(fa_solid_900), font_size,
                                            &icons_config, icons_ranges);
    }
}

static int CyberMenuFontFace(NSString* path, NSString* postScriptName) {
    if (!path || !postScriptName) return -1;
    NSData* data = [NSData dataWithContentsOfFile:path options:NSDataReadingMappedIfSafe error:nullptr];
    const unsigned char* bytes = (const unsigned char*)data.bytes;
    const size_t length = data.length;
    if (!bytes || length < 12)
        return -1;
    auto u16 = [&](size_t p) -> uint16_t {
        return p <= length - 2 ? (uint16_t)((bytes[p] << 8) | bytes[p + 1]) : 0;
    };
    auto u32 = [&](size_t p) -> uint32_t {
        return p <= length - 4 ? ((uint32_t)bytes[p] << 24) | ((uint32_t)bytes[p + 1] << 16) |
                                     ((uint32_t)bytes[p + 2] << 8) | bytes[p + 3]
                               : 0;
    };
    const bool collection = u32(0) == 0x74746366;
    const uint32_t faces = collection ? u32(8) : 1;
    if (faces > 128 || (collection && 12 + (size_t)faces * 4 > length))
        return -1;
    for (uint32_t face = 0; face < faces; ++face) {
        const size_t offset = collection ? u32(12 + face * 4) : 0;
        if (offset > length - 12)
            continue;
        const uint16_t tables = u16(offset + 4);
        if (offset + 12 + (size_t)tables * 16 > length)
            continue;
        for (uint16_t t = 0; t < tables; ++t) {
            const size_t record = offset + 12 + (size_t)t * 16;
            if (u32(record) != 0x6e616d65)
                continue;
            const size_t name = u32(record + 8), tableLength = u32(record + 12);
            if (name > length || tableLength > length - name || tableLength < 6)
                continue;
            const uint16_t count = u16(name + 2), strings = u16(name + 4);
            if (6 + (size_t)count * 12 > tableLength)
                continue;
            for (uint16_t n = 0; n < count; ++n) {
                const size_t entry = name + 6 + (size_t)n * 12;
                if (u16(entry + 6) != 6)
                    continue;
                const size_t start = (size_t)strings + u16(entry + 10), size = u16(entry + 8);
                if (start > tableLength || size > tableLength - start)
                    continue;
                const uint16_t platform = u16(entry);
                NSStringEncoding encoding = (platform == 0 || platform == 3) ? NSUTF16BigEndianStringEncoding
                                                                             : NSMacOSRomanStringEncoding;
                NSString* value = [[NSString alloc] initWithBytes:bytes + name + start
                                                           length:size
                                                         encoding:encoding];
                if ([value isEqualToString:postScriptName])
                    return (int)face;
            }
        }
    }
    return -1;
}

void InitializeMenuFonts(ImGuiIO& io) {
    if (!io.Fonts) return;
    ImFontConfig font_cfg;

    NSString* FontPath = @"/System/Library/Fonts/Core/AvenirNext.ttc";
    io.ConfigWindowsMoveFromTitleBarOnly = true;

    constexpr float menuFontBakeSize = 48.f;
    font_cfg.OversampleH = 2;
    font_cfg.OversampleV = 2;
    mainFont = nullptr;
    if ([[NSFileManager defaultManager] fileExistsAtPath:FontPath]) {
        mainFont = io.Fonts->AddFontFromFileTTF(FontPath.UTF8String, menuFontBakeSize, &font_cfg,
                                                io.Fonts->GetGlyphRangesVietnamese());
    }
    if (!mainFont) {
        mainFont = io.Fonts->AddFontDefault();
    }
    if (mainFont)
        mainFont->Scale = 13.f / menuFontBakeSize;

    ImGui::MergeIconsWithLatestFont(12.f * menuFontBakeSize / 13.f, false);

    NSString* homePath = nil;
    int homeFace = -1;
    NSArray<NSString*>* homeCandidates = @[
        @"/System/Library/Fonts/Core/Helvetica.ttc", @"/System/Library/Fonts/CoreUI/Helvetica.ttc",
        @"/System/Library/Fonts/Helvetica.ttc", @"/System/Library/Fonts/Cache/Helvetica.ttc"
    ];
    for (NSString* candidate in homeCandidates) {
        const int face = CyberMenuFontFace(candidate, @"Helvetica-Bold");
        if (face >= 0) {
            homePath = candidate;
            homeFace = face;
            break;
        }
    }
    if (homeFace < 0) {
        NSString* directory = @"/System/Library/Fonts";
        NSDirectoryEnumerator* entries = [[NSFileManager defaultManager] enumeratorAtPath:directory];
        for (NSString* relative in entries) {
            NSString* extension = relative.pathExtension.lowercaseString;
            if (![extension isEqualToString:@"ttc"] && ![extension isEqualToString:@"ttf"] &&
                ![extension isEqualToString:@"otf"])
                continue;
            NSString* candidate = [directory stringByAppendingPathComponent:relative];
            const int face = CyberMenuFontFace(candidate, @"Helvetica-Bold");
            if (face >= 0) {
                homePath = candidate;
                homeFace = face;
                break;
            }
        }
    }
    cyberMenuFont = mainFont;
    if (homePath && homeFace >= 0) {
        ImFontConfig home_cfg;
        home_cfg.FontNo = homeFace;
        home_cfg.OversampleH = 2;
        home_cfg.OversampleV = 2;
        ImFont* selected = io.Fonts->AddFontFromFileTTF(homePath.UTF8String, menuFontBakeSize, &home_cfg,
                                                        io.Fonts->GetGlyphRangesVietnamese());
        if (selected) {
            selected->Scale = 13.f / menuFontBakeSize;
            cyberMenuFont = selected;
            ImGui::MergeIconsWithLatestFont(12.f * menuFontBakeSize / 13.f, false);
        }
    }
}

// HMOOD__TG@i_8_f


void ApplyImGuiStyle() {
    if (!ImGui::GetCurrentContext()) return;
    ImGuiStyle& s = ImGui::GetStyle();
    s.WindowPadding = {0, 0};
    s.WindowRounding = 12.f;
    s.WindowBorderSize = 1.f;
    s.ChildRounding = 8.f;
    s.ChildBorderSize = 0.f;
    s.FramePadding = {8, 5};
    s.FrameRounding = 3.f;
    s.FrameBorderSize = 0.f;
    s.ItemSpacing = {8, 7};
    s.ScrollbarSize = 4.f;
    s.ScrollbarRounding = 4.f;
    s.GrabMinSize = 6.f;
    s.GrabRounding = 3.f;
    s.PopupRounding = 4.f;
    s.TabRounding = 6.f;
    s.WindowTitleAlign = {0.5f, 0.5f};
    s.ButtonTextAlign = {0.5f, 0.5f};

    auto* c = s.Colors;
    c[ImGuiCol_Text] = {1.f, 1.f, 1.f, 1.f};
    c[ImGuiCol_TextDisabled] = {0.557f, 0.557f, 0.620f, 1.f};
    c[ImGuiCol_WindowBg] = {0.031f, 0.035f, 0.055f, 1.f};
    c[ImGuiCol_ChildBg] = {0.051f, 0.059f, 0.086f, 1.f};
    c[ImGuiCol_PopupBg] = {0.043f, 0.047f, 0.071f, 0.98f};
    c[ImGuiCol_Border] = {0.110f, 0.118f, 0.180f, 1.f};
    c[ImGuiCol_BorderShadow] = {0.f, 0.f, 0.f, 0.f};
    c[ImGuiCol_FrameBg] = {0.075f, 0.082f, 0.122f, 1.f};
    c[ImGuiCol_FrameBgHovered] = {0.098f, 0.106f, 0.157f, 1.f};
    c[ImGuiCol_FrameBgActive] = {0.118f, 0.129f, 0.192f, 1.f};
    c[ImGuiCol_TitleBg] = {0.031f, 0.035f, 0.055f, 1.f};
    c[ImGuiCol_TitleBgActive] = {0.031f, 0.035f, 0.055f, 1.f};
    c[ImGuiCol_TitleBgCollapsed] = {0.031f, 0.035f, 0.055f, 1.f};
    c[ImGuiCol_ScrollbarBg] = {0.f, 0.f, 0.f, 0.f};
    c[ImGuiCol_ScrollbarGrab] = {0.110f, 0.118f, 0.180f, 1.f};
    c[ImGuiCol_ScrollbarGrabHovered] = {0.820f, 0.071f, 0.188f, 0.5f};
    c[ImGuiCol_ScrollbarGrabActive] = {0.820f, 0.071f, 0.188f, 1.f};
    c[ImGuiCol_CheckMark] = {0.820f, 0.071f, 0.188f, 1.f};
    c[ImGuiCol_SliderGrab] = {0.820f, 0.071f, 0.188f, 1.f};
    c[ImGuiCol_SliderGrabActive] = {1.f, 0.380f, 0.490f, 1.f};
    c[ImGuiCol_Button] = {0.075f, 0.082f, 0.122f, 1.f};
    c[ImGuiCol_ButtonHovered] = {0.820f, 0.071f, 0.188f, 0.18f};
    c[ImGuiCol_ButtonActive] = {0.820f, 0.071f, 0.188f, 0.35f};
    c[ImGuiCol_Header] = {0.820f, 0.071f, 0.188f, 0.15f};
    c[ImGuiCol_HeaderHovered] = {0.820f, 0.071f, 0.188f, 0.25f};
    c[ImGuiCol_HeaderActive] = {0.820f, 0.071f, 0.188f, 0.40f};
    c[ImGuiCol_Separator] = {0.110f, 0.118f, 0.180f, 1.f};
    c[ImGuiCol_SeparatorHovered] = {0.820f, 0.071f, 0.188f, 0.5f};
    c[ImGuiCol_SeparatorActive] = {0.820f, 0.071f, 0.188f, 1.f};
    c[ImGuiCol_Tab] = {0.051f, 0.059f, 0.086f, 1.f};
    c[ImGuiCol_TabHovered] = {0.820f, 0.071f, 0.188f, 0.20f};
    c[ImGuiCol_TabActive] = {0.820f, 0.071f, 0.188f, 0.30f};
    c[ImGuiCol_TableHeaderBg] = {0.031f, 0.035f, 0.055f, 1.f};
    c[ImGuiCol_TableBorderStrong] = {0.110f, 0.118f, 0.180f, 1.f};
    c[ImGuiCol_TableBorderLight] = {0.075f, 0.082f, 0.122f, 1.f};
    c[ImGuiCol_TableRowBg] = {0.f, 0.f, 0.f, 0.f};
    c[ImGuiCol_TableRowBgAlt] = {1.f, 1.f, 1.f, 0.025f};
}

// HMOOD__TG@i_8_f


namespace MenuLocale {
    static int language = 0;
    static const char* languageNames[] = {"English", "کوردی (سۆرانی)", "简体中文", "Русский", "العربية", "हिन्दी", "Türkçe"};
    static bool rtl() { return language == 1 || language == 4; }
    static std::string key(const char* value) {
        std::string result = value ? value : "";
        for (char& c : result)
            if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
        return result;
    }
    static const char* tr(const char* value) {
        if (!value) return "";
        if (language == 0) return value;
        static const std::unordered_map<std::string, std::array<const char*, 6>> phrases = {
            {"home", {{"سەرەکی", "主页", "ГЛАВНАЯ", "الرئيسية", "मुख्य पृष्ठ", "ANA SAYFA"}}},
            {"esp radar", {{"ڕاداری بینین", "透视雷达", "ESP РАДАР", "رادار العرض", "ईएसपी रडार", "ESP RADARI"}}},
            {"aimbot", {{"ئامانجگیری", "辅助瞄准", "Автоприцел", "التصويب التلقائي", "स्वचालित निशाना", "Otomatik nişan"}}},
            {"memory", {{"بیرگە", "内存", "Память", "الذاكرة", "मेमोरी", "Bellek"}}},
            {"settings", {{"ڕێکخستنەکان", "设置", "Настройки", "الإعدادات", "सेटिंग्स", "Ayarlar"}}},
            {"esp style", {{"شێوازی بینین", "透视样式", "Стиль ESP", "نمط العرض", "ईएसपी शैली", "ESP stili"}}},
            {"basic", {{"سەرەتایی", "基础", "Базовый", "أساسي", "सामान्य", "Temel"}}},
            {"vip cyber vertical", {{"VIP ستوونی", "VIP 纵向", "VIP вертикальный", "VIP عمودي", "VIP लंबवत", "VIP dikey"}}},
            {"player esp", {{"پیشاندانی یاریزان", "显示玩家", "Показ игроков", "إظهار اللاعبين", "खिलाड़ी दिखाएँ", "Oyuncuları göster"}}},
            {"draw names", {{"پیشاندانی ناو", "显示名称", "Имена", "إظهار الأسماء", "नाम दिखाएँ", "İsimleri göster"}}},
            {"draw weapon", {{"پیشاندانی چەک", "显示武器", "Оружие", "إظهار السلاح", "हथियार दिखाएँ", "Silahı göster"}}},
            {"game info", {{"زانیاری یاری", "游戏信息", "Данные игры", "معلومات اللعبة", "खेल की जानकारी", "Oyun bilgisi"}}},
            {"draw distance", {{"پیشاندانی دووری", "显示距离", "Расстояние", "إظهار المسافة", "दूरी दिखाएँ", "Mesafeyi göster"}}},
            {"draw health", {{"پیشاندانی تەندروستی", "显示生命值", "Здоровье", "إظهار الدم", "स्वास्थ्य दिखाएँ", "Canı göster"}}},
            {"360 alert", {{"ئاگاداری ٣٦٠", "360° 警报", "Оповещение 360°", "تنبيه ٣٦٠", "360° चेतावनी", "360° uyarı"}}},
            {"snap lines", {{"هێڵی یاریزان", "连线", "Линии к игрокам", "خطوط اللاعبين", "खिलाड़ी रेखाएँ", "Oyuncu çizgileri"}}},
            {"draw boxes", {{"پیشاندانی چوارچێوە", "显示方框", "Рамки", "إظهار البوكس", "बॉक्स दिखाएँ", "Kutuları göster"}}},
            {"draw bones", {{"پیشاندانی ئێسک", "显示骨骼", "Скелет", "إظهار العظام", "कंकाल दिखाएँ", "İskeleti göster"}}},
            {"hide bots", {{"شاردنەوەی بۆت", "隐藏机器人", "Скрыть ботов", "إخفاء البوتات", "बॉट छिपाएँ", "Botları gizle"}}},
            {"enemy count", {{"ژمارەی دوژمن", "敌人数量", "Число врагов", "عدد الأعداء", "दुश्मनों की संख्या", "Düşman sayısı"}}},
            {"player team id", {{"ژمارەی تیم", "队伍编号", "Номер команды", "رقم فريق اللاعب", "खिलाड़ी की टीम", "Takım numarası"}}},
            {"enemy aiming", {{"ئامانجگیری دوژمن", "敌方瞄准警报", "Враг целится", "تصويب العدو نحوك", "दुश्मन का निशाना", "Düşman nişanı"}}},
            {"lootbox", {{"سندووقی کەلوپەل", "战利品箱", "Ящики добычи", "صناديق اللوت", "लूट बॉक्स", "Ganimet kutusu"}}},
            {"items esp", {{"پیشاندانی کەلوپەل", "显示物品", "Показ предметов", "إظهار الأغراض", "वस्तुएँ दिखाएँ", "Eşyaları göster"}}},
            {"vehicle esp", {{"پیشاندانی ئۆتۆمبێل", "显示载具", "Показ транспорта", "إظهار المركبات", "वाहन दिखाएँ", "Araçları göster"}}},
            {"existing display settings", {{"ڕێکخستنی پیشاندان", "显示设置", "Настройки отображения", "إعدادات العرض", "प्रदर्शन सेटिंग्स", "Görüntü ayarları"}}},
            {"esp distance", {{"دووری پیشاندان", "显示距离上限", "Дальность ESP", "مدى العرض", "दिखाने की दूरी", "ESP mesafesi"}}},
            {"hp scale", {{"قەبارەی کارتی تەندروستی", "生命卡缩放", "Размер карточки здоровья", "حجم بطاقة الدم", "स्वास्थ्य कार्ड का आकार", "Can kartı boyutu"}}},
            {"alert radius", {{"نیوەتیرەی ئاگاداری", "警报半径", "Радиус оповещения", "نطاق التنبيه", "चेतावनी का दायरा", "Uyarı yarıçapı"}}},
            {"stroke width", {{"ئەستووری چوارچێوە", "描边宽度", "Толщина обводки", "سماكة الحواف", "किनारे की मोटाई", "Çerçeve kalınlığı"}}},
            {"text border", {{"چوارچێوەی نووسین", "文字描边", "Обводка текста", "حواف النص", "पाठ का किनारा", "Yazı çerçevesi"}}},
            {"hide name", {{"شاردنەوەی ناو", "隐藏姓名", "Скрыть имя", "إخفاء الاسم", "नाम छिपाएँ", "İsmi gizle"}}},
            {"distance color", {{"ڕەنگی دووری", "距离颜色", "Цвет расстояния", "لون المسافة", "दूरी का रंग", "Mesafe rengi"}}},
            {"border color", {{"ڕەنگی چوارچێوە", "描边颜色", "Цвет обводки", "لون الحواف", "किनारे का रंग", "Çerçeve rengi"}}},
            {"aim settings", {{"ڕێکخستنی ئامانجگیری", "瞄准设置", "Настройки прицела", "إعدادات التصويب", "निशाने की सेटिंग्स", "Nişan ayarları"}}},
            {"aim control", {{"کۆنترۆڵی ئامانجگیری", "瞄准控制", "Управление прицелом", "التحكم بالتصويب", "निशाने का नियंत्रण", "Nişan kontrolü"}}},
            {"silent aim", {{"ئامانجگیری بێدەنگ", "静默瞄准", "Тихий прицел", "تصويب صامت", "साइलेंट निशाना", "Sessiz nişan"}}},
            {"macro", {{"ماکرۆ", "宏", "Макрос", "ماكرو", "मैक्रो", "Makro"}}},
            {"aim line", {{"هێڵی ئامانجگیری", "瞄准线", "Линия прицела", "خط التصويب", "निशाने की रेखा", "Nişan çizgisi"}}},
            {"auto fire", {{"تەقەی خۆکار", "自动开火", "Автоогонь", "إطلاق تلقائي", "अपने आप गोली", "Otomatik ateş"}}},
            {"visibility check", {{"پشکنینی بینین", "可见性检查", "Проверка видимости", "فحص الرؤية", "दृश्यता जाँच", "Görünürlük kontrolü"}}},
            {"ignore bots", {{"پشتگوێخستنی بۆت", "忽略机器人", "Игнорировать ботов", "تجاهل البوتات", "बॉट को छोड़ें", "Botları yok say"}}},
            {"ignore knocked", {{"پشتگوێخستنی کەوتوو", "忽略倒地玩家", "Игнорировать сбитых", "تجاهل المطروحين", "गिरे खिलाड़ियों को छोड़ें", "Yerdekileri yok say"}}},
            {"enable fov", {{"پیشاندانی بازنە", "显示视野圈", "Показать круг FOV", "إظهار دائرة التصويب", "दायरा दिखाएँ", "FOV dairesini göster"}}},
            {"aim target", {{"شوێنی ئامانج", "瞄准部位", "Точка прицеливания", "موضع التصويب", "निशाने का स्थान", "Nişan noktası"}}},
            {"head", {{"سەر", "头部", "Голова", "الرأس", "सिर", "Baş"}}},
            {"neck", {{"مل", "颈部", "Шея", "الرقبة", "गर्दन", "Boyun"}}},
            {"body", {{"لەش", "身体", "Корпус", "الجسم", "शरीर", "Gövde"}}},
            {"pelvis", {{"لگن", "骨盆", "Таз", "الحوض", "कूल्हा", "Kalça"}}},
            {"auto", {{"خۆکار", "自动", "Авто", "تلقائي", "स्वचालित", "Otomatik"}}},
            {"fire", {{"تەقە", "开火", "Огонь", "إطلاق", "गोली चलाना", "Ateş"}}},
            {"ads", {{"نیشانەگرتن", "开镜", "Прицеливание", "فتح السكوب", "स्कोप खोलना", "Dürbün"}}},
            {"fire + ads", {{"تەقە و نیشانە", "开火且开镜", "Огонь и прицел", "إطلاق مع سكوب", "गोली और स्कोप", "Ateş ve dürbün"}}},
            {"fire or ads", {{"تەقە یان نیشانە", "开火或开镜", "Огонь или прицел", "إطلاق أو سكوب", "गोली या स्कोप", "Ateş veya dürbün"}}},
            {"fov", {{"بازنەی ئامانج", "瞄准范围", "Поле прицела", "دائرة التصويب", "निशाने का दायरा", "Nişan alanı"}}},
            {"distance", {{"دووری", "距离", "Дальность", "المسافة", "दूरी", "Mesafe"}}},
            {"aim speed", {{"خێرایی ئامانج", "瞄准速度", "Скорость прицела", "سرعة التصويب", "निशाने की गति", "Nişan hızı"}}},
            {"hit probability", {{"ئەگەری پێکان", "命中概率", "Вероятность попадания", "احتمال الإصابة", "लगने की संभावना", "İsabet olasılığı"}}},
            {"mode", {{"دۆخ", "模式", "Режим", "الوضع", "मोड", "Mod"}}},
            {"safe", {{"پارێزراو", "安全", "Безопасный", "آمن", "सुरक्षित", "Güvenli"}}},
            {"risk", {{"مەترسیدار", "高风险", "Рискованный", "مخاطرة", "जोखिम", "Riskli"}}},
            {"custom", {{"تایبەت", "自定义", "Свой", "مخصص", "कस्टम", "Özel"}}},
            {"prediction", {{"پێشبینی جووڵە", "移动预测", "Упреждение", "توقع الحركة", "गति का अनुमान", "Hareket tahmini"}}},
            {"max step", {{"زۆرترین هەنگاو", "最大步长", "Максимальный шаг", "أقصى خطوة", "अधिकतम कदम", "En büyük adım"}}},
            {"magic x", {{"ماجیک X", "魔术 X", "Магия X", "ماجيك X", "मैजिक X", "Magic X"}}},
            {"magic y", {{"ماجیک Y", "魔术 Y", "Магия Y", "ماجيك Y", "मैजिक Y", "Magic Y"}}},
            {"magic z", {{"ماجیک Z", "魔术 Z", "Магия Z", "ماجيك Z", "मैजिक Z", "Magic Z"}}},
            {"auto tap", {{"کرتەی خۆکار", "自动点击", "Автонажатие", "نقر تلقائي", "अपने आप टैप", "Otomatik dokunma"}}},
            {"fast shoot", {{"تەقەی خێرا", "快速射击", "Быстрая стрельба", "إطلاق سريع", "तेज़ गोली", "Hızlı ateş"}}},
            {"fast scope", {{"نیشانەی خێرا", "快速开镜", "Быстрый прицел", "سكوب سريع", "तेज़ स्कोप", "Hızlı dürbün"}}},
            {"fast gun", {{"گۆڕینی خێرای چەک", "快速换枪", "Быстрая смена оружия", "تبديل سلاح سريع", "तेज़ हथियार बदलना", "Hızlı silah değişimi"}}},
            {"spin", {{"سووڕانەوە", "旋转", "Вращение", "دوران", "घूमना", "Dönüş"}}},
            {"zoom", {{"نزیککردنەوە", "缩放", "Приближение", "تكبير", "ज़ूम", "Yakınlaştırma"}}},
            {"ipad", {{"ئایپاد", "iPad 视角", "Вид iPad", "منظور آيباد", "आईपैड दृश्य", "iPad görünümü"}}},
            {"no recoil", {{"بێ پاشەکشە", "无后坐力", "Без отдачи", "بدون ارتداد", "बिना झटके", "Geri tepme yok"}}},
            {"no shake", {{"بێ لەرزین", "无镜头抖动", "Без тряски", "بدون اهتزاز", "बिना कंपन", "Sarsıntı yok"}}},
            {"hitx", {{"نیشانەی پێکان", "命中特效", "Эффект попадания", "مؤثر الإصابة", "हिट प्रभाव", "İsabet efekti"}}},
            {"damage", {{"زیان", "伤害", "Урон", "الضرر", "नुकसान", "Hasar"}}},
            {"small cross", {{"نیشانەی بچووک", "小准星", "Малый прицел", "مؤشر تصويب صغير", "छोटा क्रॉसहेयर", "Küçük nişangâh"}}},
            {"rainbow", {{"کەوانەی ڕەنگین", "彩虹", "Радуга", "ألوان متغيرة", "इंद्रधनुष", "Gökkuşağı"}}},
            {"cross spin", {{"سووڕانی نیشانە", "准星旋转", "Вращение прицела", "دوران المؤشر", "क्रॉसहेयर घूमना", "Nişangâh dönüşü"}}},
            {"fast drop", {{"دابەزینی خێرا", "快速降落", "Быстрое падение", "نزول سريع", "तेज़ उतरना", "Hızlı iniş"}}},
            {"super run", {{"ڕاکردنی خێرا", "极速奔跑", "Быстрый бег", "جري سريع", "तेज़ दौड़", "Hızlı koşu"}}},
            {"spin speed", {{"خێرایی سووڕانەوە", "旋转速度", "Скорость вращения", "سرعة الدوران", "घूमने की गति", "Dönüş hızı"}}},
            {"ipad view", {{"مەودای بینینی ئایپاد", "iPad 视野", "Обзор iPad", "مدى منظور آيباد", "आईपैड का दृश्य", "iPad görüş alanı"}}},
            {"cross size", {{"قەبارەی نیشانە", "准星大小", "Размер прицела", "حجم المؤشر", "क्रॉसहेयर का आकार", "Nişangâh boyutu"}}},
            {"license", {{"مۆڵەت", "授权", "Лицензия", "الترخيص", "लाइसेंस", "Lisans"}}},
            {"expires", {{"کاتی بەسەرچوون", "到期时间", "Истекает", "ينتهي", "समाप्ति", "Bitiş"}}},
            {"device", {{"ئامێر", "设备", "Устройство", "الجهاز", "डिवाइस", "Cihaz"}}},
            {"key", {{"کلیل", "密钥", "Ключ", "المفتاح", "कुंजी", "Anahtar"}}},
            {"not configured", {{"ڕێک نەخراوە", "未配置", "Не настроено", "غير مهيأ", "सेट नहीं है", "Yapılandırılmadı"}}},
            {"game mode", {{"دۆخی یاری", "游戏模式", "Режим игры", "وضع اللعبة", "खेल मोड", "Oyun modu"}}},
            {"local mode", {{"دۆخی ناوخۆیی", "本地模式", "Локальный режим", "وضع محلي", "स्थानीय मोड", "Yerel mod"}}},
            {"no license service", {{"خزمەتگوزاری مۆڵەت نییە", "未连接授权服务", "Нет сервиса лицензий", "لا توجد خدمة ترخيص", "लाइसेंस सेवा नहीं है", "Lisans hizmeti yok"}}},
            {"open mode", {{"کردنەوەی دۆخ", "打开模式", "Открыть режим", "فتح الوضع", "मोड खोलें", "Modu aç"}}},
            {"ram booster", {{"پاککردنەوەی بیرگە", "内存清理", "Очистка памяти", "تنظيف الذاكرة", "मेमोरी सफ़ाई", "Bellek temizleme"}}},
            {"app", {{"بەرنامە", "应用", "Приложение", "التطبيق", "ऐप", "Uygulama"}}},
            {"free", {{"بەتاڵ", "空闲", "Свободно", "المتاح", "खाली", "Boş"}}},
            {"purge", {{"پاککردنەوە", "立即清理", "Очистить", "تنظيف", "साफ़ करें", "Temizle"}}},
            {"auto-clean: off", {{"پاککردنەوەی خۆکار: ناچالاک", "自动清理：关闭", "Автоочистка: выкл.", "تنظيف تلقائي: متوقف", "अपने आप सफ़ाई: बंद", "Otomatik temizlik: kapalı"}}},
            {"preferences", {{"هەڵبژاردەکان", "偏好设置", "Предпочтения", "التفضيلات", "प्राथमिकताएँ", "Tercihler"}}},
            {"stream: on", {{"شاردنەوە لە تۆمار: چالاک", "录屏隐藏：开启", "Скрытие записи: вкл.", "إخفاء التسجيل: مفعّل", "रिकॉर्डिंग में छिपाएँ: चालू", "Kayıtta gizleme: açık"}}},
            {"stream: off", {{"شاردنەوە لە تۆمار: ناچالاک", "录屏隐藏：关闭", "Скрытие записи: выкл.", "إخفاء التسجيل: متوقف", "रिकॉर्डिंग में छिपाएँ: बंद", "Kayıtta gizleme: kapalı"}}},
            {"stream", {{"شاردنەوە لە تۆمار", "录屏隐藏", "Скрытие записи", "إخفاء التسجيل", "रिकॉर्डिंग में छिपाएँ", "Kayıtta gizleme"}}},
            {"language", {{"زمان", "语言", "Язык", "اللغة", "भाषा", "Dil"}}},
            {"reset guest", {{"ڕیسێتی میوان", "重置游客", "Сбросить гостя", "إعادة ضبط الضيف", "अतिथि रीसेट", "Misafiri sıfırla"}}},
            {"reset guest account?", {{"هەژماری میوان ڕیسێت بکرێت؟", "重置游客账号？", "Сбросить гостевой аккаунт?", "إعادة ضبط حساب الضيف؟", "अतिथि खाता रीसेट करें?", "Misafir hesabı sıfırlansın mı?"}}},
            {"this deletes local game data, settings and account data.", {{"ئەمە داتای ناوخۆیی یاری و ڕێکخستن و هەژمار دەسڕێتەوە.", "这将删除本地游戏数据、设置和账号数据。", "Будут удалены локальные данные игры, настройки и данные аккаунта.", "سيحذف هذا بيانات اللعبة المحلية والإعدادات وبيانات الحساب.", "इससे स्थानीय गेम डेटा, सेटिंग्स और खाते का डेटा मिट जाएगा।", "Yerel oyun verileri, ayarlar ve hesap verileri silinecek."}}},
            {"the game will exit after the reset.", {{"دوای ڕیسێت یاری دادەخرێت.", "重置后游戏将退出。", "После сброса игра закроется.", "ستُغلق اللعبة بعد إعادة الضبط.", "रीसेट के बाद खेल बंद हो जाएगा।", "Sıfırlamadan sonra oyun kapanacak."}}},
            {"cancel", {{"پاشگەزبوونەوە", "取消", "Отмена", "إلغاء", "रद्द करें", "İptal"}}},
            {"server", {{"ڕاژەکار", "服务器", "Сервер", "السيرفر", "सर्वर", "Sunucu"}}},
            {"unavailable", {{"بەردەست نییە", "不可用", "Недоступно", "غير متاح", "उपलब्ध नहीं", "Kullanılamıyor"}}},
            {"subscription", {{"بەشداری", "订阅", "Подписка", "الاشتراك", "सदस्यता", "Abonelik"}}},
            {"device link", {{"بەستەری ئامێر", "设备绑定", "Привязка устройства", "ربط الجهاز", "डिवाइस लिंक", "Cihaz bağlantısı"}}},
            {"contact", {{"پەیوەندی", "联系我们", "Связь", "التواصل", "संपर्क", "İletişim"}}},
            {"telegram", {{"تێلیگرام", "Telegram", "Telegram", "تيليجرام", "टेलीग्राम", "Telegram"}}},
            {"support", {{"پشتگیری", "支持", "Поддержка", "الدعم", "सहायता", "Destek"}}},
            {"live", {{"ڕاستەوخۆ", "实时", "В эфире", "مباشر", "लाइव", "Canlı"}}},
            {"os", {{"سیستەم", "系统", "ОС", "النظام", "सिस्टम", "Sistem"}}},
            {"ram", {{"بیرگە", "内存", "Память", "الذاكرة", "मेमोरी", "Bellek"}}},
            {"enabled", {{"چالاک کرا", "已启用", "Включено", "تم التفعيل", "चालू", "Etkin"}}},
            {"disabled", {{"ناچالاک کرا", "已关闭", "Выключено", "تم الإيقاف", "बंद", "Devre dışı"}}},
            {"close menu", {{"داخستنی لیستە", "关闭菜单", "Закрыть меню", "إغلاق القائمة", "मेन्यू बंद करें", "Menüyü kapat"}}},
            {"not available in the current project", {{"ئەم تایبەتمەندییە بەردەست نییە.", "此功能暂不可用。", "Эта функция недоступна.", "هذه الميزة غير متاحة.", "यह सुविधा उपलब्ध नहीं है।", "Bu özellik kullanılamıyor."}}},
            {"not available, or controlled by the selected preset", {{"بەردەست نییە یان لە دۆخی ئێستا جێگیرە.", "此选项不可用，或由当前预设控制。", "Недоступно или задано текущим профилем.", "غير متاح أو يتحكم به الوضع المحدد.", "उपलब्ध नहीं या चुना गया मोड इसे नियंत्रित करता है।", "Kullanılamıyor veya seçili profil tarafından yönetiliyor."}}},
            {"enable aimbot and select risk or custom to use silent aim", {{"ئامانجگیری چالاک بکە و مەترسیدار یان تایبەت هەڵبژێرە.", "请启用辅助瞄准，并选择高风险或自定义模式。", "Включите автоприцел и выберите рискованный или свой режим.", "فعّل التصويب واختر وضع مخاطرة أو مخصص لاستخدام التصويب الصامت.", "साइलेंट निशाने के लिए स्वचालित निशाना चालू करें और जोखिम या कस्टम मोड चुनें।", "Sessiz nişan için otomatik nişanı açıp riskli veya özel modu seçin."}}},
            {"open additional existing display settings", {{"ڕێکخستنی زیاتری پیشاندان بکەرەوە.", "打开更多显示设置。", "Открыть дополнительные настройки отображения.", "فتح إعدادات العرض الإضافية.", "प्रदर्शन की अतिरिक्त सेटिंग्स खोलें।", "Ek görüntü ayarlarını aç."}}},
            {"open existing safe / risk / custom modes and additional settings", {{"دۆخ و ڕێکخستنی زیاتری ئامانجگیری بکەرەوە.", "打开瞄准模式和更多设置。", "Открыть режимы и дополнительные настройки прицела.", "فتح أوضاع التصويب والإعدادات الإضافية.", "निशाने के मोड और अतिरिक्त सेटिंग्स खोलें।", "Nişan modlarını ve ek ayarları aç."}}},
            {"more memory options", {{"هەڵبژاردەی زیاتری بیرگە", "更多内存选项", "Дополнительные опции памяти", "خيارات الذاكرة الإضافية", "मेमोरी के अधिक विकल्प", "Diğer bellek seçenekleri"}}},
            {"no contact link is configured in this project", {{"بەستەری پەیوەندی دانەنراوە.", "尚未设置联系链接。", "Ссылка для связи не настроена.", "لم يُضف رابط للتواصل.", "संपर्क लिंक सेट नहीं है।", "İletişim bağlantısı ayarlanmadı."}}},
            {"no support link is configured in this project", {{"بەستەری پشتگیری دانەنراوە.", "尚未设置支持链接。", "Ссылка поддержки не настроена.", "لم يُضف رابط للدعم.", "सहायता लिंक सेट नहीं है।", "Destek bağlantısı ayarlanmadı."}}},
            {"no mode or licensing service is configured", {{"خزمەتگوزاری دۆخ یان مۆڵەت ڕێک نەخراوە.", "尚未配置模式或授权服务。", "Сервис режимов или лицензий не настроен.", "خدمة الأوضاع أو الترخيص غير مهيأة.", "मोड या लाइसेंस सेवा सेट नहीं है।", "Mod veya lisans hizmeti ayarlanmadı."}}},
            {"the current project has no memory purge operation", {{"پاککردنەوەی بیرگە بەردەست نییە.", "内存清理暂不可用。", "Очистка памяти недоступна.", "تنظيف الذاكرة غير متاح.", "मेमोरी सफ़ाई उपलब्ध नहीं है।", "Bellek temizleme kullanılamıyor."}}},
            {"automatic cleaning is not configured", {{"پاککردنەوەی خۆکار ڕێک نەخراوە.", "尚未设置自动清理。", "Автоочистка не настроена.", "التنظيف التلقائي غير مهيأ.", "अपने आप सफ़ाई सेट नहीं है।", "Otomatik temizlik ayarlanmadı."}}},
            {"red", {{"سوور", "红色", "Красный", "أحمر", "लाल", "Kırmızı"}}},
            {"green", {{"سەوز", "绿色", "Зелёный", "أخضر", "हरा", "Yeşil"}}},
            {"blue", {{"شین", "蓝色", "Синий", "أزرق", "नीला", "Mavi"}}},
            {"opacity", {{"ڕوونی", "不透明度", "Непрозрачность", "العتامة", "अपारदर्शिता", "Opaklık"}}},
            {"guest reset complete. game will exit in 5s.", {{"ڕیسێتی میوان تەواو بوو. یاری دوای ٥ چرکە دادەخرێت.", "游客账号已重置。游戏将在 5 秒后退出。", "Гостевой аккаунт сброшен. Игра закроется через 5 секунд.", "اكتملت إعادة ضبط الضيف. ستُغلق اللعبة بعد ٥ ثوانٍ.", "अतिथि रीसेट पूरा हुआ। खेल 5 सेकंड में बंद हो जाएगा।", "Misafir sıfırlandı. Oyun 5 saniye sonra kapanacak."}}},
            {"enable aimbot first", {{"سەرەتا ئامانجگیری چالاک بکە", "请先启用辅助瞄准", "Сначала включите автоприцел", "فعّل التصويب التلقائي أولاً", "पहले स्वचालित निशाना चालू करें", "Önce otomatik nişanı açın"}}},
            {"disable silent aim to adjust camera movement", {{"ئامانجگیری بێدەنگ ناچالاک بکە بۆ ڕێکخستنی جووڵەی کامێرا", "关闭静默瞄准以调整镜头移动", "Отключите тихий прицел для настройки движения камеры", "أوقف التصويب الصامت لضبط حركة الكاميرا", "कैमरे की गति बदलने के लिए साइलेंट निशाना बंद करें", "Kamera hareketini ayarlamak için sessiz nişanı kapatın"}}},
            {"enable silent aim to adjust hit probability", {{"ئامانجگیری بێدەنگ چالاک بکە بۆ ڕێکخستنی ڕێژەی پێکان", "启用静默瞄准以调整命中概率", "Включите тихий прицел для настройки вероятности попадания", "فعّل التصويب الصامت لضبط نسبة الإصابة", "हिट की संभावना बदलने के लिए साइलेंट निशाना चालू करें", "İsabet olasılığını ayarlamak için sessiz nişanı açın"}}},
            {"fov applies to camera aim", {{"مەودای بینین بۆ ئامانجگیری کامێرایە", "视野范围用于镜头瞄准", "Радиус применяется к наведению камеры", "دائرة التصويب تخص تصويب الكاميرا", "दायरा कैमरे के निशाने के लिए है", "Görüş alanı kamera nişanı içindir"}}},
            {"wide", {{"پانایی", "视野", "Обзор", "اتساع المنظور", "चौड़ा दृश्य", "Genişlik"}}},
        };
        const auto found = phrases.find(key(value));
        return found == phrases.end() ? value : found->second[language - 1];
    }
    static bool native(const char* value) {
        if (language != 0) return true;
        for (const unsigned char* p = (const unsigned char*)value; p && *p; ++p)
            if (*p >= 0x80) return true;
        return false;
    }
    struct TextImage {
        __strong id<MTLTexture> texture = nil;
        ImVec2 content{0, 0};
        float padding = 3.f;
    };
    static std::unordered_map<std::string, TextImage>& textCache() {
        static std::unordered_map<std::string, TextImage> cache;
        return cache;
    }
    static void beginFrame() {
        static int previousLanguage = -1;
        if (previousLanguage != language || textCache().size() > 1024) {
            textCache().clear();
            previousLanguage = language;
        }
    }
    static const TextImage& image(const char* value, float fontSize, float wrap = 0.f) {
        const int points = ImMax(12, (int)ceilf(fontSize * 2.f));
        const int wrapPoints = wrap > 0.f ? (int)ceilf(wrap) : 0;
        const std::string cacheKey = std::to_string(language) + ":" + std::to_string(points) + ":" +
                                     std::to_string(wrapPoints) + ":" + (value ? value : "");
        auto& cache = textCache();
        const auto found = cache.find(cacheKey);
        if (found != cache.end()) return found->second;
        TextImage item;
        item.padding = 3.f;
        NSString* text = [NSString stringWithUTF8String:value ? value : ""];
        if (!text || text.length == 0) {
            cache[cacheKey] = item;
            return cache[cacheKey];
        }
        id<MTLDevice> device = MTLCreateSystemDefaultDevice();
        if (!device) {
            cache[cacheKey] = item;
            return cache[cacheKey];
        }
        UIFont* font = [UIFont systemFontOfSize:(CGFloat)points weight:UIFontWeightMedium];
        NSMutableParagraphStyle* style = [[NSMutableParagraphStyle alloc] init];
        style.alignment = rtl() ? NSTextAlignmentRight : NSTextAlignmentLeft;
        style.lineBreakMode = NSLineBreakByWordWrapping;
        NSDictionary* attributes = @{
            NSFontAttributeName: font,
            NSForegroundColorAttributeName: [UIColor whiteColor],
            NSParagraphStyleAttributeName: style
        };
        CGSize maxSize = CGSizeMake(wrapPoints > 0 ? (CGFloat)wrapPoints * 2.f : 2048.f, 2048.f);
        CGRect bounds = [text boundingRectWithSize:maxSize
                                           options:NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading
                                        attributes:attributes
                                           context:nil];
        const int pixelW = ImMax(2, (int)ceil(bounds.size.width + item.padding * 4.f));
        const int pixelH = ImMax(2, (int)ceil(bounds.size.height + item.padding * 4.f));
        CGColorSpaceRef space = CGColorSpaceCreateDeviceRGB();
        CGContextRef ctx = CGBitmapContextCreate(nullptr, pixelW, pixelH, 8, pixelW * 4, space,
                                                 kCGImageAlphaPremultipliedLast);
        if (ctx) {
            CGContextTranslateCTM(ctx, 0.0, (CGFloat)pixelH);
            CGContextScaleCTM(ctx, 1.0, -1.0);
            UIGraphicsPushContext(ctx);
            [text drawWithRect:CGRectMake(item.padding * 2.f, item.padding * 2.f,
                                          bounds.size.width + 2.f, bounds.size.height + 2.f)
                       options:NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading
                    attributes:attributes
                       context:nil];
            UIGraphicsPopContext();
            const void* pixels = CGBitmapContextGetData(ctx);
            if (pixels) {
                MTLTextureDescriptor* desc = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatRGBA8Unorm
                                                                                              width:pixelW
                                                                                             height:pixelH
                                                                                          mipmapped:NO];
                desc.usage = MTLTextureUsageShaderRead;
                id<MTLTexture> tex = [device newTextureWithDescriptor:desc];
                if (tex) {
                    [tex replaceRegion:MTLRegionMake2D(0, 0, pixelW, pixelH)
                               mipmapLevel:0
                                 withBytes:pixels
                               bytesPerRow:pixelW * 4];
                    item.texture = tex;
                    item.content = ImVec2((float)pixelW * .5f, (float)pixelH * .5f);
                }
            }
            CGContextRelease(ctx);
        }
        CGColorSpaceRelease(space);
        cache[cacheKey] = item;
        return cache[cacheKey];
    }
    static ImVec2 measure(const char* value, float fontSize = 0.f, float wrap = 0.f) {
        const char* text = tr(value);
        const float size = fontSize > 0.f ? fontSize : ImGui::GetFontSize();
        if (native(text)) {
            const TextImage& item = image(text, size, wrap);
            if (item.texture)
                return ImVec2(ImMax(0.f, item.content.x - item.padding * 2.f),
                              ImMax(0.f, item.content.y - item.padding * 2.f));
        }
        ImFont* f = SafeMenuFont();
        return f ? f->CalcTextSizeA(size, FLT_MAX, wrap, text) : ImVec2(0, size);
    }
    static void drawText(const char* value, ImVec2 pos, ImU32 color, float fontSize = 0.f, float wrap = 0.f) {
        const char* text = tr(value);
        const float size = fontSize > 0.f ? fontSize : ImGui::GetFontSize();
        ImDrawList* draw = ImGui::GetWindowDrawList();
        if (!draw) return;
        if (native(text)) {
            const TextImage& item = image(text, size, wrap);
            if (item.texture) {
                const float x = rtl() ? pos.x - item.content.x + item.padding : pos.x - item.padding;
                const float y = pos.y - item.padding;
                draw->AddImage((ImTextureID)(__bridge void*)item.texture,
                               ImVec2(x, y), ImVec2(x + item.content.x, y + item.content.y),
                               ImVec2(0, 0), ImVec2(1, 1), color);
                return;
            }
        }
        ImFont* f = SafeMenuFont();
        if (f) draw->AddText(f, size, pos, color, text, nullptr, wrap);
    }
    static void text(const char* value, float wrap = 0.f) {
        const char* text = tr(value);
        if (native(text)) {
            const TextImage& item = image(text, ImGui::GetFontSize(), wrap);
            if (item.texture) {
                const ImVec2 size(ImMax(0.f, item.content.x - item.padding * 2.f),
                                  ImMax(0.f, item.content.y - item.padding * 2.f));
                ImVec4 col = ImGui::GetStyle().Colors[ImGuiCol_Text];
                ImGui::Image((ImTextureID)(__bridge void*)item.texture, size,
                             ImVec2(0.5f / item.content.x, 0.5f / item.content.y),
                             ImVec2(1.f - 0.5f / item.content.x, 1.f - 0.5f / item.content.y), col);
                return;
            }
        }
        ImGui::TextUnformatted(text);
    }
    static void textDisabled(const char* value, float wrap = 0.f) {
        ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyle().Colors[ImGuiCol_TextDisabled]);
        text(value, wrap);
        ImGui::PopStyleColor();
    }
    static void textColored(ImVec4 color, const char* value, float wrap = 0.f) {
        ImGui::PushStyleColor(ImGuiCol_Text, color);
        text(value, wrap);
        ImGui::PopStyleColor();
    }
}

extern "C" void SetMenuLanguage(int language) {
    MenuLocale::language = (language >= 0 && language <= 6) ? language : 0;
}

extern "C" const char* TranslateMenuText(const char* value) {
    return MenuLocale::tr(value);
}

static bool DrawCyberButton(const char* label, const ImVec2& size_arg = ImVec2(0, 0)) {
    const char* translated = MenuLocale::tr(label);
    if (!MenuLocale::native(translated))
        return ImGui::Button(translated, size_arg);
    const ImVec2 labelSize = MenuLocale::measure(label);
    const ImGuiStyle& style = ImGui::GetStyle();
    const ImVec2 size = ImGui::CalcItemSize(size_arg, labelSize.x + style.FramePadding.x * 2.f,
                                            ImMax(labelSize.y, ImGui::GetFontSize()) + style.FramePadding.y * 2.f);
    const bool clicked = ImGui::Button("", size);
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (!window || window->SkipItems) return clicked;
    const ImRect rect(ImGui::GetItemRectMin(), ImGui::GetItemRectMax());
    const float y = rect.Min.y + (rect.GetHeight() - labelSize.y) * .5f;
    const float x = MenuLocale::rtl() ? rect.Max.x - style.FramePadding.x
                                      : rect.Min.x + (rect.GetWidth() - labelSize.x) * .5f;
    MenuLocale::drawText(label, ImVec2(x, y), ImGui::GetColorU32(ImGuiCol_Text));
    return clicked;
}

static bool DrawCyberSelectable(const char* label, bool selected, ImGuiSelectableFlags flags = 0, const ImVec2& size_arg = ImVec2(0, 0)) {
    const char* translated = MenuLocale::tr(label);
    if (!MenuLocale::native(translated))
        return ImGui::Selectable(translated, selected, flags, size_arg);
    const ImVec2 labelSize = MenuLocale::measure(label);
    const ImGuiStyle& style = ImGui::GetStyle();
    const ImVec2 size = ImGui::CalcItemSize(size_arg, labelSize.x + style.ItemSpacing.x,
                                            ImMax(labelSize.y, ImGui::GetFontSize()) + style.ItemSpacing.y * .5f);
    const bool clicked = ImGui::Selectable("", selected, flags, size);
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (!window || window->SkipItems) return clicked;
    const ImRect rect(ImGui::GetItemRectMin(), ImGui::GetItemRectMax());
    const float y = rect.Min.y + (rect.GetHeight() - labelSize.y) * .5f;
    const float x = MenuLocale::rtl() ? rect.Max.x - style.FramePadding.x : rect.Min.x + style.FramePadding.x;
    MenuLocale::drawText(label, ImVec2(x, y), ImGui::GetColorU32(ImGuiCol_Text));
    return clicked;
}

static void DrawCyberTooltip(const char* label) {
    if (ImGui::BeginTooltip()) {
        MenuLocale::text(label, 280.f);
        ImGui::EndTooltip();
    }
}

// HMOOD__TG@i_8_f


namespace CyberMenu {

static ImU32 U32(ImVec4 c) { return ImGui::ColorConvertFloat4ToU32(c); }
static ImVec4 RGBA(int r, int g, int b, float a = 1.f) { return ImVec4(r/255.f, g/255.f, b/255.f, a); }

static ImVec4 g_Accent = RGBA(209, 18, 48, 1.f);
static ImVec4 g_BgMain = RGBA(8, 9, 14, 0.96f);
static ImVec4 g_BgPanel = RGBA(13, 15, 22, 1.f);
static ImVec4 g_BgCard = RGBA(19, 21, 31, 1.f);
static ImVec4 g_BgHover = RGBA(28, 31, 45, 1.f);
static ImVec4 g_Border = RGBA(38, 42, 62, 0.75f);
static ImVec4 g_TextMain = RGBA(242, 244, 250, 1.f);
static ImVec4 g_TextDim = RGBA(135, 142, 165, 1.f);
static ImVec4 g_TextMuted = RGBA(88, 94, 115, 1.f);
static ImVec4 g_Green = RGBA(45, 215, 120, 1.f);
static ImVec4 g_Yellow = RGBA(245, 190, 45, 1.f);
static ImVec4 g_Red = RGBA(235, 55, 75, 1.f);
static ImVec4 g_Cyan = RGBA(55, 195, 240, 1.f);

struct State {
    int tab = 0;
    int espSubTab = 0;
    int aimSubTab = 0;
    int memSubTab = 0;
    int setSubTab = 0;

    int espStyle = 1;
    bool espPlayer = true;
    bool espName = true;
    bool espWeapon = false;
    bool espGameInfo = false;
    bool espDist = true;
    bool espHealth = true;
    bool esp360 = true;
    bool espLine = false;
    bool espBox = false;
    bool espBone = true;
    bool espIgnoreBot = false;
    bool espEnemyCount = true;
    bool espTeamId = false;
    bool espEnemyAim = true;
    bool espLootBox = false;
    bool espItems = false;
    bool espVehicle = false;

    float espDistMax = 300.f;
    float espHpScale = 1.0f;
    float esp360Radius = 80.f;
    float espStroke = 1.0f;
    bool espTextBorder = true;
    bool espHideName = false;
    float espDistCol[4] = {1.f, 0.85f, 0.2f, 1.f};
    float espBorderCol[4] = {0.05f, 0.78f, 0.95f, 0.85f};

    bool aimEnable = false;
    bool aimSilent = false;
    bool aimMacro = false;
    bool aimLine = false;
    bool aimAutoFire = false;
    bool aimVisCheck = true;
    bool aimIgnoreBot = false;
    bool aimIgnoreKnocked = false;
    bool aimShowFov = true;
    int aimTarget = 0;
    int aimTrigger = 3;
    float aimFov = 120.f;
    float aimDist = 250.f;
    float aimSpeed = 6.f;
    float aimHitProb = 100.f;
    int aimMode = 0;
    bool aimPredict = true;
    float aimMaxStep = 3.5f;
    float magicX = 0.f, magicY = 0.f, magicZ = 0.f;

    bool memAutoTap = false;
    bool memFastShoot = false;
    bool memFastScope = false;
    bool memFastGun = false;
    bool memSpin = false;
    bool memZoom = false;
    bool memIpad = false;
    bool memNoRecoil = false;
    bool memNoShake = false;
    bool memHitX = false;
    bool memDamage = false;
    bool memSmallCross = false;
    bool memRainbow = false;
    bool memCrossSpin = false;
    bool memFastDrop = false;
    bool memSuperRun = false;
    float memSpinSpeed = 10.f;
    float memIpadVal = 120.f;
    float memCrossSize = 4.f;

    bool setStreamHide = false;
    int setLang = 0;
    bool confirmGuestReset = false;

    char toast[128] = "";
    float toastTimer = 0.f;
    ImVec4 toastCol = g_Green;
};

static State& S() { static State s; return s; }

static void Toast(const char* msg, ImVec4 col = g_Green) {
    snprintf(S().toast, sizeof(S().toast), "%s", MenuLocale::tr(msg));
    S().toastTimer = 2.2f;
    S().toastCol = col;
}

static void SyncFromGlobals() {
    State& s = S();
    s.espStyle = IsStyle;
    s.espPlayer = imgui::ESP;
    s.espName = imgui::Name;
    s.espWeapon = imgui::Weapon;
    s.espGameInfo = imgui::GameInfo;
    s.espDist = imgui::Distance;
    s.espHealth = imgui::Health;
    s.esp360 = imgui::Alert360;
    s.espLine = imgui::Line;
    s.espBox = imgui::Boxes;
    s.espBone = imgui::Bone;
    s.espIgnoreBot = imgui::HideBot;
    s.espEnemyCount = imgui::EnemyCount;
    s.espTeamId = imgui::TeamID;
    s.espEnemyAim = imgui::EnemyAiming;
    s.espLootBox = imgui::Lootbox;
    s.espItems = imgui::Items;
    s.espVehicle = imgui::Vehicle;

    s.espDistMax = ESPMaxDistance;
    s.espHpScale = globalHpAlphaF;
    s.esp360Radius = AlertRadius;
    s.espStroke = strokeIntensity;
    s.espTextBorder = textBorder;
    s.espHideName = hideNameKillMsg;

    ImVec4 dc = ImGui::ColorConvertU32ToFloat4(COLOR_Distance);
    s.espDistCol[0] = dc.x; s.espDistCol[1] = dc.y; s.espDistCol[2] = dc.z; s.espDistCol[3] = dc.w;
    s.espBorderCol[0] = bgColor.Value.x; s.espBorderCol[1] = bgColor.Value.y;
    s.espBorderCol[2] = bgColor.Value.z; s.espBorderCol[3] = bgColor.Value.w;

    s.aimEnable = Settings::Aimbot::Tick;
    s.aimSilent = Enable;
    s.aimLine = Settings::Aimbot::SilentAimSettings::AimingLine;
    s.aimAutoFire = 自动开火;
    s.aimVisCheck = Settings::isVisibilityCheck;
    s.aimIgnoreBot = Settings::Aimbot::SilentAimSettings::Highprecisiontracking;
    s.aimIgnoreKnocked = Settings::Aimbot::SilentAimSettings::AimKnocked;
    s.aimShowFov = Settings::Aimbot::SilentAimSettings::EnableFov;
    s.aimTarget = Settings::Aimbot::SilentAimSettings::Aimpositon;
    s.aimTrigger = Settings::Aimbot::TriggerMode.load(std::memory_order_relaxed);
    s.aimFov = Cross;
    s.aimDist = SilentAimMaxDistance;
    s.aimSpeed = AimSmooth;
    s.aimHitProb = 追踪概率;
    s.aimMode = Settings::Aimbot::AimMethod;
    s.aimPredict = Settings::Aimbot::SilentAimSettings::Prediction;
    s.aimMaxStep = Settings::Aimbot::SilentAimSettings::MaxStepDeg;
    s.magicX = magicX; s.magicY = magicY; s.magicZ = magicZ;

    s.memFastShoot = IsFastshoot;
    s.memFastScope = MemoryFastScope;
    s.memFastGun = IsFastSwitch;
    s.memSpin = isSpinning;
    s.memZoom = MemoryZoom;
    s.memIpad = WideView;
    s.memNoRecoil = IsNorecoil2;
    s.memNoShake = IsNocamerashake;
    s.memHitX = HitX;
    s.memDamage = MemoryDamage;
    s.memSmallCross = IsCrossHair;
    s.memRainbow = MemoryRainbow;
    s.memCrossSpin = MemoryCrossSpin;
    s.memFastDrop = IsFastDrop;
    s.memSuperRun = chaynhanhv2;
    s.memSpinSpeed = tocdoquay;
    s.memIpadVal = (float)WideValue;
    s.memCrossSize = crosshairSizeSlider;

    s.setStreamHide = hideHacker;
    s.setLang = MenuLocale::language;
}

static void SyncToGlobals() {
    State& s = S();
    IsStyle = s.espStyle;
    imgui::ESP = s.espPlayer;
    imgui::Name = s.espName;
    imgui::Weapon = s.espWeapon;
    imgui::GameInfo = s.espGameInfo;
    imgui::Distance = s.espDist;
    imgui::Health = s.espHealth;
    imgui::Alert360 = s.esp360;
    imgui::Line = s.espLine;
    imgui::Boxes = s.espBox;
    imgui::Bone = s.espBone;
    imgui::HideBot = s.espIgnoreBot;
    imgui::EnemyCount = s.espEnemyCount;
    imgui::TeamID = s.espTeamId;
    imgui::EnemyAiming = s.espEnemyAim;
    imgui::Lootbox = s.espLootBox;
    imgui::Items = s.espItems;
    imgui::Vehicle = s.espVehicle;

    ESPMaxDistance = s.espDistMax;
    globalHpAlphaF = s.espHpScale;
    AlertRadius = s.esp360Radius;
    strokeIntensity = s.espStroke;
    textBorder = s.espTextBorder;
    hideNameKillMsg = s.espHideName;

    COLOR_Distance = ImGui::ColorConvertFloat4ToU32(ImVec4(s.espDistCol[0], s.espDistCol[1], s.espDistCol[2], s.espDistCol[3]));
    bgColor = ImColor(s.espBorderCol[0], s.espBorderCol[1], s.espBorderCol[2], s.espBorderCol[3]);

    Settings::Aimbot::Tick = s.aimEnable;
    Settings::Aimbot::AimMethod = s.aimMode;
    Enable = s.aimSilent && s.aimEnable && s.aimMode != 0;
    Settings::Aimbot::SilentAim = Enable;
    Settings::Aimbot::SilentAimSettings::AimingLine = s.aimLine;
    自动开火 = s.aimAutoFire && s.aimEnable;
    Settings::isVisibilityCheck = s.aimVisCheck;
    Settings::Aimbot::SilentAimSettings::Highprecisiontracking = s.aimIgnoreBot;
    Settings::Aimbot::SilentAimSettings::AimKnocked = s.aimIgnoreKnocked;
    Settings::Aimbot::SilentAimSettings::EnableFov = s.aimShowFov;
    Settings::Aimbot::SilentAimSettings::Aimpositon = s.aimTarget;
    Settings::Aimbot::TriggerMode.store(s.aimTrigger, std::memory_order_relaxed);
    Cross = s.aimFov;
    SilentAimMaxDistance = s.aimDist;
    AimSmooth = s.aimSpeed;
    追踪概率 = s.aimHitProb;
    Settings::Aimbot::SilentAimSettings::Prediction = s.aimPredict;
    Settings::Aimbot::SilentAimSettings::MaxStepDeg = s.aimMaxStep;
    magicX = s.magicX; magicY = s.magicY; magicZ = s.magicZ;

    IsFastshoot = s.memFastShoot;
    MemoryFastScope = s.memFastScope;
    IsFastSwitch = s.memFastGun;
    isSpinning = s.memSpin;
    MemoryZoom = s.memZoom;
    WideView = s.memIpad;
    IsNorecoil2 = s.memNoRecoil;
    IsNocamerashake = s.memNoShake;
    HitX = s.memHitX;
    MemoryDamage = s.memDamage;
    IsCrossHair = s.memSmallCross;
    MemoryRainbow = s.memRainbow;
    MemoryCrossSpin = s.memCrossSpin;
    IsFastDrop = s.memFastDrop;
    chaynhanhv2 = s.memSuperRun;
    tocdoquay = s.memSpinSpeed;
    WideValue = (int)s.memIpadVal;
    crosshairSizeSlider = s.memCrossSize;

    hideHacker = s.setStreamHide;
    MenuLocale::language = s.setLang;
}

static bool SwitchRow(const char* label, bool* v, const char* hint = nullptr) {
    ImGuiWindow* win = ImGui::GetCurrentWindow();
    if (win->SkipItems) return false;

    ImGuiStyle& style = ImGui::GetStyle();
    float w = ImGui::GetContentRegionAvail().x;
    float h = 28.f;
    ImVec2 pos = ImGui::GetCursorScreenPos();
    ImRect bb(pos, ImVec2(pos.x + w, pos.y + h));

    ImGui::ItemSize(bb, style.FramePadding.y);
    ImGuiID id = win->GetID(label);
    if (!ImGui::ItemAdd(bb, id)) return false;

    bool hovered = false, held = false;
    bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held);
    if (pressed && v) {
        *v = !(*v);
        SyncToGlobals();
        Toast(label, *v ? g_Green : g_TextDim);
    }

    ImDrawList* dl = ImGui::GetWindowDrawList();
    bool active = v ? *v : false;

    ImU32 rowBg = hovered ? U32(g_BgHover) : U32(g_BgCard);
    dl->AddRectFilled(bb.Min, bb.Max, rowBg, 5.f);

    float swW = 34.f, swH = 18.f;
    float swX = bb.Max.x - swW - 8.f;
    float swY = bb.Min.y + (h - swH) * 0.5f;
    ImVec2 swMin(swX, swY), swMax(swX + swW, swY + swH);

    ImU32 trackCol = active ? U32(g_Accent) : U32(RGBA(42, 46, 66, 1.f));
    dl->AddRectFilled(swMin, swMax, trackCol, swH * 0.5f);

    float rad = swH * 0.5f - 2.5f;
    float knobX = active ? (swMax.x - rad - 2.5f) : (swMin.x + rad + 2.5f);
    dl->AddCircleFilled(ImVec2(knobX, swMin.y + swH * 0.5f), rad, U32(g_TextMain), 16);

    float textRight = swMin.x - 8.f;
    float textY = bb.Min.y + (h - MenuLocale::measure(label).y) * 0.5f;
    ImU32 txtCol = active ? U32(g_TextMain) : U32(RGBA(185, 192, 212, 1.f));
    if (MenuLocale::rtl()) {
        MenuLocale::drawText(label, ImVec2(textRight, textY), txtCol);
    } else {
        MenuLocale::drawText(label, ImVec2(bb.Min.x + 10.f, textY), txtCol);
    }

    if (hovered && hint) {
        DrawCyberTooltip(hint);
    }
    return pressed;
}

static bool SliderRow(const char* label, float* v, float vMin, float vMax, const char* fmt = "%.1f", const char* hint = nullptr) {
    ImGuiWindow* win = ImGui::GetCurrentWindow();
    if (win->SkipItems) return false;

    ImGuiStyle& style = ImGui::GetStyle();
    float w = ImGui::GetContentRegionAvail().x;
    float h = 38.f;
    ImVec2 pos = ImGui::GetCursorScreenPos();
    ImRect bb(pos, ImVec2(pos.x + w, pos.y + h));

    ImGui::ItemSize(bb, style.FramePadding.y);
    ImGuiID id = win->GetID(label);
    if (!ImGui::ItemAdd(bb, id)) return false;

    ImDrawList* dl = ImGui::GetWindowDrawList();
    dl->AddRectFilled(bb.Min, bb.Max, U32(g_BgCard), 5.f);

    char valBuf[32];
    snprintf(valBuf, sizeof(valBuf), fmt, v ? *v : 0.f);
    ImVec2 valSz = ImGui::CalcTextSize(valBuf);

    float topY = bb.Min.y + 5.f;
    if (MenuLocale::rtl()) {
        dl->AddText(ImVec2(bb.Min.x + 10.f, topY), U32(g_Cyan), valBuf);
        MenuLocale::drawText(label, ImVec2(bb.Max.x - 10.f, topY), U32(g_TextMain));
    } else {
        MenuLocale::drawText(label, ImVec2(bb.Min.x + 10.f, topY), U32(g_TextMain));
        dl->AddText(ImVec2(bb.Max.x - valSz.x - 10.f, topY), U32(g_Cyan), valBuf);
    }

    float barX0 = bb.Min.x + 10.f;
    float barX1 = bb.Max.x - 10.f;
    float barY = bb.Max.y - 10.f;
    float barH = 5.f;

    ImRect barBB(ImVec2(barX0, barY - 5.f), ImVec2(barX1, barY + barH + 5.f));
    bool hovered = ImGui::IsMouseHoveringRect(bb.Min, bb.Max);
    bool held = false;
    if (ImGui::IsMouseHoveringRect(barBB.Min, barBB.Max) && ImGui::IsMouseClicked(0)) {
        ImGui::SetActiveID(id, win);
    }
    if (ImGui::GetActiveID() == id) {
        if (ImGui::IsMouseDown(0)) {
            held = true;
            float t = ImClamp((ImGui::GetIO().MousePos.x - barX0) / ImMax(1.f, barX1 - barX0), 0.f, 1.f);
            if (v) {
                *v = vMin + t * (vMax - vMin);
                SyncToGlobals();
            }
        } else {
            ImGui::ClearActiveID();
        }
    }

    float frac = v ? ImClamp((*v - vMin) / ImMax(0.0001f, vMax - vMin), 0.f, 1.f) : 0.f;
    float fillX = barX0 + frac * (barX1 - barX0);

    dl->AddRectFilled(ImVec2(barX0, barY), ImVec2(barX1, barY + barH), U32(RGBA(35, 39, 58, 1.f)), 2.5f);
    if (fillX > barX0) {
        dl->AddRectFilled(ImVec2(barX0, barY), ImVec2(fillX, barY + barH), U32(g_Accent), 2.5f);
    }
    dl->AddCircleFilled(ImVec2(fillX, barY + barH * 0.5f), (held || hovered) ? 6.5f : 5.5f, U32(g_TextMain), 14);

    if (hovered && hint) {
        DrawCyberTooltip(hint);
    }
    return held;
}

static void SectionHeader(const char* title) {
    ImGui::Spacing();
    float y = ImGui::GetCursorScreenPos().y;
    float x = ImGui::GetCursorScreenPos().x;
    float w = ImGui::GetContentRegionAvail().x;
    ImDrawList* dl = ImGui::GetWindowDrawList();
    if (MenuLocale::rtl()) {
        dl->AddRectFilled(ImVec2(x + w - 3.f, y + 2.f), ImVec2(x + w, y + 14.f), U32(g_Accent), 1.5f);
        MenuLocale::drawText(title, ImVec2(x + w - 9.f, y + 1.f), U32(g_TextDim), 11.5f);
    } else {
        dl->AddRectFilled(ImVec2(x, y + 2.f), ImVec2(x + 3.f, y + 14.f), U32(g_Accent), 1.5f);
        MenuLocale::drawText(title, ImVec2(x + 9.f, y + 1.f), U32(g_TextDim), 11.5f);
    }
    ImGui::Dummy(ImVec2(w, 18.f));
}

static bool SubTabBar(const char* const* labels, int count, int* current) {
    bool changed = false;
    float avail = ImGui::GetContentRegionAvail().x;
    float gap = 6.f;
    float btnW = (avail - gap * (count - 1)) / ImMax(1, count);
    float btnH = 26.f;

    for (int i = 0; i < count; ++i) {
        if (i > 0) ImGui::SameLine(0.f, gap);
        bool sel = (*current == i);
        ImGui::PushStyleColor(ImGuiCol_Button, sel ? g_Accent : g_BgCard);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, sel ? g_Accent : g_BgHover);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, g_Accent);
        ImGui::PushStyleColor(ImGuiCol_Text, sel ? g_TextMain : g_TextDim);
        if (DrawCyberButton(labels[i], ImVec2(btnW, btnH))) {
            *current = i;
            changed = true;
        }
        ImGui::PopStyleColor(4);
    }
    ImGui::Spacing();
    return changed;
}

static void DrawBadgeIcon(ImDrawList* dl, ImVec2 center, float radius) {
    UIImage* badge = GetMenuBadgeImage();
    if (badge && badge.CGImage) {
        static id<MTLTexture> s_badgeTex = nil;
        static dispatch_once_t once;
        dispatch_once(&once, ^{
            id<MTLDevice> dev = MTLCreateSystemDefaultDevice();
            if (!dev) return;
            const int w = 128, h = 128;
            CGColorSpaceRef sp = CGColorSpaceCreateDeviceRGB();
            CGContextRef ctx = CGBitmapContextCreate(nullptr, w, h, 8, w * 4, sp, kCGImageAlphaPremultipliedLast);
            if (ctx) {
                CGContextTranslateCTM(ctx, 0, h);
                CGContextScaleCTM(ctx, 1, -1);
                UIGraphicsPushContext(ctx);
                [badge drawInRect:CGRectMake(0, 0, w, h)];
                UIGraphicsPopContext();
                const void* px = CGBitmapContextGetData(ctx);
                if (px) {
                    MTLTextureDescriptor* td = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatRGBA8Unorm
                                                                                                  width:w height:h mipmapped:NO];
                    td.usage = MTLTextureUsageShaderRead;
                    s_badgeTex = [dev newTextureWithDescriptor:td];
                    if (s_badgeTex) {
                        [s_badgeTex replaceRegion:MTLRegionMake2D(0, 0, w, h) mipmapLevel:0 withBytes:px bytesPerRow:w * 4];
                    }
                }
                CGContextRelease(ctx);
            }
            CGColorSpaceRelease(sp);
        });
        if (s_badgeTex) {
            dl->AddImageRounded((ImTextureID)(__bridge void*)s_badgeTex,
                                ImVec2(center.x - radius, center.y - radius),
                                ImVec2(center.x + radius, center.y + radius),
                                ImVec2(0, 0), ImVec2(1, 1), U32(ImVec4(1, 1, 1, 1)), radius);
            dl->AddCircle(center, radius, U32(g_Accent), 32, 1.5f);
            return;
        }
    }
    dl->AddCircleFilled(center, radius, U32(RGBA(28, 16, 24, 1.f)), 32);
    dl->AddCircle(center, radius, U32(g_Accent), 32, 1.5f);
    ImVec2 tsz = ImGui::CalcTextSize("D");
    dl->AddText(ImVec2(center.x - tsz.x * 0.5f, center.y - tsz.y * 0.5f), U32(g_TextMain), "D");
}

static void DrawHomeTab() {
    State& s = S();
    ImDrawList* dl = ImGui::GetWindowDrawList();
    float availW = ImGui::GetContentRegionAvail().x;

    ImVec2 cardPos = ImGui::GetCursorScreenPos();
    float cardH = 68.f;
    dl->AddRectFilled(cardPos, ImVec2(cardPos.x + availW, cardPos.y + cardH), U32(g_BgCard), 6.f);
    dl->AddRect(cardPos, ImVec2(cardPos.x + availW, cardPos.y + cardH), U32(g_Border), 6.f);

    DrawBadgeIcon(dl, ImVec2(cardPos.x + 34.f, cardPos.y + cardH * 0.5f), 21.f);

    dl->AddText(ImVec2(cardPos.x + 64.f, cardPos.y + 12.f), U32(g_TextMain), "DARKIOS");
    MenuLocale::drawText("License", ImVec2(cardPos.x + 64.f, cardPos.y + 30.f), U32(g_TextDim), 11.5f);
    const char* statusTxt = IsLogin ? "Active" : "Inactive";
    dl->AddText(ImVec2(cardPos.x + 64.f + MenuLocale::measure("License", 11.5f).x + 6.f, cardPos.y + 30.f),
                IsLogin ? U32(g_Green) : U32(g_Yellow), statusTxt);
    MenuLocale::drawText("Expires", ImVec2(cardPos.x + 64.f, cardPos.y + 46.f), U32(g_TextMuted), 11.f);
    dl->AddText(ImVec2(cardPos.x + 64.f + MenuLocale::measure("Expires", 11.f).x + 6.f, cardPos.y + 46.f),
                U32(g_TextDim), "N/A");

    float badgeW = 54.f, badgeH = 20.f;
    ImVec2 bMin(cardPos.x + availW - badgeW - 12.f, cardPos.y + 14.f);
    ImVec2 bMax(bMin.x + badgeW, bMin.y + badgeH);
    dl->AddRectFilled(bMin, bMax, U32(RGBA(20, 55, 38, 0.9f)), 4.f);
    dl->AddRect(bMin, bMax, U32(g_Green), 4.f);
    ImVec2 liveSz = ImGui::CalcTextSize("LIVE");
    dl->AddText(ImVec2(bMin.x + (badgeW - liveSz.x) * 0.5f, bMin.y + (badgeH - liveSz.y) * 0.5f), U32(g_Green), "LIVE");

    ImGui::Dummy(ImVec2(availW, cardH + 6.f));

    float halfW = (availW - 8.f) * 0.5f;
    ImVec2 infoPos = ImGui::GetCursorScreenPos();
    float infoH = 54.f;

    dl->AddRectFilled(infoPos, ImVec2(infoPos.x + halfW, infoPos.y + infoH), U32(g_BgCard), 6.f);
    dl->AddRect(infoPos, ImVec2(infoPos.x + halfW, infoPos.y + infoH), U32(g_Border), 6.f);
    MenuLocale::drawText("Device", ImVec2(infoPos.x + 10.f, infoPos.y + 8.f), U32(g_TextMuted), 11.f);
    struct utsname u; uname(&u);
    char devBuf[48]; snprintf(devBuf, sizeof(devBuf), "%s", u.machine);
    dl->AddText(ImVec2(infoPos.x + 10.f, infoPos.y + 22.f), U32(g_TextMain), devBuf);
    MenuLocale::drawText("OS", ImVec2(infoPos.x + 10.f, infoPos.y + 37.f), U32(g_TextMuted), 10.5f);
    dl->AddText(ImVec2(infoPos.x + 10.f + MenuLocale::measure("OS", 10.5f).x + 5.f, infoPos.y + 37.f),
                U32(g_TextDim), [[UIDevice currentDevice] systemVersion].UTF8String);

    ImVec2 rPos(infoPos.x + halfW + 8.f, infoPos.y);
    dl->AddRectFilled(rPos, ImVec2(rPos.x + halfW, rPos.y + infoH), U32(g_BgCard), 6.f);
    dl->AddRect(rPos, ImVec2(rPos.x + halfW, rPos.y + infoH), U32(g_Border), 6.f);
    MenuLocale::drawText("Key", ImVec2(rPos.x + 10.f, rPos.y + 8.f), U32(g_TextMuted), 11.f);
    MenuLocale::drawText("Not configured", ImVec2(rPos.x + 10.f, rPos.y + 23.f), U32(g_TextDim), 11.5f);
    MenuLocale::drawText("RAM", ImVec2(rPos.x + 10.f, rPos.y + 38.f), U32(g_TextMuted), 10.5f);

    mach_port_t host = mach_host_self();
    vm_size_t pageSize = 0;
    host_page_size(host, &pageSize);
    vm_statistics64_data_t vmStats;
    mach_msg_type_number_t count = HOST_VM_INFO64_COUNT;
    float freeMB = 0.f;
    if (host_statistics64(host, HOST_VM_INFO64, (host_info64_t)&vmStats, &count) == KERN_SUCCESS) {
        freeMB = (float)((uint64_t)vmStats.free_count * (uint64_t)pageSize) / (1024.f * 1024.f);
    }
    char ramBuf[32]; snprintf(ramBuf, sizeof(ramBuf), "%.0f MB free", freeMB);
    dl->AddText(ImVec2(rPos.x + 10.f + MenuLocale::measure("RAM", 10.5f).x + 5.f, rPos.y + 38.f),
                U32(g_Cyan), ramBuf);

    ImGui::Dummy(ImVec2(availW, infoH + 6.f));

    ImVec2 modePos = ImGui::GetCursorScreenPos();
    float modeH = 44.f;
    dl->AddRectFilled(modePos, ImVec2(modePos.x + availW, modePos.y + modeH), U32(g_BgCard), 6.f);
    dl->AddRect(modePos, ImVec2(modePos.x + availW, modePos.y + modeH), U32(g_Border), 6.f);
    MenuLocale::drawText("Game Mode", ImVec2(modePos.x + 12.f, modePos.y + 7.f), U32(g_TextMain), 12.f);
    MenuLocale::drawText("Local mode", ImVec2(modePos.x + 12.f, modePos.y + 23.f), U32(g_TextDim), 11.f);

    float mBtnW = 90.f, mBtnH = 24.f;
    ImGui::SetCursorScreenPos(ImVec2(modePos.x + availW - mBtnW - 10.f, modePos.y + (modeH - mBtnH) * 0.5f));
    if (DrawCyberButton("Open Mode", ImVec2(mBtnW, mBtnH))) {
        Toast("No mode or licensing service is configured", g_Yellow);
    }
    ImGui::SetCursorScreenPos(ImVec2(modePos.x, modePos.y + modeH + 6.f));

    SectionHeader("Subscription");
    ImVec2 subPos = ImGui::GetCursorScreenPos();
    float subH = 44.f;
    dl->AddRectFilled(subPos, ImVec2(subPos.x + availW, subPos.y + subH), U32(g_BgCard), 6.f);
    dl->AddRect(subPos, ImVec2(subPos.x + availW, subPos.y + subH), U32(g_Border), 6.f);
    MenuLocale::drawText("Device Link", ImVec2(subPos.x + 12.f, subPos.y + 7.f), U32(g_TextMain), 12.f);
    MenuLocale::drawText("No license service", ImVec2(subPos.x + 12.f, subPos.y + 23.f), U32(g_TextDim), 11.f);

    ImGui::SetCursorScreenPos(ImVec2(subPos.x, subPos.y + subH + 6.f));

    SectionHeader("Contact");
    float cBtnW = (availW - 8.f) * 0.5f;
    if (DrawCyberButton("Telegram", ImVec2(cBtnW, 28.f))) {
        Toast("No contact link is configured in this project", g_TextDim);
    }
    ImGui::SameLine(0.f, 8.f);
    if (DrawCyberButton("Support", ImVec2(cBtnW, 28.f))) {
        Toast("No support link is configured in this project", g_TextDim);
    }

    (void)s;
}

static void DrawEspTab() {
    State& s = S();
    const char* subLabels[] = {"ESP Style", "Player ESP", "Existing Display Settings"};
    SubTabBar(subLabels, 3, &s.espSubTab);

    if (s.espSubTab == 0) {
        SectionHeader("ESP Style");
        const char* styles[] = {"Basic", "VIP Cyber Vertical"};
        for (int i = 0; i < 2; ++i) {
            bool sel = (s.espStyle == i);
            ImGui::PushStyleColor(ImGuiCol_Button, sel ? RGBA(35, 16, 24, 1.f) : g_BgCard);
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, g_BgHover);
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, g_Accent);
            if (DrawCyberButton(styles[i], ImVec2(-1.f, 34.f))) {
                s.espStyle = i;
                SyncToGlobals();
                Toast(styles[i], g_Green);
            }
            ImGui::PopStyleColor(3);
            ImGui::Spacing();
        }
    } else if (s.espSubTab == 1) {
        float availW = ImGui::GetContentRegionAvail().x;
        float colW = (availW - 8.f) * 0.5f;

        ImGui::BeginGroup();
        ImGui::PushItemWidth(colW);
        SwitchRow("Player ESP", &s.espPlayer);
        SwitchRow("Draw Names", &s.espName);
        SwitchRow("Draw Weapon", &s.espWeapon);
        SwitchRow("Game Info", &s.espGameInfo);
        SwitchRow("Draw Distance", &s.espDist);
        SwitchRow("Draw Health", &s.espHealth);
        SwitchRow("360 Alert", &s.esp360);
        SwitchRow("Snap Lines", &s.espLine);
        SwitchRow("Draw Boxes", &s.espBox);
        ImGui::PopItemWidth();
        ImGui::EndGroup();

        ImGui::SameLine(0.f, 8.f);

        ImGui::BeginGroup();
        ImGui::PushItemWidth(colW);
        SwitchRow("Draw Bones", &s.espBone);
        SwitchRow("Hide Bots", &s.espIgnoreBot);
        SwitchRow("Enemy Count", &s.espEnemyCount);
        SwitchRow("Player Team ID", &s.espTeamId);
        SwitchRow("Enemy Aiming", &s.espEnemyAim);
        SwitchRow("Lootbox", &s.espLootBox);
        SwitchRow("Items ESP", &s.espItems);
        SwitchRow("Vehicle ESP", &s.espVehicle);
        ImGui::PopItemWidth();
        ImGui::EndGroup();
    } else {
        SliderRow("ESP Distance", &s.espDistMax, 50.f, 500.f, "%.0fm");
        SliderRow("HP Scale", &s.espHpScale, 0.5f, 2.0f, "%.2fx");
        SliderRow("Alert Radius", &s.esp360Radius, 30.f, 220.f, "%.0fpx");
        SliderRow("Stroke Width", &s.espStroke, 0.5f, 3.0f, "%.2f");
        SwitchRow("Text Border", &s.espTextBorder);
        SwitchRow("Hide Name", &s.espHideName);

        SectionHeader("Distance Color");
        if (ImGui::ColorEdit4("##distcol", s.espDistCol, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar)) {
            SyncToGlobals();
        }
        SectionHeader("Border Color");
        if (ImGui::ColorEdit4("##bordcol", s.espBorderCol, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar)) {
            SyncToGlobals();
        }
    }
}

static void DrawAimTab() {
    State& s = S();
    const char* subLabels[] = {"Aim Settings", "Aim Control"};
    SubTabBar(subLabels, 2, &s.aimSubTab);

    if (s.aimSubTab == 0) {
        float availW = ImGui::GetContentRegionAvail().x;
        float colW = (availW - 8.f) * 0.5f;

        ImGui::BeginGroup();
        ImGui::PushItemWidth(colW);
        SwitchRow("Aimbot", &s.aimEnable);
        SwitchRow("Silent Aim", &s.aimSilent);
        SwitchRow("Macro", &s.aimMacro);
        SwitchRow("Aim Line", &s.aimLine);
        SwitchRow("Auto Fire", &s.aimAutoFire);
        ImGui::PopItemWidth();
        ImGui::EndGroup();

        ImGui::SameLine(0.f, 8.f);

        ImGui::BeginGroup();
        ImGui::PushItemWidth(colW);
        SwitchRow("Visibility Check", &s.aimVisCheck);
        SwitchRow("Ignore Bots", &s.aimIgnoreBot);
        SwitchRow("Ignore Knocked", &s.aimIgnoreKnocked);
        SwitchRow("Enable FOV", &s.aimShowFov);
        ImGui::PopItemWidth();
        ImGui::EndGroup();

        ImGui::Spacing();
        const char* targets[] = {"Head", "Neck", "Body", "Pelvis"};
        MenuLocale::text("Aim Target");
        ImGui::SetNextItemWidth(-1.f);
        if (ImGui::BeginCombo("##cyber_target", MenuLocale::tr(targets[ImClamp(s.aimTarget, 0, 3)]))) {
            for (int i = 0; i < 4; ++i) {
                if (DrawCyberSelectable(targets[i], s.aimTarget == i)) {
                    s.aimTarget = i;
                    SyncToGlobals();
                }
            }
            ImGui::EndCombo();
        }

        const char* triggers[] = {"Fire", "ADS", "Fire + ADS", "Fire or ADS"};
        MenuLocale::text("Auto");
        ImGui::SetNextItemWidth(-1.f);
        if (ImGui::BeginCombo("##cyber_trigger", MenuLocale::tr(triggers[ImClamp(s.aimTrigger, 0, 3)]))) {
            for (int i = 0; i < 4; ++i) {
                if (DrawCyberSelectable(triggers[i], s.aimTrigger == i)) {
                    s.aimTrigger = i;
                    SyncToGlobals();
                }
            }
            ImGui::EndCombo();
        }

        SliderRow("FOV", &s.aimFov, 10.f, 360.f, "%.0fpx");
        SliderRow("Distance", &s.aimDist, 30.f, 450.f, "%.0fm");
        SliderRow("Aim Speed", &s.aimSpeed, 1.f, 30.f, "%.1f");
        SliderRow("Hit Probability", &s.aimHitProb, 0.f, 100.f, "%.0f%%");
    } else {
        SectionHeader("Mode");
        const char* modes[] = {"Safe", "Risk", "Custom"};
        SubTabBar(modes, 3, &s.aimMode);
        SyncToGlobals();

        SwitchRow("Prediction", &s.aimPredict);
        SliderRow("Max Step", &s.aimMaxStep, 0.5f, 15.f, "%.1f°");

        MenuLocale::text("Aim Target");
        const char* targets[] = {"Head", "Neck", "Body", "Pelvis"};
        ImGui::SetNextItemWidth(-1.f);
        if (ImGui::BeginCombo("##cyber_target_2", MenuLocale::tr(targets[ImClamp(s.aimTarget, 0, 3)]))) {
            for (int i = 0; i < 4; ++i) {
                if (DrawCyberSelectable(targets[i], s.aimTarget == i)) {
                    s.aimTarget = i;
                    SyncToGlobals();
                }
            }
            ImGui::EndCombo();
        }

        SectionHeader("More Memory Options");
        SliderRow("Magic X", &s.magicX, -50.f, 50.f, "%.1f");
        SliderRow("Magic Y", &s.magicY, -50.f, 50.f, "%.1f");
        SliderRow("Magic Z", &s.magicZ, -50.f, 50.f, "%.1f");
    }
}

static void DrawMemTab() {
    State& s = S();
    const char* subLabels[] = {"Memory", "More Memory Options"};
    SubTabBar(subLabels, 2, &s.memSubTab);

    if (s.memSubTab == 0) {
        float availW = ImGui::GetContentRegionAvail().x;
        float colW = (availW - 8.f) * 0.5f;

        ImGui::BeginGroup();
        ImGui::PushItemWidth(colW);
        SwitchRow("Auto Tap", &s.memAutoTap);
        SwitchRow("Fast Shoot", &s.memFastShoot);
        SwitchRow("Fast Scope", &s.memFastScope);
        SwitchRow("Fast Gun", &s.memFastGun);
        SwitchRow("Spin", &s.memSpin);
        SwitchRow("Zoom", &s.memZoom);
        SwitchRow("iPad", &s.memIpad);
        ImGui::PopItemWidth();
        ImGui::EndGroup();

        ImGui::SameLine(0.f, 8.f);

        ImGui::BeginGroup();
        ImGui::PushItemWidth(colW);
        SwitchRow("No Recoil", &s.memNoRecoil);
        SwitchRow("No Shake", &s.memNoShake);
        SwitchRow("HitX", &s.memHitX);
        SwitchRow("Damage", &s.memDamage);
        SwitchRow("Small Cross", &s.memSmallCross);
        SwitchRow("Rainbow", &s.memRainbow);
        SwitchRow("Cross Spin", &s.memCrossSpin);
        ImGui::PopItemWidth();
        ImGui::EndGroup();
    } else {
        SwitchRow("Fast Drop", &s.memFastDrop);
        SwitchRow("Super Run", &s.memSuperRun);
        SliderRow("Spin Speed", &s.memSpinSpeed, 1.f, 50.f, "%.1f");
        SliderRow("iPad View", &s.memIpadVal, 80.f, 160.f, "%.0f");
        SliderRow("Cross Size", &s.memCrossSize, 1.f, 20.f, "%.1f");
    }
}

static void DrawSetTab() {
    State& s = S();
    ImDrawList* dl = ImGui::GetWindowDrawList();
    float availW = ImGui::GetContentRegionAvail().x;

    SectionHeader("RAM Booster");
    ImVec2 ramPos = ImGui::GetCursorScreenPos();
    float ramH = 52.f;
    dl->AddRectFilled(ramPos, ImVec2(ramPos.x + availW, ramPos.y + ramH), U32(g_BgCard), 6.f);
    dl->AddRect(ramPos, ImVec2(ramPos.x + availW, ramPos.y + ramH), U32(g_Border), 6.f);

    mach_port_t host = mach_host_self();
    vm_size_t pageSize = 0;
    host_page_size(host, &pageSize);
    vm_statistics64_data_t vmStats;
    mach_msg_type_number_t count = HOST_VM_INFO64_COUNT;
    float freeMB = 0.f;
    if (host_statistics64(host, HOST_VM_INFO64, (host_info64_t)&vmStats, &count) == KERN_SUCCESS) {
        freeMB = (float)((uint64_t)vmStats.free_count * (uint64_t)pageSize) / (1024.f * 1024.f);
    }

    task_vm_info_data_t vmInfo;
    mach_msg_type_number_t vmCount = TASK_VM_INFO_COUNT;
    float appMB = 0.f;
    if (task_info(mach_task_self(), TASK_VM_INFO, (task_info_t)&vmInfo, &vmCount) == KERN_SUCCESS) {
        appMB = (float)vmInfo.phys_footprint / (1024.f * 1024.f);
    }

    char appStr[32], freeStr[32];
    snprintf(appStr, sizeof(appStr), "%.0f MB", appMB);
    snprintf(freeStr, sizeof(freeStr), "%.0f MB", freeMB);

    MenuLocale::drawText("App", ImVec2(ramPos.x + 12.f, ramPos.y + 8.f), U32(g_TextMuted), 10.5f);
    dl->AddText(ImVec2(ramPos.x + 12.f, ramPos.y + 22.f), U32(g_TextMain), appStr);

    MenuLocale::drawText("Free", ImVec2(ramPos.x + 95.f, ramPos.y + 8.f), U32(g_TextMuted), 10.5f);
    dl->AddText(ImVec2(ramPos.x + 95.f, ramPos.y + 22.f), U32(g_Green), freeStr);

    float pW = 72.f, pH = 24.f;
    ImGui::SetCursorScreenPos(ImVec2(ramPos.x + availW - pW - 10.f, ramPos.y + 8.f));
    if (DrawCyberButton("Purge", ImVec2(pW, pH))) {
        Toast("The current project has no memory purge operation", g_Yellow);
    }
    ImGui::SetCursorScreenPos(ImVec2(ramPos.x + availW - 115.f, ramPos.y + 35.f));
    MenuLocale::drawText("Auto-Clean: OFF", ImGui::GetCursorScreenPos(), U32(g_TextMuted), 10.f);

    ImGui::SetCursorScreenPos(ImVec2(ramPos.x, ramPos.y + ramH + 6.f));

    SectionHeader("Preferences");
    SwitchRow(s.setStreamHide ? "Stream: ON" : "Stream: OFF", &s.setStreamHide);

    MenuLocale::text("Language");
    ImGui::SetNextItemWidth(-1.f);
    if (ImGui::BeginCombo("##cyber_lang", MenuLocale::languageNames[ImClamp(s.setLang, 0, 6)])) {
        for (int i = 0; i < 7; ++i) {
            if (ImGui::Selectable(MenuLocale::languageNames[i], s.setLang == i)) {
                s.setLang = i;
                MenuLocale::language = i;
                Toast("Language", g_Green);
            }
        }
        ImGui::EndCombo();
    }

    ImGui::Spacing();
    ImGui::PushStyleColor(ImGuiCol_Button, RGBA(55, 16, 22, 1.f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, RGBA(85, 22, 30, 1.f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, g_Accent);
    ImGui::PushStyleColor(ImGuiCol_Text, g_Red);
    if (DrawCyberButton("Reset Guest", ImVec2(-1.f, 30.f))) {
        s.confirmGuestReset = true;
    }
    ImGui::PopStyleColor(4);

    if (s.confirmGuestReset) {
        ImGui::OpenPopup("##guest_reset_popup");
        s.confirmGuestReset = false;
    }
    if (ImGui::BeginPopupModal("##guest_reset_popup", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar)) {
        MenuLocale::text("Reset guest account?");
        ImGui::Spacing();
        MenuLocale::textDisabled("This deletes local game data, settings and account data.", 260.f);
        MenuLocale::textDisabled("The game will exit after the reset.", 260.f);
        ImGui::Spacing();
        if (DrawCyberButton("Cancel", ImVec2(110.f, 26.f))) {
            ImGui::CloseCurrentPopup();
        }
        ImGui::SameLine(0.f, 8.f);
        ImGui::PushStyleColor(ImGuiCol_Button, g_Accent);
        if (DrawCyberButton("Reset Guest", ImVec2(110.f, 26.f))) {
            ImGui::CloseCurrentPopup();
            ResetGuestAccount();
        }
        ImGui::PopStyleColor();
        ImGui::EndPopup();
    }
}

static void DrawToast() {
    State& s = S();
    if (s.toastTimer <= 0.f || s.toast[0] == '\0') return;
    s.toastTimer -= ImGui::GetIO().DeltaTime;

    ImGuiWindow* win = ImGui::GetCurrentWindow();
    ImVec2 wMin = win->Pos;
    float wW = win->Size.x;

    float alpha = ImClamp(s.toastTimer / 0.4f, 0.f, 1.f);
    ImVec4 bg = g_BgPanel; bg.w *= alpha;
    ImVec4 col = s.toastCol; col.w *= alpha;

    ImVec2 tsz = MenuLocale::measure(s.toast, 11.5f);
    float pw = tsz.x + 24.f, ph = 24.f;
    float px = wMin.x + (wW - pw) * 0.5f;
    float py = wMin.y + 42.f;

    ImDrawList* dl = ImGui::GetWindowDrawList();
    dl->AddRectFilled(ImVec2(px, py), ImVec2(px + pw, py + ph), U32(bg), 5.f);
    dl->AddRect(ImVec2(px, py), ImVec2(px + pw, py + ph), U32(col), 5.f);
    MenuLocale::drawText(s.toast, ImVec2(px + 12.f, py + (ph - tsz.y) * 0.5f), U32(col), 11.5f);
}

static void RenderWindow() {
    State& s = S();
    static bool syncedOnce = false;
    if (!syncedOnce) {
        SyncFromGlobals();
        syncedOnce = true;
    }

    ImGui::SetNextWindowSize(ImVec2(450.f, 330.f), ImGuiCond_FirstUseEver);
    ImGui::PushStyleColor(ImGuiCol_WindowBg, g_BgMain);
    ImGui::PushStyleColor(ImGuiCol_Border, g_Border);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.f, 0.f));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 8.f);

    ImGuiWindowFlags flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse;
    if (!ImGui::Begin("##DarkosCyberMenu", nullptr, flags)) {
        ImGui::End();
        ImGui::PopStyleVar(2);
        ImGui::PopStyleColor(2);
        return;
    }

    ImVec2 wPos = ImGui::GetWindowPos();
    ImVec2 wSize = ImGui::GetWindowSize();
    ImDrawList* dl = ImGui::GetWindowDrawList();

    float headerH = 34.f;
    dl->AddRectFilled(wPos, ImVec2(wPos.x + wSize.x, wPos.y + headerH), U32(g_BgPanel), 8.f, ImDrawFlags_RoundCornersTop);
    dl->AddLine(ImVec2(wPos.x, wPos.y + headerH), ImVec2(wPos.x + wSize.x, wPos.y + headerH), U32(g_Border), 1.f);

    DrawBadgeIcon(dl, ImVec2(wPos.x + 20.f, wPos.y + headerH * 0.5f), 9.f);
    dl->AddText(ImVec2(wPos.x + 34.f, wPos.y + 10.f), U32(g_TextMain), "DARKIOS");

    float closeSz = 20.f;
    ImGui::SetCursorScreenPos(ImVec2(wPos.x + wSize.x - closeSz - 8.f, wPos.y + (headerH - closeSz) * 0.5f));
    ImGui::PushStyleColor(ImGuiCol_Button, RGBA(35, 16, 22, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, g_Accent);
    if (ImGui::Button("X##close_cyber", ImVec2(closeSz, closeSz))) {
        [metalbiew showChange:NO];
    }
    ImGui::PopStyleColor(2);

    float navW = 114.f;
    float bodyY = wPos.y + headerH;
    float bodyH = wSize.y - headerH;

    dl->AddRectFilled(ImVec2(wPos.x, bodyY), ImVec2(wPos.x + navW, bodyY + bodyH), U32(g_BgPanel), 8.f, ImDrawFlags_RoundCornersBottomLeft);
    dl->AddLine(ImVec2(wPos.x + navW, bodyY), ImVec2(wPos.x + navW, bodyY + bodyH), U32(g_Border), 1.f);

    const char* navItems[] = {"Home", "ESP Radar", "Aimbot", "Memory", "Settings"};
    float navItemH = 30.f;
    for (int i = 0; i < 5; ++i) {
        float iy = bodyY + 8.f + i * (navItemH + 3.f);
        ImVec2 iMin(wPos.x + 6.f, iy);
        ImVec2 iMax(wPos.x + navW - 6.f, iy + navItemH);
        bool sel = (s.tab == i);
        bool hov = ImGui::IsMouseHoveringRect(iMin, iMax);

        if (sel) {
            dl->AddRectFilled(iMin, iMax, U32(RGBA(35, 15, 22, 1.f)), 5.f);
            dl->AddRectFilled(ImVec2(iMin.x, iy + 5.f), ImVec2(iMin.x + 3.f, iy + navItemH - 5.f), U32(g_Accent), 1.5f);
        } else if (hov) {
            dl->AddRectFilled(iMin, iMax, U32(g_BgHover), 5.f);
        }

        if (hov && ImGui::IsMouseClicked(0)) {
            s.tab = i;
        }

        float ty = iy + (navItemH - MenuLocale::measure(navItems[i]).y) * 0.5f;
        if (MenuLocale::rtl()) {
            MenuLocale::drawText(navItems[i], ImVec2(iMax.x - 10.f, ty), sel ? U32(g_TextMain) : U32(g_TextDim));
        } else {
            MenuLocale::drawText(navItems[i], ImVec2(iMin.x + 12.f, ty), sel ? U32(g_TextMain) : U32(g_TextDim));
        }
    }

    float contentX = wPos.x + navW + 10.f;
    float contentW = wSize.x - navW - 20.f;
    ImGui::SetCursorScreenPos(ImVec2(contentX, bodyY + 8.f));
    ImGui::BeginChild("##cyber_content", ImVec2(contentW, bodyH - 16.f), false, ImGuiWindowFlags_None);

    switch (s.tab) {
        case 0: DrawHomeTab(); break;
        case 1: DrawEspTab(); break;
        case 2: DrawAimTab(); break;
        case 3: DrawMemTab(); break;
        case 4: DrawSetTab(); break;
        default: DrawHomeTab(); break;
    }

    ImGui::EndChild();
    DrawToast();

    ImGui::End();
    ImGui::PopStyleVar(2);
    ImGui::PopStyleColor(2);
}

}

void RenderMenu() {
    MenuLocale::beginFrame();
    if (!MenDeal) return;

    if (!IsLogin) {
        if (DarkosLicenseAuth::IsAuthenticated()) {
            IsLogin = true;
        } else {
            DarkosLicenseAuth::RenderLoginWindow(&IsLogin);
            return;
        }
    }

    CyberMenu::RenderWindow();
}
