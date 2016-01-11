//
//  SDKLoginUtilsForIOS+HXAppPlatformKitPro.h
//  lszb
//
//  Created by ratazzi on 12/3/14.
//
//

#import <Foundation/Foundation.h>
#import "SDKLoginUtilsForIOS.h"
#import "CCLuaObjcBridge.h"
#import "YunyueSDKIntegrateDelegate.h"
#import "KYSDK.h"

USING_NS_CC;

@interface SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_KYSDK) <YunyueSDKIntegrateDelegate, KYSDKDelegate>

@end
