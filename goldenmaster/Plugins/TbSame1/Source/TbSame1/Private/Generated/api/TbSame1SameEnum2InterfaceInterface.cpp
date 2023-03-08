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
#include "TbSame1SameEnum2InterfaceInterface.h"
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

FTbSame1SameEnum2InterfaceSig1Delegate& UAbstractTbSame1SameEnum2Interface::GetSig1SignalDelegate()
{
	return Sig1Signal;
};

void UAbstractTbSame1SameEnum2Interface::BroadcastSig1_Implementation(ETbSame1Enum1 Param1)
{
	Sig1Signal.Broadcast(Param1);
};

FTbSame1SameEnum2InterfaceSig2Delegate& UAbstractTbSame1SameEnum2Interface::GetSig2SignalDelegate()
{
	return Sig2Signal;
};

void UAbstractTbSame1SameEnum2Interface::BroadcastSig2_Implementation(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
};

FTbSame1SameEnum2InterfaceProp1ChangedDelegate& UAbstractTbSame1SameEnum2Interface::GetProp1ChangedDelegate()
{
	return Prop1Changed;
};

void UAbstractTbSame1SameEnum2Interface::BroadcastProp1Changed_Implementation(ETbSame1Enum1 InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

ETbSame1Enum1 UAbstractTbSame1SameEnum2Interface::GetProp1_Private() const
{
	return Execute_GetProp1(this);
};

void UAbstractTbSame1SameEnum2Interface::SetProp1_Private(ETbSame1Enum1 InProp1)
{
	Execute_SetProp1(this, InProp1);
};

FTbSame1SameEnum2InterfaceProp2ChangedDelegate& UAbstractTbSame1SameEnum2Interface::GetProp2ChangedDelegate()
{
	return Prop2Changed;
};

void UAbstractTbSame1SameEnum2Interface::BroadcastProp2Changed_Implementation(ETbSame1Enum2 InProp2)
{
	Prop2Changed.Broadcast(InProp2);
}

ETbSame1Enum2 UAbstractTbSame1SameEnum2Interface::GetProp2_Private() const
{
	return Execute_GetProp2(this);
};

void UAbstractTbSame1SameEnum2Interface::SetProp2_Private(ETbSame1Enum2 InProp2)
{
	Execute_SetProp2(this, InProp2);
};
void UAbstractTbSame1SameEnum2Interface::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1)
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
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = Execute_Func1(this, Param1);
				CompletionAction->Cancel();
			});
	}
}

void UAbstractTbSame1SameEnum2Interface::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
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
		Async(EAsyncExecution::Thread,
			[Param1, Param2, this, &Result, CompletionAction]()
			{
				Result = Execute_Func2(this, Param1, Param2);
				CompletionAction->Cancel();
			});
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

	Super::Deinitialize();
}

bool UAbstractTbSame1SameEnum2Interface::IsInitialized() const
{
	return bInitialized;
}
