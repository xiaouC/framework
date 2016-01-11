//
//  GenericForce.cpp
//  Stoneage
//
//  Created by fanxiaoli on 12-12-10.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "GenericForce.h"

GenericForce::GenericForce()
{
    direction.Set(0, 1, 0);	
	strength = 9.8;
	massImportance = 1;
}

GenericForce::~GenericForce()
{
    
}

void GenericForce::Load(particle::InputStream& is)
{
    direction.x=ParticleUtil::Float_Java2C(is.ReadFloat());
    direction.y=ParticleUtil::Float_Java2C(is.ReadFloat());
    direction.z=ParticleUtil::Float_Java2C(is.ReadFloat());
    
    strength=ParticleUtil::Float_Java2C(is.ReadFloat());
    massImportance=ParticleUtil::Float_Java2C(is.ReadFloat());
}

void GenericForce::Modify(Particle* part, float dt)
{
    float massScaler = part->mass*massImportance;
    massScaler = strength*dt*(1.0f+massScaler);
    
    Vector3f temp;
    temp.Set(direction.GetX(), direction.GetY(), direction.GetZ());
    temp.ScaleLocal(massScaler);
    
    Vector3f particleSpeedVector;
    particleSpeedVector.Set(part->direction.GetX(), part->direction.GetY(), part->direction.GetZ());
    particleSpeedVector.ScaleLocal(part->speed);
    
    particleSpeedVector.AddLocal(temp.GetX(), temp.GetY(), temp.GetZ());
    
    part->speed = particleSpeedVector.Length();
    
    particleSpeedVector.NormalizeLocal();	
    part->direction.Set(particleSpeedVector.GetX(), particleSpeedVector.GetY(), particleSpeedVector.GetZ());
}

int GenericForce::GetType()
{
    return Modifier::GenericForce;
}