
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
#include "Generated/Monitor/Testbed2NestedStruct3InterfaceLoggingDecorator.h"
#include "Implementation/Testbed2NestedStruct3Interface.h"
#include "Testbed2.trace.h"
#include "Testbed2Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(LogTestbed2NestedStruct3InterfaceLoggingDecorator);

class FTestbed2NestedStruct3InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed2NestedStruct3InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTestbed2NestedStruct3InterfaceLoggingDecorator::UTestbed2NestedStruct3InterfaceLoggingDecorator()
	: ITestbed2NestedStruct3InterfaceInterface()
{
}

UTestbed2NestedStruct3InterfaceLoggingDecorator::~UTestbed2NestedStruct3InterfaceLoggingDecorator() = default;

void UTestbed2NestedStruct3InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	BackendService = FTestbed2ModuleFactory::createITestbed2NestedStruct3InterfaceInterface(GetGameInstance(), Collection);
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp2Changed);
	BackendService->GetProp3ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp3Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig2);
	BackendService->GetSig3SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig3);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp1Changed);
		BackendService->GetProp2ChangedDelegate().RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp2Changed);
		BackendService->GetProp3ChangedDelegate().RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp3Changed);
		BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig1);
		BackendService->GetSig2SignalDelegate().RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig2);
		BackendService->GetSig3SignalDelegate().RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig3);
	}

	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTestbed2NestedStruct3InterfaceLoggingDecorator, Error, TEXT("Cannot set backend service to %s - interface Testbed2NestedStruct3Interface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp2Changed);
	BackendService->GetProp3ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp3Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig2);
	BackendService->GetSig3SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig3);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());
	Prop3 = BackendService->Execute_GetProp3(BackendService.GetObject());
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig1(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct3InterfaceTracer::trace_signalSig1(Param1);
	Execute_BroadcastSig1(this, Param1);
}

FTestbed2NestedStruct3InterfaceSig1Delegate& UTestbed2NestedStruct3InterfaceLoggingDecorator::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::BroadcastSig2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Testbed2NestedStruct3InterfaceTracer::trace_signalSig2(Param1, Param2);
	Execute_BroadcastSig2(this, Param1, Param2);
}

FTestbed2NestedStruct3InterfaceSig2Delegate& UTestbed2NestedStruct3InterfaceLoggingDecorator::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::BroadcastSig3_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	Sig3Signal.Broadcast(Param1, Param2, Param3);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	Testbed2NestedStruct3InterfaceTracer::trace_signalSig3(Param1, Param2, Param3);
	Execute_BroadcastSig3(this, Param1, Param2, Param3);
}

FTestbed2NestedStruct3InterfaceSig3Delegate& UTestbed2NestedStruct3InterfaceLoggingDecorator::GetSig3SignalDelegate()
{
	return Sig3Signal;
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::BroadcastProp1Changed_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct3InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute_BroadcastProp1Changed(this, InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp1_Private() const
{
	return Execute_GetProp1(this);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::SetProp1_Private(const FTestbed2NestedStruct1& InProp1)
{
	Execute_SetProp1(this, InProp1);
}

FTestbed2NestedStruct3InterfaceProp1ChangedDelegate& UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::BroadcastProp2Changed_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	Prop2Changed.Broadcast(InProp2);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp2Changed(const FTestbed2NestedStruct2& InProp2)
{
	Testbed2NestedStruct3InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Execute_BroadcastProp2Changed(this, InProp2);
}

FTestbed2NestedStruct2 UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp2_Implementation() const
{
	return BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

FTestbed2NestedStruct2 UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp2_Private() const
{
	return Execute_GetProp2(this);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::SetProp2_Private(const FTestbed2NestedStruct2& InProp2)
{
	Execute_SetProp2(this, InProp2);
}

FTestbed2NestedStruct3InterfaceProp2ChangedDelegate& UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::BroadcastProp3Changed_Implementation(const FTestbed2NestedStruct3& InProp3)
{
	Prop3Changed.Broadcast(InProp3);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp3Changed(const FTestbed2NestedStruct3& InProp3)
{
	Testbed2NestedStruct3InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop3 = InProp3;
	Execute_BroadcastProp3Changed(this, InProp3);
}

FTestbed2NestedStruct3 UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp3_Implementation() const
{
	return BackendService->Execute_GetProp3(BackendService.GetObject());
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::SetProp3_Implementation(const FTestbed2NestedStruct3& InProp3)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callSetProp3(InProp3);
	BackendService->Execute_SetProp3(BackendService.GetObject(), InProp3);
}

FTestbed2NestedStruct3 UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp3_Private() const
{
	return Execute_GetProp3(this);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::SetProp3_Private(const FTestbed2NestedStruct3& InProp3)
{
	Execute_SetProp3(this, InProp3);
}

FTestbed2NestedStruct3InterfaceProp3ChangedDelegate& UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct3InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct3InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2NestedStruct3InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct3InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
				CompletionAction->Cancel();
			});
	}
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLoggingDecorator::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callFunc2(Param1, Param2);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct3InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct3InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2NestedStruct3InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct3InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
				CompletionAction->Cancel();
			});
	}
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLoggingDecorator::Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callFunc3(Param1, Param2, Param3);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct3InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct3InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2NestedStruct3InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct3InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, Param3, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func3(BackendService.GetObject(), Param1, Param2, Param3);
				CompletionAction->Cancel();
			});
	}
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLoggingDecorator::Func3_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callFunc3(Param1, Param2, Param3);
	return BackendService->Execute_Func3(BackendService.GetObject(), Param1, Param2, Param3);
}
