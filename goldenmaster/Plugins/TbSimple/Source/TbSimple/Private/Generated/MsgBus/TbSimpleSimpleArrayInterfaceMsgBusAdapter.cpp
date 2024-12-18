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

#include "Generated/MsgBus/TbSimpleSimpleArrayInterfaceMsgBusAdapter.h"
#include "Generated/MsgBus/TbSimpleSimpleArrayInterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTbSimpleSimpleArrayInterfaceMsgBusAdapter::UTbSimpleSimpleArrayInterfaceMsgBusAdapter()
{
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::Deinitialize()
{
	_StopListening();

	Super::Deinitialize();
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::_StartListening()
{
	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	TbSimpleSimpleArrayInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSimple/SimpleArrayInterface/Service")
		.Handling<FTbSimpleSimpleArrayInterfaceDiscoveryMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTbSimpleSimpleArrayInterfacePingMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPing)
		.Handling<FTbSimpleSimpleArrayInterfaceClientDisconnectMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTbSimpleSimpleArrayInterfaceSetPropBoolRequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropBoolRequest)
		.Handling<FTbSimpleSimpleArrayInterfaceSetPropIntRequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropIntRequest)
		.Handling<FTbSimpleSimpleArrayInterfaceSetPropInt32RequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropInt32Request)
		.Handling<FTbSimpleSimpleArrayInterfaceSetPropInt64RequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropInt64Request)
		.Handling<FTbSimpleSimpleArrayInterfaceSetPropFloatRequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropFloatRequest)
		.Handling<FTbSimpleSimpleArrayInterfaceSetPropFloat32RequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropFloat32Request)
		.Handling<FTbSimpleSimpleArrayInterfaceSetPropFloat64RequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropFloat64Request)
		.Handling<FTbSimpleSimpleArrayInterfaceSetPropStringRequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropStringRequest)
		.Handling<FTbSimpleSimpleArrayInterfaceFuncBoolRequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncBoolRequest)
		.Handling<FTbSimpleSimpleArrayInterfaceFuncIntRequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncIntRequest)
		.Handling<FTbSimpleSimpleArrayInterfaceFuncInt32RequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncInt32Request)
		.Handling<FTbSimpleSimpleArrayInterfaceFuncInt64RequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncInt64Request)
		.Handling<FTbSimpleSimpleArrayInterfaceFuncFloatRequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncFloatRequest)
		.Handling<FTbSimpleSimpleArrayInterfaceFuncFloat32RequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncFloat32Request)
		.Handling<FTbSimpleSimpleArrayInterfaceFuncFloat64RequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncFloat64Request)
		.Handling<FTbSimpleSimpleArrayInterfaceFuncStringRequestMessage>(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncStringRequest)
		.Build();
	// clang-format on

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Subscribe<FTbSimpleSimpleArrayInterfaceDiscoveryMessage>();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::_StopListening()
{
	auto msg = new FTbSimpleSimpleArrayInterfaceServiceDisconnectMessage();

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	TbSimpleSimpleArrayInterfaceMsgBusEndpoint.Reset();
	ConnectedClients.Reset();
}

bool UTbSimpleSimpleArrayInterfaceMsgBusAdapter::_IsListening() const
{
	return TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid();
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::_setBackendService(TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleSimpleArrayInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleSimpleArrayInterface"));
		BackendSignals->OnPropBoolChanged.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropBoolChanged);
		BackendSignals->OnPropIntChanged.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropIntChanged);
		BackendSignals->OnPropInt32Changed.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropInt32Changed);
		BackendSignals->OnPropInt64Changed.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropInt64Changed);
		BackendSignals->OnPropFloatChanged.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropFloatChanged);
		BackendSignals->OnPropFloat32Changed.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropFloat32Changed);
		BackendSignals->OnPropFloat64Changed.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropFloat64Changed);
		BackendSignals->OnPropStringChanged.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropStringChanged);
		BackendSignals->OnPropReadOnlyStringChanged.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropReadOnlyStringChanged);
		BackendSignals->OnSigBoolSignal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigBool);
		BackendSignals->OnSigIntSignal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigInt);
		BackendSignals->OnSigInt32Signal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigInt32);
		BackendSignals->OnSigInt64Signal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigInt64);
		BackendSignals->OnSigFloatSignal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigFloat);
		BackendSignals->OnSigFloat32Signal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigFloat32);
		BackendSignals->OnSigFloat64Signal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigFloat64);
		BackendSignals->OnSigStringSignal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleSimpleArrayInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleSimpleArrayInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSimpleSimpleArrayInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnPropBoolChanged.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropBoolChanged);
	BackendSignals->OnPropIntChanged.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropIntChanged);
	BackendSignals->OnPropInt32Changed.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropInt32Changed);
	BackendSignals->OnPropInt64Changed.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropInt64Changed);
	BackendSignals->OnPropFloatChanged.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropFloatChanged);
	BackendSignals->OnPropFloat32Changed.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropFloat32Changed);
	BackendSignals->OnPropFloat64Changed.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropFloat64Changed);
	BackendSignals->OnPropStringChanged.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropStringChanged);
	BackendSignals->OnPropReadOnlyStringChanged.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropReadOnlyStringChanged);
	BackendSignals->OnSigBoolSignal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigBool);
	BackendSignals->OnSigIntSignal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigInt);
	BackendSignals->OnSigInt32Signal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigInt32);
	BackendSignals->OnSigInt64Signal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigInt64);
	BackendSignals->OnSigFloatSignal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigFloat);
	BackendSignals->OnSigFloat32Signal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigFloat32);
	BackendSignals->OnSigFloat64Signal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigFloat64);
	BackendSignals->OnSigStringSignal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigString);
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnNewClientDiscovered(const FTbSimpleSimpleArrayInterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FMessageAddress& ClientAddress = ConnectedClients.AddDefaulted_GetRef();
	ClientAddress = Context->GetSender();

	auto msg = new FTbSimpleSimpleArrayInterfaceInitMessage();
	msg->PropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	msg->PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
	msg->PropInt32 = BackendService->Execute_GetPropInt32(BackendService.GetObject());
	msg->PropInt64 = BackendService->Execute_GetPropInt64(BackendService.GetObject());
	msg->PropFloat = BackendService->Execute_GetPropFloat(BackendService.GetObject());
	msg->PropFloat32 = BackendService->Execute_GetPropFloat32(BackendService.GetObject());
	msg->PropFloat64 = BackendService->Execute_GetPropFloat64(BackendService.GetObject());
	msg->PropString = BackendService->Execute_GetPropString(BackendService.GetObject());
	msg->PropReadOnlyString = BackendService->Execute_GetPropReadOnlyString(BackendService.GetObject());

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPing(const FTbSimpleSimpleArrayInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleSimpleArrayInterfacePongMessage();
	msg->Timestamp = InMessage.Timestamp;

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfacePongMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnClientDisconnected(const FTbSimpleSimpleArrayInterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	ConnectedClients.Remove(Context->GetSender());
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncBoolRequest(const FTbSimpleSimpleArrayInterfaceFuncBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceFuncBoolReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncBool(BackendService.GetObject(), InMessage.ParamBool);

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceFuncBoolReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncIntRequest(const FTbSimpleSimpleArrayInterfaceFuncIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceFuncIntReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncInt(BackendService.GetObject(), InMessage.ParamInt);

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceFuncIntReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncInt32Request(const FTbSimpleSimpleArrayInterfaceFuncInt32RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceFuncInt32ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncInt32(BackendService.GetObject(), InMessage.ParamInt32);

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceFuncInt32ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncInt64Request(const FTbSimpleSimpleArrayInterfaceFuncInt64RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceFuncInt64ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncInt64(BackendService.GetObject(), InMessage.ParamInt64);

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceFuncInt64ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncFloatRequest(const FTbSimpleSimpleArrayInterfaceFuncFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceFuncFloatReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncFloat(BackendService.GetObject(), InMessage.ParamFloat);

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceFuncFloatReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncFloat32Request(const FTbSimpleSimpleArrayInterfaceFuncFloat32RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceFuncFloat32ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncFloat32(BackendService.GetObject(), InMessage.ParamFloat32);

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceFuncFloat32ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncFloat64Request(const FTbSimpleSimpleArrayInterfaceFuncFloat64RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceFuncFloat64ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncFloat64(BackendService.GetObject(), InMessage.ParamFloat);

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceFuncFloat64ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnFuncStringRequest(const FTbSimpleSimpleArrayInterfaceFuncStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceFuncStringReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncString(BackendService.GetObject(), InMessage.ParamString);

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceFuncStringReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigBool(const TArray<bool>& InParamBool)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceSigBoolSignalMessage();
	msg->ParamBool = InParamBool;
	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceSigBoolSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigInt(const TArray<int32>& InParamInt)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceSigIntSignalMessage();
	msg->ParamInt = InParamInt;
	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceSigIntSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigInt32(const TArray<int32>& InParamInt32)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceSigInt32SignalMessage();
	msg->ParamInt32 = InParamInt32;
	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceSigInt32SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigInt64(const TArray<int64>& InParamInt64)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceSigInt64SignalMessage();
	msg->ParamInt64 = InParamInt64;
	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceSigInt64SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigFloat(const TArray<float>& InParamFloat)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceSigFloatSignalMessage();
	msg->ParamFloat = InParamFloat;
	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceSigFloatSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigFloat32(const TArray<float>& InParamFloa32)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceSigFloat32SignalMessage();
	msg->ParamFloa32 = InParamFloa32;
	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceSigFloat32SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigFloat64(const TArray<double>& InParamFloat64)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceSigFloat64SignalMessage();
	msg->ParamFloat64 = InParamFloat64;
	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceSigFloat64SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSigString(const TArray<FString>& InParamString)
{
	auto msg = new FTbSimpleSimpleArrayInterfaceSigStringSignalMessage();
	msg->ParamString = InParamString;
	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfaceSigStringSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropBoolRequest(const FTbSimpleSimpleArrayInterfaceSetPropBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropBool(BackendService.GetObject(), InMessage.PropBool);
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropBoolChanged(const TArray<bool>& InPropBool)
{
	auto msg = new FTbSimpleSimpleArrayInterfacePropBoolChangedMessage();
	msg->PropBool = InPropBool;

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfacePropBoolChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropIntRequest(const FTbSimpleSimpleArrayInterfaceSetPropIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InMessage.PropInt);
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropIntChanged(const TArray<int32>& InPropInt)
{
	auto msg = new FTbSimpleSimpleArrayInterfacePropIntChangedMessage();
	msg->PropInt = InPropInt;

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfacePropIntChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropInt32Request(const FTbSimpleSimpleArrayInterfaceSetPropInt32RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropInt32(BackendService.GetObject(), InMessage.PropInt32);
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropInt32Changed(const TArray<int32>& InPropInt32)
{
	auto msg = new FTbSimpleSimpleArrayInterfacePropInt32ChangedMessage();
	msg->PropInt32 = InPropInt32;

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfacePropInt32ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropInt64Request(const FTbSimpleSimpleArrayInterfaceSetPropInt64RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropInt64(BackendService.GetObject(), InMessage.PropInt64);
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropInt64Changed(const TArray<int64>& InPropInt64)
{
	auto msg = new FTbSimpleSimpleArrayInterfacePropInt64ChangedMessage();
	msg->PropInt64 = InPropInt64;

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfacePropInt64ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropFloatRequest(const FTbSimpleSimpleArrayInterfaceSetPropFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropFloat(BackendService.GetObject(), InMessage.PropFloat);
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropFloatChanged(const TArray<float>& InPropFloat)
{
	auto msg = new FTbSimpleSimpleArrayInterfacePropFloatChangedMessage();
	msg->PropFloat = InPropFloat;

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfacePropFloatChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropFloat32Request(const FTbSimpleSimpleArrayInterfaceSetPropFloat32RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropFloat32(BackendService.GetObject(), InMessage.PropFloat32);
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropFloat32Changed(const TArray<float>& InPropFloat32)
{
	auto msg = new FTbSimpleSimpleArrayInterfacePropFloat32ChangedMessage();
	msg->PropFloat32 = InPropFloat32;

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfacePropFloat32ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropFloat64Request(const FTbSimpleSimpleArrayInterfaceSetPropFloat64RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropFloat64(BackendService.GetObject(), InMessage.PropFloat64);
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropFloat64Changed(const TArray<double>& InPropFloat64)
{
	auto msg = new FTbSimpleSimpleArrayInterfacePropFloat64ChangedMessage();
	msg->PropFloat64 = InPropFloat64;

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfacePropFloat64ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnSetPropStringRequest(const FTbSimpleSimpleArrayInterfaceSetPropStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropString(BackendService.GetObject(), InMessage.PropString);
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropStringChanged(const TArray<FString>& InPropString)
{
	auto msg = new FTbSimpleSimpleArrayInterfacePropStringChangedMessage();
	msg->PropString = InPropString;

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfacePropStringChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusAdapter::OnPropReadOnlyStringChanged(const FString& InPropReadOnlyString)
{
	auto msg = new FTbSimpleSimpleArrayInterfacePropReadOnlyStringChangedMessage();
	msg->PropReadOnlyString = InPropReadOnlyString;

	if (TbSimpleSimpleArrayInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleSimpleArrayInterfaceMsgBusEndpoint->Send<FTbSimpleSimpleArrayInterfacePropReadOnlyStringChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}
