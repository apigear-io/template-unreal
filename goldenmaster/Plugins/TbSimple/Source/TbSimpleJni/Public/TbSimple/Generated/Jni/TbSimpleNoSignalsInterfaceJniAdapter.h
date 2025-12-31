/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "TbSimple/Generated/api/TbSimpleNoSignalsInterfaceInterface.h"
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

#include "TbSimpleNoSignalsInterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleNoSignalsInterface_JNI, Log, All);

// Helper interface to expose necessary functions for native Jni function implementations.
// Main purpose is to allow it in a thread safe way, the native JNI calls are always from JNI thread.
class ITbSimpleNoSignalsInterfaceJniAdapterAccessor
{
public:
	virtual ~ITbSimpleNoSignalsInterfaceJniAdapterAccessor() = default;
	virtual TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> getBackendServiceForJNI() const = 0;
};

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbSimpleNoSignalsInterfaceInterface
 */
UCLASS(BlueprintType)
class TBSIMPLEJNI_API UTbSimpleNoSignalsInterfaceJniAdapter : public UGameInstanceSubsystem, public ITbSimpleNoSignalsInterfaceSubscriberInterface, public ITbSimpleNoSignalsInterfaceJniAdapterAccessor
{
public:
	GENERATED_BODY()

	explicit UTbSimpleNoSignalsInterfaceJniAdapter();
	virtual ~UTbSimpleNoSignalsInterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface")
	void setBackendService(TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface")
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> getBackendService();

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif

	void OnPropBoolChanged(bool bPropBool) override;
	void OnPropIntChanged(int32 PropInt) override;
	// Returns a copy of current backend. Backend may get changed from main thread.
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> getBackendServiceForJNI() const override;

	mutable FCriticalSection BackendServiceCS;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|NoSignalsInterface")
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> BackendService;
};
