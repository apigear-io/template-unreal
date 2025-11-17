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
#include "TbSame1/Generated/api/AbstractTbSame1SameEnum1Interface.h"
#include "TbSame1SameEnum1InterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

UAbstractTbSame1SameEnum1Interface::UAbstractTbSame1SameEnum1Interface()
{
	TbSame1SameEnum1InterfacePublisher = NewObject<UTbSame1SameEnum1InterfacePublisher>();
}

UTbSame1SameEnum1InterfacePublisher* UAbstractTbSame1SameEnum1Interface::_GetPublisher()
{
	if (!TbSame1SameEnum1InterfacePublisher)
	{
		TbSame1SameEnum1InterfacePublisher = NewObject<UTbSame1SameEnum1InterfacePublisher>();
	}
	return TbSame1SameEnum1InterfacePublisher;
}

ETbSame1Enum1 UAbstractTbSame1SameEnum1Interface::GetProp1_Private() const
{
	return GetProp1();
};

void UAbstractTbSame1SameEnum1Interface::SetProp1_Private(ETbSame1Enum1 InProp1)
{
	SetProp1(InProp1);
};

void UAbstractTbSame1SameEnum1Interface::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1)
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

TFuture<ETbSame1Enum1> UAbstractTbSame1SameEnum1Interface::Func1Async(ETbSame1Enum1 Param1)
{
	TWeakObjectPtr<UAbstractTbSame1SameEnum1Interface> WeakThis(this);
	return Async(EAsyncExecution::ThreadPool,
		[Param1, WeakThis]()
		{
		if (auto StrongThis = WeakThis.Get())
		{
			return StrongThis->Func1(Param1);
		}
		return ETbSame1Enum1::TS1E1_Value1;
	});
}

void UAbstractTbSame1SameEnum1Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSame1SameEnum1Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSame1SameEnum1InterfacePublisher)
	{
		TbSame1SameEnum1InterfacePublisher->OnSig1Signal.RemoveAll(TbSame1SameEnum1InterfacePublisher);
		TbSame1SameEnum1InterfacePublisher->OnSig1SignalBP.RemoveAll(TbSame1SameEnum1InterfacePublisher);

		TbSame1SameEnum1InterfacePublisher->OnProp1Changed.RemoveAll(TbSame1SameEnum1InterfacePublisher);
		TbSame1SameEnum1InterfacePublisher->OnProp1ChangedBP.RemoveAll(TbSame1SameEnum1InterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbSame1SameEnum1Interface::IsInitialized() const
{
	return bInitialized;
}
