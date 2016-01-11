//
//  RKNetworkManager.h
//  RKGame
//
//  Created by 蔡 阳滨 on 13-5-28.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "QReachability.h"
typedef enum
{
    HTTP_GET,
    HTTP_POST_URLENCODED,
    HTTP_POST_MULTIPART,
    HTTP_PUT,
    HTTP_DELETE
}HTTP_REQUEST_METHOD;

@interface RKNetworkManager : NSObject<NSURLConnectionDataDelegate>
{
    NSMutableData *_data;
    BOOL isFinished;
    int _tag;
    void (^afinishCallbackBlock)(NSString *);
    BOOL _isNetworkConnect;
}
@property(nonatomic,assign)int tag;
@property(nonatomic,copy) void (^finishCallbackBlock)(NSString *);
@property(nonatomic,assign)BOOL isNetworkConnect;
-(void)sendMessageToBaseURL:(NSURL *)url WithParams:(NSDictionary *)params AndMethod:(HTTP_REQUEST_METHOD)requestMethod AndDataDictionary:(NSDictionary *)dataDict FinishCallbackBlock:(void (^)(NSString *))block;
@end
