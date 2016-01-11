//
//  SDKLoginUtilsForIOS+TBPlatform.m
//  lszb
//
//  Created by liupeng on 1/13/15.
//
//

#import "SDKLoginUtilsForIOS+TBPlatform.h"

int login_delegate = -1;
int logout_delegate = -1;

@implementation SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_HXAppPlatformKitPro)

+ (void)registerNotification: (NSNotification *)notification {
    NSLog(@">>> notification: %@\n", notification);
}

+ (void)loginNotification: (NSNotification *)notification {
    NSLog(@">>> notification: %@\n", notification);
    if ([[TBPlatform defaultPlatform] TBIsLogined]) {
        
        //显示浮动工具条
        [[TBPlatform defaultPlatform] TBShowToolBar:TBToolBarAtMiddleLeft
                                      isUseOldPlace:YES];

        TBPlatformUserInfo *userInfo = [[TBPlatform defaultPlatform] TBGetMyInfo];


        NSDictionary *payload = @{@"sessionId": [userInfo sessionID],
                                  @"userId": [userInfo userID],
                                  @"userName": [userInfo nickName]};
        NSData *data = [NSJSONSerialization dataWithJSONObject:payload options:NSJSONWritingPrettyPrinted error:nil];
        NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];

        platform_callback(CB_LOGIN_SUCCESS, [json UTF8String]);
        
    } else {
        NSLog(@"login error.\n");
        
    }
    
    
}

+ (void)logoutNotification: (NSNotification *)notification {
    NSLog(@">>> notification: %@\n", notification);
    platform_callback(CB_LOGOUT_SUCCESS, "");
}

+ (void)closeViewNotification: (NSNotification *)notification {
    NSLog(@">>> notification: %@\n", notification);
}

#pragma mark YunyueSDKIntegrateDelegate


+ (void)sdkInitFinished{
    NSLog(@"..............sdkInitFinished...............");
}


+ (void)leavedSDKPlatform:(NSNotification *)notification{
    NSDictionary *notifyUserInfo = notification.userInfo;
    TBPlatformLeavedType leavedFromType = (TBPlatformLeavedType)[[notifyUserInfo objectForKey:
                                                                  TBLeavedPlatformTypeKey] intValue];
    switch (leavedFromType) {
            //从登录页离开
        case TBPlatformLeavedFromLogin:{
        }
            break;
            //从个人中心离开
        case TBPlatformLeavedFromUserCenter:{
        }
            break;
            //从充值页面离开
        case TBPlatformLeavedFromUserPay:{
            NSString *orderString = [notifyUserInfo objectForKey:TBLeavedPlatformOrderKey];
            [[TBPlatform defaultPlatform] TBCheckPaySuccess:orderString
                                                   delegate:self];
        }
            break;
        default:
            break;
    }
}


+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions rootViewController:(UIViewController *)rootViewController {
    
    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class]
                                             selector:@selector(sdkInitFinished)
                                                 name:kTBInitDidFinishNotification
                                               object:Nil];
    
    // 登录通知
    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class]
                                             selector:@selector(loginNotification:)
                                                 name:kTBLoginNotification
                                               object:nil];
    // 注销通知
    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class]
                                             selector:@selector(logoutNotification:)
                                                 name:kTBUserLogoutNotification
                                               object:nil];
    
    /*离开平台通知（包括登录页面、个人中心页面、web充值页等*/
    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class]
                                             selector:@selector(leavedSDKPlatform:)
                                                 name:kTBLeavePlatformNotification
                                               object:nil];
    
     [[TBPlatform defaultPlatform] TBInitPlatformWithAppID:[[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_ID"] integerValue]
                                         screenOrientation:UIInterfaceOrientationPortrait
                           isContinueWhenCheckUpdateFailed:NO];
}

+ (void) login: (NSDictionary *)payload {
    [[TBPlatform defaultPlatform] TBLogin:0];
}

+ (void) logout: (NSDictionary *)payload {
    [[TBPlatform defaultPlatform] TBLogout:0];
    [[TBPlatform defaultPlatform] TBHideToolBar];
}

+ (void) purchase: (NSDictionary *)payload {
    NSLog(@">>> purchase: %@\n", payload);
    //固定金额的购买
    [[TBPlatform defaultPlatform] TBUniPayForCoin:[payload objectForKey:@"transaction_id"]
                                       needPayRMB:[[payload objectForKey:@"amount"] floatValue]
                                   payDescription:[payload objectForKey:@"echo"]
                                         delegate:[SDKLoginUtilsForIOS class]];
    
}

+ (void) platform: (NSDictionary *)payload {
    [[TBPlatform defaultPlatform] TBEnterUserCenter:0];
}

@end
