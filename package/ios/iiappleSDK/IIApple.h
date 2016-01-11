//
//  iiapple.h
//  iiappleSDK
//
//  Created by stefan on 14-7-9.
//  Copyright (c) 2014年 stefan. All rights reserved.
//

#define IALOGINSUCCEED @"IALOGINSUCCEED"
#define IALOGOUTSUCCEED @"IALOGOUTSUCCEED"
#define IAPAYSUCCEED @"IAPAYSUCCEED"
#define IACLOSELOGINVIEW @"IACLOSELOGINVIEW"

#import <Foundation/Foundation.h>

@interface IIApple : NSObject

/*
 @method initIiappleWithDic:
 @abstract 初始化iiappleSDK，设置游戏相关的参数
 @param dic NSDictionary中包含初始化所需要的参数
*/
+(void)initIiappleWithDic:(NSDictionary*)dic;

/*
 @method doLogin
 @abstract 调用过initIiappleWithDic:后调用此接口，sdk会自动判断当前的登录状态做相应的处理。
*/
+(void)doLogin;

/*
 @method pushLoginView
 @abstract 显示登录页面
 */
+(void)pushLoginView;


/*
 @method doPay
 @param Amount支付金额
 @param productName 商品标题
 @param extend支付游戏所需的扩展参数，支付成功会回传给游戏服务器。
 @abstract 显示充值页面
 */
+(void)doPayWithAmount:(int)amount
           productName:(NSString*)productName
                extend:(NSString*)extend;
/*
 @method pushUserCenterView
 @abstract 显示个人中心页面
 */
+(void)pushUserCenterView;

/*
 @method logout
 @abstract 退出登录
 */
+(void)logout;

/*
 @method checkUpdate
 @abstract 检查版本号，自动提示是否更新。是否强制更新在i苹果后台设置。
 */
+(void)checkUpdate;
/*
 @method gameUpdateWithIsForce:
 @param IsForce 是否强制更新
 @abstract 游戏方控制版本号，如果需要更新调用此接口，sdk会自动弹出更新提示窗口并完成更新。
 */
+(void)gameUpdateWithIsForce:(BOOL)IsForce;

+(void)application:(UIApplication *)application
           openURL:(NSURL *)url
 sourceApplication:(NSString *)sourceApplication
        annotation:(id)annotation;


+(void)showAssistiveTouch;

+(void)hiddenAssistiveTouch;

+(NSUInteger)supportedInterfaceOrientationsForWindow:(UIWindow *)window;

@end

