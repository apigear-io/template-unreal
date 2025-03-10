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
#include "Testbed1/Generated/api/AbstractTestbed1StructInterface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTestbed1StructInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed1StructInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTestbed1StructInterface::UAbstractTestbed1StructInterface()
{
	Testbed1StructInterfaceSignals = NewObject<UTestbed1StructInterfaceSignals>();
}

UTestbed1StructInterfaceSignals* UAbstractTestbed1StructInterface::_GetSignals()
{
	if (!Testbed1StructInterfaceSignals)
	{
		Testbed1StructInterfaceSignals = NewObject<UTestbed1StructInterfaceSignals>();
	}
	return Testbed1StructInterfaceSignals;
}

FTestbed1StructBool UAbstractTestbed1StructInterface::GetPropBool_Private() const
{
	return GetPropBool();
};

void UAbstractTestbed1StructInterface::SetPropBool_Private(const FTestbed1StructBool& InPropBool)
{
	SetPropBool(InPropBool);
};

FTestbed1StructInt UAbstractTestbed1StructInterface::GetPropInt_Private() const
{
	return GetPropInt();
};

void UAbstractTestbed1StructInterface::SetPropInt_Private(const FTestbed1StructInt& InPropInt)
{
	SetPropInt(InPropInt);
};

FTestbed1StructFloat UAbstractTestbed1StructInterface::GetPropFloat_Private() const
{
	return GetPropFloat();
};

void UAbstractTestbed1StructInterface::SetPropFloat_Private(const FTestbed1StructFloat& InPropFloat)
{
	SetPropFloat(InPropFloat);
};

FTestbed1StructString UAbstractTestbed1StructInterface::GetPropString_Private() const
{
	return GetPropString();
};

void UAbstractTestbed1StructInterface::SetPropString_Private(const FTestbed1StructString& InPropString)
{
	SetPropString(InPropString);
};

void UAbstractTestbed1StructInterface::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructInterfaceLatentAction* CompletionAction = new FTestbed1StructInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = FuncBool(ParamBool);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamBool, this, &Result, CompletionAction]()
				{
				Result = FuncBool(ParamBool);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTestbed1StructInterface::FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructInt& Result, const FTestbed1StructInt& ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructInterfaceLatentAction* CompletionAction = new FTestbed1StructInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = FuncInt(ParamInt);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamInt, this, &Result, CompletionAction]()
				{
				Result = FuncInt(ParamInt);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTestbed1StructInterface::FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructInterfaceLatentAction* CompletionAction = new FTestbed1StructInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = FuncFloat(ParamFloat);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamFloat, this, &Result, CompletionAction]()
				{
				Result = FuncFloat(ParamFloat);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTestbed1StructInterface::FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructInterfaceLatentAction* CompletionAction = new FTestbed1StructInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = FuncString(ParamString);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamString, this, &Result, CompletionAction]()
				{
				Result = FuncString(ParamString);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTestbed1StructInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed1StructInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (Testbed1StructInterfaceSignals)
	{
		Testbed1StructInterfaceSignals->OnSigBoolSignal.RemoveAll(Testbed1StructInterfaceSignals);
		Testbed1StructInterfaceSignals->OnSigBoolSignalBP.RemoveAll(Testbed1StructInterfaceSignals);
		Testbed1StructInterfaceSignals->OnSigIntSignal.RemoveAll(Testbed1StructInterfaceSignals);
		Testbed1StructInterfaceSignals->OnSigIntSignalBP.RemoveAll(Testbed1StructInterfaceSignals);
		Testbed1StructInterfaceSignals->OnSigFloatSignal.RemoveAll(Testbed1StructInterfaceSignals);
		Testbed1StructInterfaceSignals->OnSigFloatSignalBP.RemoveAll(Testbed1StructInterfaceSignals);
		Testbed1StructInterfaceSignals->OnSigStringSignal.RemoveAll(Testbed1StructInterfaceSignals);
		Testbed1StructInterfaceSignals->OnSigStringSignalBP.RemoveAll(Testbed1StructInterfaceSignals);

		Testbed1StructInterfaceSignals->OnPropBoolChanged.RemoveAll(Testbed1StructInterfaceSignals);
		Testbed1StructInterfaceSignals->OnPropBoolChangedBP.RemoveAll(Testbed1StructInterfaceSignals);
		Testbed1StructInterfaceSignals->OnPropIntChanged.RemoveAll(Testbed1StructInterfaceSignals);
		Testbed1StructInterfaceSignals->OnPropIntChangedBP.RemoveAll(Testbed1StructInterfaceSignals);
		Testbed1StructInterfaceSignals->OnPropFloatChanged.RemoveAll(Testbed1StructInterfaceSignals);
		Testbed1StructInterfaceSignals->OnPropFloatChangedBP.RemoveAll(Testbed1StructInterfaceSignals);
		Testbed1StructInterfaceSignals->OnPropStringChanged.RemoveAll(Testbed1StructInterfaceSignals);
		Testbed1StructInterfaceSignals->OnPropStringChangedBP.RemoveAll(Testbed1StructInterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTestbed1StructInterface::IsInitialized() const
{
	return bInitialized;
}
