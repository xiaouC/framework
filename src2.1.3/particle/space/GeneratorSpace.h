//
//  GeneratorSpace.h
//  Stoneage
//
//  Created by gamebean on 12-12-6.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_GeneratorSpace_h
#define Stoneage_GeneratorSpace_h

#include "../Particle.h"
#include "../GeneratorBehaviour.h"
#include "ParticleSpace.h"
#include "../util/Stream.h"

//发射器空间形态的基类 
class GeneratorSpace
{
public:
    //发射器空间类型 
    enum GS_TYPE
    {
        Point,
        Line,
        Rect,
        Circle,
        Path
    };
    //动作类型 
    enum MOTION_TYPE
    {
        Border,
        Loop,
        Swing,
        Content
    };
    //位置类型 
    enum DIR_TYPE
    {
        Ori,
        Inside,
        Outside
    };
public:
    GeneratorSpace();
    ~GeneratorSpace();
public:
    virtual void LoadSpace(particle::InputStream& is);
    //根据发射器空间类型初始化粒子 
	void InitParticle(Particle* part, ParticleSpace* ps, float time);    
	virtual void InitGeneratorSpace(GeneratorBehaviour* gb);    
    int GetType(){return gstype;}
    
public:
    GS_TYPE gstype; //发射器形态类型     
    Vector3f cposition;//发射源的位置 
	float rateScale;
    ListObject* spacePoints;
		
	short motionType;
	float timeScale;	
	float offsettime;    
	bool isReDir;	
    Vector3f center;	
	short dirType;  // 方位类型 

};

#endif
