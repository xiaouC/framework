//
//  ParticleBehaviour.h
//  Stoneage
//
//  Created by gamebean on 12-12-6.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_ParticleBehaviour_h
#define Stoneage_ParticleBehaviour_h

#include "ValueList.h"
#include "./util/Stream.h"
class Particle;
//粒子属性组 
class ParticleBehaviour
{
public:
    ParticleBehaviour();
    ~ParticleBehaviour();
public:
    void Load(particle::InputStream& is);
    void OnUpdate(std::vector<Particle*>& particles);
    void SetResolution(int resolution); 
	bool isKillParticles() {return killParticles;}    
	void setKillParticles(bool particlesDie) {
		this->killParticles = particlesDie;
	}
    
    bool isAutoAngle;            //自动调整角度 
    bool killParticles; //生命周期后是否杀死粒子 
    float particleMaxlife; //粒子的生命周期--- 
    
    FloatList alpha;				//透明属性组* 
    ColorList color;				//颜色属性组* 
    FloatList mass;				//重量属性组* 
    FloatList spin;				//角度增量属性组* 
    FloatList angle;				//角度属性组* 
    FloatList size;				//大小属性组* 
    FloatList elasticity;			//弹力属性组* 
    FloatList particleAngleV;		//纵向角度属性组* 
    FloatList particleAngleH;		//横向角度属性组* 
    FloatList particleSpinV;		//纵向角度增量属性组* 
    FloatList particleSpinH;		//横向角度增量属性组* 
    FloatList width;				//宽度属性组* 
    FloatList height;				//高度属性组* 
    FloatList speed;				//速度属性组* 
    FloatList texWidth;			//纹理宽度属性组* 
    FloatList texHeight;			//纹理高度属性组* 
    
};

#endif
