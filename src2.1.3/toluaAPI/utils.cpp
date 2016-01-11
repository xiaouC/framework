#include "MC/AssetsManager.h"
#include "tolua++.h"
#include "ccMacros.h"
#include "SimpleAudioEngine.h"

static int lua_getFileData(lua_State* tolua_S)
{
    const char* name = tolua_tostring(tolua_S,1,0);
    const char* mode = tolua_tostring(tolua_S,2,0);
    if (mode==NULL)
    {
        mode = "rb";
    }
    unsigned long size=0;
    const char* buffer = (const char*)AssetsManager::sharedAssetsManager()->getFileContent(name, mode, &size);
    if (buffer==NULL)
    {
        tolua_error(tolua_S,"open file failed",NULL);
        return 0;
    }
    lua_pushlstring(tolua_S, buffer, size);
    delete[] buffer;
    //tolua_pushuserdata(tolua_S, buffer);
    //lua_pushinteger(tolua_S, size);
    return 1;
}

static int lua_getAssetsData(lua_State* tolua_S)
{
    const char* name = tolua_tostring(tolua_S,1,0);
    const char* mode = tolua_tostring(tolua_S,2,0);
    if (mode==NULL)
    {
        mode = "rb";
    }
    unsigned long size=0;
    const char* buffer = (const char*)AssetsManager::loadAssetFile(name, mode, &size);
    if (buffer==NULL)
    {
        CCLOGERROR("open file failed");
        return 0;
    }
    lua_pushlstring(tolua_S, buffer, size);
    delete[] buffer;
    //tolua_pushuserdata(tolua_S, buffer);
    //lua_pushinteger(tolua_S, size);
    return 1;
}

static int lua_getExternalData(lua_State* tolua_S)
{
    const char* name = tolua_tostring(tolua_S,1,0);
    const char* mode = tolua_tostring(tolua_S,2,0);
    if (mode==NULL)
    {
        mode = "rb";
    }
    unsigned long size=0;
    const char* buffer = (const char*)AssetsManager::loadExternalFile(name, mode, &size);
    if (buffer==NULL)
    {
        CCLOGERROR("open file failed");
        return 0;
    }
    lua_pushlstring(tolua_S, buffer, size);
    delete[] buffer;
    //tolua_pushuserdata(tolua_S, buffer);
    //lua_pushinteger(tolua_S, size);
    return 1;
}

static int lua_getPackageData(lua_State* tolua_S)
{
    const char* name = tolua_tostring(tolua_S,1,0);
    const char* mode = tolua_tostring(tolua_S,2,0);
    if (mode==NULL)
    {
        mode = "rb";
    }
    unsigned long size=0;
    const char* buffer = (const char*)AssetsManager::loadPackageFile(name, mode, &size);
    if (buffer==NULL)
    {
        CCLOGERROR("open file failed");
        return 0;
    }
    lua_pushlstring(tolua_S, buffer, size);
    delete[] buffer;
    //tolua_pushuserdata(tolua_S, buffer);
    //lua_pushinteger(tolua_S, size);
    return 1;
}

static int lua_CCAssert(lua_State* tolua_S)
{
    bool cond = tolua_toboolean(tolua_S,1,0);
    const char* msg = tolua_tostring(tolua_S,2,0);
    CCAssert(cond, msg);
    lua_pushnil(tolua_S);
    return 1;
}

static int lua_setAlterMusicPlayer(lua_State* tolua_S)
{
    bool b = tolua_toboolean(tolua_S,1,0);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->setAlterMusicPlayer(b);
    lua_pushnil(tolua_S);
    return 1;
}

static int lua_getCurrentTime(lua_State* tolua_S)
{
    struct cc_timeval now;
    CCTime::gettimeofdayCocos2d(&now, NULL);
    lua_pushnumber(tolua_S, now.tv_sec + (double)now.tv_usec / 1000000);
    return 1;
}

//extern "C" {
//    int snapshot(lua_State*);
//}

TOLUA_API int tolua_utils_open (lua_State* tolua_S)
{
    tolua_open(tolua_S);
    tolua_module(tolua_S,NULL,0);
    tolua_beginmodule(tolua_S,NULL);
    tolua_function(tolua_S, "getFileData", lua_getFileData);
    tolua_function(tolua_S, "getAssetsData", lua_getAssetsData);
    tolua_function(tolua_S, "getExternalData", lua_getExternalData);
    tolua_function(tolua_S, "getPackageData", lua_getPackageData);
    tolua_function(tolua_S, "CCAssert", lua_CCAssert);
    tolua_function(tolua_S, "setAlterMusicPlayer", lua_setAlterMusicPlayer);
    tolua_function(tolua_S, "getCurrentTime", lua_getCurrentTime);
 //   tolua_function(tolua_S, "snapshot", snapshot);
    tolua_endmodule(tolua_S);
    return 1;
}
