#include "AppDelegate.h"
#include "CCEGLView.h"
#include "particle/ParticleSystemManager.h"
#include "Common/TLCommon.h"
#include "platform/PlatformUtils.h"

USING_NS_CC;

#define USE_GAME_NAME "LuLeLu"

float g_fFrameWidth = 640;
float g_fFrameHeight = 1136;

#ifdef WIN32
#include "main.h"
#include <dbghelp.h>
#include <pthread.h>

extern "C" {
#include <lua.h>
#include "lualib.h"
#include "lauxlib.h"
#include "ldo.h"
};
#include <CCLuaEngine.h>

#pragma comment( lib, "dbghelp.lib" )

float g_fWinScale = 0.7f;

extern std::string strPlatformPostfix;

LONG WINAPI DumpWrite( struct _EXCEPTION_POINTERS *ExceptionInfo )
{
	int nErrorCode = 0;
	HANDLE hFile = CreateFileA( "dumpfile.dmp", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );
	if( hFile != INVALID_HANDLE_VALUE )
	{
		MINIDUMP_EXCEPTION_INFORMATION einfo; 
		einfo.ThreadId = ::GetCurrentThreadId(); 
		einfo.ExceptionPointers = ExceptionInfo; 
		einfo.ClientPointers = FALSE; 

		MiniDumpWriteDump( GetCurrentProcess(),
			GetCurrentProcessId(),
			hFile,
			MiniDumpNormal,
			&einfo,
			NULL,
			NULL );

		nErrorCode = GetLastError();
	}

	CloseHandle( hFile );

	return 0;
}

int run()
{
	int rtn = 0;
	__try {
		rtn = CCApplication::sharedApplication()->run();
	}
	__except (DumpWrite(GetExceptionInformation()), EXCEPTION_CONTINUE_SEARCH) {
		// never get there
	}
	return rtn;
}

extern "C"{

	int __declspec(dllexport) luaopen_LolDLL(lua_State* L)
	{
		// create the application instance
		AppDelegate app(L);
		CCEGLView* eglView = CCEGLView::sharedOpenGLView();
		eglView->setViewName(USE_GAME_NAME);
		eglView->setFrameSize( g_fFrameWidth, g_fFrameHeight );
		// The resolution of ipad3 is very large. In general, PC's resolution is smaller than it.
		// So we need to invoke 'setFrameZoomFactor'(only valid on desktop(win32, mac, linux)) to make the window smaller.
		//    eglView->setFrameZoomFactor(0.4f);*/
		run();

		return 1;
	}

};

void setAppDelegateArg(AppDelegate* app, LPTSTR lpCmdLine)
{
	if(lpCmdLine && *lpCmdLine)
	{
		int len = wcslen(lpCmdLine);
		char* cmd = (char*)malloc(len+1);
		for(int i=0; i<len; ++i)
		{
			cmd[i] = lpCmdLine[i];
		}
		cmd[len] = 0;

		const char* sep = " ";
		char* t = strtok(cmd, sep);
		while(t)
		{
			if( t[0] == '-' && t[1] == 'e' )                      // 执行一个 lua 脚本
			{
                std::string strLuaFile = &t[2];
                CCLuaEngine::defaultEngine()->executeScriptFile( getScriptFullPath( strLuaFile ).c_str() );
			}
			else if(t[0] == '-' && t[1] == 'c')
			{
				app->m_sEntryCommand = &t[2];
			}
			else if(t[0] == '-' && t[1] == 'p')
			{
				ParticleSystemManager::sharedParticleSystemManager()->splitParticls();
				exit(0);
			}
			else if(t[0] == '-' && t[1]== 's')
			{
				sscanf_s(&t[2], "%f", &g_fWinScale);
			}
            else if( t[0] == '-' && t[1] == 'w' )                       // 平台后缀
            {
				sscanf_s(&t[2], "%f", &g_fFrameWidth);
            }
			else if( t[0] == '-' && t[1] == 'h' )                       // 平台后缀
            {
				sscanf_s(&t[2], "%f", &g_fFrameHeight);
            }
			else if( t[0] == '-' && t[1] == 'f' )                       // 平台后缀
            {
				strPlatformPostfix = &t[2];
            }
			else if(t[0] == '-' && t[1] == 'd')
			{
				set_lua_prefix(&t[2]);
			}
			else if( t[0] == '-' && t[1] == 'v' )                       // 资源版本字符???
            {
				setResourceVersion( &t[2] );
            }

			t = strtok(NULL, sep);
		}

		free(cmd);
	}
}

void CustomCall2(lua_State *L, Pfunc f, void *ud)
{
	__try {
		(*f)(L, ud);
	}
	__except (DumpWrite(GetExceptionInformation()), EXCEPTION_CONTINUE_SEARCH) {
		// never get there
	}
}

void CustomThrow2(void* msg)
{
	throw 0;
}

//void (*LPFN_ACCELEROMETER_KEYHOOK)( UINT message,WPARAM wParam, LPARAM lParam );
// 添加加载脚本函数
void KeyboardHook(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_KEYDOWN)
	{
		if (wParam == VK_F4) {
			// 刷新
			CCLuaEngine::defaultEngine()->executeScriptFile("refresh.lua");
		}
	}
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
	//luaD_setCustomCall(CustomCall2);
	//luaD_setCustomThrow(CustomThrow2);

    UNREFERENCED_PARAMETER(hPrevInstance);
	LPTOP_LEVEL_EXCEPTION_FILTER kOriginalFilter = SetUnhandledExceptionFilter( DumpWrite );

	// create the application instance
	lua_State* m_state = lua_open();
	luaL_openlibs(m_state);
    AppDelegate app(m_state);
	setAppDelegateArg(&app, lpCmdLine);
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setViewName( USE_GAME_NAME );
    eglView->setFrameSize( g_fFrameWidth, g_fFrameHeight );
    // The resolution of ipad3 is very large. In general, PC's resolution is smaller than it.
    // So we need to invoke 'setFrameZoomFactor'(only valid on desktop(win32, mac, linux)) to make the window smaller.
//    */
    // eglView->setFrameZoomFactor(0.8f);
	eglView->setFrameZoomFactor(g_fWinScale);


	// CCDirector::sharedDirector()->getOpenGLView()->setAccelerometerKeyHook(CCSkyLayer::keyboardHook);
	eglView->setAccelerometerKeyHook (&KeyboardHook);

    CCApplication::sharedApplication()->run();

	SetUnhandledExceptionFilter( kOriginalFilter );

    return 0;
}

#else
int main( int argc, char** args )
{
    if( argc >= 2 )
    {
        printf( "args[1] : %s\n", args[1] );
        g_fFrameWidth = atof( args[1] );
    }
    if( argc >= 3 )
    {
        printf( "args[2] : %s\n", args[2] );
        g_fFrameHeight = atof( args[2] );
    }

    // create the application instance
	AppDelegate app;
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setViewName( USE_GAME_NAME );
    eglView->setFrameSize( g_fFrameWidth, g_fFrameHeight );
	return CCApplication::sharedApplication()->run();
}
#endif
