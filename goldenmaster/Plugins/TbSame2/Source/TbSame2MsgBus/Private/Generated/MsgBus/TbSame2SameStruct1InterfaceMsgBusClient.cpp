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

#include "TbSame2/Generated/MsgBus/TbSame2SameStruct1InterfaceMsgBusClient.h"
#include "TbSame2/Generated/MsgBus/TbSame2SameStruct1InterfaceMsgBusMessages.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "Misc/DateTime.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "GenericPlatform/GenericPlatformTime.h"
#include "MessageEndpointBuilder.h"
#include "MessageEndpoint.h"
#include "HAL/CriticalSection.h"

/**
   \brief data structure to hold the last sent property values
*/
struct TbSame2SameStruct1InterfacePropertiesMsgBusData
{
	FCriticalSection Prop1Mutex;
	FTbSame2Struct1 Prop1{FTbSame2Struct1()};
};
DEFINE_LOG_CATEGORY(LogTbSame2SameStruct1InterfaceMsgBusClient);

UTbSame2SameStruct1InterfaceMsgBusClient::UTbSame2SameStruct1InterfaceMsgBusClient()
	: UAbstractTbSame2SameStruct1Interface()
	, _SentData(MakePimpl<TbSame2SameStruct1InterfacePropertiesMsgBusData>())
{
	PingRTTBuffer.SetNumZeroed(PING_RTT_BUFFER_SIZE);
}

UTbSame2SameStruct1InterfaceMsgBusClient::~UTbSame2SameStruct1InterfaceMsgBusClient() = default;

void UTbSame2SameStruct1InterfaceMsgBusClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSame2SameStruct1InterfaceMsgBusClient::Deinitialize()
{
	_Disconnect();

	Super::Deinitialize();
}

void UTbSame2SameStruct1InterfaceMsgBusClient::_Connect()
{
	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTbSame2SameStruct1InterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (_IsConnected())
	{
		UE_LOG(LogTbSame2SameStruct1InterfaceMsgBusClient, Log, TEXT("Already connected, cannot connect again."));
		return;
	}

	if (TbSame2SameStruct1InterfaceMsgBusEndpoint.IsValid() && !ServiceAddress.IsValid())
	{
		_DiscoverService();
		return;
	}

	// clang-format off
	TbSame2SameStruct1InterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSame2/SameStruct1Interface/Client")
		.Handling<FTbSame2SameStruct1InterfaceInitMessage>(this, &UTbSame2SameStruct1InterfaceMsgBusClient::OnConnectionInit)
		.Handling<FTbSame2SameStruct1InterfacePongMessage>(this, &UTbSame2SameStruct1InterfaceMsgBusClient::OnPong)
		.Handling<FTbSame2SameStruct1InterfaceServiceDisconnectMessage>(this, &UTbSame2SameStruct1InterfaceMsgBusClient::OnServiceClosedConnection)
		.Handling<FTbSame2SameStruct1InterfaceSig1SignalMessage>(this, &UTbSame2SameStruct1InterfaceMsgBusClient::OnSig1)
		.Handling<FTbSame2SameStruct1InterfaceProp1ChangedMessage>(this, &UTbSame2SameStruct1InterfaceMsgBusClient::OnProp1Changed)
		.Handling<FTbSame2SameStruct1InterfaceFunc1ReplyMessage>(this, &UTbSame2SameStruct1InterfaceMsgBusClient::OnFunc1Reply)
		.Build();
	// clang-format on

	_DiscoverService();
}

void UTbSame2SameStruct1InterfaceMsgBusClient::_Disconnect()
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

	auto msg = new FTbSame2SameStruct1InterfaceClientDisconnectMessage();

	TbSame2SameStruct1InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct1InterfaceClientDisconnectMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	TbSame2SameStruct1InterfaceMsgBusEndpoint.Reset();
	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

void UTbSame2SameStruct1InterfaceMsgBusClient::_DiscoverService()
{
	if (!TbSame2SameStruct1InterfaceMsgBusEndpoint.IsValid())
	{
		return;
	}

	auto msg = new FTbSame2SameStruct1InterfaceDiscoveryMessage();
	TbSame2SameStruct1InterfaceMsgBusEndpoint->Publish<FTbSame2SameStruct1InterfaceDiscoveryMessage>(msg);
}

bool UTbSame2SameStruct1InterfaceMsgBusClient::_IsConnected() const
{
	return TbSame2SameStruct1InterfaceMsgBusEndpoint.IsValid() && ServiceAddress.IsValid();
}

void UTbSame2SameStruct1InterfaceMsgBusClient::OnConnectionInit(const FTbSame2SameStruct1InterfaceInitMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress.IsValid())
	{
		UE_LOG(LogTbSame2SameStruct1InterfaceMsgBusClient, Warning, TEXT("Got a second init message - should not happen"));
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
			GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTbSame2SameStruct1InterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
		}
	}
	const bool bProp1Changed = InMessage.Prop1 != Prop1;
	if (bProp1Changed)
	{
		Prop1 = InMessage.Prop1;
		_GetSignals()->OnProp1Changed.Broadcast(Prop1);
	}

	_ConnectionStatusChanged.Broadcast(true);
}

void UTbSame2SameStruct1InterfaceMsgBusClient::_OnHeartbeat()
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
		UE_LOG(LogTbSame2SameStruct1InterfaceMsgBusClient, Warning, TEXT("Heartbeat failed. Client has no connection to service. Reconnecting ..."));

		_Connect();
		return;
	}

	auto msg = new FTbSame2SameStruct1InterfacePingMessage();
	msg->Timestamp = FPlatformTime::Seconds();

	TbSame2SameStruct1InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct1InterfacePingMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
}

float UTbSame2SameStruct1InterfaceMsgBusClient::_CalculateAverageRTT() const
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

void UTbSame2SameStruct1InterfaceMsgBusClient::OnPong(const FTbSame2SameStruct1InterfacePongMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
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

const FTbSame2SameStruct1InterfaceStats& UTbSame2SameStruct1InterfaceMsgBusClient::_GetStats() const
{
	return Stats;
}

void UTbSame2SameStruct1InterfaceMsgBusClient::OnServiceClosedConnection(const FTbSame2SameStruct1InterfaceServiceDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		return;
	}

	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

FTbSame2Struct1 UTbSame2SameStruct1InterfaceMsgBusClient::GetProp1() const
{
	return Prop1;
}

void UTbSame2SameStruct1InterfaceMsgBusClient::SetProp1(const FTbSame2Struct1& InProp1)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSame2SameStruct1InterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp1() == InProp1)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->Prop1Mutex));
		if (_SentData->Prop1 == InProp1)
		{
			return;
		}
	}

	auto msg = new FTbSame2SameStruct1InterfaceSetProp1RequestMessage();
	msg->Prop1 = InProp1;

	TbSame2SameStruct1InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct1InterfaceSetProp1RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	FScopeLock Lock(&(_SentData->Prop1Mutex));
	_SentData->Prop1 = InProp1;
}

FTbSame2Struct1 UTbSame2SameStruct1InterfaceMsgBusClient::Func1(const FTbSame2Struct1& InParam1)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSame2SameStruct1InterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return FTbSame2Struct1();
	}

	auto msg = new FTbSame2SameStruct1InterfaceFunc1RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->Param1 = InParam1;
	TPromise<FTbSame2Struct1> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbSame2SameStruct1InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct1InterfaceFunc1RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbSame2SameStruct1InterfaceMsgBusClient::OnFunc1Reply(const FTbSame2SameStruct1InterfaceFunc1ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

void UTbSame2SameStruct1InterfaceMsgBusClient::OnSig1(const FTbSame2SameStruct1InterfaceSig1SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSame2SameStruct1InterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	_GetSignals()->OnSig1Signal.Broadcast(InMessage.Param1);
	return;
}

void UTbSame2SameStruct1InterfaceMsgBusClient::OnProp1Changed(const FTbSame2SameStruct1InterfaceProp1ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSame2SameStruct1InterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bProp1Changed = InMessage.Prop1 != Prop1;
	if (bProp1Changed)
	{
		Prop1 = InMessage.Prop1;
		_GetSignals()->OnProp1Changed.Broadcast(Prop1);
	}
}

template <typename ResultType>
bool UTbSame2SameStruct1InterfaceMsgBusClient::StorePromise(const FGuid& Id, TPromise<ResultType>& Promise)
{
	FScopeLock Lock(&ReplyPromisesMapCS);
	return ReplyPromisesMap.Add(Id, &Promise) != nullptr;
}

template <typename ResultType>
bool UTbSame2SameStruct1InterfaceMsgBusClient::FulfillPromise(const FGuid& Id, const ResultType& Value)
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

template bool UTbSame2SameStruct1InterfaceMsgBusClient::StorePromise<FTbSame2Struct1>(const FGuid& Id, TPromise<FTbSame2Struct1>& Promise);
template bool UTbSame2SameStruct1InterfaceMsgBusClient::FulfillPromise<FTbSame2Struct1>(const FGuid& Id, const FTbSame2Struct1& Value);
