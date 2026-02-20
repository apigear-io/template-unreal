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

#include "TbSame1/Generated/api/TbSame1SameEnum2InterfaceInterface.h"
#include "TbSame1/Generated/api/AbstractTbSame1SameEnum2Interface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSame1/Generated/Jni/TbSame1JniConnectionStatus.h"
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

#include "TbSame1SameEnum2InterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSame1SameEnum2InterfaceClient_JNI, Log, All);

// A helper class that exposes part of UTbSame1SameEnum2InterfaceJniClient to use for native JNI calls.
// The usage of it should allow thread safe access to set properties and broadcasting singals,
// since all JNI native calls are made from JNI thread.
// The difference from already provided subscirber interface is that it does not expose the functions to blueprints use.
class TBSAME1JNI_API IUTbSame1SameEnum2InterfaceJniClientJniAccessor
{
public:
	virtual void OnSig1Signal(ETbSame1Enum1 Param1) = 0;

	virtual void OnSig2Signal(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) = 0;

	virtual void OnProp1Changed(ETbSame1Enum1 Prop1) = 0;

	virtual void OnProp2Changed(ETbSame1Enum2 Prop2) = 0;
	virtual void notifyIsReady(bool isReady) = 0;
};

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME1JNI_API UTbSame1SameEnum2InterfaceJniClient : public UAbstractTbSame1SameEnum2Interface, public IUTbSame1SameEnum2InterfaceJniClientJniAccessor
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameEnum2InterfaceJniClient();

	UTbSame1SameEnum2InterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTbSame1SameEnum2InterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	ETbSame1Enum1 GetProp1() const override;
	void SetProp1(ETbSame1Enum1 InProp1) override;
	ETbSame1Enum2 GetProp2() const override;
	void SetProp2(ETbSame1Enum2 InProp2) override;

	// operations
	virtual ETbSame1Enum1 Func1(ETbSame1Enum1 Param1) override;
	TFuture<ETbSame1Enum1> Func1Async(ETbSame1Enum1 Param1) override;
	virtual ETbSame1Enum1 Func2(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) override;
	TFuture<ETbSame1Enum1> Func2Async(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum2Interface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbSame1JniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbSame1JniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a SameEnum2Interface Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|JNI|Connection")
	void _unbind();

private:
	void OnSig1Signal(ETbSame1Enum1 InParam1) override;

	void OnSig2Signal(ETbSame1Enum1 InParam1, ETbSame1Enum2 InParam2) override;

	void OnProp1Changed(ETbSame1Enum1 InProp1) override;

	void OnProp2Changed(ETbSame1Enum2 InProp2) override;

#if PLATFORM_ANDROID && USE_ANDROID_JNI
	bool tryCallAsyncJavaFunc1(FGuid Guid, jmethodID MethodId, ETbSame1Enum1 InParam1);

	bool tryCallAsyncJavaFunc2(FGuid Guid, jmethodID MethodId, ETbSame1Enum1 InParam1, ETbSame1Enum2 InParam2);
#endif
	void notifyIsReady(bool isReady) override;

	std::atomic<bool> b_isReady{false};
	FString m_lastBoundServicePackage;
	FString m_lastConnectionId;
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	jobject m_javaJniClientInstance = nullptr;
#endif
};
