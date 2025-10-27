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
#include "TbEnum/Generated/api/TbEnumEnumInterfaceBPAdapter.h"
#include "TbEnumEnumInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTbEnumEnumInterfaceBPAdapter::Initialize(TScriptInterface<ITbEnumEnumInterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTbEnumEnumInterfacePublisher* UTbEnumEnumInterfaceBPAdapter::_GetPublisher()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbEnumEnumInterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTbEnumEnumInterfaceBPAdapter::Func0Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum0>* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction<ETbEnumEnum0>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbEnumEnum0> Future = Func0Async(Param0);
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum0>* CompletionAction = new FTbEnumEnumInterfaceLatentAction<ETbEnumEnum0>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbEnumEnum0> UTbEnumEnumInterfaceBPAdapter::Func0Async(ETbEnumEnum0 Param0)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param0, this]()
		{
		return Func0(Param0);
	});
}

ETbEnumEnum0 UTbEnumEnumInterfaceBPAdapter::Func0(ETbEnumEnum0 Param0)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbEnumEnumInterfaceBPInterface::Execute_Func0(Obj, Param0);
	}
	return ETbEnumEnum0::TEE0_Value0;
}

void UTbEnumEnumInterfaceBPAdapter::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum1>* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction<ETbEnumEnum1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbEnumEnum1> Future = Func1Async(Param1);
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum1>* CompletionAction = new FTbEnumEnumInterfaceLatentAction<ETbEnumEnum1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbEnumEnum1> UTbEnumEnumInterfaceBPAdapter::Func1Async(ETbEnumEnum1 Param1)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, this]()
		{
		return Func1(Param1);
	});
}

ETbEnumEnum1 UTbEnumEnumInterfaceBPAdapter::Func1(ETbEnumEnum1 Param1)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbEnumEnumInterfaceBPInterface::Execute_Func1(Obj, Param1);
	}
	return ETbEnumEnum1::TEE1_Value1;
}

void UTbEnumEnumInterfaceBPAdapter::Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum2>* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction<ETbEnumEnum2>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbEnumEnum2> Future = Func2Async(Param2);
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum2>* CompletionAction = new FTbEnumEnumInterfaceLatentAction<ETbEnumEnum2>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbEnumEnum2> UTbEnumEnumInterfaceBPAdapter::Func2Async(ETbEnumEnum2 Param2)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param2, this]()
		{
		return Func2(Param2);
	});
}

ETbEnumEnum2 UTbEnumEnumInterfaceBPAdapter::Func2(ETbEnumEnum2 Param2)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbEnumEnumInterfaceBPInterface::Execute_Func2(Obj, Param2);
	}
	return ETbEnumEnum2::TEE2_Value2;
}

void UTbEnumEnumInterfaceBPAdapter::Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum3>* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction<ETbEnumEnum3>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbEnumEnum3> Future = Func3Async(Param3);
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum3>* CompletionAction = new FTbEnumEnumInterfaceLatentAction<ETbEnumEnum3>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbEnumEnum3> UTbEnumEnumInterfaceBPAdapter::Func3Async(ETbEnumEnum3 Param3)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param3, this]()
		{
		return Func3(Param3);
	});
}

ETbEnumEnum3 UTbEnumEnumInterfaceBPAdapter::Func3(ETbEnumEnum3 Param3)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbEnumEnumInterfaceBPInterface::Execute_Func3(Obj, Param3);
	}
	return ETbEnumEnum3::TEE3_Value3;
}

ETbEnumEnum0 UTbEnumEnumInterfaceBPAdapter::GetProp0() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbEnumEnumInterfaceBPInterface::Execute_GetProp0(Obj);
	}
	return ETbEnumEnum0::TEE0_Value0;
}
void UTbEnumEnumInterfaceBPAdapter::SetProp0(ETbEnumEnum0 InProp0)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbEnumEnumInterfaceBPInterface::Execute_SetProp0(Obj, InProp0);
	}
}

ETbEnumEnum1 UTbEnumEnumInterfaceBPAdapter::GetProp1() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbEnumEnumInterfaceBPInterface::Execute_GetProp1(Obj);
	}
	return ETbEnumEnum1::TEE1_Value1;
}
void UTbEnumEnumInterfaceBPAdapter::SetProp1(ETbEnumEnum1 InProp1)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbEnumEnumInterfaceBPInterface::Execute_SetProp1(Obj, InProp1);
	}
}

ETbEnumEnum2 UTbEnumEnumInterfaceBPAdapter::GetProp2() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbEnumEnumInterfaceBPInterface::Execute_GetProp2(Obj);
	}
	return ETbEnumEnum2::TEE2_Value2;
}
void UTbEnumEnumInterfaceBPAdapter::SetProp2(ETbEnumEnum2 InProp2)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbEnumEnumInterfaceBPInterface::Execute_SetProp2(Obj, InProp2);
	}
}

ETbEnumEnum3 UTbEnumEnumInterfaceBPAdapter::GetProp3() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbEnumEnumInterfaceBPInterface::Execute_GetProp3(Obj);
	}
	return ETbEnumEnum3::TEE3_Value3;
}
void UTbEnumEnumInterfaceBPAdapter::SetProp3(ETbEnumEnum3 InProp3)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbEnumEnumInterfaceBPInterface::Execute_SetProp3(Obj, InProp3);
	}
}
