#pragma once

#include "apigear.json.adapter.h"
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

	Cast<ICounterCounterInterface>(p.GetObject())->SetVector(j.at("vector").get<FCustomTypesVector3D>());
	Cast<ICounterCounterInterface>(p.GetObject())->SetExternVector(j.at("extern_vector").get<FVector>());
	Cast<ICounterCounterInterface>(p.GetObject())->SetVectorArray(j.at("vectorArray").get<TArray<FCustomTypesVector3D>>());
	Cast<ICounterCounterInterface>(p.GetObject())->SetExternVectorArray(j.at("extern_vectorArray").get<TArray<FVector>>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ICounterCounterInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"vector", Cast<ICounterCounterInterface>(p.GetObject())->GetVector()}, {"extern_vector", Cast<ICounterCounterInterface>(p.GetObject())->GetExternVector()}, {"vectorArray", Cast<ICounterCounterInterface>(p.GetObject())->GetVectorArray()}, {"extern_vectorArray", Cast<ICounterCounterInterface>(p.GetObject())->GetExternVectorArray()}};
}
