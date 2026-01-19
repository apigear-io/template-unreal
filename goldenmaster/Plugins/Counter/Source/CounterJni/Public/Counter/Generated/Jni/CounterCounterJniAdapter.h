/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "Counter/Generated/api/CounterCounterInterface.h"
#include "Counter/Generated/Jni/CounterJniConnectionStatus.h"
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

#include "CounterCounterJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCounterCounter_JNI, Log, All);

// Helper interface to expose necessary functions for native Jni function implementations.
// Main purpose is to allow it in a thread safe way, the native JNI calls are always from JNI thread.
class ICounterCounterJniAdapterAccessor
{
public:
	virtual ~ICounterCounterJniAdapterAccessor() = default;
	virtual TScriptInterface<ICounterCounterInterface> getBackendServiceForJNI() const = 0;
	virtual void jniServiceStatusChanged(bool) = 0;
};

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ICounterCounterInterface
 */
UCLASS(BlueprintType)
class COUNTERJNI_API UCounterCounterJniAdapter : public UGameInstanceSubsystem, public ICounterCounterSubscriberInterface, public ICounterCounterJniAdapterAccessor
{
public:
	GENERATED_BODY()

	explicit UCounterCounterJniAdapter();
	virtual ~UCounterCounterJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter")
	void setBackendService(TScriptInterface<ICounterCounterInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter")
	TScriptInterface<ICounterCounterInterface> getBackendService();

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Jni|Remote", DisplayName = "Jni Service Started")
	FCounterJniServiceStartedDelegateBP _JniServiceStartedBP;
	FCounterJniServiceStartedDelegate _JniServiceStarted;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Jni|Remote", DisplayName = "Jni Service Died")
	FCounterJniServiceDiedDelegateBP _JniServiceDiedBP;
	FCounterJniServiceDiedDelegate _JniServiceDied;

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif
	void OnValueChangedSignal(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray) override;

	void OnVectorChanged(const FCustomTypesVector3D& Vector) override;
	void OnExternVectorChanged(const FVector& ExternVector) override;
	void OnVectorArrayChanged(const TArray<FCustomTypesVector3D>& VectorArray) override;
	void OnExternVectorArrayChanged(const TArray<FVector>& ExternVectorArray) override;
	// Returns a copy of current backend. Backend may get changed from main thread.
	TScriptInterface<ICounterCounterInterface> getBackendServiceForJNI() const override;
	void jniServiceStatusChanged(bool isConnected) override;

	mutable FCriticalSection BackendServiceCS;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Counter|Counter")
	TScriptInterface<ICounterCounterInterface> BackendService;
};
