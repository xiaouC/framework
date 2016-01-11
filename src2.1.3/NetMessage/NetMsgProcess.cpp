#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <CCCommon.h>
#include "tolua++.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "google/protobuf/message_lite.h"

#ifndef WIN32
#include <sys/socket.h>
#include <arpa/inet.h>
#endif

#include "../NetMessage/NetMsgProcess.h"
#include "../NetMessage/NetWorkThread.h"
#include "../NetMessage/NetMsg.h"

static CNetSender* g_pNetSender = NULL;
CNetSender* CNetSender::SharedNetSender()
{
    if( g_pNetSender == NULL )
    {
        std::string strSemName = std::string( "net_sender" ) + getProjectNickname();
        g_pNetSender = new CNetSender( strSemName.c_str() );
    }

    return g_pNetSender;
}

CNetSender::CNetSender(const char* sem_name)
: m_nClearMsgIDHandler(0)
{
    LockInit( m_SendNetMsgLock );

    m_pSemSendMsg = NULL;
#if USE_NAMED_SEMAPHORE
    CCAssert(sem_name!=NULL, "don't support unnamed semaphore");
    m_pSemSendMsg = sem_open(sem_name, O_CREAT, 0644, 0);
    if( m_pSemSendMsg == SEM_FAILED )
    {
        CCLog( "CCTextureCache async thread semaphore init error: %s\n", strerror( errno ) );
        CCAssert(false, "open named sem failed");
        m_pSemSendMsg = NULL;
        return;
    }
#else
    int iRet = sem_init(&m_sem, 0, 0);
    if (iRet<0)
    {
        CCLog( "CCTextureCache async thread semaphore init error: %s\n", strerror( errno ) );
        CCAssert(false, "init sem failed");
        return;
    }
    m_pSemSendMsg = &m_sem;
#endif

    m_pNetWorkThread = new CNetWorkThread(this);
}

CNetSender::~CNetSender()
{
    if( m_nClearMsgIDHandler > 0 )
        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nClearMsgIDHandler );
    m_nClearMsgIDHandler = 0;

	delete m_pNetWorkThread;
	sem_destroy( m_pSemSendMsg );
	LockRelease( m_SendNetMsgLock );

    std::list<CNetMsg*>::iterator iter = m_listSendMsg.begin();
    std::list<CNetMsg*>::iterator iter_end = m_listSendMsg.end();
    for( ; iter != iter_end; ++iter )
        delete (*iter);
    m_listSendMsg.clear();

    g_pNetSender = NULL;
}

void CNetSender::SendNetMessage( CNetMsg* pNetMsg )
{
	CAutoLock autoLock( m_SendNetMsgLock );

	m_listSendMsg.push_back( pNetMsg );

	sem_post( m_pSemSendMsg );
}

CNetMsg* CNetSender::GetSendMessage()
{
	CAutoLock autoLock( m_SendNetMsgLock );

    NetWordThreadStatus statue = m_pNetWorkThread->GetStatus();
    if( statue == NWTS_CONNECTED )
    {
        if( !m_listSendMsg.empty() )
        {
            std::list<CNetMsg*>::iterator iter = m_listSendMsg.begin();

            CNetMsg* pSendMsg = (*iter);

            m_listSendMsg.erase( iter );

            return pSendMsg;
        }
    }
    else
    {
        std::list<CNetMsg*>::iterator iter = m_listSendMsg.begin();
        std::list<CNetMsg*>::iterator iter_end = m_listSendMsg.end();
        for( ; iter != iter_end; ++iter )
        {
            CNetMsg* pNetMsg = (*iter);

            unsigned short sRealMsgID, sSquID;
            unpackMsgID( pNetMsg->GetMsgID(), sRealMsgID, sSquID );
            printf( "verify ================================================================================================\n" );
            printf( "verify ================================================================================================\n" );
            printf( "send msg id : %d\n", sRealMsgID );
            printf( "verify ================================================================================================\n" );
            printf( "verify ================================================================================================\n" );

            printf( "m_setReconnectVerifyMsgID size = %d\n", (int)m_setReconnectVerifyMsgID.size() );
            std::set<unsigned int>::iterator iter1 = m_setReconnectVerifyMsgID.find( sRealMsgID );
            if( iter1 != m_setReconnectVerifyMsgID.end() )
            {
                m_listSendMsg.erase( iter );

                return pNetMsg;
            }
        }
    }

	return NULL;
}

bool CNetSender::Connect( const char* szIPAddr, unsigned int uiPort )
{
	return m_pNetWorkThread->Connect( szIPAddr, uiPort );
}

void CNetSender::setClearMsgIDHandler( int nHandler )
{
	CAutoLock autoLock( m_SendNetMsgLock );

    if( m_nClearMsgIDHandler > 0 )
        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nClearMsgIDHandler );

    m_nClearMsgIDHandler = nHandler;
}

void CNetSender::CloseSocket( NetWordThreadStatus status )
{
    CAutoLock autoLock( m_SendNetMsgLock );

    // 清理已经发送的队列
    std::list<CNetMsg*>::iterator iter = m_listWaitRecvMsg.begin();
    std::list<CNetMsg*>::iterator iter_end = m_listWaitRecvMsg.end();
    for( ; iter != iter_end; ++iter )
    {
        CNetMsg* pNetMsg = *iter;

        unsigned short sRealMsgID, sSquID;
        unpackMsgID( pNetMsg->GetMsgID(), sRealMsgID, sSquID );

        // 重连并且需要重新发送的，就重新加入到发送队列的前面去
        if( status == NWTS_RECONNECT_REQUEST && m_setResendMsgID.find( sRealMsgID ) != m_setResendMsgID.end() )
        {
            m_listSendMsg.push_front( pNetMsg );
        }
        else
        {
            // 被清理的 msg 要通知 lua 做处理
            if( m_nClearMsgIDHandler > 0 )
            {
                CCLuaEngine::defaultEngine()->getLuaStack()->pushInt( sRealMsgID );
                CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nClearMsgIDHandler, 1 );
            }

            delete pNetMsg;
        }
    }
    m_listWaitRecvMsg.clear();

    // 不是重连的话，就清理掉所有还没有发送出去的 msg
    if( status != NWTS_RECONNECT_REQUEST )
    {
        std::list<CNetMsg*>::iterator iter = m_listSendMsg.begin();
        std::list<CNetMsg*>::iterator iter_end = m_listSendMsg.end();
        for( ; iter != iter_end; ++iter )
            delete (*iter);
        m_listSendMsg.clear();
    }

    // 关闭 socket
	m_pNetWorkThread->CloseSocket( status );
}

void CNetSender::appendReconnectVerifyMsgID( unsigned int msgID )
{
	CAutoLock autoLock( m_SendNetMsgLock );

    m_setReconnectVerifyMsgID.insert( msgID );
}

void CNetSender::setIsNeedReconnection( bool bIsNeedReconnection )
{
    m_pNetWorkThread->setIsNeedReconnection( bIsNeedReconnection );
}

bool CNetSender::getIsNeedReconnection() const
{
    return m_pNetWorkThread->getIsNeedReconnection();
}

void CNetSender::setSocketStatus( NetWordThreadStatus status )
{
    m_pNetWorkThread->SetStatus( status );
}

NetWordThreadStatus CNetSender::getSocketStatus()
{
    return m_pNetWorkThread->GetStatus();
}

void CNetSender::reconnectionVerify()
{
    m_pNetWorkThread->SetStatus( NWTS_RECONNECTING );

	sem_post( m_pSemSendMsg );
}

void CNetSender::reconnectionSucceeful()
{
    m_pNetWorkThread->SetStatus( NWTS_CONNECTED );

	sem_post( m_pSemSendMsg );
}

void CNetSender::NewNetMsgAndSend( unsigned short msgID, google::protobuf::MessageLite* pMsg, int nCallBackHandler )
{
	std::string strMsgContent;
	pMsg->SerializeToString( &strMsgContent );

	NewNetMsgAndSend( msgID, strMsgContent.c_str(), strMsgContent.length(), nCallBackHandler );
}

void CNetSender::NewNetMsgAndSend( unsigned short msgID, const char* pszMsgData, int nLength, int nCallBackHandler )
{
	unsigned int uiMsgLength = nLength + 12;	// 12 是消息头长度

    unsigned int uiMsgID = packMsgID( msgID, GetNextSequenceID( msgID ) );

	CNetMsg* pNetMsg = new CNetMsg;
	pNetMsg->m_uiMsgLength = uiMsgLength;
	pNetMsg->m_uiMsgID = uiMsgID;
    pNetMsg->m_nCallBackHandler = nCallBackHandler;

	pNetMsg->m_szMsgData = new char[pNetMsg->m_uiMsgLength];
	memset( pNetMsg->m_szMsgData, 0, uiMsgLength );

	// 写消息头
	unsigned int uiTemp = htonl( pNetMsg->m_uiMsgLength );
	memcpy( pNetMsg->m_szMsgData, &uiTemp, 4 );

	uiTemp = htonl( pNetMsg->m_uiMsgID );
	memcpy( pNetMsg->m_szMsgData + 4, &uiTemp, 4 );

	uiTemp = htonl( pNetMsg->m_uiCode );
	memcpy( pNetMsg->m_szMsgData + 8, &uiTemp, 4 );

	// 写消息的实际内容
	if( pszMsgData != NULL )
		memcpy( pNetMsg->m_szMsgData + 12, pszMsgData, nLength );

	SendNetMessage( pNetMsg );
}

unsigned short CNetSender::GetNextSequenceID( unsigned short msgID )
{
    std::map<unsigned short,unsigned short>::iterator iter = m_mapSequenceID.find( msgID );
    if( iter != m_mapSequenceID.end() )
        return ++iter->second;

    m_mapSequenceID[msgID] = 1;

    return 1;
}

void CNetSender::appendWaitRecvMsg( CNetMsg* pNetMsg )
{
	CAutoLock autoLock( m_SendNetMsgLock );

    m_listWaitRecvMsg.push_back( pNetMsg );
}

CNetMsg* CNetSender::getWaitRecvMsg( unsigned int uiMsgID )
{
    CAutoLock autoLock( m_SendNetMsgLock );

    // 从等待列表里面查找
    std::list<CNetMsg*>::iterator iter = m_listWaitRecvMsg.begin();
    std::list<CNetMsg*>::iterator iter_end = m_listWaitRecvMsg.end();
    for( ; iter != iter_end; ++iter )
    {
        CNetMsg* pNetMsg = (*iter);
        if( pNetMsg->m_uiMsgID == uiMsgID )
        {
            if( pNetMsg->m_szMsgData != NULL )
            {
                delete[] pNetMsg->m_szMsgData;
                pNetMsg->m_szMsgData = NULL;
            }

            m_listWaitRecvMsg.erase( iter );

            return pNetMsg;
        }
    }

    // 等待列表中没有的话，就创建一个新的返回
    CNetMsg* pNetMsg = new CNetMsg;
    pNetMsg->m_uiMsgID = uiMsgID;
    return pNetMsg;
}

CNetMsg* CNetSender::parseNetMsg( char* szRevcBuf, unsigned int nLength )
{
	unsigned int uiTemp;
	memcpy( &uiTemp, szRevcBuf + 4, 4 );

    CNetMsg* pNetMsg = getWaitRecvMsg( ntohl( uiTemp ) );
    pNetMsg->m_uiMsgLength = nLength;

	pNetMsg->m_szMsgData = new char[nLength];
	memcpy( pNetMsg->m_szMsgData, szRevcBuf, nLength );

	memcpy( &uiTemp, pNetMsg->m_szMsgData + 8, 4 );
	pNetMsg->m_uiCode = ntohl( uiTemp );

	return pNetMsg;
}

/*
void CNetSender::sendNetMsgFailed( unsigned int uiMsgID )
{
    CAutoLock autoLock( m_SendNetMsgLock );

    CNetMsg* pNetMsg = NULL;

    std::map<unsigned int,WaitRecvMsgInfo>::iterator iter = m_mapWaitRecvMsg.find( uiMsgID );
    if( iter != m_mapWaitRecvMsg.end() )
    {
        pNetMsg = iter->second.pNetMsg;

        m_mapWaitRecvMsg.erase( iter );
    }

    if( pNetMsg != NULL )
        m_listSendMsg.push_front( pNetMsg );

    sem_post( m_pSemSendMsg );
}
*/

static CNetReceiver* g_pNetReceiver = NULL;
CNetReceiver::CNetReceiver()
: m_nMsgErrorDefaultHandler(0)
, m_bIsSendKickOutFlag(true)
{
	LockInit( m_RecvNetMsgLock );
}

CNetReceiver::~CNetReceiver()
{
	LockRelease( m_RecvNetMsgLock );
	while( !m_quRecvMsg.empty() )
	{
		CNetMsg* pNetMsg = m_quRecvMsg.front();
		m_quRecvMsg.pop();

		delete pNetMsg;
	}
	g_pNetReceiver = NULL;
}

CNetReceiver* CNetReceiver::SharedNetReceiver()
{
    if (g_pNetReceiver==NULL)
        g_pNetReceiver = new CNetReceiver();
    return g_pNetReceiver;
}

void CNetReceiver::ProcessMsg()
{
	CAutoLock autoLock( m_RecvNetMsgLock );

	while( !m_quRecvMsg.empty() )
	{
		CNetMsg* pNetMsg = m_quRecvMsg.front();
		m_quRecvMsg.pop();

        NetMsgCallback( pNetMsg );
		delete pNetMsg;
	}
}

void CNetReceiver::NetMsgCallback( CNetMsg* pNetMsg )
{
    unsigned int uiCode = pNetMsg->GetMsgCode();
    if( uiCode == 0 )
    {
        unsigned short sRealMsgID, sSquID;
        unpackMsgID( pNetMsg->GetMsgID(), sRealMsgID, sSquID );
        std::map<unsigned short,int>::iterator iter = m_mapNetMsgFunc.find( sRealMsgID );
        if( iter != m_mapNetMsgFunc.end() )
        {
            CCLuaEngine::defaultEngine()->getLuaStack()->pushCCObject( pNetMsg, "CNetMsg" );
            CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( iter->second, 1 );
        }

        // 发送消息者自己的回调
        if( pNetMsg->m_nCallBackHandler > 0 )
        {
            CCLuaEngine::defaultEngine()->getLuaStack()->pushCCObject( pNetMsg, "CNetMsg" );
            CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( pNetMsg->m_nCallBackHandler, 1 );
        }
    }
    else
    {
        int nErrHandler = m_nMsgErrorDefaultHandler;
        std::map<int,int>::iterator iter = m_mapMsgErrorFuncPtr.find( uiCode );
        if( iter != m_mapMsgErrorFuncPtr.end() )
            nErrHandler = iter->second;

        if( nErrHandler > 0 )
        {
            CCLuaEngine::defaultEngine()->getLuaStack()->pushCCObject( pNetMsg, "CNetMsg" );
            CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( nErrHandler, 1 );
        }
    }
}

void CNetReceiver::SetMsgErrorDefaultFuncPtr( int nLuaHandle )
{
	CAutoLock autoLock( m_RecvNetMsgLock );

	if( m_nMsgErrorDefaultHandler > 0 )
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nMsgErrorDefaultHandler );

	m_nMsgErrorDefaultHandler = nLuaHandle;
}

void CNetReceiver::RegisterMsgErrorFuncPtr( int nMsgCode, int nLuaHandle )
{
	CAutoLock autoLock( m_RecvNetMsgLock );

	std::map<int,int>::iterator iter = m_mapMsgErrorFuncPtr.find( nMsgCode );
	if( iter != m_mapMsgErrorFuncPtr.end() )
	{
		if( iter->second > 0 )
			CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( iter->second );

		iter->second = nLuaHandle;

		return;
	}

	m_mapMsgErrorFuncPtr[nMsgCode] = nLuaHandle;
}

void CNetReceiver::RegisterMsgProcessFuncPtr( unsigned short nMsgID, int nLuaHandler )
{
    CAutoLock autoLock( m_RecvNetMsgLock );

    std::map<unsigned short,int>::iterator iter = m_mapNetMsgFunc.find( nMsgID );
    if( iter != m_mapNetMsgFunc.end() )
        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( iter->second );

    m_mapNetMsgFunc[nMsgID] = nLuaHandler;
}

void CNetReceiver::AppendMsg( CNetMsg* pNetMsg )
{
	CAutoLock autoLock( m_RecvNetMsgLock );

    unsigned short sRealMsgID, sSquID;
    unpackMsgID( pNetMsg->GetMsgID(), sRealMsgID, sSquID );
    unsigned int uiCode = pNetMsg->GetMsgCode();

    // 如果是特殊的错误码的话，那么在网络线程就不发送 19 这个错误码，而使用这个特殊的错误码
    // 比如顶号的时候，不是提示服务器关闭之类的，而是提示顶号了
    // 现在在 socket 断开的时候，会主动发送 19 这个错误码，提示服务器关闭，这在一些情况下，提示不够精确
    // 这个标识，在重新创建网络连接的时候重置
    if( uiCode >= 60 && uiCode <= 90 )
        m_bIsSendKickOutFlag = false;

	m_quRecvMsg.push( pNetMsg );
}

void CNetReceiver::SendErrorMsgToSelf( unsigned int uiMsgCode )
{
	AppendMsg( new CNetMsg(uiMsgCode) );
}

void CNetReceiver::SendMsgToSelf( unsigned int msgID, google::protobuf::MessageLite* pMsg )
{
	unsigned int uiMsgLength = 0;
	std::string strMsgContent;
	pMsg->SerializeToString( &strMsgContent );
	uiMsgLength = strMsgContent.length() + 12;	// 12 是消息头长度

	CNetMsg* pNetMsg = new CNetMsg;
	pNetMsg->m_uiMsgLength = uiMsgLength;
	pNetMsg->m_uiMsgID = msgID;

	pNetMsg->m_szMsgData = new char[pNetMsg->m_uiMsgLength];
	memset( pNetMsg->m_szMsgData, 0, uiMsgLength );
	//写消息头
	unsigned int uiTemp = htonl( pNetMsg->m_uiMsgLength );
	memcpy( pNetMsg->m_szMsgData, &uiTemp, 4 );
	uiTemp = htonl( pNetMsg->m_uiMsgID );
	memcpy( pNetMsg->m_szMsgData + 4, &uiTemp, 4 );
	uiTemp = htonl( pNetMsg->m_uiCode );
	memcpy( pNetMsg->m_szMsgData + 8, &uiTemp, 4 );

	// 写消息的实际内容
	if( NULL != strMsgContent.c_str())
		memcpy( pNetMsg->m_szMsgData + 12, strMsgContent.c_str(), strMsgContent.length() );

	AppendMsg( pNetMsg );
}

void CNetReceiver::SendMsgToSelf( unsigned int msgID, const char* pszMsgData, int nLength )
{
	unsigned int uiMsgLength = nLength + 12;	// 12 是消息头长度

	CNetMsg* pNetMsg = new CNetMsg;
	pNetMsg->m_uiMsgLength = uiMsgLength;
	pNetMsg->m_uiMsgID = msgID;

	pNetMsg->m_szMsgData = new char[pNetMsg->m_uiMsgLength];
	memset( pNetMsg->m_szMsgData, 0, uiMsgLength );
	//写消息头
	unsigned int uiTemp = htonl( pNetMsg->m_uiMsgLength );
	memcpy( pNetMsg->m_szMsgData, &uiTemp, 4 );
	uiTemp = htonl( pNetMsg->m_uiMsgID );
	memcpy( pNetMsg->m_szMsgData + 4, &uiTemp, 4 );
	uiTemp = htonl( pNetMsg->m_uiCode );
	memcpy( pNetMsg->m_szMsgData + 8, &uiTemp, 4 );

	// 写消息的实际内容
	if( NULL != pszMsgData)
		memcpy( pNetMsg->m_szMsgData + 12, pszMsgData, nLength );

	AppendMsg( pNetMsg );
}

void CNetReceiver::Reset()
{
	CAutoLock autoLock( m_RecvNetMsgLock );

    while( !m_quRecvMsg.empty() )
    {
		CNetMsg* pNetMsg = m_quRecvMsg.front();
		delete pNetMsg;

        m_quRecvMsg.pop();
    }

	if( m_nMsgErrorDefaultHandler > 0 )
	{
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nMsgErrorDefaultHandler );

		m_nMsgErrorDefaultHandler = 0;
	}

	std::map<int,int>::iterator iter = m_mapMsgErrorFuncPtr.begin();
    for(; iter!=m_mapMsgErrorFuncPtr.end(); iter++)
    {
        if( iter->second > 0 )
			CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( iter->second );
    }
    m_mapMsgErrorFuncPtr.clear();
}


