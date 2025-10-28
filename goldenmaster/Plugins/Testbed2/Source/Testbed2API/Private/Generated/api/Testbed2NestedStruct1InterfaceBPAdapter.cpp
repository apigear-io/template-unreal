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
#include "Testbed2/Generated/api/Testbed2NestedStruct1InterfaceBPAdapter.h"
#include "Testbed2NestedStruct1InterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTestbed2NestedStruct1InterfaceBPAdapter::Initialize(TScriptInterface<ITestbed2NestedStruct1InterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTestbed2NestedStruct1InterfacePublisher* UTestbed2NestedStruct1InterfaceBPAdapter::_GetPublisher()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed2NestedStruct1InterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTestbed2NestedStruct1InterfaceBPAdapter::FuncNoReturnValue(const FTestbed2NestedStruct1& Param1)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed2NestedStruct1InterfaceBPInterface::Execute_FuncNoReturnValue(Obj, Param1);
	}
}

void UTestbed2NestedStruct1InterfaceBPAdapter::FuncNoParamsAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed2NestedStruct1> Future = FuncNoParamsAsync();
		FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>* CompletionAction = new FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed2NestedStruct1> UTestbed2NestedStruct1InterfaceBPAdapter::FuncNoParamsAsync()
{
	return Async(EAsyncExecution::ThreadPool,
		[this]()
		{
		return FuncNoParams();
	});
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceBPAdapter::FuncNoParams()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed2NestedStruct1InterfaceBPInterface::Execute_FuncNoParams(Obj);
	}
	return FTestbed2NestedStruct1();
}

void UTestbed2NestedStruct1InterfaceBPAdapter::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed2NestedStruct1> Future = Func1Async(Param1);
		FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>* CompletionAction = new FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed2NestedStruct1> UTestbed2NestedStruct1InterfaceBPAdapter::Func1Async(const FTestbed2NestedStruct1& Param1)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, this]()
		{
		return Func1(Param1);
	});
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceBPAdapter::Func1(const FTestbed2NestedStruct1& Param1)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed2NestedStruct1InterfaceBPInterface::Execute_Func1(Obj, Param1);
	}
	return FTestbed2NestedStruct1();
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceBPAdapter::GetProp1() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed2NestedStruct1InterfaceBPInterface::Execute_GetProp1(Obj);
	}
	return FTestbed2NestedStruct1();
}
void UTestbed2NestedStruct1InterfaceBPAdapter::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed2NestedStruct1InterfaceBPInterface::Execute_SetProp1(Obj, InProp1);
	}
}
