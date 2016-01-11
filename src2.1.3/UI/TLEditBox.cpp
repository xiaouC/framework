#include "TLEditBox.h"
#include "TLWindow.h"
#include "TLWindowManager.h"
#include "../RichText/TLLabelRichTex.h"
#include "platform.pb.h"
#include "../NetMessage/NetWorkThread.h"
#include "../NetMessage/NetMsgProcess.h"
#include "../NetMessage/NetMsg.h"


#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "android/jni/JniHelper.h"
#include "android/jni/Java_org_cocos2dx_lib_Cocos2dxHelper.h"
#include <jni.h>
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "TLEditBoxImpl.h"
#include "TLWindowManager.h"
#endif


static TLEditBox *s_TLEditBox = NULL;

int getTextLength( const std::string& strText )
{
    int nLength = 0;

    std::string strTemp = strText;
    while( strTemp.length() > 0 )
    {
        char* pTemp = (char*)strTemp.c_str();

        int mask,n;
        UTF8_COMPUTE( pTemp[0], mask, n );

        ++nLength;
        if( n == 3 )
            ++nLength;          // 中文字符的话，n 就应该是等于 3 的，至于其他的特殊字符，哎，就算单个字符了吧

        pTemp = cc_utf8_next_char_help( pTemp );
        strTemp = pTemp;
    }

    return nLength;
}

TLEditBox::TLEditBox( TLWindow* pInputWindow )
: m_pInputWindow(pInputWindow)
, m_kTextColor(ccc3(255,255,255))
, m_kPlaceHolderColor(ccc3(125,125,125))
, m_nFontSize(22)
, m_nPlaceFontSize(22)
, m_eRichFlag(TL_RICH_STRING_FLAG_AUTO_WRAP)
, m_eInputMode(TL_INPUT_TEXT_MODEL_ENGLISHNUMBER)
, m_eInputFlag(TL_INPUT_FLAG_NORMAL)
, m_eReturnType(TL_RETURN_TYPE_DEFAULT)
, m_nMaxLength(99999)
, m_nLength(0)
, m_nKeyboardWillShowHandler(0)
, m_nKeyboardWillHideHandler(0)
, m_pEditBoxImpl(NULL)
{
    float fFontSize = 22;

	const CCSize& size = m_pInputWindow->GetWindowRect().size;

    m_pRichTex = TLLabelRichTex::create( "", fFontSize, size, CCImage::kAlignBottomLeft );
    m_pRichTex->retain();

    m_pInputWindow->GetNode()->addChild( m_pRichTex );

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //初始化第三方EditBox
    m_pEditBoxImpl = __createSystemEditBox(this);
    float screenWidth = CCDirector::sharedDirector()->getWinSize().width;
    if (m_pEditBoxImpl) {
        m_pEditBoxImpl->initWithSize(CCSize(screenWidth, 45));
    }
#endif
}

TLEditBox::~TLEditBox()
{
    // close keyboard
    CCEGLView* pGlView = CCDirector::sharedDirector()->getOpenGLView();

    if( pGlView )
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        if( JniHelper::getStaticMethodInfo( t
                    , "org/weilan/poem"
                    , "closeCustomKeyBoard"
                    , "()V" ) )
        {
            t.env->CallStaticVoidMethod( t.classID, t.methodID );
            t.env->DeleteLocalRef( t.classID );
        }
#endif
        pGlView->setIMEKeyboardState( false );
    }

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    if (m_pEditBoxImpl != NULL) {
        m_pEditBoxImpl->closeKeyboard();
    }
    TLWindowManager::SharedTLWindowManager()->SetEditBoxWindow(NULL);
#endif

    s_TLEditBox = NULL;
    CC_SAFE_DELETE(m_pEditBoxImpl);

    m_pRichTex->release();
    m_pRichTex = NULL;

    if( m_nKeyboardWillShowHandler > 0 )
        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nKeyboardWillShowHandler );

    if( m_nKeyboardWillHideHandler > 0 )
        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nKeyboardWillHideHandler );

}

TLEditBox* TLEditBox::getCurrentTLEditBox(void) {
    return s_TLEditBox;
}

bool TLEditBox::canAttachWithIME()
{
    return true;
}

bool TLEditBox::attachWithIME()
{
    bool bRet = CCIMEDelegate::attachWithIME();
    if( bRet )
    {
        m_pRichTex->showCursor( true, m_strText.empty() );

        // open keyboard
        CCEGLView* pGlView = CCDirector::sharedDirector()->getOpenGLView();
        if( pGlView )
        {

            #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
            JniMethodInfo t;
            if( JniHelper::getStaticMethodInfo( t
                        , "org/weilan/poem"
                        , "openCustomKeyBoard"
                        , "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V" ) )
            {
                char s_maxLength[64];
                memset(s_maxLength,0,64);
                snprintf(s_maxLength, sizeof(s_maxLength), "%d", m_nMaxLength);

                char s_inputFlag[64];
                memset(s_inputFlag,0,64);
                snprintf(s_inputFlag, sizeof(s_inputFlag), "%d", m_eInputFlag);

                jstring talkStr = t.env->NewStringUTF( m_strText.c_str() );
                jstring placeHoldStr = t.env->NewStringUTF( m_strPlaceHolder.c_str() );
                jstring maxLengthStr = t.env->NewStringUTF( s_maxLength );
                jstring inputFlagStr = t.env->NewStringUTF( s_inputFlag );
                t.env->CallStaticVoidMethod( t.classID, t.methodID, talkStr,placeHoldStr, maxLengthStr, inputFlagStr );
                t.env->DeleteLocalRef( talkStr );
                t.env->DeleteLocalRef( placeHoldStr );
                t.env->DeleteLocalRef( maxLengthStr );
                t.env->DeleteLocalRef( inputFlagStr );
                t.env->DeleteLocalRef( t.classID );

                s_TLEditBox = this;

            }

            #elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            s_TLEditBox = this;
            if (m_pEditBoxImpl) {
                m_pEditBoxImpl->setInputFlag(m_eInputFlag);
                m_pEditBoxImpl->openKeyboard();
                TLWindowManager::SharedTLWindowManager()->SetEditBoxWindow(m_pInputWindow);
            }

            #else
            pGlView->setIMEKeyboardState( true );
            #endif
        }
    }
    return bRet;
}


bool TLEditBox::canDetachWithIME()
{
    return true;
}

bool TLEditBox::detachWithIME()
{
    bool bRet = CCIMEDelegate::detachWithIME();

    if( bRet )
    {

        m_pRichTex->showCursor( false, m_strText.empty() );

        // close keyboard
        CCEGLView* pGlView = CCDirector::sharedDirector()->getOpenGLView();

        if( pGlView )
        {
            pGlView->setIMEKeyboardState( false );
        }
    }

    s_TLEditBox = NULL;


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    if (m_pEditBoxImpl != NULL) {
        m_pEditBoxImpl->closeKeyboard();
    }
    TLWindowManager::SharedTLWindowManager()->SetEditBoxWindow(NULL);
#endif
    return bRet;
}

void TLEditBox::keyboardWillShow( CCIMEKeyboardNotificationInfo& info )
{
    if( m_nKeyboardWillShowHandler > 0 )
    {
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.begin.origin.x );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.begin.origin.y );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.begin.size.width );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.begin.size.height );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.end.origin.x );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.end.origin.y );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.end.size.width );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.end.size.height + 45 );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.duration );

        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nKeyboardWillShowHandler, 9 );
    }


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    if (m_pEditBoxImpl != NULL) {

        m_pEditBoxImpl->doAnimationWhenKeyboardMove(info.duration, info.end.getMaxY());
    }
#endif
}

void TLEditBox::keyboardDidShow( CCIMEKeyboardNotificationInfo& info )
{
}

void TLEditBox::keyboardWillHide( CCIMEKeyboardNotificationInfo& info )
{
    if( m_nKeyboardWillHideHandler > 0 )
    {
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.begin.origin.x );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.begin.origin.y );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.begin.size.width );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.begin.size.height );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.end.origin.x );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.end.origin.y );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.end.size.width );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.end.size.height );
		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( info.duration );

        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nKeyboardWillHideHandler, 9 );
    }

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    if (m_pEditBoxImpl != NULL) {
        m_pEditBoxImpl->closeKeyboard();
    }
#endif

}

void TLEditBox::keyboardDidHide( CCIMEKeyboardNotificationInfo& info )
{
}

void TLEditBox::insertText( const char* text, int len )
{
    if( m_nLength >= m_nMaxLength ){
        return;
    }

    //
    const char* szTemp = text;
    int nTempLength = 0;
    bool insert_flag = false;

    for( int i=0; i < len; ++i )
    {
        if( insert_flag )
            break;

        //
        char c = *( text + i );

        switch( m_eInputMode )
        {
        case TL_INPUT_TEXT_MODEL_NORMAL:
            {
                // 英文字符/数字/符号的话
                if( !( ( c & 0x80 ) == 0x80 ))
                {
                    nTempLength += 1;
                    break;
                }

                // 中文字符的话，n 将等于 3
                const char* pTemp = text + i;

                int mask,n;
                UTF8_COMPUTE( pTemp[0], mask, n );
                if( n == 3 )
                {
                    i += 2;
                    nTempLength += 2;

                    break;
                }

                // 其他都是非法字符
                insert_flag = true;
            }
            break;
        case TL_INPUT_TEXT_MODEL_NUMBER:
            {
                if( c < '0' || c > '9' )
                {
                    insert_flag = true;

                    break;
                }

                //
                nTempLength += 1;
            }
            break;
        case TL_INPUT_TEXT_MODEL_ENGLISH:
            {
                if( ( c & 0x80 ) == 0x80 )
                {
                    insert_flag = true;

                    break;
                }

                //
                nTempLength += 1;
            }
            break;
        case TL_INPUT_TEXT_MODEL_ENGLISHNUMBER:
            {
                // 不是数字，也不是英文字符
                if( ( c < '0' || c > '9' ) && ( ( c & 0x80 ) == 0x80 || ( !islower( c ) && !isupper( c ) ) ) )
                {
                    insert_flag = true;

                    break;
                }

                //
                nTempLength += 1;
            }
            break;
		case TL_INPUT_TEXT_MODEL_CHINAANDENGLISH:
			{
				// 数字或者英文字符的话
				if( ( c >= '0' && c <= '9' ) || ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) )
				{
					nTempLength += 1;

					break;
				}

				// 中文字符的话，n 将等于 3
				const char* pTemp = text + i;
				int mask,n;
				UTF8_COMPUTE( pTemp[0], mask, n );
				if( n == 3 )
				{
					i += 2;
					nTempLength += 2;

					break;
				}

				// 其他都是非法字符
				insert_flag = true;
			}
			break;
        case TL_INPUT_TEXT_MODEL_CHINAANDENGLISH_ONLY:
			{
				//第一个不能是数字
				if ( m_strText.length() == 0 && ( c >= '0' && c <= '9' ) )
				{
					break;
				}

				// 数字或英文字符的话
				if(  ( c >= '0' && c <= '9' ) || ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) )
				{
					nTempLength += 1;
					break;
				}

				// 中文字符的话，n 将等于 3
				const char* pTemp = text + i;
				int mask,n;
				UTF8_COMPUTE( pTemp[0], mask, n );
				char c1 =  ( unsigned char )pTemp[0];

				//过滤汉子以外的字符
				if( n == 3 && ( ( c1 & 0xff ) >= 0xE4 && ( c1 & 0xff ) <= 0xE9 ) )
                {
                    i += 2;
                    nTempLength += 2;

                    break;
                }

                // 如果不是中文的话，就进行自定义的判断
                std::string strText = std::string( pTemp, n );
                if( TLWindowManager::SharedTLWindowManager()->checkInputText( strText ) )
                {
                    i += ( n - 1 );
                    nTempLength += 1;

                    break;
                }


				// 其他都是非法字符
				insert_flag = true;
			}
			break;
		}

		//
		if( m_nLength + nTempLength >= m_nMaxLength )
        {
			insert_flag = true;
        }
	}

	//
	if( nTempLength > 0 )
	{
		m_nLength += nTempLength;

        //添加时使用utf8长度
		//m_strText.append( szTemp, nTempLength );
		m_strText.append( szTemp, strlen(szTemp) );

		m_pRichTex->setColor( m_kTextColor );
		m_pRichTex->setFontSize( m_nFontSize );

		if( m_eInputFlag == TL_INPUT_FLAG_PASSWORD )
		{
			std::string strTemp( m_nLength, '*' );
			m_pRichTex->setRichString( strTemp.c_str(), m_eRichFlag );
		}
		else
		{
			m_pRichTex->setRichString( m_strText.c_str(), m_eRichFlag );
		}

		m_pInputWindow->EventCallback( TL_EVENT_ENCHANGED );
	}
}

bool TLEditBox::checkText( const char* text, int len )
{
    //無效標誌
    bool is_invalid_flag = false;

    const char* szTemp = text;
    int nTempLength = 0;

    for( int i=0; i < len; ++i )
    {

        if( is_invalid_flag ){
            break;
        }

        //
        char c = *( text + i );

        switch( m_eInputMode )
        {
        case TL_INPUT_TEXT_MODEL_NORMAL:
            {
                // 英文字符/数字/符号的话
                if( !( ( c & 0x80 ) == 0x80 ))
                {
                    nTempLength += 1;

                    break;
                }

                // 中文字符的话，n 将等于 3
                const char* pTemp = text + i;

                int mask,n;
                UTF8_COMPUTE( pTemp[0], mask, n );
                if( n == 3 )
                {
                    i += 2;
                    nTempLength += 2;

                    break;
                }

                // 其他都是非法字符
                is_invalid_flag = true;
            }
            break;
        case TL_INPUT_TEXT_MODEL_NUMBER:
            {
                if( c < '0' || c > '9' )
                {
                    is_invalid_flag = true;
                    break;
                }

                //
                nTempLength += 1;
            }
            break;
        case TL_INPUT_TEXT_MODEL_ENGLISH:
            {
                if( ( c & 0x80 ) == 0x80 )
                {
                    is_invalid_flag = true;

                    break;
                }

                //
                nTempLength += 1;
            }
            break;
        case TL_INPUT_TEXT_MODEL_ENGLISHNUMBER:
            {
                // 不是空格字符
                if ( c == ' ') {
                    is_invalid_flag = true;
                    break;
                }


                // 不是数字，也不是英文字符
                if( ( c < '0' || c > '9' ) && ( ( c & 0x80 ) == 0x80 || ( !islower( c ) && !isupper( c ) ) ) )

                {
                    is_invalid_flag = true;
                    break;
                }

                //
                nTempLength += 1;
            }
            break;
		case TL_INPUT_TEXT_MODEL_CHINAANDENGLISH:
			{
				// 数字或者英文字符的话
				if( ( c >= '0' && c <= '9' ) || ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) )
				{
					nTempLength += 1;

					break;
				}

				// 中文字符的话，n 将等于 3
				const char* pTemp = text + i;
				int mask,n;
				UTF8_COMPUTE( pTemp[0], mask, n );
				if( n == 3 )
				{
					i += 2;
					nTempLength += 2;

					break;
				}

				// 其他都是非法字符
				is_invalid_flag = true;
			}
			break;
        case TL_INPUT_TEXT_MODEL_CHINAANDENGLISH_ONLY:
			{
				//第一个不能是数字
				if ( m_strText.length() == 0 && ( c >= '0' && c <= '9' ) )
				{
					break;
				}

				// 数字或英文字符的话
				if(  ( c >= '0' && c <= '9' ) || ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) )
				{
					nTempLength += 1;
					break;
				}

				// 中文字符的话，n 将等于 3
				const char* pTemp = text + i;
				int mask,n;
				UTF8_COMPUTE( pTemp[0], mask, n );
				char c1 =  ( unsigned char )pTemp[0];

				//过滤汉子以外的字符
				if( n == 3 && ( ( c1 & 0xff ) >= 0xE4 && ( c1 & 0xff ) <= 0xE9 ) )
				{
                    i += 2;
                    nTempLength += 2;

                    break;
                }

                // 如果不是中文的话，就进行自定义的判断
                std::string strText = std::string( pTemp, n );
                if( TLWindowManager::SharedTLWindowManager()->checkInputText( strText ) )
                {
                    i += ( n - 1 );
                    nTempLength += ( n - 1 );

                    break;
                }

				// 其他都是非法字符
				is_invalid_flag = true;
			}
			break;
		}

		if( nTempLength > m_nMaxLength )
        {
			is_invalid_flag = true;
        }

	}

    return !is_invalid_flag;
}


void TLEditBox::sentNetMsgToSelf( const char * text )
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    framework::AndroidEditTextMessage msgInfo;
    msgInfo.set_content(text);
    CNetReceiver::SharedNetReceiver()->SendMsgToSelf(208, &msgInfo);
#endif
}

void TLEditBox::deleteBackward()
{
    int mTempLength = m_strText.length();
    if( mTempLength <= 0 )
        return;

    int nDeleteLength = 1;

    while( 0x80 == ( 0xC0 & m_strText.at( mTempLength - nDeleteLength ) ) )
    {
        ++nDeleteLength;
    }

    // 全部被删掉了
    if( mTempLength <= nDeleteLength )
    {
        m_strText.clear();
        m_nLength = 0;

        m_pRichTex->setColor( m_kPlaceHolderColor );
        m_pRichTex->setFontSize( m_nPlaceFontSize );
        m_pRichTex->setRichString( m_strPlaceHolder.c_str(), m_eRichFlag );

        m_pRichTex->showCursor( true, true );

        return;
    }

    m_strText.erase( mTempLength - nDeleteLength );
    //m_nLength -= nDeleteLength;
    m_nLength = getTextLength(m_strText);

    m_pRichTex->setFontSize( m_nFontSize );
    if( m_eInputFlag == TL_INPUT_FLAG_PASSWORD )
    {
        std::string strTemp( m_nLength, '*' );
        m_pRichTex->setRichString( strTemp.c_str(), m_eRichFlag );
    }
    else
    {
        m_pRichTex->setRichString( m_strText.c_str(), m_eRichFlag );
    }
}

const char* TLEditBox::getContentText()
{
    return m_strText.c_str();
}

void TLEditBox::setText( const char* pszText )
{
    if( pszText != NULL )
    {
        m_strText = pszText;

        m_nLength = getTextLength(m_strText);

        if( !m_strText.empty() )
        {
            m_pRichTex->setColor( m_kTextColor );
            m_pRichTex->setFontSize( m_nFontSize );

            if( m_eInputFlag == TL_INPUT_FLAG_PASSWORD )
            {
                std::string strTemp( m_nLength, '*' );
                m_pRichTex->setRichString( strTemp.c_str(), m_eRichFlag );
            }
            else
            {
                m_pRichTex->setRichString( m_strText.c_str(), m_eRichFlag );
            }

            return;
        }
    }

    m_pRichTex->setColor( m_kPlaceHolderColor );
    m_pRichTex->setFontSize( m_nPlaceFontSize );
    m_pRichTex->setRichString( m_strPlaceHolder.c_str(), m_eRichFlag );
}

const char* TLEditBox::getText()
{
    return m_strText.c_str();
}

void TLEditBox::setTextColor( const ccColor3B& kTextColor )
{
    m_kTextColor = kTextColor;
}

const ccColor3B& TLEditBox::getTextColor()
{
    return m_kTextColor;
}

void TLEditBox::setPlaceHolder( const char* pszText )
{
    if( pszText != NULL )
    {
        m_strPlaceHolder = pszText;

        if( m_strText.empty() )
        {
            m_pRichTex->setColor( m_kPlaceHolderColor );
            m_pRichTex->setFontSize( m_nPlaceFontSize );
            m_pRichTex->setRichString( m_strPlaceHolder.c_str(), m_eRichFlag );
        }
    }
}

const char* TLEditBox::getPlaceHolder()
{
    return m_strPlaceHolder.c_str();
}

void TLEditBox::setPlaceHolderColor( const ccColor3B& kPlaceHolderColor )
{
    m_kPlaceHolderColor = kPlaceHolderColor;
}

const ccColor3B& TLEditBox::getPlaceHolderColor()
{
    return m_kPlaceHolderColor;
}

void TLEditBox::setFontSize( int nFontSize )
{
    m_nFontSize = nFontSize;
    if( !m_strText.empty() )
        m_pRichTex->setFontSize( nFontSize );
}

void TLEditBox::setPlaceFontSize( int nFontSize )
{
    m_nPlaceFontSize = nFontSize;
    if( m_strText.empty() )
        m_pRichTex->setFontSize( nFontSize );
}

void TLEditBox::setRichFlag( TL_RICH_STRING_FLAG eRichFlag )
{
    m_eRichFlag = eRichFlag;
}

void TLEditBox::setAlignment( CCImage::ETextAlign eAlignment )
{
    m_pRichTex->setAlignment( eAlignment );
}

void TLEditBox::setInputMode( TL_INPUT_TEXT_MODEL eInputMode )
{
    m_eInputMode = eInputMode;
}

void TLEditBox::setMaxLength( int nMaxLength )
{
    m_nMaxLength = nMaxLength;
}

int TLEditBox::getMaxLength()
{
    return m_nMaxLength;
}

void TLEditBox::setInputFlag( TL_INPUT_FLAG eInputFlag )
{
    m_eInputFlag = eInputFlag;
}

void TLEditBox::setReturnType( TL_RETURN_TYPE eReturnType )
{
    m_eReturnType = eReturnType;
}

void TLEditBox::setKeyboardWillShowHandler( int nWillShowHandler )
{
    if( m_nKeyboardWillShowHandler != 0 )
        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nKeyboardWillShowHandler );

    m_nKeyboardWillShowHandler = nWillShowHandler;
}

void TLEditBox::setKeyboardWillHideHandler( int nWillHideHandler )
{
    if( m_nKeyboardWillHideHandler != 0 )
        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nKeyboardWillHideHandler );

    m_nKeyboardWillHideHandler = nWillHideHandler;
}

CCSize TLEditBox::getRealSize()
{
    return m_pRichTex->getRealSize();
}
