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

#include "Generated/TbSame2Factory.h"
#include "ApiGearSettings.h"
#include "ApiGearOLink.h"
#include "TbSame2Settings.h"
#include "Implementation/TbSame2SameStruct1Interface.h"
#include "Generated/OLink/TbSame2SameStruct1InterfaceOLinkClient.h"
#include "Implementation/TbSame2SameStruct2Interface.h"
#include "Generated/OLink/TbSame2SameStruct2InterfaceOLinkClient.h"
#include "Implementation/TbSame2SameEnum1Interface.h"
#include "Generated/OLink/TbSame2SameEnum1InterfaceOLinkClient.h"
#include "Implementation/TbSame2SameEnum2Interface.h"
#include "Generated/OLink/TbSame2SameEnum2InterfaceOLinkClient.h"
#include "TbSame2Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbSame2ModuleFactory);

namespace
{
bool IsTbSame2LogEnabled()
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	return settings->Tracer_EnableDebugLog;
}
} // namespace

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> createTbSame2SameStruct1InterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame2LogEnabled())
	{
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct1InterfaceInterface: Using OLink service backend"));
	}

	UTbSame2SameStruct1InterfaceOLinkClient* Instance = Cast<UTbSame2SameStruct1InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame2SameStruct1InterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> createTbSame2SameStruct1Interface(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame2LogEnabled())
	{
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct1InterfaceInterface: Using local service backend"));
	}

	UTbSame2SameStruct1Interface* Instance = Cast<UTbSame2SameStruct1Interface>(Collection.InitializeDependency(UTbSame2SameStruct1Interface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> FTbSame2ModuleFactory::createITbSame2SameStruct1InterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbSame2Settings* TbSame2Settings = GetMutableDefault<UTbSame2Settings>();

	if (TbSame2Settings->TracerServiceIdentifier == TbSame2LocalBackendIdentifier)
	{
		return createTbSame2SameStruct1Interface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(TbSame2Settings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTbSame2SameStruct1InterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTbSame2SameStruct1InterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTbSame2SameStruct1Interface(Collection);
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> createTbSame2SameStruct2InterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame2LogEnabled())
	{
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct2InterfaceInterface: Using OLink service backend"));
	}

	UTbSame2SameStruct2InterfaceOLinkClient* Instance = Cast<UTbSame2SameStruct2InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame2SameStruct2InterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> createTbSame2SameStruct2Interface(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame2LogEnabled())
	{
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct2InterfaceInterface: Using local service backend"));
	}

	UTbSame2SameStruct2Interface* Instance = Cast<UTbSame2SameStruct2Interface>(Collection.InitializeDependency(UTbSame2SameStruct2Interface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> FTbSame2ModuleFactory::createITbSame2SameStruct2InterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbSame2Settings* TbSame2Settings = GetMutableDefault<UTbSame2Settings>();

	if (TbSame2Settings->TracerServiceIdentifier == TbSame2LocalBackendIdentifier)
	{
		return createTbSame2SameStruct2Interface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(TbSame2Settings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTbSame2SameStruct2InterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTbSame2SameStruct2InterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTbSame2SameStruct2Interface(Collection);
}

TScriptInterface<ITbSame2SameEnum1InterfaceInterface> createTbSame2SameEnum1InterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame2LogEnabled())
	{
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum1InterfaceInterface: Using OLink service backend"));
	}

	UTbSame2SameEnum1InterfaceOLinkClient* Instance = Cast<UTbSame2SameEnum1InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame2SameEnum1InterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame2SameEnum1InterfaceInterface> createTbSame2SameEnum1Interface(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame2LogEnabled())
	{
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum1InterfaceInterface: Using local service backend"));
	}

	UTbSame2SameEnum1Interface* Instance = Cast<UTbSame2SameEnum1Interface>(Collection.InitializeDependency(UTbSame2SameEnum1Interface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame2SameEnum1InterfaceInterface> FTbSame2ModuleFactory::createITbSame2SameEnum1InterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbSame2Settings* TbSame2Settings = GetMutableDefault<UTbSame2Settings>();

	if (TbSame2Settings->TracerServiceIdentifier == TbSame2LocalBackendIdentifier)
	{
		return createTbSame2SameEnum1Interface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(TbSame2Settings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTbSame2SameEnum1InterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTbSame2SameEnum1InterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTbSame2SameEnum1Interface(Collection);
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> createTbSame2SameEnum2InterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame2LogEnabled())
	{
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum2InterfaceInterface: Using OLink service backend"));
	}

	UTbSame2SameEnum2InterfaceOLinkClient* Instance = Cast<UTbSame2SameEnum2InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame2SameEnum2InterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> createTbSame2SameEnum2Interface(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame2LogEnabled())
	{
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum2InterfaceInterface: Using local service backend"));
	}

	UTbSame2SameEnum2Interface* Instance = Cast<UTbSame2SameEnum2Interface>(Collection.InitializeDependency(UTbSame2SameEnum2Interface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> FTbSame2ModuleFactory::createITbSame2SameEnum2InterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbSame2Settings* TbSame2Settings = GetMutableDefault<UTbSame2Settings>();

	if (TbSame2Settings->TracerServiceIdentifier == TbSame2LocalBackendIdentifier)
	{
		return createTbSame2SameEnum2Interface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(TbSame2Settings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTbSame2SameEnum2InterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTbSame2SameEnum2InterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTbSame2SameEnum2Interface(Collection);
}
