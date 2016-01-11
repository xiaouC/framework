//
//  TLEditBoxImpl.h
//  lszb
//
//  Created by liupeng on 1/7/15.
//
//

#ifndef __TLEditBoxImpl__
#define __TLEditBoxImpl__


#include "cocos2d.h"
#include "ExtensionMacros.h"
#include "TLEditBox.h"


class TLEditBoxImpl
{
public:
    TLEditBoxImpl(TLEditBox* pEditBox) : m_pEditBox(pEditBox) {}
    virtual ~TLEditBoxImpl() {}
    
    virtual bool initWithSize(const CCSize& size) = 0;
    virtual void setInputFlag(TL_INPUT_FLAG inputFlag) = 0;
    virtual void setText(const char* pText) = 0;
    virtual const char* getText(void) = 0;
    virtual void doAnimationWhenKeyboardMove(float duration, float distance) = 0;
    virtual void openKeyboard() = 0;
    virtual void closeKeyboard() = 0;
    
    TLEditBox* getTLEditBox() { return m_pEditBox; };

protected:
    TLEditBox* m_pEditBox;
};

extern TLEditBoxImpl* __createSystemEditBox(TLEditBox* pEditBox);




#endif /* defined(__lszb__TLEditBoxImpl__) */
