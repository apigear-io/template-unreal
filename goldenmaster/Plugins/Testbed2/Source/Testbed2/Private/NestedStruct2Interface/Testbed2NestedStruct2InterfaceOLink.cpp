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

#include "Testbed2NestedStruct2InterfaceOLink.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "apig/Testbed2.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;
UTestbed2NestedStruct2InterfaceOLinkService::UTestbed2NestedStruct2InterfaceOLinkService()
	: ITestbed2NestedStruct2InterfaceInterface()
	, m_node(nullptr)
	, m_isReady(false)
	, Prop1(FTestbed2NestedStruct1())
	, Prop2(FTestbed2NestedStruct2())
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->Connect();
		AGCM->GetOLinkConnection()->linkObjectSource(olinkObjectName());
	}
	m_node = ClientRegistry::get().addObjectSink(this);
}

UTestbed2NestedStruct2InterfaceOLinkService::~UTestbed2NestedStruct2InterfaceOLinkService()
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

void UTestbed2NestedStruct2InterfaceOLinkService::BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTestbed2NestedStruct2InterfaceSig1Delegate& UTestbed2NestedStruct2InterfaceOLinkService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTestbed2NestedStruct2InterfaceOLinkService::BroadcastSig2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
}

FTestbed2NestedStruct2InterfaceSig2Delegate& UTestbed2NestedStruct2InterfaceOLinkService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTestbed2NestedStruct2InterfaceOLinkService::BroadcastProp1Changed_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceOLinkService::GetProp1_Implementation() const
{
	return Prop1;
}

void UTestbed2NestedStruct2InterfaceOLinkService::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed2.NestedStruct2Interface/prop1", InProp1);
}

FTestbed2NestedStruct2InterfaceProp1ChangedDelegate& UTestbed2NestedStruct2InterfaceOLinkService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}
void UTestbed2NestedStruct2InterfaceOLinkService::BroadcastProp2Changed_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	Prop2 = InProp2;
	Prop2Changed.Broadcast(InProp2);
}

FTestbed2NestedStruct2 UTestbed2NestedStruct2InterfaceOLinkService::GetProp2_Implementation() const
{
	return Prop2;
}

void UTestbed2NestedStruct2InterfaceOLinkService::SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed2.NestedStruct2Interface/prop2", InProp2);
}

FTestbed2NestedStruct2InterfaceProp2ChangedDelegate& UTestbed2NestedStruct2InterfaceOLinkService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceOLinkService::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
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
			InvokeReplyFunc GetNestedStruct2InterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed2NestedStruct1>()); };
			m_node->invokeRemote("testbed2.NestedStruct2Interface/func1", {Param1}, GetNestedStruct2InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceOLinkService::Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
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
			InvokeReplyFunc GetNestedStruct2InterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed2NestedStruct1>()); };
			m_node->invokeRemote("testbed2.NestedStruct2Interface/func2", {Param1, Param2}, GetNestedStruct2InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTestbed2NestedStruct2InterfaceOLinkService::applyState(const nlohmann::json& fields)
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
}

std::string UTestbed2NestedStruct2InterfaceOLinkService::olinkObjectName()
{
	return "testbed2.NestedStruct2Interface";
}

void UTestbed2NestedStruct2InterfaceOLinkService::olinkOnSignal(std::string name, nlohmann::json args)
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
}

void UTestbed2NestedStruct2InterfaceOLinkService::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
	std::string path = Name::pathFromName(name);
	applyState({{path, value}});
}

void UTestbed2NestedStruct2InterfaceOLinkService::olinkOnInit(std::string name, nlohmann::json props, IClientNode* node)
{
	m_isReady = true;
	m_node = node;
	applyState(props);
	// call isReady();
}

void UTestbed2NestedStruct2InterfaceOLinkService::olinkOnRelease()
{
	m_isReady = false;
	m_node = nullptr;
}
