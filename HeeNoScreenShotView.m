#import "HeeNoScreenShotView.h"

@interface HeeeNoScreenShotView ()
@property (nonatomic, strong) UITextField *textField;
@property (nonatomic, strong) UIView *clearView;
@end

@implementation HeeNoScreenShotView

- (instancetype)init {
  self = [super init];
  if (self) {
    [self setupUI];
  }
  return self;
}

- (instancetype)initWithFrame:(CGRect)frame {
  self = [super initWithFrame:frame];
  if (self) {
    [self setupUI];
  }
  return self;
}

- (instancetype)initWithCoder:(NSCoder *)coder {
  self = [super initWithCoder:coder];
  if (self) {
    [self setupUI];
  }
  return self;
}

- (void)layoutSubviews {
  [super layoutSubviews];
  self.textField.frame = self.bounds;
  self.clearView.frame = self.bounds;
}

- (void)setupUI {
  [super addSubview:self.textField];
  UIView *container = self.textField.subviews.firstObject ?: self.textField;
  container.userInteractionEnabled = YES;
  [container addSubview:self.clearView];
}

- (void)addSubview:(UIView *)view {
  if (view == self.textField) {
    [super addSubview:view];
  } else {
    [self.clearView addSubview:view];
  }
}

- (BOOL)pointInside:(CGPoint)point withEvent:(UIEvent *)event {
  return CGRectContainsPoint(self.bounds, point);
}

- (UITextField *)textField {
  if (!_textField) {
    _textField = [[UITextField alloc] init];
    _textField.secureTextEntry = YES;
    _textField.userInteractionEnabled = YES;
  }
  return _textField;
}

- (UIView *)clearView {
  if (!_clearView) {
    _clearView = [[UIView alloc] init];
    _clearView.userInteractionEnabled = YES;
    _clearView.backgroundColor = [UIColor clearColor];
  }
  return _clearView;
}

@end
