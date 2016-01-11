#pragma once
#include <base_nodes/CCNode.h>

USING_NS_CC;

class TLWindow;

class TLDropDragHelper : public cocos2d::CCObject
{
	friend class TLWindow;
	friend class TLWindowManager;
public:
	TLDropDragHelper();
	virtual ~TLDropDragHelper();

	void Reset();

	void AppendShowIcon( unsigned int uiResID, const char* filename );
	void AppendShowModel( unsigned int uiResID, const char* filename );
	void AppendShow( cocos2d::CCNode* pNode );

    void setDDPosition( const CCPoint& point, bool first );

protected:
	cocos2d::CCNode* m_pDropDragNode;

	bool m_bIsDropDraging;
	TLWindow* m_pSourceWindow;

    CCPoint m_kLastPos;
    bool m_bIsEventBubble;
};
