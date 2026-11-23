#import "LicenseAuth.h"
#include "imgui.h"
#include <cstring>

static NSString * const kDarkosAuthKeyDefaults = @"DarkosSavedLicenseKey";

@interface DarkosLicenseAuth ()
@property (nonatomic, assign, readwrite) BOOL isAuthenticated;
@property (nonatomic, copy, nullable, readwrite) NSString *activeKey;
@property (nonatomic, copy, nullable, readwrite) NSString *lastErrorMessage;
@end

@implementation DarkosLicenseAuth

+ (instancetype)sharedManager {
    static DarkosLicenseAuth *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[self alloc] init];
        NSString *saved = [[NSUserDefaults standardUserDefaults] stringForKey:kDarkosAuthKeyDefaults];
        NSString *trimmed = [saved stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
        if (trimmed.length > 0) {
            instance.activeKey = trimmed;
            instance.isAuthenticated = YES;
        }
    });
    return instance;
}

+ (BOOL)isAuthenticated {
    return [self sharedManager].isAuthenticated;
}

+ (void)renderLoginWindow:(bool *)isLogin {
    DarkosLicenseAuth *mgr = [self sharedManager];
    if (mgr.isAuthenticated) {
        if (isLogin) {
            *isLogin = true;
        }
        return;
    }

    static char keyBuf[128] = {0};

    ImGui::SetNextWindowSize(ImVec2(340.f, 185.f), ImGuiCond_FirstUseEver);
    ImGui::Begin("License Login", nullptr, ImGuiWindowFlags_NoCollapse);

    ImGui::TextUnformatted("Enter License Key:");
    ImGui::InputText("##LicenseKeyInput", keyBuf, sizeof(keyBuf));

    if (mgr.lastErrorMessage.length > 0) {
        ImGui::TextColored(ImVec4(0.95f, 0.25f, 0.35f, 1.f), "%s", mgr.lastErrorMessage.UTF8String);
    }

    ImGui::Spacing();
    if (ImGui::Button("Activate", ImVec2(-1.f, 32.f))) {
        NSString *inputKey = [NSString stringWithUTF8String:keyBuf] ?: @"";
        NSString *err = nil;
        BOOL ok = [mgr verifyLicenseKey:inputKey errorMessage:&err];
        mgr.lastErrorMessage = err;
        if (ok) {
            std::memset(keyBuf, 0, sizeof(keyBuf));
            if (isLogin) {
                *isLogin = true;
            }
        }
    }

    ImGui::End();
}

- (BOOL)verifyLicenseKey:(NSString *)licenseKey errorMessage:(NSString * _Nullable * _Nullable)errorMessage {
    NSString *trimmed = [licenseKey stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    if (trimmed.length == 0) {
        self.isAuthenticated = NO;
        self.activeKey = nil;
        if (errorMessage) {
            *errorMessage = @"License key cannot be empty.";
        }
        return NO;
    }

    self.activeKey = trimmed;
    self.isAuthenticated = YES;
    [[NSUserDefaults standardUserDefaults] setObject:trimmed forKey:kDarkosAuthKeyDefaults];
    [[NSUserDefaults standardUserDefaults] synchronize];
    if (errorMessage) {
        *errorMessage = nil;
    }
    return YES;
}

- (void)logout {
    self.isAuthenticated = NO;
    self.activeKey = nil;
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:kDarkosAuthKeyDefaults];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

@end
