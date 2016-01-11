//
//  ParticleSpace.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-25.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "ParticleSpace.h"

Particle* ParticleSpace::sourcePool[MAX_PARTICAL_NUM];//粒子源池，创建一次，以后从里面取粒子 
int ParticleSpace::sourceIndex = -1;//源池中已经被使用的粒子的索引，即粒子（0-sourceIndex）已被使用或回收 
int ParticleSpace::sourceCount = 0;//源池中已存在的粒子的数量 
short ParticleSpace::recyclePool[MAX_PARTICAL_NUM];//粒子源池对应的回收池，即从源池取出的粒子消失后，把粒子id存入这里 
int ParticleSpace::recycleIndex = -1;//回收池中最后一个粒子id的索引 

void ParticleSpace::Init()
{
    memset(sourcePool, 0, sizeof(sourcePool));
    memset(recyclePool, 0, sizeof(recyclePool));
    sourceIndex = -1;
    sourceCount = 0;    
    recycleIndex = -1;
}

Particle* ParticleSpace::AddParticle()
{
    Particle* p = NULL;
    if(sourceCount < MAX_PARTICAL_NUM){//没满的话直接创建 
        p = new Particle();
        sourcePool[++sourceIndex] = p;
        p->setId(sourceIndex);
        sourceCount ++;
    }else{//已经满了就直接取 
        if(recycleIndex >= 0){
            p = sourcePool[recyclePool[recycleIndex--]];            
        }else if(sourceIndex < MAX_PARTICAL_NUM - 1){
            p = sourcePool[++sourceIndex];
        }
        if(p != NULL){
            p->Reset();//曾经使用过的粒子需要重置一下 
        }
    }    
    return p;
}

short ParticleSpace::RecycleParticle(Particle * p)
{
    return recyclePool[++recycleIndex] = p->getID();
}
