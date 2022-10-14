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

#include "Testbed2NestedStruct3InterfaceOLink.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "apig/Testbed2.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;

namespace Testbed2
{
namespace NestedStruct3Interface
{
namespace Private
{
OLinkService::OLinkService()
	: ITestbed2NestedStruct3InterfaceInterface()
	, m_node(nullptr)
	, m_isReady(false)
	, Prop1(FTestbed2NestedStruct1())
	, Prop2(FTestbed2NestedStruct2())
	, Prop3(FTestbed2NestedStruct3())
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

FTestbed2NestedStruct3InterfaceSig1Delegate& OLinkService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

FTestbed2NestedStruct3InterfaceSig2Delegate& OLinkService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

FTestbed2NestedStruct3InterfaceSig3Delegate& OLinkService::GetSig3SignalDelegate()
{
	return Sig3Signal;
}

FTestbed2NestedStruct1 OLinkService::GetProp1_Implementation() const
{
	return Prop1;
}

void OLinkService::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed2.NestedStruct3Interface/prop1", InProp1);
}

FTestbed2NestedStruct3InterfaceProp1ChangedDelegate& OLinkService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}
FTestbed2NestedStruct2 OLinkService::GetProp2_Implementation() const
{
	return Prop2;
}

void OLinkService::SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed2.NestedStruct3Interface/prop2", InProp2);
}

FTestbed2NestedStruct3InterfaceProp2ChangedDelegate& OLinkService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}
FTestbed2NestedStruct3 OLinkService::GetProp3_Implementation() const
{
	return Prop3;
}

void OLinkService::SetProp3_Implementation(const FTestbed2NestedStruct3& InProp3)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed2.NestedStruct3Interface/prop3", InProp3);
}

FTestbed2NestedStruct3InterfaceProp3ChangedDelegate& OLinkService::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}

FTestbed2NestedStruct1 OLinkService::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return FTestbed2NestedStruct1();
	}
	TPromise<FTestbed2NestedStruct1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			InvokeReplyFunc GetNestedStruct3InterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed2NestedStruct1>()); };
			m_node->invokeRemote("testbed2.NestedStruct3Interface/func1", {Param1}, GetNestedStruct3InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed2NestedStruct1 OLinkService::Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return FTestbed2NestedStruct1();
	}
	TPromise<FTestbed2NestedStruct1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, &Promise, this]()
		{
			InvokeReplyFunc GetNestedStruct3InterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed2NestedStruct1>()); };
			m_node->invokeRemote("testbed2.NestedStruct3Interface/func2", {Param1, Param2}, GetNestedStruct3InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed2NestedStruct1 OLinkService::Func3_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return FTestbed2NestedStruct1();
	}
	TPromise<FTestbed2NestedStruct1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, Param3, &Promise, this]()
		{
			InvokeReplyFunc GetNestedStruct3InterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed2NestedStruct1>()); };
			m_node->invokeRemote("testbed2.NestedStruct3Interface/func3", {Param1, Param2, Param3}, GetNestedStruct3InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void OLinkService::applyState(const nlohmann::json& fields)
{
	if (fields.contains("prop1"))
	{
		if (Prop1 != fields["prop1"].get<FTestbed2NestedStruct1>())
		{
			Prop1 = fields["prop1"].get<FTestbed2NestedStruct1>();
			Prop1Changed.Broadcast(Prop1);
		}
	}
	if (fields.contains("prop2"))
	{
		if (Prop2 != fields["prop2"].get<FTestbed2NestedStruct2>())
		{
			Prop2 = fields["prop2"].get<FTestbed2NestedStruct2>();
			Prop2Changed.Broadcast(Prop2);
		}
	}
	if (fields.contains("prop3"))
	{
		if (Prop3 != fields["prop3"].get<FTestbed2NestedStruct3>())
		{
			Prop3 = fields["prop3"].get<FTestbed2NestedStruct3>();
			Prop3Changed.Broadcast(Prop3);
		}
	}
}

std::string OLinkService::olinkObjectName()
{
	return "testbed2.NestedStruct3Interface";
}

void OLinkService::olinkOnSignal(std::string name, nlohmann::json args)
{
	std::string path = Name::pathFromName(name);
	if (path == "sig1")
	{
		Sig1Signal.Broadcast(args[0].get<FTestbed2NestedStruct1>());
		return;
	}
	if (path == "sig2")
	{
		Sig2Signal.Broadcast(args[0].get<FTestbed2NestedStruct1>(), args[1].get<FTestbed2NestedStruct2>());
		return;
	}
	if (path == "sig3")
	{
		Sig3Signal.Broadcast(args[0].get<FTestbed2NestedStruct1>(), args[1].get<FTestbed2NestedStruct2>(), args[2].get<FTestbed2NestedStruct3>());
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
} // namespace NestedStruct3Interface
} // namespace Testbed2
