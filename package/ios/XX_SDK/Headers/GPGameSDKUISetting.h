//
//  GPGameSDKUISetting.h
//  GPGameSDK
//
//  Created by 陈列奋 on 12/9/14.
//  Copyright (c) 2014 vance. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GPGameSDKUISetting : NSObject

+ (GPGameSDKUISetting *)shareGPGameSDKUISetting;

//默认NO, 不需要设置，设置supportedIOs的时候为YES
@property (nonatomic, assign, readonly) BOOL hasSetSupportedIOs;

//SDK UI支持方向,不设置默认与项目工程设置一致
@property (nonatomic, assign) NSInteger supportedIOs;

//默认NO, 不需要设置，设置statusBarHidden的时候为YES
@property (nonatomic, assign, readonly) BOOL hasSetStatusBar;

//SDK 状态栏是否显示
@property (nonatomic, assign) BOOL statusBarHidden;

@end
