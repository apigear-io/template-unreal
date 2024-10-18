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
#include "TbSimpleSettings.h"
#include "Generated/TbSimpleFactory.h"
#include "TbSimple/Generated/TbSimpleLogCategories.h"
#include "ApiGearConnectionsStore.h"
#include "Engine/Engine.h"
#include "Misc/CoreDelegates.h"

UTbSimpleSettings::UTbSimpleSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FCoreDelegates::OnPostEngineInit.AddUObject(this, &UTbSimpleSettings::ValidateSettingsPostEngineInit);
}

void UTbSimpleSettings::ValidateSettingsPostEngineInit()
{
	check(GEngine);
	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	if (!AGCM->DoesConnectionExist(OLinkConnectionIdentifier))
	{
		UE_LOG(LogTbSimple, Warning, TEXT("UTbSimpleSettings could not find connection %s."), *OLinkConnectionIdentifier);
		OLinkConnectionIdentifier = "";
	}

	// the local backend does not require configuration
	if (TracerServiceIdentifier == TbSimpleLocalBackendIdentifier)
	{
		return;
	}

	if (!AGCM->DoesConnectionExist(TracerServiceIdentifier))
	{
		UE_LOG(LogTbSimple, Warning, TEXT("UTbSimpleSettings could not find connection %s, falling back to local backend."), *TracerServiceIdentifier);
		TracerServiceIdentifier = TbSimpleLocalBackendIdentifier;
	}
}

TScriptInterface<ITbSimpleVoidInterfaceInterface> UTbSimpleSettings::GetITbSimpleVoidInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* TbSimpleSettings = GetMutableDefault<UTbSimpleSettings>();

	FString BackendIdentifier = TbSimpleSettings->TracerServiceIdentifier;

	if (TbSimpleSettings->TracerServiceIdentifier == TbSimpleLocalBackendIdentifier)
	{
		return FTbSimpleModuleFactory::GetTbSimpleVoidInterfaceImplementation(TbSimpleLocalBackendIdentifier, Collection);
	}

	if (TbSimpleSettings->TracerServiceIdentifier != TbSimpleLocalBackendIdentifier)
	{
		return FTbSimpleModuleFactory::GetTbSimpleVoidInterfaceImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITbSimpleSimpleInterfaceInterface> UTbSimpleSettings::GetITbSimpleSimpleInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* TbSimpleSettings = GetMutableDefault<UTbSimpleSettings>();

	FString BackendIdentifier = TbSimpleSettings->TracerServiceIdentifier;

	if (TbSimpleSettings->TracerServiceIdentifier == TbSimpleLocalBackendIdentifier)
	{
		return FTbSimpleModuleFactory::GetTbSimpleSimpleInterfaceImplementation(TbSimpleLocalBackendIdentifier, Collection);
	}

	if (TbSimpleSettings->TracerServiceIdentifier != TbSimpleLocalBackendIdentifier)
	{
		return FTbSimpleModuleFactory::GetTbSimpleSimpleInterfaceImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> UTbSimpleSettings::GetITbSimpleSimpleArrayInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* TbSimpleSettings = GetMutableDefault<UTbSimpleSettings>();

	FString BackendIdentifier = TbSimpleSettings->TracerServiceIdentifier;

	if (TbSimpleSettings->TracerServiceIdentifier == TbSimpleLocalBackendIdentifier)
	{
		return FTbSimpleModuleFactory::GetTbSimpleSimpleArrayInterfaceImplementation(TbSimpleLocalBackendIdentifier, Collection);
	}

	if (TbSimpleSettings->TracerServiceIdentifier != TbSimpleLocalBackendIdentifier)
	{
		return FTbSimpleModuleFactory::GetTbSimpleSimpleArrayInterfaceImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> UTbSimpleSettings::GetITbSimpleNoPropertiesInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* TbSimpleSettings = GetMutableDefault<UTbSimpleSettings>();

	FString BackendIdentifier = TbSimpleSettings->TracerServiceIdentifier;

	if (TbSimpleSettings->TracerServiceIdentifier == TbSimpleLocalBackendIdentifier)
	{
		return FTbSimpleModuleFactory::GetTbSimpleNoPropertiesInterfaceImplementation(TbSimpleLocalBackendIdentifier, Collection);
	}

	if (TbSimpleSettings->TracerServiceIdentifier != TbSimpleLocalBackendIdentifier)
	{
		return FTbSimpleModuleFactory::GetTbSimpleNoPropertiesInterfaceImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> UTbSimpleSettings::GetITbSimpleNoOperationsInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* TbSimpleSettings = GetMutableDefault<UTbSimpleSettings>();

	FString BackendIdentifier = TbSimpleSettings->TracerServiceIdentifier;

	if (TbSimpleSettings->TracerServiceIdentifier == TbSimpleLocalBackendIdentifier)
	{
		return FTbSimpleModuleFactory::GetTbSimpleNoOperationsInterfaceImplementation(TbSimpleLocalBackendIdentifier, Collection);
	}

	if (TbSimpleSettings->TracerServiceIdentifier != TbSimpleLocalBackendIdentifier)
	{
		return FTbSimpleModuleFactory::GetTbSimpleNoOperationsInterfaceImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> UTbSimpleSettings::GetITbSimpleNoSignalsInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* TbSimpleSettings = GetMutableDefault<UTbSimpleSettings>();

	FString BackendIdentifier = TbSimpleSettings->TracerServiceIdentifier;

	if (TbSimpleSettings->TracerServiceIdentifier == TbSimpleLocalBackendIdentifier)
	{
		return FTbSimpleModuleFactory::GetTbSimpleNoSignalsInterfaceImplementation(TbSimpleLocalBackendIdentifier, Collection);
	}

	if (TbSimpleSettings->TracerServiceIdentifier != TbSimpleLocalBackendIdentifier)
	{
		return FTbSimpleModuleFactory::GetTbSimpleNoSignalsInterfaceImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> UTbSimpleSettings::GetITbSimpleEmptyInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* TbSimpleSettings = GetMutableDefault<UTbSimpleSettings>();

	FString BackendIdentifier = TbSimpleSettings->TracerServiceIdentifier;

	if (TbSimpleSettings->TracerServiceIdentifier == TbSimpleLocalBackendIdentifier)
	{
		return FTbSimpleModuleFactory::GetTbSimpleEmptyInterfaceImplementation(TbSimpleLocalBackendIdentifier, Collection);
	}

	if (TbSimpleSettings->TracerServiceIdentifier != TbSimpleLocalBackendIdentifier)
	{
		return FTbSimpleModuleFactory::GetTbSimpleEmptyInterfaceImplementation("olink", Collection);
	}

	return nullptr;
}
