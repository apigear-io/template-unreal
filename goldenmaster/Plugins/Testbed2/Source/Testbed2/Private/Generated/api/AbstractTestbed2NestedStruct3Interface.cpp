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
#include "AbstractTestbed2NestedStruct3Interface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTestbed2NestedStruct3InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed2NestedStruct3InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTestbed2NestedStruct3Interface::UAbstractTestbed2NestedStruct3Interface()
{
	Testbed2NestedStruct3InterfaceSignals = NewObject<UTestbed2NestedStruct3InterfaceSignals>();
}

UTestbed2NestedStruct3InterfaceSignals* UAbstractTestbed2NestedStruct3Interface::_GetSignals_Implementation()
{
	if (!Testbed2NestedStruct3InterfaceSignals)
	{
		Testbed2NestedStruct3InterfaceSignals = NewObject<UTestbed2NestedStruct3InterfaceSignals>();
	}
	return Testbed2NestedStruct3InterfaceSignals;
}

FTestbed2NestedStruct1 UAbstractTestbed2NestedStruct3Interface::GetProp1_Private() const
{
	return Execute_GetProp1(this);
};

void UAbstractTestbed2NestedStruct3Interface::SetProp1_Private(const FTestbed2NestedStruct1& InProp1)
{
	Execute_SetProp1(this, InProp1);
};

FTestbed2NestedStruct2 UAbstractTestbed2NestedStruct3Interface::GetProp2_Private() const
{
	return Execute_GetProp2(this);
};

void UAbstractTestbed2NestedStruct3Interface::SetProp2_Private(const FTestbed2NestedStruct2& InProp2)
{
	Execute_SetProp2(this, InProp2);
};

FTestbed2NestedStruct3 UAbstractTestbed2NestedStruct3Interface::GetProp3_Private() const
{
	return Execute_GetProp3(this);
};

void UAbstractTestbed2NestedStruct3Interface::SetProp3_Private(const FTestbed2NestedStruct3& InProp3)
{
	Execute_SetProp3(this, InProp3);
};
void UAbstractTestbed2NestedStruct3Interface::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct3InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct3InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2NestedStruct3InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct3InterfaceLatentAction(LatentInfo);
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

void UAbstractTestbed2NestedStruct3Interface::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct3InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct3InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2NestedStruct3InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct3InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Func2(this, Param1, Param2);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::Thread,
				[Param1, Param2, this, &Result, CompletionAction]()
				{
					Result = Execute_Func2(this, Param1, Param2);
					CompletionAction->Cancel();
				});
		}
	}
}

void UAbstractTestbed2NestedStruct3Interface::Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct3InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct3InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2NestedStruct3InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct3InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_Func3(this, Param1, Param2, Param3);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::Thread,
				[Param1, Param2, Param3, this, &Result, CompletionAction]()
				{
					Result = Execute_Func3(this, Param1, Param2, Param3);
					CompletionAction->Cancel();
				});
		}
	}
}

void UAbstractTestbed2NestedStruct3Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed2NestedStruct3Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (Testbed2NestedStruct3InterfaceSignals)
	{
		Testbed2NestedStruct3InterfaceSignals->OnSig1Signal.RemoveAll(Testbed2NestedStruct3InterfaceSignals);
		Testbed2NestedStruct3InterfaceSignals->OnSig2Signal.RemoveAll(Testbed2NestedStruct3InterfaceSignals);
		Testbed2NestedStruct3InterfaceSignals->OnSig3Signal.RemoveAll(Testbed2NestedStruct3InterfaceSignals);

		Testbed2NestedStruct3InterfaceSignals->OnProp1Changed.RemoveAll(Testbed2NestedStruct3InterfaceSignals);
		Testbed2NestedStruct3InterfaceSignals->OnProp2Changed.RemoveAll(Testbed2NestedStruct3InterfaceSignals);
		Testbed2NestedStruct3InterfaceSignals->OnProp3Changed.RemoveAll(Testbed2NestedStruct3InterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTestbed2NestedStruct3Interface::IsInitialized() const
{
	return bInitialized;
}
