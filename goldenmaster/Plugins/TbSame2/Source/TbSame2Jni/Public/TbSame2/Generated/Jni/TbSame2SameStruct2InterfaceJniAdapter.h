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

#include "TbSame2/Generated/api/TbSame2SameStruct2InterfaceInterface.h"
#include "TbSame2/Generated/Jni/TbSame2JniConnectionStatus.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "HAL/CriticalSection.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "TbSame2SameStruct2InterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSame2SameStruct2Interface_JNI, Log, All);

// Helper interface to expose necessary functions for native Jni function implementations.
// Main purpose is to allow it in a thread safe way, the native JNI calls are always from JNI thread.
class ITbSame2SameStruct2InterfaceJniAdapterAccessor
{
public:
	virtual ~ITbSame2SameStruct2InterfaceJniAdapterAccessor() = default;
	virtual TScriptInterface<ITbSame2SameStruct2InterfaceInterface> getBackendServiceForJNI() const = 0;
	virtual void jniServiceStatusChanged(bool) = 0;
};

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbSame2SameStruct2InterfaceInterface
 */
UCLASS(BlueprintType)
class TBSAME2JNI_API UTbSame2SameStruct2InterfaceJniAdapter : public UGameInstanceSubsystem, public ITbSame2SameStruct2InterfaceSubscriberInterface, public ITbSame2SameStruct2InterfaceJniAdapterAccessor
{
public:
	GENERATED_BODY()

	explicit UTbSame2SameStruct2InterfaceJniAdapter();
	virtual ~UTbSame2SameStruct2InterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface")
	void setBackendService(TScriptInterface<ITbSame2SameStruct2InterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface")
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> getBackendService();

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface|Jni|Remote", DisplayName = "Jni Service Started")
	FTbSame2JniServiceStartedDelegateBP _JniServiceStartedBP;
	FTbSame2JniServiceStartedDelegate _JniServiceStarted;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface|Jni|Remote", DisplayName = "Jni Service Died")
	FTbSame2JniServiceDiedDelegateBP _JniServiceDiedBP;
	FTbSame2JniServiceDiedDelegate _JniServiceDied;

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif
	void OnSig1Signal(const FTbSame2Struct1& Param1) override;

	void OnSig2Signal(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;

	void OnProp1Changed(const FTbSame2Struct2& Prop1) override;
	void OnProp2Changed(const FTbSame2Struct2& Prop2) override;
	// Returns a copy of current backend. Backend may get changed from main thread.
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> getBackendServiceForJNI() const override;
	void jniServiceStatusChanged(bool isConnected) override;

	mutable FCriticalSection BackendServiceCS;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame2|SameStruct2Interface")
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> BackendService;
};
