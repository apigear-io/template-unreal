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

#include "Testbed2/Generated/api/Testbed2NestedStruct1InterfaceInterface.h"
#include "Testbed2/Generated/api/AbstractTestbed2NestedStruct1Interface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed2/Generated/Jni/Testbed2JniConnectionStatus.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "Testbed2NestedStruct1InterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2NestedStruct1InterfaceClient_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED2JNI_API UTestbed2NestedStruct1InterfaceJniClient : public UAbstractTestbed2NestedStruct1Interface
{
	GENERATED_BODY()
public:
	explicit UTestbed2NestedStruct1InterfaceJniClient();

	UTestbed2NestedStruct1InterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTestbed2NestedStruct1InterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	FTestbed2NestedStruct1 GetProp1() const override;
	void SetProp1(const FTestbed2NestedStruct1& InProp1) override;

	// operations
	virtual void FuncNoReturnValue(const FTestbed2NestedStruct1& Param1) override;
	virtual FTestbed2NestedStruct1 FuncNoParams() override;
	virtual FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTestbed2JniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTestbed2JniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a NestedStruct1Interface Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|JNI|Connection")
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
