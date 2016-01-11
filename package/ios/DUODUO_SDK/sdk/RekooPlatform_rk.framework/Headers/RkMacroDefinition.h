//
//  RkMacroDefinition.h
//  RekooUnifyPlatform_TW
//
//  Created by BergpoonMac on 14-9-23.
//  Copyright (c) 2014年 BergpoonMac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


#define isiPhone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define KDeviceWidth [UIScreen mainScreen].bounds.size.width//屏幕宽度
#define KDeviceHeight [UIScreen mainScreen].bounds.size.height//屏幕高度
#define KDeviceOrientation  [UIApplication sharedApplication].statusBarOrientation//屏幕方向

#define kRKSDKInitDidFinishedNotifications  @"kRKSDKInitDidFinishedNotifications"/**  初始化完成通知 **/
#define kRKSDKLoginNotifications  @"kRKSDKLoginNotifications"/** 登录完成通知 **/
#define kRKPayFinishedNotifications @"kRKPayFinishedNotifications"/** 支付完成通知 **/
#define kRKCancelPayFinishedNotifications @"kRKCancelPayFinishedNotifications"/** 取消支付通知 **/
#define kRKLogoutFinishedNOtifications  @"kRKLogoutFinishedNOtifications" /** 注销完成通知 **/
#define kRKLeaveSDKNotifications  @"kRKLeaveSDKNotifications"/** 离开SDK页面 **/
#define kRKClosePausePageFinishedNotifications  @"kRKClosePausePageFinishedNotifications"/** 离开暂停页面回调 **/

#define SUCCESS  @"SUCCESS"/** 成功 **/
#define FAIL  @"FAILED" /** 失败 **/
#define CANCEL  @"CANCEL"/** 取消 **/


#define USERARR   @"RKUserArr"

#define VISITOR_DIC  @"visitorMessageDic"

#define RKFastAccount @"RKFastAccount"
#define RKFastPassword @"RKFastPassword"
#define RKFastUserType @"RKFastUserType"

#define RKFastUid      @"RKFastUid"
/**
 *  Boundle
 */

//obtain resource bundle
#define RK_RESOURCE_BUNDLE LOC_BUNDLE==0?[NSBundle mainBundle]:[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"RekooResource" ofType:@"bundle"]]

//0从本地读取资源  1从自带Bundle读取资源
#define LOC_BUNDLE 1
#define BUNDLE LOC_BUNDLE==0?nil:[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"RekooResource" ofType:@"bundle"]]

//0从项目读取字符  1从自带Bundle读取字符串
#define LOC_STRING 1

#define LPROJ_BUNDLE LOC_STRING==0?nil:[NSBundle bundleWithPath:[[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"RekooResource" ofType:@"bundle"]] pathForResource:@"zh" ofType:@"lproj"]]

#define LOC_TEXT(str) LOC_STRING==0?NSLocalizedStringFromTable(@(#str), @"RKPFLocalizable", nil):NSLocalizedStringFromTableInBundle(@(#str), @"RKPFLocalizable", LPROJ_BUNDLE, nil)

#define IMAGE_PATH(imageName) LOC_STRING==0?[[NSBundle mainBundle] pathForResource:@#imageName ofType:@"png"]:[[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"RekooResource" ofType:@"bundle"]] pathForResource:@#imageName ofType:@"png"]

#define LOC_TEXTCON(str) LOC_STRING==0?[[NSBundle mainBundle] pathForResource:@#str ofType:@"txt"]:[[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"RekooResource" ofType:@"bundle"]] pathForResource:@#str ofType:@"txt"]



/**
 *  根据语言环境设置业务逻辑切换
 *  82 韩国
 *  86 中国
 */
typedef NS_ENUM(NSInteger, Language)
{
    Korea_Language=82,
    China_language=86
};


#define language 86

//#if language==82

//#define RK_SDK_VERSION @"1.7.2.82"      //韩国天天幻想版本，只能绑定邮箱
//#else
//#define RK_SDK_VERSION @"2.0"         //
//#endif

/**
 *  iPad情况下显示框大小
 */
#define  RK_IPAD_VIEW_FRAME CGRectMake(0, 0, 480, 320)
#define  RK_IPAD_VIEW_LANDSCAPE_CENTER CGPointMake(512,368)
#define  RK_IPAD_VIEW_PORTRAIT_CENTER CGPointMake(368,512)


/*
 *  正式环境
 *  测试环境
 *  内网环境切换
 */
//#define Domainname 86
//
//#if Domainname==82
//#define baseUrl @"http://jieru.korea.lohaa.com/" //韩国
//#endif
//
//#if Domainname==86
//#define baseUrl @"http://i.lohaa.com/" //正式
//#endif


