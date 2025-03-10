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
#include "TbSimple/Generated/api/AbstractTbSimpleNoPropertiesInterface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbSimpleNoPropertiesInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSimpleNoPropertiesInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTbSimpleNoPropertiesInterface::UAbstractTbSimpleNoPropertiesInterface()
{
	TbSimpleNoPropertiesInterfaceSignals = NewObject<UTbSimpleNoPropertiesInterfaceSignals>();
}

UTbSimpleNoPropertiesInterfaceSignals* UAbstractTbSimpleNoPropertiesInterface::_GetSignals()
{
	if (!TbSimpleNoPropertiesInterfaceSignals)
	{
		TbSimpleNoPropertiesInterfaceSignals = NewObject<UTbSimpleNoPropertiesInterfaceSignals>();
	}
	return TbSimpleNoPropertiesInterfaceSignals;
}

void UAbstractTbSimpleNoPropertiesInterface::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleNoPropertiesInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleNoPropertiesInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleNoPropertiesInterfaceLatentAction* CompletionAction = new FTbSimpleNoPropertiesInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = FuncBool(bParamBool);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[bParamBool, this, &Result, CompletionAction]()
				{
				Result = FuncBool(bParamBool);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSimpleNoPropertiesInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSimpleNoPropertiesInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSimpleNoPropertiesInterfaceSignals)
	{
		TbSimpleNoPropertiesInterfaceSignals->OnSigVoidSignal.RemoveAll(TbSimpleNoPropertiesInterfaceSignals);
		TbSimpleNoPropertiesInterfaceSignals->OnSigBoolSignal.RemoveAll(TbSimpleNoPropertiesInterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTbSimpleNoPropertiesInterface::IsInitialized() const
{
	return bInitialized;
}
