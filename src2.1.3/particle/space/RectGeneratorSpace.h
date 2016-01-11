//
//  RectGeneratorSpace.h
//  Stoneage
//
//  Created by gamebean on 12-12-10.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_RectGeneratorSpace_h
#define Stoneage_RectGeneratorSpace_h

#include "GeneratorSpace.h"

class RectGeneratorSpace : public GeneratorSpace
{
public:
    RectGeneratorSpace();
    ~RectGeneratorSpace();
    
    virtual void LoadSpace(particle::InputStream& is);
	virtual void InitGeneratorSpace(GeneratorBehaviour* gb);
    
    float cwidth;
	float chight;
};


#endif
