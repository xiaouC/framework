//
//  yhlmAppController.h
//  yhlm
//
//  Created by ratazzi on 11/11/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//

#import <Reachability/Reachability.h>

#ifdef YUNYUE_TARGET_APP
#import <MBProgressHUD/MBProgressHUD.h>
#endif

@class RootViewController;
@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate, UIApplicationDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
    Reachability *reachability;
    #ifdef YUNYUE_TARGET_APP
    MBProgressHUD *activityIndicator;
    #endif
}

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) RootViewController *viewController;
@property (nonatomic, retain) Reachability *reachability;
#ifdef YUNYUE_TARGET_APP
@property (nonatomic, retain) MBProgressHUD *activityIndicator;
#endif


@end

