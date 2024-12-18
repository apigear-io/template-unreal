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

#include "Generated/MsgBus/TbSimpleEmptyInterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSimpleEmptyInterfaceMsgBusMessages.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "Misc/DateTime.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "GenericPlatform/GenericPlatformTime.h"
#include "MessageEndpointBuilder.h"
#include "MessageEndpoint.h"
DEFINE_LOG_CATEGORY(LogTbSimpleEmptyInterfaceMsgBusClient);

UTbSimpleEmptyInterfaceMsgBusClient::UTbSimpleEmptyInterfaceMsgBusClient()
	: UAbstractTbSimpleEmptyInterface()
{
}

UTbSimpleEmptyInterfaceMsgBusClient::~UTbSimpleEmptyInterfaceMsgBusClient() = default;

void UTbSimpleEmptyInterfaceMsgBusClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleEmptyInterfaceMsgBusClient::Deinitialize()
{
	_Disconnect();

	Super::Deinitialize();
}

void UTbSimpleEmptyInterfaceMsgBusClient::_Connect()
{
	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTbSimpleEmptyInterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (_IsConnected())
	{
		UE_LOG(LogTbSimpleEmptyInterfaceMsgBusClient, Log, TEXT("Already connected, cannot connect again."));
		return;
	}

	if (TbSimpleEmptyInterfaceMsgBusEndpoint.IsValid() && !ServiceAddress.IsValid())
	{
		_DiscoverService();
		return;
	}

	// clang-format off
	TbSimpleEmptyInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSimple/EmptyInterface/Client")
		.Handling<FTbSimpleEmptyInterfaceInitMessage>(this, &UTbSimpleEmptyInterfaceMsgBusClient::OnConnectionInit)
		.Handling<FTbSimpleEmptyInterfacePongMessage>(this, &UTbSimpleEmptyInterfaceMsgBusClient::OnPong)
		.Handling<FTbSimpleEmptyInterfaceServiceDisconnectMessage>(this, &UTbSimpleEmptyInterfaceMsgBusClient::OnServiceClosedConnection)
		.Build();
	// clang-format on

	_DiscoverService();
}

void UTbSimpleEmptyInterfaceMsgBusClient::_Disconnect()
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

	auto msg = new FTbSimpleEmptyInterfaceClientDisconnectMessage();

	TbSimpleEmptyInterfaceMsgBusEndpoint->Send<FTbSimpleEmptyInterfaceClientDisconnectMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	TbSimpleEmptyInterfaceMsgBusEndpoint.Reset();
	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

void UTbSimpleEmptyInterfaceMsgBusClient::_DiscoverService()
{
	if (!TbSimpleEmptyInterfaceMsgBusEndpoint.IsValid())
	{
		return;
	}

	auto msg = new FTbSimpleEmptyInterfaceDiscoveryMessage();
	msg->ClientPingIntervalMS = _HeartbeatIntervalMS;

	TbSimpleEmptyInterfaceMsgBusEndpoint->Publish<FTbSimpleEmptyInterfaceDiscoveryMessage>(msg);
}

bool UTbSimpleEmptyInterfaceMsgBusClient::_IsConnected() const
{
	return TbSimpleEmptyInterfaceMsgBusEndpoint.IsValid() && ServiceAddress.IsValid();
}

void UTbSimpleEmptyInterfaceMsgBusClient::OnConnectionInit(const FTbSimpleEmptyInterfaceInitMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress.IsValid())
	{
		UE_LOG(LogTbSimpleEmptyInterfaceMsgBusClient, Warning, TEXT("Got a second init message - should not happen"));
		return;
	}

	ServiceAddress = Context->GetSender();

	_ConnectionStatusChanged.Broadcast(true);
}

void UTbSimpleEmptyInterfaceMsgBusClient::_OnHeartbeat()
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
		UE_LOG(LogTbSimpleEmptyInterfaceMsgBusClient, Warning, TEXT("Heartbeat failed. Client has no connection to service. Reconnecting ..."));

		_Connect();
		return;
	}

	auto msg = new FTbSimpleEmptyInterfacePingMessage();
	msg->Timestamp = FPlatformTime::Seconds();

	TbSimpleEmptyInterfaceMsgBusEndpoint->Send<FTbSimpleEmptyInterfacePingMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
}

void UTbSimpleEmptyInterfaceMsgBusClient::OnPong(const FTbSimpleEmptyInterfacePongMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
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

const FTbSimpleEmptyInterfaceStats& UTbSimpleEmptyInterfaceMsgBusClient::_GetStats() const
{
	return Stats;
}

void UTbSimpleEmptyInterfaceMsgBusClient::OnServiceClosedConnection(const FTbSimpleEmptyInterfaceServiceDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		return;
	}

	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}