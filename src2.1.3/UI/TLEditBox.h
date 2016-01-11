#pragma once
#include "ccTypes.h"
#include "text_input_node/CCIMEDelegate.h"
#include "sprite_nodes/CCSprite.h"
#include "TLWindowDefine.h"
#include "../RichText/TLFontTex.h"
#include "../RichText/TLLabelRichTex.h"

USING_NS_CC;


// 
class TLWindow;
class TLEditBox;

class TLEditBoxImpl;

class TLEditBox : public CCIMEDelegate
{
public:
    TLEditBox( TLWindow* pInputWindow );
    virtual ~TLEditBox();

    static TLEditBox* getCurrentTLEditBox(void);

    virtual bool canAttachWithIME();
    virtual bool attachWithIME();

    virtual bool canDetachWithIME();
    virtual bool detachWithIME();

    virtual void keyboardWillShow( CCIMEKeyboardNotificationInfo& info );
    virtual void keyboardDidShow( CCIMEKeyboardNotificationInfo& info );
    virtual void keyboardWillHide( CCIMEKeyboardNotificationInfo& info );
    virtual void keyboardDidHide( CCIMEKeyboardNotificationInfo& info );

    virtual void insertText( const char * text, int len );
    virtual void deleteBackward();
    virtual const char * getContentText();

public:
    bool checkText( const char * text, int len );
    void sentNetMsgToSelf( const char * text );

    void setText( const char* pszText );
    const char* getText();

    void setTextColor( const ccColor3B& kTextColor );
    const ccColor3B& getTextColor();

    void setPlaceHolder( const char* pszText );
    const char* getPlaceHolder();

    void setPlaceHolderColor( const ccColor3B& kPlaceHolderColor );
    const ccColor3B& getPlaceHolderColor();

    void setFontSize( int nFontSize );
    void setPlaceFontSize( int nFontSize );
    void setRichFlag( TL_RICH_STRING_FLAG eRichFlag );
    void setAlignment( CCImage::ETextAlign eAlignment );

    void setInputMode( TL_INPUT_TEXT_MODEL eInputMode );

    void setMaxLength( int nMaxLength );
    int getMaxLength();

    void setInputFlag( TL_INPUT_FLAG eInputFlag );

    void setReturnType( TL_RETURN_TYPE eReturnType );

    void setKeyboardWillShowHandler( int nWillShowHandler );
    void setKeyboardWillHideHandler( int nWillHideHandler );

    CCSize getRealSize();
    
protected:
    TLWindow* m_pInputWindow;
    TLEditBoxImpl* m_pEditBoxImpl;

    TLLabelRichTex* m_pRichTex;

    std::string m_strText;
    ccColor3B m_kTextColor;

    std::string m_strPlaceHolder;
    ccColor3B m_kPlaceHolderColor;

    int m_nFontSize;
    int m_nPlaceFontSize;
    TL_RICH_STRING_FLAG m_eRichFlag;

    TL_INPUT_TEXT_MODEL m_eInputMode;
    TL_INPUT_FLAG m_eInputFlag;
    TL_RETURN_TYPE m_eReturnType;

    int m_nMaxLength;
    int m_nLength;

    int m_nKeyboardWillShowHandler;
    int m_nKeyboardWillHideHandler;
    
};
