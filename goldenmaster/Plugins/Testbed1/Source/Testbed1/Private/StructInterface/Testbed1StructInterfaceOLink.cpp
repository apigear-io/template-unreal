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

#include "Testbed1StructInterfaceOLink.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "apig/Testbed1.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;
UTestbed1StructInterfaceOLinkService::UTestbed1StructInterfaceOLinkService()
	: ITestbed1StructInterfaceInterface()
	, m_node(nullptr)
	, m_isReady(false)
	, PropBool(FTestbed1StructBool())
	, PropInt(FTestbed1StructInt())
	, PropFloat(FTestbed1StructFloat())
	, PropString(FTestbed1StructString())
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->Connect();
		AGCM->GetOLinkConnection()->linkObjectSource(olinkObjectName());
	}
	m_node = ClientRegistry::get().addObjectSink(this);
}

UTestbed1StructInterfaceOLinkService::~UTestbed1StructInterfaceOLinkService()
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

FTestbed1StructInterfaceSigBoolDelegate& UTestbed1StructInterfaceOLinkService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

FTestbed1StructInterfaceSigIntDelegate& UTestbed1StructInterfaceOLinkService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

FTestbed1StructInterfaceSigFloatDelegate& UTestbed1StructInterfaceOLinkService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

FTestbed1StructInterfaceSigStringDelegate& UTestbed1StructInterfaceOLinkService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTestbed1StructInterfaceOLinkService::GetPropBool_Implementation(FTestbed1StructBool& ReturnValue) const
{
	ReturnValue = PropBool;
}

void UTestbed1StructInterfaceOLinkService::SetPropBool_Implementation(const FTestbed1StructBool& InPropBool)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed1.StructInterface/propBool", InPropBool);
}

FTestbed1StructInterfacePropBoolChangedDelegate& UTestbed1StructInterfaceOLinkService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}
void UTestbed1StructInterfaceOLinkService::GetPropInt_Implementation(FTestbed1StructInt& ReturnValue) const
{
	ReturnValue = PropInt;
}

void UTestbed1StructInterfaceOLinkService::SetPropInt_Implementation(const FTestbed1StructInt& InPropInt)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed1.StructInterface/propInt", InPropInt);
}

FTestbed1StructInterfacePropIntChangedDelegate& UTestbed1StructInterfaceOLinkService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}
void UTestbed1StructInterfaceOLinkService::GetPropFloat_Implementation(FTestbed1StructFloat& ReturnValue) const
{
	ReturnValue = PropFloat;
}

void UTestbed1StructInterfaceOLinkService::SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed1.StructInterface/propFloat", InPropFloat);
}

FTestbed1StructInterfacePropFloatChangedDelegate& UTestbed1StructInterfaceOLinkService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}
void UTestbed1StructInterfaceOLinkService::GetPropString_Implementation(FTestbed1StructString& ReturnValue) const
{
	ReturnValue = PropString;
}

void UTestbed1StructInterfaceOLinkService::SetPropString_Implementation(const FTestbed1StructString& InPropString)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed1.StructInterface/propString", InPropString);
}

FTestbed1StructInterfacePropStringChangedDelegate& UTestbed1StructInterfaceOLinkService::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

void UTestbed1StructInterfaceOLinkService::FuncBool_Implementation(FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		Result = FTestbed1StructBool();
		return;
	}
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[ParamBool, &Promise, this]()
		{
			InvokeReplyFunc GetStructInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructBool>()); };
			m_node->invokeRemote("testbed1.StructInterface/funcBool", {ParamBool}, GetStructInterfaceStateFunc);
		});

	Result = Promise.GetFuture().Get();
}

void UTestbed1StructInterfaceOLinkService::FuncInt_Implementation(FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		Result = FTestbed1StructBool();
		return;
	}
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[ParamInt, &Promise, this]()
		{
			InvokeReplyFunc GetStructInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructBool>()); };
			m_node->invokeRemote("testbed1.StructInterface/funcInt", {ParamInt}, GetStructInterfaceStateFunc);
		});

	Result = Promise.GetFuture().Get();
}

void UTestbed1StructInterfaceOLinkService::FuncFloat_Implementation(FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		Result = FTestbed1StructFloat();
		return;
	}
	TPromise<FTestbed1StructFloat> Promise;
	Async(EAsyncExecution::Thread,
		[ParamFloat, &Promise, this]()
		{
			InvokeReplyFunc GetStructInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructFloat>()); };
			m_node->invokeRemote("testbed1.StructInterface/funcFloat", {ParamFloat}, GetStructInterfaceStateFunc);
		});

	Result = Promise.GetFuture().Get();
}

void UTestbed1StructInterfaceOLinkService::FuncString_Implementation(FTestbed1StructString& Result, const FTestbed1StructString& ParamString)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		Result = FTestbed1StructString();
		return;
	}
	TPromise<FTestbed1StructString> Promise;
	Async(EAsyncExecution::Thread,
		[ParamString, &Promise, this]()
		{
			InvokeReplyFunc GetStructInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed1StructString>()); };
			m_node->invokeRemote("testbed1.StructInterface/funcString", {ParamString}, GetStructInterfaceStateFunc);
		});

	Result = Promise.GetFuture().Get();
}

void UTestbed1StructInterfaceOLinkService::applyState(const nlohmann::json& fields)
{
	if (fields.contains("propBool"))
	{
		if (PropBool != fields["propBool"].get<FTestbed1StructBool>())
		{
			PropBool = fields["propBool"].get<FTestbed1StructBool>();
			PropBoolChanged.Broadcast(PropBool);
		}
	}
	if (fields.contains("propInt"))
	{
		if (PropInt != fields["propInt"].get<FTestbed1StructInt>())
		{
			PropInt = fields["propInt"].get<FTestbed1StructInt>();
			PropIntChanged.Broadcast(PropInt);
		}
	}
	if (fields.contains("propFloat"))
	{
		if (PropFloat != fields["propFloat"].get<FTestbed1StructFloat>())
		{
			PropFloat = fields["propFloat"].get<FTestbed1StructFloat>();
			PropFloatChanged.Broadcast(PropFloat);
		}
	}
	if (fields.contains("propString"))
	{
		if (PropString != fields["propString"].get<FTestbed1StructString>())
		{
			PropString = fields["propString"].get<FTestbed1StructString>();
			PropStringChanged.Broadcast(PropString);
		}
	}
}

std::string UTestbed1StructInterfaceOLinkService::olinkObjectName()
{
	return "testbed1.StructInterface";
}

void UTestbed1StructInterfaceOLinkService::olinkOnSignal(std::string name, nlohmann::json args)
{
	std::string path = Name::pathFromName(name);
	if (path == "sigBool")
	{
		SigBoolSignal.Broadcast(args[0].get<FTestbed1StructBool>());
		return;
	}
	if (path == "sigInt")
	{
		SigIntSignal.Broadcast(args[0].get<FTestbed1StructInt>());
		return;
	}
	if (path == "sigFloat")
	{
		SigFloatSignal.Broadcast(args[0].get<FTestbed1StructFloat>());
		return;
	}
	if (path == "sigString")
	{
		SigStringSignal.Broadcast(args[0].get<FTestbed1StructString>());
		return;
	}
}

void UTestbed1StructInterfaceOLinkService::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
	std::string path = Name::pathFromName(name);
	applyState({{path, value}});
}

void UTestbed1StructInterfaceOLinkService::olinkOnInit(std::string name, nlohmann::json props, IClientNode* node)
{
	m_isReady = true;
	m_node = node;
	applyState(props);
	// call isReady();
}

void UTestbed1StructInterfaceOLinkService::olinkOnRelease()
{
	m_isReady = false;
	m_node = nullptr;
}
