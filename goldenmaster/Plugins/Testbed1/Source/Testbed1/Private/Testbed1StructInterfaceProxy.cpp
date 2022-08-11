
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
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

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

    void Cancel() {
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
    service = FTestbed1ModuleFactory::createITestbed1StructInterfaceInterface();
    service->GetPropBoolChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnPropBoolChanged);
    service->GetPropIntChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnPropIntChanged);
    service->GetPropFloatChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnPropFloatChanged);
    service->GetPropStringChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnPropStringChanged);
    service->GetSigBoolSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnSigBool);
    service->GetSigIntSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnSigInt);
    service->GetSigFloatSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnSigFloat);
    service->GetSigStringSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceProxy::OnSigString);
}

UTestbed1StructInterfaceProxy::~UTestbed1StructInterfaceProxy()
{
    service->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnPropBoolChanged);
    service->GetPropIntChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnPropIntChanged);
    service->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnPropFloatChanged);
    service->GetPropStringChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnPropStringChanged);
    service->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnSigBool);
    service->GetSigIntSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnSigInt);
    service->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnSigFloat);
    service->GetSigStringSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceProxy::OnSigString);
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
    Testbed1StructInterfaceTracer::capture_state(this);
    PropBoolChanged.Broadcast(InPropBool);
}

FTestbed1StructBool UTestbed1StructInterfaceProxy::GetPropBool() const
{
    return service->GetPropBool();
}

void UTestbed1StructInterfaceProxy::SetPropBool(const FTestbed1StructBool& InPropBool)
{
    Testbed1StructInterfaceTracer::trace_callSetPropBool(InPropBool);
    service->SetPropBool(InPropBool);
}

FTestbed1StructInterfacePropBoolChangedDelegate& UTestbed1StructInterfaceProxy::GetPropBoolChangedDelegate()
{
    return PropBoolChanged;
}

void UTestbed1StructInterfaceProxy::OnPropIntChanged(const FTestbed1StructInt& InPropInt)
{
    Testbed1StructInterfaceTracer::capture_state(this);
    PropIntChanged.Broadcast(InPropInt);
}

FTestbed1StructInt UTestbed1StructInterfaceProxy::GetPropInt() const
{
    return service->GetPropInt();
}

void UTestbed1StructInterfaceProxy::SetPropInt(const FTestbed1StructInt& InPropInt)
{
    Testbed1StructInterfaceTracer::trace_callSetPropInt(InPropInt);
    service->SetPropInt(InPropInt);
}

FTestbed1StructInterfacePropIntChangedDelegate& UTestbed1StructInterfaceProxy::GetPropIntChangedDelegate()
{
    return PropIntChanged;
}

void UTestbed1StructInterfaceProxy::OnPropFloatChanged(const FTestbed1StructFloat& InPropFloat)
{
    Testbed1StructInterfaceTracer::capture_state(this);
    PropFloatChanged.Broadcast(InPropFloat);
}

FTestbed1StructFloat UTestbed1StructInterfaceProxy::GetPropFloat() const
{
    return service->GetPropFloat();
}

void UTestbed1StructInterfaceProxy::SetPropFloat(const FTestbed1StructFloat& InPropFloat)
{
    Testbed1StructInterfaceTracer::trace_callSetPropFloat(InPropFloat);
    service->SetPropFloat(InPropFloat);
}

FTestbed1StructInterfacePropFloatChangedDelegate& UTestbed1StructInterfaceProxy::GetPropFloatChangedDelegate()
{
    return PropFloatChanged;
}

void UTestbed1StructInterfaceProxy::OnPropStringChanged(const FTestbed1StructString& InPropString)
{
    Testbed1StructInterfaceTracer::capture_state(this);
    PropStringChanged.Broadcast(InPropString);
}

FTestbed1StructString UTestbed1StructInterfaceProxy::GetPropString() const
{
    return service->GetPropString();
}

void UTestbed1StructInterfaceProxy::SetPropString(const FTestbed1StructString& InPropString)
{
    Testbed1StructInterfaceTracer::trace_callSetPropString(InPropString);
    service->SetPropString(InPropString);
}

FTestbed1StructInterfacePropStringChangedDelegate& UTestbed1StructInterfaceProxy::GetPropStringChangedDelegate()
{
    return PropStringChanged;
}

void UTestbed1StructInterfaceProxy::FuncBool(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result,const FTestbed1StructBool& ParamBool)
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
        Async(EAsyncExecution::Thread, [ParamBool,this, &Result, CompletionAction]()
        {
            Result = service->FuncBool(ParamBool);
            CompletionAction->Cancel();
        });
	}
}
FTestbed1StructBool UTestbed1StructInterfaceProxy::FuncBool(const FTestbed1StructBool& ParamBool)
{
    Testbed1StructInterfaceTracer::trace_callFuncBool(ParamBool);
    return service->FuncBool(ParamBool);
}
void UTestbed1StructInterfaceProxy::FuncInt(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result,const FTestbed1StructInt& ParamInt)
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
        Async(EAsyncExecution::Thread, [ParamInt,this, &Result, CompletionAction]()
        {
            Result = service->FuncInt(ParamInt);
            CompletionAction->Cancel();
        });
	}
}
FTestbed1StructBool UTestbed1StructInterfaceProxy::FuncInt(const FTestbed1StructInt& ParamInt)
{
    Testbed1StructInterfaceTracer::trace_callFuncInt(ParamInt);
    return service->FuncInt(ParamInt);
}
void UTestbed1StructInterfaceProxy::FuncFloat(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result,const FTestbed1StructFloat& ParamFloat)
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
        Async(EAsyncExecution::Thread, [ParamFloat,this, &Result, CompletionAction]()
        {
            Result = service->FuncFloat(ParamFloat);
            CompletionAction->Cancel();
        });
	}
}
FTestbed1StructFloat UTestbed1StructInterfaceProxy::FuncFloat(const FTestbed1StructFloat& ParamFloat)
{
    Testbed1StructInterfaceTracer::trace_callFuncFloat(ParamFloat);
    return service->FuncFloat(ParamFloat);
}
void UTestbed1StructInterfaceProxy::FuncString(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result,const FTestbed1StructString& ParamString)
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
        Async(EAsyncExecution::Thread, [ParamString,this, &Result, CompletionAction]()
        {
            Result = service->FuncString(ParamString);
            CompletionAction->Cancel();
        });
	}
}
FTestbed1StructString UTestbed1StructInterfaceProxy::FuncString(const FTestbed1StructString& ParamString)
{
    Testbed1StructInterfaceTracer::trace_callFuncString(ParamString);
    return service->FuncString(ParamString);
}
