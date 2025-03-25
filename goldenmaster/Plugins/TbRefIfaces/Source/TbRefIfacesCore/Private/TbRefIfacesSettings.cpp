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
#include "TbRefIfacesSettings.h"
#include "TbRefIfaces/Generated/TbRefIfacesFactory.h"
#include "TbRefIfaces/Generated/TbRefIfacesLogCategories.h"
#include "ApiGearConnectionsStore.h"
#include "Engine/Engine.h"
#include "Misc/CoreDelegates.h"

UTbRefIfacesSettings::UTbRefIfacesSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FCoreDelegates::OnPostEngineInit.AddUObject(this, &UTbRefIfacesSettings::ValidateSettingsPostEngineInit);
}

void UTbRefIfacesSettings::ValidateSettingsPostEngineInit()
{
	check(GEngine);
	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	if (!AGCM->DoesConnectionExist(OLinkConnectionIdentifier))
	{
		UE_LOG(LogTbRefIfaces, Warning, TEXT("UTbRefIfacesSettings could not find connection %s."), *OLinkConnectionIdentifier);
		OLinkConnectionIdentifier = "";
	}

	// the local backend does not require configuration
	if (TracerServiceIdentifier == TbRefIfacesLocalBackendIdentifier)
	{
		return;
	}

	if (!AGCM->DoesConnectionExist(TracerServiceIdentifier))
	{
		UE_LOG(LogTbRefIfaces, Warning, TEXT("UTbRefIfacesSettings could not find connection %s, falling back to local backend."), *TracerServiceIdentifier);
		TracerServiceIdentifier = TbRefIfacesLocalBackendIdentifier;
	}
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> UTbRefIfacesSettings::GetITbRefIfacesSimpleLocalIfInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbRefIfacesSettings* TbRefIfacesSettings = GetMutableDefault<UTbRefIfacesSettings>();

	FString BackendIdentifier = TbRefIfacesSettings->TracerServiceIdentifier;

	if (TbRefIfacesSettings->TracerServiceIdentifier == TbRefIfacesLocalBackendIdentifier)
	{
		return FTbRefIfacesModuleFactory::GetTbRefIfacesSimpleLocalIfImplementation(TbRefIfacesLocalBackendIdentifier, Collection);
	}

	if (TbRefIfacesSettings->TracerServiceIdentifier != TbRefIfacesLocalBackendIdentifier)
	{
		return FTbRefIfacesModuleFactory::GetTbRefIfacesSimpleLocalIfImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITbRefIfacesParentIfInterface> UTbRefIfacesSettings::GetITbRefIfacesParentIfInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbRefIfacesSettings* TbRefIfacesSettings = GetMutableDefault<UTbRefIfacesSettings>();

	FString BackendIdentifier = TbRefIfacesSettings->TracerServiceIdentifier;

	if (TbRefIfacesSettings->TracerServiceIdentifier == TbRefIfacesLocalBackendIdentifier)
	{
		return FTbRefIfacesModuleFactory::GetTbRefIfacesParentIfImplementation(TbRefIfacesLocalBackendIdentifier, Collection);
	}

	if (TbRefIfacesSettings->TracerServiceIdentifier != TbRefIfacesLocalBackendIdentifier)
	{
		return FTbRefIfacesModuleFactory::GetTbRefIfacesParentIfImplementation("olink", Collection);
	}

	return nullptr;
}
