#include "JavaServiceStarter.h"
#if PLATFORM_ANDROID

#include "Engine/Engine.h"
 #include "Android/AndroidJNI.h"
 #include "Android/AndroidApplication.h"

 #if USE_ANDROID_JNI
 #include <jni.h>
 #endif
#endif


void ApiGear::JavaServiceStarter::startAndroidServer(std::string fullJavaClassName)
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
    JNIEnv* Env = FAndroidApplication::GetJavaEnv();
        
		
    static jclass BridgeClass = FAndroidApplication::FindJavaClassGlobalRef(fullJavaClassName.c_str());
    if (BridgeClass == nullptr)
    {
		UE_LOG(LogTemp, Warning, TEXT("JavaServiceStarter:start; CLASS not found"));
        return;
    }
    jmethodID StartMethod = Env->GetStaticMethodID(BridgeClass, "start", "(Landroid/content/Context;)V");
    if (StartMethod == nullptr)
    {
		UE_LOG(LogTemp, Warning, TEXT( "JavaServiceStarter:start; method not found"));
        return;
    }
    jobject Activity = FJavaWrapper::GameActivityThis;
    FJavaWrapper::CallStaticVoidMethod(Env, BridgeClass, StartMethod, Activity);
#endif
}

void ApiGear::JavaServiceStarter::stopAdnroidServer(std::string fullJavaClassName)
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
    JNIEnv* Env = FAndroidApplication::GetJavaEnv();

    static jclass BridgeClass = FAndroidApplication::FindJavaClassGlobalRef(fullJavaClassName.c_str());
    if (BridgeClass == nullptr)
    {
		UE_LOG(LogTemp, Warning, TEXT( "JavaServiceStarter:stop; CLASS not found"));
        return;
    }
    jmethodID StartMethod = Env->GetStaticMethodID(BridgeClass, "stop", "(Landroid/content/Context;)V");
    if (StartMethod == nullptr)
    {
		UE_LOG(LogTemp, Warning, TEXT("JavaServiceStarter:stop; method not found"));
        return;
    }
    jobject Activity = FJavaWrapper::GameActivityThis; // Unreal’s activity
    FJavaWrapper::CallStaticVoidMethod(Env, BridgeClass, StartMethod, Activity);
#endif
}