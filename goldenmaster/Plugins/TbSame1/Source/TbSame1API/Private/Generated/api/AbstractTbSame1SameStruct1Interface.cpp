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
#include "TbSame1/Generated/api/AbstractTbSame1SameStruct1Interface.h"
#include "TbSame1SameStruct1InterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

UAbstractTbSame1SameStruct1Interface::UAbstractTbSame1SameStruct1Interface()
{
	TbSame1SameStruct1InterfacePublisher = NewObject<UTbSame1SameStruct1InterfacePublisher>();
}

UTbSame1SameStruct1InterfacePublisher* UAbstractTbSame1SameStruct1Interface::_GetPublisher()
{
	if (!TbSame1SameStruct1InterfacePublisher)
	{
		TbSame1SameStruct1InterfacePublisher = NewObject<UTbSame1SameStruct1InterfacePublisher>();
	}
	return TbSame1SameStruct1InterfacePublisher;
}

FTbSame1Struct1 UAbstractTbSame1SameStruct1Interface::GetProp1_Private() const
{
	return GetProp1();
};

void UAbstractTbSame1SameStruct1Interface::SetProp1_Private(const FTbSame1Struct1& InProp1)
{
	SetProp1(InProp1);
};

void UAbstractTbSame1SameStruct1Interface::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameStruct1InterfaceLatentAction<FTbSame1Struct1>* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameStruct1InterfaceLatentAction<FTbSame1Struct1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTbSame1Struct1> Future = Func1Async(Param1);
		FTbSame1SameStruct1InterfaceLatentAction<FTbSame1Struct1>* CompletionAction = new FTbSame1SameStruct1InterfaceLatentAction<FTbSame1Struct1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTbSame1Struct1> UAbstractTbSame1SameStruct1Interface::Func1Async(const FTbSame1Struct1& Param1)
{
	TWeakObjectPtr<UAbstractTbSame1SameStruct1Interface> WeakThis(this);
	return Async(EAsyncExecution::ThreadPool,
		[Param1, WeakThis]()
		{
		if (auto StrongThis = WeakThis.Get())
		{
			return StrongThis->Func1(Param1);
		}
		return FTbSame1Struct1();
	});
}

void UAbstractTbSame1SameStruct1Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSame1SameStruct1Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSame1SameStruct1InterfacePublisher)
	{
		TbSame1SameStruct1InterfacePublisher->OnSig1Signal.RemoveAll(TbSame1SameStruct1InterfacePublisher);
		TbSame1SameStruct1InterfacePublisher->OnSig1SignalBP.RemoveAll(TbSame1SameStruct1InterfacePublisher);

		TbSame1SameStruct1InterfacePublisher->OnProp1Changed.RemoveAll(TbSame1SameStruct1InterfacePublisher);
		TbSame1SameStruct1InterfacePublisher->OnProp1ChangedBP.RemoveAll(TbSame1SameStruct1InterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbSame1SameStruct1Interface::IsInitialized() const
{
	return bInitialized;
}
