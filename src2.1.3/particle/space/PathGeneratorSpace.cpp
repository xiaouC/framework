//
//  PathGeneratorSpace.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-10.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "PathGeneratorSpace.h"

PathGeneratorSpace::PathGeneratorSpace()
{
    gstype = Path;
}

PathGeneratorSpace::~PathGeneratorSpace()
{
    
}

void PathGeneratorSpace::LoadSpace(particle::InputStream& is)
{
    GeneratorSpace::LoadSpace(is);
    short len=is.ReadShort();
    spacePoints = new ListObject();
    for(int i = 0; i < len; i ++){
        Vector3f* vo = new Vector3f(ParticleUtil::Float_Java2C(is.ReadFloat()), ParticleUtil::Float_Java2C(is.ReadFloat()), ParticleUtil::Float_Java2C(is.ReadFloat()), 0);
		// FIXME:貌似z轴和x轴弄反了
		if(vo->z)
		{
			vo->x = vo->z;
			vo->z = 0;
		}
        spacePoints->array.push_back(vo);		
    }    
    spacePoints->lastTime=float(len)/float(spacePoints->resolution);
}

void PathGeneratorSpace::InitGeneratorSpace(GeneratorBehaviour* gb)
{
}