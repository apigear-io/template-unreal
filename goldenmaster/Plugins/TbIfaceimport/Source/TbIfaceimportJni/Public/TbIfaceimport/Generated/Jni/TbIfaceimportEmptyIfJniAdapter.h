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

#include "TbIfaceimport/Generated/api/TbIfaceimportEmptyIfInterface.h"
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

#include "TbIfaceimportEmptyIfJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbIfaceimportEmptyIf_JNI, Log, All);

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbIfaceimportEmptyIfInterface
 */
UCLASS(BlueprintType)
class TBIFACEIMPORTJNI_API UTbIfaceimportEmptyIfJniAdapter : public UGameInstanceSubsystem, public ITbIfaceimportEmptyIfSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbIfaceimportEmptyIfJniAdapter();
	virtual ~UTbIfaceimportEmptyIfJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf")
	void setBackendService(TScriptInterface<ITbIfaceimportEmptyIfInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf")
	TScriptInterface<ITbIfaceimportEmptyIfInterface> getBackendService();

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbIfaceimport|EmptyIf")
	TScriptInterface<ITbIfaceimportEmptyIfInterface> BackendService;
};
