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
#include "AbstractTbSame1SameStruct2Interface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbSame1SameStruct2InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSame1SameStruct2InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTbSame1SameStruct2Interface::UAbstractTbSame1SameStruct2Interface()
{
	TbSame1SameStruct2InterfaceSignals = NewObject<UTbSame1SameStruct2InterfaceSignals>();
}

UTbSame1SameStruct2InterfaceSignals* UAbstractTbSame1SameStruct2Interface::_GetSignals_Implementation()
{
	if (!TbSame1SameStruct2InterfaceSignals)
	{
		TbSame1SameStruct2InterfaceSignals = NewObject<UTbSame1SameStruct2InterfaceSignals>();
	}
	return TbSame1SameStruct2InterfaceSignals;
}

FTbSame1Struct2 UAbstractTbSame1SameStruct2Interface::GetProp1_Private() const
{
	return Execute_GetProp1(this);
};

void UAbstractTbSame1SameStruct2Interface::SetProp1_Private(const FTbSame1Struct2& InProp1)
{
	Execute_SetProp1(this, InProp1);
};

FTbSame1Struct2 UAbstractTbSame1SameStruct2Interface::GetProp2_Private() const
{
	return Execute_GetProp2(this);
};

void UAbstractTbSame1SameStruct2Interface::SetProp2_Private(const FTbSame1Struct2& InProp2)
{
	Execute_SetProp2(this, InProp2);
};

void UAbstractTbSame1SameStruct2Interface::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameStruct2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameStruct2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame1SameStruct2InterfaceLatentAction* CompletionAction = new FTbSame1SameStruct2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Func1(this, Param1);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param1, this, &Result, CompletionAction]()
				{
				Result = Execute_Func1(this, Param1);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSame1SameStruct2Interface::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameStruct2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameStruct2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame1SameStruct2InterfaceLatentAction* CompletionAction = new FTbSame1SameStruct2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Func2(this, Param1, Param2);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param1, Param2, this, &Result, CompletionAction]()
				{
				Result = Execute_Func2(this, Param1, Param2);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSame1SameStruct2Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSame1SameStruct2Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSame1SameStruct2InterfaceSignals)
	{
		TbSame1SameStruct2InterfaceSignals->OnSig1Signal.RemoveAll(TbSame1SameStruct2InterfaceSignals);
		TbSame1SameStruct2InterfaceSignals->OnSig2Signal.RemoveAll(TbSame1SameStruct2InterfaceSignals);

		TbSame1SameStruct2InterfaceSignals->OnProp1Changed.RemoveAll(TbSame1SameStruct2InterfaceSignals);
		TbSame1SameStruct2InterfaceSignals->OnProp2Changed.RemoveAll(TbSame1SameStruct2InterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTbSame1SameStruct2Interface::IsInitialized() const
{
	return bInitialized;
}
