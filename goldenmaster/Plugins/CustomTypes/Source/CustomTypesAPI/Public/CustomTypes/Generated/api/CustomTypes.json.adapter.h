#pragma once

#include "apigear.json.adapter.h"
#include "CustomTypes/Generated/CustomTypesLogCategories.h"
#include "CustomTypes/Generated/api/CustomTypes_data.h"

static void from_json(const nlohmann::json& j, FCustomTypesVector3D& p)
{
	const auto xIter = j.find("x");
	if (xIter != j.end() && !xIter->is_null() && xIter->is_number())
	{
		p.x = xIter->get<float>();
	}
	else
	{
		UE_LOG(LogCustomTypes, Verbose, TEXT("from_json: struct field 'x' missing or type mismatch in FCustomTypesVector3D -> using default value"));
	}

	const auto yIter = j.find("y");
	if (yIter != j.end() && !yIter->is_null() && yIter->is_number())
	{
		p.y = yIter->get<float>();
	}
	else
	{
		UE_LOG(LogCustomTypes, Verbose, TEXT("from_json: struct field 'y' missing or type mismatch in FCustomTypesVector3D -> using default value"));
	}

	const auto zIter = j.find("z");
	if (zIter != j.end() && !zIter->is_null() && zIter->is_number())
	{
		p.z = zIter->get<float>();
	}
	else
	{
		UE_LOG(LogCustomTypes, Verbose, TEXT("from_json: struct field 'z' missing or type mismatch in FCustomTypesVector3D -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FCustomTypesVector3D& p)
{
	j = nlohmann::json{{"x", p.x}, {"y", p.y}, {"z", p.z}};
}
