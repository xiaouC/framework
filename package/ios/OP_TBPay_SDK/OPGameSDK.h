//
//  OPGameSDK.h
//  OurpalmSDK
//
//  Created by op-mac1 on 13-7-29.
//
//

#ifndef __OurpalmSDK__OPGameSDK__
#define __OurpalmSDK__OPGameSDK__

#include "OPParam.h"
#include "OPPurchaseListener.h"
#include <iostream>
using namespace std;
//

namespace ourpalmpay {
    
    class OPGameSDK
    {
    public:
        OPGameSDK();
        ~OPGameSDK();
        
    public:
        inline static OPGameSDK& GetInstance(){
            static OPGameSDK pur;
            return pur;
        }
        
    public:
        
        void GetEnableInterface(char** data);
        
        //返回SDK可用功能(chargtype 支付类型ID)
        /**
         *	@brief	返回SDK可用功能
         *	@return  Type_Login 登录方式(0:官网登陆，1：第三方登陆)
         *  @return  Logout 是否使用注销登陆接口(0:不使用，1：使用)
         *  @return  SwitchAccount 是否使用切换账号接口(0:不使用，1：使用)
         *  @return  GoUserCenter  是否使用进入用户中心或者论坛接口(0:不使用，1：使用)
         *  @return  Exit是否使用退出接口(0:不使用，1：使用)
         */
        const char*  GetEnableInterface(int chargtype = 0);
        
        //const char* GetSystemInfo();
        
        //初始化（含自动调用更新接口）
        void Init(void* controller,InitParam* opInfo);
        void InitCallBack(void (* pf)(bool result,const char* jsonStr));
        void CallBackInit(bool result,const char* jsonStr) { (* pfuncInit)(result,jsonStr); }
        
        //注册登陆
        void RegisterLogin(SDKTYPE sdkType=NONE_TYPE);
        bool IsLogin();
        void LogOut();
        //设置注册登陆回调函数（已将验证封装）
        void RegisterLoginCallBack(void (* pf)(bool result,const char* jsonStr));
        void CallBackLogin(bool result,const char* jsonStr) { (* pfuncLogin)(result,jsonStr); }
        
        //设置登出回调函数（已将验证封装）
        void RegisterLogoutCallBack(void (* pf)(bool result,const char* jsonStr));
        void CallBackLogout(bool result,const char* jsonStr) { (* pfuncLogout)(result,jsonStr); }
        
        
        //官网登录
        void RegisterLogin(const char* loginFlag,const char* tokenId,const char* userInfo,
                           const char* userName,const char* userPwd,const char* mobile,
                           const char* email,const char* remark);
        
        void UserSettingCallBack(void (* pf)(bool result,const char* jsonStr));
        void CallBackUserSetting(bool result,const char* jsonStr) { (* pfuncUserSetting)(result,jsonStr); }
        
        void ModifyPassword(const char* userId,const char* newPassword);
        void BindEmail(const char* userId,const char* email,int action);
        void BindAccount(const char* userName,const char* userPwd);
        
        //计费（异步方式）
        void SetListener(PurchaseListener* listener);
        void Purchase(PurchaseParam* params);
        
        //进入平台中心
        void EnterPlatform();
        //用户反馈
        void UserFeedback();
        //分享到第三方平台
        void ShareToThirdPlatform(const char* content,const char* imageUrl="");
        //设置本地通知
        void SetLocalNotification(int second,const char* desc);
        //取消本地通知
        void CancelLoaclNotification();
        //设置捕获会话过期的通知
        void SessionInvalidCallBack(void (* pf)());
        void CallBackSessionInvalid(){ (* pfuncSessionInvalid)(); }
        
        //进入平台中心各模块*******************
        //进入好友中心
        void EnterFriendCenter();
        //进入好友空间
        void EnterUserSpace(const char* uin);
        //进入游戏大厅
        void EnterAppCenter();
        //进入指定游戏的主页
        void EnterAppCenter(int appId);
        //进入设置界面
        void EnterUserSetting();
        //进入邀请好友界面
        void EnterInviteFriendCenter(const char* desc);
        //进入引用论坛界面
        void EnterAppBBS();
        //进入充值界面
        void EnterRechargeCenter();
        
        //在游戏暂停或者从后台恢复的时候显示暂停页
        void ShowPausePage();
        
        
        //暂时不用的接口
        //检查更新
        void CheckUpdate();
        //切换账号
        void SwitchAccount();
        
        bool HandleOpenURL(void* url);
        void HandleOpenURL(void* url, void* application);
        void ExtendAccessTokenIfNeeded();
        
        bool HandleOpenURL(void* application,void* url,void* sourceApplication,void* annotation);
        void applicationWillTerminate(void* application);
        void applicationDidBecomeActive(void* application);
        
        //显示和隐藏工具栏
        void ShowToolBar(OPToolBarPlace toolBarPlace);
        void HideToolBar();
        
    public:
        SDKTYPE curSdkType;
        
    private:
        void (* pfuncInit)(bool result,const char * jsonStr);
        void (* pfuncLogin)(bool result,const char * jsonStr);
        void (* pfuncLogout)(bool result,const char * jsonStr);
        void (* pfuncUserSetting)(bool result,const char * jsonStr);
        void (* pfuncBlog)(bool result);
        void (* pfuncSessionInvalid)();
        bool isInit;//是否初始化
        bool isRegisterFun;// 是否设置登陆注册的回调函数
        std::string systemInfo;
    };
}

#endif /* defined(__OurpalmSDK__OPGameSDK__) */
