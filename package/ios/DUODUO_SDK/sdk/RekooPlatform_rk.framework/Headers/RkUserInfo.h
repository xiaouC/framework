//
//  RkUserInfo.h
//  RekooUnifyPlatform_TW
//
//  Created by 梁 国伟 on 14-9-25.
//  Copyright (c) 2014年 梁 国伟. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RkUserInfo : NSObject

@property(nonatomic,strong)NSString *rkAccount; //用户名
@property(nonatomic,assign)NSInteger userType;  //用户类型 0：普通账户  1：游客账户  2:手机账户
@property(nonatomic,assign)NSInteger phone;     //是否绑定手机标志位   0未绑定  1绑定
@property(nonatomic,strong)NSString *rkpwd;     //加密后的密码
@property(nonatomic,strong)NSString *rkUid;     //uid
@property(nonatomic,strong)NSString *mobile;    //手机号
@property(nonatomic,strong)NSString *email;     //邮箱
@property(nonatomic,strong)NSString *token;
@property(nonatomic,strong)NSString *refresh_token;


@property(nonatomic,strong)NSString *userpwd;   //未加密的密码
//@property(nonatomic,copy)NSString *refresh_token;


+(RkUserInfo *)shareSingleton;

-(void)setvalueForDic:(NSDictionary *)dic;

-(void)clearUserInfo;

//更新账号信息
+(void)saveUserInfo:(NSDictionary *)dataDic;

//存储账户信息
//+(void )saveUserAccount:(NSString *)account andRkPwd:(NSString *)rkPwd;


@end
