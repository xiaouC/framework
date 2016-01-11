//
//  Generator.h
//  Stoneage
//
//  Created by gamebean on 12-12-5.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_Generator_h
#define Stoneage_Generator_h

#include "Particle.h"
#include "GeneratorData.h"

//using namespace Game;

// 发射器数据 
class Generator
{
public:
    Generator(GeneratorData* gd);
    ~Generator();
public:
    void OnRender(float sysX, float sysY);
    void OnUpdate(float dt); //更新粒子，dt为粒子系统更新的单帧时间 
    void Generate(float time, float dt); //生成粒子 
    void Reset();//重置发射器 
public:


    GeneratorData* genData;//发射器的数据 
    std::vector<ParticleSpace*> sim;   //粒子存储空间 

    
	Vector3f position; //粒子系统的空间位置 
	float age; //该发射器的年龄 
	int genCount; //总共生成的粒子数 
	bool isVisible;
	
	//发射器属性---------------------------------------------- 
	float currentRate; //当前发射器发射速率 
    float genSpinV;
    float genSpinH;

};

#endif
