//
//  GPGameSDK_Pay.h
//  GPGameSDK
//
//  Created by xuvance on 14-10-16.
//  Copyright (c) 2014年 vance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*
 @breif 订单支付结果类型
 */
typedef enum
{
    GPSDKPayResultCodeSucceed = 0,              //购买成功
    GPSDKPayResultCodePayForbidden = 1,         //购买被拒绝，账号问题
    GPSDKPayResultCodeNotEnough = 2,            //余额不足
    GPSDKPayResultCodePayHadFinished = 3,       //订单已经完成支付，重复购买同一张订单
    GPSDKPayResultCodeCancel = 4,               //用户取消购买
    GPSDKPayResultCodeServerError = 5,          //服务器处理失败或者网络问题,不用做任何处理
    GPSDKPayResultCodePayBackground = 6,        //后台轮训购买，如果退出app或者达到轮询次数则放弃订单
    GPSDKPayResultCodeBackgroundSucceed = 7,    //轮询购买成功
    GPSDKPayResultCodeBackgroundTimeOut = 8,    //轮询购买超时

    GPSDKPayResultCodeInitFailed = 100,         //初始化失败,不弹出购买界面

    GPSDKPayResultCodeOtherError = 1000,        //其他问题购买失败
}GPSDKPayResultCode;

/*
 @breif 这是一个订单
 */
@interface GPSDKGamePayment : NSObject

@property (strong) NSString *serialNumber; //订单唯一标识，sdk使用方生成订单唯一标识 必填
@property (strong) NSString *itemID;   //商品编号 必填
@property (strong) NSString *itemName; //商品名字  必填
@property (assign) float   itemPrice;  //单价，保留两位小数  第三位会四舍五入处理  必填
@property (assign) float   itemOrigPrice;  //原单价，保留两位小数  第三位会四舍五入处理
@property (assign) unsigned int itemCount; //购买个数,不填写默认为1个  必填
@property (strong) NSString *paymentDes;   //订单描述信息

@property (strong) NSString *reserved;   //透传字段

- (float)itemSum;//订单总金额
@end

/*
 @breif 这是一个订单结果
 */
@interface GPSDKGamePaymentResult : NSObject

@property (assign) GPSDKPayResultCode resultCode;  //订单支付结果
@property (strong) NSString *serialNumber;  //订单序列号

@end

@interface GPGameSDK_Pay : NSObject

+ (GPGameSDK_Pay *)defaultGPGamePay;


//跳转
//appScheme的值默认为appname-Info.plist中key为Bundle identifier 的value的值
@property (nonatomic, retain) NSString *appScheme;

/*
 @breif 异步发起订单, 异步函数，订单结果会以通知形式返回|GPGamePaymentResult|对象，并自动退出sdk支付界面
 @param aPayment 订单信息
 @param view 当前view
 @return 返回0正常进入sdk支付界面， 非0表示sdk支付环境异常，不允许支付，－1为登录有问题，－2为订单不合法
 */
- (int)asyncGPPay:(GPSDKGamePayment *)aPayment;

/*
 @breif 在appdelegate的 - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation方法调用
 @param url
 @return YES为处理了，NO为没处理
 */
- (BOOL)openUrlResponse:(NSURL *)url;

@end
