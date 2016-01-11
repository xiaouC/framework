#include <algorithm>
#include "AssetsManager.h"
#include "CCFileUtils.h"
#include "../platform/PlatformUtils.h"
#ifdef WIN32
#include <io.h>
#define F_OK 0
#else
#include <unistd.h>
#endif

static char s_filelist[256] = {0};
static inline const char* getFileList()
{
    return "filelist";
}

static AssetsManager* _assetsManager = NULL;
AssetsManager* AssetsManager::sharedAssetsManager()
{
    if (_assetsManager==NULL)
    {
        _assetsManager = new AssetsManager();
    }
    return _assetsManager;
}

AssetsManager::AssetsManager()
{
}

AssetsManager::~AssetsManager()
{
}

unsigned char* AssetsManager::loadExternalFile( const char* pUrl, const char* pMode, unsigned long* iSize )
{
    // open from writable path
#ifdef PACK_RESOURCE
#ifdef WIN32 
#ifdef DEBUG
	std::string path = CCFileUtils::sharedFileUtils()->getWritablePath() + "../../../packetassets/";
#else
	std::string path = CCFileUtils::sharedFileUtils()->getWritablePath();
#endif // DEBUG
#else
	std::string path = CCFileUtils::sharedFileUtils()->getWritablePath();
#endif	
#else
	std::string path = CCFileUtils::sharedFileUtils()->getWritablePath();
#endif // WIN32    
    path.append( pUrl );
    return CCFileUtils::sharedFileUtils()->getFileData( path.c_str(), pMode, iSize );
}

unsigned char* AssetsManager::loadPackageFile( const char* pUrl, const char* pMode, unsigned long* iSize )
{
	std::string strFullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename( pUrl );
    return CCFileUtils::sharedFileUtils()->getFileData( strFullPath.c_str(), pMode, iSize );
}

unsigned char* AssetsManager::loadAssetFile( const char* pUrl, const char* pMode, unsigned long* iSize )
{
    unsigned char* pBuffer = loadExternalFile( pUrl, pMode, iSize );
    if( pBuffer==NULL )
    {
        // open from package
        pBuffer = loadPackageFile( pUrl, pMode, iSize );
    }
    return pBuffer;
}

bool AssetsManager::checkAssetFile( const char* sUrl )
{
    // check writable path first
    std::string path = CCFileUtils::sharedFileUtils()->getWritablePath();
    path.append( sUrl );
    if( access( path.c_str(), F_OK ) != -1 )
    {
        return true;
    }
    return CCFileUtils::sharedFileUtils()->isFileExist( sUrl );
}

bool AssetsManager::Load()
{
#ifdef PACK_RESOURCE
    mFileMap.clear();
    mFileList.Clear();

    unsigned long iSize=0;
    unsigned char* pBuffer = NULL;
    pBuffer = loadExternalFile( getFileList(), "rb", &iSize );
    if( pBuffer != NULL )
    {
        // check package version
        mFileList.ParseFromArray( (void*)pBuffer, iSize );
        delete[] pBuffer;
        if( !mFileList.has_pkg_version() || mFileList.pkg_version() != getPackageVersion() )
        {
            CCLOGERROR( "external filelist's version if not current package, ignore" );
            // invalid
            pBuffer = loadPackageFile( getFileList(), "rb", &iSize );
            if( pBuffer==NULL )
            {
                CCLOGERROR( "load file %s failed", getFileList() );
                return false;
            }
            mFileList.Clear();
            mFileList.ParseFromArray( (void*)pBuffer, iSize );
            delete[] pBuffer;
        }
    }
    else
    {
        pBuffer = loadPackageFile( getFileList(), "rb", &iSize );
        if( pBuffer==NULL )
        {
            CCLOGERROR( "load file %s failed", getFileList() );
            return false;
        }
        mFileList.ParseFromArray( (void*)pBuffer, iSize );
        delete[] pBuffer;
    }

    if( !mFileList.IsInitialized() )
    {
        CCLOGERROR( "parse file %s failed", getFileList() );
        return false;
    }

    // init map
    for( int i=0; i < mFileList.files_size(); i++ )
    {
        const framework::FileItem &item = mFileList.files(i);
        mFileMap[item.url()] = &item;
    }
#endif
    return true;
}

bool AssetsManager::fileExists( const char* url )
{
#ifdef PACK_RESOURCE
	return mFileMap.find(url) != mFileMap.end();
#else
    return CCFileUtils::sharedFileUtils()->isFileExist( CCFileUtils::sharedFileUtils()->fullPathForFilename( url ) );
#endif
}

std::string AssetsManager::getRealPath( const char* url )
{
#ifdef PACK_RESOURCE
    std::string sUrl(url);
    const framework::FileItem* pItem = mFileMap[url];
    if( pItem==NULL )
        return std::string( CCFileUtils::sharedFileUtils()->fullPathForFilename( url ) );

    std::string path = pItem->md5();
    path.insert( 2, "/" );
    size_t idx = sUrl.find_last_of( '.' );
    std::string ext("");
    if( idx != std::string::npos )
    {
        ext = sUrl.substr( idx );
    }
    path.append( ext );
    return path;
#else
    return std::string( CCFileUtils::sharedFileUtils()->fullPathForFilename( url ) );
#endif
}

unsigned char* AssetsManager::getFileContent( const char* url, const char* pMode, unsigned long* iSize )
{
    std::string path = getRealPath( url );
    if( path.empty() ) {
        return NULL;
    }
    return loadAssetFile( path.c_str(), "rb", iSize );
}

int AssetsManager::getVersion()
{
    return mFileList.version();
}

std::string AssetsManager::getVersionName()
{
    return mFileList.version_name();
}

int AssetsManager::getConfigVersion()
{
    return mFileList.config_version();
}

bool AssetsManager::supportAssetsUpgrade()
{
#ifdef PACK_RESOURCE
    return true;
#else
    return false;
#endif
}

std::string AssetsManager::getAssetUrl( std::string p )
{
#ifdef PACK_RESOURCE
    std::map<std::string, const framework::FileItem*>::iterator iter = mFileMap.begin();
    for( ; iter != mFileMap.end(); iter++ )
    {
        if( iter->second == NULL )
            continue;
        std::string path = iter->second->md5();
        path.insert( 2, "/" );
        size_t idx = iter->first.find_last_of( '.' );
        std::string ext("");
        if( idx != std::string::npos )
        {
            ext = iter->first.substr( idx );
        }
        path.append( ext );
        if( path == p )
            return iter->second->url();
    }
    return p;
#else
    return p;
#endif
}

void AssetsManager::setLuaPath( const char *path )
{
	m_szLuaPath = path;
	if (!m_szLuaPath.empty()) {
		char v = *(m_szLuaPath.rbegin());
		if (v != '\\' && v != '/')
		{
			m_szLuaPath.append("/");
		}
	}
}

std::string AssetsManager::getLuaPath() const
{
	return m_szLuaPath;
}

std::string AssetsManager::getLuaFilePath( const char *url )
{
	std::string filename(url);
	if( filename[0] != '/' )
		std::replace( filename.begin(), filename.end(), '.', '/' );
	filename.append( ".lua" );
	return filename;
}

bool AssetsManager::isLuaFileExist( const char *url )
{
	std::string file2 = getLuaFilePath(url);
	std::string file1 = m_szLuaPath + url;
	if (!m_szLuaPath.empty() && fileExists(file1.c_str()))
		return true;

	return fileExists(file2.c_str());
}

void AssetsManager::addSearchPath( const char* szPath )
{
    m_listSearchPaths.push_back( szPath );
    std::string strTemp = std::string("./") + szPath;
    CCFileUtils::sharedFileUtils()->addSearchPath( strTemp.c_str() );
}

std::string getAssetUrl( std::string p )
{
    return AssetsManager::sharedAssetsManager()->getAssetUrl( p );
}

std::string getTexturePath( const std::string& filePath )
{
	AssetsManager* assetsManager = AssetsManager::sharedAssetsManager();

	std::string path = filePath;
    std::list<std::string>::iterator iter = assetsManager->getSearchPaths().begin();
    std::list<std::string>::iterator iter_end = assetsManager->getSearchPaths().end();
    for( ; iter != iter_end; ++iter )
    {
        std::string strTempLHPath = *iter + filePath + COMPRESSED_TEXTURE_SUFFIX;
        if( assetsManager->fileExists( strTempLHPath.c_str() ) )
        {
            path = strTempLHPath;
            break;
        }

        std::string strTempPath = *iter + filePath;
        if( assetsManager->fileExists( strTempPath.c_str() ) )
        {
            path = strTempPath;

            break;
        }
    }

	std::string strRealPath = assetsManager->getRealPath( path.c_str() );
	if( strRealPath.empty() )
	{
		//CCLOGERROR("texture url is not exists %s", path.c_str());
		return "";
	}

	std::string fullPath = CCFileUtils::sharedFileUtils()->getWritablePath();
	fullPath.append( strRealPath );

	if( CCFileUtils::sharedFileUtils()->isFileExist( fullPath.c_str() ) )
	{
		return fullPath;
	}
	else
	{
		return strRealPath;
	}
}
