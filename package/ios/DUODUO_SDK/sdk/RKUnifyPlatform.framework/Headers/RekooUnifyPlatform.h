//
//  RekooUnifyPlatform.h
//  RKPlatformDemo
//
//  Created by 杨争 on 7/18/14.
//  Copyright (c) 2014 sunsea. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RekooConstant.h"
#import "RKProductInfo.h"





@interface RekooUnifyPlatform : NSObject

+(id)getInstance;

//2.1.0以下接口必须接入(1,2,3,4,6)

/*
 *  1.初始化
 */
-(void)rkInit;


/*
 *  2.登陆
 */
//-(void)rkLogin;
- (void)rkLogin;

/*
 *  3.注销账户
 */
-(void)rkLogout;


/*
 *  4.支付
 */
-(void)rkPayWithProductInfo:(RKProductInfo*)productInfo;


/*
 *  5.程序暂停
 *  热酷2.1.0无需接入此接口
 */
-(void)rkOnPause;


/*
 *  6.处理支付宝回调数据
 */
-(void)rkHandleUrl:(NSURL*)url;


/*
 *  7.开打或关闭悬浮窗
 *  热酷2.0版本后SDK没有悬浮窗
 *  此接口无效
 */
- (void)showCenter;

@end
