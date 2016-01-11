#include "ClipNode.h"

#include "CCEGLView.h"
#include "CCPointExtension.h"
#include "CCDirector.h"
#include "../Common/TLCommon.h"

ClipNode::ClipNode(void)
: m_hasClipRegion(false)
, m_clipRegion(CCRectZero)
{	
	//_cascadeColorEnabled   = true;
	_cascadeOpacityEnabled = true;
}

ClipNode::~ClipNode(void)
{
}

ClipNode * ClipNode::clipNode()
{
	ClipNode* pRet = new ClipNode();
	pRet->autorelease();
	return pRet;
}


ClipNode* ClipNode::clipNode(CCRect region)
{
    ClipNode* pRet = ClipNode::clipNode();
    pRet->setClipRegion(region);
    return pRet;
}

void ClipNode::setPosition( const CCPoint& newPosition )
{
	CCNode::setPosition( newPosition );
}

void ClipNode::setClipRegion( CCRect region )
{
	m_clipRegion = region;
	m_hasClipRegion = true;
	//m_hasClipRegion = false;
}

void ClipNode::visit()
{
    // quick return if not visible
    if( !isVisible() )
        return;

    GLboolean isEnabled = glIsEnabled( GL_SCISSOR_TEST );
    GLint oldScissor[4];

    if( m_hasClipRegion )
    {
        if( isEnabled == GL_FALSE )
        {
            glEnable( GL_SCISSOR_TEST );
        }
        else
        {
            glGetIntegerv( GL_SCISSOR_BOX, oldScissor );
        }

        CCRect rect;
        if( getRenderNodeFlag() || CC_CONTENT_SCALE_FACTOR() == 1 )
        {
            rect = CCRectApplyAffineTransform( m_clipRegion, nodeToWorldTransform() );
        }
        else
        {
            rect.origin = ccpMult( m_clipRegion.origin, CC_CONTENT_SCALE_FACTOR() );
            rect.size.width  = m_clipRegion.size.width  * CC_CONTENT_SCALE_FACTOR();
            rect.size.height = m_clipRegion.size.height * CC_CONTENT_SCALE_FACTOR();

            rect = CCRectApplyAffineTransform(rect, nodeToWorldTransform());

            rect.origin = ccpMult( rect.origin, 1/CC_CONTENT_SCALE_FACTOR() );
            rect.size.width  = rect.size.width  * (1/CC_CONTENT_SCALE_FACTOR());
            rect.size.height = rect.size.height * (1/CC_CONTENT_SCALE_FACTOR());
        }

        if( getRenderNodeFlag() )
        {
			int vp[4];
			glGetIntegerv( GL_VIEWPORT, vp );
			glScissor( (GLint)(rect.origin.x + vp[0]), (GLint)(rect.origin.y + vp[1]), (GLsizei)(rect.size.width), (GLsizei)(rect.size.height) );
        }
        else
        {
            CCEGLView::sharedOpenGLView()->setScissorInPoints( rect.origin.x, rect.origin.y, rect.size.width, rect.size.height );
        }

        if( isEnabled )
        {
            GLint tempScissor[4];
            glGetIntegerv( GL_SCISSOR_BOX, tempScissor );

            GLint x = oldScissor[0] > tempScissor[0] ? oldScissor[0] : tempScissor[0];
            GLint y = oldScissor[1] > tempScissor[1] ? oldScissor[1] : tempScissor[1];

            GLint temp_x_1 = oldScissor[0] + oldScissor[2];
            GLint temp_x_2 = tempScissor[0] + tempScissor[2];
            GLint temp_x = temp_x_1 < temp_x_2 ? temp_x_1 : temp_x_2;

            GLint temp_y_1 = oldScissor[1] + oldScissor[3];
            GLint temp_y_2 = tempScissor[1] + tempScissor[3];
            GLint temp_y = temp_y_1 < temp_y_2 ? temp_y_1 : temp_y_2;

            GLsizei width = ( temp_x - x ) > 0 ? ( temp_x - x ) : 0;
            GLsizei height = ( temp_y - y ) > 0 ? ( temp_y - y ) : 0;
            glScissor( x, y, width, height );
        }
    }

    CCNode::visit();

    if( m_hasClipRegion )
    {
        if( isEnabled == GL_FALSE )
        {
            glDisable( GL_SCISSOR_TEST );
        }
        else
        {
            glScissor( oldScissor[0], oldScissor[1], oldScissor[2], oldScissor[3] );
        }
    }
}
