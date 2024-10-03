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
#include "TbSimple/Generated/api/AbstractTbSimpleNoSignalsInterface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbSimpleNoSignalsInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSimpleNoSignalsInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTbSimpleNoSignalsInterface::UAbstractTbSimpleNoSignalsInterface()
{
	TbSimpleNoSignalsInterfaceSignals = NewObject<UTbSimpleNoSignalsInterfaceSignals>();
}

UTbSimpleNoSignalsInterfaceSignals* UAbstractTbSimpleNoSignalsInterface::_GetSignals_Implementation()
{
	if (!TbSimpleNoSignalsInterfaceSignals)
	{
		TbSimpleNoSignalsInterfaceSignals = NewObject<UTbSimpleNoSignalsInterfaceSignals>();
	}
	return TbSimpleNoSignalsInterfaceSignals;
}

bool UAbstractTbSimpleNoSignalsInterface::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
};

void UAbstractTbSimpleNoSignalsInterface::SetPropBool_Private(bool bInPropBool)
{
	Execute_SetPropBool(this, bInPropBool);
};

int32 UAbstractTbSimpleNoSignalsInterface::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
};

void UAbstractTbSimpleNoSignalsInterface::SetPropInt_Private(int32 InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
};

void UAbstractTbSimpleNoSignalsInterface::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleNoSignalsInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleNoSignalsInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleNoSignalsInterfaceLatentAction* CompletionAction = new FTbSimpleNoSignalsInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncBool(this, bParamBool);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[bParamBool, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncBool(this, bParamBool);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSimpleNoSignalsInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSimpleNoSignalsInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSimpleNoSignalsInterfaceSignals)
	{
		TbSimpleNoSignalsInterfaceSignals->OnPropBoolChanged.RemoveAll(TbSimpleNoSignalsInterfaceSignals);
		TbSimpleNoSignalsInterfaceSignals->OnPropIntChanged.RemoveAll(TbSimpleNoSignalsInterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTbSimpleNoSignalsInterface::IsInitialized() const
{
	return bInitialized;
}
