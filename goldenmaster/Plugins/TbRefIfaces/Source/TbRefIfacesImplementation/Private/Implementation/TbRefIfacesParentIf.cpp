// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbRefIfaces/Implementation/TbRefIfacesParentIf.h"

UTbRefIfacesParentIfImplementation::~UTbRefIfacesParentIfImplementation() = default;
TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> UTbRefIfacesParentIfImplementation::GetLocalIf() const
{
	return LocalIf;
}

void UTbRefIfacesParentIfImplementation::SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.SetLocalIf");
	if (LocalIf != InLocalIf)
	{
		LocalIf = InLocalIf;
		_GetPublisher()->BroadcastLocalIfChanged(LocalIf);
	}
}
TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> UTbRefIfacesParentIfImplementation::GetLocalIfList() const
{
	return LocalIfList;
}

void UTbRefIfacesParentIfImplementation::SetLocalIfList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.SetLocalIfList");
	if (LocalIfList != InLocalIfList)
	{
		LocalIfList = InLocalIfList;
		_GetPublisher()->BroadcastLocalIfListChanged(LocalIfList);
	}
}
TScriptInterface<ITbIfaceimportEmptyIfInterface> UTbRefIfacesParentIfImplementation::GetImportedIf() const
{
	return ImportedIf;
}

void UTbRefIfacesParentIfImplementation::SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.SetImportedIf");
	if (ImportedIf != InImportedIf)
	{
		ImportedIf = InImportedIf;
		_GetPublisher()->BroadcastImportedIfChanged(ImportedIf);
	}
}
TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> UTbRefIfacesParentIfImplementation::GetImportedIfList() const
{
	return ImportedIfList;
}

void UTbRefIfacesParentIfImplementation::SetImportedIfList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.SetImportedIfList");
	if (ImportedIfList != InImportedIfList)
	{
		ImportedIfList = InImportedIfList;
		_GetPublisher()->BroadcastImportedIfListChanged(ImportedIfList);
	}
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> UTbRefIfacesParentIfImplementation::LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.LocalIfMethod");
	(void)Param;
	// do business logic here
	return TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
}

TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> UTbRefIfacesParentIfImplementation::LocalIfMethodList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.LocalIfMethodList");
	(void)Param;
	// do business logic here
	return TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>();
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> UTbRefIfacesParentIfImplementation::ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.ImportedIfMethod");
	(void)Param;
	// do business logic here
	return TScriptInterface<ITbIfaceimportEmptyIfInterface>();
}

TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> UTbRefIfacesParentIfImplementation::ImportedIfMethodList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.ImportedIfMethodList");
	(void)Param;
	// do business logic here
	return TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>();
}

void UTbRefIfacesParentIfImplementation::_ResetProperties()
{
	if (LocalIf != TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>())
	{
		LocalIf = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
		_GetPublisher()->BroadcastLocalIfChanged(LocalIf);
	}
	if (LocalIfList != TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>())
	{
		LocalIfList = TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>();
		_GetPublisher()->BroadcastLocalIfListChanged(LocalIfList);
	}
	if (ImportedIf != TScriptInterface<ITbIfaceimportEmptyIfInterface>())
	{
		ImportedIf = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
		_GetPublisher()->BroadcastImportedIfChanged(ImportedIf);
	}
	if (ImportedIfList != TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>())
	{
		ImportedIfList = TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>();
		_GetPublisher()->BroadcastImportedIfListChanged(ImportedIfList);
	}
}
