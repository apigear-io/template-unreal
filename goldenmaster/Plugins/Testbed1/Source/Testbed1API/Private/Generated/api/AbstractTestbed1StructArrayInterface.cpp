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
#include "Testbed1/Generated/api/AbstractTestbed1StructArrayInterface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

template <typename TAsyncResult>
class FTestbed1StructArrayInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	TAtomic<bool> bCancelled{false};
	TFuture<TAsyncResult> Future;
	TAsyncResult* OutPtr;

public:
	FTestbed1StructArrayInterfaceLatentAction(const FLatentActionInfo& LatentInfo,
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

UAbstractTestbed1StructArrayInterface::UAbstractTestbed1StructArrayInterface()
{
	Testbed1StructArrayInterfacePublisher = NewObject<UTestbed1StructArrayInterfacePublisher>();
}

UTestbed1StructArrayInterfacePublisher* UAbstractTestbed1StructArrayInterface::_GetPublisher()
{
	if (!Testbed1StructArrayInterfacePublisher)
	{
		Testbed1StructArrayInterfacePublisher = NewObject<UTestbed1StructArrayInterfacePublisher>();
	}
	return Testbed1StructArrayInterfacePublisher;
}

TArray<FTestbed1StructBool> UAbstractTestbed1StructArrayInterface::GetPropBool_Private() const
{
	return GetPropBool();
};

void UAbstractTestbed1StructArrayInterface::SetPropBool_Private(const TArray<FTestbed1StructBool>& InPropBool)
{
	SetPropBool(InPropBool);
};

TArray<FTestbed1StructInt> UAbstractTestbed1StructArrayInterface::GetPropInt_Private() const
{
	return GetPropInt();
};

void UAbstractTestbed1StructArrayInterface::SetPropInt_Private(const TArray<FTestbed1StructInt>& InPropInt)
{
	SetPropInt(InPropInt);
};

TArray<FTestbed1StructFloat> UAbstractTestbed1StructArrayInterface::GetPropFloat_Private() const
{
	return GetPropFloat();
};

void UAbstractTestbed1StructArrayInterface::SetPropFloat_Private(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	SetPropFloat(InPropFloat);
};

TArray<FTestbed1StructString> UAbstractTestbed1StructArrayInterface::GetPropString_Private() const
{
	return GetPropString();
};

void UAbstractTestbed1StructArrayInterface::SetPropString_Private(const TArray<FTestbed1StructString>& InPropString)
{
	SetPropString(InPropString);
};

TArray<ETestbed1Enum0> UAbstractTestbed1StructArrayInterface::GetPropEnum_Private() const
{
	return GetPropEnum();
};

void UAbstractTestbed1StructArrayInterface::SetPropEnum_Private(const TArray<ETestbed1Enum0>& InPropEnum)
{
	SetPropEnum(InPropEnum);
};

void UAbstractTestbed1StructArrayInterface::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructBool>& Result, const TArray<FTestbed1StructBool>& ParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructBool>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructBool>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructBool>> Future = FuncBoolAsync(ParamBool);
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructBool>>* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructBool>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructBool>> UAbstractTestbed1StructArrayInterface::FuncBoolAsync(const TArray<FTestbed1StructBool>& ParamBool)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamBool, this]()
		{
		return FuncBool(ParamBool);
	});
}

void UAbstractTestbed1StructArrayInterface::FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructInt>& Result, const TArray<FTestbed1StructInt>& ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructInt>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructInt>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructInt>> Future = FuncIntAsync(ParamInt);
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructInt>>* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructInt>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructInt>> UAbstractTestbed1StructArrayInterface::FuncIntAsync(const TArray<FTestbed1StructInt>& ParamInt)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt, this]()
		{
		return FuncInt(ParamInt);
	});
}

void UAbstractTestbed1StructArrayInterface::FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructFloat>& Result, const TArray<FTestbed1StructFloat>& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructFloat>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructFloat>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructFloat>> Future = FuncFloatAsync(ParamFloat);
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructFloat>>* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructFloat>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructFloat>> UAbstractTestbed1StructArrayInterface::FuncFloatAsync(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat, this]()
		{
		return FuncFloat(ParamFloat);
	});
}

void UAbstractTestbed1StructArrayInterface::FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructString>& Result, const TArray<FTestbed1StructString>& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructString>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructString>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructString>> Future = FuncStringAsync(ParamString);
		FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructString>>* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction<TArray<FTestbed1StructString>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructString>> UAbstractTestbed1StructArrayInterface::FuncStringAsync(const TArray<FTestbed1StructString>& ParamString)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamString, this]()
		{
		return FuncString(ParamString);
	});
}

void UAbstractTestbed1StructArrayInterface::FuncEnumAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<ETestbed1Enum0>& Result, const TArray<ETestbed1Enum0>& ParamEnum)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction<TArray<ETestbed1Enum0>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction<TArray<ETestbed1Enum0>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<ETestbed1Enum0>> Future = FuncEnumAsync(ParamEnum);
		FTestbed1StructArrayInterfaceLatentAction<TArray<ETestbed1Enum0>>* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction<TArray<ETestbed1Enum0>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<ETestbed1Enum0>> UAbstractTestbed1StructArrayInterface::FuncEnumAsync(const TArray<ETestbed1Enum0>& ParamEnum)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamEnum, this]()
		{
		return FuncEnum(ParamEnum);
	});
}

void UAbstractTestbed1StructArrayInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed1StructArrayInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (Testbed1StructArrayInterfacePublisher)
	{
		Testbed1StructArrayInterfacePublisher->OnSigBoolSignal.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnSigBoolSignalBP.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnSigIntSignal.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnSigIntSignalBP.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnSigFloatSignal.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnSigFloatSignalBP.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnSigStringSignal.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnSigStringSignalBP.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnSigEnumSignal.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnSigEnumSignalBP.RemoveAll(Testbed1StructArrayInterfacePublisher);

		Testbed1StructArrayInterfacePublisher->OnPropBoolChanged.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnPropBoolChangedBP.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnPropIntChanged.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnPropIntChangedBP.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnPropFloatChanged.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnPropFloatChangedBP.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnPropStringChanged.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnPropStringChangedBP.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnPropEnumChanged.RemoveAll(Testbed1StructArrayInterfacePublisher);
		Testbed1StructArrayInterfacePublisher->OnPropEnumChangedBP.RemoveAll(Testbed1StructArrayInterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTestbed1StructArrayInterface::IsInitialized() const
{
	return bInitialized;
}
