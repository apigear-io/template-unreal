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
#include "TbSame2/Generated/api/TbSame2SameEnum2InterfaceBPAdapter.h"
#include "TbSame2SameEnum2InterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTbSame2SameEnum2InterfaceBPAdapter::Initialize(TScriptInterface<ITbSame2SameEnum2InterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTbSame2SameEnum2InterfacePublisher* UTbSame2SameEnum2InterfaceBPAdapter::_GetPublisher()
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSame2SameEnum2InterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTbSame2SameEnum2InterfaceBPAdapter::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbSame2Enum1> Future = Func1Async(Param1);
		FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>* CompletionAction = new FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbSame2Enum1> UTbSame2SameEnum2InterfaceBPAdapter::Func1Async(ETbSame2Enum1 Param1)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, this]()
		{
		return Func1(Param1);
	});
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceBPAdapter::Func1(ETbSame2Enum1 Param1)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSame2SameEnum2InterfaceBPInterface::Execute_Func1(Obj, Param1);
	}
	return ETbSame2Enum1::TS2E1_Value1;
}

void UTbSame2SameEnum2InterfaceBPAdapter::Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbSame2Enum1> Future = Func2Async(Param1, Param2);
		FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>* CompletionAction = new FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbSame2Enum1> UTbSame2SameEnum2InterfaceBPAdapter::Func2Async(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, Param2, this]()
		{
		return Func2(Param1, Param2);
	});
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceBPAdapter::Func2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSame2SameEnum2InterfaceBPInterface::Execute_Func2(Obj, Param1, Param2);
	}
	return ETbSame2Enum1::TS2E1_Value1;
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceBPAdapter::GetProp1() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSame2SameEnum2InterfaceBPInterface::Execute_GetProp1(Obj);
	}
	return ETbSame2Enum1::TS2E1_Value1;
}
void UTbSame2SameEnum2InterfaceBPAdapter::SetProp1(ETbSame2Enum1 InProp1)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSame2SameEnum2InterfaceBPInterface::Execute_SetProp1(Obj, InProp1);
	}
}

ETbSame2Enum2 UTbSame2SameEnum2InterfaceBPAdapter::GetProp2() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSame2SameEnum2InterfaceBPInterface::Execute_GetProp2(Obj);
	}
	return ETbSame2Enum2::TS2E2_Value1;
}
void UTbSame2SameEnum2InterfaceBPAdapter::SetProp2(ETbSame2Enum2 InProp2)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSame2SameEnum2InterfaceBPInterface::Execute_SetProp2(Obj, InProp2);
	}
}
