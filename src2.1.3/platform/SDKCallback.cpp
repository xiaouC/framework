#include "platform/SDKCallback.h"

static PlatformCallback* g_platform_callback = NULL;

// exposed to lua
void register_platform_callback(CbType t, int cb) {
    if (g_platform_callback == NULL) {
        g_platform_callback = new PlatformCallback();
    }
    if (g_platform_callback->callbacks[t]) {
        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler(g_platform_callback->callbacks[t]);
    }
    g_platform_callback->callbacks[t] = cb;
}

// called by java
void platform_callback(CbType t, const char* arg) {
    CCAssert(t < CB_MAX && t >=0, "out of index CbType");
    if (g_platform_callback == NULL) {
        return;
    }

	CAutoLock autoLock( g_platform_callback->lock );
    PlatformCallbackMsg* msg = new PlatformCallbackMsg();
    msg->cbtype = t;
    msg->arg = arg;

    g_platform_callback->msg_queue.push(msg);
}

// run in cocos2d-x render thread
void process_sdk_callback() {
    if ( g_platform_callback == NULL ) {
        return;
    }

	CAutoLock autoLock( g_platform_callback->lock );

    while ( !g_platform_callback->msg_queue.empty() ) {
        PlatformCallbackMsg* msg = g_platform_callback->msg_queue.front();
		g_platform_callback->msg_queue.pop();
        CCLuaEngine::defaultEngine()->getLuaStack()->pushString(msg->arg.c_str());
        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( g_platform_callback->callbacks[msg->cbtype], 1 );
        delete msg;
    }
}

PlatformCallback::PlatformCallback() {
    memset(callbacks, 0, sizeof(callbacks));
    LockInit(lock);
}

PlatformCallback::~PlatformCallback() {
    LockRelease(lock);
    for (int i=0; i<CB_MAX; i++) {
        if (callbacks[i]) {
            CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler(callbacks[i]);
        }
    }
}
