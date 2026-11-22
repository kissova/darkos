#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import <sys/utsname.h>

static NSString *const kDarkIOSBackendURL = @"https://darkos-yr3o.onrender.com/backend.php";

@interface DarkIOSLoginViewController : UIViewController <WKNavigationDelegate, WKScriptMessageHandler>

@property(nonatomic, strong) WKWebView *webView;
@property(nonatomic, copy) void (^onLoginSuccess)(NSInteger remainingSeconds, NSString *licenseKey);

+ (void)presentOverTopControllerWithKeyURL:(NSURL *)unused completion:(void (^)(NSInteger remainingSeconds, NSString *licenseKey))completion;

@end

@implementation DarkIOSLoginViewController

+ (UIViewController *)darkios_topViewController {
    UIViewController *top = nil;
    for (UIWindowScene *scene in [UIApplication sharedApplication].connectedScenes) {
        if (scene.activationState == UISceneActivationStateForegroundActive) {
            for (UIWindow *win in scene.windows) {
                if (win.isKeyWindow) {
                    top = win.rootViewController;
                    break;
                }
            }
        }
        if (top) break;
    }
    while (top.presentedViewController) {
        top = top.presentedViewController;
    }
    return top;
}

+ (void)presentOverTopControllerWithKeyURL:(NSURL *)unused completion:(void (^)(NSInteger remainingSeconds, NSString *licenseKey))completion {
    dispatch_async(dispatch_get_main_queue(), ^{
        UIViewController *host = [self darkios_topViewController];
        if (!host) return;
        DarkIOSLoginViewController *vc = [[DarkIOSLoginViewController alloc] init];
        vc.modalPresentationStyle = UIModalPresentationFullScreen;
        vc.onLoginSuccess = completion;
        [host presentViewController:vc animated:YES completion:nil];
    });
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskLandscape;
}

- (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation {
    return UIInterfaceOrientationLandscapeRight;
}

- (BOOL)shouldAutorotate {
    return YES;
}

- (NSString *)darkios_deviceId {
    NSString *idfv = [UIDevice currentDevice].identifierForVendor.UUIDString;
    return idfv.length > 0 ? idfv : @"IOS-UNKNOWN-ID";
}

- (NSString *)darkios_deviceName {
    struct utsname sysinfo;
    uname(&sysinfo);
    NSString *machine = [NSString stringWithCString:sysinfo.machine encoding:NSUTF8StringEncoding];
    NSString *name = [UIDevice currentDevice].name ?: @"iPhone";
    return [NSString stringWithFormat:@"%@ (%@)", name, machine];
}

- (NSString *)darkios_batteryString {
    [UIDevice currentDevice].batteryMonitoringEnabled = YES;
    float lvl = [UIDevice currentDevice].batteryLevel;
    if (lvl < 0) return @"—";
    return [NSString stringWithFormat:@"%d%%", (int)roundf(lvl * 100.0f)];
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = UIColor.blackColor;

    WKWebViewConfiguration *configuration = [[WKWebViewConfiguration alloc] init];
    [configuration.userContentController addScriptMessageHandler:self name:@"darkiosAuth"];

    self.webView = [[WKWebView alloc] initWithFrame:CGRectZero configuration:configuration];
    self.webView.translatesAutoresizingMaskIntoConstraints = NO;
    self.webView.navigationDelegate = self;
    self.webView.backgroundColor = UIColor.blackColor;
    self.webView.opaque = NO;
    self.webView.scrollView.scrollEnabled = NO;
    self.webView.scrollView.bounces = NO;

    [self.view addSubview:self.webView];

    [NSLayoutConstraint activateConstraints:@[
        [self.webView.topAnchor constraintEqualToAnchor:self.view.topAnchor],
        [self.webView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor],
        [self.webView.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor],
        [self.webView.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor]
    ]];

    NSURL *htmlURL = [[NSBundle mainBundle] URLForResource:@"game-login" withExtension:@"html"];
    if (htmlURL) {
        [self.webView loadFileURL:htmlURL allowingReadAccessToURL:htmlURL.URLByDeletingLastPathComponent];
    } else {
        NSLog(@"DARKIOS: game-login.html not found in app bundle.");
    }
}

- (void)userContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message {
    if (![message.name isEqualToString:@"darkiosAuth"]) return;
    NSDictionary *body = [message.body isKindOfClass:[NSDictionary class]] ? message.body : @{};
    NSString *type = body[@"type"] ?: @"";

    if ([type isEqualToString:@"verify_key"]) {
        NSString *key = [body[@"key"] isKindOfClass:[NSString class]] ? [body[@"key"] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] : @"";
        if (key.length == 0) {
            [self darkios_sendResultToJS:@{@"success": @NO, @"message": @"Key daxil et."}];
            return;
        }
        [self darkios_verifyKeyWithBackend:key];
    }
}

- (void)darkios_verifyKeyWithBackend:(NSString *)key {
    NSURL *url = [NSURL URLWithString:kDarkIOSBackendURL];
    NSMutableURLRequest *req = [NSMutableURLRequest requestWithURL:url];
    req.HTTPMethod = @"POST";
    req.timeoutInterval = 12.0;
    [req setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];

    NSDictionary *payload = @{
        @"action": @"player_login",
        @"key": key,
        @"device_id": [self darkios_deviceId],
        @"device_name": [self darkios_deviceName],
        @"battery": [self darkios_batteryString],
        @"location": @"AZ"
    };

    NSError *err = nil;
    req.HTTPBody = [NSJSONSerialization dataWithJSONObject:payload options:0 error:&err];
    if (err) {
        [self darkios_sendResultToJS:@{@"success": @NO, @"message": @"Sorğu hazırlanmadı."}];
        return;
    }

    NSURLSessionDataTask *task = [[NSURLSession sharedSession] dataTaskWithRequest:req completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if (error || !data) {
                [self darkios_sendResultToJS:@{@"success": @NO, @"message": @"Serverə qoşulmaq olmadı."}];
                return;
            }
            NSDictionary *json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
            BOOL ok = [json[@"success"] boolValue];
            NSString *msg = [json[@"message"] isKindOfClass:[NSString class]] ? json[@"message"] : (ok ? @"Giriş uğurludur" : @"Key səhvdir");
            NSInteger rem = [json[@"remaining_seconds"] integerValue];

            [self darkios_sendResultToJS:@{
                @"success": @(ok),
                @"message": msg,
                @"remaining_seconds": @(rem)
            }];

            if (ok) {
                void (^cb)(NSInteger, NSString *) = self.onLoginSuccess;
                [self dismissViewControllerAnimated:YES completion:^{
                    if (cb) cb(rem, key);
                }];
            }
        });
    }];
    [task resume];
}

- (void)darkios_sendResultToJS:(NSDictionary *)dict {
    NSData *d = [NSJSONSerialization dataWithJSONObject:dict options:0 error:nil];
    NSString *jsonStr = [[NSString alloc] initWithData:d encoding:NSUTF8StringEncoding] ?: @"{}";
    NSString *js = [NSString stringWithFormat:@"window.onDarkIOSAuthResult && window.onDarkIOSAuthResult(%@);", jsonStr];
    [self.webView evaluateJavaScript:js completionHandler:nil];
}

- (void)webView:(WKWebView *)webView
decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction
decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler {

    NSURL *url = navigationAction.request.URL;
    NSString *host = url.host.lowercaseString;

    BOOL isTelegram =
        [host isEqualToString:@"t.me"] ||
        [host isEqualToString:@"www.t.me"] ||
        [host isEqualToString:@"telegram.me"] ||
        [host isEqualToString:@"www.telegram.me"];

    if (isTelegram) {
        decisionHandler(WKNavigationActionPolicyCancel);

        [[UIApplication sharedApplication]
            openURL:url
            options:@{}
            completionHandler:^(BOOL success) {
                if (!success) {
                    NSLog(@"DARKIOS: Could not open Telegram URL.");
                }
            }];

        return;
    }

    decisionHandler(WKNavigationActionPolicyAllow);
}

@end
