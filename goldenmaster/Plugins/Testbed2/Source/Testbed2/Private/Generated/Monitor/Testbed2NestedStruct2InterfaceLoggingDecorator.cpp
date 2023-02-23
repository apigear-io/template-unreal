
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
#include "Generated/Monitor/Testbed2NestedStruct2InterfaceLoggingDecorator.h"
#include "Implementation/Testbed2NestedStruct2Interface.h"
#include "Testbed2.trace.h"
#include "Testbed2Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(LogTestbed2NestedStruct2InterfaceLoggingDecorator);

class FTestbed2NestedStruct2InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed2NestedStruct2InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTestbed2NestedStruct2InterfaceLoggingDecorator::UTestbed2NestedStruct2InterfaceLoggingDecorator()
	: UAbstractTestbed2NestedStruct2Interface()
{
}

UTestbed2NestedStruct2InterfaceLoggingDecorator::~UTestbed2NestedStruct2InterfaceLoggingDecorator() = default;

void UTestbed2NestedStruct2InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
	setBackendService(FTestbed2ModuleFactory::createITestbed2NestedStruct2InterfaceInterface(GetGameInstance(), Collection));
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	Super::Deinitialize();
	BackendService = nullptr;
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp1Changed);
		BackendService->GetProp2ChangedDelegate().RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp2Changed);
		BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig1);
		BackendService->GetSig2SignalDelegate().RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig2);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed2NestedStruct2Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp2Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig2);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig1(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct2InterfaceTracer::trace_signalSig1(Param1);
	Execute_BroadcastSig1(this, Param1);
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Testbed2NestedStruct2InterfaceTracer::trace_signalSig2(Param1, Param2);
	Execute_BroadcastSig2(this, Param1, Param2);
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute_BroadcastProp1Changed(this, InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp2Changed(const FTestbed2NestedStruct2& InProp2)
{
	Testbed2NestedStruct2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Execute_BroadcastProp2Changed(this, InProp2);
}

FTestbed2NestedStruct2 UTestbed2NestedStruct2InterfaceLoggingDecorator::GetProp2_Implementation() const
{
	return BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2NestedStruct2InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
				CompletionAction->Cancel();
			});
	}
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceLoggingDecorator::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callFunc2(Param1, Param2);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2NestedStruct2InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
				CompletionAction->Cancel();
			});
	}
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceLoggingDecorator::Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
}
