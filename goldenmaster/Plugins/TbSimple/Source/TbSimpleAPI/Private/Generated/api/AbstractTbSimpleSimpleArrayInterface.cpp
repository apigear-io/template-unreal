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
#include "TbSimple/Generated/api/AbstractTbSimpleSimpleArrayInterface.h"
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

UTbSimpleSimpleArrayInterfaceSignals* UAbstractTbSimpleSimpleArrayInterface::_GetSignals()
{
	if (!TbSimpleSimpleArrayInterfaceSignals)
	{
		TbSimpleSimpleArrayInterfaceSignals = NewObject<UTbSimpleSimpleArrayInterfaceSignals>();
	}
	return TbSimpleSimpleArrayInterfaceSignals;
}

TArray<bool> UAbstractTbSimpleSimpleArrayInterface::GetPropBool_Private() const
{
	return GetPropBool();
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropBool_Private(const TArray<bool>& InPropBool)
{
	SetPropBool(InPropBool);
};

TArray<int32> UAbstractTbSimpleSimpleArrayInterface::GetPropInt_Private() const
{
	return GetPropInt();
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropInt_Private(const TArray<int32>& InPropInt)
{
	SetPropInt(InPropInt);
};

TArray<int32> UAbstractTbSimpleSimpleArrayInterface::GetPropInt32_Private() const
{
	return GetPropInt32();
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropInt32_Private(const TArray<int32>& InPropInt32)
{
	SetPropInt32(InPropInt32);
};

TArray<int64> UAbstractTbSimpleSimpleArrayInterface::GetPropInt64_Private() const
{
	return GetPropInt64();
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropInt64_Private(const TArray<int64>& InPropInt64)
{
	SetPropInt64(InPropInt64);
};

TArray<float> UAbstractTbSimpleSimpleArrayInterface::GetPropFloat_Private() const
{
	return GetPropFloat();
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropFloat_Private(const TArray<float>& InPropFloat)
{
	SetPropFloat(InPropFloat);
};

TArray<float> UAbstractTbSimpleSimpleArrayInterface::GetPropFloat32_Private() const
{
	return GetPropFloat32();
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropFloat32_Private(const TArray<float>& InPropFloat32)
{
	SetPropFloat32(InPropFloat32);
};

TArray<double> UAbstractTbSimpleSimpleArrayInterface::GetPropFloat64_Private() const
{
	return GetPropFloat64();
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropFloat64_Private(const TArray<double>& InPropFloat64)
{
	SetPropFloat64(InPropFloat64);
};

TArray<FString> UAbstractTbSimpleSimpleArrayInterface::GetPropString_Private() const
{
	return GetPropString();
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropString_Private(const TArray<FString>& InPropString)
{
	SetPropString(InPropString);
};

FString UAbstractTbSimpleSimpleArrayInterface::GetPropReadOnlyString_Private() const
{
	return GetPropReadOnlyString();
};

void UAbstractTbSimpleSimpleArrayInterface::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool)
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

void UAbstractTbSimpleSimpleArrayInterface::FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt)
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

void UAbstractTbSimpleSimpleArrayInterface::FuncInt32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32)
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
			Result = FuncInt32(ParamInt32);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamInt32, this, &Result, CompletionAction]()
				{
				Result = FuncInt32(ParamInt32);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSimpleSimpleArrayInterface::FuncInt64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64)
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
			Result = FuncInt64(ParamInt64);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamInt64, this, &Result, CompletionAction]()
				{
				Result = FuncInt64(ParamInt64);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSimpleSimpleArrayInterface::FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat)
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

void UAbstractTbSimpleSimpleArrayInterface::FuncFloat32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32)
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
			Result = FuncFloat32(ParamFloat32);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamFloat32, this, &Result, CompletionAction]()
				{
				Result = FuncFloat32(ParamFloat32);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSimpleSimpleArrayInterface::FuncFloat64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat)
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
			Result = FuncFloat64(ParamFloat);
			CompletionAction->Cancel();
		}
		else
		{
			Async(EAsyncExecution::ThreadPool,
				[ParamFloat, this, &Result, CompletionAction]()
				{
				Result = FuncFloat64(ParamFloat);
				CompletionAction->Cancel();
			});
		}
	}
}

void UAbstractTbSimpleSimpleArrayInterface::FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString)
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
		TbSimpleSimpleArrayInterfaceSignals->OnSigBoolSignalBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigIntSignal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigIntSignalBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigInt32Signal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigInt32SignalBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigInt64Signal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigInt64SignalBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloatSignal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloatSignalBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloat32Signal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloat32SignalBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloat64Signal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloat64SignalBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigStringSignal.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnSigStringSignalBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);

		TbSimpleSimpleArrayInterfaceSignals->OnPropBoolChanged.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropBoolChangedBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropIntChanged.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropIntChangedBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt32Changed.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt32ChangedBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt64Changed.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt64ChangedBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloatChanged.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloatChangedBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat32Changed.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat32ChangedBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat64Changed.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat64ChangedBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropStringChanged.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropStringChangedBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropReadOnlyStringChanged.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
		TbSimpleSimpleArrayInterfaceSignals->OnPropReadOnlyStringChangedBP.RemoveAll(TbSimpleSimpleArrayInterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTbSimpleSimpleArrayInterface::IsInitialized() const
{
	return bInitialized;
}
