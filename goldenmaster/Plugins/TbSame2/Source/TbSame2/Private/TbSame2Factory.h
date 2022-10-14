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
#include "Templates/SharedPointer.h"
#include "UObject/ScriptInterface.h"
class ITbSame2SameStruct1InterfaceInterface;
class ITbSame2SameStruct2InterfaceInterface;
class ITbSame2SameEnum1InterfaceInterface;
class ITbSame2SameEnum2InterfaceInterface;

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogFTbSame2ModuleFactory, Log, All);

class FTbSame2ModuleFactory
{
public:
	static TScriptInterface<ITbSame2SameStruct1InterfaceInterface> createITbSame2SameStruct1InterfaceInterface();
	static TScriptInterface<ITbSame2SameStruct2InterfaceInterface> createITbSame2SameStruct2InterfaceInterface();
	static TScriptInterface<ITbSame2SameEnum1InterfaceInterface> createITbSame2SameEnum1InterfaceInterface();
	static TScriptInterface<ITbSame2SameEnum2InterfaceInterface> createITbSame2SameEnum2InterfaceInterface();
};
