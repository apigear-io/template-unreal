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

#include "TbSame1/Generated/api/TbSame1SameEnum2InterfaceInterface.h"
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

#include "TbSame1SameEnum2InterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSame1SameEnum2Interface_JNI, Log, All);

// Helper interface to expose necessary functions for native Jni function implementations.
// Main purpose is to allow it in a thread safe way, the native JNI calls are always from JNI thread.
class ITbSame1SameEnum2InterfaceJniAdapterAccessor
{
public:
	virtual ~ITbSame1SameEnum2InterfaceJniAdapterAccessor() = default;
	virtual TScriptInterface<ITbSame1SameEnum2InterfaceInterface> getBackendServiceForJNI() const = 0;
};

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbSame1SameEnum2InterfaceInterface
 */
UCLASS(BlueprintType)
class TBSAME1JNI_API UTbSame1SameEnum2InterfaceJniAdapter : public UGameInstanceSubsystem, public ITbSame1SameEnum2InterfaceSubscriberInterface, public ITbSame1SameEnum2InterfaceJniAdapterAccessor
{
public:
	GENERATED_BODY()

	explicit UTbSame1SameEnum2InterfaceJniAdapter();
	virtual ~UTbSame1SameEnum2InterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
	void setBackendService(TScriptInterface<ITbSame1SameEnum2InterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> getBackendService();

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif
	void OnSig1Signal(ETbSame1Enum1 Param1) override;

	void OnSig2Signal(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) override;

	void OnProp1Changed(ETbSame1Enum1 Prop1) override;
	void OnProp2Changed(ETbSame1Enum2 Prop2) override;
	// Returns a copy of current backend. Backend may get changed from main thread.
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> getBackendServiceForJNI() const override;

	mutable FCriticalSection BackendServiceCS;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame1|SameEnum2Interface")
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> BackendService;
};
