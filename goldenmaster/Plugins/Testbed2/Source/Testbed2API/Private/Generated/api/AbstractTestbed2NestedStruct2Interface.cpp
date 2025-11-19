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
#include "Testbed2/Generated/api/AbstractTestbed2NestedStruct2Interface.h"
#include "Testbed2NestedStruct2InterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

UAbstractTestbed2NestedStruct2Interface::UAbstractTestbed2NestedStruct2Interface()
{
	Testbed2NestedStruct2InterfacePublisher = NewObject<UTestbed2NestedStruct2InterfacePublisher>();
}

UTestbed2NestedStruct2InterfacePublisher* UAbstractTestbed2NestedStruct2Interface::_GetPublisher()
{
	if (!Testbed2NestedStruct2InterfacePublisher)
	{
		Testbed2NestedStruct2InterfacePublisher = NewObject<UTestbed2NestedStruct2InterfacePublisher>();
	}
	return Testbed2NestedStruct2InterfacePublisher;
}

FTestbed2NestedStruct1 UAbstractTestbed2NestedStruct2Interface::GetProp1_Private() const
{
	return GetProp1();
};

void UAbstractTestbed2NestedStruct2Interface::SetProp1_Private(const FTestbed2NestedStruct1& InProp1)
{
	SetProp1(InProp1);
};

FTestbed2NestedStruct2 UAbstractTestbed2NestedStruct2Interface::GetProp2_Private() const
{
	return GetProp2();
};

void UAbstractTestbed2NestedStruct2Interface::SetProp2_Private(const FTestbed2NestedStruct2& InProp2)
{
	SetProp2(InProp2);
};

void UAbstractTestbed2NestedStruct2Interface::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed2NestedStruct1> Future = Func1Async(Param1);
		FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>* CompletionAction = new FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed2NestedStruct1> UAbstractTestbed2NestedStruct2Interface::Func1Async(const FTestbed2NestedStruct1& Param1)
{
	TWeakObjectPtr<UAbstractTestbed2NestedStruct2Interface> WeakThis(this);
	return Async(EAsyncExecution::ThreadPool,
		[Param1, WeakThis]()
		{
		if (auto StrongThis = WeakThis.Get())
		{
			return StrongThis->Func1(Param1);
		}
		return FTestbed2NestedStruct1();
	});
}

void UAbstractTestbed2NestedStruct2Interface::Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed2NestedStruct1> Future = Func2Async(Param1, Param2);
		FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>* CompletionAction = new FTestbed2NestedStruct2InterfaceLatentAction<FTestbed2NestedStruct1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed2NestedStruct1> UAbstractTestbed2NestedStruct2Interface::Func2Async(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	TWeakObjectPtr<UAbstractTestbed2NestedStruct2Interface> WeakThis(this);
	return Async(EAsyncExecution::ThreadPool,
		[Param1, Param2, WeakThis]()
		{
		if (auto StrongThis = WeakThis.Get())
		{
			return StrongThis->Func2(Param1, Param2);
		}
		return FTestbed2NestedStruct1();
	});
}

void UAbstractTestbed2NestedStruct2Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed2NestedStruct2Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (Testbed2NestedStruct2InterfacePublisher)
	{
		Testbed2NestedStruct2InterfacePublisher->OnSig1Signal.RemoveAll(Testbed2NestedStruct2InterfacePublisher);
		Testbed2NestedStruct2InterfacePublisher->OnSig1SignalBP.RemoveAll(Testbed2NestedStruct2InterfacePublisher);
		Testbed2NestedStruct2InterfacePublisher->OnSig2Signal.RemoveAll(Testbed2NestedStruct2InterfacePublisher);
		Testbed2NestedStruct2InterfacePublisher->OnSig2SignalBP.RemoveAll(Testbed2NestedStruct2InterfacePublisher);

		Testbed2NestedStruct2InterfacePublisher->OnProp1Changed.RemoveAll(Testbed2NestedStruct2InterfacePublisher);
		Testbed2NestedStruct2InterfacePublisher->OnProp1ChangedBP.RemoveAll(Testbed2NestedStruct2InterfacePublisher);
		Testbed2NestedStruct2InterfacePublisher->OnProp2Changed.RemoveAll(Testbed2NestedStruct2InterfacePublisher);
		Testbed2NestedStruct2InterfacePublisher->OnProp2ChangedBP.RemoveAll(Testbed2NestedStruct2InterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTestbed2NestedStruct2Interface::IsInitialized() const
{
	return bInitialized;
}
