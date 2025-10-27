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
#include "Testbed2/Generated/api/Testbed2ManyParamInterfaceBPAdapter.h"
#include "Testbed2ManyParamInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTestbed2ManyParamInterfaceBPAdapter::Initialize(TScriptInterface<ITestbed2ManyParamInterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTestbed2ManyParamInterfacePublisher* UTestbed2ManyParamInterfaceBPAdapter::_GetPublisher()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed2ManyParamInterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTestbed2ManyParamInterfaceBPAdapter::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction<int32>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction<int32>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<int32> Future = Func1Async(Param1);
		FTestbed2ManyParamInterfaceLatentAction<int32>* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction<int32>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<int32> UTestbed2ManyParamInterfaceBPAdapter::Func1Async(int32 Param1)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, this]()
		{
		return Func1(Param1);
	});
}

int32 UTestbed2ManyParamInterfaceBPAdapter::Func1(int32 Param1)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed2ManyParamInterfaceBPInterface::Execute_Func1(Obj, Param1);
	}
	return 0;
}

void UTestbed2ManyParamInterfaceBPAdapter::Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction<int32>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction<int32>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<int32> Future = Func2Async(Param1, Param2);
		FTestbed2ManyParamInterfaceLatentAction<int32>* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction<int32>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<int32> UTestbed2ManyParamInterfaceBPAdapter::Func2Async(int32 Param1, int32 Param2)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, Param2, this]()
		{
		return Func2(Param1, Param2);
	});
}

int32 UTestbed2ManyParamInterfaceBPAdapter::Func2(int32 Param1, int32 Param2)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed2ManyParamInterfaceBPInterface::Execute_Func2(Obj, Param1, Param2);
	}
	return 0;
}

void UTestbed2ManyParamInterfaceBPAdapter::Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction<int32>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction<int32>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<int32> Future = Func3Async(Param1, Param2, Param3);
		FTestbed2ManyParamInterfaceLatentAction<int32>* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction<int32>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<int32> UTestbed2ManyParamInterfaceBPAdapter::Func3Async(int32 Param1, int32 Param2, int32 Param3)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, Param2, Param3, this]()
		{
		return Func3(Param1, Param2, Param3);
	});
}

int32 UTestbed2ManyParamInterfaceBPAdapter::Func3(int32 Param1, int32 Param2, int32 Param3)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed2ManyParamInterfaceBPInterface::Execute_Func3(Obj, Param1, Param2, Param3);
	}
	return 0;
}

void UTestbed2ManyParamInterfaceBPAdapter::Func4Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction<int32>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction<int32>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<int32> Future = Func4Async(Param1, Param2, Param3, Param4);
		FTestbed2ManyParamInterfaceLatentAction<int32>* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction<int32>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<int32> UTestbed2ManyParamInterfaceBPAdapter::Func4Async(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, Param2, Param3, Param4, this]()
		{
		return Func4(Param1, Param2, Param3, Param4);
	});
}

int32 UTestbed2ManyParamInterfaceBPAdapter::Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed2ManyParamInterfaceBPInterface::Execute_Func4(Obj, Param1, Param2, Param3, Param4);
	}
	return 0;
}

int32 UTestbed2ManyParamInterfaceBPAdapter::GetProp1() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed2ManyParamInterfaceBPInterface::Execute_GetProp1(Obj);
	}
	return 0;
}
void UTestbed2ManyParamInterfaceBPAdapter::SetProp1(int32 InProp1)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed2ManyParamInterfaceBPInterface::Execute_SetProp1(Obj, InProp1);
	}
}

int32 UTestbed2ManyParamInterfaceBPAdapter::GetProp2() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed2ManyParamInterfaceBPInterface::Execute_GetProp2(Obj);
	}
	return 0;
}
void UTestbed2ManyParamInterfaceBPAdapter::SetProp2(int32 InProp2)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed2ManyParamInterfaceBPInterface::Execute_SetProp2(Obj, InProp2);
	}
}

int32 UTestbed2ManyParamInterfaceBPAdapter::GetProp3() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed2ManyParamInterfaceBPInterface::Execute_GetProp3(Obj);
	}
	return 0;
}
void UTestbed2ManyParamInterfaceBPAdapter::SetProp3(int32 InProp3)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed2ManyParamInterfaceBPInterface::Execute_SetProp3(Obj, InProp3);
	}
}

int32 UTestbed2ManyParamInterfaceBPAdapter::GetProp4() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITestbed2ManyParamInterfaceBPInterface::Execute_GetProp4(Obj);
	}
	return 0;
}
void UTestbed2ManyParamInterfaceBPAdapter::SetProp4(int32 InProp4)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITestbed2ManyParamInterfaceBPInterface::Execute_SetProp4(Obj, InProp4);
	}
}
