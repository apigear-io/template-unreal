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
#include "TbSame2/Generated/api/AbstractTbSame2SameStruct1Interface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbSame2SameStruct1InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSame2SameStruct1InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTbSame2SameStruct1Interface::UAbstractTbSame2SameStruct1Interface()
{
	TbSame2SameStruct1InterfacePublisher = NewObject<UTbSame2SameStruct1InterfacePublisher>();
}

UTbSame2SameStruct1InterfacePublisher* UAbstractTbSame2SameStruct1Interface::_GetPublisher()
{
	if (!TbSame2SameStruct1InterfacePublisher)
	{
		TbSame2SameStruct1InterfacePublisher = NewObject<UTbSame2SameStruct1InterfacePublisher>();
	}
	return TbSame2SameStruct1InterfacePublisher;
}

FTbSame2Struct1 UAbstractTbSame2SameStruct1Interface::GetProp1_Private() const
{
	return GetProp1();
};

void UAbstractTbSame2SameStruct1Interface::SetProp1_Private(const FTbSame2Struct1& InProp1)
{
	SetProp1(InProp1);
};

void UAbstractTbSame2SameStruct1Interface::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameStruct1InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameStruct1InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame2SameStruct1InterfaceLatentAction* CompletionAction = new FTbSame2SameStruct1InterfaceLatentAction(LatentInfo);
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

void UAbstractTbSame2SameStruct1Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSame2SameStruct1Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSame2SameStruct1InterfacePublisher)
	{
		TbSame2SameStruct1InterfacePublisher->OnSig1Signal.RemoveAll(TbSame2SameStruct1InterfacePublisher);
		TbSame2SameStruct1InterfacePublisher->OnSig1SignalBP.RemoveAll(TbSame2SameStruct1InterfacePublisher);

		TbSame2SameStruct1InterfacePublisher->OnProp1Changed.RemoveAll(TbSame2SameStruct1InterfacePublisher);
		TbSame2SameStruct1InterfacePublisher->OnProp1ChangedBP.RemoveAll(TbSame2SameStruct1InterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbSame2SameStruct1Interface::IsInitialized() const
{
	return bInitialized;
}
