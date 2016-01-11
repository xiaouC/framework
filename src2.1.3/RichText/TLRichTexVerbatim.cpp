#include "TLRichTexVerbatim.h"
#include "CCLuaEngine.h"

TLRichTexVerbatim::TLRichTexVerbatim()
: m_bEnd(true)
, m_Time(0)
, m_nCurIdx(0)
, m_nLastIdx(0)
, m_fCurInterval(0.05f)
, m_fOriginInterval(0.05f)
, m_nPlayEndHandler(0)
{	
}

TLRichTexVerbatim::~TLRichTexVerbatim()
{
}

void TLRichTexVerbatim::update( float dt )
{
	m_Time += dt;

    if( m_nCurIdx < m_nElementCount )
    {
        while( m_Time >= m_fCurInterval )
        {
            CCNode* pNode = TLLabelRichTex::getChildByTag( m_nCurIdx );
            if( pNode != NULL )
                pNode->setVisible( true );

            m_Time -= m_fCurInterval;

            ++m_nCurIdx;
            if( m_nCurIdx >= m_nElementCount )
            {
                m_nCurIdx = m_nElementCount;

                m_Time = 0;
            }
        }
    }

    if( m_nCurIdx >= m_nElementCount && m_Time >= m_fCurInterval )
    {
        stop();
    }
}

bool TLRichTexVerbatim::isEnd()
{
	return this->m_bEnd;
}

void TLRichTexVerbatim::fastEnd()
{
	if (m_bEnd)
	{
		return;
	}

	m_fCurInterval = 0.005f;
}

void TLRichTexVerbatim::setRichString( const char* str, TL_RICH_STRING_FLAG eRichStringFlag )
{
	TLLabelRichTex::setRichString( str, eRichStringFlag );

	for( int i = 0; i < m_nElementCount; i++ )
	{
		CCNode* pNode = TLLabelRichTex::getChildByTag( i );
		if( pNode != NULL )
			pNode->setVisible( false );
	}

	m_bEnd = true;
	m_Time = 0;
	m_nCurIdx = 0;
}

void TLRichTexVerbatim::play( int nPlayEndHandler )
{
	stop();

    m_nPlayEndHandler = nPlayEndHandler;

	scheduleUpdate();

	m_bEnd = false;
	m_Time = 0;
	m_nCurIdx = 0;
	m_nLastIdx = 0;
}

void TLRichTexVerbatim::setSpeed( float nSpeed )
{
	m_fOriginInterval = nSpeed;
}

TLRichTexVerbatim* TLRichTexVerbatim::create( const char* str, float fFontSize, const CCSize& size, const CCImage::ETextAlign& alignment )
{
	TLRichTexVerbatim* pRet = new TLRichTexVerbatim;
	if( pRet && pRet->initWithString( str, fFontSize, size, alignment ) )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE( pRet );
	return NULL;
}

bool TLRichTexVerbatim::initWithString( const char* str, float fFontSize, const CCSize& size, const CCImage::ETextAlign& alignment )
{
	if( !TLLabelRichTex::initWithString( str, fFontSize, size, alignment ) )
		return false;

	return true;
}

void TLRichTexVerbatim::stop()
{
	unscheduleUpdate();
	m_fCurInterval = m_fOriginInterval;
	m_bEnd = true;

    if( m_nPlayEndHandler > 0 )
    {
        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nPlayEndHandler, 0 );

        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nPlayEndHandler );
        m_nPlayEndHandler = 0;
    }
}
