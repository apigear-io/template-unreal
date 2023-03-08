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
#include "TbSame2SameEnum1InterfaceInterface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbSame2SameEnum1InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSame2SameEnum1InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

FTbSame2SameEnum1InterfaceSig1Delegate& UAbstractTbSame2SameEnum1Interface::GetSig1SignalDelegate()
{
	return Sig1Signal;
};

void UAbstractTbSame2SameEnum1Interface::BroadcastSig1_Implementation(ETbSame2Enum1 Param1)
{
	Sig1Signal.Broadcast(Param1);
};

FTbSame2SameEnum1InterfaceProp1ChangedDelegate& UAbstractTbSame2SameEnum1Interface::GetProp1ChangedDelegate()
{
	return Prop1Changed;
};

void UAbstractTbSame2SameEnum1Interface::BroadcastProp1Changed_Implementation(ETbSame2Enum1 InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

ETbSame2Enum1 UAbstractTbSame2SameEnum1Interface::GetProp1_Private() const
{
	return Execute_GetProp1(this);
};

void UAbstractTbSame2SameEnum1Interface::SetProp1_Private(ETbSame2Enum1 InProp1)
{
	Execute_SetProp1(this, InProp1);
};
void UAbstractTbSame2SameEnum1Interface::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameEnum1InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameEnum1InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame2SameEnum1InterfaceLatentAction* CompletionAction = new FTbSame2SameEnum1InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = Execute_Func1(this, Param1);
				CompletionAction->Cancel();
			});
	}
}

void UAbstractTbSame2SameEnum1Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSame2SameEnum1Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	Super::Deinitialize();
}

bool UAbstractTbSame2SameEnum1Interface::IsInitialized() const
{
	return bInitialized;
}
