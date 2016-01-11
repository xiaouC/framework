#pragma once
#include "cocos2d.h"
#include "anim.pb.h"

USING_NS_CC;

class StaticUIMC : public CCNodeRGBA
{
public:
	CCRect mcBoundingBox;

	StaticUIMC();
	virtual ~StaticUIMC();

	bool init( const framework::Layer* layer );

protected:
	CCRect mcOriginBoundingBox;

	CCSpriteBatchNode* m_pkStaticUIBatchNode;

public:
	static void setStaticUITextureFile( const std::string& strTextureName ) { m_strTextureName = strTextureName; }

protected:
	static std::string m_strTextureName;
};

typedef void(CCObject::*PlayEndCallbackFuncPtr)( unsigned long ulUserData );

class MovieClip : public CCNodeRGBA
{
public:
	CCRect mcOriginBoundingBox;
	CCRect mcBoundingBox;

	MovieClip( bool bAsync );
	virtual ~MovieClip();

	static MovieClip* createWithName( const char* mcName, bool bAsync = false );

	bool initWithName( const char* mcName );

	virtual void update( float dt );

    virtual void setScaleX(float fScaleX);
    virtual void setScaleY(float fScaleY);
    virtual void setScale(float scale);

public:
	bool initWithSymbol( const framework::Symbol* sym );

	 /**
     * @startFrame      从哪一帧开始
     * @durationFrame   播多少帧，-1表示不限制，0表示不播放动画
     * @loop            循环次数 -1表示无限循环, 0 不循环, 正数表示循环次数
     */
    void play( int startFrame, int durationFrame, int loopCount = 0, bool reverse = false );
	void start();
	void pause();
	void setAutoClear(bool reset) { m_autoClear = reset; }
	bool getAutoClear() { return m_autoClear; }
	bool getResetKeyframe() { return m_resetKeyframe; }
	bool setResetKeyframe(bool reset) { m_resetKeyframe = reset; return true; }
	//void setWrapAround(bool wrapAround) { m_wrapAround = wrapAround; }
	//bool getWrapAround() { return m_wrapAround; }
	void setFrameRate(int rate) { m_frameRate = rate; };
	int getFrameRate() { return m_frameRate; }
	const framework::Symbol* getSymbolInfo() { return m_symbolInfo; };
	virtual void removeAllChildrenWithCleanup(bool cleanup);

	float getTimeLength( int nFrameRate = -1 );
    int getFrameCount();

public:
	bool m_bAsync;
	bool m_bPlay;

	bool getIsPlaying() const { return m_playing; }

private:
	const framework::Symbol* m_symbolInfo; // 符号信息
	int m_frameRate;            // 帧速 (1秒钟播多少帧，每帧时间 1/帧速)

	float m_startTime;          // 开始帧时间
	float m_endTime;            // 结束帧时间
	float m_elapsed;            // 逝去的时间

	std::vector<CCArray*> m_layers;         // 图层容器
	std::vector<int> m_currentKeyFrames;    // 当前关键帧索引

	int m_loopCount;              // 循环次数
	bool m_reverse;                // 是否倒播
	bool m_autoClear;        // 在关键帧是否重置子节点
	//bool m_wrapAround;        // 适用与循环播放的动画，忽视最后帧的补间。
	bool m_playing;             // 正在播放
	bool m_resetKeyframe;       // 是否在关键帧的时候重建元素

	void setKeyframe(CCArray* keyframes, int keyframeIdx, float progress);
	void resetLayer(int iLayer, int iKeyframe);
	void updateLayer(int iLayer);
	void updateKeyframe(int iLayer, int keyframeIdx, float progress);
	void clear();
	void addLayerChild(int iLayer, CCNode *pNode);
	void removeLayerChild(int iLayer, CCNode *pNode, bool cleanup);
	
public:
	bool RegisterPlayEndCallbackHandler( int nPlayEndHandler );

	bool RegisterPlayEndCallback( CCObject* pCallbackObject, PlayEndCallbackFuncPtr pPlayEndCallFuncPtr, unsigned long ulUserData = 0xFFFFFFFF );

protected:
	int m_nPlayEndHandler;

	//////////////////////////////////////////////////////////////////////////
	CCObject* m_pPlayEndCallbackObject;
	PlayEndCallbackFuncPtr m_pPlayEndCallFuncPtr;
	unsigned long m_ulUserData;
};

