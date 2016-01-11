#import "SDKLoginUtilsForIOS+KY.h"

@implementation SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_KY)

#pragma mark -
#pragma mark YunyueSDKIntegrateDelegate

// {{{ Optional

+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions rootViewController:(UIViewController *)rootViewController {
    [[XSDK instanceXSDK] setAppKey:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_KEY"]];
    [[XSDK instanceXSDK] setXsdkDelegate:[self class]];
    [[XSDK instanceXSDK] checkUpdate];
    [[XSDK instanceXSDK] setGameContact:@""];

}

+ (void)login: (NSDictionary *)payload {
    [[XSDK instanceXSDK] login];
}

+ (void)logout: (NSDictionary *)payload {
    [[XSDK instanceXSDK] logout];
}

+ (void)purchase: (NSDictionary *)payload {
    NSLog(@">>> purchase: %@\n", payload);

    [[XSDK instanceXSDK] payWithDealSeq:[payload objectForKey:@"transaction_id"]
                                 andFee:[NSString stringWithFormat:@"%@.00", [payload objectForKey:@"amount"]]
                               andPayID:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_GAME"]
                             andGamesvr:@""
                      andGameUserServer:[payload objectForKey:@"server_id"]
                             andSubject:[payload objectForKey:@"goods_name"]];
}

+ (void)platform: (NSDictionary *)payload {
    [XSDK instanceXSDK];
}

 + (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
     if ([[XSDK instanceXSDK] handleApplication:[UIApplication sharedApplication] openURL:url sourceApplication:sourceApplication annotation:annotation]) {
         NSLog(@"第三方处理");
     }
     return YES;
 }

// }}}

#pragma mark -
#pragma mark For SDK

+ (void)XSDKLogOutCallBack:(NSString *)guid {
    NSLog(@"guid %@",guid);
    platform_callback(CB_LOGOUT_SUCCESS, "");
}

+ (void)XSDKLoginCallBack:(NSString *)tokenKey {
    NSDictionary *params = @{@"sessionId": tokenKey, @"userId": @""};
    NSData *data = [NSJSONSerialization dataWithJSONObject:params options:NSJSONWritingPrettyPrinted error:nil];
    NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];

    platform_callback(CB_LOGIN_SUCCESS, [json UTF8String]);
}

+ (void)XSDKChangeSubNOCallBack:(NSString *)oldGuid newTokenKey:(NSString *)newTokenKey {
    NSLog(@">>> XSDKChangeSubNOCallBack");
    platform_callback(CB_LOGOUT_SUCCESS, "");
}

+ (void)gameLoginSuc {
    UIAlertView * tip2 = [[UIAlertView alloc]initWithTitle:@"登录成功:key" message:@"" delegate:nil cancelButtonTitle:@"ok" otherButtonTitles:nil];
    [tip2 show];
    [tip2 release];
}

+ (void)cancelUpdateCallBack {
    NSLog(@"点击了取消更新");
}

+ (void)callBackForgetGamePwd {
}

@end
