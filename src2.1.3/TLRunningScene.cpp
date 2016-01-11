#include "TLRunningScene.h"
#include "AppMacros.h"
#include <SimpleAudioEngine.h>
USING_NS_CC;

// on "init" you need to initialize your instance
bool TLRunningScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCScene::init() )
    {
        return false;
    }
    
    return true;
}

void TLRunningScene::onExit()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->end();

	CCScene::onExit();
}