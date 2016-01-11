//
//  ParticleSpace.h
//  Stoneage
//
//  Created by fanxiaoli on 12-12-8.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_ParticleSpace_h
#define Stoneage_ParticleSpace_h
#include "../Particle.h"
//发射器发射的粒子的存储空间 
class ParticleSpace
{
public:
    ParticleSpace(){
        totalGenerated=0;
        age=0;
    }
    ~ParticleSpace(){
        for(int i = 0; i < (int)particles.size(); i ++){
//            delete particles[i];//不删除，只回收 
            RecycleParticle(particles[i]);
        }
        particles.clear();
    }
public:
    float totalGenerated;
    float age;
    std::vector<Particle*> particles;
    
    static const int MAX_PARTICAL_NUM = 2000; //粒子源池的最大数量 
    static Particle* sourcePool[MAX_PARTICAL_NUM];//粒子源池，创建一次，以后从里面取粒子 
    static int sourceIndex;//源池中已经被使用的粒子的索引，即粒子（0-sourceIndex）已被使用或回收 
    static int sourceCount;//源池中已存在的粒子的数量 
    static short recyclePool[MAX_PARTICAL_NUM];//粒子源池对应的回收池，即从源池取出的粒子消失后，把粒子id存入这里 
    static int recycleIndex;//回收池中最后一个粒子id的索引 
    
    static Particle* AddParticle(); //添加粒子 
    static short RecycleParticle(Particle*);//回收粒子 
    static void Init();//初始化 
};

#endif
