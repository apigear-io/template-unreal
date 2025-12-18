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

#include "Testbed1/Generated/api/Testbed1StructArray2InterfaceInterface.h"
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

#include "Testbed1StructArray2InterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructArray2Interface_JNI, Log, All);

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITestbed1StructArray2InterfaceInterface
 */
UCLASS(BlueprintType)
class TESTBED1JNI_API UTestbed1StructArray2InterfaceJniAdapter : public UGameInstanceSubsystem, public ITestbed1StructArray2InterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructArray2InterfaceJniAdapter();
	virtual ~UTestbed1StructArray2InterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface")
	void setBackendService(TScriptInterface<ITestbed1StructArray2InterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface")
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> getBackendService();

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif
	void OnSigBoolSignal(const FTestbed1StructBoolWithArray& ParamBool) override;

	void OnSigIntSignal(const FTestbed1StructIntWithArray& ParamInt) override;

	void OnSigFloatSignal(const FTestbed1StructFloatWithArray& ParamFloat) override;

	void OnSigStringSignal(const FTestbed1StructStringWithArray& ParamString) override;

	void OnPropBoolChanged(const FTestbed1StructBoolWithArray& PropBool) override;
	void OnPropIntChanged(const FTestbed1StructIntWithArray& PropInt) override;
	void OnPropFloatChanged(const FTestbed1StructFloatWithArray& PropFloat) override;
	void OnPropStringChanged(const FTestbed1StructStringWithArray& PropString) override;
	void OnPropEnumChanged(const FTestbed1StructEnumWithArray& PropEnum) override;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructArray2Interface")
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> BackendService;
};
