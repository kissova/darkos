#import "DarkosLicenseAuth.h"

static NSString * const kDarkosAuthKeyDefaults = @"DarkosSavedLicenseKey";

@interface DarkosLicenseAuth ()
@property (nonatomic, assign, readwrite) BOOL isAuthenticated;
@property (nonatomic, copy, nullable, readwrite) NSString *activeKey;
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
