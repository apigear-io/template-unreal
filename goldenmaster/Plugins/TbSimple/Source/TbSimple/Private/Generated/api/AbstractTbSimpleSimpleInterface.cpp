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

FTbSimpleSimpleInterfaceSigVoidDelegate& UAbstractTbSimpleSimpleInterface::GetSigVoidSignalDelegate()
{
	return SigVoidSignal;
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigVoid_Implementation()
{
	SigVoidSignal.Broadcast();
};

FTbSimpleSimpleInterfaceSigBoolDelegate& UAbstractTbSimpleSimpleInterface::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigBool_Implementation(bool bParamBool)
{
	SigBoolSignal.Broadcast(bParamBool);
};

FTbSimpleSimpleInterfaceSigIntDelegate& UAbstractTbSimpleSimpleInterface::GetSigIntSignalDelegate()
{
	return SigIntSignal;
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigInt_Implementation(int32 ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
};

FTbSimpleSimpleInterfaceSigInt32Delegate& UAbstractTbSimpleSimpleInterface::GetSigInt32SignalDelegate()
{
	return SigInt32Signal;
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigInt32_Implementation(int32 ParamInt32)
{
	SigInt32Signal.Broadcast(ParamInt32);
};

FTbSimpleSimpleInterfaceSigInt64Delegate& UAbstractTbSimpleSimpleInterface::GetSigInt64SignalDelegate()
{
	return SigInt64Signal;
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigInt64_Implementation(int64 ParamInt64)
{
	SigInt64Signal.Broadcast(ParamInt64);
};

FTbSimpleSimpleInterfaceSigFloatDelegate& UAbstractTbSimpleSimpleInterface::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigFloat_Implementation(float ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
};

FTbSimpleSimpleInterfaceSigFloat32Delegate& UAbstractTbSimpleSimpleInterface::GetSigFloat32SignalDelegate()
{
	return SigFloat32Signal;
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigFloat32_Implementation(float ParamFloa32)
{
	SigFloat32Signal.Broadcast(ParamFloa32);
};

FTbSimpleSimpleInterfaceSigFloat64Delegate& UAbstractTbSimpleSimpleInterface::GetSigFloat64SignalDelegate()
{
	return SigFloat64Signal;
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigFloat64_Implementation(double ParamFloat64)
{
	SigFloat64Signal.Broadcast(ParamFloat64);
};

FTbSimpleSimpleInterfaceSigStringDelegate& UAbstractTbSimpleSimpleInterface::GetSigStringSignalDelegate()
{
	return SigStringSignal;
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigString_Implementation(const FString& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
};

FTbSimpleSimpleInterfacePropBoolChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
};

void UAbstractTbSimpleSimpleInterface::BroadcastPropBoolChanged_Implementation(bool bInPropBool)
{
	PropBoolChanged.Broadcast(bInPropBool);
}

bool UAbstractTbSimpleSimpleInterface::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropBool_Private(bool bInPropBool)
{
	Execute_SetPropBool(this, bInPropBool);
};

FTbSimpleSimpleInterfacePropIntChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropIntChangedDelegate()
{
	return PropIntChanged;
};

void UAbstractTbSimpleSimpleInterface::BroadcastPropIntChanged_Implementation(int32 InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

int32 UAbstractTbSimpleSimpleInterface::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropInt_Private(int32 InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
};

FTbSimpleSimpleInterfacePropInt32ChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropInt32ChangedDelegate()
{
	return PropInt32Changed;
};

void UAbstractTbSimpleSimpleInterface::BroadcastPropInt32Changed_Implementation(int32 InPropInt32)
{
	PropInt32Changed.Broadcast(InPropInt32);
}

int32 UAbstractTbSimpleSimpleInterface::GetPropInt32_Private() const
{
	return Execute_GetPropInt32(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropInt32_Private(int32 InPropInt32)
{
	Execute_SetPropInt32(this, InPropInt32);
};

FTbSimpleSimpleInterfacePropInt64ChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropInt64ChangedDelegate()
{
	return PropInt64Changed;
};

void UAbstractTbSimpleSimpleInterface::BroadcastPropInt64Changed_Implementation(int64 InPropInt64)
{
	PropInt64Changed.Broadcast(InPropInt64);
}

int64 UAbstractTbSimpleSimpleInterface::GetPropInt64_Private() const
{
	return Execute_GetPropInt64(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropInt64_Private(int64 InPropInt64)
{
	Execute_SetPropInt64(this, InPropInt64);
};

FTbSimpleSimpleInterfacePropFloatChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
};

void UAbstractTbSimpleSimpleInterface::BroadcastPropFloatChanged_Implementation(float InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

float UAbstractTbSimpleSimpleInterface::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropFloat_Private(float InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
};

FTbSimpleSimpleInterfacePropFloat32ChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropFloat32ChangedDelegate()
{
	return PropFloat32Changed;
};

void UAbstractTbSimpleSimpleInterface::BroadcastPropFloat32Changed_Implementation(float InPropFloat32)
{
	PropFloat32Changed.Broadcast(InPropFloat32);
}

float UAbstractTbSimpleSimpleInterface::GetPropFloat32_Private() const
{
	return Execute_GetPropFloat32(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropFloat32_Private(float InPropFloat32)
{
	Execute_SetPropFloat32(this, InPropFloat32);
};

FTbSimpleSimpleInterfacePropFloat64ChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropFloat64ChangedDelegate()
{
	return PropFloat64Changed;
};

void UAbstractTbSimpleSimpleInterface::BroadcastPropFloat64Changed_Implementation(double InPropFloat64)
{
	PropFloat64Changed.Broadcast(InPropFloat64);
}

double UAbstractTbSimpleSimpleInterface::GetPropFloat64_Private() const
{
	return Execute_GetPropFloat64(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropFloat64_Private(double InPropFloat64)
{
	Execute_SetPropFloat64(this, InPropFloat64);
};

FTbSimpleSimpleInterfacePropStringChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropStringChangedDelegate()
{
	return PropStringChanged;
};

void UAbstractTbSimpleSimpleInterface::BroadcastPropStringChanged_Implementation(const FString& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}

FString UAbstractTbSimpleSimpleInterface::GetPropString_Private() const
{
	return Execute_GetPropString(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropString_Private(const FString& InPropString)
{
	Execute_SetPropString(this, InPropString);
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

	Super::Deinitialize();
}

bool UAbstractTbSimpleSimpleInterface::IsInitialized() const
{
	return bInitialized;
}
