#include "MCFrame.h"

MCFrame* MCFrame::createWithBox( CCRect rect )
{
    MCFrame* mc = new MCFrame;
    if( mc && mc->initWithBox( rect ) )
    {
        mc->autorelease();
        return mc;
    }
    CC_SAFE_DELETE( mc );
    return NULL;
}

bool MCFrame::initWithBox( CCRect rect )
{
    mcOriginBoundingBox = rect;
    mcBoundingBox = mcOriginBoundingBox;
    setContentSize( rect.size );

    return true;
}

void MCFrame::setScaleX(float fScaleX)
{
    ClipNode::setScaleX( fScaleX );

    mcBoundingBox.origin.x = mcOriginBoundingBox.origin.x * fScaleX;
    mcBoundingBox.size.width = mcOriginBoundingBox.size.width * fScaleX;
}

void MCFrame::setScaleY(float fScaleY)
{
    ClipNode::setScaleY( fScaleY );

    mcBoundingBox.origin.y = mcOriginBoundingBox.origin.y * fScaleY;
    mcBoundingBox.size.height = mcOriginBoundingBox.size.height * fScaleY;
}

void MCFrame::setScale(float fScale)
{
    ClipNode::setScale( fScale );

    mcBoundingBox.origin.x = mcOriginBoundingBox.origin.x * fScale;
    mcBoundingBox.origin.y = mcOriginBoundingBox.origin.y * fScale;
    mcBoundingBox.size.width = mcOriginBoundingBox.size.width * fScale;
    mcBoundingBox.size.height = mcOriginBoundingBox.size.height * fScale;
}
