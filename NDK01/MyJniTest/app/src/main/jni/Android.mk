LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := libmyjni
LOCAL_SRC_FILES := myjni.cpp

include $(BUILD_SHARED_LIBRARY)