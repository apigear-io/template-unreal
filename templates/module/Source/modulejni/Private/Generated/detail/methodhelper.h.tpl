{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
#pragma once

#include "Async/Future.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Misc/Guid.h"

DECLARE_LOG_CATEGORY_EXTERN(Log{{Camel .Module.Name}}MethodHelper_JNI, Log, All);

class F{{Camel .Module.Name}}MethodHelper
{
public:
    explicit F{{Camel .Module.Name}}MethodHelper(const FString& InOwnerName)
        : OwnerName(InOwnerName)
    {
    }

	template <typename ResultType>
	FGuid StorePromise(TPromise<ResultType>& InPromise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& InId, const ResultType& InValue);

private:
	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;
    FString OwnerName;
};

template <typename ResultType>
FGuid F{{Camel .Module.Name}}MethodHelper::StorePromise(TPromise<ResultType>& Promise)
{
	FGuid Id = FGuid::NewGuid();

    {
        FScopeLock Lock(&ReplyPromisesMapCS);
        ReplyPromisesMap.Add(Id, &Promise);
    }

	UE_LOG(
        Log{{Camel .Module.Name}}MethodHelper_JNI,
        Verbose,
        TEXT("Stored promise with id %s for %s"),
        *(Id.ToString(EGuidFormats::Digits)),
        *OwnerName);

	return Id;
}

template <typename ResultType>
bool F{{Camel .Module.Name}}MethodHelper::FulfillPromise(const FGuid& Id, const ResultType& Value)
{
	UE_LOG(
        Log{{Camel .Module.Name}}MethodHelper_JNI,
        Verbose,
        TEXT("Resolving promise with id %s for %s"),
        *(Id.ToString(EGuidFormats::Digits)),
        *OwnerName);

	TPromise<ResultType>* PromisePtr = nullptr;

	{
		FScopeLock Lock(&ReplyPromisesMapCS);
		if (auto** Found = ReplyPromisesMap.Find(Id))
		{
			PromisePtr = static_cast<TPromise<ResultType>*>(*Found);
			ReplyPromisesMap.Remove(Id);
		}
	}

	if (PromisePtr)
	{
		PromisePtr->SetValue(Value);
		return true;
	}

	return false;
}
