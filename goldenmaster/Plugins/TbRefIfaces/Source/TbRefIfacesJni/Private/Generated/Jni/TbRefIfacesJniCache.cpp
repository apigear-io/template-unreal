
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
jclass TbRefIfacesJniCache::javaClassSimpleLocalIf = nullptr;
jmethodID TbRefIfacesJniCache::javaClassSimpleLocalIfIntPropertySetterId = nullptr;
jmethodID TbRefIfacesJniCache::javaClassSimpleLocalIfIntPropertyGetterId = nullptr;
jclass TbRefIfacesJniCache::serviceClassSimpleLocalIf = nullptr;
jmethodID TbRefIfacesJniCache::serviceClassSimpleLocalIfReadyMethodID = nullptr;
jmethodID TbRefIfacesJniCache::serviceClassSimpleLocalIfIntPropertyChangedMethodID = nullptr;
jmethodID TbRefIfacesJniCache::serviceClassSimpleLocalIfIntSignalSignalMethodID = nullptr;
jclass TbRefIfacesJniCache::clientClassSimpleLocalIf = nullptr;
jmethodID TbRefIfacesJniCache::clientClassSimpleLocalIfCtor = nullptr;
jmethodID TbRefIfacesJniCache::clientClassSimpleLocalIfBindMethodID = nullptr;
jmethodID TbRefIfacesJniCache::clientClassSimpleLocalIfUnbindMethodID = nullptr;
jmethodID TbRefIfacesJniCache::clientClassSimpleLocalIfIntMethodAsyncMethodID = nullptr;
jclass TbRefIfacesJniCache::javaClassParentIf = nullptr;
jmethodID TbRefIfacesJniCache::javaClassParentIfLocalIfSetterId = nullptr;
jmethodID TbRefIfacesJniCache::javaClassParentIfLocalIfGetterId = nullptr;
jmethodID TbRefIfacesJniCache::javaClassParentIfLocalIfListSetterId = nullptr;
jmethodID TbRefIfacesJniCache::javaClassParentIfLocalIfListGetterId = nullptr;
jmethodID TbRefIfacesJniCache::javaClassParentIfImportedIfSetterId = nullptr;
jmethodID TbRefIfacesJniCache::javaClassParentIfImportedIfGetterId = nullptr;
jmethodID TbRefIfacesJniCache::javaClassParentIfImportedIfListSetterId = nullptr;
jmethodID TbRefIfacesJniCache::javaClassParentIfImportedIfListGetterId = nullptr;
jclass TbRefIfacesJniCache::serviceClassParentIf = nullptr;
jmethodID TbRefIfacesJniCache::serviceClassParentIfReadyMethodID = nullptr;
jmethodID TbRefIfacesJniCache::serviceClassParentIfLocalIfChangedMethodID = nullptr;
jmethodID TbRefIfacesJniCache::serviceClassParentIfLocalIfListChangedMethodID = nullptr;
jmethodID TbRefIfacesJniCache::serviceClassParentIfImportedIfChangedMethodID = nullptr;
jmethodID TbRefIfacesJniCache::serviceClassParentIfImportedIfListChangedMethodID = nullptr;
jmethodID TbRefIfacesJniCache::serviceClassParentIfLocalIfSignalSignalMethodID = nullptr;
jmethodID TbRefIfacesJniCache::serviceClassParentIfLocalIfSignalListSignalMethodID = nullptr;
jmethodID TbRefIfacesJniCache::serviceClassParentIfImportedIfSignalSignalMethodID = nullptr;
jmethodID TbRefIfacesJniCache::serviceClassParentIfImportedIfSignalListSignalMethodID = nullptr;
jclass TbRefIfacesJniCache::clientClassParentIf = nullptr;
jmethodID TbRefIfacesJniCache::clientClassParentIfCtor = nullptr;
jmethodID TbRefIfacesJniCache::clientClassParentIfBindMethodID = nullptr;
jmethodID TbRefIfacesJniCache::clientClassParentIfUnbindMethodID = nullptr;
jmethodID TbRefIfacesJniCache::clientClassParentIfLocalIfMethodAsyncMethodID = nullptr;
jmethodID TbRefIfacesJniCache::clientClassParentIfLocalIfMethodListAsyncMethodID = nullptr;
jmethodID TbRefIfacesJniCache::clientClassParentIfImportedIfMethodAsyncMethodID = nullptr;
jmethodID TbRefIfacesJniCache::clientClassParentIfImportedIfMethodListAsyncMethodID = nullptr;

bool TbRefIfacesJniCache::m_isInitialized = false;

void TbRefIfacesJniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();

	javaClassSimpleLocalIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfaces_api/ISimpleLocalIf");
	javaClassSimpleLocalIfIntPropertySetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassSimpleLocalIf, "setIntProperty", "(I)V");
	javaClassSimpleLocalIfIntPropertyGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassSimpleLocalIf, "getIntProperty", "()I");

	serviceClassSimpleLocalIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfacesjniservice/SimpleLocalIfJniService");
	serviceClassSimpleLocalIfReadyMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassSimpleLocalIf, "nativeServiceReady", "(Z)V");
	serviceClassSimpleLocalIfIntPropertyChangedMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassSimpleLocalIf, "onIntPropertyChanged", "(I)V");
	serviceClassSimpleLocalIfIntSignalSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassSimpleLocalIf, "onIntSignal", "(I)V");
	clientClassSimpleLocalIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfacesjniclient/SimpleLocalIfJniClient");
	clientClassSimpleLocalIfIntMethodAsyncMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassSimpleLocalIf, "intMethodAsync", "(Ljava/lang/String;I)V");
	clientClassSimpleLocalIfCtor = env->GetMethodID(TbRefIfacesJniCache::clientClassSimpleLocalIf, "<init>", "()V");
	clientClassSimpleLocalIfBindMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassSimpleLocalIf, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	clientClassSimpleLocalIfUnbindMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassSimpleLocalIf, "unbind", "()V");

	javaClassParentIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfaces_api/IParentIf");
	javaClassParentIfLocalIfSetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "setLocalIf", "(LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	javaClassParentIfLocalIfGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "getLocalIf", "()LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;");
	javaClassParentIfLocalIfListSetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "setLocalIfList", "([LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	javaClassParentIfLocalIfListGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "getLocalIfList", "()[LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;");
	javaClassParentIfImportedIfSetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "setImportedIf", "(LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	javaClassParentIfImportedIfGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "getImportedIf", "()LtbIfaceimport/tbIfaceimport_api/IEmptyIf;");
	javaClassParentIfImportedIfListSetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "setImportedIfList", "([LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	javaClassParentIfImportedIfListGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "getImportedIfList", "()[LtbIfaceimport/tbIfaceimport_api/IEmptyIf;");

	serviceClassParentIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfacesjniservice/ParentIfJniService");
	serviceClassParentIfReadyMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "nativeServiceReady", "(Z)V");
	serviceClassParentIfLocalIfChangedMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onLocalIfChanged", "(LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	serviceClassParentIfLocalIfListChangedMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onLocalIfListChanged", "([LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	serviceClassParentIfImportedIfChangedMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onImportedIfChanged", "(LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	serviceClassParentIfImportedIfListChangedMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onImportedIfListChanged", "([LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	serviceClassParentIfLocalIfSignalSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onLocalIfSignal", "(LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	serviceClassParentIfLocalIfSignalListSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onLocalIfSignalList", "([LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	serviceClassParentIfImportedIfSignalSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onImportedIfSignal", "(LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	serviceClassParentIfImportedIfSignalListSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onImportedIfSignalList", "([LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	clientClassParentIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfacesjniclient/ParentIfJniClient");
	clientClassParentIfLocalIfMethodAsyncMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassParentIf, "localIfMethodAsync", "(Ljava/lang/String;LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	clientClassParentIfLocalIfMethodListAsyncMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassParentIf, "localIfMethodListAsync", "(Ljava/lang/String;[LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	clientClassParentIfImportedIfMethodAsyncMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassParentIf, "importedIfMethodAsync", "(Ljava/lang/String;LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	clientClassParentIfImportedIfMethodListAsyncMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassParentIf, "importedIfMethodListAsync", "(Ljava/lang/String;[LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	clientClassParentIfCtor = env->GetMethodID(TbRefIfacesJniCache::clientClassParentIf, "<init>", "()V");
	clientClassParentIfBindMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassParentIf, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	clientClassParentIfUnbindMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassParentIf, "unbind", "()V");
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
	env->DeleteGlobalRef(serviceClassSimpleLocalIf);
	serviceClassSimpleLocalIf = nullptr;
	serviceClassSimpleLocalIfReadyMethodID = nullptr;
	serviceClassSimpleLocalIfIntPropertyChangedMethodID = nullptr;
	serviceClassSimpleLocalIfIntSignalSignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassSimpleLocalIf);
	clientClassSimpleLocalIf = nullptr;
	clientClassSimpleLocalIfIntMethodAsyncMethodID = nullptr;
	clientClassSimpleLocalIfCtor = nullptr;
	clientClassSimpleLocalIfBindMethodID = nullptr;
	clientClassSimpleLocalIfUnbindMethodID = nullptr;
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
	env->DeleteGlobalRef(serviceClassParentIf);
	serviceClassParentIf = nullptr;
	serviceClassParentIfReadyMethodID = nullptr;
	serviceClassParentIfLocalIfChangedMethodID = nullptr;
	serviceClassParentIfLocalIfListChangedMethodID = nullptr;
	serviceClassParentIfImportedIfChangedMethodID = nullptr;
	serviceClassParentIfImportedIfListChangedMethodID = nullptr;
	serviceClassParentIfLocalIfSignalSignalMethodID = nullptr;
	serviceClassParentIfLocalIfSignalListSignalMethodID = nullptr;
	serviceClassParentIfImportedIfSignalSignalMethodID = nullptr;
	serviceClassParentIfImportedIfSignalListSignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassParentIf);
	clientClassParentIf = nullptr;
	clientClassParentIfLocalIfMethodAsyncMethodID = nullptr;
	clientClassParentIfLocalIfMethodListAsyncMethodID = nullptr;
	clientClassParentIfImportedIfMethodAsyncMethodID = nullptr;
	clientClassParentIfImportedIfMethodListAsyncMethodID = nullptr;
	clientClassParentIfCtor = nullptr;
	clientClassParentIfBindMethodID = nullptr;
	clientClassParentIfUnbindMethodID = nullptr;
}

bool TbRefIfacesJniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
