LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_WHOLE_STATIC_LIBRARIES := framework_static

LOCAL_SRC_FILES := main.cpp

include $(BUILD_SHARED_LIBRARY)

$(call import-module,src2.1.3/jni)
