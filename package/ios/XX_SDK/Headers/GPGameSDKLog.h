//
//  GPGameSDKLog.h
//  GPGameSDK_Demo
//
//  Created by 陈列奋 on 11/12/14.
//  Copyright (c) 2014 vance. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GPGameSDKLog : NSObject

+ (GPGameSDKLog *)shareGPGameSDKLog;

@property (nonatomic, assign) BOOL enableLog;//默认关闭,NO

//写log到Document目录下的kGPGameSDKLog.log文件
- (void)writeLog:(NSString *)string;

//删除kGPGameSDKLog.log文件
- (void)deleteLogFile;

//kGPGameSDKLog.log文件路径
- (NSString *)logFilePath;
@end
