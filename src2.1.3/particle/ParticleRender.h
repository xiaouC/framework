//
//  ParticleRender.h
//  Stoneage
//
//  Created by gamebean on 12-12-6.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_ParticleRender_h
#define Stoneage_ParticleRender_h
#include "./util/Stream.h"

// 渲染属性 
class ParticleRender
{
public:
    ParticleRender();
    ~ParticleRender();
    
public:
    void Load(particle::InputStream& is);
    void OnRender(float ft);
    
    particle::CONSTANT_Utf8 textureName;    //纹理名称     
    short sourceFactor;		//源因子 
    short destinationFactor;	//目标因子     
    bool absoluteParticleAngle;  //是否面向摄像机 
    
    short cutW;
    short cutH;
    short delay;
    bool  uRepeat;
    bool  vRepeat;
    float uSpeed;
    float vSpeed;
    float uOffset;
    float vOffset;
    bool repeatPlay;
    float rotateSpeed;    
	float rotateDegree;
};

#endif
