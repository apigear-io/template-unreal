
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
#include "Generated/Monitor/Testbed1StructInterfaceLoggingDecorator.h"
#include "Implementation/Testbed1StructInterface.h"
#include "Testbed1.trace.h"
#include "Testbed1Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(LogTestbed1StructInterfaceLoggingDecorator);

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
UTestbed1StructInterfaceLoggingDecorator::UTestbed1StructInterfaceLoggingDecorator()
	: UAbstractTestbed1StructInterface()
{
}

UTestbed1StructInterfaceLoggingDecorator::~UTestbed1StructInterfaceLoggingDecorator() = default;

void UTestbed1StructInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	BackendService = FTestbed1ModuleFactory::createITestbed1StructInterfaceInterface(GetGameInstance(), Collection);
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropIntChanged);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropFloatChanged);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropStringChanged);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigInt);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigFloat);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigString);
}

void UTestbed1StructInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTestbed1StructInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed1StructInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropBoolChanged);
		BackendService->GetPropIntChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropIntChanged);
		BackendService->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropFloatChanged);
		BackendService->GetPropStringChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropStringChanged);
		BackendService->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigBool);
		BackendService->GetSigIntSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigInt);
		BackendService->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigFloat);
		BackendService->GetSigStringSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigString);
	}

	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTestbed1StructInterfaceLoggingDecorator, Error, TEXT("Cannot set backend service to %s - interface Testbed1StructInterface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropIntChanged);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropFloatChanged);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropStringChanged);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigInt);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigFloat);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigString);
	// populate service state to proxy
	PropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
	PropFloat = BackendService->Execute_GetPropFloat(BackendService.GetObject());
	PropString = BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTestbed1StructInterfaceLoggingDecorator::OnSigBool(const FTestbed1StructBool& ParamBool)
{
	Testbed1StructInterfaceTracer::trace_signalSigBool(ParamBool);
	Execute_BroadcastSigBool(this, ParamBool);
}

void UTestbed1StructInterfaceLoggingDecorator::OnSigInt(const FTestbed1StructInt& ParamInt)
{
	Testbed1StructInterfaceTracer::trace_signalSigInt(ParamInt);
	Execute_BroadcastSigInt(this, ParamInt);
}

void UTestbed1StructInterfaceLoggingDecorator::OnSigFloat(const FTestbed1StructFloat& ParamFloat)
{
	Testbed1StructInterfaceTracer::trace_signalSigFloat(ParamFloat);
	Execute_BroadcastSigFloat(this, ParamFloat);
}

void UTestbed1StructInterfaceLoggingDecorator::OnSigString(const FTestbed1StructString& ParamString)
{
	Testbed1StructInterfaceTracer::trace_signalSigString(ParamString);
	Execute_BroadcastSigString(this, ParamString);
}

void UTestbed1StructInterfaceLoggingDecorator::OnPropBoolChanged(const FTestbed1StructBool& InPropBool)
{
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropBool = InPropBool;
	Execute_BroadcastPropBoolChanged(this, InPropBool);
}

FTestbed1StructBool UTestbed1StructInterfaceLoggingDecorator::GetPropBool_Implementation() const
{
	return BackendService->Execute_GetPropBool(BackendService.GetObject());
}

void UTestbed1StructInterfaceLoggingDecorator::SetPropBool_Implementation(const FTestbed1StructBool& InPropBool)
{
	Testbed1StructInterfaceTracer::trace_callSetPropBool(InPropBool);
	BackendService->Execute_SetPropBool(BackendService.GetObject(), InPropBool);
}

void UTestbed1StructInterfaceLoggingDecorator::OnPropIntChanged(const FTestbed1StructInt& InPropInt)
{
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	Execute_BroadcastPropIntChanged(this, InPropInt);
}

FTestbed1StructInt UTestbed1StructInterfaceLoggingDecorator::GetPropInt_Implementation() const
{
	return BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTestbed1StructInterfaceLoggingDecorator::SetPropInt_Implementation(const FTestbed1StructInt& InPropInt)
{
	Testbed1StructInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InPropInt);
}

void UTestbed1StructInterfaceLoggingDecorator::OnPropFloatChanged(const FTestbed1StructFloat& InPropFloat)
{
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	Execute_BroadcastPropFloatChanged(this, InPropFloat);
}

FTestbed1StructFloat UTestbed1StructInterfaceLoggingDecorator::GetPropFloat_Implementation() const
{
	return BackendService->Execute_GetPropFloat(BackendService.GetObject());
}

void UTestbed1StructInterfaceLoggingDecorator::SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	Testbed1StructInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->Execute_SetPropFloat(BackendService.GetObject(), InPropFloat);
}

void UTestbed1StructInterfaceLoggingDecorator::OnPropStringChanged(const FTestbed1StructString& InPropString)
{
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	Execute_BroadcastPropStringChanged(this, InPropString);
}

FTestbed1StructString UTestbed1StructInterfaceLoggingDecorator::GetPropString_Implementation() const
{
	return BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTestbed1StructInterfaceLoggingDecorator::SetPropString_Implementation(const FTestbed1StructString& InPropString)
{
	Testbed1StructInterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->Execute_SetPropString(BackendService.GetObject(), InPropString);
}

void UTestbed1StructInterfaceLoggingDecorator::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool)
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
				Result = BackendService->Execute_FuncBool(BackendService.GetObject(), ParamBool);
				CompletionAction->Cancel();
			});
	}
}

FTestbed1StructBool UTestbed1StructInterfaceLoggingDecorator::FuncBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	Testbed1StructInterfaceTracer::trace_callFuncBool(ParamBool);
	return BackendService->Execute_FuncBool(BackendService.GetObject(), ParamBool);
}

void UTestbed1StructInterfaceLoggingDecorator::FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt)
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
				Result = BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
				CompletionAction->Cancel();
			});
	}
}

FTestbed1StructBool UTestbed1StructInterfaceLoggingDecorator::FuncInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	Testbed1StructInterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
}

void UTestbed1StructInterfaceLoggingDecorator::FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat)
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
				Result = BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
				CompletionAction->Cancel();
			});
	}
}

FTestbed1StructFloat UTestbed1StructInterfaceLoggingDecorator::FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	Testbed1StructInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
}

void UTestbed1StructInterfaceLoggingDecorator::FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString)
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
				Result = BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
				CompletionAction->Cancel();
			});
	}
}

FTestbed1StructString UTestbed1StructInterfaceLoggingDecorator::FuncString_Implementation(const FTestbed1StructString& ParamString)
{
	Testbed1StructInterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
}
