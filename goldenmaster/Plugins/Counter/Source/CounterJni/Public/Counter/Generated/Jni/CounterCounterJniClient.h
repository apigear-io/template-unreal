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

#include "Counter/Generated/api/CounterCounterInterface.h"
#include "Counter/Generated/api/AbstractCounterCounter.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Counter/Generated/Jni/CounterJniConnectionStatus.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "CounterCounterJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCounterCounterClient_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class COUNTERJNI_API UCounterCounterJniClient : public UAbstractCounterCounter
{
	GENERATED_BODY()
public:
	explicit UCounterCounterJniClient();

	UCounterCounterJniClient(FVTableHelper& Helper);
	virtual ~UCounterCounterJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	FCustomTypesVector3D GetVector() const override;
	void SetVector(const FCustomTypesVector3D& InVector) override;
	FVector GetExternVector() const override;
	void SetExternVector(const FVector& InExternVector) override;
	TArray<FCustomTypesVector3D> GetVectorArray() const override;
	void SetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray) override;
	TArray<FVector> GetExternVectorArray() const override;
	void SetExternVectorArray(const TArray<FVector>& InExternVectorArray) override;

	// operations
	virtual FVector Increment(const FVector& Vec) override;
	virtual TArray<FVector> IncrementArray(const TArray<FVector>& Vec) override;
	virtual FCustomTypesVector3D Decrement(const FCustomTypesVector3D& Vec) override;
	virtual TArray<FCustomTypesVector3D> DecrementArray(const TArray<FCustomTypesVector3D>& Vec) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Jni|Remote", DisplayName = "Connection Status Changed")
	FCounterJniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FCounterJniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a Counter Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|JNI|Connection")
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
