//
//  PointGenerator.h
//  Stoneage
//
//  Created by gamebean on 12-12-6.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_PointGenerator_h
#define Stoneage_PointGenerator_h
#include "GeneratorSpace.h"
#include "../util/Stream.h"
class PointGeneratorSpace:public GeneratorSpace
{
public:
    PointGeneratorSpace();
    ~PointGeneratorSpace();
public:
    virtual void LoadSpace(particle::InputStream& is);
    
    virtual void InitGeneratorSpace(GeneratorBehaviour* gb);
    
};
#endif
