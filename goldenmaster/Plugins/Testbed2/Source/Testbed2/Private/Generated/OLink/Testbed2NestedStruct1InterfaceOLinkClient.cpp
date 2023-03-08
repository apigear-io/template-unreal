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

#include "Generated/OLink/Testbed2NestedStruct1InterfaceOLinkClient.h"
#include "ApiGearSettings.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/Testbed2.json.adapter.h"
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

namespace
{
bool IsTestbed2NestedStruct1InterfaceLogEnabled()
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	return settings->OLINK_EnableDebugLog;
}
} // namespace

UTestbed2NestedStruct1InterfaceOLinkClient::UTestbed2NestedStruct1InterfaceOLinkClient()
	: UAbstractTestbed2NestedStruct1Interface()
{
	m_sink = std::make_shared<FUnrealOLinkSink>("testbed2.NestedStruct1Interface");
}

void UTestbed2NestedStruct1InterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
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

void UTestbed2NestedStruct1InterfaceOLinkClient::Deinitialize()
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

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceOLinkClient::GetProp1_Implementation() const
{
	return Prop1;
}

void UTestbed2NestedStruct1InterfaceOLinkClient::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop1"), InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceOLinkClient::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	if (!m_sink->IsReady())
	{
		if (IsTestbed2NestedStruct1InterfaceLogEnabled())
		{
			UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		}

		return FTestbed2NestedStruct1();
	}
	TPromise<FTestbed2NestedStruct1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetNestedStruct1InterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed2NestedStruct1>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func1"), {Param1}, GetNestedStruct1InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTestbed2NestedStruct1InterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	const bool bProp1Changed = fields.contains("prop1") && (Prop1 != fields["prop1"].get<FTestbed2NestedStruct1>());
	if (bProp1Changed)
	{
		Prop1 = fields["prop1"].get<FTestbed2NestedStruct1>();
		Execute_BroadcastProp1Changed(this, Prop1);
	}
}

void UTestbed2NestedStruct1InterfaceOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "sig1")
	{
		const FTestbed2NestedStruct1& Param1 = args[0].get<FTestbed2NestedStruct1>();
		Execute_BroadcastSig1(this, Param1);
		return;
	}
}
