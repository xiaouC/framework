#pragma once

#include "cocos2d.h"
#include "anim.pb.h"

USING_NS_CC;

typedef void(CCObject::*PlayEndCallbackFuncPtr2)( unsigned long ulUserData );

class TLModel : public CCSpriteBatchNode
{
public:
	CCRect mcBoundingBox;

	TLModel(bool bAsync, float uvScale=1.f);
	virtual ~TLModel();

	static TLModel* createWithName(const char* mcName, bool bAsync = false, float uvScale=1.f);

	bool initWithName( const char* mcName );


	void setFrameColor(const ccColor4B& color);	// 每帧都会变化的 颜色值 
	void clearFrameColor();
	const ccColor4B& getFrameColor(void);		// 获取帧颜色 

	virtual void update( float dt );
	void SetPreCallScript(int nLuaPreCallScript);

	// 设置LUA注册 
	void RegisterPreCallScript(int nLuaHandle);
	void UnRegisterPreCallScript();
public:
	bool initWithSymbol( const framework::Symbol* sym );

	 /**
     * @startFrame      从哪一帧开始 
     * @durationFrame   播多少帧，-1表示不限制，0表示不播放动画 
     * @loop            循环次数 -1表示无限循环, 0 不循环, 正数表示循环次数 
     */
    void play( int startFrame, int durationFrame, int loopCount = 0, bool reverse = false );
	void start();
	void stop();
	void setAutoClear(bool reset) { m_autoClear = reset; }
	bool getAutoClear() { return m_autoClear; }
	//void setWrapAround(bool wrapAround) { m_wrapAround = wrapAround; }
	//bool getWrapAround() { return m_wrapAround; }
	void setFrameRate(int rate) { m_frameRate = rate; };
	int getFrameRate() { return m_frameRate; }
	const framework::Symbol* getSymbolInfo() { return m_symbolInfo; };
	virtual void removeAllChildrenWithCleanup(bool cleanup);

	float getTimeLength( int nFrameRate = -1 );

	// 获得某个图层的当前帧 
	void  getLayerFirstNodePosition(const char *szLayerName, float* x = 0, float* y = 0);
	// int  getCurrentFrame(int iLayer);

	const std::string getTextureName();
public:
	bool m_bAsync;
	bool m_bPlay;

	bool getIsPlaying() const { return m_playing; }

private:
	const framework::Symbol* m_symbolInfo; // 符号信息 
	int m_frameRate;            // 帧速 (1秒钟播多少帧，每帧时间 1/帧速) 
	float m_uvScale;			// UV缩放值 

	float m_startTime;          // 开始帧时间 
	float m_endTime;            // 结束帧时间 
	float m_elapsed;            // 逝去的时间 
	int   m_nMoveObjectId;		// 对象ID 

	std::vector<CCArray*> m_layers;         // 图层容器 
	std::vector<int> m_currentKeyFrames;    // 当前关键帧索引 
	std::vector<int> m_keyFramesScript;		// 脚本执行到哪一个关键帧 

	int m_loopCount;              // 循环次数 
	bool m_reverse;                // 是否倒播 
	bool m_autoClear;        // 在关键帧是否重置子节点 
	//bool m_wrapAround;        // 适用与循环播放的动画，忽视最后帧的补间。 
	bool m_playing;             // 正在播放	 

	void setKeyframe(CCArray* keyframes, int keyframeIdx, float progress);
	void resetLayer(int iLayer, int iKeyframe);
	void updateLayer(int iLayer);
	void updateKeyframe(int iLayer, int keyframeIdx, float progress);
	void executeKeyframeScript(int iLayer, int iKeyframe);
	void clear();
	void addLayerChild(int iLayer, CCNode *pNode);
	void removeLayerChild(int iLayer, CCNode *pNode, bool cleanup);
	
public:
	bool RegisterPlayEndCallbackHandler( int nPlayEndHandler );

	bool RegisterPlayEndCallback( CCObject* pCallbackObject, PlayEndCallbackFuncPtr2 pPlayEndCallFuncPtr, unsigned long ulUserData = 0xFFFFFFFF );

protected:
	int m_nPlayEndHandler;
	int m_nLuaPreCallScript;
	int m_nRegLuaPreCallScript;	// 注册的 

	//////////////////////////////////////////////////////////////////////////
	CCObject* m_pPlayEndCallbackObject;
	PlayEndCallbackFuncPtr2 m_pPlayEndCallFuncPtr;
	unsigned long m_ulUserData;

//	ccColor4B m_frameColor;		// 帧颜色 
	bool	  m_bUseFrameColor; // 是否使用帧颜色 
};

