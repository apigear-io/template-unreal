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

#include "Generated/api/AbstractTbSimpleVoidInterface.h"
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
#include "TbSimpleVoidInterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbSimpleVoidInterfaceInitMessage;
struct FTbSimpleVoidInterfaceServiceDisconnectMessage;
struct FTbSimpleVoidInterfaceSigVoidSignalMessage;
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleVoidInterfaceMsgBusClient, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleVoidInterfaceConnectionStatusChangedDelegate, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLE_API UTbSimpleVoidInterfaceMsgBusClient : public UAbstractTbSimpleVoidInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleVoidInterfaceMsgBusClient();
	virtual ~UTbSimpleVoidInterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|VoidInterface|Remote")
	void Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|VoidInterface|Remote")
	void Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|VoidInterface|Remote")
	bool IsConnected() const;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|VoidInterface|Remote", DisplayName = "Connection Status Changed")
	FTbSimpleVoidInterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	// operations
	void FuncVoid_Implementation() override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSimpleVoidInterfaceMsgBusEndpoint;

	void DiscoverService();
	FMessageAddress ServiceAddress;

	// connection handling
	void OnConnectionInit(const FTbSimpleVoidInterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbSimpleVoidInterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigVoid(const FTbSimpleVoidInterfaceSigVoidSignalMessage& InSigVoidMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
