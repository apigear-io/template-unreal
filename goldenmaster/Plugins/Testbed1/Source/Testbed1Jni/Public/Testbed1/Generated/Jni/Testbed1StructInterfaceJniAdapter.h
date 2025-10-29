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

#include "Testbed1/Generated/api/Testbed1StructInterfaceInterface.h"
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


#include "Testbed1StructInterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructInterface_JNI, Log, All);


/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITestbed1StructInterfaceInterface
 */
UCLASS(BlueprintType)
class TESTBED1JNI_API UTestbed1StructInterfaceJniAdapter : public UGameInstanceSubsystem, public ITestbed1StructInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructInterfaceJniAdapter();
	virtual ~UTestbed1StructInterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
    void setBackendService(TScriptInterface<ITestbed1StructInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	TScriptInterface<ITestbed1StructInterfaceInterface> getBackendService();

private:

    //helper function, wraps calling java service side
    void callJniServiceReady(bool isServiceReady);

	// helper member;
#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	jclass m_javaJniServiceClass = nullptr;
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif

	// signals
	void OnSigBoolSignal(const FTestbed1StructBool& ParamBool) override;

	void OnSigIntSignal(const FTestbed1StructInt& ParamInt) override;

	void OnSigFloatSignal(const FTestbed1StructFloat& ParamFloat) override;

	void OnSigStringSignal(const FTestbed1StructString& ParamString) override;

	void OnPropBoolChanged(const FTestbed1StructBool& PropBool) override;
	void OnPropIntChanged(const FTestbed1StructInt& PropInt) override;
	void OnPropFloatChanged(const FTestbed1StructFloat& PropFloat) override;
	void OnPropStringChanged(const FTestbed1StructString& PropString) override;


	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructInterface")
	TScriptInterface<ITestbed1StructInterfaceInterface> BackendService;
};
