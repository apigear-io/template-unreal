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

#include "TbSame1.h"
#include "Generated/TbSame1Factory.h"
#include "Implementation/TbSame1SameStruct1Interface.h"
#include "Generated/OLink/TbSame1SameStruct1InterfaceOLinkClient.h"
#include "Implementation/TbSame1SameStruct2Interface.h"
#include "Generated/OLink/TbSame1SameStruct2InterfaceOLinkClient.h"
#include "Implementation/TbSame1SameEnum1Interface.h"
#include "Generated/OLink/TbSame1SameEnum1InterfaceOLinkClient.h"
#include "Implementation/TbSame1SameEnum2Interface.h"
#include "Generated/OLink/TbSame1SameEnum2InterfaceOLinkClient.h"
#include "Engine/Engine.h"
#include "TbSame1Settings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "TbSame1"

void FTbSame1Module::StartupModule()
{
	FTbSame1ModuleFactory::RegisterFactory(TbSame1LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame1SameStruct1InterfaceInterface>
		{
		return Cast<UTbSame1SameStruct1Interface>(Collection.InitializeDependency(UTbSame1SameStruct1Interface::StaticClass()));
	});
	FTbSame1ModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame1SameStruct1InterfaceInterface>
		{
		return Cast<UTbSame1SameStruct1InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame1SameStruct1InterfaceOLinkClient::StaticClass()));
	});
	FTbSame1ModuleFactory::RegisterFactory(TbSame1LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame1SameStruct2InterfaceInterface>
		{
		return Cast<UTbSame1SameStruct2Interface>(Collection.InitializeDependency(UTbSame1SameStruct2Interface::StaticClass()));
	});
	FTbSame1ModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame1SameStruct2InterfaceInterface>
		{
		return Cast<UTbSame1SameStruct2InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame1SameStruct2InterfaceOLinkClient::StaticClass()));
	});
	FTbSame1ModuleFactory::RegisterFactory(TbSame1LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame1SameEnum1InterfaceInterface>
		{
		return Cast<UTbSame1SameEnum1Interface>(Collection.InitializeDependency(UTbSame1SameEnum1Interface::StaticClass()));
	});
	FTbSame1ModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame1SameEnum1InterfaceInterface>
		{
		return Cast<UTbSame1SameEnum1InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame1SameEnum1InterfaceOLinkClient::StaticClass()));
	});
	FTbSame1ModuleFactory::RegisterFactory(TbSame1LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame1SameEnum2InterfaceInterface>
		{
		return Cast<UTbSame1SameEnum2Interface>(Collection.InitializeDependency(UTbSame1SameEnum2Interface::StaticClass()));
	});
	FTbSame1ModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITbSame1SameEnum2InterfaceInterface>
		{
		return Cast<UTbSame1SameEnum2InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame1SameEnum2InterfaceOLinkClient::StaticClass()));
	});
}

void FTbSame1Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE(FTbSame1Module, TbSame1)

#undef LOCTEXT_NAMESPACE
