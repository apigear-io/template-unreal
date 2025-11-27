
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

DEFINE_LOG_CATEGORY(LogTbRefIfacesJniCache_JNI);

void TbRefIfacesJniCache::checkException(JNIEnv* env, FString memberInfo)
{
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbRefIfacesJniCache_JNI, Warning, TEXT("Could not find %s"), *memberInfo);
	}
}
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
	checkException(env, "tbRefIfaces/tbRefIfaces_api/ISimpleLocalIf");
	javaClassSimpleLocalIfIntPropertySetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassSimpleLocalIf, "setIntProperty", "(I)V");
	checkException(env, "setIntProperty, (I)V  for tbRefIfaces/tbRefIfaces_api/ISimpleLocalIf");
	javaClassSimpleLocalIfIntPropertyGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassSimpleLocalIf, "getIntProperty", "()I");
	checkException(env, "getIntProperty, ()I for tbRefIfaces/tbRefIfaces_api/ISimpleLocalIf");

	serviceClassSimpleLocalIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfacesjniservice/SimpleLocalIfJniService");
	checkException(env, "tbRefIfaces/tbRefIfacesjniservice/SimpleLocalIfJniService");
	serviceClassSimpleLocalIfReadyMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassSimpleLocalIf, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for tbRefIfaces/tbRefIfacesjniservice/SimpleLocalIfJniService");
	serviceClassSimpleLocalIfIntPropertyChangedMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassSimpleLocalIf, "onIntPropertyChanged", "(I)V");
	checkException(env, "onIntPropertyChanged, (I)V for tbRefIfaces/tbRefIfacesjniservice/SimpleLocalIfJniService");
	serviceClassSimpleLocalIfIntSignalSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassSimpleLocalIf, "onIntSignal", "(I)V");
	checkException(env, "onIntSignal, (I)V for tbRefIfaces/tbRefIfacesjniservice/SimpleLocalIfJniService");
	clientClassSimpleLocalIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfacesjniclient/SimpleLocalIfJniClient");
	checkException(env, "tbRefIfaces/tbRefIfacesjniclient/SimpleLocalIfJniClient");
	clientClassSimpleLocalIfIntMethodAsyncMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassSimpleLocalIf, "intMethodAsync", "(Ljava/lang/String;I)V");
	checkException(env, "intMethodAsync, (Ljava/lang/String;I)V for tbRefIfaces/tbRefIfacesjniclient/SimpleLocalIfJniClient");
	clientClassSimpleLocalIfCtor = env->GetMethodID(TbRefIfacesJniCache::clientClassSimpleLocalIf, "<init>", "()V");
	checkException(env, "init, ()V for tbRefIfaces/tbRefIfacesjniclient/SimpleLocalIfJniClient");
	clientClassSimpleLocalIfBindMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassSimpleLocalIf, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for tbRefIfaces/tbRefIfacesjniclient/SimpleLocalIfJniClient");
	clientClassSimpleLocalIfUnbindMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassSimpleLocalIf, "unbind", "()V");
	checkException(env, "unbind, ()V for tbRefIfaces/tbRefIfacesjniclient/SimpleLocalIfJniClient");

	javaClassParentIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfaces_api/IParentIf");
	checkException(env, "tbRefIfaces/tbRefIfaces_api/IParentIf");
	javaClassParentIfLocalIfSetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "setLocalIf", "(LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	checkException(env, "setLocalIf, (LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V  for tbRefIfaces/tbRefIfaces_api/IParentIf");
	javaClassParentIfLocalIfGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "getLocalIf", "()LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;");
	checkException(env, "getLocalIf, ()LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf; for tbRefIfaces/tbRefIfaces_api/IParentIf");
	javaClassParentIfLocalIfListSetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "setLocalIfList", "([LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	checkException(env, "setLocalIfList, ([LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V  for tbRefIfaces/tbRefIfaces_api/IParentIf");
	javaClassParentIfLocalIfListGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "getLocalIfList", "()[LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;");
	checkException(env, "getLocalIfList, ()[LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf; for tbRefIfaces/tbRefIfaces_api/IParentIf");
	javaClassParentIfImportedIfSetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "setImportedIf", "(LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	checkException(env, "setImportedIf, (LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V  for tbRefIfaces/tbRefIfaces_api/IParentIf");
	javaClassParentIfImportedIfGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "getImportedIf", "()LtbIfaceimport/tbIfaceimport_api/IEmptyIf;");
	checkException(env, "getImportedIf, ()LtbIfaceimport/tbIfaceimport_api/IEmptyIf; for tbRefIfaces/tbRefIfaces_api/IParentIf");
	javaClassParentIfImportedIfListSetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "setImportedIfList", "([LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	checkException(env, "setImportedIfList, ([LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V  for tbRefIfaces/tbRefIfaces_api/IParentIf");
	javaClassParentIfImportedIfListGetterId = env->GetMethodID(TbRefIfacesJniCache::javaClassParentIf, "getImportedIfList", "()[LtbIfaceimport/tbIfaceimport_api/IEmptyIf;");
	checkException(env, "getImportedIfList, ()[LtbIfaceimport/tbIfaceimport_api/IEmptyIf; for tbRefIfaces/tbRefIfaces_api/IParentIf");

	serviceClassParentIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfacesjniservice/ParentIfJniService");
	checkException(env, "tbRefIfaces/tbRefIfacesjniservice/ParentIfJniService");
	serviceClassParentIfReadyMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for tbRefIfaces/tbRefIfacesjniservice/ParentIfJniService");
	serviceClassParentIfLocalIfChangedMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onLocalIfChanged", "(LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	checkException(env, "onLocalIfChanged, (LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V for tbRefIfaces/tbRefIfacesjniservice/ParentIfJniService");
	serviceClassParentIfLocalIfListChangedMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onLocalIfListChanged", "([LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	checkException(env, "onLocalIfListChanged, ([LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V for tbRefIfaces/tbRefIfacesjniservice/ParentIfJniService");
	serviceClassParentIfImportedIfChangedMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onImportedIfChanged", "(LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	checkException(env, "onImportedIfChanged, (LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V for tbRefIfaces/tbRefIfacesjniservice/ParentIfJniService");
	serviceClassParentIfImportedIfListChangedMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onImportedIfListChanged", "([LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	checkException(env, "onImportedIfListChanged, ([LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V for tbRefIfaces/tbRefIfacesjniservice/ParentIfJniService");
	serviceClassParentIfLocalIfSignalSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onLocalIfSignal", "(LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	checkException(env, "onLocalIfSignal, (LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V for tbRefIfaces/tbRefIfacesjniservice/ParentIfJniService");
	serviceClassParentIfLocalIfSignalListSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onLocalIfSignalList", "([LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	checkException(env, "onLocalIfSignalList, ([LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V for tbRefIfaces/tbRefIfacesjniservice/ParentIfJniService");
	serviceClassParentIfImportedIfSignalSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onImportedIfSignal", "(LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	checkException(env, "onImportedIfSignal, (LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V for tbRefIfaces/tbRefIfacesjniservice/ParentIfJniService");
	serviceClassParentIfImportedIfSignalListSignalMethodID = env->GetMethodID(TbRefIfacesJniCache::serviceClassParentIf, "onImportedIfSignalList", "([LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	checkException(env, "onImportedIfSignalList, ([LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V for tbRefIfaces/tbRefIfacesjniservice/ParentIfJniService");
	clientClassParentIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfacesjniclient/ParentIfJniClient");
	checkException(env, "tbRefIfaces/tbRefIfacesjniclient/ParentIfJniClient");
	clientClassParentIfLocalIfMethodAsyncMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassParentIf, "localIfMethodAsync", "(Ljava/lang/String;LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	checkException(env, "localIfMethodAsync, (Ljava/lang/String;LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V for tbRefIfaces/tbRefIfacesjniclient/ParentIfJniClient");
	clientClassParentIfLocalIfMethodListAsyncMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassParentIf, "localIfMethodListAsync", "(Ljava/lang/String;[LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V");
	checkException(env, "localIfMethodListAsync, (Ljava/lang/String;[LtbRefIfaces/tbRefIfaces_api/ISimpleLocalIf;)V for tbRefIfaces/tbRefIfacesjniclient/ParentIfJniClient");
	clientClassParentIfImportedIfMethodAsyncMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassParentIf, "importedIfMethodAsync", "(Ljava/lang/String;LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	checkException(env, "importedIfMethodAsync, (Ljava/lang/String;LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V for tbRefIfaces/tbRefIfacesjniclient/ParentIfJniClient");
	clientClassParentIfImportedIfMethodListAsyncMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassParentIf, "importedIfMethodListAsync", "(Ljava/lang/String;[LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V");
	checkException(env, "importedIfMethodListAsync, (Ljava/lang/String;[LtbIfaceimport/tbIfaceimport_api/IEmptyIf;)V for tbRefIfaces/tbRefIfacesjniclient/ParentIfJniClient");
	clientClassParentIfCtor = env->GetMethodID(TbRefIfacesJniCache::clientClassParentIf, "<init>", "()V");
	checkException(env, "init, ()V for tbRefIfaces/tbRefIfacesjniclient/ParentIfJniClient");
	clientClassParentIfBindMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassParentIf, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for tbRefIfaces/tbRefIfacesjniclient/ParentIfJniClient");
	clientClassParentIfUnbindMethodID = env->GetMethodID(TbRefIfacesJniCache::clientClassParentIf, "unbind", "()V");
	checkException(env, "unbind, ()V for tbRefIfaces/tbRefIfacesjniclient/ParentIfJniClient");
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
