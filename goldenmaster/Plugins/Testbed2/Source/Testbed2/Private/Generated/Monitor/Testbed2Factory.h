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
#pragma once

#include "Logging/LogMacros.h"
#include "UObject/ScriptInterface.h"
#include "Runtime/Launch/Resources/Version.h"

class UGameInstance;
class FSubsystemCollectionBase;
class ITestbed2ManyParamInterfaceInterface;
class ITestbed2NestedStruct1InterfaceInterface;
class ITestbed2NestedStruct2InterfaceInterface;
class ITestbed2NestedStruct3InterfaceInterface;

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogFTestbed2ModuleFactory, Log, All);

class FTestbed2ModuleFactory
{
public:
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	static TScriptInterface<ITestbed2ManyParamInterfaceInterface> createITestbed2ManyParamInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> createITestbed2NestedStruct1InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> createITestbed2NestedStruct2InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> createITestbed2NestedStruct3InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
#else
	static TScriptInterface<ITestbed2ManyParamInterfaceInterface> createITestbed2ManyParamInterfaceInterface(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> createITestbed2NestedStruct1InterfaceInterface(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> createITestbed2NestedStruct2InterfaceInterface(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> createITestbed2NestedStruct3InterfaceInterface(FSubsystemCollectionBase& Collection);
#endif
};
