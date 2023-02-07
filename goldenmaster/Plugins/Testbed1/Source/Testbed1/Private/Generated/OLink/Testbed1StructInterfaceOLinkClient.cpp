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

#include "Generated/olink/Testbed1StructInterfaceOLinkClient.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/Testbed1.json.adapter.h"
#include "unrealolink.h"
#include "unrealolinksink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END

UTestbed1StructInterfaceOLinkClient::UTestbed1StructInterfaceOLinkClient()
	: ITestbed1StructInterfaceInterface()
{
	m_sink = std::make_shared<FUnrealOLinkSink>("testbed1.StructInterface");
}

void UTestbed1StructInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->Connect();
		AGCM->GetOLinkConnection()->node()->registry().addSink(m_sink);
		AGCM->GetOLinkConnection()->linkObjectSource(m_sink->olinkObjectName());
	}

	FUnrealOLinkSink::FPropertyChangedFunc PropertyChangedFunc = [this](const nlohmann::json& props)
	{
		this->applyState(props);
	};
	m_sink->setOnPropertyChangedCallback(PropertyChangedFunc);

	FUnrealOLinkSink::FSignalEmittedFunc SignalEmittedFunc = [this](const std::string& signalName, const nlohmann::json& args)
	{
		this->emitSignal(signalName, args);
	};
	m_sink->setOnSignalEmittedCallback(SignalEmittedFunc);
}

void UTestbed1StructInterfaceOLinkClient::Deinitialize()
{
	// tell the sink that we are gone and should not try to be invoked
	m_sink->resetOnPropertyChangedCallback();
	m_sink->resetOnSignalEmittedCallback();

	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->unlinkObjectSource(m_sink->olinkObjectName());
		AGCM->GetOLinkConnection()->node()->registry().removeSink(m_sink->olinkObjectName());
	}

	Super::Deinitialize();
}

void UTestbed1StructInterfaceOLinkClient::BroadcastSigBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
}

FTestbed1StructInterfaceSigBoolDelegate& UTestbed1StructInterfaceOLinkClient::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTestbed1StructInterfaceOLinkClient::BroadcastSigInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

FTestbed1StructInterfaceSigIntDelegate& UTestbed1StructInterfaceOLinkClient::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTestbed1StructInterfaceOLinkClient::BroadcastSigFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTestbed1StructInterfaceSigFloatDelegate& UTestbed1StructInterfaceOLinkClient::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTestbed1StructInterfaceOLinkClient::BroadcastSigString_Implementation(const FTestbed1StructString& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

FTestbed1StructInterfaceSigStringDelegate& UTestbed1StructInterfaceOLinkClient::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTestbed1StructInterfaceOLinkClient::BroadcastPropBoolChanged_Implementation(const FTestbed1StructBool& InPropBool)
{
	PropBool = InPropBool;
	PropBoolChanged.Broadcast(InPropBool);
}

FTestbed1StructBool UTestbed1StructInterfaceOLinkClient::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructInterfaceOLinkClient::SetPropBool_Implementation(const FTestbed1StructBool& InPropBool)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propBool"), InPropBool);
}

FTestbed1StructInterfacePropBoolChangedDelegate& UTestbed1StructInterfaceOLinkClient::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTestbed1StructInterfaceOLinkClient::BroadcastPropIntChanged_Implementation(const FTestbed1StructInt& InPropInt)
{
	PropInt = InPropInt;
	PropIntChanged.Broadcast(InPropInt);
}

FTestbed1StructInt UTestbed1StructInterfaceOLinkClient::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTestbed1StructInterfaceOLinkClient::SetPropInt_Implementation(const FTestbed1StructInt& InPropInt)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propInt"), InPropInt);
}

FTestbed1StructInterfacePropIntChangedDelegate& UTestbed1StructInterfaceOLinkClient::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTestbed1StructInterfaceOLinkClient::BroadcastPropFloatChanged_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	PropFloat = InPropFloat;
	PropFloatChanged.Broadcast(InPropFloat);
}

FTestbed1StructFloat UTestbed1StructInterfaceOLinkClient::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTestbed1StructInterfaceOLinkClient::SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propFloat"), InPropFloat);
}

FTestbed1StructInterfacePropFloatChangedDelegate& UTestbed1StructInterfaceOLinkClient::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTestbed1StructInterfaceOLinkClient::BroadcastPropStringChanged_Implementation(const FTestbed1StructString& InPropString)
{
	PropString = InPropString;
	PropStringChanged.Broadcast(InPropString);
}

FTestbed1StructString UTestbed1StructInterfaceOLinkClient::GetPropString_Implementation() const
{
	return PropString;
}

void UTestbed1StructInterfaceOLinkClient::SetPropString_Implementation(const FTestbed1StructString& InPropString)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propString"), InPropString);
}

FTestbed1StructInterfacePropStringChangedDelegate& UTestbed1StructInterfaceOLinkClient::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

FTestbed1StructBool UTestbed1StructInterfaceOLinkClient::FuncBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return FTestbed1StructBool();
	}
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[ParamBool, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetStructInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructBool>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcBool"), {ParamBool}, GetStructInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructBool UTestbed1StructInterfaceOLinkClient::FuncInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return FTestbed1StructBool();
	}
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[ParamInt, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetStructInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructBool>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcInt"), {ParamInt}, GetStructInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructFloat UTestbed1StructInterfaceOLinkClient::FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return FTestbed1StructFloat();
	}
	TPromise<FTestbed1StructFloat> Promise;
	Async(EAsyncExecution::Thread,
		[ParamFloat, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetStructInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructFloat>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcFloat"), {ParamFloat}, GetStructInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructString UTestbed1StructInterfaceOLinkClient::FuncString_Implementation(const FTestbed1StructString& ParamString)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return FTestbed1StructString();
	}
	TPromise<FTestbed1StructString> Promise;
	Async(EAsyncExecution::Thread,
		[ParamString, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetStructInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructString>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcString"), {ParamString}, GetStructInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTestbed1StructInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	if (fields.contains("propBool"))
	{
		if (PropBool != fields["propBool"].get<FTestbed1StructBool>())
		{
			PropBool = fields["propBool"].get<FTestbed1StructBool>();
			Execute_BroadcastPropBoolChanged(this, PropBool);
		}
	}
	if (fields.contains("propInt"))
	{
		if (PropInt != fields["propInt"].get<FTestbed1StructInt>())
		{
			PropInt = fields["propInt"].get<FTestbed1StructInt>();
			Execute_BroadcastPropIntChanged(this, PropInt);
		}
	}
	if (fields.contains("propFloat"))
	{
		if (PropFloat != fields["propFloat"].get<FTestbed1StructFloat>())
		{
			PropFloat = fields["propFloat"].get<FTestbed1StructFloat>();
			Execute_BroadcastPropFloatChanged(this, PropFloat);
		}
	}
	if (fields.contains("propString"))
	{
		if (PropString != fields["propString"].get<FTestbed1StructString>())
		{
			PropString = fields["propString"].get<FTestbed1StructString>();
			Execute_BroadcastPropStringChanged(this, PropString);
		}
	}
}

void UTestbed1StructInterfaceOLinkClient::emitSignal(const std::string& signalId, const nlohmann::json& args)
{
	std::string MemberName = ApiGear::ObjectLink::Name::getMemberName(signalId);
	if (MemberName == "sigBool")
	{
		Execute_BroadcastSigBool(this, args[0].get<FTestbed1StructBool>());
		return;
	}
	if (MemberName == "sigInt")
	{
		Execute_BroadcastSigInt(this, args[0].get<FTestbed1StructInt>());
		return;
	}
	if (MemberName == "sigFloat")
	{
		Execute_BroadcastSigFloat(this, args[0].get<FTestbed1StructFloat>());
		return;
	}
	if (MemberName == "sigString")
	{
		Execute_BroadcastSigString(this, args[0].get<FTestbed1StructString>());
		return;
	}
}
