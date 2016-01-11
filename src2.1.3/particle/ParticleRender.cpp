//
//  ParticleRender.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-6.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "ParticleRender.h"
#include "Util.h"
#include <string>

ParticleRender::ParticleRender()
{ 
    sourceFactor = 0;		//源因子 
    destinationFactor = 0;	//目标因子     
    absoluteParticleAngle = true;  //是否面向摄像机 
    
    cutW = 1;
    cutH = 1;
    delay = 1;
    uRepeat = false;
    vRepeat = false;
    uSpeed = 0;
    vSpeed = 0;
    uOffset = 0;
    vOffset = 0;
    repeatPlay = true;
    rotateSpeed=0;    
	rotateDegree=0;
}

ParticleRender::~ParticleRender()
{
    
}

void ParticleRender::OnRender(float ft)
{
    
}

void ParticleRender::Load(particle::InputStream &is)
{
    textureName.Read4HeadUTF(is);    //纹理名称 
    std::string temp = textureName.Data();
    size_t pos = temp.find("/");
    if((int)pos >= 0){
        temp = std::string("particles/textures/") + std::string(temp.substr(pos+1));
        textureName.Set(temp.c_str());
    }
    sourceFactor=is.ReadInt();		//源因子 
    destinationFactor=is.ReadInt();	//目标因子     
    absoluteParticleAngle=is.ReadBoolean();  //是否面向摄像机 
    
    cutW=is.ReadShort();
    cutH=is.ReadShort();
    delay=is.ReadShort();
    
    uRepeat=is.ReadBoolean();
    vRepeat=is.ReadBoolean();
    
    uOffset=ParticleUtil::Float_Java2C(is.ReadFloat());
    vOffset=ParticleUtil::Float_Java2C(is.ReadFloat());
    
    uSpeed=ParticleUtil::Float_Java2C(is.ReadFloat());
    vSpeed=ParticleUtil::Float_Java2C(is.ReadFloat());
    repeatPlay = is.ReadBoolean();
    rotateSpeed=ParticleUtil::Float_Java2C(is.ReadFloat());
    rotateDegree=ParticleUtil::Float_Java2C(is.ReadFloat());
}
