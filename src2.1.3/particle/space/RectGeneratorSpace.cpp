//
//  RectGeneratorSpace.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-10.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "RectGeneratorSpace.h"

RectGeneratorSpace::RectGeneratorSpace()
{
    cwidth=100;
	chight=100;
    gstype = Rect;
}

RectGeneratorSpace::~RectGeneratorSpace()
{
    
}

void RectGeneratorSpace::LoadSpace(particle::InputStream& is)
{
    GeneratorSpace::LoadSpace(is);
    cwidth = ParticleUtil::Float_Java2C(is.ReadFloat());
    chight = ParticleUtil::Float_Java2C(is.ReadFloat());
}
//进行编译该发射源进行优化
void RectGeneratorSpace::InitGeneratorSpace(GeneratorBehaviour* gb)
{
    spacePoints = new ListObject();
    switch(motionType){
		case Border:
		case Loop:
		case Swing:
        {
            Vector3f* vo = new Vector3f(cposition.x,cposition.y, cposition.z, 0);
			spacePoints->values.push_back(vo);
            
            float time = gb->lifeTime*timeScale*chight/((chight+cwidth)*2);
			vo = new Vector3f(cposition.x,cposition.y+chight,cposition.z, time);
			spacePoints->values.push_back(vo);
			
			time=gb->lifeTime*timeScale*(chight+cwidth)/((chight+cwidth)*2);
            vo = new Vector3f(cposition.x+cwidth,cposition.y+chight,cposition.z, time);
			spacePoints->values.push_back(vo);
			
			time=gb->lifeTime*timeScale*(2*chight+cwidth)/((chight+cwidth)*2);
            vo = new Vector3f(cposition.x+cwidth,cposition.y,cposition.z, time);
			spacePoints->values.push_back(vo);

			time=gb->lifeTime*timeScale;
			vo = new Vector3f(cposition.x,cposition.y, cposition.z, time);
			spacePoints->values.push_back(vo);
            
            spacePoints->CreateArray(ValueList::VECTOR3F_VALUE);
            spacePoints->startTime = spacePoints->values[0]->time;
            spacePoints->lastTime = spacePoints->values[spacePoints->values.size() - 1]->time;
			break;
        }
		case Content:
        {
//            int len = (int) cwidth*(int) chight;
//            for(int i = 0; i < len; i ++){
//                spacePoints->array.push_back(NULL);
//            }
//            
//			for(int i=0;i<cwidth;i++){
//				for(int k=0;k<chight;k++){
//					if(ParticleUtil::RandFloat()<timeScale){
//						spacePoints->array[i+((int)cwidth)*k]
//                        =new Vector3f(cposition.x+i,cposition.y+k, 0, 0);
//					}
//				}
//			}
			break;
        }
    }
    center.Set(cposition.x+(cwidth/2),cposition.y+(chight/2), 0);
}