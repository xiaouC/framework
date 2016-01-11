//
//  SDKLoginUtilsForIOS+PPAppPlatformKit.m
//  lszb
//
//  Created by ratazzi on 12/3/14.
//
//

#import "SDKLoginUtilsForIOS+PPAppPlatformKit.h"

int login_delegate = -1;
int logout_delegate = -1;
int unlock_delegate = -1;

@implementation SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_PPAppPlatformKit)

#pragma mark SDK CALLBACK

// 关闭客户端页面回调方法
+ (void)ppClosePageViewCallBack:(PPPageCode)paramPPPageCode {
    // 可根据关闭的VIEW页面做你需要的业务处理
    NSLog(@"当前关闭的VIEW页面回调是%d", paramPPPageCode);
    if ((paramPPPageCode == PPLoginViewPageCode || paramPPPageCode == PPRegisterViewPageCode)
        && [[PPAppPlatformKit sharedInstance] loginState] == 0) {
        // 未登录，重新打开登录会有问题，所以直接解锁按钮，让玩家手动打开

        platform_callback(CB_UNLOCK_LOGIN, "");
        NSLog(@">>> unlock jinru");

        NSLog(@">>> subviews: %@", [UIApplication sharedApplication].keyWindow.subviews);
    }
}

// 关闭WEB页面回调方法
+ (void)ppCloseWebViewCallBack:(PPWebViewCode)paramPPWebViewCode {
    // 可根据关闭的WEB页面做你需要的业务处理
    NSLog(@"当前关闭的WEB页面回调是%d", paramPPWebViewCode);
}

+ (void)ppLoginStrCallBack:(NSString *)paramStrToKenKey{
    NSLog(@"token: %@", paramStrToKenKey);

    NSDictionary *payload = @{@"sessionId": paramStrToKenKey, @"userId": @""};
    NSData *data = [NSJSONSerialization dataWithJSONObject:payload options:NSJSONWritingPrettyPrinted error:nil];
    NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];

    platform_callback(CB_LOGIN_SUCCESS, [json UTF8String]);
}

// 注销回调方法
+ (void)ppLogOffCallBack {
    platform_callback(CB_LOGOUT_SUCCESS, "");
}

+ (void)ppVerifyingUpdatePassCallBack{
    NSLog(@"验证游戏版本完毕回调");
    [[PPAppPlatformKit sharedInstance] showLogin];
}

// 兑换回调接口【只有兑换会执行此回调】
+ (void)ppPayResultCallBack:(PPPayResultCode)paramPPPayResultCode {
    NSLog(@"兑换回调返回编码%d", paramPPPayResultCode);
    // 回调购买成功。其余都是失败
    if (paramPPPayResultCode == PPPayResultCodeSucceed) {
        // 购买成功发放道具
        NSLog(@"购买成功");
    } else {
        NSLog(@"购买失败");
    }
}

#pragma mark YunyueSDKIntegrateDelegate

+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions rootViewController:(UIViewController *)rootViewController {
    [[PPAppPlatformKit sharedInstance] setAppId:[[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_ID"] integerValue]
                                         AppKey:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_KEY"]];
    [[PPAppPlatformKit sharedInstance] setIsNSlogData:NO];
    [[PPAppPlatformKit sharedInstance] setRechargeAmount:10];
    [[PPAppPlatformKit sharedInstance] setIsLongComet:YES];
    [[PPAppPlatformKit sharedInstance] setIsLogOutPushLoginView:NO];
    [[PPAppPlatformKit sharedInstance] setIsOpenRecharge:YES];
    [[PPAppPlatformKit sharedInstance] setCloseRechargeAlertMessage:@"充值未开启"];
    [[PPAppPlatformKit sharedInstance] setDelegate:[SDKLoginUtilsForIOS class]];
}

+ (void)handleOpenURL:(NSURL *)url {
    [[PPAppPlatformKit sharedInstance] alixPayResult:url];
}

+ (void) login: (NSDictionary *)payload {
    [[PPAppPlatformKit sharedInstance] setIsLogOutPushLoginView:NO];
    [[PPAppPlatformKit sharedInstance] showLogin];
}

+ (void) logout: (NSDictionary *)payload {
    [[PPAppPlatformKit sharedInstance] PPlogout];
}

+ (void) purchase: (NSDictionary *)payload {
    NSLog(@">>> purchase: %@\n", payload);
    [[PPAppPlatformKit sharedInstance] exchangeGoods:[[payload objectForKey:@"amount"] intValue]
                                              BillNo:[payload objectForKey:@"transaction_id"]
                                           BillTitle:[payload objectForKey:@"goods_name"]
                                              RoleId:[payload objectForKey:@"echo"]
                                              ZoneId:0];
}

+ (void) platform: (NSDictionary *)payload {
    [[PPAppPlatformKit sharedInstance] showCenter];
}

@end
