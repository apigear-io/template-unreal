
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
	service = FTbSimpleModuleFactory::createITbSimpleSimpleInterfaceInterface();
	service->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropBoolChanged);
	service->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropIntChanged);
	service->GetPropFloatChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropFloatChanged);
	service->GetPropStringChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropStringChanged);
	service->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigBool);
	service->GetSigIntSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigInt);
	service->GetSigFloatSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigFloat);
	service->GetSigStringSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigString);
}

UTbSimpleSimpleInterfaceProxy::~UTbSimpleSimpleInterfaceProxy()
{
	service->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropBoolChanged);
	service->GetPropIntChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropIntChanged);
	service->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropFloatChanged);
	service->GetPropStringChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnPropStringChanged);
	service->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigBool);
	service->GetSigIntSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigInt);
	service->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigFloat);
	service->GetSigStringSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceProxy::OnSigString);
}
void UTbSimpleSimpleInterfaceProxy::OnSigBool(bool bParamBool)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigBool(bParamBool);
	SigBoolSignal.Broadcast(bParamBool);
}

FTbSimpleSimpleInterfaceSigBoolDelegate& UTbSimpleSimpleInterfaceProxy::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTbSimpleSimpleInterfaceProxy::OnSigInt(int32 ParamInt)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigInt(ParamInt);
	SigIntSignal.Broadcast(ParamInt);
}

FTbSimpleSimpleInterfaceSigIntDelegate& UTbSimpleSimpleInterfaceProxy::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTbSimpleSimpleInterfaceProxy::OnSigFloat(float ParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigFloat(ParamFloat);
	SigFloatSignal.Broadcast(ParamFloat);
}

FTbSimpleSimpleInterfaceSigFloatDelegate& UTbSimpleSimpleInterfaceProxy::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTbSimpleSimpleInterfaceProxy::OnSigString(const FString& ParamString)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigString(ParamString);
	SigStringSignal.Broadcast(ParamString);
}

FTbSimpleSimpleInterfaceSigStringDelegate& UTbSimpleSimpleInterfaceProxy::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTbSimpleSimpleInterfaceProxy::OnPropBoolChanged(bool bInPropBool)
{
	TbSimpleSimpleInterfaceTracer::capture_state(this);
	PropBoolChanged.Broadcast(bInPropBool);
}

bool UTbSimpleSimpleInterfaceProxy::GetPropBool_Implementation() const
{
	return service->GetPropBool();
}

void UTbSimpleSimpleInterfaceProxy::SetPropBool_Implementation(bool bInPropBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropBool(bInPropBool);
	service->SetPropBool(bInPropBool);
}

bool UTbSimpleSimpleInterfaceProxy::GetPropBool_Private() const
{
	return GetPropBool_Implementation();
}

void UTbSimpleSimpleInterfaceProxy::SetPropBool_Private(bool bInPropBool)
{
	service->SetPropBool_Implementation(bInPropBool);
}

FTbSimpleSimpleInterfacePropBoolChangedDelegate& UTbSimpleSimpleInterfaceProxy::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTbSimpleSimpleInterfaceProxy::OnPropIntChanged(int32 InPropInt)
{
	TbSimpleSimpleInterfaceTracer::capture_state(this);
	PropIntChanged.Broadcast(InPropInt);
}

int32 UTbSimpleSimpleInterfaceProxy::GetPropInt_Implementation() const
{
	return service->GetPropInt();
}

void UTbSimpleSimpleInterfaceProxy::SetPropInt_Implementation(int32 InPropInt)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropInt(InPropInt);
	service->SetPropInt(InPropInt);
}

int32 UTbSimpleSimpleInterfaceProxy::GetPropInt_Private() const
{
	return GetPropInt_Implementation();
}

void UTbSimpleSimpleInterfaceProxy::SetPropInt_Private(int32 InPropInt)
{
	service->SetPropInt_Implementation(InPropInt);
}

FTbSimpleSimpleInterfacePropIntChangedDelegate& UTbSimpleSimpleInterfaceProxy::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTbSimpleSimpleInterfaceProxy::OnPropFloatChanged(float InPropFloat)
{
	TbSimpleSimpleInterfaceTracer::capture_state(this);
	PropFloatChanged.Broadcast(InPropFloat);
}

float UTbSimpleSimpleInterfaceProxy::GetPropFloat_Implementation() const
{
	return service->GetPropFloat();
}

void UTbSimpleSimpleInterfaceProxy::SetPropFloat_Implementation(float InPropFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	service->SetPropFloat(InPropFloat);
}

float UTbSimpleSimpleInterfaceProxy::GetPropFloat_Private() const
{
	return GetPropFloat_Implementation();
}

void UTbSimpleSimpleInterfaceProxy::SetPropFloat_Private(float InPropFloat)
{
	service->SetPropFloat_Implementation(InPropFloat);
}

FTbSimpleSimpleInterfacePropFloatChangedDelegate& UTbSimpleSimpleInterfaceProxy::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTbSimpleSimpleInterfaceProxy::OnPropStringChanged(const FString& InPropString)
{
	TbSimpleSimpleInterfaceTracer::capture_state(this);
	PropStringChanged.Broadcast(InPropString);
}

FString UTbSimpleSimpleInterfaceProxy::GetPropString_Implementation() const
{
	return service->GetPropString();
}

void UTbSimpleSimpleInterfaceProxy::SetPropString_Implementation(const FString& InPropString)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropString(InPropString);
	service->SetPropString(InPropString);
}

FString UTbSimpleSimpleInterfaceProxy::GetPropString_Private() const
{
	return GetPropString_Implementation();
}

void UTbSimpleSimpleInterfaceProxy::SetPropString_Private(const FString& InPropString)
{
	service->SetPropString_Implementation(InPropString);
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
				Result = service->FuncBool(bParamBool);
				CompletionAction->Cancel();
			});
	}
}
bool UTbSimpleSimpleInterfaceProxy::FuncBool_Implementation(bool bParamBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncBool(bParamBool);
	return service->FuncBool(bParamBool);
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
				Result = service->FuncInt(ParamInt);
				CompletionAction->Cancel();
			});
	}
}
int32 UTbSimpleSimpleInterfaceProxy::FuncInt_Implementation(int32 ParamInt)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt(ParamInt);
	return service->FuncInt(ParamInt);
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
				Result = service->FuncFloat(ParamFloat);
				CompletionAction->Cancel();
			});
	}
}
float UTbSimpleSimpleInterfaceProxy::FuncFloat_Implementation(float ParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return service->FuncFloat(ParamFloat);
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
				Result = service->FuncString(ParamString);
				CompletionAction->Cancel();
			});
	}
}
FString UTbSimpleSimpleInterfaceProxy::FuncString_Implementation(const FString& ParamString)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncString(ParamString);
	return service->FuncString(ParamString);
}
