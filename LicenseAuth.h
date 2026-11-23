#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DarkosLicenseAuth : NSObject

@property (nonatomic, assign, readonly) BOOL isAuthenticated;
@property (nonatomic, copy, nullable, readonly) NSString *activeKey;

+ (instancetype)sharedManager;
+ (BOOL)isAuthenticated;
+ (void)renderLoginWindow:(bool *)isLogin;

- (BOOL)verifyLicenseKey:(NSString *)licenseKey errorMessage:(NSString * _Nullable * _Nullable)errorMessage;
- (void)logout;

@end

NS_ASSUME_NONNULL_END
