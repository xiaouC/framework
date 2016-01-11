//
//  ParticleBehaviour.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-6.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "ParticleBehaviour.h"
#include "Particle.h"

ParticleBehaviour::ParticleBehaviour()
{
    isAutoAngle = false;            //自动调整角度 
    killParticles = true; //生命周期后是否杀死粒子 
    particleMaxlife = 1; //粒子的生命周期--- 
    
    //初始化各属性列表，保证至少有一个关键帧，防止取值是报错 
    alpha.SetFirstValue(1);				//透明属性组* 
    color.SetFirstValue(1, 1, 1);		//颜色属性组* 
    mass.SetFirstValue(0);				//重量属性组* 
    spin.SetFirstValue(0);				//角度增量属性组* 
    angle.SetFirstValue(0);				//角度属性组* 
    size.SetFirstValue(1);				//大小属性组* 
    elasticity.SetFirstValue(0);		//弹力属性组* 
    particleAngleV.SetFirstValue(0);	//纵向角度属性组* 
    particleAngleH.SetFirstValue(0);	//横向角度属性组* 
    particleSpinV.SetFirstValue(0);		//纵向角度增量属性组* 
    particleSpinH.SetFirstValue(0);		//横向角度增量属性组* 
    width.SetFirstValue(1);				//宽度属性组* 
    height.SetFirstValue(1);			//高度属性组* 
    speed.SetFirstValue(30);			//速度属性组* 
    texWidth.SetFirstValue(1);			//纹理宽度属性组* 
    texHeight.SetFirstValue(1);			//纹理高度属性组* 
}

ParticleBehaviour::~ParticleBehaviour()
{
    
}

void ParticleBehaviour::Load(particle::InputStream &is)
{
    killParticles = is.ReadBoolean(); //生命周期后是否杀死粒子 
    particleMaxlife = ParticleUtil::Float_Java2C(is.ReadFloat()); //粒子的生命周期--- 
    isAutoAngle=is.ReadBoolean();
    alpha.ReadList(is);				//透明属性组* 
    color.ReadList(is);				//颜色属性组* 
    mass.ReadList(is);				//重量属性组* 
    spin.ReadList(is);				//角度增量属性组* 
    angle.ReadList(is);				//角度属性组* 
    size.ReadList(is);				//大小属性组* 
    elasticity.ReadList(is);			//弹力属性组* 
    particleAngleV.ReadList(is);		//纵向角度属性组* 
    particleAngleH.ReadList(is);		//横向角度属性组* 
    particleSpinV.ReadList(is);		//纵向角度增量属性组* 
    particleSpinH.ReadList(is);		//横向角度增量属性组* 
    width.ReadList(is);				//宽度属性组* 
    height.ReadList(is);				//高度属性组* 
    speed.ReadList(is);				//速度属性组* 
    texWidth.ReadList(is);			//纹理宽度属性组* 
    texHeight.ReadList(is);			//纹理高度属性组* 
}

void ParticleBehaviour::OnUpdate(std::vector<Particle*>& particles)
{
    int size = particles.size();
    for (int i = 0; i < size; i++) {
        Particle* p = particles[i];
        if(p != NULL){
            p->OnUpdate(this);
        }
    }
}

void ParticleBehaviour::SetResolution(int resolution)
{  
    alpha.SetResolution(resolution);
    color.SetResolution(resolution);
    mass.SetResolution(resolution);
    spin.SetResolution(resolution);
    angle.SetResolution(resolution);
    size.SetResolution(resolution);
    elasticity.SetResolution(resolution);
    particleAngleV.SetResolution(resolution);
    particleAngleH.SetResolution(resolution);
    particleSpinV.SetResolution(resolution);
    particleSpinH.SetResolution(resolution);
    width.SetResolution(resolution);
    height.SetResolution(resolution);
    speed.SetResolution(resolution);
    texWidth.SetResolution(resolution);
    texHeight.SetResolution(resolution);
}

