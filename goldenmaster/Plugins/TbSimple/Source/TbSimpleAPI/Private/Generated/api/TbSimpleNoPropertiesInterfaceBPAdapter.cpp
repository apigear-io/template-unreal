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
#include "TbSimple/Generated/api/TbSimpleNoPropertiesInterfaceBPAdapter.h"
#include "TbSimpleNoPropertiesInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTbSimpleNoPropertiesInterfaceBPAdapter::Initialize(TScriptInterface<ITbSimpleNoPropertiesInterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTbSimpleNoPropertiesInterfacePublisher* UTbSimpleNoPropertiesInterfaceBPAdapter::_GetPublisher()
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleNoPropertiesInterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTbSimpleNoPropertiesInterfaceBPAdapter::FuncVoid()
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleNoPropertiesInterfaceBPInterface::Execute_FuncVoid(Obj);
	}
}

void UTbSimpleNoPropertiesInterfaceBPAdapter::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleNoPropertiesInterfaceLatentAction<bool>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleNoPropertiesInterfaceLatentAction<bool>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<bool> Future = FuncBoolAsync(bParamBool);
		FTbSimpleNoPropertiesInterfaceLatentAction<bool>* CompletionAction = new FTbSimpleNoPropertiesInterfaceLatentAction<bool>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<bool> UTbSimpleNoPropertiesInterfaceBPAdapter::FuncBoolAsync(bool bParamBool)
{
	return Async(EAsyncExecution::ThreadPool,
		[bParamBool, this]()
		{
		return FuncBool(bParamBool);
	});
}

bool UTbSimpleNoPropertiesInterfaceBPAdapter::FuncBool(bool bParamBool)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleNoPropertiesInterfaceBPInterface::Execute_FuncBool(Obj, bParamBool);
	}
	return false;
}
