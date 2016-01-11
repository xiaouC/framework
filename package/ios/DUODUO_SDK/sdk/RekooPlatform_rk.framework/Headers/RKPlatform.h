//
//  RKPlatform.h
//  RKPlatformSourse_2.1
//
//  Created by 梁 国伟 on 14-10-13.
//  Copyright (c) 2014年 梁 国伟. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RkMacroDefinition.h"
#import "RkUserInfo.h"

// SDK Version 3.0.1

@class RkMainViewController;



@interface RKPlatform : NSObject
{
}

//@property (nonatomic, assign) NSInteger btnType; // 1 点击登录 2 点击支付
/**
 *  获取RKPlatform
 */
+(RKPlatform *)defaultPlatform;

/**
 *  初始化
 */
-(void)RKInit;


-(void)RKHandleAliPay:(NSURL*) aliURL;

/**
 *  登录
 */
-(BOOL)RKLogin;
//-(BOOL)RKLoginWithType:(NSInteger)type;
/**
 *  退出
 */
-(void)RKLogout;

/**
 *  支付
 */
-(void)RKPay:(float)price
    AndTitle:(NSString *)title
     AndDesc:(NSString *)desc
  AndOrderID:(NSString *)orderid
AndProductId:(NSString *)productId
    AndCpext:(NSString *)cpext;

- (RkUserInfo *)getUserInfo;

- (void)payBindAccount;

@end
