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

#include "Testbed2/Generated/api/Testbed2NestedStruct3InterfaceInterface.h"
#include "Testbed2/Generated/api/AbstractTestbed2NestedStruct3Interface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed2/Generated/Jni/Testbed2JniConnectionStatus.h"
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

#include "Testbed2NestedStruct3InterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2NestedStruct3InterfaceClient_JNI, Log, All);

// A helper class that exposes part of UTestbed2NestedStruct3InterfaceJniClient to use for native JNI calls.
// The usage of it should allow thread safe access to set properties and broadcasting singals,
// since all JNI native calls are made from JNI thread.
// The difference from already provided subscirber interface is that it does not expose the functions to blueprints use.
class TESTBED2JNI_API IUTestbed2NestedStruct3InterfaceJniClientJniAccessor
{
public:
	virtual void OnSig1Signal(const FTestbed2NestedStruct1& Param1) = 0;

	virtual void OnSig2Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;

	virtual void OnSig3Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) = 0;

	virtual void OnProp1Changed(const FTestbed2NestedStruct1& Prop1) = 0;

	virtual void OnProp2Changed(const FTestbed2NestedStruct2& Prop2) = 0;

	virtual void OnProp3Changed(const FTestbed2NestedStruct3& Prop3) = 0;
	virtual void notifyIsReady(bool isReady) = 0;
};

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED2JNI_API UTestbed2NestedStruct3InterfaceJniClient : public UAbstractTestbed2NestedStruct3Interface, public IUTestbed2NestedStruct3InterfaceJniClientJniAccessor
{
	GENERATED_BODY()
public:
	explicit UTestbed2NestedStruct3InterfaceJniClient();

	UTestbed2NestedStruct3InterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTestbed2NestedStruct3InterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	FTestbed2NestedStruct1 GetProp1() const override;
	void SetProp1(const FTestbed2NestedStruct1& InProp1) override;
	FTestbed2NestedStruct2 GetProp2() const override;
	void SetProp2(const FTestbed2NestedStruct2& InProp2) override;
	FTestbed2NestedStruct3 GetProp3() const override;
	void SetProp3(const FTestbed2NestedStruct3& InProp3) override;

	// operations
	virtual FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) override;
	virtual FTestbed2NestedStruct1 Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;
	virtual FTestbed2NestedStruct1 Func3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTestbed2JniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTestbed2JniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a NestedStruct3Interface Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|JNI|Connection")
	void _unbind();

private:
	void OnSig1Signal(const FTestbed2NestedStruct1& InParam1) override;

	void OnSig2Signal(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2) override;

	void OnSig3Signal(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2, const FTestbed2NestedStruct3& InParam3) override;

	void OnProp1Changed(const FTestbed2NestedStruct1& InProp1) override;

	void OnProp2Changed(const FTestbed2NestedStruct2& InProp2) override;

	void OnProp3Changed(const FTestbed2NestedStruct3& InProp3) override;

#if PLATFORM_ANDROID && USE_ANDROID_JNI
	bool tryCallAsyncJavaFunc1(FGuid Guid, jmethodID MethodId, const FTestbed2NestedStruct1& InParam1);

	bool tryCallAsyncJavaFunc2(FGuid Guid, jmethodID MethodId, const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2);

	bool tryCallAsyncJavaFunc3(FGuid Guid, jmethodID MethodId, const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2, const FTestbed2NestedStruct3& InParam3);
#endif
	void notifyIsReady(bool isReady) override;

	std::atomic<bool> b_isReady{false};
	FString m_lastBoundServicePackage;
	FString m_lastConnectionId;
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	jobject m_javaJniClientInstance = nullptr;
#endif
};
