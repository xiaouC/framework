#include "TLFontTex.h"
#include "../MC/AssetsManager.h"
#include <ccUTF8.h>
#include "MC/MCLoader.h"
#include "platform/CCPlatformMacros.h"

CCSize g_fontRealSize = CCSizeMake( 20, 24 );

// 统一 18 的大小 
float TLFontTex::ms_fCommonLineHeight = 24;
float TLFontTex::ms_fFontOriginSize = 18;
int TLFontTex::ms_nEdgeSize = 0;
bool TLFontTex::ms_bStrokeEdge = false;

#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
    #include <xutility>
    #define TL_MAX max
    std::string TLFontTex::ms_strFontName = "FZPangWa-M18S";
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_LINUX )
    #define TL_MAX std::max
    std::string TLFontTex::ms_strFontName = "FZPangWa-M18S";
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
    #define TL_MAX std::max
    std::string TLFontTex::ms_strFontName = "FZPangWa-M18S";
#else
    #define TL_MAX std::max
    std::string TLFontTex::ms_strFontName = "fonts/YunYueFont.ttf";
#endif

void TLFontTex::resetCommonLineHeight()
{
	std::string standardWord = "T";
    CCLabelTTF* pLabel = CCLabelTTF::create( standardWord.c_str(), ms_strFontName.c_str(), ms_fFontOriginSize );
    const CCSize& labelSize = pLabel->getContentSize();

	ms_fCommonLineHeight = labelSize.height + ms_nEdgeSize * 2;
}

TLFontTex* g_pTLFontTex = NULL;
int TLFontTex::ms_nParseHandle = 0;
TLFontTex::TLFontTex()
: m_nOldFBO(0)
, m_uFBO(0)
, m_pFontTex(NULL)
, m_nCurrentLineHeight(0)
, m_nOffsetX(ms_nEdgeSize)
, m_nOffsetY(ms_nEdgeSize)
, m_pColorTex(NULL)
, m_nRow(8)
, m_nCol(8)
{
}

TLFontTex::~TLFontTex()
{
    glDeleteFramebuffers( 1, &m_uFBO );
}

TLFontTex* TLFontTex::sharedTLFontTex()
{
	if( g_pTLFontTex == NULL )
	{
		g_pTLFontTex = new TLFontTex;
	}

	return g_pTLFontTex;
}

CCSpriteBatchNode* TLFontTex::newBatchNode()
{
	return CCSpriteBatchNode::createWithTexture( m_pFontTex );
}

void TLFontTex::initFontTexture( const char* pFile, int nRow, int nCol, const char* szShaderName, const char* szFontShaderName )
{
    glGenFramebuffers( 1, &m_uFBO );
    m_nOffsetX = ms_nEdgeSize;
    m_nOffsetY = ms_nEdgeSize;
    m_nCurrentLineHeight = 0.0f;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (!m_pColorTex) {
        m_pColorTex = MCLoader::sharedMCLoader()->loadTexture(pFile);
        m_pColorTex->retain();
    }

    m_nRow = nRow;
    m_nCol = nCol;
    m_strShaderName = szShaderName;
    if (szFontShaderName == NULL)
        m_strFontShaderName = m_strShaderName;
    else
        m_strFontShaderName = szFontShaderName;

    //////////////////////////////////////////////////////////////////////////////////////////////////
    if (!m_pFontTex) {
        m_pFontTex = new CCTexture2D;
        int nSize = sizeof(unsigned int) * 1024 * 2048;
        unsigned int* pTexData = new unsigned int[1024 * 2048];
        memset( pTexData, 0, nSize );

        m_pFontTex->initWithData( pTexData, kCCTexture2DPixelFormat_Default, 1024, 2048, CCSizeMake(1024, 2048) );
#if CC_ENABLE_CACHE_TEXTURE_DATA
        VolatileTexture::addDataTexture(m_pFontTex, pTexData, kCCTexture2DPixelFormat_Default, CCSizeMake(1024, 2048));
#endif
    }

    if (m_orderAllChat.empty()) {
        for( int i=33; i < 127; ++i )
        {
            std::string strTemp( 1, (char)i );

            createOneCharEdge( strTemp.c_str() );
        }
    } else {
        std::vector<std::string> vec = m_orderAllChat;
        std::vector<std::string>::iterator it = vec.begin();
        for(; it!=vec.end(); it++) {
            if (!it->empty())
                createOneCharEdge( it->c_str() );
        }
    }
}

chatTexInfo* TLFontTex::createOneChar( const char* p )
{
    unsigned int utf8Char = cc_utf8_get_char( p );

    int mask,n;
    UTF8_COMPUTE( p[0], mask, n );
    std::string strTemp( p, n );

    float width = ( p[0] == ' ' ? ms_fFontOriginSize * 0.5f : 0.0f );
    float height = ( p[0] == ' ' ? ms_fFontOriginSize * 0.5f : 0.0f );

    CCImage image;
    image.initWithString( strTemp.c_str(), width, height, CCImage::kAlignTopLeft, ms_strFontName.c_str(), (int)ms_fFontOriginSize );

    if( image.getWidth() == 0 || image.getHeight() == 0 )
        return NULL;

    FontImageAddEdge( &image );

    // 列满了，下一行 
    if( m_nOffsetX + image.getWidth() > 1024 )
    {
        m_nOffsetX = 0;
        m_nOffsetY += m_nCurrentLineHeight;
        m_nCurrentLineHeight = 0;
    }

    // 行也满了，换一张贴图 
    if( m_nOffsetY + image.getHeight() > 2048 )
        return NULL;

    glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
    glBindTexture( GL_TEXTURE_2D, m_pFontTex->getName() );
    glTexSubImage2D( GL_TEXTURE_2D, 0, (GLint)m_nOffsetX, (GLint)m_nOffsetY, image.getWidth(), image.getHeight(), GL_RGBA, GL_UNSIGNED_BYTE, image.getData() );

    chatTexInfo ctInfo;
    ctInfo.rcUV = CCRectMake( m_nOffsetX, m_nOffsetY, image.getWidth(), image.getHeight() );

    // 修正 
    m_nOffsetX += image.getWidth();

    if( image.getHeight() > m_nCurrentLineHeight )
        m_nCurrentLineHeight = image.getHeight();

    if (m_mapAllChat.find(utf8Char) == m_mapAllChat.end())
        m_orderAllChat.push_back(strTemp);

    m_mapAllChat[utf8Char] = ctInfo;

    return &m_mapAllChat[utf8Char];
}

void TLFontTex::FontImageAddEdge( CCImage* pImage )
{
	if( pImage == NULL )
		return;

	if( 0 == pImage->getWidth() || 0 == pImage->getHeight() )
		return;

	int nWidth = pImage->getWidth()+(ms_nEdgeSize*2);
	int nHeight = pImage->getHeight()+(ms_nEdgeSize*2);
	int nSize = nHeight * nWidth * 4;

	unsigned char* pSrcData = pImage->getData();
	unsigned char* pDstData = new unsigned char[nSize];
	memset(pDstData, 0, nSize * sizeof(unsigned char));//set all color black, and Alpha is 0

	for (int y=0; y<pImage->getHeight(); y++)
	{
		for (int x=0; x<pImage->getWidth(); x++)
		{
			unsigned int alpha = pSrcData[(x + y*pImage->getWidth()) * 4];//get Alpha from ARGB
			if (0 == alpha)
				continue;

			unsigned int* pix = (unsigned int*)pDstData + x+ms_nEdgeSize + (y)*nWidth;//up
			*pix = (TL_MAX((*pix>>24),alpha))<<24;

			pix = (unsigned int*)pDstData + x+ms_nEdgeSize + (y+ms_nEdgeSize*2)*nWidth;//bottom
			*pix = (TL_MAX((*pix>>24),alpha))<<24;

			pix = (unsigned int*)pDstData + x+ (y+ms_nEdgeSize)*nWidth;//left
			*pix = (TL_MAX((*pix>>24),alpha))<<24;

			pix = (unsigned int*)pDstData + x+(ms_nEdgeSize*2) + (y+ms_nEdgeSize)*nWidth;//right
			*pix = (TL_MAX((*pix>>24),alpha))<<24;
		}
	}

	for (int x=0; x<pImage->getWidth(); x++)
	{
		for (int y=0; y<pImage->getHeight(); y++)
		{	
			unsigned int alphaSrc = pSrcData[(x + y*pImage->getWidth()) * 4];//get Alpah from ARGB
			if (0 == alphaSrc)
				continue;

			unsigned int* pix = (unsigned int*)pDstData + x+(ms_nEdgeSize) + (y+ms_nEdgeSize)*nWidth;//body
			*pix |= (alphaSrc)|(alphaSrc<<8)|(alphaSrc<<16)|(alphaSrc<<24);
		}
	}

	CC_SAFE_DELETE_ARRAY(pSrcData);

	//init with ARGB
	pImage->initWithImageData(pDstData, nSize, CCImage::kFmtRawData, nWidth, nHeight);

	CC_SAFE_DELETE_ARRAY(pDstData);
}

chatTexInfo* TLFontTex::getChatTextInfo( const char* p )
{
    unsigned int utf8Char = cc_utf8_get_char( p );
    if( utf8Char == 0xFFFFFFFF )
        return NULL;

    std::map<unsigned int,chatTexInfo>::iterator iter = m_mapAllChat.find( utf8Char );
    if( iter != m_mapAllChat.end() )
        return &iter->second;

    return createOneCharEdge( p );
}

float TLFontTex::getFontScale( float fInFontSize )
{
	return fInFontSize / ( ms_fFontOriginSize + ms_nEdgeSize * 2 );
}

void TLFontTex::getColorTextureCoords( int nColorIndex, float& ul, float& vt, float& ur, float& vb )
{
    int nRow = nColorIndex / m_nCol;
    int nCol = nColorIndex % m_nCol;

    ul = (float)nCol / (float)m_nCol;
    vt = (float)nRow / (float)m_nRow;
    ur = (float)( nCol + 1.0 ) / (float)m_nCol;
    vb = (float)( nRow + 1.0 ) / (float)m_nRow;
}

CCGLProgram* TLFontTex::getColorTextureShaderProgram()
{
    return CCShaderCache::sharedShaderCache()->programForKey( m_strShaderName.c_str() );
}

CCGLProgram* TLFontTex::getFontShaderProgram()
{
    return CCShaderCache::sharedShaderCache()->programForKey( m_strFontShaderName.c_str() );
}

void TLFontTex::saveFontTexture( const char* szFilePath )
{
    const CCSize& texSize = m_pFontTex->getContentSizeInPixels();
    int nSavedBufferWidth = (int)texSize.width;
    int nSavedBufferHeight = (int)texSize.height;

    GLubyte* pBuffer = new GLubyte[nSavedBufferWidth * nSavedBufferHeight * 4];
    GLubyte* pTempData = new GLubyte[nSavedBufferWidth * nSavedBufferHeight * 4];

    kmGLMatrixMode( KM_GL_PROJECTION );
    kmGLPushMatrix();
    kmGLMatrixMode( KM_GL_MODELVIEW );
    kmGLPushMatrix();

    CCDirector *director = CCDirector::sharedDirector();
    director->setProjection( director->getProjection() );

    // Calculate the adjustment ratios based on the old and new projections
    CCSize size = director->getWinSizeInPixels();
    float widthRatio = size.width / texSize.width;
    float heightRatio = size.height / texSize.height;

    // Adjust the orthographic projection and viewport
    glViewport(0, 0, (GLsizei)texSize.width, (GLsizei)texSize.height);

    kmMat4 orthoMatrix;
    kmMat4OrthographicProjection(&orthoMatrix, (float)-1.0 / widthRatio,  (float)1.0 / widthRatio,
            (float)-1.0 / heightRatio, (float)1.0 / heightRatio, -1,1 );
    kmGLMultMatrix(&orthoMatrix);

    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &m_nOldFBO);
    glBindFramebuffer(GL_FRAMEBUFFER, m_uFBO);

    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0,0,nSavedBufferWidth, nSavedBufferHeight,GL_RGBA,GL_UNSIGNED_BYTE, pTempData);

    glBindFramebuffer(GL_FRAMEBUFFER, m_nOldFBO);

    // restore viewport
    director->setViewport();

    kmGLMatrixMode(KM_GL_PROJECTION);
	kmGLPopMatrix();
	kmGLMatrixMode(KM_GL_MODELVIEW);
	kmGLPopMatrix();

    // to get the actual texture data
    // #640 the image read from rendertexture is dirty
    for (int i = 0; i < nSavedBufferHeight; ++i)
    {
        memcpy( &pBuffer[i * nSavedBufferWidth * 4], &pTempData[(nSavedBufferHeight - i - 1) * nSavedBufferWidth * 4], nSavedBufferWidth * 4 );
    }

    CCImage* pImage = new CCImage;
    pImage->initWithImageData(pBuffer, nSavedBufferWidth * nSavedBufferHeight * 4, CCImage::kFmtRawData, nSavedBufferWidth, nSavedBufferHeight, 8);

    CC_SAFE_DELETE_ARRAY(pBuffer);
    CC_SAFE_DELETE_ARRAY(pTempData);

    std::string fullpath = CCFileUtils::sharedFileUtils()->getWritablePath() + szFilePath;
    pImage->saveToFile( fullpath.c_str(), true );

    delete pImage;
}

chatTexInfo* TLFontTex::createOneCharEdge( const char* p )
{
    unsigned int utf8Char = cc_utf8_get_char( p );

    int mask,n;
    UTF8_COMPUTE( p[0], mask, n );
    std::string strTemp( p, n );

    CCLabelTTF* pLabel = CCLabelTTF::create( strTemp.c_str(), ms_strFontName.c_str(), ms_fFontOriginSize );
    //CCLabelTTF* pLabel = CCLabelTTF::create( strTemp.c_str(), "YunYueFont", ms_fFontOriginSize );
    const CCSize& labelSize = pLabel->getContentSize();

    //float nNewWidth = labelSize.width + ms_nEdgeSize * 2 + 3;
    //float nNewHeight = labelSize.height + ms_nEdgeSize * 2;
    float nNewWidth = labelSize.width + ms_nEdgeSize * 2;
    float nNewHeight = labelSize.height + ms_nEdgeSize * 2;

    // 列满了，下一行 
    if( m_nOffsetX + nNewWidth > 1024 )
    {
        m_nOffsetX = ms_nEdgeSize;
        m_nOffsetY += m_nCurrentLineHeight;
        m_nCurrentLineHeight = 0;
    }

    // 行也满了，换一张贴图 
    if( m_nOffsetY + nNewHeight > 2048 )
        return NULL;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // render to texture begin
    kmGLMatrixMode( KM_GL_PROJECTION );
	kmGLPushMatrix();
	kmGLMatrixMode( KM_GL_MODELVIEW );
    kmGLPushMatrix();

    CCDirector* director = CCDirector::sharedDirector();
    director->setProjection( director->getProjection() );

    const CCSize& texSize = m_pFontTex->getContentSizeInPixels();

    // Calculate the adjustment ratios based on the old and new projections
    CCSize size = director->getWinSizeInPixels();
    float widthRatio = size.width / texSize.width;
    float heightRatio = size.height / texSize.height;

    // Adjust the orthographic projection and viewport
    glViewport( 0, 0, (GLsizei)texSize.width, (GLsizei)texSize.height );

    kmMat4 orthoMatrix;
    kmMat4OrthographicProjection( &orthoMatrix, (float)-1.0 / widthRatio,  (float)1.0 / widthRatio,
        (float)-1.0 / heightRatio, (float)1.0 / heightRatio, -1,1 );
    kmGLMultMatrix( &orthoMatrix );

    glGetIntegerv( GL_FRAMEBUFFER_BINDING, &m_nOldFBO );
    glBindFramebuffer( GL_FRAMEBUFFER, m_uFBO );
    
    glFramebufferTexture2D( GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_pFontTex->getName(), 0 );

    // 
    float fCenterX = m_nOffsetX + nNewWidth * 0.5f;
    float fCenterY = m_nOffsetY + nNewHeight * 0.5f;

    pLabel->setFlipY( true );
    if( ms_bStrokeEdge )
    {
        pLabel->setColor( ccc3( 0, 0, 0 ) );

        ccBlendFunc originalaBlend = pLabel->getBlendFunc();
        ccBlendFunc func = { GL_SRC_ALPHA, GL_ONE };
        pLabel->setBlendFunc( func );
        pLabel->setAnchorPoint( ccp( 0.5f, 0.5f ) );

        for( int i=0; i < 360; i += 15 )
        {
            float r = CC_DEGREES_TO_RADIANS( i );
            pLabel->setPosition( ccp( fCenterX + sin( r ) * ms_nEdgeSize, fCenterY + cos( r ) * ms_nEdgeSize ) );
            pLabel->visit();
        }

        pLabel->setBlendFunc( originalaBlend );
    }
    pLabel->setColor( ccc3( 255, 255, 255 ) );
    pLabel->setPosition( ccp( fCenterX, fCenterY ) );
    pLabel->visit();

    // render to texture end
    glBindFramebuffer( GL_FRAMEBUFFER, m_nOldFBO );

    // restore viewport
    director->setViewport();

    kmGLMatrixMode( KM_GL_PROJECTION );
	kmGLPopMatrix();
	kmGLMatrixMode( KM_GL_MODELVIEW );
	kmGLPopMatrix();

    //m_pFontTex->setAliasTexParameters();

    //saveFontTexture( "font.png" );

    // 
    chatTexInfo ctInfo;
    ctInfo.rcUV = CCRectMake( m_nOffsetX, m_nOffsetY, nNewWidth - 0, nNewHeight );

    // 修正 
    m_nOffsetX += nNewWidth + 1;

    if( nNewHeight > m_nCurrentLineHeight )
        m_nCurrentLineHeight = nNewHeight;

    if (m_mapAllChat.find(utf8Char) == m_mapAllChat.end())
        m_orderAllChat.push_back(strTemp);

    m_mapAllChat[utf8Char] = ctInfo;

    return &m_mapAllChat[utf8Char];
}
