copyassets.bat

set COCOS2DX_ROOT=../../cocos2dx
set NDK_ROOT=E:/android-ndk-r8d
set NDK_MODULE_PATH=%COCOS2DX_ROOT%;%COCOS2DX_ROOT%/cocos2dx/platform/third_party/android/prebuilt;../../

%NDK_ROOT%/ndk-build -j4 NDK_DEBUG=1