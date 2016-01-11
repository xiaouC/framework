#pragma once
#include "cocoa/CCObject.h"

USING_NS_CC;

namespace google
{
    namespace protobuf
    {
        class MessageLite;
    };
};

class CNetMsg : public CCObject
{
	friend class CNetSender;
	friend class CNetReceiver;
	friend class CNetWorkThread;
public:
	CNetMsg( unsigned int uiMsgCode );
	virtual ~CNetMsg();

    bool ParseContent(::google::protobuf::MessageLite* pMsg);

protected:
	CNetMsg();
	CNetMsg( char* szRevcBuf, unsigned short int nLength );

public:
	unsigned int GetMsgID() const { return m_uiMsgID; }

	unsigned int GetMsgCode() const { return m_uiCode; }

	unsigned int GetContentLength();
	char* GetContentData();
    char* GetContentStr();

protected:
	unsigned int m_uiMsgLength;
	unsigned int m_uiMsgID;
	unsigned int m_uiCode;

    int m_nCallBackHandler;

	char* m_szMsgData;
};
