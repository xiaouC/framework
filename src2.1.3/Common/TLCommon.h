#pragma once
#include <string>
#include "pthread.h"
#include "CCLuaEngine.h"
#include <base_nodes/CCNode.h>

USING_NS_CC;

#ifdef WIN32
#include <winsock2.h>
#include <Windows.h>
typedef CRITICAL_SECTION XL_LOCK;
typedef uintptr_t XL_ThreadHandle;
#define XLSprintf sprintf_s 
#else
typedef pthread_mutex_t XL_LOCK;
typedef pthread_t XL_ThreadHandle;
#define XLSprintf snprintf
typedef int SOCKET;
#define INVALID_SOCKET -1
#endif

extern "C"
{
	#include "lua.h"

	void set_lua_prefix(const char* path);
	int lua_loader( lua_State* L );
};

//////////////////////////////////////////////////////////////////////////
void LockInit( XL_LOCK& lock );
void LockRelease( XL_LOCK& lock );
void LockEnter( XL_LOCK& lock );
void LockLeave( XL_LOCK& lock );

int SocketStartUp();
int SocketCleanUp();

class CAutoLock
{
public:
	CAutoLock( XL_LOCK& lock ) : m_LockRef(lock) { LockEnter( m_LockRef ); }
	~CAutoLock() { LockLeave( m_LockRef ); }

private:
	CAutoLock( const CAutoLock& );
	CAutoLock& operator = ( const CAutoLock& );

private:
	XL_LOCK& m_LockRef;
};

void XL_Sleep( unsigned long dwSleepTime );

namespace cocos2d {
    class CCLuaEngine;
}
cocos2d::CCLuaEngine* getLuaEngine();

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#define USE_NAMED_SEMAPHORE 1
#else
#define USE_NAMED_SEMAPHORE 0
#endif

#define RECV_MSG_BUFF_LENGTH (10*1024)
#define SEND_MSG_BUFF_LENGTH (10*1024)

enum NET_WORK_THREAD_CODE
{
    NWTC_SOCKET_RECEIVE_ERROR       = 11,           // socket 
    NWTC_SOCKET_CONNECT_ERROR       = 12,           // socket connect 操作失败
    NWTC_INVALID_SOCKET             = 13,           // 无效的 socket
    NWTC_SOCKET_CONNECT_SUCCESS     = 14,           // 成功
    NWTC_SOCKET_RECONNECT           = 17,           // 请求断线重连         这个不再使用了，重连的请求，直接由lua触发，c＋＋层不触发
    NWTC_SOCKET_DISCONNECT          = 18,           // 网络断开
    NWTC_SOCKET_SERVER_KICK_OUT     = 19,           // 服务器踢的
    NWTC_SOCKET_DISCONNECT_2        = 29,           // 有 MSG 发送成功但无法收到服务器返回，这个时候服务器和客户端的状态不一致，需要重新登陆
};

enum NetWordThreadStatus
{
    NWTS_CLOSED                 = 1,                // 已关闭
    NWTS_CONNECTING             = 2,                // 正在连接中,现在没有使用了
    NWTS_CONNECTED              = 3,                // 已连接
    NWTS_RECONNECT_REQUEST      = 4,                // 请求重连
    NWTS_RECONNECTING           = 5,                // 正在重连
};

#ifdef WIN32
	#define XL_RANDOM rand
#else
	#define XL_RANDOM random
#endif

void dump_rusage();
void dump_texture();

std::string getScriptFullPath( const std::string& path );
//#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
int StartLua( cocos2d::CCLuaEngine* pEngine, const std::string& file );
//#endif

float smoothstep( float edge0, float edge1, float x );

void setReconnectionInterval( float fInterval );
float getReconnectionInterval();

unsigned int packMsgID( unsigned short sRealMsgID, unsigned short sSquID );
void unpackMsgID( unsigned int uiMsgID, unsigned short& sRealMsgID, unsigned short& sSquID );
unsigned short getRealMsgID( unsigned int uiMsgID );

void setProjectNickname( const char* szNickname );
const char* getProjectNickname();

void setNodeAlpha( CCNode* node, GLubyte o );
void setNodeColor( CCNode* node, const ccColor3B& o );
void setNodeColorR( CCNode* node, GLubyte r );
void setNodeColorG( CCNode* node, GLubyte g );
void setNodeColorB( CCNode* node, GLubyte b );

float getNodeAlphaLua( CCNode* node );
void setNodeAlphaLua( CCNode* node, float o );
void setNodeTLAlphaLua( CCNode* node, float o, bool bUpdate = false );
void setNodeBLAlphaLua( CCNode* node, float o, bool bUpdate = false );
void setNodeBRAlphaLua( CCNode* node, float o, bool bUpdate = false );
void setNodeTRAlphaLua( CCNode* node, float o, bool bUpdate = false );
void setNodeColorRLua( CCNode* node, float r );
void setNodeColorGLua( CCNode* node, float g );
void setNodeColorBLua( CCNode* node, float b );

void setNodeShaderProgram( CCNode* node, CCGLProgram* pShaderProgram );

bool getRenderNodeFlag();
void setRenderNodeFlag( bool bFlag );
