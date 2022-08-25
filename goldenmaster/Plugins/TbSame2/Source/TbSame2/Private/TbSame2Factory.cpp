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
#include "SameStruct1Interface/TbSame2SameStruct1InterfaceLocal.h"
#include "SameStruct1Interface/TbSame2SameStruct1InterfaceOLink.h"
#include "SameStruct1Interface/TbSame2SameStruct1InterfaceSimulation.h"
#include "SameStruct2Interface/TbSame2SameStruct2InterfaceLocal.h"
#include "SameStruct2Interface/TbSame2SameStruct2InterfaceOLink.h"
#include "SameStruct2Interface/TbSame2SameStruct2InterfaceSimulation.h"
#include "SameEnum1Interface/TbSame2SameEnum1InterfaceLocal.h"
#include "SameEnum1Interface/TbSame2SameEnum1InterfaceOLink.h"
#include "SameEnum1Interface/TbSame2SameEnum1InterfaceSimulation.h"
#include "SameEnum2Interface/TbSame2SameEnum2InterfaceLocal.h"
#include "SameEnum2Interface/TbSame2SameEnum2InterfaceOLink.h"
#include "SameEnum2Interface/TbSame2SameEnum2InterfaceSimulation.h"
#include "TbSame2Settings.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbSame2ModuleFactory);

TSharedPtr<ITbSame2SameStruct1InterfaceInterface, ESPMode::ThreadSafe> FTbSame2ModuleFactory::createITbSame2SameStruct1InterfaceInterface()
{
	UTbSame2Settings* settings = GetMutableDefault<UTbSame2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct1InterfaceInterface: Using OLink service backend"));
		return MakeShared<TbSame2::SameStruct1Interface::Private::OLinkService, ESPMode::ThreadSafe>();
	case ETbSame2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct1InterfaceInterface: Using simulation service backend"));
		return MakeShared<TbSame2::SameStruct1Interface::Private::SimulationService, ESPMode::ThreadSafe>();
	case ETbSame2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct1InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct1InterfaceInterface: Defaulting to local service backend"));
		return MakeShared<TbSame2::SameStruct1Interface::Private::LocalService, ESPMode::ThreadSafe>();
	}
}

TSharedPtr<ITbSame2SameStruct2InterfaceInterface, ESPMode::ThreadSafe> FTbSame2ModuleFactory::createITbSame2SameStruct2InterfaceInterface()
{
	UTbSame2Settings* settings = GetMutableDefault<UTbSame2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct2InterfaceInterface: Using OLink service backend"));
		return MakeShared<TbSame2::SameStruct2Interface::Private::OLinkService, ESPMode::ThreadSafe>();
	case ETbSame2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct2InterfaceInterface: Using simulation service backend"));
		return MakeShared<TbSame2::SameStruct2Interface::Private::SimulationService, ESPMode::ThreadSafe>();
	case ETbSame2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct2InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct2InterfaceInterface: Defaulting to local service backend"));
		return MakeShared<TbSame2::SameStruct2Interface::Private::LocalService, ESPMode::ThreadSafe>();
	}
}

TSharedPtr<ITbSame2SameEnum1InterfaceInterface, ESPMode::ThreadSafe> FTbSame2ModuleFactory::createITbSame2SameEnum1InterfaceInterface()
{
	UTbSame2Settings* settings = GetMutableDefault<UTbSame2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum1InterfaceInterface: Using OLink service backend"));
		return MakeShared<TbSame2::SameEnum1Interface::Private::OLinkService, ESPMode::ThreadSafe>();
	case ETbSame2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum1InterfaceInterface: Using simulation service backend"));
		return MakeShared<TbSame2::SameEnum1Interface::Private::SimulationService, ESPMode::ThreadSafe>();
	case ETbSame2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum1InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum1InterfaceInterface: Defaulting to local service backend"));
		return MakeShared<TbSame2::SameEnum1Interface::Private::LocalService, ESPMode::ThreadSafe>();
	}
}

TSharedPtr<ITbSame2SameEnum2InterfaceInterface, ESPMode::ThreadSafe> FTbSame2ModuleFactory::createITbSame2SameEnum2InterfaceInterface()
{
	UTbSame2Settings* settings = GetMutableDefault<UTbSame2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum2InterfaceInterface: Using OLink service backend"));
		return MakeShared<TbSame2::SameEnum2Interface::Private::OLinkService, ESPMode::ThreadSafe>();
	case ETbSame2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum2InterfaceInterface: Using simulation service backend"));
		return MakeShared<TbSame2::SameEnum2Interface::Private::SimulationService, ESPMode::ThreadSafe>();
	case ETbSame2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum2InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum2InterfaceInterface: Defaulting to local service backend"));
		return MakeShared<TbSame2::SameEnum2Interface::Private::LocalService, ESPMode::ThreadSafe>();
	}
}
