/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "TbSimple/Generated/api/TbSimpleVoidInterfaceInterface.h"
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

#include "TbSimpleVoidInterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleVoidInterface_JNI, Log, All);

// Helper interface to expose necessary functions for native Jni function implementations.
// Main purpose is to allow it in a thread safe way, the native JNI calls are always from JNI thread.
class ITbSimpleVoidInterfaceJniAdapterAccessor
{
public:
	virtual ~ITbSimpleVoidInterfaceJniAdapterAccessor() = default;
	virtual TScriptInterface<ITbSimpleVoidInterfaceInterface> getBackendServiceForJNI() const = 0;
};

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbSimpleVoidInterfaceInterface
 */
UCLASS(BlueprintType)
class TBSIMPLEJNI_API UTbSimpleVoidInterfaceJniAdapter : public UGameInstanceSubsystem, public ITbSimpleVoidInterfaceSubscriberInterface, public ITbSimpleVoidInterfaceJniAdapterAccessor
{
public:
	GENERATED_BODY()

	explicit UTbSimpleVoidInterfaceJniAdapter();
	virtual ~UTbSimpleVoidInterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|VoidInterface")
	void setBackendService(TScriptInterface<ITbSimpleVoidInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|VoidInterface")
	TScriptInterface<ITbSimpleVoidInterfaceInterface> getBackendService();

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
	// Returns a copy of current backend. Backend may get changed from main thread.
	TScriptInterface<ITbSimpleVoidInterfaceInterface> getBackendServiceForJNI() const override;

	mutable FCriticalSection BackendServiceCS;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|VoidInterface")
	TScriptInterface<ITbSimpleVoidInterfaceInterface> BackendService;
};
