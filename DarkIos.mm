#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <os/log.h>
#import <dispatch/dispatch.h>

static os_log_t DarkIosLog;

@interface DarkIosPassthroughWindow : UIWindow
@end

@implementation DarkIosPassthroughWindow

- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
    UIView *hitView = [super hitTest:point withEvent:event];
    // Yalnız button-a toxunulduqda pəncərə toxunuşu qəbul etsin, qalan yerlər oyuna keçsin
    if (hitView == self || hitView == self.rootViewController.view) {
        return nil;
    }
    return hitView;
}

@end

@interface DarkIosOverlayManager : NSObject

@property (nonatomic, strong) UIWindow *overlayWindow;
@property (nonatomic, strong) UIButton *injectButton;
@property (nonatomic, assign) BOOL isInjected;

+ (instancetype)shared;
- (void)scheduleButtonAfterDelay:(NSTimeInterval)seconds;

@end

@implementation DarkIosOverlayManager

+ (instancetype)shared {
    static DarkIosOverlayManager *sharedInstance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[DarkIosOverlayManager alloc] init];
    });
    return sharedInstance;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        DarkIosLog = os_log_create("com.darkios.framework", "Overlay");
        _isInjected = NO;
    }
    return self;
}

- (void)scheduleButtonAfterDelay:(NSTimeInterval)seconds {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(seconds * NSEC_PER_SEC)),
                       dispatch_get_main_queue(), ^{
            [self presentInjectButton];
        });
    });
}

- (UIWindowScene *)activeWindowScene {
    for (UIScene *scene in [UIApplication sharedApplication].connectedScenes) {
        if ([scene isKindOfClass:[UIWindowScene class]] &&
            scene.activationState == UISceneActivationStateForegroundActive) {
            return (UIWindowScene *)scene;
        }
    }
    for (UIScene *scene in [UIApplication sharedApplication].connectedScenes) {
        if ([scene isKindOfClass:[UIWindowScene class]]) {
            return (UIWindowScene *)scene;
        }
    }
    return nil;
}

- (void)presentInjectButton {
    if (self.overlayWindow) {
        return;
    }

    UIWindowScene *scene = [self activeWindowScene];
    if (!scene) {
        // Scene hələ hazır deyilsə 1 saniyə sonra bir daha yoxla
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)),
                       dispatch_get_main_queue(), ^{
            [self presentInjectButton];
        });
        return;
    }

    DarkIosPassthroughWindow *win = [[DarkIosPassthroughWindow alloc] initWithWindowScene:scene];
    win.frame = scene.coordinateSpace.bounds;
    win.windowLevel = UIWindowLevelAlert + 100;
    win.backgroundColor = [UIColor clearColor];

    UIViewController *rootVC = [[UIViewController alloc] init];
    rootVC.view.backgroundColor = [UIColor clearColor];
    win.rootViewController = rootVC;

    UIButton *btn = [UIButton buttonWithType:UIButtonTypeSystem];
    btn.translatesAutoresizingMaskIntoConstraints = NO;
    [btn setTitle:@"⚡ Inject DarkIos" forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    btn.titleLabel.font = [UIFont systemFontOfSize:16.0 weight:UIFontWeightBold];

    btn.backgroundColor = [UIColor colorWithRed:0.35 green:0.12 blue:0.85 alpha:0.95];
    btn.layer.cornerRadius = 24.0;
    btn.layer.borderWidth = 1.5;
    btn.layer.borderColor = [UIColor colorWithRed:0.72 green:0.52 blue:1.0 alpha:0.9].CGColor;

    // Yumşaq parıltı / kölgə effekti
    btn.layer.shadowColor = [UIColor colorWithRed:0.45 green:0.18 blue:1.0 alpha:1.0].CGColor;
    btn.layer.shadowOffset = CGSizeMake(0, 6);
    btn.layer.shadowRadius = 14.0;
    btn.layer.shadowOpacity = 0.75;

    btn.contentEdgeInsets = UIEdgeInsetsMake(14, 26, 14, 26);
    btn.alpha = 0.0;
    btn.transform = CGAffineTransformMakeScale(0.7, 0.7);

    [btn addTarget:self action:@selector(onInjectButtonTapped:) forControlEvents:UIControlEventTouchUpInside];

    [rootVC.view addSubview:btn];
    [NSLayoutConstraint activateConstraints:@[
        [btn.centerXAnchor constraintEqualToAnchor:rootVC.view.centerXAnchor],
        [btn.centerYAnchor constraintEqualToAnchor:rootVC.view.centerYAnchor]
    ]];

    self.injectButton = btn;
    self.overlayWindow = win;
    win.hidden = NO;

    // Ekrana animasiyalı gəliş
    [UIView animateWithDuration:0.55
                          delay:0.0
         usingSpringWithDamping:0.65
          initialSpringVelocity:0.8
                        options:UIViewAnimationOptionCurveEaseOut
                     animations:^{
        btn.alpha = 1.0;
        btn.transform = CGAffineTransformIdentity;
    } completion:^(BOOL finished) {
        [self startPulseAnimation];
    }];
}

- (void)startPulseAnimation {
    if (!self.injectButton || self.isInjected) {
        return;
    }
    [UIView animateWithDuration:1.1
                          delay:0.0
                        options:UIViewAnimationOptionRepeat | UIViewAnimationOptionAutoreverse | UIViewAnimationOptionAllowUserInteraction
                     animations:^{
        self.injectButton.transform = CGAffineTransformMakeScale(1.06, 1.06);
    } completion:nil];
}

- (void)onInjectButtonTapped:(UIButton *)sender {
    if (self.isInjected) {
        return;
    }
    self.isInjected = YES;
    sender.enabled = NO;

    [sender.layer removeAllAnimations];
    [sender setTitle:@"✨ Injecting..." forState:UIControlStateNormal];

    // Basılma animasiyası + kiçilib yoxa çıxma
    [UIView animateWithDuration:0.22
                          delay:0.0
                        options:UIViewAnimationOptionCurveEaseInOut
                     animations:^{
        sender.transform = CGAffineTransformMakeScale(0.92, 0.92);
    } completion:^(BOOL finished) {
        [UIView animateWithDuration:0.35
                              delay:0.25
                            options:UIViewAnimationOptionCurveEaseIn
                         animations:^{
            sender.alpha = 0.0;
            sender.transform = CGAffineTransformMakeScale(1.25, 1.25);
        } completion:^(BOOL done) {
            self.overlayWindow.hidden = YES;
            self.overlayWindow = nil;
            [self runInjectedPayload];
        }];
    }];
}

- (void)runInjectedPayload {
    // YALNIZ düyməyə basıldıqdan sonra işləyəcək kodlar bura yazılır
    os_log_info(DarkIosLog, "DarkIos düymə basıldıqdan sonra aktivləşdi");
}

@end

__attribute__((constructor))
static void DarkIosEntryPoint(void) {
    @autoreleasepool {
        [[DarkIosOverlayManager shared] scheduleButtonAfterDelay:5.0];
    }
}
