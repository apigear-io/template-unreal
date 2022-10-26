
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
#include "TbSimpleSimpleInterfaceProxy.h"
#include "SimpleInterface/TbSimpleSimpleInterfaceLocal.h"
#include "apig/TbSimple.trace.h"
#include "TbSimpleFactory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

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
UTbSimpleSimpleInterfaceProxy::UTbSimpleSimpleInterfaceProxy()
	: ITbSimpleSimpleInterfaceInterface()
	, bPropBool(false)
	, PropInt(0)
	, PropFloat(0.0f)
	, PropString(FString())
{
	BackendService = FTbSimpleModuleFactory::createITbSimpleSimpleInterfaceInterface();
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropIntChanged);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropFloatChanged);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropStringChanged);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigInt);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigFloat);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigString);
}

UTbSimpleSimpleInterfaceProxy::~UTbSimpleSimpleInterfaceProxy() = default;

void UTbSimpleSimpleInterfaceProxy::setBackendService(TScriptInterface<ITbSimpleSimpleInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropBoolChanged);
		BackendService->GetPropIntChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropIntChanged);
		BackendService->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropFloatChanged);
		BackendService->GetPropStringChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropStringChanged);
		BackendService->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigBool);
		BackendService->GetSigIntSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigInt);
		BackendService->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigFloat);
		BackendService->GetSigStringSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigString);
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropIntChanged);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropFloatChanged);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropStringChanged);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigInt);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigFloat);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigString);
	// populate service state to proxy
	bPropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
	PropFloat = BackendService->Execute_GetPropFloat(BackendService.GetObject());
	PropString = BackendService->Execute_GetPropString(BackendService.GetObject());
}
void UTbSimpleSimpleInterfaceProxy::BroadcastSigBool_Implementation(bool bParamBool)
{
	SigBoolSignal.Broadcast(bParamBool);
}

void UTbSimpleSimpleInterfaceProxy::OnSigBool(bool bParamBool)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigBool(bParamBool);
	Execute_BroadcastSigBool(this, bParamBool);
}

FTbSimpleSimpleInterfaceSigBoolDelegate& UTbSimpleSimpleInterfaceProxy::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTbSimpleSimpleInterfaceProxy::BroadcastSigInt_Implementation(int32 ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

void UTbSimpleSimpleInterfaceProxy::OnSigInt(int32 ParamInt)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigInt(ParamInt);
	Execute_BroadcastSigInt(this, ParamInt);
}

FTbSimpleSimpleInterfaceSigIntDelegate& UTbSimpleSimpleInterfaceProxy::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTbSimpleSimpleInterfaceProxy::BroadcastSigFloat_Implementation(float ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

void UTbSimpleSimpleInterfaceProxy::OnSigFloat(float ParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigFloat(ParamFloat);
	Execute_BroadcastSigFloat(this, ParamFloat);
}

FTbSimpleSimpleInterfaceSigFloatDelegate& UTbSimpleSimpleInterfaceProxy::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTbSimpleSimpleInterfaceProxy::BroadcastSigString_Implementation(const FString& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

void UTbSimpleSimpleInterfaceProxy::OnSigString(const FString& ParamString)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigString(ParamString);
	Execute_BroadcastSigString(this, ParamString);
}

FTbSimpleSimpleInterfaceSigStringDelegate& UTbSimpleSimpleInterfaceProxy::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTbSimpleSimpleInterfaceProxy::BroadcastPropBoolChanged_Implementation(bool bInPropBool)
{
	PropBoolChanged.Broadcast(bInPropBool);
}

void UTbSimpleSimpleInterfaceProxy::OnPropBoolChanged(bool bInPropBool)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	bPropBool = bInPropBool;
	Execute_BroadcastPropBoolChanged(this, bInPropBool);
}

bool UTbSimpleSimpleInterfaceProxy::GetPropBool_Implementation() const
{
	return BackendService->Execute_GetPropBool(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceProxy::SetPropBool_Implementation(bool bInPropBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropBool(bInPropBool);
	BackendService->Execute_SetPropBool(BackendService.GetObject(), bInPropBool);
}

bool UTbSimpleSimpleInterfaceProxy::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
}

void UTbSimpleSimpleInterfaceProxy::SetPropBool_Private(bool bInPropBool)
{
	Execute_SetPropBool(this, bInPropBool);
}

FTbSimpleSimpleInterfacePropBoolChangedDelegate& UTbSimpleSimpleInterfaceProxy::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTbSimpleSimpleInterfaceProxy::BroadcastPropIntChanged_Implementation(int32 InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

void UTbSimpleSimpleInterfaceProxy::OnPropIntChanged(int32 InPropInt)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	Execute_BroadcastPropIntChanged(this, InPropInt);
}

int32 UTbSimpleSimpleInterfaceProxy::GetPropInt_Implementation() const
{
	return BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceProxy::SetPropInt_Implementation(int32 InPropInt)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InPropInt);
}

int32 UTbSimpleSimpleInterfaceProxy::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
}

void UTbSimpleSimpleInterfaceProxy::SetPropInt_Private(int32 InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
}

FTbSimpleSimpleInterfacePropIntChangedDelegate& UTbSimpleSimpleInterfaceProxy::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTbSimpleSimpleInterfaceProxy::BroadcastPropFloatChanged_Implementation(float InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

void UTbSimpleSimpleInterfaceProxy::OnPropFloatChanged(float InPropFloat)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	Execute_BroadcastPropFloatChanged(this, InPropFloat);
}

float UTbSimpleSimpleInterfaceProxy::GetPropFloat_Implementation() const
{
	return BackendService->Execute_GetPropFloat(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceProxy::SetPropFloat_Implementation(float InPropFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->Execute_SetPropFloat(BackendService.GetObject(), InPropFloat);
}

float UTbSimpleSimpleInterfaceProxy::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
}

void UTbSimpleSimpleInterfaceProxy::SetPropFloat_Private(float InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
}

FTbSimpleSimpleInterfacePropFloatChangedDelegate& UTbSimpleSimpleInterfaceProxy::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTbSimpleSimpleInterfaceProxy::BroadcastPropStringChanged_Implementation(const FString& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}

void UTbSimpleSimpleInterfaceProxy::OnPropStringChanged(const FString& InPropString)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	Execute_BroadcastPropStringChanged(this, InPropString);
}

FString UTbSimpleSimpleInterfaceProxy::GetPropString_Implementation() const
{
	return BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceProxy::SetPropString_Implementation(const FString& InPropString)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->Execute_SetPropString(BackendService.GetObject(), InPropString);
}

FString UTbSimpleSimpleInterfaceProxy::GetPropString_Private() const
{
	return Execute_GetPropString(this);
}

void UTbSimpleSimpleInterfaceProxy::SetPropString_Private(const FString& InPropString)
{
	Execute_SetPropString(this, InPropString);
}

FTbSimpleSimpleInterfacePropStringChangedDelegate& UTbSimpleSimpleInterfaceProxy::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

void UTbSimpleSimpleInterfaceProxy::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
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
bool UTbSimpleSimpleInterfaceProxy::FuncBool_Implementation(bool bParamBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncBool(bParamBool);
	return BackendService->Execute_FuncBool(BackendService.GetObject(), bParamBool);
}
void UTbSimpleSimpleInterfaceProxy::FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt)
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
int32 UTbSimpleSimpleInterfaceProxy::FuncInt_Implementation(int32 ParamInt)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
}
void UTbSimpleSimpleInterfaceProxy::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat)
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
float UTbSimpleSimpleInterfaceProxy::FuncFloat_Implementation(float ParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
}
void UTbSimpleSimpleInterfaceProxy::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString)
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
FString UTbSimpleSimpleInterfaceProxy::FuncString_Implementation(const FString& ParamString)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
}
