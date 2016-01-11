#import <Foundation/Foundation.h>
#import "CCLuaObjcBridge.h"
#import "SDKCallback.h"

@interface SDKLoginUtilsForIOS : NSObject

+ (void) start;
+ (void) enterPlatform;
+ (void) end;
@end
