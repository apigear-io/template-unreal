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

#include "TbSimple.h"
#include "Generated/TbSimpleFactory.h"
#include "Implementation/TbSimpleVoidInterface.h"
#include "Generated/OLink/TbSimpleVoidInterfaceOLinkClient.h"
#include "Implementation/TbSimpleSimpleInterface.h"
#include "Generated/OLink/TbSimpleSimpleInterfaceOLinkClient.h"
#include "Implementation/TbSimpleSimpleArrayInterface.h"
#include "Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkClient.h"
#include "Implementation/TbSimpleNoPropertiesInterface.h"
#include "Generated/OLink/TbSimpleNoPropertiesInterfaceOLinkClient.h"
#include "Implementation/TbSimpleNoOperationsInterface.h"
#include "Generated/OLink/TbSimpleNoOperationsInterfaceOLinkClient.h"
#include "Implementation/TbSimpleNoSignalsInterface.h"
#include "Generated/OLink/TbSimpleNoSignalsInterfaceOLinkClient.h"
#include "Implementation/TbSimpleEmptyInterface.h"
#include "Generated/OLink/TbSimpleEmptyInterfaceOLinkClient.h"
#include "Engine/Engine.h"
#include "TbSimpleSettings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "TbSimple"

void FTbSimpleModule::StartupModule()
{
	FTbSimpleModuleFactory::RegisterFactory(TbSimpleLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleVoidInterfaceInterface>
		{
		return Cast<UTbSimpleVoidInterface>(Collection.InitializeDependency(UTbSimpleVoidInterface::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleVoidInterfaceInterface>
		{
		return Cast<UTbSimpleVoidInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleVoidInterfaceOLinkClient::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TbSimpleLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleSimpleInterfaceInterface>
		{
		return Cast<UTbSimpleSimpleInterface>(Collection.InitializeDependency(UTbSimpleSimpleInterface::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleSimpleInterfaceInterface>
		{
		return Cast<UTbSimpleSimpleInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleSimpleInterfaceOLinkClient::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TbSimpleLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface>
		{
		return Cast<UTbSimpleSimpleArrayInterface>(Collection.InitializeDependency(UTbSimpleSimpleArrayInterface::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface>
		{
		return Cast<UTbSimpleSimpleArrayInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleSimpleArrayInterfaceOLinkClient::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TbSimpleLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface>
		{
		return Cast<UTbSimpleNoPropertiesInterface>(Collection.InitializeDependency(UTbSimpleNoPropertiesInterface::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface>
		{
		return Cast<UTbSimpleNoPropertiesInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleNoPropertiesInterfaceOLinkClient::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TbSimpleLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleNoOperationsInterfaceInterface>
		{
		return Cast<UTbSimpleNoOperationsInterface>(Collection.InitializeDependency(UTbSimpleNoOperationsInterface::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleNoOperationsInterfaceInterface>
		{
		return Cast<UTbSimpleNoOperationsInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleNoOperationsInterfaceOLinkClient::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TbSimpleLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleNoSignalsInterfaceInterface>
		{
		return Cast<UTbSimpleNoSignalsInterface>(Collection.InitializeDependency(UTbSimpleNoSignalsInterface::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleNoSignalsInterfaceInterface>
		{
		return Cast<UTbSimpleNoSignalsInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleNoSignalsInterfaceOLinkClient::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TbSimpleLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleEmptyInterfaceInterface>
		{
		return Cast<UTbSimpleEmptyInterface>(Collection.InitializeDependency(UTbSimpleEmptyInterface::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleEmptyInterfaceInterface>
		{
		return Cast<UTbSimpleEmptyInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleEmptyInterfaceOLinkClient::StaticClass()));
	});
}

void FTbSimpleModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE(FTbSimpleModule, TbSimple)

#undef LOCTEXT_NAMESPACE
