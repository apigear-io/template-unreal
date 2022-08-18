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

#include "Testbed1StructInterfaceSimulation.h"
#include "apig/Testbed1.json.adapter.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "unrealsimulation.h"

using namespace ApiGear::JSONRPC;

namespace Testbed1
{
namespace StructInterface
{
namespace Private
{
SimulationService::SimulationService()
	: ITestbed1StructInterfaceInterface()
	, PropBool(FTestbed1StructBool())
	, PropInt(FTestbed1StructInt())
	, PropFloat(FTestbed1StructFloat())
	, PropString(FTestbed1StructString())
{
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
			SigBoolSignal.Broadcast(fields["paramBool"].get<FTestbed1StructBool>());
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
			SigIntSignal.Broadcast(fields["paramInt"].get<FTestbed1StructInt>());
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
			SigFloatSignal.Broadcast(fields["paramFloat"].get<FTestbed1StructFloat>());
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
			SigStringSignal.Broadcast(fields["paramString"].get<FTestbed1StructString>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("testbed1/StructInterface#sigString", sigStringFunc);
	}
}

SimulationService::~SimulationService()
{
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

FTestbed1StructInterfaceSigBoolDelegate& SimulationService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

FTestbed1StructInterfaceSigIntDelegate& SimulationService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

FTestbed1StructInterfaceSigFloatDelegate& SimulationService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

FTestbed1StructInterfaceSigStringDelegate& SimulationService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

FTestbed1StructBool SimulationService::GetPropBool() const
{
	return PropBool;
}

void SimulationService::SetPropBool(const FTestbed1StructBool& InPropBool)
{
	Params params;
	params["propBool"] = InPropBool;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructInterface", "_set", params);
	}
}

FTestbed1StructInterfacePropBoolChangedDelegate& SimulationService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

FTestbed1StructInt SimulationService::GetPropInt() const
{
	return PropInt;
}

void SimulationService::SetPropInt(const FTestbed1StructInt& InPropInt)
{
	Params params;
	params["propInt"] = InPropInt;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructInterface", "_set", params);
	}
}

FTestbed1StructInterfacePropIntChangedDelegate& SimulationService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

FTestbed1StructFloat SimulationService::GetPropFloat() const
{
	return PropFloat;
}

void SimulationService::SetPropFloat(const FTestbed1StructFloat& InPropFloat)
{
	Params params;
	params["propFloat"] = InPropFloat;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructInterface", "_set", params);
	}
}

FTestbed1StructInterfacePropFloatChangedDelegate& SimulationService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

FTestbed1StructString SimulationService::GetPropString() const
{
	return PropString;
}

void SimulationService::SetPropString(const FTestbed1StructString& InPropString)
{
	Params params;
	params["propString"] = InPropString;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed1/StructInterface", "_set", params);
	}
}

FTestbed1StructInterfacePropStringChangedDelegate& SimulationService::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

FTestbed1StructBool SimulationService::FuncBool(const FTestbed1StructBool& ParamBool)
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

FTestbed1StructBool SimulationService::FuncInt(const FTestbed1StructInt& ParamInt)
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

FTestbed1StructFloat SimulationService::FuncFloat(const FTestbed1StructFloat& ParamFloat)
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

FTestbed1StructString SimulationService::FuncString(const FTestbed1StructString& ParamString)
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

} // namespace Private
} // namespace StructInterface
} // namespace Testbed1