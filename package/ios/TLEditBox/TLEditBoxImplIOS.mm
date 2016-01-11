//
//  TLEditBoxImplIOS.mm
//
//  Created by liupeng on 1/6/15.
//
//

#include "TLEditBoxImplIOS.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#include "TLEditBox.h"
#import "EAGLView.h"

#define getEditBoxImplIOS() ((TLEditBoxImplIOS*)editBox_)

static const int CC_EDIT_BOX_PADDING = 5;

@implementation ZZCustomUITextField
- (CGRect)textRectForBounds:(CGRect)bounds {
    float padding = CC_EDIT_BOX_PADDING * cocos2d::CCEGLView::sharedOpenGLView()->getScaleX() / [[EAGLView sharedEGLView] contentScaleFactor ];
    return CGRectMake(bounds.origin.x + padding, bounds.origin.y + padding,
                      bounds.size.width - padding*2, bounds.size.height - padding*2);
}
- (CGRect)editingRectForBounds:(CGRect)bounds {
    return [self textRectForBounds:bounds];
}
@end


@implementation ZZEditBoxImplIOS

@synthesize textField = textField_;
@synthesize editState = editState_;
@synthesize editBox = editBox_;
@synthesize lastString = lastString_;
@synthesize canFill = canFill_;

- (void)dealloc
{
    [textField_ resignFirstResponder];
    [textField_ removeFromSuperview];
    self.textField = NULL;
    [super dealloc];
}



-(id) initWithFrame: (CGRect) frameRect editBox: (void*) editBox
{
    self = [super init];
    
    do
    {
        if (self == nil) break;

        editState_ = NO;
        canFill_ = NO;
        
        self.textField = [[[ZZCustomUITextField alloc] initWithFrame: frameRect] autorelease];
        CGRect r = [ UIScreen mainScreen ].applicationFrame;
        self.textField.center = CGPointMake(r.size.width*0.5, r.size.height);
        
        if (!textField_) break;
        [textField_ setTextColor:[UIColor blackColor]];
        textField_.font = [UIFont systemFontOfSize:frameRect.size.height*2/3];
        //TODO need to delete hard code here.
        textField_.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
        textField_.backgroundColor = [UIColor whiteColor];
        textField_.borderStyle = UITextBorderStyleNone;
        textField_.delegate = self;
        textField_.hidden = true;
        textField_.returnKeyType = UIReturnKeyDone;
        textField_.autocorrectionType = UITextAutocorrectionTypeNo;
        textField_.autocapitalizationType = UITextAutocapitalizationTypeNone;
        

        [textField_ addTarget:self action:@selector(textChanged) forControlEvents:UIControlEventEditingChanged];
        self.editBox = editBox;
        
        
        
        return self;
    }while(0);
    
    return nil;
}


-(void) doAnimationWhenKeyboardMoveWithDuration:(float)duration distance:(float)distance
{
    CCEGLViewProtocol* eglView = CCEGLView::sharedOpenGLView();

    CGRect r = [ UIScreen mainScreen ].applicationFrame;
    
    
    self.textField.center = CGPointMake(r.size.width*0.5, r.size.height - distance * eglView->getScaleY() / [[UIScreen mainScreen] scale] - self.textField.frame.size.height*0.5);
}

-(void) openKeyboard
{
    [[EAGLView sharedEGLView] addSubview:textField_];
    [textField_ becomeFirstResponder];
}

-(void) closeKeyboard
{
    [textField_ resignFirstResponder];
    [textField_ removeFromSuperview];
}

- (BOOL)textFieldShouldReturn:(UITextField *)sender
{
    canFill_ = YES;
    
    if (sender == textField_) {
        [sender resignFirstResponder];
    }
    return NO;
}

-(void)animationSelector
{
    id eglView = [EAGLView sharedEGLView];
    [eglView doAnimationWhenAnotherEditBeClicked];
}

- (BOOL)textFieldShouldBeginEditing:(UITextField *)sender        // return NO to disallow editing.
{
    editState_ = YES;
    canFill_ = NO;
    id eglView = [EAGLView sharedEGLView];
    if ([eglView isKeyboardShown])
    {
        [self performSelector:@selector(animationSelector) withObject:nil afterDelay:0.0f];
    }
    
    return YES;
}

- (BOOL)textFieldShouldEndEditing:(UITextField *)sender
{
    editState_ = NO;
    
    getEditBoxImplIOS()->setText(getEditBoxImplIOS()->getText());
    
    TLEditBox*  pEditBox= getEditBoxImplIOS()->getTLEditBox();
    
    if (NULL != pEditBox && canFill_)
    {
        pEditBox->setText(getEditBoxImplIOS()->getText());
        canFill_ = NO;
    }
    
    return YES;
}

- (BOOL)textField:(UITextField *) textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string
{
    NSLog(@".........YYY textField text=%@", textField.text);
    NSLog(@".........YYY textField text length=%i", textField.text.length);
    NSLog(@".........YYY range length=%i", range.length);
    NSLog(@".........YYY range location=%i", range.location);
    NSLog(@".........YYY string=%@", string);
    
   
    
    
    TLEditBox*  pEditBox= getEditBoxImplIOS()->getTLEditBox();
    if (NULL != pEditBox) {
        bool hasCheck = false;
        
        NSString *lang = [[UITextInputMode currentInputMode] primaryLanguage];
        if ([lang isEqualToString:@"zh-Hans"])
        {
            if (range.location + range.length > self.textField.text.length) {
                return NO;
            }
            
        } else {
            
            hasCheck = pEditBox->checkText([self.textField.text UTF8String], self.textField.text.length);
            if (!hasCheck) {
                if (self.lastString && self.lastString.length > 0) {
                    self.textField.text = self.lastString;
                } else {
                    self.textField.text = NULL;
                }
            }
            
            if (range.location + range.length > self.textField.text.length) {
                return NO;
            }

        }
    }
    return YES;
}

- (void) textChanged
{
    
    bool hasCheck = false;
    
    TLEditBox*  pEditBox= getEditBoxImplIOS()->getTLEditBox();

    NSString *lang = [[UITextInputMode currentInputMode] primaryLanguage];
    if ([lang isEqualToString:@"zh-Hans"])
    {
        UITextRange *selectedRange = [self.textField markedTextRange];
        NSString *selectedString = [self.textField textInRange:selectedRange];
        
        
        if (!selectedString || selectedString.length == 0) {
            const char* tempText =[self.textField.text UTF8String];
            
            hasCheck = pEditBox->checkText([self.textField.text UTF8String], strlen(tempText));
           
            if (!hasCheck) {
                if (self.lastString && self.lastString.length > 0) {
                    self.textField.text = self.lastString;
                } else {
                    self.textField.text = NULL;
                }
            }
            
            
            self.lastString = self.textField.text;
            pEditBox->setText(getEditBoxImplIOS()->getText());
        }
        
    }else {
        const char* tempText =[self.textField.text UTF8String];

        hasCheck = pEditBox->checkText([self.textField.text UTF8String], strlen(tempText));
        
        if (!hasCheck) {
            if (self.lastString && self.lastString.length > 0) {
                self.textField.text = self.lastString;
            } else {
                self.textField.text = NULL;
            }
        }
        
        
        self.lastString = self.textField.text;
        pEditBox->setText(getEditBoxImplIOS()->getText());
    }
}
@end


TLEditBoxImpl* __createSystemEditBox(TLEditBox* pEditBox)
{
    return new TLEditBoxImplIOS(pEditBox);
}

TLEditBoxImplIOS::TLEditBoxImplIOS(TLEditBox* pEditText)
: TLEditBoxImpl(pEditText)
, m_systemControl(NULL)
{
    m_bInRetinaMode = [[EAGLView sharedEGLView] contentScaleFactor] == 2.0f ? true : false;
}

TLEditBoxImplIOS::~TLEditBoxImplIOS()
{
    [m_systemControl release];
}

void TLEditBoxImplIOS::doAnimationWhenKeyboardMove(float duration, float distance)
{
    
    if ([m_systemControl isEditState] || distance < 0.0f)
    {
        [m_systemControl doAnimationWhenKeyboardMoveWithDuration:duration distance:distance];
    }
}

bool TLEditBoxImplIOS::initWithSize(const CCSize& size)
{
    do
    {
        CCEGLViewProtocol* eglView = CCEGLView::sharedOpenGLView();
        
        CGRect rect = CGRectMake(0, 0, size.width * eglView->getScaleX(),size.height * eglView->getScaleY());

        
        if (m_bInRetinaMode)
        {
            rect.size.width /= 2.0f;
            rect.size.height /= 2.0f;
        }
        
        m_systemControl = [[ZZEditBoxImplIOS alloc] initWithFrame:rect editBox:this];

        if (!m_systemControl) break;
        
        return true;
    }while (0);
    
    return false;
}

void TLEditBoxImplIOS::setInputFlag(TL_INPUT_FLAG inputFlag)
{
    switch (inputFlag)
    {
        case TL_INPUT_FLAG_NORMAL:
            m_systemControl.textField.secureTextEntry = NO;
            break;
        case TL_INPUT_FLAG_PASSWORD:
            m_systemControl.textField.secureTextEntry = YES;
            break;
        default:
            break;
    }
}

void TLEditBoxImplIOS::setText(const char* pText)
{
    m_systemControl.textField.text = [NSString stringWithUTF8String:pText];
}

const char*  TLEditBoxImplIOS::getText(void)
{
    return [m_systemControl.textField.text UTF8String];
}

void TLEditBoxImplIOS::openKeyboard()
{
    m_systemControl.textField.hidden = NO;
    //给textField赋初值
    m_systemControl.textField.text = [NSString stringWithUTF8String:m_pEditBox->getText()];
    //更新上次纪录
    m_systemControl.lastString = m_systemControl.textField.text;
    [m_systemControl openKeyboard];
}

void TLEditBoxImplIOS::closeKeyboard()
{
    [m_systemControl closeKeyboard];
}

#endif
