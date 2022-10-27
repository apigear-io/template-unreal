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

#include "TbSame2Factory.h"
#include "Implementation/TbSame2SameStruct1InterfaceLocal.h"
#include "Generated/OLink/TbSame2SameStruct1InterfaceOLink.h"
#include "Generated/Simulation/TbSame2SameStruct1InterfaceSimulation.h"
#include "Implementation/TbSame2SameStruct2InterfaceLocal.h"
#include "Generated/OLink/TbSame2SameStruct2InterfaceOLink.h"
#include "Generated/Simulation/TbSame2SameStruct2InterfaceSimulation.h"
#include "Implementation/TbSame2SameEnum1InterfaceLocal.h"
#include "Generated/OLink/TbSame2SameEnum1InterfaceOLink.h"
#include "Generated/Simulation/TbSame2SameEnum1InterfaceSimulation.h"
#include "Implementation/TbSame2SameEnum2InterfaceLocal.h"
#include "Generated/OLink/TbSame2SameEnum2InterfaceOLink.h"
#include "Generated/Simulation/TbSame2SameEnum2InterfaceSimulation.h"
#include "TbSame2Settings.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbSame2ModuleFactory);

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> FTbSame2ModuleFactory::createITbSame2SameStruct1InterfaceInterface()
{
	UTbSame2Settings* settings = GetMutableDefault<UTbSame2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct1InterfaceInterface: Using OLink service backend"));
		return NewObject<UTbSame2SameStruct1InterfaceOLinkService>();
	case ETbSame2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct1InterfaceInterface: Using simulation service backend"));
		return NewObject<UTbSame2SameStruct1InterfaceSimulationService>();
	case ETbSame2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct1InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct1InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame2SameStruct1InterfaceLocalService>();
	}
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> FTbSame2ModuleFactory::createITbSame2SameStruct2InterfaceInterface()
{
	UTbSame2Settings* settings = GetMutableDefault<UTbSame2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct2InterfaceInterface: Using OLink service backend"));
		return NewObject<UTbSame2SameStruct2InterfaceOLinkService>();
	case ETbSame2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct2InterfaceInterface: Using simulation service backend"));
		return NewObject<UTbSame2SameStruct2InterfaceSimulationService>();
	case ETbSame2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct2InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct2InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame2SameStruct2InterfaceLocalService>();
	}
}

TScriptInterface<ITbSame2SameEnum1InterfaceInterface> FTbSame2ModuleFactory::createITbSame2SameEnum1InterfaceInterface()
{
	UTbSame2Settings* settings = GetMutableDefault<UTbSame2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum1InterfaceInterface: Using OLink service backend"));
		return NewObject<UTbSame2SameEnum1InterfaceOLinkService>();
	case ETbSame2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum1InterfaceInterface: Using simulation service backend"));
		return NewObject<UTbSame2SameEnum1InterfaceSimulationService>();
	case ETbSame2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum1InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum1InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame2SameEnum1InterfaceLocalService>();
	}
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> FTbSame2ModuleFactory::createITbSame2SameEnum2InterfaceInterface()
{
	UTbSame2Settings* settings = GetMutableDefault<UTbSame2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum2InterfaceInterface: Using OLink service backend"));
		return NewObject<UTbSame2SameEnum2InterfaceOLinkService>();
	case ETbSame2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum2InterfaceInterface: Using simulation service backend"));
		return NewObject<UTbSame2SameEnum2InterfaceSimulationService>();
	case ETbSame2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum2InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum2InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame2SameEnum2InterfaceLocalService>();
	}
}
