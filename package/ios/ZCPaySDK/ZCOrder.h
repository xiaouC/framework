//
//  ZCOrder.h
//  mypaydemo
//
//  Created by 郭 旭 on 14/12/13.
//  Copyright (c) 2014年 郭 旭. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZCOrder : NSObject

@property(nonatomic, copy) NSString * channel;
@property(nonatomic, copy) NSString * appid;
@property(nonatomic, copy) NSString * productName;
@property(nonatomic, copy) NSString * productDescription;
@property(nonatomic, copy) NSString * userid;
@property(nonatomic, copy) NSString * notifyURL;
@property(nonatomic, copy) NSString * price;

@property(nonatomic, readonly) NSMutableDictionary * extraParams;

@end
