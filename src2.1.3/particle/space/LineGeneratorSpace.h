//
//  LineGeneratorSpace.h
//  Stoneage
//
//  Created by gamebean on 12-12-10.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_LineGeneratorSpace_h
#define Stoneage_LineGeneratorSpace_h

#include "GeneratorSpace.h"
#include "../util/Stream.h"

class LineGeneratorSpace : public GeneratorSpace
{
public:
    LineGeneratorSpace();
    ~LineGeneratorSpace();
    
    virtual void LoadSpace(particle::InputStream& is);
	virtual void InitGeneratorSpace(GeneratorBehaviour* gb);
    
    Vector3f otherPoint; // 终点 
};


#endif
