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

#include "Implementation/TbEnumEnumInterface.h"

UTbEnumEnumInterface::~UTbEnumEnumInterface() = default;

void UTbEnumEnumInterface::BroadcastSig0_Implementation(const ETbEnumEnum0& Param0)
{
	Sig0Signal.Broadcast(Param0);
}

FTbEnumEnumInterfaceSig0Delegate& UTbEnumEnumInterface::GetSig0SignalDelegate()
{
	return Sig0Signal;
}

void UTbEnumEnumInterface::BroadcastSig1_Implementation(const ETbEnumEnum1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTbEnumEnumInterfaceSig1Delegate& UTbEnumEnumInterface::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbEnumEnumInterface::BroadcastSig2_Implementation(const ETbEnumEnum2& Param2)
{
	Sig2Signal.Broadcast(Param2);
}

FTbEnumEnumInterfaceSig2Delegate& UTbEnumEnumInterface::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTbEnumEnumInterface::BroadcastSig3_Implementation(const ETbEnumEnum3& Param3)
{
	Sig3Signal.Broadcast(Param3);
}

FTbEnumEnumInterfaceSig3Delegate& UTbEnumEnumInterface::GetSig3SignalDelegate()
{
	return Sig3Signal;
}

void UTbEnumEnumInterface::BroadcastProp0Changed_Implementation(const ETbEnumEnum0& InProp0)
{
	Prop0Changed.Broadcast(InProp0);
}

ETbEnumEnum0 UTbEnumEnumInterface::GetProp0_Implementation() const
{
	return Prop0;
}

void UTbEnumEnumInterface::SetProp0_Implementation(const ETbEnumEnum0& InProp0)
{
	if (Prop0 != InProp0)
	{
		Prop0 = InProp0;
		Execute_BroadcastProp0Changed(this, Prop0);
	}
}

FTbEnumEnumInterfaceProp0ChangedDelegate& UTbEnumEnumInterface::GetProp0ChangedDelegate()
{
	return Prop0Changed;
}

void UTbEnumEnumInterface::BroadcastProp1Changed_Implementation(const ETbEnumEnum1& InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

ETbEnumEnum1 UTbEnumEnumInterface::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbEnumEnumInterface::SetProp1_Implementation(const ETbEnumEnum1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute_BroadcastProp1Changed(this, Prop1);
	}
}

FTbEnumEnumInterfaceProp1ChangedDelegate& UTbEnumEnumInterface::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbEnumEnumInterface::BroadcastProp2Changed_Implementation(const ETbEnumEnum2& InProp2)
{
	Prop2Changed.Broadcast(InProp2);
}

ETbEnumEnum2 UTbEnumEnumInterface::GetProp2_Implementation() const
{
	return Prop2;
}

void UTbEnumEnumInterface::SetProp2_Implementation(const ETbEnumEnum2& InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Execute_BroadcastProp2Changed(this, Prop2);
	}
}

FTbEnumEnumInterfaceProp2ChangedDelegate& UTbEnumEnumInterface::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTbEnumEnumInterface::BroadcastProp3Changed_Implementation(const ETbEnumEnum3& InProp3)
{
	Prop3Changed.Broadcast(InProp3);
}

ETbEnumEnum3 UTbEnumEnumInterface::GetProp3_Implementation() const
{
	return Prop3;
}

void UTbEnumEnumInterface::SetProp3_Implementation(const ETbEnumEnum3& InProp3)
{
	if (Prop3 != InProp3)
	{
		Prop3 = InProp3;
		Execute_BroadcastProp3Changed(this, Prop3);
	}
}

FTbEnumEnumInterfaceProp3ChangedDelegate& UTbEnumEnumInterface::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}

ETbEnumEnum0 UTbEnumEnumInterface::Func0_Implementation(const ETbEnumEnum0& Param0)
{
	(void)Param0;
	// do business logic here
	return ETbEnumEnum0::VALUE0;
}

ETbEnumEnum1 UTbEnumEnumInterface::Func1_Implementation(const ETbEnumEnum1& Param1)
{
	(void)Param1;
	// do business logic here
	return ETbEnumEnum1::VALUE1;
}

ETbEnumEnum2 UTbEnumEnumInterface::Func2_Implementation(const ETbEnumEnum2& Param2)
{
	(void)Param2;
	// do business logic here
	return ETbEnumEnum2::VALUE2;
}

ETbEnumEnum3 UTbEnumEnumInterface::Func3_Implementation(const ETbEnumEnum3& Param3)
{
	(void)Param3;
	// do business logic here
	return ETbEnumEnum3::VALUE3;
}
