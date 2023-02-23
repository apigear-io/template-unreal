
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
#include "Generated/Monitor/TbSimpleSimpleInterfaceLoggingDecorator.h"
#include "Implementation/TbSimpleSimpleInterface.h"
#include "TbSimple.trace.h"
#include "TbSimpleFactory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(LogTbSimpleSimpleInterfaceLoggingDecorator);

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
UTbSimpleSimpleInterfaceLoggingDecorator::UTbSimpleSimpleInterfaceLoggingDecorator()
	: UAbstractTbSimpleSimpleInterface()
{
}

UTbSimpleSimpleInterfaceLoggingDecorator::~UTbSimpleSimpleInterfaceLoggingDecorator() = default;

void UTbSimpleSimpleInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
	setBackendService(FTbSimpleModuleFactory::createITbSimpleSimpleInterfaceInterface(Collection));
}

void UTbSimpleSimpleInterfaceLoggingDecorator::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSimpleSimpleInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSimpleSimpleInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropBoolChanged);
		BackendService->GetPropIntChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropIntChanged);
		BackendService->GetPropInt32ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropInt32Changed);
		BackendService->GetPropInt64ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropInt64Changed);
		BackendService->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloatChanged);
		BackendService->GetPropFloat32ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloat32Changed);
		BackendService->GetPropFloat64ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloat64Changed);
		BackendService->GetPropStringChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropStringChanged);
		BackendService->GetSigVoidSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigVoid);
		BackendService->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigBool);
		BackendService->GetSigIntSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt);
		BackendService->GetSigInt32SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt32);
		BackendService->GetSigInt64SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt64);
		BackendService->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat);
		BackendService->GetSigFloat32SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat32);
		BackendService->GetSigFloat64SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat64);
		BackendService->GetSigStringSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleSimpleInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropIntChanged);
	BackendService->GetPropInt32ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropInt32Changed);
	BackendService->GetPropInt64ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropInt64Changed);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloatChanged);
	BackendService->GetPropFloat32ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloat32Changed);
	BackendService->GetPropFloat64ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloat64Changed);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropStringChanged);
	BackendService->GetSigVoidSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigVoid);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt);
	BackendService->GetSigInt32SignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt32);
	BackendService->GetSigInt64SignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt64);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat);
	BackendService->GetSigFloat32SignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat32);
	BackendService->GetSigFloat64SignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat64);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigString);
	// populate service state to proxy
	bPropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
	PropInt32 = BackendService->Execute_GetPropInt32(BackendService.GetObject());
	PropInt64 = BackendService->Execute_GetPropInt64(BackendService.GetObject());
	PropFloat = BackendService->Execute_GetPropFloat(BackendService.GetObject());
	PropFloat32 = BackendService->Execute_GetPropFloat32(BackendService.GetObject());
	PropFloat64 = BackendService->Execute_GetPropFloat64(BackendService.GetObject());
	PropString = BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigVoid()
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigVoid();
	Execute_BroadcastSigVoid(this);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigBool(bool bParamBool)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigBool(bParamBool);
	Execute_BroadcastSigBool(this, bParamBool);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt(int32 ParamInt)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigInt(ParamInt);
	Execute_BroadcastSigInt(this, ParamInt);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt32(int32 ParamInt32)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigInt32(ParamInt32);
	Execute_BroadcastSigInt32(this, ParamInt32);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt64(int64 ParamInt64)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigInt64(ParamInt64);
	Execute_BroadcastSigInt64(this, ParamInt64);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat(float ParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigFloat(ParamFloat);
	Execute_BroadcastSigFloat(this, ParamFloat);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat32(float ParamFloa32)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigFloat32(ParamFloa32);
	Execute_BroadcastSigFloat32(this, ParamFloa32);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat64(double ParamFloat64)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigFloat64(ParamFloat64);
	Execute_BroadcastSigFloat64(this, ParamFloat64);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigString(const FString& ParamString)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigString(ParamString);
	Execute_BroadcastSigString(this, ParamString);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropBoolChanged(bool bInPropBool)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	bPropBool = bInPropBool;
	Execute_BroadcastPropBoolChanged(this, bInPropBool);
}

bool UTbSimpleSimpleInterfaceLoggingDecorator::GetPropBool_Implementation() const
{
	return BackendService->Execute_GetPropBool(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropBool_Implementation(bool bInPropBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropBool(bInPropBool);
	BackendService->Execute_SetPropBool(BackendService.GetObject(), bInPropBool);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropIntChanged(int32 InPropInt)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	Execute_BroadcastPropIntChanged(this, InPropInt);
}

int32 UTbSimpleSimpleInterfaceLoggingDecorator::GetPropInt_Implementation() const
{
	return BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropInt_Implementation(int32 InPropInt)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InPropInt);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropInt32Changed(int32 InPropInt32)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt32 = InPropInt32;
	Execute_BroadcastPropInt32Changed(this, InPropInt32);
}

int32 UTbSimpleSimpleInterfaceLoggingDecorator::GetPropInt32_Implementation() const
{
	return BackendService->Execute_GetPropInt32(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropInt32_Implementation(int32 InPropInt32)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropInt32(InPropInt32);
	BackendService->Execute_SetPropInt32(BackendService.GetObject(), InPropInt32);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropInt64Changed(int64 InPropInt64)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt64 = InPropInt64;
	Execute_BroadcastPropInt64Changed(this, InPropInt64);
}

int64 UTbSimpleSimpleInterfaceLoggingDecorator::GetPropInt64_Implementation() const
{
	return BackendService->Execute_GetPropInt64(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropInt64_Implementation(int64 InPropInt64)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropInt64(InPropInt64);
	BackendService->Execute_SetPropInt64(BackendService.GetObject(), InPropInt64);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloatChanged(float InPropFloat)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	Execute_BroadcastPropFloatChanged(this, InPropFloat);
}

float UTbSimpleSimpleInterfaceLoggingDecorator::GetPropFloat_Implementation() const
{
	return BackendService->Execute_GetPropFloat(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropFloat_Implementation(float InPropFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->Execute_SetPropFloat(BackendService.GetObject(), InPropFloat);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloat32Changed(float InPropFloat32)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat32 = InPropFloat32;
	Execute_BroadcastPropFloat32Changed(this, InPropFloat32);
}

float UTbSimpleSimpleInterfaceLoggingDecorator::GetPropFloat32_Implementation() const
{
	return BackendService->Execute_GetPropFloat32(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropFloat32_Implementation(float InPropFloat32)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropFloat32(InPropFloat32);
	BackendService->Execute_SetPropFloat32(BackendService.GetObject(), InPropFloat32);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloat64Changed(double InPropFloat64)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat64 = InPropFloat64;
	Execute_BroadcastPropFloat64Changed(this, InPropFloat64);
}

double UTbSimpleSimpleInterfaceLoggingDecorator::GetPropFloat64_Implementation() const
{
	return BackendService->Execute_GetPropFloat64(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropFloat64_Implementation(double InPropFloat64)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropFloat64(InPropFloat64);
	BackendService->Execute_SetPropFloat64(BackendService.GetObject(), InPropFloat64);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropStringChanged(const FString& InPropString)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	Execute_BroadcastPropStringChanged(this, InPropString);
}

FString UTbSimpleSimpleInterfaceLoggingDecorator::GetPropString_Implementation() const
{
	return BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropString_Implementation(const FString& InPropString)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->Execute_SetPropString(BackendService.GetObject(), InPropString);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::FuncVoid_Implementation()
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncVoid();
	BackendService->Execute_FuncVoid(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncBool(bParamBool);

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
		Async(EAsyncExecution::Thread,
			[bParamBool, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncBool(BackendService.GetObject(), bParamBool);
				CompletionAction->Cancel();
			});
	}
}

bool UTbSimpleSimpleInterfaceLoggingDecorator::FuncBool_Implementation(bool bParamBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncBool(bParamBool);
	return BackendService->Execute_FuncBool(BackendService.GetObject(), bParamBool);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt(ParamInt);

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
		Async(EAsyncExecution::Thread,
			[ParamInt, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
				CompletionAction->Cancel();
			});
	}
}

int32 UTbSimpleSimpleInterfaceLoggingDecorator::FuncInt_Implementation(int32 ParamInt)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt32)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt32(ParamInt32);

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
		Async(EAsyncExecution::Thread,
			[ParamInt32, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncInt32(BackendService.GetObject(), ParamInt32);
				CompletionAction->Cancel();
			});
	}
}

int32 UTbSimpleSimpleInterfaceLoggingDecorator::FuncInt32_Implementation(int32 ParamInt32)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt32(ParamInt32);
	return BackendService->Execute_FuncInt32(BackendService.GetObject(), ParamInt32);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int64& Result, int64 ParamInt64)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt64(ParamInt64);

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
		Async(EAsyncExecution::Thread,
			[ParamInt64, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncInt64(BackendService.GetObject(), ParamInt64);
				CompletionAction->Cancel();
			});
	}
}

int64 UTbSimpleSimpleInterfaceLoggingDecorator::FuncInt64_Implementation(int64 ParamInt64)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt64(ParamInt64);
	return BackendService->Execute_FuncInt64(BackendService.GetObject(), ParamInt64);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat(ParamFloat);

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
		Async(EAsyncExecution::Thread,
			[ParamFloat, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
				CompletionAction->Cancel();
			});
	}
}

float UTbSimpleSimpleInterfaceLoggingDecorator::FuncFloat_Implementation(float ParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat32)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat32(ParamFloat32);

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
		Async(EAsyncExecution::Thread,
			[ParamFloat32, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncFloat32(BackendService.GetObject(), ParamFloat32);
				CompletionAction->Cancel();
			});
	}
}

float UTbSimpleSimpleInterfaceLoggingDecorator::FuncFloat32_Implementation(float ParamFloat32)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat32(ParamFloat32);
	return BackendService->Execute_FuncFloat32(BackendService.GetObject(), ParamFloat32);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, double& Result, double ParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat64(ParamFloat);

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
		Async(EAsyncExecution::Thread,
			[ParamFloat, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncFloat64(BackendService.GetObject(), ParamFloat);
				CompletionAction->Cancel();
			});
	}
}

double UTbSimpleSimpleInterfaceLoggingDecorator::FuncFloat64_Implementation(double ParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat64(ParamFloat);
	return BackendService->Execute_FuncFloat64(BackendService.GetObject(), ParamFloat);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncString(ParamString);

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
		Async(EAsyncExecution::Thread,
			[ParamString, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
				CompletionAction->Cancel();
			});
	}
}

FString UTbSimpleSimpleInterfaceLoggingDecorator::FuncString_Implementation(const FString& ParamString)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
}
