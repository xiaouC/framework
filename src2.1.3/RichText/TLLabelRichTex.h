#pragma once
#include "base_nodes/CCNode.h"
#include "sprite_nodes/CCSpriteBatchNode.h"
#include "CCImage.h"
#include <vector>

USING_NS_CC;

enum TL_RICH_STRING_FLAG
{
    TL_RICH_STRING_FLAG_AUTO_WRAP,                      // 文本根据文本框的宽度，自动换行 
    TL_RICH_STRING_FLAG_ONE_LINE,                       // 把文本限制在一行，可以超出文本框的宽度 
    TL_RICH_STRING_FLAG_ONE_LINE_DOTDOTDOT,             // 把文本限制在一行，如果超出文本框的宽度的话，就会用...来代替后面的内容 
};

class TLWindow;
class TLLabelRichTex : public CCNodeRGBA
{
public:
	TLLabelRichTex();
	virtual ~TLLabelRichTex();

	static TLLabelRichTex* create( const char* str, float fFontSize, const CCSize& size = CCSizeZero,
                const CCImage::ETextAlign& alignment = CCImage::kAlignLeft,
                TLWindow* pWindow = NULL );
	virtual bool initWithString( const char* str, float fFontSize, const CCSize& size = CCSizeZero,
                CCImage::ETextAlign alignment = CCImage::kAlignLeft,
                TLWindow* pWindow = NULL );

    virtual void setColor( const ccColor3B& color3 );
    virtual void setOpacity( GLubyte opacity );
    virtual void setShaderProgram( CCGLProgram* pShaderProgram );
	
    virtual void updateDisplayedOpacity(GLubyte parentOpacity);
    virtual void updateDisplayedColor(const ccColor3B& parentColor);

protected:
    void clearLines();

    void processNodeHandler( CCNode* pNode );

public:
	void adjustLayout();

	void appendLine( bool bForcibly );

public:
	virtual void setRichString( const char* str, TL_RICH_STRING_FLAG eRichStringFlag = TL_RICH_STRING_FLAG_AUTO_WRAP );
	virtual const char* getRichString() const { return m_strText.c_str(); }

	CCNode* getChildByTag( int tag );
    CCSize getRealSize();

    void showCursor( bool bShow, bool bDefaultPos );

	void setFontSize( float fFontSize );
	float getFontSize() const { return m_fFontSize; }

	void setAlignment( CCImage::ETextAlign eAlignment );
	CCImage::ETextAlign getAlignment() const { return m_eAlignment; }

    void setFontColor( const GLubyte r, const GLubyte g, const GLubyte b, const GLubyte a ) { m_kColor = ccc4(r,g,b,a); }
    void setFontColorR( const GLubyte r ) { m_kColor.r = r; }
    void setFontColorG( const GLubyte g ) { m_kColor.g = g; }
    void setFontColorB( const GLubyte b ) { m_kColor.b = b; }
    void setFontColorA( const GLubyte a ) { m_kColor.a = a; }
    ccColor4B getFontColor() const { return m_kColor; }

	void moveOffsetX( float offset, bool flag = false );

	void appendSpriteToCurrentLine( CCNode* pkNode, float width = 0.0f, float height = 0.0f, float offsetX = 0.0f, bool layout = true );
    void appendText( const char* szText );

    TLWindow* getWindow() const { return m_pWindow; }
    void setWindow( TLWindow* pWindow ) { m_pWindow = pWindow; }
    void setCurrentNodeHandler( int nNodeHandler );
    void clearCurrentNodeHandler();

    void setRealSizeLayout( bool bRealSizeLayout ) { m_bRealSizeLayout = bRealSizeLayout; }
    void setTabNum( int nTabNum ) { m_nTabNum = nTabNum; }
    void setWordSpacing( int nWordSpacing ) { m_nWordSpacing = nWordSpacing; }
    void setLineSpacing( int nLineSpacing ) { m_nLineSpacing = nLineSpacing; }

    void setColorIndex( int nColorIndex );
    int getColorIndex() const;
    void changeColorIndex( int nColorIndex );
	
    CCNode* getTextNode() {return m_pBatchNode;};

protected:
	CCSpriteBatchNode* m_pBatchNode;
	CCNode* m_pSpriteNode;

	std::string m_strText;

	float m_fFontSize;
	CCImage::ETextAlign m_eAlignment;
	ccColor4B m_kColor;
    TL_RICH_STRING_FLAG m_eRichStringFlag;

	int m_nElementCount;

	enum NodeType {
		Font,
		Sprite ,
	};

    struct NodeInfo
    {
		NodeType eType;
        float    fOriginX;
		CCSize   currentSize;
        CCNode*  pkNode;
    };

	struct LineInfo
	{
		float fLineRealWidth;
		float fLineRealHeight;
		float fMaxFontCommonHeight;
		std::list<NodeInfo> listLineNode;
	};
	std::vector<LineInfo> m_vecLine;

    CCSize m_kRealSize;
    LineInfo m_kCurrentLineInfo;

	CCSprite* m_pCursor;
    float m_fCursorHeight;
    CCPoint m_kCursorDefaultPos;
    CCPoint m_kCursorPosition;

    TLWindow* m_pWindow;
    int m_nNodeHandler;
    std::list<int> m_listNodeHandlers;

    // 是否使用 real size 来执行 layout，默认使用的是 content size 
    // 一般来说，在创建的时候就已经指定了 content size 的话，都应该使用 content size 来执行 layout 
	bool m_bRealSizeLayout;

    // 换行后，需要缩进的空格数，这个是在聊天的时候用到 
	int m_nTabNum;
    // 字间距和行间距 
    int m_nWordSpacing;
	int m_nLineSpacing;

    // color texture coords
    int m_nColorIndex;
    float ul,vt,ur,vb;
};

