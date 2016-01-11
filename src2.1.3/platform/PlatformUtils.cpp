#include "PlatformUtils.h"
#include "../Common/TLCommon.h"
#include "CCPlatformConfig.h"
#include "platform/sdk.h"
#include "MC/AssetsManager.h"
#include "Common/LuaApi.h"
#include <string>
#include "UI/TLEditBox.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/SDKCallback.h"
//#include "OurpalmSDK.h"
#include "android/jni/JniHelper.h"
#include "android/jni/Java_org_cocos2dx_lib_Cocos2dxHelper.h"
#include <jni.h>
#include "CCString.h"
#include "../NetMessage/NetWorkThread.h"
#include "../NetMessage/NetMsgProcess.h"
#include "../NetMessage/NetMsg.h"

//framework::SDKType GetSdkType()
//{
//	return framework::SDK_UNKNOWN;
//}
//

framework::SDKType GetSdkType() {
    const char* s = getMetaData("sdktype");
    int n = 0;
    if (s!=NULL and s[0]!='\0') {
        n = atoi(s);
        return (framework::SDKType) n;
    }
    CCLog("ERROR: Not speifiy sdktype in AndroidManifest.xml, return default one");
    return framework::SDK_YY;
}

using namespace cocos2d;

const char* getdeviceUniqueID()
{
	return NULL;
}

const char* getMAC()
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t
                , "org/weilan/poem"
                , "getLocalMacAddress"
                , "()Ljava/lang/String;"))
    {
        jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
        CCString *ret = new CCString(JniHelper::jstring2string(str).c_str());
        ret->autorelease();
        return ret->m_sString.c_str();
    }
    return NULL;

}

const char* getidfa()
{
	return NULL;
}

const char* getIMEI()
{
	return NULL;
}

const char* getDeviceId()
{
	JniMethodInfo t;
	if (JniHelper::getStaticMethodInfo(t
		, "org/weilan/poem"
		, "getDeviceId"
		, "()Ljava/lang/String;"))
	{
		jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
		CCString *ret = new CCString(JniHelper::jstring2string(str).c_str());
		ret->autorelease();
		return ret->m_sString.c_str();
	}
	return NULL;
}

const char* getIMSI()
{
    return NULL;
    //JniMethodInfo t;
    //if (JniHelper::getStaticMethodInfo(t
    //            , "org/weilan/poem"
    //            , "getIMSI"
    //            , "()Ljava/lang/String;"))
    //{
    //    jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);
    //    t.env->DeleteLocalRef(t.classID);
    //    CCString *ret = new CCString(JniHelper::jstring2string(str).c_str());
    //    ret->autorelease();
    //    return ret->m_sString.c_str();
    //}
    //return NULL;
}

const char* getUUID()
{
    return NULL;
    //JniMethodInfo t;
    //if (JniHelper::getStaticMethodInfo(t
    //            , "org/weilan/poem"
    //            , "getUUID"
    //            , "()Ljava/lang/String;"))
    //{
    //    jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);
    //    t.env->DeleteLocalRef(t.classID);
    //    CCString *ret = new CCString(JniHelper::jstring2string(str).c_str());
    //    ret->autorelease();
    //    return ret->m_sString.c_str();
    //}
    //return NULL;
}

bool acquireWakeLock()
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t
                , "org/weilan/poem"
                , "acquireWakeLock"
                , "()Z"))
    {
        bool b = (jboolean)t.env->CallStaticBooleanMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
        return b;
    }
    return false;
}

bool releaseWakeLock()
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t
                , "org/weilan/poem"
                , "releaseWakeLock"
                , "()Z"))
    {
        bool b = (jboolean)t.env->CallStaticBooleanMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
        return b;
    }
    return false;
}

bool userActivity()
{
    return false;
    //JniMethodInfo t;
    //if (JniHelper::getStaticMethodInfo(t
    //            , "org/weilan/poem"
    //            , "userActivity"
    //            , "()Z"))
    //{
    //    bool b = (jboolean)t.env->CallStaticBooleanMethod(t.classID, t.methodID);
    //    t.env->DeleteLocalRef(t.classID);
    //    return b;
    //}
    //return false;
}

void quitConfirm()
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t
                , "org/weilan/poem"
                , "quitConfirm"
                , "()V"))
    {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

void quitApplication()
{
	JniMethodInfo t;
	if (JniHelper::getStaticMethodInfo(t
		, "org/weilan/poem"
		, "quitApplication"
		, "()V"))
	{
		t.env->CallStaticVoidMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
	}
}

int getPackageVersion()
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t
                , "org/weilan/poem"
                , "getVersionCode"
                , "()I"))
    {
        int ver = t.env->CallStaticIntMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
        return ver;
    }
    else
    {
        return 0;
    }
}

std::string getPackageName()
{
    const char* s = getMetaData("YYPackageName");
    std::string ret = "";
    if (s==NULL || s[0]=='\0') {
        ret = getPackageNameJNI();
    }
    else {
        ret = s;
    }
	CCLOG("test getPackageName name=%s", ret.c_str());
    //return ret.c_str();
    //return "xp";
	return ret;
}

const char* getNetworkTypeName()
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t
                , "org/weilan/poem"
                , "getNetworkType"
                , "()Ljava/lang/String;"))
    {
        jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
        CCString *ret = new CCString(JniHelper::jstring2string(str).c_str());
        ret->autorelease();
        return ret->m_sString.c_str();
    }
    return NULL;
}

void openURL(const char* sUrl)
{
	if (sUrl==NULL)
	{
		return;
	}
	JniMethodInfo t;
	if (JniHelper::getStaticMethodInfo(t
		, "org/weilan/poem"
		, "openURL"
		, "(Ljava/lang/String;)V"))
	{
		jstring stringUrl = t.env->NewStringUTF(sUrl);
		t.env->CallStaticVoidMethod(t.classID, t.methodID, stringUrl);
		t.env->DeleteLocalRef(stringUrl);
		t.env->DeleteLocalRef(t.classID);
	}
}

bool isETC1Supported()
{
    return false;
    //JniMethodInfo t;
    //if (JniHelper::getStaticMethodInfo(t
    //            , "org/weilan/poem"
    //            , "isETC1Supported"
    //            , "()Z"))
    //{
    //    bool b = (jboolean)t.env->CallStaticBooleanMethod(t.classID, t.methodID);
    //    t.env->DeleteLocalRef(t.classID);
    //    return b;
    //}
    //return false;
}

static inline bool is_login_platform(framework::SDKType sdkType)
{
    return sdkType == framework::SDK_YY;
}

void EnterPlatform()
{
	if (is_login_platform(GetSdkType()))
	{
		return;
	}

	JniMethodInfo t;
	if (JniHelper::getStaticMethodInfo(t, "org/weilan/poem",
		"openCommunity", "()V"))
	{
		t.env->CallStaticVoidMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
	}
}


void OpenPlatformLogin()
{
	if (is_login_platform(GetSdkType()))
	{
		calllua_void("login_with_device");
		return;
	}

	JniMethodInfo t;
	if (JniHelper::getStaticMethodInfo(t, "org/weilan/poem",
			"accountLogin", "()V"))
	{
		t.env->CallStaticVoidMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
	}
}

void OpenPlatformLoginout()
{
	if (is_login_platform(GetSdkType()))
	{
		calllua_void("logout");
		return;
	}

	JniMethodInfo t;
	if (JniHelper::getStaticMethodInfo(t, "org/weilan/poem",
		"accountSwitch", "()V"))
	{
		t.env->CallStaticVoidMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
	}
}

const char* getOSVersion()
{
    return NULL;
    //JniMethodInfo t;
    //if (JniHelper::getStaticMethodInfo(t
    //            , "org/weilan/poem"
    //            , "getOSVersion"
    //            , "()Ljava/lang/String;"))
    //{
    //    jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);
    //    t.env->DeleteLocalRef(t.classID);
    //    CCString *ret = new CCString(JniHelper::jstring2string(str).c_str());
    //    ret->autorelease();
    //    return ret->m_sString.c_str();
    //}
    //return NULL;
}

const char* getResolution()
{
    //JniMethodInfo t;
    //if (JniHelper::getStaticMethodInfo(t
    //            , "org/weilan/poem"
    //            , "getResolution"
    //            , "()Ljava/lang/String;"))
    //{
    //    jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);
    //    t.env->DeleteLocalRef(t.classID);
    //    CCString *ret = new CCString(JniHelper::jstring2string(str).c_str());
    //    ret->autorelease();
    //    return ret->m_sString.c_str();
    //}
    return NULL;
}

const char* getUA()
{
    //JniMethodInfo t;
    //if (JniHelper::getStaticMethodInfo(t
    //            , "org/weilan/poem"
    //            , "getUA"
    //            , "()Ljava/lang/String;"))
    //{
    //    jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);
    //    t.env->DeleteLocalRef(t.classID);
    //    CCString *ret = new CCString(JniHelper::jstring2string(str).c_str());
    //    ret->autorelease();
    //    return ret->m_sString.c_str();
    //}
    return NULL;
}

const char* getMetaData(const char* name)
{
    CCLog("getMetaData %s", name);
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t
                , "org/weilan/poem"
                , "getMetaData"
                , "(Ljava/lang/String;)Ljava/lang/String;"))
    {
        jstring stringName = t.env->NewStringUTF(name);
        jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID, stringName);
        t.env->DeleteLocalRef(stringName);
        t.env->DeleteLocalRef(t.classID);
        if (str != NULL) {
            CCString *ret = new CCString(JniHelper::jstring2string(str).c_str());
            ret->autorelease();
            return ret->m_sString.c_str();
        }
        else {
            return NULL;
        }
    }
    return NULL;

}
#else

#include "sprite_nodes/CCSprite.h"
#include "MC/MovieClip.h"
#include "UI/TLWindowManager.h"
#include "MC/MCLoader.h"
USING_NS_CC;

bool userActivity()
{
    return true;
}

void quitConfirm()
{
}

bool isETC1Supported()
{
    return false;
}

#if CC_TARGET_PLATFORM != CC_PLATFORM_IOS
void quitApplication()
{
    //system("pause");
    exit( 0 );
}

void openURL(const char* sUrl)
{
}

#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#else

bool acquireWakeLock()
{
    return true;
}

bool releaseWakeLock()
{
    return true;
}

const char* getdeviceUniqueID()
{
	return NULL;
}

const char* getMAC()
{
    return NULL;
}

const char* getidfa()
{
	return NULL;
}

const char* getIMEI()
{
	return NULL;
}

int getPackageVersion()
{
    return 1;
}

std::string getPackageName()
{
    return "pc";
}

const char* getNetworkTypeName()
{
    return "wifi";
}

const char* getDeviceId()
{
    //return "test_robot_240";
    return "test_device_id";
}

const char* getIMSI()
{
    return "PC";
}

const char* getUUID()
{
    char buf[32] = {0};
    XLSprintf(buf, sizeof(buf), "PC_FAKE_UUID_%05d", rand());
    CCString *ret = new CCString(buf);
    ret->autorelease();
    return ret->m_sString.c_str();
}

////static MovieClip* loadingSprite = NULL;
//static CCSprite* loadingSprite = NULL;
//
//void showLoading(const char* sMsg)
//{
//    if (loadingSprite==NULL)
//    {
//        loadingSprite = MCLoader::sharedMCLoader()->loadSprite("60007_07.png");
//        loadingSprite->retain();
//        loadingSprite->setPosition(TLWindowManager::SharedTLWindowManager()->GetCenterPoint());
//    }
//    if (loadingSprite->getParent()==NULL)
//    {
//        TLWindowManager::SharedTLWindowManager()->addChild(loadingSprite, 999);
//    }
//    loadingSprite->stopAllActions();
//    loadingSprite->setVisible(true);
//    loadingSprite->runAction(CCRepeatForever::actionWithAction(CCRotateBy::actionWithDuration(0.5, -360)));
//}
//void hideLoading()
//{
//	if( loadingSprite != NULL )
//	{
//		loadingSprite->stopAllActions();
//		loadingSprite->setVisible(false);
//	}
//}
//bool isLoadingShowing()
//{
//	if( loadingSprite != NULL )
//	    return loadingSprite->getIsVisible();
//
//	return false;
//}

void EnterPlatform()
{

}

void OpenPlatformLogin()
{
}

void OpenPlatformLoginout()
{

}

void OpenPayInterface(char* szSerialNo, float money)
{
}

void payWithAndroidSDK(char *orderID, char *serverID, char *roleID, char *roleName, char *roleLevel, char *loginName, char *pbID )
{

}

framework::SDKType GetSdkType()
{
	return framework::SDK_YY;
}

const char* getOSVersion()
{
    return "PC";
}

const char* getResolution()
{
    return "PC";
}

const char* getUA()
{
    return "PC";
}

const char* getMetaData(const char* name)
{
    return "";
}
#endif
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
std::string strPlatformPostfix;
static std::string strPlatform;
#endif

const char* getPlatform()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    return "android";
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	if( strPlatformPostfix.empty() )
		return "win32";

	strPlatform = std::string( "win32_" ) + strPlatformPostfix;
	return strPlatform.c_str();
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
    return "linux";
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    return "ios";
#endif
}

//////////////////////////////////////////////////////////////////////////
// 只有 lua 的 log 才会被写入文件，不然会存在线程安全问题
FILE* _logFile = NULL;

void MyLog(const char* buf)
{
	if(_logFile)
	{
		fprintf(_logFile, "%s\n", buf);
		fflush(_logFile);
	}
}

void initLog()
{
	std::string logPath = CCFileUtils::sharedFileUtils()->getWritablePath() + "debug.log";
	_logFile = fopen(logPath.c_str(), "w+");

	CCSetLogFunction(MyLog);
	CCLuaLog(logPath.c_str());
}

void finiLog()
{
	if(_logFile)
	{
		fclose(_logFile);
		_logFile = NULL;
	}
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
void payWithAndroidSDK(char *orderID, char *serverID, char *roleID, char *roleName, char *roleLevel, char *loginName, char *pbID ){
    JniMethodInfo t;
    const char* sActivity = "org/weilan/poem"; //"com/weilan/poem/xp/MainActivity";
    const char* sSignature = "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V";

    if (JniHelper::getStaticMethodInfo(t, sActivity,
                "Pay", sSignature))
    {
        jstring order_id = t.env->NewStringUTF(orderID);         //订单号
        jstring server_id = t.env->NewStringUTF(serverID);       //服务器id
        jstring role_id = t.env->NewStringUTF(roleID);           //角色id
        jstring role_name = t.env->NewStringUTF(roleName);       //角色名称
        jstring role_level = t.env->NewStringUTF(roleLevel);     //角色等级
        jstring login_name = t.env->NewStringUTF(loginName);       //用户名称
        jstring pd_id = t.env->NewStringUTF(pbID);               //道具id

        t.env->CallStaticVoidMethod(t.classID, t.methodID, order_id, server_id, role_id, role_name, role_level, login_name, pd_id);

        t.env->DeleteLocalRef(order_id);  
        t.env->DeleteLocalRef(server_id);
        t.env->DeleteLocalRef(role_id);
        t.env->DeleteLocalRef(role_name);
        t.env->DeleteLocalRef(role_level);
        t.env->DeleteLocalRef(login_name);
        t.env->DeleteLocalRef(pd_id);
        t.env->DeleteLocalRef(t.classID);

    }
}


#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
void payWithAndroidSDK(char *orderID, char *serverID, char *roleID, char *roleName, char *roleLevel, char *loginName, char *pbID )
{

}
#endif


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#ifndef APP_STORE_IOS
void OpenPayInterface(char* szSerialNo, float money)
{
    // PayWithSDK
    char snum[32] = {0};
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo t;
    // default config
    const char* sActivity = "";
    const char* sSignature = "";

    if (GetSdkType()==framework::SDK_YY)
    {
        sActivity = "com/weilan/poem/xp/MainActivity";
        sSignature = "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V";
    }
    //else if (GetSdkType()==framework::SDK_UC)
    //{
    //    sActivity = "com/weilan/poem/uc/MainActivity";
    //    sSignature = "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V";

    //}

    if (JniHelper::getStaticMethodInfo(t, sActivity,
                "Pay", sSignature))
    {
        jstring sno = t.env->NewStringUTF(szSerialNo);  // 游戏中传的支付流水号

        int server_id = 0;  // 服务器id
        int role_id = 0;    // 角色id
        calllua(server_id, "getCurrentWorldId");
        calllua(role_id, "getCurrentRoleId");

        snprintf(snum, sizeof(snum)-1, "%d", server_id);
        jstring serverId = t.env->NewStringUTF(snum);            // 服务器id

        snprintf(snum, sizeof(snum)-1, "%d", role_id);
        jstring roleId = t.env->NewStringUTF(snum);              // 角色id

        std::string strTemp;
        calllua(strTemp, "getCurrentRoleProperty", "name");
        jstring roleName = t.env->NewStringUTF(strTemp.c_str()); //角色名称

        calllua(strTemp, "getCurrentRoleProperty", "level");
        jstring roleLv = t.env->NewStringUTF(strTemp.c_str());   // 角色等级

        calllua(strTemp, "get_property_id", money);
        jstring pbId = t.env->NewStringUTF(strTemp.c_str());     // 道具id

        calllua(strTemp, "getUserAccount");
        jstring loginId = t.env->NewStringUTF(strTemp.c_str());  // 登录id

        calllua(strTemp, "getPlatformUin");
        jstring uid = t.env->NewStringUTF(strTemp.c_str());      // 掌趣分配的用户ID或第三方返回的用户ID



        calllua(strTemp, "get_payment_channel");
        jstring chanId = t.env->NewStringUTF(strTemp.c_str());   // 渠道id


        t.env->CallStaticVoidMethod(t.classID, t.methodID, sno, uid, loginId, serverId, roleId, roleName, roleLv, pbId, chanId);

        t.env->DeleteLocalRef(sno);
        t.env->DeleteLocalRef(loginId);
        t.env->DeleteLocalRef(uid);
        t.env->DeleteLocalRef(serverId);
        t.env->DeleteLocalRef(roleId);
        t.env->DeleteLocalRef(roleName);
        t.env->DeleteLocalRef(roleLv);
        t.env->DeleteLocalRef(pbId);
        t.env->DeleteLocalRef(chanId);
        t.env->DeleteLocalRef(t.classID);
    }
    return;

#endif
#if OP_GAME_SDK_ENABLE
//    PurchaseParam* param = new PurchaseParam;
//
//    calllua(param->pb, "get_property_id", money);
////    param->pb = "2770074436553162";
//    param->cd = getMetaData("OPGameSDK_GAME_KEY");
//    param->pd = param->cd.substr(10, 4);
//    CCLOG("cd: %s, pb: %s, pd: %s\n", param->cd.c_str(), param->pb.c_str(), param->pd.c_str());
//    param->platform = "1";     // 手机平台类型（1是ios,2是android，3是WP8）
//    
//    // 设置其他购买参数
//    int role_id = 0;
//
//    param->user_serverid = "0"; // 服务器id
//    
//    snprintf(snum, sizeof(snum)-1, "%d", role_id);
//    param->user_roleid = snum; // 角色id
//    
//    param->user_account = ""; // 登陆账号（一般是第三方返回的用户id@xx.com形式）
//    param->uid = ""; // 掌趣分配的用户ID或第三方返回的用户ID
//    CCLOG("username: %s, uid: %s", param->user_account.c_str(), param->uid.c_str());
//
//    param->orderId = szSerialNo; // 游戏中传的支付流水号
//    
//    snprintf(snum, sizeof(snum)-1, "%d", AssetsManager::sharedAssetsManager()->getVersion());
//    param->gameVersion = snum;   // 游戏版本号
//     
//    calllua(param->roleName, "get_role_property", "name"); // 角色等级
//    calllua(param->roleLv, "get_role_property", "level"); // 角色名称
//    CCLOG("name: %s, level: %s\n", param->roleName.c_str(), param->roleLv.c_str());
//
//    param->price = "";         // 价格
//    param->syn = false;        // 是否同步发放道具（单机为true，网游为false）
//    param->sign = "";          // 参数md5校验签名，目前只有人人网渠道需要添加此参数
//    param->gcustom = "";       // 游戏自定义信息
//    
//    ourpalmpay::OPGameSDK::GetInstance().Purchase(param);
#endif
    
}
#endif

#endif


void useConsole() //  π”√øÿ÷∆Ã®
{
#ifdef WIN32
    if(AllocConsole())
    {
        freopen("CONOUT$","w",stdout);
    }
#endif
}

std::string g_strResourceVersion;
void setResourceVersion( const char* szResVersion )
{
    if( szResVersion != NULL )
        g_strResourceVersion = szResVersion;
}

const char* getResourceVersion()
{
    return g_strResourceVersion.c_str();
}

#if( CC_TARGET_PLATFORM != CC_PLATFORM_IOS )
void createLocalNotification( const char* nDaysLater, const char* nHour, const char* nMinute, const char* nSecond, const char* szContent, const char* key, const char* nType  )
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
    JniMethodInfo t;
    if( JniHelper::getStaticMethodInfo( t
                , "org/weilan/poem"
                , "createLocalNotification"
                , "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V" ) )
    {

        jstring j_nDaysLater = t.env->NewStringUTF( nDaysLater );
        jstring j_nHour = t.env->NewStringUTF( nHour );
        jstring j_nMinute = t.env->NewStringUTF( nMinute );
        jstring j_nSecond = t.env->NewStringUTF( nSecond );
        jstring j_szContent = t.env->NewStringUTF( szContent );
        jstring j_key = t.env->NewStringUTF( key );
        jstring j_nType = t.env->NewStringUTF( nType );
        t.env->CallStaticVoidMethod( t.classID, t.methodID, j_nDaysLater, j_nHour, j_nMinute, j_nSecond, j_szContent, j_key, j_nType );

        t.env->DeleteLocalRef(j_nDaysLater);
        t.env->DeleteLocalRef(j_nHour);
        t.env->DeleteLocalRef(j_nMinute);
        t.env->DeleteLocalRef(j_nSecond);
        t.env->DeleteLocalRef(j_szContent);
        t.env->DeleteLocalRef(j_key);
        t.env->DeleteLocalRef(j_nType);
        t.env->DeleteLocalRef( t.classID );
    }

#endif
}
void releaseLocalNotification( const char* key )
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
    JniMethodInfo t;
    if( JniHelper::getStaticMethodInfo( t
                , "org/weilan/poem"
                , "releaseLocalNotification"
                , "(Ljava/lang/String;)V" ) )
    {

        jstring j_key = t.env->NewStringUTF( key );
        t.env->CallStaticVoidMethod( t.classID, t.methodID, j_key );

        t.env->DeleteLocalRef(j_key);
        t.env->DeleteLocalRef( t.classID );
    }


#endif
}
void releaseAllLocalNotification()
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
    JniMethodInfo t;
    if( JniHelper::getStaticMethodInfo( t
                , "org/weilan/poem"
                , "releaseAllLocalNotification"
                , "()V" ) )
    {

        t.env->CallStaticVoidMethod( t.classID, t.methodID );

        t.env->DeleteLocalRef( t.classID );
    }
#endif
}

void playMedia( const char* szPath )
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
    JniMethodInfo t;
    if( JniHelper::getStaticMethodInfo( t
                , "org/weilan/poem"
                , "playVideo"
                , "(Ljava/lang/String;)V" ) )
    {
		jstring string_path = t.env->NewStringUTF( szPath );
		t.env->CallStaticVoidMethod( t.classID, t.methodID, string_path );
		t.env->DeleteLocalRef( string_path );
		t.env->DeleteLocalRef( t.classID );
    }
#endif
}

void stopMedia()
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
    JniMethodInfo t;
    if( JniHelper::getStaticMethodInfo( t
                , "org/weilan/poem"
                , "stopMdeia"
                , "()V" ) )
    {
		t.env->CallStaticVoidMethod( t.classID, t.methodID );
		t.env->DeleteLocalRef( t.classID );
    }
#endif
}
#endif

void hideWindow()
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
    CCEGLView* pMainWnd = CCEGLView::sharedOpenGLView();
    ShowWindow( pMainWnd->getHWnd(), SW_HIDE );
#endif
}

#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
extern "C"
{
JNIEXPORT jboolean JNICALL Java_org_weilan_sdk_sendTalkStr(JNIEnv* env, jobject thiz, jstring talkStr)
{
    TLEditBox *s_TLEditBox = TLEditBox::getCurrentTLEditBox();
    s_TLEditBox->sentNetMsgToSelf(env->GetStringUTFChars(talkStr, 0));
	return true;
}

JNIEXPORT jboolean JNICALL Java_org_weilan_sdk_checkTalkStr(JNIEnv* env, jobject thiz, jstring talkStr, jint talkStrLength)
{
    TLEditBox *s_TLEditBox = TLEditBox::getCurrentTLEditBox();
    return s_TLEditBox->checkText(env->GetStringUTFChars(talkStr, 0), talkStrLength);
}

JNIEXPORT jboolean JNICALL Java_org_weilan_sdk_platformCallback(JNIEnv* env, jobject thiz, jint type, jstring args)
{
    platform_callback((CbType) type, env->GetStringUTFChars(args, 0));
    return true;
}


}
#endif

#if( CC_TARGET_PLATFORM != CC_PLATFORM_IOS )
const char* getAvailMemory()
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
    JniMethodInfo t;
    if( JniHelper::getStaticMethodInfo(t
                , "org/weilan/poem"
                , "getAvailMemory"
                , "()Ljava/lang/String;"))
    {
        jstring str = (jstring)t.env->CallStaticObjectMethod( t.classID, t.methodID );
        t.env->DeleteLocalRef( t.classID );

        if( str != NULL )
        {
            CCString *ret = new CCString( JniHelper::jstring2string( str ).c_str() );
            ret->autorelease();

            return ret->m_sString.c_str();
        }
    }
#endif

    return "1024";
}
#endif
