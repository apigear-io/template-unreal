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

#include "Testbed2/Generated/api/Testbed2ManyParamInterfaceInterface.h"
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


#include "Testbed2ManyParamInterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2ManyParamInterface_JNI, Log, All);


/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITestbed2ManyParamInterfaceInterface
 */
UCLASS(BlueprintType)
class TESTBED2JNI_API UTestbed2ManyParamInterfaceJniAdapter : public UGameInstanceSubsystem, public ITestbed2ManyParamInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed2ManyParamInterfaceJniAdapter();
	virtual ~UTestbed2ManyParamInterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
    void setBackendService(TScriptInterface<ITestbed2ManyParamInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> getBackendService();

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
	void OnSig1Signal(int32 Param1) override;

	void OnSig2Signal(int32 Param1, int32 Param2) override;

	void OnSig3Signal(int32 Param1, int32 Param2, int32 Param3) override;

	void OnSig4Signal(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;

	void OnProp1Changed(int32 Prop1) override;
	void OnProp2Changed(int32 Prop2) override;
	void OnProp3Changed(int32 Prop3) override;
	void OnProp4Changed(int32 Prop4) override;


	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|ManyParamInterface")
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> BackendService;
};
