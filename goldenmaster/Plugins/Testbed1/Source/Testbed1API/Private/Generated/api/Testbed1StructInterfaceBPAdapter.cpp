/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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
#include "Testbed1/Generated/api/Testbed1StructInterfaceBPAdapter.h"
#include "Testbed1StructInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTestbed1StructInterfaceBPAdapter::Initialize(TScriptInterface<ITestbed1StructInterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTestbed1StructInterfacePublisher* UTestbed1StructInterfaceBPAdapter::_GetPublisher()
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITestbed1StructInterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTestbed1StructInterfaceBPAdapter::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction<FTestbed1StructBool>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction<FTestbed1StructBool>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed1StructBool> Future = FuncBoolAsync(ParamBool);
		FTestbed1StructInterfaceLatentAction<FTestbed1StructBool>* CompletionAction = new FTestbed1StructInterfaceLatentAction<FTestbed1StructBool>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed1StructBool> UTestbed1StructInterfaceBPAdapter::FuncBoolAsync(const FTestbed1StructBool& ParamBool)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamBool, this]()
		{
		return FuncBool(ParamBool);
	});
}

FTestbed1StructBool UTestbed1StructInterfaceBPAdapter::FuncBool(const FTestbed1StructBool& ParamBool)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITestbed1StructInterfaceBPInterface::Execute_FuncBool(Obj, ParamBool);
	}
	return FTestbed1StructBool();
}

void UTestbed1StructInterfaceBPAdapter::FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructInt& Result, const FTestbed1StructInt& ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction<FTestbed1StructInt>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction<FTestbed1StructInt>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed1StructInt> Future = FuncIntAsync(ParamInt);
		FTestbed1StructInterfaceLatentAction<FTestbed1StructInt>* CompletionAction = new FTestbed1StructInterfaceLatentAction<FTestbed1StructInt>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed1StructInt> UTestbed1StructInterfaceBPAdapter::FuncIntAsync(const FTestbed1StructInt& ParamInt)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt, this]()
		{
		return FuncInt(ParamInt);
	});
}

FTestbed1StructInt UTestbed1StructInterfaceBPAdapter::FuncInt(const FTestbed1StructInt& ParamInt)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITestbed1StructInterfaceBPInterface::Execute_FuncInt(Obj, ParamInt);
	}
	return FTestbed1StructInt();
}

void UTestbed1StructInterfaceBPAdapter::FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction<FTestbed1StructFloat>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction<FTestbed1StructFloat>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed1StructFloat> Future = FuncFloatAsync(ParamFloat);
		FTestbed1StructInterfaceLatentAction<FTestbed1StructFloat>* CompletionAction = new FTestbed1StructInterfaceLatentAction<FTestbed1StructFloat>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed1StructFloat> UTestbed1StructInterfaceBPAdapter::FuncFloatAsync(const FTestbed1StructFloat& ParamFloat)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat, this]()
		{
		return FuncFloat(ParamFloat);
	});
}

FTestbed1StructFloat UTestbed1StructInterfaceBPAdapter::FuncFloat(const FTestbed1StructFloat& ParamFloat)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITestbed1StructInterfaceBPInterface::Execute_FuncFloat(Obj, ParamFloat);
	}
	return FTestbed1StructFloat();
}

void UTestbed1StructInterfaceBPAdapter::FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction<FTestbed1StructString>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction<FTestbed1StructString>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed1StructString> Future = FuncStringAsync(ParamString);
		FTestbed1StructInterfaceLatentAction<FTestbed1StructString>* CompletionAction = new FTestbed1StructInterfaceLatentAction<FTestbed1StructString>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed1StructString> UTestbed1StructInterfaceBPAdapter::FuncStringAsync(const FTestbed1StructString& ParamString)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamString, this]()
		{
		return FuncString(ParamString);
	});
}

FTestbed1StructString UTestbed1StructInterfaceBPAdapter::FuncString(const FTestbed1StructString& ParamString)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITestbed1StructInterfaceBPInterface::Execute_FuncString(Obj, ParamString);
	}
	return FTestbed1StructString();
}

FTestbed1StructBool UTestbed1StructInterfaceBPAdapter::GetPropBool() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITestbed1StructInterfaceBPInterface::Execute_GetPropBool(Obj);
	}
	return FTestbed1StructBool();
}
void UTestbed1StructInterfaceBPAdapter::SetPropBool(const FTestbed1StructBool& InPropBool)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITestbed1StructInterfaceBPInterface::Execute_SetPropBool(Obj, InPropBool);
	}
}

FTestbed1StructInt UTestbed1StructInterfaceBPAdapter::GetPropInt() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITestbed1StructInterfaceBPInterface::Execute_GetPropInt(Obj);
	}
	return FTestbed1StructInt();
}
void UTestbed1StructInterfaceBPAdapter::SetPropInt(const FTestbed1StructInt& InPropInt)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITestbed1StructInterfaceBPInterface::Execute_SetPropInt(Obj, InPropInt);
	}
}

FTestbed1StructFloat UTestbed1StructInterfaceBPAdapter::GetPropFloat() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITestbed1StructInterfaceBPInterface::Execute_GetPropFloat(Obj);
	}
	return FTestbed1StructFloat();
}
void UTestbed1StructInterfaceBPAdapter::SetPropFloat(const FTestbed1StructFloat& InPropFloat)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITestbed1StructInterfaceBPInterface::Execute_SetPropFloat(Obj, InPropFloat);
	}
}

FTestbed1StructString UTestbed1StructInterfaceBPAdapter::GetPropString() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITestbed1StructInterfaceBPInterface::Execute_GetPropString(Obj);
	}
	return FTestbed1StructString();
}
void UTestbed1StructInterfaceBPAdapter::SetPropString(const FTestbed1StructString& InPropString)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITestbed1StructInterfaceBPInterface::Execute_SetPropString(Obj, InPropString);
	}
}
