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

#include "TbSame2SameStruct2InterfaceOLink.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "apig/TbSame2.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;
UTbSame2SameStruct2InterfaceOLinkService::UTbSame2SameStruct2InterfaceOLinkService()
	: ITbSame2SameStruct2InterfaceInterface()
	, m_node(nullptr)
	, m_isReady(false)
	, Prop1(FTbSame2Struct2())
	, Prop2(FTbSame2Struct2())
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->Connect();
		AGCM->GetOLinkConnection()->linkObjectSource(olinkObjectName());
	}
	m_node = ClientRegistry::get().addObjectSink(this);
}

UTbSame2SameStruct2InterfaceOLinkService::~UTbSame2SameStruct2InterfaceOLinkService()
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

void UTbSame2SameStruct2InterfaceOLinkService::BroadcastSig1_Implementation(const FTbSame2Struct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTbSame2SameStruct2InterfaceSig1Delegate& UTbSame2SameStruct2InterfaceOLinkService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame2SameStruct2InterfaceOLinkService::BroadcastSig2_Implementation(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
}

FTbSame2SameStruct2InterfaceSig2Delegate& UTbSame2SameStruct2InterfaceOLinkService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTbSame2SameStruct2InterfaceOLinkService::BroadcastProp1Changed_Implementation(const FTbSame2Struct2& InProp1)
{
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

FTbSame2Struct2 UTbSame2SameStruct2InterfaceOLinkService::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame2SameStruct2InterfaceOLinkService::SetProp1_Implementation(const FTbSame2Struct2& InProp1)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.same2.SameStruct2Interface/prop1", InProp1);
}

FTbSame2SameStruct2InterfaceProp1ChangedDelegate& UTbSame2SameStruct2InterfaceOLinkService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbSame2SameStruct2InterfaceOLinkService::BroadcastProp2Changed_Implementation(const FTbSame2Struct2& InProp2)
{
	Prop2 = InProp2;
	Prop2Changed.Broadcast(InProp2);
}

FTbSame2Struct2 UTbSame2SameStruct2InterfaceOLinkService::GetProp2_Implementation() const
{
	return Prop2;
}

void UTbSame2SameStruct2InterfaceOLinkService::SetProp2_Implementation(const FTbSame2Struct2& InProp2)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.same2.SameStruct2Interface/prop2", InProp2);
}

FTbSame2SameStruct2InterfaceProp2ChangedDelegate& UTbSame2SameStruct2InterfaceOLinkService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

FTbSame2Struct1 UTbSame2SameStruct2InterfaceOLinkService::Func1_Implementation(const FTbSame2Struct1& Param1)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return FTbSame2Struct1();
	}
	TPromise<FTbSame2Struct1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			InvokeReplyFunc GetSameStruct2InterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTbSame2Struct1>()); };
			m_node->invokeRemote("tb.same2.SameStruct2Interface/func1", {Param1}, GetSameStruct2InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTbSame2Struct1 UTbSame2SameStruct2InterfaceOLinkService::Func2_Implementation(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return FTbSame2Struct1();
	}
	TPromise<FTbSame2Struct1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, &Promise, this]()
		{
			InvokeReplyFunc GetSameStruct2InterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTbSame2Struct1>()); };
			m_node->invokeRemote("tb.same2.SameStruct2Interface/func2", {Param1, Param2}, GetSameStruct2InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTbSame2SameStruct2InterfaceOLinkService::applyState(const nlohmann::json& fields)
{
	if (fields.contains("prop1"))
	{
		if (Prop1 != fields["prop1"].get<FTbSame2Struct2>())
		{
			Prop1 = fields["prop1"].get<FTbSame2Struct2>();
			Execute_BroadcastProp1Changed(this, Prop1);
		}
	}
	if (fields.contains("prop2"))
	{
		if (Prop2 != fields["prop2"].get<FTbSame2Struct2>())
		{
			Prop2 = fields["prop2"].get<FTbSame2Struct2>();
			Execute_BroadcastProp2Changed(this, Prop2);
		}
	}
}

std::string UTbSame2SameStruct2InterfaceOLinkService::olinkObjectName()
{
	return "tb.same2.SameStruct2Interface";
}

void UTbSame2SameStruct2InterfaceOLinkService::olinkOnSignal(std::string name, nlohmann::json args)
{
	std::string path = Name::pathFromName(name);
	if (path == "sig1")
	{
		Execute_BroadcastSig1(this, args[0].get<FTbSame2Struct1>());
		return;
	}
	if (path == "sig2")
	{
		Execute_BroadcastSig2(this, args[0].get<FTbSame2Struct1>(), args[1].get<FTbSame2Struct2>());
		return;
	}
}

void UTbSame2SameStruct2InterfaceOLinkService::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
	std::string path = Name::pathFromName(name);
	applyState({{path, value}});
}

void UTbSame2SameStruct2InterfaceOLinkService::olinkOnInit(std::string name, nlohmann::json props, IClientNode* node)
{
	m_isReady = true;
	m_node = node;
	applyState(props);
	// call isReady();
}

void UTbSame2SameStruct2InterfaceOLinkService::olinkOnRelease()
{
	m_isReady = false;
	m_node = nullptr;
}
