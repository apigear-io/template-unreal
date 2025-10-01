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
#include "TbSame2/Generated/api/AbstractTbSame2SameEnum2Interface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

template <typename TAsyncResult>
class FTbSame2SameEnum2InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	TAtomic<bool> bCancelled{false};
	TFuture<TAsyncResult> Future;
	TAsyncResult* OutPtr;

public:
	FTbSame2SameEnum2InterfaceLatentAction(const FLatentActionInfo& LatentInfo,
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

UAbstractTbSame2SameEnum2Interface::UAbstractTbSame2SameEnum2Interface()
{
	TbSame2SameEnum2InterfacePublisher = NewObject<UTbSame2SameEnum2InterfacePublisher>();
}

UTbSame2SameEnum2InterfacePublisher* UAbstractTbSame2SameEnum2Interface::_GetPublisher()
{
	if (!TbSame2SameEnum2InterfacePublisher)
	{
		TbSame2SameEnum2InterfacePublisher = NewObject<UTbSame2SameEnum2InterfacePublisher>();
	}
	return TbSame2SameEnum2InterfacePublisher;
}

ETbSame2Enum1 UAbstractTbSame2SameEnum2Interface::GetProp1_Private() const
{
	return GetProp1();
};

void UAbstractTbSame2SameEnum2Interface::SetProp1_Private(ETbSame2Enum1 InProp1)
{
	SetProp1(InProp1);
};

ETbSame2Enum2 UAbstractTbSame2SameEnum2Interface::GetProp2_Private() const
{
	return GetProp2();
};

void UAbstractTbSame2SameEnum2Interface::SetProp2_Private(ETbSame2Enum2 InProp2)
{
	SetProp2(InProp2);
};

void UAbstractTbSame2SameEnum2Interface::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbSame2Enum1> Future = Func1Async(Param1);
		FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>* CompletionAction = new FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbSame2Enum1> UAbstractTbSame2SameEnum2Interface::Func1Async(ETbSame2Enum1 Param1)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, this]()
		{
		return Func1(Param1);
	});
}

void UAbstractTbSame2SameEnum2Interface::Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbSame2Enum1> Future = Func2Async(Param1, Param2);
		FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>* CompletionAction = new FTbSame2SameEnum2InterfaceLatentAction<ETbSame2Enum1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbSame2Enum1> UAbstractTbSame2SameEnum2Interface::Func2Async(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, Param2, this]()
		{
		return Func2(Param1, Param2);
	});
}

void UAbstractTbSame2SameEnum2Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSame2SameEnum2Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSame2SameEnum2InterfacePublisher)
	{
		TbSame2SameEnum2InterfacePublisher->OnSig1Signal.RemoveAll(TbSame2SameEnum2InterfacePublisher);
		TbSame2SameEnum2InterfacePublisher->OnSig1SignalBP.RemoveAll(TbSame2SameEnum2InterfacePublisher);
		TbSame2SameEnum2InterfacePublisher->OnSig2Signal.RemoveAll(TbSame2SameEnum2InterfacePublisher);
		TbSame2SameEnum2InterfacePublisher->OnSig2SignalBP.RemoveAll(TbSame2SameEnum2InterfacePublisher);

		TbSame2SameEnum2InterfacePublisher->OnProp1Changed.RemoveAll(TbSame2SameEnum2InterfacePublisher);
		TbSame2SameEnum2InterfacePublisher->OnProp1ChangedBP.RemoveAll(TbSame2SameEnum2InterfacePublisher);
		TbSame2SameEnum2InterfacePublisher->OnProp2Changed.RemoveAll(TbSame2SameEnum2InterfacePublisher);
		TbSame2SameEnum2InterfacePublisher->OnProp2ChangedBP.RemoveAll(TbSame2SameEnum2InterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbSame2SameEnum2Interface::IsInitialized() const
{
	return bInitialized;
}
