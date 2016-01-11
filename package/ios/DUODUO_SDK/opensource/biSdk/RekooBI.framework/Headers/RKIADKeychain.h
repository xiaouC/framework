//
//  RKIADKeychain.h
//  test
//
//  Created by 蔡 阳滨 on 14-2-10.
//  Copyright (c) 2014年 sunsea. All rights reserved.
//

#import <Foundation/Foundation.h>
#define RK_KEY_DEVICE_IDENTIFIER_PASSWORD @"com.rekoo.app.deviceidentifierpassword"
#define RK_KEY_IDFV @"com.rekoo.app.idfv"
#define RK_KEY_MAC @"com.rekoo.app.mac"
#define RK_KEY_IDFA @"com.rekoo.app.idfa"
#define RK_KEY_IDENTIFIER @"com.rekoo.app.identifier"
//NSString * const RK_KEY_IDFV_PASSWORD = @"com.rekoo.app.idfvpassword";
//NSString * const RK_KEY_IDFV = @"com.rekoo.app.idfv";
@interface RKIADKeychain : NSObject
+ (void)save:(NSString *)service data:(id)data;
+ (id)load:(NSString *)service;
+ (void)delete:(NSString *)service;
@end
