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

#include "Testbed2NestedStruct1InterfaceLocal.h"

UTestbed2NestedStruct1InterfaceLocalService::~UTestbed2NestedStruct1InterfaceLocalService() = default;

void UTestbed2NestedStruct1InterfaceLocalService::BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTestbed2NestedStruct1InterfaceSig1Delegate& UTestbed2NestedStruct1InterfaceLocalService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTestbed2NestedStruct1InterfaceLocalService::BroadcastProp1Changed_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceLocalService::GetProp1_Implementation() const
{
	return Prop1;
}

void UTestbed2NestedStruct1InterfaceLocalService::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute_BroadcastProp1Changed(this, Prop1);
	}
}

FTestbed2NestedStruct1InterfaceProp1ChangedDelegate& UTestbed2NestedStruct1InterfaceLocalService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceLocalService::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTestbed2NestedStruct1();
}
