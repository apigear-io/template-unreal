/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "Testbed2/Generated/api/Testbed2NestedStruct2InterfaceInterface.h"
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

#include "Testbed2NestedStruct2InterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2NestedStruct2Interface_JNI, Log, All);

// Helper interface to expose necessary functions for native Jni function implementations.
// Main purpose is to allow it in a thread safe way, the native JNI calls are always from JNI thread.
class ITestbed2NestedStruct2InterfaceJniAdapterAccessor
{
public:
	virtual ~ITestbed2NestedStruct2InterfaceJniAdapterAccessor() = default;
	virtual TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> getBackendServiceForJNI() const = 0;
	virtual void jniServiceStatusChanged(bool) = 0;
};

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITestbed2NestedStruct2InterfaceInterface
 */
UCLASS(BlueprintType)
class TESTBED2JNI_API UTestbed2NestedStruct2InterfaceJniAdapter : public UGameInstanceSubsystem, public ITestbed2NestedStruct2InterfaceSubscriberInterface, public ITestbed2NestedStruct2InterfaceJniAdapterAccessor
{
public:
	GENERATED_BODY()

	explicit UTestbed2NestedStruct2InterfaceJniAdapter();
	virtual ~UTestbed2NestedStruct2InterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	void setBackendService(TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> getBackendService();

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Jni|Remote", DisplayName = "Jni Service Started")
	FTestbed2JniServiceStartedDelegateBP _JniServiceStartedBP;
	FTestbed2JniServiceStartedDelegate _JniServiceStarted;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Jni|Remote", DisplayName = "Jni Service Died")
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

	void OnSig2Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;

	void OnProp1Changed(const FTestbed2NestedStruct1& Prop1) override;
	void OnProp2Changed(const FTestbed2NestedStruct2& Prop2) override;
	// Returns a copy of current backend. Backend may get changed from main thread.
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> getBackendServiceForJNI() const override;
	void jniServiceStatusChanged(bool isConnected) override;

	mutable FCriticalSection BackendServiceCS;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> BackendService;
};
