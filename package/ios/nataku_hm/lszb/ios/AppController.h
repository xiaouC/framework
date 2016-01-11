//
//  yhlmAppController.h
//  yhlm
//
//  Created by ratazzi on 11/11/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//

@class RootViewController;
@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
}

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) RootViewController *viewController;

@end

