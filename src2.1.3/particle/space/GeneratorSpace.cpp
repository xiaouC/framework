//
//  GeneratorSpace.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-6.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "Common/TLCommon.h"
#include "GeneratorSpace.h"
#include "RectGeneratorSpace.h"
#include "CircleGeneratorSpace.h"
GeneratorSpace::GeneratorSpace()
{
    gstype = Point; //发射器形态类型    
    cposition.Set(0, 0, 0);//发射源的位置
	rateScale = 1;
    
	motionType = 0;
	timeScale = 1;	
	offsettime = 0;    
	isReDir = false;	
    center.Set(0, 0, 0);	
	dirType = 0;  // 方位类型
    spacePoints = NULL;
}
GeneratorSpace::~GeneratorSpace()
{
    delete spacePoints;
}

void GeneratorSpace::LoadSpace(particle::InputStream& is)
{
    rateScale=ParticleUtil::Float_Java2C(is.ReadFloat());    
    cposition.x=ParticleUtil::Float_Java2C(is.ReadFloat());
    cposition.y=ParticleUtil::Float_Java2C(is.ReadFloat());
    cposition.z=ParticleUtil::Float_Java2C(is.ReadFloat());
    if(gstype != Point){    
        timeScale=ParticleUtil::Float_Java2C(is.ReadFloat());
        motionType=is.ReadByte();    
        offsettime=ParticleUtil::Float_Java2C(is.ReadFloat());
        isReDir=is.ReadBoolean();    
        dirType=is.ReadByte();
    }
}
//根据发射器空间类型初始化粒子
void GeneratorSpace::InitParticle(Particle* part, ParticleSpace* ps, float time)
{
    part->direction.Set(0, 0, 0);
    part->position.Set(cposition.GetX(), cposition.GetY(), cposition.GetZ());
    if(gstype == Point){
        return;
    }
    
    switch(motionType){
		case Border:
        {
            ValueObject* vo = spacePoints->array[XL_RANDOM() % spacePoints->array.size()];
            part->position.Set(vo);
            break;
        }
		case Content:
        {
            Vector3f* vo = NULL;
            if(gstype == Circle){
                int rx = XL_RANDOM()%(int)((CircleGeneratorSpace*)this)->rx;
                int ry = XL_RANDOM()%(int)((CircleGeneratorSpace*)this)->ry;
                float rand = ParticleUtil::RandFloat(2*M_PI);                
                vo = new Vector3f(rx*cosf(rand)+cposition.x,ry*sinf(rand)+cposition.y, 0, 0);
            }else if(gstype == Rect){
                int w = ((RectGeneratorSpace*)this)->cwidth;
                int h = ((RectGeneratorSpace*)this)->chight;
                vo = new Vector3f(cposition.x+XL_RANDOM()%w,cposition.y+XL_RANDOM()%h, 0, 0);
            }
            if(vo != NULL){
                part->position.Set(vo);
                delete vo;
            }
            
			break;
        }
		case Loop:
        {
            ps->age = ParticleUtil::RemFloat(ps->age, spacePoints->lastTime);
			
            float curAge=offsettime*spacePoints->lastTime;
			if(isReDir){
				curAge=spacePoints->lastTime+curAge-ps->age;
			}else{
				curAge=spacePoints->lastTime+curAge+ps->age;
			}
			curAge = ParticleUtil::RemFloat(curAge, spacePoints->lastTime);            
			part->position.Set(spacePoints->GetValueAt(curAge));
			break;
        }
		case Swing:
        {
            ps->age = ParticleUtil::RemFloat(ps->age, spacePoints->lastTime * 2);
			
			float curAge=offsettime*spacePoints->lastTime;
			if(isReDir){
				curAge=spacePoints->lastTime*3+curAge+ps->age;
			}else{
				curAge=spacePoints->lastTime*2+curAge+ps->age;
			}
            
			curAge = ParticleUtil::RemFloat(curAge, spacePoints->lastTime * 2);
			if(curAge>spacePoints->lastTime){                
				part->position.Set(spacePoints->GetValueAt(spacePoints->lastTime*2-curAge));
			}else{
                part->position.Set(spacePoints->GetValueAt(curAge));
			}
			break;
        }            
    }
    
    switch(dirType){
		case Inside:	
			part->direction.Set(center.x-part->position.x, 
                               center.y-part->position.y, 
                               center.z-part->position.z);
            part->direction.NormalizeLocal();
			break;
		case Outside:	
			part->direction.Set(part->position.x-center.x, 
                               part->position.y-center.y, 
                               part->position.z-center.z);
            part->direction.NormalizeLocal();
			break;
    }
}

void GeneratorSpace::InitGeneratorSpace(GeneratorBehaviour *gb)
{
    
}

