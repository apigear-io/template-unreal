
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
#include "Generated/Monitor/Testbed2NestedStruct1InterfaceLoggingDecorator.h"
#include "Implementation/Testbed2NestedStruct1Interface.h"
#include "Testbed2.trace.h"
#include "Testbed2Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTestbed2NestedStruct1InterfaceLoggingDecorator);

class FTestbed2NestedStruct1InterfaceLoggingLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed2NestedStruct1InterfaceLoggingLatentAction(const FLatentActionInfo& LatentInfo)
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
UTestbed2NestedStruct1InterfaceLoggingDecorator::UTestbed2NestedStruct1InterfaceLoggingDecorator()
	: UAbstractTestbed2NestedStruct1Interface()
{
}

UTestbed2NestedStruct1InterfaceLoggingDecorator::~UTestbed2NestedStruct1InterfaceLoggingDecorator() = default;

void UTestbed2NestedStruct1InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService(FTestbed2ModuleFactory::createITestbed2NestedStruct1InterfaceInterface(GetGameInstance(), Collection));
#else
	setBackendService(FTestbed2ModuleFactory::createITestbed2NestedStruct1InterfaceInterface(Collection));
#endif
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTestbed2NestedStruct1InterfaceLoggingDecorator::OnProp1Changed);
		BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTestbed2NestedStruct1InterfaceLoggingDecorator::OnSig1);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed2NestedStruct1Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct1InterfaceLoggingDecorator::OnProp1Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct1InterfaceLoggingDecorator::OnSig1);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::OnSig1(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct1InterfaceTracer::trace_signalSig1(Param1);
	Execute_BroadcastSig1(this, Param1);
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct1InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute_BroadcastProp1Changed(this, InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct1InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct1InterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct1InterfaceLoggingLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct1InterfaceLoggingLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2NestedStruct1InterfaceLoggingLatentAction* CompletionAction = new FTestbed2NestedStruct1InterfaceLoggingLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
				CompletionAction->Cancel();
			});
	}
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceLoggingDecorator::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct1InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}
