
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
#include "Testbed1StructArrayInterfaceProxy.h"
#include "StructArrayInterface/Testbed1StructArrayInterfaceLocal.h"
#include "apig/Testbed1.trace.h"
#include "Testbed1Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

class FTestbed1StructArrayInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed1StructArrayInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTestbed1StructArrayInterfaceProxy::UTestbed1StructArrayInterfaceProxy()
	: ITestbed1StructArrayInterfaceInterface()
	, PropBool(TArray<FTestbed1StructBool>())
	, PropInt(TArray<FTestbed1StructInt>())
	, PropFloat(TArray<FTestbed1StructFloat>())
	, PropString(TArray<FTestbed1StructString>())
{
	service = FTestbed1ModuleFactory::createITestbed1StructArrayInterfaceInterface();
	service->GetPropBoolChangedDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnPropBoolChanged);
	service->GetPropIntChangedDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnPropIntChanged);
	service->GetPropFloatChangedDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnPropFloatChanged);
	service->GetPropStringChangedDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnPropStringChanged);
	service->GetSigBoolSignalDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnSigBool);
	service->GetSigIntSignalDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnSigInt);
	service->GetSigFloatSignalDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnSigFloat);
	service->GetSigStringSignalDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnSigString);
}

UTestbed1StructArrayInterfaceProxy::~UTestbed1StructArrayInterfaceProxy()
{
	service->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnPropBoolChanged);
	service->GetPropIntChangedDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnPropIntChanged);
	service->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnPropFloatChanged);
	service->GetPropStringChangedDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnPropStringChanged);
	service->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnSigBool);
	service->GetSigIntSignalDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnSigInt);
	service->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnSigFloat);
	service->GetSigStringSignalDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceProxy::OnSigString);
}
void UTestbed1StructArrayInterfaceProxy::OnSigBool(const TArray<FTestbed1StructBool>& ParamBool)
{
	Testbed1StructArrayInterfaceTracer::trace_signalSigBool(ParamBool);
	SigBoolSignal.Broadcast(ParamBool);
}

FTestbed1StructArrayInterfaceSigBoolDelegate& UTestbed1StructArrayInterfaceProxy::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTestbed1StructArrayInterfaceProxy::OnSigInt(const TArray<FTestbed1StructInt>& ParamInt)
{
	Testbed1StructArrayInterfaceTracer::trace_signalSigInt(ParamInt);
	SigIntSignal.Broadcast(ParamInt);
}

FTestbed1StructArrayInterfaceSigIntDelegate& UTestbed1StructArrayInterfaceProxy::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTestbed1StructArrayInterfaceProxy::OnSigFloat(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	Testbed1StructArrayInterfaceTracer::trace_signalSigFloat(ParamFloat);
	SigFloatSignal.Broadcast(ParamFloat);
}

FTestbed1StructArrayInterfaceSigFloatDelegate& UTestbed1StructArrayInterfaceProxy::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTestbed1StructArrayInterfaceProxy::OnSigString(const TArray<FTestbed1StructString>& ParamString)
{
	Testbed1StructArrayInterfaceTracer::trace_signalSigString(ParamString);
	SigStringSignal.Broadcast(ParamString);
}

FTestbed1StructArrayInterfaceSigStringDelegate& UTestbed1StructArrayInterfaceProxy::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTestbed1StructArrayInterfaceProxy::OnPropBoolChanged(const TArray<FTestbed1StructBool>& InPropBool)
{
	Testbed1StructArrayInterfaceTracer::capture_state(this);
	PropBoolChanged.Broadcast(InPropBool);
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceProxy::GetPropBool() const
{
	return service->GetPropBool();
}

void UTestbed1StructArrayInterfaceProxy::SetPropBool(const TArray<FTestbed1StructBool>& InPropBool)
{
	Testbed1StructArrayInterfaceTracer::trace_callSetPropBool(InPropBool);
	service->SetPropBool(InPropBool);
}

FTestbed1StructArrayInterfacePropBoolChangedDelegate& UTestbed1StructArrayInterfaceProxy::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTestbed1StructArrayInterfaceProxy::OnPropIntChanged(const TArray<FTestbed1StructInt>& InPropInt)
{
	Testbed1StructArrayInterfaceTracer::capture_state(this);
	PropIntChanged.Broadcast(InPropInt);
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceProxy::GetPropInt() const
{
	return service->GetPropInt();
}

void UTestbed1StructArrayInterfaceProxy::SetPropInt(const TArray<FTestbed1StructInt>& InPropInt)
{
	Testbed1StructArrayInterfaceTracer::trace_callSetPropInt(InPropInt);
	service->SetPropInt(InPropInt);
}

FTestbed1StructArrayInterfacePropIntChangedDelegate& UTestbed1StructArrayInterfaceProxy::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTestbed1StructArrayInterfaceProxy::OnPropFloatChanged(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	Testbed1StructArrayInterfaceTracer::capture_state(this);
	PropFloatChanged.Broadcast(InPropFloat);
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceProxy::GetPropFloat() const
{
	return service->GetPropFloat();
}

void UTestbed1StructArrayInterfaceProxy::SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	Testbed1StructArrayInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	service->SetPropFloat(InPropFloat);
}

FTestbed1StructArrayInterfacePropFloatChangedDelegate& UTestbed1StructArrayInterfaceProxy::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTestbed1StructArrayInterfaceProxy::OnPropStringChanged(const TArray<FTestbed1StructString>& InPropString)
{
	Testbed1StructArrayInterfaceTracer::capture_state(this);
	PropStringChanged.Broadcast(InPropString);
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceProxy::GetPropString() const
{
	return service->GetPropString();
}

void UTestbed1StructArrayInterfaceProxy::SetPropString(const TArray<FTestbed1StructString>& InPropString)
{
	Testbed1StructArrayInterfaceTracer::trace_callSetPropString(InPropString);
	service->SetPropString(InPropString);
}

FTestbed1StructArrayInterfacePropStringChangedDelegate& UTestbed1StructArrayInterfaceProxy::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

void UTestbed1StructArrayInterfaceProxy::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructBool>& ParamBool)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncBool(ParamBool);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructArrayInterfaceLatentAction* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamBool, this, &Result, CompletionAction]()
			{
				Result = service->FuncBool(ParamBool);
				CompletionAction->Cancel();
			});
	}
}
FTestbed1StructBool UTestbed1StructArrayInterfaceProxy::FuncBool(const TArray<FTestbed1StructBool>& ParamBool)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncBool(ParamBool);
	return service->FuncBool(ParamBool);
}
void UTestbed1StructArrayInterfaceProxy::FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructInt>& ParamInt)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncInt(ParamInt);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructArrayInterfaceLatentAction* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamInt, this, &Result, CompletionAction]()
			{
				Result = service->FuncInt(ParamInt);
				CompletionAction->Cancel();
			});
	}
}
FTestbed1StructBool UTestbed1StructArrayInterfaceProxy::FuncInt(const TArray<FTestbed1StructInt>& ParamInt)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncInt(ParamInt);
	return service->FuncInt(ParamInt);
}
void UTestbed1StructArrayInterfaceProxy::FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructFloat>& ParamFloat)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncFloat(ParamFloat);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructArrayInterfaceLatentAction* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamFloat, this, &Result, CompletionAction]()
			{
				Result = service->FuncFloat(ParamFloat);
				CompletionAction->Cancel();
			});
	}
}
FTestbed1StructBool UTestbed1StructArrayInterfaceProxy::FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return service->FuncFloat(ParamFloat);
}
void UTestbed1StructArrayInterfaceProxy::FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructString>& ParamString)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncString(ParamString);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed1StructArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed1StructArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed1StructArrayInterfaceLatentAction* CompletionAction = new FTestbed1StructArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamString, this, &Result, CompletionAction]()
			{
				Result = service->FuncString(ParamString);
				CompletionAction->Cancel();
			});
	}
}
FTestbed1StructBool UTestbed1StructArrayInterfaceProxy::FuncString(const TArray<FTestbed1StructString>& ParamString)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncString(ParamString);
	return service->FuncString(ParamString);
}
