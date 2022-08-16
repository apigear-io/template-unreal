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

#include "apig/TbSame1_apig.h"

namespace TbSame1
{
namespace SameEnum2Interface
{
namespace Private
{

class WAMPService : public ITbSame1SameEnum2InterfaceInterface
{
public:
	explicit WAMPService();
	virtual ~WAMPService();

	// signals
	FTbSame1SameEnum2InterfaceSig1Delegate Sig1Signal;
	FTbSame1SameEnum2InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTbSame1SameEnum2InterfaceSig2Delegate Sig2Signal;
	FTbSame1SameEnum2InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	FTbSame1SameEnum2InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame1SameEnum2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	FTbSame1SameEnum2InterfaceProp2ChangedDelegate Prop2Changed;
	FTbSame1SameEnum2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	// properties
	ETbSame1Enum1 GetProp1() const override;
	void SetProp1(const ETbSame1Enum1& Prop1) override;

	ETbSame1Enum2 GetProp2() const override;
	void SetProp2(const ETbSame1Enum2& Prop2) override;

	// operations
	ETbSame1Enum1 Func1(const ETbSame1Enum1& Param1) override;

	ETbSame1Enum1 Func2(const ETbSame1Enum1& Param1, const ETbSame1Enum2& Param2) override;

private:
	// properties - local copy
	ETbSame1Enum1 Prop1;
	ETbSame1Enum2 Prop2;
};

} // namespace Private
} // namespace SameEnum2Interface
} // namespace TbSame1
