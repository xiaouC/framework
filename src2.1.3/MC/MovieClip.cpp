#include "MovieClip.h"
#include "MCLoader.h"
#include "MCFrame.h"
#include "../Common/TLCommon.h"
#include "cocoa/CCNS.h"
#include <cstring>
#include "../RichText/TLLabelRichTex.h"
#include "CCLuaEngine.h"

using namespace framework;

//////////////////////////////////////////////////////////////////////////
std::string StaticUIMC::m_strTextureName;
StaticUIMC::StaticUIMC()
{
	CCTexture2D* pkStaticUITexture = MCLoader::sharedMCLoader()->loadTexture( m_strTextureName );
	m_pkStaticUIBatchNode = CCSpriteBatchNode::createWithTexture( pkStaticUITexture );

	addChild( m_pkStaticUIBatchNode );
}

StaticUIMC::~StaticUIMC()
{
}

bool StaticUIMC::init( const Layer* layer )
{
	if( layer == NULL || layer->keyframes_size() == 0 )
		return false;

	const Keyframe& kf = layer->keyframes( 0 );
	for( int i=0; i < kf.elements_size(); ++i )
	{
		const Element& elem = kf.elements( i );
		if( (NodeType)( elem.type() ) != ND_BITMAP )
			continue;

		CCSprite* pkSprite = MCLoader::sharedMCLoader()->loadSprite( elem.libname().c_str() );
		const Point& p = elem.position();
		pkSprite->setPosition( ccp( p.x(), p.y() ) );

		m_pkStaticUIBatchNode->addChild( pkSprite );
	}

	return true;
}

//////////////////////////////////////////////////////////////////////////
inline static CCRect toCCRect(const Rect &r)
{
    return CCRectMake(r.x(), r.y(), r.w(), r.h());
}

inline static CCPoint toCCPoint(const Point &p)
{
    return ccp(p.x(), p.y());
}

inline static ccColor3B toColor3B(const Color &c)
{
    return ccc3(c.r(), c.g(), c.b());
}

inline static ccColor4B toColor4B(const Color &c, GLbyte alpha)
{
    return ccc4(c.r(), c.g(), c.b(), alpha);
}

inline static int safe_floor(float f)
{
#ifndef WIN32
	return round(f*1000)/1000;
#else
	return (int)( floor( f * 1000 + 0.5f ) / 1000 );
#endif
}

#define interp(a, b, p) (a+(b-a)*p)
#define interp_n( a, b, p ) ( a * ( 1 - p ) + b * p )


#define PointEqual(p1, p2) (p1.x()==p2.x() && p1.y()==p2.y())

static void setNodeFromTween(CCNode *node, const Element &startElem, const Element &endElem, float p)
{
    // rotation
    float ra = startElem.rotation();
    float rb = endElem.rotation();
    if(rb!=ra) {
        // interpolation
        node->setRotation(interp(ra, rb, p));
    }

    // scale
    const Point &sa = startElem.scalevalue();
    const Point &sb = endElem.scalevalue();
    if (!PointEqual(sa, sb)) {
        // interpolation
        node->setScaleX(interp(sa.x(), sb.x(), p));
        node->setScaleY(interp(sa.y(), sb.y(), p));
    }

    // position
    const CCPoint &pa = toCCPoint(startElem.position());
    const CCPoint &pb = toCCPoint(endElem.position());
	if( !pa.equals( pb ) )
    {
        node->setPositionX(interp(pa.x, pb.x, p));
        node->setPositionY(interp(pa.y, pb.y, p));
    }

    // alpha
 //   GLbyte ba = startElem.alpha();
 //   GLbyte bb = endElem.alpha();
 //   if (bb!=ba) {
 //       setNodeAlpha(node, interp(ba, bb, p));
	//}
	unsigned int a1 = startElem.alpha();
	unsigned int a2 = endElem.alpha();
	if( a1 != a2 )
	{
		unsigned int a3 = (unsigned int)interp_n( a1, a2, p );
		GLbyte ba = a3 >= 255 ? 255 : a3;

//		CCLog( "a1=%d,a2=%d,p=%0.3f,a3=%d,ba=%d", a1, a2, p, a3, ba );
		setNodeAlpha( node, ba );
	}

    // color
    const Color &c1 = startElem.color();
    const Color &c2 = endElem.color();
    bool dirty = false;
    unsigned int r=255,g=255,b=255;
    if (c1.r()!=c2.r())
    {
        r = (unsigned int)( interp_n( c1.r(), c2.r(), p ) );
        dirty = true;
    }
    if (c1.g()!=c2.g())
    {
        g = (unsigned int)( interp_n( c1.g(), c2.g(), p ) );
        dirty = true;
    }
    if (c1.b()!=c2.b())
    {
        b = (unsigned int)( interp_n( c1.b(), c2.b(), p ) );
        dirty = true;
    }
    if(dirty)
    {
        setNodeColor( node, ccc3(r,g,b));
    }
}

static void setNodeFromElement(CCNode *node, const Element &elem, MovieClip* mc)
{
    if (elem.has_rotation())
    {
        node->setRotation(elem.rotation());
    }

    if (elem.has_alpha())
    {
        setNodeAlpha(node, elem.alpha());
    }

	if(elem.has_color())
	{
		setNodeColor(node, ccc3(elem.color().r(), elem.color().g(), elem.color().b()));
	}

    node->setContentSize(CCSizeMake(elem.boundingbox().w(), elem.boundingbox().h()));
	
    if (elem.has_scalevalue())
    {
        node->setScaleX(elem.scalevalue().x());
        node->setScaleY(elem.scalevalue().y());
    }

	if(elem.has_skew())
	{
		node->setSkewX(elem.skew().x());
		node->setSkewY(elem.skew().y());
	}

    node->setPosition(toCCPoint(elem.position()));

    if (node->getNodeType()==ND_BITMAP && (NodeType)elem.type()==ND_BITMAP)
    {
        // change sprite frame
		if( mc->m_bAsync )
		{
			CCSprite* pSprite = (CCSprite*)node;
			MCLoader::sharedMCLoader()->loadSpriteFrameAsync( elem.libname().c_str(), pSprite );
		}
		else
		{
			CCSpriteFrame* frame = MCLoader::sharedMCLoader()->loadSpriteFrame(elem.libname().c_str());
			if (frame!=NULL)
				((CCSprite*)node)->setDisplayFrame(frame);
		}
    }

    //if (elem.depth!=0 && node->getParent())
    //    node->getParent()->reorderChild(node, elem.depth);
}

static CCNode* createNodeFromElement(MovieClip* mc, const Element &elem)
{
    CCNode* node = NULL;

    CCSpriteFrame* frame = NULL;
    switch((NodeType)elem.type()) {
        case ND_BITMAP:
			if( mc->m_bAsync )
			{
				node = MCLoader::sharedMCLoader()->loadSpriteAsync( elem.libname().c_str() );
			}
			else
			{
                // 模拟慢速加载
                //if (mc->getSymbolInfo()->framecount()>1)
                //    usleep(1000000);
				frame = MCLoader::sharedMCLoader()->loadSpriteFrame(elem.libname().c_str());
				if (frame!=NULL)
					node = CCSprite::createWithSpriteFrame(frame);
				else
					node = CCNode::create();
			}
            break;
        case ND_RECT:
            node = CCLayerColor::create(toColor4B(elem.color(), elem.alpha()));
 //           node->ignoreAnchorPointForPosition(true);
            break;
        case ND_FRAME:
            node = MCFrame::createWithBox(toCCRect(elem.boundingbox()));
            break;
        case ND_BMTEXT:
            node = CCLabelBMFont::create(elem.text().c_str(), "", 0, (CCTextAlignment)elem.alignment());
            break;
        case ND_TTFTEXT:
            {
//    				node = CCLabelTTFEdge::labelWithString(elem.text().c_str(), toCCRect(elem.boundingbox()).size, (CCTextAlignment)elem.alignment(), strFontName.c_str(), elem.fontsize());
//    				((CCLabelTTF*)node)->setColor(toColor3B(elem.color()));
				CCImage::ETextAlign align = CCImage::kAlignCenter;
				if ( kCCTextAlignmentLeft == elem.alignment() )
					align = CCImage::kAlignLeft;
				else if ( kCCTextAlignmentRight == elem.alignment() )
					align = CCImage::kAlignRight;

 				//node = CCLabelTexFont::labelWithString(elem.text().c_str(), elem.fontsize(), toCCRect(elem.boundingbox()).size, align);
  				//((CCLabelTexFont*)node)->setColor(toColor3B(elem.color()));

				node = TLLabelRichTex::create( "", (float)elem.fontsize(), toCCRect( elem.boundingbox() ).size, align );
				ccColor3B clr = toColor3B( elem.color() );
				((TLLabelRichTex*)node)->setFontColor(clr.r, clr.g, clr.b, 255);
				((TLLabelRichTex*)node)->setRichString( elem.text().c_str() );
			}
            break;
        case ND_MOVIECLIP:
            {
                MovieClip* pChildMC = MovieClip::createWithName( elem.libname().c_str(), mc->m_bAsync );
                pChildMC->mcOriginBoundingBox = toCCRect( elem.boundingbox() );
                pChildMC->mcBoundingBox = pChildMC->mcOriginBoundingBox;

                node = pChildMC;
            }
            break;
        default:
            CCLOGERROR("unsupported element type %d\n", elem.type());
            return CCNode::create();
    }
    //node->setAnchorPoint(ccp(0,0));

    if (node!=NULL && elem.has_instancename())
    {
        node->setInstanceName( (std::string&)elem.instancename() );
    }
    return node;
}

static int getKeyframeAndProgress(float elapsed, float frameRate, int frameCount, const Layer &layer, float* progress)
{
    // 计算当前关键帧，超过关键帧的时间
    // 当前第几帧 从0开始
    int frameIdx = safe_floor(elapsed * frameRate);
    if (frameIdx>frameCount-1)
        frameIdx = frameCount-1;
    int keyframeIdx = -1;
    for (int i=0; i<layer.keyframes_size(); i++)
    {
        const Keyframe &keyframe = layer.keyframes(i);
        if (frameIdx >= keyframe.startframe() && frameIdx < keyframe.startframe()+keyframe.duration())
        {
            keyframeIdx = i;
            break;
        }
    }

    if (keyframeIdx==-1)
        return -1;

    const Keyframe &keyframe = layer.keyframes(keyframeIdx);
    *progress = 0;
    if (keyframe.ismotion() && keyframeIdx<layer.keyframes_size()-1)
    {
        // 补间开始关键帧
        float startElapsed = keyframe.startframe()/frameRate;
        float endElapsed = (keyframe.startframe()+keyframe.duration())/frameRate;
        *progress = (elapsed-startElapsed) / (endElapsed-startElapsed);
    }
    return keyframeIdx;
}

void clearLayer(CCArray* layerNodes)
{
    for(unsigned int i=0; i<layerNodes->count(); i++)
    {
        CCNode* pNode = (CCNode*)layerNodes->objectAtIndex( i );
        //pNode->setVisible( false );
        CCAssert( pNode->getParent() != NULL ," the parent of pNode is NULL");
        pNode->removeFromParentAndCleanup(true);
    }
    layerNodes->removeAllObjects();

}

MovieClip::MovieClip( bool bAsync )
{
	m_bAsync = bAsync;
    m_nodeType = ND_MOVIECLIP;
	_cascadeOpacityEnabled = true;       // cascade alpha
    m_frameRate = 12;
    mcOriginBoundingBox = CCRectMake(0,0,0,0);
    mcBoundingBox = mcOriginBoundingBox;
    m_loopCount = 0;
    m_reverse = false;
    m_autoClear = true;
    //m_wrapAround = false;
    m_playing = false;
    m_resetKeyframe = false;

	m_nPlayEndHandler = 0;
	m_pPlayEndCallbackObject = NULL;
	m_pPlayEndCallFuncPtr = NULL;
	m_ulUserData = 0;
}

MovieClip::~MovieClip()
{
	// 清除layer nodes
	std::vector<CCArray*>::iterator iter = m_layers.begin();
	for( ; iter!=m_layers.end(); iter++ )
	{
		CCArray* arr = (*iter);

		clearLayer( arr );

		arr->release();
	}
	m_layers.clear();

	if( m_nPlayEndHandler != 0 )
	{
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nPlayEndHandler );

		m_nPlayEndHandler = 0;
	}
}

MovieClip* MovieClip::createWithName( const char *mcName, bool bAsync )
{
    MovieClip* mc = new MovieClip( bAsync );
    if( mc && mc->initWithName( mcName ) )
    {
        mc->autorelease();

        return mc;
    }
    CC_SAFE_DELETE(mc);
    return NULL;
}

bool MovieClip::initWithName(const char* mcName)
{
//	const Symbol* sym = MCLoader::sharedMCLoader()->loadSymbol(mcName);
	const Symbol* sym = MCLoader::sharedMCLoader()->getSymbol(mcName);
    if (sym!=NULL)
    {
        return initWithSymbol(sym);
    }
    return false;
}

bool MovieClip::initWithSymbol(const Symbol* sym)
{
    m_symbolInfo = sym;
	m_frameRate = sym->framerate();
    mcOriginBoundingBox = toCCRect(sym->boundingbox());
    mcBoundingBox = mcOriginBoundingBox;
    setContentSize(mcBoundingBox.size);

    // 初始化instance map
    if (sym->framecount()>0)
    {
		CCAssert( m_layers.empty(), "m_layers is not empty!" );
        m_layers.clear();
        m_layers.reserve(sym->layers_size());
        // 初始化图层容器
        for (int i=0; i<sym->layers_size(); i++)
        {
            CCArray* arr = CCArray::createWithCapacity( sym->layers(i).keyframes(0).elements_size() );
            arr->retain();
            m_layers.push_back(arr);
        }
        for (int i=0; i<sym->layers_size(); i++)
        {
            resetLayer(i, 0);
        }
    }

    return true;
}

/**
 * init with each layer's keyframe.
 */
void MovieClip::resetLayer(int iLayer, int iKeyframe)
{
    const Layer &layer = m_symbolInfo->layers(iLayer);
    if (layer.keyframes_size()==0)
        return;
    const Keyframe &keyframe = layer.keyframes(iKeyframe);

    CCArray* layerNodes = m_layers[iLayer];

    if (m_resetKeyframe)
    {
        while (layerNodes->count()>0)
        {
            removeLayerChild(iLayer, (CCNode*)layerNodes->objectAtIndex(0), true);
        }
        for(int i=0; i<keyframe.elements_size(); i++)
        {
            CCNode *node = createNodeFromElement(this, keyframe.elements(i));
            if (node!=NULL)
            {
                addLayerChild(iLayer, node);
            }
        }
    }
    else
    {
        int childCount = layerNodes->count();
        int delta = keyframe.elements_size() - childCount;
        if (delta > 0)
        {
            for (int i=childCount; i<keyframe.elements_size(); i++)
            {
                CCNode *node = createNodeFromElement(this, keyframe.elements(i));
                if (node!=NULL)
                {
                    addLayerChild(iLayer, node);
                }
            }
        }
        else if (delta < 0)
        {
            // 从后面删除多余元素 #TODO 更好地匹配需要删除的元素
            for (int i=0, j=childCount-1; i<-delta; i++, j--)
            {
                removeLayerChild(iLayer, (CCNode*)layerNodes->objectAtIndex(layerNodes->count()-1), true);
            }
        }
    }

    // init children nodes.
    for(int i=0; i<keyframe.elements_size(); i++)
    {
        CCNode *node = (CCNode*)layerNodes->objectAtIndex(i);
        setNodeFromElement(node, keyframe.elements(i), this);
    }
	
	// 执行这帧的脚本
	if(keyframe.has_script() && keyframe.script().size() > 0)
	{
		CCLuaEngine::defaultEngine()->executeString(keyframe.script().c_str());		
	}
}

void MovieClip::updateLayer(int i)
{
    float progress=0;
    bool newKeyframe = false;
    const Layer &layer = m_symbolInfo->layers(i);

    int keyframeIdx = getKeyframeAndProgress(m_elapsed, (float)m_frameRate, m_symbolInfo->framecount(), layer, &progress);
    if (keyframeIdx!=m_currentKeyFrames[i])
    {
        m_currentKeyFrames[i] = keyframeIdx;
        newKeyframe = true;
    }

    //if (m_wrapAround && !newKeyframe && keyframeIdx==layer.keyframes_size()-1)
    //{
    //    m_elapsed = m_reverse ? m_startTime : m_endTime;
    //    return;
    //}

    if (keyframeIdx<0)
    {
        // 空帧，直接清空
        clearLayer(m_layers[i]);
    }
    else if (newKeyframe || progress>0)
    {
        if (newKeyframe)
        {
            // TODO 优化
            resetLayer(i, keyframeIdx);
        }
        if (progress>0)
        {
            updateKeyframe(i, keyframeIdx, progress);
        }
    }
}

void MovieClip::setScaleX(float fScaleX)
{
    CCNodeRGBA::setScaleX( fScaleX );

    mcBoundingBox.origin.x = mcOriginBoundingBox.origin.x * fScaleX;
    mcBoundingBox.size.width = mcOriginBoundingBox.size.width * fScaleX;
}

void MovieClip::setScaleY(float fScaleY)
{
    CCNodeRGBA::setScaleY( fScaleY );

    mcBoundingBox.origin.y = mcOriginBoundingBox.origin.y * fScaleY;
    mcBoundingBox.size.height = mcOriginBoundingBox.size.height * fScaleY;
}

void MovieClip::setScale(float fScale)
{
    CCNodeRGBA::setScale( fScale );

    mcBoundingBox.origin.x = mcOriginBoundingBox.origin.x * fScale;
    mcBoundingBox.origin.y = mcOriginBoundingBox.origin.y * fScale;
    mcBoundingBox.size.width = mcOriginBoundingBox.size.width * fScale;
    mcBoundingBox.size.height = mcOriginBoundingBox.size.height * fScale;
}
void MovieClip::updateKeyframe(int iLayer, int keyframeIdx, float progress)
{
    const Layer &layer = m_symbolInfo->layers(iLayer);
    const Keyframe &startKF = layer.keyframes(keyframeIdx);

    CCAssert(keyframeIdx<layer.keyframes_size()-1, "最后一帧不能是补间开始关键帧");
    const Keyframe &endKF = layer.keyframes(keyframeIdx+1);

    unsigned int i=0;
    for(i=0; i<m_layers[iLayer]->count(); i++)
    {
        CCNode* node = (CCNode*) m_layers[iLayer]->objectAtIndex(i);
        if (i<(unsigned)endKF.elements_size())
            setNodeFromTween(node, startKF.elements(i), endKF.elements(i), progress);
    }
}

void MovieClip::update( float dt )
{
    if (m_reverse)
        m_elapsed -= dt;
    else
        m_elapsed += dt;

    if( ( m_reverse && m_elapsed < m_startTime ) || ( m_elapsed > m_endTime ) )
    {
        // finish
        if (m_loopCount==0)
        {
            m_elapsed = m_reverse ? m_startTime : m_endTime;

            // 重置最后一帧状态
            for (int i=0; i<m_symbolInfo->layers_size(); i++)
            {
                updateLayer(i);
            }

            m_playing = false;
            this->unscheduleUpdate();

			if( m_pPlayEndCallbackObject != NULL && m_pPlayEndCallFuncPtr != NULL )
				(m_pPlayEndCallbackObject->*(m_pPlayEndCallFuncPtr))( m_ulUserData );
			else if( m_nPlayEndHandler != 0 )
				CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nPlayEndHandler, 0 );

            return;
        }
        else
        {
            //m_elapsed = m_reverse ? m_endTime : m_startTime;
            if( m_reverse )
                m_elapsed = m_endTime - ( m_startTime - m_elapsed );
            else
                m_elapsed = ( m_elapsed - m_endTime ) + m_startTime;
            if (m_loopCount>0)
                m_loopCount--;
        }
    }

    for (int i=0; i<m_symbolInfo->layers_size(); i++)
    {
        updateLayer(i);
    }
}

float MovieClip::getTimeLength( int nFrameRate )
{
	if( nFrameRate == -1 )
		nFrameRate = m_frameRate;

	int nFrameCount = m_symbolInfo->framecount();

	return (float)nFrameCount / (float)nFrameRate;
}

int MovieClip::getFrameCount()
{
	return m_symbolInfo->framecount();
}

void MovieClip::start()
{
    pause();

    m_playing = true;
    scheduleUpdate();
}

void MovieClip::pause()
{
    m_playing = false;
    unscheduleUpdate();
}

void MovieClip::play(int startFrame, int durationFrameCount, int loopCount, bool reverse)
{
    if(startFrame<0 || startFrame >= m_symbolInfo->framecount())
    {
        CCLOGERROR("帧索引越界");
        return;
    }

    if (m_playing)
    {
        if (loopCount>0)
        {
            m_loopCount = loopCount;
        }
        return;
    }

    m_loopCount = loopCount;
    m_reverse = reverse;

    // init layer progress infomation
    m_currentKeyFrames.clear();
    for (int i=0; i<m_symbolInfo->layers_size(); i++)
    {
        m_currentKeyFrames.push_back(-1);
    }

    int endFrame = 0;
    if (durationFrameCount<0)
    {
        endFrame = m_symbolInfo->framecount()-1;
    }
    else
    {
        endFrame = startFrame + durationFrameCount;
        if (endFrame>=m_symbolInfo->framecount())
            endFrame = m_symbolInfo->framecount()-1;
    }

    //CCAssert(endFrame>=0 && endFrame<m_symbolInfo->framecount(), "播放帧数超过总帧数");

    m_startTime = (float)startFrame / m_frameRate;
    m_endTime = (float)(endFrame+1) / m_frameRate;
    m_elapsed = m_reverse ? m_endTime : m_startTime;

    if (m_autoClear)
        clear();

    update(0);

    if (durationFrameCount!=0 && m_endTime>m_startTime)
        start();
}

void MovieClip::clear()
{
    // 清除layer nodes
    std::vector<CCArray*>::iterator iter = m_layers.begin();
    for(; iter!=m_layers.end(); iter++)
    {
        clearLayer(*iter);
    }
}

void MovieClip::addLayerChild(int iLayer, CCNode *pNode)
{
    m_layers[iLayer]->addObject(pNode);
    addChild(pNode, iLayer-100);
}

void MovieClip::removeLayerChild(int iLayer, CCNode *pNode, bool cleanup)
{
	//pNode->setVisible( false );
    m_layers[iLayer]->removeObject(pNode);
    removeChild(pNode, cleanup);
}

bool MovieClip::RegisterPlayEndCallbackHandler( int nPlayEndHandler )
{
	m_pPlayEndCallbackObject = NULL;
	m_pPlayEndCallFuncPtr = NULL;
	m_ulUserData = 0;

	if( m_nPlayEndHandler != 0 )
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nPlayEndHandler );

	m_nPlayEndHandler = nPlayEndHandler;

	return true;
}

bool MovieClip::RegisterPlayEndCallback( CCObject* pCallbackObject, PlayEndCallbackFuncPtr pPlayEndCallFuncPtr, unsigned long ulUserData )
{
	if( m_nPlayEndHandler != 0 )
	{
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nPlayEndHandler );
		m_nPlayEndHandler = 0;
	}

	m_pPlayEndCallbackObject = pCallbackObject;
	m_pPlayEndCallFuncPtr = pPlayEndCallFuncPtr;
	m_ulUserData = ulUserData;

	return true;
}

void MovieClip::removeAllChildrenWithCleanup(bool cleanup)
{
    clear();
    CCNode::removeAllChildrenWithCleanup(cleanup);
}


