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

#include "TbSame2SameStruct1InterfaceSimulation.h"
#include "apig/TbSame2.json.adapter.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "unrealsimulation.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

using namespace ApiGear::JSONRPC;
UTbSame2SameStruct1InterfaceSimulationService::UTbSame2SameStruct1InterfaceSimulationService()
	: ITbSame2SameStruct1InterfaceInterface()
	, Prop1(FTbSame2Struct1())
{
	UApiGearConnectionManager* AGCM = nullptr;
	if (GEngine != nullptr)
	{
		AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
	}
	NotifyRequestFunc SameStruct1InterfaceStateChangedFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("prop1"))
		{
			if (Prop1 != fields["prop1"].get<FTbSame2Struct1>())
			{
				Prop1 = fields["prop1"].get<FTbSame2Struct1>();
				Prop1Changed.Broadcast(Prop1);
			}
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->Connect();
		AGCM->GetSimulationConnection()->onNotifyState("tb.same2/SameStruct1Interface", SameStruct1InterfaceStateChangedFunc);
	}

	CallResponseFunc GetSameStruct1InterfaceStateFunc = [this](CallResponseArg arg)
	{
		if (arg.result.size() != 1)
		{
			return;
		}
		const json fields = arg.result;
		if (fields.contains("prop1"))
		{
			if (Prop1 != fields["prop1"].get<FTbSame2Struct1>())
			{
				Prop1 = fields["prop1"].get<FTbSame2Struct1>();
				Prop1Changed.Broadcast(Prop1);
			}
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->doFetchState("tb.same2/SameStruct1Interface", GetSameStruct1InterfaceStateFunc);
	}

	// register notification callback functions, signal/event -> fcn
	NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("param1"))
		{
			Sig1Signal.Broadcast(fields["param1"].get<FTbSame2Struct1>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("tb.same2/SameStruct1Interface#sig1", sig1Func);
	}
}

UTbSame2SameStruct1InterfaceSimulationService::~UTbSame2SameStruct1InterfaceSimulationService()
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->RemoveOnNotifyState("tb.same2/SameStruct1Interface");
		// unregister notification callback functions
		AGCM->GetSimulationConnection()->RemoveOnNotify("tb.same2/SameStruct1Interface#sig1");
	}
}

FTbSame2SameStruct1InterfaceSig1Delegate& UTbSame2SameStruct1InterfaceSimulationService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame2SameStruct1InterfaceSimulationService::GetProp1_Implementation(FTbSame2Struct1& ReturnValue) const
{
	ReturnValue = Prop1;
}

void UTbSame2SameStruct1InterfaceSimulationService::SetProp1_Implementation(const FTbSame2Struct1& InProp1)
{
	Params params;
	params["prop1"] = InProp1;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("tb.same2/SameStruct1Interface", "_set", params);
	}
}

FTbSame2SameStruct1InterfaceProp1ChangedDelegate& UTbSame2SameStruct1InterfaceSimulationService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbSame2SameStruct1InterfaceSimulationService::Func1_Implementation(FTbSame2Struct1& Result, const FTbSame2Struct1& Param1)
{
	Params params;
	params["param1"] = Param1;
	TPromise<FTbSame2Struct1> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetSameStruct1InterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<FTbSame2Struct1>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("tb.same2/SameStruct1Interface", "func1", params, GetSameStruct1InterfaceStateFunc);
			}
		});

	Result = Promise.GetFuture().Get();
}
