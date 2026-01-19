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

#include "Testbed1/Generated/api/Testbed1StructInterfaceInterface.h"
#include "Testbed1/Generated/Jni/Testbed1JniConnectionStatus.h"
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

#include "Testbed1StructInterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructInterface_JNI, Log, All);

// Helper interface to expose necessary functions for native Jni function implementations.
// Main purpose is to allow it in a thread safe way, the native JNI calls are always from JNI thread.
class ITestbed1StructInterfaceJniAdapterAccessor
{
public:
	virtual ~ITestbed1StructInterfaceJniAdapterAccessor() = default;
	virtual TScriptInterface<ITestbed1StructInterfaceInterface> getBackendServiceForJNI() const = 0;
	virtual void jniServiceStatusChanged(bool) = 0;
};

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITestbed1StructInterfaceInterface
 */
UCLASS(BlueprintType)
class TESTBED1JNI_API UTestbed1StructInterfaceJniAdapter : public UGameInstanceSubsystem, public ITestbed1StructInterfaceSubscriberInterface, public ITestbed1StructInterfaceJniAdapterAccessor
{
public:
	GENERATED_BODY()

	explicit UTestbed1StructInterfaceJniAdapter();
	virtual ~UTestbed1StructInterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void setBackendService(TScriptInterface<ITestbed1StructInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	TScriptInterface<ITestbed1StructInterfaceInterface> getBackendService();

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Jni|Remote", DisplayName = "Jni Service Started")
	FTestbed1JniServiceStartedDelegateBP _JniServiceStartedBP;
	FTestbed1JniServiceStartedDelegate _JniServiceStarted;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Jni|Remote", DisplayName = "Jni Service Died")
	FTestbed1JniServiceDiedDelegateBP _JniServiceDiedBP;
	FTestbed1JniServiceDiedDelegate _JniServiceDied;

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif
	void OnSigBoolSignal(const FTestbed1StructBool& ParamBool) override;

	void OnSigIntSignal(const FTestbed1StructInt& ParamInt) override;

	void OnSigFloatSignal(const FTestbed1StructFloat& ParamFloat) override;

	void OnSigStringSignal(const FTestbed1StructString& ParamString) override;

	void OnPropBoolChanged(const FTestbed1StructBool& PropBool) override;
	void OnPropIntChanged(const FTestbed1StructInt& PropInt) override;
	void OnPropFloatChanged(const FTestbed1StructFloat& PropFloat) override;
	void OnPropStringChanged(const FTestbed1StructString& PropString) override;
	// Returns a copy of current backend. Backend may get changed from main thread.
	TScriptInterface<ITestbed1StructInterfaceInterface> getBackendServiceForJNI() const override;
	void jniServiceStatusChanged(bool isConnected) override;

	mutable FCriticalSection BackendServiceCS;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructInterface")
	TScriptInterface<ITestbed1StructInterfaceInterface> BackendService;
};
