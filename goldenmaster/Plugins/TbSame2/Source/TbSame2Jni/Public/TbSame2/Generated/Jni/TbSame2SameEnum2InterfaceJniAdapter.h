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

#include "TbSame2/Generated/api/TbSame2SameEnum2InterfaceInterface.h"
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


#include "TbSame2SameEnum2InterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSame2SameEnum2Interface_JNI, Log, All);


/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbSame2SameEnum2InterfaceInterface
 */
UCLASS(BlueprintType)
class TBSAME2JNI_API UTbSame2SameEnum2InterfaceJniAdapter : public UGameInstanceSubsystem, public ITbSame2SameEnum2InterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameEnum2InterfaceJniAdapter();
	virtual ~UTbSame2SameEnum2InterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface")
    void setBackendService(TScriptInterface<ITbSame2SameEnum2InterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface")
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> getBackendService();

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
	void OnSig1Signal(ETbSame2Enum1 Param1) override;

	void OnSig2Signal(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;

	void OnProp1Changed(ETbSame2Enum1 Prop1) override;
	void OnProp2Changed(ETbSame2Enum2 Prop2) override;


	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame2|SameEnum2Interface")
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> BackendService;
};
