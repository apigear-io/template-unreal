/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "TbSimple/Generated/api/TbSimpleEmptyInterfaceInterface.h"
#include "TbSimple/Generated/Jni/TbSimpleJniConnectionStatus.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>
#include "HAL/Platform.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "HAL/CriticalSection.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "TbSimpleEmptyInterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleEmptyInterface_JNI, Log, All);

// Helper interface to expose necessary functions for native Jni function implementations.
// Main purpose is to allow it in a thread safe way, the native JNI calls are always from JNI thread.
class ITbSimpleEmptyInterfaceJniAdapterAccessor
{
public:
	virtual ~ITbSimpleEmptyInterfaceJniAdapterAccessor() = default;
	virtual TScriptInterface<ITbSimpleEmptyInterfaceInterface> getBackendServiceForJNI() const = 0;
	virtual void jniServiceStatusChanged(bool) = 0;
};

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbSimpleEmptyInterfaceInterface
 */
UCLASS(BlueprintType)
class TBSIMPLEJNI_API UTbSimpleEmptyInterfaceJniAdapter : public UGameInstanceSubsystem, public ITbSimpleEmptyInterfaceSubscriberInterface, public ITbSimpleEmptyInterfaceJniAdapterAccessor
{
public:
	GENERATED_BODY()

	explicit UTbSimpleEmptyInterfaceJniAdapter();
	virtual ~UTbSimpleEmptyInterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|EmptyInterface")
	void setBackendService(TScriptInterface<ITbSimpleEmptyInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|EmptyInterface")
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> getBackendService();

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|EmptyInterface|Jni|Remote", DisplayName = "Jni Service Started")
	FTbSimpleJniServiceStartedDelegateBP _JniServiceStartedBP;
	FTbSimpleJniServiceStartedDelegate _JniServiceStarted;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|EmptyInterface|Jni|Remote", DisplayName = "Jni Service Died")
	FTbSimpleJniServiceDiedDelegateBP _JniServiceDiedBP;
	FTbSimpleJniServiceDiedDelegate _JniServiceDied;

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif
	// Returns a copy of current backend. Backend may get changed from main thread.
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> getBackendServiceForJNI() const override;
	void jniServiceStatusChanged(bool isConnected) override;

	mutable FCriticalSection BackendServiceCS;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|EmptyInterface")
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> BackendService;
};
