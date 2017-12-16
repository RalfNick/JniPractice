#include <jni.h>
#include "MyMath.h"

extern "C"
JNIEXPORT jint JNICALL Java_com_example_ralf_cmake_MainActivity_resultFromJNI(
        JNIEnv *env, jobject jobj/* this */){

   return add(3,2);
}
