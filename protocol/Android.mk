LOCAL_PATH := $(call my-dir) #指定当前目录

################## Build ProtoBuf ################
include $(CLEAR_VARS)       #清除变量

LOCAL_MODULE_CLASS := STATIC_LIBRARIES     #指定编译后放的位置
LOCAL_MODULE := libprotocol         #模块名
LOCAL_MODULE_TAGS := optional       #编译选项
LOCAL_CPP_EXTENSION := .cc          #指定cpp的扩展名，默认是cpp

#本地的源文件
LOCAL_SRC_FILES := \
./src/files.pb.cc \
./src/anim.pb.cc \
./src/platform.pb.cc \

#路径的可选配置
LOCAL_C_INCLUDES += $(LOCAL_PATH)/src \
					$(LOCAL_PATH)/../protobuf-android/protobuf/src/ \

include $(BUILD_STATIC_LIBRARY)     #生成.a 的动态链接库
