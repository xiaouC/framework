LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := framework_static

LOCAL_MODULE_FILENAME := libframework

SRC_ROOT = ..

LOCAL_SRC_FILES := ${SRC_ROOT}/AppDelegate.cpp \
${SRC_ROOT}/UI/TLDropDragHelper.cpp \
${SRC_ROOT}/UI/TLWindowManager.cpp \
${SRC_ROOT}/UI/TLMaskLayer.cpp \
${SRC_ROOT}/UI/TLTextField.cpp \
${SRC_ROOT}/UI/TLWindow.cpp \
${SRC_ROOT}/UI/TLEditBox.cpp \
${SRC_ROOT}/UI/TLTextFieldDelegate.cpp \
${SRC_ROOT}/UI/TLRenderNode.cpp \
${SRC_ROOT}/platform/PlatformUtils.cpp \
${SRC_ROOT}/platform/SDKCallback.cpp \
${SRC_ROOT}/platform/SDKLoginUtilsForAndroid.cpp \
${SRC_ROOT}/platform/wdj_screenshot_cocos2dx.cpp \
${SRC_ROOT}/RichText/TLFontTex.cpp \
${SRC_ROOT}/RichText/TLRichTexVerbatim.cpp \
${SRC_ROOT}/RichText/TLLabelRichTex.cpp \
${SRC_ROOT}/particle/Generator.cpp \
${SRC_ROOT}/particle/GeneratorData.cpp \
${SRC_ROOT}/particle/Util.cpp \
${SRC_ROOT}/particle/ParticleRender.cpp \
${SRC_ROOT}/particle/modifier/GenericForce.cpp \
${SRC_ROOT}/particle/modifier/AirFriction.cpp \
${SRC_ROOT}/particle/ParticleBehaviour.cpp \
${SRC_ROOT}/particle/ValueList.cpp \
${SRC_ROOT}/particle/GeneratorBehaviour.cpp \
${SRC_ROOT}/particle/space/PathGeneratorSpace.cpp \
${SRC_ROOT}/particle/space/ParticleSpace.cpp \
${SRC_ROOT}/particle/space/GeneratorSpace.cpp \
${SRC_ROOT}/particle/space/CircleGeneratorSpace.cpp \
${SRC_ROOT}/particle/space/RectGeneratorSpace.cpp \
${SRC_ROOT}/particle/space/LineGeneratorSpace.cpp \
${SRC_ROOT}/particle/space/PointGeneratorSpace.cpp \
${SRC_ROOT}/particle/util/Stream.cpp \
${SRC_ROOT}/particle/util/UTF8.cpp \
${SRC_ROOT}/particle/Particle.cpp \
${SRC_ROOT}/particle/ParticleSystemManager.cpp \
${SRC_ROOT}/particle/ParticleSystem.cpp \
${SRC_ROOT}/TLRunningScene.cpp \
${SRC_ROOT}/NetMessage/HttpDownloader.cpp \
${SRC_ROOT}/NetMessage/NetWorkThread.cpp \
${SRC_ROOT}/NetMessage/NetMsg.cpp \
${SRC_ROOT}/NetMessage/NetMsgProcess.cpp \
${SRC_ROOT}/NetMessage/HttpClient.cpp \
${SRC_ROOT}/tween/TLTweenManager.cpp \
${SRC_ROOT}/toluaAPI/pbc-lua.cpp \
${SRC_ROOT}/toluaAPI/luaapi.cpp \
${SRC_ROOT}/toluaAPI/utils.cpp \
${SRC_ROOT}/Common/TLCommon.cpp \
${SRC_ROOT}/Common/TLModel.cpp \
${SRC_ROOT}/Common/CCActionExtend.cpp \
${SRC_ROOT}/MC/MCLoader.cpp \
${SRC_ROOT}/MC/MCFrame.cpp \
${SRC_ROOT}/MC/BatchNodeMC.cpp \
${SRC_ROOT}/MC/ClipNode.cpp \
${SRC_ROOT}/MC/AssetsManager.cpp \
${SRC_ROOT}/MC/MovieClip.cpp \
${SRC_ROOT}/pbc/proto.c \
${SRC_ROOT}/pbc/varint.c \
${SRC_ROOT}/pbc/stringpool.c \
${SRC_ROOT}/pbc/wmessage.c \
${SRC_ROOT}/pbc/bootstrap.c \
${SRC_ROOT}/pbc/rmessage.c \
${SRC_ROOT}/pbc/decode.c \
${SRC_ROOT}/pbc/map.c \
${SRC_ROOT}/pbc/array.c \
${SRC_ROOT}/pbc/alloc.c \
${SRC_ROOT}/pbc/register.c \
${SRC_ROOT}/pbc/context.c \
${SRC_ROOT}/pbc/pattern.c \
${SRC_ROOT}/toluaAPI/lfs.c \
${SRC_ROOT}/toluaAPI/struct.c \
${SRC_ROOT}/toluaAPI/lua_cmsgpack.c \
${SRC_ROOT}/toluaAPI/lua-cjson-2.1.0/fpconv.c \
${SRC_ROOT}/toluaAPI/lua-cjson-2.1.0/lua_cjson.c \
${SRC_ROOT}/toluaAPI/lua-cjson-2.1.0/strbuf.c \

LOCAL_CFLAGS := -DENABLE_CJSON_GLOBAL -DPOEM_LH_PACKAGE
LOCAL_CFLAGS += -pie -fPIE
LOCAL_LDFLAGS += -pie -fPIE

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/$(SRC_ROOT) \
                           $(LOCAL_PATH)/$(SRC_ROOT)/pbc \


LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SRC_ROOT) \
					$(LOCAL_PATH)/$(SRC_ROOT)/pbc \
					$(LOCAL_PATH)/${SRC_ROOT}/toluaAPI/lua-cjson-2.1.0 \
					$(LOCAL_PATH)/$(SRC_ROOT)/../protocol/src\
					$(LOCAL_PATH)/$(SRC_ROOT)/../protobuf-android/protobuf/src \
					$(LOCAL_PATH)/$(SRC_ROOT)/../cocos2d-x-2.1.5/cocos2dx \
					$(LOCAL_PATH)/$(SRC_ROOT)/../cocos2d-x-2.1.5/cocos2dx/cocoa \
					$(LOCAL_PATH)/$(SRC_ROOT)/../cocos2d-x-2.1.5/cocos2dx/support \
					$(LOCAL_PATH)/$(SRC_ROOT)/../cocos2d-x-2.1.5/cocos2dx/platform \
					$(LOCAL_PATH)/$(SRC_ROOT)/../cocos2d-x-2.1.5/cocos2dx/platform/ljsdk \
					$(LOCAL_PATH)/$(SRC_ROOT)/../cocos2d-x-2.1.5/cocos2dx/platform/android \
					$(LOCAL_PATH)/$(SRC_ROOT)/../cocos2d-x-2.1.5/scripting/lua/lua \
					$(LOCAL_PATH)/$(SRC_ROOT)/../cocos2d-x-2.1.5/scripting/lua/tolua \
					$(LOCAL_PATH)/$(SRC_ROOT)/../cocos2d-x-2.1.5/scripting/lua/cocos2dx_support \

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_lua_static
LOCAL_WHOLE_STATIC_LIBRARIES += libprotocol
LOCAL_WHOLE_STATIC_LIBRARIES += libProtobuf
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_curl_static
            
include $(BUILD_STATIC_LIBRARY)

$(call import-module,cocos2dx) \
$(call import-module,CocosDenshion/android) \
$(call import-module,scripting/lua/proj.android) \
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,protocol) \
$(call import-module,protobuf-android) \
