/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "Testbed2/Generated/api/Testbed2NestedStruct1InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "Testbed2NestedStruct1InterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2NestedStruct1Interface_JNI, Log, All);

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITestbed2NestedStruct1InterfaceInterface
 */
UCLASS(BlueprintType)
class TESTBED2JNI_API UTestbed2NestedStruct1InterfaceJniAdapter : public UGameInstanceSubsystem, public ITestbed2NestedStruct1InterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed2NestedStruct1InterfaceJniAdapter();
	virtual ~UTestbed2NestedStruct1InterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	void setBackendService(TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> getBackendService();

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Class object of the used java service.
	jclass m_javaJniServiceClass = nullptr;
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif
	void OnSig1Signal(const FTestbed2NestedStruct1& Param1) override;

	void OnProp1Changed(const FTestbed2NestedStruct1& Prop1) override;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> BackendService;
};
