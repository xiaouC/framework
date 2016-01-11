//
//  GPGameSDK.h
//  GPGameSDK
//
//  Created by xuvance on 14-8-11.
//  Copyright (c) 2014年 vance. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
    GPInitErrorCodeNone = 0,    //初始化成功
    GPInitErrorCodeNet = 1, //网络异常
    GPInitErrorCodeConig = 2,   //appid,secret配置错误
    GPInitErrorCodeUpdating = 3 //游戏更新中
}GPInitErrorCode;

typedef void (^GPInitErrorCodeBlock)(GPInitErrorCode result);


@interface GPGameSDK : NSObject

/*
 @brief 获取GPGameSDK单例
 */
+ (GPGameSDK *)defaultGPGame;

/*
 @brief GPGameSDK应用初始化函数,异步函数，result 0表示成功，1表示网络异常，2表示appid、secret错误
 @notice 使用[[NSBundle mainBundle].infoDictionary objectForKey:@"CFBundleShortVersionString"]作为游戏版本号，如果获取到为空使用[[NSBundle mainBundle].infoDictionary objectForKey:@"CFBundleVersion"]
 */
- (void)GPInit:(NSString *)aAppID secretKey:(NSString *)aSKey completion:(GPInitErrorCodeBlock)completion;

/*
 @breif 调用登录, 登录结果会以通知形式返回，若登录成功，将自动退出登录页面
 @param view 当前view
 @return 返回0正常进入sdk登录界面， 非0表示sdk登录环境异常
 */
- (int)GPLoginInView:(UIView *)view;

/*
 @brief 注销，同步方法
 */
- (void)GPLogout;

/*
 @brief 判断是否已登录并且有效
 */
- (BOOL)isLogined;

#pragma mark -

/*
 @brief 本次登录token
 */
- (NSString *)loginToken;

/*
 @brief 登录后的用户uin
 */
- (NSString *)loginUin;

/*
 @brief 登录后的用户uinMD5
 */
- (NSString *)loginUinMD5;

/*
 @brief 本次登录帐号
 */
- (NSString *)accountName;

#pragma mark -
#pragma mark env data
/*
 @brief methods for env data
 */

- (NSString *)sdkVersion;
- (NSString *)appID;
- (NSString *)secretKey;

/*
 brief 是否测试服务器，是返回YES，暂时不对外提供测试服务器，只用于检测sdk服务器配置是否正确
 */
- (BOOL)isTestServer;

@end

