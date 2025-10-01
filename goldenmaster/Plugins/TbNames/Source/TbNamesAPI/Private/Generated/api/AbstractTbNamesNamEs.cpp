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
#include "TbNames/Generated/api/AbstractTbNamesNamEs.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

template <typename TAsyncResult>
class FTbNamesNamEsLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	TAtomic<bool> bCancelled{false};
	TFuture<TAsyncResult> Future;
	TAsyncResult* OutPtr;

public:
	FTbNamesNamEsLatentAction(const FLatentActionInfo& LatentInfo,
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

UAbstractTbNamesNamEs::UAbstractTbNamesNamEs()
{
	TbNamesNamEsPublisher = NewObject<UTbNamesNamEsPublisher>();
}

UTbNamesNamEsPublisher* UAbstractTbNamesNamEs::_GetPublisher()
{
	if (!TbNamesNamEsPublisher)
	{
		TbNamesNamEsPublisher = NewObject<UTbNamesNamEsPublisher>();
	}
	return TbNamesNamEsPublisher;
}

bool UAbstractTbNamesNamEs::GetSwitch_Private() const
{
	return GetSwitch();
};

void UAbstractTbNamesNamEs::SetSwitch_Private(bool bInSwitch)
{
	SetSwitch(bInSwitch);
};

int32 UAbstractTbNamesNamEs::GetSomeProperty_Private() const
{
	return GetSomeProperty();
};

void UAbstractTbNamesNamEs::SetSomeProperty_Private(int32 InSomeProperty)
{
	SetSomeProperty(InSomeProperty);
};

int32 UAbstractTbNamesNamEs::GetSomePoperty2_Private() const
{
	return GetSomePoperty2();
};

void UAbstractTbNamesNamEs::SetSomePoperty2_Private(int32 InSomePoperty2)
{
	SetSomePoperty2(InSomePoperty2);
};

ETbNamesEnum_With_Under_scores UAbstractTbNamesNamEs::GetEnumProperty_Private() const
{
	return GetEnumProperty();
};

void UAbstractTbNamesNamEs::SetEnumProperty_Private(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	SetEnumProperty(InEnumProperty);
};

void UAbstractTbNamesNamEs::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbNamesNamEs::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbNamesNamEsPublisher)
	{
		TbNamesNamEsPublisher->OnSomeSignalSignal.RemoveAll(TbNamesNamEsPublisher);
		TbNamesNamEsPublisher->OnSomeSignalSignalBP.RemoveAll(TbNamesNamEsPublisher);
		TbNamesNamEsPublisher->OnSomeSignal2Signal.RemoveAll(TbNamesNamEsPublisher);
		TbNamesNamEsPublisher->OnSomeSignal2SignalBP.RemoveAll(TbNamesNamEsPublisher);

		TbNamesNamEsPublisher->OnSwitchChanged.RemoveAll(TbNamesNamEsPublisher);
		TbNamesNamEsPublisher->OnSwitchChangedBP.RemoveAll(TbNamesNamEsPublisher);
		TbNamesNamEsPublisher->OnSomePropertyChanged.RemoveAll(TbNamesNamEsPublisher);
		TbNamesNamEsPublisher->OnSomePropertyChangedBP.RemoveAll(TbNamesNamEsPublisher);
		TbNamesNamEsPublisher->OnSomePoperty2Changed.RemoveAll(TbNamesNamEsPublisher);
		TbNamesNamEsPublisher->OnSomePoperty2ChangedBP.RemoveAll(TbNamesNamEsPublisher);
		TbNamesNamEsPublisher->OnEnumPropertyChanged.RemoveAll(TbNamesNamEsPublisher);
		TbNamesNamEsPublisher->OnEnumPropertyChangedBP.RemoveAll(TbNamesNamEsPublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbNamesNamEs::IsInitialized() const
{
	return bInitialized;
}
