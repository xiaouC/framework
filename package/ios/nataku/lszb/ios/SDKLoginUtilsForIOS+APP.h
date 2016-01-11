//
//  SDKLoginUtilsForIOS+APP.h
//  lszb
//
//  Created by ratazzi on 3/6/15.
//
//

#import <Foundation/Foundation.h>
#import <Chartboost/Chartboost.h>
#import <Yunyue/StoreIAP.h>
#import "YunyueSDKIntegrateDelegate.h"
#import "SDKLoginUtilsForIOS.h"
#import "CCLuaObjcBridge.h"
#import <TalkingDataAppCpa/TalkingDataAppCpa.h>

USING_NS_CC;

@interface SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_APP) <YunyueSDKIntegrateDelegate, ChartboostDelegate>

@end
