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

#include "TbSimpleSimpleInterfaceSimulation.h"
#include "apig/TbSimple.json.adapter.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "unrealsimulation.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

using namespace ApiGear::JSONRPC;
UTbSimpleSimpleInterfaceSimulationService::UTbSimpleSimpleInterfaceSimulationService()
	: ITbSimpleSimpleInterfaceInterface()
	, bPropBool(false)
	, PropInt(0)
	, PropFloat(0.0f)
	, PropString(FString())
{
	UApiGearConnectionManager* AGCM = nullptr;
	if (GEngine != nullptr)
	{
		AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
	}
	NotifyRequestFunc SimpleInterfaceStateChangedFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("propBool"))
		{
			if (bPropBool != fields["propBool"].get<bool>())
			{
				bPropBool = fields["propBool"].get<bool>();
				PropBoolChanged.Broadcast(bPropBool);
			}
		}
		if (fields.contains("propInt"))
		{
			if (PropInt != fields["propInt"].get<int32>())
			{
				PropInt = fields["propInt"].get<int32>();
				PropIntChanged.Broadcast(PropInt);
			}
		}
		if (fields.contains("propFloat"))
		{
			if (PropFloat != fields["propFloat"].get<float>())
			{
				PropFloat = fields["propFloat"].get<float>();
				PropFloatChanged.Broadcast(PropFloat);
			}
		}
		if (fields.contains("propString"))
		{
			if (PropString != fields["propString"].get<FString>())
			{
				PropString = fields["propString"].get<FString>();
				PropStringChanged.Broadcast(PropString);
			}
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->Connect();
		AGCM->GetSimulationConnection()->onNotifyState("tb.simple/SimpleInterface", SimpleInterfaceStateChangedFunc);
	}

	CallResponseFunc GetSimpleInterfaceStateFunc = [this](CallResponseArg arg)
	{
		if (arg.result.size() != 1)
		{
			return;
		}
		const json fields = arg.result;
		if (fields.contains("propBool"))
		{
			if (bPropBool != fields["propBool"].get<bool>())
			{
				bPropBool = fields["propBool"].get<bool>();
				PropBoolChanged.Broadcast(bPropBool);
			}
		}
		if (fields.contains("propInt"))
		{
			if (PropInt != fields["propInt"].get<int32>())
			{
				PropInt = fields["propInt"].get<int32>();
				PropIntChanged.Broadcast(PropInt);
			}
		}
		if (fields.contains("propFloat"))
		{
			if (PropFloat != fields["propFloat"].get<float>())
			{
				PropFloat = fields["propFloat"].get<float>();
				PropFloatChanged.Broadcast(PropFloat);
			}
		}
		if (fields.contains("propString"))
		{
			if (PropString != fields["propString"].get<FString>())
			{
				PropString = fields["propString"].get<FString>();
				PropStringChanged.Broadcast(PropString);
			}
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->doFetchState("tb.simple/SimpleInterface", GetSimpleInterfaceStateFunc);
	}

	// register notification callback functions, signal/event -> fcn
	NotifyRequestFunc sigBoolFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("paramBool"))
		{
			SigBoolSignal.Broadcast(fields["paramBool"].get<bool>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("tb.simple/SimpleInterface#sigBool", sigBoolFunc);
	}

	NotifyRequestFunc sigIntFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("paramInt"))
		{
			SigIntSignal.Broadcast(fields["paramInt"].get<int32>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("tb.simple/SimpleInterface#sigInt", sigIntFunc);
	}

	NotifyRequestFunc sigFloatFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("paramFloat"))
		{
			SigFloatSignal.Broadcast(fields["paramFloat"].get<float>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("tb.simple/SimpleInterface#sigFloat", sigFloatFunc);
	}

	NotifyRequestFunc sigStringFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
		if (fields.contains("paramString"))
		{
			SigStringSignal.Broadcast(fields["paramString"].get<FString>());
		}
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->onNotify("tb.simple/SimpleInterface#sigString", sigStringFunc);
	}
}

UTbSimpleSimpleInterfaceSimulationService::~UTbSimpleSimpleInterfaceSimulationService()
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->RemoveOnNotifyState("tb.simple/SimpleInterface");
		// unregister notification callback functions
		AGCM->GetSimulationConnection()->RemoveOnNotify("tb.simple/SimpleInterface#sigBool");
		AGCM->GetSimulationConnection()->RemoveOnNotify("tb.simple/SimpleInterface#sigInt");
		AGCM->GetSimulationConnection()->RemoveOnNotify("tb.simple/SimpleInterface#sigFloat");
		AGCM->GetSimulationConnection()->RemoveOnNotify("tb.simple/SimpleInterface#sigString");
	}
}

FTbSimpleSimpleInterfaceSigBoolDelegate& UTbSimpleSimpleInterfaceSimulationService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

FTbSimpleSimpleInterfaceSigIntDelegate& UTbSimpleSimpleInterfaceSimulationService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

FTbSimpleSimpleInterfaceSigFloatDelegate& UTbSimpleSimpleInterfaceSimulationService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

FTbSimpleSimpleInterfaceSigStringDelegate& UTbSimpleSimpleInterfaceSimulationService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTbSimpleSimpleInterfaceSimulationService::GetPropBool_Implementation(bool& ReturnValue) const
{
	ReturnValue = bPropBool;
}

void UTbSimpleSimpleInterfaceSimulationService::SetPropBool_Implementation(bool bInPropBool)
{
	Params params;
	params["propBool"] = bInPropBool;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("tb.simple/SimpleInterface", "_set", params);
	}
}

FTbSimpleSimpleInterfacePropBoolChangedDelegate& UTbSimpleSimpleInterfaceSimulationService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTbSimpleSimpleInterfaceSimulationService::GetPropInt_Implementation(int32& ReturnValue) const
{
	ReturnValue = PropInt;
}

void UTbSimpleSimpleInterfaceSimulationService::SetPropInt_Implementation(int32 InPropInt)
{
	Params params;
	params["propInt"] = InPropInt;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("tb.simple/SimpleInterface", "_set", params);
	}
}

FTbSimpleSimpleInterfacePropIntChangedDelegate& UTbSimpleSimpleInterfaceSimulationService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTbSimpleSimpleInterfaceSimulationService::GetPropFloat_Implementation(float& ReturnValue) const
{
	ReturnValue = PropFloat;
}

void UTbSimpleSimpleInterfaceSimulationService::SetPropFloat_Implementation(float InPropFloat)
{
	Params params;
	params["propFloat"] = InPropFloat;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("tb.simple/SimpleInterface", "_set", params);
	}
}

FTbSimpleSimpleInterfacePropFloatChangedDelegate& UTbSimpleSimpleInterfaceSimulationService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTbSimpleSimpleInterfaceSimulationService::GetPropString_Implementation(FString& ReturnValue) const
{
	ReturnValue = PropString;
}

void UTbSimpleSimpleInterfaceSimulationService::SetPropString_Implementation(const FString& InPropString)
{
	Params params;
	params["propString"] = InPropString;
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->doCall("tb.simple/SimpleInterface", "_set", params);
	}
}

FTbSimpleSimpleInterfacePropStringChangedDelegate& UTbSimpleSimpleInterfaceSimulationService::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

void UTbSimpleSimpleInterfaceSimulationService::FuncBool_Implementation(bool& Result, bool bParamBool)
{
	Params params;
	params["paramBool"] = bParamBool;
	TPromise<bool> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetSimpleInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<bool>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("tb.simple/SimpleInterface", "funcBool", params, GetSimpleInterfaceStateFunc);
			}
		});

	Result = Promise.GetFuture().Get();
}

void UTbSimpleSimpleInterfaceSimulationService::FuncInt_Implementation(int32& Result, int32 ParamInt)
{
	Params params;
	params["paramInt"] = ParamInt;
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetSimpleInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<int32>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("tb.simple/SimpleInterface", "funcInt", params, GetSimpleInterfaceStateFunc);
			}
		});

	Result = Promise.GetFuture().Get();
}

void UTbSimpleSimpleInterfaceSimulationService::FuncFloat_Implementation(float& Result, float ParamFloat)
{
	Params params;
	params["paramFloat"] = ParamFloat;
	TPromise<float> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetSimpleInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<float>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("tb.simple/SimpleInterface", "funcFloat", params, GetSimpleInterfaceStateFunc);
			}
		});

	Result = Promise.GetFuture().Get();
}

void UTbSimpleSimpleInterfaceSimulationService::FuncString_Implementation(FString& Result, const FString& ParamString)
{
	Params params;
	params["paramString"] = ParamString;
	TPromise<FString> Promise;
	Async(EAsyncExecution::Thread,
		[params, &Promise]()
		{
			CallResponseFunc GetSimpleInterfaceStateFunc = [&Promise](CallResponseArg arg)
			{ Promise.SetValue(arg.result.get<FString>()); };
			if (GEngine != nullptr)
			{
				UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
				AGCM->GetSimulationConnection()->doCall("tb.simple/SimpleInterface", "funcString", params, GetSimpleInterfaceStateFunc);
			}
		});

	Result = Promise.GetFuture().Get();
}
