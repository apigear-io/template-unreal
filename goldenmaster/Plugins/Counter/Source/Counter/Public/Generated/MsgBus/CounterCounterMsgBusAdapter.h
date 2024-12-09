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

#include "Generated/api/CounterCounterInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "CounterCounterMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FCounterCounterDiscoveryMessage;
struct FCounterCounterClientDisconnectMessage;
struct FCounterCounterValueChangedSignalMessage;
struct FCounterCounterSetVectorRequestMessage;
struct FCounterCounterVectorChangedMessage;

struct FCounterCounterSetExternVectorRequestMessage;
struct FCounterCounterExternVectorChangedMessage;

struct FCounterCounterSetVectorArrayRequestMessage;
struct FCounterCounterVectorArrayChangedMessage;

struct FCounterCounterSetExternVectorArrayRequestMessage;
struct FCounterCounterExternVectorArrayChangedMessage;
struct FCounterCounterIncrementRequestMessage;
struct FCounterCounterIncrementArrayRequestMessage;
struct FCounterCounterDecrementRequestMessage;
struct FCounterCounterDecrementArrayRequestMessage;

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ICounterCounterInterface
/// and holds the corresponding CounterCounterOLinkSource OLink source object
UCLASS(BlueprintType)
class COUNTER_API UCounterCounterMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UCounterCounterMsgBusAdapter();
	virtual ~UCounterCounterMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Remote")
	void StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Remote")
	void StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Remote")
	bool IsListening() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter")
	void setBackendService(TScriptInterface<ICounterCounterInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> CounterCounterMsgBusEndpoint;

	void OnNewClientDiscovered(const FCounterCounterDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FCounterCounterClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnIncrementRequest(const FCounterCounterIncrementRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnIncrementArrayRequest(const FCounterCounterIncrementArrayRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnDecrementRequest(const FCounterCounterDecrementRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnDecrementArrayRequest(const FCounterCounterDecrementArrayRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetVectorRequest(const FCounterCounterSetVectorRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetExternVectorRequest(const FCounterCounterSetExternVectorRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetVectorArrayRequest(const FCounterCounterSetVectorArrayRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetExternVectorArrayRequest(const FCounterCounterSetExternVectorArrayRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|Counter|Counter", BlueprintInternalUseOnly)
	void OnValueChanged(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray);

	UFUNCTION(Category = "ApiGear|Counter|Counter", BlueprintInternalUseOnly)
	void OnVectorChanged(const FCustomTypesVector3D& Vector);

	UFUNCTION(Category = "ApiGear|Counter|Counter", BlueprintInternalUseOnly)
	void OnExternVectorChanged(const FVector& ExternVector);

	UFUNCTION(Category = "ApiGear|Counter|Counter", BlueprintInternalUseOnly)
	void OnVectorArrayChanged(const TArray<FCustomTypesVector3D>& VectorArray);

	UFUNCTION(Category = "ApiGear|Counter|Counter", BlueprintInternalUseOnly)
	void OnExternVectorArrayChanged(const TArray<FVector>& ExternVectorArray);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Counter|Counter")
	TScriptInterface<ICounterCounterInterface> BackendService;

	TArray<FMessageAddress> ConnectedClients;
};
