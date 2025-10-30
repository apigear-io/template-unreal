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

#include "TbSame1/Generated/api/TbSame1SameStruct2InterfaceInterface.h"
#include "TbSame1/Generated/api/AbstractTbSame1SameStruct2Interface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSame1/Generated/Jni/TbSame1JniConnectionStatus.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "TbSame1SameStruct2InterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSame1SameStruct2InterfaceClient_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME1JNI_API UTbSame1SameStruct2InterfaceJniClient : public UAbstractTbSame1SameStruct2Interface
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameStruct2InterfaceJniClient();

	UTbSame1SameStruct2InterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTbSame1SameStruct2InterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	FTbSame1Struct2 GetProp1() const override;
	void SetProp1(const FTbSame1Struct2& InProp1) override;
	FTbSame1Struct2 GetProp2() const override;
	void SetProp2(const FTbSame1Struct2& InProp2) override;

	// operations
	virtual FTbSame1Struct1 Func1(const FTbSame1Struct1& Param1) override;
	virtual FTbSame1Struct1 Func2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct2Interface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbSame1JniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbSame1JniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface|JNI")
	bool _IsReady() const;

	/**
	* @param package. This client will connect only to a SameStruct2Interface Service, that myb be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface|JNI|Connection")
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
