#pragma once
#include "TLWindowDefine.h"
#include <sprite_nodes/CCSprite.h>
#include "CCImage.h"
#include <string>
#include <map>
#include <set>
#include <list>
#include "../RichText/TLLabelRichTex.h"

USING_NS_CC;

//////////////////////////////////////////////////////////////////////////
class TLDropDragHelper;
class TLWindow;
class TLEditBox;
class MovieClip;

class TLWindow : public CCObject
{
	friend class TLWindowManager;
public:
	TLWindow( CCNode* pMCNode, unsigned int uiWindowFlag = TL_WINDOW_UNIVARSAL );
	virtual ~TLWindow();

public:
	//////////////////////////////////////////////////////////////////////////
    static TLWindow* createWindow( CCNode* pMCNode, unsigned int uiWindowFlag = TL_WINDOW_UNIVARSAL );

	//////////////////////////////////////////////////////////////////////////
	bool OnButtonDown( const CCPoint& point );
	bool OnButtonUp( const CCPoint& point );
	bool OnDblClk( const CCPoint& point );
	bool OnMove( const CCPoint& point );
	bool OnButtonRelease();

	bool HitTest( const CCPoint& point );

	int StartDropDrag( TLDropDragHelper& DDHelper );
	int EndDropDrag( TLDropDragHelper& DDHelper );
	int ReceiveDropDrag( TLDropDragHelper& DDHelper );
	int CancelDropDrag( TLDropDragHelper& DDHelper );

	void LostFocus( TLWindow* pFocusWindow );

public:
	bool AddChildWindow( TLWindow* pChildWindow );
    // 只release窗口，不管节点
	void RemoveAllChildWindow();
	void RemoveChildWindow( TLWindow* pWindow );

	TLWindow* FindWindow( const std::string& strWindowName, bool bFindInChild );
	TLWindow* FindWindow( const CCPoint& point );
	TLWindow* FindReceiveDropDragWindow( const CCPoint& point );

public:
	CCArray* GetChildWindow();

	CCNode* GetNode() { return m_pMCNode; };

protected:
	CCNode* m_pMCNode;

	std::map<std::string,TLWindow*> m_mapChildWindow;
	CCArray* m_listChildWindow;

public:
	bool GetWindowFlag( unsigned int uiWindowFlag ) const;
	void SetWindowFlag( unsigned int uiWindowFlag );
	void AddWindowFlag( unsigned int uiWindowFlag );
	void RemoveWindowFlag( unsigned int uiWindowFlag );

protected:
	unsigned int m_uiWindowFlag;

public:
	void RegisterEvent( TL_WINDOW_EVENT eEventType, int nEventHandler );
    void unregisterEvent( TL_WINDOW_EVENT eEventType );

	int EventCallback( TL_WINDOW_EVENT eEventType, TLDropDragHelper* pkDDHelper = NULL );

protected:
	std::map<TL_WINDOW_EVENT,int> m_mapEventCallback;

	bool m_bIsResponseButtonUp;				// 是否响应弹起事件，在长按事件触发之后，不会触发弹起事件

	// input text
public:
    // 
    void setText( const char* pszText );
    const char* getText();

    void setTextColor( const ccColor3B& kTextColor );
    const ccColor3B& getTextColor();

    void setPlaceHolder( const char* pszText );
    const char* getPlaceHolder();

    void setPlaceHolderColor( const ccColor3B& kPlaceHolderColor );
    const ccColor3B& getPlaceHolderColor();

    void setFontSize( int nFontSize );
    void setPlaceFontSize( int nFontSize );
    void setRichFlag( TL_RICH_STRING_FLAG eRichFlag );
    void setAlignment( CCImage::ETextAlign eAlignment );

    void setInputMode( TL_INPUT_TEXT_MODEL eInputMode );

    void setMaxLength( int nMaxLength );

    void setInputFlag( TL_INPUT_FLAG eInputFlag );

    void setReturnType( TL_RETURN_TYPE eReturnType );

    void setKeyboardWillShowHandler( int nWillShowHandler );
    void setKeyboardWillHideHandler( int nWillHideHandler );

    CCSize getRealSize();

protected:
    TLEditBox* m_pEditBox;
    TL_RICH_STRING_FLAG m_eInputRichStringFlag;

public:
	const std::string& GetWindowName() const;
	void SetWindowName( const std::string& strWindowName );

	bool GetIsEnable() const;
	void SetIsEnable( bool bEnable );

	bool GetIsDragDroping() const;
	void SetIsDragDroping( bool bIsDragDroping );

	bool GetIsScroll() const;
	bool GetIsInput() const;

	bool GetIsDblClked() const;
	void SetIsDblClked( bool bIsDblClked );

	bool GetIsVisible();
	void SetIsVisible( bool bIsVisible );

	bool GetIsPressed() const;
	void SetIsPressed( bool bIsPressed, float fTime );
	float GetPressTime() const;

	cocos2d::CCRect GetWindowRect();

	void SetWindowPos( const CCPoint& point );
	const CCPoint& GetWindowPos();

    bool GetCanTouchDD() const;
    void SetCanTouchDD( bool bCanTouchDD );

protected:
	std::string m_strWindowName;

	// 按下的时间,用于触发拖拽,或者长按
	float m_fPressTime;

    // 在主动取消拖拽的时候，因为还在ms_setButtonDownWindow里面，所以会在TLWindowManager::update里面再次触发拖拽出来
    // 但在主动调用TLWindowManager::CancelDropDrag的时候，并不希望会再次触发
    // 如果在TLWindowManager::CancelDropDrag里面，把this从ms_setButtonDownWindow移除的话，会导致button up和button release无法响应了
    // 因为在TLWindowManager::OnButtonUp的处理过程中，先优先处理拖拽的逻辑
    bool m_bCanTouchDD;

public:
	static void AllButtonRelease();

	static TLWindow* ms_pFocusWindow;
	static TLWindow* ms_pDownWindow;		// 用于判断是否触发 click event 或者触发拖拽
	static std::set<TLWindow*> ms_setButtonDownWindow;

    static std::list<TLWindow*> ms_listAllWindows;
};

#include "TLWindowInline.h"
