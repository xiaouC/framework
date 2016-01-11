//
//  RKStatisticsManager.h
//  Statistics
//
//  Created by 蔡 阳滨 on 13-8-13.
//  Copyright (c) 2013年 sunsea. All rights reserved.
//
#ifndef StatisticsTest_RKSTATISTICSMANAGER_h
#define StatisticsTest_RKSTATISTICSMANAGER_h
#endif

#import <Foundation/Foundation.h>

#define biVersion @"1.2.5.1"

class  RKStatisticsManager
{
public:
    
    static RKStatisticsManager * getInstance();
    ~RKStatisticsManager(){};
    static BOOL debug;
    static BOOL isIP;
    void rkStatisticsWithChannelID(const char * _channelID,
                                   const char *_gameVersion,
                                   const char * _gamePageName,
                                   const char * _action ,
                                   const char *_stayTime,
                                   const char * _gameName);
    //    void inBackGround();
    void runAThreadWithChannelID(const char * _channelID,
                                 const char *_gameVersion,
                                 const char * _gamePageName,
                                 const char *_stayTime,
                                 const char * _gameName);
    //废弃
    void showADViewWithBaseUrlStr(const char* baseUrl,
                                  int appID,
                                  const char* version);
    
    /**
     * 获取唯一标示
     * @return mac,idfa,idfv
     */
    const char* getNewUniqueIdentifier();
    
    /**
     * 获取ios<6 获取mac address
     * @return mac
     */
    const char* getOldUniqueIdentifier();
    
    /**
     * 获取id ios5 mac  ios6+ idfa
     * @return mac
     */
    const char* getID();
    
//    /**
//     *  加载积分墙广告(查询积分墙是否可以显示)
//     *  @param
//     *  AppID:需要向RekooAD平台申请
//     *  注册通知
//     *  @return:
//     *  成功or失败(YES or NO),请根据情景适时加载积分墙
//     *
//     *  测试环境配置
//     *  配置appDebug 0
//     */
//    
//    void loadADWallViewWithAppID(const char* aAppID);
//    
//    /**
//     *  显示积分墙广告
//     *  @param
//     *  AppID:需要向RekooAD平台申请
//     */
//    
//    void showADWallViewWithAppID(const char* aAppID);
//    
//    /**
//     *  加载插屏广告(查询插屏广告是否可以显示)
//     *  @param
//     *  AppID:需要向RekooAD平台申请
//     *  注册通知
//     *  @return:
//     *  成功or失败(YES or NO),请根据情景适时加载插屏广告
//     *
//     *  测试环境配置
//     *  配置appDebug 0
//     */
//    
//    void loadADInterstitialViewWithAppID(const char* aAppID);
//    
//    /**
//     *  显示插屏广告
//     *  @param
//     *  AppID:需要向RekooAD平台申请
//     */
//    void showADInterstitialViewWithAppID(const char* aAppID);
//    
//    /*
//     *  消费积分(支付)
//     *  @param
//     *  AppID:需要向RekooAD平台申请
//     *  aPayPoint:1-10000之间
//     */
//    void consumedIntegralWithAppID(const char* aAppID, int aPayPoint);
//    
//    
//    /**
//     *  查询积分
//     *  @param
//     */
//    void checkPointWithTotalPoint(const char* aAppID);
    
private:
    RKStatisticsManager(){};
    static RKStatisticsManager * _instance;
};
