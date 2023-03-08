
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
#include "Generated/Monitor/TbSimpleSimpleArrayInterfaceLoggingDecorator.h"
#include "Implementation/TbSimpleSimpleArrayInterface.h"
#include "TbSimple.trace.h"
#include "TbSimpleFactory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSimpleSimpleArrayInterfaceLoggingDecorator);

class FTbSimpleSimpleArrayInterfaceLoggingLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSimpleSimpleArrayInterfaceLoggingLatentAction(const FLatentActionInfo& LatentInfo)
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
UTbSimpleSimpleArrayInterfaceLoggingDecorator::UTbSimpleSimpleArrayInterfaceLoggingDecorator()
	: UAbstractTbSimpleSimpleArrayInterface()
{
}

UTbSimpleSimpleArrayInterfaceLoggingDecorator::~UTbSimpleSimpleArrayInterfaceLoggingDecorator() = default;

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService(FTbSimpleModuleFactory::createITbSimpleSimpleArrayInterfaceInterface(GetGameInstance(), Collection));
#else
	setBackendService(FTbSimpleModuleFactory::createITbSimpleSimpleArrayInterfaceInterface(Collection));
#endif
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropBoolChanged);
		BackendService->GetPropIntChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropIntChanged);
		BackendService->GetPropInt32ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropInt32Changed);
		BackendService->GetPropInt64ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropInt64Changed);
		BackendService->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloatChanged);
		BackendService->GetPropFloat32ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloat32Changed);
		BackendService->GetPropFloat64ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloat64Changed);
		BackendService->GetPropStringChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropStringChanged);
		BackendService->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigBool);
		BackendService->GetSigIntSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt);
		BackendService->GetSigInt32SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt32);
		BackendService->GetSigInt64SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt64);
		BackendService->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat);
		BackendService->GetSigFloat32SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat32);
		BackendService->GetSigFloat64SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat64);
		BackendService->GetSigStringSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleSimpleArrayInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropIntChanged);
	BackendService->GetPropInt32ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropInt32Changed);
	BackendService->GetPropInt64ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropInt64Changed);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloatChanged);
	BackendService->GetPropFloat32ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloat32Changed);
	BackendService->GetPropFloat64ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloat64Changed);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropStringChanged);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt);
	BackendService->GetSigInt32SignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt32);
	BackendService->GetSigInt64SignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt64);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat);
	BackendService->GetSigFloat32SignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat32);
	BackendService->GetSigFloat64SignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat64);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigString);
	// populate service state to proxy
	PropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
	PropInt32 = BackendService->Execute_GetPropInt32(BackendService.GetObject());
	PropInt64 = BackendService->Execute_GetPropInt64(BackendService.GetObject());
	PropFloat = BackendService->Execute_GetPropFloat(BackendService.GetObject());
	PropFloat32 = BackendService->Execute_GetPropFloat32(BackendService.GetObject());
	PropFloat64 = BackendService->Execute_GetPropFloat64(BackendService.GetObject());
	PropString = BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigBool(const TArray<bool>& ParamBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigBool(ParamBool);
	Execute_BroadcastSigBool(this, ParamBool);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt(const TArray<int32>& ParamInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigInt(ParamInt);
	Execute_BroadcastSigInt(this, ParamInt);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt32(const TArray<int32>& ParamInt32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigInt32(ParamInt32);
	Execute_BroadcastSigInt32(this, ParamInt32);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt64(const TArray<int64>& ParamInt64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigInt64(ParamInt64);
	Execute_BroadcastSigInt64(this, ParamInt64);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat(const TArray<float>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigFloat(ParamFloat);
	Execute_BroadcastSigFloat(this, ParamFloat);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat32(const TArray<float>& ParamFloa32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigFloat32(ParamFloa32);
	Execute_BroadcastSigFloat32(this, ParamFloa32);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat64(const TArray<double>& ParamFloat64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigFloat64(ParamFloat64);
	Execute_BroadcastSigFloat64(this, ParamFloat64);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigString(const TArray<FString>& ParamString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigString(ParamString);
	Execute_BroadcastSigString(this, ParamString);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropBoolChanged(const TArray<bool>& InPropBool)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropBool = InPropBool;
	Execute_BroadcastPropBoolChanged(this, InPropBool);
}

TArray<bool> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropBool_Implementation() const
{
	return BackendService->Execute_GetPropBool(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropBool_Implementation(const TArray<bool>& InPropBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropBool(InPropBool);
	BackendService->Execute_SetPropBool(BackendService.GetObject(), InPropBool);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropIntChanged(const TArray<int32>& InPropInt)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	Execute_BroadcastPropIntChanged(this, InPropInt);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropInt_Implementation() const
{
	return BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropInt_Implementation(const TArray<int32>& InPropInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InPropInt);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropInt32Changed(const TArray<int32>& InPropInt32)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt32 = InPropInt32;
	Execute_BroadcastPropInt32Changed(this, InPropInt32);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropInt32_Implementation() const
{
	return BackendService->Execute_GetPropInt32(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropInt32_Implementation(const TArray<int32>& InPropInt32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropInt32(InPropInt32);
	BackendService->Execute_SetPropInt32(BackendService.GetObject(), InPropInt32);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropInt64Changed(const TArray<int64>& InPropInt64)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt64 = InPropInt64;
	Execute_BroadcastPropInt64Changed(this, InPropInt64);
}

TArray<int64> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropInt64_Implementation() const
{
	return BackendService->Execute_GetPropInt64(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropInt64_Implementation(const TArray<int64>& InPropInt64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropInt64(InPropInt64);
	BackendService->Execute_SetPropInt64(BackendService.GetObject(), InPropInt64);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloatChanged(const TArray<float>& InPropFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	Execute_BroadcastPropFloatChanged(this, InPropFloat);
}

TArray<float> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropFloat_Implementation() const
{
	return BackendService->Execute_GetPropFloat(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropFloat_Implementation(const TArray<float>& InPropFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->Execute_SetPropFloat(BackendService.GetObject(), InPropFloat);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloat32Changed(const TArray<float>& InPropFloat32)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat32 = InPropFloat32;
	Execute_BroadcastPropFloat32Changed(this, InPropFloat32);
}

TArray<float> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropFloat32_Implementation() const
{
	return BackendService->Execute_GetPropFloat32(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropFloat32_Implementation(const TArray<float>& InPropFloat32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropFloat32(InPropFloat32);
	BackendService->Execute_SetPropFloat32(BackendService.GetObject(), InPropFloat32);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloat64Changed(const TArray<double>& InPropFloat64)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat64 = InPropFloat64;
	Execute_BroadcastPropFloat64Changed(this, InPropFloat64);
}

TArray<double> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropFloat64_Implementation() const
{
	return BackendService->Execute_GetPropFloat64(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropFloat64_Implementation(const TArray<double>& InPropFloat64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropFloat64(InPropFloat64);
	BackendService->Execute_SetPropFloat64(BackendService.GetObject(), InPropFloat64);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropStringChanged(const TArray<FString>& InPropString)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	Execute_BroadcastPropStringChanged(this, InPropString);
}

TArray<FString> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropString_Implementation() const
{
	return BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropString_Implementation(const TArray<FString>& InPropString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->Execute_SetPropString(BackendService.GetObject(), InPropString);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncBool(ParamBool);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLoggingLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLoggingLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamBool, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncBool(BackendService.GetObject(), ParamBool);
				CompletionAction->Cancel();
			});
	}
}

TArray<bool> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncBool_Implementation(const TArray<bool>& ParamBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncBool(ParamBool);
	return BackendService->Execute_FuncBool(BackendService.GetObject(), ParamBool);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt(ParamInt);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLoggingLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLoggingLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamInt, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
				CompletionAction->Cancel();
			});
	}
}

TArray<int32> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncInt_Implementation(const TArray<int32>& ParamInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt32(ParamInt32);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLoggingLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLoggingLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamInt32, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncInt32(BackendService.GetObject(), ParamInt32);
				CompletionAction->Cancel();
			});
	}
}

TArray<int32> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncInt32_Implementation(const TArray<int32>& ParamInt32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt32(ParamInt32);
	return BackendService->Execute_FuncInt32(BackendService.GetObject(), ParamInt32);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt64(ParamInt64);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLoggingLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLoggingLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamInt64, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncInt64(BackendService.GetObject(), ParamInt64);
				CompletionAction->Cancel();
			});
	}
}

TArray<int64> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncInt64_Implementation(const TArray<int64>& ParamInt64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt64(ParamInt64);
	return BackendService->Execute_FuncInt64(BackendService.GetObject(), ParamInt64);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat(ParamFloat);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLoggingLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLoggingLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamFloat, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
				CompletionAction->Cancel();
			});
	}
}

TArray<float> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncFloat_Implementation(const TArray<float>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat32(ParamFloat32);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLoggingLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLoggingLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamFloat32, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncFloat32(BackendService.GetObject(), ParamFloat32);
				CompletionAction->Cancel();
			});
	}
}

TArray<float> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncFloat32_Implementation(const TArray<float>& ParamFloat32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat32(ParamFloat32);
	return BackendService->Execute_FuncFloat32(BackendService.GetObject(), ParamFloat32);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat64(ParamFloat);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLoggingLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLoggingLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamFloat, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncFloat64(BackendService.GetObject(), ParamFloat);
				CompletionAction->Cancel();
			});
	}
}

TArray<double> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncFloat64_Implementation(const TArray<double>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat64(ParamFloat);
	return BackendService->Execute_FuncFloat64(BackendService.GetObject(), ParamFloat);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncString(ParamString);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLoggingLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLoggingLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLoggingLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamString, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
				CompletionAction->Cancel();
			});
	}
}

TArray<FString> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncString_Implementation(const TArray<FString>& ParamString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
}
