//
//  SDKLoginUtilsForIOS+APP.m
//  lszb
//
//  Created by ratazzi on 3/6/15.
//
//

#import "SDKLoginUtilsForIOS+APP.h"

NSInteger receipt_validation_delegate = -1;

@implementation SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_APP)

#pragma mark YunyueSDKIntegrateDelegate

+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions rootViewController:(UIViewController *)rootViewController {
    if ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CHARTBOOST_APP_ID"] != nil) {
        NSLog(@">>> Chartboost is enabled.\n");
        [Chartboost startWithAppId:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CHARTBOOST_APP_ID"]
                      appSignature:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CHARTBOOST_APP_SIGNATURE"]
                          delegate:[SDKLoginUtilsForIOS class]];
        [Chartboost showInterstitial:CBLocationHomeScreen];
    } else {
        NSLog(@">>> Chartboost is not enabled.\n");
    }

    [TalkingDataAppCpa init:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"TALKINGDATA_APP_ID"]
              withChannelId:@"AppStore"];
}

+ (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    return YES;
}

+ (void) afterLogin: (NSDictionary *)payload {
    NSString *entityID = [payload objectForKey:@"entityID"];
    NSString *bundle_id = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"];
    NSString *domain = [NSString stringWithFormat:@"%@.%@", bundle_id, entityID];

    [[StoreIAP sharedInstance] setCallbackUsingBlock:^BOOL(NSString *identifier, NSString *receipt) {
        // save receipt to keychain
        [[StoreIAP sharedInstance] saveReceipt:domain identifier:identifier receipt:receipt];

        NSDictionary *payload = @{@"transaction_id": identifier, @"receipt": [[receipt dataUsingEncoding:NSUTF8StringEncoding] base64EncodedStringWithOptions:0]};
        NSData *data = [NSJSONSerialization dataWithJSONObject:payload options:NSJSONWritingPrettyPrinted error:nil];
        NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];
        platform_callback(CB_ITUNES_IAP_VALIDATION, [json UTF8String]);
        return YES;
    }];

    // retry send local receipts
    NSLog(@">>> Read local receipts for [%@]: %@", domain, [[[StoreIAP sharedInstance] receipts:domain] allKeys]);
    [[[StoreIAP sharedInstance] receipts:domain] enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
        NSDictionary *payload = @{@"transaction_id": key, @"receipt": [[obj dataUsingEncoding:NSUTF8StringEncoding] base64EncodedStringWithOptions:0]};
        NSData *data = [NSJSONSerialization dataWithJSONObject:payload options:NSJSONWritingPrettyPrinted error:nil];
        NSString *json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];
        platform_callback(CB_ITUNES_IAP_VALIDATION, [json UTF8String]);

    }];
}

+ (void) purchase: (NSDictionary *)payload {
    NSLog(@">>> purchase: %@\n", payload);
    [[StoreIAP sharedInstance] purchase:[payload objectForKey:@"product_id"]];
}

+ (void) deleteReceipt: (NSDictionary *)payload {
    NSString *entityID = [payload objectForKey:@"entityID"];
    NSString *bundle_id = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"];
    NSString *domain = [NSString stringWithFormat:@"%@.%@", bundle_id, entityID];
    NSString *transaction_id = [payload objectForKey:@"transaction_id"];

    NSLog(@">>> Delete local receipts for [%@]: %@", domain, transaction_id);
    [[StoreIAP sharedInstance] deleteReceipt:domain identifier:transaction_id];
}

#pragma mark -
#pragma mark Chartboost
+ (BOOL)shouldRequestInterstitialsInFirstSession {
    return NO;
}

#pragma mark -
#pragma mark Talkingdata AdTracking
+ (void)onRegister:(NSDictionary *)payload {
    NSLog(@">>> onRegister: %@", payload);
    [TalkingDataAppCpa onRegister:[payload objectForKey:@"username"]];
}

+ (void)onLogin:(NSDictionary *)payload {
    NSLog(@">>> onLogin: %@", payload);
    [TalkingDataAppCpa onLogin:[payload objectForKey:@"username"]];
}
@end
