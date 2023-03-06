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

#include "Generated/OLink/TbSame2SameEnum2InterfaceOLinkClient.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/TbSame2.json.adapter.h"
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

UTbSame2SameEnum2InterfaceOLinkClient::UTbSame2SameEnum2InterfaceOLinkClient()
	: UAbstractTbSame2SameEnum2Interface()
{
	m_sink = std::make_shared<FUnrealOLinkSink>("tb.same2.SameEnum2Interface");
}

void UTbSame2SameEnum2InterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
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

void UTbSame2SameEnum2InterfaceOLinkClient::Deinitialize()
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

ETbSame2Enum1 UTbSame2SameEnum2InterfaceOLinkClient::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame2SameEnum2InterfaceOLinkClient::SetProp1_Implementation(ETbSame2Enum1 InProp1)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop1"), InProp1);
}

ETbSame2Enum2 UTbSame2SameEnum2InterfaceOLinkClient::GetProp2_Implementation() const
{
	return Prop2;
}

void UTbSame2SameEnum2InterfaceOLinkClient::SetProp2_Implementation(ETbSame2Enum2 InProp2)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop2"), InProp2);
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceOLinkClient::Func1_Implementation(ETbSame2Enum1 Param1)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return ETbSame2Enum1::TSE_VALUE1;
	}
	TPromise<ETbSame2Enum1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSameEnum2InterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<ETbSame2Enum1>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func1"), {Param1}, GetSameEnum2InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceOLinkClient::Func2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return ETbSame2Enum1::TSE_VALUE1;
	}
	TPromise<ETbSame2Enum1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSameEnum2InterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<ETbSame2Enum1>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func2"), {Param1, Param2}, GetSameEnum2InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTbSame2SameEnum2InterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	const bool bProp1Changed = fields.contains("prop1") && (Prop1 != fields["prop1"].get<ETbSame2Enum1>());
	if (bProp1Changed)
	{
		Prop1 = fields["prop1"].get<ETbSame2Enum1>();
		Execute_BroadcastProp1Changed(this, Prop1);
	}

	const bool bProp2Changed = fields.contains("prop2") && (Prop2 != fields["prop2"].get<ETbSame2Enum2>());
	if (bProp2Changed)
	{
		Prop2 = fields["prop2"].get<ETbSame2Enum2>();
		Execute_BroadcastProp2Changed(this, Prop2);
	}
}

void UTbSame2SameEnum2InterfaceOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "sig1")
	{
		ETbSame2Enum1 Param1 = args[0].get<ETbSame2Enum1>();
		Execute_BroadcastSig1(this, Param1);
		return;
	}
	if (signalName == "sig2")
	{
		ETbSame2Enum1 Param1 = args[0].get<ETbSame2Enum1>();
		ETbSame2Enum2 Param2 = args[1].get<ETbSame2Enum2>();
		Execute_BroadcastSig2(this, Param1, Param2);
		return;
	}
}
