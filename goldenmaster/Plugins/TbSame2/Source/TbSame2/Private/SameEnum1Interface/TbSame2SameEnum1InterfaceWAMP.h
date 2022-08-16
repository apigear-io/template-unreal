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
namespace SameEnum1Interface
{
namespace Private
{

class WAMPService : public ITbSame2SameEnum1InterfaceInterface
{
public:
	explicit WAMPService();
	virtual ~WAMPService();

	// signals
	FTbSame2SameEnum1InterfaceSig1Delegate Sig1Signal;
	FTbSame2SameEnum1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTbSame2SameEnum1InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame2SameEnum1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// properties
	ETbSame2Enum1 GetProp1() const override;
	void SetProp1(const ETbSame2Enum1& Prop1) override;

	// operations
	ETbSame2Enum1 Func1(const ETbSame2Enum1& Param1) override;

private:
	// properties - local copy
	ETbSame2Enum1 Prop1;
};

} // namespace Private
} // namespace SameEnum1Interface
} // namespace TbSame2
