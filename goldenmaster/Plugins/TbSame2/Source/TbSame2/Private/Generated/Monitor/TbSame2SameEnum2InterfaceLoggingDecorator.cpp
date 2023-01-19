
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
#include "Generated/Monitor/TbSame2SameEnum2InterfaceLoggingDecorator.h"
#include "Implementation/TbSame2SameEnum2Interface.h"
#include "TbSame2.trace.h"
#include "TbSame2Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(LogTbSame2SameEnum2InterfaceLoggingDecorator);

class FTbSame2SameEnum2InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSame2SameEnum2InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTbSame2SameEnum2InterfaceLoggingDecorator::UTbSame2SameEnum2InterfaceLoggingDecorator()
	: ITbSame2SameEnum2InterfaceInterface()
{
}

UTbSame2SameEnum2InterfaceLoggingDecorator::~UTbSame2SameEnum2InterfaceLoggingDecorator() = default;

void UTbSame2SameEnum2InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	BackendService = FTbSame2ModuleFactory::createITbSame2SameEnum2InterfaceInterface(GetGameInstance(), Collection);
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp2Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig2);
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSame2SameEnum2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp1Changed);
		BackendService->GetProp2ChangedDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp2Changed);
		BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig1);
		BackendService->GetSig2SignalDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig2);
	}

	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTbSame2SameEnum2InterfaceLoggingDecorator, Error, TEXT("Cannot set backend service to %s - interface TbSame2SameEnum2Interface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp2Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig2);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());
}
void UTbSame2SameEnum2InterfaceLoggingDecorator::BroadcastSig1_Implementation(const ETbSame2Enum1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig1(const ETbSame2Enum1& Param1)
{
	TbSame2SameEnum2InterfaceTracer::trace_signalSig1(Param1);
	Execute_BroadcastSig1(this, Param1);
}

FTbSame2SameEnum2InterfaceSig1Delegate& UTbSame2SameEnum2InterfaceLoggingDecorator::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::BroadcastSig2_Implementation(const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig2(const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2)
{
	TbSame2SameEnum2InterfaceTracer::trace_signalSig2(Param1, Param2);
	Execute_BroadcastSig2(this, Param1, Param2);
}

FTbSame2SameEnum2InterfaceSig2Delegate& UTbSame2SameEnum2InterfaceLoggingDecorator::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::BroadcastProp1Changed_Implementation(const ETbSame2Enum1& InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp1Changed(const ETbSame2Enum1& InProp1)
{
	TbSame2SameEnum2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute_BroadcastProp1Changed(this, InProp1);
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::SetProp1_Implementation(const ETbSame2Enum1& InProp1)
{
	TbSame2SameEnum2InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceLoggingDecorator::GetProp1_Private() const
{
	return Execute_GetProp1(this);
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::SetProp1_Private(const ETbSame2Enum1& InProp1)
{
	Execute_SetProp1(this, InProp1);
}

FTbSame2SameEnum2InterfaceProp1ChangedDelegate& UTbSame2SameEnum2InterfaceLoggingDecorator::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::BroadcastProp2Changed_Implementation(const ETbSame2Enum2& InProp2)
{
	Prop2Changed.Broadcast(InProp2);
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp2Changed(const ETbSame2Enum2& InProp2)
{
	TbSame2SameEnum2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Execute_BroadcastProp2Changed(this, InProp2);
}

ETbSame2Enum2 UTbSame2SameEnum2InterfaceLoggingDecorator::GetProp2_Implementation() const
{
	return BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::SetProp2_Implementation(const ETbSame2Enum2& InProp2)
{
	TbSame2SameEnum2InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

ETbSame2Enum2 UTbSame2SameEnum2InterfaceLoggingDecorator::GetProp2_Private() const
{
	return Execute_GetProp2(this);
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::SetProp2_Private(const ETbSame2Enum2& InProp2)
{
	Execute_SetProp2(this, InProp2);
}

FTbSame2SameEnum2InterfaceProp2ChangedDelegate& UTbSame2SameEnum2InterfaceLoggingDecorator::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, const ETbSame2Enum1& Param1)
{
	TbSame2SameEnum2InterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameEnum2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameEnum2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame2SameEnum2InterfaceLatentAction* CompletionAction = new FTbSame2SameEnum2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
				CompletionAction->Cancel();
			});
	}
}
ETbSame2Enum1 UTbSame2SameEnum2InterfaceLoggingDecorator::Func1_Implementation(const ETbSame2Enum1& Param1)
{
	TbSame2SameEnum2InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}
void UTbSame2SameEnum2InterfaceLoggingDecorator::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2)
{
	TbSame2SameEnum2InterfaceTracer::trace_callFunc2(Param1, Param2);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameEnum2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameEnum2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame2SameEnum2InterfaceLatentAction* CompletionAction = new FTbSame2SameEnum2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
				CompletionAction->Cancel();
			});
	}
}
ETbSame2Enum1 UTbSame2SameEnum2InterfaceLoggingDecorator::Func2_Implementation(const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2)
{
	TbSame2SameEnum2InterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
}
