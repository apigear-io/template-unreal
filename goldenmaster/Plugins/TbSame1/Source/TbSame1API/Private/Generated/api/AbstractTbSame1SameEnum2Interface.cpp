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
#include "TbSame1/Generated/api/AbstractTbSame1SameEnum2Interface.h"
#include "TbSame1SameEnum2InterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

UAbstractTbSame1SameEnum2Interface::UAbstractTbSame1SameEnum2Interface()
{
	TbSame1SameEnum2InterfacePublisher = NewObject<UTbSame1SameEnum2InterfacePublisher>();
}

UTbSame1SameEnum2InterfacePublisher* UAbstractTbSame1SameEnum2Interface::_GetPublisher()
{
	if (!TbSame1SameEnum2InterfacePublisher)
	{
		TbSame1SameEnum2InterfacePublisher = NewObject<UTbSame1SameEnum2InterfacePublisher>();
	}
	return TbSame1SameEnum2InterfacePublisher;
}

ETbSame1Enum1 UAbstractTbSame1SameEnum2Interface::GetProp1_Private() const
{
	return GetProp1();
};

void UAbstractTbSame1SameEnum2Interface::SetProp1_Private(ETbSame1Enum1 InProp1)
{
	SetProp1(InProp1);
};

ETbSame1Enum2 UAbstractTbSame1SameEnum2Interface::GetProp2_Private() const
{
	return GetProp2();
};

void UAbstractTbSame1SameEnum2Interface::SetProp2_Private(ETbSame1Enum2 InProp2)
{
	SetProp2(InProp2);
};

void UAbstractTbSame1SameEnum2Interface::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameEnum2InterfaceLatentAction<ETbSame1Enum1>* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameEnum2InterfaceLatentAction<ETbSame1Enum1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbSame1Enum1> Future = Func1Async(Param1);
		FTbSame1SameEnum2InterfaceLatentAction<ETbSame1Enum1>* CompletionAction = new FTbSame1SameEnum2InterfaceLatentAction<ETbSame1Enum1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbSame1Enum1> UAbstractTbSame1SameEnum2Interface::Func1Async(ETbSame1Enum1 Param1)
{
	TWeakObjectPtr<UAbstractTbSame1SameEnum2Interface> WeakThis(this);
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

void UAbstractTbSame1SameEnum2Interface::Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameEnum2InterfaceLatentAction<ETbSame1Enum1>* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameEnum2InterfaceLatentAction<ETbSame1Enum1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbSame1Enum1> Future = Func2Async(Param1, Param2);
		FTbSame1SameEnum2InterfaceLatentAction<ETbSame1Enum1>* CompletionAction = new FTbSame1SameEnum2InterfaceLatentAction<ETbSame1Enum1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbSame1Enum1> UAbstractTbSame1SameEnum2Interface::Func2Async(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	TWeakObjectPtr<UAbstractTbSame1SameEnum2Interface> WeakThis(this);
	return Async(EAsyncExecution::ThreadPool,
		[Param1, Param2, WeakThis]()
		{
		if (auto StrongThis = WeakThis.Get())
		{
			return StrongThis->Func2(Param1, Param2);
		}
		return ETbSame1Enum1::TS1E1_Value1;
	});
}

void UAbstractTbSame1SameEnum2Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSame1SameEnum2Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSame1SameEnum2InterfacePublisher)
	{
		TbSame1SameEnum2InterfacePublisher->OnSig1Signal.RemoveAll(TbSame1SameEnum2InterfacePublisher);
		TbSame1SameEnum2InterfacePublisher->OnSig1SignalBP.RemoveAll(TbSame1SameEnum2InterfacePublisher);
		TbSame1SameEnum2InterfacePublisher->OnSig2Signal.RemoveAll(TbSame1SameEnum2InterfacePublisher);
		TbSame1SameEnum2InterfacePublisher->OnSig2SignalBP.RemoveAll(TbSame1SameEnum2InterfacePublisher);

		TbSame1SameEnum2InterfacePublisher->OnProp1Changed.RemoveAll(TbSame1SameEnum2InterfacePublisher);
		TbSame1SameEnum2InterfacePublisher->OnProp1ChangedBP.RemoveAll(TbSame1SameEnum2InterfacePublisher);
		TbSame1SameEnum2InterfacePublisher->OnProp2Changed.RemoveAll(TbSame1SameEnum2InterfacePublisher);
		TbSame1SameEnum2InterfacePublisher->OnProp2ChangedBP.RemoveAll(TbSame1SameEnum2InterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbSame1SameEnum2Interface::IsInitialized() const
{
	return bInitialized;
}
