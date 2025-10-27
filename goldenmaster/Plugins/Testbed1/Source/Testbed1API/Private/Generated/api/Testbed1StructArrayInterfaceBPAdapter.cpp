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
#include "Testbed1/Generated/api/Testbed1StructArrayInterfaceBPAdapter.h"
#include "Testbed1StructArrayInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTestbed1StructArrayInterfaceBPAdapter::Initialize(TScriptInterface<ITestbed1StructArrayInterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTestbed1StructArrayInterfacePublisher* UTestbed1StructArrayInterfaceBPAdapter::_GetPublisher()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArrayInterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTestbed1StructArrayInterfaceBPAdapter::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructBool>& Result, const TArray<FTestbed1StructBool>& ParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructBool>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructBool>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructBool>> Future = FuncBoolAsync(ParamBool);
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructBool>>* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructBool>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructBool>> UTestbed1StructArrayInterfaceBPAdapter::FuncBoolAsync(const TArray<FTestbed1StructBool>& ParamBool)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamBool, this]()
		{
		return FuncBool(ParamBool);
	});
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceBPAdapter::FuncBool(const TArray<FTestbed1StructBool>& ParamBool)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArrayInterfaceBPInterface::Execute_FuncBool(Obj, ParamBool);
	}
	return TArray<FTestbed1StructBool>();
}

void UTestbed1StructArrayInterfaceBPAdapter::FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructInt>& Result, const TArray<FTestbed1StructInt>& ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructInt>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructInt>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructInt>> Future = FuncIntAsync(ParamInt);
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructInt>>* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructInt>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructInt>> UTestbed1StructArrayInterfaceBPAdapter::FuncIntAsync(const TArray<FTestbed1StructInt>& ParamInt)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt, this]()
		{
		return FuncInt(ParamInt);
	});
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceBPAdapter::FuncInt(const TArray<FTestbed1StructInt>& ParamInt)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArrayInterfaceBPInterface::Execute_FuncInt(Obj, ParamInt);
	}
	return TArray<FTestbed1StructInt>();
}

void UTestbed1StructArrayInterfaceBPAdapter::FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructFloat>& Result, const TArray<FTestbed1StructFloat>& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructFloat>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructFloat>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructFloat>> Future = FuncFloatAsync(ParamFloat);
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructFloat>>* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructFloat>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructFloat>> UTestbed1StructArrayInterfaceBPAdapter::FuncFloatAsync(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat, this]()
		{
		return FuncFloat(ParamFloat);
	});
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceBPAdapter::FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArrayInterfaceBPInterface::Execute_FuncFloat(Obj, ParamFloat);
	}
	return TArray<FTestbed1StructFloat>();
}

void UTestbed1StructArrayInterfaceBPAdapter::FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructString>& Result, const TArray<FTestbed1StructString>& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructString>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructString>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructString>> Future = FuncStringAsync(ParamString);
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructString>>* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructString>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructString>> UTestbed1StructArrayInterfaceBPAdapter::FuncStringAsync(const TArray<FTestbed1StructString>& ParamString)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamString, this]()
		{
		return FuncString(ParamString);
	});
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceBPAdapter::FuncString(const TArray<FTestbed1StructString>& ParamString)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArrayInterfaceBPInterface::Execute_FuncString(Obj, ParamString);
	}
	return TArray<FTestbed1StructString>();
}

void UTestbed1StructArrayInterfaceBPAdapter::FuncEnumAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<ETestbed1Enum0>& Result, const TArray<ETestbed1Enum0>& ParamEnum)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction<TArray<ETestbed1Enum0>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction<TArray<ETestbed1Enum0>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<ETestbed1Enum0>> Future = FuncEnumAsync(ParamEnum);
		FTestbed1StructArrayInterfaceLatentAction<TArray<ETestbed1Enum0>>* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction<TArray<ETestbed1Enum0>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<ETestbed1Enum0>> UTestbed1StructArrayInterfaceBPAdapter::FuncEnumAsync(const TArray<ETestbed1Enum0>& ParamEnum)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamEnum, this]()
		{
		return FuncEnum(ParamEnum);
	});
}

TArray<ETestbed1Enum0> UTestbed1StructArrayInterfaceBPAdapter::FuncEnum(const TArray<ETestbed1Enum0>& ParamEnum)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArrayInterfaceBPInterface::Execute_FuncEnum(Obj, ParamEnum);
	}
	return TArray<ETestbed1Enum0>();
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceBPAdapter::GetPropBool() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArrayInterfaceBPInterface::Execute_GetPropBool(Obj);
	}
	return TArray<FTestbed1StructBool>();
}
void UTestbed1StructArrayInterfaceBPAdapter::SetPropBool(const TArray<FTestbed1StructBool>& InPropBool)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed1StructArrayInterfaceBPInterface::Execute_SetPropBool(Obj, InPropBool);
	}
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceBPAdapter::GetPropInt() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArrayInterfaceBPInterface::Execute_GetPropInt(Obj);
	}
	return TArray<FTestbed1StructInt>();
}
void UTestbed1StructArrayInterfaceBPAdapter::SetPropInt(const TArray<FTestbed1StructInt>& InPropInt)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed1StructArrayInterfaceBPInterface::Execute_SetPropInt(Obj, InPropInt);
	}
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceBPAdapter::GetPropFloat() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArrayInterfaceBPInterface::Execute_GetPropFloat(Obj);
	}
	return TArray<FTestbed1StructFloat>();
}
void UTestbed1StructArrayInterfaceBPAdapter::SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed1StructArrayInterfaceBPInterface::Execute_SetPropFloat(Obj, InPropFloat);
	}
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceBPAdapter::GetPropString() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArrayInterfaceBPInterface::Execute_GetPropString(Obj);
	}
	return TArray<FTestbed1StructString>();
}
void UTestbed1StructArrayInterfaceBPAdapter::SetPropString(const TArray<FTestbed1StructString>& InPropString)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed1StructArrayInterfaceBPInterface::Execute_SetPropString(Obj, InPropString);
	}
}

TArray<ETestbed1Enum0> UTestbed1StructArrayInterfaceBPAdapter::GetPropEnum() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArrayInterfaceBPInterface::Execute_GetPropEnum(Obj);
	}
	return TArray<ETestbed1Enum0>();
}
void UTestbed1StructArrayInterfaceBPAdapter::SetPropEnum(const TArray<ETestbed1Enum0>& InPropEnum)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed1StructArrayInterfaceBPInterface::Execute_SetPropEnum(Obj, InPropEnum);
	}
}
