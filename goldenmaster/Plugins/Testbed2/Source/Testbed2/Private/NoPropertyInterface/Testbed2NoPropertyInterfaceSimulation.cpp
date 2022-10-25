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

#include "Testbed2NoPropertyInterfaceSimulation.h"
#include "apig/Testbed2.json.adapter.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "unrealsimulation.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

using namespace ApiGear::JSONRPC;
UTestbed2NoPropertyInterfaceSimulationService::UTestbed2NoPropertyInterfaceSimulationService()
	: ITestbed2NoPropertyInterfaceInterface()
{
	UApiGearConnectionManager* AGCM = nullptr;
	if (GEngine != nullptr)
	{
		AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
	}
	NotifyRequestFunc NoPropertyInterfaceStateChangedFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->Connect();
		AGCM->GetSimulationConnection()->onNotifyState("testbed2/NoPropertyInterface", NoPropertyInterfaceStateChangedFunc);
	}

	CallResponseFunc GetNoPropertyInterfaceStateFunc = [this](CallResponseArg arg)
	{
		if (arg.result.size() != 1)
		{
			return;
		}
		const json fields = arg.result;
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->doFetchState("testbed2/NoPropertyInterface", GetNoPropertyInterfaceStateFunc);
	}

	// register notification callback functions, signal/event -> fcn
	NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("param1"))
		{
			Execute_BroadcastSig1(this, fields["param1"].get<FTestbed2NestedStruct1>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("testbed2/NoPropertyInterface#sig1", sig1Func);
	}
}

UTestbed2NoPropertyInterfaceSimulationService::~UTestbed2NoPropertyInterfaceSimulationService()
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->RemoveOnNotifyState("testbed2/NoPropertyInterface");
		// unregister notification callback functions
		AGCM->GetSimulationConnection()->RemoveOnNotify("testbed2/NoPropertyInterface#sig1");
	}
}

void UTestbed2NoPropertyInterfaceSimulationService::BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTestbed2NoPropertyInterfaceSig1Delegate& UTestbed2NoPropertyInterfaceSimulationService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

FTestbed2NestedStruct1 UTestbed2NoPropertyInterfaceSimulationService::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Params params;
	params["param1"] = Param1;
	TPromise<FTestbed2NestedStruct1> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetNoPropertyInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<FTestbed2NestedStruct1>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("testbed2/NoPropertyInterface", "func1", params, GetNoPropertyInterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}
