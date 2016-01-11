//
//  Particle.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-5.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "Particle.h"
#include "ParticleSystemManager.h"

Particle::Particle()
{
    id=0;						//粒子池管理	 
    age=0.0f;                   //粒子的当前时间     
    killParticles = true;       //生命周期后是否杀死粒子 
    particleLife = 1;           //粒子的生命周期--- 
    direction.Set(0,0,0);
    position.Set(0,0,0);
    oldPosition.Set(0,0,0);
    
    alpha = 0;				    //透明属性组* 
    color.Set(0,0,0);		    //颜色属性组* 
    mass = 0;					//重量属性组* 
    spin = 0;					//角度增量属性组* 
    angle = 0;					//角度属性组* 
    size = 0;					//大小属性组* 
    elasticity = 0;			    //弹力属性组* 
    particleAngleV = 0;			//纵向角度属性组* 
    particleAngleH = 0;			//横向角度属性组* 
    particleSpinV = 0;			//纵向角度增量属性组* 
    particleSpinH = 0;			//横向角度增量属性组* 
    width = 1;				    //宽度属性组* 
    height = 1;					//高度属性组* 
    speed = 1;					//速度属性组* 
    texWidth = 1;				//纹理宽度属性组* 
    texHeight = 1;			    //纹理高度属性组*     
    cutIndex = 0;
    
    
    initAlpha = 0;
    initSize = 0;
    initAngle = 0;
    initSpeed = 0;
    initWidth = 0;
    initHeight = 0;
    //
    initColor.Set(0,0,0);		    //颜色属性组* 
    
}

Particle::~Particle()
{    
}

void Particle::Reset()
{
    age=0.0f;  
    killParticles = true;
    particleLife = 1;
    direction.Set(0,0,0);
    position.Set(0,0,0);
    oldPosition.Set(0,0,0);
    cutIndex = 0;
}

void Particle::OnRender(ParticleRender* pr, float ft, float sysX, float sysY)
{
//    RenderUtil::Orthof();
//    RenderUtil::LoadIdentity();
//    Game::Image* img = ParticleSystemManager::GetInstance().GetImage(pr->textureName.Data());
//    if(img != NULL){
//        float scalex = width / texWidth;
//        float scaley = height / texHeight;
//        RenderUtil::Save();
//        RenderUtil::Scale(scalex, scaley);
//        RenderUtil::Translate(sysX, sysY);
//        RenderUtil::Rotate(angle*180/M_PI);
//        RenderUtil::SetColor(color.GetR(), color.GetG(), color.GetB(), alpha);
//        RenderUtil::DrawTexture(img, position.GetX(), position.GetY());
//        RenderUtil::Restore();
//    }
}

void Particle::OnUpdate(float ft)
{
    oldPosition.Set(position.GetX(), position.GetY(), position.GetZ());
    position.AddLocal(direction.GetX() * speed * ft, direction.GetY() * speed * ft, direction.GetZ() * speed * ft);
    
    angle += spin * ft;     //计算出当前的角度     
    particleAngleV += particleSpinV * ft;	//计算粒子纵向旋转角度 
    particleAngleH += particleSpinH * ft;	//计算粒子的横向旋转角度 
    
    particleLife -= ft;
    age += ft;
    ++cutIndex;
}

void Particle::OnUpdate(ParticleBehaviour* pb)
{
    FloatValue fv;
    if(pb->alpha.IsActive()){
        pb->alpha.GetValueAt(age, fv);
        alpha = initAlpha*fv.Get();				    //透明属性 
    }
    
    ColorValue cv;
    if(pb->color.IsActive()){
        pb->color.GetValueAt(age, cv);
        color.Set(initColor.r*cv.GetR(), initColor.g*cv.GetG(), initColor.b*cv.GetB());	//颜色属性组* 
    }
    if(pb->mass.IsActive()){
        pb->mass.GetValueAt(age, fv);
        mass = fv.Get();					//重量属性组* 
    }
    if(pb->spin.IsActive()){
        pb->spin.GetValueAt(age, fv);
        spin=fv.Get();					//角度增量属性组* 
    }
    if(pb->angle.IsActive()){
        pb->angle.GetValueAt(age, fv);
        angle=initAngle+fv.Get();					//角度属性组* 
    }
    if(pb->size.IsActive()){
        pb->size.GetValueAt(age, fv);
        size=initSize*fv.Get();					//大小属性组* 
    }
    if(pb->elasticity.IsActive()){
        pb->elasticity.GetValueAt(age, fv);
        elasticity=fv.Get();			    //弹力属性组* 
    }
    if(pb->particleAngleV.IsActive()){
        pb->particleAngleV.GetValueAt(age, fv);
        particleAngleV=fv.Get();			//纵向角度属性组* 
    }
    if(pb->particleAngleH.IsActive()){
        pb->particleAngleH.GetValueAt(age, fv);
        particleAngleH=fv.Get();			//横向角度属性组* 
    }
    if(pb->particleSpinV.IsActive()){
        pb->particleSpinV.GetValueAt(age, fv);
        particleSpinV=fv.Get();			//纵向角度增量属性组* 
    }
    if(pb->particleSpinH.IsActive()){
        pb->particleSpinH.GetValueAt(age, fv);
        particleSpinH=fv.Get();			//横向角度增量属性组* 
    }
    if(pb->width.IsActive()){
        pb->width.GetValueAt(age, fv);
        width=initWidth*fv.Get();				    //宽度属性组* 
    }
    if(pb->height.IsActive()){
        pb->height.GetValueAt(age, fv);
        height=initHeight*fv.Get();					//高度属性组* 
    }
    if(pb->speed.IsActive()){
        pb->speed.GetValueAt(age, fv);
        speed=initSpeed+ fv.Get();					//速度属性组* 
    }
    if(pb->texWidth.IsActive()){
        pb->texWidth.GetValueAt(age, fv);
        texWidth=fv.Get();				//纹理宽度属性组* 
    }
    if(pb->texHeight.IsActive()){
        pb->texHeight.GetValueAt(age, fv);
        texHeight=fv.Get();			    //纹理高度属性组* 
    }
}
