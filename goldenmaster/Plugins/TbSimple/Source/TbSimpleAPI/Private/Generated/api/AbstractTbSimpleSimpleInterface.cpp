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
#include "TbSimple/Generated/api/AbstractTbSimpleSimpleInterface.h"
#include "TbSimpleSimpleInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

UAbstractTbSimpleSimpleInterface::UAbstractTbSimpleSimpleInterface()
{
	TbSimpleSimpleInterfacePublisher = NewObject<UTbSimpleSimpleInterfacePublisher>();
}

UTbSimpleSimpleInterfacePublisher* UAbstractTbSimpleSimpleInterface::_GetPublisher()
{
	if (!TbSimpleSimpleInterfacePublisher)
	{
		TbSimpleSimpleInterfacePublisher = NewObject<UTbSimpleSimpleInterfacePublisher>();
	}
	return TbSimpleSimpleInterfacePublisher;
}

bool UAbstractTbSimpleSimpleInterface::GetPropBool_Private() const
{
	return GetPropBool();
};

void UAbstractTbSimpleSimpleInterface::SetPropBool_Private(bool bInPropBool)
{
	SetPropBool(bInPropBool);
};

int32 UAbstractTbSimpleSimpleInterface::GetPropInt_Private() const
{
	return GetPropInt();
};

void UAbstractTbSimpleSimpleInterface::SetPropInt_Private(int32 InPropInt)
{
	SetPropInt(InPropInt);
};

int32 UAbstractTbSimpleSimpleInterface::GetPropInt32_Private() const
{
	return GetPropInt32();
};

void UAbstractTbSimpleSimpleInterface::SetPropInt32_Private(int32 InPropInt32)
{
	SetPropInt32(InPropInt32);
};

int64 UAbstractTbSimpleSimpleInterface::GetPropInt64_Private() const
{
	return GetPropInt64();
};

void UAbstractTbSimpleSimpleInterface::SetPropInt64_Private(int64 InPropInt64)
{
	SetPropInt64(InPropInt64);
};

float UAbstractTbSimpleSimpleInterface::GetPropFloat_Private() const
{
	return GetPropFloat();
};

void UAbstractTbSimpleSimpleInterface::SetPropFloat_Private(float InPropFloat)
{
	SetPropFloat(InPropFloat);
};

float UAbstractTbSimpleSimpleInterface::GetPropFloat32_Private() const
{
	return GetPropFloat32();
};

void UAbstractTbSimpleSimpleInterface::SetPropFloat32_Private(float InPropFloat32)
{
	SetPropFloat32(InPropFloat32);
};

double UAbstractTbSimpleSimpleInterface::GetPropFloat64_Private() const
{
	return GetPropFloat64();
};

void UAbstractTbSimpleSimpleInterface::SetPropFloat64_Private(double InPropFloat64)
{
	SetPropFloat64(InPropFloat64);
};

FString UAbstractTbSimpleSimpleInterface::GetPropString_Private() const
{
	return GetPropString();
};

void UAbstractTbSimpleSimpleInterface::SetPropString_Private(const FString& InPropString)
{
	SetPropString(InPropString);
};

void UAbstractTbSimpleSimpleInterface::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction<bool>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction<bool>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<bool> Future = FuncBoolAsync(bParamBool);
		FTbSimpleSimpleInterfaceLatentAction<bool>* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction<bool>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<bool> UAbstractTbSimpleSimpleInterface::FuncBoolAsync(bool bParamBool)
{
	return Async(EAsyncExecution::ThreadPool,
		[bParamBool, this]()
		{
		return FuncBool(bParamBool);
	});
}

void UAbstractTbSimpleSimpleInterface::FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction<int32>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction<int32>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<int32> Future = FuncIntAsync(ParamInt);
		FTbSimpleSimpleInterfaceLatentAction<int32>* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction<int32>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<int32> UAbstractTbSimpleSimpleInterface::FuncIntAsync(int32 ParamInt)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt, this]()
		{
		return FuncInt(ParamInt);
	});
}

void UAbstractTbSimpleSimpleInterface::FuncInt32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt32)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction<int32>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction<int32>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<int32> Future = FuncInt32Async(ParamInt32);
		FTbSimpleSimpleInterfaceLatentAction<int32>* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction<int32>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<int32> UAbstractTbSimpleSimpleInterface::FuncInt32Async(int32 ParamInt32)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt32, this]()
		{
		return FuncInt32(ParamInt32);
	});
}

void UAbstractTbSimpleSimpleInterface::FuncInt64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int64& Result, int64 ParamInt64)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction<int64>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction<int64>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<int64> Future = FuncInt64Async(ParamInt64);
		FTbSimpleSimpleInterfaceLatentAction<int64>* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction<int64>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<int64> UAbstractTbSimpleSimpleInterface::FuncInt64Async(int64 ParamInt64)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt64, this]()
		{
		return FuncInt64(ParamInt64);
	});
}

void UAbstractTbSimpleSimpleInterface::FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction<float>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction<float>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<float> Future = FuncFloatAsync(ParamFloat);
		FTbSimpleSimpleInterfaceLatentAction<float>* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction<float>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<float> UAbstractTbSimpleSimpleInterface::FuncFloatAsync(float ParamFloat)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat, this]()
		{
		return FuncFloat(ParamFloat);
	});
}

void UAbstractTbSimpleSimpleInterface::FuncFloat32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat32)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction<float>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction<float>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<float> Future = FuncFloat32Async(ParamFloat32);
		FTbSimpleSimpleInterfaceLatentAction<float>* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction<float>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<float> UAbstractTbSimpleSimpleInterface::FuncFloat32Async(float ParamFloat32)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat32, this]()
		{
		return FuncFloat32(ParamFloat32);
	});
}

void UAbstractTbSimpleSimpleInterface::FuncFloat64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, double& Result, double ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction<double>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction<double>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<double> Future = FuncFloat64Async(ParamFloat);
		FTbSimpleSimpleInterfaceLatentAction<double>* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction<double>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<double> UAbstractTbSimpleSimpleInterface::FuncFloat64Async(double ParamFloat)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat, this]()
		{
		return FuncFloat64(ParamFloat);
	});
}

void UAbstractTbSimpleSimpleInterface::FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleInterfaceLatentAction<FString>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleInterfaceLatentAction<FString>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<FString> Future = FuncStringAsync(ParamString);
		FTbSimpleSimpleInterfaceLatentAction<FString>* CompletionAction = new FTbSimpleSimpleInterfaceLatentAction<FString>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<FString> UAbstractTbSimpleSimpleInterface::FuncStringAsync(const FString& ParamString)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamString, this]()
		{
		return FuncString(ParamString);
	});
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

	if (TbSimpleSimpleInterfacePublisher)
	{
		TbSimpleSimpleInterfacePublisher->OnSigBoolSignal.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigBoolSignalBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigIntSignal.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigIntSignalBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigInt32Signal.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigInt32SignalBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigInt64Signal.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigInt64SignalBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigFloatSignal.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigFloatSignalBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigFloat32Signal.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigFloat32SignalBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigFloat64Signal.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigFloat64SignalBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigStringSignal.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnSigStringSignalBP.RemoveAll(TbSimpleSimpleInterfacePublisher);

		TbSimpleSimpleInterfacePublisher->OnPropBoolChanged.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropBoolChangedBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropIntChanged.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropIntChangedBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropInt32Changed.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropInt32ChangedBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropInt64Changed.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropInt64ChangedBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropFloatChanged.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropFloatChangedBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropFloat32Changed.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropFloat32ChangedBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropFloat64Changed.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropFloat64ChangedBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropStringChanged.RemoveAll(TbSimpleSimpleInterfacePublisher);
		TbSimpleSimpleInterfacePublisher->OnPropStringChangedBP.RemoveAll(TbSimpleSimpleInterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbSimpleSimpleInterface::IsInitialized() const
{
	return bInitialized;
}
