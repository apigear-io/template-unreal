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
#include "TbSame2/Generated/api/AbstractTbSame2SameStruct2Interface.h"
#include "TbSame2SameStruct2InterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

UAbstractTbSame2SameStruct2Interface::UAbstractTbSame2SameStruct2Interface()
{
	TbSame2SameStruct2InterfacePublisher = NewObject<UTbSame2SameStruct2InterfacePublisher>();
}

UTbSame2SameStruct2InterfacePublisher* UAbstractTbSame2SameStruct2Interface::_GetPublisher()
{
	if (!TbSame2SameStruct2InterfacePublisher)
	{
		TbSame2SameStruct2InterfacePublisher = NewObject<UTbSame2SameStruct2InterfacePublisher>();
	}
	return TbSame2SameStruct2InterfacePublisher;
}

FTbSame2Struct2 UAbstractTbSame2SameStruct2Interface::GetProp1_Private() const
{
	return GetProp1();
};

void UAbstractTbSame2SameStruct2Interface::SetProp1_Private(const FTbSame2Struct2& InProp1)
{
	SetProp1(InProp1);
};

FTbSame2Struct2 UAbstractTbSame2SameStruct2Interface::GetProp2_Private() const
{
	return GetProp2();
};

void UAbstractTbSame2SameStruct2Interface::SetProp2_Private(const FTbSame2Struct2& InProp2)
{
	SetProp2(InProp2);
};

void UAbstractTbSame2SameStruct2Interface::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTbSame2Struct1> Future = Func1Async(Param1);
		FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>* CompletionAction = new FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTbSame2Struct1> UAbstractTbSame2SameStruct2Interface::Func1Async(const FTbSame2Struct1& Param1)
{
	TWeakObjectPtr<UAbstractTbSame2SameStruct2Interface> WeakThis(this);
	return Async(EAsyncExecution::ThreadPool,
		[Param1, WeakThis]()
		{
		if (auto StrongThis = WeakThis.Get())
		{
			return StrongThis->Func1(Param1);
		}
		return FTbSame2Struct1();
	});
}

void UAbstractTbSame2SameStruct2Interface::Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTbSame2Struct1> Future = Func2Async(Param1, Param2);
		FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>* CompletionAction = new FTbSame2SameStruct2InterfaceLatentAction<FTbSame2Struct1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTbSame2Struct1> UAbstractTbSame2SameStruct2Interface::Func2Async(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	TWeakObjectPtr<UAbstractTbSame2SameStruct2Interface> WeakThis(this);
	return Async(EAsyncExecution::ThreadPool,
		[Param1, Param2, WeakThis]()
		{
		if (auto StrongThis = WeakThis.Get())
		{
			return StrongThis->Func2(Param1, Param2);
		}
		return FTbSame2Struct1();
	});
}

void UAbstractTbSame2SameStruct2Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSame2SameStruct2Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSame2SameStruct2InterfacePublisher)
	{
		TbSame2SameStruct2InterfacePublisher->OnSig1Signal.RemoveAll(TbSame2SameStruct2InterfacePublisher);
		TbSame2SameStruct2InterfacePublisher->OnSig1SignalBP.RemoveAll(TbSame2SameStruct2InterfacePublisher);
		TbSame2SameStruct2InterfacePublisher->OnSig2Signal.RemoveAll(TbSame2SameStruct2InterfacePublisher);
		TbSame2SameStruct2InterfacePublisher->OnSig2SignalBP.RemoveAll(TbSame2SameStruct2InterfacePublisher);

		TbSame2SameStruct2InterfacePublisher->OnProp1Changed.RemoveAll(TbSame2SameStruct2InterfacePublisher);
		TbSame2SameStruct2InterfacePublisher->OnProp1ChangedBP.RemoveAll(TbSame2SameStruct2InterfacePublisher);
		TbSame2SameStruct2InterfacePublisher->OnProp2Changed.RemoveAll(TbSame2SameStruct2InterfacePublisher);
		TbSame2SameStruct2InterfacePublisher->OnProp2ChangedBP.RemoveAll(TbSame2SameStruct2InterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbSame2SameStruct2Interface::IsInitialized() const
{
	return bInitialized;
}
