#pragma once

#include "cocos2d.h"
#include "ClipNode.h"
//#include "misc_nodes/CCClippingNode.h"

USING_NS_CC;

class MCFrame: public ClipNode
//class MCFrame: public CCClippingNode
{
public:
    MCFrame() { m_nodeType = ND_FRAME; }
	virtual ~MCFrame() {}

    static MCFrame* createWithBox( CCRect rect );
    bool initWithBox( CCRect rect );

    virtual void setScaleX(float fScaleX);
    virtual void setScaleY(float fScaleY);
    virtual void setScale(float scale);

    //void setClipRegion( CCRect region );
    //void clipRegionEnable( bool bEnable );

    CCRect mcBoundingBox;
    CCRect mcOriginBoundingBox;
};

