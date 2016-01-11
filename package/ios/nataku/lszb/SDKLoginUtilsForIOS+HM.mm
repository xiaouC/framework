#import "SDKLoginUtilsForIOS+HM.h"

@implementation SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_HM)

#pragma mark -
#pragma mark YunyueSDKIntegrateDelegate

// {{{ Optional

+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions rootViewController:(UIViewController *)rootViewController {
    NSLog(@">>> SDK_APP_ID: %@", [[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_ID"]);

    [ZHPayPlatform initWithAppId:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_ID"]
                    withDelegate:[SDKLoginUtilsForIOS class]
                  testUpdateMode:NO
            alertTypeCheckFailed:0];
    [ZHPayPlatform setSupportOrientation:UIInterfaceOrientationMaskPortrait];
    [ZHPayPlatform setLogEnable:YES];
}

+ (void)login: (NSDictionary *)payload {
    [ZHPayPlatform startLogin];
}

+ (void)logout: (NSDictionary *)payload {
    [ZHPayPlatform startLogout];
}

+ (void)purchase: (NSDictionary *)payload {
    NSLog(@">>> purchase: %@\n", payload);
    ZHPayOrderInfo *order = [[ZHPayOrderInfo alloc] init];
    order.orderId = [payload objectForKey:@"transaction_id"];
    order.productName = [payload objectForKey:@"product_name"];
    order.gameName = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"];
    order.productPrice = [[payload objectForKey:@"amount"] integerValue];
    order.userParams = [payload objectForKey:@"echo"];
    [ZHPayPlatform startPay:order delegate:[SDKLoginUtilsForIOS class]];
}

+ (void)platform: (NSDictionary *)payload {
    [ZHPayPlatform showUserCenter];
}

// + (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
//     return YES;
// }

// }}}

#pragma mark -
#pragma mark For SDK

+ (void)ZHPayLoginSuccess:(ZHPayUserInfo *)userInfo {
    NSDictionary *payload = @{@"sessionId": userInfo.validateToken, @"userId": userInfo.userId};
    NSData *data = [NSJSONSerialization dataWithJSONObject:payload options:NSJSONWritingPrettyPrinted error:nil];
    NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];

    platform_callback(CB_LOGIN_SUCCESS, [json UTF8String]);
}

+ (void)ZHPayLoginCancel {
    NSLog(@"账户登录取消");
}

+ (void)ZHPayDidLogout {
    NSLog(@"账户注销成功,此时您需要将游戏退出,并展示登录前界面");
    platform_callback(CB_LOGOUT_SUCCESS, "");
}

+ (void)ZHPayViewIn {
    NSLog(@"SDK视图出现");
}

+ (void)ZHPayViewOut {
    NSLog(@"SDK视图消失");
}

@end
