//
//  GeneratorBehaviour.h
//  Stoneage
//
//  Created by landye on 12-12-3.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef __Stoneage__GeneratorBehaviour__
#define __Stoneage__GeneratorBehaviour__

#include "Particle.h"
#include "ValueList.h"
#include "./util/Stream.h"
class Generator;

//发射器属性组
class GeneratorBehaviour
{
public:
    GeneratorBehaviour();
    ~GeneratorBehaviour();
    
    void OnUpdate(Generator* generator, float time, float timelapse);
    void Load(particle::InputStream& is);    
    void InitParticle(Generator* generator, Particle* p, float time);
    void SetResolution(int resolution);
	inline int getNumber() {
		return number;
	}    
	inline void setNumber(int number) {
		this->number = number;
	}

public:
    int number; 		//最大的粒子数        
    float lifeTime; 	//该发射器的生命周期        
    float bias;         //发射器偏移时间（开始工作之前的等待时间）        
    bool repeat;     	//是否循环播放-----------------        
    bool regenerateParticles; 	//是否重复生成粒子
        
    FloatList alpha;				//透明属性组*
    ColorList color;				//颜色属性组*
    FloatList mass;				//重量属性组*
    FloatList spin;				//角度增量属性组*
    FloatList angle;				//角度属性组*
    FloatList size;				//大小属性组*
    FloatList elasticity;		//弹力属性组*
    FloatList particleAngleV;	//纵向角度属性组*
    FloatList particleAngleH;	//横向角度属性组*
    FloatList particleSpinV;		//纵向角度增量属性组*
    FloatList particleSpinH;		//横向角度增量属性组*
    FloatList width;				//宽度属性组*
    FloatList height;			//高度属性组*
    FloatList speed;				//速度属性组*
    FloatList texWidth;			//纹理宽度属性组*
    FloatList texHeight;			//纹理高度属性组*
    FloatList life;              //生命周期属性组*
    FloatList rate;              //发射速率属性组*
    FloatList angleV;			//纵向分发射角度属性组*
    FloatList angleH;			//横向发射角度属性组*
    FloatList spinV;				//纵向角度增量属性组*
    FloatList spinH;				//横向角度属性组*

};

#endif
