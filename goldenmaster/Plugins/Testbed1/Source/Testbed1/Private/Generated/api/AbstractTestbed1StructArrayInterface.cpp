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
#include "Generated/api/AbstractTestbed1StructArrayInterface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTestbed1StructArrayInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed1StructArrayInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTestbed1StructArrayInterface::UAbstractTestbed1StructArrayInterface()
{
	Testbed1StructArrayInterfaceSignals = NewObject<UTestbed1StructArrayInterfaceSignals>();
}

UTestbed1StructArrayInterfaceSignals* UAbstractTestbed1StructArrayInterface::_GetSignals_Implementation()
{
	if (!Testbed1StructArrayInterfaceSignals)
	{
		Testbed1StructArrayInterfaceSignals = NewObject<UTestbed1StructArrayInterfaceSignals>();
	}
	return Testbed1StructArrayInterfaceSignals;
}

TArray<FTestbed1StructBool> UAbstractTestbed1StructArrayInterface::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
};

void UAbstractTestbed1StructArrayInterface::SetPropBool_Private(const TArray<FTestbed1StructBool>& InPropBool)
{
	Execute_SetPropBool(this, InPropBool);
};

TArray<FTestbed1StructInt> UAbstractTestbed1StructArrayInterface::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
};

void UAbstractTestbed1StructArrayInterface::SetPropInt_Private(const TArray<FTestbed1StructInt>& InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
};

TArray<FTestbed1StructFloat> UAbstractTestbed1StructArrayInterface::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
};

void UAbstractTestbed1StructArrayInterface::SetPropFloat_Private(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
};

TArray<FTestbed1StructString> UAbstractTestbed1StructArrayInterface::GetPropString_Private() const
{
	return Execute_GetPropString(this);
};

void UAbstractTestbed1StructArrayInterface::SetPropString_Private(const TArray<FTestbed1StructString>& InPropString)
{
	Execute_SetPropString(this, InPropString);
};

void UAbstractTestbed1StructArrayInterface::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructBool>& Result, const TArray<FTestbed1StructBool>& ParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructArrayInterfaceLatentAction* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncBool(this, ParamBool);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamBool, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncBool(this, ParamBool);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTestbed1StructArrayInterface::FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructInt>& Result, const TArray<FTestbed1StructInt>& ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructArrayInterfaceLatentAction* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncInt(this, ParamInt);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamInt, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncInt(this, ParamInt);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTestbed1StructArrayInterface::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructFloat>& Result, const TArray<FTestbed1StructFloat>& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructArrayInterfaceLatentAction* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncFloat(this, ParamFloat);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamFloat, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncFloat(this, ParamFloat);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTestbed1StructArrayInterface::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructString>& Result, const TArray<FTestbed1StructString>& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructArrayInterfaceLatentAction* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncString(this, ParamString);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamString, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncString(this, ParamString);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTestbed1StructArrayInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed1StructArrayInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (Testbed1StructArrayInterfaceSignals)
	{
		Testbed1StructArrayInterfaceSignals->OnSigBoolSignal.RemoveAll(Testbed1StructArrayInterfaceSignals);
		Testbed1StructArrayInterfaceSignals->OnSigIntSignal.RemoveAll(Testbed1StructArrayInterfaceSignals);
		Testbed1StructArrayInterfaceSignals->OnSigFloatSignal.RemoveAll(Testbed1StructArrayInterfaceSignals);
		Testbed1StructArrayInterfaceSignals->OnSigStringSignal.RemoveAll(Testbed1StructArrayInterfaceSignals);

		Testbed1StructArrayInterfaceSignals->OnPropBoolChanged.RemoveAll(Testbed1StructArrayInterfaceSignals);
		Testbed1StructArrayInterfaceSignals->OnPropIntChanged.RemoveAll(Testbed1StructArrayInterfaceSignals);
		Testbed1StructArrayInterfaceSignals->OnPropFloatChanged.RemoveAll(Testbed1StructArrayInterfaceSignals);
		Testbed1StructArrayInterfaceSignals->OnPropStringChanged.RemoveAll(Testbed1StructArrayInterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTestbed1StructArrayInterface::IsInitialized() const
{
	return bInitialized;
}
