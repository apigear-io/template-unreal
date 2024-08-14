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
#include "AbstractTbSimpleSimpleArrayInterface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbSimpleSimpleArrayInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSimpleSimpleArrayInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTbSimpleSimpleArrayInterface::UAbstractTbSimpleSimpleArrayInterface()
{
	TbSimpleSimpleArrayInterfaceSignals = NewObject<UTbSimpleSimpleArrayInterfaceSignals>();
}

UTbSimpleSimpleArrayInterfaceSignals* UAbstractTbSimpleSimpleArrayInterface::_GetSignals_Implementation()
{
	if (!TbSimpleSimpleArrayInterfaceSignals)
	{
		TbSimpleSimpleArrayInterfaceSignals = NewObject<UTbSimpleSimpleArrayInterfaceSignals>();
	}
	return TbSimpleSimpleArrayInterfaceSignals;
}

TArray<bool> UAbstractTbSimpleSimpleArrayInterface::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropBool_Private(const TArray<bool>& InPropBool)
{
	Execute_SetPropBool(this, InPropBool);
};

TArray<int32> UAbstractTbSimpleSimpleArrayInterface::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropInt_Private(const TArray<int32>& InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
};

TArray<int32> UAbstractTbSimpleSimpleArrayInterface::GetPropInt32_Private() const
{
	return Execute_GetPropInt32(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropInt32_Private(const TArray<int32>& InPropInt32)
{
	Execute_SetPropInt32(this, InPropInt32);
};

TArray<int64> UAbstractTbSimpleSimpleArrayInterface::GetPropInt64_Private() const
{
	return Execute_GetPropInt64(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropInt64_Private(const TArray<int64>& InPropInt64)
{
	Execute_SetPropInt64(this, InPropInt64);
};

TArray<float> UAbstractTbSimpleSimpleArrayInterface::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropFloat_Private(const TArray<float>& InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
};

TArray<float> UAbstractTbSimpleSimpleArrayInterface::GetPropFloat32_Private() const
{
	return Execute_GetPropFloat32(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropFloat32_Private(const TArray<float>& InPropFloat32)
{
	Execute_SetPropFloat32(this, InPropFloat32);
};

TArray<double> UAbstractTbSimpleSimpleArrayInterface::GetPropFloat64_Private() const
{
	return Execute_GetPropFloat64(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropFloat64_Private(const TArray<double>& InPropFloat64)
{
	Execute_SetPropFloat64(this, InPropFloat64);
};

TArray<FString> UAbstractTbSimpleSimpleArrayInterface::GetPropString_Private() const
{
	return Execute_GetPropString(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropString_Private(const TArray<FString>& InPropString)
{
	Execute_SetPropString(this, InPropString);
};

FString UAbstractTbSimpleSimpleArrayInterface::GetPropReadOnlyString_Private() const
{
	return Execute_GetPropReadOnlyString(this);
};

void UAbstractTbSimpleSimpleArrayInterface::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncBool(this, ParamBool);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::Thread,
				[ParamBool, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncBool(this, ParamBool);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSimpleSimpleArrayInterface::FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncInt(this, ParamInt);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::Thread,
				[ParamInt, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncInt(this, ParamInt);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSimpleSimpleArrayInterface::FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncInt32(this, ParamInt32);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::Thread,
				[ParamInt32, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncInt32(this, ParamInt32);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSimpleSimpleArrayInterface::FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncInt64(this, ParamInt64);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::Thread,
				[ParamInt64, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncInt64(this, ParamInt64);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSimpleSimpleArrayInterface::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncFloat(this, ParamFloat);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::Thread,
				[ParamFloat, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncFloat(this, ParamFloat);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSimpleSimpleArrayInterface::FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncFloat32(this, ParamFloat32);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::Thread,
				[ParamFloat32, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncFloat32(this, ParamFloat32);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSimpleSimpleArrayInterface::FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncFloat64(this, ParamFloat);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::Thread,
				[ParamFloat, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncFloat64(this, ParamFloat);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSimpleSimpleArrayInterface::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncString(this, ParamString);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::Thread,
				[ParamString, this, &Result, CompletionAction]()
				{
				Result = Execute_FuncString(this, ParamString);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSimpleSimpleArrayInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSimpleSimpleArrayInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSimpleSimpleArrayInterfaceSignals)
	{
		TbSimpleSimpleArrayInterfaceSignals->OnSigBoolSignal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigIntSignal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigInt32Signal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigInt64Signal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloatSignal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloat32Signal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloat64Signal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigStringSignal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);

		TbSimpleSimpleArrayInterfaceSignals->OnPropBoolChanged.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropIntChanged.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt32Changed.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt64Changed.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloatChanged.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat32Changed.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat64Changed.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropStringChanged.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropReadOnlyStringChanged.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTbSimpleSimpleArrayInterface::IsInitialized() const
{
	return bInitialized;
}
