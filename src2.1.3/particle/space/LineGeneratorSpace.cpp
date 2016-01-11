//
//  LineGeneratorSpace.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-10.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "LineGeneratorSpace.h"

LineGeneratorSpace::LineGeneratorSpace()
{
    cposition.Set(-50, 0, 0);
    otherPoint.Set(50, 0, 0);
    gstype = Line;
}
LineGeneratorSpace::~LineGeneratorSpace()
{
    
}

void LineGeneratorSpace::LoadSpace(particle::InputStream& is)
{
    GeneratorSpace::LoadSpace(is);
    otherPoint.Set(ParticleUtil::Float_Java2C(is.ReadFloat()), ParticleUtil::Float_Java2C(is.ReadFloat()), ParticleUtil::Float_Java2C(is.ReadFloat()));
}
//进行编译该发射源进行优化
void LineGeneratorSpace::InitGeneratorSpace(GeneratorBehaviour* gb)
{
    spacePoints = new ListObject();
    Vector3f* vo = new Vector3f(cposition.x,cposition.y, cposition.z, 0);
    spacePoints->values.push_back(vo);
    
    float time=gb->lifeTime*timeScale;
    Vector3f* vo2 = new Vector3f(otherPoint.x,otherPoint.y, otherPoint.z, time);
    spacePoints->values.push_back(vo2);
    
    spacePoints->CreateArray(ValueList::VECTOR3F_VALUE);
    spacePoints->startTime = spacePoints->values[0]->time;
    spacePoints->lastTime = spacePoints->values[spacePoints->values.size() - 1]->time;
}