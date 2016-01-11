//
//  ZCPay.h
//  ZCPay
//
//  Created by 郭 旭 on 14/12/15.
//  Copyright (c) 2014年 郭 旭. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZCOrder.h"

@interface ZCPay : NSObject

+(void)productsForPay:(ZCOrder *)order
           withScheme:(NSString *)scheme
       withPrivateKey:(NSString *)key
         withSelector:(SEL)selector
           withTarget:(id)target;

+(void)orderWithPaymentResult:(NSURL *)url;

@end
