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

#include "TbSimple/Generated/api/TbSimpleEmptyInterfaceInterface.h"
#include "TbSimple/Generated/api/AbstractTbSimpleEmptyInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSimple/Generated/Jni/TbSimpleJniConnectionStatus.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "TbSimpleEmptyInterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleEmptyInterfaceClient_JNI, Log, All);

// A helper class that exposes part of UTbSimpleEmptyInterfaceJniClient to use for native JNI calls.
// The usage of it should allow thread safe access to set properties and broadcasting singals,
// since all JNI native calls are made from JNI thread.
// The difference from already provided subscirber interface is that it does not expose the functions to blueprints use.
class TBSIMPLEJNI_API IUTbSimpleEmptyInterfaceJniClientJniAccessor
{
public:
	virtual void notifyIsReady(bool isReady) = 0;
};

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLEJNI_API UTbSimpleEmptyInterfaceJniClient : public UAbstractTbSimpleEmptyInterface, public IUTbSimpleEmptyInterfaceJniClientJniAccessor
{
	GENERATED_BODY()
public:
	explicit UTbSimpleEmptyInterfaceJniClient();

	UTbSimpleEmptyInterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTbSimpleEmptyInterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// operations

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|EmptyInterface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbSimpleJniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbSimpleJniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|EmptyInterface|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a EmptyInterface Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|EmptyInterface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|EmptyInterface|JNI|Connection")
	void _unbind();

private:
	void notifyIsReady(bool isReady) override;

	std::atomic<bool> b_isReady{false};
	FString m_lastBoundServicePackage;
	FString m_lastConnectionId;
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	jobject m_javaJniClientInstance = nullptr;
#endif
};
