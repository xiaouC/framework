#pragma once
#include <layers_scenes_transitions_nodes/CCLayer.h>
#include <map>
#include <list>

USING_NS_CC;

class TLDropDragHelper;
class TLWindow;
class TLMainLayer;
class TLTweenManager;

class TLWindowManager : public CCLayer
{
	friend class TLWindow;
	friend class TLEditBox;
public:
	TLWindowManager();
	virtual ~TLWindowManager();

	static TLWindowManager* SharedTLWindowManager();

public:
	virtual bool init();

	void registerWithTouchDispatcher();
	virtual bool ccTouchBegan( CCTouch* pTouch, CCEvent* pEvent );
	virtual void ccTouchMoved( CCTouch* pTouch, CCEvent* pEvent );
	virtual void ccTouchEnded( CCTouch* pTouch, CCEvent* pEvent );
	virtual void keyBackClicked();
	virtual void keyMenuClicked();

	void update( float dt );
    cocos2d::CCPoint getLastPoint() {return m_kLastPoint;};
    float getLastPointX() {return m_kLastPoint.x;};
    float getLastPointY() {return m_kLastPoint.y;};

public:
	cocos2d::CCPoint GetCenterPoint();

	void ShowUI( bool bShow );
	void ShowWindow( TLWindow* pModuleWindow );
	void PrintShowWindowList();
	void HideAllModuleWindow();
	void DestroyAllModuleWindow();

public:
	static cocos2d::CCPoint PointTransform( cocos2d::CCPoint& point );

	float getWorldTime() { return m_fWorldTime; }

    void setKeyBackClickedHandler( int nHandler );
    void setKeyMenuClickedHandler( int nHandler );

protected:
	float m_fWorldTime;

	float m_fLastTouchTime;
	cocos2d::CCPoint m_kLastPoint;

    int m_nKeyBackClickedHandler;
    int m_nKeyMenuClickedHandler;
public:
	void ReleaseAllWindow();

	bool AddModuleWindow( TLWindow* pModuleWindow );
	void RemoveModuleWindow( TLWindow* pWindow );
	TLWindow* FindModuleWindow( const std::string& strWindowName );
	TLWindow* FindModuleWindow( const cocos2d::CCPoint& point );
	TLWindow* FindReceiveDropDragWindow( const cocos2d::CCPoint& point );
    void MoveToTop( TLWindow* pWindow);
	void MoveToBottom( TLWindow* pWindow);

	bool OnButtonDown( const cocos2d::CCPoint& point );
	void OnButtonUp( const cocos2d::CCPoint& point );
	bool OnDblClk( const cocos2d::CCPoint& point );
	void OnMove( const cocos2d::CCPoint& point );

	int DoDropDrag( TLWindow* pWindow );
	void EndDropDrag();
	void CancelDropDrag();

    bool GetEventBubble() { return m_bEventBubble; }
    bool StopEventBubble() { m_bEventBubble = false; return m_bEventBubble; }

    void setTouchBeganHandler( int nHandler );
    void setTouchMovedHandler( int nHandler );
    void setTouchEndedHandler( int nHandler );

    void setCheckInputTextHandler( int nHandler );
protected:
	std::map<std::string,TLWindow*> m_mapModuleWindow;
	std::list<TLWindow*> m_listModuleWindow;

	TLDropDragHelper* m_pDDHelper;

	TLWindow* m_pActiveWindow;

    bool m_bEventBubble;    // 如果父窗口不是CONTAINER，此标记无效

	bool m_bIsWindowPress;
	CCPoint m_ptWindowPressPoint;
	float m_fLastPressWindowTime;
	TLWindow* m_pDownWindow;

    // 
    int m_nTouchBeganHandler;
    int m_nTouchMovedHandler;
    int m_nTouchEndedHandler;

    int m_nCheckInputTextHandler;
public:
    bool checkInputText( std::string text );
public:
    void lockScreen( const std::string& strLockName );
    void unlockScreen( const std::string& strLockName );
    void clearAllLock();
    void screenLockLog();

protected:
    std::map<std::string,int> m_mapLockFlag;

public:
	void SetModalWindow( TLWindow* pWindow, bool bModal );
    void SetSystemWindow( TLWindow* pWindow = NULL ) { m_pSystemWindow = pWindow; }
    void SetGuideWindow( TLWindow* pWindow = NULL ) { m_pGuideWindow = pWindow; }
    void SetLockScreenWindow( TLWindow* pWindow = NULL ) { m_pLockScreenWindow = pWindow; }
    void SetEditBoxWindow( TLWindow* pWindow = NULL) { m_pEditBoxWindow = pWindow; }

protected:
	bool IsModuleWindow( TLWindow* pWindow );
	bool IsModalWindow( TLWindow* pWindow );

	TLWindow* GetTopModalWindow();

protected:
	std::list<TLWindow*> m_listModalWindows;
    TLWindow* m_pSystemWindow;
    TLWindow* m_pGuideWindow;
    TLWindow* m_pLockScreenWindow;           // 锁屏后可以相应的窗口
    TLWindow* m_pEditBoxWindow;

protected:
	TLTweenManager* m_pTweenManager;
};
