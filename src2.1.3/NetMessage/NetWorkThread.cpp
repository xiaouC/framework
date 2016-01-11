#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "../NetMessage/NetWorkThread.h"
#include "../NetMessage/NetMsgProcess.h"
#include "../NetMessage/NetMsg.h"
#include "../UI/TLWindowManager.h"
#include "CCCommon.h"
#include "CCLuaEngine.h"
#include <errno.h>
#include <CCStdC.h>
#include <ccMacros.h>

#ifdef WIN32
#pragma comment(lib, "wsock32")
#include <process.h>
#else
#include <netinet/tcp.h>
#include "sys/socket.h"
#include "arpa/inet.h"
#include <unistd.h>
#include "pthread.h"
#endif

CNetWorkThread::CNetWorkThread(CNetSender* pNetSender)
: m_pNetSender(pNetSender)
, m_socketID(INVALID_SOCKET)
, m_szIPAddr(NULL)
, m_uiPort(0)
, m_bIsExit(false)
, m_bRecvThreadExit(true)
, m_bSendThreadExit(true)
, m_status(NWTS_CLOSED)
, m_fLastConnectTime(0.0f)
, m_bIsNeedReconnection(true)
{
	LockInit( m_socketLock );

	// receive thread
#ifdef WIN32
	m_hRecvThreadID = _beginthread( &CNetWorkThread::RecvThread, 0, this );
#else
	pthread_create( &m_hRecvThreadID, NULL, &CNetWorkThread::RecvThread, this );
#endif

	// send thread
#ifdef WIN32
	m_hSendThreadID = _beginthread( &CNetWorkThread::SendThread, 0, this );
#else
	pthread_create( &m_hSendThreadID, NULL, &CNetWorkThread::SendThread, this );
#endif
}

CNetWorkThread::~CNetWorkThread()
{
	m_bIsExit = true;

	sem_t* pSendMsgSem = m_pNetSender->GetSendMsgSem();
	sem_post( pSendMsgSem );

	CloseSocket( NWTS_CLOSED );

	// 退出的时候，要自己给自己发送一条网络消息
	// 以便让接收线程不再阻塞，正常退出
	while( !m_bRecvThreadExit || !m_bSendThreadExit )
		XL_Sleep( 1 );

	SocketCleanUp();

	LockRelease( m_socketLock );
}

bool CNetWorkThread::Connect( const char* szIPAddr, unsigned int uiPort )
{
	CAutoLock autoLock( m_socketLock );

	if( szIPAddr == NULL )
		return false;

	//////////////////////////////////////////////////////////////////////////
	if( m_socketID != INVALID_SOCKET )
	{
		if( strcmp( m_szIPAddr, szIPAddr ) == 0 && m_uiPort == uiPort )
			return true;

		CloseSocket( NWTS_CLOSED );
	}

	//////////////////////////////////////////////////////////////////////////
	if( m_szIPAddr != NULL )
		delete[] m_szIPAddr;

	int nLength = strlen( szIPAddr );
	m_szIPAddr = new char[nLength+1];
	memcpy( m_szIPAddr, szIPAddr, nLength );
	m_szIPAddr[nLength] = '\0';

	m_uiPort = uiPort;

    // 如果是连接中或者已经连接上的状态的话，就需要重连
	SOCKET socketID = socket( AF_INET, SOCK_STREAM, 0 );
	if( socketID == INVALID_SOCKET )
    {
        printf( "new socket error:%s\n", strerror( errno ) );
        CNetReceiver::SharedNetReceiver()->SendErrorMsgToSelf( NWTC_INVALID_SOCKET );
		return false;
    }

    CNetReceiver::SharedNetReceiver()->setIsSendKickOutFlag( true );

    // set socket timeout
#ifdef WIN32
	int timeout = 10000; // 10s
#else
    struct timeval timeout;      
    timeout.tv_sec = 10; // 10S
    timeout.tv_usec = 0;
#endif
    int ret = setsockopt( socketID, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof( timeout ) );
    ret = setsockopt( socketID, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof( timeout ) );

    // 
	sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr( m_szIPAddr );
	sa.sin_port = htons( (u_short)m_uiPort );

    if( connect( socketID, (sockaddr*)&sa, sizeof( sa ) ) != 0 )
    {
        printf( "connect error:%s\n", strerror( errno ) );
        CNetReceiver::SharedNetReceiver()->SendErrorMsgToSelf( NWTC_SOCKET_CONNECT_ERROR );
        return false;
    }

    // set socket timeout
#ifdef WIN32
	timeout = 100000000;        // 相当于不超时
#else
    timeout.tv_sec = 100000;    // 相当于不超时
    timeout.tv_usec = 0;
#endif
    ret = setsockopt( socketID, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof( timeout ) );
    ret = setsockopt( socketID, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof( timeout ) );
    
    int no_delay = 1;
    ret = setsockopt( socketID, IPPROTO_TCP, TCP_NODELAY, (const char*)&no_delay, sizeof( no_delay ) );
    if( ret == -1 )
    {
        printf( "TCP_NODELAY error : %s\n", strerror( errno ) );
    }

    m_socketID = socketID;
    m_status = NWTS_CONNECTED;

    CNetReceiver::SharedNetReceiver()->SendErrorMsgToSelf( NWTC_SOCKET_CONNECT_SUCCESS );

	return true;
}

void CNetWorkThread::CloseSocket( NetWordThreadStatus status )
{
	CAutoLock autoLock( m_socketLock );

	SOCKET socketID = m_socketID;

	m_status = status;
	m_socketID = INVALID_SOCKET;

#ifdef WIN32
	closesocket( socketID );
#else
	shutdown( socketID, SHUT_RDWR );
    close( socketID );
#endif
}

#ifdef WIN32
void CNetWorkThread::RecvThread( void* pParam )
#else
void* CNetWorkThread::RecvThread( void* pParam )
#endif
{
	CNetWorkThread* pThis = (CNetWorkThread*)pParam;

	pThis->m_bRecvThreadExit = false;

	//XL_Sleep( 3 );

    unsigned int szRecvBufLen = RECV_MSG_BUFF_LENGTH;
    char* szRecvBuf = (char*)malloc(szRecvBufLen * sizeof(char));
	while( !pThis->m_bIsExit )
	{
        if( !pThis->checkSocketState() )
        {
            XL_Sleep( 1 );

            continue;
        }

        char szLenBuf[4];
        unsigned int nNeedLength = sizeof(szLenBuf);
        unsigned int nExistTotal = 0;

        bool bErrorFlag = false;
        int nLength = 0;
        while( nNeedLength > 0 )
        {
            nLength = recv( pThis->m_socketID, szLenBuf+nExistTotal, nNeedLength, 0 );
            if( nLength <= 0 )
			{
#ifdef WIN32
				int a = WSAGetLastError();
				int b = WSAETIMEDOUT;
				printf("recv return: %d %d %d\n", nLength, errno, a);
				if( nLength == 0 || ( a != b ) )
#else
				printf("recv return: %d %d\n", nLength, errno);
                if( nLength == 0 || errno != EINTR )
#endif
                {
                    bErrorFlag = true;
                    break;
                }

                continue;
            }

            nNeedLength -= nLength;
            nExistTotal += nLength;
        }

        if( !bErrorFlag )
        {
            CCAssert( nExistTotal == sizeof( szLenBuf ), "impossible" );

            unsigned uiMsgLength = ntohl( *(unsigned int*)szLenBuf );
            nNeedLength = uiMsgLength - sizeof(szLenBuf);

            if( nNeedLength + sizeof( szLenBuf ) > szRecvBufLen )
            {
                // not enough buffer
                szRecvBufLen = nNeedLength + sizeof( szLenBuf );
                szRecvBuf = (char*)realloc( szRecvBuf, szRecvBufLen );
            }

            memcpy( szRecvBuf, szLenBuf, sizeof( szLenBuf ) );

            while( nNeedLength > 0 )
            {
                nLength = recv( pThis->m_socketID, szRecvBuf + nExistTotal, (unsigned)nNeedLength, 0 );
                if( nLength <= 0 )
                {
#ifdef WIN32
					int a = WSAGetLastError();
					int b = WSAETIMEDOUT;
					printf( "recv return: %d %d %d\n", nLength, errno, a );
					if( nLength == 0 || ( a != b ) )
#else
					printf( "recv return: %d %d\n", nLength, errno );
					if( nLength == 0 || errno != EINTR )
#endif
					{
						bErrorFlag = true;
						break;
					}
					continue;
                }

                nExistTotal += nLength;
                nNeedLength -= nLength;
            }

            if( !bErrorFlag )
            {
                CNetMsg* pNetMsg = CNetSender::SharedNetSender()->parseNetMsg( szRecvBuf, uiMsgLength );
                CNetReceiver::SharedNetReceiver()->AppendMsg( pNetMsg );
            }
            else
            {
                printf( "recv error1 %d %s\n", nLength, strerror( errno ) );
                if( nLength == 0 )
                {
                    pThis->CloseSocket( NWTS_CLOSED );
                    if( CNetReceiver::SharedNetReceiver()->getIsSendKickOutFlag() )
                        CNetReceiver::SharedNetReceiver()->SendErrorMsgToSelf( NWTC_SOCKET_SERVER_KICK_OUT );
                }
                else
                {
                    pThis->CloseSocket( NWTS_RECONNECTING );

                    CNetReceiver::SharedNetReceiver()->SendErrorMsgToSelf( NWTC_SOCKET_RECEIVE_ERROR );
                }
            }
        }

		if( nLength <= 0 && pThis->m_socketID != INVALID_SOCKET )
		{
            // 关闭当前 socket
            printf( "recv error2 %d %s\n", nLength, strerror( errno ) );
            if( nLength == 0 )
            {
                pThis->CloseSocket( NWTS_CLOSED );
                if( CNetReceiver::SharedNetReceiver()->getIsSendKickOutFlag() )
                    CNetReceiver::SharedNetReceiver()->SendErrorMsgToSelf( NWTC_SOCKET_SERVER_KICK_OUT );
            }
            else
            {
                pThis->CloseSocket( NWTS_RECONNECTING );

                // 尝试重连
                if( !pThis->checkSocketState() )
                {
                    CNetReceiver::SharedNetReceiver()->SendErrorMsgToSelf( NWTC_SOCKET_RECEIVE_ERROR );
                }
            }
		}
	}

    free( szRecvBuf );
	pThis->m_bRecvThreadExit = true;

#ifndef WIN32
	return NULL;
#endif
}

#ifdef WIN32
void CNetWorkThread::SendThread( void* pParam )
#else
void* CNetWorkThread::SendThread( void* pParam )
#endif
{
	CNetWorkThread* pThis = (CNetWorkThread*)pParam;

	pThis->m_bSendThreadExit = false;

	//XL_Sleep( 3 );

	while( !pThis->m_bIsExit )
	{
		sem_t* pSendMsgSem = pThis->m_pNetSender->GetSendMsgSem();
		sem_wait( pSendMsgSem );

        if( !pThis->checkSocketState() )
        {
            XL_Sleep( 1 );

            continue;
        }

		CNetMsg* pNetMsg = pThis->m_pNetSender->GetSendMessage();
		if( pNetMsg != NULL )
		{
            unsigned int uiMsgID = pNetMsg->GetMsgID();
            unsigned short sRealMsgID, sSquID;
            unpackMsgID( uiMsgID, sRealMsgID, sSquID );

			//////////////////////////////////////////////////////////////////////////
            // 待发送的数据临时拷贝一份
			unsigned int uiCount = 0;
			unsigned int uiLength = (unsigned int)pNetMsg->m_uiMsgLength;
            char* szSendData = new char[uiLength+1];
            memcpy( szSendData, pNetMsg->m_szMsgData, uiLength );
            szSendData[uiLength] = '\0';

            // 放到等待服务器返回的消息列表中
            pThis->m_pNetSender->appendWaitRecvMsg( pNetMsg );
            
            // 发送数据
            bool bNeedSleep = false;
			while( uiCount < uiLength )
			{
                // 在某些小米手机上，发送的长度首到限制，发送不出去
                unsigned int uiSendLength = uiLength - uiCount;
                if( uiSendLength > 1024 )
                {
                    uiSendLength = 1024;
                    bNeedSleep = true;
                }
                else
                {
                    bNeedSleep = false;
                }

#ifdef WIN32
				int nBytes = send( pThis->m_socketID, szSendData + uiCount, uiSendLength, 0 );
#else
#ifdef SO_NOSIGPIPE
                int nBytes = send( pThis->m_socketID, szSendData + uiCount, uiSendLength, SO_NOSIGPIPE );
#else
				int nBytes = send( pThis->m_socketID, szSendData + uiCount, uiSendLength, MSG_NOSIGNAL );
#endif
#endif
				if( nBytes == -1 || nBytes == 0 )
				{
					CNetReceiver::SharedNetReceiver()->SendErrorMsgToSelf( NWTC_SOCKET_RECEIVE_ERROR );

					break;
				}

				uiCount += nBytes;

                if( bNeedSleep )
                {
                    XL_Sleep( 0.5 );
                }
			}

            delete[] szSendData;

            sem_post( pSendMsgSem );
		}
	}

	pThis->m_bSendThreadExit = true;

#ifndef WIN32
	return NULL;
#endif
}

bool CNetWorkThread::checkSocketState()
{
    CAutoLock autoLock( m_socketLock );

    // socket 有效
    if( m_socketID != INVALID_SOCKET )
        return true;

    // 如果当前还不需要连接的话，不进行重连
    if( m_status == NWTS_CLOSED )
        return false;

    // 如果不需要重连的话，直接关闭 socket
    if( !m_bIsNeedReconnection )
    {
        CloseSocket( NWTS_CLOSED );

        CNetReceiver::SharedNetReceiver()->SendErrorMsgToSelf( NWTC_SOCKET_DISCONNECT );

        return false;
    }

    // 如果是
    if( m_status == NWTS_RECONNECTING )
        CNetReceiver::SharedNetReceiver()->SendErrorMsgToSelf( NWTC_SOCKET_RECONNECT );

    return false;
}
