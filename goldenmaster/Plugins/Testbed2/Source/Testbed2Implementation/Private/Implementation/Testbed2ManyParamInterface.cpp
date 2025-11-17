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

#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"

UTestbed2ManyParamInterfaceImplementation::~UTestbed2ManyParamInterfaceImplementation() = default;
int32 UTestbed2ManyParamInterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTestbed2ManyParamInterfaceImplementation::SetProp1(int32 InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.SetProp1");
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
int32 UTestbed2ManyParamInterfaceImplementation::GetProp2() const
{
	return Prop2;
}

void UTestbed2ManyParamInterfaceImplementation::SetProp2(int32 InProp2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.SetProp2");
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
}
int32 UTestbed2ManyParamInterfaceImplementation::GetProp3() const
{
	return Prop3;
}

void UTestbed2ManyParamInterfaceImplementation::SetProp3(int32 InProp3)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.SetProp3");
	if (Prop3 != InProp3)
	{
		Prop3 = InProp3;
		_GetPublisher()->BroadcastProp3Changed(Prop3);
	}
}
int32 UTestbed2ManyParamInterfaceImplementation::GetProp4() const
{
	return Prop4;
}

void UTestbed2ManyParamInterfaceImplementation::SetProp4(int32 InProp4)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.SetProp4");
	if (Prop4 != InProp4)
	{
		Prop4 = InProp4;
		_GetPublisher()->BroadcastProp4Changed(Prop4);
	}
}

int32 UTestbed2ManyParamInterfaceImplementation::Func1(int32 Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return 0;
}

int32 UTestbed2ManyParamInterfaceImplementation::Func2(int32 Param1, int32 Param2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.Func2");
	(void)Param1;
	(void)Param2;
	// do business logic here
	return 0;
}

int32 UTestbed2ManyParamInterfaceImplementation::Func3(int32 Param1, int32 Param2, int32 Param3)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.Func3");
	(void)Param1;
	(void)Param2;
	(void)Param3;
	// do business logic here
	return 0;
}

int32 UTestbed2ManyParamInterfaceImplementation::Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.Func4");
	(void)Param1;
	(void)Param2;
	(void)Param3;
	(void)Param4;
	// do business logic here
	return 0;
}

void UTestbed2ManyParamInterfaceImplementation::_ResetProperties()
{
	if (Prop1 != 0)
	{
		Prop1 = 0;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
	if (Prop2 != 0)
	{
		Prop2 = 0;
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
	if (Prop3 != 0)
	{
		Prop3 = 0;
		_GetPublisher()->BroadcastProp3Changed(Prop3);
	}
	if (Prop4 != 0)
	{
		Prop4 = 0;
		_GetPublisher()->BroadcastProp4Changed(Prop4);
	}
}
