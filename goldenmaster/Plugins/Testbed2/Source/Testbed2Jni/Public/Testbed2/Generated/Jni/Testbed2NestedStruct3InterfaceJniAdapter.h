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

#include "Testbed2/Generated/api/Testbed2NestedStruct3InterfaceInterface.h"
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

#include "Testbed2NestedStruct3InterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2NestedStruct3Interface_JNI, Log, All);

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITestbed2NestedStruct3InterfaceInterface
 */
UCLASS(BlueprintType)
class TESTBED2JNI_API UTestbed2NestedStruct3InterfaceJniAdapter : public UGameInstanceSubsystem, public ITestbed2NestedStruct3InterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed2NestedStruct3InterfaceJniAdapter();
	virtual ~UTestbed2NestedStruct3InterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	void setBackendService(TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> getBackendService();

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

	void OnSig2Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;

	void OnSig3Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) override;

	void OnProp1Changed(const FTestbed2NestedStruct1& Prop1) override;
	void OnProp2Changed(const FTestbed2NestedStruct2& Prop2) override;
	void OnProp3Changed(const FTestbed2NestedStruct3& Prop3) override;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> BackendService;
};
