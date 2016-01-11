#include "TLMaskLayer.h"
#include <CCDirector.h>
#include "CCLuaEngine.h"
#include "shaders/CCShaderCache.h"
#include "MC/MCLoader.h"

//////////////////////////////////////////////////////////////////////////
TLMaskLayer::TLMaskLayer()
{
    const CCSize& winSize = CCDirector::sharedDirector()->getWinSize();
    m_pMaskSprite = CCSprite::createWithTexture( MCLoader::sharedMCLoader()->getDefaultTexture(), CCRectMake( 0, 0, winSize.width, winSize.height ) );
    m_pMaskSprite->setVisible( false );
    addChild( m_pMaskSprite );

    m_pMaskSprite->setTLTextureCoords( 0.0f, 0.0f );
    m_pMaskSprite->setBLTextureCoords( 0.0f, 1.0f );
    m_pMaskSprite->setTRTextureCoords( 1.0f, 0.0f );
    m_pMaskSprite->setBRTextureCoords( 1.0f, 1.0f );

    CCGLProgram* pShaderProgram = CCShaderCache::sharedShaderCache()->programForKey( "position_texture_ellipse_mask_layer" );
    m_pMaskSprite->setShaderProgram( pShaderProgram );

    m_pMaskSprite->setPosition( CCPoint( winSize.width / 2, winSize.height / 2 ) );
}

TLMaskLayer::~TLMaskLayer()
{
}

void TLMaskLayer::visit()
{
    CCLayer::visit();
}

TLMaskLayer* g_pTLMaskLayer = NULL;
TLMaskLayer* TLMaskLayer::sharedTLMaskLayer()
{
	if( g_pTLMaskLayer == NULL )
	{
		g_pTLMaskLayer = new TLMaskLayer();
		if( g_pTLMaskLayer && g_pTLMaskLayer->init() )
		{
			g_pTLMaskLayer->autorelease();
			return g_pTLMaskLayer;
		}
		else
		{
			CC_SAFE_DELETE( g_pTLMaskLayer );
		}
	}

	return g_pTLMaskLayer;
}

void TLMaskLayer::resetMaskLayer()
{
    m_pMaskSprite->setVisible( false );
    m_pMaskSprite->removeAllChildrenWithCleanup( true );

	m_pMaskSprite->setCustomUniforms( 0.0, 0.0, 0.0, 0.0 );
	m_pMaskSprite->setCustomUniformsEx( 0.0, 0.0, 0.0, 0.0 );
}

void TLMaskLayer::setIsMaskScene( bool bMaskScene )
{
    m_pMaskSprite->setVisible( bMaskScene );
}

void TLMaskLayer::appendHighlightRect( const CCRect& rect )
{
	const CCSize& winSize = CCDirector::sharedDirector()->getWinSize();

    // 扩大 20 %
    float temp_width = rect.size.width * 0.15;
    float temp_height = rect.size.height * 0.15;

    float new_width = rect.size.width + temp_width * 2;
    float new_height = rect.size.height + temp_height * 2;
    float new_x = rect.origin.x - temp_width;
    float new_y = rect.origin.y - temp_height;

    float a = new_width * 0.5 / winSize.width;
    float b = new_height * 0.5 / winSize.height;
    float x1 = ( new_x + new_width * 0.5 ) / winSize.width;
    float y1 = ( winSize.height - new_y - new_height * 0.5 ) / winSize.height;
	m_pMaskSprite->setCustomUniforms( x1, y1, a, b );
}

void TLMaskLayer::appendHighlightRect2( const CCRect& rect )
{
    const CCSize& winSize = CCDirector::sharedDirector()->getWinSize();

    // 扩大 20 %
    float temp_width = rect.size.width * 0.15;
    float temp_height = rect.size.height * 0.15;

    float new_width = rect.size.width + temp_width * 2;
    float new_height = rect.size.height + temp_height * 2;
    float new_x = rect.origin.x - temp_width;
    float new_y = rect.origin.y - temp_height;

    float a = new_width * 0.5 / winSize.width;
    float b = new_height * 0.5 / winSize.height;
    float x1 = ( new_x + new_width * 0.5 ) / winSize.width;
    float y1 = ( winSize.height - new_y - new_height * 0.5 ) / winSize.height;
	m_pMaskSprite->setCustomUniformsEx( x1, y1, a, b );
}

void TLMaskLayer::setMaskColor( float r, float g, float b, float a )
{
	m_pMaskSprite->setColor( ccc3( r * 255, g * 255, b * 255 ) );
	m_pMaskSprite->setOpacity( a * 255 );
}

void TLMaskLayer::test()
{
	resetMaskLayer();

	appendHighlightRect( CCRectMake( 0, 0, 100, 100 ) );

	setMaskColor( 0, 0, 0, 0 );
}


