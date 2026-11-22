#import "HeeeNoScreenShotView.h"

@interface HeeeNoScreenShotView ()
@property (nonatomic, strong) UITextField *textField;
@property (nonatomic, strong) UIView *clearView;
@end

@implementation HeeeNoScreenShotView

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
  UIView *secureContainer = self.textField.subviews.firstObject ?: self.textField;
  secureContainer.userInteractionEnabled = YES;
  [secureContainer addSubview:self.clearView];
}

- (void)addSubview:(UIView *)view {
  if (view == self.textField) {
    [super addSubview:view];
  } else {
    [self.clearView addSubview:view];
  }
}

- (UITextField *)textField {
  if (!_textField) {
    _textField = [[UITextField alloc] init];
    _textField.secureTextEntry = YES;
    _textField.enabled = NO;
  }
  return _textField;
}

- (UIView *)clearView {
  if (!_clearView) {
    _clearView = [[UIView alloc] init];
    _clearView.userInteractionEnabled = YES;
  }
  return _clearView;
}

@end
