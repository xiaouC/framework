//
//  PointGenerator.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-6.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "PointGeneratorSpace.h"

PointGeneratorSpace::PointGeneratorSpace()
{
    gstype = Point;
}

PointGeneratorSpace::~PointGeneratorSpace()
{
    
}

void PointGeneratorSpace::LoadSpace(particle::InputStream& is)
{
    GeneratorSpace::LoadSpace(is);
}

void PointGeneratorSpace::InitGeneratorSpace(GeneratorBehaviour* gb)
{
}