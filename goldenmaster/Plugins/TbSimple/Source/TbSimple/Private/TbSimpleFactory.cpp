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
#include "SimpleInterface/TbSimpleSimpleInterfaceLocal.h"
#include "SimpleInterface/TbSimpleSimpleInterfaceWAMP.h"
#include "SimpleInterface/TbSimpleSimpleInterfaceOLink.h"
#include "SimpleInterface/TbSimpleSimpleInterfaceSimulation.h"
#include "SimpleArrayInterface/TbSimpleSimpleArrayInterfaceLocal.h"
#include "SimpleArrayInterface/TbSimpleSimpleArrayInterfaceWAMP.h"
#include "SimpleArrayInterface/TbSimpleSimpleArrayInterfaceOLink.h"
#include "SimpleArrayInterface/TbSimpleSimpleArrayInterfaceSimulation.h"
#include "TbSimpleSettings.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbSimpleModuleFactory);

TSharedPtr<ITbSimpleSimpleInterfaceInterface, ESPMode::ThreadSafe> FTbSimpleModuleFactory::createITbSimpleSimpleInterfaceInterface()
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_WAMP:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Using WAMP service backend"));
		return MakeShared<TbSimple::SimpleInterface::Private::WAMPService, ESPMode::ThreadSafe>();
	case ETbSimpleConnection::CONNECTION_OLINK:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Using OLink service backend"));
		return MakeShared<TbSimple::SimpleInterface::Private::OLinkService, ESPMode::ThreadSafe>();
	case ETbSimpleConnection::CONNECTION_SIMU:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Using simulation service backend"));
		return MakeShared<TbSimple::SimpleInterface::Private::SimulationService, ESPMode::ThreadSafe>();
	case ETbSimpleConnection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Defaulting to local service backend"));
		return MakeShared<TbSimple::SimpleInterface::Private::LocalService, ESPMode::ThreadSafe>();
	}
}

TSharedPtr<ITbSimpleSimpleArrayInterfaceInterface, ESPMode::ThreadSafe> FTbSimpleModuleFactory::createITbSimpleSimpleArrayInterfaceInterface()
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_WAMP:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Using WAMP service backend"));
		return MakeShared<TbSimple::SimpleArrayInterface::Private::WAMPService, ESPMode::ThreadSafe>();
	case ETbSimpleConnection::CONNECTION_OLINK:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Using OLink service backend"));
		return MakeShared<TbSimple::SimpleArrayInterface::Private::OLinkService, ESPMode::ThreadSafe>();
	case ETbSimpleConnection::CONNECTION_SIMU:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Using simulation service backend"));
		return MakeShared<TbSimple::SimpleArrayInterface::Private::SimulationService, ESPMode::ThreadSafe>();
	case ETbSimpleConnection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Defaulting to local service backend"));
		return MakeShared<TbSimple::SimpleArrayInterface::Private::LocalService, ESPMode::ThreadSafe>();
	}
}
