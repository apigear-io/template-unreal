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
#include "Testbed2/Generated/api/AbstractTestbed2ManyParamInterface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTestbed2ManyParamInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed2ManyParamInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTestbed2ManyParamInterface::UAbstractTestbed2ManyParamInterface()
{
	Testbed2ManyParamInterfaceSignals = NewObject<UTestbed2ManyParamInterfaceSignals>();
}

UTestbed2ManyParamInterfaceSignals* UAbstractTestbed2ManyParamInterface::_GetSignals_Implementation()
{
	if (!Testbed2ManyParamInterfaceSignals)
	{
		Testbed2ManyParamInterfaceSignals = NewObject<UTestbed2ManyParamInterfaceSignals>();
	}
	return Testbed2ManyParamInterfaceSignals;
}

int32 UAbstractTestbed2ManyParamInterface::GetProp1_Private() const
{
	return Execute_GetProp1(this);
};

void UAbstractTestbed2ManyParamInterface::SetProp1_Private(int32 InProp1)
{
	Execute_SetProp1(this, InProp1);
};

int32 UAbstractTestbed2ManyParamInterface::GetProp2_Private() const
{
	return Execute_GetProp2(this);
};

void UAbstractTestbed2ManyParamInterface::SetProp2_Private(int32 InProp2)
{
	Execute_SetProp2(this, InProp2);
};

int32 UAbstractTestbed2ManyParamInterface::GetProp3_Private() const
{
	return Execute_GetProp3(this);
};

void UAbstractTestbed2ManyParamInterface::SetProp3_Private(int32 InProp3)
{
	Execute_SetProp3(this, InProp3);
};

int32 UAbstractTestbed2ManyParamInterface::GetProp4_Private() const
{
	return Execute_GetProp4(this);
};

void UAbstractTestbed2ManyParamInterface::SetProp4_Private(int32 InProp4)
{
	Execute_SetProp4(this, InProp4);
};

void UAbstractTestbed2ManyParamInterface::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2ManyParamInterfaceLatentAction* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction(LatentInfo);
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

void UAbstractTestbed2ManyParamInterface::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2ManyParamInterfaceLatentAction* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction(LatentInfo);
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

void UAbstractTestbed2ManyParamInterface::Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2ManyParamInterfaceLatentAction* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Func3(this, Param1, Param2, Param3);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param1, Param2, Param3, this, &Result, CompletionAction]()
				{
				Result = Execute_Func3(this, Param1, Param2, Param3);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTestbed2ManyParamInterface::Func4Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2ManyParamInterfaceLatentAction* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Func4(this, Param1, Param2, Param3, Param4);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[Param1, Param2, Param3, Param4, this, &Result, CompletionAction]()
				{
				Result = Execute_Func4(this, Param1, Param2, Param3, Param4);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTestbed2ManyParamInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed2ManyParamInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (Testbed2ManyParamInterfaceSignals)
	{
		Testbed2ManyParamInterfaceSignals->OnSig1Signal.RemoveAll(Testbed2ManyParamInterfaceSignals);
		Testbed2ManyParamInterfaceSignals->OnSig2Signal.RemoveAll(Testbed2ManyParamInterfaceSignals);
		Testbed2ManyParamInterfaceSignals->OnSig3Signal.RemoveAll(Testbed2ManyParamInterfaceSignals);
		Testbed2ManyParamInterfaceSignals->OnSig4Signal.RemoveAll(Testbed2ManyParamInterfaceSignals);

		Testbed2ManyParamInterfaceSignals->OnProp1Changed.RemoveAll(Testbed2ManyParamInterfaceSignals);
		Testbed2ManyParamInterfaceSignals->OnProp2Changed.RemoveAll(Testbed2ManyParamInterfaceSignals);
		Testbed2ManyParamInterfaceSignals->OnProp3Changed.RemoveAll(Testbed2ManyParamInterfaceSignals);
		Testbed2ManyParamInterfaceSignals->OnProp4Changed.RemoveAll(Testbed2ManyParamInterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTestbed2ManyParamInterface::IsInitialized() const
{
	return bInitialized;
}
