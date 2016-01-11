LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := helloworld/main.cpp \
helloworld/sdk.cpp \
../../../src2.1.3/AppDelegate.cpp \
../../../src2.1.3/UI/TLDropDragHelper.cpp \
../../../src2.1.3/UI/TLWindowManager.cpp \
../../../src2.1.3/UI/TLMaskLayer.cpp \
../../../src2.1.3/UI/TLTextField.cpp \
../../../src2.1.3/UI/TLEditBox.cpp \
../../../src2.1.3/UI/TLWindow.cpp \
../../../src2.1.3/UI/TLTextFieldDelegate.cpp \
../../../src2.1.3/platform/PlatformUtils.cpp \
../../../src2.1.3/platform/share.cpp \
../../../src2.1.3/RichText/TLFontTex.cpp \
../../../src2.1.3/RichText/TLRichTexVerbatim.cpp \
../../../src2.1.3/RichText/TLLabelRichTex.cpp \
../../../src2.1.3/particle/Generator.cpp \
../../../src2.1.3/particle/GeneratorData.cpp \
../../../src2.1.3/particle/Util.cpp \
../../../src2.1.3/particle/ParticleRender.cpp \
../../../src2.1.3/particle/modifier/GenericForce.cpp \
../../../src2.1.3/particle/modifier/AirFriction.cpp \
../../../src2.1.3/particle/ParticleBehaviour.cpp \
../../../src2.1.3/particle/ValueList.cpp \
../../../src2.1.3/particle/GeneratorBehaviour.cpp \
../../../src2.1.3/particle/space/PathGeneratorSpace.cpp \
../../../src2.1.3/particle/space/ParticleSpace.cpp \
../../../src2.1.3/particle/space/GeneratorSpace.cpp \
../../../src2.1.3/particle/space/CircleGeneratorSpace.cpp \
../../../src2.1.3/particle/space/RectGeneratorSpace.cpp \
../../../src2.1.3/particle/space/LineGeneratorSpace.cpp \
../../../src2.1.3/particle/space/PointGeneratorSpace.cpp \
../../../src2.1.3/particle/util/Stream.cpp \
../../../src2.1.3/particle/util/UTF8.cpp \
../../../src2.1.3/particle/Particle.cpp \
../../../src2.1.3/particle/ParticleSystemManager.cpp \
../../../src2.1.3/particle/ParticleSystem.cpp \
../../../src2.1.3/TLRunningScene.cpp \
../../../src2.1.3/NetMessage/HttpDownloader.cpp \
../../../src2.1.3/NetMessage/NetWorkThread.cpp \
../../../src2.1.3/NetMessage/NetMsg.cpp \
../../../src2.1.3/NetMessage/NetMsgProcess.cpp \
../../../src2.1.3/NetMessage/HttpClient.cpp \
../../../src2.1.3/tween/TLTweenManager.cpp \
../../../src2.1.3/toluaAPI/pbc-lua.cpp \
../../../src2.1.3/toluaAPI/luaapi.cpp \
../../../src2.1.3/toluaAPI/utils.cpp \
../../../src2.1.3/Common/TLCommon.cpp \
../../../src2.1.3/Common/TLModel.cpp \
../../../src2.1.3/Common/CCActionExtend.cpp \
../../../src2.1.3/MC/MCLoader.cpp \
../../../src2.1.3/MC/MCFrame.cpp \
../../../src2.1.3/MC/BatchNodeMC.cpp \
../../../src2.1.3/MC/ClipNode.cpp \
../../../src2.1.3/MC/AssetsManager.cpp \
../../../src2.1.3/MC/MovieClip.cpp \
../../../src2.1.3/pbc/proto.c \
../../../src2.1.3/pbc/varint.c \
../../../src2.1.3/pbc/stringpool.c \
../../../src2.1.3/pbc/wmessage.c \
../../../src2.1.3/pbc/bootstrap.c \
../../../src2.1.3/pbc/rmessage.c \
../../../src2.1.3/pbc/decode.c \
../../../src2.1.3/pbc/map.c \
../../../src2.1.3/pbc/array.c \
../../../src2.1.3/pbc/alloc.c \
../../../src2.1.3/pbc/register.c \
../../../src2.1.3/pbc/context.c \
../../../src2.1.3/pbc/pattern.c \
../../../src2.1.3/toluaAPI/lfs.c \
../../../src2.1.3/toluaAPI/struct.c \
../../../src2.1.3/toluaAPI/lua_cmsgpack.c \

LOCAL_CFLAGS := -DPOEM_LEAN_PACKAGE

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../src2.1.3 \
					$(LOCAL_PATH)/../../../src2.1.3/pbc \
					$(LOCAL_PATH)/../../../proto_link/src \
					$(LOCAL_PATH)/../../../proto_link/src/config \
					$(LOCAL_PATH)/../../../protobuf-android/protobuf/src \
					$(LOCAL_PATH)/../../../cocos2d-x-2.1.5/cocos2dx \
					$(LOCAL_PATH)/../../../cocos2d-x-2.1.5/cocos2dx/cocoa \
					$(LOCAL_PATH)/../../../cocos2d-x-2.1.5/cocos2dx/support \
					$(LOCAL_PATH)/../../../cocos2d-x-2.1.5/cocos2dx/platform \
					$(LOCAL_PATH)/../../../cocos2d-x-2.1.5/cocos2dx/platform/android \
					$(LOCAL_PATH)/../../../cocos2d-x-2.1.5/scripting/lua/lua \
					$(LOCAL_PATH)/../../../cocos2d-x-2.1.5/scripting/lua/tolua \
					$(LOCAL_PATH)/../../../cocos2d-x-2.1.5/scripting/lua/cocos2dx_support \
					$(LOCAL_PATH)/../../../cocos2d-x-2.1.5/external/chipmunk/include \

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_lua_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += libprotocol
LOCAL_WHOLE_STATIC_LIBRARIES += libProtobuf
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_curl_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx) \
$(call import-module,CocosDenshion/android) \
$(call import-module,extensions) \
$(call import-module,scripting/lua/proj.android) \
$(call import-module,external/Box2D) \
$(call import-module,external/chipmunk) \
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,../proto_link) \
$(call import-module,../protobuf-android) \
