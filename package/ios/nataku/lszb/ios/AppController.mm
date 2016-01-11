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
#import "RootViewController.h"
#import "CCLuaEngine.h"
#import "PlatformUtils.h"
#import <Fabric/Fabric.h>
#import <Crashlytics/Crashlytics.h>


#ifdef YUNYUE_TARGET_APP
#import "SDKLoginUtilsForIOS+APP.h"
#endif

#ifdef YUNYUE_TARGET_AS
#import "SDKLoginUtilsForIOS+AS.h"
#endif

#ifdef YUNYUE_TARGET_IIAPPLE
#import "SDKLoginUtilsForIOS+IIAPPLE.h"
#endif

#ifdef YUNYUE_TARGET_ITOOLS
#import "SDKLoginUtilsForIOS+ITOOLS.h"
#endif

#ifdef YUNYUE_TARGET_PP
#import "SDKLoginUtilsForIOS+PP.h"
#endif

#ifdef YUNYUE_TARGET_TB
#import "SDKLoginUtilsForIOS+TB.h"
#endif

#ifdef YUNYUE_TARGET_KY
#import "SDKLoginUtilsForIOS+KY.h"
#endif

#ifdef YUNYUE_TARGET_HM
#import "SDKLoginUtilsForIOS+HM.h"
#endif

#ifdef YUNYUE_TARGET_XY
#import "SDKLoginUtilsForIOS+XY.h"
#endif

#ifdef YUNYUE_TARGET_DUODUO
#import "SDKLoginUtilsForIOS+DUODUO.h"
#endif

#ifdef YUNYUE_TARGET_XX
#import "SDKLoginUtilsForIOS+XX.h"
#endif

USING_NS_CC;

@implementation AppController

@synthesize window;
@synthesize viewController;
@synthesize reachability;

#ifdef YUNYUE_TARGET_APP
@synthesize activityIndicator;
#endif

#pragma mark -
#pragma mark Application lifecycle

// cocos2d application instance
static AppDelegate s_sharedApplication;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    // Override point for customization after application launch.
    if ([[UIApplication sharedApplication] respondsToSelector:@selector(registerUserNotificationSettings:)]) {
        UIUserNotificationType types = UIUserNotificationTypeBadge | UIUserNotificationTypeSound | UIUserNotificationTypeAlert;
        UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:types categories:nil];
        [[UIApplication sharedApplication] registerUserNotificationSettings:settings];
    }

    // Add the view controller's view to the window and display.
    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    EAGLView *__glView = [EAGLView viewWithFrame: [window bounds]
                                     pixelFormat: kEAGLColorFormatRGBA8
                                     depthFormat: GL_DEPTH_COMPONENT16
                              preserveBackbuffer: NO
                                      sharegroup: nil
                                   multiSampling: NO
                                 numberOfSamples: 0];

    // Use RootViewController manage EAGLView
    viewController = [[RootViewController alloc] initWithNibName:nil bundle:nil];
    viewController.wantsFullScreenLayout = YES;
    viewController.view = __glView;

    #ifdef YUNYUE_TARGET_APP
    activityIndicator = [[[MBProgressHUD alloc] initWithView:viewController.view] autorelease];
    [viewController.view addSubview:activityIndicator];
    #endif

    reachability = [Reachability reachabilityForInternetConnection];

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

    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0) {
        if ([[UIApplication sharedApplication] currentUserNotificationSettings].types & UIUserNotificationTypeBadge) {
            application.applicationIconBadgeNumber = 0;
        }
    } else {
        application.applicationIconBadgeNumber = 0;
    }

    [window makeKeyAndVisible];
    
    [[UIApplication sharedApplication] setStatusBarHidden: YES];

    cocos2d::CCApplication::sharedApplication()->run();

#ifdef YUNYUE_TARGET_APP
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(paymentDidFinished:)
                                                 name:kPaymentTransactionStatePurchasedNotification
                                               object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(paymentFailed:)
                                                 name:kPaymentTransactionStateFailedNotification
                                               object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(paymentWillStarting:)
                                                 name:kPaymentRequestProductStartingNotification
                                               object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(paymentFailed:)
                                                 name:kPaymentRequestProductFailedNotification
                                               object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(receiveExit:) name:@"EXIT_APPLICATION"
                                               object:nil];
#endif

    // {{{ Reachability
    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class]
                                             selector:@selector(reachabilityChanged:)
                                                 name:kReachabilityChangedNotification
                                               object:nil];
    [reachability startNotifier];
    // }}}

    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0
        && [[[UIDevice currentDevice] systemVersion] floatValue] < 8.3) {
        [self performSelectorInBackground:@selector(ExcResourceGenerate) withObject:nil];
    }

    if ([SDKLoginUtilsForIOS respondsToSelector:@selector(didFinishLaunchingWithOptions:rootViewController:)]) {
        [SDKLoginUtilsForIOS didFinishLaunchingWithOptions:launchOptions rootViewController:viewController];
    }

    [Fabric with:@[[Crashlytics class]]];

    return YES;
}

-(void) ExcResourceGenerate
{
    struct timespec tim, tim2;
 
    NSLog(@"ExcResource Generate Start");
 
    tim.tv_sec = 0;
    tim.tv_nsec = 1000;
 
    for(int i=0;i<(200*300);i++)
    {
        nanosleep(&tim,&tim2);
    }
 
    NSLog(@"ExcResource Generate End");
 
}

-(BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url
{
    if ([SDKLoginUtilsForIOS respondsToSelector:@selector(handleOpenURL:)]) {
        [SDKLoginUtilsForIOS handleOpenURL:url];
    }
    return YES;
}

-(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    if ([SDKLoginUtilsForIOS respondsToSelector:@selector(openURL:)]) {
        [SDKLoginUtilsForIOS openURL:url sourceApplication:sourceApplication annotation:annotation];
    }
    return YES;
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString *, id> *)options {
    if ([SDKLoginUtilsForIOS respondsToSelector:@selector(handleOpenURL:)]) {
        [SDKLoginUtilsForIOS handleOpenURL:url];
    }
    NSLog(@">>> iOS openURL");
    return YES;
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
    if ([SDKLoginUtilsForIOS respondsToSelector:@selector(applicationDidEnterBackground:)]) {
        [SDKLoginUtilsForIOS applicationDidEnterBackground:application];
    }
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    /*
     Called as part of  transition from the background to the inactive state: here you can undo many of the changes made on entering the background.
     */
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0) {
        if ([[UIApplication sharedApplication] currentUserNotificationSettings].types & UIUserNotificationTypeBadge) {
            application.applicationIconBadgeNumber = 0;
        }
    } else {
        application.applicationIconBadgeNumber = 0;
    }
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
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    [super dealloc];
}

- (void)receiveExit:(NSNotification *)notification {
    [UIView animateWithDuration:1.0f animations:^{
        window.alpha = 0;
        window.frame = CGRectMake( 0, window.bounds.size.width, 0, 0 );
    } completion:^( BOOL finished ) {
        exit( 0 );
    }];
}

#pragma mark -
#pragma mark IAP activityIndicator

#ifdef YUNYUE_TARGET_APP
- (void)paymentWillStarting:(NSNotification *)notification {
    NSLog(@">>> startAnimating");
    viewController.view.userInteractionEnabled = NO;
    [activityIndicator show:YES];
}

- (void)paymentFailed:(NSNotification *)notification {
    NSLog(@">>> stopAnimating");
    viewController.view.userInteractionEnabled = YES;
    [activityIndicator hide:YES];
}

- (void)paymentDidFinished:(NSNotification *)notification {
    viewController.view.userInteractionEnabled = YES;
    [activityIndicator hide:YES];

    NSLog(@"notification: %@", notification);
}
#endif

@end

