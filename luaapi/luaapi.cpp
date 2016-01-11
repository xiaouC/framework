/*
** Lua binding: luaapi
** Generated automatically by tolua++-1.0.92 on 07/09/13 17:59:18.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_luaapi_open (lua_State* tolua_S);

#include "tolua_fix.h"
#include "Common/Common.h"
extern void assert_tolua_error(lua_State* L, const char* msg, tolua_Error* err);
#define tolua_error(L, msg, err) assert_tolua_error(L, msg, err)
#include "TLRunningScene.h"
#include "MC/MovieClip.h"
#include "MC/MCLoader.h"
#include "MC/MCNode.h"
using namespace cocos2d;
#include "toluaui/TLWindow.h"
using namespace cocos2d;
#include "toluaui/TLWindowManager.h"
#include "toluaui/TLDropDragHelper.h"
using namespace cocos2d;
#include "NetMessage/NetMsg.h"
#include "NetMessage/NetMsgProcess.h"
using namespace poem;
#include "NetMessage/NetMsgProcess.h"
using namespace poem;
#include "Common/EventTrigger.h"
#include "Common/XLTimer.h"
#include "UI/LuaCallFunc.h"
using namespace cocos2d;
#include "Common/TimeLine.h"
#include "cocos2Dext/CCLabelTexFont.h"
using namespace cocos2d;
#include "MoveObject/TLMoveObject.h"
using namespace cocos2d;
#include "platform/PlatformUtils.h"
#include "MC/AssetsManager.h"
#include "cocos2Dext/CCTexFontConfig.h"
#include "Drama/XLDrama.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
#include "NetMessage/HttpDownloader.h"
#include "platform/sdk.h"
#include "toluaui/TLMaskLayer.h"
#include "MC/RoleMC.h"
#include <stdlib.h>

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
 tolua_usertype(tolua_S,"CCLayer");
 tolua_usertype(tolua_S,"CCTexFontConfig");
 tolua_usertype(tolua_S,"TLEventTrigger");
 tolua_usertype(tolua_S,"TLTimeLineManager");
 tolua_usertype(tolua_S,"SimpleAudioEngine");
 tolua_usertype(tolua_S,"CCLabelTexFont");
 tolua_usertype(tolua_S,"CCNode");
 tolua_usertype(tolua_S,"CCLayerColor");
 tolua_usertype(tolua_S,"CCSpriteBatchNode");
 tolua_usertype(tolua_S,"TLDropDragHelper");
 tolua_usertype(tolua_S,"ClipNode");
 tolua_usertype(tolua_S,"CCScene");
 tolua_usertype(tolua_S,"TLRunningScene");
 tolua_usertype(tolua_S,"poem::Symbol");
 tolua_usertype(tolua_S,"CCActionInterval");
 tolua_usertype(tolua_S,"ccColor3B");
 tolua_usertype(tolua_S,"LUA_FUNCTION");
 tolua_usertype(tolua_S,"CCRect");
 tolua_usertype(tolua_S,"CCActionInstant");
 tolua_usertype(tolua_S,"TLWindow");
 tolua_usertype(tolua_S,"MainSceneRoleMC");
 tolua_usertype(tolua_S,"TLMoveObject");
 tolua_usertype(tolua_S,"CHttpDownloader");
 tolua_usertype(tolua_S,"XLTimer");
 tolua_usertype(tolua_S,"cocos2d::CCObject");
 tolua_usertype(tolua_S,"CCParticleSystem");
 tolua_usertype(tolua_S,"GLubyte");
 tolua_usertype(tolua_S,"AssetsManager");
 tolua_usertype(tolua_S,"CCSize");
 tolua_usertype(tolua_S,"CNetSender");
 tolua_usertype(tolua_S,"ccColor4B");
 tolua_usertype(tolua_S,"XLDrama");
 tolua_usertype(tolua_S,"::google::protobuf::MessageLite");
 tolua_usertype(tolua_S,"CCArray");
 tolua_usertype(tolua_S,"TLMaskLayer");
 tolua_usertype(tolua_S,"MovieClip");
 tolua_usertype(tolua_S,"LuaMoveToEx");
 tolua_usertype(tolua_S,"CCLabelTTF");
 tolua_usertype(tolua_S,"CCObject");
 tolua_usertype(tolua_S,"CCTexture2D");
 tolua_usertype(tolua_S,"CCImage");
 tolua_usertype(tolua_S,"CNetReceiver");
 tolua_usertype(tolua_S,"MCLoader");
 tolua_usertype(tolua_S,"CNetMsg");
 tolua_usertype(tolua_S,"CCLabelBMFont");
 tolua_usertype(tolua_S,"CCSprite");
 tolua_usertype(tolua_S,"MCFrame");
 tolua_usertype(tolua_S,"CCSpriteFrame");
 tolua_usertype(tolua_S,"LuaCallFunc");
 tolua_usertype(tolua_S,"TLWindowManager");
}

/* method: node of class  TLRunningScene */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLRunningScene_node00
static int tolua_luaapi_TLRunningScene_node00(lua_State* tolua_S)
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
   CCScene* tolua_ret = (CCScene*)  TLRunningScene::node();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCScene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'node'.",&tolua_err);
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

/* method: createWithName of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_luaapi_MovieClip_createWithName00
static int tolua_luaapi_MovieClip_createWithName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MovieClip",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* mcName = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool bAsync = ((bool)  tolua_toboolean(tolua_S,3,false));
  bool bPlay = ((bool)  tolua_toboolean(tolua_S,4,false));
  {
   MovieClip* tolua_ret = (MovieClip*)  MovieClip::createWithName(mcName,bAsync,bPlay);
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    tolua_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"MovieClip");
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MovieClip_play00
static int tolua_luaapi_MovieClip_play00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MovieClip_start00
static int tolua_luaapi_MovieClip_start00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MovieClip_pause00
static int tolua_luaapi_MovieClip_pause00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MovieClip_setAutoClear00
static int tolua_luaapi_MovieClip_setAutoClear00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MovieClip_getAutoClear00
static int tolua_luaapi_MovieClip_getAutoClear00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MovieClip_setFrameRate00
static int tolua_luaapi_MovieClip_setFrameRate00(lua_State* tolua_S)
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

/* method: getSymbolInfo of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_luaapi_MovieClip_getSymbolInfo00
static int tolua_luaapi_MovieClip_getSymbolInfo00(lua_State* tolua_S)
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
   const poem::Symbol* tolua_ret = (const poem::Symbol*)  self->getSymbolInfo();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const poem::Symbol");
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

/* method: RegisterPlayEndCallbackLua of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_luaapi_MovieClip_RegisterPlayEndCallbackLua00
static int tolua_luaapi_MovieClip_RegisterPlayEndCallbackLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isfunction(tolua_S,2,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
  int nLuaHandle = (tolua_ref_function(tolua_S,2,0));
  int nUserData = ((int)  tolua_tonumber(tolua_S,3,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterPlayEndCallbackLua'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->RegisterPlayEndCallbackLua(nLuaHandle,nUserData);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterPlayEndCallbackLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_luaapi_MovieClip_setColor00
static int tolua_luaapi_MovieClip_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MovieClip",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MovieClip* self = (MovieClip*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getResetKeyframe of class  MovieClip */
#ifndef TOLUA_DISABLE_tolua_luaapi_MovieClip_getResetKeyframe00
static int tolua_luaapi_MovieClip_getResetKeyframe00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MovieClip_setResetKeyframe00
static int tolua_luaapi_MovieClip_setResetKeyframe00(lua_State* tolua_S)
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

/* method: sharedMCLoader of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_luaapi_MCLoader_sharedMCLoader00
static int tolua_luaapi_MCLoader_sharedMCLoader00(lua_State* tolua_S)
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
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MCLoader");
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MCLoader_loadIndexFile00
static int tolua_luaapi_MCLoader_loadIndexFile00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MCLoader_getSymbol00
static int tolua_luaapi_MCLoader_getSymbol00(lua_State* tolua_S)
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
   const poem::Symbol* tolua_ret = (const poem::Symbol*)  self->getSymbol(animName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const poem::Symbol");
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MCLoader_loadSpriteFrame00
static int tolua_luaapi_MCLoader_loadSpriteFrame00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MCLoader_loadSprite00
static int tolua_luaapi_MCLoader_loadSprite00(lua_State* tolua_S)
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

/* method: loadSpriteGray of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_luaapi_MCLoader_loadSpriteGray00
static int tolua_luaapi_MCLoader_loadSpriteGray00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadSpriteGray'", NULL);
#endif
  {
   CCSprite* tolua_ret = (CCSprite*)  self->loadSpriteGray(frameName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadSpriteGray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadSpriteAsync of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_luaapi_MCLoader_loadSpriteAsync00
static int tolua_luaapi_MCLoader_loadSpriteAsync00(lua_State* tolua_S)
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

/* method: addImageAsync of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_luaapi_MCLoader_addImageAsync00
static int tolua_luaapi_MCLoader_addImageAsync00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MCLoader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isfunction(tolua_S,3,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MCLoader* self = (MCLoader*)  tolua_tousertype(tolua_S,1,0);
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  int scriptCallback = (tolua_ref_function(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addImageAsync'", NULL);
#endif
  {
   self->addImageAsync(path,scriptCallback);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addImageAsync'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadAssetsTexture of class  MCLoader */
#ifndef TOLUA_DISABLE_tolua_luaapi_MCLoader_loadAssetsTexture00
static int tolua_luaapi_MCLoader_loadAssetsTexture00(lua_State* tolua_S)
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
  string filepath = ((string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadAssetsTexture'", NULL);
#endif
  {
   CCTexture2D* tolua_ret = (CCTexture2D*)  self->loadAssetsTexture(filepath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCTexture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadAssetsTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getAssetsTexturePath */
#ifndef TOLUA_DISABLE_tolua_luaapi_getAssetsTexturePath00
static int tolua_luaapi_getAssetsTexturePath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_iscppstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  string filepath = ((string)  tolua_tocppstring(tolua_S,1,0));
  {
   string tolua_ret = (string)  getAssetsTexturePath(filepath);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAssetsTexturePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: getBoundingBox */
#ifndef TOLUA_DISABLE_tolua_luaapi_getBoundingBox00
static int tolua_luaapi_getBoundingBox00(lua_State* tolua_S)
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
   CCRect tolua_ret = (CCRect)  getBoundingBox(node);
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
#ifndef TOLUA_DISABLE_tolua_luaapi_toMovieClip00
static int tolua_luaapi_toMovieClip00(lua_State* tolua_S)
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
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    tolua_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"MovieClip");
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

/* function: toSprite */
#ifndef TOLUA_DISABLE_tolua_luaapi_toSprite00
static int tolua_luaapi_toSprite00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_toTTFText00
static int tolua_luaapi_toTTFText00(lua_State* tolua_S)
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

/* function: toTTFRichText */
#ifndef TOLUA_DISABLE_tolua_luaapi_toTTFRichText00
static int tolua_luaapi_toTTFRichText00(lua_State* tolua_S)
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
   CCLabelTexFont* tolua_ret = (CCLabelTexFont*)  toTTFRichText(node);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCLabelTexFont");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toTTFRichText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: toBMText */
#ifndef TOLUA_DISABLE_tolua_luaapi_toBMText00
static int tolua_luaapi_toBMText00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_toRect00
static int tolua_luaapi_toRect00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_toFrame00
static int tolua_luaapi_toFrame00(lua_State* tolua_S)
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
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    tolua_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"MCFrame");
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
#ifndef TOLUA_DISABLE_tolua_luaapi_toParticle00
static int tolua_luaapi_toParticle00(lua_State* tolua_S)
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

/* method: clipNode of class  ClipNode */
#ifndef TOLUA_DISABLE_tolua_luaapi_ClipNode_clipNode00
static int tolua_luaapi_ClipNode_clipNode00(lua_State* tolua_S)
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
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ClipNode");
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
#ifndef TOLUA_DISABLE_tolua_luaapi_ClipNode_clipNode01
static int tolua_luaapi_ClipNode_clipNode01(lua_State* tolua_S)
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
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ClipNode");
  }
 }
 return 1;
tolua_lerror:
 return tolua_luaapi_ClipNode_clipNode00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getClipRegion of class  ClipNode */
#ifndef TOLUA_DISABLE_tolua_luaapi_ClipNode_getClipRegion00
static int tolua_luaapi_ClipNode_getClipRegion00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_ClipNode_setClipRegion00
static int tolua_luaapi_ClipNode_setClipRegion00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_ClipNode_removeClipRegion00
static int tolua_luaapi_ClipNode_removeClipRegion00(lua_State* tolua_S)
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

/* method: createWithBox of class  MCFrame */
#ifndef TOLUA_DISABLE_tolua_luaapi_MCFrame_createWithBox00
static int tolua_luaapi_MCFrame_createWithBox00(lua_State* tolua_S)
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
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    tolua_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"MCFrame");
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MCFrame_initWithBox00
static int tolua_luaapi_MCFrame_initWithBox00(lua_State* tolua_S)
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

/* method: createWindow of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_createWindow00
static int tolua_luaapi_TLWindow_createWindow00(lua_State* tolua_S)
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
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    tolua_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindow");
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

/* method: createEditLabel of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_createEditLabel00
static int tolua_luaapi_TLWindow_createEditLabel00(lua_State* tolua_S)
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
  unsigned int uiWindowFlag = ((unsigned int)  tolua_tonumber(tolua_S,3,TL_WINDOW_INPUT));
  {
   TLWindow* tolua_ret = (TLWindow*)  TLWindow::createEditLabel(pMCNode,uiWindowFlag);
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    tolua_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindow");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createEditLabel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createEditLabel of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_createEditLabel01
static int tolua_luaapi_TLWindow_createEditLabel01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCNode* pMCNode = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
  unsigned int uiWindowFlag = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  const std::string strFontName = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  float fFontSize = ((float)  tolua_tonumber(tolua_S,5,0.0f));
  {
   TLWindow* tolua_ret = (TLWindow*)  TLWindow::createEditLabel(pMCNode,uiWindowFlag,strFontName,fFontSize);
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    tolua_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindow");
   tolua_pushcppstring(tolua_S,(const char*)strFontName);
  }
 }
 return 2;
tolua_lerror:
 return tolua_luaapi_TLWindow_createEditLabel00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddChildWindow of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_AddChildWindow00
static int tolua_luaapi_TLWindow_AddChildWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLWindow",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  TLWindow* pChildWindow = ((TLWindow*)  tolua_tousertype(tolua_S,2,0));
  bool bAdjustLayout = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddChildWindow'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddChildWindow(pChildWindow,bAdjustLayout);
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_RemoveAllChildWindow00
static int tolua_luaapi_TLWindow_RemoveAllChildWindow00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_RemoveChildWindow00
static int tolua_luaapi_TLWindow_RemoveChildWindow00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_GetChildWindow00
static int tolua_luaapi_TLWindow_GetChildWindow00(lua_State* tolua_S)
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

/* method: AdjustLayout of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_AdjustLayout00
static int tolua_luaapi_TLWindow_AdjustLayout00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AdjustLayout'", NULL);
#endif
  {
   self->AdjustLayout();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AdjustLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindWindow of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_FindWindow00
static int tolua_luaapi_TLWindow_FindWindow00(lua_State* tolua_S)
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
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    tolua_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindow");
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_FindWindow01
static int tolua_luaapi_TLWindow_FindWindow01(lua_State* tolua_S)
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
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    tolua_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindow");
  }
 }
 return 1;
tolua_lerror:
 return tolua_luaapi_TLWindow_FindWindow00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterEvent of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_RegisterEvent00
static int tolua_luaapi_TLWindow_RegisterEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isfunction(tolua_S,3,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  TL_WINDOW_EVENT eEventType = ((TL_WINDOW_EVENT) (int)  tolua_tonumber(tolua_S,2,0));
  int nLuaFuncHandle = (tolua_ref_function(tolua_S,3,0));
  unsigned long ulUserData1 = ((unsigned long)  tolua_tonumber(tolua_S,4,0xFFFFFFFF));
  unsigned long ulUserData2 = ((unsigned long)  tolua_tonumber(tolua_S,5,0xFFFFFFFF));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterEvent'", NULL);
#endif
  {
   self->RegisterEvent(eEventType,nLuaFuncHandle,ulUserData1,ulUserData2);
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

/* method: GetNode of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_GetNode00
static int tolua_luaapi_TLWindow_GetNode00(lua_State* tolua_S)
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

/* method: GetRootNode of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_GetRootNode00
static int tolua_luaapi_TLWindow_GetRootNode00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRootNode'", NULL);
#endif
  {
   CCNode* tolua_ret = (CCNode*)  self->GetRootNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRootNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAttachNode of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_GetAttachNode00
static int tolua_luaapi_TLWindow_GetAttachNode00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttachNode'", NULL);
#endif
  {
   CCNode* tolua_ret = (CCNode*)  self->GetAttachNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttachNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetInputTextModel of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_SetInputTextModel00
static int tolua_luaapi_TLWindow_SetInputTextModel00(lua_State* tolua_S)
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
  TL_INPUT_TEXT_MODEL kInputTextModel = ((TL_INPUT_TEXT_MODEL) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInputTextModel'", NULL);
#endif
  {
   self->SetInputTextModel(kInputTextModel);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInputTextModel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetInputLimit of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_SetInputLimit00
static int tolua_luaapi_TLWindow_SetInputLimit00(lua_State* tolua_S)
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
  int nInputLimit = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInputLimit'", NULL);
#endif
  {
   self->SetInputLimit(nInputLimit);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInputLimit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInputText of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_GetInputText00
static int tolua_luaapi_TLWindow_GetInputText00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInputText'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->GetInputText();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInputText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetInputText of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_SetInputText00
static int tolua_luaapi_TLWindow_SetInputText00(lua_State* tolua_S)
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
  const std::string strText = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInputText'", NULL);
#endif
  {
   self->SetInputText(strText);
   tolua_pushcppstring(tolua_S,(const char*)strText);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInputText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AppendInputText of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_AppendInputText00
static int tolua_luaapi_TLWindow_AppendInputText00(lua_State* tolua_S)
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
  const std::string strText = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AppendInputText'", NULL);
#endif
  {
   self->AppendInputText(strText);
   tolua_pushcppstring(tolua_S,(const char*)strText);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AppendInputText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StartAction of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_StartAction00
static int tolua_luaapi_TLWindow_StartAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindow* self = (TLWindow*)  tolua_tousertype(tolua_S,1,0);
  TL_ACTION_TYPE kActionType = ((TL_ACTION_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
  float fTime = ((float)  tolua_tonumber(tolua_S,3,0));
  float fParam = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StartAction'", NULL);
#endif
  {
   self->StartAction(kActionType,fTime,fParam);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StartAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWindowName of class  TLWindow */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_GetWindowName00
static int tolua_luaapi_TLWindow_GetWindowName00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_SetWindowName00
static int tolua_luaapi_TLWindow_SetWindowName00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_GetIsEnable00
static int tolua_luaapi_TLWindow_GetIsEnable00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_SetIsEnable00
static int tolua_luaapi_TLWindow_SetIsEnable00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_GetIsScroll00
static int tolua_luaapi_TLWindow_GetIsScroll00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_GetIsInput00
static int tolua_luaapi_TLWindow_GetIsInput00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_GetIsVisible00
static int tolua_luaapi_TLWindow_GetIsVisible00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_SetIsVisible00
static int tolua_luaapi_TLWindow_SetIsVisible00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_GetWindowRect00
static int tolua_luaapi_TLWindow_GetWindowRect00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_SetWindowPos00
static int tolua_luaapi_TLWindow_SetWindowPos00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindow_GetWindowPos00
static int tolua_luaapi_TLWindow_GetWindowPos00(lua_State* tolua_S)
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

/* method: SharedTLWindowManager of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_SharedTLWindowManager00
static int tolua_luaapi_TLWindowManager_SharedTLWindowManager00(lua_State* tolua_S)
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
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    tolua_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindowManager");
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_GetCenterPoint00
static int tolua_luaapi_TLWindowManager_GetCenterPoint00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_ReleaseAllWindow00
static int tolua_luaapi_TLWindowManager_ReleaseAllWindow00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_AddModuleWindow00
static int tolua_luaapi_TLWindowManager_AddModuleWindow00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_HideAllModuleWindow00
static int tolua_luaapi_TLWindowManager_HideAllModuleWindow00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_DestroyAllModuleWindow00
static int tolua_luaapi_TLWindowManager_DestroyAllModuleWindow00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_RemoveModuleWindow00
static int tolua_luaapi_TLWindowManager_RemoveModuleWindow00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_FindModuleWindow00
static int tolua_luaapi_TLWindowManager_FindModuleWindow00(lua_State* tolua_S)
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
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    tolua_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindow");
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_FindModuleWindow01
static int tolua_luaapi_TLWindowManager_FindModuleWindow01(lua_State* tolua_S)
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
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    tolua_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"TLWindow");
  }
 }
 return 1;
tolua_lerror:
 return tolua_luaapi_TLWindowManager_FindModuleWindow00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLastPointX of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_getLastPointX00
static int tolua_luaapi_TLWindowManager_getLastPointX00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_getLastPointY00
static int tolua_luaapi_TLWindowManager_getLastPointY00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_getLastPoint00
static int tolua_luaapi_TLWindowManager_getLastPoint00(lua_State* tolua_S)
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

/* method: MoveToTop of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_MoveToTop00
static int tolua_luaapi_TLWindowManager_MoveToTop00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_MoveToBottom00
static int tolua_luaapi_TLWindowManager_MoveToBottom00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_StopEventBubble00
static int tolua_luaapi_TLWindowManager_StopEventBubble00(lua_State* tolua_S)
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

/* method: SetIsPressScene of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_SetIsPressScene00
static int tolua_luaapi_TLWindowManager_SetIsPressScene00(lua_State* tolua_S)
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
  bool bIsPressScene = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIsPressScene'", NULL);
#endif
  {
   self->SetIsPressScene(bIsPressScene);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIsPressScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ShowUI of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_ShowUI00
static int tolua_luaapi_TLWindowManager_ShowUI00(lua_State* tolua_S)
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

/* method: SetModalWindow of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_SetModalWindow00
static int tolua_luaapi_TLWindowManager_SetModalWindow00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_SetSystemWindow00
static int tolua_luaapi_TLWindowManager_SetSystemWindow00(lua_State* tolua_S)
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

/* method: SetIsLockScreen of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_SetIsLockScreen00
static int tolua_luaapi_TLWindowManager_SetIsLockScreen00(lua_State* tolua_S)
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
  bool bLockScreen = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIsLockScreen'", NULL);
#endif
  {
   self->SetIsLockScreen(bLockScreen);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIsLockScreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIsLockScreen of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_GetIsLockScreen00
static int tolua_luaapi_TLWindowManager_GetIsLockScreen00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIsLockScreen'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetIsLockScreen();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIsLockScreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TweenTo of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_TweenTo00
static int tolua_luaapi_TLWindowManager_TweenTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isfunction(tolua_S,8,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  int easeId = ((int)  tolua_tonumber(tolua_S,2,0));
  CCNode* widget = ((CCNode*)  tolua_tousertype(tolua_S,3,0));
  int pro = ((int)  tolua_tonumber(tolua_S,4,0));
  float delay = ((float)  tolua_tonumber(tolua_S,5,0));
  float duration = ((float)  tolua_tonumber(tolua_S,6,0));
  float to = ((float)  tolua_tonumber(tolua_S,7,0));
  int onStop = (tolua_ref_function(tolua_S,8,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TweenTo'", NULL);
#endif
  {
   int tolua_ret = (int)  self->TweenTo(easeId,widget,pro,delay,duration,to,onStop);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TweenTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TweenFrom of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_TweenFrom00
static int tolua_luaapi_TLWindowManager_TweenFrom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isfunction(tolua_S,8,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  int easeId = ((int)  tolua_tonumber(tolua_S,2,0));
  CCNode* widget = ((CCNode*)  tolua_tousertype(tolua_S,3,0));
  int pro = ((int)  tolua_tonumber(tolua_S,4,0));
  float delay = ((float)  tolua_tonumber(tolua_S,5,0));
  float duration = ((float)  tolua_tonumber(tolua_S,6,0));
  float from = ((float)  tolua_tonumber(tolua_S,7,0));
  int onStop = (tolua_ref_function(tolua_S,8,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TweenFrom'", NULL);
#endif
  {
   int tolua_ret = (int)  self->TweenFrom(easeId,widget,pro,delay,duration,from,onStop);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TweenFrom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TweenFromTo of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_TweenFromTo00
static int tolua_luaapi_TLWindowManager_TweenFromTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,9,&tolua_err) || !tolua_isfunction(tolua_S,9,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  int easeId = ((int)  tolua_tonumber(tolua_S,2,0));
  CCNode* widget = ((CCNode*)  tolua_tousertype(tolua_S,3,0));
  int pro = ((int)  tolua_tonumber(tolua_S,4,0));
  float delay = ((float)  tolua_tonumber(tolua_S,5,0));
  float duration = ((float)  tolua_tonumber(tolua_S,6,0));
  float from = ((float)  tolua_tonumber(tolua_S,7,0));
  float to = ((float)  tolua_tonumber(tolua_S,8,0));
  int onStop = (tolua_ref_function(tolua_S,9,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TweenFromTo'", NULL);
#endif
  {
   int tolua_ret = (int)  self->TweenFromTo(easeId,widget,pro,delay,duration,from,to,onStop);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TweenFromTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveTween of class  TLWindowManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLWindowManager_RemoveTween00
static int tolua_luaapi_TLWindowManager_RemoveTween00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLWindowManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLWindowManager* self = (TLWindowManager*)  tolua_tousertype(tolua_S,1,0);
  int tweenId = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveTween'", NULL);
#endif
  {
   self->RemoveTween(tweenId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveTween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AppendShow of class  TLDropDragHelper */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLDropDragHelper_AppendShow00
static int tolua_luaapi_TLDropDragHelper_AppendShow00(lua_State* tolua_S)
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

/* method: Parse of class  CNetMsg */
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetMsg_Parse00
static int tolua_luaapi_CNetMsg_Parse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CNetMsg",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* szRevcBuf = ((char*)  tolua_tostring(tolua_S,2,0));
  unsigned int nLength = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
   CNetMsg* tolua_ret = (CNetMsg*)  CNetMsg::Parse(szRevcBuf,nLength);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CNetMsg");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Parse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMsgID of class  CNetMsg */
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetMsg_GetMsgID00
static int tolua_luaapi_CNetMsg_GetMsgID00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetMsg_GetMsgCode00
static int tolua_luaapi_CNetMsg_GetMsgCode00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetMsg_ParseContent00
static int tolua_luaapi_CNetMsg_ParseContent00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetMsg_GetContentLength00
static int tolua_luaapi_CNetMsg_GetContentLength00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetMsg_GetContentData00
static int tolua_luaapi_CNetMsg_GetContentData00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetMsg_GetContentStr00
static int tolua_luaapi_CNetMsg_GetContentStr00(lua_State* tolua_S)
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

/* method: ConnectSession of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetSender_ConnectSession00
static int tolua_luaapi_CNetSender_ConnectSession00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CNetSender",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* szIPAddr = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned int uiPort = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  CNetSender::ConnectSession(szIPAddr,uiPort);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ConnectSession'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SessionConnection of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetSender_SessionConnection00
static int tolua_luaapi_CNetSender_SessionConnection00(lua_State* tolua_S)
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
   CNetSender* tolua_ret = (CNetSender*)  CNetSender::SessionConnection();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CNetSender");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SessionConnection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CloseSession of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetSender_CloseSession00
static int tolua_luaapi_CNetSender_CloseSession00(lua_State* tolua_S)
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
   CNetSender::CloseSession();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CloseSession'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ConnectWorld of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetSender_ConnectWorld00
static int tolua_luaapi_CNetSender_ConnectWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CNetSender",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* szIPAddr = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned int uiPort = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  CNetSender::ConnectWorld(szIPAddr,uiPort);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ConnectWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WorldConnection of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetSender_WorldConnection00
static int tolua_luaapi_CNetSender_WorldConnection00(lua_State* tolua_S)
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
   CNetSender* tolua_ret = (CNetSender*)  CNetSender::WorldConnection();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CNetSender");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WorldConnection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CloseWorld of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetSender_CloseWorld00
static int tolua_luaapi_CNetSender_CloseWorld00(lua_State* tolua_S)
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
   CNetSender::CloseWorld();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CloseWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NewNetMsgAndSend of class  CNetSender */
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetSender_NewNetMsgAndSend00
static int tolua_luaapi_CNetSender_NewNetMsgAndSend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetSender",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetSender* self = (CNetSender*)  tolua_tousertype(tolua_S,1,0);
  unsigned int msgID = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  const char* buffer = ((const char*)  tolua_tostring(tolua_S,3,NULL));
  int size = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NewNetMsgAndSend'", NULL);
#endif
  {
   self->NewNetMsgAndSend(msgID,buffer,size);
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

/* method: SharedNetReceiver of class  CNetReceiver */
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetReceiver_SharedNetReceiver00
static int tolua_luaapi_CNetReceiver_SharedNetReceiver00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetReceiver_SetMsgErrorDefaultFuncPtr00
static int tolua_luaapi_CNetReceiver_SetMsgErrorDefaultFuncPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetReceiver",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isfunction(tolua_S,2,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetReceiver* self = (CNetReceiver*)  tolua_tousertype(tolua_S,1,0);
  int nLuaHandle = (tolua_ref_function(tolua_S,2,0));
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
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetReceiver_RegisterMsgErrorFuncPtr00
static int tolua_luaapi_CNetReceiver_RegisterMsgErrorFuncPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetReceiver",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isfunction(tolua_S,3,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetReceiver* self = (CNetReceiver*)  tolua_tousertype(tolua_S,1,0);
  int nMsgCode = ((int)  tolua_tonumber(tolua_S,2,0));
  int nLuaHandle = (tolua_ref_function(tolua_S,3,0));
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
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetReceiver_RegisterMsgProcessFuncPtr00
static int tolua_luaapi_CNetReceiver_RegisterMsgProcessFuncPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CNetReceiver",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isfunction(tolua_S,3,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CNetReceiver* self = (CNetReceiver*)  tolua_tousertype(tolua_S,1,0);
  unsigned int nMsgID = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  int nLuaHandle = (tolua_ref_function(tolua_S,3,0));
  bool share = ((bool)  tolua_toboolean(tolua_S,4,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterMsgProcessFuncPtr'", NULL);
#endif
  {
   self->RegisterMsgProcessFuncPtr(nMsgID,nLuaHandle,share);
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

/* method: SetErrorMsgToSelf of class  CNetReceiver */
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetReceiver_SetErrorMsgToSelf00
static int tolua_luaapi_CNetReceiver_SetErrorMsgToSelf00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetErrorMsgToSelf'", NULL);
#endif
  {
   self->SetErrorMsgToSelf(uiMsgCode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetErrorMsgToSelf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendMsgToSelf of class  CNetReceiver */
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetReceiver_SendMsgToSelf00
static int tolua_luaapi_CNetReceiver_SendMsgToSelf00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_CNetReceiver_Reset00
static int tolua_luaapi_CNetReceiver_Reset00(lua_State* tolua_S)
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

/* method: SharedTLEventTrigger of class  TLEventTrigger */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLEventTrigger_SharedTLEventTrigger00
static int tolua_luaapi_TLEventTrigger_SharedTLEventTrigger00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLEventTrigger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLEventTrigger* tolua_ret = (TLEventTrigger*)  TLEventTrigger::SharedTLEventTrigger();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLEventTrigger");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SharedTLEventTrigger'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PurgeLuaHandlers of class  TLEventTrigger */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLEventTrigger_PurgeLuaHandlers00
static int tolua_luaapi_TLEventTrigger_PurgeLuaHandlers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLEventTrigger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLEventTrigger* self = (TLEventTrigger*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PurgeLuaHandlers'", NULL);
#endif
  {
   self->PurgeLuaHandlers();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PurgeLuaHandlers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterEventCallback of class  TLEventTrigger */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLEventTrigger_RegisterEventCallback00
static int tolua_luaapi_TLEventTrigger_RegisterEventCallback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLEventTrigger",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isfunction(tolua_S,4,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLEventTrigger* self = (TLEventTrigger*)  tolua_tousertype(tolua_S,1,0);
  int nRegisterID = ((int)  tolua_tonumber(tolua_S,2,0));
  EVENT_TYPE kEventType = ((EVENT_TYPE) (int)  tolua_tonumber(tolua_S,3,0));
  int nLuaHandle = (tolua_ref_function(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterEventCallback'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->RegisterEventCallback(nRegisterID,kEventType,nLuaHandle);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterEventCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnregisterEventCallback of class  TLEventTrigger */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLEventTrigger_UnregisterEventCallback00
static int tolua_luaapi_TLEventTrigger_UnregisterEventCallback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLEventTrigger",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLEventTrigger* self = (TLEventTrigger*)  tolua_tousertype(tolua_S,1,0);
  int nRegisterID = ((int)  tolua_tonumber(tolua_S,2,0));
  EVENT_TYPE kEventType = ((EVENT_TYPE) (int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UnregisterEventCallback'", NULL);
#endif
  {
   self->UnregisterEventCallback(nRegisterID,kEventType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnregisterEventCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEvent of class  TLEventTrigger */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLEventTrigger_SetEvent00
static int tolua_luaapi_TLEventTrigger_SetEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLEventTrigger",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLEventTrigger* self = (TLEventTrigger*)  tolua_tousertype(tolua_S,1,0);
  EVENT_TYPE kEventType = ((EVENT_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
  unsigned int uiParam1 = ((unsigned int)  tolua_tonumber(tolua_S,3,0xFFFFFFFF));
  unsigned int uiParam2 = ((unsigned int)  tolua_tonumber(tolua_S,4,0xFFFFFFFF));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEvent'", NULL);
#endif
  {
   self->SetEvent(kEventType,uiParam1,uiParam2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRegisterID of class  TLEventTrigger */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLEventTrigger_GetRegisterID00
static int tolua_luaapi_TLEventTrigger_GetRegisterID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLEventTrigger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLEventTrigger* self = (TLEventTrigger*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRegisterID'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetRegisterID();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRegisterID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SharedXLTimer of class  XLTimer */
#ifndef TOLUA_DISABLE_tolua_luaapi_XLTimer_SharedXLTimer00
static int tolua_luaapi_XLTimer_SharedXLTimer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XLTimer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XLTimer* tolua_ret = (XLTimer*)  XLTimer::SharedXLTimer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XLTimer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SharedXLTimer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldTime of class  XLTimer */
#ifndef TOLUA_DISABLE_tolua_luaapi_XLTimer_GetWorldTime00
static int tolua_luaapi_XLTimer_GetWorldTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XLTimer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XLTimer* self = (XLTimer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldTime'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetWorldTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWorldTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LuaCallFunc */
#ifndef TOLUA_DISABLE_tolua_luaapi_LuaCallFunc_create00
static int tolua_luaapi_LuaCallFunc_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaCallFunc",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isfunction(tolua_S,2,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int nHandler = (tolua_ref_function(tolua_S,2,0));
  {
   LuaCallFunc* tolua_ret = (LuaCallFunc*)  LuaCallFunc::create(nHandler);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaCallFunc");
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

/* method: resetWithDuration of class  LuaMoveToEx */
#ifndef TOLUA_DISABLE_tolua_luaapi_LuaMoveToEx_resetWithDuration00
static int tolua_luaapi_LuaMoveToEx_resetWithDuration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaMoveToEx",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isfunction(tolua_S,4,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isfunction(tolua_S,5,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaMoveToEx* self = (LuaMoveToEx*)  tolua_tousertype(tolua_S,1,0);
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  const CCPoint* position = ((const CCPoint*)  tolua_tousertype(tolua_S,3,0));
  int nMoveEndLuaHandle = (tolua_ref_function(tolua_S,4,0));
  int nUpdateLuaHandle = (tolua_ref_function(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetWithDuration'", NULL);
#endif
  {
   self->resetWithDuration(duration,*position,nMoveEndLuaHandle,nUpdateLuaHandle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetWithDuration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: actionWithDuration of class  LuaMoveToEx */
#ifndef TOLUA_DISABLE_tolua_luaapi_LuaMoveToEx_actionWithDuration00
static int tolua_luaapi_LuaMoveToEx_actionWithDuration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaMoveToEx",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isfunction(tolua_S,4,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isfunction(tolua_S,5,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  const CCPoint* position = ((const CCPoint*)  tolua_tousertype(tolua_S,3,0));
  int nMoveEndLuaHandle = (tolua_ref_function(tolua_S,4,0));
  int nUpdateLuaHandle = (tolua_ref_function(tolua_S,5,0));
  {
   LuaMoveToEx* tolua_ret = (LuaMoveToEx*)  LuaMoveToEx::actionWithDuration(duration,*position,nMoveEndLuaHandle,nUpdateLuaHandle);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaMoveToEx");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'actionWithDuration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SharedTLTimeLineManager of class  TLTimeLineManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLTimeLineManager_SharedTLTimeLineManager00
static int tolua_luaapi_TLTimeLineManager_SharedTLTimeLineManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLTimeLineManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLTimeLineManager* tolua_ret = (TLTimeLineManager*)  TLTimeLineManager::SharedTLTimeLineManager();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLTimeLineManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SharedTLTimeLineManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTimeLineEndFunc of class  TLTimeLineManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLTimeLineManager_SetTimeLineEndFunc00
static int tolua_luaapi_TLTimeLineManager_SetTimeLineEndFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLTimeLineManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isfunction(tolua_S,3,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLTimeLineManager* self = (TLTimeLineManager*)  tolua_tousertype(tolua_S,1,0);
  int nTimeLineID = ((int)  tolua_tonumber(tolua_S,2,0));
  int nLuaHandle = (tolua_ref_function(tolua_S,3,0));
  float fTime = ((float)  tolua_tonumber(tolua_S,4,0.0f));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTimeLineEndFunc'", NULL);
#endif
  {
   self->SetTimeLineEndFunc(nTimeLineID,nLuaHandle,fTime);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTimeLineEndFunc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTimeEvent of class  TLTimeLineManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLTimeLineManager_AddTimeEvent00
static int tolua_luaapi_TLTimeLineManager_AddTimeEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLTimeLineManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isfunction(tolua_S,4,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLTimeLineManager* self = (TLTimeLineManager*)  tolua_tousertype(tolua_S,1,0);
  int nTimeLineID = ((int)  tolua_tonumber(tolua_S,2,0));
  float fTime = ((float)  tolua_tonumber(tolua_S,3,0));
  int nLuaHandle = (tolua_ref_function(tolua_S,4,0));
  int nUserData1 = ((int)  tolua_tonumber(tolua_S,5,-1));
  int nUserData2 = ((int)  tolua_tonumber(tolua_S,6,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTimeEvent'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddTimeEvent(nTimeLineID,fTime,nLuaHandle,nUserData1,nUserData2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddTimeEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateTimeLine of class  TLTimeLineManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLTimeLineManager_CreateTimeLine00
static int tolua_luaapi_TLTimeLineManager_CreateTimeLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLTimeLineManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLTimeLineManager* self = (TLTimeLineManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateTimeLine'", NULL);
#endif
  {
   int tolua_ret = (int)  self->CreateTimeLine();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateTimeLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CloseTimeLine of class  TLTimeLineManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLTimeLineManager_CloseTimeLine00
static int tolua_luaapi_TLTimeLineManager_CloseTimeLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLTimeLineManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLTimeLineManager* self = (TLTimeLineManager*)  tolua_tousertype(tolua_S,1,0);
  int nTimeLineID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CloseTimeLine'", NULL);
#endif
  {
   self->CloseTimeLine(nTimeLineID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CloseTimeLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StartUpTimeLine of class  TLTimeLineManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLTimeLineManager_StartUpTimeLine00
static int tolua_luaapi_TLTimeLineManager_StartUpTimeLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLTimeLineManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLTimeLineManager* self = (TLTimeLineManager*)  tolua_tousertype(tolua_S,1,0);
  int nTimeLineID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StartUpTimeLine'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->StartUpTimeLine(nTimeLineID);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StartUpTimeLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PauseTimeLine of class  TLTimeLineManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLTimeLineManager_PauseTimeLine00
static int tolua_luaapi_TLTimeLineManager_PauseTimeLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLTimeLineManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLTimeLineManager* self = (TLTimeLineManager*)  tolua_tousertype(tolua_S,1,0);
  int nTimeLineID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PauseTimeLine'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->PauseTimeLine(nTimeLineID);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PauseTimeLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ContinueTimeLine of class  TLTimeLineManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLTimeLineManager_ContinueTimeLine00
static int tolua_luaapi_TLTimeLineManager_ContinueTimeLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLTimeLineManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLTimeLineManager* self = (TLTimeLineManager*)  tolua_tousertype(tolua_S,1,0);
  int nTimeLineID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ContinueTimeLine'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->ContinueTimeLine(nTimeLineID);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ContinueTimeLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StopTimeLine of class  TLTimeLineManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLTimeLineManager_StopTimeLine00
static int tolua_luaapi_TLTimeLineManager_StopTimeLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLTimeLineManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLTimeLineManager* self = (TLTimeLineManager*)  tolua_tousertype(tolua_S,1,0);
  int nTimeLineID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StopTimeLine'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->StopTimeLine(nTimeLineID);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StopTimeLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: labelWithString of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_labelWithString00
static int tolua_luaapi_CCLabelTexFont_labelWithString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
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
   CCLabelTexFont* tolua_ret = (CCLabelTexFont*)  CCLabelTexFont::labelWithString(str,fFontSize);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCLabelTexFont");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'labelWithString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: labelWithString of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_labelWithString01
static int tolua_luaapi_CCLabelTexFont_labelWithString01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCSize",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fFontSize = ((float)  tolua_tonumber(tolua_S,3,0));
  const CCSize* dimensions = ((const CCSize*)  tolua_tousertype(tolua_S,4,0));
  CCImage::ETextAlign alignment = ((CCImage::ETextAlign) (int)  tolua_tonumber(tolua_S,5,CCImage::kAlignLeft));
  {
   CCLabelTexFont* tolua_ret = (CCLabelTexFont*)  CCLabelTexFont::labelWithString(str,fFontSize,*dimensions,alignment);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCLabelTexFont");
  }
 }
 return 1;
tolua_lerror:
 return tolua_luaapi_CCLabelTexFont_labelWithString00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithString of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_initWithString00
static int tolua_luaapi_CCLabelTexFont_initWithString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fFontSize = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithString'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithString(str,fFontSize);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithString of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_initWithString01
static int tolua_luaapi_CCLabelTexFont_initWithString01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCSize",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  float fFontSize = ((float)  tolua_tonumber(tolua_S,3,0));
  const CCSize* dimensions = ((const CCSize*)  tolua_tousertype(tolua_S,4,0));
  CCImage::ETextAlign alignment = ((CCImage::ETextAlign) (int)  tolua_tonumber(tolua_S,5,CCImage::kAlignLeft));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithString'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithString(str,fFontSize,*dimensions,alignment);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_luaapi_CCLabelTexFont_initWithString00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setString of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_setString00
static int tolua_luaapi_CCLabelTexFont_setString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setString'", NULL);
#endif
  {
   self->setString(text);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getString of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_getString00
static int tolua_luaapi_CCLabelTexFont_getString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getString'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getString();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setContentSize of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_setContentSize00
static int tolua_luaapi_CCLabelTexFont_setContentSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setContentSize'", NULL);
#endif
  {
   self->setContentSize(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setContentSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_setColor00
static int tolua_luaapi_CCLabelTexFont_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setColor of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_setColor01
static int tolua_luaapi_CCLabelTexFont_setColor01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
  unsigned const int color = ((unsigned const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(color);
   tolua_pushnumber(tolua_S,(lua_Number)color);
  }
 }
 return 1;
tolua_lerror:
 return tolua_luaapi_CCLabelTexFont_setColor00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColor of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_getColor00
static int tolua_luaapi_CCLabelTexFont_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getOpacity of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_getOpacity00
static int tolua_luaapi_CCLabelTexFont_getOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setOpacity of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_setOpacity00
static int tolua_luaapi_CCLabelTexFont_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GLubyte",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
  GLubyte opacity = *((GLubyte*)  tolua_tousertype(tolua_S,2,0));
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

/* method: setIsOpacityModifyRGB of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_setIsOpacityModifyRGB00
static int tolua_luaapi_CCLabelTexFont_setIsOpacityModifyRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
  bool bValue = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIsOpacityModifyRGB'", NULL);
#endif
  {
   self->setIsOpacityModifyRGB(bValue);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIsOpacityModifyRGB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIsOpacityModifyRGB of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_getIsOpacityModifyRGB00
static int tolua_luaapi_CCLabelTexFont_getIsOpacityModifyRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIsOpacityModifyRGB'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getIsOpacityModifyRGB();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIsOpacityModifyRGB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRealFontSize of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_getRealFontSize00
static int tolua_luaapi_CCLabelTexFont_getRealFontSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRealFontSize'", NULL);
#endif
  {
   const CCSize& tolua_ret = (const CCSize&)  self->getRealFontSize();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const CCSize");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRealFontSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getChildByTag of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_getChildByTag00
static int tolua_luaapi_CCLabelTexFont_getChildByTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
  int nTag = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getChildByTag'", NULL);
#endif
  {
   CCSprite* tolua_ret = (CCSprite*)  self->getChildByTag(nTag);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getChildByTag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFontCount of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_getFontCount00
static int tolua_luaapi_CCLabelTexFont_getFontCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFontCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getFontCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFontCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRichString of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_setRichString00
static int tolua_luaapi_CCLabelTexFont_setRichString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool bOneLine = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRichString'", NULL);
#endif
  {
   self->setRichString(text,bOneLine);
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

/* method: getRichString of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_getRichString00
static int tolua_luaapi_CCLabelTexFont_getRichString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getRealSize of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_getRealSize00
static int tolua_luaapi_CCLabelTexFont_getRealSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRealSize'", NULL);
#endif
  {
   const CCSize& tolua_ret = (const CCSize&)  self->getRealSize();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const CCSize");
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

/* method: setAlignment of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_setAlignment00
static int tolua_luaapi_CCLabelTexFont_setAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getAlignment of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_getAlignment00
static int tolua_luaapi_CCLabelTexFont_getAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
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

/* method: appendRich of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_appendRich00
static int tolua_luaapi_CCLabelTexFont_appendRich00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendRich'", NULL);
#endif
  {
   self->appendRich(text);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendRich'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: append of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_append00
static int tolua_luaapi_CCLabelTexFont_append00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'append'", NULL);
#endif
  {
   self->append(text);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'append'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlignmentInside of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_setAlignmentInside00
static int tolua_luaapi_CCLabelTexFont_setAlignmentInside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
  CCImage::ETextAlign eAlignment = ((CCImage::ETextAlign) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlignmentInside'", NULL);
#endif
  {
   self->setAlignmentInside(eAlignment);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlignmentInside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAlignmentInside of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_getAlignmentInside00
static int tolua_luaapi_CCLabelTexFont_getAlignmentInside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAlignmentInside'", NULL);
#endif
  {
   CCImage::ETextAlign tolua_ret = (CCImage::ETextAlign)  self->getAlignmentInside();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAlignmentInside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFontSize of class  CCLabelTexFont */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCLabelTexFont_setFontSize00
static int tolua_luaapi_CCLabelTexFont_setFontSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLabelTexFont",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLabelTexFont* self = (CCLabelTexFont*)  tolua_tousertype(tolua_S,1,0);
  float size = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFontSize'", NULL);
#endif
  {
   self->setFontSize(size);
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

/* get function: ms_fNameOffsetY of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_get_TLMoveObject_ms_fNameOffsetY
static int tolua_get_TLMoveObject_ms_fNameOffsetY(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)TLMoveObject::ms_fNameOffsetY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ms_fNameOffsetY of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_set_TLMoveObject_ms_fNameOffsetY
static int tolua_set_TLMoveObject_ms_fNameOffsetY(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  TLMoveObject::ms_fNameOffsetY = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ms_fIconOffsetY of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_get_TLMoveObject_ms_fIconOffsetY
static int tolua_get_TLMoveObject_ms_fIconOffsetY(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)TLMoveObject::ms_fIconOffsetY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ms_fIconOffsetY of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_set_TLMoveObject_ms_fIconOffsetY
static int tolua_set_TLMoveObject_ms_fIconOffsetY(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  TLMoveObject::ms_fIconOffsetY = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: newTLMoveObject of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_newTLMoveObject00
static int tolua_luaapi_TLMoveObject_newTLMoveObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCLayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCSpriteBatchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayer* pLayer = ((CCLayer*)  tolua_tousertype(tolua_S,2,0));
  CCSpriteBatchNode* pkShadowBatchNode = ((CCSpriteBatchNode*)  tolua_tousertype(tolua_S,3,0));
  {
   TLMoveObject* tolua_ret = (TLMoveObject*)  TLMoveObject::newTLMoveObject(pLayer,pkShadowBatchNode);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLMoveObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'newTLMoveObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: releaseTLMoveObject of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_releaseTLMoveObject00
static int tolua_luaapi_TLMoveObject_releaseTLMoveObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* pkMoveObject = ((TLMoveObject*)  tolua_tousertype(tolua_S,2,0));
  {
   TLMoveObject::releaseTLMoveObject(pkMoveObject);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'releaseTLMoveObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MoveToByTime of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_MoveToByTime00
static int tolua_luaapi_TLMoveObject_MoveToByTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isfunction(tolua_S,4,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isfunction(tolua_S,5,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* destPos = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
  float fTime = ((float)  tolua_tonumber(tolua_S,3,0));
  int nMoveEndLuaHandle = (tolua_ref_function(tolua_S,4,0));
  int nUpdateLuaHandle = (tolua_ref_function(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MoveToByTime'", NULL);
#endif
  {
   self->MoveToByTime(*destPos,fTime,nMoveEndLuaHandle,nUpdateLuaHandle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MoveToByTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StopMoving of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_StopMoving00
static int tolua_luaapi_TLMoveObject_StopMoving00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StopMoving'", NULL);
#endif
  {
   self->StopMoving();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StopMoving'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDir of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_SetDir00
static int tolua_luaapi_TLMoveObject_SetDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* destPos = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDir'", NULL);
#endif
  {
   self->SetDir(*destPos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DoDeath of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_DoDeath00
static int tolua_luaapi_TLMoveObject_DoDeath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DoDeath'", NULL);
#endif
  {
   self->DoDeath();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DoDeath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayAction of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_PlayAction00
static int tolua_luaapi_TLMoveObject_PlayAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  int nActionType = ((int)  tolua_tonumber(tolua_S,2,0));
  int nLoopCount = ((int)  tolua_tonumber(tolua_S,3,0));
  int nUserData = ((int)  tolua_tonumber(tolua_S,4,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayAction'", NULL);
#endif
  {
   self->PlayAction(nActionType,nLoopCount,nUserData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayAnimationFromMoveObject of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_PlayAnimationFromMoveObject00
static int tolua_luaapi_TLMoveObject_PlayAnimationFromMoveObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isfunction(tolua_S,5,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isfunction(tolua_S,6,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  TLMoveObject* pFrom = ((TLMoveObject*)  tolua_tousertype(tolua_S,2,0));
  int nAnimationType = ((int)  tolua_tonumber(tolua_S,3,0));
  float fTime = ((float)  tolua_tonumber(tolua_S,4,0));
  int nEndLuaHandle = (tolua_ref_function(tolua_S,5,0));
  int nUpdateLuaHandle = (tolua_ref_function(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayAnimationFromMoveObject'", NULL);
#endif
  {
   self->PlayAnimationFromMoveObject(pFrom,nAnimationType,fTime,nEndLuaHandle,nUpdateLuaHandle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayAnimationFromMoveObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ActionFreeze of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_ActionFreeze00
static int tolua_luaapi_TLMoveObject_ActionFreeze00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ActionFreeze'", NULL);
#endif
  {
   self->ActionFreeze();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ActionFreeze'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCollideRect of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_GetCollideRect00
static int tolua_luaapi_TLMoveObject_GetCollideRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCollideRect'", NULL);
#endif
  {
   CCRect tolua_ret = (CCRect)  self->GetCollideRect();
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
 tolua_error(tolua_S,"#ferror in function 'GetCollideRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjectNode of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_GetObjectNode00
static int tolua_luaapi_TLMoveObject_GetObjectNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectNode'", NULL);
#endif
  {
   CCNode* tolua_ret = (CCNode*)  self->GetObjectNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetShadowSprite of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_GetShadowSprite00
static int tolua_luaapi_TLMoveObject_GetShadowSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetShadowSprite'", NULL);
#endif
  {
   CCSprite* tolua_ret = (CCSprite*)  self->GetShadowSprite();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetShadowSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIsVisible of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_SetIsVisible00
static int tolua_luaapi_TLMoveObject_SetIsVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetIsVisible of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_GetIsVisible00
static int tolua_luaapi_TLMoveObject_GetIsVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetPosition of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_SetPosition00
static int tolua_luaapi_TLMoveObject_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* pos = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(*pos);
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

/* method: GetPosition of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_GetPosition00
static int tolua_luaapi_TLMoveObject_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->GetPosition();
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
 tolua_error(tolua_S,"#ferror in function 'GetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMoveObjectScaleX of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_SetMoveObjectScaleX00
static int tolua_luaapi_TLMoveObject_SetMoveObjectScaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  float fScaleX = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMoveObjectScaleX'", NULL);
#endif
  {
   self->SetMoveObjectScaleX(fScaleX);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMoveObjectScaleX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMoveObjectScaleY of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_SetMoveObjectScaleY00
static int tolua_luaapi_TLMoveObject_SetMoveObjectScaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  float fScaleY = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMoveObjectScaleY'", NULL);
#endif
  {
   self->SetMoveObjectScaleY(fScaleY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMoveObjectScaleY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetResID of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_SetResID00
static int tolua_luaapi_TLMoveObject_SetResID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  int nResID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetResID'", NULL);
#endif
  {
   self->SetResID(nResID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetResID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetResID of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_GetResID00
static int tolua_luaapi_TLMoveObject_GetResID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetResID'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetResID();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetResID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetName of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_SetName00
static int tolua_luaapi_TLMoveObject_SetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string strName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetName'", NULL);
#endif
  {
   self->SetName(strName);
   tolua_pushcppstring(tolua_S,(const char*)strName);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_GetName00
static int tolua_luaapi_TLMoveObject_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHeadIcon of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_SetHeadIcon00
static int tolua_luaapi_TLMoveObject_SetHeadIcon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  int nIconID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHeadIcon'", NULL);
#endif
  {
   self->SetHeadIcon(nIconID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHeadIcon'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadAction of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_LoadAction00
static int tolua_luaapi_TLMoveObject_LoadAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  int nAction = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadAction'", NULL);
#endif
  {
   MovieClip* tolua_ret = (MovieClip*)  self->LoadAction(nAction);
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    tolua_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"MovieClip");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDefaultAction of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_SetDefaultAction00
static int tolua_luaapi_TLMoveObject_SetDefaultAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  int nDefaultAction = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDefaultAction'", NULL);
#endif
  {
   self->SetDefaultAction(nDefaultAction);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDefaultAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDefaultAction of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_GetDefaultAction00
static int tolua_luaapi_TLMoveObject_GetDefaultAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDefaultAction'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetDefaultAction();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDefaultAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMoveSpeed of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_SetMoveSpeed00
static int tolua_luaapi_TLMoveObject_SetMoveSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  float fMoveSpeed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMoveSpeed'", NULL);
#endif
  {
   self->SetMoveSpeed(fMoveSpeed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMoveSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMoveSpeed of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_GetMoveSpeed00
static int tolua_luaapi_TLMoveObject_GetMoveSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMoveSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetMoveSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMoveSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMCScaleX of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_SetMCScaleX00
static int tolua_luaapi_TLMoveObject_SetMCScaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  float fScaleX = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMCScaleX'", NULL);
#endif
  {
   self->SetMCScaleX(fScaleX);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMCScaleX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMCScaleX of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_GetMCScaleX00
static int tolua_luaapi_TLMoveObject_GetMCScaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMCScaleX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetMCScaleX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMCScaleX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMCScaleY of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_SetMCScaleY00
static int tolua_luaapi_TLMoveObject_SetMCScaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  float fScaleY = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMCScaleY'", NULL);
#endif
  {
   self->SetMCScaleY(fScaleY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMCScaleY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMCScaleY of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_GetMCScaleY00
static int tolua_luaapi_TLMoveObject_GetMCScaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMCScaleY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetMCScaleY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMCScaleY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetActionLightTime of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_GetActionLightTime00
static int tolua_luaapi_TLMoveObject_GetActionLightTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  int nActionType = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetActionLightTime'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetActionLightTime(nActionType);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetActionLightTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetActionLightOffsetX of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_GetActionLightOffsetX00
static int tolua_luaapi_TLMoveObject_GetActionLightOffsetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  int nActionType = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetActionLightOffsetX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetActionLightOffsetX(nActionType);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetActionLightOffsetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetActionLightOffsetY of class  TLMoveObject */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMoveObject_GetActionLightOffsetY00
static int tolua_luaapi_TLMoveObject_GetActionLightOffsetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMoveObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMoveObject* self = (TLMoveObject*)  tolua_tousertype(tolua_S,1,0);
  int nActionType = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetActionLightOffsetY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetActionLightOffsetY(nActionType);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetActionLightOffsetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: quitConfirm */
#ifndef TOLUA_DISABLE_tolua_luaapi_quitConfirm00
static int tolua_luaapi_quitConfirm00(lua_State* tolua_S)
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

/* function: isETC1Supported */
#ifndef TOLUA_DISABLE_tolua_luaapi_isETC1Supported00
static int tolua_luaapi_isETC1Supported00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_getDeviceId00
static int tolua_luaapi_getDeviceId00(lua_State* tolua_S)
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

/* function: getUUID */
#ifndef TOLUA_DISABLE_tolua_luaapi_getUUID00
static int tolua_luaapi_getUUID00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_getPlatform00
static int tolua_luaapi_getPlatform00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_getOSVersion00
static int tolua_luaapi_getOSVersion00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_getResolution00
static int tolua_luaapi_getResolution00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_getUA00
static int tolua_luaapi_getUA00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_getMetaData00
static int tolua_luaapi_getMetaData00(lua_State* tolua_S)
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

/* function: acquireWakeLock */
#ifndef TOLUA_DISABLE_tolua_luaapi_acquireWakeLock00
static int tolua_luaapi_acquireWakeLock00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_releaseWakeLock00
static int tolua_luaapi_releaseWakeLock00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_userActivity00
static int tolua_luaapi_userActivity00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_getPackageVersion00
static int tolua_luaapi_getPackageVersion00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_getPackageName00
static int tolua_luaapi_getPackageName00(lua_State* tolua_S)
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
   const char* tolua_ret = (const char*)  getPackageName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
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

/* function: getNetworkType */
#ifndef TOLUA_DISABLE_tolua_luaapi_getNetworkType00
static int tolua_luaapi_getNetworkType00(lua_State* tolua_S)
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
   const char* tolua_ret = (const char*)  getNetworkType();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNetworkType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: openURL */
#ifndef TOLUA_DISABLE_tolua_luaapi_openURL00
static int tolua_luaapi_openURL00(lua_State* tolua_S)
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

/* function: receiptCallback */
#ifndef TOLUA_DISABLE_tolua_luaapi_receiptCallback00
static int tolua_luaapi_receiptCallback00(lua_State* tolua_S)
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
  const char* transaction_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   receiptCallback(transaction_id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'receiptCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: resendReceiptsValidation */
#ifndef TOLUA_DISABLE_tolua_luaapi_resendReceiptsValidation00
static int tolua_luaapi_resendReceiptsValidation00(lua_State* tolua_S)
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
   resendReceiptsValidation();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resendReceiptsValidation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SharedAssetsManager of class  AssetsManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_AssetsManager_SharedAssetsManager00
static int tolua_luaapi_AssetsManager_SharedAssetsManager00(lua_State* tolua_S)
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
   AssetsManager* tolua_ret = (AssetsManager*)  AssetsManager::SharedAssetsManager();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AssetsManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SharedAssetsManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  AssetsManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_AssetsManager_Load00
static int tolua_luaapi_AssetsManager_Load00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_AssetsManager_fileExists00
static int tolua_luaapi_AssetsManager_fileExists00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_AssetsManager_getRealPath00
static int tolua_luaapi_AssetsManager_getRealPath00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_AssetsManager_getFileContent00
static int tolua_luaapi_AssetsManager_getFileContent00(lua_State* tolua_S)
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
   void* tolua_ret = (void*)  self->getFileContent(url,pMode,&iSize);
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
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
#ifndef TOLUA_DISABLE_tolua_luaapi_AssetsManager_getVersion00
static int tolua_luaapi_AssetsManager_getVersion00(lua_State* tolua_S)
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

/* method: getVersionName of class  AssetsManager */
#ifndef TOLUA_DISABLE_tolua_luaapi_AssetsManager_getVersionName00
static int tolua_luaapi_AssetsManager_getVersionName00(lua_State* tolua_S)
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
   string tolua_ret = (string)  self->getVersionName();
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
#ifndef TOLUA_DISABLE_tolua_luaapi_AssetsManager_supportAssetsUpgrade00
static int tolua_luaapi_AssetsManager_supportAssetsUpgrade00(lua_State* tolua_S)
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

/* method: sharedTexFontConfig of class  CCTexFontConfig */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCTexFontConfig_sharedTexFontConfig00
static int tolua_luaapi_CCTexFontConfig_sharedTexFontConfig00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCTexFontConfig",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCTexFontConfig* tolua_ret = (CCTexFontConfig*)  CCTexFontConfig::sharedTexFontConfig();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCTexFontConfig");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedTexFontConfig'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: EnterBackground of class  CCTexFontConfig */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCTexFontConfig_EnterBackground00
static int tolua_luaapi_CCTexFontConfig_EnterBackground00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCTexFontConfig",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTexFontConfig* self = (CCTexFontConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'EnterBackground'", NULL);
#endif
  {
   self->EnterBackground();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EnterBackground'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: EnterForeground of class  CCTexFontConfig */
#ifndef TOLUA_DISABLE_tolua_luaapi_CCTexFontConfig_EnterForeground00
static int tolua_luaapi_CCTexFontConfig_EnterForeground00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCTexFontConfig",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTexFontConfig* self = (CCTexFontConfig*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'EnterForeground'", NULL);
#endif
  {
   self->EnterForeground();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EnterForeground'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sharedDrama of class  XLDrama */
#ifndef TOLUA_DISABLE_tolua_luaapi_XLDrama_sharedDrama00
static int tolua_luaapi_XLDrama_sharedDrama00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XLDrama",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XLDrama* tolua_ret = (XLDrama*)  XLDrama::sharedDrama();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XLDrama");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedDrama'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: purgeSharedDrama of class  XLDrama */
#ifndef TOLUA_DISABLE_tolua_luaapi_XLDrama_purgeSharedDrama00
static int tolua_luaapi_XLDrama_purgeSharedDrama00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XLDrama",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XLDrama::purgeSharedDrama();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'purgeSharedDrama'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ShowDramaLua of class  XLDrama */
#ifndef TOLUA_DISABLE_tolua_luaapi_XLDrama_ShowDramaLua00
static int tolua_luaapi_XLDrama_ShowDramaLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XLDrama",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isfunction(tolua_S,3,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isfunction(tolua_S,4,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XLDrama* self = (XLDrama*)  tolua_tousertype(tolua_S,1,0);
  const std::string strFile = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  int nLuaHandle = (tolua_ref_function(tolua_S,3,0));
  int nCancelLuaHandle = (tolua_ref_function(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ShowDramaLua'", NULL);
#endif
  {
   self->ShowDramaLua(strFile,nLuaHandle,nCancelLuaHandle);
   tolua_pushcppstring(tolua_S,(const char*)strFile);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ShowDramaLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: exitFight of class  XLDrama */
#ifndef TOLUA_DISABLE_tolua_luaapi_XLDrama_exitFight00
static int tolua_luaapi_XLDrama_exitFight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XLDrama",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XLDrama* self = (XLDrama*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'exitFight'", NULL);
#endif
  {
   self->exitFight();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'exitFight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopAllEffects of class  SimpleAudioEngine */
#ifndef TOLUA_DISABLE_tolua_luaapi_SimpleAudioEngine_stopAllEffects00
static int tolua_luaapi_SimpleAudioEngine_stopAllEffects00(lua_State* tolua_S)
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

/* method: sharedHttpDownloader of class  CHttpDownloader */
#ifndef TOLUA_DISABLE_tolua_luaapi_CHttpDownloader_sharedHttpDownloader00
static int tolua_luaapi_CHttpDownloader_sharedHttpDownloader00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_CHttpDownloader_purgeSharedHttpDownloader00
static int tolua_luaapi_CHttpDownloader_purgeSharedHttpDownloader00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_CHttpDownloader_getContent00
static int tolua_luaapi_CHttpDownloader_getContent00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_CHttpDownloader_saveToFile00
static int tolua_luaapi_CHttpDownloader_saveToFile00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_CHttpDownloader_register_callback00
static int tolua_luaapi_CHttpDownloader_register_callback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CHttpDownloader",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isfunction(tolua_S,2,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CHttpDownloader* self = (CHttpDownloader*)  tolua_tousertype(tolua_S,1,0);
  int handler = (tolua_ref_function(tolua_S,2,0));
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
#ifndef TOLUA_DISABLE_tolua_luaapi_CHttpDownloader_register_progress_callback00
static int tolua_luaapi_CHttpDownloader_register_progress_callback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CHttpDownloader",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isfunction(tolua_S,2,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CHttpDownloader* self = (CHttpDownloader*)  tolua_tousertype(tolua_S,1,0);
  int handler = (tolua_ref_function(tolua_S,2,0));
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

/* function: OpenPlatformLogin */
#ifndef TOLUA_DISABLE_tolua_luaapi_OpenPlatformLogin00
static int tolua_luaapi_OpenPlatformLogin00(lua_State* tolua_S)
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

/* function: OpenPayInterface */
#ifndef TOLUA_DISABLE_tolua_luaapi_OpenPayInterface00
static int tolua_luaapi_OpenPayInterface00(lua_State* tolua_S)
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
  int money = ((int)  tolua_tonumber(tolua_S,2,0));
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
#ifndef TOLUA_DISABLE_tolua_luaapi_EnterPlatform00
static int tolua_luaapi_EnterPlatform00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_GetSdkType00
static int tolua_luaapi_GetSdkType00(lua_State* tolua_S)
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

/* method: sharedTLMaskLayer of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMaskLayer_sharedTLMaskLayer00
static int tolua_luaapi_TLMaskLayer_sharedTLMaskLayer00(lua_State* tolua_S)
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
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLMaskLayer");
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
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMaskLayer_resetMaskLayer00
static int tolua_luaapi_TLMaskLayer_resetMaskLayer00(lua_State* tolua_S)
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

/* method: setIsClickTest of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMaskLayer_setIsClickTest00
static int tolua_luaapi_TLMaskLayer_setIsClickTest00(lua_State* tolua_S)
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
  bool clickTest = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIsClickTest'", NULL);
#endif
  {
   self->setIsClickTest(clickTest);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIsClickTest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIsMaskScene of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMaskLayer_setIsMaskScene00
static int tolua_luaapi_TLMaskLayer_setIsMaskScene00(lua_State* tolua_S)
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

/* method: setIsClickToContinue of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMaskLayer_setIsClickToContinue00
static int tolua_luaapi_TLMaskLayer_setIsClickToContinue00(lua_State* tolua_S)
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
  bool clickToContinue = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIsClickToContinue'", NULL);
#endif
  {
   self->setIsClickToContinue(clickToContinue);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIsClickToContinue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: appendHighlightRect of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMaskLayer_appendHighlightRect00
static int tolua_luaapi_TLMaskLayer_appendHighlightRect00(lua_State* tolua_S)
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

/* method: appendHighlightRect of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMaskLayer_appendHighlightRect01
static int tolua_luaapi_TLMaskLayer_appendHighlightRect01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMaskLayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCRect",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const ccColor4B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TLMaskLayer* self = (TLMaskLayer*)  tolua_tousertype(tolua_S,1,0);
  const CCRect* rect = ((const CCRect*)  tolua_tousertype(tolua_S,2,0));
  const ccColor4B* color = ((const ccColor4B*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendHighlightRect'", NULL);
#endif
  {
   self->appendHighlightRect(*rect,*color);
  }
 }
 return 0;
tolua_lerror:
 return tolua_luaapi_TLMaskLayer_appendHighlightRect00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: renderMaskSprite of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMaskLayer_renderMaskSprite00
static int tolua_luaapi_TLMaskLayer_renderMaskSprite00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'renderMaskSprite'", NULL);
#endif
  {
   self->renderMaskSprite(r,g,b,a);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'renderMaskSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHitTestEnable of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMaskLayer_setHitTestEnable00
static int tolua_luaapi_TLMaskLayer_setHitTestEnable00(lua_State* tolua_S)
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
  bool bHitTestEnable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHitTestEnable'", NULL);
#endif
  {
   self->setHitTestEnable(bHitTestEnable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHitTestEnable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetHitTest of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMaskLayer_resetHitTest00
static int tolua_luaapi_TLMaskLayer_resetHitTest00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetHitTest'", NULL);
#endif
  {
   self->resetHitTest();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetHitTest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: appendHitTestRect of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMaskLayer_appendHitTestRect00
static int tolua_luaapi_TLMaskLayer_appendHitTestRect00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'appendHitTestRect'", NULL);
#endif
  {
   self->appendHitTestRect(*rect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'appendHitTestRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHitTestFuncCallback of class  TLMaskLayer */
#ifndef TOLUA_DISABLE_tolua_luaapi_TLMaskLayer_setHitTestFuncCallback00
static int tolua_luaapi_TLMaskLayer_setHitTestFuncCallback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLMaskLayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isfunction(tolua_S,2,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLMaskLayer* self = (TLMaskLayer*)  tolua_tousertype(tolua_S,1,0);
  int nLuaHandle = (tolua_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHitTestFuncCallback'", NULL);
#endif
  {
   self->setHitTestFuncCallback(nLuaHandle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHitTestFuncCallback'.",&tolua_err);
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MainSceneRoleMC_createWithName00
static int tolua_luaapi_MainSceneRoleMC_createWithName00(lua_State* tolua_S)
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
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MainSceneRoleMC");
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MainSceneRoleMC_playStand00
static int tolua_luaapi_MainSceneRoleMC_playStand00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MainSceneRoleMC_playWalk00
static int tolua_luaapi_MainSceneRoleMC_playWalk00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MainSceneRoleMC_setFrameRate00
static int tolua_luaapi_MainSceneRoleMC_setFrameRate00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MainSceneRoleMC_setFlipX00
static int tolua_luaapi_MainSceneRoleMC_setFlipX00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MainSceneRoleMC_setFlipY00
static int tolua_luaapi_MainSceneRoleMC_setFlipY00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MainSceneRoleMC_getRoleSprite00
static int tolua_luaapi_MainSceneRoleMC_getRoleSprite00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MainSceneRoleMC_setRoleSpriteOffsetX00
static int tolua_luaapi_MainSceneRoleMC_setRoleSpriteOffsetX00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MainSceneRoleMC_getRoleSpriteOffsetX00
static int tolua_luaapi_MainSceneRoleMC_getRoleSpriteOffsetX00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MainSceneRoleMC_setRoleSpriteOffsetY00
static int tolua_luaapi_MainSceneRoleMC_setRoleSpriteOffsetY00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MainSceneRoleMC_getRoleSpriteOffsetY00
static int tolua_luaapi_MainSceneRoleMC_getRoleSpriteOffsetY00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_MainSceneRoleMC_resetRoleSpritePosition00
static int tolua_luaapi_MainSceneRoleMC_resetRoleSpritePosition00(lua_State* tolua_S)
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

/* function: exit */
#ifndef TOLUA_DISABLE_tolua_luaapi_exit00
static int tolua_luaapi_exit00(lua_State* tolua_S)
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
  int status = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   exit(status);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'exit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: dump_rusage */
#ifndef TOLUA_DISABLE_tolua_luaapi_dump_rusage00
static int tolua_luaapi_dump_rusage00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_luaapi_dump_texture00
static int tolua_luaapi_dump_texture00(lua_State* tolua_S)
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

/* function: quitConfirm */
#ifndef TOLUA_DISABLE_tolua_luaapi_quitConfirm01
static int tolua_luaapi_quitConfirm01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   quitConfirm();
  }
 }
 return 0;
tolua_lerror:
 return tolua_luaapi_quitConfirm00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: quitApplication */
#ifndef TOLUA_DISABLE_tolua_luaapi_quitApplication00
static int tolua_luaapi_quitApplication00(lua_State* tolua_S)
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

/* Open function */
TOLUA_API int tolua_luaapi_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"TLRunningScene","TLRunningScene","CCScene",NULL);
  tolua_beginmodule(tolua_S,"TLRunningScene");
   tolua_function(tolua_S,"node",tolua_luaapi_TLRunningScene_node00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MovieClip","MovieClip","CCNode",NULL);
  tolua_beginmodule(tolua_S,"MovieClip");
   tolua_variable(tolua_S,"mcBoundingBox",tolua_get_MovieClip_mcBoundingBox,tolua_set_MovieClip_mcBoundingBox);
   tolua_function(tolua_S,"createWithName",tolua_luaapi_MovieClip_createWithName00);
   tolua_function(tolua_S,"play",tolua_luaapi_MovieClip_play00);
   tolua_function(tolua_S,"start",tolua_luaapi_MovieClip_start00);
   tolua_function(tolua_S,"pause",tolua_luaapi_MovieClip_pause00);
   tolua_function(tolua_S,"setAutoClear",tolua_luaapi_MovieClip_setAutoClear00);
   tolua_function(tolua_S,"getAutoClear",tolua_luaapi_MovieClip_getAutoClear00);
   tolua_function(tolua_S,"setFrameRate",tolua_luaapi_MovieClip_setFrameRate00);
   tolua_function(tolua_S,"getSymbolInfo",tolua_luaapi_MovieClip_getSymbolInfo00);
   tolua_function(tolua_S,"RegisterPlayEndCallbackLua",tolua_luaapi_MovieClip_RegisterPlayEndCallbackLua00);
   tolua_function(tolua_S,"setColor",tolua_luaapi_MovieClip_setColor00);
   tolua_function(tolua_S,"getResetKeyframe",tolua_luaapi_MovieClip_getResetKeyframe00);
   tolua_function(tolua_S,"setResetKeyframe",tolua_luaapi_MovieClip_setResetKeyframe00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MCLoader","MCLoader","",NULL);
  tolua_beginmodule(tolua_S,"MCLoader");
   tolua_function(tolua_S,"sharedMCLoader",tolua_luaapi_MCLoader_sharedMCLoader00);
   tolua_function(tolua_S,"loadIndexFile",tolua_luaapi_MCLoader_loadIndexFile00);
   tolua_function(tolua_S,"getSymbol",tolua_luaapi_MCLoader_getSymbol00);
   tolua_function(tolua_S,"loadSpriteFrame",tolua_luaapi_MCLoader_loadSpriteFrame00);
   tolua_function(tolua_S,"loadSprite",tolua_luaapi_MCLoader_loadSprite00);
   tolua_function(tolua_S,"loadSpriteGray",tolua_luaapi_MCLoader_loadSpriteGray00);
   tolua_function(tolua_S,"loadSpriteAsync",tolua_luaapi_MCLoader_loadSpriteAsync00);
   tolua_function(tolua_S,"addImageAsync",tolua_luaapi_MCLoader_addImageAsync00);
   tolua_function(tolua_S,"loadAssetsTexture",tolua_luaapi_MCLoader_loadAssetsTexture00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"getAssetsTexturePath",tolua_luaapi_getAssetsTexturePath00);
  tolua_function(tolua_S,"getBoundingBox",tolua_luaapi_getBoundingBox00);
  tolua_function(tolua_S,"toMovieClip",tolua_luaapi_toMovieClip00);
  tolua_function(tolua_S,"toSprite",tolua_luaapi_toSprite00);
  tolua_function(tolua_S,"toTTFText",tolua_luaapi_toTTFText00);
  tolua_function(tolua_S,"toTTFRichText",tolua_luaapi_toTTFRichText00);
  tolua_function(tolua_S,"toBMText",tolua_luaapi_toBMText00);
  tolua_function(tolua_S,"toRect",tolua_luaapi_toRect00);
  tolua_function(tolua_S,"toFrame",tolua_luaapi_toFrame00);
  tolua_function(tolua_S,"toParticle",tolua_luaapi_toParticle00);
  tolua_cclass(tolua_S,"ClipNode","ClipNode","CCNode",NULL);
  tolua_beginmodule(tolua_S,"ClipNode");
   tolua_function(tolua_S,"clipNode",tolua_luaapi_ClipNode_clipNode00);
   tolua_function(tolua_S,"clipNode",tolua_luaapi_ClipNode_clipNode01);
   tolua_function(tolua_S,"getClipRegion",tolua_luaapi_ClipNode_getClipRegion00);
   tolua_function(tolua_S,"setClipRegion",tolua_luaapi_ClipNode_setClipRegion00);
   tolua_function(tolua_S,"removeClipRegion",tolua_luaapi_ClipNode_removeClipRegion00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MCFrame","MCFrame","ClipNode",NULL);
  tolua_beginmodule(tolua_S,"MCFrame");
   tolua_function(tolua_S,"createWithBox",tolua_luaapi_MCFrame_createWithBox00);
   tolua_function(tolua_S,"initWithBox",tolua_luaapi_MCFrame_initWithBox00);
   tolua_variable(tolua_S,"mcBoundingBox",tolua_get_MCFrame_mcBoundingBox,tolua_set_MCFrame_mcBoundingBox);
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
  tolua_constant(tolua_S,"TL_EVENT_ADJUST_LAYOUT",TL_EVENT_ADJUST_LAYOUT);
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
  tolua_constant(tolua_S,"TL_INPUT_TEXT_MODEL_PASSWORD",TL_INPUT_TEXT_MODEL_PASSWORD);
  tolua_constant(tolua_S,"TL_ACTION_TYPE_NONE",TL_ACTION_TYPE_NONE);
  tolua_constant(tolua_S,"TL_ACTION_TYPE_FADE_IN",TL_ACTION_TYPE_FADE_IN);
  tolua_constant(tolua_S,"TL_ACTION_TYPE_FADE_OUT",TL_ACTION_TYPE_FADE_OUT);
  tolua_constant(tolua_S,"TL_ACTION_TYPE_BLINK",TL_ACTION_TYPE_BLINK);
  tolua_cclass(tolua_S,"TLWindow","TLWindow","CCObject",NULL);
  tolua_beginmodule(tolua_S,"TLWindow");
   tolua_function(tolua_S,"createWindow",tolua_luaapi_TLWindow_createWindow00);
   tolua_function(tolua_S,"createEditLabel",tolua_luaapi_TLWindow_createEditLabel00);
   tolua_function(tolua_S,"createEditLabel",tolua_luaapi_TLWindow_createEditLabel01);
   tolua_function(tolua_S,"AddChildWindow",tolua_luaapi_TLWindow_AddChildWindow00);
   tolua_function(tolua_S,"RemoveAllChildWindow",tolua_luaapi_TLWindow_RemoveAllChildWindow00);
   tolua_function(tolua_S,"RemoveChildWindow",tolua_luaapi_TLWindow_RemoveChildWindow00);
   tolua_function(tolua_S,"GetChildWindow",tolua_luaapi_TLWindow_GetChildWindow00);
   tolua_function(tolua_S,"AdjustLayout",tolua_luaapi_TLWindow_AdjustLayout00);
   tolua_function(tolua_S,"FindWindow",tolua_luaapi_TLWindow_FindWindow00);
   tolua_function(tolua_S,"FindWindow",tolua_luaapi_TLWindow_FindWindow01);
   tolua_function(tolua_S,"RegisterEvent",tolua_luaapi_TLWindow_RegisterEvent00);
   tolua_function(tolua_S,"GetNode",tolua_luaapi_TLWindow_GetNode00);
   tolua_function(tolua_S,"GetRootNode",tolua_luaapi_TLWindow_GetRootNode00);
   tolua_function(tolua_S,"GetAttachNode",tolua_luaapi_TLWindow_GetAttachNode00);
   tolua_function(tolua_S,"SetInputTextModel",tolua_luaapi_TLWindow_SetInputTextModel00);
   tolua_function(tolua_S,"SetInputLimit",tolua_luaapi_TLWindow_SetInputLimit00);
   tolua_function(tolua_S,"GetInputText",tolua_luaapi_TLWindow_GetInputText00);
   tolua_function(tolua_S,"SetInputText",tolua_luaapi_TLWindow_SetInputText00);
   tolua_function(tolua_S,"AppendInputText",tolua_luaapi_TLWindow_AppendInputText00);
   tolua_function(tolua_S,"StartAction",tolua_luaapi_TLWindow_StartAction00);
   tolua_function(tolua_S,"GetWindowName",tolua_luaapi_TLWindow_GetWindowName00);
   tolua_function(tolua_S,"SetWindowName",tolua_luaapi_TLWindow_SetWindowName00);
   tolua_function(tolua_S,"GetIsEnable",tolua_luaapi_TLWindow_GetIsEnable00);
   tolua_function(tolua_S,"SetIsEnable",tolua_luaapi_TLWindow_SetIsEnable00);
   tolua_function(tolua_S,"GetIsScroll",tolua_luaapi_TLWindow_GetIsScroll00);
   tolua_function(tolua_S,"GetIsInput",tolua_luaapi_TLWindow_GetIsInput00);
   tolua_function(tolua_S,"GetIsVisible",tolua_luaapi_TLWindow_GetIsVisible00);
   tolua_function(tolua_S,"SetIsVisible",tolua_luaapi_TLWindow_SetIsVisible00);
   tolua_function(tolua_S,"GetWindowRect",tolua_luaapi_TLWindow_GetWindowRect00);
   tolua_function(tolua_S,"SetWindowPos",tolua_luaapi_TLWindow_SetWindowPos00);
   tolua_function(tolua_S,"GetWindowPos",tolua_luaapi_TLWindow_GetWindowPos00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TLWindowManager","TLWindowManager","CCLayer",NULL);
  tolua_beginmodule(tolua_S,"TLWindowManager");
   tolua_function(tolua_S,"SharedTLWindowManager",tolua_luaapi_TLWindowManager_SharedTLWindowManager00);
   tolua_function(tolua_S,"GetCenterPoint",tolua_luaapi_TLWindowManager_GetCenterPoint00);
   tolua_function(tolua_S,"ReleaseAllWindow",tolua_luaapi_TLWindowManager_ReleaseAllWindow00);
   tolua_function(tolua_S,"AddModuleWindow",tolua_luaapi_TLWindowManager_AddModuleWindow00);
   tolua_function(tolua_S,"HideAllModuleWindow",tolua_luaapi_TLWindowManager_HideAllModuleWindow00);
   tolua_function(tolua_S,"DestroyAllModuleWindow",tolua_luaapi_TLWindowManager_DestroyAllModuleWindow00);
   tolua_function(tolua_S,"RemoveModuleWindow",tolua_luaapi_TLWindowManager_RemoveModuleWindow00);
   tolua_function(tolua_S,"FindModuleWindow",tolua_luaapi_TLWindowManager_FindModuleWindow00);
   tolua_function(tolua_S,"FindModuleWindow",tolua_luaapi_TLWindowManager_FindModuleWindow01);
   tolua_function(tolua_S,"getLastPointX",tolua_luaapi_TLWindowManager_getLastPointX00);
   tolua_function(tolua_S,"getLastPointY",tolua_luaapi_TLWindowManager_getLastPointY00);
   tolua_function(tolua_S,"getLastPoint",tolua_luaapi_TLWindowManager_getLastPoint00);
   tolua_function(tolua_S,"MoveToTop",tolua_luaapi_TLWindowManager_MoveToTop00);
   tolua_function(tolua_S,"MoveToBottom",tolua_luaapi_TLWindowManager_MoveToBottom00);
   tolua_function(tolua_S,"StopEventBubble",tolua_luaapi_TLWindowManager_StopEventBubble00);
   tolua_function(tolua_S,"SetIsPressScene",tolua_luaapi_TLWindowManager_SetIsPressScene00);
   tolua_function(tolua_S,"ShowUI",tolua_luaapi_TLWindowManager_ShowUI00);
   tolua_function(tolua_S,"SetModalWindow",tolua_luaapi_TLWindowManager_SetModalWindow00);
   tolua_function(tolua_S,"SetSystemWindow",tolua_luaapi_TLWindowManager_SetSystemWindow00);
   tolua_function(tolua_S,"SetIsLockScreen",tolua_luaapi_TLWindowManager_SetIsLockScreen00);
   tolua_function(tolua_S,"GetIsLockScreen",tolua_luaapi_TLWindowManager_GetIsLockScreen00);
   tolua_function(tolua_S,"TweenTo",tolua_luaapi_TLWindowManager_TweenTo00);
   tolua_function(tolua_S,"TweenFrom",tolua_luaapi_TLWindowManager_TweenFrom00);
   tolua_function(tolua_S,"TweenFromTo",tolua_luaapi_TLWindowManager_TweenFromTo00);
   tolua_function(tolua_S,"RemoveTween",tolua_luaapi_TLWindowManager_RemoveTween00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TLDropDragHelper","TLDropDragHelper","CCObject",NULL);
  tolua_beginmodule(tolua_S,"TLDropDragHelper");
   tolua_function(tolua_S,"AppendShow",tolua_luaapi_TLDropDragHelper_AppendShow00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CNetMsg","CNetMsg","",NULL);
  tolua_beginmodule(tolua_S,"CNetMsg");
   tolua_function(tolua_S,"Parse",tolua_luaapi_CNetMsg_Parse00);
   tolua_function(tolua_S,"GetMsgID",tolua_luaapi_CNetMsg_GetMsgID00);
   tolua_function(tolua_S,"GetMsgCode",tolua_luaapi_CNetMsg_GetMsgCode00);
   tolua_function(tolua_S,"ParseContent",tolua_luaapi_CNetMsg_ParseContent00);
   tolua_function(tolua_S,"GetContentLength",tolua_luaapi_CNetMsg_GetContentLength00);
   tolua_function(tolua_S,"GetContentData",tolua_luaapi_CNetMsg_GetContentData00);
   tolua_function(tolua_S,"GetContentStr",tolua_luaapi_CNetMsg_GetContentStr00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CNetSender","CNetSender","",NULL);
  tolua_beginmodule(tolua_S,"CNetSender");
   tolua_function(tolua_S,"ConnectSession",tolua_luaapi_CNetSender_ConnectSession00);
   tolua_function(tolua_S,"SessionConnection",tolua_luaapi_CNetSender_SessionConnection00);
   tolua_function(tolua_S,"CloseSession",tolua_luaapi_CNetSender_CloseSession00);
   tolua_function(tolua_S,"ConnectWorld",tolua_luaapi_CNetSender_ConnectWorld00);
   tolua_function(tolua_S,"WorldConnection",tolua_luaapi_CNetSender_WorldConnection00);
   tolua_function(tolua_S,"CloseWorld",tolua_luaapi_CNetSender_CloseWorld00);
   tolua_function(tolua_S,"NewNetMsgAndSend",tolua_luaapi_CNetSender_NewNetMsgAndSend00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CNetReceiver","CNetReceiver","",NULL);
  tolua_beginmodule(tolua_S,"CNetReceiver");
   tolua_function(tolua_S,"SharedNetReceiver",tolua_luaapi_CNetReceiver_SharedNetReceiver00);
   tolua_function(tolua_S,"SetMsgErrorDefaultFuncPtr",tolua_luaapi_CNetReceiver_SetMsgErrorDefaultFuncPtr00);
   tolua_function(tolua_S,"RegisterMsgErrorFuncPtr",tolua_luaapi_CNetReceiver_RegisterMsgErrorFuncPtr00);
   tolua_function(tolua_S,"RegisterMsgProcessFuncPtr",tolua_luaapi_CNetReceiver_RegisterMsgProcessFuncPtr00);
   tolua_function(tolua_S,"SetErrorMsgToSelf",tolua_luaapi_CNetReceiver_SetErrorMsgToSelf00);
   tolua_function(tolua_S,"SendMsgToSelf",tolua_luaapi_CNetReceiver_SendMsgToSelf00);
   tolua_function(tolua_S,"Reset",tolua_luaapi_CNetReceiver_Reset00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"EVENT_TYPE_INVALID",EVENT_TYPE_INVALID);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_MAX_HP",EVENT_TYPE_PLAYER_MAX_HP);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_MAX_MP",EVENT_TYPE_PLAYER_MAX_MP);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_CURRENT_HP",EVENT_TYPE_PLAYER_CURRENT_HP);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_LEVEL",EVENT_TYPE_PLAYER_LEVEL);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_FORCE",EVENT_TYPE_PLAYER_FORCE);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_STUNT",EVENT_TYPE_PLAYER_STUNT);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_SKILL",EVENT_TYPE_PLAYER_SKILL);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_INTELLECT",EVENT_TYPE_PLAYER_INTELLECT);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_VIPST",EVENT_TYPE_PLAYER_VIPST);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_GOLD",EVENT_TYPE_PLAYER_GOLD);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_MONEY",EVENT_TYPE_PLAYER_MONEY);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_SP",EVENT_TYPE_PLAYER_SP);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_PURPLE_COIN",EVENT_TYPE_PLAYER_PURPLE_COIN);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_BLUE_COIN",EVENT_TYPE_PLAYER_BLUE_COIN);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_REFRESH_RECRUITMENT",EVENT_TYPE_PLAYER_REFRESH_RECRUITMENT);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_FREE_ROLL",EVENT_TYPE_PLAYER_FREE_ROLL);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_COST_ROLL",EVENT_TYPE_PLAYER_COST_ROLL);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_RANK",EVENT_TYPE_PLAYER_RANK);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_HORNOR",EVENT_TYPE_PLAYER_HORNOR);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_CHALLENGE_COUNT",EVENT_TYPE_PLAYER_CHALLENGE_COUNT);
  tolua_constant(tolua_S,"EVENT_TYPE_PLAYER_RANK_DC",EVENT_TYPE_PLAYER_RANK_DC);
  tolua_constant(tolua_S,"EVENT_TYPE_PET_MAX_HP",EVENT_TYPE_PET_MAX_HP);
  tolua_constant(tolua_S,"EVENT_TYPE_PET_MAX_MP",EVENT_TYPE_PET_MAX_MP);
  tolua_constant(tolua_S,"EVENT_TYPE_PET_CURRENT_HP",EVENT_TYPE_PET_CURRENT_HP);
  tolua_constant(tolua_S,"EVENT_TYPE_PET_LEVEL",EVENT_TYPE_PET_LEVEL);
  tolua_constant(tolua_S,"EVENT_TYPE_PET_FORCE",EVENT_TYPE_PET_FORCE);
  tolua_constant(tolua_S,"EVENT_TYPE_PET_STUNT",EVENT_TYPE_PET_STUNT);
  tolua_constant(tolua_S,"EVENT_TYPE_PET_SKILL",EVENT_TYPE_PET_SKILL);
  tolua_constant(tolua_S,"EVENT_TYPE_PET_INTELLECT",EVENT_TYPE_PET_INTELLECT);
  tolua_constant(tolua_S,"EVENT_TYPE_PET_COUNT",EVENT_TYPE_PET_COUNT);
  tolua_constant(tolua_S,"EVENT_TYPE_CHANGE_SCENE_BEGIN",EVENT_TYPE_CHANGE_SCENE_BEGIN);
  tolua_constant(tolua_S,"EVENT_TYPE_CHANGE_SCENE_END",EVENT_TYPE_CHANGE_SCENE_END);
  tolua_constant(tolua_S,"EVENT_TYPE_TRACE_TASK_STATUS_CHANGED",EVENT_TYPE_TRACE_TASK_STATUS_CHANGED);
  tolua_constant(tolua_S,"EVENT_TYPE_REMOVE_UNUSED_TEXTURE",EVENT_TYPE_REMOVE_UNUSED_TEXTURE);
  tolua_constant(tolua_S,"EVENT_TYPE_MAX",EVENT_TYPE_MAX);
  tolua_cclass(tolua_S,"TLEventTrigger","TLEventTrigger","CCObject",NULL);
  tolua_beginmodule(tolua_S,"TLEventTrigger");
   tolua_function(tolua_S,"SharedTLEventTrigger",tolua_luaapi_TLEventTrigger_SharedTLEventTrigger00);
   tolua_function(tolua_S,"PurgeLuaHandlers",tolua_luaapi_TLEventTrigger_PurgeLuaHandlers00);
   tolua_function(tolua_S,"RegisterEventCallback",tolua_luaapi_TLEventTrigger_RegisterEventCallback00);
   tolua_function(tolua_S,"UnregisterEventCallback",tolua_luaapi_TLEventTrigger_UnregisterEventCallback00);
   tolua_function(tolua_S,"SetEvent",tolua_luaapi_TLEventTrigger_SetEvent00);
   tolua_function(tolua_S,"GetRegisterID",tolua_luaapi_TLEventTrigger_GetRegisterID00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"XLTimer","XLTimer","CCObject",NULL);
  tolua_beginmodule(tolua_S,"XLTimer");
   tolua_function(tolua_S,"SharedXLTimer",tolua_luaapi_XLTimer_SharedXLTimer00);
   tolua_function(tolua_S,"GetWorldTime",tolua_luaapi_XLTimer_GetWorldTime00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"LuaCallFunc","LuaCallFunc","CCActionInstant",NULL);
  tolua_beginmodule(tolua_S,"LuaCallFunc");
   tolua_function(tolua_S,"create",tolua_luaapi_LuaCallFunc_create00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"LuaMoveToEx","LuaMoveToEx","CCActionInterval",NULL);
  tolua_beginmodule(tolua_S,"LuaMoveToEx");
   tolua_function(tolua_S,"resetWithDuration",tolua_luaapi_LuaMoveToEx_resetWithDuration00);
   tolua_function(tolua_S,"actionWithDuration",tolua_luaapi_LuaMoveToEx_actionWithDuration00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TLTimeLineManager","TLTimeLineManager","CCObject",NULL);
  tolua_beginmodule(tolua_S,"TLTimeLineManager");
   tolua_function(tolua_S,"SharedTLTimeLineManager",tolua_luaapi_TLTimeLineManager_SharedTLTimeLineManager00);
   tolua_function(tolua_S,"SetTimeLineEndFunc",tolua_luaapi_TLTimeLineManager_SetTimeLineEndFunc00);
   tolua_function(tolua_S,"AddTimeEvent",tolua_luaapi_TLTimeLineManager_AddTimeEvent00);
   tolua_function(tolua_S,"CreateTimeLine",tolua_luaapi_TLTimeLineManager_CreateTimeLine00);
   tolua_function(tolua_S,"CloseTimeLine",tolua_luaapi_TLTimeLineManager_CloseTimeLine00);
   tolua_function(tolua_S,"StartUpTimeLine",tolua_luaapi_TLTimeLineManager_StartUpTimeLine00);
   tolua_function(tolua_S,"PauseTimeLine",tolua_luaapi_TLTimeLineManager_PauseTimeLine00);
   tolua_function(tolua_S,"ContinueTimeLine",tolua_luaapi_TLTimeLineManager_ContinueTimeLine00);
   tolua_function(tolua_S,"StopTimeLine",tolua_luaapi_TLTimeLineManager_StopTimeLine00);
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
  tolua_cclass(tolua_S,"CCLabelTexFont","CCLabelTexFont","CCNode",NULL);
  tolua_beginmodule(tolua_S,"CCLabelTexFont");
   tolua_function(tolua_S,"labelWithString",tolua_luaapi_CCLabelTexFont_labelWithString00);
   tolua_function(tolua_S,"labelWithString",tolua_luaapi_CCLabelTexFont_labelWithString01);
   tolua_function(tolua_S,"initWithString",tolua_luaapi_CCLabelTexFont_initWithString00);
   tolua_function(tolua_S,"initWithString",tolua_luaapi_CCLabelTexFont_initWithString01);
   tolua_function(tolua_S,"setString",tolua_luaapi_CCLabelTexFont_setString00);
   tolua_function(tolua_S,"getString",tolua_luaapi_CCLabelTexFont_getString00);
   tolua_function(tolua_S,"setContentSize",tolua_luaapi_CCLabelTexFont_setContentSize00);
   tolua_function(tolua_S,"setColor",tolua_luaapi_CCLabelTexFont_setColor00);
   tolua_function(tolua_S,"setColor",tolua_luaapi_CCLabelTexFont_setColor01);
   tolua_function(tolua_S,"getColor",tolua_luaapi_CCLabelTexFont_getColor00);
   tolua_function(tolua_S,"getOpacity",tolua_luaapi_CCLabelTexFont_getOpacity00);
   tolua_function(tolua_S,"setOpacity",tolua_luaapi_CCLabelTexFont_setOpacity00);
   tolua_function(tolua_S,"setIsOpacityModifyRGB",tolua_luaapi_CCLabelTexFont_setIsOpacityModifyRGB00);
   tolua_function(tolua_S,"getIsOpacityModifyRGB",tolua_luaapi_CCLabelTexFont_getIsOpacityModifyRGB00);
   tolua_function(tolua_S,"getRealFontSize",tolua_luaapi_CCLabelTexFont_getRealFontSize00);
   tolua_function(tolua_S,"getChildByTag",tolua_luaapi_CCLabelTexFont_getChildByTag00);
   tolua_function(tolua_S,"getFontCount",tolua_luaapi_CCLabelTexFont_getFontCount00);
   tolua_function(tolua_S,"setRichString",tolua_luaapi_CCLabelTexFont_setRichString00);
   tolua_function(tolua_S,"getRichString",tolua_luaapi_CCLabelTexFont_getRichString00);
   tolua_function(tolua_S,"getRealSize",tolua_luaapi_CCLabelTexFont_getRealSize00);
   tolua_function(tolua_S,"setAlignment",tolua_luaapi_CCLabelTexFont_setAlignment00);
   tolua_function(tolua_S,"getAlignment",tolua_luaapi_CCLabelTexFont_getAlignment00);
   tolua_function(tolua_S,"appendRich",tolua_luaapi_CCLabelTexFont_appendRich00);
   tolua_function(tolua_S,"append",tolua_luaapi_CCLabelTexFont_append00);
   tolua_function(tolua_S,"setAlignmentInside",tolua_luaapi_CCLabelTexFont_setAlignmentInside00);
   tolua_function(tolua_S,"getAlignmentInside",tolua_luaapi_CCLabelTexFont_getAlignmentInside00);
   tolua_function(tolua_S,"setFontSize",tolua_luaapi_CCLabelTexFont_setFontSize00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TLMoveObject","TLMoveObject","CCObject",NULL);
  tolua_beginmodule(tolua_S,"TLMoveObject");
   tolua_variable(tolua_S,"ms_fNameOffsetY",tolua_get_TLMoveObject_ms_fNameOffsetY,tolua_set_TLMoveObject_ms_fNameOffsetY);
   tolua_variable(tolua_S,"ms_fIconOffsetY",tolua_get_TLMoveObject_ms_fIconOffsetY,tolua_set_TLMoveObject_ms_fIconOffsetY);
   tolua_function(tolua_S,"newTLMoveObject",tolua_luaapi_TLMoveObject_newTLMoveObject00);
   tolua_function(tolua_S,"releaseTLMoveObject",tolua_luaapi_TLMoveObject_releaseTLMoveObject00);
   tolua_function(tolua_S,"MoveToByTime",tolua_luaapi_TLMoveObject_MoveToByTime00);
   tolua_function(tolua_S,"StopMoving",tolua_luaapi_TLMoveObject_StopMoving00);
   tolua_function(tolua_S,"SetDir",tolua_luaapi_TLMoveObject_SetDir00);
   tolua_function(tolua_S,"DoDeath",tolua_luaapi_TLMoveObject_DoDeath00);
   tolua_function(tolua_S,"PlayAction",tolua_luaapi_TLMoveObject_PlayAction00);
   tolua_function(tolua_S,"PlayAnimationFromMoveObject",tolua_luaapi_TLMoveObject_PlayAnimationFromMoveObject00);
   tolua_function(tolua_S,"ActionFreeze",tolua_luaapi_TLMoveObject_ActionFreeze00);
   tolua_function(tolua_S,"GetCollideRect",tolua_luaapi_TLMoveObject_GetCollideRect00);
   tolua_function(tolua_S,"GetObjectNode",tolua_luaapi_TLMoveObject_GetObjectNode00);
   tolua_function(tolua_S,"GetShadowSprite",tolua_luaapi_TLMoveObject_GetShadowSprite00);
   tolua_function(tolua_S,"SetIsVisible",tolua_luaapi_TLMoveObject_SetIsVisible00);
   tolua_function(tolua_S,"GetIsVisible",tolua_luaapi_TLMoveObject_GetIsVisible00);
   tolua_function(tolua_S,"SetPosition",tolua_luaapi_TLMoveObject_SetPosition00);
   tolua_function(tolua_S,"GetPosition",tolua_luaapi_TLMoveObject_GetPosition00);
   tolua_function(tolua_S,"SetMoveObjectScaleX",tolua_luaapi_TLMoveObject_SetMoveObjectScaleX00);
   tolua_function(tolua_S,"SetMoveObjectScaleY",tolua_luaapi_TLMoveObject_SetMoveObjectScaleY00);
   tolua_function(tolua_S,"SetResID",tolua_luaapi_TLMoveObject_SetResID00);
   tolua_function(tolua_S,"GetResID",tolua_luaapi_TLMoveObject_GetResID00);
   tolua_function(tolua_S,"SetName",tolua_luaapi_TLMoveObject_SetName00);
   tolua_function(tolua_S,"GetName",tolua_luaapi_TLMoveObject_GetName00);
   tolua_function(tolua_S,"SetHeadIcon",tolua_luaapi_TLMoveObject_SetHeadIcon00);
   tolua_function(tolua_S,"LoadAction",tolua_luaapi_TLMoveObject_LoadAction00);
   tolua_function(tolua_S,"SetDefaultAction",tolua_luaapi_TLMoveObject_SetDefaultAction00);
   tolua_function(tolua_S,"GetDefaultAction",tolua_luaapi_TLMoveObject_GetDefaultAction00);
   tolua_function(tolua_S,"SetMoveSpeed",tolua_luaapi_TLMoveObject_SetMoveSpeed00);
   tolua_function(tolua_S,"GetMoveSpeed",tolua_luaapi_TLMoveObject_GetMoveSpeed00);
   tolua_function(tolua_S,"SetMCScaleX",tolua_luaapi_TLMoveObject_SetMCScaleX00);
   tolua_function(tolua_S,"GetMCScaleX",tolua_luaapi_TLMoveObject_GetMCScaleX00);
   tolua_function(tolua_S,"SetMCScaleY",tolua_luaapi_TLMoveObject_SetMCScaleY00);
   tolua_function(tolua_S,"GetMCScaleY",tolua_luaapi_TLMoveObject_GetMCScaleY00);
   tolua_function(tolua_S,"GetActionLightTime",tolua_luaapi_TLMoveObject_GetActionLightTime00);
   tolua_function(tolua_S,"GetActionLightOffsetX",tolua_luaapi_TLMoveObject_GetActionLightOffsetX00);
   tolua_function(tolua_S,"GetActionLightOffsetY",tolua_luaapi_TLMoveObject_GetActionLightOffsetY00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"quitConfirm",tolua_luaapi_quitConfirm00);
  tolua_function(tolua_S,"isETC1Supported",tolua_luaapi_isETC1Supported00);
  tolua_function(tolua_S,"getDeviceId",tolua_luaapi_getDeviceId00);
  tolua_function(tolua_S,"getUUID",tolua_luaapi_getUUID00);
  tolua_function(tolua_S,"getPlatform",tolua_luaapi_getPlatform00);
  tolua_function(tolua_S,"getOSVersion",tolua_luaapi_getOSVersion00);
  tolua_function(tolua_S,"getResolution",tolua_luaapi_getResolution00);
  tolua_function(tolua_S,"getUA",tolua_luaapi_getUA00);
  tolua_function(tolua_S,"getMetaData",tolua_luaapi_getMetaData00);
  tolua_function(tolua_S,"acquireWakeLock",tolua_luaapi_acquireWakeLock00);
  tolua_function(tolua_S,"releaseWakeLock",tolua_luaapi_releaseWakeLock00);
  tolua_function(tolua_S,"userActivity",tolua_luaapi_userActivity00);
  tolua_function(tolua_S,"getPackageVersion",tolua_luaapi_getPackageVersion00);
  tolua_function(tolua_S,"getPackageName",tolua_luaapi_getPackageName00);
  tolua_function(tolua_S,"getNetworkType",tolua_luaapi_getNetworkType00);
  tolua_function(tolua_S,"openURL",tolua_luaapi_openURL00);
  tolua_function(tolua_S,"receiptCallback",tolua_luaapi_receiptCallback00);
  tolua_function(tolua_S,"resendReceiptsValidation",tolua_luaapi_resendReceiptsValidation00);
  tolua_cclass(tolua_S,"AssetsManager","AssetsManager","",NULL);
  tolua_beginmodule(tolua_S,"AssetsManager");
   tolua_function(tolua_S,"SharedAssetsManager",tolua_luaapi_AssetsManager_SharedAssetsManager00);
   tolua_function(tolua_S,"Load",tolua_luaapi_AssetsManager_Load00);
   tolua_function(tolua_S,"fileExists",tolua_luaapi_AssetsManager_fileExists00);
   tolua_function(tolua_S,"getRealPath",tolua_luaapi_AssetsManager_getRealPath00);
   tolua_function(tolua_S,"getFileContent",tolua_luaapi_AssetsManager_getFileContent00);
   tolua_function(tolua_S,"getVersion",tolua_luaapi_AssetsManager_getVersion00);
   tolua_function(tolua_S,"getVersionName",tolua_luaapi_AssetsManager_getVersionName00);
   tolua_function(tolua_S,"supportAssetsUpgrade",tolua_luaapi_AssetsManager_supportAssetsUpgrade00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CCTexFontConfig","CCTexFontConfig","",NULL);
  tolua_beginmodule(tolua_S,"CCTexFontConfig");
   tolua_function(tolua_S,"sharedTexFontConfig",tolua_luaapi_CCTexFontConfig_sharedTexFontConfig00);
   tolua_function(tolua_S,"EnterBackground",tolua_luaapi_CCTexFontConfig_EnterBackground00);
   tolua_function(tolua_S,"EnterForeground",tolua_luaapi_CCTexFontConfig_EnterForeground00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"XLDrama","XLDrama","CCLayer",NULL);
  tolua_beginmodule(tolua_S,"XLDrama");
   tolua_function(tolua_S,"sharedDrama",tolua_luaapi_XLDrama_sharedDrama00);
   tolua_function(tolua_S,"purgeSharedDrama",tolua_luaapi_XLDrama_purgeSharedDrama00);
   tolua_function(tolua_S,"ShowDramaLua",tolua_luaapi_XLDrama_ShowDramaLua00);
   tolua_function(tolua_S,"exitFight",tolua_luaapi_XLDrama_exitFight00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SimpleAudioEngine","SimpleAudioEngine","",NULL);
  tolua_beginmodule(tolua_S,"SimpleAudioEngine");
   tolua_function(tolua_S,"stopAllEffects",tolua_luaapi_SimpleAudioEngine_stopAllEffects00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CHttpDownloader","CHttpDownloader","cocos2d::CCObject",NULL);
  tolua_beginmodule(tolua_S,"CHttpDownloader");
   tolua_function(tolua_S,"sharedHttpDownloader",tolua_luaapi_CHttpDownloader_sharedHttpDownloader00);
   tolua_function(tolua_S,"purgeSharedHttpDownloader",tolua_luaapi_CHttpDownloader_purgeSharedHttpDownloader00);
   tolua_function(tolua_S,"getContent",tolua_luaapi_CHttpDownloader_getContent00);
   tolua_function(tolua_S,"saveToFile",tolua_luaapi_CHttpDownloader_saveToFile00);
   tolua_function(tolua_S,"register_callback",tolua_luaapi_CHttpDownloader_register_callback00);
   tolua_function(tolua_S,"register_progress_callback",tolua_luaapi_CHttpDownloader_register_progress_callback00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"OpenPlatformLogin",tolua_luaapi_OpenPlatformLogin00);
  tolua_function(tolua_S,"OpenPayInterface",tolua_luaapi_OpenPayInterface00);
  tolua_function(tolua_S,"EnterPlatform",tolua_luaapi_EnterPlatform00);
  tolua_function(tolua_S,"GetSdkType",tolua_luaapi_GetSdkType00);
  tolua_cclass(tolua_S,"TLMaskLayer","TLMaskLayer","CCLayer",NULL);
  tolua_beginmodule(tolua_S,"TLMaskLayer");
   tolua_function(tolua_S,"sharedTLMaskLayer",tolua_luaapi_TLMaskLayer_sharedTLMaskLayer00);
   tolua_function(tolua_S,"resetMaskLayer",tolua_luaapi_TLMaskLayer_resetMaskLayer00);
   tolua_function(tolua_S,"setIsClickTest",tolua_luaapi_TLMaskLayer_setIsClickTest00);
   tolua_function(tolua_S,"setIsMaskScene",tolua_luaapi_TLMaskLayer_setIsMaskScene00);
   tolua_function(tolua_S,"setIsClickToContinue",tolua_luaapi_TLMaskLayer_setIsClickToContinue00);
   tolua_function(tolua_S,"appendHighlightRect",tolua_luaapi_TLMaskLayer_appendHighlightRect00);
   tolua_function(tolua_S,"appendHighlightRect",tolua_luaapi_TLMaskLayer_appendHighlightRect01);
   tolua_function(tolua_S,"renderMaskSprite",tolua_luaapi_TLMaskLayer_renderMaskSprite00);
   tolua_function(tolua_S,"setHitTestEnable",tolua_luaapi_TLMaskLayer_setHitTestEnable00);
   tolua_function(tolua_S,"resetHitTest",tolua_luaapi_TLMaskLayer_resetHitTest00);
   tolua_function(tolua_S,"appendHitTestRect",tolua_luaapi_TLMaskLayer_appendHitTestRect00);
   tolua_function(tolua_S,"setHitTestFuncCallback",tolua_luaapi_TLMaskLayer_setHitTestFuncCallback00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MainSceneRoleMC","MainSceneRoleMC","CCNode",NULL);
  tolua_beginmodule(tolua_S,"MainSceneRoleMC");
   tolua_variable(tolua_S,"mcBoundingBox",tolua_get_MainSceneRoleMC_mcBoundingBox,tolua_set_MainSceneRoleMC_mcBoundingBox);
   tolua_function(tolua_S,"createWithName",tolua_luaapi_MainSceneRoleMC_createWithName00);
   tolua_function(tolua_S,"playStand",tolua_luaapi_MainSceneRoleMC_playStand00);
   tolua_function(tolua_S,"playWalk",tolua_luaapi_MainSceneRoleMC_playWalk00);
   tolua_function(tolua_S,"setFrameRate",tolua_luaapi_MainSceneRoleMC_setFrameRate00);
   tolua_function(tolua_S,"setFlipX",tolua_luaapi_MainSceneRoleMC_setFlipX00);
   tolua_function(tolua_S,"setFlipY",tolua_luaapi_MainSceneRoleMC_setFlipY00);
   tolua_function(tolua_S,"getRoleSprite",tolua_luaapi_MainSceneRoleMC_getRoleSprite00);
   tolua_function(tolua_S,"setRoleSpriteOffsetX",tolua_luaapi_MainSceneRoleMC_setRoleSpriteOffsetX00);
   tolua_function(tolua_S,"getRoleSpriteOffsetX",tolua_luaapi_MainSceneRoleMC_getRoleSpriteOffsetX00);
   tolua_function(tolua_S,"setRoleSpriteOffsetY",tolua_luaapi_MainSceneRoleMC_setRoleSpriteOffsetY00);
   tolua_function(tolua_S,"getRoleSpriteOffsetY",tolua_luaapi_MainSceneRoleMC_getRoleSpriteOffsetY00);
   tolua_function(tolua_S,"resetRoleSpritePosition",tolua_luaapi_MainSceneRoleMC_resetRoleSpritePosition00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"exit",tolua_luaapi_exit00);
  tolua_function(tolua_S,"dump_rusage",tolua_luaapi_dump_rusage00);
  tolua_function(tolua_S,"dump_texture",tolua_luaapi_dump_texture00);
  tolua_function(tolua_S,"quitConfirm",tolua_luaapi_quitConfirm01);
  tolua_function(tolua_S,"quitApplication",tolua_luaapi_quitApplication00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_luaapi (lua_State* tolua_S) {
 return tolua_luaapi_open(tolua_S);
};
#endif

