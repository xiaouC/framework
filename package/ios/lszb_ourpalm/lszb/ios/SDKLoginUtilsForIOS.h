#import <Foundation/Foundation.h>

@interface SDKLoginUtilsForIOS : NSObject

+ (void) start;
+ (void) enterPlatform;
+ (void) end;
+ (void) paymentDidPaying:(NSNotification*) notification;
+ (void) paymentDidFail:(NSNotification*) notification;
+ (void) regPayNotification;
+ (void) unregPayNotification;

+ (void) loginItools:(NSString*) username : (NSString*) sessionid;
+ (void) itoolsOpenPayInterface:(NSString*) itoolsserialNo : (float) money;
@end
