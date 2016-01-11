#pragma once
#include "../RichText/TLLabelRichTex.h"
#include "text_input_node/CCIMEDelegate.h"
#include "touch_dispatcher/CCTouchDelegateProtocol.h"

class TLTextField;
class TLRichTextFieldDelegate
{
public:
    virtual bool onTextFieldAttachWithIME( TLTextField* sender )
    {
        CC_UNUSED_PARAM(sender);
        return false;
    }
    virtual bool onTextFieldDetachWithIME( TLTextField* sender )
    {
        CC_UNUSED_PARAM(sender);
        return false;
    }
    virtual bool onTextFieldInsertText( TLTextField* sender, const char* text, int nLen )
    {
        CC_UNUSED_PARAM(sender);
        CC_UNUSED_PARAM(text);
        CC_UNUSED_PARAM(nLen);
        return false;
    }
    virtual bool onTextFieldDeleteBackward( TLTextField* sender, const char* delText, int nLen )
    {
        CC_UNUSED_PARAM(sender);
        CC_UNUSED_PARAM(delText);
        CC_UNUSED_PARAM(nLen);
        return false;
    }
    virtual bool onDraw( TLTextField* sender )
    {
        CC_UNUSED_PARAM(sender);
        return false;
	}
	virtual bool onTextFieldChanged( TLTextField* sender )
	{
		CC_UNUSED_PARAM(sender);
		return false;
	}
    
    virtual void SetInputApendLine(int model) {}
    virtual int GetInputApendLine() const { return 0; }
    
	virtual void executeErroFunc() = 0;
    
    virtual void executeInputReturnFunc() {}
};

/**
@brief    A simple text input field with TTF font.
*/
class TLTextField : public TLLabelRichTex, public CCIMEDelegate
{
public:
    TLTextField();
    virtual ~TLTextField();

    //char * description();

    /** creates a CCTextFieldTTF from a fontname, alignment, dimension and font size */
    static TLTextField * textFieldWithPlaceHolder( const char* placeholder, const CCSize& dimensions, CCImage::ETextAlign alignment, float fontSize, TL_RICH_STRING_FLAG eRichStringFlag );
    /** creates a CCLabelTTF from a fontname and font size */
    static TLTextField * textFieldWithPlaceHolder( const char* placeholder, float fontSize );
    /** initializes the CCTextFieldTTF with a font name, alignment, dimension and font size */
    bool initWithPlaceHolder( const char *placeholder, const CCSize& dimensions, CCImage::ETextAlign alignment, float fontSize );
    /** initializes the CCTextFieldTTF with a font name and font size */
    bool initWithPlaceHolder( const char *placeholder, float fontSize );

    /**
    @brief    Open keyboard and receive input text.
    */
    virtual bool attachWithIME();

    /**
    @brief    End text input and close keyboard.
    */
    virtual bool detachWithIME();

    //////////////////////////////////////////////////////////////////////////
    // properties
    //////////////////////////////////////////////////////////////////////////

    CC_SYNTHESIZE(TLRichTextFieldDelegate *, m_pDelegate, Delegate);
    CC_SYNTHESIZE_READONLY(int, m_nCharCount, CharCount);
    virtual const ccColor4B& getColorSpaceHolder();
    virtual void setColorSpaceHolder(const ccColor4B& color);

    virtual void setColor( const ccColor3B& color3 );
    virtual void setOpacity( GLubyte opacity );

    // input text property
public:
    virtual void setRichString( const char *text, TL_RICH_STRING_FLAG eRichStringFlag = TL_RICH_STRING_FLAG_ONE_LINE );
    virtual const char* getRichString(void);
	virtual void onExit();

	void setFontSize( float fFontSize );
protected:
    std::string * m_pInputText;

    // place holder text property
    // place holder text displayed when there is no text in the text field.
public:
    virtual void setPlaceHolder(const char * text);
    virtual const char * getPlaceHolder(void);
protected:
    std::string * m_pPlaceHolder;
    ccColor4B m_ColorSpaceHolder;
    ccColor4B m_originColor;
public:
    virtual void setSecureTextEntry(bool value);
	virtual bool isSecureTextEntry();
	virtual void setCursorSize(float x, float y);
	virtual bool isAttachIME();
    virtual void SetInputApendLine(int model);

protected:
    bool m_bSecureTextEntry;
protected:
    //////////////////////////////////////////////////////////////////////////
    // CCIMEDelegate interface
    //////////////////////////////////////////////////////////////////////////

    virtual bool canAttachWithIME();
    virtual bool canDetachWithIME();
    virtual void insertText(const char * text, int len);
    virtual void deleteBackward();
    virtual const char * getContentText();
private:
    class LengthStack;
	LengthStack * m_pLens;
	CCSprite* m_pCursor;
    CCPoint m_kCursorDefault;
	bool		m_isOpenKeyboard;
	int m_nErroHandler;
};

