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

#include "Testbed2/Generated/api/Testbed2NestedStruct1InterfaceInterface.h"
#include "Testbed2/Generated/Jni/Testbed2JniConnectionStatus.h"
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

#include "Testbed2NestedStruct1InterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2NestedStruct1Interface_JNI, Log, All);

// Helper interface to expose necessary functions for native Jni function implementations.
// Main purpose is to allow it in a thread safe way, the native JNI calls are always from JNI thread.
class ITestbed2NestedStruct1InterfaceJniAdapterAccessor
{
public:
	virtual ~ITestbed2NestedStruct1InterfaceJniAdapterAccessor() = default;
	virtual TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> getBackendServiceForJNI() const = 0;
	virtual void jniServiceStatusChanged(bool) = 0;
};

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITestbed2NestedStruct1InterfaceInterface
 */
UCLASS(BlueprintType)
class TESTBED2JNI_API UTestbed2NestedStruct1InterfaceJniAdapter : public UGameInstanceSubsystem, public ITestbed2NestedStruct1InterfaceSubscriberInterface, public ITestbed2NestedStruct1InterfaceJniAdapterAccessor
{
public:
	GENERATED_BODY()

	explicit UTestbed2NestedStruct1InterfaceJniAdapter();
	virtual ~UTestbed2NestedStruct1InterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	void setBackendService(TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> getBackendService();

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Jni|Remote", DisplayName = "Jni Service Started")
	FTestbed2JniServiceStartedDelegateBP _JniServiceStartedBP;
	FTestbed2JniServiceStartedDelegate _JniServiceStarted;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Jni|Remote", DisplayName = "Jni Service Died")
	FTestbed2JniServiceDiedDelegateBP _JniServiceDiedBP;
	FTestbed2JniServiceDiedDelegate _JniServiceDied;

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif
	void OnSig1Signal(const FTestbed2NestedStruct1& Param1) override;

	void OnProp1Changed(const FTestbed2NestedStruct1& Prop1) override;
	// Returns a copy of current backend. Backend may get changed from main thread.
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> getBackendServiceForJNI() const override;
	void jniServiceStatusChanged(bool isConnected) override;

	mutable FCriticalSection BackendServiceCS;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> BackendService;
};
