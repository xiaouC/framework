#include "../tween/TLTweenManager.h"
#include <CCCommon.h>
#include <CCDirector.h>
#include "CCLuaEngine.h"

USING_NS_CC;

TLTweenManager* g_pTLTweenManager = NULL;
TLTweenManager* TLTweenManager::sharedTLTweenManager()
{
    return g_pTLTweenManager;
}

TLTweenManager::TLTweenManager()
: m_nNextTweenHandle(0)
{
    g_pTLTweenManager = this;

    m_mapInterpolationFunc[LINEAR_IN] = interpolation_linear;
    m_mapInterpolationFunc[LINEAR_OUT] = interpolation_linear;
    m_mapInterpolationFunc[LINEAR_INOUT] = interpolation_linear;

    m_mapInterpolationFunc[BOUNCE_IN] = interpolation_bounce_in;
    m_mapInterpolationFunc[BOUNCE_OUT] = interpolation_bounce_out;
    m_mapInterpolationFunc[BOUNCE_INOUT] = interpolation_bounce_in_out;

    m_mapInterpolationFunc[EXPO_IN] = interpolation_expo_in;
    m_mapInterpolationFunc[EXPO_OUT] = interpolation_expo_out;
    m_mapInterpolationFunc[EXPO_INOUT] = interpolation_expo_in_out;

    m_mapInterpolationFunc[ELASTIC_IN] = interpolation_elastic_in;
    m_mapInterpolationFunc[ELASTIC_OUT] = interpolation_elastic_out;
    m_mapInterpolationFunc[ELASTIC_INOUT] = interpolation_elastic_in_out;

    m_mapInterpolationFunc[QUART_IN] = interpolation_quart_in;
    m_mapInterpolationFunc[QUART_OUT] = interpolation_quart_out;
    m_mapInterpolationFunc[QUART_INOUT] = interpolation_quart_in_out;

    m_mapInterpolationFunc[QUINT_IN] = interpolation_quint_in;
    m_mapInterpolationFunc[QUINT_OUT] = interpolation_quint_out;
    m_mapInterpolationFunc[QUINT_INOUT] = interpolation_quint_in_out;

    m_mapInterpolationFunc[QUAD_IN] = interpolation_quad_in;
    m_mapInterpolationFunc[QUAD_OUT] = interpolation_quad_out;
    m_mapInterpolationFunc[QUAD_INOUT] = interpolation_quad_in_out;

    m_mapInterpolationFunc[BACK_IN] = interpolation_back_in;
    m_mapInterpolationFunc[BACK_OUT] = interpolation_back_out;
    m_mapInterpolationFunc[BACK_INOUT] = interpolation_back_in_out;

    m_mapInterpolationFunc[STRONG_IN] = interpolation_strong_in;
    m_mapInterpolationFunc[STRONG_OUT] = interpolation_strong_out;
    m_mapInterpolationFunc[STRONG_INOUT] = interpolation_strong_in_out;

    m_mapInterpolationFunc[CIRC_IN] = interpolation_circ_in;
    m_mapInterpolationFunc[CIRC_OUT] = interpolation_circ_out;
    m_mapInterpolationFunc[CIRC_INOUT] = interpolation_circ_in_out;

    m_mapInterpolationFunc[SINE_IN] = interpolation_sine_in;
    m_mapInterpolationFunc[SINE_OUT] = interpolation_sine_out;
    m_mapInterpolationFunc[SINE_INOUT] = interpolation_sine_in_out;
}

TLTweenManager::~TLTweenManager()
{
    g_pTLTweenManager = NULL;

    removeAllTween();
}

void TLTweenManager::update( float dt )
{
    bool bIsPause = CCDirector::sharedDirector()->isPaused();

    std::map<int,TweenData*>::iterator iter = m_mapTweenList.begin();
    for( ; iter != m_mapTweenList.end(); )
    {
        TweenData* pTweenData = iter->second;
        if( bIsPause && !pTweenData->bIsPause )
        //if( pTweenData->bIsPause != bIsPause )
        {
            ++iter;

            continue;
        }

        if( pTweenData->bDelete )
        {
            delete pTweenData;

            m_mapTweenList.erase( iter++ );

            continue;
        }

        // 
        ++iter;

        // 
        pTweenData->tick += dt;
        if( pTweenData->tick < pTweenData->delay )
            continue;

        // 
        float elapsed = ( pTweenData->tick - pTweenData->delay < pTweenData->duration ) ? ( pTweenData->tick - pTweenData->delay ) : pTweenData->duration;
        float val = pTweenData->duration <= 0.0f ? pTweenData->to : pTweenData->func( elapsed, pTweenData->from, pTweenData->to - pTweenData->from, pTweenData->duration );

		CCLuaEngine::defaultEngine()->getLuaStack()->pushFloat( val );
        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( pTweenData->nSeterHandler, 1 );

        if( pTweenData->tick - pTweenData->delay >= pTweenData->duration )
        {
            CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( pTweenData->nEndHandler, 0 );

            // 循环次数减 1
            if( pTweenData->nLoopCount > 0 )
                --pTweenData->nLoopCount;

            // 结束
            if( pTweenData->nLoopCount == 0 )
            {
                pTweenData->bDelete = true;

                continue;
            }

            pTweenData->tick = pTweenData->tick - ( pTweenData->delay + pTweenData->duration );
            pTweenData->delay = pTweenData->interval;
        }
    }
}

int TLTweenManager::tweenFromTo( TWEEN_INTERPOLATION_TYPE type, float delay, float duration, float interval, float from, float to, int loopCount,
            int nSeterHandler, int nEndHandler )
{
    std::map<TWEEN_INTERPOLATION_TYPE,InterpolationFunc>::iterator iter = m_mapInterpolationFunc.find( type );
    if( iter == m_mapInterpolationFunc.end() )
        return -1;

    int nTweenHandle = getNextTweenHandle();

    TweenData* pTweenData = new TweenData;
    pTweenData->bIsPause = CCDirector::sharedDirector()->isPaused();
    pTweenData->func = iter->second;
    pTweenData->delay = delay;
    pTweenData->duration = duration;
    pTweenData->interval = interval;
    pTweenData->from = from;
    pTweenData->to = to;
    pTweenData->nLoopCount = loopCount;
    pTweenData->nSeterHandler = nSeterHandler;
    pTweenData->nEndHandler = nEndHandler;

    pTweenData->tick = 0;
    pTweenData->bDelete = false;

    m_mapTweenList[nTweenHandle] = pTweenData;

    return nTweenHandle;
}

void TLTweenManager::removeTween( int nTweenHandle )
{
    std::map<int,TweenData*>::iterator iter = m_mapTweenList.find( nTweenHandle );
    if( iter != m_mapTweenList.end() )
        iter->second->bDelete = true;
}

void TLTweenManager::removeAllTween()
{
    std::map<int,TweenData*>::iterator iter = m_mapTweenList.begin();
    std::map<int,TweenData*>::iterator iter_end = m_mapTweenList.end();
    for( ; iter != iter_end; ++iter )
        delete iter->second;
    m_mapTweenList.clear();
}
