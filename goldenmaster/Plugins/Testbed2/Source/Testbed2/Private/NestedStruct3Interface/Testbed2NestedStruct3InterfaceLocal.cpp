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

#include "Testbed2NestedStruct3InterfaceLocal.h"
UTestbed2NestedStruct3InterfaceLocalService::UTestbed2NestedStruct3InterfaceLocalService()
	: ITestbed2NestedStruct3InterfaceInterface()
	, Prop1(FTestbed2NestedStruct1())
	, Prop2(FTestbed2NestedStruct2())
	, Prop3(FTestbed2NestedStruct3())
{
}
UTestbed2NestedStruct3InterfaceLocalService::~UTestbed2NestedStruct3InterfaceLocalService()
{
}

void UTestbed2NestedStruct3InterfaceLocalService::BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTestbed2NestedStruct3InterfaceSig1Delegate& UTestbed2NestedStruct3InterfaceLocalService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTestbed2NestedStruct3InterfaceLocalService::BroadcastSig2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
}

FTestbed2NestedStruct3InterfaceSig2Delegate& UTestbed2NestedStruct3InterfaceLocalService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTestbed2NestedStruct3InterfaceLocalService::BroadcastSig3_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	Sig3Signal.Broadcast(Param1, Param2, Param3);
}

FTestbed2NestedStruct3InterfaceSig3Delegate& UTestbed2NestedStruct3InterfaceLocalService::GetSig3SignalDelegate()
{
	return Sig3Signal;
}

void UTestbed2NestedStruct3InterfaceLocalService::BroadcastProp1Changed_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLocalService::GetProp1_Implementation() const
{
	return Prop1;
}

void UTestbed2NestedStruct3InterfaceLocalService::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute_BroadcastProp1Changed(this, Prop1);
	}
}

FTestbed2NestedStruct3InterfaceProp1ChangedDelegate& UTestbed2NestedStruct3InterfaceLocalService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}
void UTestbed2NestedStruct3InterfaceLocalService::BroadcastProp2Changed_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	Prop2Changed.Broadcast(InProp2);
}

FTestbed2NestedStruct2 UTestbed2NestedStruct3InterfaceLocalService::GetProp2_Implementation() const
{
	return Prop2;
}

void UTestbed2NestedStruct3InterfaceLocalService::SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Execute_BroadcastProp2Changed(this, Prop2);
	}
}

FTestbed2NestedStruct3InterfaceProp2ChangedDelegate& UTestbed2NestedStruct3InterfaceLocalService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}
void UTestbed2NestedStruct3InterfaceLocalService::BroadcastProp3Changed_Implementation(const FTestbed2NestedStruct3& InProp3)
{
	Prop3Changed.Broadcast(InProp3);
}

FTestbed2NestedStruct3 UTestbed2NestedStruct3InterfaceLocalService::GetProp3_Implementation() const
{
	return Prop3;
}

void UTestbed2NestedStruct3InterfaceLocalService::SetProp3_Implementation(const FTestbed2NestedStruct3& InProp3)
{
	if (Prop3 != InProp3)
	{
		Prop3 = InProp3;
		Execute_BroadcastProp3Changed(this, Prop3);
	}
}

FTestbed2NestedStruct3InterfaceProp3ChangedDelegate& UTestbed2NestedStruct3InterfaceLocalService::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLocalService::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTestbed2NestedStruct1();
}
FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLocalService::Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	(void)Param1;
	(void)Param2;
	// do business logic here
	return FTestbed2NestedStruct1();
}
FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLocalService::Func3_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
	// do business logic here
	return FTestbed2NestedStruct1();
}
