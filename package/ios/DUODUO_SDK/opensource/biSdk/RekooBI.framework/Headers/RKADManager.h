//
//  RKADManager.h
//  iAd
//
//  Created by 蔡 阳滨 on 14-2-12.
//  Copyright (c) 2014年 sunsea. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <iAd/iAd.h>

@interface RKADManager : NSObject<ADBannerViewDelegate>

+(RKADManager *)defaultManager;
-(void)showADViewWithBaseUrlStr:(NSString *)baseUrlStr
                       AndAppID:(int)appID
                     AndVersion:(NSString *)version;

-(void)sendAdIdentifierWithBaseUrlStr:(NSString *)baseUrlStr
                             AndAppID:(int)appID
                           AndVersion:(NSString *)version;

-(NSString *)getNewUniqueIdentifier;
-(NSString *)getNewInterfaceUniqueIdentifier;

-(NSString *)getOldUniqueIdentifier;
@end
