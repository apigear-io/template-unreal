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

#include "TbEnumEnumInterfaceOLink.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "apig/TbEnum.json.adapter.h"
#include "unrealolink.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;

namespace TbEnum
{
namespace EnumInterface
{
namespace Private
{
OLinkService::OLinkService()
	: ITbEnumEnumInterfaceInterface()
	, m_node(nullptr)
	, m_isReady(false)
	, Prop0(ETbEnumEnum0::VALUE0)
	, Prop1(ETbEnumEnum1::VALUE1)
	, Prop2(ETbEnumEnum2::VALUE2)
	, Prop3(ETbEnumEnum3::VALUE3)
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

FTbEnumEnumInterfaceSig0Delegate& OLinkService::GetSig0SignalDelegate()
{
	return Sig0Signal;
}

FTbEnumEnumInterfaceSig1Delegate& OLinkService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

FTbEnumEnumInterfaceSig2Delegate& OLinkService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

FTbEnumEnumInterfaceSig3Delegate& OLinkService::GetSig3SignalDelegate()
{
	return Sig3Signal;
}

ETbEnumEnum0 OLinkService::GetProp0() const
{
	return Prop0;
}

void OLinkService::SetProp0(const ETbEnumEnum0& InProp0)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.enum.EnumInterface/prop0", InProp0);
}

FTbEnumEnumInterfaceProp0ChangedDelegate& OLinkService::GetProp0ChangedDelegate()
{
	return Prop0Changed;
}
ETbEnumEnum1 OLinkService::GetProp1() const
{
	return Prop1;
}

void OLinkService::SetProp1(const ETbEnumEnum1& InProp1)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.enum.EnumInterface/prop1", InProp1);
}

FTbEnumEnumInterfaceProp1ChangedDelegate& OLinkService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}
ETbEnumEnum2 OLinkService::GetProp2() const
{
	return Prop2;
}

void OLinkService::SetProp2(const ETbEnumEnum2& InProp2)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.enum.EnumInterface/prop2", InProp2);
}

FTbEnumEnumInterfaceProp2ChangedDelegate& OLinkService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}
ETbEnumEnum3 OLinkService::GetProp3() const
{
	return Prop3;
}

void OLinkService::SetProp3(const ETbEnumEnum3& InProp3)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.enum.EnumInterface/prop3", InProp3);
}

FTbEnumEnumInterfaceProp3ChangedDelegate& OLinkService::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}

ETbEnumEnum0 OLinkService::Func0(const ETbEnumEnum0& Param0)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return ETbEnumEnum0::VALUE0;
	}
	TPromise<ETbEnumEnum0> Promise;
	Async(EAsyncExecution::Thread,
		[Param0, &Promise, this]()
		{
			InvokeReplyFunc GetEnumInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<ETbEnumEnum0>()); };
			m_node->invokeRemote("tb.enum.EnumInterface/func0", {Param0}, GetEnumInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

ETbEnumEnum1 OLinkService::Func1(const ETbEnumEnum1& Param1)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return ETbEnumEnum1::VALUE1;
	}
	TPromise<ETbEnumEnum1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			InvokeReplyFunc GetEnumInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<ETbEnumEnum1>()); };
			m_node->invokeRemote("tb.enum.EnumInterface/func1", {Param1}, GetEnumInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

ETbEnumEnum2 OLinkService::Func2(const ETbEnumEnum2& Param2)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return ETbEnumEnum2::VALUE2;
	}
	TPromise<ETbEnumEnum2> Promise;
	Async(EAsyncExecution::Thread,
		[Param2, &Promise, this]()
		{
			InvokeReplyFunc GetEnumInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<ETbEnumEnum2>()); };
			m_node->invokeRemote("tb.enum.EnumInterface/func2", {Param2}, GetEnumInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

ETbEnumEnum3 OLinkService::Func3(const ETbEnumEnum3& Param3)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return ETbEnumEnum3::VALUE3;
	}
	TPromise<ETbEnumEnum3> Promise;
	Async(EAsyncExecution::Thread,
		[Param3, &Promise, this]()
		{
			InvokeReplyFunc GetEnumInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<ETbEnumEnum3>()); };
			m_node->invokeRemote("tb.enum.EnumInterface/func3", {Param3}, GetEnumInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void OLinkService::applyState(const nlohmann::json& fields)
{
	if (fields.contains("prop0"))
	{
		if (Prop0 != fields["prop0"].get<ETbEnumEnum0>())
		{
			Prop0 = fields["prop0"].get<ETbEnumEnum0>();
			Prop0Changed.Broadcast(Prop0);
		}
	}
	if (fields.contains("prop1"))
	{
		if (Prop1 != fields["prop1"].get<ETbEnumEnum1>())
		{
			Prop1 = fields["prop1"].get<ETbEnumEnum1>();
			Prop1Changed.Broadcast(Prop1);
		}
	}
	if (fields.contains("prop2"))
	{
		if (Prop2 != fields["prop2"].get<ETbEnumEnum2>())
		{
			Prop2 = fields["prop2"].get<ETbEnumEnum2>();
			Prop2Changed.Broadcast(Prop2);
		}
	}
	if (fields.contains("prop3"))
	{
		if (Prop3 != fields["prop3"].get<ETbEnumEnum3>())
		{
			Prop3 = fields["prop3"].get<ETbEnumEnum3>();
			Prop3Changed.Broadcast(Prop3);
		}
	}
}

std::string OLinkService::olinkObjectName()
{
	return "tb.enum.EnumInterface";
}

void OLinkService::olinkOnSignal(std::string name, nlohmann::json args)
{
	std::string path = Name::pathFromName(name);
	if (path == "sig0")
	{
		Sig0Signal.Broadcast(args[0].get<ETbEnumEnum0>());
		return;
	}
	if (path == "sig1")
	{
		Sig1Signal.Broadcast(args[0].get<ETbEnumEnum1>());
		return;
	}
	if (path == "sig2")
	{
		Sig2Signal.Broadcast(args[0].get<ETbEnumEnum2>());
		return;
	}
	if (path == "sig3")
	{
		Sig3Signal.Broadcast(args[0].get<ETbEnumEnum3>());
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
} // namespace EnumInterface
} // namespace TbEnum
