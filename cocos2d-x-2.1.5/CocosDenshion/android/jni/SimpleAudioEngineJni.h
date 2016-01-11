#ifndef __SIMPLE_AUDIO_ENGINE_JNI__
#define __SIMPLE_AUDIO_ENGINE_JNI__

#include <jni.h>

extern "C"
{
    extern void preloadBackgroundMusicJNI(const char *path, bool alterMusicPlayer);
    extern void playBackgroundMusicJNI(const char *path, bool isLoop, bool alterMusicPlayer);
    extern void stopBackgroundMusicJNI(bool alterMusicPlayer);
    extern void pauseBackgroundMusicJNI(bool alterMusicPlayer);
    extern void resumeBackgroundMusicJNI(bool alterMusicPlayer);
    extern void rewindBackgroundMusicJNI(bool alterMusicPlayer);
    extern bool isBackgroundMusicPlayingJNI(bool alterMusicPlayer);
    extern float getBackgroundMusicVolumeJNI(bool alterMusicPlayer);
    extern void setBackgroundMusicVolumeJNI(float volume, bool alterMusicPlayer);
    extern unsigned int playEffectJNI(const char* path, bool bLoop);
    extern void stopEffectJNI(unsigned int nSoundId);
    extern void endJNI();
    extern float getEffectsVolumeJNI();
    extern void setEffectsVolumeJNI(float volume);
    extern void preloadEffectJNI(const char *path);
    extern void unloadEffectJNI(const char* path);
    extern void pauseEffectJNI(unsigned int nSoundId);
    extern void pauseAllEffectsJNI();
    extern void resumeEffectJNI(unsigned int nSoundId);
    extern void resumeAllEffectsJNI();
    extern void stopAllEffectsJNI();
}

#endif // __SIMPLE_AUDIO_ENGINE_JNI__
