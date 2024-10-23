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

#include "Implementation/TbSame1SameStruct2Interface.h"

UTbSame1SameStruct2Interface::~UTbSame1SameStruct2Interface() = default;
FTbSame1Struct2 UTbSame1SameStruct2Interface::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame1SameStruct2Interface::SetProp1_Implementation(const FTbSame1Struct2& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}
}
FTbSame1Struct2 UTbSame1SameStruct2Interface::GetProp2_Implementation() const
{
	return Prop2;
}

void UTbSame1SameStruct2Interface::SetProp2_Implementation(const FTbSame1Struct2& InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Execute__GetSignals(this)->OnProp2Changed.Broadcast(Prop2);
	}
}

FTbSame1Struct1 UTbSame1SameStruct2Interface::Func1_Implementation(const FTbSame1Struct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTbSame1Struct1();
}

FTbSame1Struct1 UTbSame1SameStruct2Interface::Func2_Implementation(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	(void)Param1;
	(void)Param2;
	// do business logic here
	return FTbSame1Struct1();
}
