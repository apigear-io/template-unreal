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

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1JNI_API UTestbed1StructInterfaceJniClient : public UAbstractTestbed1StructInterface
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
	virtual FTestbed1StructInt FuncInt(const FTestbed1StructInt& ParamInt) override;
	virtual FTestbed1StructFloat FuncFloat(const FTestbed1StructFloat& ParamFloat) override;
	virtual FTestbed1StructString FuncString(const FTestbed1StructString& ParamString) override;

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
	bool b_isReady = false;
	FString m_lastBoundServicePackage;
	FString m_lastConnectionId;
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	jobject m_javaJniClientInstance = nullptr;
#endif
};
