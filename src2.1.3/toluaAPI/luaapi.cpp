/*
** Lua binding: api
** Generated automatically by tolua++-version on [The timestamp has been removed by xiaou].
*/

/****************************************************************************
 Copyright (c) 2011 cocos2d-x.org

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/



#include "tolua_fix.h"
#include "CCLuaValue.h"
#include "TLRunningScene.h"
#include "Common/TLCommon.h"
#include "MC/AssetsManager.h"
#include "MC/MovieClip.h"
#include "MC/MCLoader.h"
#include "MC/BatchNodeMC.h"
using namespace cocos2d;
#include "RichText/TLFontTex.h"
#include "RichText/TLLabelRichTex.h"
#include "RichText/TLRichTexVerbatim.h"
#include "NetMessage/NetMsg.h"
#include "NetMessage/NetMsgProcess.h"
#include "NetMessage/HttpDownloader.h"
#include "NetMessage/HttpClient.h"
using namespace framework;
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
#include "UI/TLMaskLayer.h"
#include "UI/TLWindow.h"
#include "UI/TLWindowManager.h"
#include "UI/TLDropDragHelper.h"
using namespace cocos2d;
#include "platform/sdk.h"
#include "platform/PlatformUtils.h"
#include "platform/SDKCallback.h"
#include "Common/TLModel.h"
using namespace cocos2d;
#include "particle/ParticleSystemManager.h"
using namespace cocos2d;
#include "tween/TLTweenManager.h"
#include "Common/CCActionExtend.h"
using namespace cocos2d;
#include "platform/SDKLoginUtilsForAndroid.h"
#include "UI/TLEditBox.h"
#include "UI/TLRenderNode.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_CCPoint (lua_State* tolua_S)
{
 CCPoint* self = (CCPoint*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCRect (lua_State* tolua_S)
{
 CCRect* self = (CCRect*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCSize (lua_State* tolua_S)
{
 CCSize* self = (CCSize*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_GLubyte (lua_State* tolua_S)
{
 GLubyte* self = (GLubyte*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CCPoint");
 tolua_usertype(tolua_S,"HttpRequestFile");
 tolua_usertype(tolua_S,"CCTexture2D");
 tolua_usertype(tolua_S,"MainSceneRoleMC");
 tolua_usertype(tolua_S,"CCIMEDelegate");
 tolua_usertype(tolua_S,"TLRichTexVerbatim");
 tolua_usertype(tolua_S,"TLRenderNode");
 tolua_usertype(tolua_S,"SimpleAudioEngine");
 tolua_usertype(tolua_S,"MCFrame");
 tolua_usertype(tolua_S,"CCNode");
 tolua_usertype(tolua_S,"GLubyte");
 tolua_usertype(tolua_S,"CURL");
 tolua_usertype(tolua_S,"CCActionLuaCallFunc");
 tolua_usertype(tolua_S,"CCLayerColor");
 tolua_usertype(tolua_S,"CCSpriteBatchNode");
 tolua_usertype(tolua_S,"TLTweenManager");
 tolua_usertype(tolua_S,"TLDropDragHelper");
 tolua_usertype(tolua_S,"ClipNode");
 tolua_usertype(tolua_S,"CCScene");
 tolua_usertype(tolua_S,"TLRunningScene");
 tolua_usertype(tolua_S,"ParticleSystemManager");
 tolua_usertype(tolua_S,"ParticleSystem");
 tolua_usertype(tolua_S,"CNetSender");
 tolua_usertype(tolua_S,"ccColor3B");
 
 tolua_usertype(tolua_S,"CCRect");
 tolua_usertype(tolua_S,"TLModel");
 tolua_usertype(tolua_S,"CCActionInstant");
 tolua_usertype(tolua_S,"TLWindow");
 tolua_usertype(tolua_S,"CCLabelBMFont");
 tolua_usertype(tolua_S,"CNetReceiver");
 tolua_usertype(tolua_S,"CCLayer");
 tolua_usertype(tolua_S,"CHttpDownloader");
 tolua_usertype(tolua_S,"CCObject");
 tolua_usertype(tolua_S,"TLHttpClient");
 tolua_usertype(tolua_S,"MCLoader");
 tolua_usertype(tolua_S,"HttpRequestMsg");
 tolua_usertype(tolua_S,"MovieClip");
 tolua_usertype(tolua_S,"CCSize");
 tolua_usertype(tolua_S,"AssetsManager");
 tolua_usertype(tolua_S,"ccColor4B");
 tolua_usertype(tolua_S,"framework::Symbol");
 tolua_usertype(tolua_S,"::google::protobuf::MessageLite");
 tolua_usertype(tolua_S,"CCArray");
 tolua_usertype(tolua_S,"TLMaskLayer");
 tolua_usertype(tolua_S,"TLFontTex");
 tolua_usertype(tolua_S,"CNetMsg");
 tolua_usertype(tolua_S,"CCLabelTTF");
 tolua_usertype(tolua_S,"chatTexInfo");
 tolua_usertype(tolua_S,"ccBlendFunc");
 tolua_usertype(tolua_S,"CCImage");
 tolua_usertype(tolua_S,"CCGLProgram");
 tolua_usertype(tolua_S,"TLLabelRichTex");
 tolua_usertype(tolua_S,"CCParticleSystem");
 tolua_usertype(tolua_S,"HttpRequest");
 tolua_usertype(tolua_S,"CCSprite");
 tolua_usertype(tolua_S,"TLEditBox");
 tolua_usertype(tolua_S,"CCSpriteFrame");
 tolua_usertype(tolua_S,"CCNodeRGBA");
 tolua_usertype(tolua_S,"TLWindowManager");
}

/* method: create of class  TLRunningScene */
#ifndef TOLUA_DISABLE_tolua_api_TLRunningScene_create00
static int tolua_api_TLRunningScene_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLRunningScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLRunningScene* tolua_ret = (TLRunningScene*)  TLRunningScene::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLRunningScene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: dump_rusage */
#ifndef TOLUA_DISABLE_tolua_api_dump_rusage00
static int tolua_api_dump_rusage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   dump_rusage();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dump_rusage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: dump_texture */
#ifndef TOLUA_DISABLE_tolua_api_dump_texture00
static int tolua_api_dump_texture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   dump_texture();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dump_texture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: smoothstep */
#ifndef TOLUA_DISABLE_tolua_api_smoothstep00
static int tolua_api_smoothstep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float edge0 = ((float)  tolua_tonumber(tolua_S,1,0));
  float edge1 = ((float)  tolua_tonumber(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   float tolua_ret = (float)  smoothstep(edge0,edge1,x);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'smoothstep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: setReconnectionInterval */
#ifndef TOLUA_DISABLE_tolua_api_setReconnectionInterval00
static int tolua_api_setReconnectionInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float fInterval = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   setReconnectionInterval(fInterval);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setReconnectionInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getRealMsgID */
#ifndef TOLUA_DISABLE_tolua_api_getRealMsgID00
static int tolua_api_getRealMsgID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned int uiMsgID = ((unsigned int)  tolua_tonumber(tolua_S,1,0));
  {
   unsigned short tolua_ret = (unsigned short)  getRealMsgID(uiMsgID);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRealMsgID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: setProjectNickname */
#ifndef TOLUA_DISABLE_tolua_api_setProjectNickname00
static int tolua_api_setProjectNickname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* szNickname = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   setProjectNickname(szNickname);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProjectNickname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getProjectNickname */
#ifndef TOLUA_DISABLE_tolua_api_getProjectNickname00
static int tolua_api_getProjectNickname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getProjectNickname();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProjectNickname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getNodeAlphaLua */
#ifndef TOLUA_DISABLE_tolua_api_getNodeAlphaLua00
static int tolua_api_getNodeAlphaLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  {
   float tolua_ret = (float)  getNodeAlphaLua(node);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNodeAlphaLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: setNodeAlphaLua */
#ifndef TOLUA_DISABLE_tolua_api_setNodeAlphaLua00
static int tolua_api_setNodeAlphaLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  float o = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   setNodeAlphaLua(node,o);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNodeAlphaLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: setNodeTLAlphaLua */
#ifndef TOLUA_DISABLE_tolua_api_setNodeTLAlphaLua00
static int tolua_api_setNodeTLAlphaLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  float o = ((float)  tolua_tonumber(tolua_S,2,0));
  bool bUpdate = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   setNodeTLAlphaLua(node,o,bUpdate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNodeTLAlphaLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: setNodeBLAlphaLua */
#ifndef TOLUA_DISABLE_tolua_api_setNodeBLAlphaLua00
static int tolua_api_setNodeBLAlphaLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  float o = ((float)  tolua_tonumber(tolua_S,2,0));
  bool bUpdate = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   setNodeBLAlphaLua(node,o,bUpdate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNodeBLAlphaLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: setNodeBRAlphaLua */
#ifndef TOLUA_DISABLE_tolua_api_setNodeBRAlphaLua00
static int tolua_api_setNodeBRAlphaLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  float o = ((float)  tolua_tonumber(tolua_S,2,0));
  bool bUpdate = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   setNodeBRAlphaLua(node,o,bUpdate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNodeBRAlphaLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: setNodeTRAlphaLua */
#ifndef TOLUA_DISABLE_tolua_api_setNodeTRAlphaLua00
static int tolua_api_setNodeTRAlphaLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  float o = ((float)  tolua_tonumber(tolua_S,2,0));
  bool bUpdate = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   setNodeTRAlphaLua(node,o,bUpdate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNodeTRAlphaLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: setNodeColor */
#ifndef TOLUA_DISABLE_tolua_api_setNodeColor00
static int tolua_api_setNodeColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  const ccColor3B* o = ((const ccColor3B*)  tolua_tousertype(tolua_S,2,0));
  {
   setNodeColor(node,*o);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNodeColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: setNodeColorRLua */
#ifndef TOLUA_DISABLE_tolua_api_setNodeColorRLua00
static int tolua_api_setNodeColorRLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   setNodeColorRLua(node,r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNodeColorRLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: setNodeColorGLua */
#ifndef TOLUA_DISABLE_tolua_api_setNodeColorGLua00
static int tolua_api_setNodeColorGLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  float g = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   setNodeColorGLua(node,g);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNodeColorGLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: setNodeColorBLua */
#ifndef TOLUA_DISABLE_tolua_api_setNodeColorBLua00
static int tolua_api_setNodeColorBLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  float b = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   setNodeColorBLua(node,b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNodeColorBLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: setNodeShaderProgram */
#ifndef TOLUA_DISABLE_tolua_api_setNodeShaderProgram00
static int tolua_api_setNodeShaderProgram00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCGLProgram",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  CCGLProgram* pShaderProgram = ((CCGLProgram*)  tolua_tousertype(tolua_S,2,0));
  {
   setNodeShaderProgram(node,pShaderProgram);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNodeShaderProgram'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sharedAssetsManager of class  AssetsManager */
#ifndef TOLUA_DISABLE_tolua_api_AssetsManager_sharedAssetsManager00
static int tolua_api_AssetsManager_sharedAssetsManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AssetsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   AssetsManager* tolua_ret = (AssetsManager*)  AssetsManager::sharedAssetsManager();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AssetsManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedAssetsManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  AssetsManager */
#ifndef TOLUA_DISABLE_tolua_api_AssetsManager_Load00
static int tolua_api_AssetsManager_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AssetsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AssetsManager* self = (AssetsManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Load();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fileExists of class  AssetsManager */
#ifndef TOLUA_DISABLE_tolua_api_AssetsManager_fileExists00
static int tolua_api_AssetsManager_fileExists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AssetsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AssetsManager* self = (AssetsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fileExists'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->fileExists(url);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fileExists'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRealPath of class  AssetsManager */
#ifndef TOLUA_DISABLE_tolua_api_AssetsManager_getRealPath00
static int tolua_api_AssetsManager_getRealPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AssetsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AssetsManager* self = (AssetsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRealPath'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getRealPath(url);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRealPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFileContent of class  AssetsManager */
#ifndef TOLUA_DISABLE_tolua_api_AssetsManager_getFileContent00
static int tolua_api_AssetsManager_getFileContent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AssetsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AssetsManager* self = (AssetsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* pMode = ((const char*)  tolua_tostring(tolua_S,3,0));
  unsigned long iSize = ((unsigned long)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFileContent'", NULL);
#endif
  {
   unsigned char* tolua_ret = (unsigned char*)  self->getFileContent(url,pMode,&iSize);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)iSize);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFileContent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVersion of class  AssetsManager */
#ifndef TOLUA_DISABLE_tolua_api_AssetsManager_getVersion00
static int tolua_api_AssetsManager_getVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AssetsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AssetsManager* self = (AssetsManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVersion'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getVersion();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getConfigVersion of class  AssetsManager */
#ifndef TOLUA_DISABLE_tolua_api_AssetsManager_getConfigVersion00
static int tolua_api_AssetsManager_getConfigVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AssetsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AssetsManager* self = (AssetsManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getConfigVersion'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getConfigVersion();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getConfigVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVersionName of class  AssetsManager */
#ifndef TOLUA_DISABLE_tolua_api_AssetsManager_getVersionName00
static int tolua_api_AssetsManager_getVersionName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AssetsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AssetsManager* self = (AssetsManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVersionName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getVersionName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVersionName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: supportAssetsUpgrade of class  AssetsManager */
#ifndef TOLUA_DISABLE_tolua_api_AssetsManager_supportAssetsUpgrade00
static int tolua_api_AssetsManager_supportAssetsUpgrade00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AssetsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AssetsManager* self = (AssetsManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'supportAssetsUpgrade'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->supportAssetsUpgrade();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'supportAssetsUpgrade'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isLuaFileExist of class  AssetsManager */
#ifndef TOLUA_DISABLE_tolua_api_AssetsManager_isLuaFileExist00
static int tolua_api_AssetsManager_isLuaFileExist00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AssetsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AssetsManager* self = (AssetsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isLuaFileExist'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isLuaFileExist(url);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isLuaFileExist'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addSearchPath of class  AssetsManager */
#ifndef TOLUA_DISABLE_tolua_api_AssetsManager_addSearchPath00
static int tolua_api_AssetsManager_addSearchPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AssetsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AssetsManager* self = (AssetsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* szPath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addSearchPath'", NULL);
#endif
  {
   self->addSearchPath(szPath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addSearchPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mcBoundingBox of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_get_MovieClip_mcBoundingBox
static int tolua_get_MovieClip_mcBoundingBox(lua_State* tolua_S)
{
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mcBoundingBox'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mcBoundingBox,"CCRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mcBoundingBox of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_set_MovieClip_mcBoundingBox
static int tolua_set_MovieClip_mcBoundingBox(lua_State* tolua_S)
{
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mcBoundingBox'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mcBoundingBox = *((CCRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mcOriginBoundingBox of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_get_MovieClip_mcOriginBoundingBox
static int tolua_get_MovieClip_mcOriginBoundingBox(lua_State* tolua_S)
{
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mcOriginBoundingBox'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mcOriginBoundingBox,"CCRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mcOriginBoundingBox of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_set_MovieClip_mcOriginBoundingBox
static int tolua_set_MovieClip_mcOriginBoundingBox(lua_State* tolua_S)
{
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mcOriginBoundingBox'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mcOriginBoundingBox = *((CCRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithName of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_api_MovieClip_createWithName00
static int tolua_api_MovieClip_createWithName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MovieClip",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* mcName = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool bAsync = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   MovieClip* tolua_ret = (MovieClip*)  MovieClip::createWithName(mcName,bAsync);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"MovieClip");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: play of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_api_MovieClip_play00
static int tolua_api_MovieClip_play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
  int startFrame = ((int)  tolua_tonumber(tolua_S,2,0));
  int durationFrame = ((int)  tolua_tonumber(tolua_S,3,0));
  int loopCount = ((int)  tolua_tonumber(tolua_S,4,0));
  bool reverse = ((bool)  tolua_toboolean(tolua_S,5,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'play'", NULL);
#endif
  {
   self->play(startFrame,durationFrame,loopCount,reverse);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_api_MovieClip_start00
static int tolua_api_MovieClip_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_api_MovieClip_pause00
static int tolua_api_MovieClip_pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pause'", NULL);
#endif
  {
   self->pause();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAutoClear of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_api_MovieClip_setAutoClear00
static int tolua_api_MovieClip_setAutoClear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
  bool reset = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoClear'", NULL);
#endif
  {
   self->setAutoClear(reset);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoClear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAutoClear of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_api_MovieClip_getAutoClear00
static int tolua_api_MovieClip_getAutoClear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAutoClear'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getAutoClear();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAutoClear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFrameRate of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_api_MovieClip_setFrameRate00
static int tolua_api_MovieClip_setFrameRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
  int rate = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFrameRate'", NULL);
#endif
  {
   self->setFrameRate(rate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFrameRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameRate of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_api_MovieClip_getFrameRate00
static int tolua_api_MovieClip_getFrameRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameRate'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getFrameRate();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSymbolInfo of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_api_MovieClip_getSymbolInfo00
static int tolua_api_MovieClip_getSymbolInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSymbolInfo'", NULL);
#endif
  {
   const framework::Symbol* tolua_ret = (const framework::Symbol*)  self->getSymbolInfo();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const framework::Symbol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSymbolInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterPlayEndCallbackHandler of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_api_MovieClip_RegisterPlayEndCallbackHandler00
static int tolua_api_MovieClip_RegisterPlayEndCallbackHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nLuaHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterPlayEndCallbackHandler'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->RegisterPlayEndCallbackHandler(nLuaHandler);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterPlayEndCallbackHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResetKeyframe of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_api_MovieClip_getResetKeyframe00
static int tolua_api_MovieClip_getResetKeyframe00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getResetKeyframe'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getResetKeyframe();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResetKeyframe'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setResetKeyframe of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_api_MovieClip_setResetKeyframe00
static int tolua_api_MovieClip_setResetKeyframe00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
  bool reset = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setResetKeyframe'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setResetKeyframe(reset);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setResetKeyframe'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTimeLength of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_api_MovieClip_getTimeLength00
static int tolua_api_MovieClip_getTimeLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
  int nFrameRate = ((int)  tolua_tonumber(tolua_S,2,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTimeLength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getTimeLength(nFrameRate);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTimeLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameCount of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_api_MovieClip_getFrameCount00
static int tolua_api_MovieClip_getFrameCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getFrameCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getBoundingBox */
#ifndef TOLUA_DISABLE_tolua_api_getBoundingBox00
static int tolua_api_getBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  bool bOrigin = ((bool)  tolua_toboolean(tolua_S,2,false));
  {
   CCRect tolua_ret = (CCRect)  getBoundingBox(node,bOrigin);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCRect));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: toMovieClip */
#ifndef TOLUA_DISABLE_tolua_api_toMovieClip00
static int tolua_api_toMovieClip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  {
   MovieClip* tolua_ret = (MovieClip*)  toMovieClip(node);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"MovieClip");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toMovieClip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: toTLModel */
#ifndef TOLUA_DISABLE_tolua_api_toTLModel00
static int tolua_api_toTLModel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  {
   TLModel* tolua_ret = (TLModel*)  toTLModel(node);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLModel");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toTLModel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: toSprite */
#ifndef TOLUA_DISABLE_tolua_api_toSprite00
static int tolua_api_toSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  {
   CCSprite* tolua_ret = (CCSprite*)  toSprite(node);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: toTTFText */
#ifndef TOLUA_DISABLE_tolua_api_toTTFText00
static int tolua_api_toTTFText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  {
   CCLabelTTF* tolua_ret = (CCLabelTTF*)  toTTFText(node);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCLabelTTF");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toTTFText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: toTLRichTex */
#ifndef TOLUA_DISABLE_tolua_api_toTLRichTex00
static int tolua_api_toTLRichTex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  {
   TLLabelRichTex* tolua_ret = (TLLabelRichTex*)  toTLRichTex(node);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLLabelRichTex");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toTLRichTex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: toBMText */
#ifndef TOLUA_DISABLE_tolua_api_toBMText00
static int tolua_api_toBMText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  {
   CCLabelBMFont* tolua_ret = (CCLabelBMFont*)  toBMText(node);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCLabelBMFont");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toBMText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: toRect */
#ifndef TOLUA_DISABLE_tolua_api_toRect00
static int tolua_api_toRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  {
   CCLayerColor* tolua_ret = (CCLayerColor*)  toRect(node);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCLayerColor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: toFrame */
#ifndef TOLUA_DISABLE_tolua_api_toFrame00
static int tolua_api_toFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  {
   MCFrame* tolua_ret = (MCFrame*)  toFrame(node);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"MCFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: toParticle */
#ifndef TOLUA_DISABLE_tolua_api_toParticle00
static int tolua_api_toParticle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  {
   CCParticleSystem* tolua_ret = (CCParticleSystem*)  toParticle(node);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCParticleSystem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toParticle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: toRenderNode */
#ifndef TOLUA_DISABLE_tolua_api_toRenderNode00
static int tolua_api_toRenderNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  {
   TLRenderNode* tolua_ret = (TLRenderNode*)  toRenderNode(node);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLRenderNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toRenderNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clipNode of class  ClipNode */
#ifndef TOLUA_DISABLE_tolua_api_ClipNode_clipNode00
static int tolua_api_ClipNode_clipNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ClipNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ClipNode* tolua_ret = (ClipNode*)  ClipNode::clipNode();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"ClipNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clipNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clipNode of class  ClipNode */
#ifndef TOLUA_DISABLE_tolua_api_ClipNode_clipNode01
static int tolua_api_ClipNode_clipNode01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ClipNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCRect region = *((CCRect*)  tolua_tousertype(tolua_S,2,0));
  {
   ClipNode* tolua_ret = (ClipNode*)  ClipNode::clipNode(region);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"ClipNode");
  }
 }
 return 1;
tolua_lerror:
 return tolua_api_ClipNode_clipNode00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getClipRegion of class  ClipNode */
#ifndef TOLUA_DISABLE_tolua_api_ClipNode_getClipRegion00
static int tolua_api_ClipNode_getClipRegion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ClipNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ClipNode* self = (ClipNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClipRegion'", NULL);
#endif
  {
   CCRect tolua_ret = (CCRect)  self->getClipRegion();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCRect));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getClipRegion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setClipRegion of class  ClipNode */
#ifndef TOLUA_DISABLE_tolua_api_ClipNode_setClipRegion00
static int tolua_api_ClipNode_setClipRegion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ClipNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ClipNode* self = (ClipNode*)  tolua_tousertype(tolua_S,1,0);
  CCRect region = *((CCRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setClipRegion'", NULL);
#endif
  {
   self->setClipRegion(region);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setClipRegion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeClipRegion of class  ClipNode */
#ifndef TOLUA_DISABLE_tolua_api_ClipNode_removeClipRegion00
static int tolua_api_ClipNode_removeClipRegion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ClipNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ClipNode* self = (ClipNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeClipRegion'", NULL);
#endif
  {
   self->removeClipRegion();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeClipRegion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mcBoundingBox of class  MCFrame */
#ifndef TOLUA_DISABLE_tolua_get_MCFrame_mcBoundingBox
static int tolua_get_MCFrame_mcBoundingBox(lua_State* tolua_S)
{
  MCFrame* self = (MCFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mcBoundingBox'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mcBoundingBox,"CCRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mcBoundingBox of class  MCFrame */
#ifndef TOLUA_DISABLE_tolua_set_MCFrame_mcBoundingBox
static int tolua_set_MCFrame_mcBoundingBox(lua_State* tolua_S)
{
  MCFrame* self = (MCFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mcBoundingBox'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mcBoundingBox = *((CCRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mcOriginBoundingBox of class  MCFrame */
#ifndef TOLUA_DISABLE_tolua_get_MCFrame_mcOriginBoundingBox
static int tolua_get_MCFrame_mcOriginBoundingBox(lua_State* tolua_S)
{
  MCFrame* self = (MCFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mcOriginBoundingBox'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mcOriginBoundingBox,"CCRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mcOriginBoundingBox of class  MCFrame */
#ifndef TOLUA_DISABLE_tolua_set_MCFrame_mcOriginBoundingBox
static int tolua_set_MCFrame_mcOriginBoundingBox(lua_State* tolua_S)
{
  MCFrame* self = (MCFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mcOriginBoundingBox'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mcOriginBoundingBox = *((CCRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithBox of class  MCFrame */
#ifndef TOLUA_DISABLE_tolua_api_MCFrame_createWithBox00
static int tolua_api_MCFrame_createWithBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCFrame",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCRect rect = *((CCRect*)  tolua_tousertype(tolua_S,2,0));
  {
   MCFrame* tolua_ret = (MCFrame*)  MCFrame::createWithBox(rect);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"MCFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithBox of class  MCFrame */
#ifndef TOLUA_DISABLE_tolua_api_MCFrame_initWithBox00
static int tolua_api_MCFrame_initWithBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MCFrame",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MCFrame* self = (MCFrame*)  tolua_tousertype(tolua_S,1,0);
  CCRect rect = *((CCRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithBox'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithBox(rect);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sharedMCLoader of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_api_MCLoader_sharedMCLoader00
static int tolua_api_MCLoader_sharedMCLoader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCLoader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MCLoader* tolua_ret = (MCLoader*)  MCLoader::sharedMCLoader();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"MCLoader");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedMCLoader'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadIndexFile of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_api_MCLoader_loadIndexFile00
static int tolua_api_MCLoader_loadIndexFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MCLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MCLoader* self = (MCLoader*)  tolua_tousertype(tolua_S,1,0);
  const char* animIndexFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* plistIndexFile = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadIndexFile'", NULL);
#endif
  {
   self->loadIndexFile(animIndexFile,plistIndexFile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadIndexFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSymbol of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_api_MCLoader_getSymbol00
static int tolua_api_MCLoader_getSymbol00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MCLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MCLoader* self = (MCLoader*)  tolua_tousertype(tolua_S,1,0);
  const char* animName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSymbol'", NULL);
#endif
  {
   const framework::Symbol* tolua_ret = (const framework::Symbol*)  self->getSymbol(animName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const framework::Symbol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSymbol'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadSpriteFrame of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_api_MCLoader_loadSpriteFrame00
static int tolua_api_MCLoader_loadSpriteFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MCLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MCLoader* self = (MCLoader*)  tolua_tousertype(tolua_S,1,0);
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadSpriteFrame'", NULL);
#endif
  {
   CCSpriteFrame* tolua_ret = (CCSpriteFrame*)  self->loadSpriteFrame(frameName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSpriteFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadSpriteFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadSprite of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_api_MCLoader_loadSprite00
static int tolua_api_MCLoader_loadSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MCLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MCLoader* self = (MCLoader*)  tolua_tousertype(tolua_S,1,0);
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadSprite'", NULL);
#endif
  {
   CCSprite* tolua_ret = (CCSprite*)  self->loadSprite(frameName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadSpriteAsync of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_api_MCLoader_loadSpriteAsync00
static int tolua_api_MCLoader_loadSpriteAsync00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MCLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MCLoader* self = (MCLoader*)  tolua_tousertype(tolua_S,1,0);
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadSpriteAsync'", NULL);
#endif
  {
   CCSprite* tolua_ret = (CCSprite*)  self->loadSpriteAsync(frameName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadSpriteAsync'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadSpriteAsyncCallback of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_api_MCLoader_loadSpriteAsyncCallback00
static int tolua_api_MCLoader_loadSpriteAsyncCallback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MCLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MCLoader* self = (MCLoader*)  tolua_tousertype(tolua_S,1,0);
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,2,0));
  LUA_FUNCTION nCallbackHandler = (  toluafix_ref_function(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadSpriteAsyncCallback'", NULL);
#endif
  {
   CCSprite* tolua_ret = (CCSprite*)  self->loadSpriteAsyncCallback(frameName,nCallbackHandler);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadSpriteAsyncCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadTextureAsync of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_api_MCLoader_loadTextureAsync00
static int tolua_api_MCLoader_loadTextureAsync00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MCLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MCLoader* self = (MCLoader*)  tolua_tousertype(tolua_S,1,0);
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  LUA_FUNCTION scriptCallback = (  toluafix_ref_function(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadTextureAsync'", NULL);
#endif
  {
   self->loadTextureAsync(path,scriptCallback);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadTextureAsync'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadTextureByFrame of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_api_MCLoader_loadTextureByFrame00
static int tolua_api_MCLoader_loadTextureByFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MCLoader",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MCLoader* self = (MCLoader*)  tolua_tousertype(tolua_S,1,0);
  const std::string filePath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadTextureByFrame'", NULL);
#endif
  {
   CCTexture2D* tolua_ret = (CCTexture2D*)  self->loadTextureByFrame(filePath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCTexture2D");
   tolua_pushcppstring(tolua_S,(const char*)filePath);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadTextureByFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadTexture of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_api_MCLoader_loadTexture00
static int tolua_api_MCLoader_loadTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MCLoader",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MCLoader* self = (MCLoader*)  tolua_tousertype(tolua_S,1,0);
  const std::string filepath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadTexture'", NULL);
#endif
  {
   CCTexture2D* tolua_ret = (CCTexture2D*)  self->loadTexture(filepath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCTexture2D");
   tolua_pushcppstring(tolua_S,(const char*)filepath);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTexturePath of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_api_MCLoader_getTexturePath00
static int tolua_api_MCLoader_getTexturePath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MCLoader",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MCLoader* self = (MCLoader*)  tolua_tousertype(tolua_S,1,0);
  const std::string filepath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTexturePath'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getTexturePath(filepath);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)filepath);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTexturePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mcBoundingBox of class  MainSceneRoleMC */
#ifndef TOLUA_DISABLE_tolua_get_MainSceneRoleMC_mcBoundingBox
static int tolua_get_MainSceneRoleMC_mcBoundingBox(lua_State* tolua_S)
{
  MainSceneRoleMC* self = (MainSceneRoleMC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mcBoundingBox'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mcBoundingBox,"CCRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mcBoundingBox of class  MainSceneRoleMC */
#ifndef TOLUA_DISABLE_tolua_set_MainSceneRoleMC_mcBoundingBox
static int tolua_set_MainSceneRoleMC_mcBoundingBox(lua_State* tolua_S)
{
  MainSceneRoleMC* self = (MainSceneRoleMC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mcBoundingBox'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mcBoundingBox = *((CCRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithName of class  MainSceneRoleMC */
#ifndef TOLUA_DISABLE_tolua_api_MainSceneRoleMC_createWithName00
static int tolua_api_MainSceneRoleMC_createWithName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MainSceneRoleMC",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"CCSpriteBatchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* mcStandName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* mcWalkName = ((const char*)  tolua_tostring(tolua_S,3,0));
  CCSpriteBatchNode* pkBatchNode = ((CCSpriteBatchNode*)  tolua_tousertype(tolua_S,4,0));
  {
   MainSceneRoleMC* tolua_ret = (MainSceneRoleMC*)  MainSceneRoleMC::createWithName(mcStandName,mcWalkName,pkBatchNode);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"MainSceneRoleMC");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playStand of class  MainSceneRoleMC */
#ifndef TOLUA_DISABLE_tolua_api_MainSceneRoleMC_playStand00
static int tolua_api_MainSceneRoleMC_playStand00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MainSceneRoleMC",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MainSceneRoleMC* self = (MainSceneRoleMC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playStand'", NULL);
#endif
  {
   self->playStand();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playStand'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playWalk of class  MainSceneRoleMC */
#ifndef TOLUA_DISABLE_tolua_api_MainSceneRoleMC_playWalk00
static int tolua_api_MainSceneRoleMC_playWalk00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MainSceneRoleMC",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MainSceneRoleMC* self = (MainSceneRoleMC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playWalk'", NULL);
#endif
  {
   self->playWalk();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playWalk'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFrameRate of class  MainSceneRoleMC */
#ifndef TOLUA_DISABLE_tolua_api_MainSceneRoleMC_setFrameRate00
static int tolua_api_MainSceneRoleMC_setFrameRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MainSceneRoleMC",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MainSceneRoleMC* self = (MainSceneRoleMC*)  tolua_tousertype(tolua_S,1,0);
  int nStandRate = ((int)  tolua_tonumber(tolua_S,2,0));
  int nWalkRate = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFrameRate'", NULL);
#endif
  {
   self->setFrameRate(nStandRate,nWalkRate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFrameRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFlipX of class  MainSceneRoleMC */
#ifndef TOLUA_DISABLE_tolua_api_MainSceneRoleMC_setFlipX00
static int tolua_api_MainSceneRoleMC_setFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MainSceneRoleMC",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MainSceneRoleMC* self = (MainSceneRoleMC*)  tolua_tousertype(tolua_S,1,0);
  bool bFlipX = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFlipX'", NULL);
#endif
  {
   self->setFlipX(bFlipX);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFlipX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFlipY of class  MainSceneRoleMC */
#ifndef TOLUA_DISABLE_tolua_api_MainSceneRoleMC_setFlipY00
static int tolua_api_MainSceneRoleMC_setFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MainSceneRoleMC",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MainSceneRoleMC* self = (MainSceneRoleMC*)  tolua_tousertype(tolua_S,1,0);
  bool bFlipY = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFlipY'", NULL);
#endif
  {
   self->setFlipY(bFlipY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFlipY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRoleSprite of class  MainSceneRoleMC */
#ifndef TOLUA_DISABLE_tolua_api_MainSceneRoleMC_getRoleSprite00
static int tolua_api_MainSceneRoleMC_getRoleSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MainSceneRoleMC",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MainSceneRoleMC* self = (MainSceneRoleMC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRoleSprite'", NULL);
#endif
  {
   CCSprite* tolua_ret = (CCSprite*)  self->getRoleSprite();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRoleSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRoleSpriteOffsetX of class  MainSceneRoleMC */
#ifndef TOLUA_DISABLE_tolua_api_MainSceneRoleMC_setRoleSpriteOffsetX00
static int tolua_api_MainSceneRoleMC_setRoleSpriteOffsetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MainSceneRoleMC",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MainSceneRoleMC* self = (MainSceneRoleMC*)  tolua_tousertype(tolua_S,1,0);
  float offsetX = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRoleSpriteOffsetX'", NULL);
#endif
  {
   self->setRoleSpriteOffsetX(offsetX);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRoleSpriteOffsetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRoleSpriteOffsetX of class  MainSceneRoleMC */
#ifndef TOLUA_DISABLE_tolua_api_MainSceneRoleMC_getRoleSpriteOffsetX00
static int tolua_api_MainSceneRoleMC_getRoleSpriteOffsetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MainSceneRoleMC",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MainSceneRoleMC* self = (MainSceneRoleMC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRoleSpriteOffsetX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getRoleSpriteOffsetX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRoleSpriteOffsetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRoleSpriteOffsetY of class  MainSceneRoleMC */
#ifndef TOLUA_DISABLE_tolua_api_MainSceneRoleMC_setRoleSpriteOffsetY00
static int tolua_api_MainSceneRoleMC_setRoleSpriteOffsetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MainSceneRoleMC",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MainSceneRoleMC* self = (MainSceneRoleMC*)  tolua_tousertype(tolua_S,1,0);
  float offsetY = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRoleSpriteOffsetY'", NULL);
#endif
  {
   self->setRoleSpriteOffsetY(offsetY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRoleSpriteOffsetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRoleSpriteOffsetY of class  MainSceneRoleMC */
#ifndef TOLUA_DISABLE_tolua_api_MainSceneRoleMC_getRoleSpriteOffsetY00
static int tolua_api_MainSceneRoleMC_getRoleSpriteOffsetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MainSceneRoleMC",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MainSceneRoleMC* self = (MainSceneRoleMC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRoleSpriteOffsetY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getRoleSpriteOffsetY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRoleSpriteOffsetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetRoleSpritePosition of class  MainSceneRoleMC */
#ifndef TOLUA_DISABLE_tolua_api_MainSceneRoleMC_resetRoleSpritePosition00
static int tolua_api_MainSceneRoleMC_resetRoleSpritePosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MainSceneRoleMC",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MainSceneRoleMC* self = (MainSceneRoleMC*)  tolua_tousertype(tolua_S,1,0);
  bool resetDisplaySpriteFrame = ((bool)  tolua_toboolean(tolua_S,2,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetRoleSpritePosition'", NULL);
#endif
  {
   self->resetRoleSpritePosition(resetDisplaySpriteFrame);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetRoleSpritePosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sharedTLFontTex of class  TLFontTex */
#ifndef TOLUA_DISABLE_tolua_api_TLFontTex_sharedTLFontTex00
static int tolua_api_TLFontTex_sharedTLFontTex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLFontTex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLFontTex* tolua_ret = (TLFontTex*)  TLFontTex::sharedTLFontTex();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLFontTex");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedTLFontTex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: newBatchNode of class  TLFontTex */
#ifndef TOLUA_DISABLE_tolua_api_TLFontTex_newBatchNode00
static int tolua_api_TLFontTex_newBatchNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLFontTex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLFontTex* self = (TLFontTex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'newBatchNode'", NULL);
#endif
  {
   CCSpriteBatchNode* tolua_ret = (CCSpriteBatchNode*)  self->newBatchNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSpriteBatchNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'newBatchNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initFontTexture of class  TLFontTex */
#ifndef TOLUA_DISABLE_tolua_api_TLFontTex_initFontTexture00
static int tolua_api_TLFontTex_initFontTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLFontTex",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isstring(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLFontTex* self = (TLFontTex*)  tolua_tousertype(tolua_S,1,0);
  const char* pFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  int nRow = ((int)  tolua_tonumber(tolua_S,3,0));
  int nCol = ((int)  tolua_tonumber(tolua_S,4,0));
  const char* szShaderName = ((const char*)  tolua_tostring(tolua_S,5,0));
  const char* szFontShaderName = ((const char*)  tolua_tostring(tolua_S,6,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initFontTexture'", NULL);
#endif
  {
   self->initFontTexture(pFile,nRow,nCol,szShaderName,szFontShaderName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initFontTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getChatTextInfo of class  TLFontTex */
#ifndef TOLUA_DISABLE_tolua_api_TLFontTex_getChatTextInfo00
static int tolua_api_TLFontTex_getChatTextInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLFontTex",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLFontTex* self = (TLFontTex*)  tolua_tousertype(tolua_S,1,0);
  const char* p = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getChatTextInfo'", NULL);
#endif
  {
   chatTexInfo* tolua_ret = (chatTexInfo*)  self->getChatTextInfo(p);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"chatTexInfo");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getChatTextInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFontScale of class  TLFontTex */
#ifndef TOLUA_DISABLE_tolua_api_TLFontTex_getFontScale00
static int tolua_api_TLFontTex_getFontScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLFontTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLFontTex* self = (TLFontTex*)  tolua_tousertype(tolua_S,1,0);
  float fInFontSize = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFontScale'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getFontScale(fInFontSize);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFontScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: saveFontTexture of class  TLFontTex */
#ifndef TOLUA_DISABLE_tolua_api_TLFontTex_saveFontTexture00
static int tolua_api_TLFontTex_saveFontTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLFontTex",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLFontTex* self = (TLFontTex*)  tolua_tousertype(tolua_S,1,0);
  const char* szFilePath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'saveFontTexture'", NULL);
#endif
  {
   self->saveFontTexture(szFilePath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveFontTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFontOriginSize of class  TLFontTex */
#ifndef TOLUA_DISABLE_tolua_api_TLFontTex_setFontOriginSize00
static int tolua_api_TLFontTex_setFontOriginSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLFontTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float fFontOriginSize = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   TLFontTex::setFontOriginSize(fFontOriginSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFontOriginSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFontName of class  TLFontTex */
#ifndef TOLUA_DISABLE_tolua_api_TLFontTex_setFontName00
static int tolua_api_TLFontTex_setFontName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLFontTex",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string strFontName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   TLFontTex::setFontName(strFontName);
   tolua_pushcppstring(tolua_S,(const char*)strFontName);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFontName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEdgeSize of class  TLFontTex */
#ifndef TOLUA_DISABLE_tolua_api_TLFontTex_setEdgeSize00
static int tolua_api_TLFontTex_setEdgeSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLFontTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int nEdgeSize = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   TLFontTex::setEdgeSize(nEdgeSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEdgeSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStrokeEdge of class  TLFontTex */
#ifndef TOLUA_DISABLE_tolua_api_TLFontTex_setStrokeEdge00
static int tolua_api_TLFontTex_setStrokeEdge00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLFontTex",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool nEdgeSize = ((bool)  tolua_toboolean(tolua_S,2,0));
  {
   TLFontTex::setStrokeEdge(nEdgeSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStrokeEdge'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setParseRichTextHandler of class  TLFontTex */
#ifndef TOLUA_DISABLE_tolua_api_TLFontTex_setParseRichTextHandler00
static int tolua_api_TLFontTex_setParseRichTextHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLFontTex",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LUA_FUNCTION nParseHandle = (  toluafix_ref_function(tolua_S,2,0));
  {
   TLFontTex::setParseRichTextHandler(nParseHandle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setParseRichTextHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_create00
static int tolua_api_TLLabelRichTex_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fFontSize = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   TLLabelRichTex* tolua_ret = (TLLabelRichTex*)  TLLabelRichTex::create(str,fFontSize);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLLabelRichTex");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_create01
static int tolua_api_TLLabelRichTex_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fFontSize = ((float)  tolua_tonumber(tolua_S,3,0));
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,4,0));
  {
   TLLabelRichTex* tolua_ret = (TLLabelRichTex*)  TLLabelRichTex::create(str,fFontSize,*size);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLLabelRichTex");
  }
 }
 return 1;
tolua_lerror:
 return tolua_api_TLLabelRichTex_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_create02
static int tolua_api_TLLabelRichTex_create02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCSize",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"TLWindow",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fFontSize = ((float)  tolua_tonumber(tolua_S,3,0));
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,4,0));
  CCImage::ETextAlign alignment = ((CCImage::ETextAlign) (int)  tolua_tonumber(tolua_S,5,0));
  TLWindow* pWindow = ((TLWindow*)  tolua_tousertype(tolua_S,6,NULL));
  {
   TLLabelRichTex* tolua_ret = (TLLabelRichTex*)  TLLabelRichTex::create(str,fFontSize,*size,alignment,pWindow);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLLabelRichTex");
   tolua_pushnumber(tolua_S,(lua_Number)alignment);
  }
 }
 return 2;
tolua_lerror:
 return tolua_api_TLLabelRichTex_create01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRichString of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_setRichString00
static int tolua_api_TLLabelRichTex_setRichString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  TL_RICH_STRING_FLAG eRichStringFlag = ((TL_RICH_STRING_FLAG) (int)  tolua_tonumber(tolua_S,3,TL_RICH_STRING_FLAG_AUTO_WRAP));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRichString'", NULL);
#endif
  {
   self->setRichString(str,eRichStringFlag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRichString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRichString of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_getRichString00
static int tolua_api_TLLabelRichTex_getRichString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRichString'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getRichString();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRichString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFontSize of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_setFontSize00
static int tolua_api_TLLabelRichTex_setFontSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  float fFontSize = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFontSize'", NULL);
#endif
  {
   self->setFontSize(fFontSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFontSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFontSize of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_getFontSize00
static int tolua_api_TLLabelRichTex_getFontSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFontSize'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getFontSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFontSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlignment of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_setAlignment00
static int tolua_api_TLLabelRichTex_setAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  CCImage::ETextAlign eAlignment = ((CCImage::ETextAlign) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlignment'", NULL);
#endif
  {
   self->setAlignment(eAlignment);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAlignment of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_getAlignment00
static int tolua_api_TLLabelRichTex_getAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAlignment'", NULL);
#endif
  {
   CCImage::ETextAlign tolua_ret = (CCImage::ETextAlign)  self->getAlignment();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFontColorR of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_setFontColorR00
static int tolua_api_TLLabelRichTex_setFontColorR00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  unsigned const char r = ((unsigned const char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFontColorR'", NULL);
#endif
  {
   self->setFontColorR(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFontColorR'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFontColorG of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_setFontColorG00
static int tolua_api_TLLabelRichTex_setFontColorG00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  unsigned const char g = ((unsigned const char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFontColorG'", NULL);
#endif
  {
   self->setFontColorG(g);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFontColorG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFontColorB of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_setFontColorB00
static int tolua_api_TLLabelRichTex_setFontColorB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  unsigned const char b = ((unsigned const char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFontColorB'", NULL);
#endif
  {
   self->setFontColorB(b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFontColorB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFontColorA of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_setFontColorA00
static int tolua_api_TLLabelRichTex_setFontColorA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  unsigned const char a = ((unsigned const char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFontColorA'", NULL);
#endif
  {
   self->setFontColorA(a);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFontColorA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveOffsetX of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_moveOffsetX00
static int tolua_api_TLLabelRichTex_moveOffsetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  float offset = ((float)  tolua_tonumber(tolua_S,2,0));
  bool flag = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveOffsetX'", NULL);
#endif
  {
   self->moveOffsetX(offset,flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveOffsetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: appendSpriteToCurrentLine of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_appendSpriteToCurrentLine00
static int tolua_api_TLLabelRichTex_appendSpriteToCurrentLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  CCNode* pkNode = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
  float width = ((float)  tolua_tonumber(tolua_S,3,0.0f));
  float height = ((float)  tolua_tonumber(tolua_S,4,0.0f));
  float offsetX = ((float)  tolua_tonumber(tolua_S,5,0.0f));
  bool layout = ((bool)  tolua_toboolean(tolua_S,6,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendSpriteToCurrentLine'", NULL);
#endif
  {
   self->appendSpriteToCurrentLine(pkNode,width,height,offsetX,layout);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendSpriteToCurrentLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: appendText of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_appendText00
static int tolua_api_TLLabelRichTex_appendText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  const char* szText = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendText'", NULL);
#endif
  {
   self->appendText(szText);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRealSize of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_getRealSize00
static int tolua_api_TLLabelRichTex_getRealSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRealSize'", NULL);
#endif
  {
   CCSize tolua_ret = (CCSize)  self->getRealSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRealSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: adjustLayout of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_adjustLayout00
static int tolua_api_TLLabelRichTex_adjustLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'adjustLayout'", NULL);
#endif
  {
   self->adjustLayout();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'adjustLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: appendLine of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_appendLine00
static int tolua_api_TLLabelRichTex_appendLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  bool bForcibly = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendLine'", NULL);
#endif
  {
   self->appendLine(bForcibly);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWindow of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_getWindow00
static int tolua_api_TLLabelRichTex_getWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWindow'", NULL);
#endif
  {
   TLWindow* tolua_ret = (TLWindow*)  self->getWindow();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindow");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWindow of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_setWindow00
static int tolua_api_TLLabelRichTex_setWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  TLWindow* pWindow = ((TLWindow*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWindow'", NULL);
#endif
  {
   self->setWindow(pWindow);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCurrentNodeHandler of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_setCurrentNodeHandler00
static int tolua_api_TLLabelRichTex_setCurrentNodeHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nNodeHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCurrentNodeHandler'", NULL);
#endif
  {
   self->setCurrentNodeHandler(nNodeHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCurrentNodeHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearCurrentNodeHandler of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_clearCurrentNodeHandler00
static int tolua_api_TLLabelRichTex_clearCurrentNodeHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearCurrentNodeHandler'", NULL);
#endif
  {
   self->clearCurrentNodeHandler();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearCurrentNodeHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRealSizeLayout of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_setRealSizeLayout00
static int tolua_api_TLLabelRichTex_setRealSizeLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  bool bRealSizeLayout = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRealSizeLayout'", NULL);
#endif
  {
   self->setRealSizeLayout(bRealSizeLayout);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRealSizeLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTabNum of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_setTabNum00
static int tolua_api_TLLabelRichTex_setTabNum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  int nTabNum = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTabNum'", NULL);
#endif
  {
   self->setTabNum(nTabNum);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTabNum'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWordSpacing of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_setWordSpacing00
static int tolua_api_TLLabelRichTex_setWordSpacing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  int nWordSpacing = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWordSpacing'", NULL);
#endif
  {
   self->setWordSpacing(nWordSpacing);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWordSpacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLineSpacing of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_setLineSpacing00
static int tolua_api_TLLabelRichTex_setLineSpacing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  int nLineSpacing = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLineSpacing'", NULL);
#endif
  {
   self->setLineSpacing(nLineSpacing);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLineSpacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColorIndex of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_setColorIndex00
static int tolua_api_TLLabelRichTex_setColorIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  int nColorIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColorIndex'", NULL);
#endif
  {
   self->setColorIndex(nColorIndex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColorIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColorIndex of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_getColorIndex00
static int tolua_api_TLLabelRichTex_getColorIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TLLabelRichTex* self = (const TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColorIndex'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getColorIndex();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColorIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: changeColorIndex of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_changeColorIndex00
static int tolua_api_TLLabelRichTex_changeColorIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
  int nColorIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeColorIndex'", NULL);
#endif
  {
   self->changeColorIndex(nColorIndex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeColorIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextNode of class  TLLabelRichTex */
#ifndef TOLUA_DISABLE_tolua_api_TLLabelRichTex_getTextNode00
static int tolua_api_TLLabelRichTex_getTextNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLLabelRichTex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLLabelRichTex* self = (TLLabelRichTex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextNode'", NULL);
#endif
  {
   CCNode* tolua_ret = (CCNode*)  self->getTextNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  TLRichTexVerbatim */
#ifndef TOLUA_DISABLE_tolua_api_TLRichTexVerbatim_create00
static int tolua_api_TLRichTexVerbatim_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLRichTexVerbatim",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fFontSize = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   TLRichTexVerbatim* tolua_ret = (TLRichTexVerbatim*)  TLRichTexVerbatim::create(str,fFontSize);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLRichTexVerbatim");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  TLRichTexVerbatim */
#ifndef TOLUA_DISABLE_tolua_api_TLRichTexVerbatim_create01
static int tolua_api_TLRichTexVerbatim_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLRichTexVerbatim",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fFontSize = ((float)  tolua_tonumber(tolua_S,3,0));
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,4,0));
  {
   TLRichTexVerbatim* tolua_ret = (TLRichTexVerbatim*)  TLRichTexVerbatim::create(str,fFontSize,*size);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLRichTexVerbatim");
  }
 }
 return 1;
tolua_lerror:
 return tolua_api_TLRichTexVerbatim_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  TLRichTexVerbatim */
#ifndef TOLUA_DISABLE_tolua_api_TLRichTexVerbatim_create02
static int tolua_api_TLRichTexVerbatim_create02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLRichTexVerbatim",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCSize",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fFontSize = ((float)  tolua_tonumber(tolua_S,3,0));
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,4,0));
  const CCImage::ETextAlign alignment = ((const CCImage::ETextAlign) (int)  tolua_tonumber(tolua_S,5,0));
  {
   TLRichTexVerbatim* tolua_ret = (TLRichTexVerbatim*)  TLRichTexVerbatim::create(str,fFontSize,*size,alignment);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLRichTexVerbatim");
   tolua_pushnumber(tolua_S,(lua_Number)alignment);
  }
 }
 return 2;
tolua_lerror:
 return tolua_api_TLRichTexVerbatim_create01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRichString of class  TLRichTexVerbatim */
#ifndef TOLUA_DISABLE_tolua_api_TLRichTexVerbatim_setRichString00
static int tolua_api_TLRichTexVerbatim_setRichString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLRichTexVerbatim",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLRichTexVerbatim* self = (TLRichTexVerbatim*)  tolua_tousertype(tolua_S,1,0);
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  TL_RICH_STRING_FLAG eRichStringFlag = ((TL_RICH_STRING_FLAG) (int)  tolua_tonumber(tolua_S,3,TL_RICH_STRING_FLAG_AUTO_WRAP));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRichString'", NULL);
#endif
  {
   self->setRichString(str,eRichStringFlag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRichString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSpeed of class  TLRichTexVerbatim */
#ifndef TOLUA_DISABLE_tolua_api_TLRichTexVerbatim_setSpeed00
static int tolua_api_TLRichTexVerbatim_setSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLRichTexVerbatim",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLRichTexVerbatim* self = (TLRichTexVerbatim*)  tolua_tousertype(tolua_S,1,0);
  float nSpeed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpeed'", NULL);
#endif
  {
   self->setSpeed(nSpeed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: play of class  TLRichTexVerbatim */
#ifndef TOLUA_DISABLE_tolua_api_TLRichTexVerbatim_play00
static int tolua_api_TLRichTexVerbatim_play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLRichTexVerbatim",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLRichTexVerbatim* self = (TLRichTexVerbatim*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nPlayEndHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'play'", NULL);
#endif
  {
   self->play(nPlayEndHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  TLRichTexVerbatim */
#ifndef TOLUA_DISABLE_tolua_api_TLRichTexVerbatim_stop00
static int tolua_api_TLRichTexVerbatim_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLRichTexVerbatim",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLRichTexVerbatim* self = (TLRichTexVerbatim*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isEnd of class  TLRichTexVerbatim */
#ifndef TOLUA_DISABLE_tolua_api_TLRichTexVerbatim_isEnd00
static int tolua_api_TLRichTexVerbatim_isEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLRichTexVerbatim",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLRichTexVerbatim* self = (TLRichTexVerbatim*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isEnd'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isEnd();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fastEnd of class  TLRichTexVerbatim */
#ifndef TOLUA_DISABLE_tolua_api_TLRichTexVerbatim_fastEnd00
static int tolua_api_TLRichTexVerbatim_fastEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLRichTexVerbatim",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLRichTexVerbatim* self = (TLRichTexVerbatim*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fastEnd'", NULL);
#endif
  {
   self->fastEnd();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fastEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMsgID of class  CNetMsg */
#ifndef TOLUA_DISABLE_tolua_api_CNetMsg_GetMsgID00
static int tolua_api_CNetMsg_GetMsgID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CNetMsg",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CNetMsg* self = (const CNetMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMsgID'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->GetMsgID();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMsgID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMsgCode of class  CNetMsg */
#ifndef TOLUA_DISABLE_tolua_api_CNetMsg_GetMsgCode00
static int tolua_api_CNetMsg_GetMsgCode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CNetMsg",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CNetMsg* self = (const CNetMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMsgCode'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->GetMsgCode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMsgCode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ParseContent of class  CNetMsg */
#ifndef TOLUA_DISABLE_tolua_api_CNetMsg_ParseContent00
static int tolua_api_CNetMsg_ParseContent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetMsg",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"::google::protobuf::MessageLite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetMsg* self = (CNetMsg*)  tolua_tousertype(tolua_S,1,0);
 ::google::protobuf::MessageLite* pMsg = ((::google::protobuf::MessageLite*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ParseContent'", NULL);
#endif
  {
   self->ParseContent(pMsg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ParseContent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetContentLength of class  CNetMsg */
#ifndef TOLUA_DISABLE_tolua_api_CNetMsg_GetContentLength00
static int tolua_api_CNetMsg_GetContentLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetMsg",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetMsg* self = (CNetMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetContentLength'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->GetContentLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetContentLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetContentData of class  CNetMsg */
#ifndef TOLUA_DISABLE_tolua_api_CNetMsg_GetContentData00
static int tolua_api_CNetMsg_GetContentData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetMsg",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetMsg* self = (CNetMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetContentData'", NULL);
#endif
  {
   void* tolua_ret = (void*)  self->GetContentData();
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetContentData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetContentStr of class  CNetMsg */
#ifndef TOLUA_DISABLE_tolua_api_CNetMsg_GetContentStr00
static int tolua_api_CNetMsg_GetContentStr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetMsg",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetMsg* self = (CNetMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetContentStr'", NULL);
#endif
  {
   char* tolua_ret = (char*)  self->GetContentStr();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetContentStr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SharedNetReceiver of class  CNetReceiver */
#ifndef TOLUA_DISABLE_tolua_api_CNetReceiver_SharedNetReceiver00
static int tolua_api_CNetReceiver_SharedNetReceiver00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CNetReceiver",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CNetReceiver* tolua_ret = (CNetReceiver*)  CNetReceiver::SharedNetReceiver();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CNetReceiver");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SharedNetReceiver'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMsgErrorDefaultFuncPtr of class  CNetReceiver */
#ifndef TOLUA_DISABLE_tolua_api_CNetReceiver_SetMsgErrorDefaultFuncPtr00
static int tolua_api_CNetReceiver_SetMsgErrorDefaultFuncPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetReceiver",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetReceiver* self = (CNetReceiver*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nLuaHandle = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMsgErrorDefaultFuncPtr'", NULL);
#endif
  {
   self->SetMsgErrorDefaultFuncPtr(nLuaHandle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMsgErrorDefaultFuncPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterMsgErrorFuncPtr of class  CNetReceiver */
#ifndef TOLUA_DISABLE_tolua_api_CNetReceiver_RegisterMsgErrorFuncPtr00
static int tolua_api_CNetReceiver_RegisterMsgErrorFuncPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetReceiver",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetReceiver* self = (CNetReceiver*)  tolua_tousertype(tolua_S,1,0);
  int nMsgCode = ((int)  tolua_tonumber(tolua_S,2,0));
  LUA_FUNCTION nLuaHandle = (  toluafix_ref_function(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterMsgErrorFuncPtr'", NULL);
#endif
  {
   self->RegisterMsgErrorFuncPtr(nMsgCode,nLuaHandle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterMsgErrorFuncPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterMsgProcessFuncPtr of class  CNetReceiver */
#ifndef TOLUA_DISABLE_tolua_api_CNetReceiver_RegisterMsgProcessFuncPtr00
static int tolua_api_CNetReceiver_RegisterMsgProcessFuncPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetReceiver",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetReceiver* self = (CNetReceiver*)  tolua_tousertype(tolua_S,1,0);
  unsigned short nMsgID = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
  LUA_FUNCTION nLuaHandler = (  toluafix_ref_function(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterMsgProcessFuncPtr'", NULL);
#endif
  {
   self->RegisterMsgProcessFuncPtr(nMsgID,nLuaHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterMsgProcessFuncPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendErrorMsgToSelf of class  CNetReceiver */
#ifndef TOLUA_DISABLE_tolua_api_CNetReceiver_SendErrorMsgToSelf00
static int tolua_api_CNetReceiver_SendErrorMsgToSelf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetReceiver",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetReceiver* self = (CNetReceiver*)  tolua_tousertype(tolua_S,1,0);
  unsigned int uiMsgCode = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendErrorMsgToSelf'", NULL);
#endif
  {
   self->SendErrorMsgToSelf(uiMsgCode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SendErrorMsgToSelf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendMsgToSelf of class  CNetReceiver */
#ifndef TOLUA_DISABLE_tolua_api_CNetReceiver_SendMsgToSelf00
static int tolua_api_CNetReceiver_SendMsgToSelf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetReceiver",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetReceiver* self = (CNetReceiver*)  tolua_tousertype(tolua_S,1,0);
  unsigned int msgID = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  const char* pszMsgData = ((const char*)  tolua_tostring(tolua_S,3,NULL));
  int nLength = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendMsgToSelf'", NULL);
#endif
  {
   self->SendMsgToSelf(msgID,pszMsgData,nLength);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SendMsgToSelf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Reset of class  CNetReceiver */
#ifndef TOLUA_DISABLE_tolua_api_CNetReceiver_Reset00
static int tolua_api_CNetReceiver_Reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetReceiver",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetReceiver* self = (CNetReceiver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Reset'", NULL);
#endif
  {
   self->Reset();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SharedNetSender of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_api_CNetSender_SharedNetSender00
static int tolua_api_CNetSender_SharedNetSender00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CNetSender",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CNetSender* tolua_ret = (CNetSender*)  CNetSender::SharedNetSender();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CNetSender");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SharedNetSender'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CloseSocket of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_api_CNetSender_CloseSocket00
static int tolua_api_CNetSender_CloseSocket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetSender",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetSender* self = (CNetSender*)  tolua_tousertype(tolua_S,1,0);
  NetWordThreadStatus state = ((NetWordThreadStatus) (int)  tolua_tonumber(tolua_S,2,NWTS_CLOSED));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CloseSocket'", NULL);
#endif
  {
   self->CloseSocket(state);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CloseSocket'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Connect of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_api_CNetSender_Connect00
static int tolua_api_CNetSender_Connect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetSender",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetSender* self = (CNetSender*)  tolua_tousertype(tolua_S,1,0);
  const char* szIPAddr = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned int uiPort = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Connect'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Connect(szIPAddr,uiPort);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Connect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NewNetMsgAndSend of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_api_CNetSender_NewNetMsgAndSend00
static int tolua_api_CNetSender_NewNetMsgAndSend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetSender",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !toluafix_isfunction(tolua_S,5,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetSender* self = (CNetSender*)  tolua_tousertype(tolua_S,1,0);
  unsigned int msgID = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  const char* buffer = ((const char*)  tolua_tostring(tolua_S,3,0));
  int size = ((int)  tolua_tonumber(tolua_S,4,0));
  LUA_FUNCTION nCallBackHandler = (  toluafix_ref_function(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NewNetMsgAndSend'", NULL);
#endif
  {
   self->NewNetMsgAndSend(msgID,buffer,size,nCallBackHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NewNetMsgAndSend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: appendReconnectVerifyMsgID of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_api_CNetSender_appendReconnectVerifyMsgID00
static int tolua_api_CNetSender_appendReconnectVerifyMsgID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetSender",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetSender* self = (CNetSender*)  tolua_tousertype(tolua_S,1,0);
  unsigned int msgID = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendReconnectVerifyMsgID'", NULL);
#endif
  {
   self->appendReconnectVerifyMsgID(msgID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendReconnectVerifyMsgID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIsNeedReconnection of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_api_CNetSender_setIsNeedReconnection00
static int tolua_api_CNetSender_setIsNeedReconnection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetSender",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetSender* self = (CNetSender*)  tolua_tousertype(tolua_S,1,0);
  bool bIsNeedReconnection = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIsNeedReconnection'", NULL);
#endif
  {
   self->setIsNeedReconnection(bIsNeedReconnection);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIsNeedReconnection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIsNeedReconnection of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_api_CNetSender_getIsNeedReconnection00
static int tolua_api_CNetSender_getIsNeedReconnection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CNetSender",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CNetSender* self = (const CNetSender*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIsNeedReconnection'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getIsNeedReconnection();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIsNeedReconnection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSocketStatus of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_api_CNetSender_setSocketStatus00
static int tolua_api_CNetSender_setSocketStatus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetSender",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetSender* self = (CNetSender*)  tolua_tousertype(tolua_S,1,0);
  NetWordThreadStatus status = ((NetWordThreadStatus) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSocketStatus'", NULL);
#endif
  {
   self->setSocketStatus(status);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSocketStatus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSocketStatus of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_api_CNetSender_getSocketStatus00
static int tolua_api_CNetSender_getSocketStatus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetSender",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetSender* self = (CNetSender*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSocketStatus'", NULL);
#endif
  {
   NetWordThreadStatus tolua_ret = (NetWordThreadStatus)  self->getSocketStatus();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSocketStatus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reconnectionVerify of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_api_CNetSender_reconnectionVerify00
static int tolua_api_CNetSender_reconnectionVerify00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetSender",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetSender* self = (CNetSender*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reconnectionVerify'", NULL);
#endif
  {
   self->reconnectionVerify();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reconnectionVerify'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reconnectionSucceeful of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_api_CNetSender_reconnectionSucceeful00
static int tolua_api_CNetSender_reconnectionSucceeful00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetSender",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetSender* self = (CNetSender*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reconnectionSucceeful'", NULL);
#endif
  {
   self->reconnectionSucceeful();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reconnectionSucceeful'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setClearMsgIDHandler of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_api_CNetSender_setClearMsgIDHandler00
static int tolua_api_CNetSender_setClearMsgIDHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetSender",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetSender* self = (CNetSender*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setClearMsgIDHandler'", NULL);
#endif
  {
   self->setClearMsgIDHandler(nHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setClearMsgIDHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sharedHttpDownloader of class  CHttpDownloader */
#ifndef TOLUA_DISABLE_tolua_api_CHttpDownloader_sharedHttpDownloader00
static int tolua_api_CHttpDownloader_sharedHttpDownloader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CHttpDownloader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CHttpDownloader* tolua_ret = (CHttpDownloader*)  CHttpDownloader::sharedHttpDownloader();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CHttpDownloader");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedHttpDownloader'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: purgeSharedHttpDownloader of class  CHttpDownloader */
#ifndef TOLUA_DISABLE_tolua_api_CHttpDownloader_purgeSharedHttpDownloader00
static int tolua_api_CHttpDownloader_purgeSharedHttpDownloader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CHttpDownloader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CHttpDownloader::purgeSharedHttpDownloader();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'purgeSharedHttpDownloader'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getContent of class  CHttpDownloader */
#ifndef TOLUA_DISABLE_tolua_api_CHttpDownloader_getContent00
static int tolua_api_CHttpDownloader_getContent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CHttpDownloader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CHttpDownloader* self = (CHttpDownloader*)  tolua_tousertype(tolua_S,1,0);
  const char* sUrl = ((const char*)  tolua_tostring(tolua_S,2,0));
  int nTag = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getContent'", NULL);
#endif
  {
   self->getContent(sUrl,nTag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getContent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: saveToFile of class  CHttpDownloader */
#ifndef TOLUA_DISABLE_tolua_api_CHttpDownloader_saveToFile00
static int tolua_api_CHttpDownloader_saveToFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CHttpDownloader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CHttpDownloader* self = (CHttpDownloader*)  tolua_tousertype(tolua_S,1,0);
  const char* sUrl = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* sSaveTo = ((const char*)  tolua_tostring(tolua_S,3,0));
  int nTag = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'saveToFile'", NULL);
#endif
  {
   self->saveToFile(sUrl,sSaveTo,nTag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveToFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: register_callback of class  CHttpDownloader */
#ifndef TOLUA_DISABLE_tolua_api_CHttpDownloader_register_callback00
static int tolua_api_CHttpDownloader_register_callback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CHttpDownloader",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CHttpDownloader* self = (CHttpDownloader*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'register_callback'", NULL);
#endif
  {
   self->register_callback(handler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'register_callback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: register_progress_callback of class  CHttpDownloader */
#ifndef TOLUA_DISABLE_tolua_api_CHttpDownloader_register_progress_callback00
static int tolua_api_CHttpDownloader_register_progress_callback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CHttpDownloader",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CHttpDownloader* self = (CHttpDownloader*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'register_progress_callback'", NULL);
#endif
  {
   self->register_progress_callback(handler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'register_progress_callback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRequestType of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_api_HttpRequest_getRequestType00
static int tolua_api_HttpRequest_getRequestType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRequestType'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getRequestType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRequestType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAppendToRecv of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_api_HttpRequest_getAppendToRecv00
static int tolua_api_HttpRequest_getAppendToRecv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAppendToRecv'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getAppendToRecv();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAppendToRecv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_opt of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_api_HttpRequest_set_opt00
static int tolua_api_HttpRequest_set_opt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CURL",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
  CURL* curl = ((CURL*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_opt'", NULL);
#endif
  {
   self->set_opt(curl);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_opt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRecvBuffer of class  HttpRequestMsg */
#ifndef TOLUA_DISABLE_tolua_api_HttpRequestMsg_setRecvBuffer00
static int tolua_api_HttpRequestMsg_setRecvBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpRequestMsg",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpRequestMsg* self = (HttpRequestMsg*)  tolua_tousertype(tolua_S,1,0);
  const char* szRevcBuf = ((const char*)  tolua_tostring(tolua_S,2,NULL));
  unsigned int nLength = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRecvBuffer'", NULL);
#endif
  {
   self->setRecvBuffer(szRevcBuf,nLength);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRecvBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSendBuffer of class  HttpRequestMsg */
#ifndef TOLUA_DISABLE_tolua_api_HttpRequestMsg_setSendBuffer00
static int tolua_api_HttpRequestMsg_setSendBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpRequestMsg",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpRequestMsg* self = (HttpRequestMsg*)  tolua_tousertype(tolua_S,1,0);
  const char* szSendBuf = ((const char*)  tolua_tostring(tolua_S,2,NULL));
  unsigned int nLength = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSendBuffer'", NULL);
#endif
  {
   self->setSendBuffer(szSendBuf,nLength);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSendBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sharedHttpClient of class  TLHttpClient */
#ifndef TOLUA_DISABLE_tolua_api_TLHttpClient_sharedHttpClient00
static int tolua_api_TLHttpClient_sharedHttpClient00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLHttpClient",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLHttpClient* tolua_ret = (TLHttpClient*)  TLHttpClient::sharedHttpClient();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLHttpClient");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedHttpClient'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendMsg of class  TLHttpClient */
#ifndef TOLUA_DISABLE_tolua_api_TLHttpClient_sendMsg00
static int tolua_api_TLHttpClient_sendMsg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLHttpClient",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLHttpClient* self = (TLHttpClient*)  tolua_tousertype(tolua_S,1,0);
  int nMsgID = ((int)  tolua_tonumber(tolua_S,2,0));
  LUA_FUNCTION nCallbackHandler = (  toluafix_ref_function(tolua_S,3,0));
  const std::string strURLPrefix = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendMsg'", NULL);
#endif
  {
   self->sendMsg(nMsgID,nCallbackHandler,strURLPrefix);
   tolua_pushcppstring(tolua_S,(const char*)strURLPrefix);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendMsg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendMsg of class  TLHttpClient */
#ifndef TOLUA_DISABLE_tolua_api_TLHttpClient_sendMsg01
static int tolua_api_TLHttpClient_sendMsg01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLHttpClient",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isstring(tolua_S,6,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TLHttpClient* self = (TLHttpClient*)  tolua_tousertype(tolua_S,1,0);
  int nMsgID = ((int)  tolua_tonumber(tolua_S,2,0));
  LUA_FUNCTION nCallbackHandler = (  toluafix_ref_function(tolua_S,3,0));
  const std::string strURLPrefix = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string strContentType = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  const char* pszMsgData = ((const char*)  tolua_tostring(tolua_S,6,NULL));
  int nLength = ((int)  tolua_tonumber(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendMsg'", NULL);
#endif
  {
   self->sendMsg(nMsgID,nCallbackHandler,strURLPrefix,strContentType,pszMsgData,nLength);
   tolua_pushcppstring(tolua_S,(const char*)strURLPrefix);
   tolua_pushcppstring(tolua_S,(const char*)strContentType);
  }
 }
 return 2;
tolua_lerror:
 return tolua_api_TLHttpClient_sendMsg00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: requestFile of class  TLHttpClient */
#ifndef TOLUA_DISABLE_tolua_api_TLHttpClient_requestFile00
static int tolua_api_TLHttpClient_requestFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLHttpClient",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLHttpClient* self = (TLHttpClient*)  tolua_tousertype(tolua_S,1,0);
  const char* szRequestURL = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* szSaveTo = ((const char*)  tolua_tostring(tolua_S,3,0));
  LUA_FUNCTION nCallbackHandler = (  toluafix_ref_function(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'requestFile'", NULL);
#endif
  {
   self->requestFile(szRequestURL,szSaveTo,nCallbackHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'requestFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: appendRequestToSend of class  TLHttpClient */
#ifndef TOLUA_DISABLE_tolua_api_TLHttpClient_appendRequestToSend00
static int tolua_api_TLHttpClient_appendRequestToSend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLHttpClient",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"HttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLHttpClient* self = (TLHttpClient*)  tolua_tousertype(tolua_S,1,0);
  HttpRequest* pRequest = ((HttpRequest*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendRequestToSend'", NULL);
#endif
  {
   self->appendRequestToSend(pRequest);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendRequestToSend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSendRequest of class  TLHttpClient */
#ifndef TOLUA_DISABLE_tolua_api_TLHttpClient_getSendRequest00
static int tolua_api_TLHttpClient_getSendRequest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLHttpClient",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLHttpClient* self = (TLHttpClient*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSendRequest'", NULL);
#endif
  {
   HttpRequest* tolua_ret = (HttpRequest*)  self->getSendRequest();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HttpRequest");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSendRequest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: appendRequestToRecv of class  TLHttpClient */
#ifndef TOLUA_DISABLE_tolua_api_TLHttpClient_appendRequestToRecv00
static int tolua_api_TLHttpClient_appendRequestToRecv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLHttpClient",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !toluafix_isfunction(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLHttpClient* self = (TLHttpClient*)  tolua_tousertype(tolua_S,1,0);
  int nRequestType = ((int)  tolua_tonumber(tolua_S,2,0));
  int nMsgID = ((int)  tolua_tonumber(tolua_S,3,0));
  LUA_FUNCTION nCallbackHandler = (  toluafix_ref_function(tolua_S,4,0));
  const char* szContent = ((const char*)  tolua_tostring(tolua_S,5,0));
  int nLength = ((int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendRequestToRecv'", NULL);
#endif
  {
   self->appendRequestToRecv(nRequestType,nMsgID,nCallbackHandler,szContent,nLength);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendRequestToRecv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDefaultURL of class  TLHttpClient */
#ifndef TOLUA_DISABLE_tolua_api_TLHttpClient_setDefaultURL00
static int tolua_api_TLHttpClient_setDefaultURL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLHttpClient",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLHttpClient* self = (TLHttpClient*)  tolua_tousertype(tolua_S,1,0);
  const std::string strDefaultURL = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDefaultURL'", NULL);
#endif
  {
   self->setDefaultURL(strDefaultURL);
   tolua_pushcppstring(tolua_S,(const char*)strDefaultURL);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDefaultURL'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDefaultURL of class  TLHttpClient */
#ifndef TOLUA_DISABLE_tolua_api_TLHttpClient_getDefaultURL00
static int tolua_api_TLHttpClient_getDefaultURL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TLHttpClient",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TLHttpClient* self = (const TLHttpClient*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDefaultURL'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->getDefaultURL();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDefaultURL'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCookiePath of class  TLHttpClient */
#ifndef TOLUA_DISABLE_tolua_api_TLHttpClient_setCookiePath00
static int tolua_api_TLHttpClient_setCookiePath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLHttpClient",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLHttpClient* self = (TLHttpClient*)  tolua_tousertype(tolua_S,1,0);
  const std::string strCookiePath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCookiePath'", NULL);
#endif
  {
   self->setCookiePath(strCookiePath);
   tolua_pushcppstring(tolua_S,(const char*)strCookiePath);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCookiePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCookiePath of class  TLHttpClient */
#ifndef TOLUA_DISABLE_tolua_api_TLHttpClient_getCookiePath00
static int tolua_api_TLHttpClient_getCookiePath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TLHttpClient",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TLHttpClient* self = (const TLHttpClient*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCookiePath'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->getCookiePath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCookiePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPlaybackScriptHandler of class  TLHttpClient */
#ifndef TOLUA_DISABLE_tolua_api_TLHttpClient_setPlaybackScriptHandler00
static int tolua_api_TLHttpClient_setPlaybackScriptHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLHttpClient",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLHttpClient* self = (TLHttpClient*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPlaybackScriptHandler'", NULL);
#endif
  {
   self->setPlaybackScriptHandler(nHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPlaybackScriptHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setResetHttpClient of class  TLHttpClient */
#ifndef TOLUA_DISABLE_tolua_api_TLHttpClient_setResetHttpClient00
static int tolua_api_TLHttpClient_setResetHttpClient00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLHttpClient",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLHttpClient* self = (TLHttpClient*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setResetHttpClient'", NULL);
#endif
  {
   self->setResetHttpClient();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setResetHttpClient'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopAllEffects of class  SimpleAudioEngine */
#ifndef TOLUA_DISABLE_tolua_api_SimpleAudioEngine_stopAllEffects00
static int tolua_api_SimpleAudioEngine_stopAllEffects00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SimpleAudioEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SimpleAudioEngine* self = (SimpleAudioEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopAllEffects'", NULL);
#endif
  {
   self->stopAllEffects();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopAllEffects'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sharedTLMaskLayer of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_api_TLMaskLayer_sharedTLMaskLayer00
static int tolua_api_TLMaskLayer_sharedTLMaskLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLMaskLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLMaskLayer* tolua_ret = (TLMaskLayer*)  TLMaskLayer::sharedTLMaskLayer();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLMaskLayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedTLMaskLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetMaskLayer of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_api_TLMaskLayer_resetMaskLayer00
static int tolua_api_TLMaskLayer_resetMaskLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMaskLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMaskLayer* self = (TLMaskLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetMaskLayer'", NULL);
#endif
  {
   self->resetMaskLayer();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetMaskLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIsMaskScene of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_api_TLMaskLayer_setIsMaskScene00
static int tolua_api_TLMaskLayer_setIsMaskScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMaskLayer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMaskLayer* self = (TLMaskLayer*)  tolua_tousertype(tolua_S,1,0);
  bool bMaskScene = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIsMaskScene'", NULL);
#endif
  {
   self->setIsMaskScene(bMaskScene);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIsMaskScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: appendHighlightRect of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_api_TLMaskLayer_appendHighlightRect00
static int tolua_api_TLMaskLayer_appendHighlightRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMaskLayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMaskLayer* self = (TLMaskLayer*)  tolua_tousertype(tolua_S,1,0);
  const CCRect* rect = ((const CCRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendHighlightRect'", NULL);
#endif
  {
   self->appendHighlightRect(*rect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendHighlightRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: appendHighlightRect2 of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_api_TLMaskLayer_appendHighlightRect200
static int tolua_api_TLMaskLayer_appendHighlightRect200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMaskLayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMaskLayer* self = (TLMaskLayer*)  tolua_tousertype(tolua_S,1,0);
  const CCRect* rect = ((const CCRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendHighlightRect2'", NULL);
#endif
  {
   self->appendHighlightRect2(*rect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendHighlightRect2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaskColor of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_api_TLMaskLayer_setMaskColor00
static int tolua_api_TLMaskLayer_setMaskColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMaskLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMaskLayer* self = (TLMaskLayer*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0.0f));
  float g = ((float)  tolua_tonumber(tolua_S,3,0.0f));
  float b = ((float)  tolua_tonumber(tolua_S,4,0.0f));
  float a = ((float)  tolua_tonumber(tolua_S,5,0.8f));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaskColor'", NULL);
#endif
  {
   self->setMaskColor(r,g,b,a);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaskColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: test of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_api_TLMaskLayer_test00
static int tolua_api_TLMaskLayer_test00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMaskLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMaskLayer* self = (TLMaskLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'test'", NULL);
#endif
  {
   self->test();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'test'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWindow of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_createWindow00
static int tolua_api_TLWindow_createWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* pMCNode = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
  unsigned int uiWindowFlag = ((unsigned int)  tolua_tonumber(tolua_S,3,TL_WINDOW_UNIVARSAL));
  {
   TLWindow* tolua_ret = (TLWindow*)  TLWindow::createWindow(pMCNode,uiWindowFlag);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindow");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddChildWindow of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_AddChildWindow00
static int tolua_api_TLWindow_AddChildWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  TLWindow* pChildWindow = ((TLWindow*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddChildWindow'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddChildWindow(pChildWindow);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddChildWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllChildWindow of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_RemoveAllChildWindow00
static int tolua_api_TLWindow_RemoveAllChildWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllChildWindow'", NULL);
#endif
  {
   self->RemoveAllChildWindow();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllChildWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveChildWindow of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_RemoveChildWindow00
static int tolua_api_TLWindow_RemoveChildWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  TLWindow* pWindow = ((TLWindow*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveChildWindow'", NULL);
#endif
  {
   self->RemoveChildWindow(pWindow);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveChildWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetChildWindow of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_GetChildWindow00
static int tolua_api_TLWindow_GetChildWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChildWindow'", NULL);
#endif
  {
   CCArray* tolua_ret = (CCArray*)  self->GetChildWindow();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCArray");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetChildWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindWindow of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_FindWindow00
static int tolua_api_TLWindow_FindWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  const std::string strWindowName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  bool bFindInChild = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindWindow'", NULL);
#endif
  {
   TLWindow* tolua_ret = (TLWindow*)  self->FindWindow(strWindowName,bFindInChild);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindow");
   tolua_pushcppstring(tolua_S,(const char*)strWindowName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindWindow of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_FindWindow01
static int tolua_api_TLWindow_FindWindow01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindWindow'", NULL);
#endif
  {
   TLWindow* tolua_ret = (TLWindow*)  self->FindWindow(*point);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindow");
  }
 }
 return 1;
tolua_lerror:
 return tolua_api_TLWindow_FindWindow00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterEvent of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_RegisterEvent00
static int tolua_api_TLWindow_RegisterEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  TL_WINDOW_EVENT eEventType = ((TL_WINDOW_EVENT) (int)  tolua_tonumber(tolua_S,2,0));
  LUA_FUNCTION nEventHandler = (  toluafix_ref_function(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterEvent'", NULL);
#endif
  {
   self->RegisterEvent(eEventType,nEventHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterEvent of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_unregisterEvent00
static int tolua_api_TLWindow_unregisterEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  TL_WINDOW_EVENT eEventType = ((TL_WINDOW_EVENT) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterEvent'", NULL);
#endif
  {
   self->unregisterEvent(eEventType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregisterEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNode of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_GetNode00
static int tolua_api_TLWindow_GetNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNode'", NULL);
#endif
  {
   CCNode* tolua_ret = (CCNode*)  self->GetNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setText of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_setText00
static int tolua_api_TLWindow_setText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  const char* pszText = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setText'", NULL);
#endif
  {
   self->setText(pszText);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getText of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_getText00
static int tolua_api_TLWindow_getText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getText'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getText();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTextColor of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_setTextColor00
static int tolua_api_TLWindow_setTextColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  const ccColor3B* kTextColor = ((const ccColor3B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTextColor'", NULL);
#endif
  {
   self->setTextColor(*kTextColor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTextColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextColor of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_getTextColor00
static int tolua_api_TLWindow_getTextColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextColor'", NULL);
#endif
  {
   const ccColor3B& tolua_ret = (const ccColor3B&)  self->getTextColor();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const ccColor3B");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPlaceHolder of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_setPlaceHolder00
static int tolua_api_TLWindow_setPlaceHolder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  const char* pszText = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPlaceHolder'", NULL);
#endif
  {
   self->setPlaceHolder(pszText);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPlaceHolder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPlaceHolder of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_getPlaceHolder00
static int tolua_api_TLWindow_getPlaceHolder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPlaceHolder'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getPlaceHolder();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPlaceHolder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPlaceHolderColor of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_setPlaceHolderColor00
static int tolua_api_TLWindow_setPlaceHolderColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  const ccColor3B* kPlaceHolderColor = ((const ccColor3B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPlaceHolderColor'", NULL);
#endif
  {
   self->setPlaceHolderColor(*kPlaceHolderColor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPlaceHolderColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPlaceHolderColor of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_getPlaceHolderColor00
static int tolua_api_TLWindow_getPlaceHolderColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPlaceHolderColor'", NULL);
#endif
  {
   const ccColor3B& tolua_ret = (const ccColor3B&)  self->getPlaceHolderColor();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const ccColor3B");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPlaceHolderColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFontSize of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_setFontSize00
static int tolua_api_TLWindow_setFontSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  int nFontSize = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFontSize'", NULL);
#endif
  {
   self->setFontSize(nFontSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFontSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPlaceFontSize of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_setPlaceFontSize00
static int tolua_api_TLWindow_setPlaceFontSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  int nFontSize = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPlaceFontSize'", NULL);
#endif
  {
   self->setPlaceFontSize(nFontSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPlaceFontSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRichFlag of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_setRichFlag00
static int tolua_api_TLWindow_setRichFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  TL_RICH_STRING_FLAG eRichFlag = ((TL_RICH_STRING_FLAG) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRichFlag'", NULL);
#endif
  {
   self->setRichFlag(eRichFlag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRichFlag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlignment of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_setAlignment00
static int tolua_api_TLWindow_setAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  CCImage::ETextAlign eAlignment = ((CCImage::ETextAlign) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlignment'", NULL);
#endif
  {
   self->setAlignment(eAlignment);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setInputMode of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_setInputMode00
static int tolua_api_TLWindow_setInputMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  TL_INPUT_TEXT_MODEL eInputMode = ((TL_INPUT_TEXT_MODEL) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setInputMode'", NULL);
#endif
  {
   self->setInputMode(eInputMode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInputMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaxLength of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_setMaxLength00
static int tolua_api_TLWindow_setMaxLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  int nMaxLength = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaxLength'", NULL);
#endif
  {
   self->setMaxLength(nMaxLength);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaxLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setInputFlag of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_setInputFlag00
static int tolua_api_TLWindow_setInputFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  TL_INPUT_FLAG eInputFlag = ((TL_INPUT_FLAG) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setInputFlag'", NULL);
#endif
  {
   self->setInputFlag(eInputFlag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInputFlag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setReturnType of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_setReturnType00
static int tolua_api_TLWindow_setReturnType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  TL_RETURN_TYPE eReturnType = ((TL_RETURN_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setReturnType'", NULL);
#endif
  {
   self->setReturnType(eReturnType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setReturnType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setKeyboardWillShowHandler of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_setKeyboardWillShowHandler00
static int tolua_api_TLWindow_setKeyboardWillShowHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nWillShowHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setKeyboardWillShowHandler'", NULL);
#endif
  {
   self->setKeyboardWillShowHandler(nWillShowHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setKeyboardWillShowHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setKeyboardWillHideHandler of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_setKeyboardWillHideHandler00
static int tolua_api_TLWindow_setKeyboardWillHideHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nWillHideHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setKeyboardWillHideHandler'", NULL);
#endif
  {
   self->setKeyboardWillHideHandler(nWillHideHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setKeyboardWillHideHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRealSize of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_getRealSize00
static int tolua_api_TLWindow_getRealSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRealSize'", NULL);
#endif
  {
   CCSize tolua_ret = (CCSize)  self->getRealSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRealSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWindowName of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_GetWindowName00
static int tolua_api_TLWindow_GetWindowName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TLWindow* self = (const TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWindowName'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetWindowName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindowName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWindowName of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_SetWindowName00
static int tolua_api_TLWindow_SetWindowName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  const std::string strWindowName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWindowName'", NULL);
#endif
  {
   self->SetWindowName(strWindowName);
   tolua_pushcppstring(tolua_S,(const char*)strWindowName);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWindowName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIsEnable of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_GetIsEnable00
static int tolua_api_TLWindow_GetIsEnable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TLWindow* self = (const TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIsEnable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetIsEnable();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIsEnable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIsEnable of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_SetIsEnable00
static int tolua_api_TLWindow_SetIsEnable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  bool bEnable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIsEnable'", NULL);
#endif
  {
   self->SetIsEnable(bEnable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIsEnable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIsScroll of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_GetIsScroll00
static int tolua_api_TLWindow_GetIsScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TLWindow* self = (const TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIsScroll'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetIsScroll();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIsScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIsInput of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_GetIsInput00
static int tolua_api_TLWindow_GetIsInput00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TLWindow* self = (const TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIsInput'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetIsInput();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIsInput'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIsVisible of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_GetIsVisible00
static int tolua_api_TLWindow_GetIsVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIsVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetIsVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIsVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIsVisible of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_SetIsVisible00
static int tolua_api_TLWindow_SetIsVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  bool bIsVisible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIsVisible'", NULL);
#endif
  {
   self->SetIsVisible(bIsVisible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIsVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWindowRect of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_GetWindowRect00
static int tolua_api_TLWindow_GetWindowRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWindowRect'", NULL);
#endif
  {
   CCRect tolua_ret = (CCRect)  self->GetWindowRect();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCRect));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindowRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWindowPos of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_SetWindowPos00
static int tolua_api_TLWindow_SetWindowPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWindowPos'", NULL);
#endif
  {
   self->SetWindowPos(*point);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWindowPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWindowPos of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_GetWindowPos00
static int tolua_api_TLWindow_GetWindowPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWindowPos'", NULL);
#endif
  {
   const CCPoint& tolua_ret = (const CCPoint&)  self->GetWindowPos();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const CCPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindowPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HitTest of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_api_TLWindow_HitTest00
static int tolua_api_TLWindow_HitTest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HitTest'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->HitTest(*point);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HitTest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SharedTLWindowManager of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_SharedTLWindowManager00
static int tolua_api_TLWindowManager_SharedTLWindowManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLWindowManager* tolua_ret = (TLWindowManager*)  TLWindowManager::SharedTLWindowManager();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindowManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SharedTLWindowManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCenterPoint of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_GetCenterPoint00
static int tolua_api_TLWindowManager_GetCenterPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCenterPoint'", NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->GetCenterPoint();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCenterPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReleaseAllWindow of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_ReleaseAllWindow00
static int tolua_api_TLWindowManager_ReleaseAllWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReleaseAllWindow'", NULL);
#endif
  {
   self->ReleaseAllWindow();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReleaseAllWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddModuleWindow of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_AddModuleWindow00
static int tolua_api_TLWindowManager_AddModuleWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  TLWindow* pModuleWindow = ((TLWindow*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddModuleWindow'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddModuleWindow(pModuleWindow);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddModuleWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HideAllModuleWindow of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_HideAllModuleWindow00
static int tolua_api_TLWindowManager_HideAllModuleWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HideAllModuleWindow'", NULL);
#endif
  {
   self->HideAllModuleWindow();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HideAllModuleWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DestroyAllModuleWindow of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_DestroyAllModuleWindow00
static int tolua_api_TLWindowManager_DestroyAllModuleWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DestroyAllModuleWindow'", NULL);
#endif
  {
   self->DestroyAllModuleWindow();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DestroyAllModuleWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveModuleWindow of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_RemoveModuleWindow00
static int tolua_api_TLWindowManager_RemoveModuleWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  TLWindow* pWindow = ((TLWindow*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveModuleWindow'", NULL);
#endif
  {
   self->RemoveModuleWindow(pWindow);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveModuleWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindModuleWindow of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_FindModuleWindow00
static int tolua_api_TLWindowManager_FindModuleWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string strWindowName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindModuleWindow'", NULL);
#endif
  {
   TLWindow* tolua_ret = (TLWindow*)  self->FindModuleWindow(strWindowName);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindow");
   tolua_pushcppstring(tolua_S,(const char*)strWindowName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindModuleWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindModuleWindow of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_FindModuleWindow01
static int tolua_api_TLWindowManager_FindModuleWindow01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindModuleWindow'", NULL);
#endif
  {
   TLWindow* tolua_ret = (TLWindow*)  self->FindModuleWindow(*point);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindow");
  }
 }
 return 1;
tolua_lerror:
 return tolua_api_TLWindowManager_FindModuleWindow00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLastPointX of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_getLastPointX00
static int tolua_api_TLWindowManager_getLastPointX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLastPointX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLastPointX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLastPointX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLastPointY of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_getLastPointY00
static int tolua_api_TLWindowManager_getLastPointY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLastPointY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLastPointY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLastPointY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLastPoint of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_getLastPoint00
static int tolua_api_TLWindowManager_getLastPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLastPoint'", NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->getLastPoint();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLastPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWorldTime of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_getWorldTime00
static int tolua_api_TLWindowManager_getWorldTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWorldTime'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getWorldTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWorldTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setKeyBackClickedHandler of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_setKeyBackClickedHandler00
static int tolua_api_TLWindowManager_setKeyBackClickedHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setKeyBackClickedHandler'", NULL);
#endif
  {
   self->setKeyBackClickedHandler(nHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setKeyBackClickedHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setKeyMenuClickedHandler of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_setKeyMenuClickedHandler00
static int tolua_api_TLWindowManager_setKeyMenuClickedHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setKeyMenuClickedHandler'", NULL);
#endif
  {
   self->setKeyMenuClickedHandler(nHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setKeyMenuClickedHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MoveToTop of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_MoveToTop00
static int tolua_api_TLWindowManager_MoveToTop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  TLWindow* pWindow = ((TLWindow*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MoveToTop'", NULL);
#endif
  {
   self->MoveToTop(pWindow);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MoveToTop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MoveToBottom of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_MoveToBottom00
static int tolua_api_TLWindowManager_MoveToBottom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  TLWindow* pWindow = ((TLWindow*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MoveToBottom'", NULL);
#endif
  {
   self->MoveToBottom(pWindow);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MoveToBottom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StopEventBubble of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_StopEventBubble00
static int tolua_api_TLWindowManager_StopEventBubble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StopEventBubble'", NULL);
#endif
  {
   self->StopEventBubble();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StopEventBubble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ShowUI of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_ShowUI00
static int tolua_api_TLWindowManager_ShowUI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  bool bShow = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ShowUI'", NULL);
#endif
  {
   self->ShowUI(bShow);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ShowUI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CancelDropDrag of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_CancelDropDrag00
static int tolua_api_TLWindowManager_CancelDropDrag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CancelDropDrag'", NULL);
#endif
  {
   self->CancelDropDrag();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CancelDropDrag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTouchBeganHandler of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_setTouchBeganHandler00
static int tolua_api_TLWindowManager_setTouchBeganHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTouchBeganHandler'", NULL);
#endif
  {
   self->setTouchBeganHandler(nHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTouchBeganHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTouchMovedHandler of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_setTouchMovedHandler00
static int tolua_api_TLWindowManager_setTouchMovedHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTouchMovedHandler'", NULL);
#endif
  {
   self->setTouchMovedHandler(nHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTouchMovedHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTouchEndedHandler of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_setTouchEndedHandler00
static int tolua_api_TLWindowManager_setTouchEndedHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTouchEndedHandler'", NULL);
#endif
  {
   self->setTouchEndedHandler(nHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTouchEndedHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetModalWindow of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_SetModalWindow00
static int tolua_api_TLWindowManager_SetModalWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLWindow",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  TLWindow* pWindow = ((TLWindow*)  tolua_tousertype(tolua_S,2,0));
  bool bModal = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetModalWindow'", NULL);
#endif
  {
   self->SetModalWindow(pWindow,bModal);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetModalWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSystemWindow of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_SetSystemWindow00
static int tolua_api_TLWindowManager_SetSystemWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLWindow",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  TLWindow* pWindow = ((TLWindow*)  tolua_tousertype(tolua_S,2,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSystemWindow'", NULL);
#endif
  {
   self->SetSystemWindow(pWindow);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSystemWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetGuideWindow of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_SetGuideWindow00
static int tolua_api_TLWindowManager_SetGuideWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLWindow",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  TLWindow* pWindow = ((TLWindow*)  tolua_tousertype(tolua_S,2,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetGuideWindow'", NULL);
#endif
  {
   self->SetGuideWindow(pWindow);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetGuideWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLockScreenWindow of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_SetLockScreenWindow00
static int tolua_api_TLWindowManager_SetLockScreenWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLWindow",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  TLWindow* pWindow = ((TLWindow*)  tolua_tousertype(tolua_S,2,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLockScreenWindow'", NULL);
#endif
  {
   self->SetLockScreenWindow(pWindow);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLockScreenWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lockScreen of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_lockScreen00
static int tolua_api_TLWindowManager_lockScreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string strLockName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lockScreen'", NULL);
#endif
  {
   self->lockScreen(strLockName);
   tolua_pushcppstring(tolua_S,(const char*)strLockName);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lockScreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unlockScreen of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_unlockScreen00
static int tolua_api_TLWindowManager_unlockScreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string strLockName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unlockScreen'", NULL);
#endif
  {
   self->unlockScreen(strLockName);
   tolua_pushcppstring(tolua_S,(const char*)strLockName);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unlockScreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearAllLock of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_clearAllLock00
static int tolua_api_TLWindowManager_clearAllLock00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearAllLock'", NULL);
#endif
  {
   self->clearAllLock();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearAllLock'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: screenLockLog of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_screenLockLog00
static int tolua_api_TLWindowManager_screenLockLog00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'screenLockLog'", NULL);
#endif
  {
   self->screenLockLog();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'screenLockLog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCheckInputTextHandler of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_setCheckInputTextHandler00
static int tolua_api_TLWindowManager_setCheckInputTextHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCheckInputTextHandler'", NULL);
#endif
  {
   self->setCheckInputTextHandler(nHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCheckInputTextHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkInputText of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_api_TLWindowManager_checkInputText00
static int tolua_api_TLWindowManager_checkInputText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  std::string text = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkInputText'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkInputText(text);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkInputText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AppendShow of class  TLDropDragHelper */
#ifndef TOLUA_DISABLE_tolua_api_TLDropDragHelper_AppendShow00
static int tolua_api_TLDropDragHelper_AppendShow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLDropDragHelper",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLDropDragHelper* self = (TLDropDragHelper*)  tolua_tousertype(tolua_S,1,0);
  CCNode* pNode = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AppendShow'", NULL);
#endif
  {
   self->AppendShow(pNode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AppendShow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: OpenPlatformLogin */
#ifndef TOLUA_DISABLE_tolua_api_OpenPlatformLogin00
static int tolua_api_OpenPlatformLogin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   OpenPlatformLogin();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OpenPlatformLogin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: OpenPlatformLoginout */
#ifndef TOLUA_DISABLE_tolua_api_OpenPlatformLoginout00
static int tolua_api_OpenPlatformLoginout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   OpenPlatformLoginout();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OpenPlatformLoginout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: OpenPayInterface */
#ifndef TOLUA_DISABLE_tolua_api_OpenPayInterface00
static int tolua_api_OpenPayInterface00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* szSerialNo = ((char*)  tolua_tostring(tolua_S,1,0));
  float money = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   OpenPayInterface(szSerialNo,money);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OpenPayInterface'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: EnterPlatform */
#ifndef TOLUA_DISABLE_tolua_api_EnterPlatform00
static int tolua_api_EnterPlatform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   EnterPlatform();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EnterPlatform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetSdkType */
#ifndef TOLUA_DISABLE_tolua_api_GetSdkType00
static int tolua_api_GetSdkType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   int tolua_ret = (int)  GetSdkType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSdkType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: payWithAndroidSDK */
#ifndef TOLUA_DISABLE_tolua_api_payWithAndroidSDK00
static int tolua_api_payWithAndroidSDK00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isstring(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* orderID = ((char*)  tolua_tostring(tolua_S,1,0));
  char* serverID = ((char*)  tolua_tostring(tolua_S,2,0));
  char* roleID = ((char*)  tolua_tostring(tolua_S,3,0));
  char* roleName = ((char*)  tolua_tostring(tolua_S,4,0));
  char* roleLevel = ((char*)  tolua_tostring(tolua_S,5,0));
  char* loginName = ((char*)  tolua_tostring(tolua_S,6,0));
  char* pbID = ((char*)  tolua_tostring(tolua_S,7,0));
  {
   payWithAndroidSDK(orderID,serverID,roleID,roleName,roleLevel,loginName,pbID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'payWithAndroidSDK'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: quitConfirm */
#ifndef TOLUA_DISABLE_tolua_api_quitConfirm00
static int tolua_api_quitConfirm00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   quitConfirm();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'quitConfirm'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: quitApplication */
#ifndef TOLUA_DISABLE_tolua_api_quitApplication00
static int tolua_api_quitApplication00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   quitApplication();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'quitApplication'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: hideWindow */
#ifndef TOLUA_DISABLE_tolua_api_hideWindow00
static int tolua_api_hideWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   hideWindow();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hideWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: isETC1Supported */
#ifndef TOLUA_DISABLE_tolua_api_isETC1Supported00
static int tolua_api_isETC1Supported00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  isETC1Supported();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isETC1Supported'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getDeviceId */
#ifndef TOLUA_DISABLE_tolua_api_getDeviceId00
static int tolua_api_getDeviceId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getDeviceId();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDeviceId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getIMSI */
#ifndef TOLUA_DISABLE_tolua_api_getIMSI00
static int tolua_api_getIMSI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getIMSI();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIMSI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getUUID */
#ifndef TOLUA_DISABLE_tolua_api_getUUID00
static int tolua_api_getUUID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getUUID();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUUID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getPlatform */
#ifndef TOLUA_DISABLE_tolua_api_getPlatform00
static int tolua_api_getPlatform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getPlatform();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPlatform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getOSVersion */
#ifndef TOLUA_DISABLE_tolua_api_getOSVersion00
static int tolua_api_getOSVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getOSVersion();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOSVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getResolution */
#ifndef TOLUA_DISABLE_tolua_api_getResolution00
static int tolua_api_getResolution00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getResolution();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResolution'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getUA */
#ifndef TOLUA_DISABLE_tolua_api_getUA00
static int tolua_api_getUA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getUA();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getMetaData */
#ifndef TOLUA_DISABLE_tolua_api_getMetaData00
static int tolua_api_getMetaData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* tolua_var_1 = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   const char* tolua_ret = (const char*)  getMetaData(tolua_var_1);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMetaData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getdeviceUniqueID */
#ifndef TOLUA_DISABLE_tolua_api_getdeviceUniqueID00
static int tolua_api_getdeviceUniqueID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getdeviceUniqueID();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getdeviceUniqueID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getMAC */
#ifndef TOLUA_DISABLE_tolua_api_getMAC00
static int tolua_api_getMAC00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getMAC();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMAC'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getidfa */
#ifndef TOLUA_DISABLE_tolua_api_getidfa00
static int tolua_api_getidfa00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getidfa();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getidfa'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getIMEI */
#ifndef TOLUA_DISABLE_tolua_api_getIMEI00
static int tolua_api_getIMEI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getIMEI();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIMEI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: acquireWakeLock */
#ifndef TOLUA_DISABLE_tolua_api_acquireWakeLock00
static int tolua_api_acquireWakeLock00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  acquireWakeLock();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'acquireWakeLock'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: releaseWakeLock */
#ifndef TOLUA_DISABLE_tolua_api_releaseWakeLock00
static int tolua_api_releaseWakeLock00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  releaseWakeLock();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'releaseWakeLock'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: userActivity */
#ifndef TOLUA_DISABLE_tolua_api_userActivity00
static int tolua_api_userActivity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  userActivity();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'userActivity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getPackageVersion */
#ifndef TOLUA_DISABLE_tolua_api_getPackageVersion00
static int tolua_api_getPackageVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   int tolua_ret = (int)  getPackageVersion();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPackageVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getPackageName */
#ifndef TOLUA_DISABLE_tolua_api_getPackageName00
static int tolua_api_getPackageName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::string tolua_ret = (std::string)  getPackageName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPackageName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getNetworkTypeName */
#ifndef TOLUA_DISABLE_tolua_api_getNetworkTypeName00
static int tolua_api_getNetworkTypeName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getNetworkTypeName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNetworkTypeName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: openURL */
#ifndef TOLUA_DISABLE_tolua_api_openURL00
static int tolua_api_openURL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* sUrl = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   openURL(sUrl);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'openURL'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: useConsole */
#ifndef TOLUA_DISABLE_tolua_api_useConsole00
static int tolua_api_useConsole00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   useConsole();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'useConsole'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: setResourceVersion */
#ifndef TOLUA_DISABLE_tolua_api_setResourceVersion00
static int tolua_api_setResourceVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* szResVersion = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   setResourceVersion(szResVersion);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setResourceVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getResourceVersion */
#ifndef TOLUA_DISABLE_tolua_api_getResourceVersion00
static int tolua_api_getResourceVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getResourceVersion();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResourceVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: playMedia */
#ifndef TOLUA_DISABLE_tolua_api_playMedia00
static int tolua_api_playMedia00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* szPath = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   playMedia(szPath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playMedia'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: stopMedia */
#ifndef TOLUA_DISABLE_tolua_api_stopMedia00
static int tolua_api_stopMedia00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   stopMedia();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopMedia'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: createLocalNotification */
#ifndef TOLUA_DISABLE_tolua_api_createLocalNotification00
static int tolua_api_createLocalNotification00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isstring(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* nDaysLater = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* nHour = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* nMinute = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* nSecond = ((const char*)  tolua_tostring(tolua_S,4,0));
  const char* szContent = ((const char*)  tolua_tostring(tolua_S,5,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,6,0));
  const char* nType = ((const char*)  tolua_tostring(tolua_S,7,0));
  {
   createLocalNotification(nDaysLater,nHour,nMinute,nSecond,szContent,key,nType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createLocalNotification'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: releaseLocalNotification */
#ifndef TOLUA_DISABLE_tolua_api_releaseLocalNotification00
static int tolua_api_releaseLocalNotification00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* key = ((const char*)  tolua_tostring(tolua_S,1,""));
  {
   releaseLocalNotification(key);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'releaseLocalNotification'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: releaseAllLocalNotification */
#ifndef TOLUA_DISABLE_tolua_api_releaseAllLocalNotification00
static int tolua_api_releaseAllLocalNotification00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   releaseAllLocalNotification();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'releaseAllLocalNotification'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: register_platform_callback */
#ifndef TOLUA_DISABLE_tolua_api_register_platform_callback00
static int tolua_api_register_platform_callback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CbType t = ((CbType) (int)  tolua_tonumber(tolua_S,1,0));
  LUA_FUNCTION cb = (  toluafix_ref_function(tolua_S,2,0));
  {
   register_platform_callback(t,cb);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'register_platform_callback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getAvailMemory */
#ifndef TOLUA_DISABLE_tolua_api_getAvailMemory00
static int tolua_api_getAvailMemory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  getAvailMemory();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAvailMemory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mcBoundingBox of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_get_TLModel_mcBoundingBox
static int tolua_get_TLModel_mcBoundingBox(lua_State* tolua_S)
{
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mcBoundingBox'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mcBoundingBox,"CCRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mcBoundingBox of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_set_TLModel_mcBoundingBox
static int tolua_set_TLModel_mcBoundingBox(lua_State* tolua_S)
{
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mcBoundingBox'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mcBoundingBox = *((CCRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithName of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_createWithName00
static int tolua_api_TLModel_createWithName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* mcName = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool bAsync = ((bool)  tolua_toboolean(tolua_S,3,false));
  float uvScale = ((float)  tolua_tonumber(tolua_S,4,1));
  {
   TLModel* tolua_ret = (TLModel*)  TLModel::createWithName(mcName,bAsync,uvScale);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLModel");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: play of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_play00
static int tolua_api_TLModel_play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
  int startFrame = ((int)  tolua_tonumber(tolua_S,2,0));
  int durationFrame = ((int)  tolua_tonumber(tolua_S,3,0));
  int loopCount = ((int)  tolua_tonumber(tolua_S,4,0));
  bool reverse = ((bool)  tolua_toboolean(tolua_S,5,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'play'", NULL);
#endif
  {
   self->play(startFrame,durationFrame,loopCount,reverse);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_start00
static int tolua_api_TLModel_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_stop00
static int tolua_api_TLModel_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIsPlaying of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_getIsPlaying00
static int tolua_api_TLModel_getIsPlaying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TLModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TLModel* self = (const TLModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIsPlaying'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getIsPlaying();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIsPlaying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAutoClear of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_setAutoClear00
static int tolua_api_TLModel_setAutoClear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
  bool reset = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoClear'", NULL);
#endif
  {
   self->setAutoClear(reset);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoClear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAutoClear of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_getAutoClear00
static int tolua_api_TLModel_getAutoClear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAutoClear'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getAutoClear();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAutoClear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFrameRate of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_setFrameRate00
static int tolua_api_TLModel_setFrameRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
  int rate = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFrameRate'", NULL);
#endif
  {
   self->setFrameRate(rate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFrameRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameRate of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_getFrameRate00
static int tolua_api_TLModel_getFrameRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameRate'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getFrameRate();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSymbolInfo of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_getSymbolInfo00
static int tolua_api_TLModel_getSymbolInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSymbolInfo'", NULL);
#endif
  {
   const framework::Symbol* tolua_ret = (const framework::Symbol*)  self->getSymbolInfo();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const framework::Symbol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSymbolInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterPlayEndCallbackHandler of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_RegisterPlayEndCallbackHandler00
static int tolua_api_TLModel_RegisterPlayEndCallbackHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nLuaHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterPlayEndCallbackHandler'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->RegisterPlayEndCallbackHandler(nLuaHandler);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterPlayEndCallbackHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterPreCallScript of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_RegisterPreCallScript00
static int tolua_api_TLModel_RegisterPreCallScript00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nLuaHandle = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterPreCallScript'", NULL);
#endif
  {
   self->RegisterPreCallScript(nLuaHandle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterPreCallScript'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLayerFirstNodePosition of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_getLayerFirstNodePosition00
static int tolua_api_TLModel_getLayerFirstNodePosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
  const char* szName = ((const char*)  tolua_tostring(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLayerFirstNodePosition'", NULL);
#endif
  {
   self->getLayerFirstNodePosition(szName,&x,&y);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLayerFirstNodePosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTimeLength of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_getTimeLength00
static int tolua_api_TLModel_getTimeLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
  int nFrameRate = ((int)  tolua_tonumber(tolua_S,2,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTimeLength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getTimeLength(nFrameRate);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTimeLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_setColor00
static int tolua_api_TLModel_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
  const ccColor3B* color = ((const ccColor3B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColor of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_getColor00
static int tolua_api_TLModel_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   const ccColor3B& tolua_ret = (const ccColor3B&)  self->getColor();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const ccColor3B");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacity of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_setOpacity00
static int tolua_api_TLModel_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
  unsigned char opacity = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpacity'", NULL);
#endif
  {
   self->setOpacity(opacity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOpacity of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_getOpacity00
static int tolua_api_TLModel_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOpacity'", NULL);
#endif
  {
   GLubyte tolua_ret = (GLubyte)  self->getOpacity();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GLubyte)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GLubyte");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GLubyte));
     tolua_pushusertype(tolua_S,tolua_obj,"GLubyte");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextureName of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_getTextureName00
static int tolua_api_TLModel_getTextureName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextureName'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->getTextureName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextureName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFrameColor of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_setFrameColor00
static int tolua_api_TLModel_setFrameColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor4B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
  const ccColor4B* color = ((const ccColor4B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFrameColor'", NULL);
#endif
  {
   self->setFrameColor(*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFrameColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearFrameColor of class  TLModel */
#ifndef TOLUA_DISABLE_tolua_api_TLModel_clearFrameColor00
static int tolua_api_TLModel_clearFrameColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLModel* self = (TLModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearFrameColor'", NULL);
#endif
  {
   self->clearFrameColor();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearFrameColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPosition of class  ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystem_GetPosition00
static int tolua_api_ParticleSystem_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleSystem* self = (ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
  {
   self->GetPosition(&x,&y);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystem_SetPosition00
static int tolua_api_ParticleSystem_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleSystem* self = (ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPositionX of class  ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystem_SetPositionX00
static int tolua_api_ParticleSystem_SetPositionX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleSystem* self = (ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPositionX'", NULL);
#endif
  {
   self->SetPositionX(x);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPositionX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPositionY of class  ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystem_SetPositionY00
static int tolua_api_ParticleSystem_SetPositionY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleSystem* self = (ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float y = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPositionY'", NULL);
#endif
  {
   self->SetPositionY(y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPositionY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale of class  ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystem_SetScale00
static int tolua_api_ParticleSystem_SetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleSystem* self = (ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale'", NULL);
#endif
  {
   self->SetScale(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTimeLength of class  ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystem_getTimeLength00
static int tolua_api_ParticleSystem_getTimeLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleSystem* self = (ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTimeLength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getTimeLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTimeLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerPlayEndCallbackHandler of class  ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystem_registerPlayEndCallbackHandler00
static int tolua_api_ParticleSystem_registerPlayEndCallbackHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleSystem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleSystem* self = (ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nLuaHandle = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerPlayEndCallbackHandler'", NULL);
#endif
  {
   self->registerPlayEndCallbackHandler(nLuaHandle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerPlayEndCallbackHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextureCount of class  ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystem_getTextureCount00
static int tolua_api_ParticleSystem_getTextureCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleSystem* self = (ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextureCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTextureCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextureCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextureName of class  ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystem_getTextureName00
static int tolua_api_ParticleSystem_getTextureName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleSystem* self = (ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  int idx = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextureName'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getTextureName(idx);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextureName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopInfiniteLoop of class  ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystem_stopInfiniteLoop00
static int tolua_api_ParticleSystem_stopInfiniteLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleSystem* self = (ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopInfiniteLoop'", NULL);
#endif
  {
   self->stopInfiniteLoop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopInfiniteLoop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sharedParticleSystemManager of class  ParticleSystemManager */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystemManager_sharedParticleSystemManager00
static int tolua_api_ParticleSystemManager_sharedParticleSystemManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ParticleSystemManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ParticleSystemManager* tolua_ret = (ParticleSystemManager*)  ParticleSystemManager::sharedParticleSystemManager();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleSystemManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedParticleSystemManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadParticleSystems of class  ParticleSystemManager */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystemManager_LoadParticleSystems00
static int tolua_api_ParticleSystemManager_LoadParticleSystems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleSystemManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleSystemManager* self = (ParticleSystemManager*)  tolua_tousertype(tolua_S,1,0);
  const char* fileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadParticleSystems'", NULL);
#endif
  {
   self->LoadParticleSystems(fileName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadParticleSystems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithName of class  ParticleSystemManager */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystemManager_createWithName00
static int tolua_api_ParticleSystemManager_createWithName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleSystemManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CCPoint",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,8,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleSystemManager* self = (ParticleSystemManager*)  tolua_tousertype(tolua_S,1,0);
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
  CCPoint point = *((CCPoint*)  tolua_tousertype(tolua_S,3,0));
  int zOder = ((int)  tolua_tonumber(tolua_S,4,0));
  const char* name = ((const char*)  tolua_tostring(tolua_S,5,0));
  bool loop = ((bool)  tolua_toboolean(tolua_S,6,0));
  float time = ((float)  tolua_tonumber(tolua_S,7,-1));
  bool bNormalSchedule = ((bool)  tolua_toboolean(tolua_S,8,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createWithName'", NULL);
#endif
  {
   ParticleSystem* tolua_ret = (ParticleSystem*)  self->createWithName(node,point,zOder,name,loop,time,bNormalSchedule);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleSystem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithNameLua of class  ParticleSystemManager */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystemManager_createWithNameLua00
static int tolua_api_ParticleSystemManager_createWithNameLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleSystemManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleSystemManager* self = (ParticleSystemManager*)  tolua_tousertype(tolua_S,1,0);
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
  const char* name = ((const char*)  tolua_tostring(tolua_S,5,0));
  int loopCnt = ((int)  tolua_tonumber(tolua_S,6,-1));
  bool bNormalSchedule = ((bool)  tolua_toboolean(tolua_S,7,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createWithNameLua'", NULL);
#endif
  {
   ParticleSystem* tolua_ret = (ParticleSystem*)  self->createWithNameLua(node,x,y,name,loopCnt,bNormalSchedule);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleSystem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithNameLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cleanupCache of class  ParticleSystemManager */
#ifndef TOLUA_DISABLE_tolua_api_ParticleSystemManager_cleanupCache00
static int tolua_api_ParticleSystemManager_cleanupCache00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleSystemManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleSystemManager* self = (ParticleSystemManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cleanupCache'", NULL);
#endif
  {
   self->cleanupCache();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cleanupCache'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sharedTLTweenManager of class  TLTweenManager */
#ifndef TOLUA_DISABLE_tolua_api_TLTweenManager_sharedTLTweenManager00
static int tolua_api_TLTweenManager_sharedTLTweenManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLTweenManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLTweenManager* tolua_ret = (TLTweenManager*)  TLTweenManager::sharedTLTweenManager();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLTweenManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedTLTweenManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: tweenFromTo of class  TLTweenManager */
#ifndef TOLUA_DISABLE_tolua_api_TLTweenManager_tweenFromTo00
static int tolua_api_TLTweenManager_tweenFromTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLTweenManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,9,&tolua_err) || !toluafix_isfunction(tolua_S,9,"LUA_FUNCTION",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,10,&tolua_err) || !toluafix_isfunction(tolua_S,10,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLTweenManager* self = (TLTweenManager*)  tolua_tousertype(tolua_S,1,0);
  TWEEN_INTERPOLATION_TYPE type = ((TWEEN_INTERPOLATION_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
  float delay = ((float)  tolua_tonumber(tolua_S,3,0));
  float duration = ((float)  tolua_tonumber(tolua_S,4,0));
  float interval = ((float)  tolua_tonumber(tolua_S,5,0));
  float from = ((float)  tolua_tonumber(tolua_S,6,0));
  float to = ((float)  tolua_tonumber(tolua_S,7,0));
  int loopCount = ((int)  tolua_tonumber(tolua_S,8,0));
  LUA_FUNCTION nSeterHandler = (  toluafix_ref_function(tolua_S,9,0));
  LUA_FUNCTION nEndHandler = (  toluafix_ref_function(tolua_S,10,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'tweenFromTo'", NULL);
#endif
  {
   int tolua_ret = (int)  self->tweenFromTo(type,delay,duration,interval,from,to,loopCount,nSeterHandler,nEndHandler);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tweenFromTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeTween of class  TLTweenManager */
#ifndef TOLUA_DISABLE_tolua_api_TLTweenManager_removeTween00
static int tolua_api_TLTweenManager_removeTween00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLTweenManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLTweenManager* self = (TLTweenManager*)  tolua_tousertype(tolua_S,1,0);
  int nTweenHandle = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeTween'", NULL);
#endif
  {
   self->removeTween(nTweenHandle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeTween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllTween of class  TLTweenManager */
#ifndef TOLUA_DISABLE_tolua_api_TLTweenManager_removeAllTween00
static int tolua_api_TLTweenManager_removeAllTween00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLTweenManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLTweenManager* self = (TLTweenManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllTween'", NULL);
#endif
  {
   self->removeAllTween();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllTween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCActionLuaCallFunc */
#ifndef TOLUA_DISABLE_tolua_api_CCActionLuaCallFunc_create00
static int tolua_api_CCActionLuaCallFunc_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCActionLuaCallFunc",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LUA_FUNCTION nHandler = (  toluafix_ref_function(tolua_S,2,0));
  {
   CCActionLuaCallFunc* tolua_ret = (CCActionLuaCallFunc*)  CCActionLuaCallFunc::create(nHandler);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCActionLuaCallFunc");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: OpenPayWithAndroid */
#ifndef TOLUA_DISABLE_tolua_api_OpenPayWithAndroid00
static int tolua_api_OpenPayWithAndroid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isstring(tolua_S,7,0,&tolua_err) ||
     !tolua_isstring(tolua_S,8,0,&tolua_err) ||
     !tolua_isstring(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* ID = ((char*)  tolua_tostring(tolua_S,1,0));
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
  char* orderID = ((char*)  tolua_tostring(tolua_S,3,0));
  char* goodsID = ((char*)  tolua_tostring(tolua_S,4,0));
  char* price = ((char*)  tolua_tostring(tolua_S,5,0));
  char* serverID = ((char*)  tolua_tostring(tolua_S,6,0));
  char* roleID = ((char*)  tolua_tostring(tolua_S,7,0));
  char* roleName = ((char*)  tolua_tostring(tolua_S,8,0));
  char* roleLevel = ((char*)  tolua_tostring(tolua_S,9,0));
  {
   OpenPayWithAndroid(ID,name,orderID,goodsID,price,serverID,roleID,roleName,roleLevel);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OpenPayWithAndroid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentTLEditBox of class  TLEditBox */
#ifndef TOLUA_DISABLE_tolua_api_TLEditBox_getCurrentTLEditBox00
static int tolua_api_TLEditBox_getCurrentTLEditBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLEditBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLEditBox* tolua_ret = (TLEditBox*)  TLEditBox::getCurrentTLEditBox();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLEditBox");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentTLEditBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setText of class  TLEditBox */
#ifndef TOLUA_DISABLE_tolua_api_TLEditBox_setText00
static int tolua_api_TLEditBox_setText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLEditBox",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLEditBox* self = (TLEditBox*)  tolua_tousertype(tolua_S,1,0);
  const char* pszText = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setText'", NULL);
#endif
  {
   self->setText(pszText);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  TLRenderNode */
#ifndef TOLUA_DISABLE_tolua_api_TLRenderNode_create00
static int tolua_api_TLRenderNode_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLRenderNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* pContentNode = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
  float width = ((float)  tolua_tonumber(tolua_S,3,0));
  float height = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   TLRenderNode* tolua_ret = (TLRenderNode*)  TLRenderNode::create(pContentNode,width,height);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLRenderNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUseRender of class  TLRenderNode */
#ifndef TOLUA_DISABLE_tolua_api_TLRenderNode_setUseRender00
static int tolua_api_TLRenderNode_setUseRender00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLRenderNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLRenderNode* self = (TLRenderNode*)  tolua_tousertype(tolua_S,1,0);
  bool use = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUseRender'", NULL);
#endif
  {
   self->setUseRender(use);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUseRender'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setShaderProgramName of class  TLRenderNode */
#ifndef TOLUA_DISABLE_tolua_api_TLRenderNode_setShaderProgramName00
static int tolua_api_TLRenderNode_setShaderProgramName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLRenderNode",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLRenderNode* self = (TLRenderNode*)  tolua_tousertype(tolua_S,1,0);
  std::string shaderName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setShaderProgramName'", NULL);
#endif
  {
   self->setShaderProgramName(shaderName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setShaderProgramName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBlendFunc of class  TLRenderNode */
#ifndef TOLUA_DISABLE_tolua_api_TLRenderNode_setBlendFunc00
static int tolua_api_TLRenderNode_setBlendFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLRenderNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ccBlendFunc",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLRenderNode* self = (TLRenderNode*)  tolua_tousertype(tolua_S,1,0);
  ccBlendFunc blendFunc = *((ccBlendFunc*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBlendFunc'", NULL);
#endif
  {
   self->setBlendFunc(blendFunc);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBlendFunc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  TLRenderNode */
#ifndef TOLUA_DISABLE_tolua_api_TLRenderNode_visit00
static int tolua_api_TLRenderNode_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLRenderNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLRenderNode* self = (TLRenderNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'", NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCustomUniforms of class  TLRenderNode */
#ifndef TOLUA_DISABLE_tolua_api_TLRenderNode_setCustomUniforms00
static int tolua_api_TLRenderNode_setCustomUniforms00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLRenderNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLRenderNode* self = (TLRenderNode*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float g = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
  float a = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCustomUniforms'", NULL);
#endif
  {
   self->setCustomUniforms(r,g,b,a);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCustomUniforms'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCustomUniformsEx of class  TLRenderNode */
#ifndef TOLUA_DISABLE_tolua_api_TLRenderNode_setCustomUniformsEx00
static int tolua_api_TLRenderNode_setCustomUniformsEx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLRenderNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLRenderNode* self = (TLRenderNode*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float g = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
  float a = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCustomUniformsEx'", NULL);
#endif
  {
   self->setCustomUniformsEx(r,g,b,a);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCustomUniformsEx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRenderSize of class  TLRenderNode */
#ifndef TOLUA_DISABLE_tolua_api_TLRenderNode_setRenderSize00
static int tolua_api_TLRenderNode_setRenderSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLRenderNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLRenderNode* self = (TLRenderNode*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRenderSize'", NULL);
#endif
  {
   self->setRenderSize(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRenderSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_api_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"TLRunningScene","TLRunningScene","CCScene",NULL);
  tolua_beginmodule(tolua_S,"TLRunningScene");
   tolua_function(tolua_S,"create",tolua_api_TLRunningScene_create00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"NWTC_SOCKET_RECEIVE_ERROR",NWTC_SOCKET_RECEIVE_ERROR);
  tolua_constant(tolua_S,"NWTC_SOCKET_CONNECT_ERROR",NWTC_SOCKET_CONNECT_ERROR);
  tolua_constant(tolua_S,"NWTC_INVALID_SOCKET",NWTC_INVALID_SOCKET);
  tolua_constant(tolua_S,"NWTC_SOCKET_CONNECT_SUCCESS",NWTC_SOCKET_CONNECT_SUCCESS);
  tolua_constant(tolua_S,"NWTC_SOCKET_RECONNECT",NWTC_SOCKET_RECONNECT);
  tolua_constant(tolua_S,"NWTC_SOCKET_DISCONNECT",NWTC_SOCKET_DISCONNECT);
  tolua_constant(tolua_S,"NWTC_SOCKET_SERVER_KICK_OUT",NWTC_SOCKET_SERVER_KICK_OUT);
  tolua_constant(tolua_S,"NWTC_SOCKET_DISCONNECT_2",NWTC_SOCKET_DISCONNECT_2);
  tolua_constant(tolua_S,"NWTS_CLOSED",NWTS_CLOSED);
  tolua_constant(tolua_S,"NWTS_CONNECTING",NWTS_CONNECTING);
  tolua_constant(tolua_S,"NWTS_CONNECTED",NWTS_CONNECTED);
  tolua_constant(tolua_S,"NWTS_RECONNECT_REQUEST",NWTS_RECONNECT_REQUEST);
  tolua_constant(tolua_S,"NWTS_RECONNECTING",NWTS_RECONNECTING);
  tolua_function(tolua_S,"dump_rusage",tolua_api_dump_rusage00);
  tolua_function(tolua_S,"dump_texture",tolua_api_dump_texture00);
  tolua_function(tolua_S,"smoothstep",tolua_api_smoothstep00);
  tolua_function(tolua_S,"setReconnectionInterval",tolua_api_setReconnectionInterval00);
  tolua_function(tolua_S,"getRealMsgID",tolua_api_getRealMsgID00);
  tolua_function(tolua_S,"setProjectNickname",tolua_api_setProjectNickname00);
  tolua_function(tolua_S,"getProjectNickname",tolua_api_getProjectNickname00);
  tolua_function(tolua_S,"getNodeAlphaLua",tolua_api_getNodeAlphaLua00);
  tolua_function(tolua_S,"setNodeAlphaLua",tolua_api_setNodeAlphaLua00);
  tolua_function(tolua_S,"setNodeTLAlphaLua",tolua_api_setNodeTLAlphaLua00);
  tolua_function(tolua_S,"setNodeBLAlphaLua",tolua_api_setNodeBLAlphaLua00);
  tolua_function(tolua_S,"setNodeBRAlphaLua",tolua_api_setNodeBRAlphaLua00);
  tolua_function(tolua_S,"setNodeTRAlphaLua",tolua_api_setNodeTRAlphaLua00);
  tolua_function(tolua_S,"setNodeColor",tolua_api_setNodeColor00);
  tolua_function(tolua_S,"setNodeColorRLua",tolua_api_setNodeColorRLua00);
  tolua_function(tolua_S,"setNodeColorGLua",tolua_api_setNodeColorGLua00);
  tolua_function(tolua_S,"setNodeColorBLua",tolua_api_setNodeColorBLua00);
  tolua_function(tolua_S,"setNodeShaderProgram",tolua_api_setNodeShaderProgram00);
  tolua_cclass(tolua_S,"AssetsManager","AssetsManager","",NULL);
  tolua_beginmodule(tolua_S,"AssetsManager");
   tolua_function(tolua_S,"sharedAssetsManager",tolua_api_AssetsManager_sharedAssetsManager00);
   tolua_function(tolua_S,"Load",tolua_api_AssetsManager_Load00);
   tolua_function(tolua_S,"fileExists",tolua_api_AssetsManager_fileExists00);
   tolua_function(tolua_S,"getRealPath",tolua_api_AssetsManager_getRealPath00);
   tolua_function(tolua_S,"getFileContent",tolua_api_AssetsManager_getFileContent00);
   tolua_function(tolua_S,"getVersion",tolua_api_AssetsManager_getVersion00);
   tolua_function(tolua_S,"getConfigVersion",tolua_api_AssetsManager_getConfigVersion00);
   tolua_function(tolua_S,"getVersionName",tolua_api_AssetsManager_getVersionName00);
   tolua_function(tolua_S,"supportAssetsUpgrade",tolua_api_AssetsManager_supportAssetsUpgrade00);
   tolua_function(tolua_S,"isLuaFileExist",tolua_api_AssetsManager_isLuaFileExist00);
   tolua_function(tolua_S,"addSearchPath",tolua_api_AssetsManager_addSearchPath00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MovieClip","MovieClip","CCNodeRGBA",NULL);
  tolua_beginmodule(tolua_S,"MovieClip");
   tolua_variable(tolua_S,"mcBoundingBox",tolua_get_MovieClip_mcBoundingBox,tolua_set_MovieClip_mcBoundingBox);
   tolua_variable(tolua_S,"mcOriginBoundingBox",tolua_get_MovieClip_mcOriginBoundingBox,tolua_set_MovieClip_mcOriginBoundingBox);
   tolua_function(tolua_S,"createWithName",tolua_api_MovieClip_createWithName00);
   tolua_function(tolua_S,"play",tolua_api_MovieClip_play00);
   tolua_function(tolua_S,"start",tolua_api_MovieClip_start00);
   tolua_function(tolua_S,"pause",tolua_api_MovieClip_pause00);
   tolua_function(tolua_S,"setAutoClear",tolua_api_MovieClip_setAutoClear00);
   tolua_function(tolua_S,"getAutoClear",tolua_api_MovieClip_getAutoClear00);
   tolua_function(tolua_S,"setFrameRate",tolua_api_MovieClip_setFrameRate00);
   tolua_function(tolua_S,"getFrameRate",tolua_api_MovieClip_getFrameRate00);
   tolua_function(tolua_S,"getSymbolInfo",tolua_api_MovieClip_getSymbolInfo00);
   tolua_function(tolua_S,"RegisterPlayEndCallbackHandler",tolua_api_MovieClip_RegisterPlayEndCallbackHandler00);
   tolua_function(tolua_S,"getResetKeyframe",tolua_api_MovieClip_getResetKeyframe00);
   tolua_function(tolua_S,"setResetKeyframe",tolua_api_MovieClip_setResetKeyframe00);
   tolua_function(tolua_S,"getTimeLength",tolua_api_MovieClip_getTimeLength00);
   tolua_function(tolua_S,"getFrameCount",tolua_api_MovieClip_getFrameCount00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"getBoundingBox",tolua_api_getBoundingBox00);
  tolua_function(tolua_S,"toMovieClip",tolua_api_toMovieClip00);
  tolua_function(tolua_S,"toTLModel",tolua_api_toTLModel00);
  tolua_function(tolua_S,"toSprite",tolua_api_toSprite00);
  tolua_function(tolua_S,"toTTFText",tolua_api_toTTFText00);
  tolua_function(tolua_S,"toTLRichTex",tolua_api_toTLRichTex00);
  tolua_function(tolua_S,"toBMText",tolua_api_toBMText00);
  tolua_function(tolua_S,"toRect",tolua_api_toRect00);
  tolua_function(tolua_S,"toFrame",tolua_api_toFrame00);
  tolua_function(tolua_S,"toParticle",tolua_api_toParticle00);
  tolua_function(tolua_S,"toRenderNode",tolua_api_toRenderNode00);
  tolua_cclass(tolua_S,"ClipNode","ClipNode","CCNode",NULL);
  tolua_beginmodule(tolua_S,"ClipNode");
   tolua_function(tolua_S,"clipNode",tolua_api_ClipNode_clipNode00);
   tolua_function(tolua_S,"clipNode",tolua_api_ClipNode_clipNode01);
   tolua_function(tolua_S,"getClipRegion",tolua_api_ClipNode_getClipRegion00);
   tolua_function(tolua_S,"setClipRegion",tolua_api_ClipNode_setClipRegion00);
   tolua_function(tolua_S,"removeClipRegion",tolua_api_ClipNode_removeClipRegion00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MCFrame","MCFrame","ClipNode",NULL);
  tolua_beginmodule(tolua_S,"MCFrame");
   tolua_variable(tolua_S,"mcBoundingBox",tolua_get_MCFrame_mcBoundingBox,tolua_set_MCFrame_mcBoundingBox);
   tolua_variable(tolua_S,"mcOriginBoundingBox",tolua_get_MCFrame_mcOriginBoundingBox,tolua_set_MCFrame_mcOriginBoundingBox);
   tolua_function(tolua_S,"createWithBox",tolua_api_MCFrame_createWithBox00);
   tolua_function(tolua_S,"initWithBox",tolua_api_MCFrame_initWithBox00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MCLoader","MCLoader","CCObject",NULL);
  tolua_beginmodule(tolua_S,"MCLoader");
   tolua_function(tolua_S,"sharedMCLoader",tolua_api_MCLoader_sharedMCLoader00);
   tolua_function(tolua_S,"loadIndexFile",tolua_api_MCLoader_loadIndexFile00);
   tolua_function(tolua_S,"getSymbol",tolua_api_MCLoader_getSymbol00);
   tolua_function(tolua_S,"loadSpriteFrame",tolua_api_MCLoader_loadSpriteFrame00);
   tolua_function(tolua_S,"loadSprite",tolua_api_MCLoader_loadSprite00);
   tolua_function(tolua_S,"loadSpriteAsync",tolua_api_MCLoader_loadSpriteAsync00);
   tolua_function(tolua_S,"loadSpriteAsyncCallback",tolua_api_MCLoader_loadSpriteAsyncCallback00);
   tolua_function(tolua_S,"loadTextureAsync",tolua_api_MCLoader_loadTextureAsync00);
   tolua_function(tolua_S,"loadTextureByFrame",tolua_api_MCLoader_loadTextureByFrame00);
   tolua_function(tolua_S,"loadTexture",tolua_api_MCLoader_loadTexture00);
   tolua_function(tolua_S,"getTexturePath",tolua_api_MCLoader_getTexturePath00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MainSceneRoleMC","MainSceneRoleMC","CCNode",NULL);
  tolua_beginmodule(tolua_S,"MainSceneRoleMC");
   tolua_variable(tolua_S,"mcBoundingBox",tolua_get_MainSceneRoleMC_mcBoundingBox,tolua_set_MainSceneRoleMC_mcBoundingBox);
   tolua_function(tolua_S,"createWithName",tolua_api_MainSceneRoleMC_createWithName00);
   tolua_function(tolua_S,"playStand",tolua_api_MainSceneRoleMC_playStand00);
   tolua_function(tolua_S,"playWalk",tolua_api_MainSceneRoleMC_playWalk00);
   tolua_function(tolua_S,"setFrameRate",tolua_api_MainSceneRoleMC_setFrameRate00);
   tolua_function(tolua_S,"setFlipX",tolua_api_MainSceneRoleMC_setFlipX00);
   tolua_function(tolua_S,"setFlipY",tolua_api_MainSceneRoleMC_setFlipY00);
   tolua_function(tolua_S,"getRoleSprite",tolua_api_MainSceneRoleMC_getRoleSprite00);
   tolua_function(tolua_S,"setRoleSpriteOffsetX",tolua_api_MainSceneRoleMC_setRoleSpriteOffsetX00);
   tolua_function(tolua_S,"getRoleSpriteOffsetX",tolua_api_MainSceneRoleMC_getRoleSpriteOffsetX00);
   tolua_function(tolua_S,"setRoleSpriteOffsetY",tolua_api_MainSceneRoleMC_setRoleSpriteOffsetY00);
   tolua_function(tolua_S,"getRoleSpriteOffsetY",tolua_api_MainSceneRoleMC_getRoleSpriteOffsetY00);
   tolua_function(tolua_S,"resetRoleSpritePosition",tolua_api_MainSceneRoleMC_resetRoleSpritePosition00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CCImage","CCImage","",NULL);
  tolua_beginmodule(tolua_S,"CCImage");
   tolua_constant(tolua_S,"kAlignCenter",CCImage::kAlignCenter);
   tolua_constant(tolua_S,"kAlignTop",CCImage::kAlignTop);
   tolua_constant(tolua_S,"kAlignTopRight",CCImage::kAlignTopRight);
   tolua_constant(tolua_S,"kAlignRight",CCImage::kAlignRight);
   tolua_constant(tolua_S,"kAlignBottomRight",CCImage::kAlignBottomRight);
   tolua_constant(tolua_S,"kAlignBottom",CCImage::kAlignBottom);
   tolua_constant(tolua_S,"kAlignBottomLeft",CCImage::kAlignBottomLeft);
   tolua_constant(tolua_S,"kAlignLeft",CCImage::kAlignLeft);
   tolua_constant(tolua_S,"kAlignTopLeft",CCImage::kAlignTopLeft);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TLFontTex","TLFontTex","",NULL);
  tolua_beginmodule(tolua_S,"TLFontTex");
   tolua_function(tolua_S,"sharedTLFontTex",tolua_api_TLFontTex_sharedTLFontTex00);
   tolua_function(tolua_S,"newBatchNode",tolua_api_TLFontTex_newBatchNode00);
   tolua_function(tolua_S,"initFontTexture",tolua_api_TLFontTex_initFontTexture00);
   tolua_function(tolua_S,"getChatTextInfo",tolua_api_TLFontTex_getChatTextInfo00);
   tolua_function(tolua_S,"getFontScale",tolua_api_TLFontTex_getFontScale00);
   tolua_function(tolua_S,"saveFontTexture",tolua_api_TLFontTex_saveFontTexture00);
   tolua_function(tolua_S,"setFontOriginSize",tolua_api_TLFontTex_setFontOriginSize00);
   tolua_function(tolua_S,"setFontName",tolua_api_TLFontTex_setFontName00);
   tolua_function(tolua_S,"setEdgeSize",tolua_api_TLFontTex_setEdgeSize00);
   tolua_function(tolua_S,"setStrokeEdge",tolua_api_TLFontTex_setStrokeEdge00);
   tolua_function(tolua_S,"setParseRichTextHandler",tolua_api_TLFontTex_setParseRichTextHandler00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"TL_RICH_STRING_FLAG_AUTO_WRAP",TL_RICH_STRING_FLAG_AUTO_WRAP);
  tolua_constant(tolua_S,"TL_RICH_STRING_FLAG_ONE_LINE",TL_RICH_STRING_FLAG_ONE_LINE);
  tolua_constant(tolua_S,"TL_RICH_STRING_FLAG_ONE_LINE_DOTDOTDOT",TL_RICH_STRING_FLAG_ONE_LINE_DOTDOTDOT);
  tolua_cclass(tolua_S,"TLLabelRichTex","TLLabelRichTex","CCNodeRGBA",NULL);
  tolua_beginmodule(tolua_S,"TLLabelRichTex");
   tolua_function(tolua_S,"create",tolua_api_TLLabelRichTex_create00);
   tolua_function(tolua_S,"create",tolua_api_TLLabelRichTex_create01);
   tolua_function(tolua_S,"create",tolua_api_TLLabelRichTex_create02);
   tolua_function(tolua_S,"setRichString",tolua_api_TLLabelRichTex_setRichString00);
   tolua_function(tolua_S,"getRichString",tolua_api_TLLabelRichTex_getRichString00);
   tolua_function(tolua_S,"setFontSize",tolua_api_TLLabelRichTex_setFontSize00);
   tolua_function(tolua_S,"getFontSize",tolua_api_TLLabelRichTex_getFontSize00);
   tolua_function(tolua_S,"setAlignment",tolua_api_TLLabelRichTex_setAlignment00);
   tolua_function(tolua_S,"getAlignment",tolua_api_TLLabelRichTex_getAlignment00);
   tolua_function(tolua_S,"setFontColorR",tolua_api_TLLabelRichTex_setFontColorR00);
   tolua_function(tolua_S,"setFontColorG",tolua_api_TLLabelRichTex_setFontColorG00);
   tolua_function(tolua_S,"setFontColorB",tolua_api_TLLabelRichTex_setFontColorB00);
   tolua_function(tolua_S,"setFontColorA",tolua_api_TLLabelRichTex_setFontColorA00);
   tolua_function(tolua_S,"moveOffsetX",tolua_api_TLLabelRichTex_moveOffsetX00);
   tolua_function(tolua_S,"appendSpriteToCurrentLine",tolua_api_TLLabelRichTex_appendSpriteToCurrentLine00);
   tolua_function(tolua_S,"appendText",tolua_api_TLLabelRichTex_appendText00);
   tolua_function(tolua_S,"getRealSize",tolua_api_TLLabelRichTex_getRealSize00);
   tolua_function(tolua_S,"adjustLayout",tolua_api_TLLabelRichTex_adjustLayout00);
   tolua_function(tolua_S,"appendLine",tolua_api_TLLabelRichTex_appendLine00);
   tolua_function(tolua_S,"getWindow",tolua_api_TLLabelRichTex_getWindow00);
   tolua_function(tolua_S,"setWindow",tolua_api_TLLabelRichTex_setWindow00);
   tolua_function(tolua_S,"setCurrentNodeHandler",tolua_api_TLLabelRichTex_setCurrentNodeHandler00);
   tolua_function(tolua_S,"clearCurrentNodeHandler",tolua_api_TLLabelRichTex_clearCurrentNodeHandler00);
   tolua_function(tolua_S,"setRealSizeLayout",tolua_api_TLLabelRichTex_setRealSizeLayout00);
   tolua_function(tolua_S,"setTabNum",tolua_api_TLLabelRichTex_setTabNum00);
   tolua_function(tolua_S,"setWordSpacing",tolua_api_TLLabelRichTex_setWordSpacing00);
   tolua_function(tolua_S,"setLineSpacing",tolua_api_TLLabelRichTex_setLineSpacing00);
   tolua_function(tolua_S,"setColorIndex",tolua_api_TLLabelRichTex_setColorIndex00);
   tolua_function(tolua_S,"getColorIndex",tolua_api_TLLabelRichTex_getColorIndex00);
   tolua_function(tolua_S,"changeColorIndex",tolua_api_TLLabelRichTex_changeColorIndex00);
   tolua_function(tolua_S,"getTextNode",tolua_api_TLLabelRichTex_getTextNode00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TLRichTexVerbatim","TLRichTexVerbatim","TLLabelRichTex",NULL);
  tolua_beginmodule(tolua_S,"TLRichTexVerbatim");
   tolua_function(tolua_S,"create",tolua_api_TLRichTexVerbatim_create00);
   tolua_function(tolua_S,"create",tolua_api_TLRichTexVerbatim_create01);
   tolua_function(tolua_S,"create",tolua_api_TLRichTexVerbatim_create02);
   tolua_function(tolua_S,"setRichString",tolua_api_TLRichTexVerbatim_setRichString00);
   tolua_function(tolua_S,"setSpeed",tolua_api_TLRichTexVerbatim_setSpeed00);
   tolua_function(tolua_S,"play",tolua_api_TLRichTexVerbatim_play00);
   tolua_function(tolua_S,"stop",tolua_api_TLRichTexVerbatim_stop00);
   tolua_function(tolua_S,"isEnd",tolua_api_TLRichTexVerbatim_isEnd00);
   tolua_function(tolua_S,"fastEnd",tolua_api_TLRichTexVerbatim_fastEnd00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CNetMsg","CNetMsg","CCObject",NULL);
  tolua_beginmodule(tolua_S,"CNetMsg");
   tolua_function(tolua_S,"GetMsgID",tolua_api_CNetMsg_GetMsgID00);
   tolua_function(tolua_S,"GetMsgCode",tolua_api_CNetMsg_GetMsgCode00);
   tolua_function(tolua_S,"ParseContent",tolua_api_CNetMsg_ParseContent00);
   tolua_function(tolua_S,"GetContentLength",tolua_api_CNetMsg_GetContentLength00);
   tolua_function(tolua_S,"GetContentData",tolua_api_CNetMsg_GetContentData00);
   tolua_function(tolua_S,"GetContentStr",tolua_api_CNetMsg_GetContentStr00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CNetReceiver","CNetReceiver","",NULL);
  tolua_beginmodule(tolua_S,"CNetReceiver");
   tolua_function(tolua_S,"SharedNetReceiver",tolua_api_CNetReceiver_SharedNetReceiver00);
   tolua_function(tolua_S,"SetMsgErrorDefaultFuncPtr",tolua_api_CNetReceiver_SetMsgErrorDefaultFuncPtr00);
   tolua_function(tolua_S,"RegisterMsgErrorFuncPtr",tolua_api_CNetReceiver_RegisterMsgErrorFuncPtr00);
   tolua_function(tolua_S,"RegisterMsgProcessFuncPtr",tolua_api_CNetReceiver_RegisterMsgProcessFuncPtr00);
   tolua_function(tolua_S,"SendErrorMsgToSelf",tolua_api_CNetReceiver_SendErrorMsgToSelf00);
   tolua_function(tolua_S,"SendMsgToSelf",tolua_api_CNetReceiver_SendMsgToSelf00);
   tolua_function(tolua_S,"Reset",tolua_api_CNetReceiver_Reset00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CNetSender","CNetSender","",NULL);
  tolua_beginmodule(tolua_S,"CNetSender");
   tolua_function(tolua_S,"SharedNetSender",tolua_api_CNetSender_SharedNetSender00);
   tolua_function(tolua_S,"CloseSocket",tolua_api_CNetSender_CloseSocket00);
   tolua_function(tolua_S,"Connect",tolua_api_CNetSender_Connect00);
   tolua_function(tolua_S,"NewNetMsgAndSend",tolua_api_CNetSender_NewNetMsgAndSend00);
   tolua_function(tolua_S,"appendReconnectVerifyMsgID",tolua_api_CNetSender_appendReconnectVerifyMsgID00);
   tolua_function(tolua_S,"setIsNeedReconnection",tolua_api_CNetSender_setIsNeedReconnection00);
   tolua_function(tolua_S,"getIsNeedReconnection",tolua_api_CNetSender_getIsNeedReconnection00);
   tolua_function(tolua_S,"setSocketStatus",tolua_api_CNetSender_setSocketStatus00);
   tolua_function(tolua_S,"getSocketStatus",tolua_api_CNetSender_getSocketStatus00);
   tolua_function(tolua_S,"reconnectionVerify",tolua_api_CNetSender_reconnectionVerify00);
   tolua_function(tolua_S,"reconnectionSucceeful",tolua_api_CNetSender_reconnectionSucceeful00);
   tolua_function(tolua_S,"setClearMsgIDHandler",tolua_api_CNetSender_setClearMsgIDHandler00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CHttpDownloader","CHttpDownloader","CCObject",NULL);
  tolua_beginmodule(tolua_S,"CHttpDownloader");
   tolua_function(tolua_S,"sharedHttpDownloader",tolua_api_CHttpDownloader_sharedHttpDownloader00);
   tolua_function(tolua_S,"purgeSharedHttpDownloader",tolua_api_CHttpDownloader_purgeSharedHttpDownloader00);
   tolua_function(tolua_S,"getContent",tolua_api_CHttpDownloader_getContent00);
   tolua_function(tolua_S,"saveToFile",tolua_api_CHttpDownloader_saveToFile00);
   tolua_function(tolua_S,"register_callback",tolua_api_CHttpDownloader_register_callback00);
   tolua_function(tolua_S,"register_progress_callback",tolua_api_CHttpDownloader_register_progress_callback00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"HTTP_REQUEST_TYPE_MSG",HTTP_REQUEST_TYPE_MSG);
  tolua_constant(tolua_S,"HTTP_REQUEST_TYPE_FILE",HTTP_REQUEST_TYPE_FILE);
  tolua_cclass(tolua_S,"HttpRequest","HttpRequest","",NULL);
  tolua_beginmodule(tolua_S,"HttpRequest");
   tolua_function(tolua_S,"getRequestType",tolua_api_HttpRequest_getRequestType00);
   tolua_function(tolua_S,"getAppendToRecv",tolua_api_HttpRequest_getAppendToRecv00);
   tolua_function(tolua_S,"set_opt",tolua_api_HttpRequest_set_opt00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"HttpRequestMsg","HttpRequestMsg","HttpRequest",NULL);
  tolua_beginmodule(tolua_S,"HttpRequestMsg");
   tolua_function(tolua_S,"setRecvBuffer",tolua_api_HttpRequestMsg_setRecvBuffer00);
   tolua_function(tolua_S,"setSendBuffer",tolua_api_HttpRequestMsg_setSendBuffer00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"HttpRequestFile","HttpRequestFile","HttpRequest",NULL);
  tolua_beginmodule(tolua_S,"HttpRequestFile");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TLHttpClient","TLHttpClient","",NULL);
  tolua_beginmodule(tolua_S,"TLHttpClient");
   tolua_function(tolua_S,"sharedHttpClient",tolua_api_TLHttpClient_sharedHttpClient00);
   tolua_function(tolua_S,"sendMsg",tolua_api_TLHttpClient_sendMsg00);
   tolua_function(tolua_S,"sendMsg",tolua_api_TLHttpClient_sendMsg01);
   tolua_function(tolua_S,"requestFile",tolua_api_TLHttpClient_requestFile00);
   tolua_function(tolua_S,"appendRequestToSend",tolua_api_TLHttpClient_appendRequestToSend00);
   tolua_function(tolua_S,"getSendRequest",tolua_api_TLHttpClient_getSendRequest00);
   tolua_function(tolua_S,"appendRequestToRecv",tolua_api_TLHttpClient_appendRequestToRecv00);
   tolua_function(tolua_S,"setDefaultURL",tolua_api_TLHttpClient_setDefaultURL00);
   tolua_function(tolua_S,"getDefaultURL",tolua_api_TLHttpClient_getDefaultURL00);
   tolua_function(tolua_S,"setCookiePath",tolua_api_TLHttpClient_setCookiePath00);
   tolua_function(tolua_S,"getCookiePath",tolua_api_TLHttpClient_getCookiePath00);
   tolua_function(tolua_S,"setPlaybackScriptHandler",tolua_api_TLHttpClient_setPlaybackScriptHandler00);
   tolua_function(tolua_S,"setResetHttpClient",tolua_api_TLHttpClient_setResetHttpClient00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SimpleAudioEngine","SimpleAudioEngine","",NULL);
  tolua_beginmodule(tolua_S,"SimpleAudioEngine");
   tolua_function(tolua_S,"stopAllEffects",tolua_api_SimpleAudioEngine_stopAllEffects00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TLMaskLayer","TLMaskLayer","CCLayer",NULL);
  tolua_beginmodule(tolua_S,"TLMaskLayer");
   tolua_function(tolua_S,"sharedTLMaskLayer",tolua_api_TLMaskLayer_sharedTLMaskLayer00);
   tolua_function(tolua_S,"resetMaskLayer",tolua_api_TLMaskLayer_resetMaskLayer00);
   tolua_function(tolua_S,"setIsMaskScene",tolua_api_TLMaskLayer_setIsMaskScene00);
   tolua_function(tolua_S,"appendHighlightRect",tolua_api_TLMaskLayer_appendHighlightRect00);
   tolua_function(tolua_S,"appendHighlightRect2",tolua_api_TLMaskLayer_appendHighlightRect200);
   tolua_function(tolua_S,"setMaskColor",tolua_api_TLMaskLayer_setMaskColor00);
   tolua_function(tolua_S,"test",tolua_api_TLMaskLayer_test00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"TL_WINDOW_FLAG_ENABLE",TL_WINDOW_FLAG_ENABLE);
  tolua_constant(tolua_S,"TL_WINDOW_FLAG_PRESSED",TL_WINDOW_FLAG_PRESSED);
  tolua_constant(tolua_S,"TL_WINDOW_FLAG_DBLCLKED",TL_WINDOW_FLAG_DBLCLKED);
  tolua_constant(tolua_S,"TL_WINDOW_FLAG_DROP_DRAG",TL_WINDOW_FLAG_DROP_DRAG);
  tolua_constant(tolua_S,"TL_WINDOW_FLAG_TOUCH_OFF_DROP_DRAG",TL_WINDOW_FLAG_TOUCH_OFF_DROP_DRAG);
  tolua_constant(tolua_S,"TL_WINDOW_FLAG_RECEIVE_DROP_DRAG",TL_WINDOW_FLAG_RECEIVE_DROP_DRAG);
  tolua_constant(tolua_S,"TL_WINDOW_FLAG_SCROLL",TL_WINDOW_FLAG_SCROLL);
  tolua_constant(tolua_S,"TL_WINDOW_FLAG_INPUT",TL_WINDOW_FLAG_INPUT);
  tolua_constant(tolua_S,"TL_WINDOW_FLAG_CLIP",TL_WINDOW_FLAG_CLIP);
  tolua_constant(tolua_S,"TL_WINDOW_FLAG_CONTAINER",TL_WINDOW_FLAG_CONTAINER);
  tolua_constant(tolua_S,"TL_WINDOW_UNIVARSAL",TL_WINDOW_UNIVARSAL);
  tolua_constant(tolua_S,"TL_WINDOW_CONTAINER",TL_WINDOW_CONTAINER);
  tolua_constant(tolua_S,"TL_WINDOW_SCROLL",TL_WINDOW_SCROLL);
  tolua_constant(tolua_S,"TL_WINDOW_INPUT",TL_WINDOW_INPUT);
  tolua_constant(tolua_S,"TL_WINDOW_DRAG_DROP",TL_WINDOW_DRAG_DROP);
  tolua_constant(tolua_S,"TL_EVENT_BUTTON_DOWN",TL_EVENT_BUTTON_DOWN);
  tolua_constant(tolua_S,"TL_EVENT_BUTTON_UP",TL_EVENT_BUTTON_UP);
  tolua_constant(tolua_S,"TL_EVENT_BUTTON_DBLCLK",TL_EVENT_BUTTON_DBLCLK);
  tolua_constant(tolua_S,"TL_EVENT_MOUSE_MOVE",TL_EVENT_MOUSE_MOVE);
  tolua_constant(tolua_S,"TL_EVENT_BUTTON_CLICK",TL_EVENT_BUTTON_CLICK);
  tolua_constant(tolua_S,"TL_EVENT_BUTTON_RELEASE",TL_EVENT_BUTTON_RELEASE);
  tolua_constant(tolua_S,"TL_EVENT_LOST_FOCUS",TL_EVENT_LOST_FOCUS);
  tolua_constant(tolua_S,"TL_EVENT_DROP_DRAG_START",TL_EVENT_DROP_DRAG_START);
  tolua_constant(tolua_S,"TL_EVENT_DROP_DRAG_RECEIVE",TL_EVENT_DROP_DRAG_RECEIVE);
  tolua_constant(tolua_S,"TL_EVENT_DROP_DRAG_END",TL_EVENT_DROP_DRAG_END);
  tolua_constant(tolua_S,"TL_EVENT_DROP_DRAG_CANCEL",TL_EVENT_DROP_DRAG_CANCEL);
  tolua_constant(tolua_S,"TL_EVENT_SCROLL_CALCULATE_SCROLL_MAX_LENGTH",TL_EVENT_SCROLL_CALCULATE_SCROLL_MAX_LENGTH);
  tolua_constant(tolua_S,"TL_EVENT_SCROLL_ON_SCROLL",TL_EVENT_SCROLL_ON_SCROLL);
  tolua_constant(tolua_S,"TL_EVENT_SCROLL_NEED_ELEMENT",TL_EVENT_SCROLL_NEED_ELEMENT);
  tolua_constant(tolua_S,"TL_EVENT_ACTION",TL_EVENT_ACTION);
  tolua_constant(tolua_S,"TL_EVENT_ENCHANGED",TL_EVENT_ENCHANGED);
  tolua_constant(tolua_S,"TL_EVENT_LONG_PRESS",TL_EVENT_LONG_PRESS);
  tolua_constant(tolua_S,"TL_EVENT_DESTORY",TL_EVENT_DESTORY);
  tolua_constant(tolua_S,"TL_EVENT_RESULT_NOT_SET_EVENT",TL_EVENT_RESULT_NOT_SET_EVENT);
  tolua_constant(tolua_S,"TL_EVENT_RESULT_DROP_DRAG_START_FAILED",TL_EVENT_RESULT_DROP_DRAG_START_FAILED);
  tolua_constant(tolua_S,"TL_EVENT_RESULT_DROP_DRAG_START_SUCCEED",TL_EVENT_RESULT_DROP_DRAG_START_SUCCEED);
  tolua_constant(tolua_S,"TL_EVENT_RESULT_DROP_DRAG_CANCEL",TL_EVENT_RESULT_DROP_DRAG_CANCEL);
  tolua_constant(tolua_S,"TL_EVENT_RESULT_DROP_DRAG_RECEIVE_FAILED",TL_EVENT_RESULT_DROP_DRAG_RECEIVE_FAILED);
  tolua_constant(tolua_S,"TL_EVENT_RESULT_DROP_DRAG_RECEIVE_SUCCEED",TL_EVENT_RESULT_DROP_DRAG_RECEIVE_SUCCEED);
  tolua_constant(tolua_S,"TL_EVENT_RESULT_EXEC_LUA_FAILED",TL_EVENT_RESULT_EXEC_LUA_FAILED);
  tolua_constant(tolua_S,"TL_EVENT_RESULT_BUBLE_UP",TL_EVENT_RESULT_BUBLE_UP);
  tolua_constant(tolua_S,"TL_EVENT_RESULT_DEFAULT_PROCESS",TL_EVENT_RESULT_DEFAULT_PROCESS);
  tolua_constant(tolua_S,"TL_SCROLL_TYPE_NONE",TL_SCROLL_TYPE_NONE);
  tolua_constant(tolua_S,"TL_SCROLL_TYPE_LEFT_RIGHT",TL_SCROLL_TYPE_LEFT_RIGHT);
  tolua_constant(tolua_S,"TL_SCROLL_TYPE_UP_DOWN",TL_SCROLL_TYPE_UP_DOWN);
  tolua_constant(tolua_S,"TL_SCROLL_TYPE_FREE",TL_SCROLL_TYPE_FREE);
  tolua_constant(tolua_S,"TL_BUTTON_LOCATION_NONE",TL_BUTTON_LOCATION_NONE);
  tolua_constant(tolua_S,"TL_BUTTON_LOCATION_LEFT",TL_BUTTON_LOCATION_LEFT);
  tolua_constant(tolua_S,"TL_BUTTON_LOCATION_RIGHT",TL_BUTTON_LOCATION_RIGHT);
  tolua_constant(tolua_S,"TL_BUTTON_LOCATION_TOP",TL_BUTTON_LOCATION_TOP);
  tolua_constant(tolua_S,"TL_BUTTON_LOCATION_BOTTOM",TL_BUTTON_LOCATION_BOTTOM);
  tolua_constant(tolua_S,"TL_INPUT_TEXT_MODEL_NORMAL",TL_INPUT_TEXT_MODEL_NORMAL);
  tolua_constant(tolua_S,"TL_INPUT_TEXT_MODEL_NUMBER",TL_INPUT_TEXT_MODEL_NUMBER);
  tolua_constant(tolua_S,"TL_INPUT_TEXT_MODEL_ENGLISH",TL_INPUT_TEXT_MODEL_ENGLISH);
  tolua_constant(tolua_S,"TL_INPUT_TEXT_MODEL_ENGLISHNUMBER",TL_INPUT_TEXT_MODEL_ENGLISHNUMBER);
  tolua_constant(tolua_S,"TL_INPUT_TEXT_MODEL_CHINAANDENGLISH",TL_INPUT_TEXT_MODEL_CHINAANDENGLISH);
  tolua_constant(tolua_S,"TL_INPUT_TEXT_MODEL_CHINAANDENGLISH_ONLY",TL_INPUT_TEXT_MODEL_CHINAANDENGLISH_ONLY);
  tolua_constant(tolua_S,"TL_RETURN_TYPE_DEFAULT",TL_RETURN_TYPE_DEFAULT);
  tolua_constant(tolua_S,"TL_RETURN_TYPE_DONE",TL_RETURN_TYPE_DONE);
  tolua_constant(tolua_S,"TL_RETURN_TYPE_SEND",TL_RETURN_TYPE_SEND);
  tolua_constant(tolua_S,"TL_RETURN_TYPE_SEARCH",TL_RETURN_TYPE_SEARCH);
  tolua_constant(tolua_S,"TL_RETURN_TYPE_GO",TL_RETURN_TYPE_GO);
  tolua_constant(tolua_S,"TL_INPUT_FLAG_NORMAL",TL_INPUT_FLAG_NORMAL);
  tolua_constant(tolua_S,"TL_INPUT_FLAG_PASSWORD",TL_INPUT_FLAG_PASSWORD);
  tolua_cclass(tolua_S,"TLWindow","TLWindow","CCObject",NULL);
  tolua_beginmodule(tolua_S,"TLWindow");
   tolua_function(tolua_S,"createWindow",tolua_api_TLWindow_createWindow00);
   tolua_function(tolua_S,"AddChildWindow",tolua_api_TLWindow_AddChildWindow00);
   tolua_function(tolua_S,"RemoveAllChildWindow",tolua_api_TLWindow_RemoveAllChildWindow00);
   tolua_function(tolua_S,"RemoveChildWindow",tolua_api_TLWindow_RemoveChildWindow00);
   tolua_function(tolua_S,"GetChildWindow",tolua_api_TLWindow_GetChildWindow00);
   tolua_function(tolua_S,"FindWindow",tolua_api_TLWindow_FindWindow00);
   tolua_function(tolua_S,"FindWindow",tolua_api_TLWindow_FindWindow01);
   tolua_function(tolua_S,"RegisterEvent",tolua_api_TLWindow_RegisterEvent00);
   tolua_function(tolua_S,"unregisterEvent",tolua_api_TLWindow_unregisterEvent00);
   tolua_function(tolua_S,"GetNode",tolua_api_TLWindow_GetNode00);
   tolua_function(tolua_S,"setText",tolua_api_TLWindow_setText00);
   tolua_function(tolua_S,"getText",tolua_api_TLWindow_getText00);
   tolua_function(tolua_S,"setTextColor",tolua_api_TLWindow_setTextColor00);
   tolua_function(tolua_S,"getTextColor",tolua_api_TLWindow_getTextColor00);
   tolua_function(tolua_S,"setPlaceHolder",tolua_api_TLWindow_setPlaceHolder00);
   tolua_function(tolua_S,"getPlaceHolder",tolua_api_TLWindow_getPlaceHolder00);
   tolua_function(tolua_S,"setPlaceHolderColor",tolua_api_TLWindow_setPlaceHolderColor00);
   tolua_function(tolua_S,"getPlaceHolderColor",tolua_api_TLWindow_getPlaceHolderColor00);
   tolua_function(tolua_S,"setFontSize",tolua_api_TLWindow_setFontSize00);
   tolua_function(tolua_S,"setPlaceFontSize",tolua_api_TLWindow_setPlaceFontSize00);
   tolua_function(tolua_S,"setRichFlag",tolua_api_TLWindow_setRichFlag00);
   tolua_function(tolua_S,"setAlignment",tolua_api_TLWindow_setAlignment00);
   tolua_function(tolua_S,"setInputMode",tolua_api_TLWindow_setInputMode00);
   tolua_function(tolua_S,"setMaxLength",tolua_api_TLWindow_setMaxLength00);
   tolua_function(tolua_S,"setInputFlag",tolua_api_TLWindow_setInputFlag00);
   tolua_function(tolua_S,"setReturnType",tolua_api_TLWindow_setReturnType00);
   tolua_function(tolua_S,"setKeyboardWillShowHandler",tolua_api_TLWindow_setKeyboardWillShowHandler00);
   tolua_function(tolua_S,"setKeyboardWillHideHandler",tolua_api_TLWindow_setKeyboardWillHideHandler00);
   tolua_function(tolua_S,"getRealSize",tolua_api_TLWindow_getRealSize00);
   tolua_function(tolua_S,"GetWindowName",tolua_api_TLWindow_GetWindowName00);
   tolua_function(tolua_S,"SetWindowName",tolua_api_TLWindow_SetWindowName00);
   tolua_function(tolua_S,"GetIsEnable",tolua_api_TLWindow_GetIsEnable00);
   tolua_function(tolua_S,"SetIsEnable",tolua_api_TLWindow_SetIsEnable00);
   tolua_function(tolua_S,"GetIsScroll",tolua_api_TLWindow_GetIsScroll00);
   tolua_function(tolua_S,"GetIsInput",tolua_api_TLWindow_GetIsInput00);
   tolua_function(tolua_S,"GetIsVisible",tolua_api_TLWindow_GetIsVisible00);
   tolua_function(tolua_S,"SetIsVisible",tolua_api_TLWindow_SetIsVisible00);
   tolua_function(tolua_S,"GetWindowRect",tolua_api_TLWindow_GetWindowRect00);
   tolua_function(tolua_S,"SetWindowPos",tolua_api_TLWindow_SetWindowPos00);
   tolua_function(tolua_S,"GetWindowPos",tolua_api_TLWindow_GetWindowPos00);
   tolua_function(tolua_S,"HitTest",tolua_api_TLWindow_HitTest00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TLWindowManager","TLWindowManager","CCLayer",NULL);
  tolua_beginmodule(tolua_S,"TLWindowManager");
   tolua_function(tolua_S,"SharedTLWindowManager",tolua_api_TLWindowManager_SharedTLWindowManager00);
   tolua_function(tolua_S,"GetCenterPoint",tolua_api_TLWindowManager_GetCenterPoint00);
   tolua_function(tolua_S,"ReleaseAllWindow",tolua_api_TLWindowManager_ReleaseAllWindow00);
   tolua_function(tolua_S,"AddModuleWindow",tolua_api_TLWindowManager_AddModuleWindow00);
   tolua_function(tolua_S,"HideAllModuleWindow",tolua_api_TLWindowManager_HideAllModuleWindow00);
   tolua_function(tolua_S,"DestroyAllModuleWindow",tolua_api_TLWindowManager_DestroyAllModuleWindow00);
   tolua_function(tolua_S,"RemoveModuleWindow",tolua_api_TLWindowManager_RemoveModuleWindow00);
   tolua_function(tolua_S,"FindModuleWindow",tolua_api_TLWindowManager_FindModuleWindow00);
   tolua_function(tolua_S,"FindModuleWindow",tolua_api_TLWindowManager_FindModuleWindow01);
   tolua_function(tolua_S,"getLastPointX",tolua_api_TLWindowManager_getLastPointX00);
   tolua_function(tolua_S,"getLastPointY",tolua_api_TLWindowManager_getLastPointY00);
   tolua_function(tolua_S,"getLastPoint",tolua_api_TLWindowManager_getLastPoint00);
   tolua_function(tolua_S,"getWorldTime",tolua_api_TLWindowManager_getWorldTime00);
   tolua_function(tolua_S,"setKeyBackClickedHandler",tolua_api_TLWindowManager_setKeyBackClickedHandler00);
   tolua_function(tolua_S,"setKeyMenuClickedHandler",tolua_api_TLWindowManager_setKeyMenuClickedHandler00);
   tolua_function(tolua_S,"MoveToTop",tolua_api_TLWindowManager_MoveToTop00);
   tolua_function(tolua_S,"MoveToBottom",tolua_api_TLWindowManager_MoveToBottom00);
   tolua_function(tolua_S,"StopEventBubble",tolua_api_TLWindowManager_StopEventBubble00);
   tolua_function(tolua_S,"ShowUI",tolua_api_TLWindowManager_ShowUI00);
   tolua_function(tolua_S,"CancelDropDrag",tolua_api_TLWindowManager_CancelDropDrag00);
   tolua_function(tolua_S,"setTouchBeganHandler",tolua_api_TLWindowManager_setTouchBeganHandler00);
   tolua_function(tolua_S,"setTouchMovedHandler",tolua_api_TLWindowManager_setTouchMovedHandler00);
   tolua_function(tolua_S,"setTouchEndedHandler",tolua_api_TLWindowManager_setTouchEndedHandler00);
   tolua_function(tolua_S,"SetModalWindow",tolua_api_TLWindowManager_SetModalWindow00);
   tolua_function(tolua_S,"SetSystemWindow",tolua_api_TLWindowManager_SetSystemWindow00);
   tolua_function(tolua_S,"SetGuideWindow",tolua_api_TLWindowManager_SetGuideWindow00);
   tolua_function(tolua_S,"SetLockScreenWindow",tolua_api_TLWindowManager_SetLockScreenWindow00);
   tolua_function(tolua_S,"lockScreen",tolua_api_TLWindowManager_lockScreen00);
   tolua_function(tolua_S,"unlockScreen",tolua_api_TLWindowManager_unlockScreen00);
   tolua_function(tolua_S,"clearAllLock",tolua_api_TLWindowManager_clearAllLock00);
   tolua_function(tolua_S,"screenLockLog",tolua_api_TLWindowManager_screenLockLog00);
   tolua_function(tolua_S,"setCheckInputTextHandler",tolua_api_TLWindowManager_setCheckInputTextHandler00);
   tolua_function(tolua_S,"checkInputText",tolua_api_TLWindowManager_checkInputText00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TLDropDragHelper","TLDropDragHelper","CCObject",NULL);
  tolua_beginmodule(tolua_S,"TLDropDragHelper");
   tolua_function(tolua_S,"AppendShow",tolua_api_TLDropDragHelper_AppendShow00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"OpenPlatformLogin",tolua_api_OpenPlatformLogin00);
  tolua_function(tolua_S,"OpenPlatformLoginout",tolua_api_OpenPlatformLoginout00);
  tolua_function(tolua_S,"OpenPayInterface",tolua_api_OpenPayInterface00);
  tolua_function(tolua_S,"EnterPlatform",tolua_api_EnterPlatform00);
  tolua_function(tolua_S,"GetSdkType",tolua_api_GetSdkType00);
  tolua_function(tolua_S,"payWithAndroidSDK",tolua_api_payWithAndroidSDK00);
  tolua_function(tolua_S,"quitConfirm",tolua_api_quitConfirm00);
  tolua_function(tolua_S,"quitApplication",tolua_api_quitApplication00);
  tolua_function(tolua_S,"hideWindow",tolua_api_hideWindow00);
  tolua_function(tolua_S,"isETC1Supported",tolua_api_isETC1Supported00);
  tolua_function(tolua_S,"getDeviceId",tolua_api_getDeviceId00);
  tolua_function(tolua_S,"getIMSI",tolua_api_getIMSI00);
  tolua_function(tolua_S,"getUUID",tolua_api_getUUID00);
  tolua_function(tolua_S,"getPlatform",tolua_api_getPlatform00);
  tolua_function(tolua_S,"getOSVersion",tolua_api_getOSVersion00);
  tolua_function(tolua_S,"getResolution",tolua_api_getResolution00);
  tolua_function(tolua_S,"getUA",tolua_api_getUA00);
  tolua_function(tolua_S,"getMetaData",tolua_api_getMetaData00);
  tolua_function(tolua_S,"getdeviceUniqueID",tolua_api_getdeviceUniqueID00);
  tolua_function(tolua_S,"getMAC",tolua_api_getMAC00);
  tolua_function(tolua_S,"getidfa",tolua_api_getidfa00);
  tolua_function(tolua_S,"getIMEI",tolua_api_getIMEI00);
  tolua_function(tolua_S,"acquireWakeLock",tolua_api_acquireWakeLock00);
  tolua_function(tolua_S,"releaseWakeLock",tolua_api_releaseWakeLock00);
  tolua_function(tolua_S,"userActivity",tolua_api_userActivity00);
  tolua_function(tolua_S,"getPackageVersion",tolua_api_getPackageVersion00);
  tolua_function(tolua_S,"getPackageName",tolua_api_getPackageName00);
  tolua_function(tolua_S,"getNetworkTypeName",tolua_api_getNetworkTypeName00);
  tolua_function(tolua_S,"openURL",tolua_api_openURL00);
  tolua_function(tolua_S,"useConsole",tolua_api_useConsole00);
  tolua_function(tolua_S,"setResourceVersion",tolua_api_setResourceVersion00);
  tolua_function(tolua_S,"getResourceVersion",tolua_api_getResourceVersion00);
  tolua_function(tolua_S,"playMedia",tolua_api_playMedia00);
  tolua_function(tolua_S,"stopMedia",tolua_api_stopMedia00);
  tolua_function(tolua_S,"createLocalNotification",tolua_api_createLocalNotification00);
  tolua_function(tolua_S,"releaseLocalNotification",tolua_api_releaseLocalNotification00);
  tolua_function(tolua_S,"releaseAllLocalNotification",tolua_api_releaseAllLocalNotification00);
  tolua_constant(tolua_S,"CB_LOGIN_SUCCESS",CB_LOGIN_SUCCESS);
  tolua_constant(tolua_S,"CB_LOGIN_FAIL",CB_LOGIN_FAIL);
  tolua_constant(tolua_S,"CB_LOGOUT_SUCCESS",CB_LOGOUT_SUCCESS);
  tolua_constant(tolua_S,"CB_LOGOUT_FAIL",CB_LOGOUT_FAIL);
  tolua_constant(tolua_S,"CB_PAY_SUCCESS",CB_PAY_SUCCESS);
  tolua_constant(tolua_S,"CB_PAY_FAIL",CB_PAY_FAIL);
  tolua_constant(tolua_S,"CB_EXIT_CUSTOM",CB_EXIT_CUSTOM);
  tolua_constant(tolua_S,"CB_DONT_SUPPORT_LOGIN",CB_DONT_SUPPORT_LOGIN);
  tolua_constant(tolua_S,"CB_UNLOCK_LOGIN",CB_UNLOCK_LOGIN);
  tolua_constant(tolua_S,"CB_ITUNES_IAP_VALIDATION",CB_ITUNES_IAP_VALIDATION);
  tolua_constant(tolua_S,"CB_REACHABILITY_CHANGED",CB_REACHABILITY_CHANGED);
  tolua_constant(tolua_S,"CB_SDK_INIT_END",CB_SDK_INIT_END);
  tolua_constant(tolua_S,"CB_MAX",CB_MAX);
  tolua_function(tolua_S,"register_platform_callback",tolua_api_register_platform_callback00);
  tolua_function(tolua_S,"getAvailMemory",tolua_api_getAvailMemory00);
  tolua_cclass(tolua_S,"TLModel","TLModel","CCSpriteBatchNode",NULL);
  tolua_beginmodule(tolua_S,"TLModel");
   tolua_variable(tolua_S,"mcBoundingBox",tolua_get_TLModel_mcBoundingBox,tolua_set_TLModel_mcBoundingBox);
   tolua_function(tolua_S,"createWithName",tolua_api_TLModel_createWithName00);
   tolua_function(tolua_S,"play",tolua_api_TLModel_play00);
   tolua_function(tolua_S,"start",tolua_api_TLModel_start00);
   tolua_function(tolua_S,"stop",tolua_api_TLModel_stop00);
   tolua_function(tolua_S,"getIsPlaying",tolua_api_TLModel_getIsPlaying00);
   tolua_function(tolua_S,"setAutoClear",tolua_api_TLModel_setAutoClear00);
   tolua_function(tolua_S,"getAutoClear",tolua_api_TLModel_getAutoClear00);
   tolua_function(tolua_S,"setFrameRate",tolua_api_TLModel_setFrameRate00);
   tolua_function(tolua_S,"getFrameRate",tolua_api_TLModel_getFrameRate00);
   tolua_function(tolua_S,"getSymbolInfo",tolua_api_TLModel_getSymbolInfo00);
   tolua_function(tolua_S,"RegisterPlayEndCallbackHandler",tolua_api_TLModel_RegisterPlayEndCallbackHandler00);
   tolua_function(tolua_S,"RegisterPreCallScript",tolua_api_TLModel_RegisterPreCallScript00);
   tolua_function(tolua_S,"getLayerFirstNodePosition",tolua_api_TLModel_getLayerFirstNodePosition00);
   tolua_function(tolua_S,"getTimeLength",tolua_api_TLModel_getTimeLength00);
   tolua_function(tolua_S,"setColor",tolua_api_TLModel_setColor00);
   tolua_function(tolua_S,"getColor",tolua_api_TLModel_getColor00);
   tolua_function(tolua_S,"setOpacity",tolua_api_TLModel_setOpacity00);
   tolua_function(tolua_S,"getOpacity",tolua_api_TLModel_getOpacity00);
   tolua_function(tolua_S,"getTextureName",tolua_api_TLModel_getTextureName00);
   tolua_function(tolua_S,"setFrameColor",tolua_api_TLModel_setFrameColor00);
   tolua_function(tolua_S,"clearFrameColor",tolua_api_TLModel_clearFrameColor00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ParticleSystem","ParticleSystem","CCNode",NULL);
  tolua_beginmodule(tolua_S,"ParticleSystem");
   tolua_function(tolua_S,"GetPosition",tolua_api_ParticleSystem_GetPosition00);
   tolua_function(tolua_S,"SetPosition",tolua_api_ParticleSystem_SetPosition00);
   tolua_function(tolua_S,"SetPositionX",tolua_api_ParticleSystem_SetPositionX00);
   tolua_function(tolua_S,"SetPositionY",tolua_api_ParticleSystem_SetPositionY00);
   tolua_function(tolua_S,"SetScale",tolua_api_ParticleSystem_SetScale00);
   tolua_function(tolua_S,"getTimeLength",tolua_api_ParticleSystem_getTimeLength00);
   tolua_function(tolua_S,"registerPlayEndCallbackHandler",tolua_api_ParticleSystem_registerPlayEndCallbackHandler00);
   tolua_function(tolua_S,"getTextureCount",tolua_api_ParticleSystem_getTextureCount00);
   tolua_function(tolua_S,"getTextureName",tolua_api_ParticleSystem_getTextureName00);
   tolua_function(tolua_S,"stopInfiniteLoop",tolua_api_ParticleSystem_stopInfiniteLoop00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ParticleSystemManager","ParticleSystemManager","",NULL);
  tolua_beginmodule(tolua_S,"ParticleSystemManager");
   tolua_function(tolua_S,"sharedParticleSystemManager",tolua_api_ParticleSystemManager_sharedParticleSystemManager00);
   tolua_function(tolua_S,"LoadParticleSystems",tolua_api_ParticleSystemManager_LoadParticleSystems00);
   tolua_function(tolua_S,"createWithName",tolua_api_ParticleSystemManager_createWithName00);
   tolua_function(tolua_S,"createWithNameLua",tolua_api_ParticleSystemManager_createWithNameLua00);
   tolua_function(tolua_S,"cleanupCache",tolua_api_ParticleSystemManager_cleanupCache00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"LINEAR_IN",LINEAR_IN);
  tolua_constant(tolua_S,"LINEAR_OUT",LINEAR_OUT);
  tolua_constant(tolua_S,"LINEAR_INOUT",LINEAR_INOUT);
  tolua_constant(tolua_S,"BOUNCE_IN",BOUNCE_IN);
  tolua_constant(tolua_S,"BOUNCE_OUT",BOUNCE_OUT);
  tolua_constant(tolua_S,"BOUNCE_INOUT",BOUNCE_INOUT);
  tolua_constant(tolua_S,"EXPO_IN",EXPO_IN);
  tolua_constant(tolua_S,"EXPO_OUT",EXPO_OUT);
  tolua_constant(tolua_S,"EXPO_INOUT",EXPO_INOUT);
  tolua_constant(tolua_S,"ELASTIC_IN",ELASTIC_IN);
  tolua_constant(tolua_S,"ELASTIC_OUT",ELASTIC_OUT);
  tolua_constant(tolua_S,"ELASTIC_INOUT",ELASTIC_INOUT);
  tolua_constant(tolua_S,"QUART_IN",QUART_IN);
  tolua_constant(tolua_S,"QUART_OUT",QUART_OUT);
  tolua_constant(tolua_S,"QUART_INOUT",QUART_INOUT);
  tolua_constant(tolua_S,"QUINT_IN",QUINT_IN);
  tolua_constant(tolua_S,"QUINT_OUT",QUINT_OUT);
  tolua_constant(tolua_S,"QUINT_INOUT",QUINT_INOUT);
  tolua_constant(tolua_S,"QUAD_IN",QUAD_IN);
  tolua_constant(tolua_S,"QUAD_OUT",QUAD_OUT);
  tolua_constant(tolua_S,"QUAD_INOUT",QUAD_INOUT);
  tolua_constant(tolua_S,"BACK_IN",BACK_IN);
  tolua_constant(tolua_S,"BACK_OUT",BACK_OUT);
  tolua_constant(tolua_S,"BACK_INOUT",BACK_INOUT);
  tolua_constant(tolua_S,"CUBIC_IN",CUBIC_IN);
  tolua_constant(tolua_S,"CUBIC_OUT",CUBIC_OUT);
  tolua_constant(tolua_S,"CUBIC_INOUT",CUBIC_INOUT);
  tolua_constant(tolua_S,"STRONG_IN",STRONG_IN);
  tolua_constant(tolua_S,"STRONG_OUT",STRONG_OUT);
  tolua_constant(tolua_S,"STRONG_INOUT",STRONG_INOUT);
  tolua_constant(tolua_S,"CIRC_IN",CIRC_IN);
  tolua_constant(tolua_S,"CIRC_OUT",CIRC_OUT);
  tolua_constant(tolua_S,"CIRC_INOUT",CIRC_INOUT);
  tolua_constant(tolua_S,"SINE_IN",SINE_IN);
  tolua_constant(tolua_S,"SINE_OUT",SINE_OUT);
  tolua_constant(tolua_S,"SINE_INOUT",SINE_INOUT);
  tolua_cclass(tolua_S,"TLTweenManager","TLTweenManager","",NULL);
  tolua_beginmodule(tolua_S,"TLTweenManager");
   tolua_function(tolua_S,"sharedTLTweenManager",tolua_api_TLTweenManager_sharedTLTweenManager00);
   tolua_function(tolua_S,"tweenFromTo",tolua_api_TLTweenManager_tweenFromTo00);
   tolua_function(tolua_S,"removeTween",tolua_api_TLTweenManager_removeTween00);
   tolua_function(tolua_S,"removeAllTween",tolua_api_TLTweenManager_removeAllTween00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CCActionLuaCallFunc","CCActionLuaCallFunc","CCActionInstant",NULL);
  tolua_beginmodule(tolua_S,"CCActionLuaCallFunc");
   tolua_function(tolua_S,"create",tolua_api_CCActionLuaCallFunc_create00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"OpenPayWithAndroid",tolua_api_OpenPayWithAndroid00);
  tolua_cclass(tolua_S,"TLEditBox","TLEditBox","CCIMEDelegate",NULL);
  tolua_beginmodule(tolua_S,"TLEditBox");
   tolua_function(tolua_S,"getCurrentTLEditBox",tolua_api_TLEditBox_getCurrentTLEditBox00);
   tolua_function(tolua_S,"setText",tolua_api_TLEditBox_setText00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TLRenderNode","TLRenderNode","CCNodeRGBA",NULL);
  tolua_beginmodule(tolua_S,"TLRenderNode");
   tolua_function(tolua_S,"create",tolua_api_TLRenderNode_create00);
   tolua_function(tolua_S,"setUseRender",tolua_api_TLRenderNode_setUseRender00);
   tolua_function(tolua_S,"setShaderProgramName",tolua_api_TLRenderNode_setShaderProgramName00);
   tolua_function(tolua_S,"setBlendFunc",tolua_api_TLRenderNode_setBlendFunc00);
   tolua_function(tolua_S,"visit",tolua_api_TLRenderNode_visit00);
   tolua_function(tolua_S,"setCustomUniforms",tolua_api_TLRenderNode_setCustomUniforms00);
   tolua_function(tolua_S,"setCustomUniformsEx",tolua_api_TLRenderNode_setCustomUniformsEx00);
   tolua_function(tolua_S,"setRenderSize",tolua_api_TLRenderNode_setRenderSize00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_api (lua_State* tolua_S) {
 return tolua_api_open(tolua_S);
};
#endif

