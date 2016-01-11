#import "SDKLoginUtilsForIOS+IIAPPLE.h"

@implementation SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_IIAPPLE)

#pragma mark -
#pragma mark YunyueSDKIntegrateDelegate

// {{{ Optional

+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions rootViewController:(UIViewController *)rootViewController {
    NSDictionary* params = [NSDictionary dictionaryWithObjectsAndKeys:
                            [[NSBundle mainBundle] objectForInfoDictionaryKey:@"SDK_APP_GAME_KEY"], @"gameKey",
                            @"1", @"isVer",
                            @"1", @"isShowATView",
                            [[[NSBundle mainBundle] infoDictionary] objectForKey:(NSString *)kCFBundleIdentifierKey], @"alipayScheme",
                            [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleVersion"], @"gameVersion",
                            @"1", @"isRepeatPay",
                            @"1", @"isLastXcode6",
                            nil];
    [IIApple initIiappleWithDic:params];

    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class]
                                             selector:@selector(loginSuccessed:)
                                                 name:IALOGINSUCCEED
                                               object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class]
                                             selector:@selector(logoutCallback:)
                                                 name:IALOGOUTSUCCEED
                                               object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class]
                                             selector:@selector(closeLoginView:)
                                                 name:IACLOSELOGINVIEW
                                               object:nil];
    [IIApple checkUpdate];
}

+ (void)login: (NSDictionary *)payload {
    [IIApple doLogin];
}

+ (void)logout: (NSDictionary *)payload {
    [IIApple logout];
}

+ (void)purchase: (NSDictionary *)payload {
    NSLog(@">>> purchase: %@\n", payload);

    [IIApple doPayWithAmount:[[payload objectForKey:@"amount"] intValue]
                 productName:[payload objectForKey:@"product_name"]
                      extend:[payload objectForKey:@"echo"]];
}

+ (void)platform: (NSDictionary *)payload {
    [IIApple pushUserCenterView];
}

 + (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
     [IIApple application:[UIApplication sharedApplication]
                  openURL:url
        sourceApplication:sourceApplication
               annotation:annotation];
     return YES;
 }

// }}}

#pragma mark -
#pragma mark For SDK

+ (void)loginSuccessed:(NSNotification *)notification {
    NSDictionary* payload = notification.object;
    NSLog(@">>> loginSuccessed: %@", payload);

    NSDictionary *params = @{@"sessionId": [payload objectForKey:@"session"], @"userId": [payload objectForKey:@"userid"]};
    NSData *data = [NSJSONSerialization dataWithJSONObject:params options:NSJSONWritingPrettyPrinted error:nil];
    NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];

    platform_callback(CB_LOGIN_SUCCESS, [json UTF8String]);
}

+ (void)logoutCallback:(NSNotification *)notification {
    platform_callback(CB_LOGOUT_SUCCESS, "");
}

+ (void)closeLoginView:(NSNotification *)notification {
    [NSTimer scheduledTimerWithTimeInterval:1.0f
                                     target:[IIApple class]
                                   selector:@selector(doLogin)
                                   userInfo:nil
                                    repeats:NO];
}

@end
