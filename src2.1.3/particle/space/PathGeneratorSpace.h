//
//  PathGeneratorSpace.h
//  Stoneage
//
//  Created by gamebean on 12-12-10.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_PathGeneratorSpace_h
#define Stoneage_PathGeneratorSpace_h

#include "GeneratorSpace.h"
#include "../util/Stream.h"

class PathGeneratorSpace : public GeneratorSpace
{
public:
    PathGeneratorSpace();
    ~PathGeneratorSpace();
    
    virtual void LoadSpace(particle::InputStream& is);
	virtual void InitGeneratorSpace(GeneratorBehaviour* gb);
    
};

#endif
