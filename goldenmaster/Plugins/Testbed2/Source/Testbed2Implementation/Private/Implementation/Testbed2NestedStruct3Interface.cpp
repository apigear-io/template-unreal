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

#include "Testbed2/Implementation/Testbed2NestedStruct3Interface.h"

UTestbed2NestedStruct3Interface::~UTestbed2NestedStruct3Interface() = default;
FTestbed2NestedStruct1 UTestbed2NestedStruct3Interface::GetProp1() const
{
	return Prop1;
}

void UTestbed2NestedStruct3Interface::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetSignals()->OnProp1Changed.Broadcast(Prop1);
	}
}
FTestbed2NestedStruct2 UTestbed2NestedStruct3Interface::GetProp2() const
{
	return Prop2;
}

void UTestbed2NestedStruct3Interface::SetProp2(const FTestbed2NestedStruct2& InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		_GetSignals()->OnProp2Changed.Broadcast(Prop2);
	}
}
FTestbed2NestedStruct3 UTestbed2NestedStruct3Interface::GetProp3() const
{
	return Prop3;
}

void UTestbed2NestedStruct3Interface::SetProp3(const FTestbed2NestedStruct3& InProp3)
{
	if (Prop3 != InProp3)
	{
		Prop3 = InProp3;
		_GetSignals()->OnProp3Changed.Broadcast(Prop3);
	}
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3Interface::Func1(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTestbed2NestedStruct1();
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3Interface::Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	(void)Param1;
	(void)Param2;
	// do business logic here
	return FTestbed2NestedStruct1();
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3Interface::Func3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
	// do business logic here
	return FTestbed2NestedStruct1();
}
