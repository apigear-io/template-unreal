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

#include "TbEnumFactory.h"
#include "Implementation/TbEnumEnumInterfaceLocal.h"
#include "Generated/OLink/TbEnumEnumInterfaceOLink.h"
#include "Generated/Simulation/TbEnumEnumInterfaceSimulation.h"
#include "TbEnumSettings.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbEnumModuleFactory);

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumModuleFactory::createITbEnumEnumInterfaceInterface()
{
	UTbEnumSettings* settings = GetMutableDefault<UTbEnumSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbEnumConnection::CONNECTION_OLINK:
		UE_LOG(LogFTbEnumModuleFactory, Log, TEXT("createITbEnumEnumInterfaceInterface: Using OLink service backend"));
		return NewObject<UTbEnumEnumInterfaceOLinkService>();
	case ETbEnumConnection::CONNECTION_SIMU:
		UE_LOG(LogFTbEnumModuleFactory, Log, TEXT("createITbEnumEnumInterfaceInterface: Using simulation service backend"));
		return NewObject<UTbEnumEnumInterfaceSimulationService>();
	case ETbEnumConnection::CONNECTION_LOCAL:
		UE_LOG(LogFTbEnumModuleFactory, Log, TEXT("createITbEnumEnumInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbEnumModuleFactory, Log, TEXT("createITbEnumEnumInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbEnumEnumInterfaceLocalService>();
	}
}
