//
// Created by Ralf on 2017/12/12.
//

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <stdlib.h>
#include <cstring>
#include <android/log.h>

#define LOG_TAG "JNI"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

/* Header for class com_example_ralf_jnitest_cmake_JniActivity */

char *Jstring2CStr(JNIEnv *env, jstring jstr) {

    char *rtn = NULL;

    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("GB2312");

    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");

    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid,
                                                         strencode); // String.getByte("GB2312");
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);

    if (alen > 0) {
        rtn = (char *) malloc(alen + 1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }

    env->ReleaseByteArrayElements(barr, ba, 0);

    return rtn;
}

extern "C" {
/*
 * Class:     com_example_ralf_jnitest_cmake_JniActivity
 * Method:    getContentFromJni
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_ralf_cmake_JniActivity_getContentFromJni
        (JNIEnv *env, jobject jobj, jstring str) {
    LOGI("getContentFromJni");
    char *ch = Jstring2CStr(env, str);
    char *newStr = "经过加工的：";
    strcat(ch, newStr); //拼接两个字符串
    return env->NewStringUTF(ch);
}
}

extern "C" {
/*
 * Class:     com_example_ralf_jnitest_cmake_JniActivity
 * Method:    callJavaMethods
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_ralf_cmake_JniActivity_callJavaMethod
        (JNIEnv *env, jobject jobj, jstring str) {
    LOGI("getContentFromJni----callJavaMethod");
    char *ch = Jstring2CStr(env, str);

    //获取类名
    jclass jniTestClass = env->FindClass("com/example/ralf/cmake/TestClass");
    LOGI("get TestClass---");
    //获取构造方法
    jmethodID constructureId = env->GetMethodID(jniTestClass, "<init>","()V");

    LOGI("get construct fun---");
    //创建实例对象
    jobject jniObj = env->NewObject(jniTestClass, constructureId);

    LOGI("get jni object");
    //获取java层方法
    jmethodID javaMethod = env->GetMethodID(jniTestClass, "javaMethod",
                                            "()Ljava/lang/String;");

    LOGI("get method ID----");
    //调用java层非静态方法
    jstring getContentStr = (jstring) env->CallObjectMethod(jniObj, javaMethod);

    LOGI("call menthod success");
    char *newStr = Jstring2CStr(env, getContentStr);
    strcat(ch,"\r\n");
    strcat(ch, newStr); //拼接两个字符串
    return env->NewStringUTF(ch);

}
}
extern "C" {

/*
 * Class:     com_example_ralf_jnitest_cmake_JniActivity
 * Method:    callJavaStaticMethod
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_ralf_cmake_JniActivity_callJavaStaticMethod
        (JNIEnv *env, jobject jobj, jstring str) {
    LOGI("getContentFromJni-----callJavaStaticMethod");
    char *ch = Jstring2CStr(env, str);

    //获取类名
    jclass jniTestClass = env->FindClass("com/example/ralf/cmake/TestClass");
    LOGI("get----jniActivityStaticClass");
    //获取静态方法
    jmethodID staticMethodId = env->GetStaticMethodID(jniTestClass, "javaStaticMethod","()Ljava/lang/String;");
    LOGI("get----staticMethodId");

    //调用静态方法
    jstring getContentStr = (jstring) env->CallStaticObjectMethod(jniTestClass, staticMethodId);
    LOGI("get----getContentStr");

    char *newStr = Jstring2CStr(env, getContentStr);
    strcat(ch,"\r\n");
    strcat(ch, newStr); //拼接两个字符串
    return env->NewStringUTF(ch);

}
}