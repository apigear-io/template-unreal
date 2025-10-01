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
#include "Testbed1/Generated/api/AbstractTestbed1StructArray2Interface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

template <typename TAsyncResult>
class FTestbed1StructArray2InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	TAtomic<bool> bCancelled{false};
	TFuture<TAsyncResult> Future;
	TAsyncResult* OutPtr;

public:
	FTestbed1StructArray2InterfaceLatentAction(const FLatentActionInfo& LatentInfo,
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

UAbstractTestbed1StructArray2Interface::UAbstractTestbed1StructArray2Interface()
{
	Testbed1StructArray2InterfacePublisher = NewObject<UTestbed1StructArray2InterfacePublisher>();
}

UTestbed1StructArray2InterfacePublisher* UAbstractTestbed1StructArray2Interface::_GetPublisher()
{
	if (!Testbed1StructArray2InterfacePublisher)
	{
		Testbed1StructArray2InterfacePublisher = NewObject<UTestbed1StructArray2InterfacePublisher>();
	}
	return Testbed1StructArray2InterfacePublisher;
}

FTestbed1StructBoolWithArray UAbstractTestbed1StructArray2Interface::GetPropBool_Private() const
{
	return GetPropBool();
};

void UAbstractTestbed1StructArray2Interface::SetPropBool_Private(const FTestbed1StructBoolWithArray& InPropBool)
{
	SetPropBool(InPropBool);
};

FTestbed1StructIntWithArray UAbstractTestbed1StructArray2Interface::GetPropInt_Private() const
{
	return GetPropInt();
};

void UAbstractTestbed1StructArray2Interface::SetPropInt_Private(const FTestbed1StructIntWithArray& InPropInt)
{
	SetPropInt(InPropInt);
};

FTestbed1StructFloatWithArray UAbstractTestbed1StructArray2Interface::GetPropFloat_Private() const
{
	return GetPropFloat();
};

void UAbstractTestbed1StructArray2Interface::SetPropFloat_Private(const FTestbed1StructFloatWithArray& InPropFloat)
{
	SetPropFloat(InPropFloat);
};

FTestbed1StructStringWithArray UAbstractTestbed1StructArray2Interface::GetPropString_Private() const
{
	return GetPropString();
};

void UAbstractTestbed1StructArray2Interface::SetPropString_Private(const FTestbed1StructStringWithArray& InPropString)
{
	SetPropString(InPropString);
};

FTestbed1StructEnumWithArray UAbstractTestbed1StructArray2Interface::GetPropEnum_Private() const
{
	return GetPropEnum();
};

void UAbstractTestbed1StructArray2Interface::SetPropEnum_Private(const FTestbed1StructEnumWithArray& InPropEnum)
{
	SetPropEnum(InPropEnum);
};

void UAbstractTestbed1StructArray2Interface::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructBool>& Result, const FTestbed1StructBoolWithArray& ParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructBool>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructBool>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructBool>> Future = FuncBoolAsync(ParamBool);
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructBool>>* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructBool>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructBool>> UAbstractTestbed1StructArray2Interface::FuncBoolAsync(const FTestbed1StructBoolWithArray& ParamBool)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamBool, this]()
		{
		return FuncBool(ParamBool);
	});
}

void UAbstractTestbed1StructArray2Interface::FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructInt>& Result, const FTestbed1StructIntWithArray& ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructInt>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructInt>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructInt>> Future = FuncIntAsync(ParamInt);
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructInt>>* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructInt>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructInt>> UAbstractTestbed1StructArray2Interface::FuncIntAsync(const FTestbed1StructIntWithArray& ParamInt)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt, this]()
		{
		return FuncInt(ParamInt);
	});
}

void UAbstractTestbed1StructArray2Interface::FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructFloat>& Result, const FTestbed1StructFloatWithArray& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructFloat>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructFloat>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructFloat>> Future = FuncFloatAsync(ParamFloat);
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructFloat>>* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructFloat>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructFloat>> UAbstractTestbed1StructArray2Interface::FuncFloatAsync(const FTestbed1StructFloatWithArray& ParamFloat)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat, this]()
		{
		return FuncFloat(ParamFloat);
	});
}

void UAbstractTestbed1StructArray2Interface::FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructString>& Result, const FTestbed1StructStringWithArray& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructString>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructString>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FTestbed1StructString>> Future = FuncStringAsync(ParamString);
		FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructString>>* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction<TArray<FTestbed1StructString>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FTestbed1StructString>> UAbstractTestbed1StructArray2Interface::FuncStringAsync(const FTestbed1StructStringWithArray& ParamString)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamString, this]()
		{
		return FuncString(ParamString);
	});
}

void UAbstractTestbed1StructArray2Interface::FuncEnumAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<ETestbed1Enum0>& Result, const FTestbed1StructEnumWithArray& ParamEnum)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction<TArray<ETestbed1Enum0>>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction<TArray<ETestbed1Enum0>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<ETestbed1Enum0>> Future = FuncEnumAsync(ParamEnum);
		FTestbed1StructArray2InterfaceLatentAction<TArray<ETestbed1Enum0>>* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction<TArray<ETestbed1Enum0>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<ETestbed1Enum0>> UAbstractTestbed1StructArray2Interface::FuncEnumAsync(const FTestbed1StructEnumWithArray& ParamEnum)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamEnum, this]()
		{
		return FuncEnum(ParamEnum);
	});
}

void UAbstractTestbed1StructArray2Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed1StructArray2Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (Testbed1StructArray2InterfacePublisher)
	{
		Testbed1StructArray2InterfacePublisher->OnSigBoolSignal.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnSigBoolSignalBP.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnSigIntSignal.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnSigIntSignalBP.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnSigFloatSignal.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnSigFloatSignalBP.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnSigStringSignal.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnSigStringSignalBP.RemoveAll(Testbed1StructArray2InterfacePublisher);

		Testbed1StructArray2InterfacePublisher->OnPropBoolChanged.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnPropBoolChangedBP.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnPropIntChanged.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnPropIntChangedBP.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnPropFloatChanged.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnPropFloatChangedBP.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnPropStringChanged.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnPropStringChangedBP.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnPropEnumChanged.RemoveAll(Testbed1StructArray2InterfacePublisher);
		Testbed1StructArray2InterfacePublisher->OnPropEnumChangedBP.RemoveAll(Testbed1StructArray2InterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTestbed1StructArray2Interface::IsInitialized() const
{
	return bInitialized;
}
