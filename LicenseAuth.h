#import <Foundation/Foundation.h>

#ifdef __cplusplus
extern "C" {
#endif

extern bool g_DarkosLicenseVerified;

void DarkosVerifyLicenseKey(NSString *licenseKey,
                             void (^completion)(BOOL ok, NSString *message, NSInteger remainingSeconds));
void DarkosClearSavedLicense(void);
NSString *DarkosGetSavedLicenseKey(void);

#ifdef __cplusplus
}
#endif
