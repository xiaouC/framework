//
//  ParticleSystem.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-5.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "ParticleSystem.h"
#include "ParticleSystemManager.h"
#include "./util/UTF8.h"
#include "CCLuaEngine.h"
#include "MC/AssetsManager.h"

ParticleSystem::ParticleSystem()
{
    version = 1;
    age = 0;
    life = 2;
    isVisible = true;
    eTime = 0;
    playTime = 0;
    maxPlayTime = 2147483647;//INT32_MAX
    
    positionZ = 0;
    offsetX = 0;
    offsetY = 0;
    offsetZ = 0;
    
    positionX = 0;
    positionY = 0;
    scaleX = 1;
    scaleY = 1;

    loopCnt = 2147483647;//INT32_MAX
    listener = NULL;
    callBackData = 0;
    hide = false;
    preObj = false;
    callBackTime = 0.0f;
    isCBTime = false;
    isSendCB = false;
    delayTime = 0.0f;

	m_nPlayEndCallbackHandler = 0;

	m_psd = NULL;
}

ParticleSystem::~ParticleSystem()
{
	unregisterPlayEndCallbackHandler();

    for(int i = 0; i < generatorPool.size(); i ++){
        delete generatorPool[i];
    }
    generatorPool.clear();

	if (m_psd) {
		m_psd->nRef--;
		m_psd = NULL;
	}
}

void ParticleSystem::ReBroadcast()
{
    age = 0;
    for (int i = 0; i < generatorPool.size(); i++) {
        Generator* generator = generatorPool[i];
        if(!generator->genData->gb->repeat){
            generator->Reset();
        }
    }
}
void ParticleSystem::Reset(const char* name)
{
    
    for(int i = 0; i < generatorPool.size(); i ++){
        delete generatorPool[i];
    }
    generatorPool.clear();
    version = 1;
    age = 0;
    life = 2;
    isVisible = true;
    eTime = 0;
    playTime = 0;
    maxPlayTime = 2147483647;//INT32_MAX
    
    positionZ = 0;
    offsetX = 0;
    offsetY = 0;
    offsetZ = 0;
    
    loopCnt = 2147483647;//INT32_MAX
    listener = NULL;
    callBackData = 0;
    hide = false;
    preObj = false;
    callBackTime = 0.0f;
    isCBTime = false;
    isSendCB = false;
    delayTime = 0.0f;
    Init(name);
}

void ParticleSystem::Init(const char* name)
{
    // CCLog( "particle ParticleSystem::Init( %s )", name );
	if (m_psd) {
		m_psd->nRef--;
		m_psd = NULL;
	}

	std::map<int, ParticleSystemData*>& allData = ParticleSystemManager::sharedParticleSystemManager()->allData;
	ParticleSystemData* psd = NULL;
	int nHasValue = particle::UTF8Hash(name);
    std::map<int, ParticleSystemData*>::iterator it = allData.find(nHasValue);
    if( it == allData.end() )
	{
		char path[256];
		sprintf(path, "particles/%s.par", name);
		unsigned long size = 0;
		char* pFileContent = (char*)AssetsManager::sharedAssetsManager()->getFileContent( path, "rb", &size );
		if(pFileContent)
		{
			particle::InputStream is( pFileContent, (int)size );
			psd = new ParticleSystemData;
			psd->LoadFromStream( is, NULL );
			allData[nHasValue] = psd;
            delete[] pFileContent;
		}
		else
		{
			CCLOG( "can't load particle [%s]", name );
		}
	}
	else
	{
		psd = it->second;
	}

	if(psd == NULL)
	{
		return;
	}

    float curTime = 0;
    float maxTime = 0;
    if( psd != NULL )
    {
        for( int i = 0; i < psd->gds->size(); ++i )
        {
            Generator* g = new Generator(psd->gds->at(i));//创建发射器 
            for(int j = 0; j < g->genData->allSpace.size(); ++j )
            {
                ParticleSpace* ps = new ParticleSpace();
                g->sim.push_back(ps); // 初始化粒子发射空间 
            }
            generatorPool.push_back(g);//存储发射器 
                
            curTime = g->genData->gb->bias + g->genData->gb->lifeTime + g->genData->pb->particleMaxlife;//计算粒子系统的生命周期 
            curTime = g->genData->gb->bias + g->genData->gb->lifeTime + g->genData->pb->particleMaxlife;//计算粒子系统的生命周期 
            if(curTime>maxTime){//取最大值 
                maxTime=curTime;
            }                
        }
        life = maxTime;
        this->name = psd->name.Data();
        version = psd->version;
        offsetX = psd->offsetX;
        offsetY = psd->offsetY;
        offsetZ = psd->offsetZ;
        repeat = psd->repeat;
    }
	m_psd = psd;
	m_psd->nRef++;
}

CCGLProgram* ParticleSystem::shader = NULL;
bool ParticleSystem::shaderInitialized = false;
void ParticleSystem::draw()
{
    if( ! shaderInitialized ) {
        shader = CCShaderCache::sharedShaderCache()->programForKey(kCCShader_PositionTextureColor);
        shaderInitialized = true;
    }
    
    CHECK_GL_ERROR_DEBUG();
    if(delayTime > 0)
    {
        return ;
    }
    if(isVisible && !hide){
        int size = generatorPool.size();
        for (int i = 0; i < size; i++) {
            Generator* generator = generatorPool[i];
            if(generator != NULL){
                kmGLPushMatrix();
                if(!generator->genData->isRendToWorld){
                    kmGLTranslatef(positionX, positionY, 0);
                    kmGLScalef(scaleX, scaleY, 1);
                }
                kmGLScalef(1, -1, 1);//把cocos2d-x的坐标系转换为左下角为中心的坐标系 
                generator->OnRender(- offsetX, - offsetY);
                kmGLPopMatrix();
            }
        }
    }

#if CC_ENABLE_GL_STATE_CACHE
	ccGLBlendResetToCache();
#endif
    
	CHECK_GL_ERROR_DEBUG();
}

void ParticleSystem::OnRender(float ft)
{
//    if(delayTime > 0)
//    {
//        return ;
//    }
//    if(isVisible && !hide){
//        int size = generatorPool.size();
//        for (int i = 0; i < size; i++) {
//            Generator* generator = generatorPool[i];
//            if(generator != NULL){
//                RenderUtil::Save();
//                if(!generator->genData->isRendToWorld){
//                    RenderUtil::Translate(positionX, positionY);
//                    RenderUtil::Scale(scaleX, scaleY);
//                }
//            
//                generator->OnRender(ft, - offsetX, - offsetY);
//                RenderUtil::Restore();
//            }
//        }
//  
//    }
}

void ParticleSystem::update(float ft)
{
    if(hide || !isVisible){
        //ParticleSystemManager::sharedParticleSystemManager()->deleteParticle(this);
        for(int i = 0; i < generatorPool.size(); i ++){
            delete generatorPool[i];
        }
        generatorPool.clear();
        removeFromParentAndCleanup(true);
        return;}
    //ft = FrameTime*2;
    if(delayTime > 0)
    {
        delayTime -=ft;
        if(delayTime <= 0){
            delayTime = 0.0f;
        }
        return ;
    }
    playTime += ft;
    if(age == 0 && listener != NULL){
        listener->OnPlayBegin();
    }
    
    eTime += ft;
    
    if (eTime < FrameTime){ //小于粒子系统的单帧时间，不更新 
        return;
    }
    
    while (eTime >= FrameTime) {//判断当延时时，将对该系统进行补偿刷新，所以发射器会按预设频率刷新 
        eTime -= FrameTime;
        age += FrameTime;
        if (age > life) {
            if(loopCnt > 0){
                loopCnt--;
            }
            if (repeat && loopCnt > 0) {                               
                age = ParticleUtil::RemFloat(age, life);
                for (int i = 0; i < generatorPool.size(); i++) {
                    Generator* generator = generatorPool[i];
                    if(!generator->genData->gb->repeat){
                        generator->Reset();
                    }
                }                
            } else {
                if(listener != NULL && isVisible && !isSendCB){
                    listener->OnPlayEnd(this);
                }
				callPlayEndCallbackHandler();
                isVisible = false;
                break;
            }
        }else if(isCBTime)
        {
            const static float Accuracy = 1.0f / MaxFPS;
            if((age + Accuracy >= callBackTime) && (age - Accuracy <= callBackTime))
            {
                isCBTime = false;
                if(listener != NULL && isVisible){
                    isSendCB = true;
                    listener->OnPlayEnd(this);
                }
				callPlayEndCallbackHandler();
            }
        }
        
        for (int i = 0; i < generatorPool.size(); i++) {
            Generator* generator = generatorPool[i];
            if(generator != NULL){
                if(generator->genData->isRendToWorld){
                    generator->position.Set(positionX*scaleX, -positionY*scaleY, 0);
                }else{
                    generator->position.Set(0, 0, 0);
                }
                generator->OnUpdate(FrameTime);
            }
        }
    }
}

void ParticleSystem::registerPlayEndCallbackHandler( int nLuaHander )
{
	unregisterPlayEndCallbackHandler();
	m_nPlayEndCallbackHandler = nLuaHander;
}

void ParticleSystem::unregisterPlayEndCallbackHandler()
{
	if (m_nPlayEndCallbackHandler)
	{
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nPlayEndCallbackHandler );
		m_nPlayEndCallbackHandler = 0;
	}
}

void ParticleSystem::callPlayEndCallbackHandler()
{
	if (m_nPlayEndCallbackHandler)
		CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler(m_nPlayEndCallbackHandler, 0);
}

int ParticleSystem::getTextureCount()
{
	if (m_psd == NULL || m_psd->gds == NULL)
		return 0;

	return m_psd->gds->size();
}

const char *ParticleSystem::getTextureName(int idx)
{
	if (idx < 0 || idx >= getTextureCount())
		return NULL;

	GeneratorData *pData = m_psd->gds->at(idx);
	return pData->pr->textureName.Data();
}

//---------------------------
ParticleSystemData::ParticleSystemData()
{
    gds = new std::vector<GeneratorData*>();
	nRef = 0;
}

ParticleSystemData::~ParticleSystemData()
{
    if(gds != NULL){
        for(int i = 0; i < gds->size(); i ++){
            delete gds->at(i);
        }
        gds->clear();
        delete gds;
        gds = NULL;
    }
}

void ParticleSystemData::LoadFromStream(particle::InputStream& is, const char* pname)
{
	if(pname == NULL)
	{
		name.Read4HeadUTF(is);
	}
	else
	{
		name = pname;
	}
//    XCLOG("离子对应 name=%s", name.Data());
    version = is.ReadInt();
    offsetX = ParticleUtil::Float_Java2C(is.ReadFloat());
    offsetY = ParticleUtil::Float_Java2C(is.ReadFloat());
    offsetZ = ParticleUtil::Float_Java2C(is.ReadFloat());
    repeat = is.ReadBoolean();
    int count = is.ReadShort();
    for(int i = 0; i < count; i ++){
        GeneratorData* gd = new GeneratorData();
        gd->Load(is);//读取发射器数据 
        gds->push_back(gd);//存储发射器数据 
    }
}
