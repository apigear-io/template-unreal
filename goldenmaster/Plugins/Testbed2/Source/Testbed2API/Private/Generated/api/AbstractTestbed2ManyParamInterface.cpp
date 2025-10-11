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
#include "Testbed2/Generated/api/AbstractTestbed2ManyParamInterface.h"
#include "Testbed2ManyParamInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

UAbstractTestbed2ManyParamInterface::UAbstractTestbed2ManyParamInterface()
{
	Testbed2ManyParamInterfacePublisher = NewObject<UTestbed2ManyParamInterfacePublisher>();
}

UTestbed2ManyParamInterfacePublisher* UAbstractTestbed2ManyParamInterface::_GetPublisher()
{
	if (!Testbed2ManyParamInterfacePublisher)
	{
		Testbed2ManyParamInterfacePublisher = NewObject<UTestbed2ManyParamInterfacePublisher>();
	}
	return Testbed2ManyParamInterfacePublisher;
}

int32 UAbstractTestbed2ManyParamInterface::GetProp1_Private() const
{
	return GetProp1();
};

void UAbstractTestbed2ManyParamInterface::SetProp1_Private(int32 InProp1)
{
	SetProp1(InProp1);
};

int32 UAbstractTestbed2ManyParamInterface::GetProp2_Private() const
{
	return GetProp2();
};

void UAbstractTestbed2ManyParamInterface::SetProp2_Private(int32 InProp2)
{
	SetProp2(InProp2);
};

int32 UAbstractTestbed2ManyParamInterface::GetProp3_Private() const
{
	return GetProp3();
};

void UAbstractTestbed2ManyParamInterface::SetProp3_Private(int32 InProp3)
{
	SetProp3(InProp3);
};

int32 UAbstractTestbed2ManyParamInterface::GetProp4_Private() const
{
	return GetProp4();
};

void UAbstractTestbed2ManyParamInterface::SetProp4_Private(int32 InProp4)
{
	SetProp4(InProp4);
};

void UAbstractTestbed2ManyParamInterface::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction<int32>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction<int32>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<int32> Future = Func1Async(Param1);
		FTestbed2ManyParamInterfaceLatentAction<int32>* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction<int32>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<int32> UAbstractTestbed2ManyParamInterface::Func1Async(int32 Param1)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, this]()
		{
		return Func1(Param1);
	});
}

void UAbstractTestbed2ManyParamInterface::Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction<int32>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction<int32>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<int32> Future = Func2Async(Param1, Param2);
		FTestbed2ManyParamInterfaceLatentAction<int32>* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction<int32>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<int32> UAbstractTestbed2ManyParamInterface::Func2Async(int32 Param1, int32 Param2)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, Param2, this]()
		{
		return Func2(Param1, Param2);
	});
}

void UAbstractTestbed2ManyParamInterface::Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction<int32>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction<int32>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<int32> Future = Func3Async(Param1, Param2, Param3);
		FTestbed2ManyParamInterfaceLatentAction<int32>* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction<int32>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<int32> UAbstractTestbed2ManyParamInterface::Func3Async(int32 Param1, int32 Param2, int32 Param3)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, Param2, Param3, this]()
		{
		return Func3(Param1, Param2, Param3);
	});
}

void UAbstractTestbed2ManyParamInterface::Func4Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction<int32>* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction<int32>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<int32> Future = Func4Async(Param1, Param2, Param3, Param4);
		FTestbed2ManyParamInterfaceLatentAction<int32>* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction<int32>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<int32> UAbstractTestbed2ManyParamInterface::Func4Async(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, Param2, Param3, Param4, this]()
		{
		return Func4(Param1, Param2, Param3, Param4);
	});
}

void UAbstractTestbed2ManyParamInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed2ManyParamInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (Testbed2ManyParamInterfacePublisher)
	{
		Testbed2ManyParamInterfacePublisher->OnSig1Signal.RemoveAll(Testbed2ManyParamInterfacePublisher);
		Testbed2ManyParamInterfacePublisher->OnSig1SignalBP.RemoveAll(Testbed2ManyParamInterfacePublisher);
		Testbed2ManyParamInterfacePublisher->OnSig2Signal.RemoveAll(Testbed2ManyParamInterfacePublisher);
		Testbed2ManyParamInterfacePublisher->OnSig2SignalBP.RemoveAll(Testbed2ManyParamInterfacePublisher);
		Testbed2ManyParamInterfacePublisher->OnSig3Signal.RemoveAll(Testbed2ManyParamInterfacePublisher);
		Testbed2ManyParamInterfacePublisher->OnSig3SignalBP.RemoveAll(Testbed2ManyParamInterfacePublisher);
		Testbed2ManyParamInterfacePublisher->OnSig4Signal.RemoveAll(Testbed2ManyParamInterfacePublisher);
		Testbed2ManyParamInterfacePublisher->OnSig4SignalBP.RemoveAll(Testbed2ManyParamInterfacePublisher);

		Testbed2ManyParamInterfacePublisher->OnProp1Changed.RemoveAll(Testbed2ManyParamInterfacePublisher);
		Testbed2ManyParamInterfacePublisher->OnProp1ChangedBP.RemoveAll(Testbed2ManyParamInterfacePublisher);
		Testbed2ManyParamInterfacePublisher->OnProp2Changed.RemoveAll(Testbed2ManyParamInterfacePublisher);
		Testbed2ManyParamInterfacePublisher->OnProp2ChangedBP.RemoveAll(Testbed2ManyParamInterfacePublisher);
		Testbed2ManyParamInterfacePublisher->OnProp3Changed.RemoveAll(Testbed2ManyParamInterfacePublisher);
		Testbed2ManyParamInterfacePublisher->OnProp3ChangedBP.RemoveAll(Testbed2ManyParamInterfacePublisher);
		Testbed2ManyParamInterfacePublisher->OnProp4Changed.RemoveAll(Testbed2ManyParamInterfacePublisher);
		Testbed2ManyParamInterfacePublisher->OnProp4ChangedBP.RemoveAll(Testbed2ManyParamInterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTestbed2ManyParamInterface::IsInitialized() const
{
	return bInitialized;
}
