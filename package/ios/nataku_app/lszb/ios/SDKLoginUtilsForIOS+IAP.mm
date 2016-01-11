//
//  SDKLoginUtilsForIOS+IAP.m
//  lszb
//
//  Created by ratazzi on 3/6/15.
//
//

#import "SDKLoginUtilsForIOS+IAP.h"
#import "ZCPay.h"
#import "ZCOrder.h"

#define CPPrivKey @"MIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBAOUust2OfurxzdifqELDYBBM44tUmqa/Sfqn90MkrjpORe78BuiUU25+JWzxizrgLgSicjH/RHZvWZs2CcZ7v2Q+cjlbMeqth/rDk5p2HW0jpEohkguwKt+2RenPTHzvRhLQ0bdYpYVQN6g8qPOVkkd1rsSVaz69PF5ENljJyw3JAgMBAAECgYEAvTRtdF4Ex8Ay+ejtR5j2gN6JaGjDeHAqCiaLCsKImBgwwhkNNwvlSS4ZhbRwBn43X5og/sfIZKKO7oWRUmytVuubR9eXsKTZGnrN8HgxEvGhlDoEBFu1GoEMmrD+XMAMsC2kKBgxjy315Ildz9LXB8tBMh1FjlQWJIXWUOMiSXUCQQD9uY34hHDFn5Fu1cLTRn8xk0vYjQzYp7FUty5k5CUMGhuSG4jXUJBHDoeXla51vyF74Qq1DOSQW6hVDMeSSa7XAkEA5zzOGfOLYbQhkD5SP6UdfBjeBJ6Em8i0lyuM/xTxEHgs9x8x2UdVUy0BSaVkrjxC4SInaM3ZIQN5o+rdvhy0XwJBANkT03KnpXB/eEdSnjBy5Un+EutAqpgGyUKIwynQxB2ZjLMx2Z8WL4qL1NiNWMkm8LfzL1z9neQgd2Hk4C652dsCQCAkramh1yAvv/KjFx/NvfmAI2yU9G4LSj8xSJo0uQXHDskTRwSjC9NSEDnCiepGai2NZ9kDtEkIiKImhchliRUCQHRacVqhfPqVjmx9HugQt1FvDnq1T+nKsYImZSKYi8oGGItXOX+alRIcflOWZk3zUpNO2Sbdx9LaugznUlYzib8="

NSInteger receipt_validation_delegate = -1;

@implementation SDKLoginUtilsForIOS (SDKLoginUtilsForIOS_IAP)

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

    // 如果产品 ID 不等于金额则使用 App Store IAP，否则走支付宝
    if (![[payload objectForKey:@"product_id"] isEqualToString: [payload objectForKey:@"amount"]]) {
        [[StoreIAP sharedInstance] purchase:[payload objectForKey:@"product_id"]];
    } else {
        NSURL *url = [NSURL URLWithString:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"ZC_PAYMENT_NOTIFY_URL"]];
        url = [url URLByAppendingPathComponent:[[payload objectForKey:@"worldID"] stringValue]
                                                   isDirectory:NO];
        url = [url URLByAppendingPathComponent:[payload objectForKey:@"transaction_id"]
                                                   isDirectory:NO];

        NSLog(@"URL: %@", [url absoluteString]);

        ZCOrder *order = [[[ZCOrder alloc] init] autorelease];
        order.channel = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"ZC_PAYMENT_CHANNEL"];
        order.appid = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"ZC_PAYMENT_APP_ID"];
        order.userid = [payload objectForKey:@"entityID"];
        order.productName = [payload objectForKey:@"product_name"];
        NSString *bundle_name = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"];
        order.productDescription = [NSString stringWithFormat:@"%@%@", bundle_name, [payload objectForKey:@"product_name"]];
        order.price = [NSString stringWithFormat:@"%@.00", [payload objectForKey:@"amount"]];
        order.notifyURL = [url absoluteString];

        //    NSString *orderSpec = [order description];
        //    NSLog(@"orderSpec = %@",orderSpec);

        [ZCPay productsForPay:order
                   withScheme:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"ZC_PAYMENT_URL_SCHEME"]
               withPrivateKey:CPPrivKey
                 withSelector:@selector(payResult:)
                   withTarget:[SDKLoginUtilsForIOS class]];
    }
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
#pragma mark ZCPaySDK
+ (void)payResult:(NSDictionary *)dic
{
    NSLog(@"msg = %@,ret = %@", [dic objectForKey:@"msg"], [dic objectForKey:@"ret"]);
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
