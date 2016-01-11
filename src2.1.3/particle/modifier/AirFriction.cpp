//
//  AirFriction.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-11.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "AirFriction.h"

AirFriction::AirFriction()
{
    strength = 1.2f;
	sizeImportance = 1.0f;
}

AirFriction::~AirFriction()
{
    
}

void AirFriction::Load(particle::InputStream& is)
{
    strength=ParticleUtil::Float_Java2C(is.ReadFloat());
    sizeImportance=ParticleUtil::Float_Java2C(is.ReadFloat());
}

void AirFriction::Modify(Particle *part, float dt)
{
    float sizeScaler = part->size * sizeImportance;
    sizeScaler = strength*dt * (1.0f + sizeScaler);    
    part->speed -= part->speed * sizeScaler;
}

int AirFriction::GetType()
{
    return Modifier::AirFriction;
}