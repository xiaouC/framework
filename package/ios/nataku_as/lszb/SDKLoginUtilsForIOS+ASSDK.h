//
//  SDKLoginUtilsForIOS+ASSDK.h
//  lszb
//
//  Created by ratazzi on 12/3/14.
//
//

#import <Foundation/Foundation.h>
#import "SDKLoginUtilsForIOS.h"
#import "CCLuaObjcBridge.h"
#import "YunyueSDKIntegrateDelegate.h"
#import <AsInfoKit.h>
#import <AsPlatformSDK.h>

USING_NS_CC;

@interface SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_ASSDK) <YunyueSDKIntegrateDelegate, AsPlatformSDKDelegate>

@end
