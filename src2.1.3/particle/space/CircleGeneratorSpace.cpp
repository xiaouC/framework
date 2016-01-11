//
//  CircleGeneratorSpace.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-10.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "CircleGeneratorSpace.h"
#include "../Util.h"

#ifdef WIN32
#define M_PI       3.14159265358979323846
#endif

CircleGeneratorSpace::CircleGeneratorSpace()
{
    rx = 50;
    ry = 50;
    gstype = Circle;
}
CircleGeneratorSpace::~CircleGeneratorSpace()
{
    
}

void CircleGeneratorSpace::LoadSpace(particle::InputStream& is)
{
    GeneratorSpace::LoadSpace(is);
    rx = ParticleUtil::Float_Java2C(is.ReadFloat());
    ry = ParticleUtil::Float_Java2C(is.ReadFloat());
}
//进行编译该发射源进行优化
void CircleGeneratorSpace::InitGeneratorSpace(GeneratorBehaviour* gb)
{
    spacePoints = new ListObject();
    center.Set(cposition.GetX(), cposition.GetY(), cposition.GetZ());
    switch(motionType){
		case Border:
        {            
			int max=(int) (rx>ry?rx:ry)+1;
			int count=max*2;			
			float ratio=2 * M_PI/count;
			float v;
			for(int i=0;i<count;i++){
				v=i*ratio;                
                Vector3f* vo = new Vector3f(cosf(v)*rx+cposition.x, sinf(v)*ry+cposition.y, 0, 0);
                spacePoints->array.push_back(vo);				
			}			
			break;
        }
		case Loop:
		case Swing:
        {
            int count=(int) (gb->lifeTime*timeScale*spacePoints->resolution);
//			pathList.array=new Object[count+1];			
			float ratio=2*M_PI/count;
            float v;
			for(int i=0;i<=count;i++){
				v=i*ratio;
				Vector3f* vo = new Vector3f(cosf(v)*rx+cposition.x, sinf(v)*ry+cposition.y, 0, 0);
                spacePoints->array.push_back(vo);
			}
			
			spacePoints->lastTime=gb->lifeTime*timeScale;		
			break;
        }
		case Content:			
//			float xr=1/rx;
//			for(int i=(int) rx;i>=-rx;--i){
//				float fValue=acosf(i*xr);
//				float y = fabs(ry*sinf(fValue));
//				for(int k=(int)y;k>-y;--k){
//					if(ParticleUtil::RandFloat() < timeScale){
//                        Vector3f* vo = new Vector3f(i+cposition.x,k+cposition.y, 0, 0);
//                        spacePoints->array.push_back(vo);
//					}
//				}
//			}
			break;
    }
}
