
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
#include "Generated/api/TbSimple.trace.h"
#include "TbSimpleFactory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(LogTbSimpleSimpleArrayInterfaceLoggingDecorator);

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
UTbSimpleSimpleArrayInterfaceLoggingDecorator::UTbSimpleSimpleArrayInterfaceLoggingDecorator()
	: ITbSimpleSimpleArrayInterfaceInterface()
{
	BackendService = FTbSimpleModuleFactory::createITbSimpleSimpleArrayInterfaceInterface();
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropIntChanged);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloatChanged);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropStringChanged);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigString);
}

UTbSimpleSimpleArrayInterfaceLoggingDecorator::~UTbSimpleSimpleArrayInterfaceLoggingDecorator() = default;

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropBoolChanged);
		BackendService->GetPropIntChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropIntChanged);
		BackendService->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloatChanged);
		BackendService->GetPropStringChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropStringChanged);
		BackendService->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigBool);
		BackendService->GetSigIntSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt);
		BackendService->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat);
		BackendService->GetSigStringSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigString);
	}

	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTbSimpleSimpleArrayInterfaceLoggingDecorator, Error, TEXT("Cannot set backend service to %s - interface TbSimpleSimpleArrayInterface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropIntChanged);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloatChanged);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropStringChanged);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigString);
	// populate service state to proxy
	PropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
	PropFloat = BackendService->Execute_GetPropFloat(BackendService.GetObject());
	PropString = BackendService->Execute_GetPropString(BackendService.GetObject());
}
void UTbSimpleSimpleArrayInterfaceLoggingDecorator::BroadcastSigBool_Implementation(const TArray<bool>& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigBool(const TArray<bool>& ParamBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigBool(ParamBool);
	Execute_BroadcastSigBool(this, ParamBool);
}

FTbSimpleSimpleArrayInterfaceSigBoolDelegate& UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::BroadcastSigInt_Implementation(const TArray<int32>& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt(const TArray<int32>& ParamInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigInt(ParamInt);
	Execute_BroadcastSigInt(this, ParamInt);
}

FTbSimpleSimpleArrayInterfaceSigIntDelegate& UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::BroadcastSigFloat_Implementation(const TArray<float>& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat(const TArray<float>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigFloat(ParamFloat);
	Execute_BroadcastSigFloat(this, ParamFloat);
}

FTbSimpleSimpleArrayInterfaceSigFloatDelegate& UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::BroadcastSigString_Implementation(const TArray<FString>& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigString(const TArray<FString>& ParamString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigString(ParamString);
	Execute_BroadcastSigString(this, ParamString);
}

FTbSimpleSimpleArrayInterfaceSigStringDelegate& UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::BroadcastPropBoolChanged_Implementation(const TArray<bool>& InPropBool)
{
	PropBoolChanged.Broadcast(InPropBool);
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

TArray<bool> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropBool_Private(const TArray<bool>& InPropBool)
{
	Execute_SetPropBool(this, InPropBool);
}

FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::BroadcastPropIntChanged_Implementation(const TArray<int32>& InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
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

TArray<int32> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropInt_Private(const TArray<int32>& InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
}

FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::BroadcastPropFloatChanged_Implementation(const TArray<float>& InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
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

TArray<float> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropFloat_Private(const TArray<float>& InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
}

FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::BroadcastPropStringChanged_Implementation(const TArray<FString>& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
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

TArray<FString> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropString_Private() const
{
	return Execute_GetPropString(this);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropString_Private(const TArray<FString>& InPropString)
{
	Execute_SetPropString(this, InPropString);
}

FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncBool(ParamBool);

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
		FTbSimpleSimpleArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction(LatentInfo);
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
void UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat(ParamFloat);

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
void UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncString(ParamString);

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
