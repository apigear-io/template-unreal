#pragma once

#include "apigear.json.adapter.h"
#include "TbSame2/Generated/api/TbSame2_data.h"

static void from_json(const nlohmann::json& j, FTbSame2Struct1& p)
{
	p.field1 = j.at("field1").get<int32>();
	p.field2 = j.at("field2").get<int32>();
	p.field3 = j.at("field3").get<int32>();
}

static void to_json(nlohmann::json& j, const FTbSame2Struct1& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}, {"field3", p.field3}};
}

static void from_json(const nlohmann::json& j, FTbSame2Struct2& p)
{
	p.field1 = j.at("field1").get<int32>();
	p.field2 = j.at("field2").get<int32>();
	p.field3 = j.at("field3").get<int32>();
}

static void to_json(nlohmann::json& j, const FTbSame2Struct2& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}, {"field3", p.field3}};
}
