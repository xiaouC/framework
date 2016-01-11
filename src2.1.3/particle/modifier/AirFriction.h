//
//  AirFriction.h
//  Stoneage
//
//  Created by gamebean on 12-12-11.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_AirFriction_h
#define Stoneage_AirFriction_h
#include "Modifier.h"
#include "../util/Stream.h"
class AirFriction : public Modifier
{
public:
    AirFriction();
    ~AirFriction();
    
    virtual void Modify(Particle* part, float dt);
	
	virtual int GetType();
    
	void Load(particle::InputStream& dis);
    
    
    float strength;    
	float sizeImportance;
    
};
#endif
