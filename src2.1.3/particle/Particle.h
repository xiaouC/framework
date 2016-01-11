//
//  Particle.h
//  Stoneage
//
//  Created by gamebean on 12-12-5.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_Particle_h
#define Stoneage_Particle_h

#include "ValueList.h"
#include "ParticleBehaviour.h"
#include "ParticleRender.h"
//粒子 
class Particle
{
public:
    Particle();
    ~Particle();    
public:
//    void Load(InputStream& is);
    void OnRender(ParticleRender* pr, float ft, float sysX, float sysY);
    void OnUpdate(float ft);
    void OnUpdate(ParticleBehaviour* pb);
    void Reset();
    inline short getID() {
		return id;
	}
    
	inline void setId(short _id) {
		id=_id;
	}
    
    short id;			 //粒子池管理	 
    float age;           //粒子的当前时间	 
    Vector3f direction;  //粒子的运动方向 
    Vector3f position;   //粒子的当前位置     
    Vector3f oldPosition;//粒子的上次的绘制位置     
    
    bool killParticles; //生命周期后是否杀死粒子 
    float particleLife; //粒子的生命周期---     
    float alpha;				    //透明属性组* 
    ColorValue color;				//颜色属性组* 
    float mass;					//重量属性组* 
    float spin;					//角度增量属性组* 
    float angle;					//角度属性组* 
    float size;					//大小属性组* 
    float elasticity;			    //弹力属性组* 
    float particleAngleV;			//纵向角度属性组* 
    float particleAngleH;			//横向角度属性组* 
    float particleSpinV;			//纵向角度增量属性组* 
    float particleSpinH;			//横向角度增量属性组* 
    float width;				    //宽度属性组* 
    float height;					//高度属性组* 
    float speed;					//速度属性组* 
    float texWidth;				//纹理宽度属性组* 
    float texHeight;			    //纹理高度属性组* 
    
    int cutIndex;
    
    float initAlpha;
    float initSize;
    float initAngle;
    float initSpeed;
    float initWidth;
    float initHeight;
    //
    ColorValue initColor;				//颜色属性组* 
    
};
#endif
