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
	/** type of function for creating implementations*/
	using FTestbed2ManyParamInterfaceFactoryFunction = TFunction<TScriptInterface<ITestbed2ManyParamInterfaceInterface>(FSubsystemCollectionBase& Collection)>;
	using FTestbed2NestedStruct1InterfaceFactoryFunction = TFunction<TScriptInterface<ITestbed2NestedStruct1InterfaceInterface>(FSubsystemCollectionBase& Collection)>;
	using FTestbed2NestedStruct2InterfaceFactoryFunction = TFunction<TScriptInterface<ITestbed2NestedStruct2InterfaceInterface>(FSubsystemCollectionBase& Collection)>;
	using FTestbed2NestedStruct3InterfaceFactoryFunction = TFunction<TScriptInterface<ITestbed2NestedStruct3InterfaceInterface>(FSubsystemCollectionBase& Collection)>;

	/** register factories for different types of implementations and interfaces */
	static bool RegisterFactory(FString TypeIdentifier, FTestbed2ManyParamInterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTestbed2NestedStruct1InterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTestbed2NestedStruct2InterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTestbed2NestedStruct3InterfaceFactoryFunction FactoryFunction);
	static TScriptInterface<ITestbed2ManyParamInterfaceInterface> GetTestbed2ManyParamInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> GetTestbed2NestedStruct1InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> GetTestbed2NestedStruct2InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> GetTestbed2NestedStruct3InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);

private:
	static TMap<FString, FTestbed2ModuleFactory::FTestbed2ManyParamInterfaceFactoryFunction> Testbed2ManyParamInterfaceFactories;
	static TMap<FString, FTestbed2ModuleFactory::FTestbed2NestedStruct1InterfaceFactoryFunction> Testbed2NestedStruct1InterfaceFactories;
	static TMap<FString, FTestbed2ModuleFactory::FTestbed2NestedStruct2InterfaceFactoryFunction> Testbed2NestedStruct2InterfaceFactories;
	static TMap<FString, FTestbed2ModuleFactory::FTestbed2NestedStruct3InterfaceFactoryFunction> Testbed2NestedStruct3InterfaceFactories;
};
