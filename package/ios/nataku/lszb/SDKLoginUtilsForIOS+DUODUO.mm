#import "SDKLoginUtilsForIOS+DUODUO.h"

@implementation SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_DUODUO)

#pragma mark -
#pragma mark YunyueSDKIntegrateDelegate

// {{{ Optional

+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions rootViewController:(UIViewController *)rootViewController {
    [[RekooUnifyPlatform getInstance] rkInit];

    //初始化回调
    [[NSNotificationCenter defaultCenter] addObserver:[self class]
                                             selector:@selector(getInitCallBack:)
                                                 name:KRKSDKInitDidFinish object:nil];

    //登录
    [[NSNotificationCenter defaultCenter] addObserver:[self class]
                                             selector:@selector(loginCallback:)
                                                 name:KRKSDKLogin object:nil];

    //注销回调
    [[NSNotificationCenter defaultCenter] addObserver:[self class]
                                             selector:@selector(logoutCallBack:)
                                                 name:KRKLogout object:nil];

}

+ (void)login: (NSDictionary *)payload {
    NSLog(@">>> press login");
    [[RekooUnifyPlatform getInstance] rkLogin];
}

+ (void)logout: (NSDictionary *)payload {
    [[RekooUnifyPlatform getInstance] rkLogout];
}

+ (void)purchase: (NSDictionary *)payload {
    NSLog(@">>> purchase: %@\n", payload);
    RKMProductionInfo *mpProductInro=[RKMProductionInfo getRKMProductionInfo:[payload objectForKey:@"transaction_id"]
                                                                 andRoleName:@"null"
                                                                andRoleGrade:@"null"
                                                              andRoleBalance:@"0"
                                                                  andRoleVip:@"0"
                                                            andRoleUserParty:@"null"
                                                               andServerName:@"null"];


    RKProductInfo *productInfo=[RKProductInfo getRKProductInfo:[payload objectForKey:@"transaction_id"]
                                                  andProductId:[payload objectForKey:@"amount"]
                                                andProductName:[payload objectForKey:@"product_name"]
                                               andProductPrice:[[payload objectForKey:@"amount"] intValue]
                                               andProductCount:1
                                            andPayDescripation:[payload objectForKey:@"product_name"]
                                                 andUserServer:[payload objectForKey:@"server_id"]
                                                    andExtInfo:[payload objectForKey:@"echo"]
                                            andMProductionInfo:mpProductInro];

    [[RekooUnifyPlatform getInstance] rkPayWithProductInfo:productInfo];
}

//+ (void)platform: (NSDictionary *)payload {
//}

+ (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
 [[RekooUnifyPlatform getInstance] rkHandleUrl:url];
 return YES;
}

// }}}

#pragma mark -
#pragma mark For SDK

+ (void)getInitCallBack:(NSNotification *)notification
{
    if ([notification.object isEqualToString:KSuccess])
    {
        NSLog(@"初始化成功");
    }
    else
    {
        NSLog(@"初始化成功");
    }
}


+ (void)loginCallback:(NSNotification *)notification {
    NSDictionary *payload = @{@"sessionId": [notification.userInfo objectForKey:@"sessionid"], @"userId": [notification.userInfo objectForKey:@"uid"]};
    NSData *data = [NSJSONSerialization dataWithJSONObject:payload options:NSJSONWritingPrettyPrinted error:nil];
    NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];

    platform_callback(CB_LOGIN_SUCCESS, [json UTF8String]);
}

+ (void)logoutCallback:(NSNotification *)notification {
    NSLog(@"注销的回掉");
    platform_callback(CB_LOGOUT_SUCCESS, "");
}

@end
