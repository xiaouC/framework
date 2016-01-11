//
//  GeneratorData.h
//  Stoneage
//
//  Created by gamebean on 12-12-11.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_GeneratorData_h
#define Stoneage_GeneratorData_h

#include "Particle.h"
#include "./space/GeneratorSpace.h"
#include "./space/ParticleSpace.h"
#include "GeneratorBehaviour.h"
#include "ParticleBehaviour.h"
#include "ParticleRender.h"
#include "./modifier/Modifier.h"
#include "./util/Stream.h"

class GeneratorData
{
public:
    GeneratorData();
    ~GeneratorData();
public:
    void Load(particle::InputStream& is);      //载入发射器数据 
    
public:   
    particle::CONSTANT_Utf8            name;
    bool                     isRendToWorld;
    std::vector<GeneratorSpace*>  allSpace;//粒子空间 
    GeneratorBehaviour*      gb;      //发射器属性组 
    ParticleBehaviour*       pb;      //粒子属性组 
    ParticleRender*          pr;      //发射器渲染属性 
    std::vector<Modifier*>        md;      //修改器 
    
    bool                     noColor;
    
};


#endif
