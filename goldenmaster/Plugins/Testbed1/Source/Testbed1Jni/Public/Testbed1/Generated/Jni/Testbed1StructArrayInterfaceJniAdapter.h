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

#include "Testbed1/Generated/api/Testbed1StructArrayInterfaceInterface.h"
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

#include "Testbed1StructArrayInterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructArrayInterface_JNI, Log, All);

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITestbed1StructArrayInterfaceInterface
 */
UCLASS(BlueprintType)
class TESTBED1JNI_API UTestbed1StructArrayInterfaceJniAdapter : public UGameInstanceSubsystem, public ITestbed1StructArrayInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructArrayInterfaceJniAdapter();
	virtual ~UTestbed1StructArrayInterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	void setBackendService(TScriptInterface<ITestbed1StructArrayInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> getBackendService();

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
	void OnSigBoolSignal(const TArray<FTestbed1StructBool>& ParamBool) override;

	void OnSigIntSignal(const TArray<FTestbed1StructInt>& ParamInt) override;

	void OnSigFloatSignal(const TArray<FTestbed1StructFloat>& ParamFloat) override;

	void OnSigStringSignal(const TArray<FTestbed1StructString>& ParamString) override;

	void OnSigEnumSignal(const TArray<ETestbed1Enum0>& ParamEnum) override;

	void OnPropBoolChanged(const TArray<FTestbed1StructBool>& PropBool) override;
	void OnPropIntChanged(const TArray<FTestbed1StructInt>& PropInt) override;
	void OnPropFloatChanged(const TArray<FTestbed1StructFloat>& PropFloat) override;
	void OnPropStringChanged(const TArray<FTestbed1StructString>& PropString) override;
	void OnPropEnumChanged(const TArray<ETestbed1Enum0>& PropEnum) override;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructArrayInterface")
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> BackendService;
};
