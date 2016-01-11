//
//  SDKLoginUtilsForIOS+ASSDK.m
//  lszb
//
//  Created by ratazzi on 12/3/14.
//
//

#import "SDKLoginUtilsForIOS+ASSDK.h"

int login_delegate = -1;
int logout_delegate = -1;

@implementation SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_ASSDK)

#pragma mark YunyueSDKIntegrateDelegate

+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions rootViewController:(UIViewController *)rootViewController {
    [[AsInfoKit sharedInstance] setAppId:[[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_ID"] intValue]];
    [[AsInfoKit sharedInstance] setAppKey:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_KEY"]];
    
    [[AsInfoKit sharedInstance] setIsHiddenCloseButtonOnAsLoginView:YES];
    [[AsInfoKit sharedInstance] setLogData:NO];
    [[AsInfoKit sharedInstance] setCloseRecharge:NO];
//    [[AsInfoKit sharedInstance] setCloseRechargeAlertMessage:@"充值功能暂时不开放"];
    [[AsInfoKit sharedInstance] setLongComet:YES];
    
    [[AsPlatformSDK sharedInstance] setDelegate:[SDKLoginUtilsForIOS class]];
    
    [[AsInfoKit sharedInstance] updateSDKOperatingEnvironment:YES andOrientationOfGame:UIInterfaceOrientationMaskPortrait];
    [[AsPlatformSDK sharedInstance] checkGameUpdate];
    
}

+ (void) login: (NSDictionary *)payload {
    [[AsPlatformSDK sharedInstance] showLogin];
}

+ (void) logout: (NSDictionary *)payload {
    [[AsPlatformSDK sharedInstance] asLogout];
}

+ (void) purchase: (NSDictionary *)payload {
    NSLog(@">>> purchase: %@\n", payload);
    [[AsPlatformSDK sharedInstance] exchangeGoods:[[payload objectForKey:@"amount"] intValue]
                                           BillNo:[payload objectForKey:@"transaction_id"]
                                        BillTitle:[payload objectForKey:@"product_name"]
                                           RoleId:[[payload objectForKey:@"entityID"] stringValue]
                                           ZoneId:[[payload objectForKey:@"server_id"] intValue]];
}

+ (void) platform: (NSDictionary *)payload {
    [[AsPlatformSDK sharedInstance] showCenter];
}

+ (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    if ([sourceApplication isEqualToString:@"com.alipay.iphoneclient"])
    {
        [[AsInfoKit sharedInstance] alixPayResult:url];
    }
    else if ([sourceApplication isEqualToString:@"com.alipay.safepayclient"])
    {
        [[AsInfoKit sharedInstance] alixPayResult:url];
    }
    else if ([sourceApplication isEqualToString:@"com.tencent.xin"])
    {
        [[AsInfoKit sharedInstance] weChatPayResult:url];
    }
    return YES;
}

#pragma mark AsPlatformSDKDelegate

+ (void)asAlixPayResultCallBack:(int)statusCode
{
    //    * 9000     订单支付成功
    //    * 8000     正在处理
    //    * 4000     订单支付失败
    //    * 6001     用户中途取消
    //    * 6002     网络连接出错
    
    switch (statusCode) {
        case 9000:
            NSLog(@"支付宝的回调 - 订单支付成功 : %d", statusCode);
            break;
        case 8000:
            NSLog(@"支付宝的回调 - 正在处理 : %d", statusCode);
            break;
        case 4000:
            NSLog(@"支付宝的回调 - 订单支付失败 : %d", statusCode);
            break;
        case 6001:
            NSLog(@"支付宝的回调 - 用户中途取消 : %d", statusCode);
            break;
        case 6002:
            NSLog(@"支付宝的回调 - 网络连接出错 : %d", statusCode);
            break;
        default:
            break;
    }
}

//-SDK 1.5.2 - 新增的银联支付的回调
+ (void)asUPPayPluginResultCallBack:(NSString *)result
{
    //    * success  支付成功
    //    * fail     支付失败
    //    * cancel   用户取消支付
    if ([result isEqualToString:@"success"]) {
        NSLog(@"银联支付的回调 - 支付成功 : %@", result);
    }
    if ([result isEqualToString:@"fail"]) {
        NSLog(@"银联支付的回调 - 支付失败 : %@", result);
    }
    if ([result isEqualToString:@"cancel"]){
        NSLog(@"银联支付的回调 - 用户取消支付 : %@", result);
    }
    
}

//-SDK 1.4.1 - 新增的关闭用户中心回调
+ (void)asClosedCenterViewCallBack
{
    // 点击按钮关闭用户中心的回调
    NSLog(@"点击按钮关闭用户中心的回调");
    
}

+ (void)asPayResultCallBack:(AsPayResultCode)paramPayResultCode
{
    /*
     * 特别提醒:
     * 该回调只会在账户的爱思币余额 >= 道具面额 时，才会执行；
     * 爱思币 < 道具面额 的情形下，该回调不会执行。
     */
    NSLog(@"支付结果的回调");
}

+ (void)asVerifyingUpdatePassCallBack
{
    NSLog(@"检测更新的回调");
    
//    [[AsPlatformSDK sharedInstance] showLogin];
}

+ (void)asLoginCallBack:(NSString *)paramToken
{
    [[AsPlatformSDK sharedInstance] currentUserName];
    [[AsPlatformSDK sharedInstance] currentUserId];

    NSLog(@"登陆的回调 - %@", paramToken);

    NSDictionary *payload = @{@"sessionId":  paramToken, @"userId": [[AsPlatformSDK sharedInstance] currentUserName]};
    NSData *data = [NSJSONSerialization dataWithJSONObject:payload options:NSJSONWritingPrettyPrinted error:nil];
    NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];

    platform_callback(CB_LOGIN_SUCCESS, [json UTF8String]);
}

+ (void)asLogOffCallBack
{
    NSLog(@"注销的回掉");
    platform_callback(CB_LOGOUT_SUCCESS, "");
}

+ (void)asClosePageViewCallBack:(AsPageCode)paramPageCode
{
    switch (paramPageCode) {
        case AsLoginViewPageCode:
            NSLog(@"关闭页面的回调 - 登录页面关闭 - AsLoginViewPageCode : %d", paramPageCode);
            break;
        case AsRegisterViewPageCode:
            NSLog(@"关闭页面的回调 - 注册页面关闭 - AsRegisterViewPageCode : %d", paramPageCode);
            break;
        default:
            break;
    }
}


+ (void)asCloseWebViewCallBack:(AsWebViewCode)paramWebViewCode
{
    switch (paramWebViewCode) {
        case AsWebViewCodeRecharge:
            NSLog(@"关闭网页的回调 - AsWebViewCodeRecharge : %d", paramWebViewCode);
            break;
        case AsWebViewCodeRechargeAndExchange:
            NSLog(@"关闭网页的回调 - AsWebViewCodeRechargeAndExchange : %d", paramWebViewCode);
        default:
            break;
    }
}

@end
