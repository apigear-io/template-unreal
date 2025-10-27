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
#include "Testbed2/Generated/api/AbstractTestbed2NestedStruct1Interface.h"
#include "Testbed2NestedStruct1InterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

UAbstractTestbed2NestedStruct1Interface::UAbstractTestbed2NestedStruct1Interface()
{
	Testbed2NestedStruct1InterfacePublisher = NewObject<UTestbed2NestedStruct1InterfacePublisher>();
}

UTestbed2NestedStruct1InterfacePublisher* UAbstractTestbed2NestedStruct1Interface::_GetPublisher()
{
	if (!Testbed2NestedStruct1InterfacePublisher)
	{
		Testbed2NestedStruct1InterfacePublisher = NewObject<UTestbed2NestedStruct1InterfacePublisher>();
	}
	return Testbed2NestedStruct1InterfacePublisher;
}

FTestbed2NestedStruct1 UAbstractTestbed2NestedStruct1Interface::GetProp1_Private() const
{
	return GetProp1();
};

void UAbstractTestbed2NestedStruct1Interface::SetProp1_Private(const FTestbed2NestedStruct1& InProp1)
{
	SetProp1(InProp1);
};

void UAbstractTestbed2NestedStruct1Interface::FuncNoParamsAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed2NestedStruct1> Future = FuncNoParamsAsync();
		FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>* CompletionAction = new FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed2NestedStruct1> UAbstractTestbed2NestedStruct1Interface::FuncNoParamsAsync()
{
	return Async(EAsyncExecution::ThreadPool,
		[this]()
		{
		return FuncNoParams();
	});
}

void UAbstractTestbed2NestedStruct1Interface::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed2NestedStruct1> Future = Func1Async(Param1);
		FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>* CompletionAction = new FTestbed2NestedStruct1InterfaceLatentAction<FTestbed2NestedStruct1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed2NestedStruct1> UAbstractTestbed2NestedStruct1Interface::Func1Async(const FTestbed2NestedStruct1& Param1)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, this]()
		{
		return Func1(Param1);
	});
}

void UAbstractTestbed2NestedStruct1Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed2NestedStruct1Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (Testbed2NestedStruct1InterfacePublisher)
	{
		Testbed2NestedStruct1InterfacePublisher->OnSig1Signal.RemoveAll(Testbed2NestedStruct1InterfacePublisher);
		Testbed2NestedStruct1InterfacePublisher->OnSig1SignalBP.RemoveAll(Testbed2NestedStruct1InterfacePublisher);

		Testbed2NestedStruct1InterfacePublisher->OnProp1Changed.RemoveAll(Testbed2NestedStruct1InterfacePublisher);
		Testbed2NestedStruct1InterfacePublisher->OnProp1ChangedBP.RemoveAll(Testbed2NestedStruct1InterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTestbed2NestedStruct1Interface::IsInitialized() const
{
	return bInitialized;
}
