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

#include "Testbed1/Generated/api/Testbed1StructArrayInterfaceInterface.h"
#include "Testbed1/Generated/api/AbstractTestbed1StructArrayInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed1/Generated/Jni/Testbed1JniConnectionStatus.h"
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

#include "Testbed1StructArrayInterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructArrayInterfaceClient_JNI, Log, All);

// A helper class that exposes part of UTestbed1StructArrayInterfaceJniClient to use for native JNI calls.
// The usage of it should allow thread safe access to set properties and broadcasting singals,
// since all JNI native calls are made from JNI thread.
// The difference from already provided subscirber interface is that it does not expose the functions to blueprints use.
class TESTBED1JNI_API IUTestbed1StructArrayInterfaceJniClientJniAccessor
{
public:
	virtual void OnSigBoolSignal(const TArray<FTestbed1StructBool>& ParamBool) = 0;

	virtual void OnSigIntSignal(const TArray<FTestbed1StructInt>& ParamInt) = 0;

	virtual void OnSigFloatSignal(const TArray<FTestbed1StructFloat>& ParamFloat) = 0;

	virtual void OnSigStringSignal(const TArray<FTestbed1StructString>& ParamString) = 0;

	virtual void OnSigEnumSignal(const TArray<ETestbed1Enum0>& ParamEnum) = 0;

	virtual void OnPropBoolChanged(const TArray<FTestbed1StructBool>& PropBool) = 0;

	virtual void OnPropIntChanged(const TArray<FTestbed1StructInt>& PropInt) = 0;

	virtual void OnPropFloatChanged(const TArray<FTestbed1StructFloat>& PropFloat) = 0;

	virtual void OnPropStringChanged(const TArray<FTestbed1StructString>& PropString) = 0;

	virtual void OnPropEnumChanged(const TArray<ETestbed1Enum0>& PropEnum) = 0;
	virtual void notifyIsReady(bool isReady) = 0;
};

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1JNI_API UTestbed1StructArrayInterfaceJniClient : public UAbstractTestbed1StructArrayInterface, public IUTestbed1StructArrayInterfaceJniClientJniAccessor
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructArrayInterfaceJniClient();

	UTestbed1StructArrayInterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTestbed1StructArrayInterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	TArray<FTestbed1StructBool> GetPropBool() const override;
	void SetPropBool(const TArray<FTestbed1StructBool>& InPropBool) override;
	TArray<FTestbed1StructInt> GetPropInt() const override;
	void SetPropInt(const TArray<FTestbed1StructInt>& InPropInt) override;
	TArray<FTestbed1StructFloat> GetPropFloat() const override;
	void SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat) override;
	TArray<FTestbed1StructString> GetPropString() const override;
	void SetPropString(const TArray<FTestbed1StructString>& InPropString) override;
	TArray<ETestbed1Enum0> GetPropEnum() const override;
	void SetPropEnum(const TArray<ETestbed1Enum0>& InPropEnum) override;

	// operations
	virtual TArray<FTestbed1StructBool> FuncBool(const TArray<FTestbed1StructBool>& ParamBool) override;
	TFuture<TArray<FTestbed1StructBool>> FuncBoolAsync(const TArray<FTestbed1StructBool>& ParamBool) override;
	virtual TArray<FTestbed1StructInt> FuncInt(const TArray<FTestbed1StructInt>& ParamInt) override;
	TFuture<TArray<FTestbed1StructInt>> FuncIntAsync(const TArray<FTestbed1StructInt>& ParamInt) override;
	virtual TArray<FTestbed1StructFloat> FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat) override;
	TFuture<TArray<FTestbed1StructFloat>> FuncFloatAsync(const TArray<FTestbed1StructFloat>& ParamFloat) override;
	virtual TArray<FTestbed1StructString> FuncString(const TArray<FTestbed1StructString>& ParamString) override;
	TFuture<TArray<FTestbed1StructString>> FuncStringAsync(const TArray<FTestbed1StructString>& ParamString) override;
	virtual TArray<ETestbed1Enum0> FuncEnum(const TArray<ETestbed1Enum0>& ParamEnum) override;
	TFuture<TArray<ETestbed1Enum0>> FuncEnumAsync(const TArray<ETestbed1Enum0>& ParamEnum) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTestbed1JniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTestbed1JniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a StructArrayInterface Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|JNI|Connection")
	void _unbind();

private:
	void OnSigBoolSignal(const TArray<FTestbed1StructBool>& InParamBool) override;

	void OnSigIntSignal(const TArray<FTestbed1StructInt>& InParamInt) override;

	void OnSigFloatSignal(const TArray<FTestbed1StructFloat>& InParamFloat) override;

	void OnSigStringSignal(const TArray<FTestbed1StructString>& InParamString) override;

	void OnSigEnumSignal(const TArray<ETestbed1Enum0>& InParamEnum) override;

	void OnPropBoolChanged(const TArray<FTestbed1StructBool>& InPropBool) override;

	void OnPropIntChanged(const TArray<FTestbed1StructInt>& InPropInt) override;

	void OnPropFloatChanged(const TArray<FTestbed1StructFloat>& InPropFloat) override;

	void OnPropStringChanged(const TArray<FTestbed1StructString>& InPropString) override;

	void OnPropEnumChanged(const TArray<ETestbed1Enum0>& InPropEnum) override;

#if PLATFORM_ANDROID && USE_ANDROID_JNI
	bool tryCallAsyncJavaFuncBool(FGuid Guid, jmethodID MethodId, const TArray<FTestbed1StructBool>& InParamBool);

	bool tryCallAsyncJavaFuncInt(FGuid Guid, jmethodID MethodId, const TArray<FTestbed1StructInt>& InParamInt);

	bool tryCallAsyncJavaFuncFloat(FGuid Guid, jmethodID MethodId, const TArray<FTestbed1StructFloat>& InParamFloat);

	bool tryCallAsyncJavaFuncString(FGuid Guid, jmethodID MethodId, const TArray<FTestbed1StructString>& InParamString);

	bool tryCallAsyncJavaFuncEnum(FGuid Guid, jmethodID MethodId, const TArray<ETestbed1Enum0>& InParamEnum);
#endif
	void notifyIsReady(bool isReady) override;

	std::atomic<bool> b_isReady{false};
	FString m_lastBoundServicePackage;
	FString m_lastConnectionId;
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	jobject m_javaJniClientInstance = nullptr;
#endif
};
