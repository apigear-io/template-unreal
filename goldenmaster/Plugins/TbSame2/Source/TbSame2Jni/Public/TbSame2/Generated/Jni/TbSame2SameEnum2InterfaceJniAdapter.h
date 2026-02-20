/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "TbSame2/Generated/api/TbSame2SameEnum2InterfaceInterface.h"
#include "TbSame2/Generated/Jni/TbSame2JniConnectionStatus.h"
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

#include "TbSame2SameEnum2InterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSame2SameEnum2Interface_JNI, Log, All);

// Helper interface to expose necessary functions for native Jni function implementations.
// Main purpose is to allow it in a thread safe way, the native JNI calls are always from JNI thread.
class ITbSame2SameEnum2InterfaceJniAdapterAccessor
{
public:
	virtual ~ITbSame2SameEnum2InterfaceJniAdapterAccessor() = default;
	virtual TScriptInterface<ITbSame2SameEnum2InterfaceInterface> getBackendServiceForJNI() const = 0;
	virtual void jniServiceStatusChanged(bool) = 0;
};

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbSame2SameEnum2InterfaceInterface
 */
UCLASS(BlueprintType)
class TBSAME2JNI_API UTbSame2SameEnum2InterfaceJniAdapter : public UGameInstanceSubsystem, public ITbSame2SameEnum2InterfaceSubscriberInterface, public ITbSame2SameEnum2InterfaceJniAdapterAccessor
{
public:
	GENERATED_BODY()

	explicit UTbSame2SameEnum2InterfaceJniAdapter();
	virtual ~UTbSame2SameEnum2InterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface")
	void setBackendService(TScriptInterface<ITbSame2SameEnum2InterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface")
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> getBackendService();

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface|Jni|Remote", DisplayName = "Jni Service Started")
	FTbSame2JniServiceStartedDelegateBP _JniServiceStartedBP;
	FTbSame2JniServiceStartedDelegate _JniServiceStarted;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface|Jni|Remote", DisplayName = "Jni Service Died")
	FTbSame2JniServiceDiedDelegateBP _JniServiceDiedBP;
	FTbSame2JniServiceDiedDelegate _JniServiceDied;

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif
	void OnSig1Signal(ETbSame2Enum1 Param1) override;

	void OnSig2Signal(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;

	void OnProp1Changed(ETbSame2Enum1 Prop1) override;
	void OnProp2Changed(ETbSame2Enum2 Prop2) override;
	// Returns a copy of current backend. Backend may get changed from main thread.
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> getBackendServiceForJNI() const override;
	void jniServiceStatusChanged(bool isConnected) override;

	mutable FCriticalSection BackendServiceCS;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame2|SameEnum2Interface")
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> BackendService;
};
