#ifndef __SDK_CALLBACK_H__
#define __SDK_CALLBACK_H__

#include<queue>
#include "Common/TLCommon.h"

// 注意注意，请不要在中间插入，影响原来的值。
enum CbType {
    CB_LOGIN_SUCCESS = 0,
    CB_LOGIN_FAIL,

    CB_LOGOUT_SUCCESS,
    CB_LOGOUT_FAIL,

    CB_PAY_SUCCESS,
    CB_PAY_FAIL,

    CB_EXIT_CUSTOM,
    CB_DONT_SUPPORT_LOGIN,

    CB_UNLOCK_LOGIN,
    CB_ITUNES_IAP_VALIDATION,
    CB_REACHABILITY_CHANGED,

    CB_SDK_INIT_END,

    CB_MAX,
};

class PlatformCallbackMsg {
public:
    CbType cbtype;
    std::string arg;
};

class PlatformCallback {
public:
    PlatformCallback();
    ~PlatformCallback();

    int callbacks[CB_MAX];
    XL_LOCK lock;
    std::queue<PlatformCallbackMsg*> msg_queue;
};

void init_platform_callback(PlatformCallback* pc);
void register_platform_callback(CbType t, int fn);
void platform_callback(CbType t, const char* args);
void process_sdk_callback();
void free_global_sdk_callback();

#endif
