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

#include "TbSame2.h"
#include "Generated/TbSame2Factory.h"
#include "Implementation/TbSame2SameStruct1Interface.h"
#include "Generated/OLink/TbSame2SameStruct1InterfaceOLinkClient.h"
#include "Implementation/TbSame2SameStruct2Interface.h"
#include "Generated/OLink/TbSame2SameStruct2InterfaceOLinkClient.h"
#include "Implementation/TbSame2SameEnum1Interface.h"
#include "Generated/OLink/TbSame2SameEnum1InterfaceOLinkClient.h"
#include "Implementation/TbSame2SameEnum2Interface.h"
#include "Generated/OLink/TbSame2SameEnum2InterfaceOLinkClient.h"
#include "Engine/Engine.h"
#include "TbSame2Settings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "TbSame2"

void FTbSame2Module::StartupModule()
{
	FTbSame2ModuleFactory::RegisterFactory(TbSame2LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame2SameStruct1InterfaceInterface>
		{
		return Cast<UTbSame2SameStruct1Interface>(Collection.InitializeDependency(UTbSame2SameStruct1Interface::StaticClass()));
	});
	FTbSame2ModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame2SameStruct1InterfaceInterface>
		{
		return Cast<UTbSame2SameStruct1InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame2SameStruct1InterfaceOLinkClient::StaticClass()));
	});
	FTbSame2ModuleFactory::RegisterFactory(TbSame2LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame2SameStruct2InterfaceInterface>
		{
		return Cast<UTbSame2SameStruct2Interface>(Collection.InitializeDependency(UTbSame2SameStruct2Interface::StaticClass()));
	});
	FTbSame2ModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame2SameStruct2InterfaceInterface>
		{
		return Cast<UTbSame2SameStruct2InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame2SameStruct2InterfaceOLinkClient::StaticClass()));
	});
	FTbSame2ModuleFactory::RegisterFactory(TbSame2LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame2SameEnum1InterfaceInterface>
		{
		return Cast<UTbSame2SameEnum1Interface>(Collection.InitializeDependency(UTbSame2SameEnum1Interface::StaticClass()));
	});
	FTbSame2ModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame2SameEnum1InterfaceInterface>
		{
		return Cast<UTbSame2SameEnum1InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame2SameEnum1InterfaceOLinkClient::StaticClass()));
	});
	FTbSame2ModuleFactory::RegisterFactory(TbSame2LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame2SameEnum2InterfaceInterface>
		{
		return Cast<UTbSame2SameEnum2Interface>(Collection.InitializeDependency(UTbSame2SameEnum2Interface::StaticClass()));
	});
	FTbSame2ModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame2SameEnum2InterfaceInterface>
		{
		return Cast<UTbSame2SameEnum2InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame2SameEnum2InterfaceOLinkClient::StaticClass()));
	});
}

void FTbSame2Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE(FTbSame2Module, TbSame2)

#undef LOCTEXT_NAMESPACE
