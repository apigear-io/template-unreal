
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

#include "TbRefIfaces/Generated/Jni/TbRefIfacesJniCache.h"
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

void TbRefIfacesJniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();

	javaClassSimpleLocalIf = FAndroidApplication::FindJavaClassGlobalRef("TbRefIfaces/TbRefIfaces_api/ISimpleLocalIf");
	javaClassSimpleLocalIfIntPropertySetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassSimpleLocalIf, "setIntProperty", "(I)V");
	javaClassSimpleLocalIfIntPropertyGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassSimpleLocalIf, "getIntProperty", "()I");
	javaClassSimpleLocalIfIntSignalSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::javaClassSimpleLocalIf, "onIntSignal", "(I)V");
	javaClassSimpleLocalIfIntMethodMethodID = env->GetMethodID(TbRefIfacesJniCache::javaClassSimpleLocalIf, "intMethodAsync", "(Ljava/lang/String;I)V");

	javaClassParentIf = FAndroidApplication::FindJavaClassGlobalRef("TbRefIfaces/TbRefIfaces_api/IParentIf");
	javaClassParentIfLocalIfSetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "setLocalIf", "(LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	javaClassParentIfLocalIfGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "getLocalIf", "()LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;");
	javaClassParentIfLocalIfListSetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "setLocalIfList", "([LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	javaClassParentIfLocalIfListGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "getLocalIfList", "()[LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;");
	javaClassParentIfImportedIfSetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "setImportedIf", "(LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	javaClassParentIfImportedIfGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "getImportedIf", "()LtbIfaceimport/tbIfaceimport_api/IEmptyIf;");
	javaClassParentIfImportedIfListSetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "setImportedIfList", "([LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	javaClassParentIfImportedIfListGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "getImportedIfList", "()[LtbIfaceimport/tbIfaceimport_api/IEmptyIf;");
	javaClassParentIfLocalIfSignalSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "onLocalIfSignal", "(LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	javaClassParentIfLocalIfSignalListSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "onLocalIfSignalList", "([LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	javaClassParentIfImportedIfSignalSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "onImportedIfSignal", "(LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	javaClassParentIfImportedIfSignalListSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "onImportedIfSignalList", "([LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	javaClassParentIfLocalIfMethodMethodID = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "localIfMethodAsync", "(Ljava/lang/String;LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	javaClassParentIfLocalIfMethodListMethodID = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "localIfMethodListAsync", "(Ljava/lang/String;[LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	javaClassParentIfImportedIfMethodMethodID = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "importedIfMethodAsync", "(Ljava/lang/String;LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	javaClassParentIfImportedIfMethodListMethodID = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "importedIfMethodListAsync", "(Ljava/lang/String;[LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	m_isInitialized = true;
}

void TbRefIfacesJniCache::clear()
{
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(javaClassSimpleLocalIf);
	javaClassSimpleLocalIf = nullptr;
	javaClassSimpleLocalIfIntPropertySetterId = nullptr;
	javaClassSimpleLocalIfIntPropertyGetterId = nullptr;
	javaClassSimpleLocalIfIntSignalSignalMethodID = nullptr;
	javaClassSimpleLocalIfIntMethodMethodID = nullptr;
	env->DeleteGlobalRef(javaClassParentIf);
	javaClassParentIf = nullptr;
	javaClassParentIfLocalIfSetterId = nullptr;
	javaClassParentIfLocalIfGetterId = nullptr;
	javaClassParentIfLocalIfListSetterId = nullptr;
	javaClassParentIfLocalIfListGetterId = nullptr;
	javaClassParentIfImportedIfSetterId = nullptr;
	javaClassParentIfImportedIfGetterId = nullptr;
	javaClassParentIfImportedIfListSetterId = nullptr;
	javaClassParentIfImportedIfListGetterId = nullptr;
	javaClassParentIfLocalIfSignalSignalMethodID = nullptr;
	javaClassParentIfLocalIfSignalListSignalMethodID = nullptr;
	javaClassParentIfImportedIfSignalSignalMethodID = nullptr;
	javaClassParentIfImportedIfSignalListSignalMethodID = nullptr;
	javaClassParentIfLocalIfMethodMethodID = nullptr;
	javaClassParentIfLocalIfMethodListMethodID = nullptr;
	javaClassParentIfImportedIfMethodMethodID = nullptr;
	javaClassParentIfImportedIfMethodListMethodID = nullptr;
}

bool TbRefIfacesJniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
