//
//  Modifier.h
//  Stoneage
//
//  Created by gamebean on 12-12-10.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_Modifier_h
#define Stoneage_Modifier_h
#include "../Particle.h"

class Modifier
{
public:
    enum M_TYPE
    {
        GenericForce, //外力
        AirFriction   //空气阻力
    };
public:
    Modifier(){}
    ~Modifier(){}
	
	virtual void Modify(Particle* part, float dt){}
	
	virtual int GetType(){return 0;}
};

#endif
