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

#include "Testbed2NestedStruct2InterfaceLocal.h"
UTestbed2NestedStruct2InterfaceLocalService::UTestbed2NestedStruct2InterfaceLocalService()
	: ITestbed2NestedStruct2InterfaceInterface()
	, Prop1(FTestbed2NestedStruct1())
	, Prop2(FTestbed2NestedStruct2())
{
}
UTestbed2NestedStruct2InterfaceLocalService::~UTestbed2NestedStruct2InterfaceLocalService()
{
}

void UTestbed2NestedStruct2InterfaceLocalService::BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTestbed2NestedStruct2InterfaceSig1Delegate& UTestbed2NestedStruct2InterfaceLocalService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTestbed2NestedStruct2InterfaceLocalService::BroadcastSig2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
}

FTestbed2NestedStruct2InterfaceSig2Delegate& UTestbed2NestedStruct2InterfaceLocalService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTestbed2NestedStruct2InterfaceLocalService::BroadcastProp1Changed_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceLocalService::GetProp1_Implementation() const
{
	return Prop1;
}

void UTestbed2NestedStruct2InterfaceLocalService::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute_BroadcastProp1Changed(this, Prop1);
	}
}

FTestbed2NestedStruct2InterfaceProp1ChangedDelegate& UTestbed2NestedStruct2InterfaceLocalService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}
void UTestbed2NestedStruct2InterfaceLocalService::BroadcastProp2Changed_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	Prop2Changed.Broadcast(InProp2);
}

FTestbed2NestedStruct2 UTestbed2NestedStruct2InterfaceLocalService::GetProp2_Implementation() const
{
	return Prop2;
}

void UTestbed2NestedStruct2InterfaceLocalService::SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Execute_BroadcastProp2Changed(this, Prop2);
	}
}

FTestbed2NestedStruct2InterfaceProp2ChangedDelegate& UTestbed2NestedStruct2InterfaceLocalService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceLocalService::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTestbed2NestedStruct1();
}
FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceLocalService::Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	(void)Param1;
	(void)Param2;
	// do business logic here
	return FTestbed2NestedStruct1();
}
