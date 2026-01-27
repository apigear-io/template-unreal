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

#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "TbRefIfaces/Generated/Jni/TbRefIfacesJniConnectionStatus.h"
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

#include "TbRefIfacesSimpleLocalIfJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbRefIfacesSimpleLocalIf_JNI, Log, All);

// Helper interface to expose necessary functions for native Jni function implementations.
// Main purpose is to allow it in a thread safe way, the native JNI calls are always from JNI thread.
class ITbRefIfacesSimpleLocalIfJniAdapterAccessor
{
public:
	virtual ~ITbRefIfacesSimpleLocalIfJniAdapterAccessor() = default;
	virtual TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> getBackendServiceForJNI() const = 0;
	virtual void jniServiceStatusChanged(bool) = 0;
};

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbRefIfacesSimpleLocalIfInterface
 */
UCLASS(BlueprintType)
class TBREFIFACESJNI_API UTbRefIfacesSimpleLocalIfJniAdapter : public UGameInstanceSubsystem, public ITbRefIfacesSimpleLocalIfSubscriberInterface, public ITbRefIfacesSimpleLocalIfJniAdapterAccessor
{
public:
	GENERATED_BODY()

	explicit UTbRefIfacesSimpleLocalIfJniAdapter();
	virtual ~UTbRefIfacesSimpleLocalIfJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf")
	void setBackendService(TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf")
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> getBackendService();

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Jni|Remote", DisplayName = "Jni Service Started")
	FTbRefIfacesJniServiceStartedDelegateBP _JniServiceStartedBP;
	FTbRefIfacesJniServiceStartedDelegate _JniServiceStarted;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Jni|Remote", DisplayName = "Jni Service Died")
	FTbRefIfacesJniServiceDiedDelegateBP _JniServiceDiedBP;
	FTbRefIfacesJniServiceDiedDelegate _JniServiceDied;

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif
	void OnIntSignalSignal(int32 Param) override;

	void OnIntPropertyChanged(int32 IntProperty) override;
	// Returns a copy of current backend. Backend may get changed from main thread.
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> getBackendServiceForJNI() const override;
	void jniServiceStatusChanged(bool isConnected) override;

	mutable FCriticalSection BackendServiceCS;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefIfaces|SimpleLocalIf")
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> BackendService;
};
