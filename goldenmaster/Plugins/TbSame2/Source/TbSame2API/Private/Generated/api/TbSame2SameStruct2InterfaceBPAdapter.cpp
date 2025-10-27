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
#include "TbSame2/Generated/api/TbSame2SameStruct2InterfaceBPAdapter.h"
#include "TbSame2SameStruct2InterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTbSame2SameStruct2InterfaceBPAdapter::Initialize(TScriptInterface<ITbSame2SameStruct2InterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTbSame2SameStruct2InterfacePublisher* UTbSame2SameStruct2InterfaceBPAdapter::_GetPublisher()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbSame2SameStruct2InterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTbSame2SameStruct2InterfaceBPAdapter::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTbSame2Struct1> Future = Func1Async(Param1);
		FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>* CompletionAction = new FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTbSame2Struct1> UTbSame2SameStruct2InterfaceBPAdapter::Func1Async(const FTbSame2Struct1& Param1)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, this]()
		{
		return Func1(Param1);
	});
}

FTbSame2Struct1 UTbSame2SameStruct2InterfaceBPAdapter::Func1(const FTbSame2Struct1& Param1)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbSame2SameStruct2InterfaceBPInterface::Execute_Func1(Obj, Param1);
	}
	return FTbSame2Struct1();
}

void UTbSame2SameStruct2InterfaceBPAdapter::Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTbSame2Struct1> Future = Func2Async(Param1, Param2);
		FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>* CompletionAction = new FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTbSame2Struct1> UTbSame2SameStruct2InterfaceBPAdapter::Func2Async(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, Param2, this]()
		{
		return Func2(Param1, Param2);
	});
}

FTbSame2Struct1 UTbSame2SameStruct2InterfaceBPAdapter::Func2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbSame2SameStruct2InterfaceBPInterface::Execute_Func2(Obj, Param1, Param2);
	}
	return FTbSame2Struct1();
}

FTbSame2Struct2 UTbSame2SameStruct2InterfaceBPAdapter::GetProp1() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbSame2SameStruct2InterfaceBPInterface::Execute_GetProp1(Obj);
	}
	return FTbSame2Struct2();
}
void UTbSame2SameStruct2InterfaceBPAdapter::SetProp1(const FTbSame2Struct2& InProp1)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbSame2SameStruct2InterfaceBPInterface::Execute_SetProp1(Obj, InProp1);
	}
}

FTbSame2Struct2 UTbSame2SameStruct2InterfaceBPAdapter::GetProp2() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbSame2SameStruct2InterfaceBPInterface::Execute_GetProp2(Obj);
	}
	return FTbSame2Struct2();
}
void UTbSame2SameStruct2InterfaceBPAdapter::SetProp2(const FTbSame2Struct2& InProp2)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbSame2SameStruct2InterfaceBPInterface::Execute_SetProp2(Obj, InProp2);
	}
}
