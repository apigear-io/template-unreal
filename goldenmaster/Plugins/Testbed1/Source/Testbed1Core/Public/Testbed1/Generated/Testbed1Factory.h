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
class ITestbed1StructInterfaceInterface;
class ITestbed1StructArrayInterfaceInterface;

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogFTestbed1ModuleFactory, Log, All);

class TESTBED1CORE_API FTestbed1ModuleFactory
{
public:
	/** type of function for creating implementations*/
	using FTestbed1StructInterfaceFactoryFunction = TFunction<TScriptInterface<ITestbed1StructInterfaceInterface>(FSubsystemCollectionBase& Collection)>;
	using FTestbed1StructArrayInterfaceFactoryFunction = TFunction<TScriptInterface<ITestbed1StructArrayInterfaceInterface>(FSubsystemCollectionBase& Collection)>;

	/** register factories for different types of implementations and interfaces */
	static bool RegisterFactory(FString TypeIdentifier, FTestbed1StructInterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTestbed1StructArrayInterfaceFactoryFunction FactoryFunction);
	static TScriptInterface<ITestbed1StructInterfaceInterface> GetTestbed1StructInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITestbed1StructArrayInterfaceInterface> GetTestbed1StructArrayInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);

private:
	static TMap<FString, FTestbed1ModuleFactory::FTestbed1StructInterfaceFactoryFunction> Testbed1StructInterfaceFactories;
	static TMap<FString, FTestbed1ModuleFactory::FTestbed1StructArrayInterfaceFactoryFunction> Testbed1StructArrayInterfaceFactories;
};
