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

#include "Testbed2NestedStruct2InterfaceSimulation.h"
#include "apig/Testbed2.json.adapter.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "unrealsimulation.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

using namespace ApiGear::JSONRPC;
UTestbed2NestedStruct2InterfaceSimulationService::UTestbed2NestedStruct2InterfaceSimulationService()
	: ITestbed2NestedStruct2InterfaceInterface()
	, Prop1(FTestbed2NestedStruct1())
	, Prop2(FTestbed2NestedStruct2())
{
	UApiGearConnectionManager* AGCM = nullptr;
	if (GEngine != nullptr)
	{
		AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
	}
	NotifyRequestFunc NestedStruct2InterfaceStateChangedFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
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
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->Connect();
		AGCM->GetSimulationConnection()->onNotifyState("testbed2/NestedStruct2Interface", NestedStruct2InterfaceStateChangedFunc);
	}

	CallResponseFunc GetNestedStruct2InterfaceStateFunc = [this](CallResponseArg arg)
	{
		if (arg.result.size() != 1)
		{
			return;
		}
		const json fields = arg.result;
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
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->doFetchState("testbed2/NestedStruct2Interface", GetNestedStruct2InterfaceStateFunc);
	}

	// register notification callback functions, signal/event -> fcn
	NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("param1"))
		{
			Sig1Signal.Broadcast(fields["param1"].get<FTestbed2NestedStruct1>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("testbed2/NestedStruct2Interface#sig1", sig1Func);
	}

	NotifyRequestFunc sig2Func = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("param1") && fields.contains("param2"))
		{
			Sig2Signal.Broadcast(fields["param1"].get<FTestbed2NestedStruct1>(), fields["param2"].get<FTestbed2NestedStruct2>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("testbed2/NestedStruct2Interface#sig2", sig2Func);
	}
}

UTestbed2NestedStruct2InterfaceSimulationService::~UTestbed2NestedStruct2InterfaceSimulationService()
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->RemoveOnNotifyState("testbed2/NestedStruct2Interface");
		// unregister notification callback functions
		AGCM->GetSimulationConnection()->RemoveOnNotify("testbed2/NestedStruct2Interface#sig1");
		AGCM->GetSimulationConnection()->RemoveOnNotify("testbed2/NestedStruct2Interface#sig2");
	}
}

void UTestbed2NestedStruct2InterfaceSimulationService::BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTestbed2NestedStruct2InterfaceSig1Delegate& UTestbed2NestedStruct2InterfaceSimulationService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTestbed2NestedStruct2InterfaceSimulationService::BroadcastSig2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
}

FTestbed2NestedStruct2InterfaceSig2Delegate& UTestbed2NestedStruct2InterfaceSimulationService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTestbed2NestedStruct2InterfaceSimulationService::BroadcastProp1Changed_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceSimulationService::GetProp1_Implementation() const
{
	return Prop1;
}

void UTestbed2NestedStruct2InterfaceSimulationService::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Params params;
	params["prop1"] = InProp1;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed2/NestedStruct2Interface", "_set", params);
	}
}

FTestbed2NestedStruct2InterfaceProp1ChangedDelegate& UTestbed2NestedStruct2InterfaceSimulationService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTestbed2NestedStruct2InterfaceSimulationService::BroadcastProp2Changed_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	Prop2 = InProp2;
	Prop2Changed.Broadcast(InProp2);
}

FTestbed2NestedStruct2 UTestbed2NestedStruct2InterfaceSimulationService::GetProp2_Implementation() const
{
	return Prop2;
}

void UTestbed2NestedStruct2InterfaceSimulationService::SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	Params params;
	params["prop2"] = InProp2;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("testbed2/NestedStruct2Interface", "_set", params);
	}
}

FTestbed2NestedStruct2InterfaceProp2ChangedDelegate& UTestbed2NestedStruct2InterfaceSimulationService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceSimulationService::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Params params;
	params["param1"] = Param1;
	TPromise<FTestbed2NestedStruct1> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetNestedStruct2InterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<FTestbed2NestedStruct1>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("testbed2/NestedStruct2Interface", "func1", params, GetNestedStruct2InterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceSimulationService::Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Params params;
	params["param1"] = Param1;
	params["param2"] = Param2;
	TPromise<FTestbed2NestedStruct1> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetNestedStruct2InterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<FTestbed2NestedStruct1>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("testbed2/NestedStruct2Interface", "func2", params, GetNestedStruct2InterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}
