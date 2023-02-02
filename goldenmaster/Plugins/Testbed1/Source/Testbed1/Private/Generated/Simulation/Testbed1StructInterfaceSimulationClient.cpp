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

#include "Testbed1StructInterfaceSimulationClient.h"
#include "Generated/api/Testbed1.json.adapter.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "unrealsimulation.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

using namespace ApiGear::JSONRPC;
UTestbed1StructInterfaceSimulationClient::UTestbed1StructInterfaceSimulationClient()
	: ITestbed1StructInterfaceInterface()
{
}

void UTestbed1StructInterfaceSimulationClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UApiGearConnectionManager* AGCM = nullptr;
	if (GEngine != nullptr)
	{
		AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
	}
	NotifyRequestFunc StructInterfaceStateChangedFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("propBool"))
		{
			if (PropBool != fields["propBool"].get<FTestbed1StructBool>())
			{
				PropBool = fields["propBool"].get<FTestbed1StructBool>();
				Execute_BroadcastPropBoolChanged(this, PropBool);
			}
		}
		if (fields.contains("propInt"))
		{
			if (PropInt != fields["propInt"].get<FTestbed1StructInt>())
			{
				PropInt = fields["propInt"].get<FTestbed1StructInt>();
				Execute_BroadcastPropIntChanged(this, PropInt);
			}
		}
		if (fields.contains("propFloat"))
		{
			if (PropFloat != fields["propFloat"].get<FTestbed1StructFloat>())
			{
				PropFloat = fields["propFloat"].get<FTestbed1StructFloat>();
				Execute_BroadcastPropFloatChanged(this, PropFloat);
			}
		}
		if (fields.contains("propString"))
		{
			if (PropString != fields["propString"].get<FTestbed1StructString>())
			{
				PropString = fields["propString"].get<FTestbed1StructString>();
				Execute_BroadcastPropStringChanged(this, PropString);
			}
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->Connect();
		AGCM->GetSimulationConnection()->onNotifyState("testbed1/StructInterface", StructInterfaceStateChangedFunc);
	}

	CallResponseFunc GetStructInterfaceStateFunc = [this](CallResponseArg arg)
	{
		if (arg.result.size() != 1)
		{
			return;
		}
		const json fields = arg.result;
		if (fields.contains("propBool"))
		{
			if (PropBool != fields["propBool"].get<FTestbed1StructBool>())
			{
				PropBool = fields["propBool"].get<FTestbed1StructBool>();
				Execute_BroadcastPropBoolChanged(this, PropBool);
			}
		}
		if (fields.contains("propInt"))
		{
			if (PropInt != fields["propInt"].get<FTestbed1StructInt>())
			{
				PropInt = fields["propInt"].get<FTestbed1StructInt>();
				Execute_BroadcastPropIntChanged(this, PropInt);
			}
		}
		if (fields.contains("propFloat"))
		{
			if (PropFloat != fields["propFloat"].get<FTestbed1StructFloat>())
			{
				PropFloat = fields["propFloat"].get<FTestbed1StructFloat>();
				Execute_BroadcastPropFloatChanged(this, PropFloat);
			}
		}
		if (fields.contains("propString"))
		{
			if (PropString != fields["propString"].get<FTestbed1StructString>())
			{
				PropString = fields["propString"].get<FTestbed1StructString>();
				Execute_BroadcastPropStringChanged(this, PropString);
			}
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->doFetchState("testbed1/StructInterface", GetStructInterfaceStateFunc);
	}

	// register notification callback functions, signal/event -> fcn
	NotifyRequestFunc sigBoolFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("paramBool"))
		{
			Execute_BroadcastSigBool(this, fields["paramBool"].get<FTestbed1StructBool>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("testbed1/StructInterface#sigBool", sigBoolFunc);
	}

	NotifyRequestFunc sigIntFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("paramInt"))
		{
			Execute_BroadcastSigInt(this, fields["paramInt"].get<FTestbed1StructInt>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("testbed1/StructInterface#sigInt", sigIntFunc);
	}

	NotifyRequestFunc sigFloatFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("paramFloat"))
		{
			Execute_BroadcastSigFloat(this, fields["paramFloat"].get<FTestbed1StructFloat>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("testbed1/StructInterface#sigFloat", sigFloatFunc);
	}

	NotifyRequestFunc sigStringFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("paramString"))
		{
			Execute_BroadcastSigString(this, fields["paramString"].get<FTestbed1StructString>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("testbed1/StructInterface#sigString", sigStringFunc);
	}
}

void UTestbed1StructInterfaceSimulationClient::Deinitialize()
{
	Super::Deinitialize();

	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->RemoveOnNotifyState("testbed1/StructInterface");
		// unregister notification callback functions
		AGCM->GetSimulationConnection()->RemoveOnNotify("testbed1/StructInterface#sigBool");
		AGCM->GetSimulationConnection()->RemoveOnNotify("testbed1/StructInterface#sigInt");
		AGCM->GetSimulationConnection()->RemoveOnNotify("testbed1/StructInterface#sigFloat");
		AGCM->GetSimulationConnection()->RemoveOnNotify("testbed1/StructInterface#sigString");
	}
}

void UTestbed1StructInterfaceSimulationClient::BroadcastSigBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
}

FTestbed1StructInterfaceSigBoolDelegate& UTestbed1StructInterfaceSimulationClient::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTestbed1StructInterfaceSimulationClient::BroadcastSigInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

FTestbed1StructInterfaceSigIntDelegate& UTestbed1StructInterfaceSimulationClient::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTestbed1StructInterfaceSimulationClient::BroadcastSigFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTestbed1StructInterfaceSigFloatDelegate& UTestbed1StructInterfaceSimulationClient::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTestbed1StructInterfaceSimulationClient::BroadcastSigString_Implementation(const FTestbed1StructString& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

FTestbed1StructInterfaceSigStringDelegate& UTestbed1StructInterfaceSimulationClient::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTestbed1StructInterfaceSimulationClient::BroadcastPropBoolChanged_Implementation(const FTestbed1StructBool& InPropBool)
{
	PropBool = InPropBool;
	PropBoolChanged.Broadcast(InPropBool);
}

FTestbed1StructBool UTestbed1StructInterfaceSimulationClient::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructInterfaceSimulationClient::SetPropBool_Implementation(const FTestbed1StructBool& InPropBool)
{
	Params params;
	params["propBool"] = InPropBool;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructInterface", "_set", params);
	}
}

FTestbed1StructInterfacePropBoolChangedDelegate& UTestbed1StructInterfaceSimulationClient::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTestbed1StructInterfaceSimulationClient::BroadcastPropIntChanged_Implementation(const FTestbed1StructInt& InPropInt)
{
	PropInt = InPropInt;
	PropIntChanged.Broadcast(InPropInt);
}

FTestbed1StructInt UTestbed1StructInterfaceSimulationClient::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTestbed1StructInterfaceSimulationClient::SetPropInt_Implementation(const FTestbed1StructInt& InPropInt)
{
	Params params;
	params["propInt"] = InPropInt;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructInterface", "_set", params);
	}
}

FTestbed1StructInterfacePropIntChangedDelegate& UTestbed1StructInterfaceSimulationClient::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTestbed1StructInterfaceSimulationClient::BroadcastPropFloatChanged_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	PropFloat = InPropFloat;
	PropFloatChanged.Broadcast(InPropFloat);
}

FTestbed1StructFloat UTestbed1StructInterfaceSimulationClient::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTestbed1StructInterfaceSimulationClient::SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	Params params;
	params["propFloat"] = InPropFloat;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructInterface", "_set", params);
	}
}

FTestbed1StructInterfacePropFloatChangedDelegate& UTestbed1StructInterfaceSimulationClient::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTestbed1StructInterfaceSimulationClient::BroadcastPropStringChanged_Implementation(const FTestbed1StructString& InPropString)
{
	PropString = InPropString;
	PropStringChanged.Broadcast(InPropString);
}

FTestbed1StructString UTestbed1StructInterfaceSimulationClient::GetPropString_Implementation() const
{
	return PropString;
}

void UTestbed1StructInterfaceSimulationClient::SetPropString_Implementation(const FTestbed1StructString& InPropString)
{
	Params params;
	params["propString"] = InPropString;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructInterface", "_set", params);
	}
}

FTestbed1StructInterfacePropStringChangedDelegate& UTestbed1StructInterfaceSimulationClient::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

FTestbed1StructBool UTestbed1StructInterfaceSimulationClient::FuncBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	Params params;
	params["paramBool"] = ParamBool;
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetStructInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<FTestbed1StructBool>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("testbed1/StructInterface", "funcBool", params, GetStructInterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructBool UTestbed1StructInterfaceSimulationClient::FuncInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	Params params;
	params["paramInt"] = ParamInt;
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetStructInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<FTestbed1StructBool>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("testbed1/StructInterface", "funcInt", params, GetStructInterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructFloat UTestbed1StructInterfaceSimulationClient::FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	Params params;
	params["paramFloat"] = ParamFloat;
	TPromise<FTestbed1StructFloat> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetStructInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<FTestbed1StructFloat>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("testbed1/StructInterface", "funcFloat", params, GetStructInterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructString UTestbed1StructInterfaceSimulationClient::FuncString_Implementation(const FTestbed1StructString& ParamString)
{
	Params params;
	params["paramString"] = ParamString;
	TPromise<FTestbed1StructString> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetStructInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<FTestbed1StructString>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("testbed1/StructInterface", "funcString", params, GetStructInterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}