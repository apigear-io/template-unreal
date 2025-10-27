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

#include "Testbed2/Implementation/Testbed2NestedStruct1Interface.h"

UTestbed2NestedStruct1InterfaceImplementation::~UTestbed2NestedStruct1InterfaceImplementation() = default;
FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTestbed2NestedStruct1InterfaceImplementation::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}

void UTestbed2NestedStruct1InterfaceImplementation::FuncNoReturnValue(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
	// do business logic here
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceImplementation::FuncNoParams()
{
	// do business logic here
	return FTestbed2NestedStruct1();
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceImplementation::Func1(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTestbed2NestedStruct1();
}

void UTestbed2NestedStruct1InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != FTestbed2NestedStruct1())
	{
		Prop1 = FTestbed2NestedStruct1();
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
