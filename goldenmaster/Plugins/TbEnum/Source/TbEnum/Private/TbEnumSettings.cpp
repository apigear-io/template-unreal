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
#include "TbEnumSettings.h"
#include "Generated/TbEnumFactory.h"
#include "TbEnum/Generated/TbEnumLogCategories.h"
#include "ApiGearConnectionsStore.h"
#include "Engine/Engine.h"
#include "Misc/CoreDelegates.h"

UTbEnumSettings::UTbEnumSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FCoreDelegates::OnPostEngineInit.AddUObject(this, &UTbEnumSettings::ValidateSettingsPostEngineInit);
}

void UTbEnumSettings::ValidateSettingsPostEngineInit()
{
	check(GEngine);
	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	if (!AGCM->DoesConnectionExist(OLinkConnectionIdentifier))
	{
		UE_LOG(LogTbEnum, Warning, TEXT("UTbEnumSettings could not find connection %s."), *OLinkConnectionIdentifier);
		OLinkConnectionIdentifier = "";
	}

	// the local backend does not require configuration
	if (TracerServiceIdentifier == TbEnumLocalBackendIdentifier)
	{
		return;
	}

	if (!AGCM->DoesConnectionExist(TracerServiceIdentifier))
	{
		UE_LOG(LogTbEnum, Warning, TEXT("UTbEnumSettings could not find connection %s, falling back to local backend."), *TracerServiceIdentifier);
		TracerServiceIdentifier = TbEnumLocalBackendIdentifier;
	}
}

TScriptInterface<ITbEnumEnumInterfaceInterface> UTbEnumSettings::GetITbEnumEnumInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbEnumSettings* TbEnumSettings = GetMutableDefault<UTbEnumSettings>();

	FString BackendIdentifier = TbEnumSettings->TracerServiceIdentifier;

	if (TbEnumSettings->TracerServiceIdentifier == TbEnumLocalBackendIdentifier)
	{
		return FTbEnumModuleFactory::GetTbEnumEnumInterfaceImplementation(TbEnumLocalBackendIdentifier, Collection);
	}

	if (TbEnumSettings->TracerServiceIdentifier != TbEnumLocalBackendIdentifier)
	{
		return FTbEnumModuleFactory::GetTbEnumEnumInterfaceImplementation("olink", Collection);
	}

	return nullptr;
}
