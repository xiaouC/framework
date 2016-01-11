//
//  CircleGeneratorSpace.h
//  Stoneage
//
//  Created by gamebean on 12-12-10.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_CircleGeneratorSpace_h
#define Stoneage_CircleGeneratorSpace_h
#include "GeneratorSpace.h"
#include "../util/Stream.h"

class CircleGeneratorSpace : public GeneratorSpace
{
public:
    CircleGeneratorSpace();
    ~CircleGeneratorSpace();
    
    virtual void LoadSpace(particle::InputStream& is);
	virtual void InitGeneratorSpace(GeneratorBehaviour* gb);
    
    float rx;//横轴
    float ry;//纵轴
};

#endif
