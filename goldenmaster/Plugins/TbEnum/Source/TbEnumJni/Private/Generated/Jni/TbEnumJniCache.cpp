
/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "TbEnum/Generated/Jni/TbEnumJniCache.h"
#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

#include "Engine/Engine.h"

// TODO
// after each findJAvaClassGlobalRef and getting methodId or FieldId
// if (env->ExceptionCheck()) {
//	env->ExceptionDescribe(); // logs in java
//	env->ExceptionClear();
//	LOG UE;
//}

void TbEnumJniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	javaEnumEnum0 = FAndroidApplication::FindJavaClassGlobalRef("TbEnum/TbEnum_api/Enum0");
	javaEnumEnum0FromValueMethodId = env->GetStaticMethodID(TbEnumJniCache::javaEnumEnum0, "fromValue", "(I)LTbEnum/TbEnum_api/Enum0;");
	javaEnumEnum0GetValueMethod = env->GetMethodID(TbEnumJniCache::javaEnumEnum0, "getValue", "()I");
	javaEnumEnum1 = FAndroidApplication::FindJavaClassGlobalRef("TbEnum/TbEnum_api/Enum1");
	javaEnumEnum1FromValueMethodId = env->GetStaticMethodID(TbEnumJniCache::javaEnumEnum1, "fromValue", "(I)LTbEnum/TbEnum_api/Enum1;");
	javaEnumEnum1GetValueMethod = env->GetMethodID(TbEnumJniCache::javaEnumEnum1, "getValue", "()I");
	javaEnumEnum2 = FAndroidApplication::FindJavaClassGlobalRef("TbEnum/TbEnum_api/Enum2");
	javaEnumEnum2FromValueMethodId = env->GetStaticMethodID(TbEnumJniCache::javaEnumEnum2, "fromValue", "(I)LTbEnum/TbEnum_api/Enum2;");
	javaEnumEnum2GetValueMethod = env->GetMethodID(TbEnumJniCache::javaEnumEnum2, "getValue", "()I");
	javaEnumEnum3 = FAndroidApplication::FindJavaClassGlobalRef("TbEnum/TbEnum_api/Enum3");
	javaEnumEnum3FromValueMethodId = env->GetStaticMethodID(TbEnumJniCache::javaEnumEnum3, "fromValue", "(I)LTbEnum/TbEnum_api/Enum3;");
	javaEnumEnum3GetValueMethod = env->GetMethodID(TbEnumJniCache::javaEnumEnum3, "getValue", "()I");

	javaClassEnumInterface = FAndroidApplication::FindJavaClassGlobalRef("TbEnum/TbEnum_api/IEnumInterface");
	javaClassEnumInterfaceProp0SetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "setProp0", "(LtbEnum/tbEnum_api/Enum0;)V");
	javaClassEnumInterfaceProp0GetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "getProp0", "()LtbEnum/tbEnum_api/Enum0;");
	javaClassEnumInterfaceProp1SetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "setProp1", "(LtbEnum/tbEnum_api/Enum1;)V");
	javaClassEnumInterfaceProp1GetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "getProp1", "()LtbEnum/tbEnum_api/Enum1;");
	javaClassEnumInterfaceProp2SetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "setProp2", "(LtbEnum/tbEnum_api/Enum2;)V");
	javaClassEnumInterfaceProp2GetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "getProp2", "()LtbEnum/tbEnum_api/Enum2;");
	javaClassEnumInterfaceProp3SetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "setProp3", "(LtbEnum/tbEnum_api/Enum3;)V");
	javaClassEnumInterfaceProp3GetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "getProp3", "()LtbEnum/tbEnum_api/Enum3;");
	javaClassEnumInterfaceSig0SignalMethodID = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "onSig0", "(LtbEnum/tbEnum_api/Enum0;)V");
	javaClassEnumInterfaceSig1SignalMethodID = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "onSig1", "(LtbEnum/tbEnum_api/Enum1;)V");
	javaClassEnumInterfaceSig2SignalMethodID = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "onSig2", "(LtbEnum/tbEnum_api/Enum2;)V");
	javaClassEnumInterfaceSig3SignalMethodID = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "onSig3", "(LtbEnum/tbEnum_api/Enum3;)V");
	javaClassEnumInterfaceFunc0MethodID = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "func0Async", "(Ljava/lang/String;LtbEnum/tbEnum_api/Enum0;)V");
	javaClassEnumInterfaceFunc1MethodID = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "func1Async", "(Ljava/lang/String;LtbEnum/tbEnum_api/Enum1;)V");
	javaClassEnumInterfaceFunc2MethodID = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "func2Async", "(Ljava/lang/String;LtbEnum/tbEnum_api/Enum2;)V");
	javaClassEnumInterfaceFunc3MethodID = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "func3Async", "(Ljava/lang/String;LtbEnum/tbEnum_api/Enum3;)V");
	m_isInitialized = true;
}

void TbEnumJniCache::clear()
{
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(javaEnumEnum0);
	javaEnumEnum0 = nullptr;
	javaEnumEnum0FromValueMethodId = nullptr;
	javaEnumEnum0GetValueMethod = nullptr;
	env->DeleteGlobalRef(javaEnumEnum1);
	javaEnumEnum1 = nullptr;
	javaEnumEnum1FromValueMethodId = nullptr;
	javaEnumEnum1GetValueMethod = nullptr;
	env->DeleteGlobalRef(javaEnumEnum2);
	javaEnumEnum2 = nullptr;
	javaEnumEnum2FromValueMethodId = nullptr;
	javaEnumEnum2GetValueMethod = nullptr;
	env->DeleteGlobalRef(javaEnumEnum3);
	javaEnumEnum3 = nullptr;
	javaEnumEnum3FromValueMethodId = nullptr;
	javaEnumEnum3GetValueMethod = nullptr;
	env->DeleteGlobalRef(javaClassEnumInterface);
	javaClassEnumInterface = nullptr;
	javaClassEnumInterfaceProp0SetterId = nullptr;
	javaClassEnumInterfaceProp0GetterId = nullptr;
	javaClassEnumInterfaceProp1SetterId = nullptr;
	javaClassEnumInterfaceProp1GetterId = nullptr;
	javaClassEnumInterfaceProp2SetterId = nullptr;
	javaClassEnumInterfaceProp2GetterId = nullptr;
	javaClassEnumInterfaceProp3SetterId = nullptr;
	javaClassEnumInterfaceProp3GetterId = nullptr;
	javaClassEnumInterfaceSig0SignalMethodID = nullptr;
	javaClassEnumInterfaceSig1SignalMethodID = nullptr;
	javaClassEnumInterfaceSig2SignalMethodID = nullptr;
	javaClassEnumInterfaceSig3SignalMethodID = nullptr;
	javaClassEnumInterfaceFunc0MethodID = nullptr;
	javaClassEnumInterfaceFunc1MethodID = nullptr;
	javaClassEnumInterfaceFunc2MethodID = nullptr;
	javaClassEnumInterfaceFunc3MethodID = nullptr;
}

bool TbEnumJniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
