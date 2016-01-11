//
//  YunyueSDKIntegrateDelegate.h
//  for CCLuaObjcBridge
//
//  Created by ratazzi on 12/3/14.
//
//

#ifndef lszb_YunyueSDKIntegrateDelegate_h
#define lszb_YunyueSDKIntegrateDelegate_h

@protocol YunyueSDKIntegrateDelegate <NSObject>

@required

+ (void)purchase:(NSDictionary *)payload;

@optional

+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions rootViewController:(UIViewController *)rootViewController;
+ (void)handleOpenURL:(NSURL *)url;
+ (BOOL)openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
+ (void)applicationDidEnterBackground:(UIApplication *)application;
+ (void)applicationWillEnterForeground:(UIApplication *)application;

+ (void)login:(NSDictionary *)payload;
+ (void)logout:(NSDictionary *)payload;
+ (void)platform:(NSDictionary *)payload;

@end

#endif
