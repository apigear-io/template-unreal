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
#include "TbEnum/Generated/api/AbstractTbEnumEnumInterface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbEnumEnumInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbEnumEnumInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTbEnumEnumInterface::UAbstractTbEnumEnumInterface()
{
	TbEnumEnumInterfacePublisher = NewObject<UTbEnumEnumInterfacePublisher>();
}

UTbEnumEnumInterfacePublisher* UAbstractTbEnumEnumInterface::_GetPublisher()
{
	if (!TbEnumEnumInterfacePublisher)
	{
		TbEnumEnumInterfacePublisher = NewObject<UTbEnumEnumInterfacePublisher>();
	}
	return TbEnumEnumInterfacePublisher;
}

ETbEnumEnum0 UAbstractTbEnumEnumInterface::GetProp0_Private() const
{
	return GetProp0();
};

void UAbstractTbEnumEnumInterface::SetProp0_Private(ETbEnumEnum0 InProp0)
{
	SetProp0(InProp0);
};

ETbEnumEnum1 UAbstractTbEnumEnumInterface::GetProp1_Private() const
{
	return GetProp1();
};

void UAbstractTbEnumEnumInterface::SetProp1_Private(ETbEnumEnum1 InProp1)
{
	SetProp1(InProp1);
};

ETbEnumEnum2 UAbstractTbEnumEnumInterface::GetProp2_Private() const
{
	return GetProp2();
};

void UAbstractTbEnumEnumInterface::SetProp2_Private(ETbEnumEnum2 InProp2)
{
	SetProp2(InProp2);
};

ETbEnumEnum3 UAbstractTbEnumEnumInterface::GetProp3_Private() const
{
	return GetProp3();
};

void UAbstractTbEnumEnumInterface::SetProp3_Private(ETbEnumEnum3 InProp3)
{
	SetProp3(InProp3);
};

void UAbstractTbEnumEnumInterface::Func0Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbEnumEnumInterfaceLatentAction* CompletionAction = new FTbEnumEnumInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Func0(Param0);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param0, this, &Result, CompletionAction]()
				{
				Result = Func0(Param0);
				CompletionAction->Cancel();
			});
		}
	}
}

TFuture<ETbEnumEnum0> UAbstractTbEnumEnumInterface::Func0Async(ETbEnumEnum0 Param0)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param0, this]()
		{
		return Func0(Param0);
	});
}

void UAbstractTbEnumEnumInterface::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbEnumEnumInterfaceLatentAction* CompletionAction = new FTbEnumEnumInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Func1(Param1);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param1, this, &Result, CompletionAction]()
				{
				Result = Func1(Param1);
				CompletionAction->Cancel();
			});
		}
	}
}

TFuture<ETbEnumEnum1> UAbstractTbEnumEnumInterface::Func1Async(ETbEnumEnum1 Param1)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, this]()
		{
		return Func1(Param1);
	});
}

void UAbstractTbEnumEnumInterface::Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbEnumEnumInterfaceLatentAction* CompletionAction = new FTbEnumEnumInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Func2(Param2);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param2, this, &Result, CompletionAction]()
				{
				Result = Func2(Param2);
				CompletionAction->Cancel();
			});
		}
	}
}

TFuture<ETbEnumEnum2> UAbstractTbEnumEnumInterface::Func2Async(ETbEnumEnum2 Param2)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param2, this]()
		{
		return Func2(Param2);
	});
}

void UAbstractTbEnumEnumInterface::Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbEnumEnumInterfaceLatentAction* CompletionAction = new FTbEnumEnumInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Func3(Param3);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param3, this, &Result, CompletionAction]()
				{
				Result = Func3(Param3);
				CompletionAction->Cancel();
			});
		}
	}
}

TFuture<ETbEnumEnum3> UAbstractTbEnumEnumInterface::Func3Async(ETbEnumEnum3 Param3)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param3, this]()
		{
		return Func3(Param3);
	});
}

void UAbstractTbEnumEnumInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbEnumEnumInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbEnumEnumInterfacePublisher)
	{
		TbEnumEnumInterfacePublisher->OnSig0Signal.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnSig0SignalBP.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnSig1Signal.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnSig1SignalBP.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnSig2Signal.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnSig2SignalBP.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnSig3Signal.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnSig3SignalBP.RemoveAll(TbEnumEnumInterfacePublisher);

		TbEnumEnumInterfacePublisher->OnProp0Changed.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnProp0ChangedBP.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnProp1Changed.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnProp1ChangedBP.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnProp2Changed.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnProp2ChangedBP.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnProp3Changed.RemoveAll(TbEnumEnumInterfacePublisher);
		TbEnumEnumInterfacePublisher->OnProp3ChangedBP.RemoveAll(TbEnumEnumInterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbEnumEnumInterface::IsInitialized() const
{
	return bInitialized;
}
