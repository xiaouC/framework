#include "BatchNodeMC.h"
#include "MCLoader.h"
#include "anim.pb.h"

//////////////////////////////////////////////////////////////////////////
MainSceneRoleMC::MainSceneRoleMC( CCSpriteBatchNode* pkBatchNode )
: m_bFlipX(false)
, m_bFlipY(false)
, m_kRoleSpriteOffset(CCPointZero)
, m_bIsInitBoundingBox(false)
, m_bIsStand( true )
, m_nCurrentFrameIndex(0)
, m_fFrameTimeInterval(0.33f)
, m_fElapsedTime(0.0f)
, m_nStandRate(6)
, m_nWalkRate(12)
{
    m_pRoleSprite = CCSprite::createWithTexture( pkBatchNode->getTexture(), CCRectZero );
    m_pRoleSprite->retain();

    pkBatchNode->addChild( m_pRoleSprite );

    pkBatchNode->getParent()->addChild( this, 2 );

    scheduleUpdate();
}

MainSceneRoleMC::~MainSceneRoleMC()
{
}

MainSceneRoleMC* MainSceneRoleMC::createWithName( const char* mcStandName, const char* mcWalkName, CCSpriteBatchNode* pkBatchNode )
{
    MainSceneRoleMC* mc = new MainSceneRoleMC( pkBatchNode );
    if( mc && mc->initWithName( mcStandName, mc->m_vecStandKeyFrames ) )
    {
        if( mcWalkName != NULL )
            mc->initWithName( mcWalkName, mc->m_vecWalkKeyFrames );

        mc->autorelease();

        return mc;
    }

    CC_SAFE_DELETE( mc );

    return NULL;
}

bool MainSceneRoleMC::initWithName( const char* mcName, std::vector<KeyFrameInfo*>& vecKeyFrames )
{
    if( mcName == NULL )
        return false;

    const framework::Symbol* sym = MCLoader::sharedMCLoader()->getSymbol( mcName );
    if( sym == NULL || sym->framecount() <= 0 )
        return false;

    if( !m_bIsInitBoundingBox )
    {
        m_bIsInitBoundingBox = true;

        const framework::Rect& r = sym->boundingbox();
        mcBoundingBox = CCRectMake( r.x(), r.y(), r.w(), r.h() );
        setContentSize( mcBoundingBox.size );
    }

    const framework::Layer& layer = sym->layers( 0 );
    if( layer.keyframes_size() == 0 )
        return false;

    for( int i=0; i < layer.keyframes_size(); ++i )
    {
		const framework::Keyframe& kf = layer.keyframes( i );
		if( kf.elements_size() <= 0 )
			continue;

        const framework::Element& elem = kf.elements( 0 );
        if( (NodeType)( elem.type() ) != ND_BITMAP )
            continue;

        KeyFrameInfo* pKeyFrameInfo = new KeyFrameInfo;
        pKeyFrameInfo->pkSpriteFrame = MCLoader::sharedMCLoader()->loadSpriteFrame( elem.libname().c_str() );
        pKeyFrameInfo->pkSpriteFrame->retain();

        const framework::Point& p = elem.position();
        pKeyFrameInfo->kOffset = ccp( p.x(), p.y() );

        vecKeyFrames.push_back( pKeyFrameInfo );
    }

    return true;
}

MainSceneRoleMC::KeyFrameInfo* MainSceneRoleMC::getCurrentKeyFrameInfo()
{
    if( m_bIsStand )
    {
        int nRealIndex = m_nCurrentFrameIndex % m_vecStandKeyFrames.size();
        return m_vecStandKeyFrames[nRealIndex];
    }

    int nRealIndex = m_nCurrentFrameIndex % m_vecWalkKeyFrames.size();
    return m_vecWalkKeyFrames[nRealIndex];
}

void MainSceneRoleMC::setRoleSpriteFrame( int nSpriteFrameIndex )
{
    m_nCurrentFrameIndex = nSpriteFrameIndex;

    resetRoleSpritePosition( true );
}

void MainSceneRoleMC::resetRoleSpritePosition( bool resetDisplaySpriteFrame )
{
    float x = getPositionX();
    float y = getPositionY();

    KeyFrameInfo* kfi = getCurrentKeyFrameInfo();

    if( resetDisplaySpriteFrame )
        m_pRoleSprite->setDisplayFrame( kfi->pkSpriteFrame );

    float scaleX = getScaleX();
    float scaleY = getScaleY();

    x += ( m_bFlipX ? -kfi->kOffset.x : kfi->kOffset.x ) * scaleX;
    y += ( m_bFlipY ? -kfi->kOffset.y : kfi->kOffset.y ) * scaleY;

    x += ( m_bFlipX ? -m_kRoleSpriteOffset.x : m_kRoleSpriteOffset.x );
    y += ( m_bFlipY ? -m_kRoleSpriteOffset.y : m_kRoleSpriteOffset.y );

    m_pRoleSprite->setPosition( ccp( x, y ) );
}

void MainSceneRoleMC::update( float dt )
{
    m_fElapsedTime += dt;

    if( m_fElapsedTime >= ( m_nCurrentFrameIndex + 1 ) * m_fFrameTimeInterval )
    {
        m_nCurrentFrameIndex = (int)( m_fElapsedTime / m_fFrameTimeInterval );

        setRoleSpriteFrame( m_nCurrentFrameIndex );
    }
}

void MainSceneRoleMC::onExit()
{
    unscheduleUpdate();

    for( int i=0; i < (int)m_vecStandKeyFrames.size(); ++i )
        m_vecStandKeyFrames[i]->pkSpriteFrame->release();
    m_vecStandKeyFrames.clear();

    for( int i=0; i < (int)m_vecWalkKeyFrames.size(); ++i )
        m_vecWalkKeyFrames[i]->pkSpriteFrame->release();
    m_vecWalkKeyFrames.clear();

    m_pRoleSprite->removeFromParentAndCleanup( true );
    m_pRoleSprite->release();
    m_pRoleSprite = NULL;
}

void MainSceneRoleMC::setVisible( bool bVisible )
{
    m_pRoleSprite->setVisible( bVisible );

    CCNode::setVisible( bVisible );
}

void MainSceneRoleMC::setPosition( float x, float y )
{
    CCNode::setPosition( x, y );

    resetRoleSpritePosition();
}

void MainSceneRoleMC::setScaleX( float scaleX )
{
    m_pRoleSprite->setScaleX( scaleX );

    CCNode::setScaleX( scaleX );
}

void MainSceneRoleMC::setScaleY( float scaleY )
{
    m_pRoleSprite->setScaleY( scaleY );

    CCNode::setScaleY( scaleY );
}

void MainSceneRoleMC::setFlipX( bool bFlipX )
{
    m_bFlipX = bFlipX;

    m_pRoleSprite->setFlipX( bFlipX );

    resetRoleSpritePosition();
}

void MainSceneRoleMC::setFlipY( bool bFlipY )
{
    m_bFlipY = bFlipY;

    m_pRoleSprite->setFlipY( bFlipY );

    resetRoleSpritePosition();
}

void MainSceneRoleMC::playStand()
{
    m_bIsStand = true;
    m_nCurrentFrameIndex = 0;

    m_fFrameTimeInterval = 1.0f / m_nStandRate;
    m_fElapsedTime = 0.0f;

    setRoleSpriteFrame( m_nCurrentFrameIndex );

}

void MainSceneRoleMC::playWalk()
{
    m_bIsStand = false;
    m_nCurrentFrameIndex = 0;

    m_fFrameTimeInterval = 1.0f / m_nWalkRate;
    m_fElapsedTime = 0.0f;

    setRoleSpriteFrame( m_nCurrentFrameIndex );
}
