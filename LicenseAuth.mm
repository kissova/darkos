#import "LicenseAuth.h"
#import <UIKit/UIKit.h>

bool g_DarkosLicenseVerified = false;

namespace {
    // Öz backend.php ünvanını buraya yaz (HTTPS olmalıdır)
    static NSString *const kDarkosBackendURL = @"https://darkos-yr3o.onrender.com/backend.php";
    static NSString *const kSavedKeyDefaults = @"darkos_saved_license_key";
    static NSString *const kDeviceIdDefaults = @"darkos_ios_device_id";

    static NSString *DarkosDeviceIdentifier(void) {
        NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
        NSString *savedId = [defaults stringForKey:kDeviceIdDefaults];
        if (savedId.length > 0) {
            return savedId;
        }

        NSString *vendorId = [UIDevice currentDevice].identifierForVendor.UUIDString;
        NSString *chosen = vendorId.length > 0 ? vendorId : [[NSUUID UUID] UUIDString];
        [defaults setObject:chosen forKey:kDeviceIdDefaults];
        [defaults synchronize];
        return chosen;
    }
}

NSString *DarkosGetSavedLicenseKey(void) {
    NSString *key = [[NSUserDefaults standardUserDefaults] stringForKey:kSavedKeyDefaults];
    return key ?: @"";
}

void DarkosClearSavedLicense(void) {
    g_DarkosLicenseVerified = false;
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:kSavedKeyDefaults];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

void DarkosVerifyLicenseKey(NSString *licenseKey,
                             void (^completion)(BOOL ok, NSString *message, NSInteger remainingSeconds)) {
    NSString *trimmed = [licenseKey stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    if (trimmed.length == 0) {
        g_DarkosLicenseVerified = false;
        if (completion) {
            dispatch_async(dispatch_get_main_queue(), ^{
                completion(NO, @"Açar boş ola bilməz.", 0);
            });
        }
        return;
    }

    NSURL *url = [NSURL URLWithString:kDarkosBackendURL];
    if (!url) {
        g_DarkosLicenseVerified = false;
        if (completion) {
            dispatch_async(dispatch_get_main_queue(), ^{
                completion(NO, @"Backend URL yanlışdır.", 0);
            });
        }
        return;
    }

    NSDictionary *payload = @{
        @"action": @"player_login",
        @"key": trimmed,
        @"device_id": DarkosDeviceIdentifier()
    };

    NSError *jsonError = nil;
    NSData *bodyData = [NSJSONSerialization dataWithJSONObject:payload options:0 error:&jsonError];
    if (jsonError || !bodyData) {
        g_DarkosLicenseVerified = false;
        if (completion) {
            dispatch_async(dispatch_get_main_queue(), ^{
                completion(NO, @"Sorğu məlumatı hazırlana bilmədi.", 0);
            });
        }
        return;
    }

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url
                                                           cachePolicy:NSURLRequestReloadIgnoringLocalCacheData
                                                       timeoutInterval:12.0];
    request.HTTPMethod = @"POST";
    request.HTTPBody = bodyData;
    [request setValue:@"application/json; charset=utf-8" forHTTPHeaderField:@"Content-Type"];
    [request setValue:@"application/json" forHTTPHeaderField:@"Accept"];

    NSURLSessionDataTask *task = [[NSURLSession sharedSession] dataTaskWithRequest:request
                                                                completionHandler:^(NSData * _Nullable data,
                                                                                    NSURLResponse * _Nullable response,
                                                                                    NSError * _Nullable error) {
        if (error || !data) {
            g_DarkosLicenseVerified = false;
            dispatch_async(dispatch_get_main_queue(), ^{
                if (completion) completion(NO, @"Serverlə əlaqə alınmadı.", 0);
            });
            return;
        }

        NSError *parseError = nil;
        id jsonObj = [NSJSONSerialization JSONObjectWithData:data options:0 error:&parseError];
        if (parseError || ![jsonObj isKindOfClass:[NSDictionary class]]) {
            g_DarkosLicenseVerified = false;
            dispatch_async(dispatch_get_main_queue(), ^{
                if (completion) completion(NO, @"Server cavabı oxuna bilmədi.", 0);
            });
            return;
        }

        NSDictionary *dict = (NSDictionary *)jsonObj;
        BOOL success = [dict[@"success"] boolValue];
        NSString *msg = [dict[@"message"] isKindOfClass:[NSString class]] ? dict[@"message"] : (success ? @"Login successful" : @"Giriş rədd edildi");
        NSInteger rem = [dict[@"remaining_seconds"] respondsToSelector:@selector(integerValue)] ? [dict[@"remaining_seconds"] integerValue] : 0;

        if (success) {
            g_DarkosLicenseVerified = true;
            [[NSUserDefaults standardUserDefaults] setObject:trimmed forKey:kSavedKeyDefaults];
            [[NSUserDefaults standardUserDefaults] synchronize];
        } else {
            g_DarkosLicenseVerified = false;
        }

        dispatch_async(dispatch_get_main_queue(), ^{
            if (completion) completion(success, msg, rem);
        });
    }];

    [task resume];
}
