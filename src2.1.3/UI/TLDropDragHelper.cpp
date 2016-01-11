#include "TLDropDragHelper.h"
#include "../MC/MCLoader.h"
#include "../MC/MovieClip.h"
#include "../Common/TLCommon.h"

TLDropDragHelper::TLDropDragHelper()
: m_bIsDropDraging(false)
, m_pSourceWindow(NULL)
, m_bIsEventBubble(true)
{
	m_pDropDragNode = CCNode::create();
	m_pDropDragNode->retain();
}

TLDropDragHelper::~TLDropDragHelper()
{
	m_pDropDragNode->release();
	m_pDropDragNode = NULL;
}

void TLDropDragHelper::Reset()
{
	m_bIsDropDraging = false;
	m_pSourceWindow = NULL;
    m_bIsEventBubble = true;
}

void TLDropDragHelper::AppendShowIcon( unsigned int uiResID, const char* strTempName )
{	
	CCSpriteFrame* pSpriteFrame = MCLoader::sharedMCLoader()->loadSpriteFrame( strTempName );
	if( pSpriteFrame != NULL )
	{
		CCSprite* pSprite = cocos2d::CCSprite::createWithSpriteFrame( pSpriteFrame );

		m_pDropDragNode->addChild( pSprite );
	}
}

void TLDropDragHelper::AppendShowModel( unsigned int uiResID, const char* strTempName )
{	
	MovieClip* pNode = MovieClip::createWithName( strTempName );
	if( pNode != NULL )
	{
		pNode->play( 0, -1, -1 );

		m_pDropDragNode->addChild( pNode );
	}
}

void TLDropDragHelper::AppendShow( CCNode* pNode )
{
	if( pNode != NULL )
		m_pDropDragNode->addChild( pNode );
}

void TLDropDragHelper::setDDPosition( const CCPoint& point, bool first )
{
    if( first )
        m_kLastPos = point;

    if( abs( point.x - m_kLastPos.x ) > 20.0f || abs( point.y - m_kLastPos.y ) > 20.0f )
        m_bIsEventBubble = false;

    m_pDropDragNode->setPosition( point );
}
