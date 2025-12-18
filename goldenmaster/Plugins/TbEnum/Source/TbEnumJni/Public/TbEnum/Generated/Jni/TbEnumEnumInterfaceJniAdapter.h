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

#include "TbEnum/Generated/api/TbEnumEnumInterfaceInterface.h"
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

#include "TbEnumEnumInterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbEnumEnumInterface_JNI, Log, All);

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbEnumEnumInterfaceInterface
 */
UCLASS(BlueprintType)
class TBENUMJNI_API UTbEnumEnumInterfaceJniAdapter : public UGameInstanceSubsystem, public ITbEnumEnumInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbEnumEnumInterfaceJniAdapter();
	virtual ~UTbEnumEnumInterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void setBackendService(TScriptInterface<ITbEnumEnumInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	TScriptInterface<ITbEnumEnumInterfaceInterface> getBackendService();

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif
	void OnSig0Signal(ETbEnumEnum0 Param0) override;

	void OnSig1Signal(ETbEnumEnum1 Param1) override;

	void OnSig2Signal(ETbEnumEnum2 Param2) override;

	void OnSig3Signal(ETbEnumEnum3 Param3) override;

	void OnProp0Changed(ETbEnumEnum0 Prop0) override;
	void OnProp1Changed(ETbEnumEnum1 Prop1) override;
	void OnProp2Changed(ETbEnumEnum2 Prop2) override;
	void OnProp3Changed(ETbEnumEnum3 Prop3) override;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbEnum|EnumInterface")
	TScriptInterface<ITbEnumEnumInterfaceInterface> BackendService;
};
