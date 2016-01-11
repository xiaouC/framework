//
//  DeviceMessage.h
//  rekooPlatform
//
//  Created by 蔡 阳滨 on 13-4-8.
//  Copyright (c) 2013年 sunsea. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#define RK_DEVICEIDENTIFIER_IDFV_KEY @"rk_deviceidentifier_idfv_key"
#define RK_DEVICEIDENTIFIER_MAC_KEY  @"rk_deviceidentifier_mac_key"
@interface RKIADDDeviceIdentifier : NSObject

+(NSDictionary *)getDeviceIdentifier;
+(NSString *)getUniqueIdentifier;
//mac_idfa_idfv
+(NSString *)getNewUniqueIdentifier;
+(NSString *) macaddress;
+(NSString *)idfv;
+(NSString *)idfa;
@end
