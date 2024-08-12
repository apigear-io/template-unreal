#pragma once

#include "apigear.json.adapter.h"
#include "Generated/api/ExternTypes_data.h"
#include "Runtime/Core/Public/Math/Vector.h"

// do the specialization of the adl_serializer for the in the nlohmann namespace
// we do not want to modify the external namespace
namespace nlohmann {

	template <>
	struct EXTERNTYPES_API adl_serializer<::FVector> {
		static ::FVector from_json(const json& j) {
			(void) j;
			// Do deserialization here, e.g.
			// return { j.at("xyz").get<Int>() };
			return {};
		}

		static void to_json(json& j, ::FVector t) {
			(void) j;
			(void) t;
			// Do serialization here, e.g.
			// j = t.xyz;
		}
	};

} // namespace nlohmann
