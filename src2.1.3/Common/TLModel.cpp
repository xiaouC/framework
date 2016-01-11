#include "TLModel.h"
#include "TLCommon.h"
#include "MC/MCLoader.h"
#include "MC/MCFrame.h"
#include "cocoa/CCNS.h"
#include <cstring>
#include "CCLuaEngine.h"

using namespace framework;

#if CC_SPRITEBATCHNODE_RENDER_SUBPIXEL
#define RENDER_IN_SUBPIXEL
#else
#define RENDER_IN_SUBPIXEL(__ARGS__) (ceil(__ARGS__))
#endif


bool colorEqual(const ccColor3B& c1, const ccColor3B& c2)
{
	return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b;
}

class TLSprite : public CCSprite
{
public:
	TLSprite(float uvScale);

	static TLSprite* createWithSpriteFrame(CCSpriteFrame *pSpriteFrame, float uvScale);

	virtual void setTextureCoords(CCRect rect);
	virtual void updateTransform(void);
	virtual CCAffineTransform nodeToParentTransform(void);

protected:
	float _uvScale;
};

TLSprite::TLSprite(float uvScale)
	: _uvScale(uvScale)
{	
}

TLSprite* TLSprite::createWithSpriteFrame(CCSpriteFrame *pSpriteFrame, float uvScale)
{
	TLSprite *pobSprite = new TLSprite(uvScale);
	if (pSpriteFrame && pobSprite && pobSprite->initWithSpriteFrame(pSpriteFrame))
	{
		pobSprite->autorelease();
		return pobSprite;
	}
	CC_SAFE_DELETE(pobSprite);
	return NULL;
}


void TLSprite::setTextureCoords(CCRect rect)
{
	rect = CC_RECT_POINTS_TO_PIXELS(rect);

	CCTexture2D *tex = m_pobBatchNode ? m_pobTextureAtlas->getTexture() : m_pobTexture;
	if (! tex)
	{
		return;
	}

	float atlasWidth = (float)tex->getPixelsWide();
	float atlasHeight = (float)tex->getPixelsHigh();

	float left, right, top, bottom;

	if (m_bRectRotated)
	{
#if CC_FIX_ARTIFACTS_BY_STRECHING_TEXEL
		left    = (2*rect.origin.x+1)/(2*atlasWidth);
		right    = left+(rect.size.height*2-2)/(2*atlasWidth);
		top        = (2*rect.origin.y+1)/(2*atlasHeight);
		bottom    = top+(rect.size.width*2-2)/(2*atlasHeight);
#else
		left    = rect.origin.x/atlasWidth;
		right    = (rect.origin.x+rect.size.height) / atlasWidth;
		top        = rect.origin.y/atlasHeight;
		bottom    = (rect.origin.y+rect.size.width) / atlasHeight;
#endif // CC_FIX_ARTIFACTS_BY_STRECHING_TEXEL

		if (m_bFlipX)
		{
			CC_SWAP(top, bottom, float);
		}

		if (m_bFlipY)
		{
			CC_SWAP(left, right, float);
		}

		m_sQuad.bl.texCoords.u = left * _uvScale;
		m_sQuad.bl.texCoords.v = top * _uvScale;
		m_sQuad.br.texCoords.u = left * _uvScale;
		m_sQuad.br.texCoords.v = bottom * _uvScale;
		m_sQuad.tl.texCoords.u = right * _uvScale;
		m_sQuad.tl.texCoords.v = top * _uvScale;
		m_sQuad.tr.texCoords.u = right * _uvScale;
		m_sQuad.tr.texCoords.v = bottom * _uvScale;
	}
	else
	{
#if CC_FIX_ARTIFACTS_BY_STRECHING_TEXEL
		left    = (2*rect.origin.x+1)/(2*atlasWidth);
		right    = left + (rect.size.width*2-2)/(2*atlasWidth);
		top        = (2*rect.origin.y+1)/(2*atlasHeight);
		bottom    = top + (rect.size.height*2-2)/(2*atlasHeight);
#else
		left    = rect.origin.x/atlasWidth;
		right    = (rect.origin.x + rect.size.width) / atlasWidth;
		top        = rect.origin.y/atlasHeight;
		bottom    = (rect.origin.y + rect.size.height) / atlasHeight;
#endif // ! CC_FIX_ARTIFACTS_BY_STRECHING_TEXEL

		if(m_bFlipX)
		{
			CC_SWAP(left,right,float);
		}

		if(m_bFlipY)
		{
			CC_SWAP(top,bottom,float);
		}

		m_sQuad.bl.texCoords.u = left * _uvScale;
		m_sQuad.bl.texCoords.v = bottom * _uvScale;
		m_sQuad.br.texCoords.u = right * _uvScale;
		m_sQuad.br.texCoords.v = bottom * _uvScale;
		m_sQuad.tl.texCoords.u = left * _uvScale;
		m_sQuad.tl.texCoords.v = top * _uvScale;
		m_sQuad.tr.texCoords.u = right * _uvScale;
		m_sQuad.tr.texCoords.v = top * _uvScale;
	}
}

CCAffineTransform TLSprite::nodeToParentTransform(void)
{
	if (m_bTransformDirty) 
	{

		// Translate values
		float x = m_obPosition.x;
		float y = m_obPosition.y;

		if (m_bIgnoreAnchorPointForPosition) 
		{
			x += m_obAnchorPointInPoints.x;
			y += m_obAnchorPointInPoints.y;
		}

		// Rotation values
		// Change rotation code to handle X and Y
		// If we skew with the exact same value for both x and y then we're simply just rotating
		float cx = 1, sx = 0, cy = 1, sy = 0;
		if (m_fRotationX || m_fRotationY)
		{
			float radiansX = -CC_DEGREES_TO_RADIANS(m_fRotationX);
			float radiansY = -CC_DEGREES_TO_RADIANS(m_fRotationY);
			cx = cosf(radiansX);
			sx = sinf(radiansX);
			cy = cosf(radiansY);
			sy = sinf(radiansY);
		}

		bool needsSkewMatrix = ( m_fSkewX || m_fSkewY );


		// optimization:
		// inline anchor point calculation if skew is not needed
		// Adjusted transform calculation for rotational skew
		if (! needsSkewMatrix && !m_obAnchorPointInPoints.equals(CCPointZero))
		{
			x += cy * -m_obAnchorPointInPoints.x * m_fScaleX + -sx * -m_obAnchorPointInPoints.y * m_fScaleY;
			y += sy * -m_obAnchorPointInPoints.x * m_fScaleX +  cx * -m_obAnchorPointInPoints.y * m_fScaleY;
		}


		// Build Transform Matrix
		// Adjusted transform calculation for rotational skew
		m_sTransform = CCAffineTransformMake( cy * m_fScaleX,  sy * m_fScaleX,
			-sx * m_fScaleY, cx * m_fScaleY,
			x, y );

		// XXX: Try to inline skew
		// If skew is needed, apply skew and then anchor point
		//if (needsSkewMatrix) 
		//{
		//	CCAffineTransform skewMatrix = CCAffineTransformMake(1.0f, tanf(CC_DEGREES_TO_RADIANS(m_fSkewY)),
		//		tanf(CC_DEGREES_TO_RADIANS(m_fSkewX)), 1.0f,
		//		0.0f, 0.0f );
		//	m_sTransform = CCAffineTransformConcat(skewMatrix, m_sTransform);

		//	// adjust anchor point
		//	if (!m_obAnchorPointInPoints.equals(CCPointZero))
		//	{
		//		m_sTransform = CCAffineTransformTranslate(m_sTransform, -m_obAnchorPointInPoints.x, -m_obAnchorPointInPoints.y);
		//	}
		//}

		if (m_bAdditionalTransformDirty)
		{
			m_sTransform = CCAffineTransformConcat(m_sTransform, m_sAdditionalTransform);
			m_bAdditionalTransformDirty = false;
		}

		m_bTransformDirty = false;
	}

	return m_sTransform;
}

void TLSprite::updateTransform(void)
{
    CCAssert(m_pobBatchNode, "updateTransform is only valid when CCSprite is being rendered using an CCSpriteBatchNode");

    // recalculate matrix only if it is dirty
    if( isDirty() ) {

        // If it is not visible, or one of its ancestors is not visible, then do nothing:
        if( !m_bVisible || ( m_pParent && m_pParent != m_pobBatchNode && ((CCSprite*)m_pParent)->getShouldBeHidden()) )
        {
            m_sQuad.br.vertices = m_sQuad.tl.vertices = m_sQuad.tr.vertices = m_sQuad.bl.vertices = vertex3(0,0,0);
            m_bShouldBeHidden = true;
        }
        else 
        {
            m_bShouldBeHidden = false;

            if( ! m_pParent || m_pParent == m_pobBatchNode )
            {
                m_transformToBatch = nodeToParentTransform();
            }
            else 
            {
                CCAssert( dynamic_cast<CCSprite*>(m_pParent), "Logic error in CCSprite. Parent must be a CCSprite");
                m_transformToBatch = CCAffineTransformConcat( nodeToParentTransform() , ((CCSprite*)m_pParent)->getTransformToBatch() );
            }

            //
            // calculate the Quad based on the Affine Matrix
            //

			CCSize size = m_obRect.size;            

            float x1 = m_obOffsetPosition.x;
            float y1 = m_obOffsetPosition.y;

            float x2 = x1 + size.width;
            float y2 = y1 + size.height;
            float x = m_transformToBatch.tx;
            float y = m_transformToBatch.ty;

            float cr = m_transformToBatch.a;
            float sr = m_transformToBatch.b;
            float cr2 = m_transformToBatch.d;
            float sr2 = -m_transformToBatch.c;
            float ax = x1 * cr - y1 * sr2 + x;
            float ay = x1 * sr + y1 * cr2 + y;

            float bx = x2 * cr - y1 * sr2 + x;
            float by = x2 * sr + y1 * cr2 + y;

            float cx = x2 * cr - y2 * sr2 + x;
            float cy = x2 * sr + y2 * cr2 + y;

            float dx = x1 * cr - y2 * sr2 + x;
            float dy = x1 * sr + y2 * cr2 + y;
			
			bool needsSkewMatrix = false;

			if(m_fSkewX)
			{
				float wh = m_obRect.size.width*m_fScaleX*0.5f;
				float hh = m_obRect.size.height*m_fScaleY*0.5f;
				float fSin = sin(m_fSkewX * 3.1415926f / 180.f);
				float fCos = cos(m_fSkewX * 3.1415926f / 180.f);
				float x0 = fSin*hh;
				float y0 = fCos*hh;
				dx += x0;
				dy += -(hh-y0);
				ax += -x0;
				ay += hh-y0;
				cx += x0;
				cy += -(hh-y0);
				bx += -x0;
				by += hh-y0;

				needsSkewMatrix = true;
			}		

			if(m_fSkewY)
			{
				float wh = m_obRect.size.width*m_fScaleX*0.5f;
				float hh = m_obRect.size.height*m_fScaleY*0.5f;
				float fSin = sin(m_fSkewY * 3.1415926f / 180.f);
				float fCos = cos(m_fSkewY * 3.1415926f / 180.f);
				float x0 = fCos*wh;
				float y0 = fSin*wh;
				dx += wh-x0;
				dy += y0;
				ax += wh-x0;
				ay += y0;
				cx += -(wh-x0);
				cy += -y0;
				bx += -(wh-x0);
				by += -y0;

				needsSkewMatrix = true;
			}

			if(needsSkewMatrix)
			{
				dx -= m_obAnchorPointInPoints.x * m_fScaleX;
				dy -= m_obAnchorPointInPoints.y * m_fScaleY;
				ax -= m_obAnchorPointInPoints.x * m_fScaleX;
				ay -= m_obAnchorPointInPoints.y * m_fScaleY;
				cx -= m_obAnchorPointInPoints.x * m_fScaleX;
				cy -= m_obAnchorPointInPoints.y * m_fScaleY;
				bx -= m_obAnchorPointInPoints.x * m_fScaleX;
				by -= m_obAnchorPointInPoints.y * m_fScaleY;
			}

			m_sQuad.bl.vertices = vertex3( RENDER_IN_SUBPIXEL(ax), RENDER_IN_SUBPIXEL(ay), m_fVertexZ );
			m_sQuad.br.vertices = vertex3( RENDER_IN_SUBPIXEL(bx), RENDER_IN_SUBPIXEL(by), m_fVertexZ );
			m_sQuad.tl.vertices = vertex3( RENDER_IN_SUBPIXEL(dx), RENDER_IN_SUBPIXEL(dy), m_fVertexZ );
			m_sQuad.tr.vertices = vertex3( RENDER_IN_SUBPIXEL(cx), RENDER_IN_SUBPIXEL(cy), m_fVertexZ );
        }

        // MARMALADE CHANGE: ADDED CHECK FOR NULL, TO PERMIT SPRITES WITH NO BATCH NODE / TEXTURE ATLAS
        if (m_pobTextureAtlas)
		{
            m_pobTextureAtlas->updateQuad(&m_sQuad, m_uAtlasIndex);
        }
		
        m_bRecursiveDirty = false;
        setDirty(false);
    }

    // MARMALADE CHANGED
    // recursively iterate over children
/*    if( m_bHasChildren ) 
    {
        // MARMALADE: CHANGED TO USE CCNode*
        // NOTE THAT WE HAVE ALSO DEFINED virtual CCNode::updateTransform()
        arrayMakeObjectsPerformSelector(m_pChildren, updateTransform, CCSprite*);
    }*/
    CCNode::updateTransform();

#if CC_SPRITE_DEBUG_DRAW
    // draw bounding box
    CCPoint vertices[4] = {
        ccp( m_sQuad.bl.vertices.x, m_sQuad.bl.vertices.y ),
        ccp( m_sQuad.br.vertices.x, m_sQuad.br.vertices.y ),
        ccp( m_sQuad.tr.vertices.x, m_sQuad.tr.vertices.y ),
        ccp( m_sQuad.tl.vertices.x, m_sQuad.tl.vertices.y ),
    };
    ccDrawPoly(vertices, 4, true);
#endif // CC_SPRITE_DEBUG_DRAW
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

#define max_n(a,b)    (((a) > (b)) ? (a) : (b))
#define min_n(a,b)    (((a) < (b)) ? (a) : (b))

inline static float interp_nearangle(float a, float b, float p)
{
	if(a < 0)
	{
		a += 360;
	}
	if(b < 0)
	{
		b += 360;
	}
	float angle = 0;
	float mx = max_n(a,b);
	float mi = min_n(a,b);
	if(mx - mi > 180)
	{
		p = a > b ? (1-p) : p;
		float offset = (mi + (360 - mx))*p;
		angle = (offset > mi) ? (360 - (offset - mi)) : (mi - offset);
	}
	else
	{
		angle = (a+(b-a)*p);
	}

	return angle;
}

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

	// skew
	const Point &ska = startElem.skew();
	const Point &skb = endElem.skew();
	if (!PointEqual(ska, skb)) {
		node->setSkewX(interp_nearangle(ska.x(), skb.x(), p));
		node->setSkewY(interp_nearangle(ska.y(), skb.y(), p));
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

static void setNodeFromElement(CCNode *node, const Element &elem, TLModel* mc)
{
    if (elem.has_rotation())
    {
        node->setRotation(elem.rotation());
    }

    if (elem.has_alpha())
    {
        setNodeAlpha(node, elem.alpha());
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

  //  if (node->getNodeType()==ND_BITMAP && (NodeType)elem.type()==ND_BITMAP)
  //  {
		//CCAssert(0, "not support set bitmap");
  //      // change sprite frame
		//if( mc->m_bAsync )
		//{
		//	CCSprite* pSprite = (CCSprite*)node;
		//	MCLoader::sharedMCLoader()->loadSpriteFrameAsync( elem.libname().c_str(), pSprite );
		//}
		//else
		//{
		//	CCSpriteFrame* frame = MCLoader::sharedMCLoader()->loadSpriteFrame(elem.libname().c_str());
		//	if (frame!=NULL)
		//		((CCSprite*)node)->setDisplayFrame(frame);
		//}
  //  }

    //if (elem.depth!=0 && node->getParent())
    //    node->getParent()->reorderChild(node, elem.depth);
}

static CCSprite* createSpriteFromElement(const Element &elem, bool async, float uvScale)
{
    CCSprite* node = NULL;

    switch((NodeType)elem.type()) {
	case ND_BITMAP:
			//if( async )
			//{
			//	node = MCLoader::sharedMCLoader()->loadSpriteAsync( elem.libname().c_str() );
			//}
			//else
			//{
			//	node = MCLoader::sharedMCLoader()->loadSprite(elem.libname().c_str());
			//}

			{
				CCSpriteFrame *frame = MCLoader::sharedMCLoader()->loadSpriteFrame( elem.libname().c_str() );
				node = TLSprite::createWithSpriteFrame( frame, uvScale );
			}
			break;

        default:
            CCLOGERROR("unsupported element type %d\n", elem.type());
            return TLSprite::create();
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

static void clearLayer(CCArray* layerNodes)
{
    for(unsigned int i=0; i<layerNodes->count(); i++)
    {
        CCNode* pNode = (CCNode*)layerNodes->objectAtIndex( i );
        //pNode->setVisible( false );

        //CCAssert( pNode->getParent() != NULL ," the parent of pNode is NULL");
		if(pNode->getParent())
		{
			pNode->removeFromParentAndCleanup(true);
		}
    }
    layerNodes->removeAllObjects();

}

TLModel::TLModel(bool bAsync, float uvScale )
{
	m_bAsync = bAsync;
	m_uvScale = uvScale;
    m_nodeType = ND_MODEL;
    m_frameRate = 12;
    mcBoundingBox = CCRectMake(0,0,0,0);
    m_loopCount = 0;
    m_reverse = false;
    m_autoClear = true;
    //m_wrapAround = false;
    m_playing = false;

	m_nPlayEndHandler = 0;
	m_pPlayEndCallbackObject = NULL;
	m_pPlayEndCallFuncPtr = NULL;
	m_ulUserData = 0;
	m_nLuaPreCallScript = 0;
	m_nRegLuaPreCallScript = 0;

	m_bUseFrameColor = false;
	
	_cascadeColorEnabled = true;
    _cascadeOpacityEnabled = true;
}

TLModel::~TLModel()
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

	UnRegisterPreCallScript();
}

TLModel* TLModel::createWithName(const char *mcName, bool bAsync, float uvScale )
{	
    TLModel* mc = new TLModel( bAsync, uvScale );
    if( mc && mc->initWithName( mcName ) )
    {
        mc->autorelease();

        return mc;
    }
    CC_SAFE_DELETE(mc);
    return NULL;
}

bool TLModel::initWithName(const char* mcName)
{
//	const Symbol* sym = MCLoader::sharedMCLoader()->loadSymbol(mcName);
	const Symbol* sym = MCLoader::sharedMCLoader()->getSymbol(mcName);
    if (sym!=NULL)
    {
        return initWithSymbol(sym);
    }
    return false;
}

bool TLModel::initWithSymbol(const Symbol* sym)
{
	m_symbolInfo = sym;   
    m_frameRate = sym->framerate();
    mcBoundingBox = toCCRect(sym->boundingbox());
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
	
	if(m_pobTextureAtlas == NULL)
	{
		return false;
	}

    return true;
}

/**
 * init with each layer's keyframe.
 */
void TLModel::resetLayer(int iLayer, int iKeyframe)
{
    const Layer &layer = m_symbolInfo->layers(iLayer);
    if (layer.keyframes_size()==0)
        return;
    const Keyframe &keyframe = layer.keyframes(iKeyframe);

    CCArray* layerNodes = m_layers[iLayer];

    while (layerNodes->count()>0)
    {
        removeLayerChild(iLayer, (CCNode*)layerNodes->objectAtIndex(0), true);
    }
    for(int i=0; i<keyframe.elements_size(); i++)
	{
		if(m_pobTextureAtlas == NULL)
		{
			CCTexture2D* tex= MCLoader::sharedMCLoader()->loadTextureByFrame(keyframe.elements(i).libname().c_str());						
			if(tex)
			{
				initWithTexture(tex, 0);
			}
			else
			{
				CCLOG("can't load file %s", keyframe.elements(i).libname().c_str());
			}
		}
        CCSprite *node = createSpriteFromElement(keyframe.elements(i), m_bAsync, m_uvScale);
        addLayerChild(iLayer, node);
    }

    // init children nodes.
    for(int i=0; i<keyframe.elements_size(); i++)
    {
        CCNode *node = (CCNode*)layerNodes->objectAtIndex(i);
        setNodeFromElement(node, keyframe.elements(i), this);
    }

	// if (colorEqual(_realColor, ccWHITE))
	if (m_bUseFrameColor)
	{
		setOpacity( _realOpacity );
		setColor( _realColor );
	}
	
	// 执行这帧的脚本
	//if (bExecuteScript)
	//{
	//	if(keyframe.has_script() && keyframe.script().size() > 0)
	//	{
	//		if (m_nLuaPreCallScript != 0)
	//		{
	//			CCLuaEngine::defaultEngine()->getLuaStack()->pushString( keyframe.script().c_str() );
	//			CCLuaEngine::defaultEngine()->getLuaStack()->pushString( m_symbolInfo->name().c_str() );
	//			CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler(m_nLuaPreCallScript, 2);
	//		}

	//		if (m_nRegLuaPreCallScript != 0)
	//		{
	//			CCLuaEngine::defaultEngine()->getLuaStack()->pushString( keyframe.script().c_str() );
	//			CCLuaEngine::defaultEngine()->getLuaStack()->pushString( m_symbolInfo->name().c_str() );
	//			CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler(m_nRegLuaPreCallScript, 2);
	//		}

	//		//CCLOG(keyframe.script().c_str());
	//		CCLuaEngine::defaultEngine()->executeString(keyframe.script().c_str());
	//	}
	//}
}

void TLModel::executeKeyframeScript(int iLayer, int iKeyframe)
{
	const Layer &layer = m_symbolInfo->layers(iLayer);
	if (layer.keyframes_size()==0)
		return;
	const Keyframe &keyframe = layer.keyframes(iKeyframe);
	if(keyframe.has_script() && keyframe.script().size() > 0)
	{
		// CCLOG("run execute keyframe Script");
		if (m_nLuaPreCallScript != 0)
		{
			CCLuaEngine::defaultEngine()->getLuaStack()->pushString( keyframe.script().c_str() );
			CCLuaEngine::defaultEngine()->getLuaStack()->pushString( m_symbolInfo->name().c_str() );
			CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler(m_nLuaPreCallScript, 2);
		}

		if (m_nRegLuaPreCallScript != 0)
		{
			CCLuaEngine::defaultEngine()->getLuaStack()->pushString( keyframe.script().c_str() );
			CCLuaEngine::defaultEngine()->getLuaStack()->pushString( m_symbolInfo->name().c_str() );
			CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler(m_nRegLuaPreCallScript, 2);
		}

		//CCLOG(keyframe.script().c_str());
		CCLuaEngine::defaultEngine()->executeString(keyframe.script().c_str());
	}
}

void TLModel::updateLayer(int i)
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

	// 执行脚本 
	if (keyframeIdx == 0 && newKeyframe)	// 跳过首次脚本执行 
		return;
	int nRunScript = m_keyFramesScript[i];
	int j = nRunScript + 1;
	for (; j <= keyframeIdx; j++)
	{
		executeKeyframeScript(i, j);
	}
	m_keyFramesScript[i] = keyframeIdx;	    // 设置脚本执行到哪里 
}

void TLModel::updateKeyframe(int iLayer, int keyframeIdx, float progress)
{
    const Layer &layer = m_symbolInfo->layers(iLayer);
    const Keyframe &startKF = layer.keyframes(keyframeIdx);

    CCAssert(keyframeIdx<layer.keyframes_size()-1, "最后一帧不能是补间开始关键帧 ");
    const Keyframe &endKF = layer.keyframes(keyframeIdx+1);

    unsigned int i=0;
    for(i=0; i<m_layers[iLayer]->count(); i++)
    {
        CCNode* node = (CCNode*) m_layers[iLayer]->objectAtIndex(i);
        if (i<(unsigned)endKF.elements_size())
            setNodeFromTween(node, startKF.elements(i), endKF.elements(i), progress);
    }
}

void TLModel::update( float dt )
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
            // 纠正 m_elapsed 的范围
            if( m_reverse )
                m_elapsed = m_endTime - ( m_startTime - m_elapsed );
            else
                m_elapsed = ( m_elapsed - m_endTime ) + m_startTime;

            if (m_loopCount>0)
                m_loopCount--;
        }
    }

    for (int i=0; i<m_symbolInfo->layers_size(); i++)
        updateLayer(i);
}

float TLModel::getTimeLength( int nFrameRate )
{
	if( nFrameRate == -1 )
		nFrameRate = m_frameRate;

	int nFrameCount = m_symbolInfo->framecount();

	return (float)nFrameCount / (float)nFrameRate;
}

void TLModel::start()
{
	if (!m_playing)
	{
		m_playing = true;
		scheduleUpdate();
	}
}

void TLModel::stop()
{
	if (m_playing)
	{
		m_playing = false;
		unscheduleUpdate();
	}
}


void TLModel::play(int startFrame, int durationFrameCount, int loopCount, bool reverse)
{
	if(startFrame<0 || startFrame >= m_symbolInfo->framecount())
    {
        CCLOGERROR("帧索引越界 ");
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
	m_keyFramesScript.clear();
    for (int i=0; i<m_symbolInfo->layers_size(); i++)
    {
        m_currentKeyFrames.push_back(-1);
		m_keyFramesScript.push_back(-1);
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

void TLModel::clear()
{
    // 清除layer nodes
    std::vector<CCArray*>::iterator iter = m_layers.begin();
    for(; iter!=m_layers.end(); iter++)
    {
        clearLayer(*iter);
    }
}

void TLModel::addLayerChild(int iLayer, CCNode *pNode)
{
    m_layers[iLayer]->addObject(pNode);
	if(pNode && ((CCSprite*)pNode)->getTexture())
	{
		addChild(pNode, iLayer-100);
	}
}

void TLModel::removeLayerChild(int iLayer, CCNode *pNode, bool cleanup)
{
	//pNode->setVisible( false );
	if(pNode && ((CCSprite*)pNode)->getTexture())
	{
		removeChild(pNode, cleanup);
	}
    m_layers[iLayer]->removeObject(pNode);
}

bool TLModel::RegisterPlayEndCallbackHandler( int nPlayEndHandler )
{
	m_pPlayEndCallbackObject = NULL;
	m_pPlayEndCallFuncPtr = NULL;
	m_ulUserData = 0;

	if( m_nPlayEndHandler != 0 )
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nPlayEndHandler );

	m_nPlayEndHandler = nPlayEndHandler;

	return true;
}

bool TLModel::RegisterPlayEndCallback( CCObject* pCallbackObject, PlayEndCallbackFuncPtr2 pPlayEndCallFuncPtr, unsigned long ulUserData )
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

void TLModel::removeAllChildrenWithCleanup(bool cleanup)
{
    clear();
    CCNode::removeAllChildrenWithCleanup(cleanup);
}

void TLModel::SetPreCallScript( int nLuaPreCallScript )
{
	m_nLuaPreCallScript = nLuaPreCallScript;
}

void TLModel::RegisterPreCallScript( int nLuaHandle )
{
	UnRegisterPreCallScript();
	m_nRegLuaPreCallScript = nLuaHandle;
}

void TLModel::UnRegisterPreCallScript()
{
	if (m_nRegLuaPreCallScript == 0)
		return;

	CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler(m_nRegLuaPreCallScript);
	m_nRegLuaPreCallScript = 0;
}

void TLModel::getLayerFirstNodePosition(const char *szLayerName, float *x, float *y)
{
	getPosition(x, y);
	if (szLayerName == NULL)
		return;

	for (int i = 0; i < m_symbolInfo->layers_size(); ++i)
	{
		const ::framework::Layer &layer = m_symbolInfo->layers(i);
		if (strcmp(layer.name().c_str(), szLayerName) == 0) 
		{
			// 找到图层的第一个Node
			if (m_layers[i]->count() <=0)
				continue;
			CCNode *pNode = (CCNode*)m_layers[i]->objectAtIndex(0);
			if (pNode == NULL)
				return;
			//std::string name = pNode->getInstanceName();
			float xx = 0;
			float yy = 0;
			pNode->getPosition(&xx, &yy);
			*x += xx;
			*y += yy;
			return;
		}
	}
}

void TLModel::setFrameColor(const ccColor4B& color)	// 每帧都会变化的 颜色值 
{
	m_bUseFrameColor = true;

    setOpacity( color.a );
	setColor( ccc3( color.r, color.g, color.b ) );
}

void TLModel::clearFrameColor()
{
    setFrameColor( ccc4( 255, 255, 255, 255 ) );

	m_bUseFrameColor = false;
}

const ccColor4B& TLModel::getFrameColor(void)		// 获取帧颜色 
{
	return ccc4(_realColor.r,_realColor.g,_realColor.b,_realOpacity);
}

const std::string TLModel::getTextureName()
{
	int nSize = m_symbolInfo->layers_size();
	for (int i = 0; i < nSize; ++i) {

		const Layer &layer = m_symbolInfo->layers(i);
		int keySize = layer.keyframes_size();
		for (int j = 0; j < keySize; ++j) {

			const Keyframe &frame = layer.keyframes(j);
			int nElementSize = frame.elements_size();
			for (int k = 0; k < nElementSize; ++k) {

				const Element &elem = frame.elements(k);
				if (elem.libname().size() > 0)
				{
					return MCLoader::sharedMCLoader()->getFrameTexture(elem.libname()).c_str();
				}
			}
			
		}
	}

	return NULL;
}
