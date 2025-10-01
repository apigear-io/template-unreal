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
#include "TbRefIfaces/Generated/api/AbstractTbRefIfacesSimpleLocalIf.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

template <typename TAsyncResult>
class FTbRefIfacesSimpleLocalIfLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	TAtomic<bool> bCancelled{false};
	TFuture<TAsyncResult> Future;
	TAsyncResult* OutPtr;

public:
	FTbRefIfacesSimpleLocalIfLatentAction(const FLatentActionInfo& LatentInfo,
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

UAbstractTbRefIfacesSimpleLocalIf::UAbstractTbRefIfacesSimpleLocalIf()
{
	TbRefIfacesSimpleLocalIfPublisher = NewObject<UTbRefIfacesSimpleLocalIfPublisher>();
}

UTbRefIfacesSimpleLocalIfPublisher* UAbstractTbRefIfacesSimpleLocalIf::_GetPublisher()
{
	if (!TbRefIfacesSimpleLocalIfPublisher)
	{
		TbRefIfacesSimpleLocalIfPublisher = NewObject<UTbRefIfacesSimpleLocalIfPublisher>();
	}
	return TbRefIfacesSimpleLocalIfPublisher;
}

int32 UAbstractTbRefIfacesSimpleLocalIf::GetIntProperty_Private() const
{
	return GetIntProperty();
};

void UAbstractTbRefIfacesSimpleLocalIf::SetIntProperty_Private(int32 InIntProperty)
{
	SetIntProperty(InIntProperty);
};

void UAbstractTbRefIfacesSimpleLocalIf::IntMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbRefIfacesSimpleLocalIfLatentAction<int32>* oldRequest = LatentActionManager.FindExistingAction<FTbRefIfacesSimpleLocalIfLatentAction<int32>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<int32> Future = IntMethodAsync(Param);
		FTbRefIfacesSimpleLocalIfLatentAction<int32>* CompletionAction = new FTbRefIfacesSimpleLocalIfLatentAction<int32>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<int32> UAbstractTbRefIfacesSimpleLocalIf::IntMethodAsync(int32 Param)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param, this]()
		{
		return IntMethod(Param);
	});
}

void UAbstractTbRefIfacesSimpleLocalIf::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbRefIfacesSimpleLocalIf::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbRefIfacesSimpleLocalIfPublisher)
	{
		TbRefIfacesSimpleLocalIfPublisher->OnIntSignalSignal.RemoveAll(TbRefIfacesSimpleLocalIfPublisher);
		TbRefIfacesSimpleLocalIfPublisher->OnIntSignalSignalBP.RemoveAll(TbRefIfacesSimpleLocalIfPublisher);

		TbRefIfacesSimpleLocalIfPublisher->OnIntPropertyChanged.RemoveAll(TbRefIfacesSimpleLocalIfPublisher);
		TbRefIfacesSimpleLocalIfPublisher->OnIntPropertyChangedBP.RemoveAll(TbRefIfacesSimpleLocalIfPublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbRefIfacesSimpleLocalIf::IsInitialized() const
{
	return bInitialized;
}
