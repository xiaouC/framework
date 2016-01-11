#pragma once
#include <base_nodes/CCNode.h>

USING_NS_CC;

class ClipNode : public CCNodeRGBA
{ // tolua_export
public:
    ClipNode();
    virtual ~ClipNode();

	static ClipNode * clipNode(); // tolua_export

	static ClipNode * clipNode(CCRect region); // tolua_export

	virtual void setPosition( const CCPoint& newPosition );

    // tolua_begin
    inline CCRect getClipRegion() { return m_clipRegion; };
    void setClipRegion(CCRect region);
    inline void removeClipRegion(void) { m_clipRegion = CCRectZero; m_hasClipRegion = false; };
    // tolua_end
    virtual void visit();
protected:
    bool m_hasClipRegion;
    CCRect m_clipRegion;

}; // tolua_export

