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

#include "Generated/api/AbstractTbNamesNamEs.h"
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
#include "TbNamesNamEsMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbNamesNamEsInitMessage;
struct FTbNamesNamEsServiceDisconnectMessage;
struct FTbNamesNamEsSomeSignalSignalMessage;
struct FTbNamesNamEsSomeSignal2SignalMessage;
struct FTbNamesNamEsSwitchChangedMessage;
struct FTbNamesNamEsSomePropertyChangedMessage;
struct FTbNamesNamEsSomePoperty2ChangedMessage;

struct TbNamesNamEsPropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbNamesNamEsMsgBusClient, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsConnectionStatusChangedDelegate, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBNAMES_API UTbNamesNamEsMsgBusClient : public UAbstractTbNamesNamEs
{
	GENERATED_BODY()
public:
	explicit UTbNamesNamEsMsgBusClient();
	virtual ~UTbNamesNamEsMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Remote")
	void Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Remote")
	void Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Remote")
	bool IsConnected() const;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Remote", DisplayName = "Connection Status Changed")
	FTbNamesNamEsConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	bool GetSwitch_Implementation() const override;
	void SetSwitch_Implementation(bool bSwitch) override;

	int32 GetSomeProperty_Implementation() const override;
	void SetSomeProperty_Implementation(int32 SomeProperty) override;

	int32 GetSomePoperty2_Implementation() const override;
	void SetSomePoperty2_Implementation(int32 SomePoperty2) override;

	// operations
	void SomeFunction_Implementation(bool bSomeParam) override;

	void SomeFunction2_Implementation(bool bSomeParam) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbNamesNamEsMsgBusEndpoint;

	void DiscoverService();
	FMessageAddress ServiceAddress;

	// connection handling
	void OnConnectionInit(const FTbNamesNamEsInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbNamesNamEsServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSomeSignal(const FTbNamesNamEsSomeSignalSignalMessage& InSomeSignalMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSomeSignal2(const FTbNamesNamEsSomeSignal2SignalMessage& InSomeSignal2Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSwitchChanged(const FTbNamesNamEsSwitchChangedMessage& bInSwitchMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSomePropertyChanged(const FTbNamesNamEsSomePropertyChangedMessage& InSomePropertyMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSomePoperty2Changed(const FTbNamesNamEsSomePoperty2ChangedMessage& InSomePoperty2Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbNamesNamEsPropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
