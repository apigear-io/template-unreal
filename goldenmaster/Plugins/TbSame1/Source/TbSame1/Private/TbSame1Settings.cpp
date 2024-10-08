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
#include "TbSame1Settings.h"
#include "Generated/TbSame1Factory.h"
#include "TbSame1/Generated/TbSame1LogCategories.h"
#include "ApiGearConnectionsStore.h"
#include "Engine/Engine.h"
#include "Misc/CoreDelegates.h"

UTbSame1Settings::UTbSame1Settings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FCoreDelegates::OnPostEngineInit.AddUObject(this, &UTbSame1Settings::ValidateSettingsPostEngineInit);
}

void UTbSame1Settings::ValidateSettingsPostEngineInit()
{
	check(GEngine);
	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	if (!AGCM->DoesConnectionExist(OLinkConnectionIdentifier))
	{
		UE_LOG(LogTbSame1, Warning, TEXT("UTbSame1Settings could not find connection %s."), *OLinkConnectionIdentifier);
		OLinkConnectionIdentifier = "";
	}

	// the local backend does not require configuration
	if (TracerServiceIdentifier == TbSame1LocalBackendIdentifier)
	{
		return;
	}

	if (!AGCM->DoesConnectionExist(TracerServiceIdentifier))
	{
		UE_LOG(LogTbSame1, Warning, TEXT("UTbSame1Settings could not find connection %s, falling back to local backend."), *TracerServiceIdentifier);
		TracerServiceIdentifier = TbSame1LocalBackendIdentifier;
	}
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> UTbSame1Settings::GetITbSame1SameStruct1InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSame1Settings* TbSame1Settings = GetMutableDefault<UTbSame1Settings>();

	FString BackendIdentifier = TbSame1Settings->TracerServiceIdentifier;

	if (TbSame1Settings->TracerServiceIdentifier == TbSame1LocalBackendIdentifier)
	{
		return FTbSame1ModuleFactory::GetTbSame1SameStruct1InterfaceImplementation(TbSame1LocalBackendIdentifier, Collection);
	}

	if (TbSame1Settings->TracerServiceIdentifier != TbSame1LocalBackendIdentifier)
	{
		return FTbSame1ModuleFactory::GetTbSame1SameStruct1InterfaceImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> UTbSame1Settings::GetITbSame1SameStruct2InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSame1Settings* TbSame1Settings = GetMutableDefault<UTbSame1Settings>();

	FString BackendIdentifier = TbSame1Settings->TracerServiceIdentifier;

	if (TbSame1Settings->TracerServiceIdentifier == TbSame1LocalBackendIdentifier)
	{
		return FTbSame1ModuleFactory::GetTbSame1SameStruct2InterfaceImplementation(TbSame1LocalBackendIdentifier, Collection);
	}

	if (TbSame1Settings->TracerServiceIdentifier != TbSame1LocalBackendIdentifier)
	{
		return FTbSame1ModuleFactory::GetTbSame1SameStruct2InterfaceImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITbSame1SameEnum1InterfaceInterface> UTbSame1Settings::GetITbSame1SameEnum1InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSame1Settings* TbSame1Settings = GetMutableDefault<UTbSame1Settings>();

	FString BackendIdentifier = TbSame1Settings->TracerServiceIdentifier;

	if (TbSame1Settings->TracerServiceIdentifier == TbSame1LocalBackendIdentifier)
	{
		return FTbSame1ModuleFactory::GetTbSame1SameEnum1InterfaceImplementation(TbSame1LocalBackendIdentifier, Collection);
	}

	if (TbSame1Settings->TracerServiceIdentifier != TbSame1LocalBackendIdentifier)
	{
		return FTbSame1ModuleFactory::GetTbSame1SameEnum1InterfaceImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> UTbSame1Settings::GetITbSame1SameEnum2InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSame1Settings* TbSame1Settings = GetMutableDefault<UTbSame1Settings>();

	FString BackendIdentifier = TbSame1Settings->TracerServiceIdentifier;

	if (TbSame1Settings->TracerServiceIdentifier == TbSame1LocalBackendIdentifier)
	{
		return FTbSame1ModuleFactory::GetTbSame1SameEnum2InterfaceImplementation(TbSame1LocalBackendIdentifier, Collection);
	}

	if (TbSame1Settings->TracerServiceIdentifier != TbSame1LocalBackendIdentifier)
	{
		return FTbSame1ModuleFactory::GetTbSame1SameEnum2InterfaceImplementation("olink", Collection);
	}

	return nullptr;
}
