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

#include "Testbed2ManyParamInterfaceLocal.h"
UTestbed2ManyParamInterfaceLocalService::UTestbed2ManyParamInterfaceLocalService()
	: ITestbed2ManyParamInterfaceInterface()
	, Prop1(0)
	, Prop2(0)
	, Prop3(0)
	, Prop4(0)
{
}
UTestbed2ManyParamInterfaceLocalService::~UTestbed2ManyParamInterfaceLocalService()
{
}

void UTestbed2ManyParamInterfaceLocalService::BroadcastSig1_Implementation(int32 Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTestbed2ManyParamInterfaceSig1Delegate& UTestbed2ManyParamInterfaceLocalService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTestbed2ManyParamInterfaceLocalService::BroadcastSig2_Implementation(int32 Param1, int32 Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
}

FTestbed2ManyParamInterfaceSig2Delegate& UTestbed2ManyParamInterfaceLocalService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTestbed2ManyParamInterfaceLocalService::BroadcastSig3_Implementation(int32 Param1, int32 Param2, int32 Param3)
{
	Sig3Signal.Broadcast(Param1, Param2, Param3);
}

FTestbed2ManyParamInterfaceSig3Delegate& UTestbed2ManyParamInterfaceLocalService::GetSig3SignalDelegate()
{
	return Sig3Signal;
}

void UTestbed2ManyParamInterfaceLocalService::BroadcastSig4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Sig4Signal.Broadcast(Param1, Param2, Param3, Param4);
}

FTestbed2ManyParamInterfaceSig4Delegate& UTestbed2ManyParamInterfaceLocalService::GetSig4SignalDelegate()
{
	return Sig4Signal;
}

void UTestbed2ManyParamInterfaceLocalService::BroadcastProp1Changed_Implementation(int32 InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

int32 UTestbed2ManyParamInterfaceLocalService::GetProp1_Implementation() const
{
	return Prop1;
}

void UTestbed2ManyParamInterfaceLocalService::SetProp1_Implementation(int32 InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute_BroadcastProp1Changed(this, Prop1);
	}
}

FTestbed2ManyParamInterfaceProp1ChangedDelegate& UTestbed2ManyParamInterfaceLocalService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}
void UTestbed2ManyParamInterfaceLocalService::BroadcastProp2Changed_Implementation(int32 InProp2)
{
	Prop2Changed.Broadcast(InProp2);
}

int32 UTestbed2ManyParamInterfaceLocalService::GetProp2_Implementation() const
{
	return Prop2;
}

void UTestbed2ManyParamInterfaceLocalService::SetProp2_Implementation(int32 InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Execute_BroadcastProp2Changed(this, Prop2);
	}
}

FTestbed2ManyParamInterfaceProp2ChangedDelegate& UTestbed2ManyParamInterfaceLocalService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}
void UTestbed2ManyParamInterfaceLocalService::BroadcastProp3Changed_Implementation(int32 InProp3)
{
	Prop3Changed.Broadcast(InProp3);
}

int32 UTestbed2ManyParamInterfaceLocalService::GetProp3_Implementation() const
{
	return Prop3;
}

void UTestbed2ManyParamInterfaceLocalService::SetProp3_Implementation(int32 InProp3)
{
	if (Prop3 != InProp3)
	{
		Prop3 = InProp3;
		Execute_BroadcastProp3Changed(this, Prop3);
	}
}

FTestbed2ManyParamInterfaceProp3ChangedDelegate& UTestbed2ManyParamInterfaceLocalService::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}
void UTestbed2ManyParamInterfaceLocalService::BroadcastProp4Changed_Implementation(int32 InProp4)
{
	Prop4Changed.Broadcast(InProp4);
}

int32 UTestbed2ManyParamInterfaceLocalService::GetProp4_Implementation() const
{
	return Prop4;
}

void UTestbed2ManyParamInterfaceLocalService::SetProp4_Implementation(int32 InProp4)
{
	if (Prop4 != InProp4)
	{
		Prop4 = InProp4;
		Execute_BroadcastProp4Changed(this, Prop4);
	}
}

FTestbed2ManyParamInterfaceProp4ChangedDelegate& UTestbed2ManyParamInterfaceLocalService::GetProp4ChangedDelegate()
{
	return Prop4Changed;
}

int32 UTestbed2ManyParamInterfaceLocalService::Func1_Implementation(int32 Param1)
{
	(void)Param1;
	// do business logic here
	return 0;
}
int32 UTestbed2ManyParamInterfaceLocalService::Func2_Implementation(int32 Param1, int32 Param2)
{
	(void)Param1;
	(void)Param2;
	// do business logic here
	return 0;
}
int32 UTestbed2ManyParamInterfaceLocalService::Func3_Implementation(int32 Param1, int32 Param2, int32 Param3)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
	// do business logic here
	return 0;
}
int32 UTestbed2ManyParamInterfaceLocalService::Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
	(void)Param4;
	// do business logic here
	return 0;
}
