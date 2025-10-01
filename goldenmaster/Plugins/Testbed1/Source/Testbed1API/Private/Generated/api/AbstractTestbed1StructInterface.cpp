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
#include "Testbed1/Generated/api/AbstractTestbed1StructInterface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

template <typename TAsyncResult>
class FTestbed1StructInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	TAtomic<bool> bCancelled{false};
	TFuture<TAsyncResult> Future;
	TAsyncResult* OutPtr;

public:
	FTestbed1StructInterfaceLatentAction(const FLatentActionInfo& LatentInfo,
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

UAbstractTestbed1StructInterface::UAbstractTestbed1StructInterface()
{
	Testbed1StructInterfacePublisher = NewObject<UTestbed1StructInterfacePublisher>();
}

UTestbed1StructInterfacePublisher* UAbstractTestbed1StructInterface::_GetPublisher()
{
	if (!Testbed1StructInterfacePublisher)
	{
		Testbed1StructInterfacePublisher = NewObject<UTestbed1StructInterfacePublisher>();
	}
	return Testbed1StructInterfacePublisher;
}

FTestbed1StructBool UAbstractTestbed1StructInterface::GetPropBool_Private() const
{
	return GetPropBool();
};

void UAbstractTestbed1StructInterface::SetPropBool_Private(const FTestbed1StructBool& InPropBool)
{
	SetPropBool(InPropBool);
};

FTestbed1StructInt UAbstractTestbed1StructInterface::GetPropInt_Private() const
{
	return GetPropInt();
};

void UAbstractTestbed1StructInterface::SetPropInt_Private(const FTestbed1StructInt& InPropInt)
{
	SetPropInt(InPropInt);
};

FTestbed1StructFloat UAbstractTestbed1StructInterface::GetPropFloat_Private() const
{
	return GetPropFloat();
};

void UAbstractTestbed1StructInterface::SetPropFloat_Private(const FTestbed1StructFloat& InPropFloat)
{
	SetPropFloat(InPropFloat);
};

FTestbed1StructString UAbstractTestbed1StructInterface::GetPropString_Private() const
{
	return GetPropString();
};

void UAbstractTestbed1StructInterface::SetPropString_Private(const FTestbed1StructString& InPropString)
{
	SetPropString(InPropString);
};

void UAbstractTestbed1StructInterface::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction<FTestbed1StructBool>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction<FTestbed1StructBool>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed1StructBool> Future = FuncBoolAsync(ParamBool);
		FTestbed1StructInterfaceLatentAction<FTestbed1StructBool>* CompletionAction = new FTestbed1StructInterfaceLatentAction<FTestbed1StructBool>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed1StructBool> UAbstractTestbed1StructInterface::FuncBoolAsync(const FTestbed1StructBool& ParamBool)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamBool, this]()
		{
		return FuncBool(ParamBool);
	});
}

void UAbstractTestbed1StructInterface::FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructInt& Result, const FTestbed1StructInt& ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction<FTestbed1StructInt>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction<FTestbed1StructInt>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed1StructInt> Future = FuncIntAsync(ParamInt);
		FTestbed1StructInterfaceLatentAction<FTestbed1StructInt>* CompletionAction = new FTestbed1StructInterfaceLatentAction<FTestbed1StructInt>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed1StructInt> UAbstractTestbed1StructInterface::FuncIntAsync(const FTestbed1StructInt& ParamInt)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt, this]()
		{
		return FuncInt(ParamInt);
	});
}

void UAbstractTestbed1StructInterface::FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction<FTestbed1StructFloat>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction<FTestbed1StructFloat>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed1StructFloat> Future = FuncFloatAsync(ParamFloat);
		FTestbed1StructInterfaceLatentAction<FTestbed1StructFloat>* CompletionAction = new FTestbed1StructInterfaceLatentAction<FTestbed1StructFloat>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed1StructFloat> UAbstractTestbed1StructInterface::FuncFloatAsync(const FTestbed1StructFloat& ParamFloat)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat, this]()
		{
		return FuncFloat(ParamFloat);
	});
}

void UAbstractTestbed1StructInterface::FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction<FTestbed1StructString>* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction<FTestbed1StructString>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FTestbed1StructString> Future = FuncStringAsync(ParamString);
		FTestbed1StructInterfaceLatentAction<FTestbed1StructString>* CompletionAction = new FTestbed1StructInterfaceLatentAction<FTestbed1StructString>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FTestbed1StructString> UAbstractTestbed1StructInterface::FuncStringAsync(const FTestbed1StructString& ParamString)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamString, this]()
		{
		return FuncString(ParamString);
	});
}

void UAbstractTestbed1StructInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed1StructInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (Testbed1StructInterfacePublisher)
	{
		Testbed1StructInterfacePublisher->OnSigBoolSignal.RemoveAll(Testbed1StructInterfacePublisher);
		Testbed1StructInterfacePublisher->OnSigBoolSignalBP.RemoveAll(Testbed1StructInterfacePublisher);
		Testbed1StructInterfacePublisher->OnSigIntSignal.RemoveAll(Testbed1StructInterfacePublisher);
		Testbed1StructInterfacePublisher->OnSigIntSignalBP.RemoveAll(Testbed1StructInterfacePublisher);
		Testbed1StructInterfacePublisher->OnSigFloatSignal.RemoveAll(Testbed1StructInterfacePublisher);
		Testbed1StructInterfacePublisher->OnSigFloatSignalBP.RemoveAll(Testbed1StructInterfacePublisher);
		Testbed1StructInterfacePublisher->OnSigStringSignal.RemoveAll(Testbed1StructInterfacePublisher);
		Testbed1StructInterfacePublisher->OnSigStringSignalBP.RemoveAll(Testbed1StructInterfacePublisher);

		Testbed1StructInterfacePublisher->OnPropBoolChanged.RemoveAll(Testbed1StructInterfacePublisher);
		Testbed1StructInterfacePublisher->OnPropBoolChangedBP.RemoveAll(Testbed1StructInterfacePublisher);
		Testbed1StructInterfacePublisher->OnPropIntChanged.RemoveAll(Testbed1StructInterfacePublisher);
		Testbed1StructInterfacePublisher->OnPropIntChangedBP.RemoveAll(Testbed1StructInterfacePublisher);
		Testbed1StructInterfacePublisher->OnPropFloatChanged.RemoveAll(Testbed1StructInterfacePublisher);
		Testbed1StructInterfacePublisher->OnPropFloatChangedBP.RemoveAll(Testbed1StructInterfacePublisher);
		Testbed1StructInterfacePublisher->OnPropStringChanged.RemoveAll(Testbed1StructInterfacePublisher);
		Testbed1StructInterfacePublisher->OnPropStringChangedBP.RemoveAll(Testbed1StructInterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTestbed1StructInterface::IsInitialized() const
{
	return bInitialized;
}
