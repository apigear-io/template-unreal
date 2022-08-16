
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
#pragma once

#include "apig/TbSame2_apig.h"

namespace TbSame2
{
namespace SameEnum2Interface
{
namespace Private
{

class LocalService : public ITbSame2SameEnum2InterfaceInterface
{
public:
	explicit LocalService();
	virtual ~LocalService();

	// signals
	FTbSame2SameEnum2InterfaceSig1Delegate Sig1Signal;
	FTbSame2SameEnum2InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTbSame2SameEnum2InterfaceSig2Delegate Sig2Signal;
	FTbSame2SameEnum2InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	FTbSame2SameEnum2InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame2SameEnum2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	FTbSame2SameEnum2InterfaceProp2ChangedDelegate Prop2Changed;
	FTbSame2SameEnum2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	// properties
	ETbSame2Enum1 GetProp1() const override;
	void SetProp1(const ETbSame2Enum1& Prop1) override;

	ETbSame2Enum2 GetProp2() const override;
	void SetProp2(const ETbSame2Enum2& Prop2) override;

	// operations
	ETbSame2Enum1 Func1(const ETbSame2Enum1& Param1) override;

	ETbSame2Enum1 Func2(const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2) override;

private:
	// properties - local copy - use setter functions to emit changed signals
	ETbSame2Enum1 Prop1;
	ETbSame2Enum2 Prop2;
};

} // namespace Private
} // namespace SameEnum2Interface
} // namespace TbSame2
