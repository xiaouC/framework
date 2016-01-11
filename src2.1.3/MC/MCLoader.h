#pragma once
#include "cocos2d.h"
#include "textures/CCTexture2D.h"
#include "anim.pb.h"
#include "../Common/TLCommon.h"

USING_NS_CC;

class LoadTextureAsyncCallback: public CCObject
{
public:
	LoadTextureAsyncCallback();
	~LoadTextureAsyncCallback();

	static LoadTextureAsyncCallback* create( int nHandler );

	void execute( CCTexture2D* pTexture );

protected:
	int m_nCallbackHandler;
};

struct loadSpriteAsyncInfo
{
	std::string strFrameName;
	CCSprite* pSprite;
	bool bInPlist;
	std::string strTexturePath;
	int nTextureIndex;
    int nCallbackHandler;
};

struct loadTextureCallbackInfo
{
    CCTexture2D* pTexture;
    int nRequestID;
    int nTextureIndex;
};

class MCLoader : public CCObject
{
public:
	MCLoader();
	virtual ~MCLoader();

	static MCLoader* sharedMCLoader();

	void loadIndexFile( const char* animIndexFile, const char* plistIndexFile );
	void clearIndexFile();

    void processLoadTextureCallback();

public:
	const framework::Symbol* getSymbol( const char* symName );

	std::string getTexturePath( const std::string& filePath );

protected:
	std::map<std::string,std::string> m_AnimIndex;
	framework::FrameList* m_pFrameList;
	std::map<std::string,const framework::Frame*> m_frames;
	std::map<std::string,const framework::Symbol*> m_symbols;
	std::list<framework::Anim*> m_anims;

public:
	CCTexture2D* createTexture(const char* name, int w, int h);
	CCTexture2D* loadTextureByFrame( const std::string& filePath );
	const std::string getFrameTexture(const std::string& frameName);
	CCTexture2D* loadTexture( const std::string& filePath );
	void loadTextureAsync( const char* texFile, int nCallbackHandler );

	CCSpriteFrame* loadSpriteFrame( const char* frameName );
	CCSprite* loadSprite( const char* frameName );

	CCSprite* loadSpriteAsync( const char* frameName );
	CCSprite* loadSpriteAsyncCallback( const char* frameName, int nCallbackHandler );
	void loadSpriteFrameAsync( const char* frameName, CCSprite* pSprite );
	void loadSpriteFrameAsync( const char* frameName, int nRequestID, loadSpriteAsyncInfo* lsaInfo );

	void loadTextureCallback( CCObject* obj, int nRequestID, int nTextureIndex );

	std::string getRequestTexturePath( int nRequestID );

    CCTexture2D* getDefaultTexture() { return m_pDefaultTexture; }

protected:
	CCTexture2D* m_pDefaultTexture;

	std::map<int,loadSpriteAsyncInfo*> m_mapLoadSpriteAsyncInfo;
	std::map< std::string, std::list<int> > m_mapRequestTextures;

    XL_LOCK m_kCallbackLock;
    std::list<loadTextureCallbackInfo*> m_listLoadTextureCallback;

	int m_nNextRequestID;
	int GetNextRequestID() { return ++m_nNextRequestID; }
};

class MovieClip;
class TLModel;
class MCFrame;
class TLLabelRichTex;
class TLRenderNode;

MovieClip*				toMovieClip( CCNode* node );
TLModel*				toTLModel( CCNode* node );
CCSprite*				toSprite( CCNode* node );
CCLabelTTF*			toTTFText( CCNode* node );
TLLabelRichTex*			toTLRichTex( CCNode* node );
CCLabelBMFont*			toBMText( CCNode* node );
CCLayerColor*			toRect( CCNode* node );
MCFrame*				toFrame( CCNode* node );
CCParticleSystem*		toParticle( CCNode* node );
TLRenderNode*           toRenderNode( CCNode* node );
CCRect				getBoundingBox( CCNode* node, bool bOrigin = false );
