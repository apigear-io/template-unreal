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
#include "TbSimple/Generated/api/AbstractTbSimpleNoSignalsInterface.h"
#include "TbSimpleNoSignalsInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

UAbstractTbSimpleNoSignalsInterface::UAbstractTbSimpleNoSignalsInterface()
{
	TbSimpleNoSignalsInterfacePublisher = NewObject<UTbSimpleNoSignalsInterfacePublisher>();
}

UTbSimpleNoSignalsInterfacePublisher* UAbstractTbSimpleNoSignalsInterface::_GetPublisher()
{
	if (!TbSimpleNoSignalsInterfacePublisher)
	{
		TbSimpleNoSignalsInterfacePublisher = NewObject<UTbSimpleNoSignalsInterfacePublisher>();
	}
	return TbSimpleNoSignalsInterfacePublisher;
}

bool UAbstractTbSimpleNoSignalsInterface::GetPropBool_Private() const
{
	return GetPropBool();
};

void UAbstractTbSimpleNoSignalsInterface::SetPropBool_Private(bool bInPropBool)
{
	SetPropBool(bInPropBool);
};

int32 UAbstractTbSimpleNoSignalsInterface::GetPropInt_Private() const
{
	return GetPropInt();
};

void UAbstractTbSimpleNoSignalsInterface::SetPropInt_Private(int32 InPropInt)
{
	SetPropInt(InPropInt);
};

void UAbstractTbSimpleNoSignalsInterface::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
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

TFuture<bool> UAbstractTbSimpleNoSignalsInterface::FuncBoolAsync(bool bParamBool)
{
	TWeakObjectPtr<UAbstractTbSimpleNoSignalsInterface> WeakThis(this);
	return Async(EAsyncExecution::ThreadPool,
		[bParamBool, WeakThis]()
		{
		if (auto StrongThis = WeakThis.Get())
		{
			return StrongThis->FuncBool(bParamBool);
		}
		return false;
	});
}

void UAbstractTbSimpleNoSignalsInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSimpleNoSignalsInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSimpleNoSignalsInterfacePublisher)
	{
		TbSimpleNoSignalsInterfacePublisher->OnPropBoolChanged.RemoveAll(TbSimpleNoSignalsInterfacePublisher);
		TbSimpleNoSignalsInterfacePublisher->OnPropBoolChangedBP.RemoveAll(TbSimpleNoSignalsInterfacePublisher);
		TbSimpleNoSignalsInterfacePublisher->OnPropIntChanged.RemoveAll(TbSimpleNoSignalsInterfacePublisher);
		TbSimpleNoSignalsInterfacePublisher->OnPropIntChangedBP.RemoveAll(TbSimpleNoSignalsInterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbSimpleNoSignalsInterface::IsInitialized() const
{
	return bInitialized;
}
