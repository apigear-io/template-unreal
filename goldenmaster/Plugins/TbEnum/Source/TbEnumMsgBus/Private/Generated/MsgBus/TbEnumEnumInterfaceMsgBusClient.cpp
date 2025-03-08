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

#include "TbEnum/Generated/MsgBus/TbEnumEnumInterfaceMsgBusClient.h"
#include "TbEnum/Generated/MsgBus/TbEnumEnumInterfaceMsgBusMessages.h"
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
struct TbEnumEnumInterfacePropertiesMsgBusData
{
	std::atomic<ETbEnumEnum0> Prop0{ETbEnumEnum0::TEE0_VALUE0};
	std::atomic<ETbEnumEnum1> Prop1{ETbEnumEnum1::TEE1_VALUE1};
	std::atomic<ETbEnumEnum2> Prop2{ETbEnumEnum2::TEE2_VALUE2};
	std::atomic<ETbEnumEnum3> Prop3{ETbEnumEnum3::TEE3_VALUE3};
};
DEFINE_LOG_CATEGORY(LogTbEnumEnumInterfaceMsgBusClient);

UTbEnumEnumInterfaceMsgBusClient::UTbEnumEnumInterfaceMsgBusClient()
	: UAbstractTbEnumEnumInterface()
	, _SentData(MakePimpl<TbEnumEnumInterfacePropertiesMsgBusData>())
{
	PingRTTBuffer.SetNumZeroed(PING_RTT_BUFFER_SIZE);
}

UTbEnumEnumInterfaceMsgBusClient::~UTbEnumEnumInterfaceMsgBusClient() = default;

void UTbEnumEnumInterfaceMsgBusClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbEnumEnumInterfaceMsgBusClient::Deinitialize()
{
	_Disconnect();

	Super::Deinitialize();
}

void UTbEnumEnumInterfaceMsgBusClient::_Connect()
{
	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTbEnumEnumInterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (_IsConnected())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Log, TEXT("Already connected, cannot connect again."));
		return;
	}

	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid() && !ServiceAddress.IsValid())
	{
		_DiscoverService();
		return;
	}

	// clang-format off
	TbEnumEnumInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbEnum/EnumInterface/Client")
		.Handling<FTbEnumEnumInterfaceInitMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnConnectionInit)
		.Handling<FTbEnumEnumInterfacePongMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnPong)
		.Handling<FTbEnumEnumInterfaceServiceDisconnectMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnServiceClosedConnection)
		.Handling<FTbEnumEnumInterfaceSig0SignalMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnSig0)
		.Handling<FTbEnumEnumInterfaceSig1SignalMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnSig1)
		.Handling<FTbEnumEnumInterfaceSig2SignalMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnSig2)
		.Handling<FTbEnumEnumInterfaceSig3SignalMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnSig3)
		.Handling<FTbEnumEnumInterfaceProp0ChangedMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnProp0Changed)
		.Handling<FTbEnumEnumInterfaceProp1ChangedMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnProp1Changed)
		.Handling<FTbEnumEnumInterfaceProp2ChangedMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnProp2Changed)
		.Handling<FTbEnumEnumInterfaceProp3ChangedMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnProp3Changed)
		.Handling<FTbEnumEnumInterfaceFunc0ReplyMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnFunc0Reply)
		.Handling<FTbEnumEnumInterfaceFunc1ReplyMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnFunc1Reply)
		.Handling<FTbEnumEnumInterfaceFunc2ReplyMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnFunc2Reply)
		.Handling<FTbEnumEnumInterfaceFunc3ReplyMessage>(this, &UTbEnumEnumInterfaceMsgBusClient::OnFunc3Reply)
		.Build();
	// clang-format on

	_DiscoverService();
}

void UTbEnumEnumInterfaceMsgBusClient::_Disconnect()
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

	auto msg = new FTbEnumEnumInterfaceClientDisconnectMessage();

	TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceClientDisconnectMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	TbEnumEnumInterfaceMsgBusEndpoint.Reset();
	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

void UTbEnumEnumInterfaceMsgBusClient::_DiscoverService()
{
	if (!TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		return;
	}

	auto msg = new FTbEnumEnumInterfaceDiscoveryMessage();
	TbEnumEnumInterfaceMsgBusEndpoint->Publish<FTbEnumEnumInterfaceDiscoveryMessage>(msg);
}

bool UTbEnumEnumInterfaceMsgBusClient::_IsConnected() const
{
	return TbEnumEnumInterfaceMsgBusEndpoint.IsValid() && ServiceAddress.IsValid();
}

void UTbEnumEnumInterfaceMsgBusClient::OnConnectionInit(const FTbEnumEnumInterfaceInitMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress.IsValid())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Warning, TEXT("Got a second init message - should not happen"));
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
			GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTbEnumEnumInterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
		}
	}
	const bool bProp0Changed = InMessage.Prop0 != Prop0;
	if (bProp0Changed)
	{
		Prop0 = InMessage.Prop0;
		_GetSignals()->OnProp0Changed.Broadcast(Prop0);
	}

	const bool bProp1Changed = InMessage.Prop1 != Prop1;
	if (bProp1Changed)
	{
		Prop1 = InMessage.Prop1;
		_GetSignals()->OnProp1Changed.Broadcast(Prop1);
	}

	const bool bProp2Changed = InMessage.Prop2 != Prop2;
	if (bProp2Changed)
	{
		Prop2 = InMessage.Prop2;
		_GetSignals()->OnProp2Changed.Broadcast(Prop2);
	}

	const bool bProp3Changed = InMessage.Prop3 != Prop3;
	if (bProp3Changed)
	{
		Prop3 = InMessage.Prop3;
		_GetSignals()->OnProp3Changed.Broadcast(Prop3);
	}

	_ConnectionStatusChanged.Broadcast(true);
}

void UTbEnumEnumInterfaceMsgBusClient::_OnHeartbeat()
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
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Warning, TEXT("Heartbeat failed. Client has no connection to service. Reconnecting ..."));

		_Connect();
		return;
	}

	auto msg = new FTbEnumEnumInterfacePingMessage();
	msg->Timestamp = FPlatformTime::Seconds();

	TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfacePingMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
}

float UTbEnumEnumInterfaceMsgBusClient::_CalculateAverageRTT() const
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

void UTbEnumEnumInterfaceMsgBusClient::OnPong(const FTbEnumEnumInterfacePongMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
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

const FTbEnumEnumInterfaceStats& UTbEnumEnumInterfaceMsgBusClient::_GetStats() const
{
	return Stats;
}

void UTbEnumEnumInterfaceMsgBusClient::OnServiceClosedConnection(const FTbEnumEnumInterfaceServiceDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		return;
	}

	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

ETbEnumEnum0 UTbEnumEnumInterfaceMsgBusClient::GetProp0() const
{
	return Prop0;
}

void UTbEnumEnumInterfaceMsgBusClient::SetProp0(ETbEnumEnum0 InProp0)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp0() == InProp0)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop0 == InProp0)
	{
		return;
	}

	auto msg = new FTbEnumEnumInterfaceSetProp0RequestMessage();
	msg->Prop0 = InProp0;

	TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceSetProp0RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->Prop0 = InProp0;
}

ETbEnumEnum1 UTbEnumEnumInterfaceMsgBusClient::GetProp1() const
{
	return Prop1;
}

void UTbEnumEnumInterfaceMsgBusClient::SetProp1(ETbEnumEnum1 InProp1)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp1() == InProp1)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop1 == InProp1)
	{
		return;
	}

	auto msg = new FTbEnumEnumInterfaceSetProp1RequestMessage();
	msg->Prop1 = InProp1;

	TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceSetProp1RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->Prop1 = InProp1;
}

ETbEnumEnum2 UTbEnumEnumInterfaceMsgBusClient::GetProp2() const
{
	return Prop2;
}

void UTbEnumEnumInterfaceMsgBusClient::SetProp2(ETbEnumEnum2 InProp2)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp2() == InProp2)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop2 == InProp2)
	{
		return;
	}

	auto msg = new FTbEnumEnumInterfaceSetProp2RequestMessage();
	msg->Prop2 = InProp2;

	TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceSetProp2RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->Prop2 = InProp2;
}

ETbEnumEnum3 UTbEnumEnumInterfaceMsgBusClient::GetProp3() const
{
	return Prop3;
}

void UTbEnumEnumInterfaceMsgBusClient::SetProp3(ETbEnumEnum3 InProp3)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp3() == InProp3)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop3 == InProp3)
	{
		return;
	}

	auto msg = new FTbEnumEnumInterfaceSetProp3RequestMessage();
	msg->Prop3 = InProp3;

	TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceSetProp3RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->Prop3 = InProp3;
}

ETbEnumEnum0 UTbEnumEnumInterfaceMsgBusClient::Func0(ETbEnumEnum0 InParam0)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return ETbEnumEnum0::TEE0_VALUE0;
	}

	auto msg = new FTbEnumEnumInterfaceFunc0RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->Param0 = InParam0;
	TPromise<ETbEnumEnum0> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceFunc0RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbEnumEnumInterfaceMsgBusClient::OnFunc0Reply(const FTbEnumEnumInterfaceFunc0ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

ETbEnumEnum1 UTbEnumEnumInterfaceMsgBusClient::Func1(ETbEnumEnum1 InParam1)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return ETbEnumEnum1::TEE1_VALUE1;
	}

	auto msg = new FTbEnumEnumInterfaceFunc1RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->Param1 = InParam1;
	TPromise<ETbEnumEnum1> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceFunc1RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbEnumEnumInterfaceMsgBusClient::OnFunc1Reply(const FTbEnumEnumInterfaceFunc1ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

ETbEnumEnum2 UTbEnumEnumInterfaceMsgBusClient::Func2(ETbEnumEnum2 InParam2)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return ETbEnumEnum2::TEE2_VALUE2;
	}

	auto msg = new FTbEnumEnumInterfaceFunc2RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->Param2 = InParam2;
	TPromise<ETbEnumEnum2> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceFunc2RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbEnumEnumInterfaceMsgBusClient::OnFunc2Reply(const FTbEnumEnumInterfaceFunc2ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

ETbEnumEnum3 UTbEnumEnumInterfaceMsgBusClient::Func3(ETbEnumEnum3 InParam3)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return ETbEnumEnum3::TEE3_VALUE3;
	}

	auto msg = new FTbEnumEnumInterfaceFunc3RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->Param3 = InParam3;
	TPromise<ETbEnumEnum3> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceFunc3RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbEnumEnumInterfaceMsgBusClient::OnFunc3Reply(const FTbEnumEnumInterfaceFunc3ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

void UTbEnumEnumInterfaceMsgBusClient::OnSig0(const FTbEnumEnumInterfaceSig0SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	_GetSignals()->OnSig0Signal.Broadcast(InMessage.Param0);
	return;
}

void UTbEnumEnumInterfaceMsgBusClient::OnSig1(const FTbEnumEnumInterfaceSig1SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	_GetSignals()->OnSig1Signal.Broadcast(InMessage.Param1);
	return;
}

void UTbEnumEnumInterfaceMsgBusClient::OnSig2(const FTbEnumEnumInterfaceSig2SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	_GetSignals()->OnSig2Signal.Broadcast(InMessage.Param2);
	return;
}

void UTbEnumEnumInterfaceMsgBusClient::OnSig3(const FTbEnumEnumInterfaceSig3SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	_GetSignals()->OnSig3Signal.Broadcast(InMessage.Param3);
	return;
}

void UTbEnumEnumInterfaceMsgBusClient::OnProp0Changed(const FTbEnumEnumInterfaceProp0ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bProp0Changed = InMessage.Prop0 != Prop0;
	if (bProp0Changed)
	{
		Prop0 = InMessage.Prop0;
		_GetSignals()->OnProp0Changed.Broadcast(Prop0);
	}
}

void UTbEnumEnumInterfaceMsgBusClient::OnProp1Changed(const FTbEnumEnumInterfaceProp1ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bProp1Changed = InMessage.Prop1 != Prop1;
	if (bProp1Changed)
	{
		Prop1 = InMessage.Prop1;
		_GetSignals()->OnProp1Changed.Broadcast(Prop1);
	}
}

void UTbEnumEnumInterfaceMsgBusClient::OnProp2Changed(const FTbEnumEnumInterfaceProp2ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bProp2Changed = InMessage.Prop2 != Prop2;
	if (bProp2Changed)
	{
		Prop2 = InMessage.Prop2;
		_GetSignals()->OnProp2Changed.Broadcast(Prop2);
	}
}

void UTbEnumEnumInterfaceMsgBusClient::OnProp3Changed(const FTbEnumEnumInterfaceProp3ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbEnumEnumInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bProp3Changed = InMessage.Prop3 != Prop3;
	if (bProp3Changed)
	{
		Prop3 = InMessage.Prop3;
		_GetSignals()->OnProp3Changed.Broadcast(Prop3);
	}
}

template <typename ResultType>
bool UTbEnumEnumInterfaceMsgBusClient::StorePromise(const FGuid& Id, TPromise<ResultType>& Promise)
{
	FScopeLock Lock(&ReplyPromisesMapCS);
	return ReplyPromisesMap.Add(Id, &Promise) != nullptr;
}

template <typename ResultType>
bool UTbEnumEnumInterfaceMsgBusClient::FulfillPromise(const FGuid& Id, const ResultType& Value)
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

template bool UTbEnumEnumInterfaceMsgBusClient::StorePromise<ETbEnumEnum0>(const FGuid& Id, TPromise<ETbEnumEnum0>& Promise);
template bool UTbEnumEnumInterfaceMsgBusClient::FulfillPromise<ETbEnumEnum0>(const FGuid& Id, const ETbEnumEnum0& Value);
template bool UTbEnumEnumInterfaceMsgBusClient::StorePromise<ETbEnumEnum1>(const FGuid& Id, TPromise<ETbEnumEnum1>& Promise);
template bool UTbEnumEnumInterfaceMsgBusClient::FulfillPromise<ETbEnumEnum1>(const FGuid& Id, const ETbEnumEnum1& Value);
template bool UTbEnumEnumInterfaceMsgBusClient::StorePromise<ETbEnumEnum2>(const FGuid& Id, TPromise<ETbEnumEnum2>& Promise);
template bool UTbEnumEnumInterfaceMsgBusClient::FulfillPromise<ETbEnumEnum2>(const FGuid& Id, const ETbEnumEnum2& Value);
template bool UTbEnumEnumInterfaceMsgBusClient::StorePromise<ETbEnumEnum3>(const FGuid& Id, TPromise<ETbEnumEnum3>& Promise);
template bool UTbEnumEnumInterfaceMsgBusClient::FulfillPromise<ETbEnumEnum3>(const FGuid& Id, const ETbEnumEnum3& Value);
