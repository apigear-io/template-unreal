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
	TbSimpleSimpleArrayInterfacePublisher = NewObject<UTbSimpleSimpleArrayInterfacePublisher>();
}

UTbSimpleSimpleArrayInterfacePublisher* UAbstractTbSimpleSimpleArrayInterface::_GetPublisher()
{
	if (!TbSimpleSimpleArrayInterfacePublisher)
	{
		TbSimpleSimpleArrayInterfacePublisher = NewObject<UTbSimpleSimpleArrayInterfacePublisher>();
	}
	return TbSimpleSimpleArrayInterfacePublisher;
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

TFuture<TArray<bool>> UAbstractTbSimpleSimpleArrayInterface::FuncBoolAsync(const TArray<bool>& ParamBool)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamBool, this]()
		{
		return FuncBool(ParamBool);
	});
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

TFuture<TArray<int32>> UAbstractTbSimpleSimpleArrayInterface::FuncIntAsync(const TArray<int32>& ParamInt)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt, this]()
		{
		return FuncInt(ParamInt);
	});
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

TFuture<TArray<int32>> UAbstractTbSimpleSimpleArrayInterface::FuncInt32Async(const TArray<int32>& ParamInt32)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt32, this]()
		{
		return FuncInt32(ParamInt32);
	});
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

TFuture<TArray<int64>> UAbstractTbSimpleSimpleArrayInterface::FuncInt64Async(const TArray<int64>& ParamInt64)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt64, this]()
		{
		return FuncInt64(ParamInt64);
	});
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

TFuture<TArray<float>> UAbstractTbSimpleSimpleArrayInterface::FuncFloatAsync(const TArray<float>& ParamFloat)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat, this]()
		{
		return FuncFloat(ParamFloat);
	});
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

TFuture<TArray<float>> UAbstractTbSimpleSimpleArrayInterface::FuncFloat32Async(const TArray<float>& ParamFloat32)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat32, this]()
		{
		return FuncFloat32(ParamFloat32);
	});
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

TFuture<TArray<double>> UAbstractTbSimpleSimpleArrayInterface::FuncFloat64Async(const TArray<double>& ParamFloat)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat, this]()
		{
		return FuncFloat64(ParamFloat);
	});
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

TFuture<TArray<FString>> UAbstractTbSimpleSimpleArrayInterface::FuncStringAsync(const TArray<FString>& ParamString)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamString, this]()
		{
		return FuncString(ParamString);
	});
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

	if (TbSimpleSimpleArrayInterfacePublisher)
	{
		TbSimpleSimpleArrayInterfacePublisher->OnSigBoolSignal.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigBoolSignalBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigIntSignal.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigIntSignalBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigInt32Signal.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigInt32SignalBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigInt64Signal.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigInt64SignalBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloatSignal.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloatSignalBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloat32Signal.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloat32SignalBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloat64Signal.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloat64SignalBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigStringSignal.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnSigStringSignalBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);

		TbSimpleSimpleArrayInterfacePublisher->OnPropBoolChanged.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropBoolChangedBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropIntChanged.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropIntChangedBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt32Changed.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt32ChangedBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt64Changed.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt64ChangedBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloatChanged.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloatChangedBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat32Changed.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat32ChangedBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat64Changed.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat64ChangedBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropStringChanged.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropStringChangedBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropReadOnlyStringChanged.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
		TbSimpleSimpleArrayInterfacePublisher->OnPropReadOnlyStringChangedBP.RemoveAll(TbSimpleSimpleArrayInterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbSimpleSimpleArrayInterface::IsInitialized() const
{
	return bInitialized;
}
