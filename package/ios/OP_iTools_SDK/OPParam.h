//
//  OPParam.h
//  OurpalmSDK
//
//  Created by op-mac1 on 13-7-29.
//
//

#ifndef OurpalmSDK_OPParam_h
#define OurpalmSDK_OPParam_h

#include <iostream>
using namespace std;

#ifdef NEWSDK
enum SDKTYPE{
    NONE_TYPE,
    kRegister=1,                    // 注册
    kNormalLogin,                   // 常规登陆
    kPhoneLogin,                    // 手机登陆
    kEmailLogin,                    // 邮箱登陆
    kQuickLogin,                    // 快速登陆
    kModifyPassword,                // 修改密码
    kBindEmail,                     // 绑定邮箱
    kBindAccount,                   // 绑定账号
    kGetVerifyCode,                 /* 获取验证码 */
    kBindTelephone,                 /* 绑定手机接口 */
    kUnbindTelephone,               /* 手机解绑接口 */
    kModifyBindingTelephone,        /* 修改绑定手机接口 */
    kFindPassword,                  /* 找回密码接口  */

    VTC_TYPE,
    FACEBOOK_TYPE
};
#else
enum SDKTYPE{
    NONE_TYPE,
    VTC_TYPE=1,
    FACEBOOK_TYPE
};
#endif

enum OPToolBarPlace{
    OPToolBarAtTopLeft = 1,			  /**< 左上 */
    OPToolBarAtTopRight,              /**< 右上 */
    OPToolBarAtMiddleLeft,            /**< 左中 */
    OPToolBarAtMiddleRight,           /**< 右中 */
    OPToolBarAtBottomLeft,            /**< 左下 */
    OPToolBarAtBottomRight,           /**< 右下 */
};

struct InitParam
{
public:
    InitParam(){
        debugModel = false;
        screenOrientation=0;
        appName = "";
        appKey = "";
        verifyUrl = "";
        gameKey = "";
        serverKey = "";
        cpID = 0;
        gameID = 0;
        serverID = 0;
        channelID = 0;
        cpID = 0;
        gameID = 0;
        serverID = 0;
        isAutoOrientation = false;
        chargeUrl = "";
        
        VTC_devId = "";
        VTC_devCode = "";
        VTC_mediaId = "";
        VTC_mediaCode = "";
        VTC_returnURL = "";
        VTC_keycode = "";
    }
    
    ~InitParam(){}
    
    int appId;
    std::string appKey;
    std::string verifyUrl;      //登陆验证地址
    std::string appName;
    std::string gameKey;
    std::string serverKey;  //
    std::string merchantId;
    std::string skey;//设置游戏skey
    std::string appSecret;//生成请求 request Token 的 secret,与 app key 一起分配。(新浪)
    std::string appRedirectURI;//应用回调页面,可在新浪微博开放平台->我的应用->应用信息->高级应用 ->授权设置->应用回调页中找到。
    std::string ssoCallbackScheme;//sso 回调地址,info.plist 中定义的 URL types,用于在微博客户端完成 sso 登录后进行回调。
    bool debugModel;
    int cpID;
    int gameID;
    int serverID;
    int channelID;
	std::string itunesAppId;
    
    //int AppID,bool isDebug, bool isAutoRotation, bool isLandScape, const char* isGameName,void* isViewController
    bool isAutoOrientation;//屏幕是否旋转
    void *gameController;//游戏的controller
    
    //平台界面方向
    //0  UIInterfaceOrientationLandscapeRight
    //1  UIDeviceOrientationLandscapeLeft
    //2  UIDeviceOrientationPortrait
    //3  UIDeviceOrientationPortraitUpsideDown
    int screenOrientation;
    
    std::string chargeUrl;
    
    //vtc 配置参数
    std::string VTC_devId;
    std::string VTC_devCode;
    std::string VTC_mediaId;
    std::string VTC_mediaCode;
    std::string VTC_returnURL;
    std::string VTC_keycode;
};

struct PurchaseParam
{
public:
    PurchaseParam(){
        user_account = "";
        uid = "";
        user_serverid = "";
        user_roleid = "";
        orderId = "";
        pd = "";
        pb = "";
        cd = "";
        platform = "";
        gameVersion = "";
        roleLv = "";
        roleName = "";
        price = "";
        syn = false;
        sign = "";
        gcustom = "";
    }
    ~PurchaseParam(){}
    
    std::string user_account;  //登陆账号（一般是第三方返回的用户id@xx.com形式）
    std::string uid;           //第三方返回的用户ID或token或其他参数
    std::string user_serverid; //服务器id
    std::string user_roleid;   //角色id
    std::string orderId;       //游戏中传的支付流水号，通常是机型MAC地址和时间生产的一串数字
    std::string pd;            //产品(游戏)id
    std::string pb;            //道具id
    std::string cd;            //渠道号id
    std::string platform;      //手机平台类型（1是ios,2是android）
    std::string gameVersion;   //客户端版本号
    std::string roleLv;        //角色等级（根据平台要求传）
    std::string roleName;      //角色名称（根据平台要求传）
    std::string price;         //充值方式时要传过来的价格
    bool syn;                  //是否同步发放道具（如单机游戏需要同步）
    std::string sign;          //参数md5校验签名
    std::string gcustom;       //游戏自定义信息
};



#endif
