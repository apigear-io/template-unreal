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
class ITbSame2SameStruct1InterfaceInterface;
class ITbSame2SameStruct2InterfaceInterface;
class ITbSame2SameEnum1InterfaceInterface;
class ITbSame2SameEnum2InterfaceInterface;

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogFTbSame2ModuleFactory, Log, All);

class TBSAME2CORE_API FTbSame2ModuleFactory
{
public:
	/** type of function for creating implementations*/
	using FTbSame2SameStruct1InterfaceFactoryFunction = TFunction<TScriptInterface<ITbSame2SameStruct1InterfaceInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSame2SameStruct2InterfaceFactoryFunction = TFunction<TScriptInterface<ITbSame2SameStruct2InterfaceInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSame2SameEnum1InterfaceFactoryFunction = TFunction<TScriptInterface<ITbSame2SameEnum1InterfaceInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSame2SameEnum2InterfaceFactoryFunction = TFunction<TScriptInterface<ITbSame2SameEnum2InterfaceInterface>(FSubsystemCollectionBase& Collection)>;

	/** register factories for different types of implementations and interfaces */
	static bool RegisterFactory(FString TypeIdentifier, FTbSame2SameStruct1InterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSame2SameStruct2InterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSame2SameEnum1InterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSame2SameEnum2InterfaceFactoryFunction FactoryFunction);
	static TScriptInterface<ITbSame2SameStruct1InterfaceInterface> GetTbSame2SameStruct1InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame2SameStruct2InterfaceInterface> GetTbSame2SameStruct2InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame2SameEnum1InterfaceInterface> GetTbSame2SameEnum1InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame2SameEnum2InterfaceInterface> GetTbSame2SameEnum2InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);

private:
	static TMap<FString, FTbSame2ModuleFactory::FTbSame2SameStruct1InterfaceFactoryFunction> TbSame2SameStruct1InterfaceFactories;
	static TMap<FString, FTbSame2ModuleFactory::FTbSame2SameStruct2InterfaceFactoryFunction> TbSame2SameStruct2InterfaceFactories;
	static TMap<FString, FTbSame2ModuleFactory::FTbSame2SameEnum1InterfaceFactoryFunction> TbSame2SameEnum1InterfaceFactories;
	static TMap<FString, FTbSame2ModuleFactory::FTbSame2SameEnum2InterfaceFactoryFunction> TbSame2SameEnum2InterfaceFactories;
};
