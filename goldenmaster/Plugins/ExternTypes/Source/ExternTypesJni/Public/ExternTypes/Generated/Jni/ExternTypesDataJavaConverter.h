
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
#pragma once

#include "Runtime/Core/Public/Math/Vector.h"
#if PLATFORM_ANDROID

#include "HAL/CriticalSection.h"
#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI
DECLARE_LOG_CATEGORY_EXTERN(LogExternTypesDataJavaConverter_JNI, Log, All);

class EXTERNTYPESAPI_API ExternTypesDataJavaConverter
{
public:
	static jclass jMyVector3D;
	static void fillMyVector3D(JNIEnv* env, jobject input, FVector& out_my_vector3_d);
	static void fillMyVector3DArray(JNIEnv* env, jobjectArray input, TArray<FVector>& out_array);
	static jobject makeJavaMyVector3D(JNIEnv* env, const FVector& out_my_vector3_d);
	static jobjectArray makeJavaMyVector3DArray(JNIEnv* env, const TArray<FVector>& cppArray);

	static bool checkJniErrorOccured(const TCHAR* Msg);
	static void cleanJavaReferences();

private:
	static FCriticalSection initMutex;
	static void ensureInitialized();
	static bool m_isInitialized;
};

#endif
