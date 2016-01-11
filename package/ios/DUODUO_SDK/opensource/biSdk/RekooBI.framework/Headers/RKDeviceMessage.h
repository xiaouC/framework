//
//  DeviceMessage.h
//  rekooPlatform
//
//  Created by 蔡 阳滨 on 13-4-8.
//  Copyright (c) 2013年 sunsea. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AdSupport/AdSupport.h>
#import <UIKit/UIKit.h>
#import "QReachability.h"

@interface RKDeviceMessage : NSObject
+(NSString *) macaddress;
+(NSString *) platformString;
+(NSString *) timeString;
+(NSString *) systemVersion;
+(NSString *) screenResolution;
+(NSString *) networkString;
+(NSString *) adUid;
@end
