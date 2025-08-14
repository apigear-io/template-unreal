#pragma once

#include "apigear.json.adapter.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_data.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesParentIfInterface.h"
#include "TbIfaceimport/Generated/api/TbIfaceimport.json.adapter.h"

static void from_json(const nlohmann::json& j, TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbRefIfacesSimpleLocalIfInterface>(p.GetObject())->SetIntProperty(j.at("intProperty").get<int32>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"intProperty", Cast<ITbRefIfacesSimpleLocalIfInterface>(p.GetObject())->GetIntProperty()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbRefIfacesParentIfInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->SetLocalIf(j.at("localIf").get<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>());
	Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->SetLocalIfList(j.at("localIfList").get<TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>>());
	Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->SetImportedIf(j.at("importedIf").get<TScriptInterface<ITbIfaceimportEmptyIfInterface>>());
	Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->SetImportedIfList(j.at("importedIfList").get<TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbRefIfacesParentIfInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"localIf", Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->GetLocalIf()}, {"localIfList", Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->GetLocalIfList()}, {"importedIf", Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->GetImportedIf()}, {"importedIfList", Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->GetImportedIfList()}};
}
