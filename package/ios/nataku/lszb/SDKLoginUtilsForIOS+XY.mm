#import "SDKLoginUtilsForIOS+XY.h"

@implementation SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_XY)

#pragma mark -
#pragma mark YunyueSDKIntegrateDelegate

// {{{ Optional

+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions rootViewController:(UIViewController *)rootViewController {
    NSLog(@">>> SDK_APP_ID: %d", [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_ID"] intValue]);

    [[XYPlatform defaultPlatform] initializeWithAppId:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_ID"]
                                               appKey:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_KEY"]
                      isContinueWhenCheckUpdateFailed:YES];
    [XYPlatform defaultPlatform].appScheme = [[[NSBundle mainBundle] infoDictionary] objectForKey:(NSString *)kCFBundleIdentifierKey];

    //    [[XYPlatform defaultPlatform] XYSetDebugModel:YES];
    //    [[XYPlatform defaultPlatform] XYSetShowSDKLog:YES];

    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(afterInit:)
                                                 name:kXYPlatformInitDidFinishedNotification
                                               object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(loginNotification:)
                                                 name:kXYPlatformLoginNotification
                                               object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(logoutNotification:)
                                                 name:kXYPlatformLogoutNotification
                                               object:nil];
}

+ (void)login: (NSDictionary *)payload {
    [[XYPlatform defaultPlatform] XYAutoLogin:0];
}

+ (void)logout: (NSDictionary *)payload {
    [[XYPlatform defaultPlatform] XYLogout:0];
}

+ (void)purchase: (NSDictionary *)payload {
    NSLog(@">>> purchase: %@\n", payload);
    [XYPlatform defaultPlatform].appScheme = [[[NSBundle mainBundle] infoDictionary] objectForKey:(NSString *)kCFBundleIdentifierKey];
    [[XYPlatform defaultPlatform] XYPayWithAmount:[payload objectForKey:@"amount"]
                                      appServerId:[payload objectForKey:@"server_id"]
                                         appExtra:[payload objectForKey:@"echo"]
                                         delegate:[SDKLoginUtilsForIOS class]];
}

+ (void)platform: (NSDictionary *)payload {
    [[XYPlatform defaultPlatform] XYEnterUserCenter:0];
}

+ (void)handleOpenURL:(NSURL *)url {
    [[XYPlatform defaultPlatform] XYHandleOpenURL:url];
}

+ (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    [[XYPlatform defaultPlatform] XYHandleOpenURL:url];
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
    if ([[notification.userInfo objectForKey:@"ret"] integerValue] != 0) {
        NSLog(@">>> login failed.");
        return;
    }

    NSDictionary *payload = @{@"sessionId": [[XYPlatform defaultPlatform] XYToken],
                              @"userId": [[XYPlatform defaultPlatform] XYOpenUID]};
    NSData *data = [NSJSONSerialization dataWithJSONObject:payload options:NSJSONWritingPrettyPrinted error:nil];
    NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];

    platform_callback(CB_LOGIN_SUCCESS, [json UTF8String]);
}

+ (void)logoutNotification: (NSNotification *)notification {
    NSLog(@">>> notification: %@\n", notification);
    platform_callback(CB_LOGOUT_SUCCESS, "");
}

+ (void)afterInit: (NSNotification *)notification {
    NSLog(@">>> SDK Initialized: %@\n", notification);
}

@end
