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
#include "Testbed1/Generated/api/Testbed1StructArray2InterfaceBPAdapter.h"
#include "Testbed1StructArray2InterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTestbed1StructArray2InterfaceBPAdapter::Initialize(TScriptInterface<ITestbed1StructArray2InterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTestbed1StructArray2InterfacePublisher* UTestbed1StructArray2InterfaceBPAdapter::_GetPublisher()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArray2InterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTestbed1StructArray2InterfaceBPAdapter::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructBool>& Result, const FTestbed1StructBoolWithArray& ParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructBool>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructBool>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructBool>> Future = FuncBoolAsync(ParamBool);
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructBool>>* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructBool>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructBool>> UTestbed1StructArray2InterfaceBPAdapter::FuncBoolAsync(const FTestbed1StructBoolWithArray& ParamBool)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamBool, this]()
		{
		return FuncBool(ParamBool);
	});
}

TArray<FTestbed1StructBool> UTestbed1StructArray2InterfaceBPAdapter::FuncBool(const FTestbed1StructBoolWithArray& ParamBool)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArray2InterfaceBPInterface::Execute_FuncBool(Obj, ParamBool);
	}
	return TArray<FTestbed1StructBool>();
}

void UTestbed1StructArray2InterfaceBPAdapter::FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructInt>& Result, const FTestbed1StructIntWithArray& ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructInt>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructInt>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructInt>> Future = FuncIntAsync(ParamInt);
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructInt>>* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructInt>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructInt>> UTestbed1StructArray2InterfaceBPAdapter::FuncIntAsync(const FTestbed1StructIntWithArray& ParamInt)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt, this]()
		{
		return FuncInt(ParamInt);
	});
}

TArray<FTestbed1StructInt> UTestbed1StructArray2InterfaceBPAdapter::FuncInt(const FTestbed1StructIntWithArray& ParamInt)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArray2InterfaceBPInterface::Execute_FuncInt(Obj, ParamInt);
	}
	return TArray<FTestbed1StructInt>();
}

void UTestbed1StructArray2InterfaceBPAdapter::FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructFloat>& Result, const FTestbed1StructFloatWithArray& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructFloat>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructFloat>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructFloat>> Future = FuncFloatAsync(ParamFloat);
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructFloat>>* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructFloat>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructFloat>> UTestbed1StructArray2InterfaceBPAdapter::FuncFloatAsync(const FTestbed1StructFloatWithArray& ParamFloat)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat, this]()
		{
		return FuncFloat(ParamFloat);
	});
}

TArray<FTestbed1StructFloat> UTestbed1StructArray2InterfaceBPAdapter::FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArray2InterfaceBPInterface::Execute_FuncFloat(Obj, ParamFloat);
	}
	return TArray<FTestbed1StructFloat>();
}

void UTestbed1StructArray2InterfaceBPAdapter::FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructString>& Result, const FTestbed1StructStringWithArray& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructString>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructString>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructString>> Future = FuncStringAsync(ParamString);
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructString>>* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructString>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructString>> UTestbed1StructArray2InterfaceBPAdapter::FuncStringAsync(const FTestbed1StructStringWithArray& ParamString)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamString, this]()
		{
		return FuncString(ParamString);
	});
}

TArray<FTestbed1StructString> UTestbed1StructArray2InterfaceBPAdapter::FuncString(const FTestbed1StructStringWithArray& ParamString)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArray2InterfaceBPInterface::Execute_FuncString(Obj, ParamString);
	}
	return TArray<FTestbed1StructString>();
}

void UTestbed1StructArray2InterfaceBPAdapter::FuncEnumAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<ETestbed1Enum0>& Result, const FTestbed1StructEnumWithArray& ParamEnum)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction<TArray<ETestbed1Enum0>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction<TArray<ETestbed1Enum0>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<ETestbed1Enum0>> Future = FuncEnumAsync(ParamEnum);
		FTestbed1StructArray2InterfaceLatentAction<TArray<ETestbed1Enum0>>* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction<TArray<ETestbed1Enum0>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<ETestbed1Enum0>> UTestbed1StructArray2InterfaceBPAdapter::FuncEnumAsync(const FTestbed1StructEnumWithArray& ParamEnum)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamEnum, this]()
		{
		return FuncEnum(ParamEnum);
	});
}

TArray<ETestbed1Enum0> UTestbed1StructArray2InterfaceBPAdapter::FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArray2InterfaceBPInterface::Execute_FuncEnum(Obj, ParamEnum);
	}
	return TArray<ETestbed1Enum0>();
}

FTestbed1StructBoolWithArray UTestbed1StructArray2InterfaceBPAdapter::GetPropBool() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArray2InterfaceBPInterface::Execute_GetPropBool(Obj);
	}
	return FTestbed1StructBoolWithArray();
}
void UTestbed1StructArray2InterfaceBPAdapter::SetPropBool(const FTestbed1StructBoolWithArray& InPropBool)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed1StructArray2InterfaceBPInterface::Execute_SetPropBool(Obj, InPropBool);
	}
}

FTestbed1StructIntWithArray UTestbed1StructArray2InterfaceBPAdapter::GetPropInt() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArray2InterfaceBPInterface::Execute_GetPropInt(Obj);
	}
	return FTestbed1StructIntWithArray();
}
void UTestbed1StructArray2InterfaceBPAdapter::SetPropInt(const FTestbed1StructIntWithArray& InPropInt)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed1StructArray2InterfaceBPInterface::Execute_SetPropInt(Obj, InPropInt);
	}
}

FTestbed1StructFloatWithArray UTestbed1StructArray2InterfaceBPAdapter::GetPropFloat() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArray2InterfaceBPInterface::Execute_GetPropFloat(Obj);
	}
	return FTestbed1StructFloatWithArray();
}
void UTestbed1StructArray2InterfaceBPAdapter::SetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed1StructArray2InterfaceBPInterface::Execute_SetPropFloat(Obj, InPropFloat);
	}
}

FTestbed1StructStringWithArray UTestbed1StructArray2InterfaceBPAdapter::GetPropString() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArray2InterfaceBPInterface::Execute_GetPropString(Obj);
	}
	return FTestbed1StructStringWithArray();
}
void UTestbed1StructArray2InterfaceBPAdapter::SetPropString(const FTestbed1StructStringWithArray& InPropString)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed1StructArray2InterfaceBPInterface::Execute_SetPropString(Obj, InPropString);
	}
}

FTestbed1StructEnumWithArray UTestbed1StructArray2InterfaceBPAdapter::GetPropEnum() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed1StructArray2InterfaceBPInterface::Execute_GetPropEnum(Obj);
	}
	return FTestbed1StructEnumWithArray();
}
void UTestbed1StructArray2InterfaceBPAdapter::SetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed1StructArray2InterfaceBPInterface::Execute_SetPropEnum(Obj, InPropEnum);
	}
}
