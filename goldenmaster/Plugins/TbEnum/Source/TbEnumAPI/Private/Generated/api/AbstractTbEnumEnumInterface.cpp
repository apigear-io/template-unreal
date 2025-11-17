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
#include "TbEnum/Generated/api/AbstractTbEnumEnumInterface.h"
#include "TbEnumEnumInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

UAbstractTbEnumEnumInterface::UAbstractTbEnumEnumInterface()
{
	TbEnumEnumInterfacePublisher = NewObject<UTbEnumEnumInterfacePublisher>();
}

UTbEnumEnumInterfacePublisher* UAbstractTbEnumEnumInterface::_GetPublisher()
{
	if (!TbEnumEnumInterfacePublisher)
	{
		TbEnumEnumInterfacePublisher = NewObject<UTbEnumEnumInterfacePublisher>();
	}
	return TbEnumEnumInterfacePublisher;
}

ETbEnumEnum0 UAbstractTbEnumEnumInterface::GetProp0_Private() const
{
	return GetProp0();
};

void UAbstractTbEnumEnumInterface::SetProp0_Private(ETbEnumEnum0 InProp0)
{
	SetProp0(InProp0);
};

ETbEnumEnum1 UAbstractTbEnumEnumInterface::GetProp1_Private() const
{
	return GetProp1();
};

void UAbstractTbEnumEnumInterface::SetProp1_Private(ETbEnumEnum1 InProp1)
{
	SetProp1(InProp1);
};

ETbEnumEnum2 UAbstractTbEnumEnumInterface::GetProp2_Private() const
{
	return GetProp2();
};

void UAbstractTbEnumEnumInterface::SetProp2_Private(ETbEnumEnum2 InProp2)
{
	SetProp2(InProp2);
};

ETbEnumEnum3 UAbstractTbEnumEnumInterface::GetProp3_Private() const
{
	return GetProp3();
};

void UAbstractTbEnumEnumInterface::SetProp3_Private(ETbEnumEnum3 InProp3)
{
	SetProp3(InProp3);
};

void UAbstractTbEnumEnumInterface::Func0Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum0>* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction<ETbEnumEnum0>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbEnumEnum0> Future = Func0Async(Param0);
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum0>* CompletionAction = new FTbEnumEnumInterfaceLatentAction<ETbEnumEnum0>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbEnumEnum0> UAbstractTbEnumEnumInterface::Func0Async(ETbEnumEnum0 Param0)
{
	TWeakObjectPtr<UAbstractTbEnumEnumInterface> WeakThis(this);
	return Async(EAsyncExecution::ThreadPool,
		[Param0, WeakThis]()
		{
		if (auto StrongThis = WeakThis.Get())
		{
			return StrongThis->Func0(Param0);
		}
		return ETbEnumEnum0::TEE0_Value0;
	});
}

void UAbstractTbEnumEnumInterface::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum1>* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction<ETbEnumEnum1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbEnumEnum1> Future = Func1Async(Param1);
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum1>* CompletionAction = new FTbEnumEnumInterfaceLatentAction<ETbEnumEnum1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbEnumEnum1> UAbstractTbEnumEnumInterface::Func1Async(ETbEnumEnum1 Param1)
{
	TWeakObjectPtr<UAbstractTbEnumEnumInterface> WeakThis(this);
	return Async(EAsyncExecution::ThreadPool,
		[Param1, WeakThis]()
		{
		if (auto StrongThis = WeakThis.Get())
		{
			return StrongThis->Func1(Param1);
		}
		return ETbEnumEnum1::TEE1_Value1;
	});
}

void UAbstractTbEnumEnumInterface::Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum2>* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction<ETbEnumEnum2>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbEnumEnum2> Future = Func2Async(Param2);
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum2>* CompletionAction = new FTbEnumEnumInterfaceLatentAction<ETbEnumEnum2>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbEnumEnum2> UAbstractTbEnumEnumInterface::Func2Async(ETbEnumEnum2 Param2)
{
	TWeakObjectPtr<UAbstractTbEnumEnumInterface> WeakThis(this);
	return Async(EAsyncExecution::ThreadPool,
		[Param2, WeakThis]()
		{
		if (auto StrongThis = WeakThis.Get())
		{
			return StrongThis->Func2(Param2);
		}
		return ETbEnumEnum2::TEE2_Value2;
	});
}

void UAbstractTbEnumEnumInterface::Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum3>* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction<ETbEnumEnum3>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbEnumEnum3> Future = Func3Async(Param3);
		FTbEnumEnumInterfaceLatentAction<ETbEnumEnum3>* CompletionAction = new FTbEnumEnumInterfaceLatentAction<ETbEnumEnum3>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbEnumEnum3> UAbstractTbEnumEnumInterface::Func3Async(ETbEnumEnum3 Param3)
{
	TWeakObjectPtr<UAbstractTbEnumEnumInterface> WeakThis(this);
	return Async(EAsyncExecution::ThreadPool,
		[Param3, WeakThis]()
		{
		if (auto StrongThis = WeakThis.Get())
		{
			return StrongThis->Func3(Param3);
		}
		return ETbEnumEnum3::TEE3_Value3;
	});
}

void UAbstractTbEnumEnumInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbEnumEnumInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbEnumEnumInterfacePublisher)
	{
		TbEnumEnumInterfacePublisher->OnSig0Signal.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnSig0SignalBP.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnSig1Signal.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnSig1SignalBP.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnSig2Signal.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnSig2SignalBP.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnSig3Signal.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnSig3SignalBP.RemoveAll(TbEnumEnumInterfacePublisher);

		TbEnumEnumInterfacePublisher->OnProp0Changed.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnProp0ChangedBP.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnProp1Changed.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnProp1ChangedBP.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnProp2Changed.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnProp2ChangedBP.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnProp3Changed.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnProp3ChangedBP.RemoveAll(TbEnumEnumInterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbEnumEnumInterface::IsInitialized() const
{
	return bInitialized;
}
