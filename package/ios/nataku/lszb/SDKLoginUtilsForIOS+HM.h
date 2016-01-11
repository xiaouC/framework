#import <Foundation/Foundation.h>
#import "YunyueSDKIntegrateDelegate.h"
#import "SDKLoginUtilsForIOS.h"
#import "CCLuaObjcBridge.h"
#import <ZHPay/ZHPayPlatform.h>

USING_NS_CC;

@interface SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_HM) <YunyueSDKIntegrateDelegate, ZHPayCheckDelegate, ZHPayDelegate, ZHPayResultDelegate>

@end
