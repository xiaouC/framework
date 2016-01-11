#import "SDKLoginUtilsForIOS.h"
#import <Foundation/NSString.h>
#include "sdk.h"

#include "OPGameSDK.h"
#include "OPParam.h"

//#import "SBJson.h"
#include "CCString.h"
#include "CCLuaEngine.h"

USING_NS_CC;


poem::SDKType GetSdkType()
{
    int sdktype = [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SdkType"] intValue];
	return poem::SDKType(sdktype);
}

int platformloginHandler = 0;
int platformlogoutHandler = 0;
cocos2d::CCString *rsplatformusername = nil;
cocos2d::CCString *rsplatformuid = nil;


void setPlatformLogin( int nLoginHandler )
{
    if( platformloginHandler > 0 )
        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( platformloginHandler );
    platformloginHandler = nLoginHandler;
}

void setPlatformLogout( int nLogoutHandler )
{
    if( platformlogoutHandler > 0 )
        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( platformlogoutHandler );
    platformlogoutHandler = nLogoutHandler;
}

void RegisterLoginCallback(bool result, const char *payload) {
    if (result) {
//        SBJsonParser * parser = [[SBJsonParser alloc] init];
        NSString *_payload = [NSString stringWithUTF8String:payload];
        NSError *error;
        NSMutableDictionary *data = [NSJSONSerialization JSONObjectWithData:[_payload dataUsingEncoding:NSUTF8StringEncoding] options:NSJSONWritingPrettyPrinted error:&error];
        SDKTYPE type = ourpalmpay::OPGameSDK::GetInstance().curSdkType;
        rsplatformusername = new cocos2d::CCString([[data objectForKey:@"userName"] UTF8String]);
        rsplatformuid = new cocos2d::CCString([[data objectForKey:@"id"] UTF8String]);

//        if (type == kRegister) {
//            NSLog(@"kRegister: %@, %@", [data objectForKey:@"tokenId"], [data objectForKey:@"userName"]);
//            CCLuaEngine::defaultEngine()->getLuaStack()->pushString([[data objectForKey:@"tokenId"] UTF8String]);
//            CCLuaEngine::defaultEngine()->getLuaStack()->pushString([[data objectForKey:@"userName"] UTF8String]);
//            CCLuaEngine::defaultEngine()->getLuaStack()->pushString("");
//            CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler(platformloginHandler, 3);
//        } else if (type == kNormalLogin) {
//            NSLog(@"kNormalLogin: %@, %@", [data objectForKey:@"tokenId"], [data objectForKey:@"userName"]);
//            CCLuaEngine::defaultEngine()->getLuaStack()->pushString([[data objectForKey:@"tokenId"] UTF8String]);
//            CCLuaEngine::defaultEngine()->getLuaStack()->pushString([[data objectForKey:@"userName"] UTF8String]);
//            CCLuaEngine::defaultEngine()->getLuaStack()->pushString("");
//            CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler(platformloginHandler, 3);
//        }
    } else {
        NSLog(@"RegisterLoginCallback failed.");
    }
}

void OPGameSDKRegister(char *username, char * passwd) {
    NSLog(@">>> call OPGameSDKRegister: %s", username);
    ourpalmpay::OPGameSDK::GetInstance().RegisterLoginCallBack(RegisterLoginCallback);
    ourpalmpay::OPGameSDK::GetInstance().RegisterLogin("9", "", "", username, passwd, "", "", "");
}

void OPGameSDKLogin(char *username, char *passwd) {
    NSLog(@">>> call OPGameSDKLogin: %s", username);
    ourpalmpay::OPGameSDK::GetInstance().RegisterLoginCallBack(RegisterLoginCallback);
    ourpalmpay::OPGameSDK::GetInstance().RegisterLogin("0", "", "", username, passwd, "", "", "");
}


const char* platformusername()
{
    return rsplatformusername->m_sString.c_str();
}

const char* platformuid()
{
    return rsplatformuid->m_sString.c_str();
}

void setZCGameUserId(char *userId)
{
    
}

void payWithSDK(char *orderID, float amount, int serverID, int roleID, char *roleName, char *username)
{
}

void Updateipa(char* url) {
}

void loginCallBack(bool result,const char* jsonStr)
{
    NSLog(@"got login callback");
    if (result) {
        // 登陆成功
        cout<<"登录成功"<<endl;
        // data 是json数据，包含uid和userName
        NSError *error;
        NSString *_payload = [NSString stringWithUTF8String:jsonStr];
        NSMutableDictionary *data = [NSJSONSerialization JSONObjectWithData:[_payload dataUsingEncoding:NSUTF8StringEncoding] options:NSJSONWritingPrettyPrinted error:&error];
        NSLog(@"login payload: %@", data);
        CCLuaEngine::defaultEngine()->getLuaStack()->pushString([[data objectForKey:@"tokenId"] UTF8String]);
        CCLuaEngine::defaultEngine()->getLuaStack()->pushString([[data objectForKey:@"userName"] UTF8String]);
        CCLuaEngine::defaultEngine()->getLuaStack()->pushString("");
        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler(platformloginHandler, 3);
        NSLog(@"success");
    } else {
        // 登陆失败
        NSLog(@"login failed");
//        ourpalmpay::OPGameSDK::GetInstance().RegisterLogin();
    }
}

// 登出回调
void logoutCallBack(bool result, const char* jsonStr)
{
    NSLog(@"got logout callback");
    if (result) {
        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler(platformlogoutHandler, 0);
    } else {
        NSLog(@"logout failed");
    }
}

@implementation SDKLoginUtilsForIOS

+ (void)start {
    ourpalmpay::OPGameSDK::GetInstance().RegisterLoginCallBack(loginCallBack);
    ourpalmpay::OPGameSDK::GetInstance().RegisterLogoutCallBack(logoutCallBack);
    ourpalmpay::OPGameSDK::GetInstance().RegisterLogin();
};

+ (void)end {
    ourpalmpay::OPGameSDK::GetInstance().LogOut();
}

+ (void) enterPlatform {
    ourpalmpay::OPGameSDK::GetInstance().EnterPlatform();
}

@end