#pragma once

#include "apigear.json.adapter.h"
#include "TbRefIfaces/Generated/TbRefIfacesLogCategories.h"
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

	const auto intPropertyIter = j.find("intProperty");
	if (intPropertyIter != j.end() && !intPropertyIter->is_null() && intPropertyIter->is_number_integer())
	{
		Cast<ITbRefIfacesSimpleLocalIfInterface>(p.GetObject())->SetIntProperty(intPropertyIter->get<int32>());
	}
	else
	{
		UE_LOG(LogTbRefIfaces, Verbose, TEXT("from_json: interface property 'intProperty' missing or type mismatch in ITbRefIfacesSimpleLocalIfInterface -> ignore"));
	}
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

	const auto localIfIter = j.find("localIf");
	if (localIfIter != j.end() && !localIfIter->is_null() && localIfIter->is_object())
	{
		Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->SetLocalIf(localIfIter->get<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>());
	}
	else
	{
		UE_LOG(LogTbRefIfaces, Verbose, TEXT("from_json: interface property 'localIf' missing or type mismatch in ITbRefIfacesParentIfInterface -> ignore"));
	}

	const auto localIfListIter = j.find("localIfList");
	if (localIfListIter != j.end() && !localIfListIter->is_null() && localIfListIter->is_array())
	{
		Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->SetLocalIfList(localIfListIter->get<TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>>());
	}
	else
	{
		UE_LOG(LogTbRefIfaces, Verbose, TEXT("from_json: interface property 'localIfList' missing or type mismatch in ITbRefIfacesParentIfInterface -> ignore"));
	}

	const auto importedIfIter = j.find("importedIf");
	if (importedIfIter != j.end() && !importedIfIter->is_null() && importedIfIter->is_object())
	{
		Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->SetImportedIf(importedIfIter->get<TScriptInterface<ITbIfaceimportEmptyIfInterface>>());
	}
	else
	{
		UE_LOG(LogTbRefIfaces, Verbose, TEXT("from_json: interface property 'importedIf' missing or type mismatch in ITbRefIfacesParentIfInterface -> ignore"));
	}

	const auto importedIfListIter = j.find("importedIfList");
	if (importedIfListIter != j.end() && !importedIfListIter->is_null() && importedIfListIter->is_array())
	{
		Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->SetImportedIfList(importedIfListIter->get<TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>>());
	}
	else
	{
		UE_LOG(LogTbRefIfaces, Verbose, TEXT("from_json: interface property 'importedIfList' missing or type mismatch in ITbRefIfacesParentIfInterface -> ignore"));
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbRefIfacesParentIfInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"localIf", Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->GetLocalIf()}, {"localIfList", Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->GetLocalIfList()}, {"importedIf", Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->GetImportedIf()}, {"importedIfList", Cast<ITbRefIfacesParentIfInterface>(p.GetObject())->GetImportedIfList()}};
}
