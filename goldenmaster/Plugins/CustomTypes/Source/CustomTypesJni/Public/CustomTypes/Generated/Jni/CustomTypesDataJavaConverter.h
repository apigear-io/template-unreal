
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
#include "CustomTypes/Generated/api/CustomTypes_data.h"
#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI
DECLARE_LOG_CATEGORY_EXTERN(LogCustomTypesDataJavaConverter_JNI, Log, All);

#include "Engine/Engine.h"

class CUSTOMTYPESAPI_API CustomTypesDataJavaConverter
{
public:
	static void fillVector3D(JNIEnv* env, jobject input, FCustomTypesVector3D& out_vector3_d);
	static void fillVector3DArray(JNIEnv* env, jobjectArray input, TArray<FCustomTypesVector3D>& out_array);
	static jobject makeJavaVector3D(JNIEnv* env, const FCustomTypesVector3D& out_vector3_d);
	static jobjectArray makeJavaVector3DArray(JNIEnv* env, const TArray<FCustomTypesVector3D>& cppArray);

	static void checkJniError(const TCHAR* Msg);
};

#endif
