//
//  TLEditBoxImplIOS.h
//
//  Created by liupeng on 1/6/15.
//
//

#ifndef __TLEditBoxIMPLIOS_H__
#define __TLEditBoxIMPLIOS_H__

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "ExtensionMacros.h"
#include "TLEditBoxImpl.h"

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ZZCustomUITextField : UITextField
{
}

@end


@interface ZZEditBoxImplIOS : NSObject <UITextFieldDelegate>
{
    ZZCustomUITextField* textField_;
    void* editBox_;
    BOOL editState_;
    NSString* selectedString_;
    NSString* lastString_;
    BOOL canFill_;
}

@property(nonatomic, retain) UITextField* textField;
@property(nonatomic, readonly, getter = isEditState) BOOL editState;
@property(nonatomic, assign) void* editBox;
@property(nonatomic, copy) NSString* lastString;
@property(nonatomic, assign) BOOL canFill;



-(id) initWithFrame: (CGRect) frameRect editBox: (void*) editBox;
-(void) doAnimationWhenKeyboardMoveWithDuration:(float)duration distance:(float)distance;
-(void) openKeyboard;
-(void) closeKeyboard;


@end


class TLEditBox;

class TLEditBoxImplIOS : public TLEditBoxImpl
{
public :
    TLEditBoxImplIOS(TLEditBox* pEditText);
    virtual ~TLEditBoxImplIOS();
    
    virtual bool initWithSize(const CCSize& size);
    virtual void setInputFlag(TL_INPUT_FLAG inputFlag);
    
    virtual void setText(const char* pText);
    virtual const char* getText(void);
    virtual void doAnimationWhenKeyboardMove(float duration, float distance);
    virtual void openKeyboard();
    virtual void closeKeyboard();
    
private:
    ZZEditBoxImplIOS* m_systemControl;
    bool            m_bInRetinaMode;

};

#endif
#endif

