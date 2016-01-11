#include "AppDelegate.h"

#include <vector>
#include <string>

#include "TLRunningScene.h"
#include "AppMacros.h"
#include "script_support/CCScriptSupport.h"
#include "CCLuaEngine.h"
#include "./MC/AssetsManager.h"
#include "./Common/TLCommon.h"
#include "./Common/LuaApi.h"
#include "SimpleAudioEngine.h"
#include "platform/sdk.h"
#include "platform/PlatformUtils.h"
#include "UI/TLRenderNode.h"

#ifdef PLATFORM91
#include "OPGameSDK.h"
#endif

extern int tolua_api_open( lua_State* tolua_S );
extern int luaopen_protobuf_c( lua_State* tolua_S );
extern int tolua_utils_open( lua_State* tolua_S );
extern "C" {
	int luaopen_bit( lua_State* tolua_S );
	int luaopen_struct( lua_State* tolua_S );
	int luaopen_lfs( lua_State* tolua_S );
    int luaopen_cmsgpack( lua_State* tolua_S );
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    int luaopen_cjson( lua_State *tolua_S );
#endif
}

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate(lua_State* L)
:  m_sEntryFilename("launch.main")
{
	// 
#if( CC_TARGET_PLATFORM == CC_PLATFORM_LINUX )
    char* directory = getenv("CLIENT_DIRECTORY");
    if (directory == NULL)
        directory = "../win32_client/";
	CCFileUtils::sharedFileUtils()->addSearchPath(directory);
#else
	CCFileUtils::sharedFileUtils()->addSearchPath( "./" );
#endif
	
    AssetsManager::sharedAssetsManager()->Load();

	// 
	CCLuaEngine* pEngine = CCLuaEngine::createDefaultEngine( L );
	CCScriptEngineManager::sharedManager()->setScriptEngine( pEngine );
	pEngine->addLuaLoader( lua_loader );

    CCLuaEngine::defaultEngine()->getLuaStack()->setXXTEAKeyAndSign("+/yUt6mb9FCtnC2C+F", strlen("+/yUt6mb9FCtnC2C+F"), "YYLUA", strlen("YYLUA"));
    lua_State* lua_state = CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState();
	tolua_api_open( lua_state );
	luaopen_protobuf_c( lua_state );
	tolua_utils_open( lua_state );
	luaopen_struct( lua_state );
	luaopen_lfs( lua_state );
    luaopen_cmsgpack( lua_state );
	luaopen_bit( lua_state );
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    luaopen_cjson( lua_state );
#endif
}

AppDelegate::~AppDelegate() 
{
	finiLog();
}

bool AppDelegate::applicationDidFinishLaunching() {
	// 
	initLog();

    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);

    // Set the design resolution
	//pEGLView->setDesignResolutionSize( GAME_SCENE_WIDTH, GAME_SCENE_HEIGHT, kResolutionExactFit );	
	
    //// turn on display FPS
    //pDirector->setDisplayStats(true);

    //// set FPS. the default value is 1.0/60 if you don't call this
    //pDirector->setAnimationInterval(1.0 / 60);

	SocketStartUp();

    if (StartLua(CCLuaEngine::defaultEngine(), m_sEntryFilename) != 0) {
        CCLog( "error start lua %s", m_sEntryFilename.c_str() );
    }

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	TLRenderNode::pause();
    CCDirector::sharedDirector()->pause();  
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
//    CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    CCLuaEngine::defaultEngine()->getLuaStack()->executeGlobalFunction( "enterBackground" );
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->resume();
    CCDirector::sharedDirector()->startAnimation();
	TLRenderNode::resume();
#ifdef PLATFORM91
    ourpalmpay::OPGameSDK::GetInstance().ShowPausePage();
#endif

    // if you use SimpleAudioEngine, it must resume here
//    CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    CCLuaEngine::defaultEngine()->getLuaStack()->executeGlobalFunction( "enterForeground" );
}
