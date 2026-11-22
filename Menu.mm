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
#include "LicenseAuth.h"
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

namespace Settings {
    extern int Tab;
    extern bool isVisibilityCheck;
    namespace SettingsTab {
        extern bool BypassMode;
    }
    namespace Aimbot {
        extern bool Tick;
        extern int AimMethod;
        extern std::atomic<int> TriggerMode;
        extern bool MemoryAimbot;
        extern bool SilentAim;
        namespace SilentAimSettings {
            extern bool AimKnocked;
            extern bool Highprecisiontracking;
            extern int Aimpositon;
            extern bool Prediction;
            extern bool EnableFov;
            extern bool BypassFOVLimit;
            extern bool AimingLine;
            extern float MaxStepDeg;
            extern int LegitTrackSwitchrate;
        }
    }
}

namespace imgui {
    extern bool ESP;
    extern bool Boxes;
    extern bool HideBot;
    extern bool Health;
    extern bool Line;
    extern bool Name;
    extern bool TeamID;
    extern bool Distance;
    extern bool EnemyCount;
    extern bool Weapon;
    extern bool Bone;
    extern bool GameInfo;
    extern bool Alert360;
    extern bool EnemyAiming;
    extern bool Items;
    extern bool Lootbox;
    extern bool Vehicle;
}

 
extern void ResetGuestAccount();

extern ImFont* mainFont;

// HMOOD__TG@i_8_f


bool MenDeal;
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
        TextImage result;
        @autoreleasepool {
            NSString* string = [NSString stringWithUTF8String:value ? value : ""];
            UIFont* font = [UIFont fontWithName:@"Helvetica-Bold" size:points * .5f];
            if (!font) font = [UIFont boldSystemFontOfSize:points * .5f];
            NSMutableParagraphStyle* paragraph = [NSMutableParagraphStyle new];
            paragraph.baseWritingDirection = rtl() ? NSWritingDirectionRightToLeft : NSWritingDirectionNatural;
            paragraph.alignment = NSTextAlignmentNatural;
            paragraph.lineBreakMode = NSLineBreakByWordWrapping;
            NSAttributedString* text = [[NSAttributedString alloc] initWithString:string ?: @""
                attributes:@{NSFontAttributeName: font, NSForegroundColorAttributeName: UIColor.whiteColor,
                             NSParagraphStyleAttributeName: paragraph}];
            const NSStringDrawingOptions options = NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading;
            CGRect bounds = [text boundingRectWithSize:CGSizeMake(wrapPoints > 0 ? wrapPoints : 4096.f, CGFLOAT_MAX)
                                               options:options context:nil];
            result.content = ImVec2(fmaxf(1.f, ceilf(bounds.size.width)), fmaxf(1.f, ceilf(bounds.size.height)));
            CGSize size = CGSizeMake(result.content.x + result.padding * 2.f, result.content.y + result.padding * 2.f);
            UIGraphicsImageRendererFormat* format = [UIGraphicsImageRendererFormat defaultFormat];
            format.scale = 2.f;
            format.opaque = NO;
            UIGraphicsImageRenderer* renderer = [[UIGraphicsImageRenderer alloc] initWithSize:size format:format];
            const float padding = result.padding;
            const CGFloat contentWidth = result.content.x, contentHeight = result.content.y;
            UIImage* bitmap = renderer ? [renderer imageWithActions:^(UIGraphicsImageRendererContext* context) {
                (void)context;
                [text drawWithRect:CGRectMake(padding - bounds.origin.x, padding - bounds.origin.y,
                                             contentWidth, contentHeight)
                           options:options context:nil];
            }] : nil;
            CGImageRef source = bitmap.CGImage;
            static id<MTLDevice> device = MTLCreateSystemDefaultDevice();
            if (source && device) {
                const size_t width = CGImageGetWidth(source), height = CGImageGetHeight(source);
                if (width > 0 && height > 0 && width <= 8192 && height <= 8192) {
                    std::vector<uint8_t> rgba(width * height * 4, 0);
                    CGColorSpaceRef space = CGColorSpaceCreateWithName(kCGColorSpaceSRGB);
                    CGContextRef context = space ? CGBitmapContextCreate(rgba.data(), width, height, 8, width * 4,
                        space, kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big) : nullptr;
                    if (context) {
                        CGContextDrawImage(context, CGRectMake(0, 0, width, height), source);
                        CGContextFlush(context);
                        for (size_t i = 0; i < width * height; ++i)
                            rgba[i * 4] = rgba[i * 4 + 1] = rgba[i * 4 + 2] = 255;
                        MTLTextureDescriptor* descriptor = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatRGBA8Unorm
                            width:width height:height mipmapped:NO];
                        descriptor.usage = MTLTextureUsageShaderRead;
                        descriptor.storageMode = MTLStorageModeShared;
                        result.texture = [device newTextureWithDescriptor:descriptor];
                        if (result.texture) {
                            [result.texture replaceRegion:MTLRegionMake2D(0, 0, width, height) mipmapLevel:0
                                                 withBytes:rgba.data() bytesPerRow:width * 4];
                        }
                        CGContextRelease(context);
                    }
                    if (space) CGColorSpaceRelease(space);
                }
            }
        }
        return cache.emplace(cacheKey, std::move(result)).first->second;
    }
    static ImVec2 measure(const char* value, float fontSize, float wrap = 0.f) {
        const char* label = tr(value);
        if (!native(label)) {
            ImFont* f = SafeMenuFont();
            return f ? f->CalcTextSizeA(fontSize, FLT_MAX, wrap, label) : ImVec2(0.f, 0.f);
        }
        return image(label, fontSize, wrap).content;
    }
    static void draw(ImDrawList* list, const char* value, ImVec2 position, float fontSize, ImU32 color,
                      float maxWidth = 0.f, bool rightAlign = false, float wrap = 0.f) {
        if (!list) return;
        const char* label = tr(value);
        if (!native(label)) {
            ImFont* f = SafeMenuFont();
            if (!f) return;
            const float width = measure(label, fontSize).x;
            if (maxWidth > 0.f && width > maxWidth && width > 0.f) fontSize *= maxWidth / width;
            list->AddText(f, fontSize, position, color, label);
            return;
        }
        const TextImage& text = image(label, fontSize, wrap);
        if (!text.texture) return;
        const float factor = (maxWidth > 0.f && text.content.x > maxWidth && text.content.x > 0.f) ? maxWidth / text.content.x : 1.f;
        if (rightAlign && maxWidth > 0.f) position.x += maxWidth - text.content.x * factor;
        const float padding = text.padding * factor;
        list->AddImage((__bridge ImTextureID)text.texture,
            ImVec2(position.x - padding, position.y - padding),
            ImVec2(position.x + text.content.x * factor + padding, position.y + text.content.y * factor + padding),
            ImVec2(0, 0), ImVec2(1, 1), color);
    }
    static void text(const char* value, float wrap = 0.f) {
        const char* label = tr(value);
        if (!native(label)) { ImGui::TextUnformatted(label); return; }
        const float fs = ImGui::GetFontSize();
        const ImVec2 size = measure(value, fs, wrap), position = ImGui::GetCursorScreenPos();
        ImGui::Dummy(size);
        draw(ImGui::GetWindowDrawList(), value, position, fs, ImGui::GetColorU32(ImGuiCol_Text), wrap,
             rtl(), wrap);
    }
    static void tooltip(const char* value) {
        if (!native(tr(value))) { ImGui::SetTooltip("%s", tr(value)); return; }
        ImGui::BeginTooltip();
        text(value, ImMin(360.f, ImGui::GetIO().DisplaySize.x * .75f));
        ImGui::EndTooltip();
    }
    static bool selectable(const char* value, bool selected) {
        const char* label = tr(value);
        if (!native(label)) return ImGui::Selectable(label, selected);
        const ImVec2 position = ImGui::GetCursorScreenPos();
        const float fs = ImGui::GetFontSize(), height = ImGui::GetFrameHeight() * 1.2f;
        const float width = ImMax(190.f, measure(value, fs).x + 20.f);
        const std::string id = "##locale_select_" + std::string(value ? value : "");
        const bool pressed = ImGui::Selectable(id.c_str(), selected, 0, ImVec2(width, height));
        draw(ImGui::GetWindowDrawList(), value, ImVec2(position.x + 5.f, position.y + (height - measure(value, fs).y) * .5f),
             fs, ImGui::GetColorU32(ImGuiCol_Text), width - 10.f, rtl());
        return pressed;
    }
    static void widgetLabel(const char* value) {
        const float width = ImGui::GetFontSize() * 12.f;
        const ImVec2 position = ImGui::GetCursorScreenPos();
        ImGui::Dummy(ImVec2(width, ImGui::GetFrameHeight()));
        draw(ImGui::GetWindowDrawList(), value, ImVec2(position.x, position.y + ImGui::GetStyle().FramePadding.y),
             ImGui::GetFontSize(), ImGui::GetColorU32(ImGuiCol_Text), width, rtl());
    }
    static bool checkbox(const char* value, bool* state) {
        if (!state) return false;
        if (!native(tr(value))) return ImGui::Checkbox(value, state);
        ImGui::PushID(value);
        ImGui::BeginGroup();
        bool changed = ImGui::Checkbox("##check", state);
        ImGui::SameLine();
        const float width = ImMax(160.f, measure(value, ImGui::GetFontSize()).x);
        const ImVec2 position = ImGui::GetCursorScreenPos();
        if (ImGui::InvisibleButton("##label", ImVec2(width, ImGui::GetFrameHeight()))) {
            *state = !*state;
            changed = true;
        }
        draw(ImGui::GetWindowDrawList(), value, ImVec2(position.x, position.y + ImGui::GetStyle().FramePadding.y),
             ImGui::GetFontSize(), ImGui::GetColorU32(ImGuiCol_Text), width, rtl());
        ImGui::EndGroup();
        ImGui::PopID();
        return changed;
    }
    static bool sliderFloat(const char* label, float* value, float low, float high, const char* format = "%.3f") {
        if (!value) return false;
        if (!native(tr(label))) return ImGui::SliderFloat(label, value, low, high, format);
        ImGui::PushID(label);
        ImGui::BeginGroup();
        ImGui::SetNextItemWidth(ImGui::GetFontSize() * 14.f);
        const bool changed = ImGui::SliderFloat("##value", value, low, high, format);
        ImGui::SameLine();
        widgetLabel(label);
        ImGui::EndGroup();
        ImGui::PopID();
        return changed;
    }
    static bool sliderInt(const char* label, int* value, int low, int high) {
        if (!value) return false;
        if (!native(tr(label))) return ImGui::SliderInt(label, value, low, high);
        ImGui::PushID(label);
        ImGui::BeginGroup();
        ImGui::SetNextItemWidth(ImGui::GetFontSize() * 14.f);
        const bool changed = ImGui::SliderInt("##value", value, low, high);
        ImGui::SameLine();
        widgetLabel(label);
        ImGui::EndGroup();
        ImGui::PopID();
        return changed;
    }
    static bool colorEdit(const char* label, float* value) {
        if (!value) return false;
        if (!native(tr(label))) return ImGui::ColorEdit4(label, value);
        ImGui::PushID(label);
        ImGui::BeginGroup();
        if (ImGui::ColorButton("##color", ImVec4(value[0], value[1], value[2], value[3]),
                                ImGuiColorEditFlags_NoTooltip, ImVec2(52.f, ImGui::GetFrameHeight())))
            ImGui::OpenPopup("##colors");
        ImGui::SameLine();
        widgetLabel(label);
        bool changed = false;
        if (ImGui::BeginPopup("##colors")) {
            const char* components[] = {"Red", "Green", "Blue", "Opacity"};
            for (int i = 0; i < 4; ++i)
                changed = sliderFloat(components[i], &value[i], 0.f, 1.f, "%.2f") || changed;
            ImGui::EndPopup();
        }
        ImGui::EndGroup();
        ImGui::PopID();
        return changed;
    }
    static bool combo(const char* label, int* value, const char* const* choices, int count) {
        if (!value || !choices || count <= 0) return false;
        if (language == 0) return ImGui::Combo(label, value, choices, count);
        ImGui::PushID(label);
        ImGui::BeginGroup();
        const ImVec2 position = ImGui::GetCursorScreenPos();
        const float width = ImGui::GetFontSize() * 14.f;
        ImDrawList* owner = ImGui::GetWindowDrawList();
        ImGui::SetNextItemWidth(width);
        const bool open = ImGui::BeginCombo("##choice", "");
        draw(owner, choices[ImClamp(*value, 0, count - 1)],
             ImVec2(position.x + 5.f, position.y + ImGui::GetStyle().FramePadding.y), ImGui::GetFontSize(),
             ImGui::GetColorU32(ImGuiCol_Text), width - ImGui::GetFrameHeight() - 10.f, rtl());
        bool changed = false;
        if (open) {
            for (int i = 0; i < count; ++i)
                if (selectable(choices[i], *value == i)) { *value = i; changed = true; }
            ImGui::EndCombo();
        }
        ImGui::SameLine();
        widgetLabel(label);
        ImGui::EndGroup();
        ImGui::PopID();
        return changed;
    }
    static bool button(const char* label, ImVec2 size) {
        if (!native(tr(label))) return ImGui::Button(label, size);
        const ImVec2 position = ImGui::GetCursorScreenPos();
        const std::string id = "##locale_button_" + std::string(label ? label : "");
        const bool pressed = ImGui::Button(id.c_str(), size);
        const ImVec2 textSize = measure(label, ImGui::GetFontSize());
        const float factor = (textSize.x > size.x - 12.f && textSize.x > 0.f) ? (size.x - 12.f) / textSize.x : 1.f;
        draw(ImGui::GetWindowDrawList(), label,
             ImVec2(position.x + (size.x - textSize.x * factor) * .5f,
                    position.y + (size.y - textSize.y * factor) * .5f),
             ImGui::GetFontSize(), ImGui::GetColorU32(ImGuiCol_Text), size.x - 12.f);
        return pressed;
    }
}

// HMOOD__TG@i_8_f
void SetMenuLanguage(int language) { MenuLocale::language = language < 0 ? 0 : language > 6 ? 6 : language; }
int GetMenuLanguage() { return MenuLocale::language; }
const char* TranslateMenuText(const char* value) { return MenuLocale::tr(value); }


namespace CyberMenu {
// HMOOD__TG@i_8_f


    static const ImU32 Red = IM_COL32(195, 12, 41, 255);
    static const ImU32 White = IM_COL32(203, 204, 209, 255);
    static const ImU32 Muted = IM_COL32(112, 120, 130, 255);
    static const ImU32 Cyan = IM_COL32(17, 178, 201, 255);
    static const ImU32 Green = IM_COL32(37, 216, 125, 255);

    struct Canvas {
        ImDrawList* dl;
        ImVec2 origin;
        float scale;
        float stretchX = 1.f;
        float stretchY = 1.f;
        float switchReveal = 1.f;
        double animationTime = 0.0;
        ImVec2 p(float x, float y) const {
            return {origin.x + x * scale * stretchX, origin.y + y * scale * stretchY};
        }
        ImVec2 size(float w, float h) const {
            return {w * scale * stretchX, h * scale * stretchY};
        }
        void rect(float x, float y, float w, float h, ImU32 color, float radius = 0.f) const {
            if (!dl) return;
            dl->AddRectFilled(p(x, y), p(x + w, y + h), color, radius * scale);
        }
        void line(float x, float y, float xx, float yy, ImU32 color, float width = 1.f) const {
            if (!dl) return;
            dl->AddLine(p(x, y), p(xx, yy), color, width * scale);
        }
        void text(float x, float y, const char* label, float height = 20.f, ImU32 color = White,
                  float maxWidth = 0.f) const {
            if (!dl || !label) return;
            float fs = height * scale;
            if (MenuLocale::native(MenuLocale::tr(label))) {
                MenuLocale::draw(dl, label, p(x, y), fs, color,
                                  maxWidth > 0.f ? maxWidth * scale * stretchX : 0.f, MenuLocale::rtl());
                return;
            }
            ImFont* font = SafeMenuFont();
            if (!font) return;
            if (maxWidth > 0.f) {
                float width = font->CalcTextSizeA(fs, FLT_MAX, 0.f, label).x;
                if (width > maxWidth * scale * stretchX && width > 0.f)
                    fs *= maxWidth * scale * stretchX / width;
            }
            dl->AddText(font, fs, p(x, y), color, label);
        }
    };

// HMOOD__TG@i_8_f


     
     
    struct PageMotion {
        int page = -1;
        bool shown = false;
        bool opening = false;
        double started = 0.0;
        double lastFrame = 0.0;
        float age = 0.f;

        void update(int selected) {
            const double now =
                std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();
            if (!shown || selected != page) {
                opening = !shown;
                page = selected;
                started = now;
            }
            age = ImMax(0.f, (float)(now - started));
            shown = true;
            lastFrame = now;
        }

        float offset() const {
            if (opening && page == 0)
                return 0.f;
             
             
            static const float residual[] = {1.f,   .707f,  .467f,  .280f,  .147f,  .080f,
                                             .013f, -.013f, -.013f, -.013f, -.013f, 0.f};
            const int last = (int)(sizeof(residual) / sizeof(residual[0])) - 1;
            const float sample = age * 60.f;
            if (sample >= last)
                return 0.f;
            const int index = (int)sample;
            const float t = sample - index;
            return -88.f * (residual[index] + (residual[index + 1] - residual[index]) * t);
        }

        float opacity() const {
            if (page != 0 && page != 4)
                return 1.f;
            const float t = ImClamp(age / .20f, 0.f, 1.f);
            const float fade = 1.f - (1.f - t) * (1.f - t);
            return opening && page == 0 ? .72f + .28f * fade : fade;
        }

        float switches() const {
            return age >= .08f ? 1.f : 1.f - std::exp(-age * 80.f);
        }
    };

    static void fadeContent(ImDrawList* draw, int first, float opacity) {
        if (!draw || opacity >= 1.f)
            return;
        const int clampedFirst = ImClamp(first, 0, draw->VtxBuffer.Size);
        for (int i = clampedFirst; i < draw->VtxBuffer.Size; ++i) {
            ImU32& color = draw->VtxBuffer[i].col;
            const ImU32 alpha = (color & IM_COL32_A_MASK) >> IM_COL32_A_SHIFT;
            color = (color & ~IM_COL32_A_MASK) | ((ImU32)(alpha * opacity + .5f) << IM_COL32_A_SHIFT);
        }
    }

// HMOOD__TG@i_8_f


    struct Reference {
        id<MTLTexture> texture;
        float w, h, x, y;
    };

     
     
     
    static Reference& artwork(int index) {
        static Reference textures[3] = {};
        static bool attempted[3] = {};
        if (index < 0 || index >= 3) return textures[0];
        Reference& result = textures[index];
        if (attempted[index])
            return result;
        attempted[index] = true;
        @autoreleasepool {
            const char* bytes[] = {kCyberDetailedFrame, kCyberDetailedBrand, kCyberDetailedBrand};
            const CGRect crops[] = {CGRectMake(8, 8, 1528, 978), CGRectMake(60, 156, 2060, 403), CGRectMake(0, 0, 448, 448)};
            if (!bytes[index]) return result;
            NSString* encoded = [[NSString alloc] initWithUTF8String:bytes[index]];
            NSData* data = [[NSData alloc] initWithBase64EncodedString:encoded options:0];
            UIImage* decoded = index == 2 ? GetMenuBadgeImage() : (data ? [UIImage imageWithData:data] : nil);
            CGImageRef image =
                decoded.CGImage ? CGImageCreateWithImageInRect(decoded.CGImage, crops[index]) : nullptr;
            id<MTLDevice> device = MTLCreateSystemDefaultDevice();
            if (!image || !device) {
                if (image)
                    CGImageRelease(image);
                return result;
            }
            const size_t width = CGImageGetWidth(image), height = CGImageGetHeight(image);
            if (width == 0 || height == 0 || width > 8192 || height > 8192) {
                CGImageRelease(image);
                return result;
            }
            std::vector<uint8_t> rgba(width * height * 4, 0);
            CGColorSpaceRef space = CGColorSpaceCreateWithName(kCGColorSpaceSRGB);
            CGContextRef context =
                space ? CGBitmapContextCreate(rgba.data(), width, height, 8, width * 4, space,
                                              kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big)
                      : nullptr;
            if (context) {
                CGContextDrawImage(context, CGRectMake(0, 0, width, height), image);
                CGContextFlush(context);
                for (size_t i = 0; i < width * height; ++i) {
                    uint8_t* pixel = rgba.data() + i * 4;
                    const unsigned alpha = pixel[3];
                    if (alpha < 4) {
                        pixel[0] = pixel[1] = pixel[2] = pixel[3] = 0;
                        continue;
                    }
                    for (int k = 0; k < 3; ++k)
                        pixel[k] = (uint8_t)ImMin(255u, (pixel[k] * 255u + alpha / 2u) / alpha);
                }
                MTLTextureDescriptor* descriptor =
                    [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatRGBA8Unorm
                                                                       width:width
                                                                      height:height
                                                                   mipmapped:NO];
                descriptor.usage = MTLTextureUsageShaderRead;
                descriptor.storageMode = MTLStorageModeShared;
                result.texture = [device newTextureWithDescriptor:descriptor];
                if (result.texture)
                    [result.texture replaceRegion:MTLRegionMake2D(0, 0, width, height)
                                      mipmapLevel:0
                                        withBytes:rgba.data()
                                      bytesPerRow:width * 4];
                result.w = (float)width;
                result.h = (float)height;
                CGContextRelease(context);
            }
            if (space)
                CGColorSpaceRelease(space);
            CGImageRelease(image);
        }
        return result;
    }

    static Reference& highQualityFrame() {
        return artwork(0);
    }

     
     
    static Reference& navigationTexture(int tab, bool selected) {
        static Reference faces[5][2] = {};
        static bool attempted[5][2] = {};
        if (tab < 0 || tab >= 5) return faces[0][0];
        const int state = selected ? 1 : 0;
        Reference& face = faces[tab][state];
        if (attempted[tab][state])
            return face;
        attempted[tab][state] = true;
        @autoreleasepool {
            if (!kCyberNavigation9230) return face;
            NSString* encoded = [[NSString alloc] initWithUTF8String:kCyberNavigation9230];
            NSData* data = [[NSData alloc] initWithBase64EncodedString:encoded options:0];
            UIImage* source = data ? [UIImage imageWithData:data] : nil;
            const CGRect crop = CGRectMake(49, 20 + tab * 150, 295, 139);
            CGImageRef own = source.CGImage ? CGImageCreateWithImageInRect(source.CGImage, crop) : nullptr;
            id<MTLDevice> device = MTLCreateSystemDefaultDevice();
            if (!own || !device) {
                if (own)
                    CGImageRelease(own);
                return face;
            }
            const size_t width = CGImageGetWidth(own), height = CGImageGetHeight(own);
            if (width == 0 || height == 0 || width > 8192 || height > 8192) {
                CGImageRelease(own);
                return face;
            }
            MTKTextureLoader* loader = [[MTKTextureLoader alloc] initWithDevice:device];
            NSDictionary* options = @{
                MTKTextureLoaderOptionSRGB : @NO,
                MTKTextureLoaderOptionOrigin : MTKTextureLoaderOriginTopLeft,
                MTKTextureLoaderOptionTextureUsage : @(MTLTextureUsageShaderRead)
            };
            face.w = (float)width;
            face.h = (float)height;
            const bool nativeState = (tab == 3) == selected;
            if (nativeState)
                face.texture = [loader newTextureWithCGImage:own options:options error:nil];
            else {
                CGColorSpaceRef space = CGColorSpaceCreateWithName(kCGColorSpaceSRGB);
                auto pixels = [&](CGImageRef image, std::vector<uint8_t>& buffer) -> bool {
                    buffer.assign(width * height * 4, 0);
                    CGContextRef context =
                        space
                            ? CGBitmapContextCreate(buffer.data(), width, height, 8, width * 4, space,
                                                    kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big)
                            : nullptr;
                    if (!context)
                        return false;
                    CGContextDrawImage(context, CGRectMake(0, 0, width, height), image);
                    CGContextFlush(context);
                    CGContextRelease(context);
                    return true;
                };
                 
                 
                CGImageRef plate = CGImageCreateWithImageInRect(
                    source.CGImage, CGRectMake(49, selected ? 470 : 20, 295, 139));
                std::vector<uint8_t> foreground, composed;
                if (plate && pixels(own, foreground) && pixels(plate, composed)) {
                    for (size_t y = 0; y < height; ++y)
                        for (size_t x = 0; x < width; ++x) {
                            const bool body = x >= 23 && x < 270 && y >= 33 && y < 109;
                            const bool tallIcon = x >= 23 && x < 106 && y >= 28 && y < 109;
                            if (!body && !tallIcon)
                                continue;
                            const size_t offset = (y * width + x) * 4;
                            uint8_t* pixel = composed.data() + offset;
                            for (int k = 0; k < 4; ++k)
                                pixel[k] = foreground[offset + k];
                            if (!selected) {
                                 
                                 
                                if (pixel[1] > pixel[0] + 6 || pixel[2] > pixel[0] + 6) {
                                    const uint8_t neutral =
                                        (uint8_t)(pixel[0] * .30f + pixel[1] * .52f + pixel[2] * .18f);
                                    pixel[0] = pixel[1] = pixel[2] = neutral;
                                }
                            } else if (ImMax(pixel[0], ImMax(pixel[1], pixel[2])) > 110) {
                                pixel[0] = (uint8_t)(pixel[0] * .95f);
                                pixel[2] = (uint8_t)(pixel[2] * .96f);
                            }
                        }
                    CGContextRef context =
                        CGBitmapContextCreate(composed.data(), width, height, 8, width * 4, space,
                                              kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big);
                    CGImageRef result = context ? CGBitmapContextCreateImage(context) : nullptr;
                    if (result) {
                        face.texture = [loader newTextureWithCGImage:result options:options error:nil];
                        CGImageRelease(result);
                    }
                    if (context)
                        CGContextRelease(context);
                }
                if (plate)
                    CGImageRelease(plate);
                if (space)
                    CGColorSpaceRelease(space);
            }
            CGImageRelease(own);
        }
        return face;
    }

// HMOOD__TG@i_8_f


    static bool hit(const Canvas& c, const char* id, float x, float y, float w, float h,
                    bool available = true, const char* reason = nullptr) {
        if (!id) return false;
        ImGui::SetCursorScreenPos(c.p(x, y));
        ImGui::BeginDisabled(!available);
        bool clicked = ImGui::InvisibleButton(id, c.size(w, h));
        bool hovered = ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled);
        ImGui::EndDisabled();
        if (hovered && reason)
            MenuLocale::tooltip(reason);
        return clicked;
    }

     
     
     
    enum IconKind {
        Player = 0,
        Target,
        List,
        Box,
        Warning,
        Group,
        Ruler,
        Bolt,
        NameCard,
        Question,
        Information,
        Health,
        Compass,
        Bone,
        Robot,
        Shield,
        Loot,
        Items,
        Car,
        Wand,
        Flame,
        Skull,
        Fov,
        Gauge,
        Percent,
        PaperPlane,
        Headset,
        Link,
        Cloud,
        Eye,
        Gear,
        Globe,
        Reset,
        Gamepad,
        Phone,
        Calendar,
        Check,
        Database,
        MemoryChip
    };

    static void icon(const Canvas& c, int kind, float x, float y, float size, ImU32 color = Red) {
        if (!c.dl || kind < 0)
            return;
        static const char* const symbols[] = {ICON_FA_USER,
                                              ICON_FA_CROSSHAIRS,
                                              ICON_FA_LIST,
                                              ICON_FA_VECTOR_SQUARE,
                                              ICON_FA_EXCLAMATION_TRIANGLE,
                                              ICON_FA_USERS,
                                              ICON_FA_RULER,
                                              ICON_FA_BOLT,
                                              ICON_FA_ADDRESS_CARD,
                                              ICON_FA_QUESTION,
                                              ICON_FA_INFO_CIRCLE,
                                              ICON_FA_HEARTBEAT,
                                              ICON_FA_COMPASS,
                                              ICON_FA_BONE,
                                              ICON_FA_ROBOT,
                                              ICON_FA_SHIELD_ALT,
                                              ICON_FA_BOX_OPEN,
                                              ICON_FA_BOXES,
                                              ICON_FA_CAR,
                                              ICON_FA_MAGIC,
                                              ICON_FA_FIRE,
                                              ICON_FA_SKULL,
                                              ICON_FA_EXPAND,
                                              ICON_FA_TACHOMETER_ALT,
                                              ICON_FA_PERCENT,
                                              ICON_FA_PAPER_PLANE,
                                              ICON_FA_HEADSET,
                                              ICON_FA_LINK,
                                              ICON_FA_CLOUD,
                                              ICON_FA_EYE,
                                              ICON_FA_COG,
                                              ICON_FA_GLOBE,
                                              ICON_FA_SYNC_ALT,
                                              ICON_FA_GAMEPAD,
                                              ICON_FA_MOBILE_ALT,
                                              ICON_FA_CALENDAR_ALT,
                                              ICON_FA_CHECK_CIRCLE,
                                              ICON_FA_DATABASE,
                                              ICON_FA_MEMORY};
        if (kind >= IM_ARRAYSIZE(symbols) || !symbols[kind])
            return;
        const unsigned char* utf8 = (const unsigned char*)symbols[kind];
        const ImWchar code = (ImWchar)(((utf8[0] & 15) << 12) | ((utf8[1] & 63) << 6) | (utf8[2] & 63));
        ImFont* font = SafeMenuFont();
        if (!font) return;
        const ImFontGlyph* glyph = font->FindGlyphNoFallback(code);
        if (!glyph) {
             
            c.dl->AddCircle(c.p(x + size * .5f, y + size * .5f), size * .36f * c.scale, color, 24,
                            1.8f * c.scale);
            return;
        }
        const float width = glyph->X1 - glyph->X0, height = glyph->Y1 - glyph->Y0;
        if (width <= 0 || height <= 0)
            return;
        const float fit = ImMin(size * c.scale * c.stretchX / width, size * c.scale * c.stretchY / height);
        const ImVec2 origin = c.p(x, y);
        const ImVec2 position = {
            origin.x + (size * c.scale * c.stretchX - width * fit) * .5f - glyph->X0 * fit,
            origin.y + (size * c.scale * c.stretchY - height * fit) * .5f - glyph->Y0 * fit};
        c.dl->AddText(font, font->FontSize * fit, position, color, symbols[kind]);
    }

// HMOOD__TG@i_8_f


    static void panel(const Canvas& c, float x, float y, float w, float h, ImU32 accent = Red) {
        if (!c.dl) return;
        c.dl->AddRectFilledMultiColor(c.p(x, y), c.p(x + w, y + h), IM_COL32(16, 8, 13, 255),
                                      IM_COL32(12, 8, 12, 255), IM_COL32(8, 9, 12, 255),
                                      IM_COL32(8, 9, 12, 255));
        c.dl->AddRect(c.p(x, y), c.p(x + w, y + h), IM_COL32(59, 13, 28, 210), 4 * c.scale, 0,
                      1.1f * c.scale);
        c.dl->AddRect(c.p(x + 2, y + 2), c.p(x + w - 2, y + h - 2), IM_COL32(37, 16, 24, 110), 3 * c.scale, 0,
                      .6f * c.scale);
        (void)accent;
    }

    static void heading(const Canvas& c, const char* title, float x, float y, float w, int glyph = Target) {
        panel(c, x, y, w, 29);
        c.rect(x + 1, y + 3, 3, 23, Red, 1);
        icon(c, glyph, x + 12, y + 6, 16, White);
        c.text(x + 38, y + 4, title, 19, White, w - 48);
    }

// HMOOD__TG@i_8_f


     
     
    struct FeatureNotice {
        std::string label;
        int glyph;
        bool enabled;
        double started;
        float y = -1.f;
    };
    static std::vector<FeatureNotice>& notices() {
        static std::vector<FeatureNotice> items;
        return items;
    }
    static void notifyFeature(const char* label, int glyph, bool enabled) {
        if (!ImGui::GetCurrentContext()) return;
        auto& items = notices();
        if (items.size() >= 8)
            items.erase(items.begin());
        items.push_back({label ? label : "", glyph, enabled, ImGui::GetTime(), -1.f});
    }
    static bool featureCheckbox(const char* label, bool* value, int glyph) {
        if (!value) return false;
        const bool changed = MenuLocale::checkbox(label, value);
        if (changed)
            notifyFeature(label, glyph, *value);
        return changed;
    }
    static void renderNotices() {
        if (!ImGui::GetCurrentContext()) return;
        auto& items = notices();
        const double now = ImGui::GetTime();
        for (auto i = items.begin(); i != items.end();) {
            if (now - i->started >= 2.25)
                i = items.erase(i);
            else
                ++i;
        }
        if (items.empty())
            return;
        const ImGuiIO& io = ImGui::GetIO();
        if (io.DisplaySize.x < 1.f || io.DisplaySize.y < 1.f)
            return;
        const float scale = ImClamp(io.DisplaySize.y / 592.f, .55f, 1.4f);
        const float width = ImMin(265.f * scale, io.DisplaySize.x - 24.f * scale);
        const float height = 44.f * scale, spacing = 8.f * scale;
        const float top =
            ImMin((items.back().glyph == Globe ? 40.f : 62.f) * scale, ImMax(8.f * scale, io.DisplaySize.y - 4 * (height + spacing) - 8.f * scale));
        ImFont* activeFont = cyberMenuFont ? cyberMenuFont : SafeMenuFont();
        if (activeFont) ImGui::PushFont(activeFont);
        ImDrawList* draw = ImGui::GetForegroundDrawList();
        if (!draw) {
            if (activeFont) ImGui::PopFont();
            return;
        }
        draw->PushClipRect(ImVec2(0, 0), io.DisplaySize, true);
        for (size_t i = 0; i < items.size() && i < 4; ++i) {
            FeatureNotice& n = items[i];
            const float age = (float)(now - n.started);
            const float enter = ImClamp(age / .28f, 0.f, 1.f);
            const float fade = 1.f - ImClamp((age - 1.95f) / .30f, 0.f, 1.f);
            const float remaining = 1.f - enter;
            const float offset = (width + 24.f * scale) * remaining * remaining * remaining;
            const float desired = top + i * (height + spacing);
            if (n.y < 0)
                n.y = desired;
            n.y += (desired - n.y) * (1.f - std::exp(-ImMin(io.DeltaTime, .1f) * 20.f));
            const float x = io.DisplaySize.x - 20.f * scale - width + offset;
            Canvas c{draw, ImVec2(x, n.y), scale};
            const float w = width / scale;
            const int first = draw->VtxBuffer.Size;
            const ImU32 accent = n.enabled ? IM_COL32(0, 238, 155, 255) : IM_COL32(233, 21, 57, 255);
            c.rect(-1, 1, w + 2, 45, IM_COL32(0, 0, 0, 45), 7);
            c.rect(0, 0, w, 44, n.enabled ? IM_COL32(3, 19, 15, 235) : IM_COL32(25, 5, 10, 235), 6);
            draw->AddRect(c.p(0, 0), c.p(w, 44),
                          n.enabled ? IM_COL32(9, 156, 110, 225) : IM_COL32(144, 16, 40, 225), 6 * scale, 0,
                          1.3f * scale);
            c.rect(3, 5, 5, 34, n.enabled ? IM_COL32(0, 226, 136, 45) : IM_COL32(255, 12, 52, 45), 2);
            c.rect(4, 5, 3, 34, accent, 1.5f);
            icon(c, n.glyph, 16, 7, 16, accent);
            c.text(40, 6, n.label.c_str(), 14, IM_COL32(234, 238, 239, 255), w - 50);
            c.text(40, 24, n.enabled ? "ENABLED" : "DISABLED", 11.5f, accent, w - 50);
            fadeContent(draw, first, fade);
        }
        draw->PopClipRect();
        if (activeFont) ImGui::PopFont();
    }

// HMOOD__TG@i_8_f


    struct SwitchMotion {
        float value = 0.f;
        float from = 0.f;
        bool target = false;
        double started = 0.;
        int frame = -2;
    };

    static float switchPosition(ImGuiID key, bool enabled, double now) {
        static std::unordered_map<ImGuiID, SwitchMotion> motions;
        SwitchMotion& motion = motions[key];
        const int frame = ImGui::GetFrameCount();
        if (motion.frame < frame - 1) {
            motion.value = motion.from = enabled ? 1.f : 0.f;
            motion.target = enabled;
            motion.started = now - .14;
        }
        const float elapsed = ImClamp((float)((now - motion.started) / .14), 0.f, 1.f);
        const float eased = 1.f - (1.f - elapsed) * (1.f - elapsed) * (1.f - elapsed);
        motion.value = motion.from + ((motion.target ? 1.f : 0.f) - motion.from) * eased;
        if (enabled != motion.target) {
            motion.from = motion.value;
            motion.target = enabled;
            motion.started = now;
        }
        motion.frame = frame;
        return motion.value;
    }

    static bool toggle(const Canvas& c, const char* label, const char* id, bool* value, float x, float y,
                       float w, int glyph, bool available = true,
                       const char* reason = "Not available in the current project") {
        if (!c.dl || !value) return false;
        bool changed = hit(c, id, x, y, w, 36, available, available ? nullptr : reason);
        const bool pressed = available && ImGui::IsItemActive();
        const bool hovered = available && ImGui::IsItemHovered();
        if (changed) {
            *value = !*value;
            notifyFeature(label, glyph, *value);
        }
        ImU32 fg = available ? White : IM_COL32(106, 107, 113, 255);
        icon(c, glyph, x + 3, y + 6, 23, available ? Red : IM_COL32(104, 20, 38, 255));
        const float switchX = x + w - 52;
        c.text(x + 37, y + 4, label, 23, fg, w - 96);
        const ImGuiID key = ImGui::GetID(id ? id : label);
        const float position = switchPosition(key, *value, c.animationTime) * c.switchReveal;
        const float light = available ? position : 0.f;
        const float cy = y + 18.5f;
        for (int layer = 4; layer >= 1; --layer) {
            const float spread = layer * 1.05f;
            c.rect(switchX - spread, y + 5 - spread, 49 + spread * 2, 27 + spread * 2,
                   IM_COL32(255, 0, 43, (int)((5 - layer) * 4.f * light)), 13.5f + spread);
        }
         
         
        const ImU32 track =
            IM_COL32((int)(35 + 214 * light), (int)(37 * (1.f - light)), (int)(44 - 2 * light), 255);
        c.rect(switchX, y + 5, 49, 27, track, 13.5f);
        const float pressRim = pressed ? 118.f : (hovered ? 74.f : 0.f);
        const float rimAlpha = ImMax(55.f * light, pressRim);
        if (rimAlpha > 0.f) {
            c.dl->AddRect(c.p(switchX - .8f, y + 4.2f), c.p(switchX + 49.8f, y + 32.8f),
                          IM_COL32(227, 23, 52, (int)(rimAlpha * .30f)), 14.3f * c.scale, 0, 2.3f * c.scale);
            c.dl->AddRect(c.p(switchX + .4f, y + 5.4f), c.p(switchX + 48.6f, y + 31.6f),
                          IM_COL32(242, 32, 61, (int)rimAlpha), 13 * c.scale, 0, .9f * c.scale);
        }
        const float knobX = switchX + 12 + 25 * position;
        c.dl->AddCircleFilled(c.p(knobX, cy + .7f), 11.2f * c.scale, IM_COL32(0, 0, 0, 65), 32);
        c.dl->AddCircleFilled(c.p(knobX, cy), 12.7f * c.scale, IM_COL32(255, 220, 226, (int)(45 * light)),
                              32);
        c.dl->AddCircleFilled(c.p(knobX, cy), 11.2f * c.scale, IM_COL32(220, 222, 226, available ? 110 : 40),
                              32);
        c.dl->AddCircleFilled(c.p(knobX, cy), 10.2f * c.scale,
                              available ? IM_COL32(253, 253, 253, 255) : IM_COL32(133, 134, 137, 255), 32);
        return changed;
    }

    static bool slider(const Canvas& c, const char* id, const char* label, float* value, float low,
                       float high, float x, float y, float w, int glyph, bool available = true,
                       const char* disabledReason = "Not available, or controlled by the selected preset") {
        if (!c.dl || !value) return false;
        if (!std::isfinite(*value)) *value = low;
        const float span = high - low;
        const bool hasSpan = std::isfinite(span) && fabsf(span) > 1e-6f;
        panel(c, x, y, w, 37);
        icon(c, glyph, x + 10, y + 9, 19, available ? Red : IM_COL32(103, 23, 40, 255));
        c.text(x + 37, y + 9, label, glyph == Percent ? 12.5f : 17.f, available ? White : Muted, 77);
        const float tx = x + 124, tw = w - 142, cy = y + 19;
        float t = hasSpan ? ImClamp((*value - low) / span, 0.f, 1.f) : 0.f;
        const float knob = tx + tw * t;
        hit(c, id, tx - 8, y, tw + 16, 37, available,
            available ? nullptr : disabledReason);
        ImGuiID key = ImGui::GetID(id ? id : label);
        ImGuiStorage* storage = ImGui::GetStateStorage();
        if (ImGui::IsItemActivated() && storage) {
            float dx = ImGui::GetIO().MousePos.x - c.p(knob, cy).x;
            storage->SetFloat(key, std::fabs(dx) <= 14 * c.scale ? dx : 0.f);
        }
        if (available && ImGui::IsItemActive() && ImGui::GetIO().MouseDown[0] && hasSpan && storage) {
            const float denom = tw * c.scale * c.stretchX;
            float pos = fabsf(denom) > 1e-6f ? (ImGui::GetIO().MousePos.x - storage->GetFloat(key) - c.p(tx, cy).x) / denom : 0.f;
            float next = low + span * ImClamp(pos, 0.f, 1.f);
            if (std::isfinite(next) && next != *value) {
                *value = next;
                ImGui::MarkItemEdited(key);
            }
            t = ImClamp((*value - low) / span, 0.f, 1.f);
            char hint[256];
            snprintf(hint, sizeof(hint), "%s: %.1f", MenuLocale::tr(label), *value);
            MenuLocale::tooltip(hint);
        }
        bool committed = ImGui::IsItemDeactivatedAfterEdit();
        c.rect(tx, cy - 2.25f, tw, 4.5f, IM_COL32(41, 26, 33, 255), 3);
        c.rect(tx, cy - 2.25f, tw * t, 4.5f, available ? Red : IM_COL32(115, 23, 42, 255), 3);
        c.dl->AddCircleFilled(c.p(tx + tw * t, cy), 6.3f * c.scale, IM_COL32(237, 236, 239, 255), 20);
        c.dl->AddCircleFilled(c.p(tx + tw * t, cy), 3.2f * c.scale, Red, 16);
        return committed;
    }

    static bool combo(const Canvas& c, const char* id, int* current, const char* const* items, int count,
                      float x, float y, float w, float h = 32.f) {
        if (!c.dl || !current || !items || count <= 0 || !id) return false;
        c.rect(x, y, w, h, IM_COL32(18, 12, 18, 255), 3);
        c.dl->AddRect(c.p(x, y), c.p(x + w, y + h), IM_COL32(74, 23, 39, 255), 3 * c.scale, 0,
                      1.5f * c.scale);
        const int selected = ImClamp(*current, 0, count - 1);
        c.text(x + 11, y + 5, items[selected], 19, White, w - 42);
        c.dl->AddTriangleFilled(c.p(x + w - 23, y + h * .42f), c.p(x + w - 11, y + h * .42f),
                                c.p(x + w - 17, y + h * .65f), Red);
        if (hit(c, id, x, y, w, h))
            ImGui::OpenPopup(id);
        bool changed = false;
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8, 8));
        if (ImGui::BeginPopup(id)) {
            for (int i = 0; i < count; ++i)
                if (MenuLocale::selectable(items[i], *current == i)) {
                    *current = i;
                    changed = true;
                }
            ImGui::EndPopup();
        }
        ImGui::PopStyleVar();
        return changed;
    }

// HMOOD__TG@i_8_f


    static void frame(const Canvas& c) {
        if (!c.dl) return;
        c.rect(39, 30, 956, 597, IM_COL32(7, 8, 11, 255), 9);
        Reference& chrome = highQualityFrame();
        if (chrome.texture)
            c.dl->AddImage((__bridge ImTextureID)chrome.texture, c.p(0, 0), c.p(1024, 676));
        else {
            for (int i = 0; i < 5; ++i)
                c.dl->AddRect(c.p(8 + i * 5, 8 + i * 5), c.p(1016 - i * 5, 668 - i * 5),
                              i % 2 ? IM_COL32(77, 81, 89, 255) : Red, 16 * c.scale, 0, 5 * c.scale);
            c.line(44, 139, 991, 139, Red, 5);
            c.line(245, 145, 245, 612, Red, 5);
        }
        Reference& brand = artwork(1);
        if (brand.texture && brand.w > 0.f) {
            const float width = 610.f, height = width * brand.h / brand.w;
            c.dl->AddImage((__bridge ImTextureID)brand.texture, c.p(220, 27), c.p(220 + width, 27 + height),
                           {0, 0}, {1, 1}, IM_COL32(225, 227, 232, 255));
        } else {
            ImFont* f = SafeMenuFont();
            const float titleSize = 44.f;
            const float textWidth = f ? f->CalcTextSizeA(titleSize, FLT_MAX, 0, "HMOOD VIP").x : 0.f;
            c.text(540.f - textWidth * .5f, 60, "HMOOD VIP", titleSize, White);
        }
    }

    static bool closeButton(const Canvas& c) {
        if (!c.dl) return false;
        const bool clicked = hit(c, "##cyber_close", 899, 38, 44, 44, true, "Close menu");
        const bool hovered = ImGui::IsItemHovered();
        c.rect(906, 44, 30, 29, hovered ? IM_COL32(107, 6, 25, 245) : IM_COL32(55, 5, 15, 235), 3);
        c.dl->AddRect(c.p(906, 44), c.p(936, 73),
                      hovered ? IM_COL32(220, 16, 44, 230) : IM_COL32(148, 9, 32, 180), 3 * c.scale, 0,
                      .8f * c.scale);
        const ImU32 color = hovered ? IM_COL32(255, 57, 77, 255) : IM_COL32(239, 19, 46, 255);
        constexpr float pi = 3.14159265f;
        const float cx = 921.f, cy = 59.f, r = 7.8f, start = -pi * .5f + .68f, end = pi * 1.5f - .68f;
        c.dl->PathArcTo(c.p(cx, cy), r * c.scale, start, end, 28);
        c.dl->PathStroke(color, 0, 2.4f * c.scale);
        c.line(cx, cy - 9.6f, cx, cy - 1.4f, color, 2.5f);
        c.dl->AddCircleFilled(c.p(cx, cy - 9.6f), 1.25f * c.scale, color, 12);
        c.dl->AddCircleFilled(c.p(cx, cy - 1.4f), 1.25f * c.scale, color, 12);
        return clicked;
    }

    static void navigation(const Canvas& c, int& page) {
        if (!c.dl) return;
        if (!highQualityFrame().texture)
            c.rect(52, 151, 185, 453, IM_COL32(8, 10, 13, 255));
        const float dstY[] = {159, 247, 335, 423, 511};
        const char* ids[] = {"##cyber_home", "##cyber_visual", "##cyber_aim", "##cyber_memory",
                             "##cyber_settings"};
        const char* labels[] = {"HOME", "ESP RADAR", "AIMBOT", "Memory", "SETTINGS"};
         
        for (int i = 0; i < 5; ++i)
            if (hit(c, ids[i], 64, dstY[i], 166, 79))
                page = i;
        for (int i = 0; i < 5; ++i) {
            const bool selected = page == i;
            Reference& face = navigationTexture(i, selected);
            if (face.texture) {
                c.dl->AddImage((__bridge ImTextureID)face.texture, c.p(64, dstY[i]), c.p(230, dstY[i] + 79));
                if (MenuLocale::language != 0) {
                    const float left = 121.f, top = dstY[i] + 22.f, width = 101.f, height = 36.f;
                    c.rect(left, top, width, height,
                           selected ? IM_COL32(5, 17, 13, 255) : IM_COL32(11, 8, 12, 255), 2.f);
                    c.dl->PushClipRect(c.p(left, top), c.p(left + width, top + height), true);
                    for (int offset = -36; offset < 110; offset += 5)
                        c.line(left + offset, top + height, left + offset + height, top,
                               IM_COL32(48, 53, 54, 32), .7f);
                    c.dl->PopClipRect();
                    c.text(left + 4.f, top + 6.f, labels[i], 18.f, selected ? Green : White, width - 8.f);
                }
            } else {
                panel(c, 64, dstY[i], 166, 79, selected ? Green : Red);
                c.dl->AddRect(c.p(66, dstY[i] + 3), c.p(228, dstY[i] + 76),
                              selected ? IM_COL32(78, 99, 94, 255) : Red, 7 * c.scale, 0, 2 * c.scale);
                if (selected) {
                    c.rect(64, dstY[i] + 7, 3, 65, Cyan, 1);
                    c.rect(125, dstY[i] + 68, 42, 3, Green, 1);
                }
                c.text(80, dstY[i] + 26, labels[i], 22, selected ? Green : White, 142);
            }
        }
    }

// HMOOD__TG@i_8_f


    struct Stats {
        std::string device, ios, time, date;
        float fps = 0, appMB = -1, freeGB = -1, totalGB = 0, battery = -1;
    };
    static const Stats& stats() {
        static Stats st;
        static double last = -10;
        if (!ImGui::GetCurrentContext()) return st;
        if (ImGui::GetTime() - last < 1.0)
            return st;
        last = ImGui::GetTime();
        struct utsname si;
        memset(&si, 0, sizeof(si));
        uname(&si);
        st.device = si.machine[0] ? si.machine : "iPhone";
        NSString* sysVer = [UIDevice currentDevice].systemVersion;
        st.ios = sysVer ? sysVer.UTF8String : "";
        [UIDevice currentDevice].batteryMonitoringEnabled = YES;
        st.battery = [UIDevice currentDevice].batteryLevel;
        st.fps = ImGui::GetIO().Framerate;
        st.totalGB = (float)[NSProcessInfo processInfo].physicalMemory / (1024.f * 1024.f * 1024.f);
        mach_task_basic_info_data_t task = {};
        mach_msg_type_number_t count = MACH_TASK_BASIC_INFO_COUNT;
        if (task_info(mach_task_self(), MACH_TASK_BASIC_INFO, (task_info_t)&task, &count) == KERN_SUCCESS)
            st.appMB = task.resident_size / (1024.f * 1024.f);
        host_t host = mach_host_self();
        vm_statistics64_data_t vm = {};
        count = HOST_VM_INFO64_COUNT;
        vm_size_t page = 0;
        if (host_page_size(host, &page) == KERN_SUCCESS && page > 0 &&
            host_statistics64(host, HOST_VM_INFO64, (host_info64_t)&vm, &count) == KERN_SUCCESS)
            st.freeGB = (vm.free_count + vm.inactive_count) * (double)page / (1024. * 1024. * 1024.);
        mach_port_deallocate(mach_task_self(), host);
        static NSDateFormatter* tf = nil;
        static NSDateFormatter* df = nil;
        if (!tf) {
            tf = [NSDateFormatter new];
            tf.dateFormat = @"HH:mm";
            df = [NSDateFormatter new];
            df.dateFormat = @"yyyy/MM/dd";
        }
        NSDate* now = [NSDate date];
        NSString* tStr = now ? [tf stringFromDate:now] : nil;
        NSString* dStr = now ? [df stringFromDate:now] : nil;
        st.time = tStr ? tStr.UTF8String : "--:--";
        st.date = dStr ? dStr.UTF8String : "----/--/--";
        return st;
    }

// HMOOD__TG@i_8_f


    static const ImU32 HomeCyan = IM_COL32(27, 205, 223, 255);
    static const ImU32 HomeLabel = IM_COL32(141, 150, 159, 255);

     
    static ImVec2 rimPoint(float x, float y, float w, float h, float radius, float distance) {
        constexpr float pi = 3.14159265f;
        const float r = ImMax(0.001f, ImMin(radius, ImMin(w, h) * .5f));
        const float horizontal = ImMax(0.f, w - 2.f * r), vertical = ImMax(0.f, h - 2.f * r), arc = pi * r * .5f;
        const float perimeter = 2.f * (horizontal + vertical) + 4.f * arc;
        if (perimeter <= 1e-5f) return {x, y};
        float d = std::fmod(distance, perimeter);
        if (d < 0.f)
            d += perimeter;
        if (d <= horizontal)
            return {x + r + d, y};
        d -= horizontal;
        if (d <= arc) {
            const float a = -pi * .5f + d / r;
            return {x + w - r + std::cos(a) * r, y + r + std::sin(a) * r};
        }
        d -= arc;
        if (d <= vertical)
            return {x + w, y + r + d};
        d -= vertical;
        if (d <= arc) {
            const float a = d / r;
            return {x + w - r + std::cos(a) * r, y + h - r + std::sin(a) * r};
        }
        d -= arc;
        if (d <= horizontal)
            return {x + w - r - d, y + h};
        d -= horizontal;
        if (d <= arc) {
            const float a = pi * .5f + d / r;
            return {x + r + std::cos(a) * r, y + h - r + std::sin(a) * r};
        }
        d -= arc;
        if (d <= vertical)
            return {x, y + h - r - d};
        d -= vertical;
        const float a = pi + d / r;
        return {x + r + std::cos(a) * r, y + r + std::sin(a) * r};
    }

    static void movingRim(const Canvas& c, float x, float y, float w, float h, float radius, ImU32 tint) {
        if (!c.dl) return;
        constexpr float pi = 3.14159265f;
        const float r = ImMin(radius, ImMin(w, h) * .5f);
        const float perimeter = 2.f * (w + h - 4.f * r) + 2.f * pi * r;
        if (perimeter <= 1e-5f) return;
        const float phase = (float)std::fmod(c.animationTime * .32 + (x + y * .37f) * .003, 1.0);
        const float head = phase * perimeter;
        const float trail = ImMin(76.f, perimeter * .14f);
        const int red = (tint >> IM_COL32_R_SHIFT) & 255, green = (tint >> IM_COL32_G_SHIFT) & 255,
                  blue = (tint >> IM_COL32_B_SHIFT) & 255;
        for (int i = 0; i < 18; ++i) {
            const float t = (i + 1.f) / 18.f;
            const ImVec2 a = rimPoint(x, y, w, h, r, head - trail + i * trail / 18.f);
            const ImVec2 b = rimPoint(x, y, w, h, r, head - trail + (i + 1.f) * trail / 18.f);
            const float intensity = t * t;
            c.line(a.x, a.y, b.x, b.y, IM_COL32(red, green, blue, (int)(24 * intensity)), 3.5f);
            c.line(a.x, a.y, b.x, b.y, IM_COL32(red, green, blue, (int)(210 * intensity)), .9f);
        }
    }

     
     
    static void headerSweep(const Canvas& c, float age) {
        if (!c.dl || age < 0.f || age >= .17f)
            return;
        const float t = ImClamp(age / .20f, 0.f, 1.f);
        const float progress = 1.f - (1.f - t) * (1.f - t) * (1.f - t);
        const float x = 350.f + 614.f * progress, y = 125.5f;
        const float fade = age > .135f ? ImClamp((.17f - age) / .035f, 0.f, 1.f) : 1.f;
        const ImU32 clear = IM_COL32(10, 111, 255, 0);
        const ImU32 blue = IM_COL32(29, 142, 255, (int)(165 * fade));
        const ImU32 cyan = IM_COL32(99, 239, 255, (int)(230 * fade));
        c.dl->PushClipRect(c.p(305, 117), c.p(977, 135), true);
        c.dl->AddRectFilledMultiColor(c.p(x - 76, y - 2), c.p(x, y + 2), clear,
                                      IM_COL32(25, 151, 255, (int)(36 * fade)),
                                      IM_COL32(25, 151, 255, (int)(36 * fade)), clear);
        c.dl->AddRectFilledMultiColor(c.p(x - 72, y - .65f), c.p(x, y + .65f), clear, blue, blue, clear);
        c.dl->AddRectFilledMultiColor(c.p(x, y - .5f), c.p(x + 44, y + .5f), cyan, clear, clear, cyan);
        c.dl->AddCircleFilled(c.p(x, y), 4.f * c.scale, IM_COL32(27, 181, 255, (int)(22 * fade)), 16);
        c.dl->AddCircleFilled(c.p(x, y), 2.f * c.scale, cyan, 16);
        c.dl->AddCircleFilled(c.p(x, y), .85f * c.scale, IM_COL32(213, 255, 255, (int)(240 * fade)), 12);
        c.dl->PopClipRect();
    }

     
     
    static void homeText(const Canvas& c, float x, float y, const char* text, float nominalSize, ImU32 color,
                         float maxWidth = 0.f, float visibleCap = 0.f, bool centered = false) {
        if (!c.dl || !text) return;
        if (MenuLocale::native(MenuLocale::tr(text))) {
            const float fs = (visibleCap > 0.f ? visibleCap / .76f : nominalSize) * c.scale;
            ImVec2 position = c.p(x, y);
            const float room = maxWidth > 0.f ? maxWidth * c.scale * c.stretchX : 0.f;
            const ImVec2 measured = MenuLocale::measure(text, fs);
            if (centered) position.x -= (room > 0.f ? ImMin(measured.x, room) : measured.x) * .5f;
            MenuLocale::draw(c.dl, text, position, fs, color, room, MenuLocale::rtl() && !centered);
            return;
        }
        ImFont* font = cyberMenuFont ? cyberMenuFont : SafeMenuFont();
        if (!font) return;
        const ImFontGlyph* capital = font->FindGlyphNoFallback('H');
        if (!capital || capital->Y1 <= capital->Y0) {
            c.text(x, y, text, nominalSize, color, maxWidth);
            return;
        }
        const float cap = visibleCap > 0 ? visibleCap : nominalSize * .76f;
        const float ratio = cap * c.scale / (capital->Y1 - capital->Y0);
        const float fontSize = font->FontSize * ratio;
        const float naturalWidth = font->CalcTextSizeA(fontSize, FLT_MAX, 0, text).x;
        const float horizontal = (maxWidth > 0 && naturalWidth > 0)
                                     ? ImMin(1.f, maxWidth * c.scale * c.stretchX / naturalWidth)
                                     : 1.f;
        ImVec2 origin = c.p(x, y);
        if (centered)
            origin.x -= naturalWidth * horizontal * .5f;
        const float anchor = origin.x;
        origin.y += capital->Y0 * (nominalSize * c.scale / font->FontSize - ratio);
        const int first = c.dl->VtxBuffer.Size;
        c.dl->AddText(font, fontSize, origin, color, text);
        if (horizontal < 1.f)
            for (int i = first; i < c.dl->VtxBuffer.Size; ++i)
                c.dl->VtxBuffer[i].pos.x = anchor + (c.dl->VtxBuffer[i].pos.x - anchor) * horizontal;
    }

     
     
    static void homePanel(const Canvas& c, float x, float y, float w, float h) {
        if (!c.dl) return;
        const float r = 4.5f;
        c.rect(x, y, w, h, IM_COL32(10, 8, 12, 255), r);
        c.dl->AddRectFilledMultiColor(c.p(x + 3, y + 3), c.p(x + w - 3, y + h - 3), IM_COL32(18, 8, 13, 255),
                                      IM_COL32(15, 8, 12, 255), IM_COL32(8, 9, 11, 255),
                                      IM_COL32(8, 9, 11, 255));
        const float band = h > 120 ? 35.f : 20.f;
        c.dl->AddRectFilledMultiColor(c.p(x + 3, y + 3), c.p(x + w - 3, y + band), IM_COL32(30, 7, 13, 255),
                                      IM_COL32(23, 7, 12, 255), IM_COL32(13, 8, 12, 255),
                                      IM_COL32(17, 8, 12, 255));
        c.dl->AddRect(c.p(x - .8f, y - .8f), c.p(x + w + .8f, y + h + .8f), IM_COL32(4, 4, 6, 240),
                      (r + .8f) * c.scale, 0, 1.1f * c.scale);
        c.dl->AddRect(c.p(x, y), c.p(x + w, y + h), IM_COL32(65, 14, 29, 210), r * c.scale, 0,
                      .85f * c.scale);
        c.dl->AddRect(c.p(x + 1.5f, y + 1.5f), c.p(x + w - 1.5f, y + h - 1.5f), IM_COL32(23, 11, 17, 245),
                      (r - 1) * c.scale, 0, .75f * c.scale);
        c.dl->AddRect(c.p(x + 3, y + 3), c.p(x + w - 3, y + h - 3), IM_COL32(40, 11, 22, 120),
                      (r - 2) * c.scale, 0, .55f * c.scale);
         
        for (int pass = 0; pass < 2; ++pass) {
            const ImU32 color = pass ? IM_COL32(191, 16, 47, 180) : IM_COL32(177, 9, 41, 24);
            const float width = (pass ? .8f : 3.f) * c.scale;
            c.dl->AddBezierCubic(c.p(x + .6f, y + 18), c.p(x + .6f, y + 2), c.p(x + 2, y + .6f),
                                 c.p(x + 18, y + .6f), color, width, 12);
            c.dl->AddBezierCubic(c.p(x + .6f, y + h - 19), c.p(x + .6f, y + h - 2), c.p(x + 2, y + h - .6f),
                                 c.p(x + 19, y + h - .6f), color, width, 12);
            c.dl->AddBezierCubic(c.p(x + w - 17, y + h - .6f), c.p(x + w - 2, y + h - .6f),
                                 c.p(x + w - .6f, y + h - 2), c.p(x + w - .6f, y + h - 18), color, width, 12);
        }
        c.line(x + 13, y + .6f, x + w * .27f, y + .6f, IM_COL32(167, 24, 46, 190), .85f);
        c.line(x + w * .6f, y + .6f, x + w - 14, y + .6f, IM_COL32(66, 16, 29, 150), .7f);
        c.line(x + 16, y + h - .6f, x + w * .42f, y + h - .6f, IM_COL32(110, 16, 37, 180), .7f);
        c.line(x + 4, y + 19, x + 4, y + 31, IM_COL32(104, 14, 36, 125), .65f);
        movingRim(c, x, y, w, h, r, IM_COL32(231, 13, 52, 255));
    }

    static void homeAction(const Canvas& c, float x, float y, float w, float h) {
        if (!c.dl) return;
        const float r = 3.f;
        c.rect(x, y, w, h, IM_COL32(26, 8, 14, 255), r);
        c.dl->AddRectFilledMultiColor(c.p(x + 2, y + 2), c.p(x + w - 2, y + h - 2), IM_COL32(43, 9, 17, 255),
                                      IM_COL32(37, 8, 16, 255), IM_COL32(27, 8, 14, 255),
                                      IM_COL32(32, 9, 16, 255));
        c.dl->AddRect(c.p(x - .8f, y - .8f), c.p(x + w + .8f, y + h + .8f), IM_COL32(5, 5, 8, 230),
                      4 * c.scale, 0, 1 * c.scale);
        c.dl->AddRect(c.p(x, y), c.p(x + w, y + h), IM_COL32(80, 12, 29, 195), r * c.scale, 0,
                      .85f * c.scale);
        c.dl->AddRect(c.p(x + 1.5f, y + 1.5f), c.p(x + w - 1.5f, y + h - 1.5f), IM_COL32(119, 13, 36, 95),
                      1.8f * c.scale, 0, .65f * c.scale);
        c.line(x + 7, y + 2, x + w - 7, y + 2, IM_COL32(132, 16, 38, 90), .6f);
        c.line(x + 7, y + h - 1, x + w - 7, y + h - 1, IM_COL32(69, 10, 27, 155), .7f);
        c.line(x + 2, y + 6, x + 2, y + h - 6, IM_COL32(151, 13, 40, 105), .65f);
        movingRim(c, x, y, w, h, r, IM_COL32(220, 11, 48, 255));
    }

    static void statusTile(const Canvas& c, float x, float y, float w, const char* title, const char* value,
                           ImU32 accent, int glyph) {
        if (!c.dl) return;
        const bool status = glyph < 0, active = accent == Green;
        const float r = 4.f;
        const ImU32 rim = status ? IM_COL32(58, 164, 100, 225) : IM_COL32(17, 43, 59, 220);
        c.dl->AddRect(c.p(x - .5f, y - .5f), c.p(x + w + .5f, y + 39.5f),
                      status ? IM_COL32(25, 201, 113, 13) : IM_COL32(3, 87, 116, 9), (r + .5f) * c.scale, 0,
                      2 * c.scale);
        c.rect(x, y, w, 39, status ? IM_COL32(5, 25, 18, 255) : IM_COL32(6, 17, 26, 255), r);
        c.dl->AddRectFilledMultiColor(c.p(x + 2, y + 2), c.p(x + w - 2, y + 37),
                                      status ? IM_COL32(7, 30, 21, 255) : IM_COL32(8, 23, 32, 255),
                                      status ? IM_COL32(6, 26, 20, 255) : IM_COL32(7, 19, 28, 255),
                                      status ? IM_COL32(4, 20, 15, 255) : IM_COL32(5, 14, 22, 255),
                                      status ? IM_COL32(4, 23, 16, 255) : IM_COL32(5, 16, 24, 255));
        c.dl->AddRect(c.p(x, y), c.p(x + w, y + 39), rim, r * c.scale, 0, .85f * c.scale);
        c.dl->AddRect(c.p(x + 1.8f, y + 1.8f), c.p(x + w - 1.8f, y + 37.2f),
                      status ? IM_COL32(17, 69, 42, 170) : IM_COL32(9, 33, 47, 160), 2.5f * c.scale, 0,
                      .65f * c.scale);
        c.line(x + 6, y + 1, x + w * .4f, y + 1,
               status ? IM_COL32(83, 181, 117, 120) : IM_COL32(26, 64, 81, 105), .6f);
        c.line(x + w * .6f, y + 38, x + w - 6, y + 38,
               status ? IM_COL32(38, 131, 76, 130) : IM_COL32(14, 44, 60, 115), .6f);
        movingRim(c, x, y, w, 39, r, status ? IM_COL32(67, 217, 124, 255) : IM_COL32(23, 125, 159, 255));
        if (status) {
            if (active)
                c.dl->AddCircleFilled(c.p(x + 13, y + 20), 6 * c.scale, IM_COL32(23, 228, 126, 28), 24);
            c.dl->AddCircleFilled(c.p(x + 13, y + 20), 3.5f * c.scale, accent, 24);
        } else
            icon(c, glyph, x + 7.5f, y + 13, 13, glyph == Shield ? Green : glyph == Link ? HomeCyan : accent);
        homeText(c, x + 29, y + (status ? 4.f : 8.f), title, 9, HomeLabel, w - 35);
        const ImU32 valueColor = accent == Muted ? IM_COL32(159, 166, 173, 255)
                                 : accent == Cyan || accent == HomeCyan || accent == White
                                     ? IM_COL32(213, 216, 220, 255)
                                     : accent;
        homeText(c, x + 29, y + (status ? 19.f : 23.f), value, 11.8f, valueColor, w - 35, 8.5f);
    }

// HMOOD__TG@i_8_f


    static void openChannel() {
        dispatch_async(dispatch_get_main_queue(), ^{
            NSURL* url = [NSURL URLWithString:@"https://t.me/DylibSafe"];
            UIApplication* app = [UIApplication sharedApplication];
            if (url && app) {
                [app openURL:url options:@{} completionHandler:nil];
            }
        });
    }

    static void home(const Canvas& canvas) {
        if (!canvas.dl) return;
        Canvas c = canvas;
        c.origin = canvas.p(261, 158);
        c.scale = canvas.scale * (419.f / 373.f);
        c.stretchX = (699.f / 604.f) / (419.f / 373.f);
        c.stretchY = 1.f;
        const Stats& st = stats();
        char fps[32];
        snprintf(fps, sizeof(fps), "%.0f FPS", std::isfinite(st.fps) ? st.fps : 0.f);
        homePanel(c, 12, 15, 328, 219);
        homePanel(c, 355, 15, 240, 219);
         
        c.dl->AddRectFilledMultiColor(c.p(17, 22), c.p(335, 59), IM_COL32(23, 7, 13, 255),
                                      IM_COL32(25, 7, 14, 255), IM_COL32(31, 6, 14, 255),
                                      IM_COL32(28, 6, 13, 255));
        c.dl->AddRectFilledMultiColor(c.p(17, 59), c.p(335, 64), IM_COL32(28, 6, 13, 150),
                                      IM_COL32(31, 6, 14, 150), IM_COL32(12, 8, 12, 0),
                                      IM_COL32(12, 8, 12, 0));
        homeText(c, 28, 31, "HMOOD VIP", 17.5f, White, 274);
         
        c.dl->AddCircleFilled(c.p(308.5f, 39.5f), 9 * c.scale, IM_COL32(0, 235, 126, 14), 28);
        c.dl->AddCircleFilled(c.p(308.5f, 39.5f), 7.5f * c.scale, IM_COL32(0, 235, 126, 24), 28);
        icon(c, Check, 302, 33, 13, IM_COL32(0, 224, 119, 255));
         
         
        c.line(337.4f, 160, 337.4f, 224, IM_COL32(6, 5, 9, 235), 1.f);
        for (int pass = 0; pass < 3; ++pass) {
            const ImU32 edge = pass == 0   ? IM_COL32(226, 7, 44, 16)
                               : pass == 1 ? IM_COL32(216, 10, 43, 55)
                                           : IM_COL32(192, 16, 44, 210);
            const float width = pass == 0 ? 5.f : pass == 1 ? 2.6f : .85f;
            c.line(339.3f, 168, 339.3f, 225, edge, width);
            c.dl->AddBezierCubic(c.p(339.3f, 225), c.p(339.3f, 232), c.p(335.5f, 233.4f),
                                 c.p(328, 233.4f), edge, width * c.scale, 12);
        }
        c.line(23, 233.4f, 328, 233.4f, IM_COL32(72, 16, 30, 145), .7f);
         
        const float leftX[] = {29, 189}, rightX[] = {369, 487};
        const float tileW = 135, miniW = 98, row1 = 76, row2 = 123, row3 = 171;
        statusTile(c, leftX[0], row1, tileW, "SERVER", "LIVE", Green, -1);
        statusTile(c, leftX[1], row1, tileW, "EXPIRES", "UNAVAILABLE", Muted, -1);
        statusTile(c, leftX[0], row2, tileW, "SUBSCRIPTION", "UNAVAILABLE", Muted, Shield);
        statusTile(c, leftX[1], row2, tileW, "DEVICE LINK", "UNAVAILABLE", Muted, Link);
        statusTile(c, leftX[0], row3, tileW, "DEVICE", st.device.c_str(), HomeCyan, Phone);
        statusTile(c, leftX[1], row3, tileW, "KEY", "NOT CONFIGURED", Muted, Calendar);
         
        homeText(c, 370, 31, "CONTACT", 17.5f, White, 210);
        homeAction(c, 370, 76, 210, 44);
        icon(c, PaperPlane, 386, 87, 21, IM_COL32(25, 198, 224, 255));
        homeText(c, 424, 90, "TELEGRAM", 15, White, 145);
        homeAction(c, 370, 128, 210, 44);
        icon(c, Headset, 386, 139, 21, IM_COL32(236, 18, 52, 255));
        homeText(c, 424, 142, "SUPPORT", 15, White, 145);
        if (hit(c, "##cyber_telegram", 370, 76, 210, 44))
            openChannel();
        if (hit(c, "##cyber_support", 370, 128, 210, 44))
            openChannel();
        c.rect(370, 180, 210, 38, IM_COL32(10, 12, 16, 255), 3);
        c.dl->AddRect(c.p(370, 180), c.p(580, 218), IM_COL32(43, 15, 25, 200), 3 * c.scale, 0,
                      .8f * c.scale);
        c.dl->AddCircleFilled(c.p(387, 199), 6.5f * c.scale, IM_COL32(0, 235, 126, 16), 24);
        c.dl->AddCircleFilled(c.p(387, 199), 5 * c.scale, IM_COL32(0, 235, 126, 30), 24);
        c.dl->AddCircleFilled(c.p(387, 199), 3.3f * c.scale, Green, 20);
        homeText(c, 404, 192, "LIVE", 11.8f, IM_COL32(189, 193, 198, 255), 165, 8.5f);
         
        homePanel(c, 12, 249, 254, 111);
        homePanel(c, 281, 249, 314, 111);
        homeText(c, 27, 261, "GAME MODE", 15.5f, White, 224);
        homeText(c, 27, 290, "LOCAL MODE", 11.2f, IM_COL32(223, 225, 229, 255), 224, 8.2f);
        homeText(c, 27, 305, "NO LICENSE SERVICE", 10.5f, IM_COL32(162, 168, 175, 255), 224, 7.6f);
        homeAction(c, 27, 323, 134, 27);
        homeText(c, 94, 331, "OPEN MODE", 11.5f, IM_COL32(228, 230, 234, 255), 120, 8.2f, true);
        if (hit(c, "##cyber_open_mode", 27, 323, 134, 27, false,
                "No mode or licensing service is configured")) {
        }
        homeText(c, 296, 261, "RAM BOOSTER", 15.5f, White, 284);
        char app[32], free[32];
        snprintf(app, sizeof(app), st.appMB >= 0 ? "APP: %.0f MB" : "APP: --", st.appMB);
        snprintf(free, sizeof(free), st.freeGB >= 0 ? "FREE: %.1f GB" : "FREE: --", st.freeGB);
        homeText(c, 296, 290, app, 11.2f, IM_COL32(223, 225, 229, 255), 284, 8.2f);
        homeText(c, 296, 305, free, 10.5f, IM_COL32(162, 168, 175, 255), 284, 7.6f);
        homeAction(c, 296, 323, 92, 27);
        homeText(c, 342, 331, "PURGE", 11.5f, IM_COL32(228, 230, 234, 255), 80, 8.2f, true);
        if (hit(c, "##cyber_purge", 296, 323, 92, 27, false,
                "The current project has no memory purge operation")) {
        }
        homeAction(c, 396, 323, 146, 27);
        homeText(c, 469, 331, "AUTO-CLEAN: OFF", 11.5f, IM_COL32(228, 230, 234, 255), 134, 8.2f, true);
        if (hit(c, "##cyber_autoclean", 396, 323, 146, 27, false,
                "Automatic cleaning is not configured")) {
        }
         
        homePanel(c, 360, 15, 235, 219);
        homeText(c, 376, 30, "CONTACT", 17.5f, White, 203);
        homeAction(c, 376, 75, 203, 44);
        icon(c, PaperPlane, 392, 86, 21, IM_COL32(25, 198, 224, 255));
        homeText(c, 429, 89, "TELEGRAM", 15, White, 138);
        homeAction(c, 376, 127, 203, 44);
        icon(c, Headset, 392, 138, 21, IM_COL32(236, 18, 52, 255));
        homeText(c, 429, 141, "SUPPORT", 15, White, 138);
        if (hit(c, "##cyber_telegram_top", 376, 75, 203, 44))
            openChannel();
        if (hit(c, "##cyber_support_top", 376, 127, 203, 44))
            openChannel();
        c.rect(376, 179, 203, 38, IM_COL32(10, 12, 16, 255), 3);
        c.dl->AddRect(c.p(376, 179), c.p(579, 217), IM_COL32(43, 15, 25, 200), 3 * c.scale, 0,
                      .8f * c.scale);
        c.dl->AddCircleFilled(c.p(393, 198), 6.5f * c.scale, IM_COL32(0, 235, 126, 16), 24);
        c.dl->AddCircleFilled(c.p(393, 198), 5 * c.scale, IM_COL32(0, 235, 126, 30), 24);
        c.dl->AddCircleFilled(c.p(393, 198), 3.3f * c.scale, Green, 20);
        homeText(c, 410, 191, "LIVE", 11.8f, IM_COL32(189, 193, 198, 255), 158, 8.5f);
        homePanel(c, 360, 249, 235, 111);
        homeText(c, 376, 261, "PREFERENCES", 15.5f, White, 203);
        homeAction(c, 376, 290, 96, 27);
        homeText(c, 424, 298, hideHacker ? "STREAM: ON" : "STREAM: OFF", 11.5f,
                 IM_COL32(228, 230, 234, 255), 84, 8.2f, true);
        if (hit(c, "##cyber_stream", 376, 290, 96, 27)) {
            hideHacker = !hideHacker;
            notifyFeature("Stream", Eye, hideHacker);
        }
        homeAction(c, 480, 290, 99, 27);
        homeText(c, 529.5f, 298, MenuLocale::languageNames[MenuLocale::language], 11.5f,
                 IM_COL32(228, 230, 234, 255), 87, 8.2f, true);
        if (hit(c, "##cyber_language", 480, 290, 99, 27))
            ImGui::OpenPopup("##cyber_language_popup");
        if (ImGui::BeginPopup("##cyber_language_popup")) {
            for (int i = 0; i < 7; ++i)
                if (MenuLocale::selectable(MenuLocale::languageNames[i], MenuLocale::language == i))
                    MenuLocale::language = i;
            ImGui::EndPopup();
        }
        homeAction(c, 376, 323, 203, 27);
        homeText(c, 477.5f, 331, "RESET GUEST", 11.5f, IM_COL32(228, 230, 234, 255), 191, 8.2f, true);
        if (hit(c, "##cyber_reset_guest", 376, 323, 203, 27))
            ImGui::OpenPopup("##cyber_reset_guest_popup");
        ImGui::SetNextWindowPos(ImGui::GetIO().DisplaySize * .5f, ImGuiCond_Appearing, ImVec2(.5f, .5f));
        if (ImGui::BeginPopupModal("##cyber_reset_guest_popup", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
            MenuLocale::text("Reset guest account?");
            ImGui::Spacing();
            MenuLocale::text("This deletes local game data, settings and account data.");
            MenuLocale::text("The game will exit after the reset.");
            ImGui::Spacing();
            if (MenuLocale::button("Reset Guest", ImVec2(120, 30))) {
                ImGui::CloseCurrentPopup();
                ResetGuestAccount();
            }
            ImGui::SameLine();
            if (MenuLocale::button("Cancel", ImVec2(100, 30)))
                ImGui::CloseCurrentPopup();
            ImGui::EndPopup();
        }
        c.rect(346, 17, 13, 215, IM_COL32(10, 8, 12, 255));
        for (int pass = 0; pass < 3; ++pass) {
            const ImU32 edge = pass == 0   ? IM_COL32(226, 7, 44, 16)
                               : pass == 1 ? IM_COL32(216, 10, 43, 55)
                                           : IM_COL32(192, 16, 44, 210);
            const float width = pass == 0 ? 5.f : pass == 1 ? 2.6f : .85f;
            c.line(339.3f, 20, 339.3f, 225, edge, width);
            c.dl->AddBezierCubic(c.p(339.3f, 225), c.p(339.3f, 232), c.p(335.5f, 233.4f),
                                 c.p(328, 233.4f), edge, width * c.scale, 12);
        }
         
        statusTile(c, rightX[0], row1, miniW, "SERVER", "LIVE", Green, -1);
        statusTile(c, rightX[1], row1, miniW, "OS", st.ios.empty() ? "iOS" : st.ios.c_str(), White,
                   Gamepad);
        statusTile(c, rightX[0], row2, miniW, "FPS", fps, st.fps >= 55 ? Green : Cyan, Gauge);
        statusTile(c, rightX[1], row2, miniW, "RAM",
                   st.totalGB > 0 ? (std::to_string((int)std::round(st.totalGB)) + " GB").c_str() : "iOS",
                   Cyan, MemoryChip);
        statusTile(c, rightX[0], row3, miniW, "TIME", st.time.c_str(), White, Calendar);
        statusTile(c, rightX[1], row3, miniW, "DATE", st.date.c_str(), White, Calendar);
        c.rect(346, 17, 13, 215, IM_COL32(10, 8, 12, 255));
        for (int pass = 0; pass < 3; ++pass) {
            const ImU32 edge = pass == 0   ? IM_COL32(226, 7, 44, 16)
                               : pass == 1 ? IM_COL32(216, 10, 43, 55)
                                           : IM_COL32(192, 16, 44, 210);
            const float width = pass == 0 ? 5.f : pass == 1 ? 2.6f : .85f;
            c.line(339.3f, 20, 339.3f, 225, edge, width);
            c.dl->AddBezierCubic(c.p(339.3f, 225), c.p(339.3f, 232), c.p(335.5f, 233.4f),
                                 c.p(328, 233.4f), edge, width * c.scale, 12);
        }
    }

// HMOOD__TG@i_8_f


    static void visual(const Canvas& c) {
        if (!c.dl) return;
        panel(c, 12, 12, 232, 85);
        c.text(24, 18, "ESP Style", 19, White, 208);
        static const char* styles[] = {"Basic", "VIP Cyber Vertical"};
        combo(c, "##cyber_style", &IsStyle, styles, 2, 24, 46, 208, 36);
        panel(c, 12, 106, 232, 260);
        heading(c, "Player ESP", 20, 114, 216, Player);
        toggle(c, "Draw Names", "##cyber_name", &imgui::Name, 24, 151, 208, NameCard);
        toggle(c, "Draw Weapon", "##cyber_weapon", &imgui::Weapon, 24, 192, 208, Cross);
        toggle(c, "Game Info", "##cyber_gameinfo", &imgui::GameInfo, 24, 233, 208, Information);
        toggle(c, "Draw Distance", "##cyber_dist", &imgui::Distance, 24, 274, 208, Ruler);
        toggle(c, "Draw Health", "##cyber_hp", &imgui::Health, 24, 315, 208, Health);
        panel(c, 253, 12, 232, 354);
        toggle(c, "360 Alert", "##cyber_360", &imgui::Alert360, 265, 20, 208, Compass);
        toggle(c, "Snap Lines", "##cyber_line", &imgui::Line, 265, 61, 208, Box);
        toggle(c, "Draw Boxes", "##cyber_box", &imgui::Boxes, 265, 102, 208, Box);
        toggle(c, "Draw Bones", "##cyber_bone", &imgui::Bone, 265, 143, 208, Bone);
        toggle(c, "Hide Bots", "##cyber_bot", &imgui::HideBot, 265, 184, 208, Robot);
        toggle(c, "Enemy Count", "##cyber_ecount", &imgui::EnemyCount, 265, 225, 208, Group);
        toggle(c, "Player Team ID", "##cyber_tid", &imgui::TeamID, 265, 266, 208, Group);
        toggle(c, "Enemy Aiming", "##cyber_aiming", &imgui::EnemyAiming, 265, 307, 208, Warning);
        panel(c, 494, 12, 232, 146);
        toggle(c, "Lootbox", "##cyber_loot", &imgui::Lootbox, 506, 20, 208, Loot);
        toggle(c, "Items ESP", "##cyber_items", &imgui::Items, 506, 61, 208, Items);
        toggle(c, "Vehicle ESP", "##cyber_veh", &imgui::Vehicle, 506, 102, 208, Car);
        panel(c, 494, 167, 232, 199);
        heading(c, "Existing Display Settings", 502, 175, 216, Gear);
        c.text(508, 214, "Open additional existing display settings.", 15, Muted, 204);
        c.rect(508, 256, 204, 42, IM_COL32(28, 11, 18, 255), 4);
        c.dl->AddRect(c.p(508, 256), c.p(712, 298), Red, 4 * c.scale, 0, 1.3f * c.scale);
        c.text(552, 267, "ESP Radar", 20, White, 152);
        if (hit(c, "##cyber_esp_settings", 508, 256, 204, 42))
            ImGui::OpenPopup("##cyber_esp_settings_popup");
        if (ImGui::BeginPopup("##cyber_esp_settings_popup")) {
            MenuLocale::sliderFloat("ESP Distance", &ESPMaxDistance, 50.f, 600.f, "%.0f m");
            MenuLocale::sliderFloat("HP Scale", &globalHpAlphaF, .5f, 5.f, "%.2f");
            MenuLocale::sliderFloat("Alert Radius", &AlertRadius, 20.f, 240.f, "%.0f");
            MenuLocale::sliderFloat("Stroke Width", &strokeIntensity, .5f, 5.f, "%.2f");
            MenuLocale::checkbox("Text Border", &textBorder);
            MenuLocale::checkbox("Hide Name", &hideNameKillMsg);
            ImGui::ColorEdit4(MenuLocale::tr("Distance Color"), &COLOR_Distance);
            float borderColor[4] = {bgColor.Value.x, bgColor.Value.y, bgColor.Value.z, bgColor.Value.w};
            if (MenuLocale::colorEdit("Border Color", borderColor)) {
                bgColor.Value.x = borderColor[0];
                bgColor.Value.y = borderColor[1];
                bgColor.Value.z = borderColor[2];
                bgColor.Value.w = borderColor[3];
            }
            ImGui::EndPopup();
        }
    }

// HMOOD__TG@i_8_f


    static void aim(const Canvas& c) {
        if (!c.dl) return;
        panel(c, 12, 12, 232, 354);
        heading(c, "Aim Settings", 20, 20, 216, Gear);
        toggle(c, "Aimbot", "##cyber_aimbot", &Settings::Aimbot::Tick, 24, 57, 208, Target);
        const bool aimReady = Settings::Aimbot::Tick;
        const bool silentAllowed = aimReady && Settings::Aimbot::AimMethod != 0;
        if (!silentAllowed && Enable)
            Enable = false;
        toggle(c, "Silent Aim", "##cyber_silent", &Enable, 24, 98, 208, Wand, silentAllowed,
               "Enable Aimbot and select Risk or Custom to use Silent Aim");
        bool macro = false;
        toggle(c, "Macro", "##cyber_macro", &macro, 24, 139, 208, Flame);
        toggle(c, "Aim Line", "##cyber_aimline", &Settings::Aimbot::SilentAimSettings::AimingLine, 24, 180,
               208, Bolt);
        toggle(c, "Auto Fire", "##cyber_autofire", &自动开火, 24, 221, 208, Skull);
        toggle(c, "Visibility Check", "##cyber_vis", &Settings::isVisibilityCheck, 24, 262, 208, Eye);
        toggle(c, "Ignore Bots", "##cyber_ibots", &Settings::Aimbot::SilentAimSettings::Highprecisiontracking,
               24, 303, 208, Robot);
        panel(c, 253, 12, 232, 354);
        heading(c, "Aim Control", 261, 20, 216, Target);
        toggle(c, "Ignore Knocked", "##cyber_iknocked", &Settings::Aimbot::SilentAimSettings::AimKnocked,
               265, 57, 208, Skull);
        toggle(c, "Enable FOV", "##cyber_efov", &Settings::Aimbot::SilentAimSettings::EnableFov, 265, 98,
               208, Fov);
        c.text(265, 141, "Aim Target", 18, White, 208);
        static const char* targets[] = {"Head", "Neck", "Body", "Pelvis", "Auto"};
        combo(c, "##cyber_target", &Settings::Aimbot::SilentAimSettings::Aimpositon, targets, 5, 265, 165,
              208);
        c.text(265, 205, "Trigger Mode", 18, White, 208);
        static const char* triggers[] = {"Fire", "ADS", "Fire + ADS", "Fire or ADS"};
        int trigger = Settings::Aimbot::TriggerMode.load(std::memory_order_relaxed);
        if (combo(c, "##cyber_trigger", &trigger, triggers, 4, 265, 229, 208))
            Settings::Aimbot::TriggerMode.store(trigger, std::memory_order_relaxed);
        c.text(265, 269, "Aim Target", 18, White, 208);
        combo(c, "##cyber_target_2", &Settings::Aimbot::SilentAimSettings::Aimpositon, targets, 5, 265, 293,
              208);
        panel(c, 494, 12, 232, 354);
        slider(c, "##cyber_fov", "FOV", &Cross, 30, 300, 502, 20, 216, Fov, aimReady,
               "Enable Aimbot first");
        slider(c, "##cyber_dist", "Distance", &SilentAimMaxDistance, 50, 355, 502, 65, 216, Ruler, aimReady,
               "Enable Aimbot first");
        slider(c, "##cyber_speed", "Aim Speed", &AimSmooth, 2, 30, 502, 110, 216, Gauge,
               aimReady && !Enable,
               aimReady ? "Disable Silent Aim to adjust camera movement" : "Enable Aimbot first");
        slider(c, "##cyber_prob", "Hit Probability", &追踪概率, 0, 100, 502, 155, 216, Percent,
               aimReady && Enable,
               aimReady ? "Enable Silent Aim to adjust hit probability" : "Enable Aimbot first");
        panel(c, 502, 200, 216, 156);
        c.text(512, 208, "Mode", 19, White, 196);
        static const char* modes[] = {"Safe", "Risk", "Custom"};
        combo(c, "##cyber_mode", &Settings::Aimbot::AimMethod, modes, 3, 512, 234, 196);
        c.text(512, 274, "Open existing Safe / Risk / Custom modes and additional settings.", 13.5f, Muted,
               196);
        c.rect(512, 312, 196, 34, IM_COL32(28, 11, 18, 255), 4);
        c.dl->AddRect(c.p(512, 312), c.p(708, 346), Red, 4 * c.scale, 0, 1.3f * c.scale);
        c.text(534, 319, "Aim Settings", 18, White, 152);
        if (hit(c, "##cyber_aim_settings", 512, 312, 196, 34))
            ImGui::OpenPopup("##cyber_aim_settings_popup");
        if (ImGui::BeginPopup("##cyber_aim_settings_popup")) {
            MenuLocale::checkbox("Prediction", &Settings::Aimbot::SilentAimSettings::Prediction);
            MenuLocale::sliderFloat("Max Step", &Settings::Aimbot::SilentAimSettings::MaxStepDeg, .3f, 8.f,
                                    "%.2f deg");
            MenuLocale::sliderFloat("Magic X", &magicX, -50.f, 50.f, "%.1f");
            MenuLocale::sliderFloat("Magic Y", &magicY, -50.f, 50.f, "%.1f");
            MenuLocale::sliderFloat("Magic Z", &magicZ, -50.f, 50.f, "%.1f");
            ImGui::EndPopup();
        }
    }

// HMOOD__TG@i_8_f


    static void memory(const Canvas& c) {
        if (!c.dl) return;
        panel(c, 12, 12, 232, 354);
        bool autoTap = false;
        toggle(c, "Auto Tap", "##cyber_autotap", &autoTap, 24, 20, 208, Bolt);
        toggle(c, "Fast Shoot", "##cyber_fastshoot", &IsFastshoot, 24, 61, 208, Bolt);
        toggle(c, "Fast Scope", "##cyber_fastscope", &MemoryFastScope, 24, 102, 208, Target);
        toggle(c, "Fast Gun", "##cyber_fastgun", &IsFastSwitch, 24, 143, 208, Gear);
        toggle(c, "Spin", "##cyber_spin", &isSpinning, 24, 184, 208, Reset);
        toggle(c, "Zoom", "##cyber_zoom", &MemoryZoom, 24, 225, 208, Fov);
        toggle(c, "iPad", "##cyber_ipad", &WideView, 24, 266, 208, Globe);
        toggle(c, "No Recoil", "##cyber_recoil", &IsNorecoil2, 24, 307, 208, Shield);
        panel(c, 253, 12, 232, 354);
        toggle(c, "No Shake", "##cyber_shake", &IsNocamerashake, 265, 20, 208, Warning);
        toggle(c, "HitX", "##cyber_hitx", &HitX, 265, 61, 208, Flame);
        toggle(c, "Damage", "##cyber_damage", &MemoryDamage, 265, 102, 208, Skull);
        toggle(c, "Small Cross", "##cyber_smcross", &IsCrossHair, 265, 143, 208, Cross);
        toggle(c, "Rainbow", "##cyber_rainbow", &MemoryRainbow, 265, 184, 208, Wand);
        toggle(c, "Cross Spin", "##cyber_crossspin", &MemoryCrossSpin, 265, 225, 208, Reset);
        toggle(c, "Fast Drop", "##cyber_fastdrop", &IsFastDrop, 265, 266, 208, Bolt);
        toggle(c, "Super Run", "##cyber_superrun", &chaynhanhv2, 265, 307, 208, Flame);
        panel(c, 494, 12, 232, 354);
        slider(c, "##cyber_spinspeed", "Spin Speed", &tocdoquay, 0, 360, 502, 20, 216, Gauge);
        float wideFloat = (float)WideValue;
        if (slider(c, "##cyber_ipadview", "iPad View", &wideFloat, 80, 160, 502, 65, 216, Eye))
            WideValue = (int)std::round(wideFloat);
        slider(c, "##cyber_crosssize", "Cross Size", &crosshairSizeSlider, 0, 20, 502, 110, 216, Fov);
        panel(c, 502, 155, 216, 201);
        c.text(512, 165, "More memory options", 19, White, 196);
        c.text(512, 194,
               "Current view, crosshair, fast scope, damage and spin controls are active above.",
               14.5f, Muted, 196);
        c.text(512, 250, "Memory", 17.5f, White, 196);
        c.text(512, 274, "No extra memory sliders are included in this project.", 14.5f, Muted, 196);
    }

// HMOOD__TG@i_8_f


    static void settings(const Canvas& c) {
        if (!c.dl) return;
        panel(c, 12, 12, 354, 354);
        heading(c, "Preferences", 20, 20, 338, Gear);
        toggle(c, hideHacker ? "Stream: ON" : "Stream: OFF", "##cyber_set_stream", &hideHacker, 24, 59,
               330, Eye);
        c.text(24, 106, "Language", 19, White, 330);
        combo(c, "##cyber_set_lang", &MenuLocale::language, MenuLocale::languageNames, 7, 24, 132, 330);
        c.rect(24, 184, 330, 40, IM_COL32(28, 11, 18, 255), 4);
        c.dl->AddRect(c.p(24, 184), c.p(354, 224), Red, 4 * c.scale, 0, 1.3f * c.scale);
        c.text(126, 193, "Reset Guest", 20, White, 190);
        if (hit(c, "##cyber_set_reset", 24, 184, 330, 40))
            ImGui::OpenPopup("##cyber_set_reset_popup");
        ImGui::SetNextWindowPos(ImGui::GetIO().DisplaySize * .5f, ImGuiCond_Appearing, ImVec2(.5f, .5f));
        if (ImGui::BeginPopupModal("##cyber_set_reset_popup", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
            MenuLocale::text("Reset guest account?");
            ImGui::Spacing();
            MenuLocale::text("This deletes local game data, settings and account data.");
            MenuLocale::text("The game will exit after the reset.");
            ImGui::Spacing();
            if (MenuLocale::button("Reset Guest", ImVec2(120, 30))) {
                ImGui::CloseCurrentPopup();
                ResetGuestAccount();
            }
            ImGui::SameLine();
            if (MenuLocale::button("Cancel", ImVec2(100, 30)))
                ImGui::CloseCurrentPopup();
            ImGui::EndPopup();
        }
        panel(c, 375, 12, 351, 354);
        heading(c, "GAME INFO", 383, 20, 335, Information);
        const Stats& st = stats();
        char line[128];
        snprintf(line, sizeof(line), "DEVICE: %s", st.device.c_str());
        c.text(387, 62, line, 18, White, 327);
        snprintf(line, sizeof(line), "OS: iOS %s", st.ios.c_str());
        c.text(387, 90, line, 18, White, 327);
        snprintf(line, sizeof(line), "FPS: %.0f", st.fps);
        c.text(387, 118, line, 18, st.fps >= 55 ? Green : Cyan, 327);
        snprintf(line, sizeof(line), "APP RAM: %.0f MB", st.appMB);
        c.text(387, 146, line, 18, White, 327);
        snprintf(line, sizeof(line), "FREE RAM: %.1f GB", st.freeGB);
        c.text(387, 174, line, 18, White, 327);
        snprintf(line, sizeof(line), "TIME: %s", st.time.c_str());
        c.text(387, 202, line, 18, White, 327);
        snprintf(line, sizeof(line), "DATE: %s", st.date.c_str());
        c.text(387, 230, line, 18, White, 327);
    }

// HMOOD__TG@i_8_f


    static void render() {
        if (!MenDeal || !ImGui::GetCurrentContext())
            return;
        MenuLocale::beginFrame();
        ImFont* activeFont = cyberMenuFont ? cyberMenuFont : SafeMenuFont();
        if (activeFont) ImGui::PushFont(activeFont);
        const ImGuiIO& io = ImGui::GetIO();
        if (io.DisplaySize.x < 1.f || io.DisplaySize.y < 1.f) {
            if (activeFont) ImGui::PopFont();
            return;
        }
        static int page = 0;
        static PageMotion motion;
        const float scale = ImMin(io.DisplaySize.x / 1024.f, io.DisplaySize.y / 676.f);
        const ImVec2 winSize = {1024.f * scale, 676.f * scale};
        ImGui::SetNextWindowSize(winSize, ImGuiCond_Always);
        ImGui::SetNextWindowPos(ImVec2((io.DisplaySize.x - winSize.x) * .5f, (io.DisplaySize.y - winSize.y) * .5f),
                                ImGuiCond_FirstUseEver);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
        ImGui::PushStyleColor(ImGuiCol_WindowBg, IM_COL32(0, 0, 0, 0));
        if (ImGui::Begin("##cyber_menu", nullptr,
                         ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                             ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar |
                             ImGuiWindowFlags_NoScrollWithMouse)) {
            ImDrawList* dl = ImGui::GetWindowDrawList();
            if (dl) {
                Canvas c{dl, ImGui::GetWindowPos(), scale};
                c.animationTime =
                    std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();
                frame(c);
                if (closeButton(c)) {
                    [metalbiew showChange:NO];
                    ImGui::End();
                    ImGui::PopStyleColor();
                    ImGui::PopStyleVar(2);
                    if (activeFont) ImGui::PopFont();
                    return;
                }
                navigation(c, page);
                motion.update(page);
                headerSweep(c, motion.age);
                Canvas content = c;
                content.origin = c.p(251 + motion.offset(), 150);
                content.scale = c.scale * (419.f / 373.f);
                content.stretchX = (738.f / 604.f) / (419.f / 373.f);
                content.stretchY = 1.f;
                content.switchReveal = motion.switches();
                const int first = dl->VtxBuffer.Size;
                switch (page) {
                    case 0:
                        home(c);
                        break;
                    case 1:
                        visual(content);
                        break;
                    case 2:
                        aim(content);
                        break;
                    case 3:
                        memory(content);
                        break;
                    case 4:
                        settings(content);
                        break;
                }
                fadeContent(dl, first, motion.opacity());
                dl->AddRect(c.p(10, 10), c.p(1014, 666), IM_COL32(7, 8, 11, 255), 14 * c.scale, 0,
                            6 * c.scale);
            }
        }
        ImGui::End();
        ImGui::PopStyleColor();
        ImGui::PopStyleVar(2);
        if (activeFont) ImGui::PopFont();
    }

} // namespace CyberMenu

// HMOOD__TG@i_8_f


static void RenderLicenseGate() {
    if (!MenDeal || !ImGui::GetCurrentContext())
        return;

    MenuLocale::beginFrame();
    ImFont* activeFont = cyberMenuFont ? cyberMenuFont : SafeMenuFont();
    if (activeFont) ImGui::PushFont(activeFont);

    const ImGuiIO& io = ImGui::GetIO();
    if (io.DisplaySize.x < 1.f || io.DisplaySize.y < 1.f) {
        if (activeFont) ImGui::PopFont();
        return;
    }

    static char keyInputBuf[128] = {0};
    static bool keyLoaded = false;
    static std::string statusMessage = "";
    static bool statusError = false;
    static bool isVerifying = false;

    if (!keyLoaded) {
        keyLoaded = true;
        NSString* savedKey = [[NSUserDefaults standardUserDefaults] stringForKey:@"DarkosSavedLicenseKey"];
        if (savedKey.length > 0) {
            snprintf(keyInputBuf, sizeof(keyInputBuf), "%s", savedKey.UTF8String);
        }
    }

    const float scale = ImClamp(ImMin(io.DisplaySize.x / 520.f, io.DisplaySize.y / 320.f), 0.85f, 1.35f);
    const ImVec2 winSize = ImVec2(480.f * scale, 265.f * scale);

    ImGui::SetNextWindowSize(winSize, ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2((io.DisplaySize.x - winSize.x) * 0.5f,
                                   (io.DisplaySize.y - winSize.y) * 0.5f),
                           ImGuiCond_FirstUseEver);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 10.f * scale);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.2f * scale);
    ImGui::PushStyleColor(ImGuiCol_WindowBg, IM_COL32(10, 11, 16, 250));
    ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(195, 12, 41, 220));

    if (ImGui::Begin("##darkos_key_login", nullptr,
                     ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                         ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar)) {
        ImDrawList* dl = ImGui::GetWindowDrawList();
        const ImVec2 pos = ImGui::GetWindowPos();
        const ImVec2 size = ImGui::GetWindowSize();

        // Başlıq paneli
        dl->AddRectFilled(pos, ImVec2(pos.x + size.x, pos.y + 44.f * scale),
                          IM_COL32(22, 9, 15, 255), 10.f * scale, ImDrawCornerFlags_Top);
        dl->AddLine(ImVec2(pos.x, pos.y + 44.f * scale),
                    ImVec2(pos.x + size.x, pos.y + 44.f * scale),
                    IM_COL32(195, 12, 41, 180), 1.2f * scale);

        const float titleFontSize = 18.f * scale;
        dl->AddText(activeFont, titleFontSize,
                    ImVec2(pos.x + 18.f * scale, pos.y + 12.f * scale),
                    IM_COL32(245, 245, 248, 255), "KEY LOGIN");

        // Sağ yuxarı bağlama düyməsi
        const float closeSize = 26.f * scale;
        const ImVec2 closePos = ImVec2(pos.x + size.x - closeSize - 10.f * scale, pos.y + 9.f * scale);
        ImGui::SetCursorScreenPos(closePos);
        if (ImGui::InvisibleButton("##key_gate_close", ImVec2(closeSize, closeSize))) {
            [metalbiew showChange:NO];
        }
        const bool closeHovered = ImGui::IsItemHovered();
        dl->AddRectFilled(closePos, ImVec2(closePos.x + closeSize, closePos.y + closeSize),
                          closeHovered ? IM_COL32(195, 12, 41, 240) : IM_COL32(45, 12, 20, 220),
                          4.f * scale);
        dl->AddText(activeFont, 15.f * scale,
                    ImVec2(closePos.x + 8.f * scale, closePos.y + 5.f * scale),
                    IM_COL32(255, 255, 255, 255), "X");

        // Key daxiletmə yeri + Paste düyməsi
        const float padX = 18.f * scale;
        const float inputY = pos.y + 66.f * scale;
        const float inputH = 38.f * scale;
        const float pasteW = 84.f * scale;
        const float gap = 8.f * scale;
        const float inputW = size.x - padX * 2.f - pasteW - gap;

        dl->AddText(activeFont, 13.f * scale,
                    ImVec2(pos.x + padX, inputY - 18.f * scale),
                    IM_COL32(165, 170, 182, 255), "License Key");

        ImGui::SetCursorScreenPos(ImVec2(pos.x + padX, inputY));
        ImGui::PushStyleColor(ImGuiCol_FrameBg, IM_COL32(18, 20, 28, 255));
        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, IM_COL32(24, 27, 38, 255));
        ImGui::PushStyleColor(ImGuiCol_FrameBgActive, IM_COL32(28, 31, 44, 255));
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.f * scale);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10.f * scale, 9.f * scale));
        ImGui::SetNextItemWidth(inputW);
        ImGui::InputText("##darkos_key_field", keyInputBuf, sizeof(keyInputBuf));
        ImGui::PopStyleVar(2);
        ImGui::PopStyleColor(3);

        // Paste düyməsi
        const ImVec2 pastePos = ImVec2(pos.x + padX + inputW + gap, inputY);
        ImGui::SetCursorScreenPos(pastePos);
        if (ImGui::InvisibleButton("##darkos_paste_btn", ImVec2(pasteW, inputH))) {
            NSString* clip = [UIPasteboard generalPasteboard].string;
            if (clip.length > 0) {
                NSString* trimmed = [clip stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
                snprintf(keyInputBuf, sizeof(keyInputBuf), "%s", trimmed.UTF8String);
                statusMessage = "Key pasted from clipboard.";
                statusError = false;
            } else {
                statusMessage = "Clipboard is empty.";
                statusError = true;
            }
        }
        const bool pasteHovered = ImGui::IsItemHovered();
        dl->AddRectFilled(pastePos, ImVec2(pastePos.x + pasteW, pastePos.y + inputH),
                          pasteHovered ? IM_COL32(42, 47, 64, 255) : IM_COL32(26, 30, 42, 255),
                          5.f * scale);
        dl->AddRect(pastePos, ImVec2(pastePos.x + pasteW, pastePos.y + inputH),
                    IM_COL32(195, 12, 41, 160), 5.f * scale, 0, 1.f * scale);
        dl->AddText(activeFont, 14.f * scale,
                    ImVec2(pastePos.x + 22.f * scale, pastePos.y + 11.f * scale),
                    IM_COL32(235, 238, 245, 255), "Paste");

        // Login düyməsi (key yerinin altında)
        const float loginY = inputY + inputH + 14.f * scale;
        const float loginH = 40.f * scale;
        const float fullW = size.x - padX * 2.f;
        const ImVec2 loginPos = ImVec2(pos.x + padX, loginY);

        ImGui::SetCursorScreenPos(loginPos);
        ImGui::BeginDisabled(isVerifying);
        const bool loginClicked = ImGui::InvisibleButton("##darkos_login_btn", ImVec2(fullW, loginH));
        const bool loginHovered = ImGui::IsItemHovered();
        ImGui::EndDisabled();

        if (loginClicked && !isVerifying) {
            NSString* entered = [[NSString stringWithUTF8String:keyInputBuf]
                stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
            if (entered.length == 0) {
                statusMessage = "Please enter a license key.";
                statusError = true;
            } else {
                isVerifying = true;
                statusMessage = "Verifying key...";
                statusError = false;
                [[NSUserDefaults standardUserDefaults] setObject:entered forKey:@"DarkosSavedLicenseKey"];
                [[NSUserDefaults standardUserDefaults] synchronize];

                // DarkosLicenseAuth yoxlaması
                BOOL ok = [[DarkosLicenseAuth sharedManager] verifyLicenseKey:entered errorMessage:nil];
                if (!ok) {
                    // Fallback: DarkosLicenseAuth-da verifyLicenseKey yoxdursa və ya false qaytarırsa,
                    // yadda saxlanılan/aktiv tokeni yoxlayır
                    ok = [DarkosLicenseAuth sharedManager].isAuthenticated;
                }

                isVerifying = false;
                if (ok) {
                    IsLogin = true;
                    statusMessage = "Login successful!";
                    statusError = false;
                } else {
                    IsLogin = false;
                    statusMessage = "Invalid or expired key.";
                    statusError = true;
                }
            }
        }

        dl->AddRectFilled(loginPos, ImVec2(loginPos.x + fullW, loginPos.y + loginH),
                          isVerifying ? IM_COL32(110, 12, 28, 255)
                                      : (loginHovered ? IM_COL32(220, 18, 50, 255) : IM_COL32(195, 12, 41, 255)),
                          6.f * scale);
        dl->AddText(activeFont, 15.f * scale,
                    ImVec2(loginPos.x + fullW * 0.5f - 18.f * scale, loginPos.y + 12.f * scale),
                    IM_COL32(255, 255, 255, 255), isVerifying ? "..." : "Login");

        // Status mesajı
        if (!statusMessage.empty()) {
            dl->AddText(activeFont, 12.5f * scale,
                        ImVec2(pos.x + padX, loginY + loginH + 8.f * scale),
                        statusError ? IM_COL32(255, 72, 95, 255) : IM_COL32(37, 216, 125, 255),
                        statusMessage.c_str());
        }

        // Sol alt küncdə Buy Key düyməsi -> https://t.me/DylibSafe
        const float buyW = 104.f * scale;
        const float buyH = 30.f * scale;
        const ImVec2 buyPos = ImVec2(pos.x + padX, pos.y + size.y - buyH - 14.f * scale);
        ImGui::SetCursorScreenPos(buyPos);
        if (ImGui::InvisibleButton("##darkos_buy_key_btn", ImVec2(buyW, buyH))) {
            dispatch_async(dispatch_get_main_queue(), ^{
                NSURL* url = [NSURL URLWithString:@"https://t.me/DylibSafe"];
                UIApplication* app = [UIApplication sharedApplication];
                if (url && app) {
                    [app openURL:url options:@{} completionHandler:nil];
                }
            });
        }
        const bool buyHovered = ImGui::IsItemHovered();
        dl->AddRectFilled(buyPos, ImVec2(buyPos.x + buyW, buyPos.y + buyH),
                          buyHovered ? IM_COL32(24, 58, 76, 255) : IM_COL32(15, 34, 48, 255),
                          5.f * scale);
        dl->AddRect(buyPos, ImVec2(buyPos.x + buyW, buyPos.y + buyH),
                    IM_COL32(27, 205, 223, 210), 5.f * scale, 0, 1.f * scale);
        dl->AddText(activeFont, 13.5f * scale,
                    ImVec2(buyPos.x + 22.f * scale, buyPos.y + 8.f * scale),
                    IM_COL32(130, 238, 250, 255), "Buy Key");
    }

    ImGui::End();
    ImGui::PopStyleColor(2);
    ImGui::PopStyleVar(2);
    if (activeFont) ImGui::PopFont();
}

void RenderMenu() {
    if (!MenDeal || !ImGui::GetCurrentContext())
        return;

    if (!IsLogin) {
        RenderLicenseGate();
        return;
    }

    CyberMenu::render();
    CyberMenu::renderNotices();
}
