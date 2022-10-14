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

#include "TbSame1SameStruct2InterfaceOLink.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "apig/TbSame1.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;

namespace TbSame1
{
namespace SameStruct2Interface
{
namespace Private
{
OLinkService::OLinkService()
	: ITbSame1SameStruct2InterfaceInterface()
	, m_node(nullptr)
	, m_isReady(false)
	, Prop1(FTbSame1Struct2())
	, Prop2(FTbSame1Struct2())
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->Connect();
		AGCM->GetOLinkConnection()->linkObjectSource(olinkObjectName());
	}
	m_node = ClientRegistry::get().addObjectSink(this);
}

OLinkService::~OLinkService()
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

FTbSame1SameStruct2InterfaceSig1Delegate& OLinkService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

FTbSame1SameStruct2InterfaceSig2Delegate& OLinkService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

FTbSame1Struct2 OLinkService::GetProp1_Implementation() const
{
	return Prop1;
}

void OLinkService::SetProp1_Implementation(const FTbSame1Struct2& InProp1)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.same1.SameStruct2Interface/prop1", InProp1);
}

FTbSame1SameStruct2InterfaceProp1ChangedDelegate& OLinkService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}
FTbSame1Struct2 OLinkService::GetProp2_Implementation() const
{
	return Prop2;
}

void OLinkService::SetProp2_Implementation(const FTbSame1Struct2& InProp2)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.same1.SameStruct2Interface/prop2", InProp2);
}

FTbSame1SameStruct2InterfaceProp2ChangedDelegate& OLinkService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

FTbSame1Struct1 OLinkService::Func1_Implementation(const FTbSame1Struct1& Param1)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return FTbSame1Struct1();
	}
	TPromise<FTbSame1Struct1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			InvokeReplyFunc GetSameStruct2InterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTbSame1Struct1>()); };
			m_node->invokeRemote("tb.same1.SameStruct2Interface/func1", {Param1}, GetSameStruct2InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTbSame1Struct1 OLinkService::Func2_Implementation(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return FTbSame1Struct1();
	}
	TPromise<FTbSame1Struct1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, &Promise, this]()
		{
			InvokeReplyFunc GetSameStruct2InterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTbSame1Struct1>()); };
			m_node->invokeRemote("tb.same1.SameStruct2Interface/func2", {Param1, Param2}, GetSameStruct2InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void OLinkService::applyState(const nlohmann::json& fields)
{
	if (fields.contains("prop1"))
	{
		if (Prop1 != fields["prop1"].get<FTbSame1Struct2>())
		{
			Prop1 = fields["prop1"].get<FTbSame1Struct2>();
			Prop1Changed.Broadcast(Prop1);
		}
	}
	if (fields.contains("prop2"))
	{
		if (Prop2 != fields["prop2"].get<FTbSame1Struct2>())
		{
			Prop2 = fields["prop2"].get<FTbSame1Struct2>();
			Prop2Changed.Broadcast(Prop2);
		}
	}
}

std::string OLinkService::olinkObjectName()
{
	return "tb.same1.SameStruct2Interface";
}

void OLinkService::olinkOnSignal(std::string name, nlohmann::json args)
{
	std::string path = Name::pathFromName(name);
	if (path == "sig1")
	{
		Sig1Signal.Broadcast(args[0].get<FTbSame1Struct1>());
		return;
	}
	if (path == "sig2")
	{
		Sig2Signal.Broadcast(args[0].get<FTbSame1Struct1>(), args[1].get<FTbSame1Struct2>());
		return;
	}
}

void OLinkService::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
	std::string path = Name::pathFromName(name);
	applyState({{path, value}});
}

void OLinkService::olinkOnInit(std::string name, nlohmann::json props, IClientNode* node)
{
	m_isReady = true;
	m_node = node;
	applyState(props);
	// call isReady();
}

void OLinkService::olinkOnRelease()
{
	m_isReady = false;
	m_node = nullptr;
}

} // namespace Private
} // namespace SameStruct2Interface
} // namespace TbSame1
