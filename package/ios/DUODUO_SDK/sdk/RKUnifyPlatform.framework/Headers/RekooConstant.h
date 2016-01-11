//
//  ZYNotifications.h
//  RKPlatformDemo
//
//  Created by 杨争 on 7/11/14.
//  Copyright (c) 2014 sunsea. All rights reserved.
//

//#ifndef _ZYNotifications_H_
//#define _ZYNotifications_H_

//static NSString *const kRKSDKInitDidFinishedNotifications = @"kRKSDKInitDidFinishedNotifications";/**  初始化完成通知 **/
//static NSString *const kRKSDKLoginNotifications = @"kRKSDKLoginNotifications"; /** 登录完成通知 **/
//static NSString *const kRKPayFinishedNotifications = @"kRKPayFinishedNotifications";/** 支付完成通知 **/
//static NSString *const kRKLogoutFinishedNOtifications = @"kRKLogoutFinishedNOtifications"; /** 注销完成通知 **/
//static NSString *const kRKLeaveSDKNotifications = @"kRKLeaveSDKNotifications";/** 离开SDK页面 **/
//static NSString *const kRKClosePausePageFinishedNotifications = @"kRKClosePausePageFinishedNotifications";/** 离开暂停页面回调 **/

#ifndef RekooUnifyPlatform_RekooConstant_h
#define RekooUnifyPlatform_RekooConstant_h

#import <Foundation/Foundation.h>

//消息通知

#define KRKSDKInitDidFinish @"KRKSDKInitDidFinish"  //初始化完成通知
#define KRKSDKLogin @"KRKSDKLogin"                  //登录完成通知
#define KRKSDKPay @"KRKSDKPay"                      //支付结果通知
#define KRKSDKPauseDidExit @"KRKSDKPauseDidExit"    //暂停页退出通知
#define KRKLogout @"KRKLogout"                      //注销通知
#define KRKSDKLeave @"KRKSDKLeave"                  //离开SDK平台页面通知

#define KRKSDKCancelPay @"KRKSDKCancelPay"          //取消支付通知

#define KSuccess @"SUCCESS"
#define KFailed @"FAILED"
#define KUserCancel @"CANCEL"

#define REKOOUNIFYURL  @"http://message.rekoo.net"      // 正式服务

#endif