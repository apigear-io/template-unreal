
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
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

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

bool UTbSimpleSimpleInterfaceProxy::GetPropBool() const
{
	return service->GetPropBool();
}

void UTbSimpleSimpleInterfaceProxy::SetPropBool(bool bInPropBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropBool(bInPropBool);
	service->SetPropBool(bInPropBool);
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

int32 UTbSimpleSimpleInterfaceProxy::GetPropInt() const
{
	return service->GetPropInt();
}

void UTbSimpleSimpleInterfaceProxy::SetPropInt(int32 InPropInt)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropInt(InPropInt);
	service->SetPropInt(InPropInt);
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

float UTbSimpleSimpleInterfaceProxy::GetPropFloat() const
{
	return service->GetPropFloat();
}

void UTbSimpleSimpleInterfaceProxy::SetPropFloat(float InPropFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	service->SetPropFloat(InPropFloat);
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

FString UTbSimpleSimpleInterfaceProxy::GetPropString() const
{
	return service->GetPropString();
}

void UTbSimpleSimpleInterfaceProxy::SetPropString(const FString& InPropString)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropString(InPropString);
	service->SetPropString(InPropString);
}

FTbSimpleSimpleInterfacePropStringChangedDelegate& UTbSimpleSimpleInterfaceProxy::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

void UTbSimpleSimpleInterfaceProxy::FuncBool(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
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
bool UTbSimpleSimpleInterfaceProxy::FuncBool(bool bParamBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncBool(bParamBool);
	return service->FuncBool(bParamBool);
}
void UTbSimpleSimpleInterfaceProxy::FuncInt(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt)
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
int32 UTbSimpleSimpleInterfaceProxy::FuncInt(int32 ParamInt)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt(ParamInt);
	return service->FuncInt(ParamInt);
}
void UTbSimpleSimpleInterfaceProxy::FuncFloat(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat)
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
float UTbSimpleSimpleInterfaceProxy::FuncFloat(float ParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return service->FuncFloat(ParamFloat);
}
void UTbSimpleSimpleInterfaceProxy::FuncString(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString)
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
FString UTbSimpleSimpleInterfaceProxy::FuncString(const FString& ParamString)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncString(ParamString);
	return service->FuncString(ParamString);
}
