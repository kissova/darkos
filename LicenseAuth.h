#import <Foundation/Foundation.h>

#ifdef __cplusplus
extern "C" {
#endif

extern bool g_DarkosLicenseVerified;

void DarkosVerifyLicenseKey(NSString *licenseKey,
                            void (^completion)(BOOL ok, NSString *message, NSInteger remainingDays));
void DarkosClearSavedLicense(void);
NSString *DarkosGetSavedLicenseKey(void);

#ifdef __cplusplus
}
#endif

@interface DarkosLicenseAuth : NSObject
@property (nonatomic, assign) BOOL isAuthenticated;
@property (nonatomic, copy) NSString *lastMessage;
@property (nonatomic, assign) NSInteger remainingDays;

+ (instancetype)sharedManager;
- (BOOL)verifyLicenseKey:(NSString *)key errorMessage:(NSString **)errorMessage;
- (void)clearSavedLicense;
- (NSString *)savedLicenseKey;
@end
