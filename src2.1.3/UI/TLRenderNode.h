#pragma once
#include <misc_nodes/CCRenderTexture.h>
#include <map>
#include <set>
#include <list>

USING_NS_CC;

class TLRenderNode: public CCNodeRGBA
{
public:
	static std::set<TLRenderNode*> listNodes;
	static void resume();

	static void pause();

private:
	static inline void onAppendRenderNode( TLRenderNode* node )
	{
		listNodes.insert(node);
	}

	static inline void onReleaseRenderNode( TLRenderNode* node )
	{
		std::set<TLRenderNode*>::iterator iter = listNodes.find( node );
		if( iter != listNodes.end() )
		{
			listNodes.erase(iter);
		}
	}

public:
	static TLRenderNode* create( CCNode* pContentNode, float width, float height );

	virtual ~TLRenderNode();

	void setUseRender(bool use);

	void setCustomUniforms( float r, float g, float b, float a );
	void setCustomUniformsEx( float r, float g, float b, float a );
	
	void setRenderSize(const CCSize & size);

	void setBlendFunc(ccBlendFunc blendFunc);

    virtual void setShaderProgramName(std::string shaderName = "");

    virtual void visit(void);

protected:
	TLRenderNode( CCNode* pContentNode );

    void removeRender();

	CCRenderTexture *   m_pRender;
    CCNode*             m_pContentNode;

    std::string         m_sShaderName;

	bool                m_bUseRender;

    ccBlendFunc         m_sBlendFunc;

	CCSize              m_renderSize;
    bool                m_bRecreateRenderTexture;

	float m_fCustomUniforms[4];
	float m_fCustomUniformsEx[4];
};
