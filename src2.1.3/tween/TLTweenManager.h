#pragma once
#include <map>

enum TWEEN_INTERPOLATION_TYPE
{
    LINEAR_IN,	//!< 线性 
    LINEAR_OUT,
    LINEAR_INOUT,

    BOUNCE_IN,	//!< 弹性 
    BOUNCE_OUT,
    BOUNCE_INOUT,

    EXPO_IN,	//!< 减速 
    EXPO_OUT,
    EXPO_INOUT,

    ELASTIC_IN,	//!< 弹性 
    ELASTIC_OUT,
    ELASTIC_INOUT,

    QUART_IN,	//!< 减速 
    QUART_OUT,
    QUART_INOUT,

    QUINT_IN,	//!< 减速 
    QUINT_OUT,
    QUINT_INOUT,

    QUAD_IN,	//!< 减速 
    QUAD_OUT,
    QUAD_INOUT,

    BACK_IN,	//!< 减速（带返回） 
    BACK_OUT,
    BACK_INOUT,

    CUBIC_IN,	//!< 减速 
    CUBIC_OUT,
    CUBIC_INOUT,

    STRONG_IN,	//!< 减速 
    STRONG_OUT,
    STRONG_INOUT,

    CIRC_IN,	//!< 减速（快） 
    CIRC_OUT,
    CIRC_INOUT,

    SINE_IN,	//!< 减速（慢） 
    SINE_OUT,
    SINE_INOUT,
};

typedef float ( *InterpolationFunc )( float t, float b, float c, float d );
class TLTweenManager
{
public:
    TLTweenManager();
    virtual ~TLTweenManager();

	static TLTweenManager* sharedTLTweenManager();

	void update( float dt );

public:
    int tweenFromTo( TWEEN_INTERPOLATION_TYPE type, float delay, float duration, float interval, float from, float to, int loopCount,
            int nSeterHandler, int nEndHandler );
    void removeTween( int nTweenHandle );
    void removeAllTween();

protected:
    int m_nNextTweenHandle;
    int getNextTweenHandle() { return ++m_nNextTweenHandle; }

    std::map<TWEEN_INTERPOLATION_TYPE,InterpolationFunc> m_mapInterpolationFunc;

protected:
    struct TweenData
    {
        bool bIsPause;
        InterpolationFunc func;
        float delay;
        float duration;
        float interval;
        float from;
        float to;
        int nLoopCount;
        int nGeterHandler;
        int nSeterHandler;
        int nEndHandler;

        float tick;
        bool bDelete;
    };
    std::map<int,TweenData*> m_mapTweenList;
};

#include "interpolation.h"
