#pragma once
#include "../Common/TLCommon.h"
#include "semaphore.h"
#include <list>
#include <queue>
#include <map>

namespace google
{
    namespace protobuf
    {
        class MessageLite;
    }
}

class CNetMsg;
class CNetWorkThread;

typedef void(*NetMsgFuncPtr)( CNetMsg* pNetMsg );

class CNetSender
{
	friend class CNetWorkThread;
public:
    static CNetSender* SharedNetSender();

	void CloseSocket( NetWordThreadStatus state = NWTS_CLOSED );
	bool Connect( const char* szIPAddr, unsigned int uiPort );

	void NewNetMsgAndSend( unsigned short msgID, ::google::protobuf::MessageLite* pMsg, int nCallBackHandler = 0 );
	void NewNetMsgAndSend( unsigned short msgID, const char* pszMsgData = NULL, int nLength = 0, int nCallBackHandler = 0 );

    void appendReconnectVerifyMsgID( unsigned int msgID );

    void setIsNeedReconnection( bool bIsNeedReconnection );
    bool getIsNeedReconnection() const;

    void setSocketStatus( NetWordThreadStatus status );
    NetWordThreadStatus getSocketStatus();

    void reconnectionVerify();
    void reconnectionSucceeful();

    void appendResendMsgID( unsigned int uiMsgID ) { CAutoLock autoLock( m_SendNetMsgLock ); m_setResendMsgID.insert( uiMsgID ); }

    void setClearMsgIDHandler( int nHandler );

protected:
	CNetMsg* GetSendMessage();
	CNetSender( const char* sem_name );
	~CNetSender();

	void SendNetMessage( CNetMsg* pNetMsg );

    void appendWaitRecvMsg( CNetMsg* pNetMsg );
    CNetMsg* getWaitRecvMsg( unsigned int uiMsgID );
    CNetMsg* parseNetMsg( char* szRevcBuf, unsigned int nLength );

	sem_t* GetSendMsgSem() { return m_pSemSendMsg; }

protected:
	XL_LOCK m_SendNetMsgLock;
	sem_t* m_pSemSendMsg;
#if USE_NAMED_SEMAPHORE
#else
    sem_t m_sem;
#endif
	std::list<CNetMsg*> m_listSendMsg;
    std::set<unsigned int> m_setResendMsgID;
    std::list<CNetMsg*> m_listWaitRecvMsg;
    int m_nClearMsgIDHandler;

    unsigned short GetNextSequenceID( unsigned short msgID );
    std::map<unsigned short,unsigned short> m_mapSequenceID;

    // 在重连校验过程中，需要与服务器通信的消息 ID
    // 只有处于重连校验的时候才起作用
    std::set<unsigned int> m_setReconnectVerifyMsgID;

	CNetWorkThread* m_pNetWorkThread;
};

class CNetReceiver
{
public:
	~CNetReceiver();
    static CNetReceiver* SharedNetReceiver();

    // 设置错误消息处理函数
	void SetMsgErrorDefaultFuncPtr( int nLuaHandle );
	void RegisterMsgErrorFuncPtr( int nMsgCode, int nLuaHandle );

	void RegisterMsgProcessFuncPtr( unsigned short nMsgID, int nLuaHandler );

    // 设置lua网络消息回调函数	
	void ProcessMsg();
	void AppendMsg( CNetMsg* pNetMsg );
	void SendErrorMsgToSelf( unsigned int uiMsgCode );
	void SendMsgToSelf( unsigned int msgID, google::protobuf::MessageLite* pMsg  );
	void SendMsgToSelf( unsigned int msgID, const char* pszMsgData = NULL, int nLength = 0 );

    void Reset();

public:
    bool getIsSendKickOutFlag() const { return m_bIsSendKickOutFlag; }
    void setIsSendKickOutFlag( bool bFlag ) { m_bIsSendKickOutFlag = bFlag; }

protected:
	CNetReceiver();
	void NetMsgCallback( CNetMsg* pNetMsg );

	XL_LOCK m_RecvNetMsgLock;
	std::queue<CNetMsg*> m_quRecvMsg;

	//////////////////////////////////////////////////////////////////////////
    int m_nMsgErrorDefaultHandler;
	std::map<int,int> m_mapMsgErrorFuncPtr;
    std::map<unsigned short,int> m_mapNetMsgFunc;

    bool m_bIsSendKickOutFlag;
};
