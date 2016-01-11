//
//  SDKLoginUtilsForIOS+XX.m
//  lszb
//
//  Created by ratazzi on 12/3/14.
//
//

#import "SDKLoginUtilsForIOS+XX.h"

int login_delegate = -1;
int logout_delegate = -1;

@implementation SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_XX)

#pragma mark YunyueSDKIntegrateDelegate

+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions rootViewController:(UIViewController *)rootViewController {
    [GPGameSDKLog shareGPGameSDKLog].enableLog = YES;
    [GPGameSDK_Pay defaultGPGamePay].appScheme = [[[NSBundle mainBundle] infoDictionary] objectForKey:(NSString *)kCFBundleIdentifierKey];
    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class] selector:@selector(loginNotif:) name:kGPGameNotification_Login_Succeed object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class] selector:@selector(payMentResult:) name:kGPGameNotification_Pay_Result object:nil];

}

+ (void) login: (NSDictionary *)payload {
    [[GPGameSDK defaultGPGame] GPInit:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_APP_ID"]
                            secretKey:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SDK_CLIENT_SECRET"]
                           completion:^(GPInitErrorCode result) {
                               dispatch_async(dispatch_get_main_queue(), ^{
                                   if (result == GPInitErrorCodeNone) {
                                       NSLog(@">>> init");
                                       [[GPGameSDK defaultGPGame] GPLoginInView:[UIApplication sharedApplication].keyWindow.rootViewController.view];
                                   }
                                   else{
                                       //GPInitErrorCodeNone = 0,    //初始化成功
                                       //GPInitErrorCodeNet = 1, //网络异常
                                       //GPInitErrorCodeConig = 2,   //appid,secret配置错误
                                       //GPInitErrorCodeUpdating = 3,  //游戏更新中
                                       
                                       //1.SDK 会自己show出UIAlertView
                                       //2.TODO 处理本地逻辑
                                       //登录初始化问题应该kill app，重新进入
                                       exit(0);
                                   }
                               });
                           }];
}

+ (void) logout: (NSDictionary *)payload {
    [[GPGameSDK defaultGPGame] GPLogout];
}

+ (void) purchase: (NSDictionary *)payload {
    NSLog(@">>> purchase: %@\n", payload);
    [[GPGameSDKLog shareGPGameSDKLog] writeLog:[NSString stringWithFormat:@"***游戏方发起购买"]];
    
    GPSDKGamePayment *aGamePayment = [[GPSDKGamePayment alloc] init];
    
    aGamePayment.serialNumber = [payload objectForKey:@"transaction_id"];
    aGamePayment.itemID = [payload objectForKey:@"product_id"];//自定义id
    aGamePayment.itemName = [payload objectForKey:@"product_name"];
    aGamePayment.itemPrice = [[payload objectForKey:@"amount"] floatValue];
    aGamePayment.itemCount = 1;
    aGamePayment.reserved = [payload objectForKey:@"echo"];//透传字段
    aGamePayment.paymentDes = [payload objectForKey:@"product_name"];
    
    int result = [[GPGameSDK_Pay defaultGPGamePay] asyncGPPay:aGamePayment];
    if (result == 0) {
        //支付请求成功
    }
    else{
        // -1，登录问题
        // -2, 订单不合法
        
        if (result == -1) {
            [[GPGameSDKLog shareGPGameSDKLog] writeLog:[NSString stringWithFormat:@"***游戏方发起购买 错误:登录状态有问题"]];
            
            UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:nil message:@"登录状态有问题" delegate:self cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
            [alertView show];
        } else if(result == -2){
            [[GPGameSDKLog shareGPGameSDKLog] writeLog:[NSString stringWithFormat:@"***游戏方发起购买 错误:订单不合法"]];
            
            UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:nil message:@"订单不合法" delegate:self cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
            [alertView show];
        }
    }
}

+ (void) platform: (NSDictionary *)payload {
}

+ (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    return [[GPGameSDK_Pay defaultGPGamePay] openUrlResponse:url];
}

#pragma mark AsPlatformSDKDelegate

+ (void)loginNotif:(id)no
{
    [[GPGameSDKLog shareGPGameSDKLog] writeLog:[NSString stringWithFormat:@"***登录成功 loginUIN:<%@> loginToken:<%@> accountName:<%@>", [[GPGameSDK defaultGPGame] loginUin], [[GPGameSDK defaultGPGame] loginToken], [[GPGameSDK defaultGPGame] accountName]]];
    
//    dispatch_async(dispatch_get_main_queue(), ^{
//        //更新ui
//    });
    
    NSDictionary *payload = @{@"sessionId": [[GPGameSDK defaultGPGame] loginToken], @"userId": [[GPGameSDK defaultGPGame] loginUin]};
    NSData *data = [NSJSONSerialization dataWithJSONObject:payload options:NSJSONWritingPrettyPrinted error:nil];
    NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];
    
    platform_callback(CB_LOGIN_SUCCESS, [json UTF8String]);
    
}

+ (void)payMentResult:(NSNotification *)notification
{
    GPSDKGamePaymentResult * result= (GPSDKGamePaymentResult *)(notification.object);
    
    [[GPGameSDKLog shareGPGameSDKLog] writeLog:[NSString stringWithFormat:@"***游戏方接受购买结果 serialNumber:<%@> resultcode:<%d>",result.serialNumber, result.resultCode]];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        //更新ui
    });
    
}


@end
