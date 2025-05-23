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

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "TbNames/Generated/MsgBus/TbNamesNamEsMsgBusClient.h"
#include "TbNames/Generated/MsgBus/TbNamesNamEsMsgBusMessages.h"
#include "Async/Async.h"
#include "Engine/World.h"
#include "Misc/DateTime.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "GenericPlatform/GenericPlatformTime.h"
#include "MessageEndpointBuilder.h"
#include "MessageEndpoint.h"
#include "TbNamesSettings.h"
#include <atomic>

/**
   \brief data structure to hold the last sent property values
*/
struct TbNamesNamEsPropertiesMsgBusData
{
	std::atomic<bool> bSwitch{false};
	std::atomic<int32> SomeProperty{0};
	std::atomic<int32> SomePoperty2{0};
	std::atomic<ETbNamesEnum_With_Under_scores> EnumProperty{ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE};
};
DEFINE_LOG_CATEGORY(LogTbNamesNamEsMsgBusClient);

UTbNamesNamEsMsgBusClient::UTbNamesNamEsMsgBusClient()
	: UAbstractTbNamesNamEs()
	, _SentData(MakePimpl<TbNamesNamEsPropertiesMsgBusData>())
{
	PingRTTBuffer.SetNumZeroed(PING_RTT_BUFFER_SIZE);
}

UTbNamesNamEsMsgBusClient::~UTbNamesNamEsMsgBusClient() = default;

void UTbNamesNamEsMsgBusClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbNamesNamEsMsgBusClient::Deinitialize()
{
	_Disconnect();

	Super::Deinitialize();
}

void UTbNamesNamEsMsgBusClient::_Connect()
{
	if (_IsConnected())
	{
		UE_LOG(LogTbNamesNamEsMsgBusClient, Log, TEXT("Already connected, cannot connect again."));
		return;
	}

	if (!_HeartbeatTickerHandle.IsValid())
	{
		UTbNamesSettings* settings = GetMutableDefault<UTbNamesSettings>();
		check(settings);
		_HeartbeatIntervalMS = settings->MsgBusHeartbeatIntervalMS;

#if (ENGINE_MAJOR_VERSION < 5)
		FTicker::GetCoreTicker().RemoveTicker(_HeartbeatTickerHandle);
		_HeartbeatTickerHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UTbNamesNamEsMsgBusClient::_OnHeartbeatTick), _HeartbeatIntervalMS / 1000.0f);
#else
		FTSTicker::GetCoreTicker().RemoveTicker(_HeartbeatTickerHandle);
		_HeartbeatTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UTbNamesNamEsMsgBusClient::_OnHeartbeatTick), _HeartbeatIntervalMS / 1000.0f);
#endif
	}

	if (TbNamesNamEsMsgBusEndpoint.IsValid() && !ServiceAddress.IsValid())
	{
		_DiscoverService();
		return;
	}

	// clang-format off
	TbNamesNamEsMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbNames/NamEs/Client")
		.Handling<FTbNamesNamEsInitMessage>(this, &UTbNamesNamEsMsgBusClient::OnConnectionInit)
		.Handling<FTbNamesNamEsPongMessage>(this, &UTbNamesNamEsMsgBusClient::OnPong)
		.Handling<FTbNamesNamEsServiceDisconnectMessage>(this, &UTbNamesNamEsMsgBusClient::OnServiceClosedConnection)
		.Handling<FTbNamesNamEsSomeSignalSignalMessage>(this, &UTbNamesNamEsMsgBusClient::OnSomeSignal)
		.Handling<FTbNamesNamEsSomeSignal2SignalMessage>(this, &UTbNamesNamEsMsgBusClient::OnSomeSignal2)
		.Handling<FTbNamesNamEsSwitchChangedMessage>(this, &UTbNamesNamEsMsgBusClient::OnSwitchChanged)
		.Handling<FTbNamesNamEsSomePropertyChangedMessage>(this, &UTbNamesNamEsMsgBusClient::OnSomePropertyChanged)
		.Handling<FTbNamesNamEsSomePoperty2ChangedMessage>(this, &UTbNamesNamEsMsgBusClient::OnSomePoperty2Changed)
		.Handling<FTbNamesNamEsEnumPropertyChangedMessage>(this, &UTbNamesNamEsMsgBusClient::OnEnumPropertyChanged)
		.Build();
	// clang-format on

	_DiscoverService();
}

void UTbNamesNamEsMsgBusClient::_Disconnect()
{
	_LastHbTimestamp = 0.0f;

#if (ENGINE_MAJOR_VERSION < 5)
	FTicker::GetCoreTicker().RemoveTicker(_HeartbeatTickerHandle);
#else
	FTSTicker::GetCoreTicker().RemoveTicker(_HeartbeatTickerHandle);
#endif

	if (!_IsConnected())
	{
		return;
	}

	auto msg = new FTbNamesNamEsClientDisconnectMessage();

	TbNamesNamEsMsgBusEndpoint->Send<FTbNamesNamEsClientDisconnectMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	TbNamesNamEsMsgBusEndpoint.Reset();
	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
	_ConnectionStatusChangedBP.Broadcast(false);
}

void UTbNamesNamEsMsgBusClient::_DiscoverService()
{
	if (!TbNamesNamEsMsgBusEndpoint.IsValid())
	{
		return;
	}

	auto msg = new FTbNamesNamEsDiscoveryMessage();
	TbNamesNamEsMsgBusEndpoint->Publish<FTbNamesNamEsDiscoveryMessage>(msg);
}

bool UTbNamesNamEsMsgBusClient::_IsConnected() const
{
	return TbNamesNamEsMsgBusEndpoint.IsValid() && ServiceAddress.IsValid();
}

void UTbNamesNamEsMsgBusClient::OnConnectionInit(const FTbNamesNamEsInitMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress.IsValid())
	{
		UE_LOG(LogTbNamesNamEsMsgBusClient, Warning,
			TEXT("Got a second init message. It usually means that there are several instances of the same service on the network.")
				TEXT(" This can cause connection mixups. Please make sure that there is only one instance of the service running on the network."));
		return;
	}

	ServiceAddress = Context->GetSender();
	// reset ping stats for a new connection
	PingRTTBuffer.Empty();
	PingRTTBuffer.SetNumZeroed(PING_RTT_BUFFER_SIZE);
	CurrentPingCounter = 0;
	Stats.CurrentRTT_MS = 0.0f;
	Stats.AverageRTT_MS = 0.0f;
	Stats.MaxRTT_MS = 0.0f;
	Stats.MinRTT_MS = 10000.0f;

	const bool b_ClientPingIntervalMSChanged = InMessage._ClientPingIntervalMS != _HeartbeatIntervalMS;
	if (b_ClientPingIntervalMSChanged)
	{
		_HeartbeatIntervalMS = InMessage._ClientPingIntervalMS;

#if (ENGINE_MAJOR_VERSION < 5)
		FTicker::GetCoreTicker().RemoveTicker(_HeartbeatTickerHandle);
		_HeartbeatTickerHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UTbNamesNamEsMsgBusClient::_OnHeartbeatTick), _HeartbeatIntervalMS / 1000.0f);
#else
		FTSTicker::GetCoreTicker().RemoveTicker(_HeartbeatTickerHandle);
		_HeartbeatTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UTbNamesNamEsMsgBusClient::_OnHeartbeatTick), _HeartbeatIntervalMS / 1000.0f);
#endif
	}
	const bool bbSwitchChanged = InMessage.bSwitch != bSwitch;
	if (bbSwitchChanged)
	{
		bSwitch = InMessage.bSwitch;
		// reset sent data to the current state
		_SentData->bSwitch = bSwitch;
		_GetSignals()->BroadcastSwitchChanged(bSwitch);
	}

	const bool bSomePropertyChanged = InMessage.SomeProperty != SomeProperty;
	if (bSomePropertyChanged)
	{
		SomeProperty = InMessage.SomeProperty;
		// reset sent data to the current state
		_SentData->SomeProperty = SomeProperty;
		_GetSignals()->BroadcastSomePropertyChanged(SomeProperty);
	}

	const bool bSomePoperty2Changed = InMessage.SomePoperty2 != SomePoperty2;
	if (bSomePoperty2Changed)
	{
		SomePoperty2 = InMessage.SomePoperty2;
		// reset sent data to the current state
		_SentData->SomePoperty2 = SomePoperty2;
		_GetSignals()->BroadcastSomePoperty2Changed(SomePoperty2);
	}

	const bool bEnumPropertyChanged = InMessage.EnumProperty != EnumProperty;
	if (bEnumPropertyChanged)
	{
		EnumProperty = InMessage.EnumProperty;
		// reset sent data to the current state
		_SentData->EnumProperty = EnumProperty;
		_GetSignals()->BroadcastEnumPropertyChanged(EnumProperty);
	}

	_ConnectionStatusChanged.Broadcast(true);
	_ConnectionStatusChangedBP.Broadcast(true);
}

bool UTbNamesNamEsMsgBusClient::_OnHeartbeatTick(float /*DeltaTime*/)
{
	_OnHeartbeat();
	return true;
}

void UTbNamesNamEsMsgBusClient::_OnHeartbeat()
{
	if (_LastHbTimestamp > 0.1)
	{
		const double DeltaMS = (FPlatformTime::Seconds() - _LastHbTimestamp) * 1000.0;

		if (DeltaMS > 2 * _HeartbeatIntervalMS)
		{
			// service seems to be dead or not responding - reset connection
			ServiceAddress.Invalidate();
			_LastHbTimestamp = 0.0;
			_ConnectionStatusChanged.Broadcast(false);
		}
	}

	if (!_IsConnected())
	{
		// only log warning message once a second
		if (FPlatformTime::Seconds() - _LastConnectionWarningTimestamp > 1.0)
		{
			UE_LOG(LogTbNamesNamEsMsgBusClient, Warning, TEXT("Heartbeat failed. Client has no connection to service. Reconnecting ..."));
			_LastConnectionWarningTimestamp = FPlatformTime::Seconds();
		}

		_Connect();
		return;
	}

	auto msg = new FTbNamesNamEsPingMessage();
	msg->Timestamp = FPlatformTime::Seconds();

	TbNamesNamEsMsgBusEndpoint->Send<FTbNamesNamEsPingMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
}

float UTbNamesNamEsMsgBusClient::_CalculateAverageRTT() const
{
	if (CurrentPingCounter == 0)
	{
		return 0.0f;
	}

	float TotalRTT = 0.0f;

	for (const float& RTT : PingRTTBuffer)
	{
		TotalRTT += RTT;
	}

	return CurrentPingCounter > 0 ? TotalRTT / CurrentPingCounter : 0.0f;
}

void UTbNamesNamEsMsgBusClient::OnPong(const FTbNamesNamEsPongMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	_LastHbTimestamp = InMessage.Timestamp;

	const double Current = FPlatformTime::Seconds();
	const double DeltaMS = (Current - InMessage.Timestamp) * 1000.0f;

	Stats.CurrentRTT_MS = DeltaMS;
	if (CurrentPingCounter < PING_RTT_BUFFER_SIZE)
	{
		CurrentPingCounter++;
	}
	PingRTTBuffer.RemoveAt(0);
	PingRTTBuffer.Add(Stats.CurrentRTT_MS);
	Stats.AverageRTT_MS = _CalculateAverageRTT();
	Stats.MaxRTT_MS = FGenericPlatformMath::Max(Stats.MaxRTT_MS, Stats.CurrentRTT_MS);
	Stats.MinRTT_MS = FGenericPlatformMath::Min(Stats.MinRTT_MS, Stats.CurrentRTT_MS);

	_StatsUpdated.Broadcast(Stats);
}

const FTbNamesNamEsStats& UTbNamesNamEsMsgBusClient::_GetStats() const
{
	return Stats;
}

void UTbNamesNamEsMsgBusClient::OnServiceClosedConnection(const FTbNamesNamEsServiceDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		return;
	}

	_LastHbTimestamp = 0.0;
	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
	_ConnectionStatusChangedBP.Broadcast(false);
}

bool UTbNamesNamEsMsgBusClient::GetSwitch() const
{
	return bSwitch;
}

void UTbNamesNamEsMsgBusClient::SetSwitch(bool bInSwitch)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbNamesNamEsMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetSwitch() == bInSwitch)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->bSwitch == bInSwitch)
	{
		return;
	}

	auto msg = new FTbNamesNamEsSetSwitchRequestMessage();
	msg->bSwitch = bInSwitch;

	TbNamesNamEsMsgBusEndpoint->Send<FTbNamesNamEsSetSwitchRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->bSwitch = bInSwitch;
}

int32 UTbNamesNamEsMsgBusClient::GetSomeProperty() const
{
	return SomeProperty;
}

void UTbNamesNamEsMsgBusClient::SetSomeProperty(int32 InSomeProperty)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbNamesNamEsMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetSomeProperty() == InSomeProperty)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->SomeProperty == InSomeProperty)
	{
		return;
	}

	auto msg = new FTbNamesNamEsSetSomePropertyRequestMessage();
	msg->SomeProperty = InSomeProperty;

	TbNamesNamEsMsgBusEndpoint->Send<FTbNamesNamEsSetSomePropertyRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->SomeProperty = InSomeProperty;
}

int32 UTbNamesNamEsMsgBusClient::GetSomePoperty2() const
{
	return SomePoperty2;
}

void UTbNamesNamEsMsgBusClient::SetSomePoperty2(int32 InSomePoperty2)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbNamesNamEsMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetSomePoperty2() == InSomePoperty2)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->SomePoperty2 == InSomePoperty2)
	{
		return;
	}

	auto msg = new FTbNamesNamEsSetSomePoperty2RequestMessage();
	msg->SomePoperty2 = InSomePoperty2;

	TbNamesNamEsMsgBusEndpoint->Send<FTbNamesNamEsSetSomePoperty2RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->SomePoperty2 = InSomePoperty2;
}

ETbNamesEnum_With_Under_scores UTbNamesNamEsMsgBusClient::GetEnumProperty() const
{
	return EnumProperty;
}

void UTbNamesNamEsMsgBusClient::SetEnumProperty(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbNamesNamEsMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetEnumProperty() == InEnumProperty)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->EnumProperty == InEnumProperty)
	{
		return;
	}

	auto msg = new FTbNamesNamEsSetEnumPropertyRequestMessage();
	msg->EnumProperty = InEnumProperty;

	TbNamesNamEsMsgBusEndpoint->Send<FTbNamesNamEsSetEnumPropertyRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->EnumProperty = InEnumProperty;
}

void UTbNamesNamEsMsgBusClient::SomeFunction(bool bInSomeParam)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbNamesNamEsMsgBusClient, Error, TEXT("Client has no connection to service."));

		return;
	}

	auto msg = new FTbNamesNamEsSomeFunctionRequestMessage();
	msg->bSomeParam = bInSomeParam;

	TbNamesNamEsMsgBusEndpoint->Send<FTbNamesNamEsSomeFunctionRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return;
}

void UTbNamesNamEsMsgBusClient::SomeFunction2(bool bInSomeParam)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbNamesNamEsMsgBusClient, Error, TEXT("Client has no connection to service."));

		return;
	}

	auto msg = new FTbNamesNamEsSomeFunction2RequestMessage();
	msg->bSomeParam = bInSomeParam;

	TbNamesNamEsMsgBusEndpoint->Send<FTbNamesNamEsSomeFunction2RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return;
}

void UTbNamesNamEsMsgBusClient::OnSomeSignal(const FTbNamesNamEsSomeSignalSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbNamesNamEsMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	_GetSignals()->BroadcastSomeSignalSignal(InMessage.bSomeParam);
	return;
}

void UTbNamesNamEsMsgBusClient::OnSomeSignal2(const FTbNamesNamEsSomeSignal2SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbNamesNamEsMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	_GetSignals()->BroadcastSomeSignal2Signal(InMessage.bSomeParam);
	return;
}

void UTbNamesNamEsMsgBusClient::OnSwitchChanged(const FTbNamesNamEsSwitchChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbNamesNamEsMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bbSwitchChanged = InMessage.bSwitch != bSwitch;
	if (bbSwitchChanged)
	{
		bSwitch = InMessage.bSwitch;
		// reset sent data to the current state
		_SentData->bSwitch = bSwitch;
		_GetSignals()->BroadcastSwitchChanged(bSwitch);
	}
}

void UTbNamesNamEsMsgBusClient::OnSomePropertyChanged(const FTbNamesNamEsSomePropertyChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbNamesNamEsMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bSomePropertyChanged = InMessage.SomeProperty != SomeProperty;
	if (bSomePropertyChanged)
	{
		SomeProperty = InMessage.SomeProperty;
		// reset sent data to the current state
		_SentData->SomeProperty = SomeProperty;
		_GetSignals()->BroadcastSomePropertyChanged(SomeProperty);
	}
}

void UTbNamesNamEsMsgBusClient::OnSomePoperty2Changed(const FTbNamesNamEsSomePoperty2ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbNamesNamEsMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bSomePoperty2Changed = InMessage.SomePoperty2 != SomePoperty2;
	if (bSomePoperty2Changed)
	{
		SomePoperty2 = InMessage.SomePoperty2;
		// reset sent data to the current state
		_SentData->SomePoperty2 = SomePoperty2;
		_GetSignals()->BroadcastSomePoperty2Changed(SomePoperty2);
	}
}

void UTbNamesNamEsMsgBusClient::OnEnumPropertyChanged(const FTbNamesNamEsEnumPropertyChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbNamesNamEsMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bEnumPropertyChanged = InMessage.EnumProperty != EnumProperty;
	if (bEnumPropertyChanged)
	{
		EnumProperty = InMessage.EnumProperty;
		// reset sent data to the current state
		_SentData->EnumProperty = EnumProperty;
		_GetSignals()->BroadcastEnumPropertyChanged(EnumProperty);
	}
}

template <typename ResultType>
bool UTbNamesNamEsMsgBusClient::StorePromise(const FGuid& Id, TPromise<ResultType>& Promise)
{
	FScopeLock Lock(&ReplyPromisesMapCS);
	return ReplyPromisesMap.Add(Id, &Promise) != nullptr;
}

template <typename ResultType>
bool UTbNamesNamEsMsgBusClient::FulfillPromise(const FGuid& Id, const ResultType& Value)
{
	TPromise<ResultType>* PromisePtr = nullptr;

	{
		FScopeLock Lock(&ReplyPromisesMapCS);
		if (auto** Found = ReplyPromisesMap.Find(Id))
		{
			PromisePtr = static_cast<TPromise<ResultType>*>(*Found);
			ReplyPromisesMap.Remove(Id);
		}
	}

	if (PromisePtr)
	{
		PromisePtr->SetValue(Value);
		return true;
	}
	return false;
}
