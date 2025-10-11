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
#include "TbSimple/Generated/api/TbSimpleNoSignalsInterfaceBPAdapter.h"
#include "TbSimpleNoSignalsInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTbSimpleNoSignalsInterfaceBPAdapter::Initialize(TScriptInterface<ITbSimpleNoSignalsInterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTbSimpleNoSignalsInterfacePublisher* UTbSimpleNoSignalsInterfaceBPAdapter::_GetPublisher()
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleNoSignalsInterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTbSimpleNoSignalsInterfaceBPAdapter::FuncVoid()
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleNoSignalsInterfaceBPInterface::Execute_FuncVoid(Obj);
	}
}

void UTbSimpleNoSignalsInterfaceBPAdapter::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleNoSignalsInterfaceLatentAction<bool>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleNoSignalsInterfaceLatentAction<bool>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<bool> Future = FuncBoolAsync(bParamBool);
		FTbSimpleNoSignalsInterfaceLatentAction<bool>* CompletionAction = new FTbSimpleNoSignalsInterfaceLatentAction<bool>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<bool> UTbSimpleNoSignalsInterfaceBPAdapter::FuncBoolAsync(bool bParamBool)
{
	return Async(EAsyncExecution::ThreadPool,
		[bParamBool, this]()
		{
		return FuncBool(bParamBool);
	});
}

bool UTbSimpleNoSignalsInterfaceBPAdapter::FuncBool(bool bParamBool)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleNoSignalsInterfaceBPInterface::Execute_FuncBool(Obj, bParamBool);
	}
	return false;
}

bool UTbSimpleNoSignalsInterfaceBPAdapter::GetPropBool() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleNoSignalsInterfaceBPInterface::Execute_GetPropBool(Obj);
	}
	return false;
}
void UTbSimpleNoSignalsInterfaceBPAdapter::SetPropBool(bool bInPropBool)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleNoSignalsInterfaceBPInterface::Execute_SetPropBool(Obj, bInPropBool);
	}
}

int32 UTbSimpleNoSignalsInterfaceBPAdapter::GetPropInt() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleNoSignalsInterfaceBPInterface::Execute_GetPropInt(Obj);
	}
	return 0;
}
void UTbSimpleNoSignalsInterfaceBPAdapter::SetPropInt(int32 InPropInt)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleNoSignalsInterfaceBPInterface::Execute_SetPropInt(Obj, InPropInt);
	}
}
