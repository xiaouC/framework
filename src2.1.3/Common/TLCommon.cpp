#include "TLCommon.h"
#include <string>
#include <algorithm>
#include <CCCommon.h>
#include <CCFileUtils.h>
#include "../MC/AssetsManager.h"
#include "../Common/TLModel.h"

#ifndef WIN32
#include <unistd.h>
#include <sys/resource.h>
#endif

USING_NS_CC;

static std::string _luaPath;

extern "C"
{
#include "lualib.h"
#include "lauxlib.h"

	void set_lua_prefix(const char* path)
	{
		AssetsManager::sharedAssetsManager()->setLuaPath(path);
		_luaPath = path ? path : "";
	}

	int lua_loader( lua_State* L )
	{
		std::string filename( luaL_checkstring( L, 1 ) );
		if( filename[0] != '/' )
			std::replace( filename.begin(), filename.end(), '.', '/' );
		filename.append( ".lua" );

		unsigned long size;
		char* pFileContent = NULL;
		if(!_luaPath.empty())
		{
			std::string filename2 = _luaPath + filename;
			if( filename2[0] != '/' )
				pFileContent = (char*)AssetsManager::sharedAssetsManager()->getFileContent( filename2.c_str(), "r", &size );
			else
				pFileContent = (char*)CCFileUtils::sharedFileUtils()->getFileData( filename2.c_str(), "r", &size );	
			if(pFileContent == NULL)
			{
				if( filename[0] != '/' )
					pFileContent = (char*)AssetsManager::sharedAssetsManager()->getFileContent( filename.c_str(), "r", &size );
				else
					pFileContent = (char*)CCFileUtils::sharedFileUtils()->getFileData( filename.c_str(), "r", &size );	
			}
		}
		else
		{
			if( filename[0] != '/' )
				pFileContent = (char*)AssetsManager::sharedAssetsManager()->getFileContent( filename.c_str(), "r", &size );
			else
				pFileContent = (char*)CCFileUtils::sharedFileUtils()->getFileData( filename.c_str(), "r", &size );
		}

		if( pFileContent != NULL )
		{
            if( CCLuaEngine::defaultEngine()->getLuaStack()->luaLoadBuffer(L, pFileContent, size, filename.c_str() ) != 0 )
			{
				luaL_error( L, "error loading module %s from file %s :\n\t%s", lua_tostring( L, 1 ), filename.c_str(), lua_tostring( L, -1 ) );
			}
			delete[] pFileContent;
		}
		else
		{
			//CCLog( "can not get file data of %s", filename.c_str() );
		}

		return 1;
	}
};

//void test()
//{
//	CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
//	cocos2d::extension::CCBReader* ccbReader = new cocos2d::extension::CCBReader( ccNodeLoaderLibrary );
//	ccbReader->autorelease();
//
//	CCNode* node = ccbReader->readNodeGraphFromFile( "*.ccbi", this );
//	node->setPosition( 0, 0 );
//	this->addChild( node );
//
//	// 根据动作名播放动作
//	ccbReader->getAnimationManager()->runAnimationsForSequenceNamed( "jump" );
//
//	// 通过 sequence id 播放动作
//	ccbReader->getAnimationManager()->runAnimationsForSequenceIdTweenDuration( 0, 0.3f );
//
//	// 获取所有的动作序列
//	CCArray* allSeq = ccbReader->getAnimationManager()->getSequences();
//	for( int i=0; i < allSeq->count(); ++i )
//	{
//		CCBSequence* seq = (CCBSequence*)allSeq->objectAtIndex( i );
//
//		// 获取每个序列的动作周期，名字，ID
//		float duration = seq->getDuration();
//		const char* name = seq->getName();
//		int id = seq->getSequenceId();
//	}
//}
/*
std::string GetActionMCName( unsigned int uiResID, int nActionType )
{
	char szMCName[256];
	memset( szMCName, 0, 256 );

	switch( nActionType )
	{
	case XL_RESOURCE_TYPE_ACTION_STAND:
		XLSprintf( szMCName, 256, "%d/stand", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_STANDBY:
		XLSprintf( szMCName, 256, "%d/standby", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_WALK:
		XLSprintf( szMCName, 256, "%d/walk", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_ATTACK:
		XLSprintf( szMCName, 256, "%d/attack1", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_ATTACK2:
		XLSprintf( szMCName, 256, "%d/attack2", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_ATTACK3:
		XLSprintf( szMCName, 256, "%d/attack3", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_ATTACK4:
		XLSprintf( szMCName, 256, "%d/attack4", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_ATTACK5:
		XLSprintf( szMCName, 256, "%d/attack5", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_HURT0:
		XLSprintf( szMCName, 256, "%d/hurt1", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_HURT1:
		XLSprintf( szMCName, 256, "%d/hurt1", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_HURT2:
		XLSprintf( szMCName, 256, "%d/hurt2", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_HURT3:
		XLSprintf( szMCName, 256, "%d/hurt3", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_DEFENSE:
		XLSprintf( szMCName, 256, "%d/defense", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_DODGE:
		XLSprintf( szMCName, 256, "%d/dodge", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_PREATTACK:
		XLSprintf( szMCName, 256, "%d/pose", uiResID );
		break;
	case XL_RESOURCE_TYPE_ICON:
		XLSprintf( szMCName, 256, "icon/%d.png", uiResID );
		break;
	case XL_RESOURCE_TYPE_BUST:
		XLSprintf( szMCName, 256, "bust/%d.png", uiResID );
		break;
	case XL_RESOURCE_TYPE_HEAD:
		XLSprintf( szMCName, 256, "head/%d.png", uiResID );
		break;
	case XL_RESOURCE_TYPE_ACTION_DEAD:
		XLSprintf( szMCName, 256, "%d/dead", uiResID );
		break;
	}

	return szMCName;
}
*/
//////////////////////////////////////////////////////////////////////////
void LockInit( XL_LOCK& lock )
{
#ifndef WIN32
	pthread_mutexattr_t a;
	pthread_mutexattr_init(&a);
	pthread_mutexattr_settype(&a,PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&lock, &a);
	pthread_mutexattr_destroy(&a);
#else
	InitializeCriticalSection( &lock );
#endif
}

void LockRelease( XL_LOCK& lock )
{
#ifndef WIN32
	pthread_mutex_destroy( &lock );
#else
	DeleteCriticalSection( &lock );
#endif
}

void LockEnter( XL_LOCK& lock )
{
#ifndef WIN32
	pthread_mutex_lock( &lock );
#else
	EnterCriticalSection( &lock );
#endif
}

void LockLeave( XL_LOCK& lock )
{
#ifndef WIN32
	pthread_mutex_unlock( &lock );
#else
	LeaveCriticalSection( &lock ); 
#endif
}

int SocketStartUp()
{
#ifdef WIN32
	WSADATA wsaData;
	WORD version = MAKEWORD( 2, 0 );
	return WSAStartup( version, &wsaData ); // win sock start up
#else
	return 0;
#endif
}

int SocketCleanUp()
{
#ifdef WIN32
	return WSACleanup();
#else
	return 0;
#endif
}

void XL_Sleep( unsigned long dwSleepTime )
{
#ifdef WIN32
	Sleep( dwSleepTime );
#else
	sleep( dwSleepTime );
#endif
}

cocos2d::CCLuaEngine* getLuaEngine()
{
    return (cocos2d::CCLuaEngine*) cocos2d::CCScriptEngineManager::sharedManager()->getScriptEngine();
}

void dump_rusage()
{
#ifndef WIN32
    struct rusage usage;    
    getrusage(RUSAGE_SELF, &usage);
    cocos2d::CCLog("cocos2dx_android rss: %ld", usage.ru_maxrss);
#endif
}

void dump_texture()
{
    cocos2d::CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
}

std::string getScriptFullPath( const std::string& path )
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	return CCFileUtils::sharedFileUtils()->fullPathForFilename( path.c_str() );
#else
	if(!_luaPath.empty())
	{
		return CCFileUtils::sharedFileUtils()->fullPathForFilename( (_luaPath + path + ".lua").c_str() );
	}
	return CCFileUtils::sharedFileUtils()->fullPathForFilename( (path + ".lua").c_str() );
#endif
}

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
int StartLua(CCLuaEngine* pEngine, const std::string& file)
{
    std::string code("require \"");
    code.append(file);
    code.append("\"");
    return pEngine->getLuaStack()->executeString(code.c_str());
}
//#endif

float saturate( float val )
{
#ifdef WIN32
    return min( max( val, 0.0f ), 1.0f );
#else
    return std::min( std::max( val, 0.0f ), 1.0f );
#endif
}

float smoothstep( float edge0, float edge1, float x )
{
    x = x * x * ( 3 - 2 * x );

    x = edge0 + ( edge1 - edge0 ) * x;

    return x;
}

float g_fReconnectionInterval = 5.0f;
void setReconnectionInterval( float fInterval )
{
    g_fReconnectionInterval = fInterval;
}

float getReconnectionInterval()
{
    return g_fReconnectionInterval;
}

unsigned int packMsgID( unsigned short sRealMsgID, unsigned short sSquID )
{
    unsigned int uiMsgID = sSquID;
    uiMsgID <<= 16;
    uiMsgID |= sRealMsgID;

    return uiMsgID;
}

void unpackMsgID( unsigned int uiMsgID, unsigned short& sRealMsgID, unsigned short& sSquID )
{
    sRealMsgID = uiMsgID;
    sSquID = uiMsgID >> 16;
}

unsigned short getRealMsgID( unsigned int uiMsgID )
{
    unsigned short sRealMsgID, sSquID;
    unpackMsgID( uiMsgID, sRealMsgID, sSquID );

    return sRealMsgID;
}

std::string g_strProjectNickname;
void setProjectNickname( const char* szNickname )
{
    g_strProjectNickname = szNickname;
}

const char* getProjectNickname()
{
    return g_strProjectNickname.c_str();
}

void setNodeAlpha( CCNode* node, GLubyte o )
{
	NodeType nt = node->getNodeType();
	if( nt == ND_BITMAP || nt == ND_RECT || nt == ND_TTFRICHTEXT || nt == ND_MOVIECLIP)
    {

        ((CCNodeRGBA*)node)->setOpacity( o );

        return;
    }

    if( nt == ND_MODEL )
    {
        ((TLModel*)node)->setOpacity( o );

        return;
    }

    CCArray* children = node->getChildren();
    if( children != NULL )
    {
        for( unsigned i = 0; i < children->count(); ++i )
        {
            setNodeAlpha( (CCNode*)children->objectAtIndex(i), o );
        }
    }
}

GLubyte getNodeAlpha( CCNode* node )
{
	NodeType nt = node->getNodeType();
    if( nt == ND_BITMAP || nt == ND_RECT || nt == ND_TTFRICHTEXT || nt == ND_MOVIECLIP )
        return ((CCNodeRGBA*)node)->getOpacity();

    if( nt == ND_MODEL )
        return ((TLModel*)node)->getOpacity();

    CCArray* children = node->getChildren();
    if( children != NULL && children->count() > 0 )
        return getNodeAlpha( (CCNode*)children->objectAtIndex(0) );

    return 0;
}

float getNodeAlphaLua( CCNode* node )
{
    return (float)getNodeAlpha( node );
}

void setNodeColor( CCNode* node, const ccColor3B& o )
{
	NodeType nt = node->getNodeType();
    if( nt == ND_BITMAP || nt == ND_RECT || nt == ND_TTFRICHTEXT )
    {
        ((CCNodeRGBA*)node)->setColor( o );

        return;
    }

    if( nt == ND_MODEL )
    {
        ((TLModel*)node)->setColor( o );

        return;
    }

    CCArray* children = node->getChildren();
    if( children != NULL )
    {
        for( unsigned i = 0; i < children->count(); ++i )
        {
            setNodeColor( (CCNode*)children->objectAtIndex(i), o );
        }
    }
}

const ccColor3B& getNodeColor( CCNode* node )
{
	NodeType nt = node->getNodeType();
    if( nt == ND_BITMAP || nt == ND_RECT || nt == ND_TTFRICHTEXT )
        return ((CCNodeRGBA*)node)->getColor();

    if( nt == ND_MODEL )
        return ((TLModel*)node)->getColor();

    CCArray* children = node->getChildren();
    if( children != NULL && children->count() > 0 )
        return getNodeColor( (CCNode*)children->objectAtIndex(0) );

	static ccColor3B c = ccc3( 0, 0, 0 );
	return c;
}

void setNodeColorR( CCNode* node, GLubyte r )
{
	ccColor3B color = getNodeColor( node );
    color.r = r;
    setNodeColor( node, color );
}

void setNodeColorG( CCNode* node, GLubyte g )
{
	ccColor3B color = getNodeColor( node );
    color.g = g;
    setNodeColor( node, color );
}

void setNodeColorB( CCNode* node, GLubyte b )
{
	ccColor3B color = getNodeColor( node );
    color.b = b;
    setNodeColor( node, color );
}

void setNodeAlphaLua( CCNode* node, float o )
{
    setNodeAlpha( node, o );
}

void setNodeTLAlphaLua( CCNode* node, float o, bool bUpdate )
{
    NodeType nt = node->getNodeType();
    if( nt == ND_BITMAP )
    {
        ((CCSprite*)node)->setTLVertexAlpha( o, bUpdate );

        return;
    }

    CCArray* children = node->getChildren();
    if( children != NULL )
    {
        for( unsigned i = 0; i < children->count(); ++i )
        {
            setNodeTLAlphaLua( (CCNode*)children->objectAtIndex(i), o, bUpdate );
        }
    }
}

void setNodeBLAlphaLua( CCNode* node, float o, bool bUpdate )
{
    NodeType nt = node->getNodeType();
    if( nt == ND_BITMAP )
    {
        ((CCSprite*)node)->setBLVertexAlpha( o, bUpdate );

        return;
    }

    CCArray* children = node->getChildren();
    if( children != NULL )
    {
        for( unsigned i = 0; i < children->count(); ++i )
        {
            setNodeBLAlphaLua( (CCNode*)children->objectAtIndex(i), o, bUpdate );
        }
    }
}

void setNodeBRAlphaLua( CCNode* node, float o, bool bUpdate )
{
    NodeType nt = node->getNodeType();
    if( nt == ND_BITMAP )
    {
        ((CCSprite*)node)->setBRVertexAlpha( o, bUpdate );

        return;
    }

    CCArray* children = node->getChildren();
    if( children != NULL )
    {
        for( unsigned i = 0; i < children->count(); ++i )
        {
            setNodeBRAlphaLua( (CCNode*)children->objectAtIndex(i), o, bUpdate );
        }
    }
}

void setNodeTRAlphaLua( CCNode* node, float o, bool bUpdate )
{
    NodeType nt = node->getNodeType();
    if( nt == ND_BITMAP )
    {
        ((CCSprite*)node)->setTRVertexAlpha( o, bUpdate );

        return;
    }

    CCArray* children = node->getChildren();
    if( children != NULL )
    {
        for( unsigned i = 0; i < children->count(); ++i )
        {
            setNodeTRAlphaLua( (CCNode*)children->objectAtIndex(i), o, bUpdate );
        }
    }
}

void setNodeColorRLua( CCNode* node, float r )
{
    setNodeColorR( node, r );
}

void setNodeColorGLua( CCNode* node, float g )
{
    setNodeColorG( node, g );
}

void setNodeColorBLua( CCNode* node, float b )
{
    setNodeColorB( node, b );
}

void setNodeShaderProgram( CCNode* node, CCGLProgram* pShaderProgram )
{
    // CCSprite 和 TLLabelRichTex 需要设置 CCGLProgram
    if( node->getNodeType() == ND_BITMAP || node->getNodeType() == ND_TTFRICHTEXT )
        node->setShaderProgram( pShaderProgram );

    // 遍历字节点
    CCArray* children = node->getChildren();
    if( children != NULL )
    {
        for( unsigned i=0; i < children->count(); ++i )
            setNodeShaderProgram( (CCNode*)children->objectAtIndex( i ), pShaderProgram );
    }
}

bool g_bRenderNodeFlag = false;
bool getRenderNodeFlag()
{
    return g_bRenderNodeFlag;
}

void setRenderNodeFlag( bool bFlag )
{
    g_bRenderNodeFlag = bFlag;
}
