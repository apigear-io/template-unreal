/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

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
#include "AbstractTbSame1SameStruct1Interface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbSame1SameStruct1InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSame1SameStruct1InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTbSame1SameStruct1Interface::UAbstractTbSame1SameStruct1Interface()
{
	TbSame1SameStruct1InterfaceSignals = NewObject<UTbSame1SameStruct1InterfaceSignals>();
}

FTbSame1Struct1 UAbstractTbSame1SameStruct1Interface::GetProp1_Private() const
{
	return Execute_GetProp1(this);
};

void UAbstractTbSame1SameStruct1Interface::SetProp1_Private(const FTbSame1Struct1& InProp1)
{
	Execute_SetProp1(this, InProp1);
};
void UAbstractTbSame1SameStruct1Interface::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameStruct1InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameStruct1InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame1SameStruct1InterfaceLatentAction* CompletionAction = new FTbSame1SameStruct1InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Func1(this, Param1);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::Thread,
				[Param1, this, &Result, CompletionAction]()
				{
					Result = Execute_Func1(this, Param1);
					CompletionAction->Cancel();
				});
		}
	}
}

void UAbstractTbSame1SameStruct1Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSame1SameStruct1Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSame1SameStruct1InterfaceSignals)
	{
		TbSame1SameStruct1InterfaceSignals->OnSig1Signal.RemoveAll(TbSame1SameStruct1InterfaceSignals);

		TbSame1SameStruct1InterfaceSignals->OnProp1Changed.RemoveAll(TbSame1SameStruct1InterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTbSame1SameStruct1Interface::IsInitialized() const
{
	return bInitialized;
}
