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
#include "TbSame2/Generated/api/TbSame2SameEnum1InterfaceBPAdapter.h"
#include "TbSame2SameEnum1InterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTbSame2SameEnum1InterfaceBPAdapter::Initialize(TScriptInterface<ITbSame2SameEnum1InterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTbSame2SameEnum1InterfacePublisher* UTbSame2SameEnum1InterfaceBPAdapter::_GetPublisher()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbSame2SameEnum1InterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTbSame2SameEnum1InterfaceBPAdapter::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameEnum1InterfaceLatentAction<ETbSame2Enum1>* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameEnum1InterfaceLatentAction<ETbSame2Enum1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbSame2Enum1> Future = Func1Async(Param1);
		FTbSame2SameEnum1InterfaceLatentAction<ETbSame2Enum1>* CompletionAction = new FTbSame2SameEnum1InterfaceLatentAction<ETbSame2Enum1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbSame2Enum1> UTbSame2SameEnum1InterfaceBPAdapter::Func1Async(ETbSame2Enum1 Param1)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, this]()
		{
		return Func1(Param1);
	});
}

ETbSame2Enum1 UTbSame2SameEnum1InterfaceBPAdapter::Func1(ETbSame2Enum1 Param1)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbSame2SameEnum1InterfaceBPInterface::Execute_Func1(Obj, Param1);
	}
	return ETbSame2Enum1::TS2E1_Value1;
}

ETbSame2Enum1 UTbSame2SameEnum1InterfaceBPAdapter::GetProp1() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbSame2SameEnum1InterfaceBPInterface::Execute_GetProp1(Obj);
	}
	return ETbSame2Enum1::TS2E1_Value1;
}
void UTbSame2SameEnum1InterfaceBPAdapter::SetProp1(ETbSame2Enum1 InProp1)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbSame2SameEnum1InterfaceBPInterface::Execute_SetProp1(Obj, InProp1);
	}
}
