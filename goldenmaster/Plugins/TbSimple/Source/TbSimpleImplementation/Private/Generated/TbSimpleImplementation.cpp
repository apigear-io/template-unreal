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

#include "TbSimple/TbSimpleImplementation.h"
#include "TbSimple/Generated/TbSimpleFactory.h"
#include "TbSimple/Implementation/TbSimpleVoidInterface.h"
#include "TbSimple/Implementation/TbSimpleSimpleInterface.h"
#include "TbSimple/Implementation/TbSimpleSimpleArrayInterface.h"
#include "TbSimple/Implementation/TbSimpleNoPropertiesInterface.h"
#include "TbSimple/Implementation/TbSimpleNoOperationsInterface.h"
#include "TbSimple/Implementation/TbSimpleNoSignalsInterface.h"
#include "TbSimple/Implementation/TbSimpleEmptyInterface.h"
#include "Engine/Engine.h"
#include "TbSimpleSettings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "TbSimpleImplementation"

void FTbSimpleImplementationModule::StartupModule()
{
	FTbSimpleModuleFactory::RegisterFactory(TbSimpleLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleVoidInterfaceInterface>
		{
		return Cast<UTbSimpleVoidInterface>(Collection.InitializeDependency(UTbSimpleVoidInterface::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TbSimpleLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleSimpleInterfaceInterface>
		{
		return Cast<UTbSimpleSimpleInterface>(Collection.InitializeDependency(UTbSimpleSimpleInterface::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TbSimpleLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface>
		{
		return Cast<UTbSimpleSimpleArrayInterface>(Collection.InitializeDependency(UTbSimpleSimpleArrayInterface::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TbSimpleLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface>
		{
		return Cast<UTbSimpleNoPropertiesInterface>(Collection.InitializeDependency(UTbSimpleNoPropertiesInterface::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TbSimpleLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleNoOperationsInterfaceInterface>
		{
		return Cast<UTbSimpleNoOperationsInterface>(Collection.InitializeDependency(UTbSimpleNoOperationsInterface::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TbSimpleLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleNoSignalsInterfaceInterface>
		{
		return Cast<UTbSimpleNoSignalsInterface>(Collection.InitializeDependency(UTbSimpleNoSignalsInterface::StaticClass()));
	});
	FTbSimpleModuleFactory::RegisterFactory(TbSimpleLocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSimpleEmptyInterfaceInterface>
		{
		return Cast<UTbSimpleEmptyInterface>(Collection.InitializeDependency(UTbSimpleEmptyInterface::StaticClass()));
	});
}

void FTbSimpleImplementationModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE(FTbSimpleImplementationModule, TbSimpleImplementation)

#undef LOCTEXT_NAMESPACE
