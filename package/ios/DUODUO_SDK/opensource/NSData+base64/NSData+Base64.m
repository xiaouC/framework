//
//  NSData+Base64.m
//  RKPlatformDemo
//
//  Created by erik on 14-5-13.
//  Copyright (c) 2014年 sunsea. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface NSData (Base64)

+ (NSData *)dataWithBase64EncodedString:(NSString *)string;
- (NSString *)base64EncodedStringWithWrapWidth:(NSUInteger)wrapWidth;
- (NSString *)base64EncodedString;
@end
