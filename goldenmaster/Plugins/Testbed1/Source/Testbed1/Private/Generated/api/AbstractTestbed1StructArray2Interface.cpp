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
#include "Generated/api/AbstractTestbed1StructArray2Interface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTestbed1StructArray2InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed1StructArray2InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTestbed1StructArray2Interface::UAbstractTestbed1StructArray2Interface()
{
	Testbed1StructArray2InterfaceSignals = NewObject<UTestbed1StructArray2InterfaceSignals>();
}

UTestbed1StructArray2InterfaceSignals* UAbstractTestbed1StructArray2Interface::_GetSignals_Implementation()
{
	if (!Testbed1StructArray2InterfaceSignals)
	{
		Testbed1StructArray2InterfaceSignals = NewObject<UTestbed1StructArray2InterfaceSignals>();
	}
	return Testbed1StructArray2InterfaceSignals;
}

FTestbed1StructBoolWithArray UAbstractTestbed1StructArray2Interface::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
};

void UAbstractTestbed1StructArray2Interface::SetPropBool_Private(const FTestbed1StructBoolWithArray& InPropBool)
{
	Execute_SetPropBool(this, InPropBool);
};

FTestbed1StructIntWithArray UAbstractTestbed1StructArray2Interface::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
};

void UAbstractTestbed1StructArray2Interface::SetPropInt_Private(const FTestbed1StructIntWithArray& InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
};

FTestbed1StructFloatWithArray UAbstractTestbed1StructArray2Interface::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
};

void UAbstractTestbed1StructArray2Interface::SetPropFloat_Private(const FTestbed1StructFloatWithArray& InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
};

FTestbed1StructStringWithArray UAbstractTestbed1StructArray2Interface::GetPropString_Private() const
{
	return Execute_GetPropString(this);
};

void UAbstractTestbed1StructArray2Interface::SetPropString_Private(const FTestbed1StructStringWithArray& InPropString)
{
	Execute_SetPropString(this, InPropString);
};

FTestbed1StructEnumWithArray UAbstractTestbed1StructArray2Interface::GetPropEnum_Private() const
{
	return Execute_GetPropEnum(this);
};

void UAbstractTestbed1StructArray2Interface::SetPropEnum_Private(const FTestbed1StructEnumWithArray& InPropEnum)
{
	Execute_SetPropEnum(this, InPropEnum);
};

void UAbstractTestbed1StructArray2Interface::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructBool>& Result, const FTestbed1StructBoolWithArray& ParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructArray2InterfaceLatentAction* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction(LatentInfo);
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

void UAbstractTestbed1StructArray2Interface::FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructInt>& Result, const FTestbed1StructIntWithArray& ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructArray2InterfaceLatentAction* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction(LatentInfo);
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

void UAbstractTestbed1StructArray2Interface::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructFloat>& Result, const FTestbed1StructFloatWithArray& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructArray2InterfaceLatentAction* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction(LatentInfo);
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

void UAbstractTestbed1StructArray2Interface::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructString>& Result, const FTestbed1StructStringWithArray& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructArray2InterfaceLatentAction* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction(LatentInfo);
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

void UAbstractTestbed1StructArray2Interface::FuncEnumAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<ETestbed1Enum0>& Result, const FTestbed1StructEnumWithArray& ParamEnum)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArray2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArray2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructArray2InterfaceLatentAction* CompletionAction = new FTestbed1StructArray2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncEnum(this, ParamEnum);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamEnum, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncEnum(this, ParamEnum);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTestbed1StructArray2Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed1StructArray2Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (Testbed1StructArray2InterfaceSignals)
	{
		Testbed1StructArray2InterfaceSignals->OnSigBoolSignal.RemoveAll(Testbed1StructArray2InterfaceSignals);
		Testbed1StructArray2InterfaceSignals->OnSigIntSignal.RemoveAll(Testbed1StructArray2InterfaceSignals);
		Testbed1StructArray2InterfaceSignals->OnSigFloatSignal.RemoveAll(Testbed1StructArray2InterfaceSignals);
		Testbed1StructArray2InterfaceSignals->OnSigStringSignal.RemoveAll(Testbed1StructArray2InterfaceSignals);

		Testbed1StructArray2InterfaceSignals->OnPropBoolChanged.RemoveAll(Testbed1StructArray2InterfaceSignals);
		Testbed1StructArray2InterfaceSignals->OnPropIntChanged.RemoveAll(Testbed1StructArray2InterfaceSignals);
		Testbed1StructArray2InterfaceSignals->OnPropFloatChanged.RemoveAll(Testbed1StructArray2InterfaceSignals);
		Testbed1StructArray2InterfaceSignals->OnPropStringChanged.RemoveAll(Testbed1StructArray2InterfaceSignals);
		Testbed1StructArray2InterfaceSignals->OnPropEnumChanged.RemoveAll(Testbed1StructArray2InterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTestbed1StructArray2Interface::IsInitialized() const
{
	return bInitialized;
}
