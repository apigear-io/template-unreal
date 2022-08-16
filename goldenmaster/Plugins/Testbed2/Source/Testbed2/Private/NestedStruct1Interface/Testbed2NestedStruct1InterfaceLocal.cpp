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

#include "Testbed2NestedStruct1InterfaceLocal.h"

namespace Testbed2
{
namespace NestedStruct1Interface
{
namespace Private
{
LocalService::LocalService()
	: ITestbed2NestedStruct1InterfaceInterface()
	, Prop1(FTestbed2NestedStruct1())
{
}
LocalService::~LocalService()
{
}

FTestbed2NestedStruct1InterfaceSig1Delegate& LocalService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

FTestbed2NestedStruct1 LocalService::GetProp1() const
{
	return Prop1;
}

void LocalService::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Prop1Changed.Broadcast(Prop1);
	}
}

FTestbed2NestedStruct1InterfaceProp1ChangedDelegate& LocalService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

FTestbed2NestedStruct1 LocalService::Func1(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTestbed2NestedStruct1();
}

} // namespace Private
} // namespace NestedStruct1Interface
} // namespace Testbed2
