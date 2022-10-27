
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
#include "TbSimpleSimpleArrayInterfaceProxy.h"
#include "Implementation/TbSimpleSimpleArrayInterface.h"
#include "Generated/api/TbSimple.trace.h"
#include "TbSimpleFactory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

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
UTbSimpleSimpleArrayInterfaceProxy::UTbSimpleSimpleArrayInterfaceProxy()
	: ITbSimpleSimpleArrayInterfaceInterface()
{
	BackendService = FTbSimpleModuleFactory::createITbSimpleSimpleArrayInterfaceInterface();
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropIntChanged);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropFloatChanged);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropStringChanged);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigInt);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigFloat);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigString);
}

UTbSimpleSimpleArrayInterfaceProxy::~UTbSimpleSimpleArrayInterfaceProxy() = default;

void UTbSimpleSimpleArrayInterfaceProxy::setBackendService(TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropBoolChanged);
		BackendService->GetPropIntChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropIntChanged);
		BackendService->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropFloatChanged);
		BackendService->GetPropStringChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropStringChanged);
		BackendService->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigBool);
		BackendService->GetSigIntSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigInt);
		BackendService->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigFloat);
		BackendService->GetSigStringSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigString);
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropIntChanged);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropFloatChanged);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropStringChanged);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigInt);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigFloat);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigString);
	// populate service state to proxy
	PropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
	PropFloat = BackendService->Execute_GetPropFloat(BackendService.GetObject());
	PropString = BackendService->Execute_GetPropString(BackendService.GetObject());
}
void UTbSimpleSimpleArrayInterfaceProxy::BroadcastSigBool_Implementation(const TArray<bool>& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
}

void UTbSimpleSimpleArrayInterfaceProxy::OnSigBool(const TArray<bool>& ParamBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigBool(ParamBool);
	Execute_BroadcastSigBool(this, ParamBool);
}

FTbSimpleSimpleArrayInterfaceSigBoolDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTbSimpleSimpleArrayInterfaceProxy::BroadcastSigInt_Implementation(const TArray<int32>& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

void UTbSimpleSimpleArrayInterfaceProxy::OnSigInt(const TArray<int32>& ParamInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigInt(ParamInt);
	Execute_BroadcastSigInt(this, ParamInt);
}

FTbSimpleSimpleArrayInterfaceSigIntDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTbSimpleSimpleArrayInterfaceProxy::BroadcastSigFloat_Implementation(const TArray<float>& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

void UTbSimpleSimpleArrayInterfaceProxy::OnSigFloat(const TArray<float>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigFloat(ParamFloat);
	Execute_BroadcastSigFloat(this, ParamFloat);
}

FTbSimpleSimpleArrayInterfaceSigFloatDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTbSimpleSimpleArrayInterfaceProxy::BroadcastSigString_Implementation(const TArray<FString>& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

void UTbSimpleSimpleArrayInterfaceProxy::OnSigString(const TArray<FString>& ParamString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigString(ParamString);
	Execute_BroadcastSigString(this, ParamString);
}

FTbSimpleSimpleArrayInterfaceSigStringDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTbSimpleSimpleArrayInterfaceProxy::BroadcastPropBoolChanged_Implementation(const TArray<bool>& InPropBool)
{
	PropBoolChanged.Broadcast(InPropBool);
}

void UTbSimpleSimpleArrayInterfaceProxy::OnPropBoolChanged(const TArray<bool>& InPropBool)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropBool = InPropBool;
	Execute_BroadcastPropBoolChanged(this, InPropBool);
}

TArray<bool> UTbSimpleSimpleArrayInterfaceProxy::GetPropBool_Implementation() const
{
	return BackendService->Execute_GetPropBool(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceProxy::SetPropBool_Implementation(const TArray<bool>& InPropBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropBool(InPropBool);
	BackendService->Execute_SetPropBool(BackendService.GetObject(), InPropBool);
}

TArray<bool> UTbSimpleSimpleArrayInterfaceProxy::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
}

void UTbSimpleSimpleArrayInterfaceProxy::SetPropBool_Private(const TArray<bool>& InPropBool)
{
	Execute_SetPropBool(this, InPropBool);
}

FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTbSimpleSimpleArrayInterfaceProxy::BroadcastPropIntChanged_Implementation(const TArray<int32>& InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

void UTbSimpleSimpleArrayInterfaceProxy::OnPropIntChanged(const TArray<int32>& InPropInt)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	Execute_BroadcastPropIntChanged(this, InPropInt);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceProxy::GetPropInt_Implementation() const
{
	return BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceProxy::SetPropInt_Implementation(const TArray<int32>& InPropInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InPropInt);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceProxy::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
}

void UTbSimpleSimpleArrayInterfaceProxy::SetPropInt_Private(const TArray<int32>& InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
}

FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTbSimpleSimpleArrayInterfaceProxy::BroadcastPropFloatChanged_Implementation(const TArray<float>& InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

void UTbSimpleSimpleArrayInterfaceProxy::OnPropFloatChanged(const TArray<float>& InPropFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	Execute_BroadcastPropFloatChanged(this, InPropFloat);
}

TArray<float> UTbSimpleSimpleArrayInterfaceProxy::GetPropFloat_Implementation() const
{
	return BackendService->Execute_GetPropFloat(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceProxy::SetPropFloat_Implementation(const TArray<float>& InPropFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->Execute_SetPropFloat(BackendService.GetObject(), InPropFloat);
}

TArray<float> UTbSimpleSimpleArrayInterfaceProxy::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
}

void UTbSimpleSimpleArrayInterfaceProxy::SetPropFloat_Private(const TArray<float>& InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
}

FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTbSimpleSimpleArrayInterfaceProxy::BroadcastPropStringChanged_Implementation(const TArray<FString>& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}

void UTbSimpleSimpleArrayInterfaceProxy::OnPropStringChanged(const TArray<FString>& InPropString)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	Execute_BroadcastPropStringChanged(this, InPropString);
}

TArray<FString> UTbSimpleSimpleArrayInterfaceProxy::GetPropString_Implementation() const
{
	return BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceProxy::SetPropString_Implementation(const TArray<FString>& InPropString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->Execute_SetPropString(BackendService.GetObject(), InPropString);
}

TArray<FString> UTbSimpleSimpleArrayInterfaceProxy::GetPropString_Private() const
{
	return Execute_GetPropString(this);
}

void UTbSimpleSimpleArrayInterfaceProxy::SetPropString_Private(const TArray<FString>& InPropString)
{
	Execute_SetPropString(this, InPropString);
}

FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

void UTbSimpleSimpleArrayInterfaceProxy::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool)
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
TArray<bool> UTbSimpleSimpleArrayInterfaceProxy::FuncBool_Implementation(const TArray<bool>& ParamBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncBool(ParamBool);
	return BackendService->Execute_FuncBool(BackendService.GetObject(), ParamBool);
}
void UTbSimpleSimpleArrayInterfaceProxy::FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt)
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
TArray<int32> UTbSimpleSimpleArrayInterfaceProxy::FuncInt_Implementation(const TArray<int32>& ParamInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
}
void UTbSimpleSimpleArrayInterfaceProxy::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat)
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
TArray<float> UTbSimpleSimpleArrayInterfaceProxy::FuncFloat_Implementation(const TArray<float>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
}
void UTbSimpleSimpleArrayInterfaceProxy::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString)
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
TArray<FString> UTbSimpleSimpleArrayInterfaceProxy::FuncString_Implementation(const TArray<FString>& ParamString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
}
