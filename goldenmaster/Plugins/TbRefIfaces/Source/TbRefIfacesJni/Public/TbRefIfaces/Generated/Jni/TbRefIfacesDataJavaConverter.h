
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

#include "TbIfaceimport/Generated/Jni/TbIfaceimportDataJavaConverter.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_apig.h"
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
DECLARE_LOG_CATEGORY_EXTERN(LogTbRefIfacesDataJavaConverter_JNI, Log, All);

class TBREFIFACESAPI_API TbRefIfacesDataJavaConverter
{
public:
	static jclass jSimpleLocalIf;
	static void fillSimpleLocalIf(JNIEnv* env, jobject input, TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> out_simple_local_if);
	static void fillSimpleLocalIfArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& out_array);
	static jobject makeJavaSimpleLocalIf(JNIEnv* env, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> out_simple_local_if);
	static jobjectArray makeJavaSimpleLocalIfArray(JNIEnv* env, const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& cppArray);

	static TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> getCppInstanceTbRefIfacesSimpleLocalIf();

	static jclass jParentIf;
	static void fillParentIf(JNIEnv* env, jobject input, TScriptInterface<ITbRefIfacesParentIfInterface> out_parent_if);
	static void fillParentIfArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbRefIfacesParentIfInterface>>& out_array);
	static jobject makeJavaParentIf(JNIEnv* env, const TScriptInterface<ITbRefIfacesParentIfInterface> out_parent_if);
	static jobjectArray makeJavaParentIfArray(JNIEnv* env, const TArray<TScriptInterface<ITbRefIfacesParentIfInterface>>& cppArray);

	static TScriptInterface<ITbRefIfacesParentIfInterface> getCppInstanceTbRefIfacesParentIf();

	static bool checkJniErrorOccured(const TCHAR* Msg);
	static void cleanJavaReferences();

private:
	static FCriticalSection initMutex;
	static void ensureInitialized();
	static bool m_isInitialized;
	static jmethodID getMethod(jclass cls, const char* name, const char* signature, const TCHAR*);
	static jmethodID getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo);
	static jfieldID getFieldId(jclass cls, const char* name, const char* signature, const TCHAR*);
};

#endif
