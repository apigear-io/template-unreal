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

#include "TbRefIfaces/Generated/api/AbstractTbRefIfacesSimpleLocalIf.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "Templates/PimplPtr.h"
#include "IMessageContext.h"
#include "TbRefIfacesSimpleLocalIfMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbRefIfacesSimpleLocalIfInitMessage;
struct FTbRefIfacesSimpleLocalIfPongMessage;
struct FTbRefIfacesSimpleLocalIfServiceDisconnectMessage;
struct FTbRefIfacesSimpleLocalIfIntSignalSignalMessage;
struct FTbRefIfacesSimpleLocalIfIntPropertyChangedMessage;
struct FTbRefIfacesSimpleLocalIfIntMethodReplyMessage;

USTRUCT(BlueprintType)
struct FTbRefIfacesSimpleLocalIfStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesSimpleLocalIfStatsUpdatedDelegate, FTbRefIfacesSimpleLocalIfStats, Stats);

struct TbRefIfacesSimpleLocalIfPropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbRefIfacesSimpleLocalIfMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesSimpleLocalIfConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesSimpleLocalIfConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBREFIFACESMSGBUS_API UTbRefIfacesSimpleLocalIfMsgBusClient : public UAbstractTbRefIfacesSimpleLocalIf
{
	GENERATED_BODY()
public:
	explicit UTbRefIfacesSimpleLocalIfMsgBusClient();
	virtual ~UTbRefIfacesSimpleLocalIfMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote")
	const FTbRefIfacesSimpleLocalIfStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote", DisplayName = "Statistics Updated")
	FTbRefIfacesSimpleLocalIfStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote", DisplayName = "Connection Status Changed")
	FTbRefIfacesSimpleLocalIfConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbRefIfacesSimpleLocalIfConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	int32 GetIntProperty() const override;
	void SetIntProperty(int32 IntProperty) override;

	// operations
	int32 IntMethod(int32 Param) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbRefIfacesSimpleLocalIfMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbRefIfacesSimpleLocalIfStats Stats;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	void _OnHeartbeat();
	bool _OnHeartbeatTick(float DeltaTime);
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTbRefIfacesSimpleLocalIfInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbRefIfacesSimpleLocalIfPongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbRefIfacesSimpleLocalIfServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnIntSignal(const FTbRefIfacesSimpleLocalIfIntSignalSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnIntPropertyChanged(const FTbRefIfacesSimpleLocalIfIntPropertyChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnIntMethodReply(const FTbRefIfacesSimpleLocalIfIntMethodReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbRefIfacesSimpleLocalIfPropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
