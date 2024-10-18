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
#include "TbSame2Settings.h"
#include "TbSame2/Generated/TbSame2Factory.h"
#include "TbSame2/Generated/TbSame2LogCategories.h"
#include "ApiGearConnectionsStore.h"
#include "Engine/Engine.h"
#include "Misc/CoreDelegates.h"

UTbSame2Settings::UTbSame2Settings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FCoreDelegates::OnPostEngineInit.AddUObject(this, &UTbSame2Settings::ValidateSettingsPostEngineInit);
}

void UTbSame2Settings::ValidateSettingsPostEngineInit()
{
	check(GEngine);
	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	if (!AGCM->DoesConnectionExist(OLinkConnectionIdentifier))
	{
		UE_LOG(LogTbSame2, Warning, TEXT("UTbSame2Settings could not find connection %s."), *OLinkConnectionIdentifier);
		OLinkConnectionIdentifier = "";
	}

	// the local backend does not require configuration
	if (TracerServiceIdentifier == TbSame2LocalBackendIdentifier)
	{
		return;
	}

	if (!AGCM->DoesConnectionExist(TracerServiceIdentifier))
	{
		UE_LOG(LogTbSame2, Warning, TEXT("UTbSame2Settings could not find connection %s, falling back to local backend."), *TracerServiceIdentifier);
		TracerServiceIdentifier = TbSame2LocalBackendIdentifier;
	}
}

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> UTbSame2Settings::GetITbSame2SameStruct1InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSame2Settings* TbSame2Settings = GetMutableDefault<UTbSame2Settings>();

	FString BackendIdentifier = TbSame2Settings->TracerServiceIdentifier;

	if (TbSame2Settings->TracerServiceIdentifier == TbSame2LocalBackendIdentifier)
	{
		return FTbSame2ModuleFactory::GetTbSame2SameStruct1InterfaceImplementation(TbSame2LocalBackendIdentifier, Collection);
	}

	if (TbSame2Settings->TracerServiceIdentifier != TbSame2LocalBackendIdentifier)
	{
		return FTbSame2ModuleFactory::GetTbSame2SameStruct1InterfaceImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> UTbSame2Settings::GetITbSame2SameStruct2InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSame2Settings* TbSame2Settings = GetMutableDefault<UTbSame2Settings>();

	FString BackendIdentifier = TbSame2Settings->TracerServiceIdentifier;

	if (TbSame2Settings->TracerServiceIdentifier == TbSame2LocalBackendIdentifier)
	{
		return FTbSame2ModuleFactory::GetTbSame2SameStruct2InterfaceImplementation(TbSame2LocalBackendIdentifier, Collection);
	}

	if (TbSame2Settings->TracerServiceIdentifier != TbSame2LocalBackendIdentifier)
	{
		return FTbSame2ModuleFactory::GetTbSame2SameStruct2InterfaceImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITbSame2SameEnum1InterfaceInterface> UTbSame2Settings::GetITbSame2SameEnum1InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSame2Settings* TbSame2Settings = GetMutableDefault<UTbSame2Settings>();

	FString BackendIdentifier = TbSame2Settings->TracerServiceIdentifier;

	if (TbSame2Settings->TracerServiceIdentifier == TbSame2LocalBackendIdentifier)
	{
		return FTbSame2ModuleFactory::GetTbSame2SameEnum1InterfaceImplementation(TbSame2LocalBackendIdentifier, Collection);
	}

	if (TbSame2Settings->TracerServiceIdentifier != TbSame2LocalBackendIdentifier)
	{
		return FTbSame2ModuleFactory::GetTbSame2SameEnum1InterfaceImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> UTbSame2Settings::GetITbSame2SameEnum2InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSame2Settings* TbSame2Settings = GetMutableDefault<UTbSame2Settings>();

	FString BackendIdentifier = TbSame2Settings->TracerServiceIdentifier;

	if (TbSame2Settings->TracerServiceIdentifier == TbSame2LocalBackendIdentifier)
	{
		return FTbSame2ModuleFactory::GetTbSame2SameEnum2InterfaceImplementation(TbSame2LocalBackendIdentifier, Collection);
	}

	if (TbSame2Settings->TracerServiceIdentifier != TbSame2LocalBackendIdentifier)
	{
		return FTbSame2ModuleFactory::GetTbSame2SameEnum2InterfaceImplementation("olink", Collection);
	}

	return nullptr;
}
