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

#include "TbEnumEnumInterfaceSimulation.h"
#include "Generated/api/TbEnum.json.adapter.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "unrealsimulation.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

using namespace ApiGear::JSONRPC;
UTbEnumEnumInterfaceSimulationService::UTbEnumEnumInterfaceSimulationService()
	: ITbEnumEnumInterfaceInterface()
{
	UApiGearConnectionManager* AGCM = nullptr;
	if (GEngine != nullptr)
	{
		AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
	}
	NotifyRequestFunc EnumInterfaceStateChangedFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("prop0"))
		{
			if (Prop0 != fields["prop0"].get<ETbEnumEnum0>())
			{
				Prop0 = fields["prop0"].get<ETbEnumEnum0>();
				Execute_BroadcastProp0Changed(this, Prop0);
			}
		}
		if (fields.contains("prop1"))
		{
			if (Prop1 != fields["prop1"].get<ETbEnumEnum1>())
			{
				Prop1 = fields["prop1"].get<ETbEnumEnum1>();
				Execute_BroadcastProp1Changed(this, Prop1);
			}
		}
		if (fields.contains("prop2"))
		{
			if (Prop2 != fields["prop2"].get<ETbEnumEnum2>())
			{
				Prop2 = fields["prop2"].get<ETbEnumEnum2>();
				Execute_BroadcastProp2Changed(this, Prop2);
			}
		}
		if (fields.contains("prop3"))
		{
			if (Prop3 != fields["prop3"].get<ETbEnumEnum3>())
			{
				Prop3 = fields["prop3"].get<ETbEnumEnum3>();
				Execute_BroadcastProp3Changed(this, Prop3);
			}
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->Connect();
		AGCM->GetSimulationConnection()->onNotifyState("tb.enum/EnumInterface", EnumInterfaceStateChangedFunc);
	}

	CallResponseFunc GetEnumInterfaceStateFunc = [this](CallResponseArg arg)
	{
		if (arg.result.size() != 1)
		{
			return;
		}
		const json fields = arg.result;
		if (fields.contains("prop0"))
		{
			if (Prop0 != fields["prop0"].get<ETbEnumEnum0>())
			{
				Prop0 = fields["prop0"].get<ETbEnumEnum0>();
				Execute_BroadcastProp0Changed(this, Prop0);
			}
		}
		if (fields.contains("prop1"))
		{
			if (Prop1 != fields["prop1"].get<ETbEnumEnum1>())
			{
				Prop1 = fields["prop1"].get<ETbEnumEnum1>();
				Execute_BroadcastProp1Changed(this, Prop1);
			}
		}
		if (fields.contains("prop2"))
		{
			if (Prop2 != fields["prop2"].get<ETbEnumEnum2>())
			{
				Prop2 = fields["prop2"].get<ETbEnumEnum2>();
				Execute_BroadcastProp2Changed(this, Prop2);
			}
		}
		if (fields.contains("prop3"))
		{
			if (Prop3 != fields["prop3"].get<ETbEnumEnum3>())
			{
				Prop3 = fields["prop3"].get<ETbEnumEnum3>();
				Execute_BroadcastProp3Changed(this, Prop3);
			}
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->doFetchState("tb.enum/EnumInterface", GetEnumInterfaceStateFunc);
	}

	// register notification callback functions, signal/event -> fcn
	NotifyRequestFunc sig0Func = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("param0"))
		{
			Execute_BroadcastSig0(this, fields["param0"].get<ETbEnumEnum0>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("tb.enum/EnumInterface#sig0", sig0Func);
	}

	NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("param1"))
		{
			Execute_BroadcastSig1(this, fields["param1"].get<ETbEnumEnum1>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("tb.enum/EnumInterface#sig1", sig1Func);
	}

	NotifyRequestFunc sig2Func = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("param2"))
		{
			Execute_BroadcastSig2(this, fields["param2"].get<ETbEnumEnum2>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("tb.enum/EnumInterface#sig2", sig2Func);
	}

	NotifyRequestFunc sig3Func = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("param3"))
		{
			Execute_BroadcastSig3(this, fields["param3"].get<ETbEnumEnum3>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("tb.enum/EnumInterface#sig3", sig3Func);
	}
}

UTbEnumEnumInterfaceSimulationService::~UTbEnumEnumInterfaceSimulationService()
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->RemoveOnNotifyState("tb.enum/EnumInterface");
		// unregister notification callback functions
		AGCM->GetSimulationConnection()->RemoveOnNotify("tb.enum/EnumInterface#sig0");
		AGCM->GetSimulationConnection()->RemoveOnNotify("tb.enum/EnumInterface#sig1");
		AGCM->GetSimulationConnection()->RemoveOnNotify("tb.enum/EnumInterface#sig2");
		AGCM->GetSimulationConnection()->RemoveOnNotify("tb.enum/EnumInterface#sig3");
	}
}

void UTbEnumEnumInterfaceSimulationService::BroadcastSig0_Implementation(const ETbEnumEnum0& Param0)
{
	Sig0Signal.Broadcast(Param0);
}

FTbEnumEnumInterfaceSig0Delegate& UTbEnumEnumInterfaceSimulationService::GetSig0SignalDelegate()
{
	return Sig0Signal;
}

void UTbEnumEnumInterfaceSimulationService::BroadcastSig1_Implementation(const ETbEnumEnum1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTbEnumEnumInterfaceSig1Delegate& UTbEnumEnumInterfaceSimulationService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbEnumEnumInterfaceSimulationService::BroadcastSig2_Implementation(const ETbEnumEnum2& Param2)
{
	Sig2Signal.Broadcast(Param2);
}

FTbEnumEnumInterfaceSig2Delegate& UTbEnumEnumInterfaceSimulationService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTbEnumEnumInterfaceSimulationService::BroadcastSig3_Implementation(const ETbEnumEnum3& Param3)
{
	Sig3Signal.Broadcast(Param3);
}

FTbEnumEnumInterfaceSig3Delegate& UTbEnumEnumInterfaceSimulationService::GetSig3SignalDelegate()
{
	return Sig3Signal;
}

void UTbEnumEnumInterfaceSimulationService::BroadcastProp0Changed_Implementation(const ETbEnumEnum0& InProp0)
{
	Prop0 = InProp0;
	Prop0Changed.Broadcast(InProp0);
}

ETbEnumEnum0 UTbEnumEnumInterfaceSimulationService::GetProp0_Implementation() const
{
	return Prop0;
}

void UTbEnumEnumInterfaceSimulationService::SetProp0_Implementation(const ETbEnumEnum0& InProp0)
{
	Params params;
	params["prop0"] = InProp0;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("tb.enum/EnumInterface", "_set", params);
	}
}

FTbEnumEnumInterfaceProp0ChangedDelegate& UTbEnumEnumInterfaceSimulationService::GetProp0ChangedDelegate()
{
	return Prop0Changed;
}

void UTbEnumEnumInterfaceSimulationService::BroadcastProp1Changed_Implementation(const ETbEnumEnum1& InProp1)
{
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

ETbEnumEnum1 UTbEnumEnumInterfaceSimulationService::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbEnumEnumInterfaceSimulationService::SetProp1_Implementation(const ETbEnumEnum1& InProp1)
{
	Params params;
	params["prop1"] = InProp1;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("tb.enum/EnumInterface", "_set", params);
	}
}

FTbEnumEnumInterfaceProp1ChangedDelegate& UTbEnumEnumInterfaceSimulationService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbEnumEnumInterfaceSimulationService::BroadcastProp2Changed_Implementation(const ETbEnumEnum2& InProp2)
{
	Prop2 = InProp2;
	Prop2Changed.Broadcast(InProp2);
}

ETbEnumEnum2 UTbEnumEnumInterfaceSimulationService::GetProp2_Implementation() const
{
	return Prop2;
}

void UTbEnumEnumInterfaceSimulationService::SetProp2_Implementation(const ETbEnumEnum2& InProp2)
{
	Params params;
	params["prop2"] = InProp2;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("tb.enum/EnumInterface", "_set", params);
	}
}

FTbEnumEnumInterfaceProp2ChangedDelegate& UTbEnumEnumInterfaceSimulationService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTbEnumEnumInterfaceSimulationService::BroadcastProp3Changed_Implementation(const ETbEnumEnum3& InProp3)
{
	Prop3 = InProp3;
	Prop3Changed.Broadcast(InProp3);
}

ETbEnumEnum3 UTbEnumEnumInterfaceSimulationService::GetProp3_Implementation() const
{
	return Prop3;
}

void UTbEnumEnumInterfaceSimulationService::SetProp3_Implementation(const ETbEnumEnum3& InProp3)
{
	Params params;
	params["prop3"] = InProp3;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("tb.enum/EnumInterface", "_set", params);
	}
}

FTbEnumEnumInterfaceProp3ChangedDelegate& UTbEnumEnumInterfaceSimulationService::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}

ETbEnumEnum0 UTbEnumEnumInterfaceSimulationService::Func0_Implementation(const ETbEnumEnum0& Param0)
{
	Params params;
	params["param0"] = Param0;
	TPromise<ETbEnumEnum0> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetEnumInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<ETbEnumEnum0>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("tb.enum/EnumInterface", "func0", params, GetEnumInterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}

ETbEnumEnum1 UTbEnumEnumInterfaceSimulationService::Func1_Implementation(const ETbEnumEnum1& Param1)
{
	Params params;
	params["param1"] = Param1;
	TPromise<ETbEnumEnum1> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetEnumInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<ETbEnumEnum1>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("tb.enum/EnumInterface", "func1", params, GetEnumInterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}

ETbEnumEnum2 UTbEnumEnumInterfaceSimulationService::Func2_Implementation(const ETbEnumEnum2& Param2)
{
	Params params;
	params["param2"] = Param2;
	TPromise<ETbEnumEnum2> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetEnumInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<ETbEnumEnum2>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("tb.enum/EnumInterface", "func2", params, GetEnumInterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}

ETbEnumEnum3 UTbEnumEnumInterfaceSimulationService::Func3_Implementation(const ETbEnumEnum3& Param3)
{
	Params params;
	params["param3"] = Param3;
	TPromise<ETbEnumEnum3> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetEnumInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<ETbEnumEnum3>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("tb.enum/EnumInterface", "func3", params, GetEnumInterfaceStateFunc);
			}
		});

	return Promise.GetFuture().Get();
}