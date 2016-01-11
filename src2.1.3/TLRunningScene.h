#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class TLRunningScene : public cocos2d::CCScene
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	virtual void onExit();
    
    // implement the "static node()" method manually
    CREATE_FUNC(TLRunningScene);
};

#endif // __HELLOWORLD_SCENE_H__
