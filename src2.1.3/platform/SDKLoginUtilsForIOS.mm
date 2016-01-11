#import "SDKLoginUtilsForIOS.h"
#import <Foundation/NSString.h>
#include "sdk.h"

#include "CCString.h"
#include "CCLuaEngine.h"
#import "SDKCallback.h"
#import <Reachability/Reachability.h>

USING_NS_CC;

NSInteger reachability_changed_delegate = -1;

framework::SDKType GetSdkType()
{
    int sdktype = [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"SdkType"] intValue];
	return framework::SDKType(sdktype);
}

@implementation SDKLoginUtilsForIOS

+ (void)start {
}

+ (void)end {
}

+ (void) enterPlatform {
}

+ (void)setReachabilityDelegate:(NSDictionary *)payload {
    if (reachability_changed_delegate != -1) {
        CCLuaObjcBridge::releaseLuaFunctionById(reachability_changed_delegate);
    }
    reachability_changed_delegate = [[payload objectForKey:@"delegate"] integerValue];
}

+ (void)reachabilityChanged:(NSNotification *)notification {
    NSLog(@">>> reachabilityChanged");
    Reachability *reachability = [Reachability reachabilityForInternetConnection];
    platform_callback(CB_REACHABILITY_CHANGED, [[reachability currentReachabilityString] UTF8String]);

}

@end
