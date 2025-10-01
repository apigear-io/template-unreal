/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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
#include "TbSimple/Generated/api/AbstractTbSimpleNoPropertiesInterface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

template <typename TAsyncResult>
class FTbSimpleNoPropertiesInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	TAtomic<bool> bCancelled{false};
	TFuture<TAsyncResult> Future;
	TAsyncResult* OutPtr;

public:
	FTbSimpleNoPropertiesInterfaceLatentAction(const FLatentActionInfo& LatentInfo,
		TFuture<TAsyncResult>&& InFuture,
		TAsyncResult& ResultReference)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, Future(MoveTemp(InFuture))
		, OutPtr(&ResultReference)
	{
	}

	void Cancel()
	{
		bCancelled.Store(true);
	}

	void UpdateOperation(FLatentResponse& Response) override
	{
		if (bCancelled.Load())
		{
			Response.DoneIf(true);
			return;
		}

		if (Future.IsReady())
		{
			*OutPtr = Future.Get();
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
	}

	void NotifyObjectDestroyed() override
	{
		Cancel();
	}

	void NotifyActionAborted() override
	{
		Cancel();
	}
};

UAbstractTbSimpleNoPropertiesInterface::UAbstractTbSimpleNoPropertiesInterface()
{
	TbSimpleNoPropertiesInterfacePublisher = NewObject<UTbSimpleNoPropertiesInterfacePublisher>();
}

UTbSimpleNoPropertiesInterfacePublisher* UAbstractTbSimpleNoPropertiesInterface::_GetPublisher()
{
	if (!TbSimpleNoPropertiesInterfacePublisher)
	{
		TbSimpleNoPropertiesInterfacePublisher = NewObject<UTbSimpleNoPropertiesInterfacePublisher>();
	}
	return TbSimpleNoPropertiesInterfacePublisher;
}

void UAbstractTbSimpleNoPropertiesInterface::FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleNoPropertiesInterfaceLatentAction<bool>* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleNoPropertiesInterfaceLatentAction<bool>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<bool> Future = FuncBoolAsync(bParamBool);
		FTbSimpleNoPropertiesInterfaceLatentAction<bool>* CompletionAction = new FTbSimpleNoPropertiesInterfaceLatentAction<bool>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<bool> UAbstractTbSimpleNoPropertiesInterface::FuncBoolAsync(bool bParamBool)
{
	return Async(EAsyncExecution::ThreadPool,
		[bParamBool, this]()
		{
		return FuncBool(bParamBool);
	});
}

void UAbstractTbSimpleNoPropertiesInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSimpleNoPropertiesInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSimpleNoPropertiesInterfacePublisher)
	{
		TbSimpleNoPropertiesInterfacePublisher->OnSigVoidSignal.RemoveAll(TbSimpleNoPropertiesInterfacePublisher);
		TbSimpleNoPropertiesInterfacePublisher->OnSigVoidSignalBP.RemoveAll(TbSimpleNoPropertiesInterfacePublisher);
		TbSimpleNoPropertiesInterfacePublisher->OnSigBoolSignal.RemoveAll(TbSimpleNoPropertiesInterfacePublisher);
		TbSimpleNoPropertiesInterfacePublisher->OnSigBoolSignalBP.RemoveAll(TbSimpleNoPropertiesInterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbSimpleNoPropertiesInterface::IsInitialized() const
{
	return bInitialized;
}
