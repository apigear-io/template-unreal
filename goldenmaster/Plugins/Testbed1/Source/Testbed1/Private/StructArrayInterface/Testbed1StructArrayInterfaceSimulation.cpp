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

namespace Testbed1
{
namespace StructArrayInterface
{
namespace Private
{
SimulationService::SimulationService()
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
				PropBoolChanged.Broadcast(PropBool);
			}
		}
		if (fields.contains("propInt"))
		{
			if (PropInt != fields["propInt"].get<TArray<FTestbed1StructInt>>())
			{
				PropInt = fields["propInt"].get<TArray<FTestbed1StructInt>>();
				PropIntChanged.Broadcast(PropInt);
			}
		}
		if (fields.contains("propFloat"))
		{
			if (PropFloat != fields["propFloat"].get<TArray<FTestbed1StructFloat>>())
			{
				PropFloat = fields["propFloat"].get<TArray<FTestbed1StructFloat>>();
				PropFloatChanged.Broadcast(PropFloat);
			}
		}
		if (fields.contains("propString"))
		{
			if (PropString != fields["propString"].get<TArray<FTestbed1StructString>>())
			{
				PropString = fields["propString"].get<TArray<FTestbed1StructString>>();
				PropStringChanged.Broadcast(PropString);
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
				PropBoolChanged.Broadcast(PropBool);
			}
		}
		if (fields.contains("propInt"))
		{
			if (PropInt != fields["propInt"].get<TArray<FTestbed1StructInt>>())
			{
				PropInt = fields["propInt"].get<TArray<FTestbed1StructInt>>();
				PropIntChanged.Broadcast(PropInt);
			}
		}
		if (fields.contains("propFloat"))
		{
			if (PropFloat != fields["propFloat"].get<TArray<FTestbed1StructFloat>>())
			{
				PropFloat = fields["propFloat"].get<TArray<FTestbed1StructFloat>>();
				PropFloatChanged.Broadcast(PropFloat);
			}
		}
		if (fields.contains("propString"))
		{
			if (PropString != fields["propString"].get<TArray<FTestbed1StructString>>())
			{
				PropString = fields["propString"].get<TArray<FTestbed1StructString>>();
				PropStringChanged.Broadcast(PropString);
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
			SigBoolSignal.Broadcast(fields["paramBool"].get<TArray<FTestbed1StructBool>>());
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
			SigIntSignal.Broadcast(fields["paramInt"].get<TArray<FTestbed1StructInt>>());
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
			SigFloatSignal.Broadcast(fields["paramFloat"].get<TArray<FTestbed1StructFloat>>());
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
			SigStringSignal.Broadcast(fields["paramString"].get<TArray<FTestbed1StructString>>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("testbed1/StructArrayInterface#sigString", sigStringFunc);
	}
}

SimulationService::~SimulationService()
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

FTestbed1StructArrayInterfaceSigBoolDelegate& SimulationService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

FTestbed1StructArrayInterfaceSigIntDelegate& SimulationService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

FTestbed1StructArrayInterfaceSigFloatDelegate& SimulationService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

FTestbed1StructArrayInterfaceSigStringDelegate& SimulationService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

TArray<FTestbed1StructBool> SimulationService::GetPropBool_Implementation() const
{
	return PropBool;
}

void SimulationService::SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	Params params;
	params["propBool"] = InPropBool;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructArrayInterface", "_set", params);
	}
}

FTestbed1StructArrayInterfacePropBoolChangedDelegate& SimulationService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

TArray<FTestbed1StructInt> SimulationService::GetPropInt_Implementation() const
{
	return PropInt;
}

void SimulationService::SetPropInt_Implementation(const TArray<FTestbed1StructInt>& InPropInt)
{
	Params params;
	params["propInt"] = InPropInt;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructArrayInterface", "_set", params);
	}
}

FTestbed1StructArrayInterfacePropIntChangedDelegate& SimulationService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

TArray<FTestbed1StructFloat> SimulationService::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void SimulationService::SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	Params params;
	params["propFloat"] = InPropFloat;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructArrayInterface", "_set", params);
	}
}

FTestbed1StructArrayInterfacePropFloatChangedDelegate& SimulationService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

TArray<FTestbed1StructString> SimulationService::GetPropString_Implementation() const
{
	return PropString;
}

void SimulationService::SetPropString_Implementation(const TArray<FTestbed1StructString>& InPropString)
{
	Params params;
	params["propString"] = InPropString;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructArrayInterface", "_set", params);
	}
}

FTestbed1StructArrayInterfacePropStringChangedDelegate& SimulationService::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

FTestbed1StructBool SimulationService::FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool)
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

FTestbed1StructBool SimulationService::FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt)
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

FTestbed1StructBool SimulationService::FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat)
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

FTestbed1StructBool SimulationService::FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString)
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

} // namespace Private
} // namespace StructArrayInterface
} // namespace Testbed1
