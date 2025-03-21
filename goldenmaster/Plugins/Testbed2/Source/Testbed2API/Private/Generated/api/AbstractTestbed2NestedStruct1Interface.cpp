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
#include "Testbed2/Generated/api/AbstractTestbed2NestedStruct1Interface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTestbed2NestedStruct1InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed2NestedStruct1InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTestbed2NestedStruct1Interface::UAbstractTestbed2NestedStruct1Interface()
{
	Testbed2NestedStruct1InterfaceSignals = NewObject<UTestbed2NestedStruct1InterfaceSignals>();
}

UTestbed2NestedStruct1InterfaceSignals* UAbstractTestbed2NestedStruct1Interface::_GetSignals()
{
	if (!Testbed2NestedStruct1InterfaceSignals)
	{
		Testbed2NestedStruct1InterfaceSignals = NewObject<UTestbed2NestedStruct1InterfaceSignals>();
	}
	return Testbed2NestedStruct1InterfaceSignals;
}

FTestbed2NestedStruct1 UAbstractTestbed2NestedStruct1Interface::GetProp1_Private() const
{
	return GetProp1();
};

void UAbstractTestbed2NestedStruct1Interface::SetProp1_Private(const FTestbed2NestedStruct1& InProp1)
{
	SetProp1(InProp1);
};

void UAbstractTestbed2NestedStruct1Interface::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct1InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct1InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2NestedStruct1InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct1InterfaceLatentAction(LatentInfo);
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

void UAbstractTestbed2NestedStruct1Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed2NestedStruct1Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (Testbed2NestedStruct1InterfaceSignals)
	{
		Testbed2NestedStruct1InterfaceSignals->OnSig1Signal.RemoveAll(Testbed2NestedStruct1InterfaceSignals);
		Testbed2NestedStruct1InterfaceSignals->OnSig1SignalBP.RemoveAll(Testbed2NestedStruct1InterfaceSignals);

		Testbed2NestedStruct1InterfaceSignals->OnProp1Changed.RemoveAll(Testbed2NestedStruct1InterfaceSignals);
		Testbed2NestedStruct1InterfaceSignals->OnProp1ChangedBP.RemoveAll(Testbed2NestedStruct1InterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTestbed2NestedStruct1Interface::IsInitialized() const
{
	return bInitialized;
}
