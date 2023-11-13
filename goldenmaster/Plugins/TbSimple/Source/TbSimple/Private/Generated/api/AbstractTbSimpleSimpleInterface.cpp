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
#include "AbstractTbSimpleSimpleInterface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbSimpleSimpleInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSimpleSimpleInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTbSimpleSimpleInterface::UAbstractTbSimpleSimpleInterface()
{
	TbSimpleSimpleInterfaceSignals = NewObject<UTbSimpleSimpleInterfaceSignals>();
}

UTbSimpleSimpleInterfaceSignals* UAbstractTbSimpleSimpleInterface::_GetSignals_Implementation()
{
	if (!TbSimpleSimpleInterfaceSignals)
	{
		TbSimpleSimpleInterfaceSignals = NewObject<UTbSimpleSimpleInterfaceSignals>();
	}
	return TbSimpleSimpleInterfaceSignals;
}

bool UAbstractTbSimpleSimpleInterface::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropBool_Private(bool bInPropBool)
{
	Execute_SetPropBool(this, bInPropBool);
};

int32 UAbstractTbSimpleSimpleInterface::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropInt_Private(int32 InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
};

int32 UAbstractTbSimpleSimpleInterface::GetPropInt32_Private() const
{
	return Execute_GetPropInt32(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropInt32_Private(int32 InPropInt32)
{
	Execute_SetPropInt32(this, InPropInt32);
};

int64 UAbstractTbSimpleSimpleInterface::GetPropInt64_Private() const
{
	return Execute_GetPropInt64(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropInt64_Private(int64 InPropInt64)
{
	Execute_SetPropInt64(this, InPropInt64);
};

float UAbstractTbSimpleSimpleInterface::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropFloat_Private(float InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
};

float UAbstractTbSimpleSimpleInterface::GetPropFloat32_Private() const
{
	return Execute_GetPropFloat32(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropFloat32_Private(float InPropFloat32)
{
	Execute_SetPropFloat32(this, InPropFloat32);
};

double UAbstractTbSimpleSimpleInterface::GetPropFloat64_Private() const
{
	return Execute_GetPropFloat64(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropFloat64_Private(double InPropFloat64)
{
	Execute_SetPropFloat64(this, InPropFloat64);
};

FString UAbstractTbSimpleSimpleInterface::GetPropString_Private() const
{
	return Execute_GetPropString(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropString_Private(const FString& InPropString)
{
	Execute_SetPropString(this, InPropString);
};

FString UAbstractTbSimpleSimpleInterface::GetPropReadOnlyString_Private() const
{
	return Execute_GetPropReadOnlyString(this);
};

void UAbstractTbSimpleSimpleInterface::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);

		// If this class is a BP based implementation it has to be running within the game thread - we cannot fork
		if (this->GetClass()->IsInBlueprint())
		{
			Result = Execute_FuncBool(this, bParamBool);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::Thread,
				[bParamBool, this, &Result, CompletionAction]()
				{
					Result = Execute_FuncBool(this, bParamBool);
					CompletionAction->Cancel();
				});
		}
	}
}

void UAbstractTbSimpleSimpleInterface::FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction(LatentInfo);
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

void UAbstractTbSimpleSimpleInterface::FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt32)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction(LatentInfo);
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

void UAbstractTbSimpleSimpleInterface::FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int64& Result, int64 ParamInt64)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction(LatentInfo);
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

void UAbstractTbSimpleSimpleInterface::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction(LatentInfo);
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

void UAbstractTbSimpleSimpleInterface::FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat32)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction(LatentInfo);
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

void UAbstractTbSimpleSimpleInterface::FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, double& Result, double ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction(LatentInfo);
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

void UAbstractTbSimpleSimpleInterface::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction(LatentInfo);
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

void UAbstractTbSimpleSimpleInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSimpleSimpleInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSimpleSimpleInterfaceSignals)
	{
		TbSimpleSimpleInterfaceSignals->OnSigVoidSignal.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnSigBoolSignal.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnSigIntSignal.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnSigInt32Signal.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnSigInt64Signal.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnSigFloatSignal.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnSigFloat32Signal.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnSigFloat64Signal.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnSigStringSignal.RemoveAll(TbSimpleSimpleInterfaceSignals);

		TbSimpleSimpleInterfaceSignals->OnPropBoolChanged.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnPropIntChanged.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnPropInt32Changed.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnPropInt64Changed.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnPropFloatChanged.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnPropFloat32Changed.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnPropFloat64Changed.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnPropStringChanged.RemoveAll(TbSimpleSimpleInterfaceSignals);
		TbSimpleSimpleInterfaceSignals->OnPropReadOnlyStringChanged.RemoveAll(TbSimpleSimpleInterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTbSimpleSimpleInterface::IsInitialized() const
{
	return bInitialized;
}
