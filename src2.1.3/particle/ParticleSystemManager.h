//
//  ParticleSystemManager.h
//  Stoneage
//
//  Created by fanxiaoli on 12-12-16.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_ParticleSystemManager_h
#define Stoneage_ParticleSystemManager_h

#include "Generator.h"
#include "ParticleSystem.h"
#include <map>
using namespace cocos2d;
class ParticleSystemManager
{
public:
    ParticleSystemManager();
    ~ParticleSystemManager();
    
    static ParticleSystemManager* sharedParticleSystemManager();

    void LoadParticleSystems( const char* fileName );

    ParticleSystem* createWithName( CCNode* node, CCPoint point, int zOder, const char* name, bool loop, float time = -1, bool bNormalSchedule = true );
    ParticleSystem* createWithNameLua( CCNode* node, int x, int y, const char* name, int loopCnt = -1, bool bNormalSchedule = true );

    //
    ParticleSystem* AddParticlesSystem( CCNode* node, CCPoint point, int zOder,
            const char* fileName, bool loop, float time = -1, ParticleSystem::PSListener* listener = NULL );
    ParticleSystem* AddParticlesSystem( CCNode* node, int x, int y, const char* fileName, int loopCnt = -1, ParticleSystem::PSListener* listener = NULL );

    CCTexture2D* GetImage( const std::string& strTexFile );

	// 清空粒子系统的贴图缓存
	void cleanupCache();

	void splitParticls();

public:
    std::map<int,ParticleSystemData*> allData;//用来存储所有的粒子系统的所有发射器数据 

    std::map<std::string,CCTexture2D*> textures;//粒子系统所用的图片 
};


#endif
