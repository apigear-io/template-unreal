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
#include "TbStructArray/Generated/api/TbStructArrayStructArrayFieldInterfaceBPAdapter.h"
#include "TbStructArrayStructArrayFieldInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTbStructArrayStructArrayFieldInterfaceBPAdapter::Initialize(TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPInterface> InTarget)
{
	ensureMsgf(InTarget.GetObject() == nullptr || InTarget.GetObject()->Implements<UTbStructArrayStructArrayFieldInterfaceBPInterface>(),
		TEXT("UTbStructArrayStructArrayFieldInterfaceBPAdapter::Initialize: InTarget does not implement ITbStructArrayStructArrayFieldInterfaceBPInterface. All BP calls will be silently skipped."));
	Target = InTarget;
}

UTbStructArrayStructArrayFieldInterfacePublisher* UTbStructArrayStructArrayFieldInterfaceBPAdapter::_GetPublisher()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbStructArrayStructArrayFieldInterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTbStructArrayStructArrayFieldInterfaceBPAdapter::FuncMixedAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbStructArrayMixedStruct& Result, const FTbStructArrayMixedStruct& ParamMixed)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbStructArrayStructArrayFieldInterfaceLatentAction<FTbStructArrayMixedStruct>* oldRequest = LatentActionManager.FindExistingAction<FTbStructArrayStructArrayFieldInterfaceLatentAction<FTbStructArrayMixedStruct>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			oldRequest->Cancel();
		}

		TFuture<FTbStructArrayMixedStruct> Future = FuncMixedAsync(ParamMixed);
		FTbStructArrayStructArrayFieldInterfaceLatentAction<FTbStructArrayMixedStruct>* CompletionAction = new FTbStructArrayStructArrayFieldInterfaceLatentAction<FTbStructArrayMixedStruct>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTbStructArrayMixedStruct> UTbStructArrayStructArrayFieldInterfaceBPAdapter::FuncMixedAsync(const FTbStructArrayMixedStruct& ParamMixed)
{
	TWeakObjectPtr<UTbStructArrayStructArrayFieldInterfaceBPAdapter> WeakThis(this);
	return Async(EAsyncExecution::TaskGraphMainThread,
		[ParamMixed, WeakThis]()
		{
		if (UTbStructArrayStructArrayFieldInterfaceBPAdapter* StrongThis = WeakThis.Get())
		{
			return StrongThis->FuncMixed(ParamMixed);
		}
		return FTbStructArrayMixedStruct();
	});
}

FTbStructArrayMixedStruct UTbStructArrayStructArrayFieldInterfaceBPAdapter::FuncMixed(const FTbStructArrayMixedStruct& ParamMixed)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbStructArrayStructArrayFieldInterfaceBPInterface::Execute_FuncMixed(Obj, ParamMixed);
	}
	return FTbStructArrayMixedStruct();
}

void UTbStructArrayStructArrayFieldInterfaceBPAdapter::FuncStructArrayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbStructArrayStructWithArrayOfStructs& Result, const FTbStructArrayStructWithArrayOfStructs& ParamPoints)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbStructArrayStructArrayFieldInterfaceLatentAction<FTbStructArrayStructWithArrayOfStructs>* oldRequest = LatentActionManager.FindExistingAction<FTbStructArrayStructArrayFieldInterfaceLatentAction<FTbStructArrayStructWithArrayOfStructs>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			oldRequest->Cancel();
		}

		TFuture<FTbStructArrayStructWithArrayOfStructs> Future = FuncStructArrayAsync(ParamPoints);
		FTbStructArrayStructArrayFieldInterfaceLatentAction<FTbStructArrayStructWithArrayOfStructs>* CompletionAction = new FTbStructArrayStructArrayFieldInterfaceLatentAction<FTbStructArrayStructWithArrayOfStructs>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTbStructArrayStructWithArrayOfStructs> UTbStructArrayStructArrayFieldInterfaceBPAdapter::FuncStructArrayAsync(const FTbStructArrayStructWithArrayOfStructs& ParamPoints)
{
	TWeakObjectPtr<UTbStructArrayStructArrayFieldInterfaceBPAdapter> WeakThis(this);
	return Async(EAsyncExecution::TaskGraphMainThread,
		[ParamPoints, WeakThis]()
		{
		if (UTbStructArrayStructArrayFieldInterfaceBPAdapter* StrongThis = WeakThis.Get())
		{
			return StrongThis->FuncStructArray(ParamPoints);
		}
		return FTbStructArrayStructWithArrayOfStructs();
	});
}

FTbStructArrayStructWithArrayOfStructs UTbStructArrayStructArrayFieldInterfaceBPAdapter::FuncStructArray(const FTbStructArrayStructWithArrayOfStructs& ParamPoints)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbStructArrayStructArrayFieldInterfaceBPInterface::Execute_FuncStructArray(Obj, ParamPoints);
	}
	return FTbStructArrayStructWithArrayOfStructs();
}

FTbStructArrayStructWithArrayOfStructs UTbStructArrayStructArrayFieldInterfaceBPAdapter::GetPropStructArray() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbStructArrayStructArrayFieldInterfaceBPInterface::Execute_GetPropStructArray(Obj);
	}
	return FTbStructArrayStructWithArrayOfStructs();
}
void UTbStructArrayStructArrayFieldInterfaceBPAdapter::SetPropStructArray(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbStructArrayStructArrayFieldInterfaceBPInterface::Execute_SetPropStructArray(Obj, InPropStructArray);
	}
}

FTbStructArrayStructWithArrayOfEnums UTbStructArrayStructArrayFieldInterfaceBPAdapter::GetPropEnumArray() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbStructArrayStructArrayFieldInterfaceBPInterface::Execute_GetPropEnumArray(Obj);
	}
	return FTbStructArrayStructWithArrayOfEnums();
}
void UTbStructArrayStructArrayFieldInterfaceBPAdapter::SetPropEnumArray(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbStructArrayStructArrayFieldInterfaceBPInterface::Execute_SetPropEnumArray(Obj, InPropEnumArray);
	}
}

FTbStructArrayStructWithArrayOfInts UTbStructArrayStructArrayFieldInterfaceBPAdapter::GetPropIntArray() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbStructArrayStructArrayFieldInterfaceBPInterface::Execute_GetPropIntArray(Obj);
	}
	return FTbStructArrayStructWithArrayOfInts();
}
void UTbStructArrayStructArrayFieldInterfaceBPAdapter::SetPropIntArray(const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbStructArrayStructArrayFieldInterfaceBPInterface::Execute_SetPropIntArray(Obj, InPropIntArray);
	}
}

FTbStructArrayMixedStruct UTbStructArrayStructArrayFieldInterfaceBPAdapter::GetPropMixed() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbStructArrayStructArrayFieldInterfaceBPInterface::Execute_GetPropMixed(Obj);
	}
	return FTbStructArrayMixedStruct();
}
void UTbStructArrayStructArrayFieldInterfaceBPAdapter::SetPropMixed(const FTbStructArrayMixedStruct& InPropMixed)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbStructArrayStructArrayFieldInterfaceBPInterface::Execute_SetPropMixed(Obj, InPropMixed);
	}
}
