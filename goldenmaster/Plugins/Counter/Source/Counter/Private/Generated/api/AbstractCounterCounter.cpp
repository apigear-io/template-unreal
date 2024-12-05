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
#include "AbstractCounterCounter.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FCounterCounterLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FCounterCounterLatentAction(const FLatentActionInfo& LatentInfo)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, bInProgress(true)
	{
	}

	void Cancel()
	{
		bInProgress = false;
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		if (bInProgress == false)
		{
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
	}

	virtual void NotifyObjectDestroyed()
	{
		Cancel();
	}

	virtual void NotifyActionAborted()
	{
		Cancel();
	}
};

UAbstractCounterCounter::UAbstractCounterCounter()
{
	CounterCounterSignals = NewObject<UCounterCounterSignals>();
}

UCounterCounterSignals* UAbstractCounterCounter::_GetSignals_Implementation()
{
	if (!CounterCounterSignals)
	{
		CounterCounterSignals = NewObject<UCounterCounterSignals>();
	}
	return CounterCounterSignals;
}

FCustomTypesVector3D UAbstractCounterCounter::GetVector_Private() const
{
	return Execute_GetVector(this);
};

void UAbstractCounterCounter::SetVector_Private(const FCustomTypesVector3D& InVector)
{
	Execute_SetVector(this, InVector);
};

FVector UAbstractCounterCounter::GetExternVector_Private() const
{
	return Execute_GetExternVector(this);
};

void UAbstractCounterCounter::SetExternVector_Private(const FVector& InExternVector)
{
	Execute_SetExternVector(this, InExternVector);
};

TArray<FCustomTypesVector3D> UAbstractCounterCounter::GetVectorArray_Private() const
{
	return Execute_GetVectorArray(this);
};

void UAbstractCounterCounter::SetVectorArray_Private(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	Execute_SetVectorArray(this, InVectorArray);
};

TArray<FVector> UAbstractCounterCounter::GetExternVectorArray_Private() const
{
	return Execute_GetExternVectorArray(this);
};

void UAbstractCounterCounter::SetExternVectorArray_Private(const TArray<FVector>& InExternVectorArray)
{
	Execute_SetExternVectorArray(this, InExternVectorArray);
};

void UAbstractCounterCounter::IncrementAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FVector& Result, const FVector& Vec)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FCounterCounterLatentAction* oldRequest = LatentActionManager.FindExistingAction<FCounterCounterLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FCounterCounterLatentAction* CompletionAction = new FCounterCounterLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Increment(this, Vec);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Vec, this, &Result, CompletionAction]()
				{
				Result = Execute_Increment(this, Vec);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractCounterCounter::IncrementArrayAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FVector>& Result, const TArray<FVector>& Vec)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FCounterCounterLatentAction* oldRequest = LatentActionManager.FindExistingAction<FCounterCounterLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FCounterCounterLatentAction* CompletionAction = new FCounterCounterLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_IncrementArray(this, Vec);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Vec, this, &Result, CompletionAction]()
				{
				Result = Execute_IncrementArray(this, Vec);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractCounterCounter::DecrementAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FCustomTypesVector3D& Result, const FCustomTypesVector3D& Vec)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FCounterCounterLatentAction* oldRequest = LatentActionManager.FindExistingAction<FCounterCounterLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FCounterCounterLatentAction* CompletionAction = new FCounterCounterLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Decrement(this, Vec);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Vec, this, &Result, CompletionAction]()
				{
				Result = Execute_Decrement(this, Vec);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractCounterCounter::DecrementArrayAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FCustomTypesVector3D>& Result, const TArray<FCustomTypesVector3D>& Vec)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FCounterCounterLatentAction* oldRequest = LatentActionManager.FindExistingAction<FCounterCounterLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FCounterCounterLatentAction* CompletionAction = new FCounterCounterLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_DecrementArray(this, Vec);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Vec, this, &Result, CompletionAction]()
				{
				Result = Execute_DecrementArray(this, Vec);
				CompletionAction->Cancel();
			});
		}
	}
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

	if (CounterCounterSignals)
	{
		CounterCounterSignals->OnValueChangedSignal.RemoveAll(CounterCounterSignals);

		CounterCounterSignals->OnVectorChanged.RemoveAll(CounterCounterSignals);
		CounterCounterSignals->OnExternVectorChanged.RemoveAll(CounterCounterSignals);
		CounterCounterSignals->OnVectorArrayChanged.RemoveAll(CounterCounterSignals);
		CounterCounterSignals->OnExternVectorArrayChanged.RemoveAll(CounterCounterSignals);
	}

	Super::Deinitialize();
}

bool UAbstractCounterCounter::IsInitialized() const
{
	return bInitialized;
}
