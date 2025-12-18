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

#include "TbNames/Generated/api/TbNamesNamEsInterface.h"
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

#include "TbNamesNamEsJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbNamesNamEs_JNI, Log, All);

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbNamesNamEsInterface
 */
UCLASS(BlueprintType)
class TBNAMESJNI_API UTbNamesNamEsJniAdapter : public UGameInstanceSubsystem, public ITbNamesNamEsSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbNamesNamEsJniAdapter();
	virtual ~UTbNamesNamEsJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs")
	void setBackendService(TScriptInterface<ITbNamesNamEsInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs")
	TScriptInterface<ITbNamesNamEsInterface> getBackendService();

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif
	void OnSomeSignalSignal(bool bSomeParam) override;

	void OnSomeSignal2Signal(bool bSomeParam) override;

	void OnSwitchChanged(bool bSwitch) override;
	void OnSomePropertyChanged(int32 SomeProperty) override;
	void OnSomePoperty2Changed(int32 SomePoperty2) override;
	void OnEnumPropertyChanged(ETbNamesEnum_With_Under_scores EnumProperty) override;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbNames|NamEs")
	TScriptInterface<ITbNamesNamEsInterface> BackendService;
};
