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

#include "TbSimple/Generated/MsgBus/TbSimpleNoSignalsInterfaceMsgBusClient.h"
#include "TbSimple/Generated/MsgBus/TbSimpleNoSignalsInterfaceMsgBusMessages.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "Misc/DateTime.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "GenericPlatform/GenericPlatformTime.h"
#include "MessageEndpointBuilder.h"
#include "MessageEndpoint.h"
#include <atomic>

/**
   \brief data structure to hold the last sent property values
*/
struct TbSimpleNoSignalsInterfacePropertiesMsgBusData
{
	std::atomic<bool> bPropBool{false};
	std::atomic<int32> PropInt{0};
};
DEFINE_LOG_CATEGORY(LogTbSimpleNoSignalsInterfaceMsgBusClient);

UTbSimpleNoSignalsInterfaceMsgBusClient::UTbSimpleNoSignalsInterfaceMsgBusClient()
	: UAbstractTbSimpleNoSignalsInterface()
	, _SentData(MakePimpl<TbSimpleNoSignalsInterfacePropertiesMsgBusData>())
{
	PingRTTBuffer.SetNumZeroed(PING_RTT_BUFFER_SIZE);
}

UTbSimpleNoSignalsInterfaceMsgBusClient::~UTbSimpleNoSignalsInterfaceMsgBusClient() = default;

void UTbSimpleNoSignalsInterfaceMsgBusClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleNoSignalsInterfaceMsgBusClient::Deinitialize()
{
	_Disconnect();

	Super::Deinitialize();
}

void UTbSimpleNoSignalsInterfaceMsgBusClient::_Connect()
{
	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTbSimpleNoSignalsInterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (_IsConnected())
	{
		UE_LOG(LogTbSimpleNoSignalsInterfaceMsgBusClient, Log, TEXT("Already connected, cannot connect again."));
		return;
	}

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid() && !ServiceAddress.IsValid())
	{
		_DiscoverService();
		return;
	}

	// clang-format off
	TbSimpleNoSignalsInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSimple/NoSignalsInterface/Client")
		.Handling<FTbSimpleNoSignalsInterfaceInitMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusClient::OnConnectionInit)
		.Handling<FTbSimpleNoSignalsInterfacePongMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusClient::OnPong)
		.Handling<FTbSimpleNoSignalsInterfaceServiceDisconnectMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusClient::OnServiceClosedConnection)
		.Handling<FTbSimpleNoSignalsInterfacePropBoolChangedMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusClient::OnPropBoolChanged)
		.Handling<FTbSimpleNoSignalsInterfacePropIntChangedMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusClient::OnPropIntChanged)
		.Handling<FTbSimpleNoSignalsInterfaceFuncBoolReplyMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusClient::OnFuncBoolReply)
		.Build();
	// clang-format on

	_DiscoverService();
}

void UTbSimpleNoSignalsInterfaceMsgBusClient::_Disconnect()
{
	_LastHbTimestamp = 0.0f;
	if (_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(_HeartbeatTimerHandle);
	}

	if (!_IsConnected())
	{
		return;
	}

	auto msg = new FTbSimpleNoSignalsInterfaceClientDisconnectMessage();

	TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfaceClientDisconnectMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	TbSimpleNoSignalsInterfaceMsgBusEndpoint.Reset();
	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

void UTbSimpleNoSignalsInterfaceMsgBusClient::_DiscoverService()
{
	if (!TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid())
	{
		return;
	}

	auto msg = new FTbSimpleNoSignalsInterfaceDiscoveryMessage();
	TbSimpleNoSignalsInterfaceMsgBusEndpoint->Publish<FTbSimpleNoSignalsInterfaceDiscoveryMessage>(msg);
}

bool UTbSimpleNoSignalsInterfaceMsgBusClient::_IsConnected() const
{
	return TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid() && ServiceAddress.IsValid();
}

void UTbSimpleNoSignalsInterfaceMsgBusClient::OnConnectionInit(const FTbSimpleNoSignalsInterfaceInitMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress.IsValid())
	{
		UE_LOG(LogTbSimpleNoSignalsInterfaceMsgBusClient, Warning, TEXT("Got a second init message - should not happen"));
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
	Stats.MinRTT_MS = 0.0f;

	const bool b_ClientPingIntervalMSChanged = InMessage._ClientPingIntervalMS != _HeartbeatIntervalMS;
	if (b_ClientPingIntervalMSChanged)
	{
		_HeartbeatIntervalMS = InMessage._ClientPingIntervalMS;

		if (_HeartbeatTimerHandle.IsValid() && GetWorld())
		{
			GetWorld()->GetTimerManager().ClearTimer(_HeartbeatTimerHandle);
		}

		if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
		{
			GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTbSimpleNoSignalsInterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
		}
	}
	const bool bbPropBoolChanged = InMessage.bPropBool != bPropBool;
	if (bbPropBoolChanged)
	{
		bPropBool = InMessage.bPropBool;
		_GetSignals()->BroadcastPropBoolChanged(bPropBool);
	}

	const bool bPropIntChanged = InMessage.PropInt != PropInt;
	if (bPropIntChanged)
	{
		PropInt = InMessage.PropInt;
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}

	_ConnectionStatusChanged.Broadcast(true);
}

void UTbSimpleNoSignalsInterfaceMsgBusClient::_OnHeartbeat()
{
	if (_LastHbTimestamp > 0.1f)
	{
		double Delta = (FPlatformTime::Seconds() - _LastHbTimestamp) * 1000;

		if (Delta > 2 * _HeartbeatIntervalMS)
		{
			// service seems to be dead or not responding - reset connection
			ServiceAddress.Invalidate();
			_LastHbTimestamp = 0.0f;
		}
	}

	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleNoSignalsInterfaceMsgBusClient, Warning, TEXT("Heartbeat failed. Client has no connection to service. Reconnecting ..."));

		_Connect();
		return;
	}

	auto msg = new FTbSimpleNoSignalsInterfacePingMessage();
	msg->Timestamp = FPlatformTime::Seconds();

	TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfacePingMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
}

float UTbSimpleNoSignalsInterfaceMsgBusClient::_CalculateAverageRTT() const
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

void UTbSimpleNoSignalsInterfaceMsgBusClient::OnPong(const FTbSimpleNoSignalsInterfacePongMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
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

const FTbSimpleNoSignalsInterfaceStats& UTbSimpleNoSignalsInterfaceMsgBusClient::_GetStats() const
{
	return Stats;
}

void UTbSimpleNoSignalsInterfaceMsgBusClient::OnServiceClosedConnection(const FTbSimpleNoSignalsInterfaceServiceDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		return;
	}

	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

bool UTbSimpleNoSignalsInterfaceMsgBusClient::GetPropBool() const
{
	return bPropBool;
}

void UTbSimpleNoSignalsInterfaceMsgBusClient::SetPropBool(bool bInPropBool)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleNoSignalsInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropBool() == bInPropBool)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->bPropBool == bInPropBool)
	{
		return;
	}

	auto msg = new FTbSimpleNoSignalsInterfaceSetPropBoolRequestMessage();
	msg->bPropBool = bInPropBool;

	TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfaceSetPropBoolRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->bPropBool = bInPropBool;
}

int32 UTbSimpleNoSignalsInterfaceMsgBusClient::GetPropInt() const
{
	return PropInt;
}

void UTbSimpleNoSignalsInterfaceMsgBusClient::SetPropInt(int32 InPropInt)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleNoSignalsInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropInt() == InPropInt)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->PropInt == InPropInt)
	{
		return;
	}

	auto msg = new FTbSimpleNoSignalsInterfaceSetPropIntRequestMessage();
	msg->PropInt = InPropInt;

	TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfaceSetPropIntRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->PropInt = InPropInt;
}

void UTbSimpleNoSignalsInterfaceMsgBusClient::FuncVoid()
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleNoSignalsInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return;
	}

	auto msg = new FTbSimpleNoSignalsInterfaceFuncVoidRequestMessage();

	TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfaceFuncVoidRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return;
}

bool UTbSimpleNoSignalsInterfaceMsgBusClient::FuncBool(bool bInParamBool)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleNoSignalsInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return false;
	}

	auto msg = new FTbSimpleNoSignalsInterfaceFuncBoolRequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->bParamBool = bInParamBool;
	TPromise<bool> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfaceFuncBoolRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbSimpleNoSignalsInterfaceMsgBusClient::OnFuncBoolReply(const FTbSimpleNoSignalsInterfaceFuncBoolReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

void UTbSimpleNoSignalsInterfaceMsgBusClient::OnPropBoolChanged(const FTbSimpleNoSignalsInterfacePropBoolChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleNoSignalsInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bbPropBoolChanged = InMessage.bPropBool != bPropBool;
	if (bbPropBoolChanged)
	{
		bPropBool = InMessage.bPropBool;
		_GetSignals()->BroadcastPropBoolChanged(bPropBool);
	}
}

void UTbSimpleNoSignalsInterfaceMsgBusClient::OnPropIntChanged(const FTbSimpleNoSignalsInterfacePropIntChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleNoSignalsInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropIntChanged = InMessage.PropInt != PropInt;
	if (bPropIntChanged)
	{
		PropInt = InMessage.PropInt;
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}
}

template <typename ResultType>
bool UTbSimpleNoSignalsInterfaceMsgBusClient::StorePromise(const FGuid& Id, TPromise<ResultType>& Promise)
{
	FScopeLock Lock(&ReplyPromisesMapCS);
	return ReplyPromisesMap.Add(Id, &Promise) != nullptr;
}

template <typename ResultType>
bool UTbSimpleNoSignalsInterfaceMsgBusClient::FulfillPromise(const FGuid& Id, const ResultType& Value)
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

template bool UTbSimpleNoSignalsInterfaceMsgBusClient::StorePromise<bool>(const FGuid& Id, TPromise<bool>& Promise);
template bool UTbSimpleNoSignalsInterfaceMsgBusClient::FulfillPromise<bool>(const FGuid& Id, const bool& Value);
