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
#include "Testbed2/Generated/api/Testbed2NestedStruct2InterfaceBPAdapter.h"
#include "Testbed2NestedStruct2InterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTestbed2NestedStruct2InterfaceBPAdapter::Initialize(TScriptInterface<ITestbed2NestedStruct2InterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTestbed2NestedStruct2InterfacePublisher* UTestbed2NestedStruct2InterfaceBPAdapter::_GetPublisher()
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITestbed2NestedStruct2InterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTestbed2NestedStruct2InterfaceBPAdapter::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed2NestedStruct1> Future = Func1Async(Param1);
		FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>* CompletionAction = new FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed2NestedStruct1> UTestbed2NestedStruct2InterfaceBPAdapter::Func1Async(const FTestbed2NestedStruct1& Param1)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, this]()
		{
		return Func1(Param1);
	});
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceBPAdapter::Func1(const FTestbed2NestedStruct1& Param1)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITestbed2NestedStruct2InterfaceBPInterface::Execute_Func1(Obj, Param1);
	}
	return FTestbed2NestedStruct1();
}

void UTestbed2NestedStruct2InterfaceBPAdapter::Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed2NestedStruct1> Future = Func2Async(Param1, Param2);
		FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>* CompletionAction = new FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed2NestedStruct1> UTestbed2NestedStruct2InterfaceBPAdapter::Func2Async(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, Param2, this]()
		{
		return Func2(Param1, Param2);
	});
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceBPAdapter::Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITestbed2NestedStruct2InterfaceBPInterface::Execute_Func2(Obj, Param1, Param2);
	}
	return FTestbed2NestedStruct1();
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceBPAdapter::GetProp1() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITestbed2NestedStruct2InterfaceBPInterface::Execute_GetProp1(Obj);
	}
	return FTestbed2NestedStruct1();
}
void UTestbed2NestedStruct2InterfaceBPAdapter::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITestbed2NestedStruct2InterfaceBPInterface::Execute_SetProp1(Obj, InProp1);
	}
}

FTestbed2NestedStruct2 UTestbed2NestedStruct2InterfaceBPAdapter::GetProp2() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITestbed2NestedStruct2InterfaceBPInterface::Execute_GetProp2(Obj);
	}
	return FTestbed2NestedStruct2();
}
void UTestbed2NestedStruct2InterfaceBPAdapter::SetProp2(const FTestbed2NestedStruct2& InProp2)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITestbed2NestedStruct2InterfaceBPInterface::Execute_SetProp2(Obj, InProp2);
	}
}
