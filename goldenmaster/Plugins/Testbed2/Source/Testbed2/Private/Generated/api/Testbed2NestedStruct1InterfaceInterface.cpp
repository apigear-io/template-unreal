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
#include "Testbed2NestedStruct1InterfaceInterface.h"

UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct1Interface")
FTestbed2NestedStruct1InterfaceSig1Delegate& UAbstractTestbed2NestedStruct1Interface::GetSig1SignalDelegate()
{
	return Sig1Signal;
};

FTestbed2NestedStruct1InterfaceProp1ChangedDelegate& UAbstractTestbed2NestedStruct1Interface::GetProp1ChangedDelegate()
{
	return Prop1Changed;
};
void UAbstractTestbed2NestedStruct1Interface::BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
};

void UAbstractTestbed2NestedStruct1Interface::BroadcastProp1Changed_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}
FTestbed2NestedStruct1 UAbstractTestbed2NestedStruct1Interface::GetProp1_Private() const
{
	return Execute_GetProp1(this);
};

void UAbstractTestbed2NestedStruct1Interface::SetProp1_Private(const FTestbed2NestedStruct1& InProp1)
{
	Execute_SetProp1(this, InProp1);
};

void UAbstractTestbed2NestedStruct1Interface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed2NestedStruct1Interface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	Super::Deinitialize();
}

bool UAbstractTestbed2NestedStruct1Interface::IsInitialized() const
{
	return bInitialized;
}
