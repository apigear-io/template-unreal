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

#include "TbSame2SameEnum2InterfaceOLink.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "apig/TbSame2.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;
UTbSame2SameEnum2InterfaceOLinkService::UTbSame2SameEnum2InterfaceOLinkService()
	: ITbSame2SameEnum2InterfaceInterface()
	, m_node(nullptr)
	, m_isReady(false)
	, Prop1(ETbSame2Enum1::VALUE1)
	, Prop2(ETbSame2Enum2::VALUE1)
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->Connect();
		AGCM->GetOLinkConnection()->linkObjectSource(olinkObjectName());
	}
	m_node = ClientRegistry::get().addObjectSink(this);
}

UTbSame2SameEnum2InterfaceOLinkService::~UTbSame2SameEnum2InterfaceOLinkService()
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

FTbSame2SameEnum2InterfaceSig1Delegate& UTbSame2SameEnum2InterfaceOLinkService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

FTbSame2SameEnum2InterfaceSig2Delegate& UTbSame2SameEnum2InterfaceOLinkService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTbSame2SameEnum2InterfaceOLinkService::GetProp1_Implementation(ETbSame2Enum1& ReturnValue) const
{
	ReturnValue = Prop1;
}

void UTbSame2SameEnum2InterfaceOLinkService::SetProp1_Implementation(const ETbSame2Enum1& InProp1)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.same2.SameEnum2Interface/prop1", InProp1);
}

FTbSame2SameEnum2InterfaceProp1ChangedDelegate& UTbSame2SameEnum2InterfaceOLinkService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}
void UTbSame2SameEnum2InterfaceOLinkService::GetProp2_Implementation(ETbSame2Enum2& ReturnValue) const
{
	ReturnValue = Prop2;
}

void UTbSame2SameEnum2InterfaceOLinkService::SetProp2_Implementation(const ETbSame2Enum2& InProp2)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.same2.SameEnum2Interface/prop2", InProp2);
}

FTbSame2SameEnum2InterfaceProp2ChangedDelegate& UTbSame2SameEnum2InterfaceOLinkService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTbSame2SameEnum2InterfaceOLinkService::Func1_Implementation(ETbSame2Enum1& Result, const ETbSame2Enum1& Param1)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		Result = ETbSame2Enum1::VALUE1;
	}
	TPromise<ETbSame2Enum1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			InvokeReplyFunc GetSameEnum2InterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<ETbSame2Enum1>()); };
			m_node->invokeRemote("tb.same2.SameEnum2Interface/func1", {Param1}, GetSameEnum2InterfaceStateFunc);
		});

	Result = Promise.GetFuture().Get();
}

void UTbSame2SameEnum2InterfaceOLinkService::Func2_Implementation(ETbSame2Enum1& Result, const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		Result = ETbSame2Enum1::VALUE1;
	}
	TPromise<ETbSame2Enum1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, &Promise, this]()
		{
			InvokeReplyFunc GetSameEnum2InterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<ETbSame2Enum1>()); };
			m_node->invokeRemote("tb.same2.SameEnum2Interface/func2", {Param1, Param2}, GetSameEnum2InterfaceStateFunc);
		});

	Result = Promise.GetFuture().Get();
}

void UTbSame2SameEnum2InterfaceOLinkService::applyState(const nlohmann::json& fields)
{
	if (fields.contains("prop1"))
	{
		if (Prop1 != fields["prop1"].get<ETbSame2Enum1>())
		{
			Prop1 = fields["prop1"].get<ETbSame2Enum1>();
			Prop1Changed.Broadcast(Prop1);
		}
	}
	if (fields.contains("prop2"))
	{
		if (Prop2 != fields["prop2"].get<ETbSame2Enum2>())
		{
			Prop2 = fields["prop2"].get<ETbSame2Enum2>();
			Prop2Changed.Broadcast(Prop2);
		}
	}
}

std::string UTbSame2SameEnum2InterfaceOLinkService::olinkObjectName()
{
	return "tb.same2.SameEnum2Interface";
}

void UTbSame2SameEnum2InterfaceOLinkService::olinkOnSignal(std::string name, nlohmann::json args)
{
	std::string path = Name::pathFromName(name);
	if (path == "sig1")
	{
		Sig1Signal.Broadcast(args[0].get<ETbSame2Enum1>());
		return;
	}
	if (path == "sig2")
	{
		Sig2Signal.Broadcast(args[0].get<ETbSame2Enum1>(), args[1].get<ETbSame2Enum2>());
		return;
	}
}

void UTbSame2SameEnum2InterfaceOLinkService::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
	std::string path = Name::pathFromName(name);
	applyState({{path, value}});
}

void UTbSame2SameEnum2InterfaceOLinkService::olinkOnInit(std::string name, nlohmann::json props, IClientNode* node)
{
	m_isReady = true;
	m_node = node;
	applyState(props);
	// call isReady();
}

void UTbSame2SameEnum2InterfaceOLinkService::olinkOnRelease()
{
	m_isReady = false;
	m_node = nullptr;
}
