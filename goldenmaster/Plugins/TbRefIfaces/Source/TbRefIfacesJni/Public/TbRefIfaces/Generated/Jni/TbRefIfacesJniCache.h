
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
	static jclass javaClassSimpleLocalIf = nullptr;
	static jmethodID javaClassSimpleLocalIfIntPropertySetterId = nullptr;
	static jmethodID javaClassSimpleLocalIfIntPropertyGetterId = nullptr;
	static jmethodID javaClassSimpleLocalIfIntSignalSignalMethodID = nullptr;
	static jmethodID javaClassSimpleLocalIfIntMethodMethodID = nullptr;
	static jclass javaClassParentIf = nullptr;
	static jmethodID javaClassParentIfLocalIfSetterId = nullptr;
	static jmethodID javaClassParentIfLocalIfGetterId = nullptr;
	static jmethodID javaClassParentIfLocalIfListSetterId = nullptr;
	static jmethodID javaClassParentIfLocalIfListGetterId = nullptr;
	static jmethodID javaClassParentIfImportedIfSetterId = nullptr;
	static jmethodID javaClassParentIfImportedIfGetterId = nullptr;
	static jmethodID javaClassParentIfImportedIfListSetterId = nullptr;
	static jmethodID javaClassParentIfImportedIfListGetterId = nullptr;
	static jmethodID javaClassParentIfLocalIfSignalSignalMethodID = nullptr;
	static jmethodID javaClassParentIfLocalIfSignalListSignalMethodID = nullptr;
	static jmethodID javaClassParentIfImportedIfSignalSignalMethodID = nullptr;
	static jmethodID javaClassParentIfImportedIfSignalListSignalMethodID = nullptr;
	static jmethodID javaClassParentIfLocalIfMethodMethodID = nullptr;
	static jmethodID javaClassParentIfLocalIfMethodListMethodID = nullptr;
	static jmethodID javaClassParentIfImportedIfMethodMethodID = nullptr;
	static jmethodID javaClassParentIfImportedIfMethodListMethodID = nullptr;

	static void init();
	static void clear();
	static bool isInitialized();

private:
	static bool m_isInitialized = false;
}

#endif
