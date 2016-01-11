//
//  ParticleSystemManager.cpp
//  Stoneage
//
//  Created by fanxiaoli on 12-12-16.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "ParticleSystemManager.h"
#include "Util.h"
#include "./util/UTF8.h"
#include "./space/CircleGeneratorSpace.h"
#include "./space/PointGeneratorSpace.h"
#include "./space/RectGeneratorSpace.h"
#include "./space/LineGeneratorSpace.h"
#include "./space/PathGeneratorSpace.h"
#include "ParticleRender.h"
#include "./modifier/GenericForce.h"
#include "./modifier/AirFriction.h"
#include <algorithm>
#include "../MC/MCLoader.h"
#include "../MC/AssetsManager.h"

ParticleSystemManager* ParticleSystemManager::sharedParticleSystemManager()
{
    static ParticleSystemManager self;
    return &self;
}

ParticleSystem* ParticleSystemManager::createWithName( CCNode* node, CCPoint point, int zOder, const char* name, bool loop, float time, bool bNormalSchedule )
{
    ParticleSystem* ps = new ParticleSystem;
    if( ps != NULL )
    {
        ps->Init( name );
        ps->repeat = loop;

        node->addChild( ps );

        if( loop && time > ps->life )
            ps->maxPlayTime = time;

        if( bNormalSchedule )
        {
            ps->scheduleUpdate();
        }
        else
        {
            CCDirector::sharedDirector()->getPauseScheduler()->scheduleUpdateForTarget( ps, 0, false );
        }

        ps->setPosition(point);
        ps->autorelease();
    }

    return ps;
}

ParticleSystem* ParticleSystemManager::createWithNameLua( CCNode* node, int x, int y, const char* name, int loopCnt, bool bNormalSchedule )
{
    ParticleSystem* ps = new ParticleSystem;
    if( ps != NULL )
    {
        ps->Init( name );

        node->addChild( ps );

        if( loopCnt > 0 )
        {
            ps->repeat = true;
            ps->loopCnt = loopCnt;
        }

        if( bNormalSchedule )
        {
            ps->scheduleUpdate();
        }
        else
        {
            CCDirector::sharedDirector()->getPauseScheduler()->scheduleUpdateForTarget( ps, 0, false );
        }
        ps->setPosition(x, y);
        ps->autorelease();
    }

    return ps;
}

ParticleSystemManager::ParticleSystemManager()
{
    ParticleSpace::Init();//初始化粒子缓冲源池
    ParticleUtil::InitUtil();//初始化util的float随机数缓冲池
}

ParticleSystemManager::~ParticleSystemManager()
{
    for(std::map<int, ParticleSystemData*>::iterator it = allData.begin(); it != allData.end(); it ++){
        ParticleSystemData* v = it->second;
        delete v;
    }
    allData.clear();

    std::map<std::string,CCTexture2D*>::iterator iter = textures.begin();
    std::map<std::string,CCTexture2D*>::iterator iter_end = textures.end();
    for( ; iter != iter_end; ++iter )
        iter->second->release();
    textures.clear();
}

CCTexture2D* ParticleSystemManager::GetImage( const std::string& strTexFile )
{
    //CCLog( "particle GetImage( %s )", strTexFile.c_str() );
    std::map<std::string,CCTexture2D*>::iterator iter = textures.find( strTexFile );
    if( iter != textures.end() )
        return iter->second;

    CCTexture2D* tex = MCLoader::sharedMCLoader()->loadTexture( strTexFile );
    if( tex != NULL )
    {
        textures[strTexFile] = tex;
        tex->retain();
        //tex->setAntiAliasTexParameters();           //抗锯齿(线性过滤)
    }

    return tex;
}

void ParticleSystemManager::cleanupCache()
{
	//for(std::map<int, ParticleSystemData*>::iterator it = allData.begin(); it != allData.end(); ){
	//	ParticleSystemData* v = it->second;
	//	if (v->nRef <= 0)
	//	{
	//		delete v;
	//		std::map<int, ParticleSystemData*>::iterator ittmp = it;
	//		it++;
	//		allData.erase(ittmp);
	//	}
	//	else
	//	{
	//		++it;
	//	}
	//}
	//
	for (std::map<std::string,CCTexture2D*>::iterator iter = textures.begin(); iter != textures.end(); ++iter)
	{
		iter->second->release();
	}
	textures.clear();
}

ParticleSystem* ParticleSystemManager::AddParticlesSystem(CCNode* node,CCPoint point,int zOder,const char* psName, bool loop, float time, ParticleSystem::PSListener* listener)
{
    ParticleSystem* ps = new ParticleSystem();
    ps->Init(psName);
    if(ps != NULL){
        node->addChild(ps,zOder);
        ps->repeat = loop;
        if(loop && time > ps->life){//循环播放
            ps->maxPlayTime = time;
        }
        ps->setPosition(point);
        ps->SetListener(listener);
        //addParticle(ps);
        return ps;
    }
    return NULL;
}

ParticleSystem* ParticleSystemManager::AddParticlesSystem( CCNode* node, int x, int y, const char* psName, int loopCnt, ParticleSystem::PSListener* listener )
{
    ParticleSystem* ps = new ParticleSystem();
    ps->Init(psName);
    if(ps != NULL){
        node->addChild(ps);
        if(loopCnt > 0){
            ps->repeat = true;
            ps->loopCnt = loopCnt;
        }
        ps->setPosition(x, y);
        ps->SetListener(listener);
        //addParticle(ps);
        return ps;
    }
    return NULL;
}

void ParticleSystemManager::LoadParticleSystems( const char* fileName )
{
#if 0
	struct cc_timeval t1,t2,t3;
	CCTime::gettimeofdayCocos2d(&t1, NULL);

    unsigned long size = 0;
    char* pFileContent = (char*)AssetsManager::sharedAssetsManager()->getFileContent( fileName, "rb", &size );
	CCTime::gettimeofdayCocos2d(&t2, NULL);

    particle::InputStream is( pFileContent, (int)size );
    if( is.Available() )
    {
        CCLog( "is.Available()" );
        int count = is.ReadShort();
        for( int i=0; i < count; ++i )
        {
            ParticleSystemData* psd = new ParticleSystemData;
            psd->LoadFromStream( is );
			int nHasValue = particle::UTF8Hash((char*)psd->name.Data());
			if (allData.find(nHasValue) != allData.end())
			{
				CCLOGERROR ("Particle Name redefine!!! =[%s]", psd->name.Data());
				delete psd;
				psd = NULL;
				continue;
			}
            allData[nHasValue] = psd;
        }
    }
	CCTime::gettimeofdayCocos2d(&t3, NULL);

	CCLOG("par 2 = %lf", CCTime::timersubCocos2d(&t1, &t2));
	CCLOG("par 3 = %lf", CCTime::timersubCocos2d(&t2, &t3));
	CCLOG("par = %lf", CCTime::timersubCocos2d(&t1, &t3));
#endif
}

void ParticleSystemManager::splitParticls()
{
	const char* particleBins[] = {
		"/particles/normal.bin",
		"/particles/ui.bin"
	};

	for(int i=0; i<2; ++i)
	{
		unsigned long size = 0;
		char* pFileContent = (char*)AssetsManager::sharedAssetsManager()->getFileContent( particleBins[i], "rb", &size );
		particle::InputStream is( pFileContent, (int)size );
		if( is.Available() )
		{
			int count = is.ReadShort();
			for( int i=0; i < count; ++i )
			{
				ParticleSystemData* psd = new ParticleSystemData;
				int startOffset = is.Offset();
				psd->LoadFromStream( is, NULL );
				//startOffset += psd->name.Length()+1;
				int endOffset = is.Offset();

				std::string path = CCFileUtils::sharedFileUtils()->getWritablePath() + "particles/" + psd->name.Data() + ".par";
				FILE* pf = fopen(path.c_str(), "wb");
				if(pf)
				{
					int n = fwrite(pFileContent+startOffset, 1, endOffset-startOffset, pf);
					fclose(pf);
					CCLOG("exported %s", path.c_str());
				}
				else
				{
					CCLOG("can't export %s", path.c_str());
				}
			}
		}
		else
		{
			CCLOG("can't load file %s", particleBins[i]);
		}
	}
}
