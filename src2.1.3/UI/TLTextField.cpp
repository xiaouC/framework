#include "TLTextField.h"
#include "../RichText/TLFontTex.h"
#include "CCDirector.h"
#include "CCEGLView.h"
#include "../MC/MCLoader.h"
#include "CCLuaEngine.h"
#include "TLWindowDefine.h"

static int _calcCharCount( const char* pszText )
{
    int nCharCount = 0;

	std::string strTemp = pszText;
	while( strTemp.length() > 0 )
    {
		char* pTemp = (char*)strTemp.c_str();

        int mask,n;
        UTF8_COMPUTE( pTemp[0], mask, n );

        ++nCharCount;
        if( n == 3 ) ++nCharCount;          // 中文字符的话，n 就应该是等于 3 的，至于其他的特殊字符，哎，就算单个字符了吧

        pTemp = cc_utf8_next_char_help( pTemp );
        strTemp = pTemp;
    }

    return nCharCount;

	//return cc_utf8_strlen( pszText, -1 );

    //
    //int n = 0;
    //char ch = 0;
    //while ((ch = *pszText))
    //{
    //    CC_BREAK_IF(! ch);

    //    if (0x80 != (0xC0 & ch))
    //    {
    //        ++n;
    //    }
    //    ++pszText;
    //}
    //return n;
}

//////////////////////////////////////////////////////////////////////////
// constructor and destructor
//////////////////////////////////////////////////////////////////////////

TLTextField::TLTextField()
: m_pDelegate(0)
, m_nCharCount(0)
, m_pInputText(new std::string)
, m_pPlaceHolder(new std::string)   // prevent CCLabelTTF initWithString assertion
, m_ColorSpaceHolder(ccc4(127,127,127,127))
, m_bSecureTextEntry(false)
, m_pCursor(NULL)
, m_kCursorDefault(CCPointZero)
, m_isOpenKeyboard(false)
, m_nErroHandler(0)
{
    m_originColor = m_kColor;
    m_kColor = m_ColorSpaceHolder;
}

TLTextField::~TLTextField()
{
    CC_SAFE_DELETE(m_pInputText);
    CC_SAFE_DELETE(m_pPlaceHolder);
}

//////////////////////////////////////////////////////////////////////////
// static constructor
//////////////////////////////////////////////////////////////////////////

TLTextField* TLTextField::textFieldWithPlaceHolder( const char* placeholder, const CCSize& dimensions, CCImage::ETextAlign alignment, float fontSize, TL_RICH_STRING_FLAG eRichStringFlag )
{
    TLTextField *pRet = new TLTextField();
    if( pRet && pRet->initWithPlaceHolder( "", dimensions, alignment, fontSize ) )
    {
        pRet->m_eRichStringFlag = eRichStringFlag;
        pRet->autorelease();
        if( placeholder )
        {
            pRet->setPlaceHolder( placeholder );
        }
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

TLTextField * TLTextField::textFieldWithPlaceHolder( const char *placeholder, float fontSize )
{
    TLTextField *pRet = new TLTextField();
    if( pRet && pRet->initWithString( "", fontSize ) )
    {
        pRet->autorelease();
        if( placeholder )
        {
            pRet->setPlaceHolder( placeholder );
        }
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

//////////////////////////////////////////////////////////////////////////
// initialize
//////////////////////////////////////////////////////////////////////////

bool TLTextField::initWithPlaceHolder( const char *placeholder, const CCSize& dimensions, CCImage::ETextAlign alignment, float fontSize )
{
    if( placeholder )
    {
        CC_SAFE_DELETE(m_pPlaceHolder);
        m_pPlaceHolder = new std::string(placeholder);
	}

	m_pCursor = MCLoader::sharedMCLoader()->loadSprite( "Cursor.png" );

    CCSize kCursorSize = m_pCursor->getContentSize();

    chatTexInfo* pCTInfo = TLFontTex::sharedTLFontTex()->getChatTextInfo( "j" );
	float fScale = TLFontTex::sharedTLFontTex()->getFontScale( fontSize );
    m_kCursorDefault = CCPoint( kCursorSize.width * 1.5f, dimensions.height - pCTInfo->rcUV.size.height * fScale * 0.5 );

    m_pCursor->setScale( fScale );
	m_pCursor->setAnchorPoint( ccp( 0.5, 0.5 ) );
    m_pCursor->setPosition( m_kCursorDefault );
	m_pCursor->setVisible( false );
	addChild(m_pCursor);

    return TLLabelRichTex::initWithString( m_pPlaceHolder->c_str(), fontSize, dimensions, alignment );
}
bool TLTextField::initWithPlaceHolder( const char *placeholder, float fontSize )
{
    if( placeholder )
    {
        CC_SAFE_DELETE(m_pPlaceHolder);
        m_pPlaceHolder = new std::string(placeholder);
	}

	m_pCursor = MCLoader::sharedMCLoader()->loadSprite( "Cursor.png" );

    CCSize kCursorSize = m_pCursor->getContentSize();

    chatTexInfo* pCTInfo = TLFontTex::sharedTLFontTex()->getChatTextInfo( "j" );
	float fScale = TLFontTex::sharedTLFontTex()->getFontScale( fontSize );
    m_kCursorDefault = CCPoint( kCursorSize.width * 1.5f, pCTInfo->rcUV.size.height * fScale );

    m_pCursor->setScale( fScale );
	m_pCursor->setAnchorPoint( ccp( 0.5, 0.5 ) );
    m_pCursor->setPosition( m_kCursorDefault );
	m_pCursor->setVisible( false );
	addChild(m_pCursor);

    return TLLabelRichTex::initWithString( m_pPlaceHolder->c_str(), fontSize, CCSizeZero, CCImage::kAlignLeft );
}

//////////////////////////////////////////////////////////////////////////
// CCIMEDelegate
//////////////////////////////////////////////////////////////////////////

bool TLTextField::attachWithIME()
{
    bool bRet = CCIMEDelegate::attachWithIME();
    if (bRet)
    {
        // open keyboard
        CCEGLView * pGlView = CCDirector::sharedDirector()->getOpenGLView();
        if (pGlView)
        {
            pGlView->setIMEKeyboardState(true);
        }
    }
    return bRet;
}

bool TLTextField::detachWithIME()
{
    bool bRet = CCIMEDelegate::detachWithIME();
    if (bRet)
    {
        // close keyboard
        CCEGLView * pGlView = CCDirector::sharedDirector()->getOpenGLView();
        if (pGlView)
        {
            pGlView->setIMEKeyboardState(false);
        }
    }
    return bRet;
}

bool TLTextField::canAttachWithIME()
{
    m_isOpenKeyboard = true;
	m_pCursor->setVisible( true );
	cocos2d::CCRepeatForever* pAction = cocos2d::CCRepeatForever::create( cocos2d::CCBlink::create( 1.0f, 1 ) );
	m_pCursor->runAction( pAction );

    return (m_pDelegate) ? (! m_pDelegate->onTextFieldAttachWithIME(this)) : true;
}

bool TLTextField::canDetachWithIME()
{
    m_isOpenKeyboard = false;
	m_pCursor->setVisible( false );
	m_pCursor->stopAllActions();
    return (m_pDelegate) ? (! m_pDelegate->onTextFieldDetachWithIME(this)) : true;
}

void TLTextField::insertText(const char * text, int len)
{
    std::string sInsert(text, len);

    // insert \n means input end
    int nPos = sInsert.find('\n');
    if ((int)sInsert.npos != nPos)
    {
        if ( m_pDelegate )
        {
            //if (m_pDelegate->GetInputApendLine() == TL_CLOSEIME)
            //{
            //    detachWithIME();
            //    return;
            //}
            //else if ( m_pDelegate->GetInputApendLine() == TL_HADLESCRIPT )
            //{
            //    m_pDelegate->executeInputReturnFunc();
            //    return;
            //}
        }
        len = nPos;
        sInsert.erase(nPos);
    }

    if (len > 0)
    {
        if (m_pDelegate && m_pDelegate->onTextFieldInsertText(this, sInsert.c_str(), len))
        {
            // delegate doesn't want to insert text
			m_pDelegate->executeErroFunc();
            return;
        }

        m_nCharCount += _calcCharCount(sInsert.c_str());
        std::string sText(*m_pInputText);
        sText.append(sInsert);

        setRichString( sText.c_str(), m_eRichStringFlag );
    }

    if ((int)sInsert.npos == nPos) {
        return;
    }

    // '\n' inserted, let delegate process first
    if (m_pDelegate && m_pDelegate->onTextFieldInsertText(this, "\n", 1))
    {
        return;
    }

    // if delegate hasn't processed, detach from IME by default
    detachWithIME();
}

void TLTextField::deleteBackward()
{
    int nStrLen = m_pInputText->length();
    if (! nStrLen)
    {
        // there is no string
        return;
    }

    // get the delete byte number
    int nDeleteLen = 1;    // default, erase 1 byte

    while(0x80 == (0xC0 & m_pInputText->at(nStrLen - nDeleteLen)))
    {
        ++nDeleteLen;
    }

    if (m_pDelegate && m_pDelegate->onTextFieldDeleteBackward(this, m_pInputText->c_str() + nStrLen - nDeleteLen, nDeleteLen))
    {
        // delegate doesn't wan't to delete backwards
        return;
    }

    // if all text deleted, show placeholder string
    if (nStrLen <= nDeleteLen)
    {
        CC_SAFE_DELETE(m_pInputText);
        m_pInputText = new std::string;
		m_nCharCount = 0;
        m_pCursor->setPosition( m_kCursorDefault );

        TLLabelRichTex::setColor( ccc3( m_ColorSpaceHolder.r, m_ColorSpaceHolder.g, m_ColorSpaceHolder.b ) );
        TLLabelRichTex::setOpacity( m_ColorSpaceHolder.a );

        TLLabelRichTex::setRichString( m_pPlaceHolder->c_str(), m_eRichStringFlag );

        if( m_pDelegate )
            m_pDelegate->onTextFieldChanged( this );

        return;
    }

    // set new input text
    std::string sText(m_pInputText->c_str(), nStrLen - nDeleteLen);
    m_pCursor->setPosition( m_kCursorPosition );
    setRichString( sText.c_str(), m_eRichStringFlag );
}

const char * TLTextField::getContentText()
{
    return m_pInputText->c_str();
}

const ccColor4B& TLTextField::getColorSpaceHolder()
{
    return m_ColorSpaceHolder;
}

void TLTextField::setColorSpaceHolder(const ccColor4B& color)
{
    m_ColorSpaceHolder = color;
}

void TLTextField::setColor( const ccColor3B& color3 )
{
    m_originColor.r = color3.r;
    m_originColor.g = color3.g;
    m_originColor.b = color3.b;

    TLLabelRichTex::setColor( color3 );
}

void TLTextField::setOpacity( GLubyte opacity )
{
    m_originColor.a = opacity;

    TLLabelRichTex::setOpacity( opacity );
}

//////////////////////////////////////////////////////////////////////////
// properties
//////////////////////////////////////////////////////////////////////////

// input text property
void TLTextField::setRichString( const char *text, TL_RICH_STRING_FLAG eRichStringFlag )
{
	//static char bulletString[] = {(char)0xe2, (char)0x80, (char)0xa2, (char)0x00};
	static char bulletString[] = {(char)42, (char)0x00};
    std::string displayText;
    int length;

    std::string* pInputText = NULL;

    if (text)
    {
        pInputText = new std::string(text);
        displayText = *pInputText;
        if (m_bSecureTextEntry)
        {
            displayText = "";
            length = pInputText->length();
            while (length)
            {
                displayText.append(bulletString);
                --length;
            }
        }
    }
    else
    {
        pInputText = new std::string;
    }

    CC_SAFE_DELETE(m_pInputText);
    m_pInputText = pInputText;

    // if there is no input text, display placeholder instead
    if (! m_pInputText->length())
    {
        TLLabelRichTex::setColor( ccc3( m_ColorSpaceHolder.r, m_ColorSpaceHolder.g, m_ColorSpaceHolder.b ) );
        TLLabelRichTex::setOpacity( m_ColorSpaceHolder.a );
        TLLabelRichTex::setRichString( m_pPlaceHolder->c_str(), eRichStringFlag );
        m_pCursor->setPosition( m_kCursorDefault );
    }
    else
    {
        TLLabelRichTex::setColor( ccc3( m_originColor.r, m_originColor.g, m_originColor.b ) );
        TLLabelRichTex::setOpacity( m_originColor.a );
        TLLabelRichTex::setRichString( displayText.c_str(), eRichStringFlag );

        m_pCursor->setPosition( m_kCursorPosition );
    }
	m_nCharCount = _calcCharCount(m_pInputText->c_str());

	if( m_pDelegate )
		m_pDelegate->onTextFieldChanged( this );
}

const char* TLTextField::getRichString(void)
{
    return m_pInputText->c_str();
}

void TLTextField::setFontSize( float fFontSize )
{
    if( m_pCursor != NULL )
    {
        CCSize kContentSize = getContentSize();
        CCSize kCursorSize = m_pCursor->getContentSize();

        chatTexInfo* pCTInfo = TLFontTex::sharedTLFontTex()->getChatTextInfo( "j" );

        float fScale = TLFontTex::sharedTLFontTex()->getFontScale( fFontSize );

        m_kCursorDefault = CCPoint( kCursorSize.width * 1.5f, kContentSize.height - pCTInfo->rcUV.size.height * fScale * 0.5f );
    }

    TLLabelRichTex::setFontSize( fFontSize );
}

// place holder text property
void TLTextField::setPlaceHolder(const char * text)
{
    CC_SAFE_DELETE(m_pPlaceHolder);
    m_pPlaceHolder = (text) ? new std::string(text) : new std::string;
    if (! m_pInputText->length())
    {
        TLLabelRichTex::setColor( ccc3( m_ColorSpaceHolder.r, m_ColorSpaceHolder.g, m_ColorSpaceHolder.b ) );
        TLLabelRichTex::setOpacity( m_ColorSpaceHolder.a );

        TLLabelRichTex::setRichString( m_pPlaceHolder->c_str(), m_eRichStringFlag );
    }
}

const char * TLTextField::getPlaceHolder(void)
{
    return m_pPlaceHolder->c_str();
}

// secureTextEntry
void TLTextField::setSecureTextEntry(bool value)
{
    if (m_bSecureTextEntry != value)
    {
        m_bSecureTextEntry = value;
        setRichString( getRichString(), m_eRichStringFlag );
    }
}

bool TLTextField::isSecureTextEntry()
{
    return m_bSecureTextEntry;
}

void TLTextField::setCursorSize( float x, float y )
{
	if ( m_pCursor != NULL  )
	{
		m_pCursor->setScaleX(x);
		m_pCursor->setScaleY(y);
	}
}

bool TLTextField::isAttachIME()
{
	return m_isOpenKeyboard;
}

void TLTextField::SetInputApendLine(int model)
{
    if ( m_pDelegate )
    {
        m_pDelegate->SetInputApendLine(model );
    }
}

void TLTextField::onExit()
{
	detachWithIME();

	TLLabelRichTex::onExit();
}

