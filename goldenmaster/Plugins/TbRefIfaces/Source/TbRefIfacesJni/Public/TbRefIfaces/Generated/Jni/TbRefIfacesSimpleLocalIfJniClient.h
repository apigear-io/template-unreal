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

#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "TbRefIfaces/Generated/api/AbstractTbRefIfacesSimpleLocalIf.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbRefIfaces/Generated/Jni/TbRefIfacesJniConnectionStatus.h"
#include <memory>
#include "Misc/Guid.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "TbRefIfacesSimpleLocalIfJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbRefIfacesSimpleLocalIfClient_JNI, Log, All);

// A helper class that exposes part of UTbRefIfacesSimpleLocalIfJniClient to use for native JNI calls.
// The usage of it should allow thread safe access to set properties and broadcasting singals,
// since all JNI native calls are made from JNI thread.
// The difference from already provided subscirber interface is that it does not expose the functions to blueprints use.
class TBREFIFACESJNI_API IUTbRefIfacesSimpleLocalIfJniClientJniAccessor
{
public:
	virtual void OnIntSignalSignal(int32 Param) = 0;

	virtual void OnIntPropertyChanged(int32 IntProperty) = 0;
	virtual void notifyIsReady(bool isReady) = 0;
};

UCLASS(NotBlueprintable, BlueprintType)
class TBREFIFACESJNI_API UTbRefIfacesSimpleLocalIfJniClient : public UAbstractTbRefIfacesSimpleLocalIf, public IUTbRefIfacesSimpleLocalIfJniClientJniAccessor
{
	GENERATED_BODY()
public:
	explicit UTbRefIfacesSimpleLocalIfJniClient();

	UTbRefIfacesSimpleLocalIfJniClient(FVTableHelper& Helper);
	virtual ~UTbRefIfacesSimpleLocalIfJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	int32 GetIntProperty() const override;
	void SetIntProperty(int32 InIntProperty) override;

	// operations
	virtual int32 IntMethod(int32 Param) override;
	TFuture<int32> IntMethodAsync(int32 Param) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbRefIfacesJniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbRefIfacesJniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a SimpleLocalIf Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|JNI|Connection")
	void _unbind();

private:
	void OnIntSignalSignal(int32 InParam) override;

	void OnIntPropertyChanged(int32 InIntProperty) override;

#if PLATFORM_ANDROID && USE_ANDROID_JNI
	bool tryCallAsyncJavaIntMethod(FGuid Guid, jmethodID MethodId, int32 InParam);
#endif
	void notifyIsReady(bool isReady) override;

	std::atomic<bool> b_isReady{false};
	FString m_lastBoundServicePackage;
	FString m_lastConnectionId;
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	jobject m_javaJniClientInstance = nullptr;
#endif
};
