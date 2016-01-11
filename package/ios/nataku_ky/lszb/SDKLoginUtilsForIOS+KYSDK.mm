//
//  SDKLoginUtilsForIOS+KYSDK.m
//  lszb
//
//  Created by liupeng on 12/3/14.
//
//

#import "SDKLoginUtilsForIOS+KYSDK.h"

int login_delegate = -1;
int logout_delegate = -1;

@implementation SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_KYSDK)

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

#pragma mark YunyueSDKIntegrateDelegate

+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions rootViewController:(UIViewController *)rootViewController {
    [[KYSDK instance] setSdkdelegate:self];
}

+ (void) login: (NSDictionary *)payload {
    [[KYSDK instance] changeLogOption:KYLOG_OFFGAMENAME];
    [[KYSDK instance] showUserView];
}

+ (void) logout: (NSDictionary *)payload {
    [[KYSDK instance] userLogOut];
}

+ (void) purchase: (NSDictionary *)payload {
    NSLog(@">>> purchase: %@\n", payload);
    [[KYSDK instance] showPayWith:[payload objectForKey:@"transaction_id"]
                              fee:[payload objectForKey:@"amount"]
                             game:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_GAME"]
                          gamesvr:@""
                          subject:[payload objectForKey:@"goods_name"]
                           md5Key:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_MD5_KEY"]
                           userId:@""
                        appScheme:@"com.yunyuegame.nzgl.ky"];
}

+ (void) platform: (NSDictionary *)payload {
    [[KYSDK instance] setUpUser];
}

#pragma mark --KyUserSDKDelegate--
+(void)loginCallBack:(NSString *)tokenKey{
    NSLog(@".........YYY loginCallBack................");
    NSDictionary *params = @{@"sessionId": tokenKey, @"userId": @""};
    NSData *data = [NSJSONSerialization dataWithJSONObject:params options:NSJSONWritingPrettyPrinted error:nil];
    NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];

    platform_callback(CB_LOGIN_SUCCESS, [json UTF8String]);
}

+(void)quickLogCallBack:(NSString *)tokenKey{
    NSLog(@".........YYY quickLogCallBack................");
    NSDictionary *params = @{@"sessionId": tokenKey, @"userId": @""};
    NSData *data = [NSJSONSerialization dataWithJSONObject:params options:NSJSONWritingPrettyPrinted error:nil];
    NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];

    platform_callback(CB_LOGIN_SUCCESS, [json UTF8String]);
}



+(void)logOutCallBack:(NSString *)guid{
    NSLog(@".........YYY logOutCallBack................");

    NSLog(@"用户点击了注销按钮");
    
    NSLog(@"guid %@",guid);

    platform_callback(CB_LOGOUT_SUCCESS, "");

}



#pragma mark end


-(void)gameLoginCallback:(NSString *)username password:(NSString *)password
{
    
    NSLog(@".........YYY gameLoginCallback................");

//    NSLog(@"name  %@  pwd  %@",username,password);
//    if ([username isEqualToString:gamename.text] && [password isEqualToString:gamepwd.text]) {
//        [[KYSDK instance]showStateGame:@"suc"];
//    }else{
//        [[KYSDK instance]showStateGame:gamemsg.text];
//    }
    
}

+(void)gameLoginSuc
{
    NSLog(@".........YYY gameLoginSuc................");

    NSLog(@"log  log log!!!");
    UIAlertView * tip2 = [[UIAlertView alloc]initWithTitle:@"登录成功:key" message:@"" delegate:nil cancelButtonTitle:@"ok" otherButtonTitles:nil];
    [tip2 show];
    [tip2 release];
    
//    [self showPayBtn];
    
}
+(void)cancelUpdateCallBack{
    NSLog(@".........YYY cancelUpdateCallBack................");

    NSLog(@"点击了取消更新");
}

+(void)callBackForgetGamePwd
{
    NSLog(@".........YYY callBackForgetGamePwd................");

//    [[UIApplication sharedApplication]openURL:[NSURL URLWithString:@"http://www.baidu.com"]];
}





@end
