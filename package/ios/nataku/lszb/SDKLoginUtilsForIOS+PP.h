#import <Foundation/Foundation.h>
#import "YunyueSDKIntegrateDelegate.h"
#import "SDKLoginUtilsForIOS.h"
#import "CCLuaObjcBridge.h"
#import "PPAppPlatformKit/PPAppPlatformKit.h"

USING_NS_CC;

@interface SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_PP) <YunyueSDKIntegrateDelegate, PPAppPlatformKitDelegate>

@end
