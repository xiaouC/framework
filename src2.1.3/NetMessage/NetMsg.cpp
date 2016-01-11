#include <string.h>

#ifndef WIN32
#include <arpa/inet.h>
#endif

#include <google/protobuf/message_lite.h>
#include "../NetMessage/NetMsg.h"
#include "../NetMessage/NetMsgProcess.h"
#include "CCLuaEngine.h"

CNetMsg::CNetMsg( unsigned int uiMsgCode )
: m_uiMsgID(0)
, m_uiCode(uiMsgCode)
, m_nCallBackHandler(0)
, m_szMsgData(NULL)
{
}

CNetMsg::CNetMsg()
: m_uiMsgID(0)
, m_uiCode(0)
, m_nCallBackHandler(0)
, m_szMsgData(NULL)
{
}

unsigned int CNetMsg::GetContentLength()
{
	return m_uiMsgLength - 12;
}

char* CNetMsg::GetContentData()
{
    if (m_szMsgData)
        return m_szMsgData + 12;
    else
        return NULL;
}

char* CNetMsg::GetContentStr()
{
    if (m_szMsgData == NULL)
        return NULL;
    else
        return m_szMsgData + 12;
}

bool CNetMsg::ParseContent(::google::protobuf::MessageLite* pMsg)
{
    return pMsg->ParseFromArray(GetContentData(), GetContentLength());
}

CNetMsg::~CNetMsg()
{
    if (m_szMsgData!=NULL)
        delete[] m_szMsgData;

    if( m_nCallBackHandler > 0 )
    {
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nCallBackHandler );
        m_nCallBackHandler = 0;
    }
}
