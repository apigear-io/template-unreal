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

#include "TbNames/Implementation/TbNamesNamEs.h"

UTbNamesNamEs::~UTbNamesNamEs() = default;
bool UTbNamesNamEs::GetSwitch() const
{
	return bSwitch;
}

void UTbNamesNamEs::SetSwitch(bool bInSwitch)
{
	if (bSwitch != bInSwitch)
	{
		bSwitch = bInSwitch;
		_GetSignals()->BroadcastSwitchChanged(bSwitch);
	}
}
int32 UTbNamesNamEs::GetSomeProperty() const
{
	return SomeProperty;
}

void UTbNamesNamEs::SetSomeProperty(int32 InSomeProperty)
{
	if (SomeProperty != InSomeProperty)
	{
		SomeProperty = InSomeProperty;
		_GetSignals()->BroadcastSomePropertyChanged(SomeProperty);
	}
}
int32 UTbNamesNamEs::GetSomePoperty2() const
{
	return SomePoperty2;
}

void UTbNamesNamEs::SetSomePoperty2(int32 InSomePoperty2)
{
	if (SomePoperty2 != InSomePoperty2)
	{
		SomePoperty2 = InSomePoperty2;
		_GetSignals()->BroadcastSomePoperty2Changed(SomePoperty2);
	}
}
ETbNamesEnum_With_Under_scores UTbNamesNamEs::GetEnumProperty() const
{
	return EnumProperty;
}

void UTbNamesNamEs::SetEnumProperty(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	if (EnumProperty != InEnumProperty)
	{
		EnumProperty = InEnumProperty;
		_GetSignals()->BroadcastEnumPropertyChanged(EnumProperty);
	}
}

void UTbNamesNamEs::SomeFunction(bool bSomeParam)
{
	(void)bSomeParam;
	// do business logic here
}

void UTbNamesNamEs::SomeFunction2(bool bSomeParam)
{
	(void)bSomeParam;
	// do business logic here
}

void UTbNamesNamEs::_ResetProperties()
{
	if (bSwitch != false)
	{
		bSwitch = false;
		_GetSignals()->BroadcastSwitchChanged(bSwitch);
	}
	if (SomeProperty != 0)
	{
		SomeProperty = 0;
		_GetSignals()->BroadcastSomePropertyChanged(SomeProperty);
	}
	if (SomePoperty2 != 0)
	{
		SomePoperty2 = 0;
		_GetSignals()->BroadcastSomePoperty2Changed(SomePoperty2);
	}
	if (EnumProperty != ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue)
	{
		EnumProperty = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
		_GetSignals()->BroadcastEnumPropertyChanged(EnumProperty);
	}
}
