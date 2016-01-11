#pragma once
#include "TLWindow.h"
#include <base_nodes/CCNode.h>
#include "../MC/MovieClip.h"
#include "../MC/MCFrame.h"
#include "../MC/MCLoader.h"
#include "CCLuaEngine.h"

//////////////////////////////////////////////////////////////////////////
TL_WINDOW_INLINE bool TLWindow::HitTest( const cocos2d::CCPoint& point )
{
	if( !GetIsVisible() )
		return false;

	if( m_pMCNode != NULL )
	{
		cocos2d::CCPoint pt = m_pMCNode->convertToNodeSpace( point );

		cocos2d::CCRect rcTemp = GetWindowRect();

		return rcTemp.containsPoint( pt );
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////
TL_WINDOW_INLINE CCArray* TLWindow::GetChildWindow()
{
	return m_listChildWindow;
}

//////////////////////////////////////////////////////////////////////////
TL_WINDOW_INLINE bool TLWindow::GetWindowFlag( unsigned int uiWindowFlag ) const
{
	return ( m_uiWindowFlag & uiWindowFlag ) ? true : false;
}

TL_WINDOW_INLINE void TLWindow::SetWindowFlag( unsigned int uiWindowFlag )
{
	m_uiWindowFlag = uiWindowFlag;
}

TL_WINDOW_INLINE void TLWindow::AddWindowFlag( unsigned int uiWindowFlag )
{
	m_uiWindowFlag |= uiWindowFlag;
}

TL_WINDOW_INLINE void TLWindow::RemoveWindowFlag( unsigned int uiWindowFlag )
{
	m_uiWindowFlag &= (~uiWindowFlag);
}

//////////////////////////////////////////////////////////////////////////
TL_WINDOW_INLINE void TLWindow::RegisterEvent( TL_WINDOW_EVENT eEventType, int nEventHandler )
{
    std::map<TL_WINDOW_EVENT,int>::iterator iter = m_mapEventCallback.find( eEventType );
    if( iter != m_mapEventCallback.end() )
        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( iter->second );

    m_mapEventCallback[eEventType] = nEventHandler;
}

TL_WINDOW_INLINE void TLWindow::unregisterEvent( TL_WINDOW_EVENT eEventType )
{
    std::map<TL_WINDOW_EVENT,int>::iterator iter = m_mapEventCallback.find( eEventType );
    if( iter != m_mapEventCallback.end() )
    {
        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( iter->second );

        m_mapEventCallback.erase( iter );
    }
}

//////////////////////////////////////////////////////////////////////////
TL_WINDOW_INLINE const std::string& TLWindow::GetWindowName() const
{
	return m_strWindowName;
}

TL_WINDOW_INLINE void TLWindow::SetWindowName( const std::string& strWindowName )
{
	m_strWindowName = strWindowName;
}

TL_WINDOW_INLINE bool TLWindow::GetIsEnable() const
{
	return GetWindowFlag( TL_WINDOW_FLAG_ENABLE );
}

TL_WINDOW_INLINE void TLWindow::SetIsEnable( bool bEnable )
{
	bEnable ? AddWindowFlag( TL_WINDOW_FLAG_ENABLE ) : RemoveWindowFlag( TL_WINDOW_FLAG_ENABLE );
}

TL_WINDOW_INLINE bool TLWindow::GetIsDragDroping() const
{
	return GetWindowFlag( TL_WINDOW_FLAG_DROP_DRAG );
}

TL_WINDOW_INLINE void TLWindow::SetIsDragDroping( bool bIsDragDroping )
{
	bIsDragDroping ? AddWindowFlag( TL_WINDOW_FLAG_DROP_DRAG ) : RemoveWindowFlag( TL_WINDOW_FLAG_DROP_DRAG );
}

TL_WINDOW_INLINE bool TLWindow::GetIsScroll() const
{
	return GetWindowFlag( TL_WINDOW_FLAG_SCROLL );
}

TL_WINDOW_INLINE bool TLWindow::GetIsInput() const
{
	return GetWindowFlag( TL_WINDOW_FLAG_INPUT );
}

TL_WINDOW_INLINE bool TLWindow::GetIsDblClked() const
{
	return GetWindowFlag( TL_WINDOW_FLAG_DBLCLKED );
}

TL_WINDOW_INLINE void TLWindow::SetIsDblClked( bool bIsDblClked )
{
	bIsDblClked ? AddWindowFlag( TL_WINDOW_FLAG_DBLCLKED ) : RemoveWindowFlag( TL_WINDOW_FLAG_DBLCLKED );
}

TL_WINDOW_INLINE bool TLWindow::GetIsVisible()
{
	if( m_pMCNode != NULL )
		return m_pMCNode->isVisible();

	return false;
}

TL_WINDOW_INLINE void TLWindow::SetIsVisible( bool bIsVisible )
{
	if( m_pMCNode != NULL )
		m_pMCNode->setVisible( bIsVisible );
}

TL_WINDOW_INLINE bool TLWindow::GetIsPressed() const
{
	return GetWindowFlag( TL_WINDOW_FLAG_PRESSED );
}

TL_WINDOW_INLINE void TLWindow::SetIsPressed( bool bIsPressed, float fTime )
{
	m_fPressTime = fTime;

	bIsPressed ? AddWindowFlag( TL_WINDOW_FLAG_PRESSED ) : RemoveWindowFlag( TL_WINDOW_FLAG_PRESSED );
}

TL_WINDOW_INLINE float TLWindow::GetPressTime() const
{
	return m_fPressTime;
}

TL_WINDOW_INLINE cocos2d::CCRect TLWindow::GetWindowRect()
{
    return getBoundingBox( GetNode(), true );
}

TL_WINDOW_INLINE void TLWindow::SetWindowPos( const cocos2d::CCPoint& point )
{
	if( m_pMCNode != NULL )
		m_pMCNode->setPosition( point );
}

TL_WINDOW_INLINE const cocos2d::CCPoint& TLWindow::GetWindowPos()
{
	if( m_pMCNode != NULL )
		return m_pMCNode->getPosition();

	return cocos2d::CCPointZero;
}

TL_WINDOW_INLINE bool TLWindow::GetCanTouchDD() const
{
    return m_bCanTouchDD;
}

TL_WINDOW_INLINE void TLWindow::SetCanTouchDD( bool bCanTouchDD )
{
    m_bCanTouchDD = bCanTouchDD;
}
