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

#include "TbNamesFactory.h"
#include "ApiGearSettings.h"
#include "ApiGearOLink.h"
#include "TbNamesSettings.h"
#include "Implementation/TbNamesNamEs.h"
#include "Generated/OLink/TbNamesNamEsOLinkClient.h"
#include "TbNamesSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbNamesModuleFactory);

namespace
{
bool IsTbNamesLogEnabled()
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	return settings->Tracer_EnableDebugLog;
}
} // namespace

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
TScriptInterface<ITbNamesNamEsInterface> createTbNamesNamEsOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	if (IsTbNamesLogEnabled())
	{
		UE_LOG(LogFTbNamesModuleFactory, Log, TEXT("createITbNamesNamEsInterface: Using OLink service backend"));
	}

	UTbNamesNamEsOLinkClient* Instance = GameInstance->GetSubsystem<UTbNamesNamEsOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbNamesNamEsOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbNamesNamEsOLinkClient>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITbNamesNamEsInterface> createTbNamesNamEs(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	if (IsTbNamesLogEnabled())
	{
		UE_LOG(LogFTbNamesModuleFactory, Log, TEXT("createITbNamesNamEsInterface: Using local service backend"));
	}

	UTbNamesNamEs* Instance = GameInstance->GetSubsystem<UTbNamesNamEs>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbNamesNamEs::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbNamesNamEs>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITbNamesNamEsInterface> FTbNamesModuleFactory::createITbNamesNamEsInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbNamesSettings* TbNamesSettings = GetMutableDefault<UTbNamesSettings>();

	if (TbNamesSettings->TracerServiceIdentifier == TbNamesLocalBackendIdentifier)
	{
		return createTbNamesNamEs(GameInstance, Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(TbNamesSettings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTbNamesNamEsOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTbNamesNamEsOLink(GameInstance, Collection);
	}

	// fallback to local implementation
	return createTbNamesNamEs(GameInstance, Collection);
}

#else

TScriptInterface<ITbNamesNamEsInterface> createTbNamesNamEsOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTbNamesLogEnabled())
	{
		UE_LOG(LogFTbNamesModuleFactory, Log, TEXT("createITbNamesNamEsInterface: Using OLink service backend"));
	}

	UTbNamesNamEsOLinkClient* Instance = Cast<UTbNamesNamEsOLinkClient>(Collection.InitializeDependency(UTbNamesNamEsOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbNamesNamEsInterface> createTbNamesNamEs(FSubsystemCollectionBase& Collection)
{
	if (IsTbNamesLogEnabled())
	{
		UE_LOG(LogFTbNamesModuleFactory, Log, TEXT("createITbNamesNamEsInterface: Using local service backend"));
	}

	UTbNamesNamEs* Instance = Cast<UTbNamesNamEs>(Collection.InitializeDependency(UTbNamesNamEs::StaticClass()));
	return Instance;
}

TScriptInterface<ITbNamesNamEsInterface> FTbNamesModuleFactory::createITbNamesNamEsInterface(FSubsystemCollectionBase& Collection)
{
	UTbNamesSettings* TbNamesSettings = GetMutableDefault<UTbNamesSettings>();

	if (TbNamesSettings->TracerServiceIdentifier == TbNamesLocalBackendIdentifier)
	{
		return createTbNamesNamEs(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(TbNamesSettings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTbNamesNamEsOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTbNamesNamEsOLink(Collection);
	}

	// fallback to local implementation
	return createTbNamesNamEs(Collection);
}
#endif
