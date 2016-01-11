#include "TLLabelRichTex.h"
#include "TLFontTex.h"
#include "CCPointExtension.h"
#include "CCLuaEngine.h"
#include "MC/MCLoader.h"
#include "UI/TLWindow.h"
#include "Common/TLCommon.h"

TLLabelRichTex::TLLabelRichTex()
: m_fFontSize(18)
, m_eAlignment(CCImage::kAlignTopLeft)
, m_kColor(ccc4(255,255,255,255))
, m_nElementCount(0)
, m_eRichStringFlag(TL_RICH_STRING_FLAG_AUTO_WRAP)
, m_kRealSize(CCSizeZero)
, m_pWindow(NULL)
, m_nNodeHandler(0)
, m_bRealSizeLayout(false)
, m_nTabNum(0)
, m_nWordSpacing(-3)
, m_nLineSpacing(0)
, m_pCursor(NULL)
, m_fCursorHeight(0.0f)
, m_kCursorDefaultPos(CCSizeZero)
, m_kCursorPosition(CCSizeZero)
, m_nColorIndex(0)
{
    // 
    _cascadeColorEnabled = true;
    _cascadeOpacityEnabled = true;

	m_kCurrentLineInfo.fLineRealWidth = 0;
	m_kCurrentLineInfo.fLineRealHeight = 0;
	m_kCurrentLineInfo.fMaxFontCommonHeight = 0;
	
	m_nodeType = ND_TTFRICHTEXT;
	setAnchorPoint( ccp( 0.5f, 0.5f ) );

	m_pBatchNode = TLFontTex::sharedTLFontTex()->newBatchNode();
	//m_pBatchNode->setAnchorPoint( ccp( 0.5f, 0.5f ) );
	m_pBatchNode->setAnchorPoint( CCPointZero );
	addChild( m_pBatchNode );

	m_pSpriteNode = CCNode::create();
	//m_pSpriteNode->setAnchorPoint( ccp( 0.5f, 0.5f ) );
	m_pSpriteNode->setAnchorPoint( CCPointZero );
	addChild( m_pSpriteNode );

    // 
    TLFontTex::sharedTLFontTex()->getColorTextureCoords( m_nColorIndex, ul, vt, ur, vb );

    CCGLProgram* pShaderProgram = TLFontTex::sharedTLFontTex()->getFontShaderProgram();
    setShaderProgram( pShaderProgram );

    m_pBatchNode->setTexture2( TLFontTex::sharedTLFontTex()->m_pColorTex );
}

TLLabelRichTex::~TLLabelRichTex()
{
	std::list<int>::iterator iter = m_listNodeHandlers.begin();
	std::list<int>::iterator iter_end = m_listNodeHandlers.end();
	for( ; iter != iter_end; ++iter )
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( *iter );
	m_listNodeHandlers.clear();
}

TLLabelRichTex* TLLabelRichTex::create( const char* str, float fFontSize, const CCSize& size, const CCImage::ETextAlign& alignment, TLWindow* pWindow )
{
	TLLabelRichTex* pRet = new TLLabelRichTex;
	if( pRet && pRet->initWithString( str, fFontSize, size, alignment, pWindow ) )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE( pRet );
	return NULL;
}

bool TLLabelRichTex::initWithString( const char* str, float fFontSize, const CCSize& size, CCImage::ETextAlign alignment, TLWindow* pWindow )
{
	if( str == NULL )
		return false;

	m_pWindow = pWindow;

	setContentSize( size );
	m_fFontSize = fFontSize;
	m_eAlignment = alignment;

	setRichString( str );

	return true;
}

void TLLabelRichTex::setColor( const ccColor3B& color3 )
{
	CCNodeRGBA::setColor( color3 );
	/*
	m_kColor.r = color3.r;
	m_kColor.g = color3.g;
	m_kColor.b = color3.b;

	for( int i=0; i < (int)m_vecLine.size(); ++i )
	{
		std::list<NodeInfo>::iterator iter = m_vecLine[i].listLineNode.begin();
		std::list<NodeInfo>::iterator iter_end = m_vecLine[i].listLineNode.end();
		for( ; iter != iter_end; ++iter )
		{
			CCNode* node = iter->pkNode;
			if( node->getNodeType() == ND_BITMAP )
            {
				((CCSprite*)node)->setColor( color3 );
            }
		}
	}
	*/
}

void TLLabelRichTex::setOpacity( GLubyte opacity )
{
	CCNodeRGBA::setOpacity( opacity );
	/*
	m_kColor.a = opacity;

	for( int i=0; i < (int)m_vecLine.size(); ++i )
	{
		std::list<NodeInfo>::iterator iter = m_vecLine[i].listLineNode.begin();
		std::list<NodeInfo>::iterator iter_end = m_vecLine[i].listLineNode.end();
		for( ; iter != iter_end; ++iter )
		{
			CCNode* node = iter->pkNode;
			if( node->getNodeType() == ND_BITMAP )
				((CCSprite*)node)->setOpacity( opacity );
		}
	}
	*/
}

void TLLabelRichTex::updateDisplayedOpacity( GLubyte parentOpacity )
{
	//CCNodeRGBA::updateDisplayedOpacity( parentOpacity );
	_displayedOpacity = _realOpacity * parentOpacity/255.0;
	
    if (_cascadeOpacityEnabled)
    {
        for( int i=0; i < (int)m_vecLine.size(); ++i )
        {
            std::list<NodeInfo>::iterator iter = m_vecLine[i].listLineNode.begin();
            std::list<NodeInfo>::iterator iter_end = m_vecLine[i].listLineNode.end();
            for( ; iter != iter_end; ++iter )
            {
                CCNode* node = iter->pkNode;
                if( node->getNodeType() == ND_BITMAP )
                {
                    ((CCSprite*)node)->updateDisplayedOpacity( _displayedOpacity );
                }
            }
        }
    }
}

void TLLabelRichTex::updateDisplayedColor( const ccColor3B& parentColor )
{
	//CCNodeRGBA::updateDisplayedColor( parentColor );
	_displayedColor.r = _realColor.r * parentColor.r/255.0;
	_displayedColor.g = _realColor.g * parentColor.g/255.0;
	_displayedColor.b = _realColor.b * parentColor.b/255.0;
	
    if (_cascadeColorEnabled)
    {
        for( int i=0; i < (int)m_vecLine.size(); ++i )
        {
            std::list<NodeInfo>::iterator iter = m_vecLine[i].listLineNode.begin();
            std::list<NodeInfo>::iterator iter_end = m_vecLine[i].listLineNode.end();
            for( ; iter != iter_end; ++iter )
            {
                CCNode* node = iter->pkNode;
                if( node->getNodeType() == ND_BITMAP )
                {
                    ((CCSprite*)node)->updateDisplayedColor( _displayedColor );
                }
            }
        }
    }
}

void TLLabelRichTex::setShaderProgram( CCGLProgram* pShaderProgram )
{
	m_pBatchNode->setShaderProgram( pShaderProgram );

	setNodeShaderProgram( m_pSpriteNode, pShaderProgram );
}

void TLLabelRichTex::moveOffsetX( float offset, bool flag )
{
	const CCSize& kContentSize = getContentSize();

	float fScale = TLFontTex::sharedTLFontTex()->getFontScale( m_fFontSize );
	float fRealOffset = offset * m_fFontSize * fScale * 0.5f;
	if( m_eRichStringFlag == TL_RICH_STRING_FLAG_AUTO_WRAP && kContentSize.width > 0.0f && m_kCurrentLineInfo.fLineRealWidth + offset > kContentSize.width )
	{
		if( !flag )
		{
			fRealOffset = kContentSize.width - m_kCurrentLineInfo.fLineRealWidth;
		}

		appendLine( true );
	}

	m_kCurrentLineInfo.fLineRealWidth += fRealOffset;
}

void TLLabelRichTex::appendSpriteToCurrentLine( CCNode* pkNode, float width, float height, float offsetX, bool layout )
{
	const CCSize& kContentSize = getContentSize();

	CCSize n_size = CCSizeMake( width, height );
	if( width == 0.0f || height == 0.0f )
		n_size = pkNode->getContentSize();

	if( m_eRichStringFlag == TL_RICH_STRING_FLAG_AUTO_WRAP && kContentSize.width > 0.0f && m_kCurrentLineInfo.fLineRealWidth + n_size.width > kContentSize.width )
		appendLine( true );

	pkNode->setAnchorPoint( CCPointZero );

    if( pkNode->getNodeType() == ND_BITMAP )
    {
        CCSprite* pkSprite = (CCSprite*)pkNode;
        pkSprite->setTexture2( TLFontTex::sharedTLFontTex()->m_pColorTex );
        pkSprite->setTexture2Coords( ul, vt, ur, vb );
        pkSprite->setColor2B( 1.0f );

        CCGLProgram* pShaderProgram = TLFontTex::sharedTLFontTex()->getColorTextureShaderProgram();
        pkSprite->setShaderProgram( pShaderProgram );
    }

	m_pSpriteNode->addChild( pkNode, 0, m_nElementCount++ );

	processNodeHandler( pkNode );

    NodeInfo ni;
	ni.eType = Sprite;
    ni.fOriginX = m_kCurrentLineInfo.fLineRealWidth + offsetX;
    ni.pkNode = pkNode;
	ni.currentSize = CCSizeMake( pkNode->getContentSize().width * pkNode->getScaleX(), pkNode->getContentSize().height * pkNode->getScaleY() );
	m_kCurrentLineInfo.listLineNode.push_back( ni );

	m_kCurrentLineInfo.fLineRealWidth += ( n_size.width + m_nWordSpacing );
	// line height
	if( layout && m_kCurrentLineInfo.fLineRealHeight < n_size.height )
		m_kCurrentLineInfo.fLineRealHeight = n_size.height;
}

void TLLabelRichTex::appendText( const char* szText )
{
	const float fCommonLineHeight = TLFontTex::getCommonLineHeight();
    const CCSize& kContentSize = getContentSize();
	
    std::string strTemp = szText;
    while( strTemp.length() > 0 )
    {
		float fScale = TLFontTex::sharedTLFontTex()->getFontScale( m_fFontSize );
        char* pTemp = (char*)strTemp.c_str();

        if( m_eRichStringFlag == TL_RICH_STRING_FLAG_ONE_LINE_DOTDOTDOT )
        {
            if( m_kCurrentLineInfo.fLineRealWidth + m_fFontSize * 2 > kContentSize.width )
            {
                for( int j=0; j<3; ++j )
                {
                    chatTexInfo* pCTInfo = TLFontTex::sharedTLFontTex()->getChatTextInfo( "." );

                    CCSprite* pkSprite = CCSprite::createWithTexture( m_pBatchNode->getTexture(), pCTInfo->rcUV );
                    pkSprite->setAnchorPoint( CCPointZero );
                    pkSprite->setColor( ccc3( m_kColor.r, m_kColor.g, m_kColor.b ) );
                    pkSprite->setOpacity( m_kColor.a );
                    pkSprite->setScale( fScale );
                    pkSprite->setTexture2Coords( ul, vt, ur, vb );
                    m_pBatchNode->addChild( pkSprite, 0, m_nElementCount++ );

                    processNodeHandler( pkSprite );

                    NodeInfo ni;
					ni.eType = Font;
                    ni.fOriginX = m_kCurrentLineInfo.fLineRealWidth + m_fFontSize * j / 3;
                    ni.pkNode = pkSprite;
					ni.currentSize = CCSizeMake( pCTInfo->rcUV.size.width * fScale, fCommonLineHeight * fScale );
                    m_kCurrentLineInfo.listLineNode.push_back( ni );
                }
                break;
            }
        }

        //if( pTemp[0] == ' ' )
        //{
        //    // 换行了  
        //    float fTempWidth = m_fFontSize * 0.5f * fScale;
        //    if( m_eRichStringFlag == TL_RICH_STRING_FLAG_AUTO_WRAP && kContentSize.width > 0.0f && m_kCurrentLineInfo.fLineRealWidth + fTempWidth > kContentSize.width )
        //        appendLine( true );

        //    m_kCurrentLineInfo.fLineRealWidth += fTempWidth;

        //    //
        //    pTemp = cc_utf8_next_char_help( pTemp );

        //    strTemp = pTemp;

        //    continue;
        //}

        if( pTemp[0] == '\n' )
        {
            strTemp.erase( 0, 1 );

            // 如果文本要求控制在一行的话，不允许换行
            if( m_eRichStringFlag == TL_RICH_STRING_FLAG_AUTO_WRAP )
                appendLine( true );

            continue;
        }

        if( pTemp[0] == '\r' )
        {
            strTemp.erase( 0, 1 );

            moveOffsetX( 4 );

            continue;
        }

        if( pTemp[0] == '[' )   // 转义 
        {
            int nPos = strTemp.find( ']' );
            if( nPos != std::string::npos )
            {
                std::string strSub = strTemp.substr( 1, nPos - 1 );

                int nPos1 = strSub.find( ':' );
                if( nPos1 != std::string::npos )
                {
                    std::string strMark = strSub.substr( 0, nPos1 );
                    strSub.erase( 0, nPos1 + 1 );

                    strTemp.erase( 0, nPos + 1 );

                    CCLuaEngine::defaultEngine()->getLuaStack()->pushString( strMark.c_str(), strMark.length() );
                    CCLuaEngine::defaultEngine()->getLuaStack()->pushString( strSub.c_str(), strSub.length() );
                    CCLuaEngine::defaultEngine()->getLuaStack()->pushCCObject( this, "TLLabelRichTex" );
                    CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( TLFontTex::sharedTLFontTex()->ms_nParseHandle, 3 );

                    continue;
                }
            }
        }

        chatTexInfo* pCTInfo = TLFontTex::sharedTLFontTex()->getChatTextInfo( pTemp );
        if( pCTInfo == NULL )
        {
            pTemp = cc_utf8_next_char_help( pTemp );

            strTemp = pTemp;

            continue;
        }

        CCSprite* pkSprite = CCSprite::createWithTexture( m_pBatchNode->getTexture(), pCTInfo->rcUV );
        pkSprite->setAnchorPoint( CCPointZero );
        pkSprite->setColor( ccc3( m_kColor.r, m_kColor.g, m_kColor.b ) );
        pkSprite->setOpacity( m_kColor.a );
        pkSprite->setScale( fScale );
        pkSprite->setTexture2Coords( ul, vt, ur, vb );

        // 换行了  
        float fTempWidth = pCTInfo->rcUV.size.width * fScale;
        if( m_eRichStringFlag == TL_RICH_STRING_FLAG_AUTO_WRAP && kContentSize.width > 0.0f && m_kCurrentLineInfo.fLineRealWidth + fTempWidth > kContentSize.width )
            appendLine( true );

        m_pBatchNode->addChild( pkSprite, 0, m_nElementCount++ );

        processNodeHandler( pkSprite );

        NodeInfo ni;
		ni.eType = Font;
        ni.fOriginX = m_kCurrentLineInfo.fLineRealWidth;
        ni.pkNode = pkSprite;
		ni.currentSize = CCSizeMake( fTempWidth, fCommonLineHeight * fScale );
        m_kCurrentLineInfo.listLineNode.push_back( ni );

        m_kCurrentLineInfo.fLineRealWidth += ( fTempWidth + m_nWordSpacing );
		// line height
        if( m_kCurrentLineInfo.fLineRealHeight < pCTInfo->rcUV.size.height * fScale )
            m_kCurrentLineInfo.fLineRealHeight = pCTInfo->rcUV.size.height * fScale;

		// common height
        if( m_kCurrentLineInfo.fMaxFontCommonHeight < fCommonLineHeight * fScale )
            m_kCurrentLineInfo.fMaxFontCommonHeight = fCommonLineHeight * fScale;
		
        pTemp = cc_utf8_next_char_help( pTemp );
        strTemp = pTemp;
    }
}

void TLLabelRichTex::appendLine( bool bForcibly )
{
    // 这个代表这行完全没有内容
    if( !bForcibly && m_kCurrentLineInfo.fLineRealWidth == 0.0f )
        return;

	// 这代表这是一个空行
	if( m_kCurrentLineInfo.listLineNode.empty() )
	{
		m_kCurrentLineInfo.fLineRealHeight = m_fFontSize;
		m_kCurrentLineInfo.fLineRealWidth = 0.0f;
	}

	// 
	m_kRealSize.height += m_kCurrentLineInfo.fLineRealHeight + m_nLineSpacing;

	if( m_kCurrentLineInfo.fLineRealWidth > m_kRealSize.width )
		m_kRealSize.width = m_kCurrentLineInfo.fLineRealWidth;

	m_vecLine.push_back( m_kCurrentLineInfo );

	// 清理一下 
	m_kCurrentLineInfo.fLineRealWidth = 0;
	m_kCurrentLineInfo.fLineRealHeight = 0;
    m_kCurrentLineInfo.fMaxFontCommonHeight = 0;
	m_kCurrentLineInfo.listLineNode.clear();

    if( m_nTabNum > 0 )
    {
        float fScale = TLFontTex::sharedTLFontTex()->getFontScale( m_fFontSize );
        float fRealOffset = m_nTabNum * m_fFontSize * fScale * 0.5f;
        m_kCurrentLineInfo.fLineRealWidth = fRealOffset;
    }
}

void TLLabelRichTex::clearLines()
{
	m_nElementCount = 0;

	m_kRealSize = CCSizeZero;

	m_kCurrentLineInfo.fLineRealWidth = 0;
	m_kCurrentLineInfo.fLineRealHeight = 0;
    m_kCurrentLineInfo.fMaxFontCommonHeight = 0;
	m_kCurrentLineInfo.listLineNode.clear();

	m_vecLine.clear();

	std::list<int>::iterator iter = m_listNodeHandlers.begin();
	std::list<int>::iterator iter_end = m_listNodeHandlers.end();
	for( ; iter != iter_end; ++iter )
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( *iter );
	m_listNodeHandlers.clear();

	m_pBatchNode->removeAllChildrenWithCleanup( true );
	m_pSpriteNode->removeAllChildrenWithCleanup( true );
}

void TLLabelRichTex::setRichString( const char* str, TL_RICH_STRING_FLAG eRichStringFlag )
{
	if( str == NULL || m_strText.compare( str ) == 0 )
		return;

	clearLines();

	m_strText = str;
    m_eRichStringFlag = eRichStringFlag;

    appendText( str );

	// 把最后一行添加进入，如果有的话 
	appendLine( false );

	// 更新颜色（之前未考虑颜色与透明度的传递而导至遗漏
	setColor(_realColor);
	setOpacity(_realOpacity);

	// 重新布局一次 
	adjustLayout();
}

CCNode* TLLabelRichTex::getChildByTag( int tag )
{
	if( m_pBatchNode != NULL )
	{
		CCNode* pChildNode = m_pBatchNode->getChildByTag( tag );
		if( pChildNode != NULL )
			return pChildNode;
	}

	if( m_pSpriteNode != NULL )
		return m_pSpriteNode->getChildByTag( tag );

	return NULL;
}

CCSize TLLabelRichTex::getRealSize()
{
	return m_kRealSize;
}

void TLLabelRichTex::showCursor( bool bShow, bool bDefaultPos )
{
    if( m_pCursor == NULL )
    {
        m_pCursor = MCLoader::sharedMCLoader()->loadSprite( "Cursor.png" );
        m_fCursorHeight = m_pCursor->getContentSize().height;
        //m_pCursor->setAnchorPoint( CCPoint( 0.5f, 0.5f ) );
        m_pCursor->setAnchorPoint( CCPointZero );

        std::string strTempText = m_strText;

        // 默认的光标坐标
        setRichString( "*", m_eRichStringFlag );
        m_kCursorDefaultPos = m_kCursorPosition;

        float fScale = TLFontTex::sharedTLFontTex()->getFontScale( m_fFontSize );
        chatTexInfo* pCTInfo = TLFontTex::sharedTLFontTex()->getChatTextInfo( "*" );
		float fTempWidth = pCTInfo->rcUV.size.width * fScale;
        m_kCursorDefaultPos.x -= fTempWidth;

        setRichString( strTempText.c_str(), m_eRichStringFlag );

        // 
        m_pCursor->setPosition( m_kCursorPosition );
        addChild( m_pCursor );
    }

    // 光标闪烁
    if( bShow )
    {
        m_pCursor->setVisible( true );
        cocos2d::CCRepeatForever* pAction = cocos2d::CCRepeatForever::create( cocos2d::CCBlink::create( 1.0f, 1 ) );
        m_pCursor->runAction( pAction );
    }
    else
    {
        m_pCursor->setVisible( false );
        m_pCursor->stopAllActions();
    }

    m_pCursor->setPosition( bDefaultPos ? m_kCursorDefaultPos : m_kCursorPosition );
}

void TLLabelRichTex::setFontSize( float fFontSize )
{
	if( m_fFontSize != fFontSize )
	{
		m_fFontSize = fFontSize;

		//setRichString( getRichString(), m_eRichStringFlag );
	}
}

void TLLabelRichTex::setAlignment( CCImage::ETextAlign eAlignment )
{
	if( m_eAlignment != eAlignment )
	{
		m_eAlignment = eAlignment;

		adjustLayout();
	}
}

void TLLabelRichTex::adjustLayout()
{
	CCSize kContentSize = m_bRealSizeLayout ? getRealSize() : getContentSize();

	float current_y = kContentSize.height;

    m_kCursorPosition = m_kCursorDefaultPos;

	for( int i=0; i < (int)m_vecLine.size(); ++i )
	{
        float fTempHeight = m_vecLine[i].fLineRealHeight + m_nLineSpacing;
		current_y -= fTempHeight;

		if( m_vecLine[i].listLineNode.empty() )
			continue;

		float fixYRate = 0;
		float offset_x = 0;
		float offset_y = current_y;
		switch( m_eAlignment )
		{
		case CCImage::kAlignCenter:
			offset_x = ( kContentSize.width - m_vecLine[i].fLineRealWidth ) * 0.5f;
			offset_y += ( -kContentSize.height * 0.5f + m_kRealSize.height * 0.5f );
			fixYRate = 0.5f;
			break;
		case CCImage::kAlignTop:
			offset_x = ( kContentSize.width - m_vecLine[i].fLineRealWidth ) * 0.5f;
			fixYRate = 1.0f;
			break;
		case CCImage::kAlignBottom:
			offset_x = ( kContentSize.width - m_vecLine[i].fLineRealWidth ) * 0.5f;
			offset_y += ( -kContentSize.height + m_kRealSize.height );
			break;
		case CCImage::kAlignTopRight:
			offset_x = kContentSize.width - m_vecLine[i].fLineRealWidth;
			fixYRate = 1.0f;
			break;
		case CCImage::kAlignRight:
			offset_x = kContentSize.width - m_vecLine[i].fLineRealWidth;
			offset_y += ( -kContentSize.height * 0.5f + m_kRealSize.height * 0.5f );
			fixYRate = 0.5f;
			break;
		case CCImage::kAlignBottomRight:
			offset_x = kContentSize.width - m_vecLine[i].fLineRealWidth;
			offset_y += ( -kContentSize.height + m_kRealSize.height );
			break;
		case CCImage::kAlignTopLeft:
			offset_x = 0.0f;
			fixYRate = 1.0f;
			break;
		case CCImage::kAlignLeft:
			offset_x = 0.0f;
			offset_y += ( -kContentSize.height * 0.5f + m_kRealSize.height * 0.5f );
			fixYRate = 0.5f;
			break;
		case CCImage::kAlignBottomLeft:
			offset_x = 0.0f;
			offset_y += ( -kContentSize.height + m_kRealSize.height );
			break;
		}// end switch( m_eAlignment ) 

        m_kCursorPosition.y = offset_y + ( fTempHeight - m_fCursorHeight ) * 0.5f;
        //m_kCursorPosition.y = offset_y;

		std::list<NodeInfo>::iterator iter = m_vecLine[i].listLineNode.begin();
		std::list<NodeInfo>::iterator iter_end = m_vecLine[i].listLineNode.end();
		for( ; iter != iter_end; ++iter )
		{
			CCNode* pkNode = iter->pkNode;
            float fOriginX = iter->fOriginX;

            float real_offset_y = offset_y;

            MovieClip* mc = toMovieClip( pkNode );
            if( mc )
            {
                float temp = current_y - m_vecLine[i].fLineRealHeight;
                real_offset_y = temp + mc->mcBoundingBox.size.height * 0.5f + mc->mcBoundingBox.size.height + ( offset_y - current_y );
            }

			float fixY = 0;
			switch (iter->eType)
			{
			case Font:
				//fixY = (m_vecLine[i].fLineRealHeight - m_vecLine[i].fMaxFontCommonHeight) * fixYRate;
				fixY = (m_vecLine[i].fLineRealHeight - iter->currentSize.height) * fixYRate;
				break;
			case Sprite:
			default:
				fixY = (m_vecLine[i].fLineRealHeight - iter->currentSize.height) * fixYRate;
				break;
			}

			pkNode->setPosition( fOriginX + offset_x, real_offset_y + fixY);

			m_kCursorPosition.x = pkNode->getPositionX() + iter->currentSize.width;
		}// end for( ; iter != iter_end; ++iter )
	}// end for( int i=0; i < (int)m_vecLine.size(); ++i )

    // 更新光标的位置
    if( m_pCursor )
    {
        m_pCursor->setPosition( m_kCursorPosition );
    }
}

void TLLabelRichTex::setCurrentNodeHandler( int nClickHandler )
{
	m_nNodeHandler = nClickHandler;

	if( m_nNodeHandler != 0 )
		m_listNodeHandlers.push_back( nClickHandler );
}

void TLLabelRichTex::clearCurrentNodeHandler()
{
	m_nNodeHandler = 0;
}

void TLLabelRichTex::processNodeHandler( CCNode* pNode )
{
	if( m_nNodeHandler == 0 )
		return;

	CCLuaEngine::defaultEngine()->getLuaStack()->pushCCObject( pNode, "CCNode" );
	CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nNodeHandler, 1 );
}

void TLLabelRichTex::setColorIndex( int nColorIndex )
{
    m_nColorIndex = nColorIndex;
    TLFontTex::sharedTLFontTex()->getColorTextureCoords( m_nColorIndex, ul, vt, ur, vb );
}

int TLLabelRichTex::getColorIndex() const
{
    return m_nColorIndex;
}

void TLLabelRichTex::changeColorIndex( int nColorIndex )
{
    m_nColorIndex = nColorIndex;
    TLFontTex::sharedTLFontTex()->getColorTextureCoords( m_nColorIndex, ul, vt, ur, vb );

	for( int i=0; i < (int)m_vecLine.size(); ++i )
    {
        std::list<NodeInfo>::iterator iter = m_vecLine[i].listLineNode.begin();
		std::list<NodeInfo>::iterator iter_end = m_vecLine[i].listLineNode.end();
		for( ; iter != iter_end; ++iter )
		{
			CCNode* node = iter->pkNode;
			if( node->getNodeType() == ND_BITMAP )
            {
				((CCSprite*)node)->setTexture2Coords( ul, vt, ur, vb );
            }
		}
    }
}
