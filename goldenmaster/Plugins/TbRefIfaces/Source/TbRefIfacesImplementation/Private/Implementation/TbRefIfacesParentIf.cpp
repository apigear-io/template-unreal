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
		_GetSignals()->BroadcastLocalIfChanged(LocalIf);
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
		_GetSignals()->BroadcastImportedIfChanged(ImportedIf);
	}
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> UTbRefIfacesParentIfImplementation::LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	(void)Param;
	// do business logic here
	return TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> UTbRefIfacesParentIfImplementation::ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	(void)Param;
	// do business logic here
	return TScriptInterface<ITbIfaceimportEmptyIfInterface>();
}

void UTbRefIfacesParentIfImplementation::_ResetProperties()
{
	if (LocalIf != TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>())
	{
		LocalIf = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
		_GetSignals()->BroadcastLocalIfChanged(LocalIf);
	}
	if (ImportedIf != TScriptInterface<ITbIfaceimportEmptyIfInterface>())
	{
		ImportedIf = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
		_GetSignals()->BroadcastImportedIfChanged(ImportedIf);
	}
}
