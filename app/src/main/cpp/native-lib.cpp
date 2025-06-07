#include <jni.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <android/log.h>

//调用 libadd.so 动态库中的方法
extern "C" {    //注意在 C++ 中调用 C 语言方法 , 需要做兼容设置
extern int add(int a, int b);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_ifengyu_talk_TalkManager_stringFromJNI(JNIEnv *env, jobject thiz) {
    //
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}