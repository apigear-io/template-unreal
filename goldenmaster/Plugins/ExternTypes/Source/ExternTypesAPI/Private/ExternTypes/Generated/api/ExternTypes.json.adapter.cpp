#include "ExternTypes/Generated/api/ExternTypes.json.adapter.h"
#include "Runtime/Core/Public/Math/Vector.h"

// do the specialization of the adl_serializer for the in the nlohmann namespace
// we do not want to modify the external namespace
namespace nlohmann
{

FVector adl_serializer<FVector>::from_json(const json& j)
{
	(void)j;
	// Do deserialization here, e.g.
	// return { j.at("xyz").get<Int>() };
	return {};
}

void adl_serializer<FVector>::to_json(json& j, FVector t)
{
	(void)j;
	(void)t;
	// Do serialization here, e.g.
	// j = t.xyz;
}

} // namespace nlohmann
