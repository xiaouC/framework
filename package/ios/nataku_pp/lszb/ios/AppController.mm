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
#import <Crashlytics/Crashlytics.h>

USING_NS_CC;

#import "PlatformUtils.h"
#import "SDKLoginUtilsForIOS+PPAppPlatformKit.h"

@implementation AppController

@synthesize window;
@synthesize viewController;
@synthesize reachability;

#pragma mark -
#pragma mark Application lifecycle

// cocos2d application instance
static AppDelegate s_sharedApplication;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    // Override point for customization after application launch.
    if ([[UIApplication sharedApplication] respondsToSelector:@selector(registerUserNotificationSettings:)]) {
        UIUserNotificationType types = UIUserNotificationTypeBadge |UIUserNotificationTypeSound | UIUserNotificationTypeAlert;
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
                                 numberOfSamples:0 ];

    // Use RootViewController manage EAGLView
    viewController = [[RootViewController alloc] initWithNibName:nil bundle:nil];
    viewController.wantsFullScreenLayout = YES;
    viewController.view = __glView;

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

    // {{{ Reachability
    [[NSNotificationCenter defaultCenter] addObserver:[SDKLoginUtilsForIOS class]
                                             selector:@selector(reachabilityChanged:)
                                                 name:kReachabilityChangedNotification
                                               object:nil];
    [reachability startNotifier];
    // }}}

    if ([SDKLoginUtilsForIOS respondsToSelector:@selector(didFinishLaunchingWithOptions:rootViewController:)]) {
        [SDKLoginUtilsForIOS didFinishLaunchingWithOptions:launchOptions rootViewController:viewController];
    }

    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0 && [[[UIDevice currentDevice] systemVersion] floatValue] < 8.3) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            struct timespec tim, tim2;

            NSLog(@"ExcResource Generate Start");

            tim.tv_sec = 0;
            tim.tv_nsec = 1000;

            for(int i=0;i<(200*300);i++)
            {
                nanosleep(&tim,&tim2);
            }

            NSLog(@"ExcResource Generate End");
        });
    }

    [Crashlytics startWithAPIKey:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CrashlyticsAPIKey"]];
    [Crashlytics sharedInstance].debugMode = [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CrashlyticsDebugMode"] boolValue];

    return YES;
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
    if ([SDKLoginUtilsForIOS respondsToSelector:@selector(handleOpenURL:)]) {
        [SDKLoginUtilsForIOS handleOpenURL:url];
    }
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
    application.applicationIconBadgeNumber = 0;
    cocos2d::CCApplication::sharedApplication()->applicationWillEnterForeground();
    if ([SDKLoginUtilsForIOS respondsToSelector:@selector(applicationWillEnterForeground:)]) {
        [SDKLoginUtilsForIOS applicationWillEnterForeground:application];
    }
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
    [[NSNotificationCenter defaultCenter] removeObserver:[SDKLoginUtilsForIOS class]];
    [super dealloc];
}

@end

