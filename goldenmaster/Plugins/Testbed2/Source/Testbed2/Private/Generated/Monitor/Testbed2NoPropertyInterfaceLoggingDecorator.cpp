
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
#include "Generated/Monitor/Testbed2NoPropertyInterfaceLoggingDecorator.h"
#include "Implementation/Testbed2NoPropertyInterface.h"
#include "Generated/api/Testbed2.trace.h"
#include "Testbed2Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(LogTestbed2NoPropertyInterfaceLoggingDecorator);

class FTestbed2NoPropertyInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed2NoPropertyInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTestbed2NoPropertyInterfaceLoggingDecorator::UTestbed2NoPropertyInterfaceLoggingDecorator()
	: ITestbed2NoPropertyInterfaceInterface()
{
}

UTestbed2NoPropertyInterfaceLoggingDecorator::~UTestbed2NoPropertyInterfaceLoggingDecorator() = default;

void UTestbed2NoPropertyInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase&)
{
	BackendService = FTestbed2ModuleFactory::createITestbed2NoPropertyInterfaceInterface();
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTestbed2NoPropertyInterfaceLoggingDecorator::OnSig1);
}

void UTestbed2NoPropertyInterfaceLoggingDecorator::Deinitialize()
{
	BackendService = nullptr;
}

void UTestbed2NoPropertyInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed2NoPropertyInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTestbed2NoPropertyInterfaceLoggingDecorator::OnSig1);
	}

	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTestbed2NoPropertyInterfaceLoggingDecorator, Error, TEXT("Cannot set backend service to %s - interface Testbed2NoPropertyInterface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTestbed2NoPropertyInterfaceLoggingDecorator::OnSig1);
	// populate service state to proxy
}
void UTestbed2NoPropertyInterfaceLoggingDecorator::BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

void UTestbed2NoPropertyInterfaceLoggingDecorator::OnSig1(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NoPropertyInterfaceTracer::trace_signalSig1(Param1);
	Execute_BroadcastSig1(this, Param1);
}

FTestbed2NoPropertyInterfaceSig1Delegate& UTestbed2NoPropertyInterfaceLoggingDecorator::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTestbed2NoPropertyInterfaceLoggingDecorator::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1)
{
	Testbed2NoPropertyInterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NoPropertyInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NoPropertyInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2NoPropertyInterfaceLatentAction* CompletionAction = new FTestbed2NoPropertyInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
				CompletionAction->Cancel();
			});
	}
}
FTestbed2NestedStruct1 UTestbed2NoPropertyInterfaceLoggingDecorator::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NoPropertyInterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}
