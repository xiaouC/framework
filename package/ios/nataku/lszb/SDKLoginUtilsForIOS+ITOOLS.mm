#import "SDKLoginUtilsForIOS+ITOOLS.h"

@implementation SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_ITOOLS)

#pragma mark -
#pragma mark YunyueSDKIntegrateDelegate

// {{{ Optional

+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions rootViewController:(UIViewController *)rootViewController {
    NSLog(@">>> SDK_APP_ID: %d", [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_ID"] intValue]);

    [HXAppPlatformKitPro setAppId:[[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_ID"] integerValue]
                           appKey:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_KEY"]];
    [HXAppPlatformKitPro setAlipayURLScheme:[[[NSBundle mainBundle] infoDictionary] objectForKey:(NSString *)kCFBundleIdentifierKey]];
    [HXAppPlatformKitPro setSupportOrientationPortrait:YES
                                    portraitUpsideDown:NO
                                         landscapeLeft:NO
                                        landscapeRight:NO];
    [HXAppPlatformKitPro setSDKAssistiveTouchAtScreenPlace: TSAssistiveTouchViewAtTopLeft];
    // 登录通知
    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class]
                                             selector:@selector(loginNotification:)
                                                 name:HX_NOTIFICATION_LOGIN
                                               object:nil];
    // 注销通知
    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class]
                                             selector:@selector(logoutNotification:)
                                                 name:HX_NOTIFICATION_LOGOUT
                                               object:nil];
    // 视图关闭通知
    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class]
                                             selector:@selector(closeViewNotification:)
                                                 name:HX_NOTIFICATION_CLOSEVIEW
                                               object:nil];
    // 注册通知
    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class]
                                             selector:@selector(registerNotification:)
                                                 name:HX_NOTIFICATION_REGISTER
                                               object:nil];
}

+ (void)login: (NSDictionary *)payload {
    [HXAppPlatformKitPro setLoginViewClosedEnabled:NO];
    [HXAppPlatformKitPro showLoginView];
}

+ (void)logout: (NSDictionary *)payload {
    [HXAppPlatformKitPro logout];
}

+ (void)purchase: (NSDictionary *)payload {
    NSLog(@">>> purchase: %@\n", payload);

    [HXAppPlatformKitPro payProductWithProductName:[payload objectForKey:@"goods_name"]
                                            Amount:[[payload objectForKey:@"amount"] floatValue]
                                        OrderIdCom:[payload objectForKey:@"transaction_id"]];
}

+ (void)platform: (NSDictionary *)payload {
    [HXAppPlatformKitPro showPlatformView];
}

 + (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
     if ([url.host isEqualToString:@"safepay"]) {
         [[AlipaySDK defaultService] processOrderWithPaymentResult:url standbyCallback:^(NSDictionary *resultDic) {
             [HXAppPlatformKitPro alipayCallBack:resultDic];
         }];
     }
     return YES;
 }

// }}}

#pragma mark -
#pragma mark For SDK

+ (void)registerNotification: (NSNotification *)notification {
    NSLog(@">>> notification: %@\n", notification);
}

+ (void)loginNotification: (NSNotification *)notification {
    NSLog(@">>> notification: %@\n", notification);
    NSDictionary *userInfo = notification.object;

    NSData *data = [NSJSONSerialization dataWithJSONObject:userInfo options:NSJSONWritingPrettyPrinted error:nil];
    NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];

    platform_callback(CB_LOGIN_SUCCESS, [json UTF8String]);
}

+ (void)logoutNotification: (NSNotification *)notification {
    NSLog(@">>> notification: %@\n", notification);
    platform_callback(CB_LOGOUT_SUCCESS, "");
}

+ (void)closeViewNotification: (NSNotification *)notification {
    NSLog(@">>> notification: %@\n", notification);
}

@end
