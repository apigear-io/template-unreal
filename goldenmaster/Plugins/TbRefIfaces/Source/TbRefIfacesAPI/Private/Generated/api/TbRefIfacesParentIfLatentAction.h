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
#pragma once
#include "Async/Async.h"
#include "LatentActions.h"

template <typename TAsyncResult>
class FTbRefIfacesParentIfLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	TAtomic<bool> bCancelled{false};
	TFuture<TAsyncResult> Future;
	TAsyncResult* OutPtr;

public:
	FTbRefIfacesParentIfLatentAction(const FLatentActionInfo& LatentInfo,
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
