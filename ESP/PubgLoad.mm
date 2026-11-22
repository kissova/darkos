// HMOOD__TG@i_8_f
#import "PubgLoad.h"
#import "Engine.h"
#import "menu.h"
#import "HeeNoScreenShotView.h"
#import <QuartzCore/QuartzCore.h>
#include <math.h>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <unistd.h>

bool aPVQRIF = false;
bool zQkX8A = false;
bool MxVsd = false;
bool MXValQy = false;
extern bool MenDeal;
float menuIconAlpha = .92f;

// HMOOD__TG@i_8_f
@interface HMOODFloatingWindow : UIWindow
@property(nonatomic, weak) UIView* interactiveView;
@end

@implementation HMOODFloatingWindow
- (BOOL)canBecomeKeyWindow { return NO; }
- (UIView*)hitTest:(CGPoint)point withEvent:(UIEvent*)event {
    if (self.hidden || self.alpha <= 0.01f) return nil;
    UIView* target = [super hitTest:point withEvent:event];
    if (!target || !self.interactiveView) return nil;
    return (target == self.interactiveView || [target isDescendantOfView:self.interactiveView]) ? target : nil;
}
@end

// HMOOD__TG@i_8_f
@interface ImGuiLoad ()
@property(nonatomic, strong) metalbiew* vna;
@property(nonatomic, strong) HMOODFloatingWindow* floatingWindow;
@property(nonatomic, strong) UIButton* menuIconView;
@property(nonatomic, strong) NSTimer* iconTimer;
@property(nonatomic, assign) CGPoint dragOrigin;
@property(nonatomic, assign) BOOL dragging;
@property(nonatomic, assign) CGSize previousWindowSize;
- (UIWindow*)getKeyWindow;
- (void)attachRenderer;
- (void)refreshMenuIcon;
- (void)dragMenuIcon:(UIPanGestureRecognizer*)gesture;
@end

@implementation ImGuiLoad
+ (void)load { [self load1]; }

+ (void)load1 {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 3 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
        [[self share] initTapGes];
    });
}

+ (instancetype)share {
    static ImGuiLoad* instance = nil;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ instance = [[ImGuiLoad alloc] init]; });
    return instance;
}

- (UIWindow*)getKeyWindow {
    if (![NSThread isMainThread]) return nil;
    UIApplication* app = UIApplication.sharedApplication;
    if (!app) return nil;
    UIWindow* fallback = nil;
    for (UIScene* scene in app.connectedScenes) {
        if (![scene isKindOfClass:UIWindowScene.class] || scene.activationState != UISceneActivationStateForegroundActive)
            continue;
        UIWindowScene* windowScene = (UIWindowScene*)scene;
        for (UIWindow* window in windowScene.windows) {
            if (!window || window == self.floatingWindow || [window isKindOfClass:HMOODFloatingWindow.class] ||
                window.hidden || window.windowLevel != UIWindowLevelNormal) continue;
            if (window.isKeyWindow && window.rootViewController) return window;
            if (!fallback && window.rootViewController) fallback = window;
        }
    }
    return fallback;
}

- (void)attachRenderer {
    if (![NSThread isMainThread]) {
        dispatch_async(dispatch_get_main_queue(), ^{ [self attachRenderer]; });
        return;
    }
    UIWindow* window = [self getKeyWindow];
    if (!window || !window.rootViewController || !window.rootViewController.view) return;
    if (!self.vna) self.vna = [[metalbiew alloc] init];
    UIView* view = self.vna.view;
    if (!view) return;
    CGRect bounds = window.bounds;
    if (bounds.size.width <= 0.f || bounds.size.height <= 0.f ||
        !isfinite(bounds.size.width) || !isfinite(bounds.size.height)) return;
    view.frame = bounds;
    view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    if (view.superview != window.rootViewController.view) {
        [view removeFromSuperview];
        [window.rootViewController.view addSubview:view];
    }
    view.userInteractionEnabled = MenDeal;
}

- (void)initTapGes {
    if (![NSThread isMainThread]) {
        dispatch_async(dispatch_get_main_queue(), ^{ [self initTapGes]; });
        return;
    }
    [self attachRenderer];
    [self refreshMenuIcon];
    if (!self.iconTimer) {
        __weak ImGuiLoad* weakSelf = self;
        self.iconTimer = [NSTimer timerWithTimeInterval:.25 repeats:YES block:^(NSTimer* timer) {
            (void)timer;
            ImGuiLoad* strongSelf = weakSelf;
            if (!strongSelf) return;
            [strongSelf refreshMenuIcon];
        }];
        [NSRunLoop.mainRunLoop addTimer:self.iconTimer forMode:NSRunLoopCommonModes];
    }
}

- (void)refreshMenuIcon {
    if (![NSThread isMainThread]) {
        dispatch_async(dispatch_get_main_queue(), ^{ [self refreshMenuIcon]; });
        return;
    }
    UIWindow* window = [self getKeyWindow];
    if (!window || !window.windowScene || window.bounds.size.width <= 0.f || window.bounds.size.height <= 0.f) {
        self.floatingWindow.hidden = YES;
        return;
    }
    if (!self.floatingWindow || self.floatingWindow.windowScene != window.windowScene) {
        self.floatingWindow.hidden = YES;
        HMOODFloatingWindow* floating = [[HMOODFloatingWindow alloc] initWithWindowScene:window.windowScene];
        if (!floating) return;
        floating.frame = window.bounds;
        floating.backgroundColor = UIColor.clearColor;
        floating.windowLevel = UIWindowLevelAlert + 1.f;
        UIViewController* controller = [UIViewController new];
        UIView* container = [[HeeeNoScreenShotView alloc] initWithFrame:floating.bounds];
        if (!container) container = [[UIView alloc] initWithFrame:floating.bounds];
        container.backgroundColor = UIColor.clearColor;
        container.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
        controller.view = container;
        floating.rootViewController = controller;

        UIButton* icon = [UIButton buttonWithType:UIButtonTypeCustom];
        icon.frame = CGRectMake(0, 0, 52, 52);
        icon.adjustsImageWhenHighlighted = NO;
        UIImage* image = GetMenuBadgeImage();
        if (image) {
            [icon setImage:image forState:UIControlStateNormal];
        } else {
            [icon setTitle:@"H" forState:UIControlStateNormal];
            [icon setTitleColor:UIColor.whiteColor forState:UIControlStateNormal];
            icon.backgroundColor = [UIColor colorWithRed:.35f green:.02f blue:.08f alpha:1.f];
        }
        if (icon.imageView) icon.imageView.contentMode = UIViewContentModeScaleAspectFit;
        icon.accessibilityLabel = @"HMOOD VIP";
        icon.layer.cornerRadius = 26.f;
        icon.layer.shadowColor = UIColor.blackColor.CGColor;
        icon.layer.shadowOpacity = .5f;
        icon.layer.shadowRadius = 4.f;
        icon.layer.shadowOffset = CGSizeMake(0, 2);
        [icon addTarget:self action:@selector(show) forControlEvents:UIControlEventTouchUpInside];

        UIPanGestureRecognizer* pan = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(dragMenuIcon:)];
        pan.cancelsTouchesInView = YES;
        [icon addGestureRecognizer:pan];
        [container addSubview:icon];

        floating.interactiveView = icon;
        self.floatingWindow = floating;
        self.menuIconView = icon;
        self.previousWindowSize = floating.bounds.size;

        NSUserDefaults* defaults = NSUserDefaults.standardUserDefaults;
        id savedX = [defaults objectForKey:@"HMOODIconX"];
        id savedY = [defaults objectForKey:@"HMOODIconY"];
        double rawX = [savedX respondsToSelector:@selector(doubleValue)] ? [savedX doubleValue] : 0.94;
        double rawY = [savedY respondsToSelector:@selector(doubleValue)] ? [savedY doubleValue] : 0.32;
        if (!isfinite(rawX) || rawX < 0.0 || rawX > 1.0) rawX = 0.94;
        if (!isfinite(rawY) || rawY < 0.0 || rawY > 1.0) rawY = 0.32;
        icon.center = CGPointMake((CGFloat)rawX * floating.bounds.size.width, (CGFloat)rawY * floating.bounds.size.height);
    }

    [self attachRenderer];
    if (!self.floatingWindow || !self.menuIconView) return;

    self.floatingWindow.frame = window.bounds;
    const CGSize previous = self.previousWindowSize;
    const CGSize current = self.floatingWindow.bounds.size;
    if (!self.dragging && previous.width > 0.f && previous.height > 0.f &&
        current.width > 0.f && current.height > 0.f && !CGSizeEqualToSize(previous, current)) {
        CGFloat nx = self.menuIconView.center.x * current.width / previous.width;
        CGFloat ny = self.menuIconView.center.y * current.height / previous.height;
        if (isfinite(nx) && isfinite(ny)) {
            self.menuIconView.center = CGPointMake(nx, ny);
        }
    }
    self.previousWindowSize = current;

    if (!self.dragging) {
        CGPoint center = self.menuIconView.center;
        const UIEdgeInsets safe = window.safeAreaInsets;
        CGFloat minX = safe.left + 29.f;
        CGFloat maxX = current.width - safe.right - 29.f;
        CGFloat minY = safe.top + 29.f;
        CGFloat maxY = current.height - safe.bottom - 29.f;
        if (maxX >= minX) center.x = fmax(minX, fmin(maxX, center.x));
        if (maxY >= minY) center.y = fmax(minY, fmin(maxY, center.y));
        if (isfinite(center.x) && isfinite(center.y)) {
            self.menuIconView.center = center;
        }
    }

    float safeAlpha = isfinite(menuIconAlpha) ? fmaxf(.35f, fminf(1.f, menuIconAlpha)) : .92f;
    self.menuIconView.alpha = MenDeal ? 1.f : safeAlpha;
    self.floatingWindow.hidden = NO;
}

- (void)dragMenuIcon:(UIPanGestureRecognizer*)gesture {
    if (!gesture || !self.menuIconView || !self.floatingWindow) return;
    if (gesture.state == UIGestureRecognizerStateBegan) {
        self.dragging = YES;
        self.dragOrigin = self.menuIconView.center;
    }
    UIView* refView = self.floatingWindow.rootViewController.view ?: self.floatingWindow;
    const CGPoint shift = [gesture translationInView:refView];
    if (gesture.state == UIGestureRecognizerStateChanged) {
        CGFloat tx = self.dragOrigin.x + shift.x;
        CGFloat ty = self.dragOrigin.y + shift.y;
        if (isfinite(tx) && isfinite(ty)) {
            self.menuIconView.center = CGPointMake(tx, ty);
        }
    }
    if (gesture.state == UIGestureRecognizerStateEnded || gesture.state == UIGestureRecognizerStateCancelled) {
        self.dragging = NO;
        [self refreshMenuIcon];
        const CGSize size = self.floatingWindow.bounds.size;
        if (size.width > 0.f && size.height > 0.f && isfinite(self.menuIconView.center.x) && isfinite(self.menuIconView.center.y)) {
            double ratioX = fmax(0.0, fmin(1.0, (double)(self.menuIconView.center.x / size.width)));
            double ratioY = fmax(0.0, fmin(1.0, (double)(self.menuIconView.center.y / size.height)));
            [NSUserDefaults.standardUserDefaults setDouble:ratioX forKey:@"HMOODIconX"];
            [NSUserDefaults.standardUserDefaults setDouble:ratioY forKey:@"HMOODIconY"];
        }
    }
}

- (void)updateMenuIconAlpha:(float)alpha {
    if (![NSThread isMainThread]) {
        dispatch_async(dispatch_get_main_queue(), ^{ [self updateMenuIconAlpha:alpha]; });
        return;
    }
    menuIconAlpha = isfinite(alpha) ? fmaxf(.35f, fminf(1.f, alpha)) : .92f;
    [self refreshMenuIcon];
}

- (void)show {
    if (![NSThread isMainThread]) {
        dispatch_async(dispatch_get_main_queue(), ^{ [self show]; });
        return;
    }
    [self attachRenderer];
    if (!self.vna || !self.vna.view || !self.vna.view.superview) return;
    MenDeal = !MenDeal;
    self.vna.view.userInteractionEnabled = MenDeal;
    [self refreshMenuIcon];
}
@end
