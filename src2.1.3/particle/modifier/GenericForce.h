//
//  GenericForce.h
//  Stoneage
//
//  Created by fanxiaoli on 12-12-10.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_GenericForce_h
#define Stoneage_GenericForce_h
#include "Modifier.h"

class GenericForce : public Modifier
{
public:
    GenericForce();
    ~GenericForce();
    
    virtual void Modify(Particle* part, float dt);
	
	virtual int GetType();
    
	void Load(particle::InputStream& dis);    
    
    Vector3f direction;
	
	float strength;
	
	float massImportance;
};

#endif
