#include <jni.h>
#include "MyMath.h"

extern "C"
JNIEXPORT jint

JNICALL
Java_com_example_ralf_jnitest_1cmake_MainActivity_resultFromJNI(
        JNIEnv *env,
        jobject /* this */) {

   return add(3,2);
}
