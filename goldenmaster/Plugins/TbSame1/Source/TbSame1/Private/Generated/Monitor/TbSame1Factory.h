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
class ITbSame1SameStruct1InterfaceInterface;
class ITbSame1SameStruct2InterfaceInterface;
class ITbSame1SameEnum1InterfaceInterface;
class ITbSame1SameEnum2InterfaceInterface;

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogFTbSame1ModuleFactory, Log, All);

class FTbSame1ModuleFactory
{
public:
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	static TScriptInterface<ITbSame1SameStruct1InterfaceInterface> createITbSame1SameStruct1InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame1SameStruct2InterfaceInterface> createITbSame1SameStruct2InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame1SameEnum1InterfaceInterface> createITbSame1SameEnum1InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame1SameEnum2InterfaceInterface> createITbSame1SameEnum2InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
#else
	static TScriptInterface<ITbSame1SameStruct1InterfaceInterface> createITbSame1SameStruct1InterfaceInterface(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame1SameStruct2InterfaceInterface> createITbSame1SameStruct2InterfaceInterface(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame1SameEnum1InterfaceInterface> createITbSame1SameEnum1InterfaceInterface(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame1SameEnum2InterfaceInterface> createITbSame1SameEnum2InterfaceInterface(FSubsystemCollectionBase& Collection);
#endif
};
