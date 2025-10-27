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
#include "TbSame1/Generated/api/TbSame1SameEnum1InterfaceBPAdapter.h"
#include "TbSame1SameEnum1InterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTbSame1SameEnum1InterfaceBPAdapter::Initialize(TScriptInterface<ITbSame1SameEnum1InterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTbSame1SameEnum1InterfacePublisher* UTbSame1SameEnum1InterfaceBPAdapter::_GetPublisher()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbSame1SameEnum1InterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTbSame1SameEnum1InterfaceBPAdapter::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameEnum1InterfaceLatentAction<ETbSame1Enum1>* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameEnum1InterfaceLatentAction<ETbSame1Enum1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbSame1Enum1> Future = Func1Async(Param1);
		FTbSame1SameEnum1InterfaceLatentAction<ETbSame1Enum1>* CompletionAction = new FTbSame1SameEnum1InterfaceLatentAction<ETbSame1Enum1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbSame1Enum1> UTbSame1SameEnum1InterfaceBPAdapter::Func1Async(ETbSame1Enum1 Param1)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, this]()
		{
		return Func1(Param1);
	});
}

ETbSame1Enum1 UTbSame1SameEnum1InterfaceBPAdapter::Func1(ETbSame1Enum1 Param1)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbSame1SameEnum1InterfaceBPInterface::Execute_Func1(Obj, Param1);
	}
	return ETbSame1Enum1::TS1E1_Value1;
}

ETbSame1Enum1 UTbSame1SameEnum1InterfaceBPAdapter::GetProp1() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbSame1SameEnum1InterfaceBPInterface::Execute_GetProp1(Obj);
	}
	return ETbSame1Enum1::TS1E1_Value1;
}
void UTbSame1SameEnum1InterfaceBPAdapter::SetProp1(ETbSame1Enum1 InProp1)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbSame1SameEnum1InterfaceBPInterface::Execute_SetProp1(Obj, InProp1);
	}
}
