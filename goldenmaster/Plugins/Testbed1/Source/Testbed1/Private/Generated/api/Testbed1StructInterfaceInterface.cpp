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
#include "Testbed1StructInterfaceInterface.h"
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

FTestbed1StructInterfaceSigBoolDelegate& UAbstractTestbed1StructInterface::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
};

void UAbstractTestbed1StructInterface::BroadcastSigBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
};

FTestbed1StructInterfaceSigIntDelegate& UAbstractTestbed1StructInterface::GetSigIntSignalDelegate()
{
	return SigIntSignal;
};

void UAbstractTestbed1StructInterface::BroadcastSigInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
};

FTestbed1StructInterfaceSigFloatDelegate& UAbstractTestbed1StructInterface::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
};

void UAbstractTestbed1StructInterface::BroadcastSigFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
};

FTestbed1StructInterfaceSigStringDelegate& UAbstractTestbed1StructInterface::GetSigStringSignalDelegate()
{
	return SigStringSignal;
};

void UAbstractTestbed1StructInterface::BroadcastSigString_Implementation(const FTestbed1StructString& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
};

FTestbed1StructInterfacePropBoolChangedDelegate& UAbstractTestbed1StructInterface::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
};

void UAbstractTestbed1StructInterface::BroadcastPropBoolChanged_Implementation(const FTestbed1StructBool& InPropBool)
{
	PropBoolChanged.Broadcast(InPropBool);
}

FTestbed1StructBool UAbstractTestbed1StructInterface::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
};

void UAbstractTestbed1StructInterface::SetPropBool_Private(const FTestbed1StructBool& InPropBool)
{
	Execute_SetPropBool(this, InPropBool);
};

FTestbed1StructInterfacePropIntChangedDelegate& UAbstractTestbed1StructInterface::GetPropIntChangedDelegate()
{
	return PropIntChanged;
};

void UAbstractTestbed1StructInterface::BroadcastPropIntChanged_Implementation(const FTestbed1StructInt& InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

FTestbed1StructInt UAbstractTestbed1StructInterface::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
};

void UAbstractTestbed1StructInterface::SetPropInt_Private(const FTestbed1StructInt& InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
};

FTestbed1StructInterfacePropFloatChangedDelegate& UAbstractTestbed1StructInterface::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
};

void UAbstractTestbed1StructInterface::BroadcastPropFloatChanged_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

FTestbed1StructFloat UAbstractTestbed1StructInterface::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
};

void UAbstractTestbed1StructInterface::SetPropFloat_Private(const FTestbed1StructFloat& InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
};

FTestbed1StructInterfacePropStringChangedDelegate& UAbstractTestbed1StructInterface::GetPropStringChangedDelegate()
{
	return PropStringChanged;
};

void UAbstractTestbed1StructInterface::BroadcastPropStringChanged_Implementation(const FTestbed1StructString& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}

FTestbed1StructString UAbstractTestbed1StructInterface::GetPropString_Private() const
{
	return Execute_GetPropString(this);
};

void UAbstractTestbed1StructInterface::SetPropString_Private(const FTestbed1StructString& InPropString)
{
	Execute_SetPropString(this, InPropString);
};
void UAbstractTestbed1StructInterface::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool)
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
		Async(EAsyncExecution::Thread,
			[ParamBool, this, &Result, CompletionAction]()
			{
				Result = Execute_FuncBool(this, ParamBool);
				CompletionAction->Cancel();
			});
	}
}

void UAbstractTestbed1StructInterface::FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt)
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
		Async(EAsyncExecution::Thread,
			[ParamInt, this, &Result, CompletionAction]()
			{
				Result = Execute_FuncInt(this, ParamInt);
				CompletionAction->Cancel();
			});
	}
}

void UAbstractTestbed1StructInterface::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat)
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
		Async(EAsyncExecution::Thread,
			[ParamFloat, this, &Result, CompletionAction]()
			{
				Result = Execute_FuncFloat(this, ParamFloat);
				CompletionAction->Cancel();
			});
	}
}

void UAbstractTestbed1StructInterface::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString)
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
		Async(EAsyncExecution::Thread,
			[ParamString, this, &Result, CompletionAction]()
			{
				Result = Execute_FuncString(this, ParamString);
				CompletionAction->Cancel();
			});
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

	Super::Deinitialize();
}

bool UAbstractTestbed1StructInterface::IsInitialized() const
{
	return bInitialized;
}
