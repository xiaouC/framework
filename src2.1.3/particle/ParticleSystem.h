//
//  ParticleSystem.h
//  Stoneage
//
//  Created by gamebean on 12-12-5.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_ParticleSystem_h
#define Stoneage_ParticleSystem_h

#include "Generator.h"
#include "./util/Stream.h"
#include "cocos2d.h"

using namespace cocos2d;

//粒子系统，为实际使用中的实例, 它包含若干个发射器 
class ParticleSystemData;
class ParticleSystem : public cocos2d::CCNode
{
public:
    class PSListener
    {
    public:
        virtual void OnPlayBegin(){}
        virtual void OnPlayEnd(ParticleSystem*){}
    };
public:
    ParticleSystem();
    virtual ~ParticleSystem();

public:
    void Init(const char* name);
    void Reset(const char* name);
	void OnRender(float ft);
    virtual void draw(void);
    virtual void update(float delta);
    void ReBroadcast();//重新播发 
    float positionX;
    float positionY;
    float scaleX;
    float scaleY;
	void  GetPosition(float* x, float* y)
	{
		*x = positionX;
		*y = positionY;
	}
    inline void SetPosition(float x, float y){
        positionX = x;
        positionY = y;
    }
    void SetPositionX( float x ) { positionX = x; }
    void SetPositionY( float y ) { positionY = y; }
    inline PSListener*   GetListener(){return listener;}
    inline void SetListener(PSListener* ls){this->listener=ls;}
    void        setHide(bool flag){this->hide = flag;}
    inline void SetScale(float x, float y)
    {
        scaleX = x;
        scaleY = y;
    }

	// 获取纹理
	int getTextureCount();
	const char *getTextureName(int idx);

public:    
    #define MaxFPS   30              // 最大刷新帧数为跟解析度相同,设置为30fps 
    #define FrameTime  1.0f / MaxFPS   // 最短间隔时间 

    PSListener* listener;
    std::vector<Generator*> generatorPool;//存储单个粒子系统中的所有发射器 
    
    particle::CONSTANT_Utf8 name;
    int version;
    bool repeat;//是否重复播放 
    float age; // 粒子系统的当前生命值     
	float life; //通过子系统计算得出 粒子系统的生命周期 
	bool isVisible; // 是否可见 
    float playTime;//已经播放了多长时间 
    float maxPlayTime;//最大播放时间 
    float eTime;//用于存储临时时间 
    float positionZ;
    float offsetX;
    float offsetY;
    float offsetZ;

    unsigned int loopCnt;//重复播放次数 

    int callBackData;//用于回调 区别类别 
    bool hide;
    bool preObj;
    float   callBackTime;//用于播放倒2/3等 节点callback 
    bool    isCBTime;
    bool    isSendCB;// 用去区别  时间短回调 结束回调标识 
    float   delayTime;
    static cocos2d::CCGLProgram* shader;
    static bool shaderInitialized;

	// 注册完成回调函数
	void registerPlayEndCallbackHandler(int nLuaHander);

	// 获取该特效的时间长度
	float getTimeLength() { return life; }

    // 取消无限循环
    void stopInfiniteLoop() { repeat = false; loopCnt = 0; }

private:
	void callPlayEndCallbackHandler();	// 调用结束脚本
	void unregisterPlayEndCallbackHandler();
	int m_nPlayEndCallbackHandler;		// 结束回调句柄
	ParticleSystemData *m_psd;			// ParticleSystemData引用
};

class ParticleSystemData
{
public:
    ParticleSystemData();
    ~ParticleSystemData();
public:
	int   nRef;						// 引用计数
    float offsetX;
    float offsetY;
    float offsetZ;
    particle::CONSTANT_Utf8 name;
    int version;
    bool repeat;					 // 是否重复播放 
    
    std::vector<GeneratorData*>* gds;//发射器数据 
    void LoadFromStream(particle::InputStream& is, const char* pname);
};
#endif
