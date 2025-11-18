#pragma once

#include "apigear.json.adapter.h"
#include "ExternTypes/Generated/ExternTypesLogCategories.h"
#include "ExternTypes/Generated/api/ExternTypes_data.h"
#include "Runtime/Core/Public/Math/Vector.h"

// do the specialization of the adl_serializer for the in the nlohmann namespace
// we do not want to modify the external namespace
namespace nlohmann
{

template <>
struct EXTERNTYPESAPI_API adl_serializer<FVector>
{
	static FVector from_json(const json& j);

	static void to_json(json& j, FVector t);
};

} // namespace nlohmann
