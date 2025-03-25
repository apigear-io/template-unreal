#pragma once

#include "apigear.json.adapter.h"
#include "TbIfaceimport/Generated/api/TbIfaceimport_data.h"
#include "TbIfaceimport/Generated/api/TbIfaceimportEmptyIfInterface.h"

static void from_json(const nlohmann::json& j, TScriptInterface<ITbIfaceimportEmptyIfInterface>& p)
{
	if (!p)
	{
		return;
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbIfaceimportEmptyIfInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{};
}
