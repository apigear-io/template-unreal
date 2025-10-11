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
#include "TbSimple/Generated/api/TbSimpleSimpleInterfaceBPAdapter.h"
#include "TbSimpleSimpleInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTbSimpleSimpleInterfaceBPAdapter::Initialize(TScriptInterface<ITbSimpleSimpleInterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTbSimpleSimpleInterfacePublisher* UTbSimpleSimpleInterfaceBPAdapter::_GetPublisher()
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTbSimpleSimpleInterfaceBPAdapter::FuncNoReturnValue(bool bParamBool)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_FuncNoReturnValue(Obj, bParamBool);
	}
}

void UTbSimpleSimpleInterfaceBPAdapter::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
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

TFuture<bool> UTbSimpleSimpleInterfaceBPAdapter::FuncBoolAsync(bool bParamBool)
{
	return Async(EAsyncExecution::ThreadPool,
		[bParamBool, this]()
		{
		return FuncBool(bParamBool);
	});
}

bool UTbSimpleSimpleInterfaceBPAdapter::FuncBool(bool bParamBool)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_FuncBool(Obj, bParamBool);
	}
	return false;
}

void UTbSimpleSimpleInterfaceBPAdapter::FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt)
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

TFuture<int32> UTbSimpleSimpleInterfaceBPAdapter::FuncIntAsync(int32 ParamInt)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt, this]()
		{
		return FuncInt(ParamInt);
	});
}

int32 UTbSimpleSimpleInterfaceBPAdapter::FuncInt(int32 ParamInt)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_FuncInt(Obj, ParamInt);
	}
	return 0;
}

void UTbSimpleSimpleInterfaceBPAdapter::FuncInt32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt32)
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

TFuture<int32> UTbSimpleSimpleInterfaceBPAdapter::FuncInt32Async(int32 ParamInt32)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt32, this]()
		{
		return FuncInt32(ParamInt32);
	});
}

int32 UTbSimpleSimpleInterfaceBPAdapter::FuncInt32(int32 ParamInt32)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_FuncInt32(Obj, ParamInt32);
	}
	return 0;
}

void UTbSimpleSimpleInterfaceBPAdapter::FuncInt64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int64& Result, int64 ParamInt64)
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

TFuture<int64> UTbSimpleSimpleInterfaceBPAdapter::FuncInt64Async(int64 ParamInt64)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamInt64, this]()
		{
		return FuncInt64(ParamInt64);
	});
}

int64 UTbSimpleSimpleInterfaceBPAdapter::FuncInt64(int64 ParamInt64)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_FuncInt64(Obj, ParamInt64);
	}
	return 0LL;
}

void UTbSimpleSimpleInterfaceBPAdapter::FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat)
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

TFuture<float> UTbSimpleSimpleInterfaceBPAdapter::FuncFloatAsync(float ParamFloat)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat, this]()
		{
		return FuncFloat(ParamFloat);
	});
}

float UTbSimpleSimpleInterfaceBPAdapter::FuncFloat(float ParamFloat)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_FuncFloat(Obj, ParamFloat);
	}
	return 0.0f;
}

void UTbSimpleSimpleInterfaceBPAdapter::FuncFloat32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat32)
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

TFuture<float> UTbSimpleSimpleInterfaceBPAdapter::FuncFloat32Async(float ParamFloat32)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat32, this]()
		{
		return FuncFloat32(ParamFloat32);
	});
}

float UTbSimpleSimpleInterfaceBPAdapter::FuncFloat32(float ParamFloat32)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_FuncFloat32(Obj, ParamFloat32);
	}
	return 0.0f;
}

void UTbSimpleSimpleInterfaceBPAdapter::FuncFloat64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, double& Result, double ParamFloat)
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

TFuture<double> UTbSimpleSimpleInterfaceBPAdapter::FuncFloat64Async(double ParamFloat)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamFloat, this]()
		{
		return FuncFloat64(ParamFloat);
	});
}

double UTbSimpleSimpleInterfaceBPAdapter::FuncFloat64(double ParamFloat)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_FuncFloat64(Obj, ParamFloat);
	}
	return 0.0;
}

void UTbSimpleSimpleInterfaceBPAdapter::FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString)
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

TFuture<FString> UTbSimpleSimpleInterfaceBPAdapter::FuncStringAsync(const FString& ParamString)
{
	return Async(EAsyncExecution::ThreadPool,
		[ParamString, this]()
		{
		return FuncString(ParamString);
	});
}

FString UTbSimpleSimpleInterfaceBPAdapter::FuncString(const FString& ParamString)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_FuncString(Obj, ParamString);
	}
	return FString();
}

bool UTbSimpleSimpleInterfaceBPAdapter::GetPropBool() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_GetPropBool(Obj);
	}
	return false;
}
void UTbSimpleSimpleInterfaceBPAdapter::SetPropBool(bool bInPropBool)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleInterfaceBPInterface::Execute_SetPropBool(Obj, bInPropBool);
	}
}

int32 UTbSimpleSimpleInterfaceBPAdapter::GetPropInt() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_GetPropInt(Obj);
	}
	return 0;
}
void UTbSimpleSimpleInterfaceBPAdapter::SetPropInt(int32 InPropInt)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleInterfaceBPInterface::Execute_SetPropInt(Obj, InPropInt);
	}
}

int32 UTbSimpleSimpleInterfaceBPAdapter::GetPropInt32() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_GetPropInt32(Obj);
	}
	return 0;
}
void UTbSimpleSimpleInterfaceBPAdapter::SetPropInt32(int32 InPropInt32)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleInterfaceBPInterface::Execute_SetPropInt32(Obj, InPropInt32);
	}
}

int64 UTbSimpleSimpleInterfaceBPAdapter::GetPropInt64() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_GetPropInt64(Obj);
	}
	return 0LL;
}
void UTbSimpleSimpleInterfaceBPAdapter::SetPropInt64(int64 InPropInt64)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleInterfaceBPInterface::Execute_SetPropInt64(Obj, InPropInt64);
	}
}

float UTbSimpleSimpleInterfaceBPAdapter::GetPropFloat() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_GetPropFloat(Obj);
	}
	return 0.0f;
}
void UTbSimpleSimpleInterfaceBPAdapter::SetPropFloat(float InPropFloat)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleInterfaceBPInterface::Execute_SetPropFloat(Obj, InPropFloat);
	}
}

float UTbSimpleSimpleInterfaceBPAdapter::GetPropFloat32() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_GetPropFloat32(Obj);
	}
	return 0.0f;
}
void UTbSimpleSimpleInterfaceBPAdapter::SetPropFloat32(float InPropFloat32)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleInterfaceBPInterface::Execute_SetPropFloat32(Obj, InPropFloat32);
	}
}

double UTbSimpleSimpleInterfaceBPAdapter::GetPropFloat64() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_GetPropFloat64(Obj);
	}
	return 0.0;
}
void UTbSimpleSimpleInterfaceBPAdapter::SetPropFloat64(double InPropFloat64)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleInterfaceBPInterface::Execute_SetPropFloat64(Obj, InPropFloat64);
	}
}

FString UTbSimpleSimpleInterfaceBPAdapter::GetPropString() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleSimpleInterfaceBPInterface::Execute_GetPropString(Obj);
	}
	return FString();
}
void UTbSimpleSimpleInterfaceBPAdapter::SetPropString(const FString& InPropString)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleSimpleInterfaceBPInterface::Execute_SetPropString(Obj, InPropString);
	}
}
