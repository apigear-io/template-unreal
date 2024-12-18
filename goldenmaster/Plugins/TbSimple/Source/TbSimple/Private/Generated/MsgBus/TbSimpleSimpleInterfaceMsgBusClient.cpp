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

#include "Generated/MsgBus/TbSimpleSimpleInterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSimpleSimpleInterfaceMsgBusMessages.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "Misc/DateTime.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "GenericPlatform/GenericPlatformTime.h"
#include "MessageEndpointBuilder.h"
#include "MessageEndpoint.h"
#include <atomic>
#include "HAL/CriticalSection.h"

/**
   \brief data structure to hold the last sent property values
*/
struct TbSimpleSimpleInterfacePropertiesMsgBusData
{
	std::atomic<bool> bPropBool{false};
	std::atomic<int32> PropInt{0};
	std::atomic<int32> PropInt32{0};
	std::atomic<int64> PropInt64{0LL};
	std::atomic<float> PropFloat{0.0f};
	std::atomic<float> PropFloat32{0.0f};
	std::atomic<double> PropFloat64{0.0};
	FCriticalSection PropStringMutex;
	FString PropString{FString()};
};
DEFINE_LOG_CATEGORY(LogTbSimpleSimpleInterfaceMsgBusClient);

UTbSimpleSimpleInterfaceMsgBusClient::UTbSimpleSimpleInterfaceMsgBusClient()
	: UAbstractTbSimpleSimpleInterface()
	, _SentData(MakePimpl<TbSimpleSimpleInterfacePropertiesMsgBusData>())
{
}

UTbSimpleSimpleInterfaceMsgBusClient::~UTbSimpleSimpleInterfaceMsgBusClient() = default;

void UTbSimpleSimpleInterfaceMsgBusClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleSimpleInterfaceMsgBusClient::Deinitialize()
{
	_Disconnect();

	Super::Deinitialize();
}

void UTbSimpleSimpleInterfaceMsgBusClient::_Connect()
{
	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTbSimpleSimpleInterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Log, TEXT("Already connected, cannot connect again."));
		return;
	}

	if (TbSimpleSimpleInterfaceMsgBusEndpoint.IsValid() && !ServiceAddress.IsValid())
	{
		_DiscoverService();
		return;
	}

	// clang-format off
	TbSimpleSimpleInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSimple/SimpleInterface/Client")
		.Handling<FTbSimpleSimpleInterfaceInitMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnConnectionInit)
		.Handling<FTbSimpleSimpleInterfacePongMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnPong)
		.Handling<FTbSimpleSimpleInterfaceServiceDisconnectMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnServiceClosedConnection)
		.Handling<FTbSimpleSimpleInterfaceSigBoolSignalMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnSigBool)
		.Handling<FTbSimpleSimpleInterfaceSigIntSignalMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnSigInt)
		.Handling<FTbSimpleSimpleInterfaceSigInt32SignalMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnSigInt32)
		.Handling<FTbSimpleSimpleInterfaceSigInt64SignalMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnSigInt64)
		.Handling<FTbSimpleSimpleInterfaceSigFloatSignalMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnSigFloat)
		.Handling<FTbSimpleSimpleInterfaceSigFloat32SignalMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnSigFloat32)
		.Handling<FTbSimpleSimpleInterfaceSigFloat64SignalMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnSigFloat64)
		.Handling<FTbSimpleSimpleInterfaceSigStringSignalMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnSigString)
		.Handling<FTbSimpleSimpleInterfacePropBoolChangedMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnPropBoolChanged)
		.Handling<FTbSimpleSimpleInterfacePropIntChangedMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnPropIntChanged)
		.Handling<FTbSimpleSimpleInterfacePropInt32ChangedMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnPropInt32Changed)
		.Handling<FTbSimpleSimpleInterfacePropInt64ChangedMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnPropInt64Changed)
		.Handling<FTbSimpleSimpleInterfacePropFloatChangedMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnPropFloatChanged)
		.Handling<FTbSimpleSimpleInterfacePropFloat32ChangedMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnPropFloat32Changed)
		.Handling<FTbSimpleSimpleInterfacePropFloat64ChangedMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnPropFloat64Changed)
		.Handling<FTbSimpleSimpleInterfacePropStringChangedMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnPropStringChanged)
		.Handling<FTbSimpleSimpleInterfaceFuncBoolReplyMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnFuncBoolReply)
		.Handling<FTbSimpleSimpleInterfaceFuncIntReplyMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnFuncIntReply)
		.Handling<FTbSimpleSimpleInterfaceFuncInt32ReplyMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnFuncInt32Reply)
		.Handling<FTbSimpleSimpleInterfaceFuncInt64ReplyMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnFuncInt64Reply)
		.Handling<FTbSimpleSimpleInterfaceFuncFloatReplyMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnFuncFloatReply)
		.Handling<FTbSimpleSimpleInterfaceFuncFloat32ReplyMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnFuncFloat32Reply)
		.Handling<FTbSimpleSimpleInterfaceFuncFloat64ReplyMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnFuncFloat64Reply)
		.Handling<FTbSimpleSimpleInterfaceFuncStringReplyMessage>(this, &UTbSimpleSimpleInterfaceMsgBusClient::OnFuncStringReply)
		.Build();
	// clang-format on

	_DiscoverService();
}

void UTbSimpleSimpleInterfaceMsgBusClient::_Disconnect()
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

	auto msg = new FTbSimpleSimpleInterfaceClientDisconnectMessage();

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceClientDisconnectMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	TbSimpleSimpleInterfaceMsgBusEndpoint.Reset();
	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

void UTbSimpleSimpleInterfaceMsgBusClient::_DiscoverService()
{
	if (!TbSimpleSimpleInterfaceMsgBusEndpoint.IsValid())
	{
		return;
	}

	auto msg = new FTbSimpleSimpleInterfaceDiscoveryMessage();
	msg->ClientPingIntervalMS = _HeartbeatIntervalMS;

	TbSimpleSimpleInterfaceMsgBusEndpoint->Publish<FTbSimpleSimpleInterfaceDiscoveryMessage>(msg);
}

bool UTbSimpleSimpleInterfaceMsgBusClient::_IsConnected() const
{
	return TbSimpleSimpleInterfaceMsgBusEndpoint.IsValid() && ServiceAddress.IsValid();
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnConnectionInit(const FTbSimpleSimpleInterfaceInitMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress.IsValid())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Warning, TEXT("Got a second init message - should not happen"));
		return;
	}

	ServiceAddress = Context->GetSender();
	const bool bbPropBoolChanged = InMessage.bPropBool != bPropBool;
	if (bbPropBoolChanged)
	{
		bPropBool = InMessage.bPropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(bPropBool);
	}

	const bool bPropIntChanged = InMessage.PropInt != PropInt;
	if (bPropIntChanged)
	{
		PropInt = InMessage.PropInt;
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}

	const bool bPropInt32Changed = InMessage.PropInt32 != PropInt32;
	if (bPropInt32Changed)
	{
		PropInt32 = InMessage.PropInt32;
		Execute__GetSignals(this)->OnPropInt32Changed.Broadcast(PropInt32);
	}

	const bool bPropInt64Changed = InMessage.PropInt64 != PropInt64;
	if (bPropInt64Changed)
	{
		PropInt64 = InMessage.PropInt64;
		Execute__GetSignals(this)->OnPropInt64Changed.Broadcast(PropInt64);
	}

	const bool bPropFloatChanged = InMessage.PropFloat != PropFloat;
	if (bPropFloatChanged)
	{
		PropFloat = InMessage.PropFloat;
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}

	const bool bPropFloat32Changed = InMessage.PropFloat32 != PropFloat32;
	if (bPropFloat32Changed)
	{
		PropFloat32 = InMessage.PropFloat32;
		Execute__GetSignals(this)->OnPropFloat32Changed.Broadcast(PropFloat32);
	}

	const bool bPropFloat64Changed = InMessage.PropFloat64 != PropFloat64;
	if (bPropFloat64Changed)
	{
		PropFloat64 = InMessage.PropFloat64;
		Execute__GetSignals(this)->OnPropFloat64Changed.Broadcast(PropFloat64);
	}

	const bool bPropStringChanged = InMessage.PropString != PropString;
	if (bPropStringChanged)
	{
		PropString = InMessage.PropString;
		Execute__GetSignals(this)->OnPropStringChanged.Broadcast(PropString);
	}

	_ConnectionStatusChanged.Broadcast(true);
}

void UTbSimpleSimpleInterfaceMsgBusClient::_OnHeartbeat()
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
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Warning, TEXT("Heartbeat failed. Client has no connection to service. Reconnecting ..."));

		_Connect();
		return;
	}

	auto msg = new FTbSimpleSimpleInterfacePingMessage();
	msg->Timestamp = FPlatformTime::Seconds();

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfacePingMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnPong(const FTbSimpleSimpleInterfacePongMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	_LastHbTimestamp = InMessage.Timestamp;

	const double Current = FPlatformTime::Seconds();
	const double DeltaMS = (Current - InMessage.Timestamp) * 1000.0f;

	Stats.CurrentRTT_MS = DeltaMS;
	Stats.AverageRTT_MS = (Stats.AverageRTT_MS + Stats.CurrentRTT_MS) / 2.0f;
	Stats.MaxRTT_MS = FGenericPlatformMath::Max(Stats.MaxRTT_MS, Stats.CurrentRTT_MS);
	Stats.MinRTT_MS = FGenericPlatformMath::Min(Stats.MinRTT_MS, Stats.CurrentRTT_MS);

	_StatsUpdated.Broadcast(Stats);
}

const FTbSimpleSimpleInterfaceStats& UTbSimpleSimpleInterfaceMsgBusClient::_GetStats() const
{
	return Stats;
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnServiceClosedConnection(const FTbSimpleSimpleInterfaceServiceDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		return;
	}

	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

bool UTbSimpleSimpleInterfaceMsgBusClient::GetPropBool_Implementation() const
{
	return bPropBool;
}

void UTbSimpleSimpleInterfaceMsgBusClient::SetPropBool_Implementation(bool bInPropBool)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropBool_Implementation() == bInPropBool)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->bPropBool == bInPropBool)
	{
		return;
	}

	auto msg = new FTbSimpleSimpleInterfaceSetPropBoolRequestMessage();
	msg->bPropBool = bInPropBool;

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceSetPropBoolRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->bPropBool = bInPropBool;
}

int32 UTbSimpleSimpleInterfaceMsgBusClient::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleSimpleInterfaceMsgBusClient::SetPropInt_Implementation(int32 InPropInt)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropInt_Implementation() == InPropInt)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->PropInt == InPropInt)
	{
		return;
	}

	auto msg = new FTbSimpleSimpleInterfaceSetPropIntRequestMessage();
	msg->PropInt = InPropInt;

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceSetPropIntRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->PropInt = InPropInt;
}

int32 UTbSimpleSimpleInterfaceMsgBusClient::GetPropInt32_Implementation() const
{
	return PropInt32;
}

void UTbSimpleSimpleInterfaceMsgBusClient::SetPropInt32_Implementation(int32 InPropInt32)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropInt32_Implementation() == InPropInt32)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->PropInt32 == InPropInt32)
	{
		return;
	}

	auto msg = new FTbSimpleSimpleInterfaceSetPropInt32RequestMessage();
	msg->PropInt32 = InPropInt32;

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceSetPropInt32RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->PropInt32 = InPropInt32;
}

int64 UTbSimpleSimpleInterfaceMsgBusClient::GetPropInt64_Implementation() const
{
	return PropInt64;
}

void UTbSimpleSimpleInterfaceMsgBusClient::SetPropInt64_Implementation(int64 InPropInt64)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropInt64_Implementation() == InPropInt64)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->PropInt64 == InPropInt64)
	{
		return;
	}

	auto msg = new FTbSimpleSimpleInterfaceSetPropInt64RequestMessage();
	msg->PropInt64 = InPropInt64;

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceSetPropInt64RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->PropInt64 = InPropInt64;
}

float UTbSimpleSimpleInterfaceMsgBusClient::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTbSimpleSimpleInterfaceMsgBusClient::SetPropFloat_Implementation(float InPropFloat)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropFloat_Implementation() == InPropFloat)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->PropFloat == InPropFloat)
	{
		return;
	}

	auto msg = new FTbSimpleSimpleInterfaceSetPropFloatRequestMessage();
	msg->PropFloat = InPropFloat;

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceSetPropFloatRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->PropFloat = InPropFloat;
}

float UTbSimpleSimpleInterfaceMsgBusClient::GetPropFloat32_Implementation() const
{
	return PropFloat32;
}

void UTbSimpleSimpleInterfaceMsgBusClient::SetPropFloat32_Implementation(float InPropFloat32)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropFloat32_Implementation() == InPropFloat32)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->PropFloat32 == InPropFloat32)
	{
		return;
	}

	auto msg = new FTbSimpleSimpleInterfaceSetPropFloat32RequestMessage();
	msg->PropFloat32 = InPropFloat32;

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceSetPropFloat32RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->PropFloat32 = InPropFloat32;
}

double UTbSimpleSimpleInterfaceMsgBusClient::GetPropFloat64_Implementation() const
{
	return PropFloat64;
}

void UTbSimpleSimpleInterfaceMsgBusClient::SetPropFloat64_Implementation(double InPropFloat64)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropFloat64_Implementation() == InPropFloat64)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->PropFloat64 == InPropFloat64)
	{
		return;
	}

	auto msg = new FTbSimpleSimpleInterfaceSetPropFloat64RequestMessage();
	msg->PropFloat64 = InPropFloat64;

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceSetPropFloat64RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->PropFloat64 = InPropFloat64;
}

FString UTbSimpleSimpleInterfaceMsgBusClient::GetPropString_Implementation() const
{
	return PropString;
}

void UTbSimpleSimpleInterfaceMsgBusClient::SetPropString_Implementation(const FString& InPropString)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropString_Implementation() == InPropString)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->PropStringMutex));
		if (_SentData->PropString == InPropString)
		{
			return;
		}
	}

	auto msg = new FTbSimpleSimpleInterfaceSetPropStringRequestMessage();
	msg->PropString = InPropString;

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceSetPropStringRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	FScopeLock Lock(&(_SentData->PropStringMutex));
	_SentData->PropString = InPropString;
}

void UTbSimpleSimpleInterfaceMsgBusClient::FuncNoReturnValue_Implementation(bool bInParamBool)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return;
	}

	auto msg = new FTbSimpleSimpleInterfaceFuncNoReturnValueRequestMessage();
	msg->bParamBool = bInParamBool;

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceFuncNoReturnValueRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return;
}

bool UTbSimpleSimpleInterfaceMsgBusClient::FuncBool_Implementation(bool bInParamBool)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return false;
	}

	auto msg = new FTbSimpleSimpleInterfaceFuncBoolRequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->bParamBool = bInParamBool;
	TPromise<bool> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceFuncBoolRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnFuncBoolReply(const FTbSimpleSimpleInterfaceFuncBoolReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

int32 UTbSimpleSimpleInterfaceMsgBusClient::FuncInt_Implementation(int32 InParamInt)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return 0;
	}

	auto msg = new FTbSimpleSimpleInterfaceFuncIntRequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamInt = InParamInt;
	TPromise<int32> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceFuncIntRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnFuncIntReply(const FTbSimpleSimpleInterfaceFuncIntReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

int32 UTbSimpleSimpleInterfaceMsgBusClient::FuncInt32_Implementation(int32 InParamInt32)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return 0;
	}

	auto msg = new FTbSimpleSimpleInterfaceFuncInt32RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamInt32 = InParamInt32;
	TPromise<int32> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceFuncInt32RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnFuncInt32Reply(const FTbSimpleSimpleInterfaceFuncInt32ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

int64 UTbSimpleSimpleInterfaceMsgBusClient::FuncInt64_Implementation(int64 InParamInt64)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return 0LL;
	}

	auto msg = new FTbSimpleSimpleInterfaceFuncInt64RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamInt64 = InParamInt64;
	TPromise<int64> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceFuncInt64RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnFuncInt64Reply(const FTbSimpleSimpleInterfaceFuncInt64ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

float UTbSimpleSimpleInterfaceMsgBusClient::FuncFloat_Implementation(float InParamFloat)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return 0.0f;
	}

	auto msg = new FTbSimpleSimpleInterfaceFuncFloatRequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamFloat = InParamFloat;
	TPromise<float> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceFuncFloatRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnFuncFloatReply(const FTbSimpleSimpleInterfaceFuncFloatReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

float UTbSimpleSimpleInterfaceMsgBusClient::FuncFloat32_Implementation(float InParamFloat32)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return 0.0f;
	}

	auto msg = new FTbSimpleSimpleInterfaceFuncFloat32RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamFloat32 = InParamFloat32;
	TPromise<float> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceFuncFloat32RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnFuncFloat32Reply(const FTbSimpleSimpleInterfaceFuncFloat32ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

double UTbSimpleSimpleInterfaceMsgBusClient::FuncFloat64_Implementation(double InParamFloat)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return 0.0;
	}

	auto msg = new FTbSimpleSimpleInterfaceFuncFloat64RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamFloat = InParamFloat;
	TPromise<double> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceFuncFloat64RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnFuncFloat64Reply(const FTbSimpleSimpleInterfaceFuncFloat64ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

FString UTbSimpleSimpleInterfaceMsgBusClient::FuncString_Implementation(const FString& InParamString)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return FString();
	}

	auto msg = new FTbSimpleSimpleInterfaceFuncStringRequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamString = InParamString;
	TPromise<FString> Promise;
	StorePromise(msg->ResponseId, Promise);

	TbSimpleSimpleInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleInterfaceFuncStringRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnFuncStringReply(const FTbSimpleSimpleInterfaceFuncStringReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnSigBool(const FTbSimpleSimpleInterfaceSigBoolSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigBoolSignal.Broadcast(InMessage.bParamBool);
	return;
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnSigInt(const FTbSimpleSimpleInterfaceSigIntSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigIntSignal.Broadcast(InMessage.ParamInt);
	return;
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnSigInt32(const FTbSimpleSimpleInterfaceSigInt32SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigInt32Signal.Broadcast(InMessage.ParamInt32);
	return;
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnSigInt64(const FTbSimpleSimpleInterfaceSigInt64SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigInt64Signal.Broadcast(InMessage.ParamInt64);
	return;
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnSigFloat(const FTbSimpleSimpleInterfaceSigFloatSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigFloatSignal.Broadcast(InMessage.ParamFloat);
	return;
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnSigFloat32(const FTbSimpleSimpleInterfaceSigFloat32SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigFloat32Signal.Broadcast(InMessage.ParamFloat32);
	return;
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnSigFloat64(const FTbSimpleSimpleInterfaceSigFloat64SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigFloat64Signal.Broadcast(InMessage.ParamFloat64);
	return;
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnSigString(const FTbSimpleSimpleInterfaceSigStringSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigStringSignal.Broadcast(InMessage.ParamString);
	return;
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnPropBoolChanged(const FTbSimpleSimpleInterfacePropBoolChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bbPropBoolChanged = InMessage.bPropBool != bPropBool;
	if (bbPropBoolChanged)
	{
		bPropBool = InMessage.bPropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(bPropBool);
	}
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnPropIntChanged(const FTbSimpleSimpleInterfacePropIntChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropIntChanged = InMessage.PropInt != PropInt;
	if (bPropIntChanged)
	{
		PropInt = InMessage.PropInt;
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnPropInt32Changed(const FTbSimpleSimpleInterfacePropInt32ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropInt32Changed = InMessage.PropInt32 != PropInt32;
	if (bPropInt32Changed)
	{
		PropInt32 = InMessage.PropInt32;
		Execute__GetSignals(this)->OnPropInt32Changed.Broadcast(PropInt32);
	}
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnPropInt64Changed(const FTbSimpleSimpleInterfacePropInt64ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropInt64Changed = InMessage.PropInt64 != PropInt64;
	if (bPropInt64Changed)
	{
		PropInt64 = InMessage.PropInt64;
		Execute__GetSignals(this)->OnPropInt64Changed.Broadcast(PropInt64);
	}
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnPropFloatChanged(const FTbSimpleSimpleInterfacePropFloatChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropFloatChanged = InMessage.PropFloat != PropFloat;
	if (bPropFloatChanged)
	{
		PropFloat = InMessage.PropFloat;
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnPropFloat32Changed(const FTbSimpleSimpleInterfacePropFloat32ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropFloat32Changed = InMessage.PropFloat32 != PropFloat32;
	if (bPropFloat32Changed)
	{
		PropFloat32 = InMessage.PropFloat32;
		Execute__GetSignals(this)->OnPropFloat32Changed.Broadcast(PropFloat32);
	}
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnPropFloat64Changed(const FTbSimpleSimpleInterfacePropFloat64ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropFloat64Changed = InMessage.PropFloat64 != PropFloat64;
	if (bPropFloat64Changed)
	{
		PropFloat64 = InMessage.PropFloat64;
		Execute__GetSignals(this)->OnPropFloat64Changed.Broadcast(PropFloat64);
	}
}

void UTbSimpleSimpleInterfaceMsgBusClient::OnPropStringChanged(const FTbSimpleSimpleInterfacePropStringChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSimpleSimpleInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropStringChanged = InMessage.PropString != PropString;
	if (bPropStringChanged)
	{
		PropString = InMessage.PropString;
		Execute__GetSignals(this)->OnPropStringChanged.Broadcast(PropString);
	}
}

template <typename ResultType>
bool UTbSimpleSimpleInterfaceMsgBusClient::StorePromise(const FGuid& Id, TPromise<ResultType>& Promise)
{
	FScopeLock Lock(&ReplyPromisesMapCS);
	return ReplyPromisesMap.Add(Id, &Promise) != nullptr;
}

template <typename ResultType>
bool UTbSimpleSimpleInterfaceMsgBusClient::FulfillPromise(const FGuid& Id, const ResultType& Value)
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

template bool UTbSimpleSimpleInterfaceMsgBusClient::StorePromise<FString>(const FGuid& Id, TPromise<FString>& Promise);
template bool UTbSimpleSimpleInterfaceMsgBusClient::FulfillPromise<FString>(const FGuid& Id, const FString& Value);
template bool UTbSimpleSimpleInterfaceMsgBusClient::StorePromise<bool>(const FGuid& Id, TPromise<bool>& Promise);
template bool UTbSimpleSimpleInterfaceMsgBusClient::FulfillPromise<bool>(const FGuid& Id, const bool& Value);
template bool UTbSimpleSimpleInterfaceMsgBusClient::StorePromise<double>(const FGuid& Id, TPromise<double>& Promise);
template bool UTbSimpleSimpleInterfaceMsgBusClient::FulfillPromise<double>(const FGuid& Id, const double& Value);
template bool UTbSimpleSimpleInterfaceMsgBusClient::StorePromise<float>(const FGuid& Id, TPromise<float>& Promise);
template bool UTbSimpleSimpleInterfaceMsgBusClient::FulfillPromise<float>(const FGuid& Id, const float& Value);
template bool UTbSimpleSimpleInterfaceMsgBusClient::StorePromise<int32>(const FGuid& Id, TPromise<int32>& Promise);
template bool UTbSimpleSimpleInterfaceMsgBusClient::FulfillPromise<int32>(const FGuid& Id, const int32& Value);
template bool UTbSimpleSimpleInterfaceMsgBusClient::StorePromise<int64>(const FGuid& Id, TPromise<int64>& Promise);
template bool UTbSimpleSimpleInterfaceMsgBusClient::FulfillPromise<int64>(const FGuid& Id, const int64& Value);