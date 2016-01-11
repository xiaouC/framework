//
//  yhlmAppController.mm
//  yhlm
//
//  Created by ratazzi on 11/11/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "AppController.h"
#import "cocos2d.h"
#import "EAGLView.h"
#import "AppDelegate.h"
#include "MobClick.h"
#import "RootViewController.h"
#import "platform/share.h"
#include "CCLuaEngine.h"
#import <Crashlytics/Crashlytics.h>

USING_NS_CC;

#include "OPGameSDK.h"
#include "OPParam.h"
using namespace ourpalmpay;

#include "PlatformUtils.h"

@implementation AppController

@synthesize window;
@synthesize viewController;

#pragma mark -
#pragma mark Application lifecycle

// cocos2d application instance
static AppDelegate s_sharedApplication;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    // Override point for customization after application launch.

    // Add the view controller's view to the window and display.
    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    EAGLView *__glView = [EAGLView viewWithFrame: [window bounds]
                                     pixelFormat: kEAGLColorFormatRGBA8
                                     depthFormat: GL_DEPTH_COMPONENT16
                              preserveBackbuffer: NO
                                      sharegroup: nil
                                   multiSampling: NO
                                 numberOfSamples:0 ];

    // Use RootViewController manage EAGLView
    viewController = [[RootViewController alloc] initWithNibName:nil bundle:nil];
    viewController.wantsFullScreenLayout = YES;
    viewController.view = __glView;

    // Set RootViewController to window
    if ( [[UIDevice currentDevice].systemVersion floatValue] < 6.0)
    {
        // warning: addSubView doesn't work on iOS6
        [window addSubview: viewController.view];
    }
    else
    {
        // use this method on ios6
        [window setRootViewController:viewController];
    }
    
    application.applicationIconBadgeNumber = 0;
    
    [window makeKeyAndVisible];
    
    [[UIApplication sharedApplication] setStatusBarHidden: YES];
    
    NSString *channelId = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"GameKey"];
    [MobClick startWithAppkey:@"526b6e7856240b8ed10a0c58" reportPolicy:BATCH channelId:channelId];
    [MobClick updateOnlineConfig];

    InitParam* opInfo = new InitParam;
    opInfo->appId = [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"OPGameSDK_APP_ID"] integerValue];
    opInfo->appKey = [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"OPGameSDK_APP_KEY"] UTF8String];
    opInfo->gameKey = [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"OPGameSDK_GAME_KEY"] UTF8String];
    // for debug
    opInfo->debugModel = [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"OPGameSDK_DEBUG"] boolValue];
    opInfo->screenOrientation = 2;
    ourpalmpay::OPGameSDK::GetInstance().Init(viewController, opInfo);

    cocos2d::CCApplication::sharedApplication()->run();
    [Crashlytics startWithAPIKey:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CrashlyticsAPIKey"]];
    [Crashlytics sharedInstance].debugMode = [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CrashlyticsDebugMode"] boolValue];
    return YES;
}

-(BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url
{
    return [WXApi handleOpenURL:url delegate:self];
}

-(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    return [WXApi handleOpenURL:url delegate:self];
}

-(void) onReq:(BaseReq *)req
{
    if ([req isKindOfClass:[GetMessageFromWXReq class]])
    {
        
    }
}

-(void) onResp:(BaseResp *)resp
{
    if ([resp isKindOfClass:[SendMessageToWXReq class]])
    {
        // NSString *strMsg = [NSString stringWithFormat:@"errcode:%d", resp.errCode];
        int errCode = resp.errCode;
        CShare::onResult(CShare::SHARE_WXPENYOU, errCode);
    }
}

- (NSUInteger)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window
{
    return UIInterfaceOrientationMaskPortrait;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
    cocos2d::CCDirector::sharedDirector()->pause();
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
    cocos2d::CCDirector::sharedDirector()->resume();
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    /*
     Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
     If your application supports background execution, called instead of applicationWillTerminate: when the user quits.
     */
    cocos2d::CCApplication::sharedApplication()->applicationDidEnterBackground();
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    /*
     Called as part of  transition from the background to the inactive state: here you can undo many of the changes made on entering the background.
     */
    application.applicationIconBadgeNumber = 0;
    cocos2d::CCApplication::sharedApplication()->applicationWillEnterForeground();
}

- (void)applicationWillTerminate:(UIApplication *)application {
    /*
     Called when the application is about to terminate.
     See also applicationDidEnterBackground:.
     */
}

#pragma mark -
#pragma mark Memory management

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application {
    /*
     Free up as much memory as possible by purging cached data objects that can be recreated (or reloaded from disk) later.
     */
     cocos2d::CCDirector::sharedDirector()->purgeCachedData();
}


- (void)dealloc {
    [super dealloc];
}

//登录通知处理
- (void)loginNotification:(NSNotification *)notification
{
    NSLog(@"userId: %@", [notification.object objectForKey:@"userId"]);
    NSLog(@"userName: %@", [notification.object objectForKey:@"userName"]);
    NSLog(@"sessionId: %@", [notification.object objectForKey:@"sessionId"]);
    NSString* username = [notification.object objectForKey:@"userName"];
    NSString* sessionid = [notification.object objectForKey:@"sessionId"];
//    [SDKLoginUtilsForIOS loginItools:username : sessionid];

}

//注册通知处理
- (void)registerNotification:(NSNotification *)notification
{
    NSLog(@"userId: %@", [notification.object objectForKey:@"userId"]);
    NSLog(@"userName: %@", [notification.object objectForKey:@"userName"]);
    NSLog(@"sessionId: %@", [notification.object objectForKey:@"sessionId"]);
    NSString* username = [notification.object objectForKey:@"userName"];
    NSString* sessionid = [notification.object objectForKey:@"sessionId"];
//    [SDKLoginUtilsForIOS loginItools:username  : sessionid];
}

//注销通知处理
- (void)logoutNotification:(NSNotificationCenter *)notification
{
    NSLog(@"Logout");
//    [HXAppPlatformKitPro showLoginView]; //调出登录窗口
    CCLuaEngine::defaultEngine()->getLuaStack()->executeGlobalFunction( "logoutexplatform" );
    CCLuaEngine::defaultEngine()->getLuaStack()->executeGlobalFunction( "resetLogin" );
}

//关闭窗口通知处理
- (void)closeViewNotification:(NSNotification *)notification
{
    NSLog(@"SDK View Closed");
    CCLuaEngine::defaultEngine()->getLuaStack()->executeGlobalFunction( "hidepayloading" );
}

@end

