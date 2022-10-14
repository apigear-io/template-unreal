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
UTbEnumEnumInterfaceLocalService::UTbEnumEnumInterfaceLocalService()
	: ITbEnumEnumInterfaceInterface()
	, Prop0(ETbEnumEnum0::VALUE0)
	, Prop1(ETbEnumEnum1::VALUE1)
	, Prop2(ETbEnumEnum2::VALUE2)
	, Prop3(ETbEnumEnum3::VALUE3)
{
}
UTbEnumEnumInterfaceLocalService::~UTbEnumEnumInterfaceLocalService()
{
}

FTbEnumEnumInterfaceSig0Delegate& UTbEnumEnumInterfaceLocalService::GetSig0SignalDelegate()
{
	return Sig0Signal;
}

FTbEnumEnumInterfaceSig1Delegate& UTbEnumEnumInterfaceLocalService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

FTbEnumEnumInterfaceSig2Delegate& UTbEnumEnumInterfaceLocalService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

FTbEnumEnumInterfaceSig3Delegate& UTbEnumEnumInterfaceLocalService::GetSig3SignalDelegate()
{
	return Sig3Signal;
}

void UTbEnumEnumInterfaceLocalService::GetProp0_Implementation(ETbEnumEnum0& ReturnValue) const
{
	ReturnValue = Prop0;
}

void UTbEnumEnumInterfaceLocalService::SetProp0_Implementation(const ETbEnumEnum0& InProp0)
{
	if (Prop0 != InProp0)
	{
		Prop0 = InProp0;
		Prop0Changed.Broadcast(Prop0);
	}
}

FTbEnumEnumInterfaceProp0ChangedDelegate& UTbEnumEnumInterfaceLocalService::GetProp0ChangedDelegate()
{
	return Prop0Changed;
}
void UTbEnumEnumInterfaceLocalService::GetProp1_Implementation(ETbEnumEnum1& ReturnValue) const
{
	ReturnValue = Prop1;
}

void UTbEnumEnumInterfaceLocalService::SetProp1_Implementation(const ETbEnumEnum1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Prop1Changed.Broadcast(Prop1);
	}
}

FTbEnumEnumInterfaceProp1ChangedDelegate& UTbEnumEnumInterfaceLocalService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}
void UTbEnumEnumInterfaceLocalService::GetProp2_Implementation(ETbEnumEnum2& ReturnValue) const
{
	ReturnValue = Prop2;
}

void UTbEnumEnumInterfaceLocalService::SetProp2_Implementation(const ETbEnumEnum2& InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Prop2Changed.Broadcast(Prop2);
	}
}

FTbEnumEnumInterfaceProp2ChangedDelegate& UTbEnumEnumInterfaceLocalService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}
void UTbEnumEnumInterfaceLocalService::GetProp3_Implementation(ETbEnumEnum3& ReturnValue) const
{
	ReturnValue = Prop3;
}

void UTbEnumEnumInterfaceLocalService::SetProp3_Implementation(const ETbEnumEnum3& InProp3)
{
	if (Prop3 != InProp3)
	{
		Prop3 = InProp3;
		Prop3Changed.Broadcast(Prop3);
	}
}

FTbEnumEnumInterfaceProp3ChangedDelegate& UTbEnumEnumInterfaceLocalService::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}

void UTbEnumEnumInterfaceLocalService::Func0_Implementation(ETbEnumEnum0& Result, const ETbEnumEnum0& Param0)
{
	(void)Param0;
	// do business logic here
	Result = ETbEnumEnum0::VALUE0;
}
void UTbEnumEnumInterfaceLocalService::Func1_Implementation(ETbEnumEnum1& Result, const ETbEnumEnum1& Param1)
{
	(void)Param1;
	// do business logic here
	Result = ETbEnumEnum1::VALUE1;
}
void UTbEnumEnumInterfaceLocalService::Func2_Implementation(ETbEnumEnum2& Result, const ETbEnumEnum2& Param2)
{
	(void)Param2;
	// do business logic here
	Result = ETbEnumEnum2::VALUE2;
}
void UTbEnumEnumInterfaceLocalService::Func3_Implementation(ETbEnumEnum3& Result, const ETbEnumEnum3& Param3)
{
	(void)Param3;
	// do business logic here
	Result = ETbEnumEnum3::VALUE3;
}
