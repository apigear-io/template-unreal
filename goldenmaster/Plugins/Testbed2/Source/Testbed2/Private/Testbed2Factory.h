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
class ITestbed2ManyParamInterfaceInterface;
class ITestbed2NestedStruct1InterfaceInterface;
class ITestbed2NestedStruct2InterfaceInterface;
class ITestbed2NestedStruct3InterfaceInterface;

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogFTestbed2ModuleFactory, Log, All);

class FTestbed2ModuleFactory
{
public:
	static TSharedPtr<ITestbed2ManyParamInterfaceInterface, ESPMode::ThreadSafe> createITestbed2ManyParamInterfaceInterface();
	static TSharedPtr<ITestbed2NestedStruct1InterfaceInterface, ESPMode::ThreadSafe> createITestbed2NestedStruct1InterfaceInterface();
	static TSharedPtr<ITestbed2NestedStruct2InterfaceInterface, ESPMode::ThreadSafe> createITestbed2NestedStruct2InterfaceInterface();
	static TSharedPtr<ITestbed2NestedStruct3InterfaceInterface, ESPMode::ThreadSafe> createITestbed2NestedStruct3InterfaceInterface();
};
