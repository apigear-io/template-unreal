/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "TbRefIfaces/Implementation/TbRefIfacesParentIf.h"

UTbRefIfacesParentIfImplementation::~UTbRefIfacesParentIfImplementation() = default;
TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> UTbRefIfacesParentIfImplementation::GetLocalIf() const
{
	return LocalIf;
}

void UTbRefIfacesParentIfImplementation::SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
{
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
	if (ImportedIfList != InImportedIfList)
	{
		ImportedIfList = InImportedIfList;
		_GetPublisher()->BroadcastImportedIfListChanged(ImportedIfList);
	}
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> UTbRefIfacesParentIfImplementation::LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	(void)Param;
	// do business logic here
	return TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
}

TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> UTbRefIfacesParentIfImplementation::LocalIfMethodList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param)
{
	(void)Param;
	// do business logic here
	return TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>();
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> UTbRefIfacesParentIfImplementation::ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	(void)Param;
	// do business logic here
	return TScriptInterface<ITbIfaceimportEmptyIfInterface>();
}

TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> UTbRefIfacesParentIfImplementation::ImportedIfMethodList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param)
{
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
