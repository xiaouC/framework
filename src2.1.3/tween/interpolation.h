#pragma once
#include <math.h>

#ifdef WIN32
#define M_PI       3.14159265358979323846
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// linear
inline float interpolation_linear( float t, float b, float c, float d )
{
    return c * t / d + b;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// bounce
inline float interpolation_bounce_out( float t, float b, float c, float d )
{
    if( ( t /= d ) < ( 1.0f / 2.75f ) )
        return c * ( 7.5625f * t * t ) + b;

    if( t < ( 2.0f / 2.75f ) )
    {
        t -= ( 1.5f / 2.75f );
        return c * ( 7.5625f * t * t + 0.75f ) + b;
    }

    if( t < ( 2.5f / 2.75f ) )
    {
        t -= ( 2.25f / 2.75f );
        return c * ( 7.5625f * t * t + 0.9375f ) + b;
    }

    t -= ( 2.625f / 2.75f );
    return c * ( 7.5625f * t * t + 0.984375f ) + b;
}

inline float interpolation_bounce_in( float t, float b, float c, float d )
{
    return c - interpolation_bounce_out( d - t, 0, c, d ) + b;
}

inline float interpolation_bounce_in_out( float t, float b, float c, float d )
{
    if( t < d * 0.5f )
        return interpolation_bounce_in( t * 2, 0, c, d ) * 0.5f + b;

    return interpolation_bounce_out( t * 2.0f - d, 0, c, d ) * 0.5f + c * 0.5f + b;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// expo
inline float interpolation_expo_in( float t, float b, float c, float d )
{		
    return ( t == 0 ) ? b : c * pow( 2.0f, 10.0f * ( t / d - 1.0f ) ) + b - c * 0.001f;
}

inline float interpolation_expo_out( float t, float b, float c, float d )
{
    return ( t == d ) ? b + c : c * ( -pow( 2.0f, -10.0f * t / d ) + 1.0f ) + b;
}

inline float interpolation_expo_in_out( float t, float b, float c, float d )
{
    if( t == 0 )
        return b;

    if( t == d )
        return b + c;

    if( ( t /= d * 0.5f ) < 1.0f )
        return c * 0.5f * pow( 2.0f, 10.0f * ( t - 1.0f ) ) + b;

    return c * 0.5f * ( -pow( 2.0f, -10.0f * --t ) + 2 ) + b;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// elastic
const float _2PI = (float)(M_PI * 2.f);
const float _a = 0.f;
const float _p = 0.f;
inline float interpolation_elastic_in( float t, float b, float c, float d )
{
    float s = 0, p = _p, a = _a;
    if( t == 0 ) return b;

    if( ( t /= d ) == 1.0f ) return b+c;

    if( !p ) p = d * 0.3f;

    if( !a || ( c > 0 && a < c ) || ( c < 0 && a < -c ) )
    {
        a = c;
        s = p / 4.0f;
    }
    else
    {
        s = p/_2PI * asin (c/a);
    }

    t -= 1.0f;
    return -( a * pow( 2.0f, 10.0f * t ) * sin( ( t * d - s ) * _2PI / p ) ) + b;
}

inline float interpolation_elastic_out( float t, float b, float c, float d )
{
    float s = 0, p = _p, a = _a;
    if( t == 0 ) return b;

    if( ( t /= d ) == 1 ) return b + c;

    if( !p ) p = d * 0.3f;

    if( !a || ( c > 0 && a < c ) || ( c < 0 && a < -c ) )
    {
        a = c;
        s = p / 4.0f;
    }
    else
    {
        s = p / _2PI * asin( c / a );
    }

    return ( a * pow( 2.0f, -10.0f * t ) * sin( ( t * d - s ) * _2PI / p ) + c + b );
}

inline float interpolation_elastic_in_out( float t, float b, float c, float d )
{
    float s = 0, p = _p, a = _a;
    if( t == 0 ) return b;

    if( ( t /= d * 0.5f ) == 2 ) return b + c;

    if( !p ) p = d * ( 0.3f * 1.5f );

    if( !a || ( c > 0 && a < c ) || ( c < 0 && a < -c ) )
    {
        a = c;
        s = p / 4.0f;
    }
    else
    {
        s = p / _2PI * asin( c / a );
    }

    if( t < 1 )
    {
        t -= 1.0f;
        return -0.5f * ( a * pow( 2.0f, 10.0f * t ) * sin( ( t * d - s ) * _2PI / p ) ) + b;
    }

    t -= 1.0f;
    return a * pow( 2.0f, -10.0f * t ) * sin( ( t * d - s ) * _2PI / p ) * 0.5f + c + b;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// quart
inline float interpolation_quart_in( float t, float b, float c, float d )
{
    t /= d;
    return c * t * t * t * t + b;
}

inline float interpolation_quart_out( float t, float b, float c, float d )
{
    t = t / d - 1.0f;
    return -c * ( t * t * t * t - 1 ) + b;
}

inline float interpolation_quart_in_out( float t, float b, float c, float d )
{
    t /= d * 0.5f;
    if( t < 1 )
        return c * 0.5f * t * t * t * t + b;

    t -= 2.0f;
    return -c * 0.5f * ( t * t * t * t - 2.0f ) + b;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// quint
inline float interpolation_quint_in( float t, float b, float c, float d )
{
    t /= d;
    return c * t * t * t * t * t + b;
}

inline float interpolation_quint_out( float t, float b, float c, float d )
{
    t = t / d - 1.0f;
    return c * ( t * t * t * t * t + 1.0f ) + b;
}

inline float interpolation_quint_in_out( float t, float b, float c, float d )
{
    t /= d * 0.5f;
    if( t < 1.0f )
        return c * 0.5f * t * t * t * t * t + b;

    t -= 2.0f;
    return c * 0.5f * ( t * t * t * t * t + 2.0f ) + b;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// quad
inline float interpolation_quad_in( float t, float b, float c, float d )
{
    t /= d;
    return c * t * t + b;
}

inline float interpolation_quad_out( float t, float b, float c, float d )
{
    t /= d;
    return -c * t * ( t - 2.0f ) + b;
}

inline float interpolation_quad_in_out( float t, float b, float c, float d )
{
    t /= d * 0.5f;
    if( t < 1.0f )
        return c * 0.5f * t * t + b;

    --t;
    return -c * 0.5f * ( t * ( t - 2.0f ) - 1.0f ) + b;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// back
const float back_power = 1.70158f;
inline float interpolation_back_in( float t, float b, float c, float d )
{
    float s = back_power;
    t /= d;
    return c * t * t * ( ( s + 1.0f ) * t - s ) + b;
}

inline float interpolation_back_out( float t, float b, float c, float d )
{
    float s = back_power;
    t = t / d - 1.0f;
    return c * ( t * t * ( ( s + 1.0f ) * t + s ) + 1.0f ) + b;
}

inline float interpolation_back_in_out( float t, float b, float c, float d )
{
    float s = back_power * 1.525f;
    t /= d * 0.5f;
    if( t < 1.0f )
        return c * 0.5f * ( t * t * ( ( s + 1.0f ) * t - s ) ) + b;

    t -= 2.0f;
    return c / 2.0f * ( t * t * ( ( s + 1.0f ) * t + s ) + 2.0f ) + b;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// cubic
inline float interpolation_cubic_in( float t, float b, float c, float d )
{
    t /= d;
    return c * t * t * t + b;
}

inline float interpolation_cubic_out( float t, float b, float c, float d )
{
    t = t / d - 1.0f;
    return c * ( t * t * t + 1.0f ) + b;
}

inline float interpolation_cubic_in_out( float t, float b, float c, float d )
{
    t /= d * 0.5f;
    if( t < 1.0f )
        return c * 0.5f * t * t * t + b;

    t -= 2.0f;
    return c * 0.5f * ( t * t * t + 2.0f ) + b;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// strong
inline float interpolation_strong_in( float t, float b, float c, float d )
{
    t /= d;
    return c * t * t * t * t * t + b;
}

inline float interpolation_strong_out( float t, float b, float c, float d )
{
    t = t / d - 1.0f;
    return c * ( t * t * t * t * t + 1.0f ) + b;
}

inline float interpolation_strong_in_out( float t, float b, float c, float d )
{
    t /= d * 0.5f;
    if( t < 1.0f )
        return c * 0.5f * t * t * t * t * t + b;

    t -= 2.0f;
    return c * 0.5f * ( t * t * t * t * t + 2.0f ) + b;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// circ
inline float interpolation_circ_in( float t, float b, float c, float d )
{
    t /= d;
    return -c * ( sqrt( 1.0f - t * t ) - 1.0f ) + b;
}

inline float interpolation_circ_out( float t, float b, float c, float d )
{
    t = t / d - 1.0f;
    return c * sqrt( 1.0f - t * t ) + b;
}

inline float interpolation_circ_in_out( float t, float b, float c, float d )
{
    t /= d * 0.5f;
    if( t < 1.0f )
        return -c * 0.5f * ( sqrt( 1.0f - t * t ) - 1.0f ) + b;

    t -= 2.0f;
    return c * 0.5f * ( sqrt( 1.0f - t * t ) + 1.0f ) + b;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// sine
const float _HALF_PI = M_PI * 0.5f;
inline float interpolation_sine_in( float t, float b, float c, float d )
{
    return -c * cos( t / d * _HALF_PI ) + c + b;
}

inline float interpolation_sine_out( float t, float b, float c, float d )
{
    return c * sin( t / d * _HALF_PI ) + b;
}

inline float interpolation_sine_in_out( float t, float b, float c, float d )
{
    return -c * 0.5f * ( cos ( M_PI * t / d ) - 1.0f ) + b;
}


