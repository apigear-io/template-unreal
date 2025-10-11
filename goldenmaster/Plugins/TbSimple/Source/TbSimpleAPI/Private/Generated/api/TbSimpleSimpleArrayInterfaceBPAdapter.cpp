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
#include "TbSimple/Generated/api/TbSimpleSimpleArrayInterfaceBPAdapter.h"
#include "TbSimpleSimpleArrayInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTbSimpleSimpleArrayInterfaceBPAdapter::Initialize(TScriptInterface<ITbSimpleSimpleArrayInterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTbSimpleSimpleArrayInterfacePublisher* UTbSimpleSimpleArrayInterfaceBPAdapter::_GetPublisher()
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTbSimpleSimpleArrayInterfaceBPAdapter::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<bool>>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction<TArray<bool>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<bool>> Future = FuncBoolAsync(ParamBool);
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<bool>>* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction<TArray<bool>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<bool>> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncBoolAsync(const TArray<bool>& ParamBool)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamBool, this]()
		{
		return FuncBool(ParamBool);
	});
}

TArray<bool> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncBool(const TArray<bool>& ParamBool)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_FuncBool(Obj, ParamBool);
	}
	return TArray<bool>();
}

void UTbSimpleSimpleArrayInterfaceBPAdapter::FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<int32>>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction<TArray<int32>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<int32>> Future = FuncIntAsync(ParamInt);
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<int32>>* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction<TArray<int32>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<int32>> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncIntAsync(const TArray<int32>& ParamInt)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt, this]()
		{
		return FuncInt(ParamInt);
	});
}

TArray<int32> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncInt(const TArray<int32>& ParamInt)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_FuncInt(Obj, ParamInt);
	}
	return TArray<int32>();
}

void UTbSimpleSimpleArrayInterfaceBPAdapter::FuncInt32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<int32>>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction<TArray<int32>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<int32>> Future = FuncInt32Async(ParamInt32);
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<int32>>* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction<TArray<int32>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<int32>> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncInt32Async(const TArray<int32>& ParamInt32)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt32, this]()
		{
		return FuncInt32(ParamInt32);
	});
}

TArray<int32> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncInt32(const TArray<int32>& ParamInt32)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_FuncInt32(Obj, ParamInt32);
	}
	return TArray<int32>();
}

void UTbSimpleSimpleArrayInterfaceBPAdapter::FuncInt64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<int64>>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction<TArray<int64>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<int64>> Future = FuncInt64Async(ParamInt64);
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<int64>>* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction<TArray<int64>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<int64>> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncInt64Async(const TArray<int64>& ParamInt64)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt64, this]()
		{
		return FuncInt64(ParamInt64);
	});
}

TArray<int64> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncInt64(const TArray<int64>& ParamInt64)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_FuncInt64(Obj, ParamInt64);
	}
	return TArray<int64>();
}

void UTbSimpleSimpleArrayInterfaceBPAdapter::FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<float>>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction<TArray<float>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<float>> Future = FuncFloatAsync(ParamFloat);
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<float>>* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction<TArray<float>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<float>> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncFloatAsync(const TArray<float>& ParamFloat)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat, this]()
		{
		return FuncFloat(ParamFloat);
	});
}

TArray<float> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncFloat(const TArray<float>& ParamFloat)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_FuncFloat(Obj, ParamFloat);
	}
	return TArray<float>();
}

void UTbSimpleSimpleArrayInterfaceBPAdapter::FuncFloat32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<float>>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction<TArray<float>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<float>> Future = FuncFloat32Async(ParamFloat32);
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<float>>* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction<TArray<float>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<float>> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncFloat32Async(const TArray<float>& ParamFloat32)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat32, this]()
		{
		return FuncFloat32(ParamFloat32);
	});
}

TArray<float> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncFloat32(const TArray<float>& ParamFloat32)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_FuncFloat32(Obj, ParamFloat32);
	}
	return TArray<float>();
}

void UTbSimpleSimpleArrayInterfaceBPAdapter::FuncFloat64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<double>>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction<TArray<double>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<double>> Future = FuncFloat64Async(ParamFloat);
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<double>>* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction<TArray<double>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<double>> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncFloat64Async(const TArray<double>& ParamFloat)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat, this]()
		{
		return FuncFloat64(ParamFloat);
	});
}

TArray<double> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncFloat64(const TArray<double>& ParamFloat)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_FuncFloat64(Obj, ParamFloat);
	}
	return TArray<double>();
}

void UTbSimpleSimpleArrayInterfaceBPAdapter::FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<FString>>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction<TArray<FString>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<FString>> Future = FuncStringAsync(ParamString);
		FTbSimpleSimpleArrayInterfaceLatentAction<TArray<FString>>* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction<TArray<FString>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<FString>> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncStringAsync(const TArray<FString>& ParamString)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamString, this]()
		{
		return FuncString(ParamString);
	});
}

TArray<FString> UTbSimpleSimpleArrayInterfaceBPAdapter::FuncString(const TArray<FString>& ParamString)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_FuncString(Obj, ParamString);
	}
	return TArray<FString>();
}

TArray<bool> UTbSimpleSimpleArrayInterfaceBPAdapter::GetPropBool() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_GetPropBool(Obj);
	}
	return TArray<bool>();
}
void UTbSimpleSimpleArrayInterfaceBPAdapter::SetPropBool(const TArray<bool>& InPropBool)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleArrayInterfaceBPInterface::Execute_SetPropBool(Obj, InPropBool);
	}
}

TArray<int32> UTbSimpleSimpleArrayInterfaceBPAdapter::GetPropInt() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_GetPropInt(Obj);
	}
	return TArray<int32>();
}
void UTbSimpleSimpleArrayInterfaceBPAdapter::SetPropInt(const TArray<int32>& InPropInt)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleArrayInterfaceBPInterface::Execute_SetPropInt(Obj, InPropInt);
	}
}

TArray<int32> UTbSimpleSimpleArrayInterfaceBPAdapter::GetPropInt32() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_GetPropInt32(Obj);
	}
	return TArray<int32>();
}
void UTbSimpleSimpleArrayInterfaceBPAdapter::SetPropInt32(const TArray<int32>& InPropInt32)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleArrayInterfaceBPInterface::Execute_SetPropInt32(Obj, InPropInt32);
	}
}

TArray<int64> UTbSimpleSimpleArrayInterfaceBPAdapter::GetPropInt64() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_GetPropInt64(Obj);
	}
	return TArray<int64>();
}
void UTbSimpleSimpleArrayInterfaceBPAdapter::SetPropInt64(const TArray<int64>& InPropInt64)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleArrayInterfaceBPInterface::Execute_SetPropInt64(Obj, InPropInt64);
	}
}

TArray<float> UTbSimpleSimpleArrayInterfaceBPAdapter::GetPropFloat() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_GetPropFloat(Obj);
	}
	return TArray<float>();
}
void UTbSimpleSimpleArrayInterfaceBPAdapter::SetPropFloat(const TArray<float>& InPropFloat)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleArrayInterfaceBPInterface::Execute_SetPropFloat(Obj, InPropFloat);
	}
}

TArray<float> UTbSimpleSimpleArrayInterfaceBPAdapter::GetPropFloat32() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_GetPropFloat32(Obj);
	}
	return TArray<float>();
}
void UTbSimpleSimpleArrayInterfaceBPAdapter::SetPropFloat32(const TArray<float>& InPropFloat32)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleArrayInterfaceBPInterface::Execute_SetPropFloat32(Obj, InPropFloat32);
	}
}

TArray<double> UTbSimpleSimpleArrayInterfaceBPAdapter::GetPropFloat64() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_GetPropFloat64(Obj);
	}
	return TArray<double>();
}
void UTbSimpleSimpleArrayInterfaceBPAdapter::SetPropFloat64(const TArray<double>& InPropFloat64)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleArrayInterfaceBPInterface::Execute_SetPropFloat64(Obj, InPropFloat64);
	}
}

TArray<FString> UTbSimpleSimpleArrayInterfaceBPAdapter::GetPropString() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_GetPropString(Obj);
	}
	return TArray<FString>();
}
void UTbSimpleSimpleArrayInterfaceBPAdapter::SetPropString(const TArray<FString>& InPropString)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleArrayInterfaceBPInterface::Execute_SetPropString(Obj, InPropString);
	}
}

FString UTbSimpleSimpleArrayInterfaceBPAdapter::GetPropReadOnlyString() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleArrayInterfaceBPInterface::Execute_GetPropReadOnlyString(Obj);
	}
	return FString();
}
