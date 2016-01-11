#include "TLWindowManager.h"
#include "../Common/TLCommon.h"
#include "TLDropDragHelper.h"
#include "TLWindow.h"
#include <CCDirector.h>
#include "tolua++.h"
#include "TLMaskLayer.h"
#include "../NetMessage/NetMsgProcess.h"
#include "../NetMessage/HttpClient.h"
#include "../tween/TLTweenManager.h"
#include "platform/SDKCallback.h"
#include "../MC/MCLoader.h"

TLWindowManager::TLWindowManager()
: m_fWorldTime(0.0f)
, m_fLastTouchTime(0)
, m_nKeyBackClickedHandler(0)
, m_nKeyMenuClickedHandler(0)
, m_pActiveWindow(NULL)
, m_bEventBubble(true)
, m_bIsWindowPress(false)
, m_pDownWindow(NULL)
, m_nTouchBeganHandler(0)
, m_nTouchMovedHandler(0)
, m_nTouchEndedHandler(0)
, m_nCheckInputTextHandler(0)
, m_pSystemWindow(NULL)
, m_pGuideWindow(NULL)
, m_pLockScreenWindow(NULL)
, m_pEditBoxWindow(NULL)
{
	m_pDDHelper = new TLDropDragHelper;
    m_pTweenManager = new TLTweenManager;
}

TLWindowManager::~TLWindowManager()
{
    if( m_nKeyBackClickedHandler > 0 )
    {
        CCLuaEngine::defaultEngine()->removeScriptHandler( m_nKeyBackClickedHandler );
        m_nKeyBackClickedHandler = 0;
    }

    if( m_nKeyMenuClickedHandler > 0 )
    {
        CCLuaEngine::defaultEngine()->removeScriptHandler( m_nKeyMenuClickedHandler );
        m_nKeyMenuClickedHandler = 0;
    }

    if( m_nTouchBeganHandler > 0 )
    {
        CCLuaEngine::defaultEngine()->removeScriptHandler( m_nTouchBeganHandler );
        m_nTouchBeganHandler = 0;
    }

    if( m_nTouchMovedHandler > 0 )
    {
        CCLuaEngine::defaultEngine()->removeScriptHandler( m_nTouchMovedHandler );
        m_nTouchMovedHandler = 0;
    }

    if( m_nTouchEndedHandler > 0 )
    {
        CCLuaEngine::defaultEngine()->removeScriptHandler( m_nTouchEndedHandler );
        m_nTouchEndedHandler = 0;
    }

    if( m_nCheckInputTextHandler > 0 )
    {
        CCLuaEngine::defaultEngine()->removeScriptHandler( m_nCheckInputTextHandler );
        m_nCheckInputTextHandler = 0;
    }

    CCDirector::sharedDirector()->getPauseScheduler()->unscheduleUpdateForTarget( this );
	ReleaseAllWindow();

	delete m_pDDHelper;
	m_pDDHelper = NULL;

    delete m_pTweenManager;
    m_pTweenManager = NULL;
}

TLWindowManager* g_pTLWindowManager = NULL;
TLWindowManager* TLWindowManager::SharedTLWindowManager()
{
	if( g_pTLWindowManager == NULL )
	{
		g_pTLWindowManager = new TLWindowManager;
		if( g_pTLWindowManager != NULL && g_pTLWindowManager->init() )
		{
			g_pTLWindowManager->autorelease();
		}
		else
		{
			delete g_pTLWindowManager;
			g_pTLWindowManager = NULL;
		}
	}

	return g_pTLWindowManager;
}

bool TLWindowManager::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}

	setTouchEnabled( true );
	setKeypadEnabled( true );

    CCDirector::sharedDirector()->getPauseScheduler()->scheduleUpdateForTarget( this, 0, false );

	return true;
}

void TLWindowManager::registerWithTouchDispatcher(void)
{	
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);
}

#define DOUBLE_CLICK_TIME_INTERVAL 0.3f
bool TLWindowManager::ccTouchBegan( CCTouch* pTouch, cocos2d::CCEvent* /*pEvent*/ )
{
    CCPoint point = pTouch->getLocationInView();
    m_kLastPoint = PointTransform( point );

    if( m_nTouchBeganHandler > 0 )
    {
        CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( m_kLastPoint.x );
        CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( m_kLastPoint.y );
        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nTouchBeganHandler, 2 );
    }

    if( !m_pDDHelper->m_bIsDropDraging )
    {
        float fCurrTime = getWorldTime();
        if( fCurrTime - m_fLastTouchTime <= CCDirector::sharedDirector()->getSpeed() * DOUBLE_CLICK_TIME_INTERVAL )
        {
            OnDblClk( m_kLastPoint );
        }
        else
        {
            OnButtonDown( m_kLastPoint );
        }

        m_fLastTouchTime = fCurrTime;
    }
	
	return true;
}

void TLWindowManager::ccTouchMoved( CCTouch* pTouch, cocos2d::CCEvent* /*pEvent*/ )
{
	CCPoint point = pTouch->getLocationInView();
	m_kLastPoint = PointTransform( point );

    if( m_nTouchMovedHandler > 0 )
    {
        CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( m_kLastPoint.x );
        CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( m_kLastPoint.y );
        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nTouchMovedHandler, 2 );
    }

    if( m_pDDHelper->m_bIsDropDraging )
    {
        m_pDDHelper->setDDPosition( m_kLastPoint, false );
    }

    // 
    OnMove( m_kLastPoint );
}

void TLWindowManager::ccTouchEnded( CCTouch* pTouch, cocos2d::CCEvent* /*pEvent*/ )
{
	CCPoint point = pTouch->getLocationInView();
	m_kLastPoint = PointTransform( point );

    if( m_nTouchEndedHandler > 0 )
    {
        CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( m_kLastPoint.x );
        CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( m_kLastPoint.y );
        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nTouchEndedHandler, 2 );
    }

    OnButtonUp( m_kLastPoint );

	TLWindow::AllButtonRelease();
}

#define TL_TOUCH_OFF_DRAG_DROP_TIME_INTERVAL 0.05f
void TLWindowManager::update( float dt )
{
	// world time
	m_fWorldTime += dt;

    CNetReceiver::SharedNetReceiver()->ProcessMsg();
    TLHttpClient::sharedHttpClient()->Process();
    process_sdk_callback();
    MCLoader::sharedMCLoader()->processLoadTextureCallback();

    // 
    m_pTweenManager->update( dt );

	// 触发拖拽 
    if( !m_pDDHelper->m_bIsDropDraging )
    {
        float fCurrentWorldTime = getWorldTime();
        if( fCurrentWorldTime - m_fLastTouchTime >= TL_TOUCH_OFF_DRAG_DROP_TIME_INTERVAL )
        {
            std::set<TLWindow*>::iterator iter = TLWindow::ms_setButtonDownWindow.begin();
            std::set<TLWindow*>::iterator iter_end = TLWindow::ms_setButtonDownWindow.end();
            for( ; iter != iter_end; ++iter )
            {
                TLWindow* pDownWindow = *iter;
                if( pDownWindow->GetCanTouchDD() && pDownWindow->GetWindowFlag( TL_WINDOW_FLAG_TOUCH_OFF_DROP_DRAG ) && !pDownWindow->GetIsDragDroping() )
                {
                    if( DoDropDrag( pDownWindow ) == TL_EVENT_RESULT_DROP_DRAG_START_SUCCEED )
                        break;
                }
            }
        }
    }

    // 如果处于拖拽，并且移动过一定的距离的话，就不允许响应其他事件了
    if( m_pDDHelper->m_bIsDropDraging && !m_pDDHelper->m_bIsEventBubble )
    {
    }
    else
    {
        if( m_bIsWindowPress )
        {
            float fWorldTime = getWorldTime();
            if( m_fLastPressWindowTime + 0.5f < fWorldTime )
            {
                if( (m_pDownWindow != NULL) && (m_pDownWindow->GetIsEnable()) )
                {
                    m_pDownWindow->EventCallback( TL_EVENT_LONG_PRESS );
                }

                m_bIsWindowPress = false;
                m_pDownWindow = NULL;
            }
        }
    }

    // 清理
    std::list<TLWindow*>::iterator iter = TLWindow::ms_listAllWindows.begin();
    for( ; iter != TLWindow::ms_listAllWindows.end(); )
    {
        if( (*iter)->retainCount() == 1 )
        {
            (*iter)->release();
            iter = TLWindow::ms_listAllWindows.erase( iter );
        }
        else
        {
            if( (*iter)->retainCount() == 2 )
            {
                (*iter)->release();
            }

            ++iter;
        }
    }
}

void TLWindowManager::keyBackClicked()
{
    if( m_nKeyBackClickedHandler > 0 )
        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nKeyBackClickedHandler, 0 );
}

void TLWindowManager::keyMenuClicked()
{
    if( m_nKeyMenuClickedHandler > 0 )
        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nKeyMenuClickedHandler, 0 );
}

CCPoint TLWindowManager::GetCenterPoint()
{
	CCDirector* pDirector = cocos2d::CCDirector::sharedDirector();
	CCSize kWinSize = pDirector->getWinSize();
	CCPoint kCenterPoint( kWinSize.width * 0.5f, kWinSize.height * 0.5f );

	return kCenterPoint;
}

void TLWindowManager::ShowUI( bool bShow )
{
	setVisible( bShow );
}

void TLWindowManager::ShowWindow( TLWindow* pModuleWindow )
{
	std::list<TLWindow*>::iterator iter = m_listModuleWindow.begin();
	std::list<TLWindow*>::iterator iter_end = m_listModuleWindow.end();
	for( ; iter != iter_end; ++iter )
	{
		if( pModuleWindow == (*iter) )
		{
			m_listModuleWindow.erase( iter );
			m_listModuleWindow.push_back( pModuleWindow );

			pModuleWindow->SetIsVisible( true );

			break;
		}
	}
}

void TLWindowManager::PrintShowWindowList()
{
	std::list<TLWindow*>::iterator iter = m_listModuleWindow.begin();
	std::list<TLWindow*>::iterator iter_end = m_listModuleWindow.end();
	CCLog( "**************************************");			
	for( ; iter != iter_end; ++iter )
	{
		TLWindow* pWindow = *iter;
		if( pWindow->GetIsVisible() )
		{
			CCLog( "windowName: %s", pWindow->GetWindowName().c_str() );			
		}
	}
	CCLog( "**************************************");			
}

void TLWindowManager::HideAllModuleWindow()
{
	std::list<TLWindow*>::iterator iter = m_listModuleWindow.begin();
	std::list<TLWindow*>::iterator iter_end = m_listModuleWindow.end();
	for( ; iter != iter_end; ++iter )
	{
		(*iter)->SetIsVisible( false );
	}
}

void TLWindowManager::DestroyAllModuleWindow()
{
    // 如果正处于拖拽的话，就要清理掉 
    CancelDropDrag();

    m_pActiveWindow = NULL;
    m_pSystemWindow = NULL;
    m_pGuideWindow = NULL;
    m_pLockScreenWindow = NULL;
    m_pEditBoxWindow = NULL;
	m_listModalWindows.clear();
    m_mapModuleWindow.clear();
	std::list<TLWindow*>::iterator iter = m_listModuleWindow.begin();
	std::list<TLWindow*>::iterator iter_end = m_listModuleWindow.end();
	for( ; iter != iter_end; ++iter )
	{
		(*iter)->release();
	}
    removeAllChildrenWithCleanup(true);
	m_listModuleWindow.clear();

    // 所有的锁屏全部清掉 
    clearAllLock();
}

CCPoint TLWindowManager::PointTransform( cocos2d::CCPoint& point )
{
	return CCDirector::sharedDirector()->convertToGL( point );
}

void TLWindowManager::setKeyBackClickedHandler( int nHandler )
{
    if( m_nKeyBackClickedHandler > 0 )
        CCLuaEngine::defaultEngine()->removeScriptHandler( m_nKeyBackClickedHandler );

    m_nKeyBackClickedHandler = nHandler;
}

void TLWindowManager::setKeyMenuClickedHandler( int nHandler )
{
    if( m_nKeyMenuClickedHandler > 0 )
        CCLuaEngine::defaultEngine()->removeScriptHandler( m_nKeyMenuClickedHandler );

    m_nKeyMenuClickedHandler = nHandler;
}

void TLWindowManager::ReleaseAllWindow()
{
	std::list<TLWindow*>::iterator iter = m_listModuleWindow.begin();
	std::list<TLWindow*>::iterator iter_end = m_listModuleWindow.end();
	for( ; iter != iter_end; ++iter )
		(*iter)->release();
	m_listModuleWindow.clear();
	m_mapModuleWindow.clear();
}

bool TLWindowManager::AddModuleWindow( TLWindow* pModuleWindow )
{
    if (!pModuleWindow->GetWindowName().empty())
    {
		CCAssert(m_mapModuleWindow.find(pModuleWindow->GetWindowName()) == m_mapModuleWindow.end(), "Duplicate Module Window Name!");
    }

	pModuleWindow->retain();

    if (!pModuleWindow->GetWindowName().empty())
        m_mapModuleWindow[pModuleWindow->GetWindowName()] = pModuleWindow;
	m_listModuleWindow.push_back( pModuleWindow );

	//////////////////////////////////////////////////////////////////////////
	CCNode* pAttachNode = pModuleWindow->m_pMCNode;
    if( pAttachNode != NULL && pAttachNode->getParent() == NULL )
    {
        addChild( pAttachNode );
	}

	//打印当前显示界面 
	//PrintShowWindowList();
	return true;
}

void TLWindowManager::RemoveModuleWindow( TLWindow* pWindow )
{
    if (pWindow==NULL)
        return;

    if (m_pEditBoxWindow ==pWindow) {
        m_pEditBoxWindow = NULL;
    }
    
    if( m_pSystemWindow == pWindow )
        m_pSystemWindow = NULL;

    if( m_pLockScreenWindow == pWindow )
        m_pLockScreenWindow = NULL;

    if( m_pGuideWindow == pWindow )
        m_pGuideWindow = NULL;
    
    

    if ( !pWindow->GetWindowName().empty() )
    {
        std::map<std::string,TLWindow*>::iterator iter = m_mapModuleWindow.find( pWindow->GetWindowName() );
        if( iter != m_mapModuleWindow.end() )
        {
            m_mapModuleWindow.erase( iter );
        }
    }

    std::list<TLWindow*>::iterator iter = m_listModuleWindow.begin();
    for ( ; iter!=m_listModuleWindow.end(); iter++)
    {
        if (*iter==pWindow)
        {
            m_listModuleWindow.erase(iter);
            removeChild( pWindow->m_pMCNode, true );
            pWindow->release();
			  break;
        }
    }

	std::list<TLWindow*>::iterator iterM = m_listModalWindows.begin();
	std::list<TLWindow*>::iterator iterM_end = m_listModalWindows.end();
	for( ; iterM != iterM_end; ++iterM )
	{
		if( (*iterM) == pWindow )
		{
			m_listModalWindows.erase( iterM );

			break;
		}
	}

	if( m_pActiveWindow == pWindow )
		m_pActiveWindow = NULL;
}

TLWindow* TLWindowManager::FindModuleWindow( const std::string& strWindowName )
{
	std::map<std::string,TLWindow*>::iterator iter = m_mapModuleWindow.find( strWindowName );
	if( iter != m_mapModuleWindow.end() )
		return iter->second;

	return NULL;
}

TLWindow* TLWindowManager::FindModuleWindow( const CCPoint& point )
{
	std::list<TLWindow*>::reverse_iterator iter = m_listModuleWindow.rbegin();
	std::list<TLWindow*>::reverse_iterator iter_end = m_listModuleWindow.rend();
	for( ; iter != iter_end; ++iter )
	{
		TLWindow* pModuleWindow = (*iter);
		if( pModuleWindow->HitTest( point ) )
			return pModuleWindow;
	}

	return NULL;
}

TLWindow* TLWindowManager::FindReceiveDropDragWindow( const CCPoint& point )
{
    if (m_pEditBoxWindow != NULL) {
        TLWindow* pReceiveDropDragWindow = m_pEditBoxWindow->FindReceiveDropDragWindow( point );
        if( pReceiveDropDragWindow != NULL )
            return pReceiveDropDragWindow;
        
        return NULL;
    }
    
    
    if( m_pSystemWindow != NULL )
    {
		TLWindow* pReceiveDropDragWindow = m_pSystemWindow->FindReceiveDropDragWindow( point );
		if( pReceiveDropDragWindow != NULL )
			return pReceiveDropDragWindow;

        return NULL;
    }

    if( m_pLockScreenWindow != NULL )
    {
		TLWindow* pReceiveDropDragWindow = m_pLockScreenWindow->FindReceiveDropDragWindow( point );
		if( pReceiveDropDragWindow != NULL )
			return pReceiveDropDragWindow;

        return NULL;
    }

    if( m_pGuideWindow != NULL )
    {
		TLWindow* pReceiveDropDragWindow = m_pGuideWindow->FindReceiveDropDragWindow( point );
		if( pReceiveDropDragWindow != NULL )
			return pReceiveDropDragWindow;

        return NULL;
    }

	std::list<TLWindow*>::reverse_iterator iter = m_listModuleWindow.rbegin();
	std::list<TLWindow*>::reverse_iterator iter_end = m_listModuleWindow.rend();
	for( ; iter != iter_end; ++iter )
	{
		TLWindow* pModuleWindow = (*iter);

		TLWindow* pReceiveDropDragWindow = pModuleWindow->FindReceiveDropDragWindow( point );
		if( pReceiveDropDragWindow != NULL )
			return pReceiveDropDragWindow;
	}

	return NULL;
}

bool TLWindowManager::OnButtonDown( const CCPoint& point )
{
    m_bEventBubble = true; // reset event bubble flag 

    m_bIsWindowPress = true;
    m_fLastPressWindowTime = getWorldTime();
    
    if ( m_pEditBoxWindow != NULL) {
        m_pEditBoxWindow->LostFocus(NULL);
        return true;
    }
    

    // 系统级窗口 
    if( m_pSystemWindow != NULL )
    {
        m_pSystemWindow->OnButtonDown( point );

        return true;
    }

    if( m_pLockScreenWindow != NULL )
    {
        m_pLockScreenWindow->OnButtonDown( point );

        return true;
    }

    // 新手引导窗口 
    if( m_pGuideWindow != NULL )
    {
        m_pGuideWindow->OnButtonDown( point );

        return true;
    }

	// 如果被锁屏了，就直接返回 
	if( !m_mapLockFlag.empty() )
        return false;

	TLWindow* pModalWindow = GetTopModalWindow();
	if( pModalWindow != NULL )
	{
		pModalWindow->OnButtonDown( point );

		return true;
	}

	m_pActiveWindow = FindModuleWindow( point );
	if( m_pActiveWindow != NULL )
	{
		m_ptWindowPressPoint = point;

		m_pActiveWindow->OnButtonDown( point );

        return true;
	}
  	else
  	{
		m_bIsWindowPress = false;
  	}

    return false;
}

void TLWindowManager::OnButtonUp( const CCPoint& point )
{
	m_bIsWindowPress = false;
	m_pDownWindow = NULL;
    m_bEventBubble = true; // reset event bubble flag 

    bool isDDEventBubble = m_pDDHelper->m_bIsEventBubble;
    if( m_pDDHelper->m_bIsDropDraging )
    {
        TLWindow* pWindow = FindReceiveDropDragWindow( m_kLastPoint );
        if( pWindow != NULL && pWindow->ReceiveDropDrag( *m_pDDHelper ) ==TL_EVENT_RESULT_DROP_DRAG_RECEIVE_SUCCEED )
        {
            EndDropDrag();
        }
        else
        {
            CancelDropDrag();
        }
    }

    if( !isDDEventBubble )
        return;

    if ( m_pEditBoxWindow != NULL) {
        
        m_pEditBoxWindow->OnButtonUp( m_kLastPoint );
        
        return;
    }
    
    
    if( m_pSystemWindow != NULL )
    {
        m_pSystemWindow->OnButtonUp( m_kLastPoint );

        return;
    }

    if( m_pLockScreenWindow != NULL )
    {
        m_pLockScreenWindow->OnButtonUp( point );

        return;
    }

    if( m_pGuideWindow != NULL )
    {
        m_pGuideWindow->OnButtonUp( m_kLastPoint );

        return;
    }

	// 如果被锁屏了，就直接返回 
	if( !m_mapLockFlag.empty() )
        return;

	TLWindow* pModalWindow = GetTopModalWindow();
	if( pModalWindow != NULL )
	{
		pModalWindow->OnButtonUp( point );
	}
	else
	{
        TLWindow* pTempWindow = FindModuleWindow( point );
		if( pTempWindow != NULL && m_pActiveWindow == pTempWindow )
		{
			m_pActiveWindow->OnButtonUp( point );

			m_pActiveWindow = NULL;
		}
	}
}

bool TLWindowManager::OnDblClk( const CCPoint& point )
{
    m_bEventBubble = true; // reset event bubble flag
    
    
    if ( m_pEditBoxWindow != NULL ) {
        
        m_pEditBoxWindow->OnDblClk( point );
        
        return true;
    }
    

    // 系统级窗口 
    if( m_pSystemWindow != NULL )
    {
        m_pSystemWindow->OnDblClk( point );

        return true;
    }

    if( m_pLockScreenWindow != NULL )
    {
        m_pLockScreenWindow->OnDblClk( point );

        return true;
    }

    // 新手引导窗口 
    if( m_pGuideWindow != NULL )
    {
        m_pGuideWindow->OnDblClk( point );

        return true;
    }

	// 如果被锁屏了，就直接返回 
	if( !m_mapLockFlag.empty() )
        return false;

	TLWindow* pModalWindow = GetTopModalWindow();
	if( pModalWindow != NULL )
	{
		pModalWindow->OnDblClk( point );

		return true;
	}

	m_pActiveWindow = FindModuleWindow( point );
	if( m_pActiveWindow != NULL )
	{
		m_pActiveWindow->OnDblClk( point );

        return true;
	}

    return false;
}

void TLWindowManager::OnMove( const CCPoint& point )
{
    m_bEventBubble = true; // reset event bubble flag
    
    if ( m_pEditBoxWindow != NULL ) {
        
        m_pEditBoxWindow->OnMove( point );
        
        return;
    }
    

    if( m_pSystemWindow != NULL )
    {
        m_pSystemWindow->OnMove( point );

        return;
    }

    if( m_pLockScreenWindow != NULL )
    {
        m_pLockScreenWindow->OnMove( point );

        return;
    }

    if( m_pGuideWindow != NULL )
    {
        m_pGuideWindow->OnMove( point );

        return;
    }

	// 如果被锁屏了，就直接返回 
	if( !m_mapLockFlag.empty() )
        return;

	TLWindow* pModalWindow = GetTopModalWindow();
	if( pModalWindow != NULL )
	{
		pModalWindow->OnMove( point );

		return;
	}

	if( m_pActiveWindow != NULL )
	{
		m_pActiveWindow->OnMove( point );
	}
  	else
  	{
  		//XLSceneManager::SharedXLSceneManager()->OnSceneMove( point );
  	}

	if( m_bIsWindowPress )
	{
		if( abs( (int)(point.x - m_ptWindowPressPoint.x) ) > 40 || abs( (int)(point.y - m_ptWindowPressPoint.y) ) > 40 )
		{
			m_bIsWindowPress = false;
			m_pDownWindow = NULL;
		}
	}
}

int TLWindowManager::DoDropDrag( TLWindow* pWindow )
{
	if( m_pDDHelper->m_bIsDropDraging )
		return TL_EVENT_RESULT_DROP_DRAG_START_FAILED;

	int nResult = pWindow->StartDropDrag( *m_pDDHelper );
	if( nResult == TL_EVENT_RESULT_DROP_DRAG_START_SUCCEED )
	{
		m_pDDHelper->m_pSourceWindow = pWindow;
		m_pDDHelper->m_bIsDropDraging = true;

        CCScene* pRunningScene = CCDirector::sharedDirector()->getRunningScene();
		pRunningScene->addChild( m_pDDHelper->m_pDropDragNode, 1 );

		m_pDDHelper->setDDPosition( m_kLastPoint, true );

		pWindow->SetIsDragDroping( true );
	}

	return nResult;
}

void TLWindowManager::EndDropDrag()
{
	TLWindow* pWindow = m_pDDHelper->m_pSourceWindow;

	pWindow->SetIsDragDroping( false );

    CCNode* pNode = m_pDDHelper->m_pDropDragNode;
    pNode->removeAllChildrenWithCleanup( true );

    CCScene* pRunningScene = CCDirector::sharedDirector()->getRunningScene();
    pRunningScene->removeChild( pNode, true );
    pNode->setParent( NULL );

    m_pDDHelper->Reset();
}

void TLWindowManager::CancelDropDrag()
{
    if( !m_pDDHelper->m_bIsDropDraging )
        return;

	TLWindow* pWindow = m_pDDHelper->m_pSourceWindow;

	pWindow->CancelDropDrag( *m_pDDHelper );
	pWindow->SetIsDragDroping( false );
    pWindow->SetCanTouchDD( false );

    CCNode* pNode = m_pDDHelper->m_pDropDragNode;
    pNode->removeAllChildrenWithCleanup( true );

    CCScene* pRunningScene = CCDirector::sharedDirector()->getRunningScene();
    pRunningScene->removeChild( pNode, true );
    pNode->setParent( NULL );

    m_pDDHelper->Reset();
}

void TLWindowManager::setTouchBeganHandler( int nHandler )
{
    if( m_nTouchBeganHandler > 0 )
        CCLuaEngine::defaultEngine()->removeScriptHandler( m_nTouchBeganHandler );

    m_nTouchBeganHandler = nHandler;
}

void TLWindowManager::setTouchMovedHandler( int nHandler )
{
    if( m_nTouchMovedHandler > 0 )
        CCLuaEngine::defaultEngine()->removeScriptHandler( m_nTouchMovedHandler );

    m_nTouchMovedHandler = nHandler;
}

void TLWindowManager::setTouchEndedHandler( int nHandler )
{
    if( m_nTouchEndedHandler > 0 )
        CCLuaEngine::defaultEngine()->removeScriptHandler( m_nTouchEndedHandler );

    m_nTouchEndedHandler = nHandler;
}

void TLWindowManager::setCheckInputTextHandler( int nHandler )
{
    if( m_nCheckInputTextHandler > 0 )
        CCLuaEngine::defaultEngine()->removeScriptHandler( m_nCheckInputTextHandler );

    m_nCheckInputTextHandler = nHandler;
}

void TLWindowManager::MoveToTop( TLWindow* pWindow)
{
    CCNode* pNode = pWindow->GetNode();
    CCNode* pParent = pNode->getParent();
    if (pParent==NULL)
        return;

    int nZOrder = pNode->getZOrder();
    pParent->reorderChild(pNode, nZOrder);

	std::list<TLWindow*>::iterator iter = m_listModuleWindow.begin();
    for (; iter!=m_listModuleWindow.end(); iter++)
	{
        if (*iter == pWindow)
        {
            m_listModuleWindow.erase(iter);
            m_listModuleWindow.push_back(pWindow);
            break;
        }
	}
}

void TLWindowManager::MoveToBottom( TLWindow* pWindow)
{
	CCNode* pNode = pWindow->GetNode();
	CCNode* pParent = pNode->getParent();
	if (pParent==NULL)
		return;

    int nZOrder = pNode->getZOrder();
	pParent->reorderChild(pNode, nZOrder);

	std::list<TLWindow*>::iterator iter = m_listModuleWindow.begin();
	for (; iter!=m_listModuleWindow.end(); iter++)
	{
		if (*iter == pWindow)
		{
			m_listModuleWindow.erase(iter);
			m_listModuleWindow.push_front(pWindow);
			break;
		}
	}
}

void TLWindowManager::SetModalWindow( TLWindow* pWindow, bool bModal )
{
	if( !IsModuleWindow( pWindow ) )
		return;

	if( bModal )
	{
		if( IsModalWindow( pWindow ) )
			return;

		m_listModalWindows.push_back( pWindow );

		return;
	}

	std::list<TLWindow*>::iterator iter = m_listModalWindows.begin();
	std::list<TLWindow*>::iterator iter_end = m_listModalWindows.end();
	for( ; iter != iter_end; ++iter )
	{
		if( *iter == pWindow )
		{
			m_listModalWindows.erase( iter );

			return;
		}
	}
}

bool TLWindowManager::IsModuleWindow( TLWindow* pWindow )
{
	std::list<TLWindow*>::iterator iter = m_listModuleWindow.begin();
	std::list<TLWindow*>::iterator iter_end = m_listModuleWindow.end();
	for( ; iter != iter_end; ++iter )
	{
		if( *iter == pWindow )
			return true;
	}

	return false;
}

bool TLWindowManager::IsModalWindow( TLWindow* pWindow )
{
	std::list<TLWindow*>::iterator iter = m_listModalWindows.begin();
	std::list<TLWindow*>::iterator iter_end = m_listModalWindows.end();
	for( ; iter != iter_end; ++iter )
	{
		if( *iter == pWindow )
			return true;
	}

	return false;
}

TLWindow* TLWindowManager::GetTopModalWindow()
{
	std::list<TLWindow*>::reverse_iterator iter = m_listModalWindows.rbegin();
	if( iter != m_listModalWindows.rend() )
		return *iter;

	return NULL;
}

void TLWindowManager::lockScreen( const std::string& strLockName )
{
    CCAssert( !strLockName.empty(), "不允许使用匿名锁!" );
    std::map<std::string,int>::iterator iter = m_mapLockFlag.find( strLockName );
    if( iter != m_mapLockFlag.end() )
        iter->second += 1;
    else
        m_mapLockFlag[strLockName] = 1;
}

void TLWindowManager::unlockScreen( const std::string& strLockName )
{
    std::map<std::string,int>::iterator iter = m_mapLockFlag.find( strLockName );
    if( iter == m_mapLockFlag.end() )
    {
        CCLog( "找不到 %s 对应的锁屏!", strLockName.c_str() );

        return;
    }

    if( --iter->second <= 0 )
        m_mapLockFlag.erase( iter );
}

void TLWindowManager::clearAllLock()
{
    m_mapLockFlag.clear();
}

void TLWindowManager::screenLockLog()
{
    CCLuaLog( "------------------------------------------------------------------------------------------------" );
    CCLuaLog( "------------------------------------------------------------------------------------------------" );
    CCLuaLog( "screen lock info : " );
    std::map<std::string,int>::iterator iter = m_mapLockFlag.begin();
    std::map<std::string,int>::iterator iter_end = m_mapLockFlag.end();
    for( ; iter != iter_end; ++iter )
    {
        char szBuf[1024];
        sprintf( szBuf, "lock name : %s,\t\t lock count : %d", iter->first.c_str(), iter->second );
        CCLuaLog( szBuf );
    }
    CCLuaLog( "------------------------------------------------------------------------------------------------" );
    CCLuaLog( "------------------------------------------------------------------------------------------------" );
}

bool TLWindowManager::checkInputText( std::string text )
{
    if( m_nCheckInputTextHandler > 0 )
    {
        CCLuaEngine::defaultEngine()->getLuaStack()->pushString( text.c_str(), text.length() );
        int nRet = CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nCheckInputTextHandler, 1 );
        return nRet == 1;
    }

    return false;
}
