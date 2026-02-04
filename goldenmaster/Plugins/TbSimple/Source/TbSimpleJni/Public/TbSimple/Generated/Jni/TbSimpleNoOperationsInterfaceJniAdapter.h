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

#include "TbSimple/Generated/api/TbSimpleNoOperationsInterfaceInterface.h"
#include "TbSimple/Generated/Jni/TbSimpleJniConnectionStatus.h"
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

#include "TbSimpleNoOperationsInterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleNoOperationsInterface_JNI, Log, All);

// Helper interface to expose necessary functions for native Jni function implementations.
// Main purpose is to allow it in a thread safe way, the native JNI calls are always from JNI thread.
class ITbSimpleNoOperationsInterfaceJniAdapterAccessor
{
public:
	virtual ~ITbSimpleNoOperationsInterfaceJniAdapterAccessor() = default;
	virtual TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> getBackendServiceForJNI() const = 0;
	virtual void jniServiceStatusChanged(bool) = 0;
};

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbSimpleNoOperationsInterfaceInterface
 */
UCLASS(BlueprintType)
class TBSIMPLEJNI_API UTbSimpleNoOperationsInterfaceJniAdapter : public UGameInstanceSubsystem, public ITbSimpleNoOperationsInterfaceSubscriberInterface, public ITbSimpleNoOperationsInterfaceJniAdapterAccessor
{
public:
	GENERATED_BODY()

	explicit UTbSimpleNoOperationsInterfaceJniAdapter();
	virtual ~UTbSimpleNoOperationsInterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface")
	void setBackendService(TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface")
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> getBackendService();

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Jni|Remote", DisplayName = "Jni Service Started")
	FTbSimpleJniServiceStartedDelegateBP _JniServiceStartedBP;
	FTbSimpleJniServiceStartedDelegate _JniServiceStarted;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Jni|Remote", DisplayName = "Jni Service Died")
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
	void OnSigVoidSignal() override;

	void OnSigBoolSignal(bool bParamBool) override;

	void OnPropBoolChanged(bool bPropBool) override;
	void OnPropIntChanged(int32 PropInt) override;
	// Returns a copy of current backend. Backend may get changed from main thread.
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> getBackendServiceForJNI() const override;
	void jniServiceStatusChanged(bool isConnected) override;

	mutable FCriticalSection BackendServiceCS;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|NoOperationsInterface")
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> BackendService;
};
