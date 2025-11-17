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

#include "TbSame1/Implementation/TbSame1SameStruct2Interface.h"

UTbSame1SameStruct2InterfaceImplementation::~UTbSame1SameStruct2InterfaceImplementation() = default;
FTbSame1Struct2 UTbSame1SameStruct2InterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTbSame1SameStruct2InterfaceImplementation::SetProp1(const FTbSame1Struct2& InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameStruct2Interface.Impl.SetProp1");
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
FTbSame1Struct2 UTbSame1SameStruct2InterfaceImplementation::GetProp2() const
{
	return Prop2;
}

void UTbSame1SameStruct2InterfaceImplementation::SetProp2(const FTbSame1Struct2& InProp2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameStruct2Interface.Impl.SetProp2");
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
}

FTbSame1Struct1 UTbSame1SameStruct2InterfaceImplementation::Func1(const FTbSame1Struct1& Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameStruct2Interface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return FTbSame1Struct1();
}

FTbSame1Struct1 UTbSame1SameStruct2InterfaceImplementation::Func2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameStruct2Interface.Impl.Func2");
	(void)Param1;
	(void)Param2;
	// do business logic here
	return FTbSame1Struct1();
}

void UTbSame1SameStruct2InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != FTbSame1Struct2())
	{
		Prop1 = FTbSame1Struct2();
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
	if (Prop2 != FTbSame1Struct2())
	{
		Prop2 = FTbSame1Struct2();
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
}
