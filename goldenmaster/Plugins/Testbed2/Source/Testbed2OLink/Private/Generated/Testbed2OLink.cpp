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

#include "Testbed2/Testbed2OLink.h"
#include "Testbed2/Generated/Testbed2Factory.h"
#include "Testbed2/Generated/OLink/Testbed2ManyParamInterfaceOLinkClient.h"
#include "Testbed2/Generated/OLink/Testbed2NestedStruct1InterfaceOLinkClient.h"
#include "Testbed2/Generated/OLink/Testbed2NestedStruct2InterfaceOLinkClient.h"
#include "Testbed2/Generated/OLink/Testbed2NestedStruct3InterfaceOLinkClient.h"
#include "Engine/Engine.h"
#include "Testbed2Settings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "Testbed2OLink"

void FTestbed2OLinkModule::StartupModule()
{
	FTestbed2ModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITestbed2ManyParamInterfaceInterface>
		{
		return Cast<UTestbed2ManyParamInterfaceOLinkClient>(Collection.InitializeDependency(UTestbed2ManyParamInterfaceOLinkClient::StaticClass()));
	});
	FTestbed2ModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITestbed2NestedStruct1InterfaceInterface>
		{
		return Cast<UTestbed2NestedStruct1InterfaceOLinkClient>(Collection.InitializeDependency(UTestbed2NestedStruct1InterfaceOLinkClient::StaticClass()));
	});
	FTestbed2ModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITestbed2NestedStruct2InterfaceInterface>
		{
		return Cast<UTestbed2NestedStruct2InterfaceOLinkClient>(Collection.InitializeDependency(UTestbed2NestedStruct2InterfaceOLinkClient::StaticClass()));
	});
	FTestbed2ModuleFactory::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITestbed2NestedStruct3InterfaceInterface>
		{
		return Cast<UTestbed2NestedStruct3InterfaceOLinkClient>(Collection.InitializeDependency(UTestbed2NestedStruct3InterfaceOLinkClient::StaticClass()));
	});
}

void FTestbed2OLinkModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE(FTestbed2OLinkModule, Testbed2OLink)

#undef LOCTEXT_NAMESPACE
