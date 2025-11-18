#pragma once

#include "apigear.json.adapter.h"
#include "Counter/Generated/CounterLogCategories.h"
#include "Counter/Generated/api/Counter_data.h"
#include "Counter/Generated/api/CounterCounterInterface.h"
#include "CustomTypes/Generated/api/CustomTypes.json.adapter.h"
#include "ExternTypes/Generated/api/ExternTypes.json.adapter.h"

static void from_json(const nlohmann::json& j, TScriptInterface<ICounterCounterInterface>& p)
{
	if (!p)
	{
		return;
	}

	const auto vectorIter = j.find("vector");
	if (vectorIter != j.end() && !vectorIter->is_null() && vectorIter->is_object())
	{
		Cast<ICounterCounterInterface>(p.GetObject())->SetVector(vectorIter->get<FCustomTypesVector3D>());
	}
	else
	{
		UE_LOG(LogCounter, Verbose, TEXT("from_json: interface property 'vector' missing or type mismatch in ICounterCounterInterface -> ignore"));
	}

	const auto extern_vectorIter = j.find("extern_vector");
	if (extern_vectorIter != j.end() && !extern_vectorIter->is_null() && extern_vectorIter->is_object())
	{
		Cast<ICounterCounterInterface>(p.GetObject())->SetExternVector(extern_vectorIter->get<FVector>());
	}
	else
	{
		UE_LOG(LogCounter, Verbose, TEXT("from_json: interface property 'extern_vector' missing or type mismatch in ICounterCounterInterface -> ignore"));
	}

	const auto vectorArrayIter = j.find("vectorArray");
	if (vectorArrayIter != j.end() && !vectorArrayIter->is_null() && vectorArrayIter->is_array())
	{
		Cast<ICounterCounterInterface>(p.GetObject())->SetVectorArray(vectorArrayIter->get<TArray<FCustomTypesVector3D>>());
	}
	else
	{
		UE_LOG(LogCounter, Verbose, TEXT("from_json: interface property 'vectorArray' missing or type mismatch in ICounterCounterInterface -> ignore"));
	}

	const auto extern_vectorArrayIter = j.find("extern_vectorArray");
	if (extern_vectorArrayIter != j.end() && !extern_vectorArrayIter->is_null() && extern_vectorArrayIter->is_array())
	{
		Cast<ICounterCounterInterface>(p.GetObject())->SetExternVectorArray(extern_vectorArrayIter->get<TArray<FVector>>());
	}
	else
	{
		UE_LOG(LogCounter, Verbose, TEXT("from_json: interface property 'extern_vectorArray' missing or type mismatch in ICounterCounterInterface -> ignore"));
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ICounterCounterInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"vector", Cast<ICounterCounterInterface>(p.GetObject())->GetVector()}, {"extern_vector", Cast<ICounterCounterInterface>(p.GetObject())->GetExternVector()}, {"vectorArray", Cast<ICounterCounterInterface>(p.GetObject())->GetVectorArray()}, {"extern_vectorArray", Cast<ICounterCounterInterface>(p.GetObject())->GetExternVectorArray()}};
}
