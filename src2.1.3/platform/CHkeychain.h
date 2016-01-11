//
//  CHkeychain.h
//  lll215
//
//  Created by ratazzi on 11/7/13.
//
//

#import <Foundation/Foundation.h>
#import <Security/Security.h>

@interface CHkeychain : NSObject
+ (void) save: (NSString *) service data:(id)data;
+ (id) load: (NSString *) service;
+ (void) delete: (NSString *)service;

@end
