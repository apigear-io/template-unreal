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

#include "TbRefIfaces/Generated/api/AbstractTbRefIfacesParentIf.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "Templates/PimplPtr.h"
#include "IMessageContext.h"
#include "TbRefIfacesParentIfMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbRefIfacesParentIfInitMessage;
struct FTbRefIfacesParentIfPongMessage;
struct FTbRefIfacesParentIfServiceDisconnectMessage;
struct FTbRefIfacesParentIfLocalIfSignalSignalMessage;
struct FTbRefIfacesParentIfLocalIfSignalListSignalMessage;
struct FTbRefIfacesParentIfImportedIfSignalSignalMessage;
struct FTbRefIfacesParentIfImportedIfSignalListSignalMessage;
struct FTbRefIfacesParentIfLocalIfChangedMessage;
struct FTbRefIfacesParentIfLocalIfListChangedMessage;
struct FTbRefIfacesParentIfImportedIfChangedMessage;
struct FTbRefIfacesParentIfImportedIfListChangedMessage;
struct FTbRefIfacesParentIfLocalIfMethodReplyMessage;
struct FTbRefIfacesParentIfLocalIfMethodListReplyMessage;
struct FTbRefIfacesParentIfImportedIfMethodReplyMessage;
struct FTbRefIfacesParentIfImportedIfMethodListReplyMessage;

USTRUCT(BlueprintType)
struct FTbRefIfacesParentIfStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefIfaces|ParentIf|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefIfaces|ParentIf|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefIfaces|ParentIf|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbRefIfaces|ParentIf|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfStatsUpdatedDelegate, FTbRefIfacesParentIfStats, Stats);

class TbRefIfacesParentIfPropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbRefIfacesParentIfMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBREFIFACESMSGBUS_API UTbRefIfacesParentIfMsgBusClient : public UAbstractTbRefIfacesParentIf
{
	GENERATED_BODY()
public:
	explicit UTbRefIfacesParentIfMsgBusClient();
	virtual ~UTbRefIfacesParentIfMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Remote")
	const FTbRefIfacesParentIfStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Remote", DisplayName = "Statistics Updated")
	FTbRefIfacesParentIfStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Remote", DisplayName = "Connection Status Changed")
	FTbRefIfacesParentIfConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbRefIfacesParentIfConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetLocalIf() const override;
	void SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& LocalIf) override;

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> GetLocalIfList() const override;
	void SetLocalIfList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& LocalIfList) override;

	TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf() const override;
	void SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& ImportedIf) override;

	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> GetImportedIfList() const override;
	void SetImportedIfList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& ImportedIfList) override;

	// operations
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override;

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfMethodList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) override;

	TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override;

	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfMethodList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbRefIfacesParentIfMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbRefIfacesParentIfStats Stats;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	void _OnHeartbeat();
	bool _OnHeartbeatTick(float DeltaTime);
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTbRefIfacesParentIfInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbRefIfacesParentIfPongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbRefIfacesParentIfServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnLocalIfSignal(const FTbRefIfacesParentIfLocalIfSignalSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnLocalIfSignalList(const FTbRefIfacesParentIfLocalIfSignalListSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnImportedIfSignal(const FTbRefIfacesParentIfImportedIfSignalSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnImportedIfSignalList(const FTbRefIfacesParentIfImportedIfSignalListSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnLocalIfChanged(const FTbRefIfacesParentIfLocalIfChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnLocalIfListChanged(const FTbRefIfacesParentIfLocalIfListChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnImportedIfChanged(const FTbRefIfacesParentIfImportedIfChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnImportedIfListChanged(const FTbRefIfacesParentIfImportedIfListChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnLocalIfMethodReply(const FTbRefIfacesParentIfLocalIfMethodReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnLocalIfMethodListReply(const FTbRefIfacesParentIfLocalIfMethodListReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnImportedIfMethodReply(const FTbRefIfacesParentIfImportedIfMethodReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnImportedIfMethodListReply(const FTbRefIfacesParentIfImportedIfMethodListReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbRefIfacesParentIfPropertiesData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
