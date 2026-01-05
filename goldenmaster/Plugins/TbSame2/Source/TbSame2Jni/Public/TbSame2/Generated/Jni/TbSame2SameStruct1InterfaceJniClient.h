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

#include "TbSame2/Generated/api/TbSame2SameStruct1InterfaceInterface.h"
#include "TbSame2/Generated/api/AbstractTbSame2SameStruct1Interface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSame2/Generated/Jni/TbSame2JniConnectionStatus.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "TbSame2SameStruct1InterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSame2SameStruct1InterfaceClient_JNI, Log, All);

// A helper class that exposes part of UTbSame2SameStruct1InterfaceJniClient to use for native JNI calls.
// The usage of it should allow thread safe access to set properties and broadcasting singals,
// since all JNI native calls are made from JNI thread.
// The difference from already provided subscirber interface is that it does not expose the functions to blueprints use.
class TBSAME2JNI_API IUTbSame2SameStruct1InterfaceJniClientJniAccessor
{
public:
	virtual void OnSig1Signal(const FTbSame2Struct1& Param1) = 0;

	virtual void OnProp1Changed(const FTbSame2Struct1& Prop1) = 0;
	virtual void notifyIsReady(bool isReady) = 0;
};

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME2JNI_API UTbSame2SameStruct1InterfaceJniClient : public UAbstractTbSame2SameStruct1Interface, public IUTbSame2SameStruct1InterfaceJniClientJniAccessor
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameStruct1InterfaceJniClient();

	UTbSame2SameStruct1InterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTbSame2SameStruct1InterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	FTbSame2Struct1 GetProp1() const override;
	void SetProp1(const FTbSame2Struct1& InProp1) override;

	// operations
	virtual FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct1Interface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbSame2JniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbSame2JniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a SameStruct1Interface Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|JNI|Connection")
	void _unbind();

private:
	void OnSig1Signal(const FTbSame2Struct1& Param1) override;

	void OnProp1Changed(const FTbSame2Struct1& InProp1) override;
	void notifyIsReady(bool isReady) override;

	std::atomic<bool> b_isReady{false};
	FString m_lastBoundServicePackage;
	FString m_lastConnectionId;
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	jobject m_javaJniClientInstance = nullptr;
#endif
};
