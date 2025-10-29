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

#include "TbSimple/Generated/api/TbSimpleVoidInterfaceInterface.h"
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


#include "TbSimpleVoidInterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleVoidInterface_JNI, Log, All);


/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbSimpleVoidInterfaceInterface
 */
UCLASS(BlueprintType)
class TBSIMPLEJNI_API UTbSimpleVoidInterfaceJniAdapter : public UGameInstanceSubsystem, public ITbSimpleVoidInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleVoidInterfaceJniAdapter();
	virtual ~UTbSimpleVoidInterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|VoidInterface")
    void setBackendService(TScriptInterface<ITbSimpleVoidInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|VoidInterface")
	TScriptInterface<ITbSimpleVoidInterfaceInterface> getBackendService();

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
	void OnSigVoidSignal() override;


	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|VoidInterface")
	TScriptInterface<ITbSimpleVoidInterfaceInterface> BackendService;
};
