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

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1JNI_API UTestbed1StructArray2InterfaceJniClient : public UAbstractTestbed1StructArray2Interface
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

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|JNI")
	bool _IsReady() const;

	/**
	* @param package. This client will connect only to a StructArray2Interface Service, that myb be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|JNI|Connection")
	void _unbind();
private:
	bool b_isReady = false;
	FString m_lastBoundServicePackage;
	FString m_lastConnectionId;
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	jclass m_javaJniClientClass = nullptr;
	jobject m_javaJniClientInstance = nullptr;
#endif
};
