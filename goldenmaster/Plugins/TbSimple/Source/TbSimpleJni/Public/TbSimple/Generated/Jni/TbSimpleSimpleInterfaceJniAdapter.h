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

#include "TbSimple/Generated/api/TbSimpleSimpleInterfaceInterface.h"
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

#include "TbSimpleSimpleInterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleSimpleInterface_JNI, Log, All);

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbSimpleSimpleInterfaceInterface
 */
UCLASS(BlueprintType)
class TBSIMPLEJNI_API UTbSimpleSimpleInterfaceJniAdapter : public UGameInstanceSubsystem, public ITbSimpleSimpleInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleInterfaceJniAdapter();
	virtual ~UTbSimpleSimpleInterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void setBackendService(TScriptInterface<ITbSimpleSimpleInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> getBackendService();

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif
	void OnSigBoolSignal(bool bParamBool) override;

	void OnSigIntSignal(int32 ParamInt) override;

	void OnSigInt32Signal(int32 ParamInt32) override;

	void OnSigInt64Signal(int64 ParamInt64) override;

	void OnSigFloatSignal(float ParamFloat) override;

	void OnSigFloat32Signal(float ParamFloat32) override;

	void OnSigFloat64Signal(double ParamFloat64) override;

	void OnSigStringSignal(const FString& ParamString) override;

	void OnPropBoolChanged(bool bPropBool) override;
	void OnPropIntChanged(int32 PropInt) override;
	void OnPropInt32Changed(int32 PropInt32) override;
	void OnPropInt64Changed(int64 PropInt64) override;
	void OnPropFloatChanged(float PropFloat) override;
	void OnPropFloat32Changed(float PropFloat32) override;
	void OnPropFloat64Changed(double PropFloat64) override;
	void OnPropStringChanged(const FString& PropString) override;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|SimpleInterface")
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> BackendService;
};
