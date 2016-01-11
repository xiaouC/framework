#include "CCActionExtend.h"
#include "CCLuaEngine.h"

CCActionLuaCallFunc::CCActionLuaCallFunc()
: m_nScriptHandler(0)
{
}

CCActionLuaCallFunc::~CCActionLuaCallFunc()
{
    if( m_nScriptHandler > 0 )
    {
        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nScriptHandler );
        m_nScriptHandler = 0;
    }
}

void CCActionLuaCallFunc::execute()
{
    if( m_nScriptHandler > 0 )
        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nScriptHandler, 0 );
}

void CCActionLuaCallFunc::update( float time )
{
    CC_UNUSED_PARAM( time );
    execute();
}

CCActionLuaCallFunc* CCActionLuaCallFunc::create( int nHandler )
{
    CCActionLuaCallFunc* pRet = new CCActionLuaCallFunc;
    if( pRet )
    {
        pRet->m_nScriptHandler = nHandler;
        pRet->autorelease();

        return pRet;
    }

    CC_SAFE_DELETE( pRet );

    return NULL;
}


