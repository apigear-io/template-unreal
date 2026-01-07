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

#include "Testbed1/Generated/api/Testbed1StructArray2InterfaceInterface.h"
#include "Testbed1/Generated/api/AbstractTestbed1StructArray2Interface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed1/Generated/Jni/Testbed1JniConnectionStatus.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "Testbed1StructArray2InterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructArray2InterfaceClient_JNI, Log, All);

// A helper class that exposes part of UTestbed1StructArray2InterfaceJniClient to use for native JNI calls.
// The usage of it should allow thread safe access to set properties and broadcasting singals,
// since all JNI native calls are made from JNI thread.
// The difference from already provided subscirber interface is that it does not expose the functions to blueprints use.
class TESTBED1JNI_API IUTestbed1StructArray2InterfaceJniClientJniAccessor
{
public:
	virtual void OnSigBoolSignal(const FTestbed1StructBoolWithArray& ParamBool) = 0;

	virtual void OnSigIntSignal(const FTestbed1StructIntWithArray& ParamInt) = 0;

	virtual void OnSigFloatSignal(const FTestbed1StructFloatWithArray& ParamFloat) = 0;

	virtual void OnSigStringSignal(const FTestbed1StructStringWithArray& ParamString) = 0;

	virtual void OnPropBoolChanged(const FTestbed1StructBoolWithArray& PropBool) = 0;

	virtual void OnPropIntChanged(const FTestbed1StructIntWithArray& PropInt) = 0;

	virtual void OnPropFloatChanged(const FTestbed1StructFloatWithArray& PropFloat) = 0;

	virtual void OnPropStringChanged(const FTestbed1StructStringWithArray& PropString) = 0;

	virtual void OnPropEnumChanged(const FTestbed1StructEnumWithArray& PropEnum) = 0;
	virtual void notifyIsReady(bool isReady) = 0;
};

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1JNI_API UTestbed1StructArray2InterfaceJniClient : public UAbstractTestbed1StructArray2Interface, public IUTestbed1StructArray2InterfaceJniClientJniAccessor
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructArray2InterfaceJniClient();

	UTestbed1StructArray2InterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTestbed1StructArray2InterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	FTestbed1StructBoolWithArray GetPropBool() const override;
	void SetPropBool(const FTestbed1StructBoolWithArray& InPropBool) override;
	FTestbed1StructIntWithArray GetPropInt() const override;
	void SetPropInt(const FTestbed1StructIntWithArray& InPropInt) override;
	FTestbed1StructFloatWithArray GetPropFloat() const override;
	void SetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat) override;
	FTestbed1StructStringWithArray GetPropString() const override;
	void SetPropString(const FTestbed1StructStringWithArray& InPropString) override;
	FTestbed1StructEnumWithArray GetPropEnum() const override;
	void SetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum) override;

	// operations
	virtual TArray<FTestbed1StructBool> FuncBool(const FTestbed1StructBoolWithArray& ParamBool) override;
	virtual TArray<FTestbed1StructInt> FuncInt(const FTestbed1StructIntWithArray& ParamInt) override;
	virtual TArray<FTestbed1StructFloat> FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat) override;
	virtual TArray<FTestbed1StructString> FuncString(const FTestbed1StructStringWithArray& ParamString) override;
	virtual TArray<ETestbed1Enum0> FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTestbed1JniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTestbed1JniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a StructArray2Interface Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|JNI|Connection")
	void _unbind();

private:
	void OnSigBoolSignal(const FTestbed1StructBoolWithArray& InParamBool) override;

	void OnSigIntSignal(const FTestbed1StructIntWithArray& InParamInt) override;

	void OnSigFloatSignal(const FTestbed1StructFloatWithArray& InParamFloat) override;

	void OnSigStringSignal(const FTestbed1StructStringWithArray& InParamString) override;

	void OnPropBoolChanged(const FTestbed1StructBoolWithArray& InPropBool) override;

	void OnPropIntChanged(const FTestbed1StructIntWithArray& InPropInt) override;

	void OnPropFloatChanged(const FTestbed1StructFloatWithArray& InPropFloat) override;

	void OnPropStringChanged(const FTestbed1StructStringWithArray& InPropString) override;

	void OnPropEnumChanged(const FTestbed1StructEnumWithArray& InPropEnum) override;
	void notifyIsReady(bool isReady) override;

	std::atomic<bool> b_isReady{false};
	FString m_lastBoundServicePackage;
	FString m_lastConnectionId;
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	jobject m_javaJniClientInstance = nullptr;
#endif
};
