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

#include "Generated/MsgBus/TbSame1SameEnum2InterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSame1SameEnum2InterfaceMsgBusMessages.h"
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
struct TbSame1SameEnum2InterfacePropertiesMsgBusData
{
	std::atomic<ETbSame1Enum1> Prop1{ETbSame1Enum1::TS1E1_VALUE1};
	std::atomic<ETbSame1Enum2> Prop2{ETbSame1Enum2::TS1E2_VALUE1};
};
DEFINE_LOG_CATEGORY(LogTbSame1SameEnum2InterfaceMsgBusClient);

UTbSame1SameEnum2InterfaceMsgBusClient::UTbSame1SameEnum2InterfaceMsgBusClient()
	: UAbstractTbSame1SameEnum2Interface()
	, _SentData(MakePimpl<TbSame1SameEnum2InterfacePropertiesMsgBusData>())
{
	PingRTTBuffer.SetNumZeroed(PING_RTT_BUFFER_SIZE);
}

UTbSame1SameEnum2InterfaceMsgBusClient::~UTbSame1SameEnum2InterfaceMsgBusClient() = default;

void UTbSame1SameEnum2InterfaceMsgBusClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSame1SameEnum2InterfaceMsgBusClient::Deinitialize()
{
	_Disconnect();

	Super::Deinitialize();
}

void UTbSame1SameEnum2InterfaceMsgBusClient::_Connect()
{
	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTbSame1SameEnum2InterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (_IsConnected())
	{
		UE_LOG(LogTbSame1SameEnum2InterfaceMsgBusClient, Log, TEXT("Already connected, cannot connect again."));
		return;
	}

	if (TbSame1SameEnum2InterfaceMsgBusEndpoint.IsValid() && !ServiceAddress.IsValid())
	{
		_DiscoverService();
		return;
	}

	// clang-format off
	TbSame1SameEnum2InterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSame1/SameEnum2Interface/Client")
		.Handling<FTbSame1SameEnum2InterfaceInitMessage>(this, &UTbSame1SameEnum2InterfaceMsgBusClient::OnConnectionInit)
		.Handling<FTbSame1SameEnum2InterfacePongMessage>(this, &UTbSame1SameEnum2InterfaceMsgBusClient::OnPong)
		.Handling<FTbSame1SameEnum2InterfaceServiceDisconnectMessage>(this, &UTbSame1SameEnum2InterfaceMsgBusClient::OnServiceClosedConnection)
		.Handling<FTbSame1SameEnum2InterfaceSig1SignalMessage>(this, &UTbSame1SameEnum2InterfaceMsgBusClient::OnSig1)
		.Handling<FTbSame1SameEnum2InterfaceSig2SignalMessage>(this, &UTbSame1SameEnum2InterfaceMsgBusClient::OnSig2)
		.Handling<FTbSame1SameEnum2InterfaceProp1ChangedMessage>(this, &UTbSame1SameEnum2InterfaceMsgBusClient::OnProp1Changed)
		.Handling<FTbSame1SameEnum2InterfaceProp2ChangedMessage>(this, &UTbSame1SameEnum2InterfaceMsgBusClient::OnProp2Changed)
		.Handling<FTbSame1SameEnum2InterfaceFunc1ReplyMessage>(this, &UTbSame1SameEnum2InterfaceMsgBusClient::OnFunc1Reply)
		.Handling<FTbSame1SameEnum2InterfaceFunc2ReplyMessage>(this, &UTbSame1SameEnum2InterfaceMsgBusClient::OnFunc2Reply)
		.Build();
	// clang-format on

	_DiscoverService();
}

void UTbSame1SameEnum2InterfaceMsgBusClient::_Disconnect()
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

	auto msg = new FTbSame1SameEnum2InterfaceClientDisconnectMessage();

	TbSame1SameEnum2InterfaceMsgBusEndpoint->Send<FTbSame1SameEnum2InterfaceClientDisconnectMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	TbSame1SameEnum2InterfaceMsgBusEndpoint.Reset();
	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

void UTbSame1SameEnum2InterfaceMsgBusClient::_DiscoverService()
{
	if (!TbSame1SameEnum2InterfaceMsgBusEndpoint.IsValid())
	{
		return;
	}

	auto msg = new FTbSame1SameEnum2InterfaceDiscoveryMessage();
	TbSame1SameEnum2InterfaceMsgBusEndpoint->Publish<FTbSame1SameEnum2InterfaceDiscoveryMessage>(msg);
}

bool UTbSame1SameEnum2InterfaceMsgBusClient::_IsConnected() const
{
	return TbSame1SameEnum2InterfaceMsgBusEndpoint.IsValid() && ServiceAddress.IsValid();
}

void UTbSame1SameEnum2InterfaceMsgBusClient::OnConnectionInit(const FTbSame1SameEnum2InterfaceInitMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress.IsValid())
	{
		UE_LOG(LogTbSame1SameEnum2InterfaceMsgBusClient, Warning, TEXT("Got a second init message - should not happen"));
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
			GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTbSame1SameEnum2InterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
		}
	}
	const bool bProp1Changed = InMessage.Prop1 != Prop1;
	if (bProp1Changed)
	{
		Prop1 = InMessage.Prop1;
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}

	const bool bProp2Changed = InMessage.Prop2 != Prop2;
	if (bProp2Changed)
	{
		Prop2 = InMessage.Prop2;
		Execute__GetSignals(this)->OnProp2Changed.Broadcast(Prop2);
	}

	_ConnectionStatusChanged.Broadcast(true);
}

void UTbSame1SameEnum2InterfaceMsgBusClient::_OnHeartbeat()
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
		UE_LOG(LogTbSame1SameEnum2InterfaceMsgBusClient, Warning, TEXT("Heartbeat failed. Client has no connection to service. Reconnecting ..."));

		_Connect();
		return;
	}

	auto msg = new FTbSame1SameEnum2InterfacePingMessage();
	msg->Timestamp = FPlatformTime::Seconds();

	TbSame1SameEnum2InterfaceMsgBusEndpoint->Send<FTbSame1SameEnum2InterfacePingMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
}

float UTbSame1SameEnum2InterfaceMsgBusClient::_CalculateAverageRTT() const
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

void UTbSame1SameEnum2InterfaceMsgBusClient::OnPong(const FTbSame1SameEnum2InterfacePongMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
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

const FTbSame1SameEnum2InterfaceStats& UTbSame1SameEnum2InterfaceMsgBusClient::_GetStats() const
{
	return Stats;
}

void UTbSame1SameEnum2InterfaceMsgBusClient::OnServiceClosedConnection(const FTbSame1SameEnum2InterfaceServiceDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		return;
	}

	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

ETbSame1Enum1 UTbSame1SameEnum2InterfaceMsgBusClient::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame1SameEnum2InterfaceMsgBusClient::SetProp1_Implementation(ETbSame1Enum1 InProp1)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSame1SameEnum2InterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp1_Implementation() == InProp1)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop1 == InProp1)
	{
		return;
	}

	auto msg = new FTbSame1SameEnum2InterfaceSetProp1RequestMessage();
	msg->Prop1 = InProp1;

	TbSame1SameEnum2InterfaceMsgBusEndpoint->Send<FTbSame1SameEnum2InterfaceSetProp1RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->Prop1 = InProp1;
}

ETbSame1Enum2 UTbSame1SameEnum2InterfaceMsgBusClient::GetProp2_Implementation() const
{
	return Prop2;
}

void UTbSame1SameEnum2InterfaceMsgBusClient::SetProp2_Implementation(ETbSame1Enum2 InProp2)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSame1SameEnum2InterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp2_Implementation() == InProp2)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop2 == InProp2)
	{
		return;
	}

	auto msg = new FTbSame1SameEnum2InterfaceSetProp2RequestMessage();
	msg->Prop2 = InProp2;

	TbSame1SameEnum2InterfaceMsgBusEndpoint->Send<FTbSame1SameEnum2InterfaceSetProp2RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->Prop2 = InProp2;
}

ETbSame1Enum1 UTbSame1SameEnum2InterfaceMsgBusClient::Func1_Implementation(ETbSame1Enum1 InParam1)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSame1SameEnum2InterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return ETbSame1Enum1::TS1E1_VALUE1;
	}

	auto msg = new FTbSame1SameEnum2InterfaceFunc1RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->Param1 = InParam1;
	TPromise<ETbSame1Enum1> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbSame1SameEnum2InterfaceMsgBusEndpoint->Send<FTbSame1SameEnum2InterfaceFunc1RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbSame1SameEnum2InterfaceMsgBusClient::OnFunc1Reply(const FTbSame1SameEnum2InterfaceFunc1ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

ETbSame1Enum1 UTbSame1SameEnum2InterfaceMsgBusClient::Func2_Implementation(ETbSame1Enum1 InParam1, ETbSame1Enum2 InParam2)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSame1SameEnum2InterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return ETbSame1Enum1::TS1E1_VALUE1;
	}

	auto msg = new FTbSame1SameEnum2InterfaceFunc2RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->Param1 = InParam1;
	msg->Param2 = InParam2;
	TPromise<ETbSame1Enum1> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbSame1SameEnum2InterfaceMsgBusEndpoint->Send<FTbSame1SameEnum2InterfaceFunc2RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbSame1SameEnum2InterfaceMsgBusClient::OnFunc2Reply(const FTbSame1SameEnum2InterfaceFunc2ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

void UTbSame1SameEnum2InterfaceMsgBusClient::OnSig1(const FTbSame1SameEnum2InterfaceSig1SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSame1SameEnum2InterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSig1Signal.Broadcast(InMessage.Param1);
	return;
}

void UTbSame1SameEnum2InterfaceMsgBusClient::OnSig2(const FTbSame1SameEnum2InterfaceSig2SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSame1SameEnum2InterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSig2Signal.Broadcast(InMessage.Param1, InMessage.Param2);
	return;
}

void UTbSame1SameEnum2InterfaceMsgBusClient::OnProp1Changed(const FTbSame1SameEnum2InterfaceProp1ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSame1SameEnum2InterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bProp1Changed = InMessage.Prop1 != Prop1;
	if (bProp1Changed)
	{
		Prop1 = InMessage.Prop1;
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}
}

void UTbSame1SameEnum2InterfaceMsgBusClient::OnProp2Changed(const FTbSame1SameEnum2InterfaceProp2ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSame1SameEnum2InterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bProp2Changed = InMessage.Prop2 != Prop2;
	if (bProp2Changed)
	{
		Prop2 = InMessage.Prop2;
		Execute__GetSignals(this)->OnProp2Changed.Broadcast(Prop2);
	}
}

template <typename ResultType>
bool UTbSame1SameEnum2InterfaceMsgBusClient::StorePromise(const FGuid& Id, TPromise<ResultType>& Promise)
{
	FScopeLock Lock(&ReplyPromisesMapCS);
	return ReplyPromisesMap.Add(Id, &Promise) != nullptr;
}

template <typename ResultType>
bool UTbSame1SameEnum2InterfaceMsgBusClient::FulfillPromise(const FGuid& Id, const ResultType& Value)
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

template bool UTbSame1SameEnum2InterfaceMsgBusClient::StorePromise<ETbSame1Enum1>(const FGuid& Id, TPromise<ETbSame1Enum1>& Promise);
template bool UTbSame1SameEnum2InterfaceMsgBusClient::FulfillPromise<ETbSame1Enum1>(const FGuid& Id, const ETbSame1Enum1& Value);
