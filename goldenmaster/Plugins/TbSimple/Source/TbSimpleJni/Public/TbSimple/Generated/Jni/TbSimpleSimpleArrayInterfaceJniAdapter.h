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

#include "TbSimple/Generated/api/TbSimpleSimpleArrayInterfaceInterface.h"
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

#include "TbSimpleSimpleArrayInterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleSimpleArrayInterface_JNI, Log, All);

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbSimpleSimpleArrayInterfaceInterface
 */
UCLASS(BlueprintType)
class TBSIMPLEJNI_API UTbSimpleSimpleArrayInterfaceJniAdapter : public UGameInstanceSubsystem, public ITbSimpleSimpleArrayInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleArrayInterfaceJniAdapter();
	virtual ~UTbSimpleSimpleArrayInterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void setBackendService(TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> getBackendService();

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif
	void OnSigBoolSignal(const TArray<bool>& ParamBool) override;

	void OnSigIntSignal(const TArray<int32>& ParamInt) override;

	void OnSigInt32Signal(const TArray<int32>& ParamInt32) override;

	void OnSigInt64Signal(const TArray<int64>& ParamInt64) override;

	void OnSigFloatSignal(const TArray<float>& ParamFloat) override;

	void OnSigFloat32Signal(const TArray<float>& ParamFloa32) override;

	void OnSigFloat64Signal(const TArray<double>& ParamFloat64) override;

	void OnSigStringSignal(const TArray<FString>& ParamString) override;

	void OnPropBoolChanged(const TArray<bool>& PropBool) override;
	void OnPropIntChanged(const TArray<int32>& PropInt) override;
	void OnPropInt32Changed(const TArray<int32>& PropInt32) override;
	void OnPropInt64Changed(const TArray<int64>& PropInt64) override;
	void OnPropFloatChanged(const TArray<float>& PropFloat) override;
	void OnPropFloat32Changed(const TArray<float>& PropFloat32) override;
	void OnPropFloat64Changed(const TArray<double>& PropFloat64) override;
	void OnPropStringChanged(const TArray<FString>& PropString) override;
	void OnPropReadOnlyStringChanged(const FString& PropReadOnlyString) override;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> BackendService;
};
