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

#include "Testbed2NoPropertyInterfaceLocal.h"
UTestbed2NoPropertyInterfaceLocalService::UTestbed2NoPropertyInterfaceLocalService()
	: ITestbed2NoPropertyInterfaceInterface()
{
}
UTestbed2NoPropertyInterfaceLocalService::~UTestbed2NoPropertyInterfaceLocalService() = default;

void UTestbed2NoPropertyInterfaceLocalService::BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTestbed2NoPropertyInterfaceSig1Delegate& UTestbed2NoPropertyInterfaceLocalService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

FTestbed2NestedStruct1 UTestbed2NoPropertyInterfaceLocalService::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTestbed2NestedStruct1();
}
