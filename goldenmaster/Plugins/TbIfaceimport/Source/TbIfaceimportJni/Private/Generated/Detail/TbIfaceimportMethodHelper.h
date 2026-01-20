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
#pragma once

#include "Async/Future.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Misc/Guid.h"
#include "Templates/UniquePtr.h"

#include "Generated/Detail/TbIfaceimportPromiseHolder.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbIfaceimportMethodHelper_JNI, Log, All);

class FTbIfaceimportMethodHelper
{
public:
	explicit FTbIfaceimportMethodHelper(const FString& InOwnerName)
		: OwnerName(InOwnerName)
	{
	}

	void FlushPendingPromises()
	{
		TMap<FGuid, TUniquePtr<ITbIfaceimportPromiseHolder>> ReplyPromisesMapCopy;
		{
			FScopeLock Lock(&ReplyPromisesMapCS);
			ReplyPromisesMapCopy = MoveTemp(ReplyPromisesMap);
		}

		for (auto& Element : ReplyPromisesMapCopy)
		{
			Element.Value->FulfillWithDefaultValue();
		}
	}

	template <typename ResultType>
	FGuid StorePromise(TPromise<ResultType>&& InPromise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& InId, const ResultType& InValue);

private:
	TMap<FGuid, TUniquePtr<ITbIfaceimportPromiseHolder>> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;
	FString OwnerName;
};

template <typename ResultType>
FGuid FTbIfaceimportMethodHelper::StorePromise(TPromise<ResultType>&& Promise)
{
	FGuid Id = FGuid::NewGuid();

	{
		FScopeLock Lock(&ReplyPromisesMapCS);
		ReplyPromisesMap.Add(
			Id, MakeUnique<TTbIfaceimportPromiseHolder<ResultType>>(MoveTemp(Promise)));
	}

	UE_LOG(
		LogTbIfaceimportMethodHelper_JNI,
		Verbose,
		TEXT("Stored promise with id %s for %s"),
		*(Id.ToString(EGuidFormats::Digits)),
		*OwnerName);

	return Id;
}

template <typename ResultType>
bool FTbIfaceimportMethodHelper::FulfillPromise(const FGuid& Id, const ResultType& Value)
{
	UE_LOG(
		LogTbIfaceimportMethodHelper_JNI,
		Verbose,
		TEXT("Resolving promise with id %s for %s"),
		*(Id.ToString(EGuidFormats::Digits)),
		*OwnerName);

	TUniquePtr<TTbIfaceimportPromiseHolder<ResultType>> PromiseHolderPtr;

	{
		FScopeLock Lock(&ReplyPromisesMapCS);
		if (auto* Found = ReplyPromisesMap.Find(Id))
		{
			PromiseHolderPtr.Reset(
				static_cast<TTbIfaceimportPromiseHolder<ResultType>*>(Found->Release()));
			ReplyPromisesMap.Remove(Id);
		}
	}

	if (PromiseHolderPtr)
	{
		PromiseHolderPtr->VisitPromise(
			[&](TPromise<ResultType>& Promise)
			{
			Promise.SetValue(Value);
		});
		return true;
	}

	return false;
}
