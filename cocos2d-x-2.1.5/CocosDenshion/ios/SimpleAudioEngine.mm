/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "SimpleAudioEngine.h"
#include "SimpleAudioEngine_objc.h"
#include "cocos2d.h"
USING_NS_CC;

static void static_end()
{
    [SimpleAudioEngine  end];
}

static void static_preloadBackgroundMusic(const char* pszFilePath)
{
    [[SimpleAudioEngine sharedEngine] preloadBackgroundMusic: [NSString stringWithUTF8String: pszFilePath]];
}

static void static_playBackgroundMusic(const char* pszFilePath, bool bLoop)
{
    [[SimpleAudioEngine sharedEngine] playBackgroundMusic: [NSString stringWithUTF8String: pszFilePath] loop: bLoop];
}

static void static_stopBackgroundMusic()
{
    [[SimpleAudioEngine sharedEngine] stopBackgroundMusic];
}

static void static_pauseBackgroundMusic()
{
     [[SimpleAudioEngine sharedEngine] pauseBackgroundMusic];
}

static void static_resumeBackgroundMusic()
{
    [[SimpleAudioEngine sharedEngine] resumeBackgroundMusic];
} 

static void static_rewindBackgroundMusic()
{
    [[SimpleAudioEngine sharedEngine] rewindBackgroundMusic];
}

static bool static_willPlayBackgroundMusic()
{
    return [[SimpleAudioEngine sharedEngine] willPlayBackgroundMusic];
}

static bool static_isBackgroundMusicPlaying()
{
    return [[SimpleAudioEngine sharedEngine] isBackgroundMusicPlaying];
}

static float static_getBackgroundMusicVolume()
{
    return [[SimpleAudioEngine sharedEngine] backgroundMusicVolume];
}

static void static_setBackgroundMusicVolume(float volume)
{
    volume = MAX( MIN(volume, 1.0), 0 );
    [SimpleAudioEngine sharedEngine].backgroundMusicVolume = volume;
}
 
static void static_preloadBackgroundMusic2(const char* pszFilePath)
{
    [[SimpleAudioEngine sharedEngine] preloadBackgroundMusic2: [NSString stringWithUTF8String: pszFilePath]];
}

static void static_playBackgroundMusic2(const char* pszFilePath, bool bLoop)
{
    [[SimpleAudioEngine sharedEngine] playBackgroundMusic2: [NSString stringWithUTF8String: pszFilePath] loop: bLoop];
}

static void static_stopBackgroundMusic2()
{
    [[SimpleAudioEngine sharedEngine] stopBackgroundMusic2];
}

static void static_pauseBackgroundMusic2()
{
     [[SimpleAudioEngine sharedEngine] pauseBackgroundMusic2];
}

static void static_resumeBackgroundMusic2()
{
    [[SimpleAudioEngine sharedEngine] resumeBackgroundMusic2];
} 

static void static_rewindBackgroundMusic2()
{
    [[SimpleAudioEngine sharedEngine] rewindBackgroundMusic2];
}

static bool static_willPlayBackgroundMusic2()
{
    return [[SimpleAudioEngine sharedEngine] willPlayBackgroundMusic2];
}

static bool static_isBackgroundMusic2Playing()
{
    return [[SimpleAudioEngine sharedEngine] isBackgroundMusic2Playing];
}

static float static_getBackgroundMusic2Volume()
{
    return [[SimpleAudioEngine sharedEngine] backgroundMusic2Volume];
}

static void static_setBackgroundMusic2Volume(float volume)
{
    volume = MAX( MIN(volume, 1.0), 0 );
    [SimpleAudioEngine sharedEngine].backgroundMusic2Volume = volume;
}
    
static float static_getEffectsVolume()
{
    return [[SimpleAudioEngine sharedEngine] effectsVolume];
}
     
static void static_setEffectsVolume(float volume)
{
    volume = MAX( MIN(volume, 1.0), 0 );
    [SimpleAudioEngine sharedEngine].effectsVolume = volume;
}
     
static unsigned int static_playEffect(const char* pszFilePath, bool bLoop)
{
    return [[SimpleAudioEngine sharedEngine] playEffect:[NSString stringWithUTF8String: pszFilePath] loop:bLoop]; 
}
     
static void static_stopEffect(int nSoundId)
{
    [[SimpleAudioEngine sharedEngine] stopEffect: nSoundId];
}
     
static void static_preloadEffect(const char* pszFilePath)
{
    [[SimpleAudioEngine sharedEngine] preloadEffect: [NSString stringWithUTF8String: pszFilePath]];
}
     
static void static_unloadEffect(const char* pszFilePath)
{
    [[SimpleAudioEngine sharedEngine] unloadEffect: [NSString stringWithUTF8String: pszFilePath]];
}

static void static_pauseEffect(unsigned int uSoundId)
{
    [[SimpleAudioEngine sharedEngine] pauseEffect: uSoundId];
}

static void static_pauseAllEffects()
{
    [[SimpleAudioEngine sharedEngine] pauseAllEffects];
}

static void static_resumeEffect(unsigned int uSoundId)
{
    [[SimpleAudioEngine sharedEngine] resumeEffect: uSoundId];
}

static void static_resumeAllEffects()
{
    [[SimpleAudioEngine sharedEngine] resumeAllEffects];
}

static void static_stopAllEffects()
{
    [[SimpleAudioEngine sharedEngine] stopAllEffects];
}

namespace CocosDenshion {

static SimpleAudioEngine *s_pEngine;

SimpleAudioEngine::SimpleAudioEngine()
{

}

SimpleAudioEngine::~SimpleAudioEngine()
{

}

SimpleAudioEngine* SimpleAudioEngine::sharedEngine()
{
    if (! s_pEngine)
    {
        s_pEngine = new SimpleAudioEngine();
    }
    
    return s_pEngine;
}

void SimpleAudioEngine::end()
{
    if (s_pEngine)
    {
        delete s_pEngine;
        s_pEngine = NULL;
    }
    
    static_end();
}

void SimpleAudioEngine::preloadBackgroundMusic(const char* pszFilePath)
{
    // Changing file path to full path
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(pszFilePath);
    if( alterMusicPlayer )
    {
        static_preloadBackgroundMusic2(fullPath.c_str());
    }
    else
    {
        static_preloadBackgroundMusic(fullPath.c_str());
    }
}

void SimpleAudioEngine::playBackgroundMusic(const char* pszFilePath, bool bLoop)
{
    // Changing file path to full path
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(pszFilePath);
    if( alterMusicPlayer )
    {
        static_playBackgroundMusic2(fullPath.c_str(), bLoop);
    }
    else
    {
        static_playBackgroundMusic(fullPath.c_str(), bLoop);
    }
}

void SimpleAudioEngine::stopBackgroundMusic(bool bReleaseData)
{
    if( alterMusicPlayer )
    {
        static_stopBackgroundMusic2();
    }
    else
    {
        static_stopBackgroundMusic();
    }
}

void SimpleAudioEngine::pauseBackgroundMusic()
{
    if( alterMusicPlayer )
    {
        static_pauseBackgroundMusic2();
    }
    else
    {
        static_pauseBackgroundMusic();
    }
}

void SimpleAudioEngine::resumeBackgroundMusic()
{
    if( alterMusicPlayer )
    {
        static_resumeBackgroundMusic2();
    }
    else
    {
        static_resumeBackgroundMusic();
    }
} 

void SimpleAudioEngine::rewindBackgroundMusic()
{
    if( alterMusicPlayer )
    {
        static_rewindBackgroundMusic2();
    }
    else
    {
        static_rewindBackgroundMusic();
    }
}

bool SimpleAudioEngine::willPlayBackgroundMusic()
{
    if( alterMusicPlayer )
    {
        return static_willPlayBackgroundMusic2();
    }
    else
    {
        return static_willPlayBackgroundMusic();
    }
}

bool SimpleAudioEngine::isBackgroundMusicPlaying()
{
    if( alterMusicPlayer )
    {
        return static_isBackgroundMusic2Playing();
    }
    else
    {
        return static_isBackgroundMusicPlaying();
    }
}

float SimpleAudioEngine::getBackgroundMusicVolume()
{
    if( alterMusicPlayer )
    {
        return static_getBackgroundMusic2Volume();
    }
    else
    {
        return static_getBackgroundMusicVolume();
    }
}

void SimpleAudioEngine::setBackgroundMusicVolume(float volume)
{
    if( alterMusicPlayer )
    {
        static_setBackgroundMusic2Volume(volume);
    }
    else
    {
        static_setBackgroundMusicVolume(volume);
    }
}

float SimpleAudioEngine::getEffectsVolume()
{
    return static_getEffectsVolume();
}

void SimpleAudioEngine::setEffectsVolume(float volume)
{
    static_setEffectsVolume(volume);
}

unsigned int SimpleAudioEngine::playEffect(const char* pszFilePath, bool bLoop)
{
    // Changing file path to full path
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(pszFilePath);
    return static_playEffect(fullPath.c_str(), bLoop);
}

void SimpleAudioEngine::stopEffect(unsigned int nSoundId)
{
    static_stopEffect(nSoundId);
}

void SimpleAudioEngine::preloadEffect(const char* pszFilePath)
{
    // Changing file path to full path
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(pszFilePath);
    static_preloadEffect(fullPath.c_str());
}

void SimpleAudioEngine::unloadEffect(const char* pszFilePath)
{
    // Changing file path to full path
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(pszFilePath);
    static_unloadEffect(fullPath.c_str());
}

void SimpleAudioEngine::pauseEffect(unsigned int uSoundId)
{
    static_pauseEffect(uSoundId);
}

void SimpleAudioEngine::resumeEffect(unsigned int uSoundId)
{
    static_resumeEffect(uSoundId);
}

void SimpleAudioEngine::pauseAllEffects()
{
    static_pauseAllEffects();
}

void SimpleAudioEngine::resumeAllEffects()
{
    static_resumeAllEffects();
}

void SimpleAudioEngine::stopAllEffects()
{
    static_stopAllEffects();
}

} // endof namespace CocosDenshion {
