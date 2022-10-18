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

#include "TbSame2SameEnum1InterfaceOLink.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "apig/TbSame2.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;
UTbSame2SameEnum1InterfaceOLinkService::UTbSame2SameEnum1InterfaceOLinkService()
	: ITbSame2SameEnum1InterfaceInterface()
	, m_node(nullptr)
	, m_isReady(false)
	, Prop1(ETbSame2Enum1::VALUE1)
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->Connect();
		AGCM->GetOLinkConnection()->linkObjectSource(olinkObjectName());
	}
	m_node = ClientRegistry::get().addObjectSink(this);
}

UTbSame2SameEnum1InterfaceOLinkService::~UTbSame2SameEnum1InterfaceOLinkService()
{
	ClientRegistry::get().removeObjectSink(this);
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->unlinkObjectSource(olinkObjectName());
	}
	m_isReady = false;
	m_node = nullptr;
}

void UTbSame2SameEnum1InterfaceOLinkService::BroadcastSig1_Implementation(const ETbSame2Enum1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTbSame2SameEnum1InterfaceSig1Delegate& UTbSame2SameEnum1InterfaceOLinkService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame2SameEnum1InterfaceOLinkService::BroadcastProp1Changed_Implementation(const ETbSame2Enum1& InProp1)
{
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

ETbSame2Enum1 UTbSame2SameEnum1InterfaceOLinkService::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame2SameEnum1InterfaceOLinkService::SetProp1_Implementation(const ETbSame2Enum1& InProp1)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.same2.SameEnum1Interface/prop1", InProp1);
}

FTbSame2SameEnum1InterfaceProp1ChangedDelegate& UTbSame2SameEnum1InterfaceOLinkService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

ETbSame2Enum1 UTbSame2SameEnum1InterfaceOLinkService::Func1_Implementation(const ETbSame2Enum1& Param1)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return ETbSame2Enum1::VALUE1;
	}
	TPromise<ETbSame2Enum1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			InvokeReplyFunc GetSameEnum1InterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<ETbSame2Enum1>()); };
			m_node->invokeRemote("tb.same2.SameEnum1Interface/func1", {Param1}, GetSameEnum1InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTbSame2SameEnum1InterfaceOLinkService::applyState(const nlohmann::json& fields)
{
	if (fields.contains("prop1"))
	{
		if (Prop1 != fields["prop1"].get<ETbSame2Enum1>())
		{
			Prop1 = fields["prop1"].get<ETbSame2Enum1>();
			Prop1Changed.Broadcast(Prop1);
		}
	}
}

std::string UTbSame2SameEnum1InterfaceOLinkService::olinkObjectName()
{
	return "tb.same2.SameEnum1Interface";
}

void UTbSame2SameEnum1InterfaceOLinkService::olinkOnSignal(std::string name, nlohmann::json args)
{
	std::string path = Name::pathFromName(name);
	if (path == "sig1")
	{
		Sig1Signal.Broadcast(args[0].get<ETbSame2Enum1>());
		return;
	}
}

void UTbSame2SameEnum1InterfaceOLinkService::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
	std::string path = Name::pathFromName(name);
	applyState({{path, value}});
}

void UTbSame2SameEnum1InterfaceOLinkService::olinkOnInit(std::string name, nlohmann::json props, IClientNode* node)
{
	m_isReady = true;
	m_node = node;
	applyState(props);
	// call isReady();
}

void UTbSame2SameEnum1InterfaceOLinkService::olinkOnRelease()
{
	m_isReady = false;
	m_node = nullptr;
}
