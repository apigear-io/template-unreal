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

#include "Generated/TbEnumFactory.h"
#include "ApiGearSettings.h"
#include "ApiGearOLink.h"
#include "TbEnumSettings.h"
#include "Implementation/TbEnumEnumInterface.h"
#include "Generated/OLink/TbEnumEnumInterfaceOLinkClient.h"
#include "TbEnumSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbEnumModuleFactory);

namespace
{
bool IsTbEnumLogEnabled()
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	return settings->Tracer_EnableDebugLog;
}
} // namespace

TScriptInterface<ITbEnumEnumInterfaceInterface> createTbEnumEnumInterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTbEnumLogEnabled())
	{
		UE_LOG(LogFTbEnumModuleFactory, Log, TEXT("createITbEnumEnumInterfaceInterface: Using OLink service backend"));
	}

	UTbEnumEnumInterfaceOLinkClient* Instance = Cast<UTbEnumEnumInterfaceOLinkClient>(Collection.InitializeDependency(UTbEnumEnumInterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbEnumEnumInterfaceInterface> createTbEnumEnumInterface(FSubsystemCollectionBase& Collection)
{
	if (IsTbEnumLogEnabled())
	{
		UE_LOG(LogFTbEnumModuleFactory, Log, TEXT("createITbEnumEnumInterfaceInterface: Using local service backend"));
	}

	UTbEnumEnumInterface* Instance = Cast<UTbEnumEnumInterface>(Collection.InitializeDependency(UTbEnumEnumInterface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumModuleFactory::createITbEnumEnumInterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbEnumSettings* TbEnumSettings = GetMutableDefault<UTbEnumSettings>();

	if (TbEnumSettings->TracerServiceIdentifier == TbEnumLocalBackendIdentifier)
	{
		return createTbEnumEnumInterface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(TbEnumSettings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTbEnumEnumInterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTbEnumEnumInterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTbEnumEnumInterface(Collection);
}
