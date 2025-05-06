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

#include "TbSame1/Implementation/TbSame1SameStruct1Interface.h"

UTbSame1SameStruct1Interface::~UTbSame1SameStruct1Interface() = default;
FTbSame1Struct1 UTbSame1SameStruct1Interface::GetProp1() const
{
	return Prop1;
}

void UTbSame1SameStruct1Interface::SetProp1(const FTbSame1Struct1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetSignals()->BroadcastProp1Changed(Prop1);
	}
}

FTbSame1Struct1 UTbSame1SameStruct1Interface::Func1(const FTbSame1Struct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTbSame1Struct1();
}

void UTbSame1SameStruct1Interface::_ResetProperties()
{
	if (Prop1 != FTbSame1Struct1())
	{
		Prop1 = FTbSame1Struct1();
		_GetSignals()->BroadcastProp1Changed(Prop1);
	}
}
