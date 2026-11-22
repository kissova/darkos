// HMOOD__TG@i_8_f

#import "Engine.h"
#include "menu.h"
#include "esp.h"
#import "mahoa.h"
#include "sys/mman.h"
#include "Tools.h"
#include <stdio.h>
#include <stdint.h>
#import <sys/utsname.h>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>
#include <sys/sysctl.h>
#include <signal.h>
#include <unistd.h>
#include <math.h>
#include <cmath>
#include <limits>
#include <chrono>
#include <tuple>
#include <map>
#include <mutex>
#include <atomic>
#include <dlfcn.h>
#include <stdlib.h>
#include <filesystem>
#import "HideFunsion.h"

#include <string.h>
#include "Vector3.hpp"
#include "Vector2.hpp"
#import <Foundation/Foundation.h>
#import "UE4.h"
#import "PubgLoad.h"
#include "imgui.h"
#import "HeeeNoScreenShotView.h"
#import "ini_rw.h"
#import <libkern/OSCacheControl.h>

#define ImClamp(X, MIN, MAX) ((X) < (MIN) ? (MIN) : ((X) > (MAX) ? (MAX) : (X)))
#define kWidth  [UIScreen mainScreen].bounds.size.width
#define kHeight [UIScreen mainScreen].bounds.size.height
#define timer(sec) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(sec * NSEC_PER_SEC)), dispatch_get_main_queue(), ^

#define ICON_FA_EXCLAMATION_TRIANGLE "\xef\x81\xb1"
#define E(str) _xor_(str).c_str()

#define iPhone8P ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

#define HMOOD_METALBIEW_IMPLEMENTATION
#include "ESP/Engine_2.h"
#undef HMOOD_METALBIEW_IMPLEMENTATION

typedef uintptr_t kaddr;
using namespace std;
using namespace SDK;

struct sRegion {
    uintptr_t start, end;
};
std::vector<sRegion> trapRegions;

static std::mutex g_HookMutex;
static std::once_flag g_InitOnceFlag;
static std::atomic<bool> g_RtlHooked{false};

// HMOOD__TG@i_8_f
bool isObjectInvalid(UObject *obj) {
    if (!Tools::IsPtrValid(obj)) {
        return true;
    }

    uintptr_t rawObj = (uintptr_t)obj;
    if ((rawObj % sizeof(uintptr_t)) != 0x0 && (rawObj % sizeof(uintptr_t)) != 0x4) {
        return true;
    }

    if (!Tools::IsPtrValid(obj->ClassPrivate)) {
        return true;
    }

    if (obj->InternalIndex <= 0) {
        return true;
    }

    if (obj->NamePrivate.ComparisonIndex <= 0) {
        return true;
    }

    if (std::any_of(trapRegions.begin(), trapRegions.end(), [obj](const sRegion& region) {
            return ((uintptr_t)obj) >= region.start && ((uintptr_t)obj) <= region.end;
        }) ||
        std::any_of(trapRegions.begin(), trapRegions.end(), [obj](const sRegion& region) {
            return ((uintptr_t)obj->ClassPrivate) >= region.start && ((uintptr_t)obj->ClassPrivate) <= region.end;
        })) {
        return true;
    }

    return false;
}

// HMOOD__TG@i_8_f
static bool SafeWriteVTableSlot(void **vtable, int index, void *newFunc, void **outOldFunc) {
    if (!vtable || index < 0 || !newFunc) return false;
    if (!Tools::IsPtrValid(vtable)) return false;

    void **slotPtr = &vtable[index];
    if (!Tools::IsPtrValid(slotPtr)) return false;

    void *currentVal = *slotPtr;
    if (!Tools::IsPtrValid(currentVal)) return false;

    if (currentVal == newFunc) {
        if (outOldFunc && !*outOldFunc) {
            *outOldFunc = currentVal;
        }
        return true;
    }

    long page_size = sysconf(_SC_PAGESIZE);
    if (page_size <= 0) page_size = 16384;
    uintptr_t start = ((uintptr_t)slotPtr) & ~((uintptr_t)page_size - 1);
    uintptr_t end = (((uintptr_t)slotPtr + sizeof(void *)) + (uintptr_t)page_size - 1) & ~((uintptr_t)page_size - 1);
    size_t len = end - start;

    if (mprotect((void *)start, len, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
        if (mprotect((void *)start, len, PROT_READ | PROT_WRITE) != 0) {
            return false;
        }
    }

    if (outOldFunc && !*outOldFunc) {
        *outOldFunc = currentVal;
    }
    *slotPtr = newFunc;
    sys_icache_invalidate((void *)slotPtr, sizeof(void *));
    return true;
}

// HMOOD__TG@i_8_f
static bool IsAimTriggerActive(const ASTExtraPlayerCharacter* player) {
    if (!Tools::IsPtrValid((void *)(uintptr_t)player)) return false;
    const bool fire = player->bIsWeaponFiring;
    const bool ads = player->bIsGunADS;
    switch (Settings::Aimbot::TriggerMode.load(std::memory_order_relaxed)) {
        case 0: return fire;
        case 1: return ads;
        case 2: return fire && ads;
        case 3: return fire || ads;
        default: return false;
    }
}

@implementation metalbiew
INI* config;

// HMOOD__TG@i_8_f
- (MTKView *)mtkView
{
    return (MTKView *)self.view;
}

// HMOOD__TG@i_8_f
- (void)loadView {
    self.view = [[MTKView alloc] initWithFrame:CGRectMake(0, 0, kWidth, kHeight)];
}

// HMOOD__TG@i_8_f
- (void)viewDidLoad {
    [super viewDidLoad];

    self.mtkView.device = self.device;
    self.mtkView.delegate = self;
    self.mtkView.clearColor = MTLClearColorMake(0, 0, 0, 0);
    self.mtkView.backgroundColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:0];
    self.mtkView.clipsToBounds = YES;
}

// HMOOD__TG@i_8_f
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    NSString *documentsDirectory = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSString *filePath = [documentsDirectory stringByAppendingPathComponent:@"IMGUI.ini"];

    if (![fileManager fileExistsAtPath:filePath]) {
        [fileManager createFileAtPath:filePath contents:[NSData data] attributes:nil];
    }

    config = ini_load((char*)filePath.UTF8String);
    _device = MTLCreateSystemDefaultDevice();
    _commandQueue = [_device newCommandQueue];
    if (!self.device || !_commandQueue) return self;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ApplyImGuiStyle();
    InitializeMenuFonts(io);
    ImGui_ImplMetal_Init(_device);

    return self;
}

static auto start = std::chrono::steady_clock::now();
static auto noww = std::chrono::high_resolution_clock::now();

namespace Settings
{
    int Tab = 0;
}

namespace Variables {
    int ActiveTab = 1;
}

// HMOOD__TG@i_8_f
- (void)drawInMTKView:(MTKView*)view
{
    if (!view || !self.commandQueue) return;

    [[HideFunsion sharedManager] addView:view
                         isStreaming:hideHacker
                             MenDeal:MenDeal];

    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize.x = view.bounds.size.width;
    io.DisplaySize.y = view.bounds.size.height;
    aimDisplayWidth.store(io.DisplaySize.x, std::memory_order_relaxed);
    aimDisplayHeight.store(io.DisplaySize.y, std::memory_order_relaxed);
    static bool s_configLoaded = false;
    if (!s_configLoaded) { [self readIniConfig]; s_configLoaded = true; }

#if TARGET_OS_OSX
    CGFloat framebufferScale = view.window.screen.backingScaleFactor ?: NSScreen.mainScreen.backingScaleFactor;
#else
    CGFloat framebufferScale = view.window.screen.nativeScale ?: 2.0;
#endif
    io.DisplayFramebufferScale = ImVec2(framebufferScale, framebufferScale);
    io.DeltaTime = 1.f / float(view.preferredFramesPerSecond ?: 60);

    id<MTLCommandBuffer> commandBuffer = [self.commandQueue commandBuffer];

    if (MenDeal == true) {
        [self.view setUserInteractionEnabled:YES];
    } else if (MenDeal == false) {
        [self.view setUserInteractionEnabled:NO];
    }

    MTLRenderPassDescriptor* renderPassDescriptor = view.currentRenderPassDescriptor;
    if (renderPassDescriptor != nil && commandBuffer != nil)
    {
        id <MTLRenderCommandEncoder> renderEncoder = [commandBuffer renderCommandEncoderWithDescriptor:renderPassDescriptor];
        if (renderEncoder != nil) {
            [renderEncoder pushDebugGroup:@""];

            ImGui_ImplMetal_NewFrame(renderPassDescriptor);
            ImGui::NewFrame();
            if (imgui::ESP || Settings::Aimbot::Tick || Enable) {
                Drawesp();
            }

            DrawWorldEsp();
            RenderMenu();

            ImGui::Render();
            ImDrawData* draw_data = ImGui::GetDrawData();
            ImGui_ImplMetal_RenderDrawData(draw_data, commandBuffer, renderEncoder);

            [renderEncoder popDebugGroup];
            [renderEncoder endEncoding];
        }

        if (view.currentDrawable != nil) {
            [commandBuffer presentDrawable:view.currentDrawable];
        }
    }

    [commandBuffer commit];
}

// HMOOD__TG@i_8_f
-(void) readIniConfig {
    if (!config) return;

    ini_remove(config, (char*)"modSkin", nullptr);
    ini_remove(config, (char*)"modSwitch", nullptr);

    imgui::ESP         = configManager::readBoolean(config, "ESP", "ESP", false);
    imgui::Health      = configManager::readBoolean(config, "ESP", "HEALTH", false);
    imgui::Line        = configManager::readBoolean(config, "ESP", "LINE", false);
    imgui::Name        = configManager::readBoolean(config, "ESP", "NAME", false);
    imgui::TeamID      = configManager::readBoolean(config, "ESP", "TEAM_ID", false);
    imgui::Distance    = configManager::readBoolean(config, "ESP", "DISTANCE", false);
    imgui::EnemyCount  = configManager::readBoolean(config, "ESP", "ENEMY_COUNT", false);
    imgui::Weapon      = configManager::readBoolean(config, "ESP", "WEAPON", false);
    imgui::Bone        = configManager::readBoolean(config, "ESP", "BONE", false);
    imgui::GameInfo    = configManager::readBoolean(config, "ESP", "GAME_INFO", false);
    imgui::EnemyAiming = configManager::readBoolean(config, "ESP", "ENEMY_AIMING", false);
    imgui::Alert360    = configManager::readBoolean(config, "ESP", "ALERT_360", false);
    IsStyle            = configManager::readInteger(config, "ESP", "STYLE", 1);
    imgui::Boxes       = configManager::readBoolean(config, "ESP", "BOXES", false);
    imgui::Items       = configManager::readBoolean(config, "ESP", "ITEMS", false);
    imgui::Lootbox     = configManager::readBoolean(config, "ESP", "LOOTBOX", false);
    imgui::Vehicle     = configManager::readBoolean(config, "ESP", "VEHICLE", false);
    globalHpAlphaF     = ImClamp(configManager::readFloat(config, "ESP", "HP_SCALE", 1.f), .5f, 5.f);
    strokeIntensity    = ImClamp(configManager::readFloat(config, "ESP", "STROKE_WIDTH", 1.f), .5f, 5.f);
    bgColor.Value.x    = ImClamp(configManager::readFloat(config, "ESP", "BORDER_R", bgColor.Value.x), 0.f, 1.f);
    bgColor.Value.y    = ImClamp(configManager::readFloat(config, "ESP", "BORDER_G", bgColor.Value.y), 0.f, 1.f);
    bgColor.Value.z    = ImClamp(configManager::readFloat(config, "ESP", "BORDER_B", bgColor.Value.z), 0.f, 1.f);
    bgColor.Value.w    = ImClamp(configManager::readFloat(config, "ESP", "BORDER_A", bgColor.Value.w), 0.f, 1.f);
    SetMenuLanguage(configManager::readInteger(config, "SYSTEM", "LANGUAGE", 0));
    const int triggerMode = configManager::readInteger(config, "AIMBOT", "TRIGGER_MODE", 3);
    Settings::Aimbot::TriggerMode.store(ImClamp(triggerMode, 0, 3), std::memory_order_relaxed);

    Settings::Aimbot::Tick = configManager::readBoolean(config, "AIMBOT", "ENABLED", false);
    Settings::Aimbot::AimMethod = ImClamp(configManager::readInteger(config, "AIMBOT", "MODE", 0), 0, 2);
    Enable = configManager::readBoolean(config, "AIMBOT", "SILENT_AIM", false) &&
             Settings::Aimbot::Tick && Settings::Aimbot::AimMethod != 0;
    Settings::Aimbot::SilentAim = Enable;
    Settings::Aimbot::SilentAimSettings::AimingLine = configManager::readBoolean(config, "AIMBOT", "AIM_LINE", false);
    Settings::Aimbot::SilentAimSettings::EnableFov = configManager::readBoolean(config, "AIMBOT", "SHOWFOV", true);
    Settings::Aimbot::SilentAimSettings::Prediction = configManager::readBoolean(config, "AIMBOT", "PREDICTION", true);
    Settings::Aimbot::SilentAimSettings::AimKnocked = configManager::readBoolean(config, "AIMBOT", "IGNOREKNOCKED", false);
    Settings::Aimbot::SilentAimSettings::Highprecisiontracking = configManager::readBoolean(config, "AIMBOT", "IGNOREBOTS", false);
    Settings::Aimbot::SilentAimSettings::Aimpositon = ImClamp(configManager::readInteger(config, "AIMBOT", "TARGET", 0), 0, 4);
    Settings::Aimbot::SilentAimSettings::MaxStepDeg = ImClamp(configManager::readFloat(config, "AIMBOT", "MAX_STEP", 2.f), .3f, 8.f);
    Settings::isVisibilityCheck = configManager::readBoolean(config, "AIMBOT", "VISCHECK", true);
    AimSmooth = ImClamp(configManager::readFloat(config, "AIMBOT", "SPEED", 5.f), 2.f, 30.f);
    Cross = ImClamp(configManager::readFloat(config, "AIMBOT", "FOV", 200.f), 30.f, 300.f);
    SilentAimMaxDistance = ImClamp(configManager::readFloat(config, "AIMBOT", "SILENT_DISTANCE", 150.f), 50.f, 355.f);
    追踪概率 = ImClamp(configManager::readFloat(config, "AIMBOT", "HITPROB", 100.f), 0.f, 100.f);
    自动开火 = configManager::readBoolean(config, "AIMBOT", "AUTOFIRE", false) && Settings::Aimbot::Tick;
    瞄准线 = configManager::readBoolean(config, "AIMBOT", "AIMLINE", false);
    ShowFov = Settings::Aimbot::SilentAimSettings::EnableFov;
    VisCheck = Settings::isVisibilityCheck;
    FixShoot = configManager::readBoolean(config, "AIMBOT", "FIXSHOOT", false);
    打击圈 = configManager::readInteger(config, "AIMBOT", "FOVSTYLE", 0);
    CL = configManager::readInteger(config, "AIMBOT", "CIRCLECOLOR", 1);
    AimF = configManager::readInteger(config, "AIMBOT", "ATTACKMETHOD", 1);
    g_disstance = configManager::readFloat(config, "AIMBOT", "DISTANCE", 300.f);

    MemoryFastScope = configManager::readBoolean(config, "MEMORY", "FASTSCOPE", false);
    MemoryZoom = configManager::readBoolean(config, "MEMORY", "ZOOM", false);
    MemoryDamage = configManager::readBoolean(config, "MEMORY", "DAMAGE", false);
    MemoryRainbow = configManager::readBoolean(config, "MEMORY", "RAINBOW", false);
    MemoryCrossSpin = configManager::readBoolean(config, "MEMORY", "CROSSSPIN", false);
    MemoryRainbowSpeed = ImClamp(configManager::readFloat(config, "MEMORY", "RAINBOW_SPEED", 1.6f), .1f, 2.4f);
    MemoryCrossSpinSpeed = ImClamp(configManager::readFloat(config, "MEMORY", "CROSSSPIN_SPEED", 180.f), 0.f, 180.f);
    MemoryZoomFov = ImClamp(configManager::readFloat(config, "MEMORY", "ZOOM_FOV", 40.f), 20.f, 90.f);
    WideView = configManager::readBoolean(config, "SETTINGS", "IPADVIEW", false);
    WideValue = ImClamp(configManager::readInteger(config, "SETTINGS", "TPP", 100), 80, 160);
    IsFastSwitch = configManager::readBoolean(config, "MEMORY", "FASTSWITCH", false);
    IsNocamerashake = configManager::readBoolean(config, "MEMORY", "NOCAMERASHAKE", false);
    IsNorecoil2 = configManager::readBoolean(config, "MEMORY", "NORECOIL2", false);
    IsFastshoot = configManager::readBoolean(config, "MEMORY", "FASTSHOOT", false);
    IsFastDrop = configManager::readBoolean(config, "MEMORY", "FASTDROP", false);
    chaynhanhv2 = configManager::readBoolean(config, "MEMORY", "SUPERRUN", false);
    isSpinning = configManager::readBoolean(config, "MEMORY", "SPIN", false);
    tocdoquay = configManager::readFloat(config, "MEMORY", "SPINSPEED", 0.f);
    crosshairSizeSlider = ImClamp(configManager::readFloat(config, "MEMORY", "CROSSSIZE", 0.f), 0.f, 20.f);
    HitX = configManager::readBoolean(config, "MEMORY", "HITX", false);
    IsCrossHair = configManager::readBoolean(config, "MEMORY", "SMALLCROSS", false);

    hideHacker = configManager::readBoolean(config, "SYSTEM", "HIDERECORD", false);
}

// HMOOD__TG@i_8_f
- (void)mtkView:(MTKView*)view drawableSizeWillChange:(CGSize)size
{
}

// HMOOD__TG@i_8_f
- (void)updateIOWithTouchEvent:(UIEvent *)event
{
    if (!event || !self.view) return;
    UITouch *anyTouch = event.allTouches.anyObject;
    if (!anyTouch) return;
    CGPoint touchLocation = [anyTouch locationInView:self.view];
    ImGuiIO &io = ImGui::GetIO();
    io.MousePos = ImVec2(touchLocation.x, touchLocation.y);

    BOOL hasActiveTouch = NO;
    for (UITouch *touch in event.allTouches)
    {
        if (touch.phase != UITouchPhaseEnded && touch.phase != UITouchPhaseCancelled)
        {
            hasActiveTouch = YES;
            break;
        }
    }
    io.MouseDown[0] = hasActiveTouch;
}

// HMOOD__TG@i_8_f
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self updateIOWithTouchEvent:event];
}

// HMOOD__TG@i_8_f
- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self updateIOWithTouchEvent:event];
}

// HMOOD__TG@i_8_f
- (void)touchesCancelled:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self updateIOWithTouchEvent:event];
}

// HMOOD__TG@i_8_f
- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self updateIOWithTouchEvent:event];
}

// HMOOD__TG@i_8_f
kaddr getRealOffset(kaddr offset){
    kaddr base = (kaddr)Get_module_base();
    if (!base) return 0;
    return base + offset;
}

long obbbbl() {
    kaddr base = (kaddr)Get_module_base();
    if (!base) return 0;
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    NSString *BundID = [infoDictionary objectForKey:@"CFBundleIdentifier"];
    if (!BundID) return 0;
    if ([BundID containsString:@"com.tencent.ig"]) {
        return (long)getRealOffset(0x10AAD3898);
    }
    if ([BundID containsString:@"kr"]) {
        return (long)getRealOffset(0x10A566580);
    }
    if ([BundID containsString:@"rekoo"]) {
        return (long)getRealOffset(0x10A545580);
    }
    if ([BundID containsString:@"vn.vng.pubgmobile"]) {
        return (long)getRealOffset(0x10A205B00);
    }
    if ([BundID containsString:@"imobile"]) {
        return (long)getRealOffset(0x1098bac80);
    }
    return 0;
}

UWorld *GEWorld = nullptr;
int GWorldNum = 0;
TUObjectArray gobjects;

#define TSL_FONT_DEFAULT_SIZE 26
static UFont *robotoFont = nullptr, *robotoTinyFont = nullptr, *tslFont = nullptr;

// HMOOD__TG@i_8_f
UWorld *GetFullWorld()
{
    if (!Tools::IsPtrValid(UObject::GUObjectArray)) return nullptr;
    auto *objArray = &UObject::GUObjectArray->ObjObjects;
    if (!Tools::IsPtrValid(objArray)) return nullptr;

    int count = objArray->Num();
    if (count <= 0 || count > 5000000) return nullptr;

    if (GWorldNum <= 0 || GWorldNum >= count) {
        for (int i = 0; i < count; i++) {
            UObject *obj = objArray->GetByIndex(i);
            if (!isObjectInvalid(obj) && obj->IsA(UEngine::StaticClass())) {
                auto *GEngine = (UEngine *)obj;
                if (Tools::IsPtrValid(GEngine)) {
                    tslFont = GEngine->MediumFont;
                    robotoTinyFont = GEngine->MediumFont;
                    robotoFont = GEngine->MediumFont;
                    auto *ViewPort = GEngine->GameViewport;
                    if (Tools::IsPtrValid(ViewPort) && Tools::IsPtrValid(ViewPort->World)) {
                        GEWorld = ViewPort->World;
                        GWorldNum = i;
                        return ViewPort->World;
                    }
                }
            }
        }
    } else {
        UObject *obj = objArray->GetByIndex(GWorldNum);
        auto *GEngine = (UEngine *)obj;
        if (!isObjectInvalid(GEngine) && GEngine->IsA(UEngine::StaticClass())) {
            tslFont = GEngine->MediumFont;
            robotoTinyFont = GEngine->MediumFont;
            robotoFont = GEngine->MediumFont;
            auto *ViewPort = GEngine->GameViewport;
            if (Tools::IsPtrValid(ViewPort) && Tools::IsPtrValid(ViewPort->World)) {
                GEWorld = ViewPort->World;
                return ViewPort->World;
            }
        }
        GWorldNum = 0;
    }
    return nullptr;
}

// HMOOD__TG@i_8_f
TNameEntryArray *GetGNames() {
    kaddr base = (kaddr)Get_module_base();
    if (!base) return nullptr;
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    NSString *BundID = [infoDictionary objectForKey:@"CFBundleIdentifier"];
    if (!BundID) return nullptr;
    if ([BundID containsString:@"ig"]) {
        return ((TNameEntryArray *(*)())(base + 0x10522AC98))();
    }
    if ([BundID containsString:@"kr"]) {
        return ((TNameEntryArray *(*)())(base + 0x104D9FA14))();
    }
    if ([BundID containsString:@"rekoo"]) {
        return ((TNameEntryArray *(*)())(base + 0x104D78AE0))();
    }
    if ([BundID containsString:@"vn"]) {
        return ((TNameEntryArray *(*)())(base + 0x104B1AE24))();
    }
    if ([BundID containsString:@"imobile"]) {
        return ((TNameEntryArray *(*)())(base + 0x10454d2a4))();
    }
    return nullptr;
}

// HMOOD__TG@i_8_f
std::vector<AActor *> getActorsSafe(UWorld* World)
{
    if (!Tools::IsPtrValid(World)) {
        return {};
    }
    ULevel* PersistentLevel = World->PersistentLevel;
    if (!Tools::IsPtrValid(PersistentLevel)) {
        return {};
    }

    uintptr_t actorsPtrAddr = (uintptr_t)PersistentLevel + 0xa0;
    if (!Tools::IsPtrValid((void *)actorsPtrAddr)) {
        return {};
    }

    const TArray<AActor *>& Actors = *(const TArray<AActor *> *)actorsPtrAddr;
    int num = Actors.Num();
    if (num <= 0 || num > 100000) {
        return {};
    }

    std::vector<AActor *> ValidActors;
    ValidActors.reserve((size_t)num);
    for (int i = 0; i < num; i++) {
        auto* Actor = Actors[i];
        if (!isObjectInvalid(Actor) && !Actor->IsChildActor()) {
            ValidActors.push_back(Actor);
        }
    }
    return ValidActors;
}

// HMOOD__TG@i_8_f
FVector GetBoneLocationByName(ASTExtraPlayerCharacter *Actor, const char *BoneName) {
    if (!Tools::IsPtrValid(Actor) || !Tools::IsPtrValid(Actor->Mesh) || !BoneName) return FVector();
    return Actor->GetBonePos(BoneName, FVector());
}

// HMOOD__TG@i_8_f
bool WriteAddr(void *addr, void *buffer, size_t length) {
    if (!addr || !buffer || length == 0) return false;
    if (!Tools::IsPtrValid(addr)) return false;
    long page_size = sysconf(_SC_PAGESIZE);
    if (page_size <= 0) page_size = 16384;
    uintptr_t start = ((uintptr_t)addr) & ~((uintptr_t)page_size - 1);
    uintptr_t end = (((uintptr_t)addr + length) + (uintptr_t)page_size - 1) & ~((uintptr_t)page_size - 1);
    size_t size = end - start;
    if (mprotect((void *)start, size, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) return false;
    memcpy(addr, buffer, length);
    sys_icache_invalidate(addr, length);
    return true;
}

class Rect2 {
public:
    float x;
    float y;
    float width;
    float height;

    Rect2() : x(0), y(0), width(0), height(0) {}
    Rect2(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {}

    bool operator==(const Rect2 &src) const {
        return (src.x == this->x && src.y == this->y && src.height == this->height &&
                src.width == this->width);
    }

    bool operator!=(const Rect2 &src) const {
        return !(*this == src);
    }
};

struct FLinearColor visCol;
ASTExtraPlayerCharacter *g_LocalPlayer = nullptr;
ASTExtraPlayerController *g_PlayerController = nullptr;

#define COLOR_BLACK  FLinearColor(0, 0, 0, 1.f)
#define COLOR_WHITE  FLinearColor(1.f, 1.f, 1.f, 1.f)
#define COLOR_RED    FLinearColor(1.f, 0, 0, 1.f)
#define COLOR_LIME   FLinearColor(0, 1.f, 0, 1.f)
#define COLOR_BLUE   FLinearColor(0, 0, 1.f, 1.f)
#define COLOR_CAR    FLinearColor(1.f, 0.5f, 1.f, 1.f)
#define GREEN        FLinearColor(0 / 255.f, 153 / 255.f, 0 / 255.f, 1.f)
#define ABU          FLinearColor(0 / 255.f, 204 / 255.f, 204 / 255.f, 1.f)
#define COLOR_GREEN  FLinearColor(0, 0.5f, 0, 1.f)
#define COLOR_PLAYER FLinearColor(1.000f, 0.620f, 0.150f, 1.000f)
#define COLOR_YELLOW FLinearColor(1.000f, 1.000f, 0.000f, 1.000f)
#define 黑色         FLinearColor(0, 0, 0, 1.f)
#define 白色         FLinearColor(1.f, 1.f, 1.f, 1.f)
#define 灰色         FLinearColor(0, 1.f, 0, 1.f)
#define 红色         FLinearColor(1.f, 0, 0, 0.7f)
#define 绿色         FLinearColor(0, 0.5f, 0, 1.f)
#define 黄色         FLinearColor(1.00f, 1.00f, 0.0f, 1.0f)
#define 青色         FLinearColor(0.0f, 1.00f, 1.00f, 1.0f)
#define 橄榄绿       FLinearColor(0.5f, 0.5f, 0.0f, 1.0f)
#define 棕色         FLinearColor(0.6f, 0.3f, 0.1f, 1.0f)
#define 紫色         FLinearColor(0.894f, 0.0f, 0.671f, 1.0f)
#define 橙色         FLinearColor(1.00f, 0.45f, 0.0f, 1.0f)
#define 粉色         FLinearColor(1.00f, 0.39f, 0.78f, 1.0f)
#define 蓝色         FLinearColor(0, 2, 2.f, 0.f)

static UGameplayStatics* iosde = nullptr;

// HMOOD__TG@i_8_f
FVector2D WorldToRadar(float Yaw, FVector Origin, FVector LocalOrigin, float PosX, float PosY,
                       FVector Size, bool & outbuff)
{
    bool flag = false;
    double num = (double)Yaw;
    double num2 = num * 0.017453292519943295;
    float num3 = (float)std::cos(num2);
    float num4 = (float)std::sin(num2);
    float num5 = Origin.X - LocalOrigin.X;
    float num6 = Origin.Y - LocalOrigin.Y;
    FVector2D vector;
    vector.X = (num6 * num3 - num5 * num4) / 150.f;
    vector.Y = (num5 * num3 + num6 * num4) / 150.f;
    FVector2D vector2;
    vector2.X = vector.X + PosX + Size.X / 2.f;
    vector2.Y = -vector.Y + PosY + Size.Y / 2.f;
    if (vector2.X > PosX + Size.X) {
        vector2.X = PosX + Size.X;
    } else if (vector2.X < PosX) {
        vector2.X = PosX;
    }
    if (vector2.Y > PosY + Size.Y) {
        vector2.Y = PosY + Size.Y;
    } else if (vector2.Y < PosY) {
        vector2.Y = PosY;
    }
    if (vector2.Y == PosY || vector2.X == PosX) {
        flag = true;
    }
    outbuff = flag;
    return vector2;
}

// HMOOD__TG@i_8_f
FVector2D rotateCoord(float angle, FVector2D coord) {
    float s = sinf(angle * M_PI / 180.f);
    float c = cosf(angle * M_PI / 180.f);
    return {coord.X * c + coord.Y * s, -coord.X * s + coord.Y * c};
}

// HMOOD__TG@i_8_f
float DegreeToRadian(float degree){
    return degree * (M_PI / 180.f);
}

// HMOOD__TG@i_8_f
void DrawFilledRectangle(AHUD *HUD, FVector2D Pos, float Width, float Height, FLinearColor Color) {
    if (!Tools::IsPtrValid(HUD)) return;
    HUD->DrawRect(Color, Pos.X, Pos.Y, Width, Height);
}

// HMOOD__TG@i_8_f
void DrawLine(AHUD *HUD, FVector2D posFrom, FVector2D posTo, float Thickness, FLinearColor Color) {
    if (!Tools::IsPtrValid(HUD)) return;
    HUD->DrawLine(posFrom.X, posFrom.Y, posTo.X, posTo.Y, Color, Thickness);
}

// HMOOD__TG@i_8_f
void DrawCircle(AHUD *HUD, int x, int y, int radius, int numsides, FLinearColor OutlineColor){
    if (!Tools::IsPtrValid(HUD) || !Tools::IsPtrValid(HUD->Canvas) || numsides <= 0) return;
    float Step = (float)(M_PI * 2.0 / numsides);
    for (float a = 0; a < (float)(M_PI * 2.0); a += Step) {
        float X1 = radius * cosf(a) + x;
        float Y1 = radius * sinf(a) + y;
        float X2 = radius * cosf(a + Step) + x;
        float Y2 = radius * sinf(a + Step) + y;
        HUD->Canvas->K2_DrawLine(FVector2D{X1, Y1}, FVector2D{X2, Y2}, 1.f, OutlineColor);
    }
}

// HMOOD__TG@i_8_f
void DrawCircle(UCanvas *Canvas, int x, int y, int radius, int numsides, FLinearColor OutlineColor){
    if (!Tools::IsPtrValid(Canvas) || numsides <= 0) return;
    float Step = (float)(M_PI * 2.0 / numsides);
    for (float a = 0; a < (float)(M_PI * 2.0); a += Step) {
        float X1 = radius * cosf(a) + x;
        float Y1 = radius * sinf(a) + y;
        float X2 = radius * cosf(a + Step) + x;
        float Y2 = radius * sinf(a + Step) + y;
        Canvas->K2_DrawLine(FVector2D{X1, Y1}, FVector2D{X2, Y2}, 1.f, OutlineColor);
    }
}

// HMOOD__TG@i_8_f
void LoadFontOnce() {
    if (!tslFont)     tslFont = UObject::FindObject<UFont>("Font TSLFont.TSLFont");
    if (!robotoFont) robotoFont = UObject::FindObject<UFont>("Font Roboto.Roboto");
    if (!robotoTinyFont) robotoTinyFont = UObject::FindObject<UFont>("Font RobotoTiny.RobotoTiny");
}

// HMOOD__TG@i_8_f
bool _read(kaddr addr, void *buffer, int len)
{
    if (!addr || !buffer || len <= 0 || !IsValidAddress(addr)) return false;
    vm_size_t size = 0;
    kern_return_t error = vm_read_overwrite(mach_task_self(), (vm_address_t)addr, len, (vm_address_t)buffer, &size);
    if (error != KERN_SUCCESS || size != (vm_size_t)len) {
        return false;
    }
    return true;
}

#define W2S(w, s) UGameplayStatics::ProjectWorldToScreen(g_PlayerController, w, false, s)

// HMOOD__TG@i_8_f
FVector WorldToRadar(float Yaw, FVector Origin, FVector LocalOrigin, float PosX, float PosY, Vector3 Size, bool &outbuff) {
    bool flag = false;
    double num = (double)Yaw;
    double num2 = num * 0.017453292519943295;
    float num3 = (float)std::cos(num2);
    float num4 = (float)std::sin(num2);
    float num5 = Origin.X - LocalOrigin.X;
    float num6 = Origin.Y - LocalOrigin.Y;
    struct FVector Xector;
    Xector.X = (num6 * num3 - num5 * num4) / 150.f;
    Xector.Y = (num5 * num3 + num6 * num4) / 150.f;
    struct FVector Xector2;
    Xector2.X = Xector.X + PosX + Size.X / 2.f;
    Xector2.Y = -Xector.Y + PosY + Size.Y / 2.f;
    if (Xector2.X > PosX + Size.X) {
        Xector2.X = PosX + Size.X;
    } else if (Xector2.X < PosX) {
        Xector2.X = PosX;
    }
    if (Xector2.Y > PosY + Size.Y) {
        Xector2.Y = PosY + Size.Y;
    } else if (Xector2.Y < PosY) {
        Xector2.Y = PosY;
    }
    if (Xector2.Y == PosY || Xector2.X == PosX) {
        flag = true;
    }
    outbuff = flag;
    return Xector2;
}

void (*orig_Broadcast)(ASTExtraPlayerController* thiz, FFatalDamageParameter* FatalDamageParameter) = nullptr;

// HMOOD__TG@i_8_f
void hk_Broadcast(ASTExtraPlayerController* thiz, FFatalDamageParameter* FatalDamageParameter)
{
    if (!Tools::IsPtrValid((void *)orig_Broadcast)) return;
    if (isObjectInvalid(thiz) || !Tools::IsPtrValid(FatalDamageParameter) ||
        isObjectInvalid(g_PlayerController) || isObjectInvalid(g_LocalPlayer) ||
        g_PlayerController->PlayerKey == 0) {
        return orig_Broadcast(thiz, FatalDamageParameter);
    }

    if (hideNameKillMsg && g_PlayerController->PlayerKey == FatalDamageParameter->CauserKey) {
        static uint16_t hideBuf[] = { '?','?','?', 0 };
        struct FStr16 { uint16_t *D; int32_t C; int32_t M; };
        auto tryHide = [](void *fieldPtr) {
            if (!Tools::IsPtrValid(fieldPtr)) return;
            FStr16 *r = reinterpret_cast<FStr16*>(fieldPtr);
            if (r->M >= 4) {
                r->D = hideBuf;
                r->C = 3;
            }
        };
        tryHide(&FatalDamageParameter->String.causerName);
        tryHide(&FatalDamageParameter->String.FuzzyCauserName);
        tryHide(&FatalDamageParameter->String.RealKillerName);
    }

    return orig_Broadcast(thiz, FatalDamageParameter);
}

int glWidth = 0, glHeight = 0;

// HMOOD__TG@i_8_f
static FVector ResolveAimPosition(ASTExtraPlayerCharacter* player, ASTExtraPlayerController* controller);

// HMOOD__TG@i_8_f
ASTExtraPlayerCharacter* GetTargetByCrossDist() {
    auto* player = g_LocalPlayer;
    auto* controller = g_PlayerController;
    if (!IsLogin || isObjectInvalid(player) || isObjectInvalid(controller) ||
        !Tools::IsPtrValid(player->RootComponent) || glWidth <= 0 || glHeight <= 0)
        return nullptr;
    const float displayWidth = aimDisplayWidth.load(std::memory_order_relaxed);
    const float displayHeight = aimDisplayHeight.load(std::memory_order_relaxed);
    if (displayWidth <= 0.f || displayHeight <= 0.f || !std::isfinite(Cross) || Cross <= 0.f)
        return nullptr;
    int viewportWidth = 0, viewportHeight = 0;
    controller->GetViewportSize(&viewportWidth, &viewportHeight);
    if (viewportWidth <= 0 || viewportHeight <= 0) return nullptr;
    const float scaleX = displayWidth / viewportWidth, scaleY = displayHeight / viewportHeight;
    const float centerX = displayWidth * .5f, centerY = displayHeight * .5f;
    const bool bulletTrack = Enable;
    float nearest = bulletTrack ? std::numeric_limits<float>::infinity() : Cross * Cross;
    ASTExtraPlayerCharacter* result = nullptr;
    std::vector<ASTExtraPlayerCharacter*> players;
    GetAllActors(players);
    for (auto* candidate : players) {
        if (isObjectInvalid(candidate) || candidate == player || candidate->PlayerKey == player->PlayerKey ||
            candidate->TeamID == player->TeamID || candidate->bDead || candidate->bHidden ||
            !Tools::IsPtrValid(candidate->Mesh) || !Tools::IsPtrValid(candidate->RootComponent))
            continue;
        if (Settings::Aimbot::SilentAimSettings::AimKnocked && candidate->Health <= 0.f)
            continue;
        if (Settings::Aimbot::SilentAimSettings::Highprecisiontracking && (candidate->bEnsure || candidate->bIsAI))
            continue;
        const float distance = player->GetDistanceTo(candidate) / 100.f;
        if (!std::isfinite(distance) || distance > SilentAimMaxDistance)
            continue;
        if (Settings::isVisibilityCheck && !controller->LineOfSightTo(candidate, {0, 0, 0}, true))
            continue;
        const FVector point = ResolveAimPosition(candidate, controller);
        if (!(point.X || point.Y || point.Z)) continue;
        float metric = distance * distance;
        if (!bulletTrack) {
            FVector2D screen;
            if (!UGameplayStatics::ProjectWorldToScreen(controller, point, false, &screen)) continue;
            const float x = screen.X * scaleX, y = screen.Y * scaleY;
            if (!std::isfinite(x) || !std::isfinite(y) || x < 0.f || x > displayWidth || y < 0.f || y > displayHeight)
                continue;
            const float dx = x - centerX, dy = y - centerY;
            metric = dx * dx + dy * dy;
            if (metric > Cross * Cross) continue;
        }
        if (metric <= nearest) {
            nearest = metric;
            result = candidate;
        }
    }
    return result;
}

// HMOOD__TG@i_8_f
auto VIP_Fov_Based() -> ASTExtraPlayerCharacter* { return GetTargetByCrossDist(); }

// HMOOD__TG@i_8_f
static void UpdateAutoFire(ASTExtraPlayerCharacter* player, ASTExtraPlayerController* controller) {
    static uintptr_t previousController = 0;
    static bool pressed = false;
    if (isObjectInvalid(player) || isObjectInvalid(controller)) {
        pressed = false;
        return;
    }
    const uintptr_t identity = (uintptr_t)controller;
    if (previousController != identity) { pressed = false; previousController = identity; }
    bool fire = IsLogin && Settings::Aimbot::Tick && 自动开火 &&
                Tools::IsPtrValid(player->RootComponent) && !player->bDead;
    if (fire) {
        auto* manager = player->WeaponManagerComponent;
        fire = Tools::IsPtrValid(manager) && Tools::IsPtrValid(manager->CurrentWeaponReplicated);
        if (fire) {
            const int slot = (int)manager->GetCurrentUsingPropSlot().GetValue();
            fire = slot >= 1 && slot <= 3 &&
                   manager->CurrentWeaponReplicated->IsA(ASTExtraShootWeapon::StaticClass());
        }
        const int trigger = Settings::Aimbot::TriggerMode.load(std::memory_order_relaxed);
        if ((trigger == 1 || trigger == 2) && !player->bIsGunADS) fire = false;
        if (fire) fire = GetTargetByCrossDist() != nullptr;
    }
    if (fire && !pressed) { controller->OnPressFire(); pressed = true; }
    else if (!fire && pressed) {
        controller->OnReleaseFire();
        pressed = false;
    }
}

bool  VehicleAimNearCrosshair = false;
bool  VehicleVisCheck         = false;

float VehicleAimConeDeg   = 8.0f;
float VehicleAimHeightZ   = 50.0f;
float SilentAimPingMs     = 0.0f;

// HMOOD__TG@i_8_f
static inline float Dot3(const FVector& a, const FVector& b){ return a.X*b.X + a.Y*b.Y + a.Z*b.Z; }
// HMOOD__TG@i_8_f
static inline float Len (const FVector& v){ return sqrtf(v.X*v.X + v.Y*v.Y + v.Z*v.Z); }
// HMOOD__TG@i_8_f
static inline float DegToRad(float d){ return d * 0.017453292519943295f; }

// HMOOD__TG@i_8_f
static float GetPingSeconds(APlayerController* ) {
    float ms = SilentAimPingMs;
    if (ms < 0.f)   ms = 0.f;
    if (ms > 400.f) ms = 400.f;
    return ms * 0.001f;
}

// HMOOD__TG@i_8_f
static bool IsPartiallyVisible(APlayerController* PC, AActor* Other, const FVector& viewLoc){
    if (isObjectInvalid(PC) || isObjectInvalid(Other)) return false;
    if (PC->LineOfSightTo(Other, viewLoc, true)) return true;

    FVector to = UKismetMathLibrary::Subtract_VectorVector(Other->K2_GetActorLocation(), viewLoc);
    float d = Len(to);
    if (d > 0.f && d <= 12000.f) {
        FRotator rot = PC->GetControlRotation();
        FVector fwd  = UKismetMathLibrary::GetForwardVector(rot);
        FVector dir  = { to.X/d, to.Y/d, to.Z/d };
        float cosT = Dot3(fwd, dir);
        if (cosT > cosf(DegToRad(6.0f))) return true;
    }
    return false;
}

// HMOOD__TG@i_8_f
static bool IsVisiblePoint(APlayerController* PC, AActor* Target, const FVector& from, const FVector& to) {
    (void)from;
    if (isObjectInvalid(PC) || isObjectInvalid(Target)) return false;
    return PC->LineOfSightTo(Target, to, true);
}

// HMOOD__TG@i_8_f
static FVector GetBestBonePosVisible(ASTExtraPlayerCharacter* P, APlayerController* PC, const FVector& viewLoc){
    if (isObjectInvalid(P) || !Tools::IsPtrValid(P->Mesh)) return FVector{0,0,0};

    static const char* bones[] = {
        "Head","neck_01","spine_03","spine_02",
        "hand_r","hand_l","lowerarm_r","lowerarm_l","upperarm_r","upperarm_l",
        "foot_r","foot_l","calf_r","calf_l","thigh_r","thigh_l",
        "spine_01","pelvis"
    };

    FVector fallback{0,0,0};
    for (int i = 0; i < (int)(sizeof(bones)/sizeof(bones[0])); ++i) {
        FVector p = P->GetBonePos(bones[i], {});
        if (!(p.X || p.Y || p.Z)) continue;
        if (IsVisiblePoint(PC, (AActor*)P, viewLoc, p)) {
            return p;
        }
        if (!(fallback.X || fallback.Y || fallback.Z)) fallback = p;
    }
    if (fallback.X || fallback.Y || fallback.Z) return fallback;
    FVector h = P->GetBonePos("Head", {}); if (h.X || h.Y || h.Z) return h;
    return P->GetBonePos("pelvis", {});
}

// HMOOD__TG@i_8_f
static FVector ResolveAimPosition(ASTExtraPlayerCharacter* player, ASTExtraPlayerController* controller) {
    if (isObjectInvalid(player) || !Tools::IsPtrValid(player->Mesh)) return FVector{0, 0, 0};
    const char* bones[] = {"Head", "neck_01", "spine_03", "pelvis"};
    const int target = Settings::Aimbot::SilentAimSettings::Aimpositon;
    if (target >= 0 && target < 4) return player->GetBonePos(bones[target], {});
    FVector view = (!isObjectInvalid(g_LocalPlayer) && Tools::IsPtrValid(g_LocalPlayer->Mesh))
                   ? g_LocalPlayer->GetBonePos("Head", {}) : FVector{0, 0, 0};
    view.Z += 10.f;
    return GetBestBonePosVisible(player, controller, view);
}

// HMOOD__TG@i_8_f
static ASTExtraVehicleBase* PickVehicleNearCrosshair(
    APlayerController* PC, const FVector& start, const FRotator& shotRot, float coneDeg, bool doVis)
{
    if (isObjectInvalid(PC) || isObjectInvalid(g_LocalPlayer)) return nullptr;

    TArray<AActor*> all;
    UGameplayStatics::GetAllActorsOfClass((UObject*)PC, AActor::StaticClass(), &all);

    FVector aimDir = UKismetMathLibrary::GetForwardVector(shotRot);
    float l2 = aimDir.X*aimDir.X + aimDir.Y*aimDir.Y + aimDir.Z*aimDir.Z;
    if (l2 < 0.5f && Tools::IsPtrValid(PC->PlayerCameraManager))
        aimDir = UKismetMathLibrary::GetForwardVector(PC->PlayerCameraManager->GetCameraRotation());

    const float coneCos = cosf(DegToRad(coneDeg > 0.f ? coneDeg : 10.f));
    FVector viewLoc = Tools::IsPtrValid(g_LocalPlayer->Mesh) ? g_LocalPlayer->GetBonePos("Head", {}) : FVector{0,0,0};
    viewLoc.Z += 10.f;

    float best = 1e9f;
    ASTExtraVehicleBase* bestVeh = nullptr;

    int allCount = all.Num();
    if (allCount <= 0 || allCount > 100000) return nullptr;

    for (int i = 0; i < allCount; ++i) {
        AActor* a = all[i];
        if (isObjectInvalid(a) || !a->IsA(ASTExtraVehicleBase::StaticClass())) continue;

        auto* V = (ASTExtraVehicleBase*)a;
        if (!Tools::IsPtrValid(V->RootComponent)) continue;
        if (doVis && !IsPartiallyVisible(PC, V, viewLoc)) continue;

        FVector to = UKismetMathLibrary::Subtract_VectorVector(V->K2_GetActorLocation(), start);
        float d = Len(to); if (d < 1.f) continue;

        FVector dir = { to.X/d, to.Y/d, to.Z/d };
        float dot = Dot3(aimDir, dir);
        if (dot < coneCos) continue;

        float score = (1.f - dot)*1000.f + (d * 0.001f);
        if (score < best) { best = score; bestVeh = V; }
    }
    return bestVeh;
}

// HMOOD__TG@i_8_f
static ASTExtraPlayerCharacter* FindVehicleOccupant(ASTExtraVehicleBase* Veh){
    if (isObjectInvalid(Veh) || isObjectInvalid(g_LocalPlayer)) return nullptr;

    TArray<AActor*> allP;
    UGameplayStatics::GetAllActorsOfClass((UObject*)Veh, ASTExtraPlayerCharacter::StaticClass(), &allP);

    ASTExtraPlayerCharacter* best = nullptr;
    float bestD = 1e9f;

    FVector cam = Tools::IsPtrValid(g_LocalPlayer->Mesh) ? g_LocalPlayer->GetBonePos("Head", {}) : FVector();
    cam.Z += 10.f;

    int count = allP.Num();
    if (count <= 0 || count > 100000) return nullptr;

    for (int i = 0; i < count; ++i) {
        auto* P = (ASTExtraPlayerCharacter*)allP[i];
        if (isObjectInvalid(P) || P == g_LocalPlayer || !Tools::IsPtrValid(P->RootComponent)) continue;
        if (P->bDead) continue;
        if (P->CurrentVehicle != Veh) continue;

        float d = Len(UKismetMathLibrary::Subtract_VectorVector(P->K2_GetActorLocation(), cam));
        if (d < bestD) { bestD = d; best = P; }
    }
    return best;
}

// HMOOD__TG@i_8_f
static ASTExtraPlayerCharacter* PickAirborneOrPeekNearCrosshair(
    APlayerController* PC, const FVector& start, const FRotator& shotRot, float coneDeg)
{
    if (isObjectInvalid(PC) || isObjectInvalid(g_LocalPlayer)) return nullptr;

    TArray<AActor*> allP;
    UGameplayStatics::GetAllActorsOfClass((UObject*)PC, ASTExtraPlayerCharacter::StaticClass(), &allP);

    FVector aimDir = UKismetMathLibrary::GetForwardVector(shotRot);
    float l2 = aimDir.X*aimDir.X + aimDir.Y*aimDir.Y + aimDir.Z*aimDir.Z;
    if (l2 < 0.5f && Tools::IsPtrValid(PC->PlayerCameraManager))
        aimDir = UKismetMathLibrary::GetForwardVector(PC->PlayerCameraManager->GetCameraRotation());

    const float coneCos = cosf(DegToRad(coneDeg > 0.f ? coneDeg : 8.f));
    FVector viewLoc = Tools::IsPtrValid(g_LocalPlayer->Mesh) ? g_LocalPlayer->GetBonePos("Head", {}) : FVector{0,0,0};
    viewLoc.Z += 10.f;

    ASTExtraPlayerCharacter* best = nullptr;
    float bestScore = 1e9f;

    int count = allP.Num();
    if (count <= 0 || count > 100000) return nullptr;

    for (int i = 0; i < count; ++i) {
        auto* P = (ASTExtraPlayerCharacter*)allP[i];
        if (isObjectInvalid(P) || P == g_LocalPlayer || !Tools::IsPtrValid(P->RootComponent)) continue;
        if (P->bDead) continue;

        FVector v = P->GetVelocity();
        bool airborneish = (fabsf(v.Z) > 120.f);

        if (!airborneish && !IsPartiallyVisible(PC, (AActor*)P, viewLoc)) continue;

        FVector to = UKismetMathLibrary::Subtract_VectorVector(P->K2_GetActorLocation(), start);
        float d = Len(to); if (d < 1.f) continue;

        FVector dir = { to.X/d, to.Y/d, to.Z/d };
        float dot = Dot3(aimDir, dir);
        if (dot < coneCos) continue;

        float score = (1.f - dot)*1000.f + (d * 0.001f);
        if (score < bestScore) { bestScore = score; best = P; }
    }
    return best;
}

void (*orig_shoot_event)(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1, int unk2) = nullptr;

// HMOOD__TG@i_8_f
void shoot_event(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, ASTExtraShootWeapon *weapon, int unk1) {
    if (!Tools::IsPtrValid((void *)orig_shoot_event)) return;
    if (!Enable || !Settings::Aimbot::Tick || Settings::Aimbot::AimMethod == 0 ||
        !IsLogin || isObjectInvalid(g_LocalPlayer) || isObjectInvalid(g_PlayerController) ||
        isObjectInvalid(thiz))
        return orig_shoot_event(thiz, start, rot, weapon, unk1);
    const float probability = std::isfinite(追踪概率) ? ImClamp(追踪概率, 0.f, 100.f) : 0.f;
    if (probability <= 0.f || (probability < 100.f && arc4random_uniform(10000) >= (uint32_t)(probability * 100.f)))
        return orig_shoot_event(thiz, start, rot, weapon, unk1);
    UKismetMathLibrary* UMC = (UKismetMathLibrary*)UKismetMathLibrary::StaticClass();
    if (!Tools::IsPtrValid(UMC)) return orig_shoot_event(thiz, start, rot, weapon, unk1);

    ASTExtraPlayerCharacter* Target = nullptr;
    if (Enable) Target = VIP_Fov_Based();

    if (!isObjectInvalid(Target) && !isObjectInvalid(g_LocalPlayer)) {
        float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.0f;
        if (dist > SilentAimMaxDistance) {
            Target = nullptr;
        }
    }

    ASTExtraVehicleBase* VehicleChosen = nullptr;
    if (isObjectInvalid(Target) && VehicleAimNearCrosshair && !isObjectInvalid(g_LocalController)) {
        float cone = (VehicleAimConeDeg > 0.f ? VehicleAimConeDeg : 8.f);
        VehicleChosen = PickVehicleNearCrosshair(g_LocalController, start, rot, cone, VehicleVisCheck);
        if (!isObjectInvalid(VehicleChosen)) {
            if (ASTExtraPlayerCharacter* occ = FindVehicleOccupant(VehicleChosen)) {
                Target = occ;
                VehicleChosen = nullptr;
            }
        }
    }

    if (!isObjectInvalid(Target) && !isObjectInvalid(g_LocalPlayer)) {
        float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.0f;
        if (dist > SilentAimMaxDistance) {
            Target = nullptr;
        }
    }

    if (!isObjectInvalid(Target) || (!isObjectInvalid(VehicleChosen) && Tools::IsPtrValid(VehicleChosen->RootComponent))) {
        bool triggerOk = IsAimTriggerActive(g_LocalPlayer);

        if (triggerOk) {
            FVector targetAimPos{};

            if (!isObjectInvalid(Target)) {
                FVector bonePos = ResolveAimPosition(Target, g_PlayerController);
                if (!(bonePos.X || bonePos.Y || bonePos.Z))
                    return orig_shoot_event(thiz, start, rot, weapon, unk1);

                if (auto SW = thiz->ShootWeaponEntityComponent; Tools::IsPtrValid(SW)) {
                    float spd = SW->BulletFireSpeed;
                    if (spd > 1.f && Settings::Aimbot::SilentAimSettings::Prediction) {
                        ASTExtraVehicleBase* curVeh = Target->CurrentVehicle;
                        FVector tgtVel = !isObjectInvalid(curVeh) ? curVeh->ReplicatedMovement.LinearVelocity
                                                                 : Target->GetVelocity();

                        const bool airborneish = fabsf(tgtVel.Z) > 120.f;
                        float dist = Len(UMC->Subtract_VectorVector(bonePos, start));
                        float t = dist/spd + GetPingSeconds(g_LocalController);
                        if (airborneish) t += 0.05f;

                        targetAimPos = UMC->Add_VectorVector(bonePos, UMC->Multiply_VectorFloat(tgtVel, t));
                        targetAimPos.Z += 0.5f * 980.f * t * t;

                        if (airborneish && (bonePos.Z - start.Z) > 600.f) {
                            targetAimPos.Z += 15.f;
                        }
                    } else {
                        targetAimPos = bonePos;
                    }
                } else {
                    targetAimPos = bonePos;
                }
            }
            else if (!isObjectInvalid(VehicleChosen) && Tools::IsPtrValid(VehicleChosen->RootComponent)) {
                targetAimPos = VehicleChosen->K2_GetActorLocation();
                targetAimPos.Z += (VehicleAimHeightZ != 0.f ? VehicleAimHeightZ : 50.f);

                if (auto SW = thiz->ShootWeaponEntityComponent; Tools::IsPtrValid(SW)) {
                    float spd = SW->BulletFireSpeed;
                    if (spd > 1.f && Settings::Aimbot::SilentAimSettings::Prediction) {
                        FVector vel = VehicleChosen->ReplicatedMovement.LinearVelocity;
                        float dist = g_LocalPlayer->GetDistanceTo(VehicleChosen);
                        float t = dist/spd + GetPingSeconds(g_LocalController);

                        targetAimPos = UMC->Add_VectorVector(targetAimPos, UMC->Multiply_VectorFloat(vel, t));
                        targetAimPos.Z += 0.5f * 980.f * t * t;
                    }
                }
            }

            if (!std::isfinite(targetAimPos.X) || !std::isfinite(targetAimPos.Y) || !std::isfinite(targetAimPos.Z))
                return orig_shoot_event(thiz, start, rot, weapon, unk1);
            FVector fDir = UMC->Subtract_VectorVector(targetAimPos, start);
            rot = UMC->Conv_VectorToRotator(fDir);
            return orig_shoot_event(thiz, targetAimPos, rot, weapon, unk1);
        }
    }

    return orig_shoot_event(thiz, start, rot, weapon, unk1);
}

// HMOOD__TG@i_8_f
const char *GetVehicleName(ASTExtraVehicleBase *Vehicle)
{
    if (isObjectInvalid(Vehicle)) return "Vehicle";
    switch (Vehicle->VehicleShapeType)
    {
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike_SideCart:
            return "Motorbike";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Dacia:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyDacia:
            return "Dacia";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MiniBus:
            return "Mini Bus";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyPickup:
            return "Pick Up";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Buggy:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyBuggy:
            return "Buggy";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ02:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ03:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUAZ:
            return "UAZ";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PG117:
            return "PG117";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Aquarail:
            return "Aquarail";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado01:
            return "Mirado";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Rony:
            return "Rony";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Scooter:
            return "Scooter";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowMobile:
            return "Snow Mobile";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_TukTukTuk:
            return "Tuk Tuk";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowBike:
            return "Snow Bike";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Surfboard:
            return "Surf Board";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Snowboard:
            return "Snow Board";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Amphibious:
            return "Amphibious";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_LadaNiva:
            return "Lada Niva";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAV:
            return "UAV";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MegaDrop:
            return "Mega Drop";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini01:
            return "Lamborghini";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_GoldMirado:
            return "Gold Mirado";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_BigFoot:
            return "Big Foot";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUH60:
            return "UH60";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_CoupeRB:
            return "CoupeRB";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UTV:
            return "UTV";
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_WingMan:
            return "Helicopter";
        default:
            return "Vehicle";
    }
}

// HMOOD__TG@i_8_f
void ResetGuestAccount() {
    NSFileManager *fm = [NSFileManager defaultManager];
    [fm removeItemAtPath:[NSString stringWithFormat:@"%@/Documents/ano_tmp", NSHomeDirectory()] error:nil];
    [fm removeItemAtPath:[NSString stringWithFormat:@"%@/Documents", NSHomeDirectory()] error:nil];
    [fm removeItemAtPath:[NSString stringWithFormat:@"%@/Library", NSHomeDirectory()] error:nil];
    [fm removeItemAtPath:[NSString stringWithFormat:@"%@/tmp", NSHomeDirectory()] error:nil];

    NSString *prefsPath = [NSString stringWithFormat:@"%@/Library/Preferences", NSHomeDirectory()];
    NSArray *prefsFiles = [fm contentsOfDirectoryAtPath:prefsPath error:nil];

    NSArray *bundleIdentifiersToRemove = @[
        @"tencent",
        @"ig",
        @"rekoo",
        @"vn",
        @"imobile",
        @"korean"
    ];

    for (NSString *file in prefsFiles) {
        for (NSString *bundleId in bundleIdentifiersToRemove) {
            if ([file containsString:bundleId] || [file hasSuffix:@".plist"]) {
                [fm removeItemAtPath:[prefsPath stringByAppendingPathComponent:file] error:nil];
                break;
            }
        }
    }

    dispatch_async(dispatch_get_main_queue(), ^{
        UIWindow *window = nil;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
        if (!window) window = [UIApplication sharedApplication].keyWindow;
#pragma clang diagnostic pop

        UIViewController *rootVC = window.rootViewController;
        UIAlertController *done = [UIAlertController alertControllerWithTitle:[NSString stringWithUTF8String:
            TranslateMenuText("Guest reset complete. Game will exit in 5s.")]
                                                                    message:nil
                                                             preferredStyle:UIAlertControllerStyleAlert];
        if (rootVC) {
            [rootVC presentViewController:done animated:YES completion:nil];
        }
    });

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)),
                   dispatch_get_main_queue(), ^{
        exit(0);
    });
}

// HMOOD__TG@i_8_f
static void ApplyMemoryReferenceOptions(ASTExtraPlayerCharacter* player, ASTExtraPlayerController* controller) {
    if (isObjectInvalid(player) || isObjectInvalid(controller)) return;
    struct Value { float original = 0.f; bool applied = false; };
    struct IntegerValue { int original = 0; bool applied = false; };
    using Key = std::tuple<uintptr_t, int, uintptr_t>;
    static std::map<Key, Value> floats;
    static std::map<Key, IntegerValue> integers;
    static uintptr_t previousController = 0;
    if (previousController != (uintptr_t)controller) {
        floats.clear(); integers.clear(); previousController = (uintptr_t)controller;
    }
    auto changeFloat = [&](UObject* owner, float& field, bool enabled, float value) {
        if (isObjectInvalid(owner) || !Tools::IsPtrValid(&field)) return;
        const Key key((uintptr_t)owner, owner->InternalIndex, (uintptr_t)&field);
        if (!enabled && floats.find(key) == floats.end()) return;
        auto& saved = floats[key];
        if (enabled) {
            if (!saved.applied) saved.original = field;
            field = value;
            saved.applied = true;
        } else if (saved.applied) { field = saved.original; saved.applied = false; }
    };
    auto changeInteger = [&](UObject* owner, int& field, bool enabled, int value) {
        if (isObjectInvalid(owner) || !Tools::IsPtrValid(&field)) return;
        const Key key((uintptr_t)owner, owner->InternalIndex, (uintptr_t)&field);
        if (!enabled && integers.find(key) == integers.end()) return;
        auto& saved = integers[key];
        if (enabled) {
            if (!saved.applied) saved.original = field;
            field = value;
            saved.applied = true;
        } else if (saved.applied) { field = saved.original; saved.applied = false; }
    };
    static const auto started = std::chrono::steady_clock::now();
    const float elapsed = std::chrono::duration<float>(std::chrono::steady_clock::now() - started).count();
    static float previousTime = elapsed, phase = 0.f, spinAngle = 0.f;
    const float delta = ImClamp(elapsed - previousTime, 0.f, .1f);
    previousTime = elapsed;
    if (MemoryRainbow) phase = fmodf(phase + delta * ImClamp(MemoryRainbowSpeed, .1f, 2.4f), 6.2831853f);
    if (MemoryCrossSpin) spinAngle = fmodf(spinAngle - delta * ImClamp(MemoryCrossSpinSpeed, 0.f, 180.f), 360.f);
    changeFloat(controller, controller->CrossHairColor.R, MemoryRainbow, .5f + .5f * sinf(phase));
    changeFloat(controller, controller->CrossHairColor.G, MemoryRainbow, .5f + .5f * sinf(phase + 2.094395f));
    changeFloat(controller, controller->CrossHairColor.B, MemoryRainbow, .5f + .5f * sinf(phase + 4.18879f));
    changeFloat(controller, controller->CrossHairColor.A, MemoryRainbow, 1.f);
    changeInteger(controller, controller->GameReplayType, MemoryDamage, player->bIsWeaponFiring ? 2 : 1);
    if (auto* camera = player->ScopeCameraComp; Tools::IsPtrValid(camera)) {
        float* fov = (float*)((uintptr_t)&camera->OrthoWidth - sizeof(float));
        if (Tools::IsPtrValid(fov)) {
            changeFloat(camera, *fov, MemoryZoom && player->bIsGunADS, ImClamp(MemoryZoomFov, 20.f, 90.f));
        }
    }
    auto* manager = player->WeaponManagerComponent;
    if (isObjectInvalid(manager) || isObjectInvalid(manager->CurrentWeaponReplicated) ||
        !manager->CurrentWeaponReplicated->IsA(ASTExtraShootWeapon::StaticClass())) return;
    auto* weapon = (ASTExtraShootWeapon*)manager->CurrentWeaponReplicated;
    if (auto* entity = weapon->ShootWeaponEntityComp; Tools::IsPtrValid(entity))
        changeFloat(entity, entity->WeaponAimInTime, MemoryFastScope, .01f);
    if (auto* cross = weapon->CachedCrossHairComponent; Tools::IsPtrValid(cross))
        changeFloat(cross, cross->RotateAngle, MemoryCrossSpin, spinAngle);
}

// HMOOD__TG@i_8_f
void RenderESP(AHUD *HUD, int ScreenWidth, int ScreenHeight) {
    if (isObjectInvalid(HUD)) return;

    ASTExtraPlayerCharacter *localPlayer = nullptr;
    ASTExtraPlayerController *localPlayerController = nullptr;
    screenWidth = ScreenWidth;
    screenHeight = ScreenHeight;
    glWidth = ScreenWidth;
    glHeight = ScreenHeight;

    UCanvas *Canvas = HUD->Canvas;
    if (Tools::IsPtrValid(Canvas) && IsLogin) {
        LoadFontOnce();
        if (!Tools::IsPtrValid(tslFont)) return;

        UKismetMathLibrary* UMC = (UKismetMathLibrary*)UKismetMathLibrary::StaticClass();
        UGameplayStatics *gGameplayStatics = (UGameplayStatics *)UGameplayStatics::StaticClass();
        (void)gGameplayStatics;

        auto GWorld = GetFullWorld();
        if (Tools::IsPtrValid(GWorld) && IsLogin && Tools::IsPtrValid(UMC)) {
            UNetDriver *NetDriver = GWorld->NetDriver;
            if (Tools::IsPtrValid(NetDriver)) {
                UNetConnection *ServerConnection = NetDriver->ServerConnection;
                if (Tools::IsPtrValid(ServerConnection) && !isObjectInvalid(ServerConnection->PlayerController)) {
                    localPlayerController = (ASTExtraPlayerController *)ServerConnection->PlayerController;
                }
            }

            if (!isObjectInvalid(localPlayerController)) {
                std::vector<ASTExtraPlayerCharacter *> PlayerCharacter;
                GetAllActors(PlayerCharacter);

                for (auto* Actor : PlayerCharacter) {
                    if (isObjectInvalid(Actor)) continue;
                    if (Actor->PlayerKey == localPlayerController->PlayerKey) {
                        localPlayer = Actor;
                        break;
                    }
                }

                if (!isObjectInvalid(localPlayer)) {
                    g_LocalPlayer = localPlayer;
                    g_PlayerController = localPlayerController;
                    g_LocalController = localPlayerController;

                    auto* camera = localPlayer->ThirdPersonCameraComponent;
                    static uintptr_t previousCamera = 0;
                    static float originalView = 90.f;
                    static bool viewApplied = false;
                    if (Tools::IsPtrValid(camera)) {
                        float* view = (float*)((uintptr_t)&camera->OrthoWidth - sizeof(float));
                        if (Tools::IsPtrValid(view)) {
                            if (previousCamera != (uintptr_t)camera) {
                                previousCamera = (uintptr_t)camera;
                                originalView = *view;
                                viewApplied = false;
                            }
                            if (WideView) {
                                if (!viewApplied) originalView = *view;
                                *view = (float)ImClamp(WideValue, 80, 160);
                                viewApplied = true;
                            } else if (viewApplied) {
                                *view = originalView;
                                viewApplied = false;
                            }
                        }
                    }

                    if (Blacksky) {
                        localPlayer->SetWeaponShootType(ESTEWeaponShootType::ESTEWeaponShootType__Auto);
                    }

                    if (Tools::IsPtrValid(localPlayer->MeshContainer)) {
                        if (localPlayer->bIsGunADS) {
                            localPlayer->MeshContainer->RelativeRotation = { 0, 360, 0 };
                        } else if (!localPlayer->bIsWeaponFiring) {
                            localPlayer->MeshContainer->RelativeRotation = { 0, 360, 0 };
                        } else if (isSpinning) {
                            localPlayer->MeshContainer->RelativeRotation = { 0, DanceValue, 0 };
                            DanceValue += DancerValue;
                            if (DanceValue >= 360.0f)
                                DanceValue = 0.0f;
                            DanceValue += tocdoquay;
                        }
                    }

                    if (下雨 && !isObjectInvalid(localPlayer->STPlayerController)) {
                        localPlayer->STPlayerController->SetIsRainy(true);
                    }

                    if (下雪特效 && !isObjectInvalid(localPlayer->STPlayerController)) {
                        localPlayer->STPlayerController->SetIsSnowy(true);
                    }

                    if (人物自杀 && IsLogin && !isObjectInvalid(localPlayer->STPlayerController)) {
                        localPlayer->STPlayerController->RPC_GiveUpGame();
                    }

                    if (重置游客) {
                        ResetGuestAccount();
                    }
                    if (ResetGuest) {
                        ResetGuestAccount();
                    }

                    if (人物变大 && Tools::IsPtrValid(localPlayer->MeshContainer)) {
                        localPlayer->MeshContainer->SetWorldScale3D({巨人, 巨人, 巨人});
                    }

                    if (Settings::Aimbot::Tick && !Enable) {
                        ASTExtraPlayerCharacter *Target = GetTargetByCrossDist();
                        if (!isObjectInvalid(Target) && Tools::IsPtrValid(Target->RootComponent)) {
                            bool triggerOk = IsAimTriggerActive(localPlayer);
                            if (triggerOk && Tools::IsPtrValid(localPlayerController->PlayerCameraManager)) {
                                FVector targetAimPos = ResolveAimPosition(Target, localPlayerController);
                                auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                                if (Tools::IsPtrValid(WeaponManagerComponent)) {
                                    auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                                    if ((int)propSlot.GetValue() >= 1 && (int)propSlot.GetValue() <= 3 &&
                                        !isObjectInvalid(WeaponManagerComponent->CurrentWeaponReplicated)) {
                                        auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
                                        auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                        if (Tools::IsPtrValid(ShootWeaponComponent)) {
                                            UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
                                            if (Tools::IsPtrValid(ShootWeaponEntityComponent) &&
                                                ShootWeaponEntityComponent->BulletFireSpeed > 1.f &&
                                                Settings::Aimbot::SilentAimSettings::Prediction) {
                                                ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                                                if (!isObjectInvalid(CurrentVehicle)) {
                                                    FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;
                                                    float dist = localPlayer->GetDistanceTo(Target);
                                                    auto timeToTravel = dist / ShootWeaponEntityComponent->BulletFireSpeed;
                                                    targetAimPos = UMC->Add_VectorVector(targetAimPos, UMC->Multiply_VectorFloat(LinearVelocity, timeToTravel));
                                                } else {
                                                    FVector Velocity = Target->GetVelocity();
                                                    float dist = localPlayer->GetDistanceTo(Target);
                                                    auto timeToTravel = dist / ShootWeaponEntityComponent->BulletFireSpeed;
                                                    targetAimPos = UMC->Add_VectorVector(targetAimPos, UMC->Multiply_VectorFloat(Velocity, timeToTravel));
                                                }
                                            }

                                            FVector fDir = UKismetMathLibrary::Subtract_VectorVector(
                                                targetAimPos,
                                                localPlayerController->PlayerCameraManager->CameraCache.POV.Location
                                            );

                                            FRotator Yaptr = UKismetMathLibrary::Conv_VectorToRotator(fDir);
                                            FRotator CpYaT = localPlayerController->PlayerCameraManager->CameraCache.POV.Rotation;

                                            Yaptr.Yaw = std::remainder(Yaptr.Yaw - CpYaT.Yaw, 360.f);
                                            Yaptr.Pitch -= CpYaT.Pitch;
                                            Yaptr.Roll = 0.f;

                                            const float maxStep = ImClamp(Settings::Aimbot::SilentAimSettings::MaxStepDeg, .3f, 8.f);
                                            const float smooth = ImClamp(AimSmooth, 2.f, 30.f);
                                            auto clampDelta = [](float v, float step) -> float {
                                                return v > step ? step : (v < -step ? -step : v);
                                            };
                                            localPlayer->AddControllerYawInput(clampDelta(Yaptr.Yaw / smooth, maxStep));
                                            localPlayer->AddControllerPitchInput(clampDelta(Yaptr.Pitch / smooth, maxStep));
                                        }
                                    }
                                }
                            }
                        }
                    }

                    if (IsLaunch) {
                        if ((Enable && IsLogin) || (坐标追 && IsLogin)) {
                            auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                            if (Tools::IsPtrValid(WeaponManagerComponent)) {
                                auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                                if ((int)propSlot.GetValue() >= 1 && (int)propSlot.GetValue() <= 3 &&
                                    !isObjectInvalid(WeaponManagerComponent->CurrentWeaponReplicated)) {
                                    auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
                                    auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                    if (Tools::IsPtrValid(ShootWeaponComponent)) {
                                        std::lock_guard<std::mutex> lock(g_HookMutex);
                                        int shoot_event_idx = 174;
                                        auto VTable = (void **)ShootWeaponComponent->VTable;
                                        if (!initialized) {
                                            InitializeMemoryProtection();
                                        }
                                        SafeWriteVTableSlot(VTable, shoot_event_idx, (void *)shoot_event, (void **)&orig_shoot_event);
                                    }
                                }
                            }
                        }
                        IsLaunch = false;
                    }

                    if (!localPlayer->IsUsingGrenade()) {
                        auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                        if (Tools::IsPtrValid(WeaponManagerComponent)) {
                            auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                            if ((int)propSlot.GetValue() >= 1 && (int)propSlot.GetValue() <= 3 &&
                                !isObjectInvalid(WeaponManagerComponent->CurrentWeaponReplicated)) {
                                auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
                                auto ShootWeaponEntityComp = CurrentWeaponReplicated->ShootWeaponEntityComp;
                                auto ShootWeaponEffectComp = CurrentWeaponReplicated->ShootWeaponEffectComp;

                                auto ID = CurrentWeaponReplicated->GetWeaponID();
                                if (ID != 108004 && ID != 108003 && ID != 108002 && ID != 108001 &&
                                    ID != 108000 && ID != 108005 && ID != 108006 && ID != 108007) {
                                    if (Tools::IsPtrValid(ShootWeaponEntityComp) && Tools::IsPtrValid(ShootWeaponEffectComp)) {
                                        if (IsFastSwitch) {
                                            ShootWeaponEntityComp->SwitchFromBackpackToIdleTime = 0.0f;
                                            ShootWeaponEntityComp->SwitchFromIdleToBackpackTime = 0.0f;
                                        }

                                        if (IsCrossHair) {
                                            memset(&ShootWeaponEntityComp->DeviationInfo, 0, sizeof(FSDeviation));
                                            ShootWeaponEntityComp->ShotGunCenterPerc = 0.0f;
                                            ShootWeaponEntityComp->ShotGunVerticalSpread = 0.0f;
                                            ShootWeaponEntityComp->ShotGunHorizontalSpread = 0.0f;
                                            ShootWeaponEntityComp->GameDeviationFactor = 0.0f;
                                            ShootWeaponEntityComp->GameDeviationAccuracy = 0.0f;
                                            ShootWeaponEntityComp->CrossHairInitialSize = 0.0f;
                                            ShootWeaponEntityComp->CrossHairBurstSpeed = 0.0f;
                                            ShootWeaponEntityComp->CrossHairBurstIncreaseSpeed = 0.0f;
                                            ShootWeaponEntityComp->VehicleWeaponDeviationAngle = 0.0f;
                                        }

                                        if (IsFastshoot) {
                                            ShootWeaponEntityComp->ShootInterval = 0.02f;
                                        }

                                        if (IsNocamerashake) {
                                            ShootWeaponEffectComp->CameraShakeInnerRadius = 0.0f;
                                            ShootWeaponEffectComp->CameraShakeOuterRadius = 0.0f;
                                            ShootWeaponEffectComp->CameraShakFalloff = 0.0f;
                                            ShootWeaponEntityComp->AnimationKick = 0;
                                        }

                                        if (IsNorecoil2) {
                                            ShootWeaponEntityComp->RecoilKickADS = 0.0f;
                                        }

                                        if (HitX) {
                                            ShootWeaponEntityComp->ExtraHitPerformScale = 100;
                                            ShootWeaponEntityComp->HUDAlphaDecreaseSpeedScale = 1.f;
                                        }

                                        if (ReCo && IsLogin) {
                                            ShootWeaponEntityComp->AccessoriesVRecoilFactor = 0.0f;
                                            ShootWeaponEntityComp->AccessoriesHRecoilFactor = 0.0f;
                                            ShootWeaponEntityComp->AccessoriesRecoveryFactor = 0.0f;
                                        }

                                        if (IsCrossHair) {
                                            static float cnt = 0.0f;
                                            if (cnt >= FLT_MAX) {
                                                cnt = 0.0f;
                                            } else {
                                                cnt += 0.01f;
                                            }

                                            memset(&ShootWeaponEntityComp->DeviationInfo, 0, sizeof(FSDeviation));
                                            ShootWeaponEntityComp->ShotGunCenterPerc = 0.0f;
                                            ShootWeaponEntityComp->ShotGunVerticalSpread = 0.0f;
                                            ShootWeaponEntityComp->ShotGunHorizontalSpread = 0.0f;
                                            ShootWeaponEntityComp->GameDeviationFactor = 0.0f;
                                            ShootWeaponEntityComp->GameDeviationAccuracy = 0.0f;
                                            ShootWeaponEntityComp->CrossHairInitialSize = crosshairSizeSlider;
                                            ShootWeaponEntityComp->CrossHairBurstSpeed = crosshairSizeSlider;
                                            ShootWeaponEntityComp->CrossHairBurstIncreaseSpeed = crosshairSizeSlider;
                                            ShootWeaponEntityComp->VehicleWeaponDeviationAngle = 0.0f;
                                        }

                                        if (IsHitXPL) {
                                            ShootWeaponEntityComp->ExtraHitPerformScale = 300;
                                            ShootWeaponEntityComp->HUDAlphaDecreaseSpeedScale = 5.1f;
                                        }

                                        if (CarFly && !isObjectInvalid(localPlayer->CurrentVehicle)) {
                                            static float CurrentHeight = 0.0f;
                                            auto CurrentVehicle = localPlayer->CurrentVehicle;
                                            auto RootComponent = static_cast<UPrimitiveComponent*>(CurrentVehicle->K2_GetRootComponent());
                                            if (Tools::IsPtrValid(RootComponent) && CurrentVehicle->GetMoveForwardRate() > 0) {
                                                FVector Velocity{};
                                                if (CurrentHeight < 70000.f) {
                                                    Velocity.X = carx;
                                                    Velocity.Y = cary;
                                                    Velocity.Z = carz;
                                                    CurrentHeight += Velocity.Z;
                                                    RootComponent->SetAllPhysicsLinearVelocity(Velocity, true);
                                                } else {
                                                    Velocity.Z = 0.f;
                                                    RootComponent->SetAllPhysicsLinearVelocity(Velocity, true);
                                                }
                                            }
                                        }

                                        if (chaynhanhv2 && Tools::IsPtrValid(localPlayer->CharacterMovement)) {
                                            localPlayer->CharacterMovement->GravityScale = -15.f;
                                            localPlayer->CharacterMovement->JumpZVelocity = 10.f;
                                            localPlayer->CharacterMovement->JumpOffJumpZFactor = 10.f;
                                        }

                                        if (tudongnhay) {
                                            localPlayer->Jump();
                                        }

                                        if (IsFastDrop && Tools::IsPtrValid(localPlayer->ParachuteComponent)) {
                                            localPlayer->ParachuteComponent->CurrentFallSpeed = 8300.f;
                                            localPlayer->ParachuteComponent->FreeFall_AcceFall = 25000.f;
                                            localPlayer->ParachuteComponent->FreeFall_MaxFreeFallSpeed = 25000.f;
                                            localPlayer->ParachuteComponent->FreeFall_AcceForward = 25000.f;
                                            localPlayer->ParachuteComponent->FreeFall_MaxForwardExtraFallSpeed = 25000.f;

                                            localPlayer->ParachuteComponent->Opened_AcceFall = 5000.f;
                                            localPlayer->ParachuteComponent->Opened_MaxFreeFallSpeed = 5000.f;
                                            localPlayer->ParachuteComponent->Opened_AcceForward = 5000.f;
                                            localPlayer->ParachuteComponent->Opened_MaxForwardSpeed = 5000.f;
                                            localPlayer->ParachuteComponent->Opened_MaxForwardExtraFallSpeed = 5000.f;

                                            localPlayer->ParachuteComponent->AllowMaxDiatanceSqAtServer = 40000.f;
                                            localPlayer->ParachuteComponent->MaxZAllowDistance = 40000.f;
                                        }

                                        if (据点) {
                                            static float cnt = 0.0f;
                                            if (cnt >= FLT_MAX) {
                                                cnt = 0.0f;
                                            } else {
                                                cnt += 0.01f;
                                            }

                                            memset(&ShootWeaponEntityComp->DeviationInfo, 0, sizeof(FSDeviation));
                                            memset(&ShootWeaponEntityComp->RecoilInfo, 0, sizeof(FSRecoilInfo));

                                            ShootWeaponEntityComp->ShotGunCenterPerc = 0.0f;
                                            ShootWeaponEntityComp->ShotGunVerticalSpread = 0.0f;
                                            ShootWeaponEntityComp->ShotGunHorizontalSpread = 0.0f;
                                            ShootWeaponEntityComp->GameDeviationFactor = 0.0f;
                                            ShootWeaponEntityComp->GameDeviationAccuracy = 0.0f;
                                            ShootWeaponEntityComp->CrossHairInitialSize = 0.0f;
                                            ShootWeaponEntityComp->CrossHairBurstSpeed = 0.0f;
                                            ShootWeaponEntityComp->CrossHairBurstIncreaseSpeed = 0.0f;
                                            ShootWeaponEntityComp->VehicleWeaponDeviationAngle = 0.0f;
                                        }
                                    }
                                }
                            }
                        }
                    }

                    if (枪械变大) {
                        auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                        if (Tools::IsPtrValid(WeaponManagerComponent)) {
                            auto Slot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                            if ((int)Slot.GetValue() >= 1 && (int)Slot.GetValue() <= 3 &&
                                !isObjectInvalid(WeaponManagerComponent->CurrentWeaponReplicated)) {
                                auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
                                if (Tools::IsPtrValid(CurrentWeaponReplicated->RootComponent)) {
                                    CurrentWeaponReplicated->RootComponent->RelativeScale3D.Y = Gun_Size;
                                    CurrentWeaponReplicated->RootComponent->RelativeScale3D.Z = Gun_Size;
                                    CurrentWeaponReplicated->RootComponent->RelativeScale3D.X = Gun_Size;
                                }
                            }
                        }
                    }

                    int totalEnemies = 0, totalBots = 0;
                    for (auto* Player : PlayerCharacter) {
                        if (isObjectInvalid(Player)) continue;
                        if (Player->PlayerKey == localPlayer->PlayerKey) continue;
                        if (Player->TeamID == localPlayer->TeamID) continue;
                        if (Player->bDead || Player->bHidden || !Tools::IsPtrValid(Player->RootComponent)) continue;

                        if (Config.ESPMenu.IgnoreBot && IsLogin) {
                            if (Player->bEnsure) continue;
                        }

                        if (Player->bEnsure)
                            totalBots++;
                        else
                            totalEnemies++;

                        玩家 = totalEnemies;
                        人机 = totalBots;

                        if (hideNameKillMsg) {
                            std::lock_guard<std::mutex> lock(g_HookMutex);
                            int its = 1002;
                            auto VTable = (void**)localPlayerController->VTable;
                            SafeWriteVTableSlot(VTable, its, (void *)hk_Broadcast, (void **)&orig_Broadcast);
                        }

                        FVector Head = GetBoneLocationByName(Player, "Head");
                        Head.Z += 12.5f;
                        FVector Root = GetBoneLocationByName(Player, "Root");
                        (void)Root;

                        float Distance = Player->GetDistanceTo(localPlayer) / 100.f;
                        bool IsVisible = localPlayerController->LineOfSightTo(Player, {0,0,0}, true);

                        if (IsVisible) {
                            if (Player->bEnsure) {
                                visCol.R = 0.f; visCol.G = 0.5f; visCol.B = 0.f; visCol.A = 1.f;
                            } else if (Player->Health == 0.0f) {
                                visCol.R = 0.0f; visCol.G = 0.3f; visCol.B = 0.0f; visCol.A = 1.0f;
                            } else {
                                visCol.R = 0.f; visCol.G = 0.5f; visCol.B = 0.f; visCol.A = 1.f;
                            }
                        } else if (Player->bEnsure) {
                            visCol.R = 1.f; visCol.G = 0.f; visCol.B = 0.f; visCol.A = 1.f;
                        } else if (Player->Health == 0.0f) {
                            visCol.R = 0.549019607f; visCol.G = 0.039215686f; visCol.B = 0.050980392f; visCol.A = 1.0f;
                        } else {
                            visCol.R = 1.f; visCol.G = 0.f; visCol.B = 0.f; visCol.A = 1.f;
                        }

                        if (Player->IsInvincible) {
                            visCol.R = 1.f; visCol.G = 1.f; visCol.B = 0.f; visCol.A = 1.f;
                        }

                        if (Distance < 500.f) {
                            if (Radar == 1 && IsLogin && Tools::IsPtrValid(localPlayerController->PlayerCameraManager) &&
                                Tools::IsPtrValid(localPlayer->RootComponent)) {
                                bool out = false;
                                struct Vector3 Pos;
                                Pos.X = (RadarX * 10);
                                Pos.Y = (RadarY * 13);
                                struct Vector3 Size;
                                Size.X = 210;
                                Size.Y = 200;
                                float RadarCenterX = Pos.X + (Size.X / 2);
                                float RadarCenterY = Pos.Y + (Size.Y / 2);

                                FVector MyPosition, EnemyPosition;
                                ASTExtraVehicleBase *CurrentVehiclea = Player->CurrentVehicle;
                                if (!isObjectInvalid(CurrentVehiclea) && Tools::IsPtrValid(CurrentVehiclea->RootComponent)) {
                                    MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
                                } else {
                                    MyPosition = Player->RootComponent->RelativeLocation;
                                }
                                ASTExtraVehicleBase *CurrentVehicle = localPlayer->CurrentVehicle;
                                if (!isObjectInvalid(CurrentVehicle) && Tools::IsPtrValid(CurrentVehicle->RootComponent)) {
                                    EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
                                } else {
                                    EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                                }

                                FVector RadarSketch = WorldToRadar(
                                    localPlayerController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw,
                                    MyPosition, EnemyPosition, Pos.X, Pos.Y,
                                    Vector3(Size.X, Size.Y, 0), out
                                );

                                DrawCircle(HUD, RadarCenterX + 0.5f, RadarCenterY + 0.5f, 100.0f, 100.0f, COLOR_WHITE);
                                DrawFilledRectangle(HUD, FVector2D{RadarCenterX + 0.5f, RadarCenterY + 0.5f}, 5, 5, COLOR_YELLOW);
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, Head, true)) {
                                    DrawFilledRectangle(HUD, FVector2D{RadarSketch.X, RadarSketch.Y}, 5, 5, COLOR_BLUE);
                                } else {
                                    DrawFilledRectangle(HUD, FVector2D{RadarSketch.X, RadarSketch.Y}, 5, 5, COLOR_RED);
                                }
                            }

                            if (Radar == 2 && IsLogin && Tools::IsPtrValid(localPlayerController->PlayerCameraManager) &&
                                Tools::IsPtrValid(Player->RootComponent)) {
                                float lateralAngleView = (localPlayerController->ControlRotation.Yaw) - 90;
                                FVector selfcoord = localPlayerController->PlayerCameraManager->CameraCache.POV.Location;
                                FVector Objectcoord = Player->RootComponent->RelativeLocation;

                                int Ev = 200;
                                FVector2D radar = rotateCoord(lateralAngleView, FVector2D((selfcoord.X - Objectcoord.X) / Ev, (selfcoord.Y - Objectcoord.Y) / Ev));

                                FVector2D 雷达位置 = {500, 200};
                                float 雷达大小 = 55;
                                Canvas->K2_DrawLine({(float)雷达位置.X - (225 * 雷达大小 / 100), (float)雷达位置.Y}, {(float)雷达位置.X + (225 * 雷达大小 / 100), (float)雷达位置.Y}, 1, FLinearColor(1.f,1.f,1.f,1.f));
                                Canvas->K2_DrawLine({(float)雷达位置.X, (float)雷达位置.Y - (225 * 雷达大小 / 100)}, {(float)雷达位置.X, (float)雷达位置.Y + (225 * 雷达大小 / 100)}, 1, FLinearColor(1.f,1.f,1.f,1.f));
                                Canvas->K2_DrawLine({(float)雷达位置.X - (225 * 雷达大小 / 100), (float)雷达位置.Y - (225 * 雷达大小 / 100)}, {(float)雷达位置.X - (225 * 雷达大小 / 100), (float)雷达位置.Y + (225 * 雷达大小 / 100)}, 1, FLinearColor(1.f,1.f,1.f,1.f));
                                Canvas->K2_DrawLine({(float)雷达位置.X + (225 * 雷达大小 / 100), (float)雷达位置.Y - (225 * 雷达大小 / 100)}, {(float)雷达位置.X + (225 * 雷达大小 / 100), (float)雷达位置.Y + (225 * 雷达大小 / 100)}, 1, FLinearColor(1.f,1.f,1.f,1.f));
                                Canvas->K2_DrawLine({(float)雷达位置.X - (225 * 雷达大小 / 100), (float)雷达位置.Y - (225 * 雷达大小 / 100)}, {(float)雷达位置.X + (225 * 雷达大小 / 100), (float)雷达位置.Y - (225 * 雷达大小 / 100)}, 1, FLinearColor(1.f,1.f,1.f,1.f));
                                Canvas->K2_DrawLine({(float)雷达位置.X - (225 * 雷达大小 / 100), (float)雷达位置.Y + (225 * 雷达大小 / 100)}, {(float)雷达位置.X + (225 * 雷达大小 / 100), (float)雷达位置.Y + (225 * 雷达大小 / 100)}, 1, FLinearColor(1.f,1.f,1.f,1.f));

                                DrawCircle(Canvas, (float)雷达位置.X + radar.X * (雷达大小 / 100), (float)雷达位置.Y + radar.Y * (雷达大小 / 100), 2, 50, FLinearColor(1.0f,0.0f,0.0f,1.0f));
                            }
                        }
                    }
                }
            }
        }
    }

    g_LocalPlayer = localPlayer;
    g_PlayerController = localPlayerController;
    g_LocalController = localPlayerController;
    ApplyMemoryReferenceOptions(localPlayer, localPlayerController);
    UpdateAutoFire(localPlayer, localPlayerController);
    CaptureWorldEsp(localPlayer, localPlayerController);
}

void *(*oProcessEvent)(UObject *pObj, UFunction *pFunc, void *pArgs) = nullptr;

// HMOOD__TG@i_8_f
void *hkProcessEvent(UObject *pObj, UFunction *pFunc, void *pArgs) {
    if (!isObjectInvalid(pObj) && !isObjectInvalid(pFunc) && Tools::IsPtrValid(pArgs)) {
        if (pObj->IsA(AHUD::StaticClass()) && pFunc->GetFullName() == "Function Engine.HUD.ReceiveDrawHUD") {
            AHUD *pHUD = (AHUD *)pObj;
            auto Params = (AHUD_ReceiveDrawHUD_Params *)pArgs;
            if (!isObjectInvalid(pHUD) && Tools::IsPtrValid(Params)) {
                RenderESP(pHUD, Params->SizeX, Params->SizeY);
                screenWidth = Params->SizeX;
                screenHeight = Params->SizeY;
            }
        }
    }
    if (Tools::IsPtrValid((void *)oProcessEvent)) {
        return oProcessEvent(pObj, pFunc, pArgs);
    }
    return nullptr;
}

// HMOOD__TG@i_8_f
void *RTL_language(){
    std::lock_guard<std::mutex> lock(g_HookMutex);
    long baseAddr = obbbbl();
    if (!baseAddr) return nullptr;
    auto MAIN = (FUObjectArray *)(baseAddr);
    if (!Tools::IsPtrValid(MAIN)) return nullptr;
    auto *objArray = &MAIN->ObjObjects;
    if (!Tools::IsPtrValid(objArray)) return nullptr;

    int count = objArray->Num();
    if (count <= 0 || count > 5000000) return nullptr;

    int its = 76;
    for (int i = 0; i < count; i++) {
        UObject *obj = objArray->GetByIndex(i);
        if (!isObjectInvalid(obj) && obj->IsA(AHUD::StaticClass())) {
            auto HUD = (AHUD *)obj;
            auto VTable = (void**)HUD->VTable;
            if (SafeWriteVTableSlot(VTable, its, (void *)hkProcessEvent, (void **)&oProcessEvent)) {
                g_RtlHooked.store(true, std::memory_order_release);
            }
        }
    }
    return nullptr;
}

// HMOOD__TG@i_8_f
+ (void)load
{
    std::call_once(g_InitOnceFlag, ^{
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)),
                       dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
            for (int attempt = 0; attempt < 30 && !Tools::IsPtrValid(FName::GNames); attempt++) {
                FName::GNames = GetGNames();
                if (!Tools::IsPtrValid(FName::GNames)) sleep(1);
            }

            for (int attempt = 0; attempt < 30 && !Tools::IsPtrValid(UObject::GUObjectArray); attempt++) {
                long objArrayAddr = obbbbl();
                if (objArrayAddr && Tools::IsPtrValid((void *)objArrayAddr)) {
                    UObject::GUObjectArray = (FUObjectArray *)(objArrayAddr);
                }
                if (!Tools::IsPtrValid(UObject::GUObjectArray)) sleep(1);
            }

            iosde = (UGameplayStatics*)UGameplayStatics::StaticClass();

            dispatch_async(dispatch_get_main_queue(), ^{
                [self load1];
            });
        });
    });
}

// HMOOD__TG@i_8_f
+ (void)load1
{
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)),
                   dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
        RTL_language();
    });
}

@end
