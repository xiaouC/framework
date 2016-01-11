#pragma once
#include "cocos2d.h"

USING_NS_CC;

class CCActionLuaCallFunc : public CCActionInstant
{
public:
    CCActionLuaCallFunc();
    virtual ~CCActionLuaCallFunc();

    virtual void execute();
    virtual void update( float time );

public:
    static CCActionLuaCallFunc* create( int nHandler );

protected:
    int m_nScriptHandler;
};

