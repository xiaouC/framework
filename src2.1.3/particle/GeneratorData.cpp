//
//  GeneratorData.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-11.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "ParticleSystem.h"
#include "GeneratorData.h"
#include "./space/PointGeneratorSpace.h"
#include "./space/CircleGeneratorSpace.h"
#include "./space/LineGeneratorSpace.h"
#include "./space/RectGeneratorSpace.h"
#include "./space/PathGeneratorSpace.h"
#include "./modifier/GenericForce.h"
#include "./modifier/AirFriction.h"

GeneratorData::GeneratorData()
{
    isRendToWorld=false;
    gb = new GeneratorBehaviour();
    pb = new ParticleBehaviour();
    pr = new ParticleRender();
    noColor=false;
}

GeneratorData::~GeneratorData()
{
    delete gb;
    delete pb;
    delete pr;
    for(int i = 0; i < allSpace.size(); i ++){
        delete allSpace[i];
    }
    allSpace.clear();
    for(int i = 0; i < md.size(); i ++){
        delete md[i];
    }
    md.clear();
}

void GeneratorData::Load(particle::InputStream& is)
{
    name.Read4HeadUTF(is);
    isRendToWorld=is.ReadBoolean();
    //粒子生成空间
    int count = is.ReadShort();
    for(int i = 0; i < count; i ++){
        GeneratorSpace* gs = NULL;
        short type = is.ReadByte();
        switch (type) {
            case GeneratorSpace::Point:
            {
                PointGeneratorSpace* pgs = new PointGeneratorSpace();
                pgs->LoadSpace(is);
                pgs->InitGeneratorSpace(gb);
                allSpace.push_back(pgs);
                break;
            }
            case GeneratorSpace::Line:
            {
                LineGeneratorSpace* lgs = new LineGeneratorSpace();
                lgs->LoadSpace(is);
                lgs->InitGeneratorSpace(gb);
                allSpace.push_back(lgs);
                break;
            }
            case GeneratorSpace::Rect:
            {
                RectGeneratorSpace* rgs = new RectGeneratorSpace();
                rgs->LoadSpace(is);
                rgs->InitGeneratorSpace(gb);
                allSpace.push_back(rgs);
                break;
            }
            case GeneratorSpace::Circle:
            {
                CircleGeneratorSpace* cgs = new CircleGeneratorSpace();
                cgs->LoadSpace(is);
                cgs->InitGeneratorSpace(gb);
                allSpace.push_back(cgs);
                break;
            }
            case GeneratorSpace::Path:
            {
                PathGeneratorSpace* pathGs = new PathGeneratorSpace();
                pathGs->LoadSpace(is);
                pathGs->InitGeneratorSpace(gb);
                allSpace.push_back(pathGs);
                break;
            }
            default:
                break;
        }
    }
    gb->Load(is);//发射器属性组
    pb->Load(is);//粒子属性组
    pr->Load(is);
    //读取修改器数据
    count = is.ReadShort();
    for(int i = 0; i < count; i ++){
        short type=is.ReadByte();
        switch(type){
			case Modifier::GenericForce:
            {
				GenericForce* gf=new GenericForce(); //外力修改器
                gf->Load(is);		
                md.push_back(gf);
                break;
            }
            case Modifier::AirFriction:
            {
                AirFriction* af = new AirFriction(); //空气阻力
                af->Load(is);
                md.push_back(af);
                break;
            }
        }
    }
    gb->SetResolution(MaxFPS);
    pb->SetResolution(MaxFPS);
    
    bool checkColorResult_gb(false);
    bool checkColorResult_pb(false);
    if(!gb->color.active){
    	checkColorResult_gb=true;
    }else if(!gb->color.random&&gb->color.mainValueList->array.size()==1){
    	ColorValue* vo=dynamic_cast<ColorValue*>(gb->color.mainValueList->array[0]);
    	if(vo->GetB()==1.0f&&vo->GetG()==1.0f&&vo->GetR()==1.0f){
    		checkColorResult_gb=true;
    	}
    }
    
    if(!pb->color.active){
    	checkColorResult_pb=true;
    }else if(!pb->color.random&&pb->color.mainValueList->array.size()==1){
     	ColorValue* vo=dynamic_cast<ColorValue*>(pb->color.mainValueList->array[0]);
     	if(vo->GetB()==1.0f&&vo->GetG()==1.0f&&vo->GetR()==1.0f){
     		checkColorResult_pb=true;
     	}
    }
    
    noColor=checkColorResult_gb&&checkColorResult_pb;
}