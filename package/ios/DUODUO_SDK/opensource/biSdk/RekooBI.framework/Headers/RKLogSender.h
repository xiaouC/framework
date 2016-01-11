//
//  RKLogSender.h
//  StatisticsTest
//
//  Created by 蔡 阳滨 on 13-8-26.
//
//

#import <Foundation/Foundation.h>
#import "QReachability.h"

@interface RKLogSender : NSObject
{
    dispatch_queue_t _queue;
}

@property(nonatomic,assign) dispatch_queue_t queue;

+(id)shareRKLogSender;


- (void)runDisposeAThreadWithUrl:(NSString *)url;


@end
