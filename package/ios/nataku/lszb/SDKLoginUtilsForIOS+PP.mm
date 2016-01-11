#import "SDKLoginUtilsForIOS+PP.h"

@implementation SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_PP)

#pragma mark -
#pragma mark YunyueSDKIntegrateDelegate

// {{{ Optional

+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions rootViewController:(UIViewController *)rootViewController {
    NSLog(@">>> SDK_APP_ID: %d", [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_ID"] intValue]);

    PPAppPlatformKit *ppKit = [PPAppPlatformKit share];
    [ppKit setupWithDelegate:[SDKLoginUtilsForIOS class]
                       appId:[[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_ID"] intValue]
                      appKey:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_KEY"]];
//    ppKit.orientationMaskType = PPSDKInterfaceOrientationMaskTypePortrait;
    [ppKit startPPSDK];
}

+ (void)login: (NSDictionary *)payload {
    [[PPAppPlatformKit share] login];
}

+ (void)logout: (NSDictionary *)payload {
    [[PPAppPlatformKit share] logout];
}

+ (void)purchase: (NSDictionary *)payload {
    NSLog(@">>> purchase: %@\n", payload);
    [[PPAppPlatformKit share] exchangeGoods:[[payload objectForKey:@"amount"] intValue]
                                     BillNo:[payload objectForKey:@"transaction_id"]
                                  BillTitle:[payload objectForKey:@"goods_name"]
                                     RoleId:[payload objectForKey:@"echo"]
                                     ZoneId:0];
}

+ (void)platform: (NSDictionary *)payload {
    [[PPAppPlatformKit share] showSDKCenter];
}

+ (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
 [[PPAppPlatformKit share] alixPayResult:url];
 return YES;
}

// }}}

#pragma mark -
#pragma mark For SDK

/**
 *  动态库加载成功回调 （注意：登录必须在该回调之后调用）
 */
+ (void)ppDylibLoadSucceedCallBack
{
}

/**
 *  登录成功回调
 *
 *  @param paramStrToKenKey 字符串token
 *  @param block            回调block === 验证成功 block(YES) || 验证失败（NO）
 */
+ (void)ppLoginSuccessCallBack:(NSString *)paramStrToKenKey callBack:(tokenVerifyingSuccessCallBack)block
{
    NSLog(@">>> token: %@", paramStrToKenKey);

    NSDictionary *payload = @{@"sessionId": paramStrToKenKey, @"userId": @""};
    NSData *data = [NSJSONSerialization dataWithJSONObject:payload options:NSJSONWritingPrettyPrinted error:nil];
    NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];

    platform_callback(CB_LOGIN_SUCCESS, [json UTF8String]);

    //cp必须回调
    if (block) {
        block(YES);
    }

}

/**
 * @brief   注销后的回调
 * @return  无返回
 */
+ (void)ppLogOffCallBack
{
    NSLog(@"注销回调");
    platform_callback(CB_LOGOUT_SUCCESS, "");
}

@end
