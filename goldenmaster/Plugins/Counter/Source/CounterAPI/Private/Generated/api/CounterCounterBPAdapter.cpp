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
#include "Counter/Generated/api/CounterCounterBPAdapter.h"
#include "CounterCounterLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UCounterCounterBPAdapter::Initialize(TScriptInterface<ICounterCounterBPInterface> InTarget)
{
	Target = InTarget;
}

UCounterCounterPublisher* UCounterCounterBPAdapter::_GetPublisher()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ICounterCounterBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UCounterCounterBPAdapter::IncrementAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FVector& Result, const FVector& Vec)
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

TFuture<FVector> UCounterCounterBPAdapter::IncrementAsync(const FVector& Vec)
{
	return Async(EAsyncExecution::ThreadPool,
		[Vec, this]()
		{
		return Increment(Vec);
	});
}

FVector UCounterCounterBPAdapter::Increment(const FVector& Vec)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ICounterCounterBPInterface::Execute_Increment(Obj, Vec);
	}
	return FVector(0.f, 0.f, 0.f);
}

void UCounterCounterBPAdapter::IncrementArrayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FVector>& Result, const TArray<FVector>& Vec)
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

TFuture<TArray<FVector>> UCounterCounterBPAdapter::IncrementArrayAsync(const TArray<FVector>& Vec)
{
	return Async(EAsyncExecution::ThreadPool,
		[Vec, this]()
		{
		return IncrementArray(Vec);
	});
}

TArray<FVector> UCounterCounterBPAdapter::IncrementArray(const TArray<FVector>& Vec)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ICounterCounterBPInterface::Execute_IncrementArray(Obj, Vec);
	}
	return TArray<FVector>();
}

void UCounterCounterBPAdapter::DecrementAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FCustomTypesVector3D& Result, const FCustomTypesVector3D& Vec)
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

TFuture<FCustomTypesVector3D> UCounterCounterBPAdapter::DecrementAsync(const FCustomTypesVector3D& Vec)
{
	return Async(EAsyncExecution::ThreadPool,
		[Vec, this]()
		{
		return Decrement(Vec);
	});
}

FCustomTypesVector3D UCounterCounterBPAdapter::Decrement(const FCustomTypesVector3D& Vec)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ICounterCounterBPInterface::Execute_Decrement(Obj, Vec);
	}
	return FCustomTypesVector3D();
}

void UCounterCounterBPAdapter::DecrementArrayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FCustomTypesVector3D>& Result, const TArray<FCustomTypesVector3D>& Vec)
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

TFuture<TArray<FCustomTypesVector3D>> UCounterCounterBPAdapter::DecrementArrayAsync(const TArray<FCustomTypesVector3D>& Vec)
{
	return Async(EAsyncExecution::ThreadPool,
		[Vec, this]()
		{
		return DecrementArray(Vec);
	});
}

TArray<FCustomTypesVector3D> UCounterCounterBPAdapter::DecrementArray(const TArray<FCustomTypesVector3D>& Vec)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ICounterCounterBPInterface::Execute_DecrementArray(Obj, Vec);
	}
	return TArray<FCustomTypesVector3D>();
}

FCustomTypesVector3D UCounterCounterBPAdapter::GetVector() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ICounterCounterBPInterface::Execute_GetVector(Obj);
	}
	return FCustomTypesVector3D();
}
void UCounterCounterBPAdapter::SetVector(const FCustomTypesVector3D& InVector)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ICounterCounterBPInterface::Execute_SetVector(Obj, InVector);
	}
}

FVector UCounterCounterBPAdapter::GetExternVector() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ICounterCounterBPInterface::Execute_GetExternVector(Obj);
	}
	return FVector(0.f, 0.f, 0.f);
}
void UCounterCounterBPAdapter::SetExternVector(const FVector& InExternVector)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ICounterCounterBPInterface::Execute_SetExternVector(Obj, InExternVector);
	}
}

TArray<FCustomTypesVector3D> UCounterCounterBPAdapter::GetVectorArray() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ICounterCounterBPInterface::Execute_GetVectorArray(Obj);
	}
	return TArray<FCustomTypesVector3D>();
}
void UCounterCounterBPAdapter::SetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ICounterCounterBPInterface::Execute_SetVectorArray(Obj, InVectorArray);
	}
}

TArray<FVector> UCounterCounterBPAdapter::GetExternVectorArray() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ICounterCounterBPInterface::Execute_GetExternVectorArray(Obj);
	}
	return TArray<FVector>();
}
void UCounterCounterBPAdapter::SetExternVectorArray(const TArray<FVector>& InExternVectorArray)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ICounterCounterBPInterface::Execute_SetExternVectorArray(Obj, InExternVectorArray);
	}
}
