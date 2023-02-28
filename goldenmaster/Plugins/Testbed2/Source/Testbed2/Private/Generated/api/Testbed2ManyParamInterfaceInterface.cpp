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
#include "Testbed2ManyParamInterfaceInterface.h"

UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface")
FTestbed2ManyParamInterfaceSig1Delegate& UAbstractTestbed2ManyParamInterface::GetSig1SignalDelegate()
{
	return Sig1Signal;
};

UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface")
FTestbed2ManyParamInterfaceSig2Delegate& UAbstractTestbed2ManyParamInterface::GetSig2SignalDelegate()
{
	return Sig2Signal;
};

UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface")
FTestbed2ManyParamInterfaceSig3Delegate& UAbstractTestbed2ManyParamInterface::GetSig3SignalDelegate()
{
	return Sig3Signal;
};

UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface")
FTestbed2ManyParamInterfaceSig4Delegate& UAbstractTestbed2ManyParamInterface::GetSig4SignalDelegate()
{
	return Sig4Signal;
};

FTestbed2ManyParamInterfaceProp1ChangedDelegate& UAbstractTestbed2ManyParamInterface::GetProp1ChangedDelegate()
{
	return Prop1Changed;
};

FTestbed2ManyParamInterfaceProp2ChangedDelegate& UAbstractTestbed2ManyParamInterface::GetProp2ChangedDelegate()
{
	return Prop2Changed;
};

FTestbed2ManyParamInterfaceProp3ChangedDelegate& UAbstractTestbed2ManyParamInterface::GetProp3ChangedDelegate()
{
	return Prop3Changed;
};

FTestbed2ManyParamInterfaceProp4ChangedDelegate& UAbstractTestbed2ManyParamInterface::GetProp4ChangedDelegate()
{
	return Prop4Changed;
};
void UAbstractTestbed2ManyParamInterface::BroadcastSig1_Implementation(int32 Param1)
{
	Sig1Signal.Broadcast(Param1);
};

void UAbstractTestbed2ManyParamInterface::BroadcastSig2_Implementation(int32 Param1, int32 Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
};

void UAbstractTestbed2ManyParamInterface::BroadcastSig3_Implementation(int32 Param1, int32 Param2, int32 Param3)
{
	Sig3Signal.Broadcast(Param1, Param2, Param3);
};

void UAbstractTestbed2ManyParamInterface::BroadcastSig4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Sig4Signal.Broadcast(Param1, Param2, Param3, Param4);
};

void UAbstractTestbed2ManyParamInterface::BroadcastProp1Changed_Implementation(int32 InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

void UAbstractTestbed2ManyParamInterface::BroadcastProp2Changed_Implementation(int32 InProp2)
{
	Prop2Changed.Broadcast(InProp2);
}

void UAbstractTestbed2ManyParamInterface::BroadcastProp3Changed_Implementation(int32 InProp3)
{
	Prop3Changed.Broadcast(InProp3);
}

void UAbstractTestbed2ManyParamInterface::BroadcastProp4Changed_Implementation(int32 InProp4)
{
	Prop4Changed.Broadcast(InProp4);
}
int32 UAbstractTestbed2ManyParamInterface::GetProp1_Private() const
{
	return Execute_GetProp1(this);
};

void UAbstractTestbed2ManyParamInterface::SetProp1_Private(int32 InProp1)
{
	Execute_SetProp1(this, InProp1);
};

int32 UAbstractTestbed2ManyParamInterface::GetProp2_Private() const
{
	return Execute_GetProp2(this);
};

void UAbstractTestbed2ManyParamInterface::SetProp2_Private(int32 InProp2)
{
	Execute_SetProp2(this, InProp2);
};

int32 UAbstractTestbed2ManyParamInterface::GetProp3_Private() const
{
	return Execute_GetProp3(this);
};

void UAbstractTestbed2ManyParamInterface::SetProp3_Private(int32 InProp3)
{
	Execute_SetProp3(this, InProp3);
};

int32 UAbstractTestbed2ManyParamInterface::GetProp4_Private() const
{
	return Execute_GetProp4(this);
};

void UAbstractTestbed2ManyParamInterface::SetProp4_Private(int32 InProp4)
{
	Execute_SetProp4(this, InProp4);
};
