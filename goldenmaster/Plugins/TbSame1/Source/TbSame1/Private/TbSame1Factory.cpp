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

#include "TbSame1Factory.h"
#include "SameStruct1Interface/TbSame1SameStruct1InterfaceLocal.h"
#include "SameStruct1Interface/TbSame1SameStruct1InterfaceOLink.h"
#include "SameStruct1Interface/TbSame1SameStruct1InterfaceSimulation.h"
#include "SameStruct2Interface/TbSame1SameStruct2InterfaceLocal.h"
#include "SameStruct2Interface/TbSame1SameStruct2InterfaceOLink.h"
#include "SameStruct2Interface/TbSame1SameStruct2InterfaceSimulation.h"
#include "SameEnum1Interface/TbSame1SameEnum1InterfaceLocal.h"
#include "SameEnum1Interface/TbSame1SameEnum1InterfaceOLink.h"
#include "SameEnum1Interface/TbSame1SameEnum1InterfaceSimulation.h"
#include "SameEnum2Interface/TbSame1SameEnum2InterfaceLocal.h"
#include "SameEnum2Interface/TbSame1SameEnum2InterfaceOLink.h"
#include "SameEnum2Interface/TbSame1SameEnum2InterfaceSimulation.h"
#include "TbSame1Settings.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbSame1ModuleFactory);

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> FTbSame1ModuleFactory::createITbSame1SameStruct1InterfaceInterface()
{
	UTbSame1Settings* settings = GetMutableDefault<UTbSame1Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame1Connection::CONNECTION_OLINK:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct1InterfaceInterface: Using OLink service backend"));
		return NewObject<UTbSame1SameStruct1InterfaceOLinkService>();
	case ETbSame1Connection::CONNECTION_SIMU:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct1InterfaceInterface: Using simulation service backend"));
		return NewObject<UTbSame1SameStruct1InterfaceSimulationService>();
	case ETbSame1Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct1InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct1InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame1SameStruct1InterfaceLocalService>();
	}
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> FTbSame1ModuleFactory::createITbSame1SameStruct2InterfaceInterface()
{
	UTbSame1Settings* settings = GetMutableDefault<UTbSame1Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame1Connection::CONNECTION_OLINK:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct2InterfaceInterface: Using OLink service backend"));
		return NewObject<UTbSame1SameStruct2InterfaceOLinkService>();
	case ETbSame1Connection::CONNECTION_SIMU:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct2InterfaceInterface: Using simulation service backend"));
		return NewObject<UTbSame1SameStruct2InterfaceSimulationService>();
	case ETbSame1Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct2InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct2InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame1SameStruct2InterfaceLocalService>();
	}
}

TScriptInterface<ITbSame1SameEnum1InterfaceInterface> FTbSame1ModuleFactory::createITbSame1SameEnum1InterfaceInterface()
{
	UTbSame1Settings* settings = GetMutableDefault<UTbSame1Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame1Connection::CONNECTION_OLINK:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum1InterfaceInterface: Using OLink service backend"));
		return NewObject<UTbSame1SameEnum1InterfaceOLinkService>();
	case ETbSame1Connection::CONNECTION_SIMU:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum1InterfaceInterface: Using simulation service backend"));
		return NewObject<UTbSame1SameEnum1InterfaceSimulationService>();
	case ETbSame1Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum1InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum1InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame1SameEnum1InterfaceLocalService>();
	}
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> FTbSame1ModuleFactory::createITbSame1SameEnum2InterfaceInterface()
{
	UTbSame1Settings* settings = GetMutableDefault<UTbSame1Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame1Connection::CONNECTION_OLINK:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum2InterfaceInterface: Using OLink service backend"));
		return NewObject<UTbSame1SameEnum2InterfaceOLinkService>();
	case ETbSame1Connection::CONNECTION_SIMU:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum2InterfaceInterface: Using simulation service backend"));
		return NewObject<UTbSame1SameEnum2InterfaceSimulationService>();
	case ETbSame1Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum2InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum2InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame1SameEnum2InterfaceLocalService>();
	}
}
