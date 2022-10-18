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

#include "Testbed1StructArrayInterfaceSimulation.h"
#include "apig/Testbed1.json.adapter.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "unrealsimulation.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

using namespace ApiGear::JSONRPC;
UTestbed1StructArrayInterfaceSimulationService::UTestbed1StructArrayInterfaceSimulationService()
	: ITestbed1StructArrayInterfaceInterface()
	, PropBool(TArray<FTestbed1StructBool>())
	, PropInt(TArray<FTestbed1StructInt>())
	, PropFloat(TArray<FTestbed1StructFloat>())
	, PropString(TArray<FTestbed1StructString>())
{
	UApiGearConnectionManager* AGCM = nullptr;
	if (GEngine != nullptr)
	{
		AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
	}
	NotifyRequestFunc StructArrayInterfaceStateChangedFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("propBool"))
		{
			if (PropBool != fields["propBool"].get<TArray<FTestbed1StructBool>>())
			{
				PropBool = fields["propBool"].get<TArray<FTestbed1StructBool>>();
				Execute_BroadcastPropBoolChanged(this, PropBool);
			}
		}
		if (fields.contains("propInt"))
		{
			if (PropInt != fields["propInt"].get<TArray<FTestbed1StructInt>>())
			{
				PropInt = fields["propInt"].get<TArray<FTestbed1StructInt>>();
				Execute_BroadcastPropIntChanged(this, PropInt);
			}
		}
		if (fields.contains("propFloat"))
		{
			if (PropFloat != fields["propFloat"].get<TArray<FTestbed1StructFloat>>())
			{
				PropFloat = fields["propFloat"].get<TArray<FTestbed1StructFloat>>();
				Execute_BroadcastPropFloatChanged(this, PropFloat);
			}
		}
		if (fields.contains("propString"))
		{
			if (PropString != fields["propString"].get<TArray<FTestbed1StructString>>())
			{
				PropString = fields["propString"].get<TArray<FTestbed1StructString>>();
				Execute_BroadcastPropStringChanged(this, PropString);
			}
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->Connect();
		AGCM->GetSimulationConnection()->onNotifyState("testbed1/StructArrayInterface", StructArrayInterfaceStateChangedFunc);
	}

	CallResponseFunc GetStructArrayInterfaceStateFunc = [this](CallResponseArg arg)
	{
		if (arg.result.size() != 1)
		{
			return;
		}
		const json fields = arg.result;
		if (fields.contains("propBool"))
		{
			if (PropBool != fields["propBool"].get<TArray<FTestbed1StructBool>>())
			{
				PropBool = fields["propBool"].get<TArray<FTestbed1StructBool>>();
				Execute_BroadcastPropBoolChanged(this, PropBool);
			}
		}
		if (fields.contains("propInt"))
		{
			if (PropInt != fields["propInt"].get<TArray<FTestbed1StructInt>>())
			{
				PropInt = fields["propInt"].get<TArray<FTestbed1StructInt>>();
				Execute_BroadcastPropIntChanged(this, PropInt);
			}
		}
		if (fields.contains("propFloat"))
		{
			if (PropFloat != fields["propFloat"].get<TArray<FTestbed1StructFloat>>())
			{
				PropFloat = fields["propFloat"].get<TArray<FTestbed1StructFloat>>();
				Execute_BroadcastPropFloatChanged(this, PropFloat);
			}
		}
		if (fields.contains("propString"))
		{
			if (PropString != fields["propString"].get<TArray<FTestbed1StructString>>())
			{
				PropString = fields["propString"].get<TArray<FTestbed1StructString>>();
				Execute_BroadcastPropStringChanged(this, PropString);
			}
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->doFetchState("testbed1/StructArrayInterface", GetStructArrayInterfaceStateFunc);
	}

	// register notification callback functions, signal/event -> fcn
	NotifyRequestFunc sigBoolFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("paramBool"))
		{
			Execute_BroadcastSigBool(this, fields["paramBool"].get<TArray<FTestbed1StructBool>>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("testbed1/StructArrayInterface#sigBool", sigBoolFunc);
	}

	NotifyRequestFunc sigIntFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("paramInt"))
		{
			Execute_BroadcastSigInt(this, fields["paramInt"].get<TArray<FTestbed1StructInt>>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("testbed1/StructArrayInterface#sigInt", sigIntFunc);
	}

	NotifyRequestFunc sigFloatFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("paramFloat"))
		{
			Execute_BroadcastSigFloat(this, fields["paramFloat"].get<TArray<FTestbed1StructFloat>>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("testbed1/StructArrayInterface#sigFloat", sigFloatFunc);
	}

	NotifyRequestFunc sigStringFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("paramString"))
		{
			Execute_BroadcastSigString(this, fields["paramString"].get<TArray<FTestbed1StructString>>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("testbed1/StructArrayInterface#sigString", sigStringFunc);
	}
}

UTestbed1StructArrayInterfaceSimulationService::~UTestbed1StructArrayInterfaceSimulationService()
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->RemoveOnNotifyState("testbed1/StructArrayInterface");
		// unregister notification callback functions
		AGCM->GetSimulationConnection()->RemoveOnNotify("testbed1/StructArrayInterface#sigBool");
		AGCM->GetSimulationConnection()->RemoveOnNotify("testbed1/StructArrayInterface#sigInt");
		AGCM->GetSimulationConnection()->RemoveOnNotify("testbed1/StructArrayInterface#sigFloat");
		AGCM->GetSimulationConnection()->RemoveOnNotify("testbed1/StructArrayInterface#sigString");
	}
}

void UTestbed1StructArrayInterfaceSimulationService::BroadcastSigBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
}

FTestbed1StructArrayInterfaceSigBoolDelegate& UTestbed1StructArrayInterfaceSimulationService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTestbed1StructArrayInterfaceSimulationService::BroadcastSigInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

FTestbed1StructArrayInterfaceSigIntDelegate& UTestbed1StructArrayInterfaceSimulationService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTestbed1StructArrayInterfaceSimulationService::BroadcastSigFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTestbed1StructArrayInterfaceSigFloatDelegate& UTestbed1StructArrayInterfaceSimulationService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTestbed1StructArrayInterfaceSimulationService::BroadcastSigString_Implementation(const TArray<FTestbed1StructString>& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

FTestbed1StructArrayInterfaceSigStringDelegate& UTestbed1StructArrayInterfaceSimulationService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTestbed1StructArrayInterfaceSimulationService::BroadcastPropBoolChanged_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	PropBool = InPropBool;
	PropBoolChanged.Broadcast(InPropBool);
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceSimulationService::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructArrayInterfaceSimulationService::SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	Params params;
	params["propBool"] = InPropBool;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructArrayInterface", "_set", params);
	}
}

FTestbed1StructArrayInterfacePropBoolChangedDelegate& UTestbed1StructArrayInterfaceSimulationService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTestbed1StructArrayInterfaceSimulationService::BroadcastPropIntChanged_Implementation(const TArray<FTestbed1StructInt>& InPropInt)
{
	PropInt = InPropInt;
	PropIntChanged.Broadcast(InPropInt);
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceSimulationService::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTestbed1StructArrayInterfaceSimulationService::SetPropInt_Implementation(const TArray<FTestbed1StructInt>& InPropInt)
{
	Params params;
	params["propInt"] = InPropInt;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructArrayInterface", "_set", params);
	}
}

FTestbed1StructArrayInterfacePropIntChangedDelegate& UTestbed1StructArrayInterfaceSimulationService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTestbed1StructArrayInterfaceSimulationService::BroadcastPropFloatChanged_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	PropFloat = InPropFloat;
	PropFloatChanged.Broadcast(InPropFloat);
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceSimulationService::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTestbed1StructArrayInterfaceSimulationService::SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	Params params;
	params["propFloat"] = InPropFloat;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructArrayInterface", "_set", params);
	}
}

FTestbed1StructArrayInterfacePropFloatChangedDelegate& UTestbed1StructArrayInterfaceSimulationService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTestbed1StructArrayInterfaceSimulationService::BroadcastPropStringChanged_Implementation(const TArray<FTestbed1StructString>& InPropString)
{
	PropString = InPropString;
	PropStringChanged.Broadcast(InPropString);
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceSimulationService::GetPropString_Implementation() const
{
	return PropString;
}

void UTestbed1StructArrayInterfaceSimulationService::SetPropString_Implementation(const TArray<FTestbed1StructString>& InPropString)
{
	Params params;
	params["propString"] = InPropString;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructArrayInterface", "_set", params);
	}
}

FTestbed1StructArrayInterfacePropStringChangedDelegate& UTestbed1StructArrayInterfaceSimulationService::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

FTestbed1StructBool UTestbed1StructArrayInterfaceSimulationService::FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool)
{
	Params params;
	params["paramBool"] = ParamBool;
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetStructArrayInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<FTestbed1StructBool>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("testbed1/StructArrayInterface", "funcBool", params, GetStructArrayInterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructBool UTestbed1StructArrayInterfaceSimulationService::FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt)
{
	Params params;
	params["paramInt"] = ParamInt;
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetStructArrayInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<FTestbed1StructBool>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("testbed1/StructArrayInterface", "funcInt", params, GetStructArrayInterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructBool UTestbed1StructArrayInterfaceSimulationService::FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	Params params;
	params["paramFloat"] = ParamFloat;
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetStructArrayInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<FTestbed1StructBool>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("testbed1/StructArrayInterface", "funcFloat", params, GetStructArrayInterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}

FTestbed1StructBool UTestbed1StructArrayInterfaceSimulationService::FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString)
{
	Params params;
	params["paramString"] = ParamString;
	TPromise<FTestbed1StructBool> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetStructArrayInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<FTestbed1StructBool>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("testbed1/StructArrayInterface", "funcString", params, GetStructArrayInterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}
