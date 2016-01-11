#import "SDKLoginUtilsForIOS.h"
#import <Foundation/NSString.h>
#include "sdk.h"

#include "OPGameSDK.h"
#include "OPParam.h"

#import "SBJson.h"
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
        SBJsonParser * parser = [[SBJsonParser alloc] init];
        NSString *_payload = [NSString stringWithUTF8String:payload];
        NSMutableDictionary *data = [parser objectWithString:_payload];
        SDKTYPE type = ourpalmpay::OPGameSDK::GetInstance().curSdkType;
        rsplatformusername = new cocos2d::CCString([[data objectForKey:@"userName"] UTF8String]);
        rsplatformuid = new cocos2d::CCString([[data objectForKey:@"id"] UTF8String]);

        if (type == kRegister) {
            NSLog(@"kRegister: %@, %@", [data objectForKey:@"tokenId"], [data objectForKey:@"userName"]);
            CCLuaEngine::defaultEngine()->getLuaStack()->pushString([[data objectForKey:@"tokenId"] UTF8String]);
            CCLuaEngine::defaultEngine()->getLuaStack()->pushString([[data objectForKey:@"userName"] UTF8String]);
            CCLuaEngine::defaultEngine()->getLuaStack()->pushString("");
            CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler(platformloginHandler, 3);
        } else if (type == kNormalLogin) {
            NSLog(@"kNormalLogin: %@, %@", [data objectForKey:@"tokenId"], [data objectForKey:@"userName"]);
            CCLuaEngine::defaultEngine()->getLuaStack()->pushString([[data objectForKey:@"tokenId"] UTF8String]);
            CCLuaEngine::defaultEngine()->getLuaStack()->pushString([[data objectForKey:@"userName"] UTF8String]);
            CCLuaEngine::defaultEngine()->getLuaStack()->pushString("");
            CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler(platformloginHandler, 3);
        }
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
    NSString* orders = [NSString stringWithUTF8String:orderID];
    [SDKLoginUtilsForIOS itoolsOpenPayInterface:orders : float(amount)];
}

#ifdef PALMSDK
#ifndef OURPALMLOGIN
void loginCallBack(bool result,const char* jsonStr)
{
    if (jsonStr != NULL) {
        cout<<jsonStr<<endl;
        SBJsonParser * parser = [[SBJsonParser alloc] init];
        NSString *str2 = [NSString stringWithUTF8String:jsonStr];
        NSMutableDictionary * jsonDic = [parser objectWithString:str2];
        NSString* username = [jsonDic objectForKey:@"userName"];
        rsplatformusername = new cocos2d::CCString([username UTF8String]);
        NSString* uid = [jsonDic objectForKey:@"id"];
        rsplatformuid = new cocos2d::CCString([uid UTF8String]);
    }
    
    if (result) {
        // 登陆成功
        cout<<"登录成功"<<endl;
        // data 是json数据，包含uid和userName
        CCLuaEngine::defaultEngine()->getLuaStack()->executeGlobalFunction( "openLogin" );
        NSLog(@"success");
    } else {
        // 登陆失败
        cout<<"初始化失败"<<endl;
        NSLog(@"failed");
        OPGameSDK::GetInstance().RegisterLogin();
    }
}
#else
void loginCallBack(bool result,const char* jsonStr)
{
    cout<<"*********loginCallBack********"<<endl;
    SDKTYPE type = ourpalmpay::OPGameSDK::GetInstance().curSdkType;
    if (type == kRegister) {
        cout<<"注册账号"<<endl;
    }else if (type == kNormalLogin) {
        cout<<"常规登陆"<<endl;
    }else if (type == kQuickLogin){
        cout<<"快速登陆"<<endl;
    }
}
#endif



// 登出回调
void logoutCallBack(bool result, const char* jsonStr)
{
    cout<<"**********logoutCallBack**********"<<endl;
}

#endif

void Updateipa(char* url)
{
    
}

@implementation SDKLoginUtilsForIOS


+ (void)start {

};

+ (void)end {
//    CCLuaEngine::defaultEngine()->getLuaStack()->executeGlobalFunction( "resetLogin" );
}

+ (void) enterPlatform {
}

+ (void) unregPayNotification
{
//    [[NSNotificationCenter defaultCenter] removeObserver:self name:kPaymentTransactionStatePurchasedNotification object:nil];
//    [[NSNotificationCenter defaultCenter] removeObserver:self name:kPaymentTransactionStatePurchasingNotification object:nil];
#ifdef GF_APPSTORE
    [[NSNotificationCenter defaultCenter] removeObserver:self name:kPaymentTransactionStateFailedNotification object:nil];
#endif
}

+ (void) regPayNotification
{
//    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(paymentDidFinished:) name:kPaymentTransactionStatePurchasedNotification object:nil];
//    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(paymentDidPaying:) name:kPaymentTransactionStatePurchasingNotification object:nil];
#ifdef GF_APPSTORE
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(paymentDidFail:) name:kPaymentTransactionStateFailedNotification object:nil];
#endif
}

+(void)paymentDidPaying:(NSNotification*) notification
{
//    CCLuaEngine::defaultEngine()->getLuaStack()->executeGlobalFunction( "paying" );
//    [SDKLoginUtilsForIOS unregPayNotification];
}

+(void)paymentDidFail:(NSNotification*) notification
{
#ifdef GF_APPSTORE
    NSLog(@"notification error: %@,",[notification.object error]);
    if ( [[notification.object error] code] != SKErrorPaymentCancelled )
    {
        NSLog(@"购买失败");
        CCLuaEngine::defaultEngine()->getLuaStack()->executeGlobalFunction( "payfailed" );
    }
    else
    {
        NSLog(@"用户取消");
        CCLuaEngine::defaultEngine()->getLuaStack()->executeGlobalFunction( "paycanceled" );
    }
    [SDKLoginUtilsForIOS unregPayNotification];
#endif
}

+(void)loginItools:(NSString*) username : (NSString*) sessionid
{
#ifdef ITOOLS
//    rsplatformusername = new cocos2d::CCString([username UTF8String]);
    cocos2d::CCString * loginname = new cocos2d::CCString([username UTF8String]);
    cocos2d::CCString * loginsessionid = new cocos2d::CCString([sessionid UTF8String]);
    CCLuaEngine::defaultEngine()->getLuaStack()->pushString( loginsessionid->m_sString.c_str() );
    CCLuaEngine::defaultEngine()->getLuaStack()->pushString( loginname->m_sString.c_str() );
    CCLuaEngine::defaultEngine()->getLuaStack()->pushString( "" );
    CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( platformloginHandler,  3 );
    loginname->autorelease();
    loginsessionid->autorelease();
//    CCLuaEngine::defaultEngine()->getLuaStack()->executeGlobalFunction( "openLogin" );
#endif
}

+(void)itoolsOpenPayInterface:(NSString*) payserialNo : (float)money
{
#ifdef ITOOLS
//    NSString* username = nil;
//    if ( platformusername )
//    {
//         username = [NSString stringWithUTF8String:rsplatformusername->m_sString.c_str()];
//    }
    [HXAppPlatformKitPro setPayViewAmount: float(money) orderIdCom:payserialNo];
#endif
}

@end
