#include "TLTextFieldDelegate.h"
#include "TLWindow.h"
#include "../MC/MCLoader.h"

TLTextFieldDelegate::TLTextFieldDelegate( TLWindow* pInputWindow, float fFontSize, const char* placeholder, TL_RICH_STRING_FLAG eRichStringFlag )
: m_pInputWindow(pInputWindow)
, m_kInputTextModel(TL_INPUT_TEXT_MODEL_NORMAL)
, m_nInputLimit(1024)
, m_fFontSize(fFontSize)
, m_nErroHandler(0)
, m_nInputApendLine(1)
, m_nInputReturnHandler(0)
{
	m_kTextFieldSize = m_pInputWindow->GetWindowRect().size;

	m_pTextFiledTexFont = TLTextField::textFieldWithPlaceHolder( placeholder, m_kTextFieldSize, CCImage::kAlignLeft, fFontSize, eRichStringFlag );
    m_pTextFiledTexFont->retain();
	m_pTextFiledTexFont->setDelegate( this );

	m_pInputWindow->GetNode()->addChild( m_pTextFiledTexFont );
}

TLTextFieldDelegate::~TLTextFieldDelegate()
{
    m_pTextFiledTexFont->setDelegate( NULL );
    m_pTextFiledTexFont->release();
}

void TLTextFieldDelegate::setCursorSize(float  x, float y)
{
	if ( m_pTextFiledTexFont != NULL )
	{
		m_pTextFiledTexFont->setCursorSize(x, y);
	}
}

bool TLTextFieldDelegate::RegisterInputReturnCallbackHandler( int funcHandler )
{
	if( m_nInputReturnHandler != 0 )
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nInputReturnHandler );
    
	m_nInputReturnHandler = funcHandler;
    
	return true;
}

void TLTextFieldDelegate::executeInputReturnFunc()
{
	if( m_nInputReturnHandler != 0 )
		CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nInputReturnHandler, 0 );
}

bool TLTextFieldDelegate::RegisterErroTipCallbackHandler( int errofuncHandler )
{
	if( m_nErroHandler != 0 )
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nErroHandler );

	m_nErroHandler = errofuncHandler;

	return true;
}

void TLTextFieldDelegate::executeErroFunc()
{
	if( m_nErroHandler != 0 )
		CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nErroHandler, 0 );
}

bool TLTextFieldDelegate::onTextFieldInsertText( TLTextField* pSender, const char* text, int nLen )
{
	if( pSender->getCharCount() >= m_nInputLimit )
		return true;

	switch( m_kInputTextModel )
	{
	case TL_INPUT_TEXT_MODEL_NUMBER:
		{
			for( int i=0; i < nLen; ++i )
			{
				char c = *( text + i );
				if( c < '0' || c > '9' )
					return true;
			}
		}
		break;
	case TL_INPUT_TEXT_MODEL_ENGLISH:
	//case TL_INPUT_TEXT_MODEL_PASSWORD:
		{
			for( int i=0; i < nLen; ++i )
			{
				char c = *( text + i );
				if( ( c & 0x80 ) == 0x80 )
					return true;
			}
		}
	case TL_INPUT_TEXT_MODEL_ENGLISHNUMBER:
		{
			bool bNoNumber = false;
			for( int i=0; i < nLen; ++i )
			{
				char c = *( text + i );
				if( c < '0' || c > '9' )
				{
					bNoNumber = true;
					break;
				}
			}

			bool bNoEnglish = false;
			for( int i=0; i < nLen; ++i )
			{
				char c = *( text + i );
				if( ( c & 0x80 ) == 0x80 || ( !islower(c) && !isupper(c) ) )
				{
					bNoEnglish = true;
					break;
				}
			}

			if (bNoNumber && bNoEnglish) 
			{
				return true;
			}
		}
		case TL_INPUT_TEXT_MODEL_CHINAANDENGLISH:
			{ 
				//hb添加创建角色可以是中文加英文数字屏蔽了英文上的特殊符号
				bool bNoNumber = false;
				for( int i=0; i < nLen; ++i )
				{
					char c = *( text + i );
					if( c < '0' || c > '9' )
					{
						bNoNumber = true;
						break;
					}
				}

				bool bNoEnglish = false;
				for( int i=0; i < nLen; ++i )
				{
					char c = *( text + i );
					if( ( c & 0x80 ) == 0x80 || ( !islower(c) && !isupper(c) ) )
					{
						bNoEnglish = true;
						break;
					}
				}
				bool bSing = false;
				if (bNoNumber && bNoEnglish) //假如不是数字也不是英文的话
				{
					for( int i=0; i < nLen; ++i )
					{
						char c = *( text + i );
						if( c > 0 && c < 127 )
						{
							bSing = true;
							break;
						}
					}
				}
				if (bNoNumber && bNoEnglish&&bSing) 
				{
					return true;
				}
			
			}
	}
	
	return false;
}

bool TLTextFieldDelegate::onTextFieldDeleteBackward( TLTextField * sender, const char * delText, int nLen )
{
	return false;
}

bool TLTextFieldDelegate::onTextFieldAttachWithIME( TLTextField* sender )
{
	return false;
}

bool TLTextFieldDelegate::onTextFieldDetachWithIME( TLTextField* sender )
{
	return false;
}

bool TLTextFieldDelegate::onDraw( TLTextField* pSender )
{
	return false;
}

void TLTextFieldDelegate::SetInputTextModel( TL_INPUT_TEXT_MODEL kInputTextModel )
{
	m_kInputTextModel = kInputTextModel;
	// 修改密码格式显示
	if ( m_pTextFiledTexFont != NULL )
	{
		//if ( kInputTextModel == TL_INPUT_TEXT_MODEL_PASSWORD ) 
		//{
		//	m_pTextFiledTexFont->setSecureTextEntry(true);
		//}
		//else
		//{
			m_pTextFiledTexFont->setSecureTextEntry(false);
		//}
	}
}

bool TLTextFieldDelegate::onTextFieldChanged( TLTextField* pSender )
{
	m_pInputWindow->EventCallback( TL_EVENT_ENCHANGED );
	return true;
}

void TLTextFieldDelegate::SetInputApendLine( int model )
{
	m_nInputApendLine = model;
}

void TLTextFieldDelegate::SetInputAlignment( CCImage::ETextAlign eAlignment )
{
    m_pTextFiledTexFont->setAlignment( eAlignment );
}

