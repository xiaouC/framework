#include "SDKLoginUtilsForAndroid.h"

#include "../Common/TLCommon.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "android/jni/JniHelper.h"
//#include "android/jni/Java_org_cocos2dx_lib_Cocos2dxHelper.h"
#include <jni.h>

#endif
void OpenPayWithAndroid(char *ID, char *name, char *orderID, char *goodsID, char *price, char *serverID, char *roleID, char *roleName, char *roleLevel)
{

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo t;
    const char* sActivity = "org/weilan/poem"; 
    const char* sSignature = "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V";

    if (JniHelper::getStaticMethodInfo(t, sActivity,
                "Pay", sSignature))
    {
        jstring j_ID = t.env->NewStringUTF(ID);                   //禮包ID
        jstring j_name = t.env->NewStringUTF(name);               //禮包名稱
        jstring j_orderID = t.env->NewStringUTF(orderID);         //订单号
        jstring j_goodsID = t.env->NewStringUTF(goodsID);         //商品id
        jstring j_price = t.env->NewStringUTF(price);             //价格
        jstring j_serverID = t.env->NewStringUTF(serverID);       //服务器id
        jstring j_roleID = t.env->NewStringUTF(roleID);           //角色id
        jstring j_roleName = t.env->NewStringUTF(roleName);       //角色名称
        jstring j_roleLevel = t.env->NewStringUTF(roleLevel);     //角色等级

        t.env->CallStaticVoidMethod(t.classID, t.methodID, j_ID, j_name, j_orderID, j_goodsID, j_price, j_serverID, j_roleID, j_roleName, j_roleLevel);

        t.env->DeleteLocalRef(j_ID);  
        t.env->DeleteLocalRef(j_name);  
        t.env->DeleteLocalRef(j_orderID);  
        t.env->DeleteLocalRef(j_goodsID);
        t.env->DeleteLocalRef(j_price);
        t.env->DeleteLocalRef(j_serverID);
        t.env->DeleteLocalRef(j_roleID);
        t.env->DeleteLocalRef(j_roleName);
        t.env->DeleteLocalRef(j_roleLevel);
        t.env->DeleteLocalRef(t.classID);

    }

#endif
}

