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

#include "TbSame2/Implementation/TbSame2SameStruct1Interface.h"

UTbSame2SameStruct1InterfaceImplementation::~UTbSame2SameStruct1InterfaceImplementation() = default;
FTbSame2Struct1 UTbSame2SameStruct1InterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTbSame2SameStruct1InterfaceImplementation::SetProp1(const FTbSame2Struct1& InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame2.SameStruct1Interface.Impl.SetProp1");
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}

FTbSame2Struct1 UTbSame2SameStruct1InterfaceImplementation::Func1(const FTbSame2Struct1& Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame2.SameStruct1Interface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return FTbSame2Struct1();
}

void UTbSame2SameStruct1InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != FTbSame2Struct1())
	{
		Prop1 = FTbSame2Struct1();
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
