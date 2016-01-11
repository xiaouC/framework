
#include "TLRenderNode.h"
#include "shaders/CCShaderCache.h"
#include "kazmath/GL/matrix.h"
#include "CCEGLView.h"
#include <CCDirector.h>
#include "../Common/TLCommon.h"

std::set<TLRenderNode*> TLRenderNode::listNodes;

void TLRenderNode::resume()
{
/*
	std::set<TLRenderNode*>::iterator iter = listNodes.begin();
	for( ; iter != listNodes.end(); ++iter )
	{
		TLRenderNode* pNode = *iter;
		pNode->initRender();
	}
*/
}

void TLRenderNode::pause()
{
	std::set<TLRenderNode*>::iterator iter = listNodes.begin();
	for( ; iter != listNodes.end(); ++iter )
	{
		TLRenderNode* pNode = *iter;
		pNode->removeRender();
	}
}


TLRenderNode* TLRenderNode::create( CCNode* pContentNode, float width, float height )
{
	TLRenderNode * pRet = new TLRenderNode( pContentNode );
    if (pRet && pRet->init())
    {
        pRet->autorelease();
		pRet->setRenderSize(CCSize(width, height));
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
	return pRet;
}

TLRenderNode::TLRenderNode( CCNode* pContentNode )
: m_pRender( NULL )
, m_pContentNode(pContentNode)
, m_sShaderName(kCCShader_PositionTextureColor)
, m_bUseRender( false )
, m_bRecreateRenderTexture(true)
{
	m_nodeType = ND_RENDERNODE;
    m_pContentNode->retain();

	m_fCustomUniforms[0] = 0.0f;
	m_fCustomUniforms[1] = 0.0f;
	m_fCustomUniforms[2] = 0.0f;
	m_fCustomUniforms[3] = 0.0f;

	m_fCustomUniformsEx[0] = 0.0f;
	m_fCustomUniformsEx[1] = 0.0f;
	m_fCustomUniformsEx[2] = 0.0f;
	m_fCustomUniformsEx[3] = 0.0f;

    ccBlendFunc tBlendFunc = {GL_ONE, GL_ONE_MINUS_SRC_ALPHA };
	setBlendFunc(tBlendFunc);

	TLRenderNode::onAppendRenderNode( this );
}

TLRenderNode::~TLRenderNode()
{
    m_pContentNode->release();

	TLRenderNode::onReleaseRenderNode( this );

    if( m_pRender != NULL )
    {
        m_pRender->release();
        m_pRender = NULL;
    }
}

void TLRenderNode::setUseRender(bool use)
{
    m_bUseRender = use;
    //m_bUseRender = false;
}

void TLRenderNode::removeRender()
{
    if( m_pRender != NULL )
    {
        m_pRender->release();
        m_pRender = NULL;
    }

    m_bRecreateRenderTexture = true;
}

void TLRenderNode::setShaderProgramName(std::string shaderName)
{
    if( shaderName.length() == 0 )
    {
        m_sShaderName = kCCShader_PositionTextureColor;
    }
    else
    {
        m_sShaderName = shaderName;
    }

	if (m_pRender != NULL )
	{
        CCGLProgram* shader = CCShaderCache::sharedShaderCache()->programForKey(m_sShaderName.c_str());
        m_pRender->getSprite()->setShaderProgram( shader );
	}
}

void TLRenderNode::setBlendFunc(ccBlendFunc blendFunc)
{
	m_sBlendFunc = blendFunc;

	if (m_pRender != NULL )
	{
		m_pRender->getSprite()->setBlendFunc( m_sBlendFunc );
	}
}

void TLRenderNode::visit(void)
{
	if( !m_bVisible )
    {
        return;
    }

	if( m_bUseRender )
	{
        if( m_bRecreateRenderTexture )
        {
            if( m_pRender != NULL )
            {
                m_pRender->clear( 0, 0, 0, 0 );
                m_pRender->visit();

                m_pRender->release();
                m_pRender = NULL;
            }

            m_pRender = CCRenderTexture::create( (int)m_renderSize.width, (int)m_renderSize.height );
            m_pRender->retain();

            m_pRender->getSprite()->setCustomUniforms( m_fCustomUniforms[0], m_fCustomUniforms[1], m_fCustomUniforms[2], m_fCustomUniforms[3] );
            m_pRender->getSprite()->setCustomUniformsEx( m_fCustomUniformsEx[0], m_fCustomUniformsEx[1], m_fCustomUniformsEx[2], m_fCustomUniformsEx[3] );
            m_pRender->getSprite()->getTexture()->setAntiAliasTexParameters();

            CCGLProgram* shader = CCShaderCache::sharedShaderCache()->programForKey( m_sShaderName.c_str() );
            m_pRender->getSprite()->setShaderProgram( shader );

            m_pRender->getSprite()->setBlendFunc( m_sBlendFunc );

            m_bRecreateRenderTexture = false;
        }

        // clear gl
        GLboolean isEnabled = glIsEnabled( GL_SCISSOR_TEST );
        GLint oldScissor[4];
        if( isEnabled != GL_FALSE )
        {
            glGetIntegerv( GL_SCISSOR_BOX, oldScissor );
        }

		glDisable( GL_SCISSOR_TEST );

        CCNode* pParent = m_pContentNode->getParent();
        CCPoint point = m_pContentNode->getPosition();

        bool bOldRenderNodeFlag = getRenderNodeFlag();
        setRenderNodeFlag( true );

        // render
        m_pRender->beginWithClear( 0, 0, 0, 0 );

        m_pContentNode->setParent( NULL );
        m_pContentNode->setPosition( CCPoint( point.x + m_renderSize.width * 0.5, point.y + m_renderSize.height * 0.5 ) );
        m_pContentNode->visit();

        m_pRender->end();

        setRenderNodeFlag( bOldRenderNodeFlag );

        m_pContentNode->setPosition( point );
        m_pContentNode->setParent( pParent );

        // reset gl
        if( isEnabled != GL_FALSE )
        {
            glEnable( GL_SCISSOR_TEST );
            glScissor( oldScissor[0], oldScissor[1], oldScissor[2], oldScissor[3] );
        }
        else
        {
            glDisable( GL_SCISSOR_TEST );
        }

        m_pRender->getSprite()->visit();
    }
	else
	{
		CCNode::visit();
	}
}

void TLRenderNode::setRenderSize(const CCSize& size)
{
	m_renderSize = size;
    m_bRecreateRenderTexture = true;
}

void TLRenderNode::setCustomUniforms( float r, float g, float b, float a )
{
    m_fCustomUniforms[0] = r;
    m_fCustomUniforms[1] = g;
    m_fCustomUniforms[2] = b;
    m_fCustomUniforms[3] = a;

    if( m_pRender != NULL )
    {
        m_pRender->getSprite()->setCustomUniforms( m_fCustomUniforms[0] ,m_fCustomUniforms[1] ,m_fCustomUniforms[2] ,m_fCustomUniforms[3] );
    }
}

void TLRenderNode::setCustomUniformsEx( float r, float g, float b, float a )
{
    m_fCustomUniformsEx[0] = r;
    m_fCustomUniformsEx[1] = g;
    m_fCustomUniformsEx[2] = b;
    m_fCustomUniformsEx[3] = a;

    if( m_pRender != NULL )
    {
        m_pRender->getSprite()->setCustomUniformsEx( m_fCustomUniformsEx[0] ,m_fCustomUniformsEx[1] ,m_fCustomUniformsEx[2] ,m_fCustomUniformsEx[3] );
    }
}

