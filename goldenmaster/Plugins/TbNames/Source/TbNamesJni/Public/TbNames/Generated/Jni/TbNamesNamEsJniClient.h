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

#include "TbNames/Generated/api/TbNamesNamEsInterface.h"
#include "TbNames/Generated/api/AbstractTbNamesNamEs.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbNames/Generated/Jni/TbNamesJniConnectionStatus.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "TbNamesNamEsJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbNamesNamEsClient_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBNAMESJNI_API UTbNamesNamEsJniClient : public UAbstractTbNamesNamEs
{
	GENERATED_BODY()
public:
	explicit UTbNamesNamEsJniClient();

	UTbNamesNamEsJniClient(FVTableHelper& Helper);
	virtual ~UTbNamesNamEsJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	bool GetSwitch() const override;
	void SetSwitch(bool bInSwitch) override;
	int32 GetSomeProperty() const override;
	void SetSomeProperty(int32 InSomeProperty) override;
	int32 GetSomePoperty2() const override;
	void SetSomePoperty2(int32 InSomePoperty2) override;
	ETbNamesEnum_With_Under_scores GetEnumProperty() const override;
	void SetEnumProperty(ETbNamesEnum_With_Under_scores InEnumProperty) override;

	// operations
	virtual void SomeFunction(bool bSomeParam) override;
	virtual void SomeFunction2(bool bSomeParam) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbNamesJniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbNamesJniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|JNI")
	bool _IsReady() const;

	/**
	* @param package. This client will connect only to a NamEs Service, that myb be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|JNI|Connection")
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
