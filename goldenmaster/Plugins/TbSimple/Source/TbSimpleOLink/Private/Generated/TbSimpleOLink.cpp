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

#include "TbSimple/TbSimpleOLink.h"
#include "TbSimple/Generated/TbSimpleFactory.h"
#include "TbSimple/Generated/OLink/TbSimpleVoidInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleSimpleInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleNoPropertiesInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleNoOperationsInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleNoSignalsInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleEmptyInterfaceOLinkClient.h"
#include "Engine/Engine.h"
#include "TbSimpleSettings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "TbSimpleOLink"

void FTbSimpleOLinkModule::StartupModule()
{
	FTbSimpleModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleVoidInterfaceInterface>
		{
		return Cast<UTbSimpleVoidInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleVoidInterfaceOLinkClient::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleSimpleInterfaceInterface>
		{
		return Cast<UTbSimpleSimpleInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleSimpleInterfaceOLinkClient::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface>
		{
		return Cast<UTbSimpleSimpleArrayInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleSimpleArrayInterfaceOLinkClient::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface>
		{
		return Cast<UTbSimpleNoPropertiesInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleNoPropertiesInterfaceOLinkClient::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleNoOperationsInterfaceInterface>
		{
		return Cast<UTbSimpleNoOperationsInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleNoOperationsInterfaceOLinkClient::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleNoSignalsInterfaceInterface>
		{
		return Cast<UTbSimpleNoSignalsInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleNoSignalsInterfaceOLinkClient::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleEmptyInterfaceInterface>
		{
		return Cast<UTbSimpleEmptyInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleEmptyInterfaceOLinkClient::StaticClass()));
	});
}

void FTbSimpleOLinkModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE(FTbSimpleOLinkModule, TbSimpleOLink)

#undef LOCTEXT_NAMESPACE
