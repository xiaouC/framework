//
//  yhlmAppController.h
//  yhlm
//
//  Created by ratazzi on 11/11/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//

#import <MBProgressHUD/MBProgressHUD.h>
#import <Reachability/Reachability.h>

@class RootViewController;
@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate, UIApplicationDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
    MBProgressHUD *activityIndicator;
    Reachability *reachability;
}

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) RootViewController *viewController;
@property (nonatomic, retain) MBProgressHUD *activityIndicator;
@property (nonatomic, retain) Reachability *reachability;


@end

