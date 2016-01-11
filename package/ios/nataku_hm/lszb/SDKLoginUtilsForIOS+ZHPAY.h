//
//  SDKLoginUtilsForIOS+ZHPAY.h
//  lszb
//
//  Created by ratazzi on 12/3/14.
//
//

#import <Foundation/Foundation.h>
#import "SDKLoginUtilsForIOS.h"
#import "CCLuaObjcBridge.h"
#import "YunyueSDKIntegrateDelegate.h"
#import <ZHPay/ZHPayPlatform.h>

USING_NS_CC;

@interface SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_ZHPAY) <YunyueSDKIntegrateDelegate, ZHPayCheckDelegate, ZHPayDelegate, ZHPayResultDelegate>

@end
