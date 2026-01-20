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

#include "Testbed1/Generated/api/Testbed1StructInterfaceInterface.h"
#include "Testbed1/Generated/api/AbstractTestbed1StructInterface.h"
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

#include "Testbed1StructInterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructInterfaceClient_JNI, Log, All);

// A helper class that exposes part of UTestbed1StructInterfaceJniClient to use for native JNI calls.
// The usage of it should allow thread safe access to set properties and broadcasting singals,
// since all JNI native calls are made from JNI thread.
// The difference from already provided subscirber interface is that it does not expose the functions to blueprints use.
class TESTBED1JNI_API IUTestbed1StructInterfaceJniClientJniAccessor
{
public:
	virtual void OnSigBoolSignal(const FTestbed1StructBool& ParamBool) = 0;

	virtual void OnSigIntSignal(const FTestbed1StructInt& ParamInt) = 0;

	virtual void OnSigFloatSignal(const FTestbed1StructFloat& ParamFloat) = 0;

	virtual void OnSigStringSignal(const FTestbed1StructString& ParamString) = 0;

	virtual void OnPropBoolChanged(const FTestbed1StructBool& PropBool) = 0;

	virtual void OnPropIntChanged(const FTestbed1StructInt& PropInt) = 0;

	virtual void OnPropFloatChanged(const FTestbed1StructFloat& PropFloat) = 0;

	virtual void OnPropStringChanged(const FTestbed1StructString& PropString) = 0;
	virtual void notifyIsReady(bool isReady) = 0;
};

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1JNI_API UTestbed1StructInterfaceJniClient : public UAbstractTestbed1StructInterface, public IUTestbed1StructInterfaceJniClientJniAccessor
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructInterfaceJniClient();

	UTestbed1StructInterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTestbed1StructInterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	FTestbed1StructBool GetPropBool() const override;
	void SetPropBool(const FTestbed1StructBool& InPropBool) override;
	FTestbed1StructInt GetPropInt() const override;
	void SetPropInt(const FTestbed1StructInt& InPropInt) override;
	FTestbed1StructFloat GetPropFloat() const override;
	void SetPropFloat(const FTestbed1StructFloat& InPropFloat) override;
	FTestbed1StructString GetPropString() const override;
	void SetPropString(const FTestbed1StructString& InPropString) override;

	// operations
	virtual FTestbed1StructBool FuncBool(const FTestbed1StructBool& ParamBool) override;
	TFuture<FTestbed1StructBool> FuncBoolAsync(const FTestbed1StructBool& ParamBool) override;
	virtual FTestbed1StructInt FuncInt(const FTestbed1StructInt& ParamInt) override;
	TFuture<FTestbed1StructInt> FuncIntAsync(const FTestbed1StructInt& ParamInt) override;
	virtual FTestbed1StructFloat FuncFloat(const FTestbed1StructFloat& ParamFloat) override;
	TFuture<FTestbed1StructFloat> FuncFloatAsync(const FTestbed1StructFloat& ParamFloat) override;
	virtual FTestbed1StructString FuncString(const FTestbed1StructString& ParamString) override;
	TFuture<FTestbed1StructString> FuncStringAsync(const FTestbed1StructString& ParamString) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTestbed1JniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTestbed1JniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a StructInterface Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|JNI|Connection")
	void _unbind();

private:
	void OnSigBoolSignal(const FTestbed1StructBool& InParamBool) override;

	void OnSigIntSignal(const FTestbed1StructInt& InParamInt) override;

	void OnSigFloatSignal(const FTestbed1StructFloat& InParamFloat) override;

	void OnSigStringSignal(const FTestbed1StructString& InParamString) override;

	void OnPropBoolChanged(const FTestbed1StructBool& InPropBool) override;

	void OnPropIntChanged(const FTestbed1StructInt& InPropInt) override;

	void OnPropFloatChanged(const FTestbed1StructFloat& InPropFloat) override;

	void OnPropStringChanged(const FTestbed1StructString& InPropString) override;

#if PLATFORM_ANDROID && USE_ANDROID_JNI
	bool tryCallAsyncJavaFuncBool(FGuid Guid, jmethodID MethodId, const FTestbed1StructBool& InParamBool);

	bool tryCallAsyncJavaFuncInt(FGuid Guid, jmethodID MethodId, const FTestbed1StructInt& InParamInt);

	bool tryCallAsyncJavaFuncFloat(FGuid Guid, jmethodID MethodId, const FTestbed1StructFloat& InParamFloat);

	bool tryCallAsyncJavaFuncString(FGuid Guid, jmethodID MethodId, const FTestbed1StructString& InParamString);
#endif
	void notifyIsReady(bool isReady) override;

	std::atomic<bool> b_isReady{false};
	FString m_lastBoundServicePackage;
	FString m_lastConnectionId;
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	jobject m_javaJniClientInstance = nullptr;
#endif
};
