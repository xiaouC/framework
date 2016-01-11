#pragma once
#include <sprite_nodes/CCSprite.h>
#include <layers_scenes_transitions_nodes/CCLayer.h>
#include <list>

USING_NS_CC;

class TLMaskLayer : public CCLayer
{
public:
	TLMaskLayer();
	virtual ~TLMaskLayer();

    virtual void visit();

	static TLMaskLayer* sharedTLMaskLayer();

	void test();

public:
	void resetMaskLayer();
	void setIsMaskScene( bool bMaskScene );
	void appendHighlightRect( const CCRect& rect );
	void appendHighlightRect2( const CCRect& rect );
	void setMaskColor( float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 0.8f );

protected:
	CCSprite* m_pMaskSprite;
};

