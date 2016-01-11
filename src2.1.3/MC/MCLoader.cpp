#include "MCLoader.h"
#include "AssetsManager.h"
#include "CCLuaEngine.h"
#include "MCFrame.h"
#include "MovieClip.h"
#include "../UI/TLRenderNode.h"
#include "../Common/TLModel.h"

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//#define COMPRESSED_TEXTURE_SUFFIX ".pvrtc"
//#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//#define COMPRESSED_TEXTURE_SUFFIX ".pkm"
//#else
//#define COMPRESSED_TEXTURE_SUFFIX ".lh"
//#endif

//FILE* debug_file = NULL;
//void write_debug_info( const char* szMsg )
//{
//	if( debug_file == NULL )
//	{
//		std::string texLogPath = CCFileUtils::sharedFileUtils()->getWritablePath() + "tex_debug.txt";
//		debug_file = fopen( texLogPath.c_str(), "w+" );
//	}
//
//	fprintf( debug_file, "%s\n", szMsg );
//	fflush( debug_file );
//}

LoadTextureAsyncCallback::LoadTextureAsyncCallback()
: m_nCallbackHandler(0)
{
}

LoadTextureAsyncCallback::~LoadTextureAsyncCallback()
{
	if( m_nCallbackHandler != 0 )
	{
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nCallbackHandler );
		m_nCallbackHandler = 0;
	}
}

LoadTextureAsyncCallback* LoadTextureAsyncCallback::create( int nHandler )
{
	LoadTextureAsyncCallback* pRet = new LoadTextureAsyncCallback;

	if( pRet != NULL )
	{
		pRet->m_nCallbackHandler = nHandler;
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE( pRet );
	return NULL;
}

void LoadTextureAsyncCallback::execute( CCTexture2D* pTexture )
{
	if( m_nCallbackHandler != 0 )
	{
        int numArgs = 0;
        if( pTexture )
        {
            numArgs = 1;
            CCLuaEngine::defaultEngine()->getLuaStack()->pushCCObject( pTexture, "CCTexture2D" );
        }

		CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nCallbackHandler, numArgs );

		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nCallbackHandler );
		m_nCallbackHandler = 0;
	}
}

//////////////////////////////////////////////////////////////////////////
MCLoader* g_pMCLoader = NULL;
MCLoader::MCLoader()
: m_pFrameList(NULL)
, m_nNextRequestID(0)
{
    LockInit( m_kCallbackLock );

	m_pDefaultTexture = loadTexture( "default.png" );
	if ( m_pDefaultTexture != NULL )
	{
		m_pDefaultTexture->retain();
	}
}

MCLoader::~MCLoader()
{
    LockRelease( m_kCallbackLock );
}

MCLoader* MCLoader::sharedMCLoader()

{
	if( g_pMCLoader == NULL )
		g_pMCLoader = new MCLoader;

	return g_pMCLoader;
}

void MCLoader::loadIndexFile( const char* animIndexFile, const char* plistIndexFile )
{
	// support reload 
	clearIndexFile();

	// animation index file
	unsigned long iSize = 0;
	unsigned char* pBuffer = AssetsManager::sharedAssetsManager()->getFileContent( animIndexFile, "rb", &iSize );
	CCAssert(pBuffer!=NULL, "get index buffer failed");

	framework::AnimIndex animIndex;
	animIndex.ParseFromArray((void*)pBuffer, iSize );
	delete[] pBuffer;

	for( int i=0; i < animIndex.anims_size(); ++i )
	{
		const framework::AnimIndexItem& aii = animIndex.anims( i );
		for( int j=0; j<aii.symbols_size(); j++)
		{
			const std::string& key = aii.symbols(j);
#ifdef _DEBUG
			std::map<std::string, std::string>::iterator it= m_AnimIndex.find(key);
			if(it != m_AnimIndex.end())
			{				
				CCLOG("[%s]---[%s]", aii.name().c_str(), m_AnimIndex[key].c_str());
				CCLOG("AnimIndex key %s redefine", key.c_str());
			}
#endif
			m_AnimIndex[key] = aii.name();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	// plist index file
	pBuffer = AssetsManager::sharedAssetsManager()->getFileContent( plistIndexFile, "rb", &iSize );

	m_pFrameList = new framework::FrameList;
	m_pFrameList->ParseFromArray( (void*)pBuffer, iSize );
	delete[] pBuffer;

	for( int i=0; i < m_pFrameList->frames_size(); ++i )
	{
		const framework::Frame& frame = m_pFrameList->frames( i );

		const std::string& key = frame.name();
#ifdef _DEBUG
		std::map<std::string,const framework::Frame*>::iterator it1 = m_frames.find(key);
		if(it1 != m_frames.end())
		{
			int nIndex = it1->second->filename();
			std::string filepath1 = m_pFrameList->filenames( nIndex );
			std::string filepath2 = m_pFrameList->filenames( m_frames[key]->filename() );
			CCLOG("[%s]---[%s]", filepath1.c_str(), filepath2.c_str());
			CCLOG("FrameIndex key %s redefine", key.c_str());
		}
#endif
		m_frames[key] = &frame;
	}
}

void MCLoader::clearIndexFile()
{
	m_symbols.clear();

	m_AnimIndex.clear();
	m_frames.clear();

	if( m_pFrameList != NULL )
	{
		delete m_pFrameList;
		m_pFrameList = NULL;
	}
}

const framework::Symbol* MCLoader::getSymbol( const char* symName )
{
	std::map<std::string,const framework::Symbol*>::iterator iter = m_symbols.find( symName );
	if( iter != m_symbols.end() )
		return iter->second;

	std::map<std::string,std::string>::iterator iterA = m_AnimIndex.find( symName );
	if( iterA == m_AnimIndex.end() )
		return NULL;

	const std::string& fileName = iterA->second;

	unsigned long iSize = 0;
	unsigned char* pBuffer = AssetsManager::sharedAssetsManager()->getFileContent( fileName.c_str(), "rb", &iSize );

	framework::Anim* anim = new framework::Anim;
	anim->ParseFromArray( (void*)pBuffer, iSize );
	delete[] pBuffer;

	for( int i=0; i < anim->symbols_size(); ++i )
	{
		const framework::Symbol* sym = &anim->symbols( i );
		m_symbols[sym->name()] = sym;
	}
	m_anims.push_back( anim );
	return m_symbols[symName];
}

std::string MCLoader::getTexturePath( const std::string& filePath )
{
	return ::getTexturePath(filePath);
}

CCTexture2D* MCLoader::loadTextureByFrame( const std::string& texFile )
{
	std::string filepath = texFile;

	// 有可能这是一张大贴图里面的一部分
	std::map<std::string,const framework::Frame*>::iterator iter = m_frames.find( std::string(texFile) );
	if( iter != m_frames.end() )
	{
		int nIndex = iter->second->filename();
		filepath = m_pFrameList->filenames( nIndex );
	}

	std::string strFullPath = getTexturePath( filepath );
	return CCTextureCache::sharedTextureCache()->addImage( strFullPath.c_str() );
}

const std::string MCLoader::getFrameTexture(const std::string& texFile)
{
	std::string filepath = texFile;

	// 有可能这是一张大贴图里面的一部分
	std::map<std::string,const framework::Frame*>::iterator iter = m_frames.find( std::string(texFile) );
	if( iter != m_frames.end() )
	{
		int nIndex = iter->second->filename();
		filepath = m_pFrameList->filenames( nIndex );
	}

	return filepath;
}

CCTexture2D* MCLoader::createTexture(const char* name, int w, int h)
{
	return CCTextureCache::sharedTextureCache()->createImage(name, w, h);
}

CCTexture2D* MCLoader::loadTexture( const std::string& filePath )
{
	std::string strFullPath = getTexturePath( filePath );
	return CCTextureCache::sharedTextureCache()->addImage( strFullPath.c_str() );
}

void MCLoader::loadTextureAsync( const char* texFile, int nCallbackHandler )
{
	std::string filepath = texFile;

	// 有可能这是一张大贴图里面的一部分
	std::map<std::string,const framework::Frame*>::iterator iter = m_frames.find( std::string(texFile) );
	if( iter != m_frames.end() )
	{
		int nIndex = iter->second->filename();
		filepath = m_pFrameList->filenames( nIndex );
	}
	else
	{
		filepath = getTexturePath(filepath);
	}

	LoadTextureAsyncCallback* callback = LoadTextureAsyncCallback::create( nCallbackHandler );
	CCTextureCache::sharedTextureCache()->addImageAsync( filepath.c_str(), callback, callfuncO_selector( LoadTextureAsyncCallback::execute ) );
}

CCSpriteFrame* MCLoader::loadSpriteFrame( const char* frameName )
{
	CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName( frameName );
	if( frame != NULL )
		return frame;

	CCTexture2D* pTexture = NULL;
	std::map<std::string,const framework::Frame*>::iterator iter = m_frames.find( frameName );
	if( iter == m_frames.end() )
	{
		//std::string filepath = "images/";
		//filepath.append( frameName );

		//pTexture = loadTexture( filepath );
		pTexture = loadTexture( frameName );
		if( pTexture == NULL )
		{
            std::string strFullPath = getTexturePath( frameName );
			//CCLOG("can't find texture %s", filepath.c_str());
			CCLog("can't find texture 111 %s", strFullPath.c_str() );

			//std::string strDebugMsg = std::string( "can't find texture " );
			//strDebugMsg.append( frameName );
			//write_debug_info( strDebugMsg.c_str() );

			//cc_assert_script_compatible(false, "can't find texture!!!");
			return NULL;
		}

		CCRect rect = CCRectZero;
		rect.size = pTexture->getContentSize();
		CCSpriteFrame* spriteFrame = CCSpriteFrame::createWithTexture( pTexture, rect );
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame( spriteFrame, frameName );

		return spriteFrame;
	}

	int nIndex = iter->second->filename();
	std::string filepath = m_pFrameList->filenames( nIndex );

	pTexture = loadTexture( filepath );
	if( pTexture == NULL )
	{
        std::string strFullPath = getTexturePath( filepath );
		CCLog("can't find texture 222 %s", strFullPath.c_str());
		//cc_assert_script_compatible(false, "can't find texture!!!");

		//std::string strDebugMsg = std::string( "can't find texture " );
		//strDebugMsg.append( filepath );
		//write_debug_info( strDebugMsg.c_str() );

		return NULL;
	}

	float x = (float)iter->second->x();
	float y = (float)iter->second->y();
	float w = (float)iter->second->w();
	float h = (float)iter->second->h();

	CCRect rect = CCRect( x, y, w, h );
	CCSize size = rect.size;

	bool rotated = iter->second->rotated();
	if( rotated )
	{
		rect.size.width = h;
		rect.size.height = w;
	}

	CCSpriteFrame* spriteFrame = CCSpriteFrame::createWithTexture( pTexture, rect, rotated, CCPointZero, size );
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame( spriteFrame, frameName );

	return spriteFrame;
}

CCSprite* MCLoader::loadSprite( const char* frameName )
{
	CCSpriteFrame *frame = loadSpriteFrame( frameName );
	if( frame != NULL )
		return CCSprite::createWithSpriteFrame( frame );
	else
		return CCSprite::createWithTexture( m_pDefaultTexture );
}

CCSprite* MCLoader::loadSpriteAsync( const char* frameName )
{
    return loadSpriteAsyncCallback( frameName, 0 );
}

CCSprite* MCLoader::loadSpriteAsyncCallback( const char* frameName, int nCallbackHandler )
{
	CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName( frameName );
	if( frame != NULL )
    {
        CCSprite* pRetSprite = CCSprite::createWithSpriteFrame( frame );

        if( nCallbackHandler > 0 )
        {
            CCLuaEngine::defaultEngine()->getLuaStack()->pushCCObject( pRetSprite, "CCSprite" );
            CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( nCallbackHandler, 1 );

            CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( nCallbackHandler );
        }

		return pRetSprite;
    }

	//////////////////////////////////////////////////////////////////////////
	int nRequireID = GetNextRequestID();

	CCSprite* pSprite = CCSprite::createWithTexture( m_pDefaultTexture );
	pSprite->retain();
	//pSprite->setVisible( false );

	loadSpriteAsyncInfo* lsaInfo = new loadSpriteAsyncInfo;
	lsaInfo->strFrameName = frameName;
	lsaInfo->pSprite = pSprite;
	lsaInfo->nTextureIndex = -1;
    lsaInfo->nCallbackHandler = nCallbackHandler;

	m_mapLoadSpriteAsyncInfo[nRequireID] = lsaInfo;

	loadSpriteFrameAsync( frameName, nRequireID, lsaInfo );

	return pSprite;
}

void MCLoader::loadSpriteFrameAsync( const char* frameName, CCSprite* pSprite )
{
	CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName( frameName );
	if( frame != NULL )
	{
		pSprite->setDisplayFrame( frame );

		return;
	}

	//////////////////////////////////////////////////////////////////////////
	int nRequireID = GetNextRequestID();

	pSprite->retain();
	//pSprite->setVisible( false );

	loadSpriteAsyncInfo* lsaInfo = new loadSpriteAsyncInfo;
	lsaInfo->strFrameName = frameName;
	lsaInfo->pSprite = pSprite;
	lsaInfo->nTextureIndex = -1;
    lsaInfo->nCallbackHandler = 0;

	m_mapLoadSpriteAsyncInfo[nRequireID] = lsaInfo;

	loadSpriteFrameAsync( frameName, nRequireID, lsaInfo );
}

void MCLoader::loadSpriteFrameAsync( const char* frameName, int nRequestID, loadSpriteAsyncInfo* lsaInfo )
{
	AssetsManager* assetsManager = AssetsManager::sharedAssetsManager();

	std::map<std::string,const framework::Frame*>::iterator iter = m_frames.find( std::string(frameName) );
	if( iter == m_frames.end() )
	{
		//std::string filepath = "images/";
		//filepath.append( frameName );

		lsaInfo->bInPlist = false;
		//lsaInfo->strTexturePath = getTexturePath( filepath );
		lsaInfo->strTexturePath = getTexturePath( frameName );

		std::map< std::string,std::list<int> >::iterator iter = m_mapRequestTextures.find( lsaInfo->strTexturePath );
		if( iter != m_mapRequestTextures.end() )
		{
			iter->second.push_back( nRequestID );
			return;
		}

		std::list<int> listRequestID;
		listRequestID.push_back( nRequestID );

		m_mapRequestTextures[lsaInfo->strTexturePath] = listRequestID;

		CCTextureCache::sharedTextureCache()->addImageAsync( lsaInfo->strTexturePath.c_str(), this, (SEL_CallFuncNI)&MCLoader::loadTextureCallback, nRequestID, -1 );

		return;
	}

	//////////////////////////////////////////////////////////////////////////
	lsaInfo->bInPlist = true;

	lsaInfo->nTextureIndex = iter->second->filename();
	std::string strTextureFile = m_pFrameList->filenames( lsaInfo->nTextureIndex ).c_str();
	lsaInfo->strTexturePath = getTexturePath(strTextureFile);

	std::map< std::string,std::list<int> >::iterator iterR = m_mapRequestTextures.find( lsaInfo->strTexturePath );
	if( iterR != m_mapRequestTextures.end() )
	{
		iterR->second.push_back( nRequestID );
		return;
	}

	//////////////////////////////////////////////////////////////////////////
	std::list<int> listRequestID;
	listRequestID.push_back( nRequestID );

	m_mapRequestTextures[lsaInfo->strTexturePath] = listRequestID;

	CCTextureCache::sharedTextureCache()->addImageAsync( lsaInfo->strTexturePath.c_str(), this, callfuncNI_selector(MCLoader::loadTextureCallback), nRequestID, lsaInfo->nTextureIndex );
}

void MCLoader::loadTextureCallback( CCObject* obj, int nRequestID, int nTextureIndex )
{
    loadTextureCallbackInfo* pInfo = new loadTextureCallbackInfo;
    pInfo->pTexture = (CCTexture2D*)obj;
    pInfo->nRequestID = nRequestID;
    pInfo->nTextureIndex = nTextureIndex;
    if( pInfo->pTexture != NULL )
        pInfo->pTexture->retain();

    CAutoLock autoLock( m_kCallbackLock );
    m_listLoadTextureCallback.push_back( pInfo );
}

void MCLoader::processLoadTextureCallback()
{
    CAutoLock autoLock( m_kCallbackLock );

    std::list<loadTextureCallbackInfo*>::iterator iter = m_listLoadTextureCallback.begin();
    std::list<loadTextureCallbackInfo*>::iterator iter_end = m_listLoadTextureCallback.end();
    for( ; iter != iter_end; ++iter )
    {
        CCTexture2D* pTexture = (*iter)->pTexture;

        std::string strTexturePath = getRequestTexturePath( (*iter)->nRequestID );
        std::map< std::string,std::list<int> >::iterator iterR = m_mapRequestTextures.find( strTexturePath );
        if( iterR != m_mapRequestTextures.end() )
        {
            std::list<int>::iterator iter1 = iterR->second.begin();
            std::list<int>::iterator iter1_end = iterR->second.end();
            for( ; iter1 != iter1_end; ++iter1 )
            {
                std::map<int,loadSpriteAsyncInfo*>::iterator iterL = m_mapLoadSpriteAsyncInfo.find( (*iter1) );
                if( iterL != m_mapLoadSpriteAsyncInfo.end() )
                {
                    loadSpriteAsyncInfo* lsaInfo = iterL->second;

                    //////////////////////////////////////////////////////////////////////////
                    m_mapLoadSpriteAsyncInfo.erase( iterL );

                    //////////////////////////////////////////////////////////////////////////
                    CCSpriteFrame* spriteFrame = NULL;
                    if( pTexture != NULL )
                    {
                        spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName( lsaInfo->strFrameName.c_str() );
                        if( spriteFrame == NULL )
                        {
                            if( lsaInfo->bInPlist )
                            {
                                std::map<std::string,const framework::Frame*>::iterator iterF = m_frames.find( lsaInfo->strFrameName );
                                if( iterF != m_frames.end() )
                                {
                                    float x = (float)iterF->second->x();
                                    float y = (float)iterF->second->y();
                                    float w = (float)iterF->second->w();
                                    float h = (float)iterF->second->h();

                                    CCRect rect = CCRect( x, y, w, h );
                                    CCSize size = rect.size;

                                    bool rotated = iterF->second->rotated();
                                    if( rotated )
                                    {
                                        rect.size.width = h;
                                        rect.size.height = w;
                                    }

                                    spriteFrame = CCSpriteFrame::createWithTexture( pTexture, rect, rotated, CCPointZero, rect.size );

                                    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame( spriteFrame, iterF->first.c_str() );
                                }
                            }
                            else
                            {
                                CCRect rect = CCRectZero;
                                rect.size = pTexture->getContentSize();
                                spriteFrame = CCSpriteFrame::createWithTexture( pTexture, rect );

                                CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame( spriteFrame, lsaInfo->strFrameName.c_str() );
                            }
                        }
                    }

                    if( spriteFrame != NULL && lsaInfo->pSprite->retainCount() > 1 )
                    {
                        lsaInfo->pSprite->setDisplayFrame( spriteFrame );
                        //lsaInfo->pSprite->setVisible( true );

                        if( lsaInfo->nCallbackHandler > 0 )
                        {
                            CCLuaEngine::defaultEngine()->getLuaStack()->pushCCObject( lsaInfo->pSprite, "CCSprite" );
                            CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( lsaInfo->nCallbackHandler, 1 );
                        }
                    }

                    lsaInfo->pSprite->release();

                    // 有可能因为 sprite 已经被释放了，而不会进入回调，所以在这里统一移除
                    if( lsaInfo->nCallbackHandler > 0 )
                        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( lsaInfo->nCallbackHandler );

                    delete lsaInfo;
                }
            }

            m_mapRequestTextures.erase( iterR );
        }

        if( pTexture != NULL )
            pTexture->release();

        delete (*iter);
    }

    m_listLoadTextureCallback.clear();
}

std::string MCLoader::getRequestTexturePath( int nRequestID )
{
	std::map<int,loadSpriteAsyncInfo*>::iterator iter = m_mapLoadSpriteAsyncInfo.find( nRequestID );
	if( iter != m_mapLoadSpriteAsyncInfo.end() )
		return iter->second->strTexturePath;

	return "";
}

MovieClip*	 toMovieClip( CCNode* node )
{
	if( node != NULL && node->getNodeType() == ND_MOVIECLIP )
		return (MovieClip*)node;

	return NULL;
}

TLModel*	 toTLModel( CCNode* node )
{
	if( node != NULL && node->getNodeType() == ND_MODEL )
		return (TLModel*)node;

	return NULL;
}

CCSprite* toSprite( CCNode* node )
{
	if( node != NULL && node->getNodeType() == ND_BITMAP )
		return (CCSprite*)node;

	return NULL;
}

CCLabelTTF* toTTFText( CCNode* node )
{
	if( node != NULL && node->getNodeType() == ND_TTFTEXT )
		return (CCLabelTTF*)node;

	return NULL;
}

TLLabelRichTex*	 toTLRichTex( CCNode* node )
{
	if( node != NULL && node->getNodeType() == ND_TTFRICHTEXT )
		return (TLLabelRichTex*)node;

	return NULL;
}

CCLabelBMFont*	 toBMText( CCNode* node )
{
	if( node != NULL && node->getNodeType() == ND_BMTEXT )
		return (CCLabelBMFont*)node;

	return NULL;
}

CCLayerColor* toRect( CCNode* node )
{
	if( node != NULL && node->getNodeType() == ND_RECT )
		return (CCLayerColor*)node;

	return NULL;
}

MCFrame*	toFrame( CCNode* node )
{
	if( node != NULL && node->getNodeType() == ND_FRAME )
		return (MCFrame*)node;

	return NULL;
}

CCParticleSystem* toParticle( CCNode* node )
{
	if( node != NULL && node->getNodeType() == ND_PARTICLE )
		return (CCParticleSystem*)node;

	return NULL;
}

TLRenderNode* toRenderNode( CCNode* node )
{
	if( node != NULL && node->getNodeType() == ND_RENDERNODE )
		return (TLRenderNode*)node;

	return NULL;
}

CCRect getBoundingBox( CCNode* node, bool bOrigin )
{
	if( node->getNodeType() == ND_MOVIECLIP )
		return bOrigin ? ((MovieClip*)node)->mcOriginBoundingBox : ((MovieClip*)node)->mcBoundingBox;

	if( node->getNodeType() == ND_FRAME )
		return bOrigin ? ((MCFrame*)node)->mcOriginBoundingBox : ((MCFrame*)node)->mcBoundingBox;

	if( node->getNodeType() == ND_TTFRICHTEXT )
	{
		CCSize size = node->getContentSize();
		CCRect rc;
		rc.size = size;
		rc.origin.x = size.width * 0.5f;
		rc.origin.y = -size.height * 0.5f;

		return rc;
	}

	CCPoint ap = node->getAnchorPointInPoints();
	CCSize size = node->getContentSize();
	CCRect box = CCRectMake( -ap.x, -ap.y, size.width, size.height );
	return CC_RECT_PIXELS_TO_POINTS( box );
}

