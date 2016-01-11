//
//  Util.cpp
//  Stoneage
//
//  Created by fanxiaoli on 12-12-9.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <stdlib.h>
#include <iostream>
#include "Common/TLCommon.h"
#include "Util.h"
#include "ValueList.h"

float ParticleUtil::randPool[MAX_FLOAT_COUNT];

void ParticleUtil::InitUtil()
{
    for(int i = 0; i < MAX_FLOAT_COUNT; i ++){
        randPool[i] = CreateRandFloat();
    }
}

//对float v1 对 float v2取余数 
float ParticleUtil::RemFloat(float v1, float v2)
{
    return v1 - ((float)(int)(v1 / v2) * v2);
}
//(0-end)float随机数 
float ParticleUtil::RandFloat(float end)
{
    double temp = RandFloat() * end;
    return (float)temp;
}
//(0-1)float随机数 
float ParticleUtil::RandFloat()
{
    double temp = randPool[XL_RANDOM() % MAX_FLOAT_COUNT];;
    return (float)temp;
}
//(begin-end)float随机数 
float ParticleUtil::RandFloat(float begin, float end)
{
    double temp = begin + RandFloat(end - begin);
    return (float)temp;
}

float ParticleUtil::CreateRandFloat(float end)
{
    double temp = (double)(XL_RANDOM() * end) / (double)RAND_MAX;
    return (float)temp;
}

float ParticleUtil::CreateRandFloat()
{
    double temp = (float)XL_RANDOM() / (float)RAND_MAX;
    return (float)temp;
}

float ParticleUtil::CreateRandFloat(float begin, float end)
{
    double temp = begin + CreateRandFloat(end - begin);
    return (float)temp;
}

// 旋转X----------------------------------- 
void rotateOnX(Vector3f& position, float angle) {
    
    float y = cosf(angle) * position.GetY() - sinf(angle)
    * position.GetZ();
    
    float z = sinf(angle) * position.GetY() + cosf(angle)
    * position.GetZ();
    
    position.SetY(y);
    position.SetZ(z);
}

// 旋转Y--------------------------------- 
void rotateOnY(Vector3f& position, float angle) {
    float x = cosf(angle) * position.GetX() + sinf(angle)
    * position.GetZ();
    
    float z = -sinf(angle) * position.GetX() + cosf(angle)
    * position.GetZ();
    
    position.SetX(x);
    position.SetZ(z);
}

// 旋转Z--------------------------------- 
void rotateOnZ(Vector3f& position, float angle) {
    float x = cosf(angle) * position.GetX() - sinf(angle)
    * position.GetY();
    
    float y = sinf(angle) * position.GetX() + cosf(angle)
    * position.GetY();
    
    position.SetY(y);
    position.SetX(x);
}

// 根据旋转指定点--------------------------------- 
void ParticleUtil::rotateOnAngleVector(Vector3f& position, float angleX, float angleY, float angleZ) {
    rotateOnX(position, angleX);
    rotateOnY(position, angleY);
    rotateOnZ(position, angleZ);
}

void ParticleUtil::rotate2f(Vector3f& v, float angle) {
    float tempX = v.GetX() * cosf(angle) - v.GetY() * sinf(angle);
    float tempY = v.GetX() * sinf(angle) + v.GetY() * cosf(angle);
    v.SetX(tempX);
    v.SetY(tempY);
}

void ParticleUtil::rotate2f(Vector2f& v, float angle) {
    float tempX = v.x * cosf(angle) - v.y * sinf(angle);
    float tempY = v.x * sinf(angle) + v.y * cosf(angle);
    v.x = tempX;
    v.y = tempY;
}
