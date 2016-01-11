#pragma once

#include "cocos2d.h"
#include "files.pb.h"
#include <string>
#include <map>
#include <list>

USING_NS_CC;

class AssetsManager
{
public:
	AssetsManager();
	~AssetsManager();

	static AssetsManager* sharedAssetsManager();

    static unsigned char* loadAssetFile( const char* path, const char* pMode, unsigned long *iSize );
    static unsigned char* loadPackageFile( const char* path, const char* pMode, unsigned long *iSize );
    static unsigned char* loadExternalFile( const char* path, const char* pMode, unsigned long *iSize );
	static bool checkAssetFile( const char* path );

    bool Load();
    bool fileExists( const char* url );
    int getVersion();
    std::string getVersionName();
    int getConfigVersion();
    std::string getRealPath( const char* url );
    unsigned char* getFileContent( const char* url, const char* pMode, unsigned long* iSize );
    bool supportAssetsUpgrade();
    std::string getAssetUrl( std::string p );

	// 设置lua目录
	void		setLuaPath(const char *path);

	// 获取lua目录
	std::string getLuaPath() const;

	// 格式example: win.const
	static std::string getLuaFilePath(const char *url);

	// 判断lua脚本是否存在 格式example: win.const
	bool		isLuaFileExist(const char *url);

    void addSearchPath( const char* szPath );
    std::list<std::string>& getSearchPaths() { return m_listSearchPaths; }

private:
	std::string		 m_szLuaPath;
    framework::FileList mFileList;
    std::map<std::string, const framework::FileItem*> mFileMap;

    std::list<std::string> m_listSearchPaths;
};

class AssetData
{
public:
    AssetData( const char* pszFileName, const char* pszMode )
        : m_pBuffer(0)
        , m_uSize(0)
    {
        m_pBuffer = AssetsManager::sharedAssetsManager()->getFileContent( pszFileName, pszMode, &m_uSize );
    }
    ~AssetData()
    {
        CC_SAFE_DELETE_ARRAY( m_pBuffer );
    }

    bool reset( const char* pszFileName, const char* pszMode )
    {
        CC_SAFE_DELETE_ARRAY( m_pBuffer );
        m_uSize = 0;
        m_pBuffer = AssetsManager::sharedAssetsManager()->getFileContent( pszFileName, pszMode, &m_uSize );
        return (m_pBuffer) ? true : false;
    }

    CC_SYNTHESIZE_READONLY( unsigned char *, m_pBuffer, Buffer );
    CC_SYNTHESIZE_READONLY( unsigned long ,  m_uSize,   Size );
};

#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
#define COMPRESSED_TEXTURE_SUFFIX ".p8"
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
#ifdef POEM_LH_PACKAGE
#define COMPRESSED_TEXTURE_SUFFIX ".lh"
#else
#define COMPRESSED_TEXTURE_SUFFIX ".p8"
#endif
#else
#define COMPRESSED_TEXTURE_SUFFIX ""
#endif

extern std::string getTexturePath( const std::string& filePath );
