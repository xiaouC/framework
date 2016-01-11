#pragma once
#include "../Common/TLCommon.h"
#include "semaphore.h"

class CNetSender;

class CNetWorkThread
{
public:
	CNetWorkThread( CNetSender* pNetSender );
	~CNetWorkThread();

	bool Connect( const char* szIPAddr, unsigned int uiPort );
	void CloseSocket( NetWordThreadStatus status );

#ifdef WIN32
	static void RecvThread( void* pParam );
	static void SendThread( void* pParam );
#else
	static void* RecvThread( void* pParam );
	static void* SendThread( void* pParam );
#endif

	SOCKET GetSocketID() { return m_socketID; }

    bool RecvThreadRunning() { return m_bRecvThreadExit; }
    bool SendThreadRunning() { return m_bSendThreadExit; }

    void SetStatus( NetWordThreadStatus status ) { CAutoLock autoLock( m_socketLock ); m_status = status; }
    NetWordThreadStatus GetStatus() { return m_status; }

    void setIsNeedReconnection( bool bIsNeedReconnection ) { m_bIsNeedReconnection = bIsNeedReconnection; }
    bool getIsNeedReconnection() const { return m_bIsNeedReconnection; }

protected:
    bool checkSocketState();

    CNetSender* m_pNetSender;

	SOCKET m_socketID;
	XL_LOCK m_socketLock;

	char* m_szIPAddr;
	unsigned int m_uiPort;

	//////////////////////////////////////////////////////////////////////////
	bool m_bIsExit;

	bool m_bRecvThreadExit;
	bool m_bSendThreadExit;

	XL_ThreadHandle m_hRecvThreadID;
	XL_ThreadHandle m_hSendThreadID;

    NetWordThreadStatus m_status;
    float m_fLastConnectTime;           // 上一次创建 socket 连接的时间
    bool m_bIsNeedReconnection;         // 当前连接如果断开的话，是否需要重连
};
