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

#include "OrgObjectapiTestbedFactory.h"
#include "Interface1/OrgObjectapiTestbedInterface1Local.h"
#include "Interface1/OrgObjectapiTestbedInterface1WAMP.h"
#include "Interface1/OrgObjectapiTestbedInterface1OLink.h"
#include "Interface1/OrgObjectapiTestbedInterface1Simulation.h"
#include "Interface2/OrgObjectapiTestbedInterface2Local.h"
#include "Interface2/OrgObjectapiTestbedInterface2WAMP.h"
#include "Interface2/OrgObjectapiTestbedInterface2OLink.h"
#include "Interface2/OrgObjectapiTestbedInterface2Simulation.h"
#include "OrgObjectapiTestbedSettings.h"

//General Log
DEFINE_LOG_CATEGORY(LogFOrgObjectapiTestbedModuleFactory);

TSharedPtr<IOrgObjectapiTestbedInterface1Interface, ESPMode::ThreadSafe> FOrgObjectapiTestbedModuleFactory::createIOrgObjectapiTestbedInterface1Interface()
{
    UOrgObjectapiTestbedSettings* settings = GetMutableDefault<UOrgObjectapiTestbedSettings>();

    switch(settings->ServiceConnection) {
        case EOrgObjectapiTestbedConnection::CONNECTION_WAMP:
            UE_LOG(LogFOrgObjectapiTestbedModuleFactory, Log, TEXT("createIOrgObjectapiTestbedInterface1Interface: Using WAMP service backend"));
            return MakeShared<OrgObjectapiTestbedInterface1WAMPService, ESPMode::ThreadSafe>();
        case EOrgObjectapiTestbedConnection::CONNECTION_OLINK:
            UE_LOG(LogFOrgObjectapiTestbedModuleFactory, Log, TEXT("createIOrgObjectapiTestbedInterface1Interface: Using OLink service backend"));
            return MakeShared<OrgObjectapiTestbedInterface1OLinkService, ESPMode::ThreadSafe>();
        case EOrgObjectapiTestbedConnection::CONNECTION_SIMU:
            UE_LOG(LogFOrgObjectapiTestbedModuleFactory, Log, TEXT("createIOrgObjectapiTestbedInterface1Interface: Using simulation service backend"));
            return MakeShared<OrgObjectapiTestbedInterface1SimulationService, ESPMode::ThreadSafe>();
        case EOrgObjectapiTestbedConnection::CONNECTION_LOCAL:
            UE_LOG(LogFOrgObjectapiTestbedModuleFactory, Log, TEXT("createIOrgObjectapiTestbedInterface1Interface: Using local service backend"));
        default:
            UE_LOG(LogFOrgObjectapiTestbedModuleFactory, Log, TEXT("createIOrgObjectapiTestbedInterface1Interface: Defaulting to local service backend"));
            return MakeShared<OrgObjectapiTestbedInterface1LocalService, ESPMode::ThreadSafe>();
    }
}

TSharedPtr<IOrgObjectapiTestbedInterface2Interface, ESPMode::ThreadSafe> FOrgObjectapiTestbedModuleFactory::createIOrgObjectapiTestbedInterface2Interface()
{
    UOrgObjectapiTestbedSettings* settings = GetMutableDefault<UOrgObjectapiTestbedSettings>();

    switch(settings->ServiceConnection) {
        case EOrgObjectapiTestbedConnection::CONNECTION_WAMP:
            UE_LOG(LogFOrgObjectapiTestbedModuleFactory, Log, TEXT("createIOrgObjectapiTestbedInterface2Interface: Using WAMP service backend"));
            return MakeShared<OrgObjectapiTestbedInterface2WAMPService, ESPMode::ThreadSafe>();
        case EOrgObjectapiTestbedConnection::CONNECTION_OLINK:
            UE_LOG(LogFOrgObjectapiTestbedModuleFactory, Log, TEXT("createIOrgObjectapiTestbedInterface2Interface: Using OLink service backend"));
            return MakeShared<OrgObjectapiTestbedInterface2OLinkService, ESPMode::ThreadSafe>();
        case EOrgObjectapiTestbedConnection::CONNECTION_SIMU:
            UE_LOG(LogFOrgObjectapiTestbedModuleFactory, Log, TEXT("createIOrgObjectapiTestbedInterface2Interface: Using simulation service backend"));
            return MakeShared<OrgObjectapiTestbedInterface2SimulationService, ESPMode::ThreadSafe>();
        case EOrgObjectapiTestbedConnection::CONNECTION_LOCAL:
            UE_LOG(LogFOrgObjectapiTestbedModuleFactory, Log, TEXT("createIOrgObjectapiTestbedInterface2Interface: Using local service backend"));
        default:
            UE_LOG(LogFOrgObjectapiTestbedModuleFactory, Log, TEXT("createIOrgObjectapiTestbedInterface2Interface: Defaulting to local service backend"));
            return MakeShared<OrgObjectapiTestbedInterface2LocalService, ESPMode::ThreadSafe>();
    }
}
