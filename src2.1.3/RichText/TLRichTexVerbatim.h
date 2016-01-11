#pragma once
#include "TLLabelRichTex.h"

class TLRichTexVerbatim : public TLLabelRichTex
{
public:
	TLRichTexVerbatim();
	virtual ~TLRichTexVerbatim();

	static TLRichTexVerbatim* create( const char* str, float fFontSize, const CCSize& size = CCSizeZero, const CCImage::ETextAlign& alignment = CCImage::kAlignTopLeft );
	virtual bool initWithString( const char* str, float fFontSize, const CCSize& size = CCSizeZero, const CCImage::ETextAlign& alignment = CCImage::kAlignTopLeft );

	virtual void update( float dt );

	virtual void setRichString( const char* str, TL_RICH_STRING_FLAG eRichStringFlag = TL_RICH_STRING_FLAG_AUTO_WRAP );

	void setSpeed( float nSpeed );
	void play( int nPlayEndHandler );
	void stop();

	bool isEnd();
	void fastEnd();

protected:
	bool m_bEnd;
	int m_nCurIdx;
	int m_nLastIdx;
	float m_fCurInterval;
	float m_fOriginInterval;
	float m_Time;

    int m_nPlayEndHandler;
};
