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

#include "Implementation/TbNamesNamEs.h"

UTbNamesNamEs::~UTbNamesNamEs() = default;
bool UTbNamesNamEs::GetSwitch_Implementation() const
{
	return bSwitch;
}

void UTbNamesNamEs::SetSwitch_Implementation(bool bInSwitch)
{
	if (bSwitch != bInSwitch)
	{
		bSwitch = bInSwitch;
		Execute__GetSignals(this)->OnSwitchChanged.Broadcast(bSwitch);
	}
}
int32 UTbNamesNamEs::GetSomeProperty_Implementation() const
{
	return SomeProperty;
}

void UTbNamesNamEs::SetSomeProperty_Implementation(int32 InSomeProperty)
{
	if (SomeProperty != InSomeProperty)
	{
		SomeProperty = InSomeProperty;
		Execute__GetSignals(this)->OnSomePropertyChanged.Broadcast(SomeProperty);
	}
}
int32 UTbNamesNamEs::GetSomePoperty2_Implementation() const
{
	return SomePoperty2;
}

void UTbNamesNamEs::SetSomePoperty2_Implementation(int32 InSomePoperty2)
{
	if (SomePoperty2 != InSomePoperty2)
	{
		SomePoperty2 = InSomePoperty2;
		Execute__GetSignals(this)->OnSomePoperty2Changed.Broadcast(SomePoperty2);
	}
}
ETbNamesEnum_With_Under_scores UTbNamesNamEs::GetEnumProperty_Implementation() const
{
	return EnumProperty;
}

void UTbNamesNamEs::SetEnumProperty_Implementation(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	if (EnumProperty != InEnumProperty)
	{
		EnumProperty = InEnumProperty;
		Execute__GetSignals(this)->OnEnumPropertyChanged.Broadcast(EnumProperty);
	}
}

void UTbNamesNamEs::SomeFunction_Implementation(bool bSomeParam)
{
	(void)bSomeParam;
	// do business logic here
}

void UTbNamesNamEs::SomeFunction2_Implementation(bool bSomeParam)
{
	(void)bSomeParam;
	// do business logic here
}

void UTbNamesNamEs::_ResetProperties()
{
	if (bSwitch != false)
	{
		bSwitch = false;
		Execute__GetSignals(this)->OnSwitchChanged.Broadcast(bSwitch);
	}
	if (SomeProperty != 0)
	{
		SomeProperty = 0;
		Execute__GetSignals(this)->OnSomePropertyChanged.Broadcast(SomeProperty);
	}
	if (SomePoperty2 != 0)
	{
		SomePoperty2 = 0;
		Execute__GetSignals(this)->OnSomePoperty2Changed.Broadcast(SomePoperty2);
	}
	if (EnumProperty != ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue)
	{
		EnumProperty = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
		Execute__GetSignals(this)->OnEnumPropertyChanged.Broadcast(EnumProperty);
	}
}
