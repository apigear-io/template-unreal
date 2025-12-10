
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
#include "TbRefIfaces/Generated/Core/TbRefIfacesPropertiesData.h"

void TbRefIfacesParentIfPropertiesData::SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
{
	FScopeLock Lock(&(LocalIfCS));
	LocalIf = InLocalIf;
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> TbRefIfacesParentIfPropertiesData::GetLocalIf() const
{
	FScopeLock Lock(&(LocalIfCS));
	return LocalIf;
}

void TbRefIfacesParentIfPropertiesData::SetLocalIfList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList)
{
	FScopeLock Lock(&(LocalIfListCS));
	LocalIfList = InLocalIfList;
}

TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> TbRefIfacesParentIfPropertiesData::GetLocalIfList() const
{
	FScopeLock Lock(&(LocalIfListCS));
	return LocalIfList;
}

void TbRefIfacesParentIfPropertiesData::SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf)
{
	FScopeLock Lock(&(ImportedIfCS));
	ImportedIf = InImportedIf;
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> TbRefIfacesParentIfPropertiesData::GetImportedIf() const
{
	FScopeLock Lock(&(ImportedIfCS));
	return ImportedIf;
}

void TbRefIfacesParentIfPropertiesData::SetImportedIfList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList)
{
	FScopeLock Lock(&(ImportedIfListCS));
	ImportedIfList = InImportedIfList;
}

TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> TbRefIfacesParentIfPropertiesData::GetImportedIfList() const
{
	FScopeLock Lock(&(ImportedIfListCS));
	return ImportedIfList;
}
