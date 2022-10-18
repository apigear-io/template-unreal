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

#include "TbSame1SameStruct1InterfaceSimulation.h"
#include "apig/TbSame1.json.adapter.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "unrealsimulation.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

using namespace ApiGear::JSONRPC;
UTbSame1SameStruct1InterfaceSimulationService::UTbSame1SameStruct1InterfaceSimulationService()
	: ITbSame1SameStruct1InterfaceInterface()
	, Prop1(FTbSame1Struct1())
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
			if (Prop1 != fields["prop1"].get<FTbSame1Struct1>())
			{
				Prop1 = fields["prop1"].get<FTbSame1Struct1>();
				Execute_BroadcastProp1Changed(this, Prop1);
			}
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->Connect();
		AGCM->GetSimulationConnection()->onNotifyState("tb.same1/SameStruct1Interface", SameStruct1InterfaceStateChangedFunc);
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
			if (Prop1 != fields["prop1"].get<FTbSame1Struct1>())
			{
				Prop1 = fields["prop1"].get<FTbSame1Struct1>();
				Execute_BroadcastProp1Changed(this, Prop1);
			}
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->doFetchState("tb.same1/SameStruct1Interface", GetSameStruct1InterfaceStateFunc);
	}

	// register notification callback functions, signal/event -> fcn
	NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("param1"))
		{
			Execute_BroadcastSig1(this, fields["param1"].get<FTbSame1Struct1>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("tb.same1/SameStruct1Interface#sig1", sig1Func);
	}
}

UTbSame1SameStruct1InterfaceSimulationService::~UTbSame1SameStruct1InterfaceSimulationService()
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->RemoveOnNotifyState("tb.same1/SameStruct1Interface");
		// unregister notification callback functions
		AGCM->GetSimulationConnection()->RemoveOnNotify("tb.same1/SameStruct1Interface#sig1");
	}
}

void UTbSame1SameStruct1InterfaceSimulationService::BroadcastSig1_Implementation(const FTbSame1Struct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTbSame1SameStruct1InterfaceSig1Delegate& UTbSame1SameStruct1InterfaceSimulationService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame1SameStruct1InterfaceSimulationService::BroadcastProp1Changed_Implementation(const FTbSame1Struct1& InProp1)
{
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

FTbSame1Struct1 UTbSame1SameStruct1InterfaceSimulationService::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame1SameStruct1InterfaceSimulationService::SetProp1_Implementation(const FTbSame1Struct1& InProp1)
{
	Params params;
	params["prop1"] = InProp1;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("tb.same1/SameStruct1Interface", "_set", params);
	}
}

FTbSame1SameStruct1InterfaceProp1ChangedDelegate& UTbSame1SameStruct1InterfaceSimulationService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

FTbSame1Struct1 UTbSame1SameStruct1InterfaceSimulationService::Func1_Implementation(const FTbSame1Struct1& Param1)
{
	Params params;
	params["param1"] = Param1;
	TPromise<FTbSame1Struct1> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetSameStruct1InterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<FTbSame1Struct1>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("tb.same1/SameStruct1Interface", "func1", params, GetSameStruct1InterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}
