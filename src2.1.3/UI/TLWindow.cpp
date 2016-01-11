#include "TLWindow.h"
#include "TLWindowManager.h"
#include "TLDropDragHelper.h"
#include "TLEditBox.h"
#include "tolua_fix.h"
#include "../MC/MCLoader.h"

TLWindow* TLWindow::ms_pFocusWindow = NULL;
TLWindow* TLWindow::ms_pDownWindow = NULL;
std::set<TLWindow*> TLWindow::ms_setButtonDownWindow;
std::list<TLWindow*> TLWindow::ms_listAllWindows;
TLWindow::TLWindow( CCNode* pMCNode, unsigned int uiWindowFlag )
: m_pMCNode(pMCNode)
, m_listChildWindow(NULL)
, m_uiWindowFlag(uiWindowFlag)
, m_bIsResponseButtonUp(true)
, m_pEditBox(NULL)
, m_bCanTouchDD(false)
{
    // 记录下来，在 TLWindowManager:update() 里面清理
    this->retain();       // 两次！两次！
    this->retain();
    ms_listAllWindows.push_back( this );

    // 
	m_strWindowName = m_pMCNode->getInstanceName();
    m_pMCNode->retain();

    m_listChildWindow = CCArray::create();
    m_listChildWindow->retain();

	if( m_uiWindowFlag & TL_WINDOW_FLAG_CLIP )
	{
		MCFrame* pMCFrame = toFrame( m_pMCNode );
		if( pMCFrame != NULL )
			pMCFrame->setClipRegion( pMCFrame->mcBoundingBox );
	}

	// input
	if( GetIsInput() )
    {
        m_pEditBox = new TLEditBox( this );
    }
}

TLWindow::~TLWindow()
{
	if( m_pEditBox != NULL )
	{
		delete m_pEditBox;
		m_pEditBox = NULL;
	}

	EventCallback( TL_EVENT_DESTORY );

	RemoveAllChildWindow();

	m_listChildWindow->release();

    m_pMCNode->release();
}

TLWindow* TLWindow::createWindow( CCNode* pMCNode, unsigned int uiWindowFlag )
{
	TLWindow* pRet = new TLWindow( pMCNode, uiWindowFlag );
    if( pRet != NULL )
        pRet->autorelease();

	return pRet;
}

bool TLWindow::OnButtonDown( const CCPoint& point )
{
	if( !GetIsEnable() || !GetIsVisible() )
		return false;

	TLWindow* pChildWindow = FindWindow( point );
	if( pChildWindow != NULL )
	{
		// 如果子窗口处理了,就直接返回
		// 如果子窗口处理了,还需要父窗口处理的话,那么子窗口应该返回false
		if( pChildWindow->OnButtonDown( point ) )
        {
            if ( m_uiWindowFlag & TL_WINDOW_FLAG_CONTAINER && TLWindowManager::SharedTLWindowManager()->GetEventBubble() )
            {
                // button down event
                EventCallback( TL_EVENT_BUTTON_DOWN );

                // 
                ms_setButtonDownWindow.insert( this );
                ms_pDownWindow = this;
                m_bCanTouchDD = true;
            }

            return true;
        }
	}

	// 
	if( ms_pFocusWindow != NULL && ms_pFocusWindow != this )
		ms_pFocusWindow->LostFocus( this );
	ms_pFocusWindow = this;


	//////////////////////////////////////////////////////////////////////////
	if( m_pEditBox != NULL )
	{
        m_pEditBox->attachWithIME();
	}

	//////////////////////////////////////////////////////////////////////////

	// 
	SetIsPressed( true, TLWindowManager::SharedTLWindowManager()->getWorldTime() );

	// button down event
	EventCallback( TL_EVENT_BUTTON_DOWN );

	// 
	ms_setButtonDownWindow.insert( this );
    m_bCanTouchDD = true;
	ms_pDownWindow = this;
	TLWindowManager::SharedTLWindowManager()->m_pDownWindow = this;

#if( CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
    CCLog( "OnButtonDown %s", GetWindowName().c_str() );
#endif

	return true;
}

bool TLWindow::OnButtonUp( const CCPoint& point )
{
	if( !GetIsEnable() || !GetIsVisible() )
		return false;

	TLWindow* pChildWindow = FindWindow( point );
	if( pChildWindow != NULL )
	{
		if( pChildWindow->OnButtonUp( point ) )
        {
            if ( m_uiWindowFlag & TL_WINDOW_FLAG_CONTAINER && TLWindowManager::SharedTLWindowManager()->GetEventBubble() )
            {
                // button down event
                EventCallback( TL_EVENT_BUTTON_UP );
                ms_setButtonDownWindow.erase( this );
                m_bCanTouchDD = false;
            }
			return true;
        }
	}

	//////////////////////////////////////////////////////////////////////////
	ms_setButtonDownWindow.erase( this );
    m_bCanTouchDD = false;

	// 
	SetIsPressed( false, TLWindowManager::SharedTLWindowManager()->getWorldTime() );

	// 优先判断 click 
	bool bClickFlag = false;
	if( ms_pDownWindow == this && !GetIsDblClked() )
	{
		int nResult = EventCallback( TL_EVENT_BUTTON_CLICK );
		if( nResult != TL_EVENT_RESULT_NOT_SET_EVENT )
			bClickFlag = true;
	}
	ms_pDownWindow = NULL;

	// button up event
	if( !bClickFlag )
		EventCallback( TL_EVENT_BUTTON_UP );

	SetIsDblClked( false );

	return true;
}

bool TLWindow::OnDblClk( const CCPoint& point )
{
	if( !GetIsEnable() || !GetIsVisible() )
		return false;

	SetIsDblClked( true );

	TLWindow* pChildWindow = FindWindow( point );
	if( pChildWindow != NULL )
	{
		if( pChildWindow->OnDblClk( point ) )
        {
            if ( m_uiWindowFlag & TL_WINDOW_FLAG_CONTAINER && TLWindowManager::SharedTLWindowManager()->GetEventBubble() )
            {
                // button down event
                if( EventCallback( TL_EVENT_BUTTON_DBLCLK ) == TL_EVENT_RESULT_NOT_SET_EVENT )
                    EventCallback( TL_EVENT_BUTTON_DOWN );

                // 
                ms_setButtonDownWindow.insert( this );
                ms_pDownWindow = this;
                m_bCanTouchDD = true;
            }
            return true;
        }
	}

	// 
	SetIsPressed( true, TLWindowManager::SharedTLWindowManager()->getWorldTime() );

	// double click event
	if( EventCallback( TL_EVENT_BUTTON_DBLCLK ) == TL_EVENT_RESULT_NOT_SET_EVENT )
		EventCallback( TL_EVENT_BUTTON_DOWN );

	// 
	ms_setButtonDownWindow.insert( this );
	ms_pDownWindow = this;
    m_bCanTouchDD = true;

	// 
	if( ms_pFocusWindow != NULL && ms_pFocusWindow != this )
		ms_pFocusWindow->LostFocus( this );

	ms_pFocusWindow = this;

	return true;
}

bool TLWindow::OnMove( const CCPoint& point )
{
	if( !GetIsEnable() || !GetIsVisible() )
		return false;

	TLWindow* pChildWindow = FindWindow( point );
	if( pChildWindow != NULL )
	{
		if( pChildWindow->OnMove( point ) )
        {
            if ( m_uiWindowFlag & TL_WINDOW_FLAG_CONTAINER && TLWindowManager::SharedTLWindowManager()->GetEventBubble() )
            {
                EventCallback( TL_EVENT_MOUSE_MOVE );
            }
            return true;
        }
	}

	//////////////////////////////////////////////////////////////////////////
	EventCallback( TL_EVENT_MOUSE_MOVE );

	return true;
}

bool TLWindow::OnButtonRelease()
{
	//////////////////////////////////////////////////////////////////////////
    if( ms_pDownWindow == this )
    {
        ms_pDownWindow = NULL;
    }
	EventCallback( TL_EVENT_BUTTON_RELEASE );
    m_bCanTouchDD = false;

	return true;
}

int TLWindow::StartDropDrag( TLDropDragHelper& DDHelper )
{
	if( !GetWindowFlag( TL_WINDOW_FLAG_TOUCH_OFF_DROP_DRAG ) )
		return TL_EVENT_RESULT_DROP_DRAG_START_FAILED;

	// 
	return EventCallback( TL_EVENT_DROP_DRAG_START, &DDHelper );
}

//int TLWindow::EndDropDrag( TLDropDragHelper& DDHelper )
//{
//	return EventCallback( TL_EVENT_DROP_DRAG_END, 0xFFFFFFFF, (unsigned int)&DDHelper );
//}

int TLWindow::ReceiveDropDrag( TLDropDragHelper& DDHelper )
{
	if( DDHelper.m_pSourceWindow == this )
		return TL_EVENT_RESULT_DROP_DRAG_RECEIVE_FAILED;

	if( !GetWindowFlag( TL_WINDOW_FLAG_RECEIVE_DROP_DRAG ) )
		return TL_EVENT_RESULT_DROP_DRAG_RECEIVE_FAILED;

	// 
	return EventCallback( TL_EVENT_DROP_DRAG_RECEIVE, &DDHelper );
}

int TLWindow::CancelDropDrag( TLDropDragHelper& DDHelper )
{
	return EventCallback( TL_EVENT_DROP_DRAG_CANCEL, &DDHelper );
}

void TLWindow::LostFocus( TLWindow* pFocusWindow )
{
	EventCallback( TL_EVENT_LOST_FOCUS );

	//////////////////////////////////////////////////////////////////////////
	if( m_pEditBox != NULL )
    {
		m_pEditBox->detachWithIME();
    }
}

//////////////////////////////////////////////////////////////////////////
bool TLWindow::AddChildWindow( TLWindow* pChildWindow )
{
    if ( !pChildWindow->GetWindowName().empty() )
    {
        TLWindow* pWindow = FindWindow( pChildWindow->GetWindowName(), false );
		CCAssert( pWindow == NULL, "ChildWindow Duplicate Name!" );
        m_mapChildWindow[pChildWindow->GetWindowName()] = pChildWindow;
    }

	m_listChildWindow->addObject( pChildWindow );

	//////////////////////////////////////////////////////////////////////////
	CCNode* pAttachNode = pChildWindow->m_pMCNode;
	if( pAttachNode != NULL && pAttachNode->getParent() == NULL )
		m_pMCNode->addChild( pAttachNode );

	//////////////////////////////////////////////////////////////////////////
	return true;
}

void TLWindow::RemoveAllChildWindow()
{
    m_listChildWindow->removeAllObjects();
	m_mapChildWindow.clear();

    if( ms_pFocusWindow == this )
        ms_pFocusWindow = NULL;

    if( ms_pDownWindow == this )
        ms_pDownWindow = NULL;

    ms_setButtonDownWindow.erase( this );
    m_bCanTouchDD = false;
}

TLWindow* TLWindow::FindWindow( const std::string& strWindowName, bool bFindInChild )
{
	if( strWindowName.compare( m_strWindowName ) == 0 )
		return this;

	std::map<std::string,TLWindow*>::iterator iter = m_mapChildWindow.find( strWindowName );
	if( iter != m_mapChildWindow.end() )
		return iter->second;

	if( bFindInChild )
	{
        for( int i=0; i < (int)m_listChildWindow->count(); ++i )
		{
			TLWindow* pWindow = ((TLWindow*)m_listChildWindow->objectAtIndex(i))->FindWindow( strWindowName, bFindInChild );
			if( pWindow != NULL )
				return pWindow;
		}
	}

	return NULL;
}

TLWindow* TLWindow::FindWindow( const CCPoint& point )
{
    for(int i=m_listChildWindow->count()-1; i>=0; i--)
	{
        TLWindow* pChildWindow = (TLWindow*)m_listChildWindow->objectAtIndex(i);
		if( pChildWindow->HitTest( point ) )
			return pChildWindow;
	}

	return NULL;
}

TLWindow* TLWindow::FindReceiveDropDragWindow( const CCPoint& point )
{
	// 不在这个窗口上,直接返回NULL
	if( !HitTest( point ) )
		return NULL;

	if( !GetIsEnable() || !GetIsVisible() )
		return NULL;

	if( GetWindowFlag( TL_WINDOW_FLAG_RECEIVE_DROP_DRAG ) )
		return this;

    for( int i=0; i < (int)m_listChildWindow->count(); ++i )
	{
		TLWindow* pFildWindow = ((TLWindow*) m_listChildWindow->objectAtIndex(i))->FindReceiveDropDragWindow( point );
		if( pFildWindow != NULL )
			return pFildWindow;
	}

	return NULL;
}

//////////////////////////////////////////////////////////////////////////
void TLWindow::setText( const char* pszText )
{
    if( m_pEditBox != NULL )
        m_pEditBox->setText( pszText );
}

const char* TLWindow::getText()
{
    return m_pEditBox != NULL ? m_pEditBox->getText() : NULL;
}

void TLWindow::setTextColor( const ccColor3B& kTextColor )
{
    if( m_pEditBox != NULL )
        m_pEditBox->setTextColor( kTextColor );
}

const ccColor3B& TLWindow::getTextColor()
{
    return m_pEditBox != NULL ? m_pEditBox->getTextColor() : ccc3( 255, 255, 255 );
}

void TLWindow::setPlaceHolder( const char* pszText )
{
    if( m_pEditBox != NULL )
        m_pEditBox->setPlaceHolder( pszText );
}

const char* TLWindow::getPlaceHolder()
{
    return m_pEditBox != NULL ? m_pEditBox->getPlaceHolder() : NULL;
}

void TLWindow::setPlaceHolderColor( const ccColor3B& kPlaceHolderColor )
{
    if( m_pEditBox != NULL )
        m_pEditBox->setPlaceHolderColor( kPlaceHolderColor );
}

const ccColor3B& TLWindow::getPlaceHolderColor()
{
    return m_pEditBox != NULL ? m_pEditBox->getPlaceHolderColor() : ccc3( 255, 255, 255 );
}

void TLWindow::setFontSize( int nFontSize )
{
    if( m_pEditBox != NULL )
        m_pEditBox->setFontSize( nFontSize );
}

void TLWindow::setPlaceFontSize( int nFontSize )
{
    if( m_pEditBox != NULL )
        m_pEditBox->setPlaceFontSize( nFontSize );
}

void TLWindow::setRichFlag( TL_RICH_STRING_FLAG eRichFlag )
{
    if( m_pEditBox != NULL )
        m_pEditBox->setRichFlag( eRichFlag );
}

void TLWindow::setAlignment( CCImage::ETextAlign eAlignment )
{
    if( m_pEditBox != NULL )
        m_pEditBox->setAlignment( eAlignment );
}

void TLWindow::setInputMode( TL_INPUT_TEXT_MODEL eInputMode )
{
    if( m_pEditBox != NULL )
        m_pEditBox->setInputMode( eInputMode );
}

void TLWindow::setMaxLength( int nMaxLength )
{
    if( m_pEditBox != NULL )
        m_pEditBox->setMaxLength( nMaxLength );
}

void TLWindow::setInputFlag( TL_INPUT_FLAG eInputFlag )
{
    if( m_pEditBox != NULL )
        m_pEditBox->setInputFlag( eInputFlag );
}

void TLWindow::setReturnType( TL_RETURN_TYPE eReturnType )
{
    if( m_pEditBox != NULL )
        m_pEditBox->setReturnType( eReturnType );
}

void TLWindow::setKeyboardWillShowHandler( int nWillShowHandler )
{
    if( m_pEditBox != NULL )
        m_pEditBox->setKeyboardWillShowHandler( nWillShowHandler );
}

void TLWindow::setKeyboardWillHideHandler( int nWillHideHandler )
{
    if( m_pEditBox != NULL )
        m_pEditBox->setKeyboardWillHideHandler( nWillHideHandler );
}

CCSize TLWindow::getRealSize()
{
    if( m_pEditBox != NULL )
        return m_pEditBox->getRealSize();

    return CCSizeZero;
}

//////////////////////////////////////////////////////////////////////////
void TLWindow::AllButtonRelease()
{
	std::set<TLWindow*>::iterator iter = ms_setButtonDownWindow.begin();
	std::set<TLWindow*>::iterator iter_end = ms_setButtonDownWindow.end();
	for( ; iter != iter_end; ++iter )
		(*iter)->OnButtonRelease();

	ms_setButtonDownWindow.clear();
}

//////////////////////////////////////////////////////////////////////////
int TLWindow::EventCallback( TL_WINDOW_EVENT eEventType, TLDropDragHelper* pkDDHelper )
{
	if( ((eEventType == TL_EVENT_BUTTON_UP) || (eEventType == TL_EVENT_BUTTON_RELEASE)) && !m_bIsResponseButtonUp )
	{
		m_bIsResponseButtonUp = true;

		return EventCallback( TL_EVENT_BUTTON_RELEASE );
	}

    std::map<TL_WINDOW_EVENT,int>::iterator iter = m_mapEventCallback.find( eEventType );
	if( iter == m_mapEventCallback.end() )
		return TL_EVENT_RESULT_NOT_SET_EVENT;

	if( eEventType == TL_EVENT_LONG_PRESS )
		m_bIsResponseButtonUp = false;

	int argNum = 0;
	if( pkDDHelper != NULL )
	{
		argNum = 1;
		CCLuaEngine::defaultEngine()->getLuaStack()->pushCCObject( pkDDHelper, "TLDropDragHelper" );
	}

	return CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( iter->second, argNum );
}

void TLWindow::RemoveChildWindow( TLWindow* pWindow )
{
    if (!pWindow->GetWindowName().empty())
        m_mapChildWindow.erase(pWindow->GetWindowName());

    if (ms_pFocusWindow==pWindow)
    {
        ms_pFocusWindow = NULL;
    }
    if (ms_pDownWindow==pWindow)
    {
        ms_pDownWindow = NULL;
    }
	ms_setButtonDownWindow.erase(pWindow);
    pWindow->m_bCanTouchDD = false;

	m_listChildWindow->removeObject(pWindow);
}

