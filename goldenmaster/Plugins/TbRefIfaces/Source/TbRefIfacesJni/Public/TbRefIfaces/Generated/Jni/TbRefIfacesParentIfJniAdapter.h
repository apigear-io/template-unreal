/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "TbRefIfaces/Generated/api/TbRefIfacesParentIfInterface.h"
#include "TbRefIfaces/Generated/Jni/TbRefIfacesJniConnectionStatus.h"
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

#include "TbRefIfacesParentIfJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbRefIfacesParentIf_JNI, Log, All);

// Helper interface to expose necessary functions for native Jni function implementations.
// Main purpose is to allow it in a thread safe way, the native JNI calls are always from JNI thread.
class ITbRefIfacesParentIfJniAdapterAccessor
{
public:
	virtual ~ITbRefIfacesParentIfJniAdapterAccessor() = default;
	virtual TScriptInterface<ITbRefIfacesParentIfInterface> getBackendServiceForJNI() const = 0;
	virtual void jniServiceStatusChanged(bool) = 0;
};

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbRefIfacesParentIfInterface
 */
UCLASS(BlueprintType)
class TBREFIFACESJNI_API UTbRefIfacesParentIfJniAdapter : public UGameInstanceSubsystem, public ITbRefIfacesParentIfSubscriberInterface, public ITbRefIfacesParentIfJniAdapterAccessor
{
public:
	GENERATED_BODY()

	explicit UTbRefIfacesParentIfJniAdapter();
	virtual ~UTbRefIfacesParentIfJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf")
	void setBackendService(TScriptInterface<ITbRefIfacesParentIfInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf")
	TScriptInterface<ITbRefIfacesParentIfInterface> getBackendService();

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Jni|Remote", DisplayName = "Jni Service Started")
	FTbRefIfacesJniServiceStartedDelegateBP _JniServiceStartedBP;
	FTbRefIfacesJniServiceStartedDelegate _JniServiceStarted;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Jni|Remote", DisplayName = "Jni Service Died")
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
	void OnLocalIfSignalSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override;

	void OnLocalIfSignalListSignal(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) override;

	void OnImportedIfSignalSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override;

	void OnImportedIfSignalListSignal(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) override;

	void OnLocalIfChanged(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& LocalIf) override;
	void OnLocalIfListChanged(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& LocalIfList) override;
	void OnImportedIfChanged(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& ImportedIf) override;
	void OnImportedIfListChanged(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& ImportedIfList) override;
	// Returns a copy of current backend. Backend may get changed from main thread.
	TScriptInterface<ITbRefIfacesParentIfInterface> getBackendServiceForJNI() const override;
	void jniServiceStatusChanged(bool isConnected) override;

	mutable FCriticalSection BackendServiceCS;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefIfaces|ParentIf")
	TScriptInterface<ITbRefIfacesParentIfInterface> BackendService;
};
