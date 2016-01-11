LOCAL_PATH := $(call my-dir)




################## Build ProtoBuf ################
include $(CLEAR_VARS)


LOCAL_ARM_MODE := arm
LOCAL_CPPFLAGS += -frtti
LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_MODULE := libProtobuf
LOCAL_MODULE_TAGS := optional
LOCAL_CPP_EXTENSION := .cc

LOCAL_SRC_FILES := \
protobuf/src/google/protobuf/stubs/common.cc                              \
protobuf/src/google/protobuf/stubs/once.cc                                \
protobuf/src/google/protobuf/extension_set.cc                             \
protobuf/src/google/protobuf/generated_message_util.cc                    \
protobuf/src/google/protobuf/message_lite.cc                              \
protobuf/src/google/protobuf/repeated_field.cc                            \
protobuf/src/google/protobuf/wire_format_lite.cc                          \
protobuf/src/google/protobuf/io/coded_stream.cc                           \
protobuf/src/google/protobuf/io/zero_copy_stream.cc                       \
protobuf/src/google/protobuf/io/zero_copy_stream_impl_lite.cc

LOCAL_C_INCLUDES += . \
$(LOCAL_PATH)/protobuf/src \
$(LOCAL_PATH)/protobuf \
#$(LOCAL_PATH)/protobuf/vsprojects \





LOCAL_LDLIBS := -llog -lgcc -pthread


ifndef NDK_ROOT
include external/stlport/libstlport.mk
endif
include $(BUILD_STATIC_LIBRARY)
