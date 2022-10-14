
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
#include "Testbed1StructInterfaceProxy.h"
#include "StructInterface/Testbed1StructInterfaceLocal.h"
#include "apig/Testbed1.trace.h"
#include "Testbed1Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

class FTestbed1StructInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed1StructInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTestbed1StructInterfaceProxy::UTestbed1StructInterfaceProxy()
	: ITestbed1StructInterfaceInterface()
	, PropBool(FTestbed1StructBool())
	, PropInt(FTestbed1StructInt())
	, PropFloat(FTestbed1StructFloat())
	, PropString(FTestbed1StructString())
{
	BackendService = FTestbed1ModuleFactory::createITestbed1StructInterfaceInterface();
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnPropIntChanged);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnPropFloatChanged);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnPropStringChanged);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnSigInt);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnSigFloat);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnSigString);
}

UTestbed1StructInterfaceProxy::~UTestbed1StructInterfaceProxy()
{
	if (BackendService != nullptr)
	{
		//BackendService->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnPropBoolChanged);
		//BackendService->GetPropIntChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnPropIntChanged);
		//BackendService->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnPropFloatChanged);
		//BackendService->GetPropStringChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnPropStringChanged);
		//BackendService->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnSigBool);
		//BackendService->GetSigIntSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnSigInt);
		//BackendService->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnSigFloat);
		//BackendService->GetSigStringSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnSigString);
	}
}
void UTestbed1StructInterfaceProxy::OnSigBool(const FTestbed1StructBool& ParamBool)
{
	Testbed1StructInterfaceTracer::trace_signalSigBool(ParamBool);
	SigBoolSignal.Broadcast(ParamBool);
}

FTestbed1StructInterfaceSigBoolDelegate& UTestbed1StructInterfaceProxy::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTestbed1StructInterfaceProxy::OnSigInt(const FTestbed1StructInt& ParamInt)
{
	Testbed1StructInterfaceTracer::trace_signalSigInt(ParamInt);
	SigIntSignal.Broadcast(ParamInt);
}

FTestbed1StructInterfaceSigIntDelegate& UTestbed1StructInterfaceProxy::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTestbed1StructInterfaceProxy::OnSigFloat(const FTestbed1StructFloat& ParamFloat)
{
	Testbed1StructInterfaceTracer::trace_signalSigFloat(ParamFloat);
	SigFloatSignal.Broadcast(ParamFloat);
}

FTestbed1StructInterfaceSigFloatDelegate& UTestbed1StructInterfaceProxy::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTestbed1StructInterfaceProxy::OnSigString(const FTestbed1StructString& ParamString)
{
	Testbed1StructInterfaceTracer::trace_signalSigString(ParamString);
	SigStringSignal.Broadcast(ParamString);
}

FTestbed1StructInterfaceSigStringDelegate& UTestbed1StructInterfaceProxy::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTestbed1StructInterfaceProxy::OnPropBoolChanged(const FTestbed1StructBool& InPropBool)
{
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropBool = InPropBool;
	PropBoolChanged.Broadcast(InPropBool);
}

void UTestbed1StructInterfaceProxy::GetPropBool_Implementation(FTestbed1StructBool& ReturnValue) const
{
	BackendService->Execute_GetPropBool(BackendService.GetObject(), ReturnValue);
}

void UTestbed1StructInterfaceProxy::SetPropBool_Implementation(const FTestbed1StructBool& InPropBool)
{
	Testbed1StructInterfaceTracer::trace_callSetPropBool(InPropBool);
	BackendService->Execute_SetPropBool(BackendService.GetObject(), InPropBool);
}

FTestbed1StructBool UTestbed1StructInterfaceProxy::GetPropBool_Private() const
{
	FTestbed1StructBool outPropBool;
	Execute_GetPropBool(this, outPropBool);
	return outPropBool;
}

void UTestbed1StructInterfaceProxy::SetPropBool_Private(const FTestbed1StructBool& InPropBool)
{
	Execute_SetPropBool(this, InPropBool);
}

FTestbed1StructInterfacePropBoolChangedDelegate& UTestbed1StructInterfaceProxy::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTestbed1StructInterfaceProxy::OnPropIntChanged(const FTestbed1StructInt& InPropInt)
{
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	PropIntChanged.Broadcast(InPropInt);
}

void UTestbed1StructInterfaceProxy::GetPropInt_Implementation(FTestbed1StructInt& ReturnValue) const
{
	BackendService->Execute_GetPropInt(BackendService.GetObject(), ReturnValue);
}

void UTestbed1StructInterfaceProxy::SetPropInt_Implementation(const FTestbed1StructInt& InPropInt)
{
	Testbed1StructInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InPropInt);
}

FTestbed1StructInt UTestbed1StructInterfaceProxy::GetPropInt_Private() const
{
	FTestbed1StructInt outPropInt;
	Execute_GetPropInt(this, outPropInt);
	return outPropInt;
}

void UTestbed1StructInterfaceProxy::SetPropInt_Private(const FTestbed1StructInt& InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
}

FTestbed1StructInterfacePropIntChangedDelegate& UTestbed1StructInterfaceProxy::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTestbed1StructInterfaceProxy::OnPropFloatChanged(const FTestbed1StructFloat& InPropFloat)
{
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	PropFloatChanged.Broadcast(InPropFloat);
}

void UTestbed1StructInterfaceProxy::GetPropFloat_Implementation(FTestbed1StructFloat& ReturnValue) const
{
	BackendService->Execute_GetPropFloat(BackendService.GetObject(), ReturnValue);
}

void UTestbed1StructInterfaceProxy::SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	Testbed1StructInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->Execute_SetPropFloat(BackendService.GetObject(), InPropFloat);
}

FTestbed1StructFloat UTestbed1StructInterfaceProxy::GetPropFloat_Private() const
{
	FTestbed1StructFloat outPropFloat;
	Execute_GetPropFloat(this, outPropFloat);
	return outPropFloat;
}

void UTestbed1StructInterfaceProxy::SetPropFloat_Private(const FTestbed1StructFloat& InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
}

FTestbed1StructInterfacePropFloatChangedDelegate& UTestbed1StructInterfaceProxy::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTestbed1StructInterfaceProxy::OnPropStringChanged(const FTestbed1StructString& InPropString)
{
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	PropStringChanged.Broadcast(InPropString);
}

void UTestbed1StructInterfaceProxy::GetPropString_Implementation(FTestbed1StructString& ReturnValue) const
{
	BackendService->Execute_GetPropString(BackendService.GetObject(), ReturnValue);
}

void UTestbed1StructInterfaceProxy::SetPropString_Implementation(const FTestbed1StructString& InPropString)
{
	Testbed1StructInterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->Execute_SetPropString(BackendService.GetObject(), InPropString);
}

FTestbed1StructString UTestbed1StructInterfaceProxy::GetPropString_Private() const
{
	FTestbed1StructString outPropString;
	Execute_GetPropString(this, outPropString);
	return outPropString;
}

void UTestbed1StructInterfaceProxy::SetPropString_Private(const FTestbed1StructString& InPropString)
{
	Execute_SetPropString(this, InPropString);
}

FTestbed1StructInterfacePropStringChangedDelegate& UTestbed1StructInterfaceProxy::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

void UTestbed1StructInterfaceProxy::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool)
{
	Testbed1StructInterfaceTracer::trace_callFuncBool(ParamBool);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructInterfaceLatentAction* CompletionAction = new FTestbed1StructInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamBool, this, &Result, CompletionAction]()
			{
				BackendService->Execute_FuncBool(BackendService.GetObject(), Result, ParamBool);
				CompletionAction->Cancel();
			});
	}
}
void UTestbed1StructInterfaceProxy::FuncBool_Implementation(FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool)
{
	Testbed1StructInterfaceTracer::trace_callFuncBool(ParamBool);
	BackendService->Execute_FuncBool(BackendService.GetObject(), Result, ParamBool);
}
void UTestbed1StructInterfaceProxy::FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt)
{
	Testbed1StructInterfaceTracer::trace_callFuncInt(ParamInt);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructInterfaceLatentAction* CompletionAction = new FTestbed1StructInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamInt, this, &Result, CompletionAction]()
			{
				BackendService->Execute_FuncInt(BackendService.GetObject(), Result, ParamInt);
				CompletionAction->Cancel();
			});
	}
}
void UTestbed1StructInterfaceProxy::FuncInt_Implementation(FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt)
{
	Testbed1StructInterfaceTracer::trace_callFuncInt(ParamInt);
	BackendService->Execute_FuncInt(BackendService.GetObject(), Result, ParamInt);
}
void UTestbed1StructInterfaceProxy::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat)
{
	Testbed1StructInterfaceTracer::trace_callFuncFloat(ParamFloat);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructInterfaceLatentAction* CompletionAction = new FTestbed1StructInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamFloat, this, &Result, CompletionAction]()
			{
				BackendService->Execute_FuncFloat(BackendService.GetObject(), Result, ParamFloat);
				CompletionAction->Cancel();
			});
	}
}
void UTestbed1StructInterfaceProxy::FuncFloat_Implementation(FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat)
{
	Testbed1StructInterfaceTracer::trace_callFuncFloat(ParamFloat);
	BackendService->Execute_FuncFloat(BackendService.GetObject(), Result, ParamFloat);
}
void UTestbed1StructInterfaceProxy::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString)
{
	Testbed1StructInterfaceTracer::trace_callFuncString(ParamString);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructInterfaceLatentAction* CompletionAction = new FTestbed1StructInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamString, this, &Result, CompletionAction]()
			{
				BackendService->Execute_FuncString(BackendService.GetObject(), Result, ParamString);
				CompletionAction->Cancel();
			});
	}
}
void UTestbed1StructInterfaceProxy::FuncString_Implementation(FTestbed1StructString& Result, const FTestbed1StructString& ParamString)
{
	Testbed1StructInterfaceTracer::trace_callFuncString(ParamString);
	BackendService->Execute_FuncString(BackendService.GetObject(), Result, ParamString);
}
