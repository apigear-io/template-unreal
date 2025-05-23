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
#include "TbSame1/Generated/api/AbstractTbSame1SameEnum2Interface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbSame1SameEnum2InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSame1SameEnum2InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTbSame1SameEnum2Interface::UAbstractTbSame1SameEnum2Interface()
{
	TbSame1SameEnum2InterfaceSignals = NewObject<UTbSame1SameEnum2InterfaceSignals>();
}

UTbSame1SameEnum2InterfaceSignals* UAbstractTbSame1SameEnum2Interface::_GetSignals()
{
	if (!TbSame1SameEnum2InterfaceSignals)
	{
		TbSame1SameEnum2InterfaceSignals = NewObject<UTbSame1SameEnum2InterfaceSignals>();
	}
	return TbSame1SameEnum2InterfaceSignals;
}

ETbSame1Enum1 UAbstractTbSame1SameEnum2Interface::GetProp1_Private() const
{
	return GetProp1();
};

void UAbstractTbSame1SameEnum2Interface::SetProp1_Private(ETbSame1Enum1 InProp1)
{
	SetProp1(InProp1);
};

ETbSame1Enum2 UAbstractTbSame1SameEnum2Interface::GetProp2_Private() const
{
	return GetProp2();
};

void UAbstractTbSame1SameEnum2Interface::SetProp2_Private(ETbSame1Enum2 InProp2)
{
	SetProp2(InProp2);
};

void UAbstractTbSame1SameEnum2Interface::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameEnum2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameEnum2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame1SameEnum2InterfaceLatentAction* CompletionAction = new FTbSame1SameEnum2InterfaceLatentAction(LatentInfo);
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

void UAbstractTbSame1SameEnum2Interface::Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameEnum2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameEnum2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame1SameEnum2InterfaceLatentAction* CompletionAction = new FTbSame1SameEnum2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Func2(Param1, Param2);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param1, Param2, this, &Result, CompletionAction]()
				{
				Result = Func2(Param1, Param2);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSame1SameEnum2Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSame1SameEnum2Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSame1SameEnum2InterfaceSignals)
	{
		TbSame1SameEnum2InterfaceSignals->OnSig1Signal.RemoveAll(TbSame1SameEnum2InterfaceSignals);
		TbSame1SameEnum2InterfaceSignals->OnSig1SignalBP.RemoveAll(TbSame1SameEnum2InterfaceSignals);
		TbSame1SameEnum2InterfaceSignals->OnSig2Signal.RemoveAll(TbSame1SameEnum2InterfaceSignals);
		TbSame1SameEnum2InterfaceSignals->OnSig2SignalBP.RemoveAll(TbSame1SameEnum2InterfaceSignals);

		TbSame1SameEnum2InterfaceSignals->OnProp1Changed.RemoveAll(TbSame1SameEnum2InterfaceSignals);
		TbSame1SameEnum2InterfaceSignals->OnProp1ChangedBP.RemoveAll(TbSame1SameEnum2InterfaceSignals);
		TbSame1SameEnum2InterfaceSignals->OnProp2Changed.RemoveAll(TbSame1SameEnum2InterfaceSignals);
		TbSame1SameEnum2InterfaceSignals->OnProp2ChangedBP.RemoveAll(TbSame1SameEnum2InterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTbSame1SameEnum2Interface::IsInitialized() const
{
	return bInitialized;
}
