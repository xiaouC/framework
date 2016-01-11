//
//  GeneratorBehaviour.cpp
//  Stoneage
//
//  Created by landye on 12-12-3.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include "GeneratorBehaviour.h"
#include "Generator.h"
#include "stdlib.h"
GeneratorBehaviour::GeneratorBehaviour()
{
    number = 50; 		//最大的粒子数        
    lifeTime = 2.0; 	//该发射器的生命周期        
    bias = 0;         //发射器偏移时间---------------        
    repeat = true;     	//是否循环播放-----------------        
    regenerateParticles = true; 	//是否重复生成粒子
    
    //初始化各属性列表，保证至少有一个关键帧，防止取值是报错
    alpha.SetFirstValue(1);				//透明属性组*
    color.SetFirstValue(1, 1, 1);		//颜色属性组*
    mass.SetFirstValue(0);				//重量属性组*
    spin.SetFirstValue(0);				//角度增量属性组*
    angle.SetFirstValue(0);				//角度属性组*
    size.SetFirstValue(2);				//大小属性组*
    elasticity.SetFirstValue(0);		//弹力属性组*
    particleAngleV.SetFirstValue(0);	//纵向角度属性组*
    particleAngleH.SetFirstValue(0);	//横向角度属性组*
    particleSpinV.SetFirstValue(0);		//纵向角度增量属性组*
    particleSpinH.SetFirstValue(0);		//横向角度增量属性组*
    width.SetFirstValue(1);				//宽度属性组*
    height.SetFirstValue(1);			//高度属性组*
    speed.SetFirstValue(0);			//速度属性组*
    texWidth.SetFirstValue(1);			//纹理宽度属性组*
    texHeight.SetFirstValue(1);			//纹理高度属性组*
    
    life.SetFirstValue(1);              //生命周期属性组*
    rate.SetFirstValue(5);              //发射速率属性组*
    angleV.SetFirstValue(0);			//纵向分发射角度属性组*
    angleH.SetFirstValue(0);			//横向发射角度属性组*
    spinV.SetFirstValue(0);				//纵向角度增量属性组*
    spinH.SetFirstValue(0);				//横向角度属性组*
    
}

GeneratorBehaviour::~GeneratorBehaviour()
{
    
}

void GeneratorBehaviour::Load(particle::InputStream &is)
{
    number = is.ReadShort();    //允许发射的最大粒子数量
    lifeTime = ParticleUtil::Float_Java2C(is.ReadFloat());//发射器的周期
    bias = ParticleUtil::Float_Java2C(is.ReadFloat());	//发射器的偏移时间
    repeat = is.ReadBoolean(); //发射器是否重复发射
    regenerateParticles = is.ReadBoolean();//是否重复生成粒子
    
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
    
    life.ReadList(is);			//生命周期属性组*
    rate.ReadList(is);			//发射速率属性组*
    angleV.ReadList(is);			//纵向分发射角度属性组*
    angleH.ReadList(is);			//横向发射角度属性组*
    spinV.ReadList(is);			//纵向角度增量属性组*
    spinH.ReadList(is);			//横向角度属性组*
}

void GeneratorBehaviour::OnUpdate(Generator* generator, float time, float timelapse)
{
    FloatValue fv;
    rate.GetValueAt(time, fv);
    generator->currentRate = fv.Get();
    
    spinH.GetValueAt(time, fv);
    float currentSpinH = fv.Get();
    spinV.GetValueAt(time, fv);
    float currentSpinV = fv.Get();

    float oldSpinV=generator->genSpinV;
    float oldSpinH=generator->genSpinH;
    
    oldSpinV+=currentSpinV*timelapse;
    oldSpinH+=currentSpinH*timelapse;
    
    if(oldSpinV >= 360){        
        oldSpinV = ParticleUtil::RemFloat(oldSpinV, 360);
    }else{
        if(oldSpinV <- 360){
            oldSpinV = -ParticleUtil::RemFloat(oldSpinV, 360);
        }
    }
    
    if(oldSpinH>=360){
        oldSpinH = ParticleUtil::RemFloat(oldSpinH, 360);
    }else{
        if(oldSpinH<-360){
            oldSpinH=-ParticleUtil::RemFloat(oldSpinH, 360);
        }
    }
    
    generator->genSpinV=oldSpinV;
    generator->genSpinH=oldSpinH;
}

void GeneratorBehaviour::InitParticle(Generator* generator ,Particle* p, float time) {
    p->age = 0.0f;
    
    FloatValue fv;
    angleH.GetValueAt(time, fv);
    float vangleH = fv.Get();
    
    angleV.GetValueAt(time, fv);
    float vangleV = fv.Get();
    
    vangleV+=generator->genSpinV;
    vangleH+=generator->genSpinH;
    
    float cosH = cosf(vangleH);
    float sinH = sinf(vangleH);
    float cosV = cosf(vangleV);
    float sinV = sinf(vangleV);
    
    float dx = cosH * cosV ;
    float dy = sinH * cosV ;
    float dz = sinV;
    
    speed.GetValueAt(time, fv);
    p->initSpeed=p->speed = fv.Get();
    
    life.GetValueAt(time, fv);
    p->particleLife = fv.Get();// -diference;
    
    alpha.GetValueAt(time, fv);
    p->initAlpha=p->alpha = fv.Get();
    
    ColorValue cv;
    color.GetValueAt(time, cv);
    p->color.Set(cv.GetR(), cv.GetG(), cv.GetB());
    p->initColor.Set(cv.GetR(), cv.GetG(), cv.GetB());
    
    mass.GetValueAt(time, fv);
    p->mass = fv.Get();

    spin.GetValueAt(time, fv);
    p->spin = fv.Get();

    angle.GetValueAt(time, fv);
    p->initAngle=p->angle = fv.Get();

    size.GetValueAt(time, fv);
    p->initSize=p->size = fv.Get();

    elasticity.GetValueAt(time, fv);
    p->elasticity = fv.Get();
    
    if(p->direction.x!=0||p->direction.y!=0||p->direction.z!=0){
    }else{
        p->direction.Set(dx, dy, dz);
        p->direction.NormalizeLocal();
    }
    
    angleH.GetValueAt(time, fv);
    p->particleAngleH = fv.Get();

    angleV.GetValueAt(time, fv);
    p->particleAngleV = fv.Get();
    
    spinH.GetValueAt(time, fv);
    p->particleSpinH = fv.Get();
    
    spinV.GetValueAt(time, fv);
    p->particleSpinV = fv.Get();
    
    height.GetValueAt(time, fv);
    p->initHeight=p->height = fv.Get();
    
    width.GetValueAt(time, fv);
    p->initWidth=p->width = fv.Get();
    
    texHeight.GetValueAt(time, fv);
    p->texHeight = fv.Get();
    
    texWidth.GetValueAt(time, fv);
    p->texWidth = fv.Get();
}

void GeneratorBehaviour::SetResolution(int resolution) {
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
    texWidth.SetResolution(resolution);
    texHeight.SetResolution(resolution);
    speed.SetResolution(resolution);
    
    life.SetResolution(resolution);
    rate.SetResolution(resolution);
    angleV.SetResolution(resolution);
    angleH.SetResolution(resolution);
    spinV.SetResolution(resolution);
    spinH.SetResolution(resolution);	
}
