
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
#include "Generated/Monitor/TbEnumEnumInterfaceLoggingDecorator.h"
#include "Implementation/TbEnumEnumInterface.h"
#include "TbEnum.trace.h"
#include "TbEnumFactory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbEnumEnumInterfaceLoggingDecorator);

class FTbEnumEnumInterfaceLoggingLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbEnumEnumInterfaceLoggingLatentAction(const FLatentActionInfo& LatentInfo)
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
UTbEnumEnumInterfaceLoggingDecorator::UTbEnumEnumInterfaceLoggingDecorator()
	: UAbstractTbEnumEnumInterface()
{
}

UTbEnumEnumInterfaceLoggingDecorator::~UTbEnumEnumInterfaceLoggingDecorator() = default;

void UTbEnumEnumInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService(FTbEnumModuleFactory::createITbEnumEnumInterfaceInterface(GetGameInstance(), Collection));
#else
	setBackendService(FTbEnumModuleFactory::createITbEnumEnumInterfaceInterface(Collection));
#endif
}

void UTbEnumEnumInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbEnumEnumInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbEnumEnumInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetProp0ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp0Changed);
		BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp1Changed);
		BackendService->GetProp2ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp2Changed);
		BackendService->GetProp3ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp3Changed);
		BackendService->GetSig0SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig0);
		BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig1);
		BackendService->GetSig2SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig2);
		BackendService->GetSig3SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig3);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbEnumEnumInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetProp0ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp0Changed);
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp2Changed);
	BackendService->GetProp3ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp3Changed);
	BackendService->GetSig0SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig0);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig2);
	BackendService->GetSig3SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig3);
	// populate service state to proxy
	Prop0 = BackendService->Execute_GetProp0(BackendService.GetObject());
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());
	Prop3 = BackendService->Execute_GetProp3(BackendService.GetObject());
}

void UTbEnumEnumInterfaceLoggingDecorator::OnSig0(ETbEnumEnum0 Param0)
{
	TbEnumEnumInterfaceTracer::trace_signalSig0(Param0);
	Execute_BroadcastSig0(this, Param0);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnSig1(ETbEnumEnum1 Param1)
{
	TbEnumEnumInterfaceTracer::trace_signalSig1(Param1);
	Execute_BroadcastSig1(this, Param1);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnSig2(ETbEnumEnum2 Param2)
{
	TbEnumEnumInterfaceTracer::trace_signalSig2(Param2);
	Execute_BroadcastSig2(this, Param2);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnSig3(ETbEnumEnum3 Param3)
{
	TbEnumEnumInterfaceTracer::trace_signalSig3(Param3);
	Execute_BroadcastSig3(this, Param3);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnProp0Changed(ETbEnumEnum0 InProp0)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop0 = InProp0;
	Execute_BroadcastProp0Changed(this, InProp0);
}

ETbEnumEnum0 UTbEnumEnumInterfaceLoggingDecorator::GetProp0_Implementation() const
{
	return BackendService->Execute_GetProp0(BackendService.GetObject());
}

void UTbEnumEnumInterfaceLoggingDecorator::SetProp0_Implementation(ETbEnumEnum0 InProp0)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp0(InProp0);
	BackendService->Execute_SetProp0(BackendService.GetObject(), InProp0);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnProp1Changed(ETbEnumEnum1 InProp1)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute_BroadcastProp1Changed(this, InProp1);
}

ETbEnumEnum1 UTbEnumEnumInterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTbEnumEnumInterfaceLoggingDecorator::SetProp1_Implementation(ETbEnumEnum1 InProp1)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnProp2Changed(ETbEnumEnum2 InProp2)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Execute_BroadcastProp2Changed(this, InProp2);
}

ETbEnumEnum2 UTbEnumEnumInterfaceLoggingDecorator::GetProp2_Implementation() const
{
	return BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTbEnumEnumInterfaceLoggingDecorator::SetProp2_Implementation(ETbEnumEnum2 InProp2)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnProp3Changed(ETbEnumEnum3 InProp3)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop3 = InProp3;
	Execute_BroadcastProp3Changed(this, InProp3);
}

ETbEnumEnum3 UTbEnumEnumInterfaceLoggingDecorator::GetProp3_Implementation() const
{
	return BackendService->Execute_GetProp3(BackendService.GetObject());
}

void UTbEnumEnumInterfaceLoggingDecorator::SetProp3_Implementation(ETbEnumEnum3 InProp3)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp3(InProp3);
	BackendService->Execute_SetProp3(BackendService.GetObject(), InProp3);
}

void UTbEnumEnumInterfaceLoggingDecorator::Func0Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0)
{
	TbEnumEnumInterfaceTracer::trace_callFunc0(Param0);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLoggingLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLoggingLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbEnumEnumInterfaceLoggingLatentAction* CompletionAction = new FTbEnumEnumInterfaceLoggingLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param0, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func0(BackendService.GetObject(), Param0);
				CompletionAction->Cancel();
			});
	}
}

ETbEnumEnum0 UTbEnumEnumInterfaceLoggingDecorator::Func0_Implementation(ETbEnumEnum0 Param0)
{
	TbEnumEnumInterfaceTracer::trace_callFunc0(Param0);
	return BackendService->Execute_Func0(BackendService.GetObject(), Param0);
}

void UTbEnumEnumInterfaceLoggingDecorator::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1)
{
	TbEnumEnumInterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLoggingLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLoggingLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbEnumEnumInterfaceLoggingLatentAction* CompletionAction = new FTbEnumEnumInterfaceLoggingLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
				CompletionAction->Cancel();
			});
	}
}

ETbEnumEnum1 UTbEnumEnumInterfaceLoggingDecorator::Func1_Implementation(ETbEnumEnum1 Param1)
{
	TbEnumEnumInterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}

void UTbEnumEnumInterfaceLoggingDecorator::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2)
{
	TbEnumEnumInterfaceTracer::trace_callFunc2(Param2);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLoggingLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLoggingLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbEnumEnumInterfaceLoggingLatentAction* CompletionAction = new FTbEnumEnumInterfaceLoggingLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param2, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func2(BackendService.GetObject(), Param2);
				CompletionAction->Cancel();
			});
	}
}

ETbEnumEnum2 UTbEnumEnumInterfaceLoggingDecorator::Func2_Implementation(ETbEnumEnum2 Param2)
{
	TbEnumEnumInterfaceTracer::trace_callFunc2(Param2);
	return BackendService->Execute_Func2(BackendService.GetObject(), Param2);
}

void UTbEnumEnumInterfaceLoggingDecorator::Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3)
{
	TbEnumEnumInterfaceTracer::trace_callFunc3(Param3);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLoggingLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLoggingLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbEnumEnumInterfaceLoggingLatentAction* CompletionAction = new FTbEnumEnumInterfaceLoggingLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param3, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func3(BackendService.GetObject(), Param3);
				CompletionAction->Cancel();
			});
	}
}

ETbEnumEnum3 UTbEnumEnumInterfaceLoggingDecorator::Func3_Implementation(ETbEnumEnum3 Param3)
{
	TbEnumEnumInterfaceTracer::trace_callFunc3(Param3);
	return BackendService->Execute_Func3(BackendService.GetObject(), Param3);
}
