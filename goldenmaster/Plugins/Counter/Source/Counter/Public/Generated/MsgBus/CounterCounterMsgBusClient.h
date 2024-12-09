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

#include "Generated/api/AbstractCounterCounter.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
#include "Templates/UniquePtr.h"
#else
#include "Templates/PimplPtr.h"
#endif
#include "IMessageContext.h"
#include "CounterCounterMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FCounterCounterInitMessage;
struct FCounterCounterServiceDisconnectMessage;
struct FCounterCounterValueChangedSignalMessage;
struct FCounterCounterVectorChangedMessage;
struct FCounterCounterExternVectorChangedMessage;
struct FCounterCounterVectorArrayChangedMessage;
struct FCounterCounterExternVectorArrayChangedMessage;
struct FCounterCounterIncrementReplyMessage;
struct FCounterCounterIncrementArrayReplyMessage;
struct FCounterCounterDecrementReplyMessage;
struct FCounterCounterDecrementArrayReplyMessage;

struct CounterCounterPropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogCounterCounterMsgBusClient, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCounterCounterConnectionStatusChangedDelegate, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class COUNTER_API UCounterCounterMsgBusClient : public UAbstractCounterCounter
{
	GENERATED_BODY()
public:
	explicit UCounterCounterMsgBusClient();
	virtual ~UCounterCounterMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Remote")
	void Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Remote")
	void Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Remote")
	bool IsConnected() const;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Remote", DisplayName = "Connection Status Changed")
	FCounterCounterConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	FCustomTypesVector3D GetVector_Implementation() const override;
	void SetVector_Implementation(const FCustomTypesVector3D& Vector) override;

	FVector GetExternVector_Implementation() const override;
	void SetExternVector_Implementation(const FVector& ExternVector) override;

	TArray<FCustomTypesVector3D> GetVectorArray_Implementation() const override;
	void SetVectorArray_Implementation(const TArray<FCustomTypesVector3D>& VectorArray) override;

	TArray<FVector> GetExternVectorArray_Implementation() const override;
	void SetExternVectorArray_Implementation(const TArray<FVector>& ExternVectorArray) override;

	// operations
	FVector Increment_Implementation(const FVector& Vec) override;

	TArray<FVector> IncrementArray_Implementation(const TArray<FVector>& Vec) override;

	FCustomTypesVector3D Decrement_Implementation(const FCustomTypesVector3D& Vec) override;

	TArray<FCustomTypesVector3D> DecrementArray_Implementation(const TArray<FCustomTypesVector3D>& Vec) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> CounterCounterMsgBusEndpoint;

	void DiscoverService();
	FMessageAddress ServiceAddress;

	// connection handling
	void OnConnectionInit(const FCounterCounterInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FCounterCounterServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnValueChanged(const FCounterCounterValueChangedSignalMessage& InValueChangedMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnVectorChanged(const FCounterCounterVectorChangedMessage& InVectorMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnExternVectorChanged(const FCounterCounterExternVectorChangedMessage& InExternVectorMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnVectorArrayChanged(const FCounterCounterVectorArrayChangedMessage& InVectorArrayMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnExternVectorArrayChanged(const FCounterCounterExternVectorArrayChangedMessage& InExternVectorArrayMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnIncrementReply(const FCounterCounterIncrementReplyMessage& InIncrementMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnIncrementArrayReply(const FCounterCounterIncrementArrayReplyMessage& InIncrementArrayMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnDecrementReply(const FCounterCounterDecrementReplyMessage& InDecrementMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnDecrementArrayReply(const FCounterCounterDecrementArrayReplyMessage& InDecrementArrayMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<CounterCounterPropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
