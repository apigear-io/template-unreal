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
#include "Counter/Generated/api/AbstractCounterCounter.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

template <typename TAsyncResult>
class FCounterCounterLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	TAtomic<bool> bCancelled{false};
	TFuture<TAsyncResult> Future;
	TAsyncResult* OutPtr;

public:
	FCounterCounterLatentAction(const FLatentActionInfo& LatentInfo,
		TFuture<TAsyncResult>&& InFuture,
		TAsyncResult& ResultReference)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, Future(MoveTemp(InFuture))
		, OutPtr(&ResultReference)
	{
	}

	void Cancel()
	{
		bCancelled.Store(true);
	}

	void UpdateOperation(FLatentResponse& Response) override
	{
		if (bCancelled.Load())
		{
			Response.DoneIf(true);
			return;
		}

		if (Future.IsReady())
		{
			*OutPtr = Future.Get();
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
	}

	void NotifyObjectDestroyed() override
	{
		Cancel();
	}

	void NotifyActionAborted() override
	{
		Cancel();
	}
};

UAbstractCounterCounter::UAbstractCounterCounter()
{
	CounterCounterPublisher = NewObject<UCounterCounterPublisher>();
}

UCounterCounterPublisher* UAbstractCounterCounter::_GetPublisher()
{
	if (!CounterCounterPublisher)
	{
		CounterCounterPublisher = NewObject<UCounterCounterPublisher>();
	}
	return CounterCounterPublisher;
}

FCustomTypesVector3D UAbstractCounterCounter::GetVector_Private() const
{
	return GetVector();
};

void UAbstractCounterCounter::SetVector_Private(const FCustomTypesVector3D& InVector)
{
	SetVector(InVector);
};

FVector UAbstractCounterCounter::GetExternVector_Private() const
{
	return GetExternVector();
};

void UAbstractCounterCounter::SetExternVector_Private(const FVector& InExternVector)
{
	SetExternVector(InExternVector);
};

TArray<FCustomTypesVector3D> UAbstractCounterCounter::GetVectorArray_Private() const
{
	return GetVectorArray();
};

void UAbstractCounterCounter::SetVectorArray_Private(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	SetVectorArray(InVectorArray);
};

TArray<FVector> UAbstractCounterCounter::GetExternVectorArray_Private() const
{
	return GetExternVectorArray();
};

void UAbstractCounterCounter::SetExternVectorArray_Private(const TArray<FVector>& InExternVectorArray)
{
	SetExternVectorArray(InExternVectorArray);
};

void UAbstractCounterCounter::IncrementAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FVector& Result, const FVector& Vec)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FCounterCounterLatentAction<FVector>* oldRequest = LatentActionManager.FindExistingAction<FCounterCounterLatentAction<FVector>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FVector> Future = IncrementAsync(Vec);
		FCounterCounterLatentAction<FVector>* CompletionAction = new FCounterCounterLatentAction<FVector>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FVector> UAbstractCounterCounter::IncrementAsync(const FVector& Vec)
{
	return Async(EAsyncExecution::ThreadPool,
		[Vec, this]()
		{
		return Increment(Vec);
	});
}

void UAbstractCounterCounter::IncrementArrayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FVector>& Result, const TArray<FVector>& Vec)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FCounterCounterLatentAction<TArray<FVector>>* oldRequest = LatentActionManager.FindExistingAction<FCounterCounterLatentAction<TArray<FVector>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FVector>> Future = IncrementArrayAsync(Vec);
		FCounterCounterLatentAction<TArray<FVector>>* CompletionAction = new FCounterCounterLatentAction<TArray<FVector>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FVector>> UAbstractCounterCounter::IncrementArrayAsync(const TArray<FVector>& Vec)
{
	return Async(EAsyncExecution::ThreadPool,
		[Vec, this]()
		{
		return IncrementArray(Vec);
	});
}

void UAbstractCounterCounter::DecrementAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FCustomTypesVector3D& Result, const FCustomTypesVector3D& Vec)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FCounterCounterLatentAction<FCustomTypesVector3D>* oldRequest = LatentActionManager.FindExistingAction<FCounterCounterLatentAction<FCustomTypesVector3D>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FCustomTypesVector3D> Future = DecrementAsync(Vec);
		FCounterCounterLatentAction<FCustomTypesVector3D>* CompletionAction = new FCounterCounterLatentAction<FCustomTypesVector3D>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FCustomTypesVector3D> UAbstractCounterCounter::DecrementAsync(const FCustomTypesVector3D& Vec)
{
	return Async(EAsyncExecution::ThreadPool,
		[Vec, this]()
		{
		return Decrement(Vec);
	});
}

void UAbstractCounterCounter::DecrementArrayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FCustomTypesVector3D>& Result, const TArray<FCustomTypesVector3D>& Vec)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FCounterCounterLatentAction<TArray<FCustomTypesVector3D>>* oldRequest = LatentActionManager.FindExistingAction<FCounterCounterLatentAction<TArray<FCustomTypesVector3D>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FCustomTypesVector3D>> Future = DecrementArrayAsync(Vec);
		FCounterCounterLatentAction<TArray<FCustomTypesVector3D>>* CompletionAction = new FCounterCounterLatentAction<TArray<FCustomTypesVector3D>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FCustomTypesVector3D>> UAbstractCounterCounter::DecrementArrayAsync(const TArray<FCustomTypesVector3D>& Vec)
{
	return Async(EAsyncExecution::ThreadPool,
		[Vec, this]()
		{
		return DecrementArray(Vec);
	});
}

void UAbstractCounterCounter::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractCounterCounter::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (CounterCounterPublisher)
	{
		CounterCounterPublisher->OnValueChangedSignal.RemoveAll(CounterCounterPublisher);
		CounterCounterPublisher->OnValueChangedSignalBP.RemoveAll(CounterCounterPublisher);

		CounterCounterPublisher->OnVectorChanged.RemoveAll(CounterCounterPublisher);
		CounterCounterPublisher->OnVectorChangedBP.RemoveAll(CounterCounterPublisher);
		CounterCounterPublisher->OnExternVectorChanged.RemoveAll(CounterCounterPublisher);
		CounterCounterPublisher->OnExternVectorChangedBP.RemoveAll(CounterCounterPublisher);
		CounterCounterPublisher->OnVectorArrayChanged.RemoveAll(CounterCounterPublisher);
		CounterCounterPublisher->OnVectorArrayChangedBP.RemoveAll(CounterCounterPublisher);
		CounterCounterPublisher->OnExternVectorArrayChanged.RemoveAll(CounterCounterPublisher);
		CounterCounterPublisher->OnExternVectorArrayChangedBP.RemoveAll(CounterCounterPublisher);
	}

	Super::Deinitialize();
}

bool UAbstractCounterCounter::IsInitialized() const
{
	return bInitialized;
}
