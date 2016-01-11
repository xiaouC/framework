#pragma once
#include "TLWindowDefine.h"
#include "TLTextField.h"

USING_NS_CC;

class TLWindow;

class TLTextFieldDelegate : public TLRichTextFieldDelegate
{
	friend class TLWindow;
public:
	TLTextFieldDelegate( TLWindow* pInputWindow, float fFontSize, const char* placeholder, TL_RICH_STRING_FLAG eRichStringFlag );
	virtual ~TLTextFieldDelegate();

	virtual bool onTextFieldInsertText( TLTextField * pSender, const char * text, int nLen );
	virtual bool onTextFieldDeleteBackward( TLTextField * sender, const char * delText, int nLen );
	virtual bool onTextFieldAttachWithIME( TLTextField * sender );
	virtual bool onTextFieldDetachWithIME( TLTextField * sender );
	virtual bool onDraw( TLTextField* pSender );
	virtual bool onTextFieldChanged( TLTextField* pSender );
	virtual void  setCursorSize(float x, float y);

	virtual bool RegisterErroTipCallbackHandler( int errofuncHandler );
    virtual void executeErroFunc();
    
    virtual bool RegisterInputReturnCallbackHandler( int funcHandler );
	virtual void executeInputReturnFunc();

public:
	void SetInputTextModel( TL_INPUT_TEXT_MODEL kInputTextModel );
	TL_INPUT_TEXT_MODEL GetInputTextModel() const { return m_kInputTextModel; }

	void SetInputLimit( int nLimit ) { m_nInputLimit = nLimit; }
	int GetInputLimit() const { return m_nInputLimit; }
    void SetInputApendLine(int model);
    int GetInputApendLine() const { return m_nInputApendLine; }

    void SetInputAlignment( CCImage::ETextAlign eAlignment );
protected:
	int m_nErroHandler;
    
    // 输入回车时调用脚本
    int m_nInputReturnHandler;
    
	TLWindow* m_pInputWindow;
	TLTextField* m_pTextFiledTexFont;

	TL_INPUT_TEXT_MODEL m_kInputTextModel;
	int m_nInputLimit;
    int m_nInputApendLine;

	float m_fFontSize;
	CCSize m_kTextFieldSize;
};
