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

#include "TbSame1SameStruct2InterfaceOLinkClient.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/TbSame1.json.adapter.h"
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

UTbSame1SameStruct2InterfaceOLinkClient::UTbSame1SameStruct2InterfaceOLinkClient()
	: ITbSame1SameStruct2InterfaceInterface()
{
	m_sink = std::make_shared<FUnrealOLinkSink>("tb.same1.SameStruct2Interface");
}

void UTbSame1SameStruct2InterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
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

void UTbSame1SameStruct2InterfaceOLinkClient::Deinitialize()
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

void UTbSame1SameStruct2InterfaceOLinkClient::BroadcastSig1_Implementation(const FTbSame1Struct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTbSame1SameStruct2InterfaceSig1Delegate& UTbSame1SameStruct2InterfaceOLinkClient::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame1SameStruct2InterfaceOLinkClient::BroadcastSig2_Implementation(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
}

FTbSame1SameStruct2InterfaceSig2Delegate& UTbSame1SameStruct2InterfaceOLinkClient::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTbSame1SameStruct2InterfaceOLinkClient::BroadcastProp1Changed_Implementation(const FTbSame1Struct2& InProp1)
{
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

FTbSame1Struct2 UTbSame1SameStruct2InterfaceOLinkClient::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame1SameStruct2InterfaceOLinkClient::SetProp1_Implementation(const FTbSame1Struct2& InProp1)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop1"), InProp1);
}

FTbSame1SameStruct2InterfaceProp1ChangedDelegate& UTbSame1SameStruct2InterfaceOLinkClient::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbSame1SameStruct2InterfaceOLinkClient::BroadcastProp2Changed_Implementation(const FTbSame1Struct2& InProp2)
{
	Prop2 = InProp2;
	Prop2Changed.Broadcast(InProp2);
}

FTbSame1Struct2 UTbSame1SameStruct2InterfaceOLinkClient::GetProp2_Implementation() const
{
	return Prop2;
}

void UTbSame1SameStruct2InterfaceOLinkClient::SetProp2_Implementation(const FTbSame1Struct2& InProp2)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop2"), InProp2);
}

FTbSame1SameStruct2InterfaceProp2ChangedDelegate& UTbSame1SameStruct2InterfaceOLinkClient::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

FTbSame1Struct1 UTbSame1SameStruct2InterfaceOLinkClient::Func1_Implementation(const FTbSame1Struct1& Param1)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return FTbSame1Struct1();
	}
	TPromise<FTbSame1Struct1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSameStruct2InterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTbSame1Struct1>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func1"), {Param1}, GetSameStruct2InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTbSame1Struct1 UTbSame1SameStruct2InterfaceOLinkClient::Func2_Implementation(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return FTbSame1Struct1();
	}
	TPromise<FTbSame1Struct1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetSameStruct2InterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTbSame1Struct1>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func2"), {Param1, Param2}, GetSameStruct2InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTbSame1SameStruct2InterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	if (fields.contains("prop1"))
	{
		if (Prop1 != fields["prop1"].get<FTbSame1Struct2>())
		{
			Prop1 = fields["prop1"].get<FTbSame1Struct2>();
			Execute_BroadcastProp1Changed(this, Prop1);
		}
	}
	if (fields.contains("prop2"))
	{
		if (Prop2 != fields["prop2"].get<FTbSame1Struct2>())
		{
			Prop2 = fields["prop2"].get<FTbSame1Struct2>();
			Execute_BroadcastProp2Changed(this, Prop2);
		}
	}
}

void UTbSame1SameStruct2InterfaceOLinkClient::emitSignal(const std::string& signalId, const nlohmann::json& args)
{
	std::string MemberName = ApiGear::ObjectLink::Name::getMemberName(signalId);
	if (MemberName == "sig1")
	{
		Execute_BroadcastSig1(this, args[0].get<FTbSame1Struct1>());
		return;
	}
	if (MemberName == "sig2")
	{
		Execute_BroadcastSig2(this, args[0].get<FTbSame1Struct1>(), args[1].get<FTbSame1Struct2>());
		return;
	}
}
