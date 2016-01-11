//
//  RKProductInfo.h
//  RekooUnifyPlatform_91
//
//  Created by 梁 国伟 on 14-11-19.
//  Copyright (c) 2014年 LazyYang. All rights reserved.
//

#import <Foundation/Foundation.h>

//游戏角色信息
@interface RKMProductionInfo : NSObject
@property(nonatomic, copy)NSString* role_Id;//游戏角色id
@property(nonatomic, copy)NSString* role_Name;//游戏角色名称
@property(nonatomic, copy)NSString* role_Grade;//游戏角色等级
@property(nonatomic, copy)NSString* role_Balance;//用户游戏内虚拟币余额，如元宝，金币，符石
@property(nonatomic, copy)NSString* role_Vip;//角色vip等级
@property(nonatomic, copy)NSString* role_UserParty;//角色所在公会
@property(nonatomic, copy)NSString* server_Name;//角色所在服务器

+(RKMProductionInfo*)getRKMProductionInfo:(NSString *)roleId
                        andRoleName:(NSString *)roleName
                       andRoleGrade:(NSString *)roleGrade
                     andRoleBalance:(NSString *)roleBalance
                         andRoleVip:(NSString *)roleVip
                   andRoleUserParty:(NSString *)roleUserPArty
                      andServerName:(NSString *)serverName;

@end

@interface RKProductInfo : NSObject

//购买商品描述

@property(nonatomic, copy)NSString*     orderID;                    //订单号，双方对账的唯一标记（必须唯一）
@property (nonatomic, copy) NSString *  productId;				//商品Id
@property (nonatomic, copy) NSString *  productName;				//商品名字
@property (nonatomic, assign) float     productPrice;				//商品价格
@property (nonatomic, assign) unsigned int productCount;		//购买商品个数
@property (nonatomic, copy) NSString *  payDescription;			//购买描述，可选，没有为空
@property (nonatomic,copy)NSString *    userServer;                 //服务器id，没有传入@""
@property(nonatomic,copy)NSString *     extInfo;                     //扩展字段，没有传入@""

@property(nonatomic,retain )RKMProductionInfo *mProductionInfo;//游戏角色信息

+(RKProductInfo *)getRKProductInfo:(NSString *)order_id
                      andProductId:(NSString *)product_id
                    andProductName:(NSString *)product_name
                   andProductPrice:(float)product_price
                   andProductCount:(int)product_count
                andPayDescripation:(NSString *)pay_description
                     andUserServer:(NSString *)user_server
                        andExtInfo:(NSString   *)ext_info
                andMProductionInfo:(RKMProductionInfo *)m_production_info;

@end
