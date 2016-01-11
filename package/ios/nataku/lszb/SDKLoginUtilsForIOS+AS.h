//
//  SDKLoginUtilsForIOS+AS.h
//  lszb
//
//  Created by ratazzi on 12/3/14.
//
//

#import <Foundation/Foundation.h>
#import "SDKLoginUtilsForIOS.h"
#import "CCLuaObjcBridge.h"
#import "YunyueSDKIntegrateDelegate.h"
#import <AsSdkFMWK/AsInfoKit.h>
#import <AsSdkFMWK/AsPlatformSDK.h>

USING_NS_CC;

@interface SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_AS) <YunyueSDKIntegrateDelegate, AsPlatformSDKDelegate>

@end
