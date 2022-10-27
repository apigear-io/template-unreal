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

#include "TbSimpleFactory.h"
#include "Implementation/TbSimpleSimpleInterface.h"
#include "Generated/OLink/TbSimpleSimpleInterfaceOLink.h"
#include "Generated/Simulation/TbSimpleSimpleInterfaceSimulationClient.h"
#include "Implementation/TbSimpleSimpleArrayInterface.h"
#include "Generated/OLink/TbSimpleSimpleArrayInterfaceOLink.h"
#include "Generated/Simulation/TbSimpleSimpleArrayInterfaceSimulationClient.h"
#include "TbSimpleSettings.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbSimpleModuleFactory);

TScriptInterface<ITbSimpleSimpleInterfaceInterface> FTbSimpleModuleFactory::createITbSimpleSimpleInterfaceInterface()
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_OLINK:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Using OLink service backend"));
		return NewObject<UTbSimpleSimpleInterfaceOLinkService>();
	case ETbSimpleConnection::CONNECTION_SIMU:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Using simulation service backend"));
		return NewObject<UTbSimpleSimpleInterfaceSimulationClient>();
	case ETbSimpleConnection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSimpleSimpleInterface>();
	}
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleModuleFactory::createITbSimpleSimpleArrayInterfaceInterface()
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_OLINK:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Using OLink service backend"));
		return NewObject<UTbSimpleSimpleArrayInterfaceOLinkService>();
	case ETbSimpleConnection::CONNECTION_SIMU:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Using simulation service backend"));
		return NewObject<UTbSimpleSimpleArrayInterfaceSimulationClient>();
	case ETbSimpleConnection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSimpleSimpleArrayInterface>();
	}
}
