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

#include "TbEnumEnumInterfaceLocal.h"

namespace TbEnum
{
namespace EnumInterface
{
namespace Private
{
LocalService::LocalService()
	: ITbEnumEnumInterfaceInterface()
	, Prop0(ETbEnumEnum0::VALUE0)
	, Prop1(ETbEnumEnum1::VALUE1)
	, Prop2(ETbEnumEnum2::VALUE2)
	, Prop3(ETbEnumEnum3::VALUE3)
{
}
LocalService::~LocalService()
{
}

FTbEnumEnumInterfaceSig0Delegate& LocalService::GetSig0SignalDelegate()
{
	return Sig0Signal;
}

FTbEnumEnumInterfaceSig1Delegate& LocalService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

FTbEnumEnumInterfaceSig2Delegate& LocalService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

FTbEnumEnumInterfaceSig3Delegate& LocalService::GetSig3SignalDelegate()
{
	return Sig3Signal;
}

ETbEnumEnum0 LocalService::GetProp0_Implementation() const
{
	return Prop0;
}

void LocalService::SetProp0_Implementation(const ETbEnumEnum0& InProp0)
{
	if (Prop0 != InProp0)
	{
		Prop0 = InProp0;
		Prop0Changed.Broadcast(Prop0);
	}
}

FTbEnumEnumInterfaceProp0ChangedDelegate& LocalService::GetProp0ChangedDelegate()
{
	return Prop0Changed;
}
ETbEnumEnum1 LocalService::GetProp1_Implementation() const
{
	return Prop1;
}

void LocalService::SetProp1_Implementation(const ETbEnumEnum1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Prop1Changed.Broadcast(Prop1);
	}
}

FTbEnumEnumInterfaceProp1ChangedDelegate& LocalService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}
ETbEnumEnum2 LocalService::GetProp2_Implementation() const
{
	return Prop2;
}

void LocalService::SetProp2_Implementation(const ETbEnumEnum2& InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Prop2Changed.Broadcast(Prop2);
	}
}

FTbEnumEnumInterfaceProp2ChangedDelegate& LocalService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}
ETbEnumEnum3 LocalService::GetProp3_Implementation() const
{
	return Prop3;
}

void LocalService::SetProp3_Implementation(const ETbEnumEnum3& InProp3)
{
	if (Prop3 != InProp3)
	{
		Prop3 = InProp3;
		Prop3Changed.Broadcast(Prop3);
	}
}

FTbEnumEnumInterfaceProp3ChangedDelegate& LocalService::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}

ETbEnumEnum0 LocalService::Func0_Implementation(const ETbEnumEnum0& Param0)
{
	(void)Param0;
	// do business logic here
	return ETbEnumEnum0::VALUE0;
}
ETbEnumEnum1 LocalService::Func1_Implementation(const ETbEnumEnum1& Param1)
{
	(void)Param1;
	// do business logic here
	return ETbEnumEnum1::VALUE1;
}
ETbEnumEnum2 LocalService::Func2_Implementation(const ETbEnumEnum2& Param2)
{
	(void)Param2;
	// do business logic here
	return ETbEnumEnum2::VALUE2;
}
ETbEnumEnum3 LocalService::Func3_Implementation(const ETbEnumEnum3& Param3)
{
	(void)Param3;
	// do business logic here
	return ETbEnumEnum3::VALUE3;
}

} // namespace Private
} // namespace EnumInterface
} // namespace TbEnum
