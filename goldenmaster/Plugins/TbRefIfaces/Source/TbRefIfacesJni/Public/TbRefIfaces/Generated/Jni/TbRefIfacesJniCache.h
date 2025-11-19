
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

#include "CoreMinimal.h"

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

class TBREFIFACESAPI_API TbRefIfacesJniCache
{
public:
	static jclass javaClassSimpleLocalIf;
	static jmethodID javaClassSimpleLocalIfIntPropertySetterId;
	static jmethodID javaClassSimpleLocalIfIntPropertyGetterId;
	static jmethodID javaClassSimpleLocalIfIntPropertyChangedMethodID;
	static jclass serviceClassSimpleLocalIf;
	static jmethodID serviceClassSimpleLocalIfReadyMethodID;
	static jmethodID serviceClassSimpleLocalIfIntPropertyChangedMethodID;
	static jmethodID serviceClassSimpleLocalIfIntSignalSignalMethodID;
	static jclass clientClassSimpleLocalIf;
	static jmethodID clientClassSimpleLocalIfCtor;
	static jmethodID clientClassSimpleLocalIfBindMethodID;
	static jmethodID clientClassSimpleLocalIfUnbindMethodID;
	static jmethodID clientClassSimpleLocalIfIntMethodAsyncMethodID;
	static jclass javaClassParentIf;
	static jmethodID javaClassParentIfLocalIfSetterId;
	static jmethodID javaClassParentIfLocalIfGetterId;
	static jmethodID javaClassParentIfLocalIfChangedMethodID;
	static jmethodID javaClassParentIfLocalIfListSetterId;
	static jmethodID javaClassParentIfLocalIfListGetterId;
	static jmethodID javaClassParentIfLocalIfListChangedMethodID;
	static jmethodID javaClassParentIfImportedIfSetterId;
	static jmethodID javaClassParentIfImportedIfGetterId;
	static jmethodID javaClassParentIfImportedIfChangedMethodID;
	static jmethodID javaClassParentIfImportedIfListSetterId;
	static jmethodID javaClassParentIfImportedIfListGetterId;
	static jmethodID javaClassParentIfImportedIfListChangedMethodID;
	static jclass serviceClassParentIf;
	static jmethodID serviceClassParentIfReadyMethodID;
	static jmethodID serviceClassParentIfLocalIfChangedMethodID;
	static jmethodID serviceClassParentIfLocalIfListChangedMethodID;
	static jmethodID serviceClassParentIfImportedIfChangedMethodID;
	static jmethodID serviceClassParentIfImportedIfListChangedMethodID;
	static jmethodID serviceClassParentIfLocalIfSignalSignalMethodID;
	static jmethodID serviceClassParentIfLocalIfSignalListSignalMethodID;
	static jmethodID serviceClassParentIfImportedIfSignalSignalMethodID;
	static jmethodID serviceClassParentIfImportedIfSignalListSignalMethodID;
	static jclass clientClassParentIf;
	static jmethodID clientClassParentIfCtor;
	static jmethodID clientClassParentIfBindMethodID;
	static jmethodID clientClassParentIfUnbindMethodID;
	static jmethodID clientClassParentIfLocalIfMethodAsyncMethodID;
	static jmethodID clientClassParentIfLocalIfMethodListAsyncMethodID;
	static jmethodID clientClassParentIfImportedIfMethodAsyncMethodID;
	static jmethodID clientClassParentIfImportedIfMethodListAsyncMethodID;

	static void init();
	static void clear();
	static bool isInitialized();

private:
	static bool m_isInitialized;
};

#endif
