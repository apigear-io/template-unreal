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

UTestbed2ManyParamInterface::~UTestbed2ManyParamInterface() = default;
int32 UTestbed2ManyParamInterface::GetProp1() const
{
	return Prop1;
}

void UTestbed2ManyParamInterface::SetProp1(int32 InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetSignals()->BroadcastProp1Changed(Prop1);
	}
}
int32 UTestbed2ManyParamInterface::GetProp2() const
{
	return Prop2;
}

void UTestbed2ManyParamInterface::SetProp2(int32 InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		_GetSignals()->BroadcastProp2Changed(Prop2);
	}
}
int32 UTestbed2ManyParamInterface::GetProp3() const
{
	return Prop3;
}

void UTestbed2ManyParamInterface::SetProp3(int32 InProp3)
{
	if (Prop3 != InProp3)
	{
		Prop3 = InProp3;
		_GetSignals()->BroadcastProp3Changed(Prop3);
	}
}
int32 UTestbed2ManyParamInterface::GetProp4() const
{
	return Prop4;
}

void UTestbed2ManyParamInterface::SetProp4(int32 InProp4)
{
	if (Prop4 != InProp4)
	{
		Prop4 = InProp4;
		_GetSignals()->BroadcastProp4Changed(Prop4);
	}
}

int32 UTestbed2ManyParamInterface::Func1(int32 Param1)
{
	(void)Param1;
	// do business logic here
	return 0;
}

int32 UTestbed2ManyParamInterface::Func2(int32 Param1, int32 Param2)
{
	(void)Param1;
	(void)Param2;
	// do business logic here
	return 0;
}

int32 UTestbed2ManyParamInterface::Func3(int32 Param1, int32 Param2, int32 Param3)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
	// do business logic here
	return 0;
}

int32 UTestbed2ManyParamInterface::Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
	(void)Param4;
	// do business logic here
	return 0;
}
