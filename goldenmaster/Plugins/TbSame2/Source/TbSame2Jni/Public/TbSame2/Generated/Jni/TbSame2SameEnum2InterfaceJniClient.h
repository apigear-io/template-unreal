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

#include "TbSame2/Generated/api/TbSame2SameEnum2InterfaceInterface.h"
#include "TbSame2/Generated/api/AbstractTbSame2SameEnum2Interface.h"
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

#include "TbSame2SameEnum2InterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSame2SameEnum2InterfaceClient_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME2JNI_API UTbSame2SameEnum2InterfaceJniClient : public UAbstractTbSame2SameEnum2Interface
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameEnum2InterfaceJniClient();

	UTbSame2SameEnum2InterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTbSame2SameEnum2InterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	ETbSame2Enum1 GetProp1() const override;
	void SetProp1(ETbSame2Enum1 InProp1) override;
	ETbSame2Enum2 GetProp2() const override;
	void SetProp2(ETbSame2Enum2 InProp2) override;

	// operations
	virtual ETbSame2Enum1 Func1(ETbSame2Enum1 Param1) override;
	virtual ETbSame2Enum1 Func2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbSame2JniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbSame2JniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a SameEnum2Interface Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|JNI|Connection")
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
