#pragma once
#include <vector>
#include "sprite_nodes/CCSpriteBatchNode.h"
#include "sprite_nodes/CCSpriteFrame.h"

USING_NS_CC;

class MainSceneRoleMC: public CCNode
{
public:
    CCRect mcBoundingBox;

    MainSceneRoleMC( CCSpriteBatchNode* pkBatchNode );
    virtual ~MainSceneRoleMC();

    static MainSceneRoleMC* createWithName( const char* mcStandName, const char* mcWalkName, CCSpriteBatchNode* pkBatchNode );

    virtual void update( float dt );
    virtual void onExit();
    virtual void setVisible( bool bVisible );
    virtual void setPosition( float x, float y );
    void setScaleX( float scaleX );
    void setScaleY( float scaleY );
    void setFlipX( bool bFlipX );
    void setFlipY( bool bFlipY );

public:
    CCSprite* getRoleSprite() const { return m_pRoleSprite; }

    void setRoleSpriteOffsetX( float offsetX ) { m_kRoleSpriteOffset.x = offsetX; }
    float getRoleSpriteOffsetX() const { return m_kRoleSpriteOffset.x; }

    void setRoleSpriteOffsetY( float offsetY ) { m_kRoleSpriteOffset.y = offsetY; }
    float getRoleSpriteOffsetY() const { return m_kRoleSpriteOffset.y; }

    void resetRoleSpritePosition( bool resetDisplaySpriteFrame = false );

protected:
    struct KeyFrameInfo
    {
        CCSpriteFrame* pkSpriteFrame;
        CCPoint kOffset;
    };
    std::vector<KeyFrameInfo*> m_vecStandKeyFrames;
    std::vector<KeyFrameInfo*> m_vecWalkKeyFrames;

    bool initWithName( const char* mcName, std::vector<KeyFrameInfo*>& vecKeyFrames );
    KeyFrameInfo* getCurrentKeyFrameInfo();

    void setRoleSpriteFrame( int nSpriteFrameIndex );

    CCSprite* m_pRoleSprite;
    bool m_bFlipX,m_bFlipY;
    CCPoint m_kRoleSpriteOffset;

    bool m_bIsInitBoundingBox;
public:
    void playStand();
    void playWalk();

    void setFrameRate( int nStandRate, int nWalkRate ) { m_nStandRate = nStandRate; m_nWalkRate = nWalkRate; }

protected:
    bool m_bIsStand;
    int m_nCurrentFrameIndex;
    float m_fFrameTimeInterval;
    float m_fElapsedTime;

    int m_nStandRate;
    int m_nWalkRate;
};

