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

UTbNamesNamEsImplementation::~UTbNamesNamEsImplementation() = default;
bool UTbNamesNamEsImplementation::GetSwitch() const
{
	return bSwitch;
}

void UTbNamesNamEsImplementation::SetSwitch(bool bInSwitch)
{
	if (bSwitch != bInSwitch)
	{
		bSwitch = bInSwitch;
		_GetPublisher()->BroadcastSwitchChanged(bSwitch);
	}
}
int32 UTbNamesNamEsImplementation::GetSomeProperty() const
{
	return SomeProperty;
}

void UTbNamesNamEsImplementation::SetSomeProperty(int32 InSomeProperty)
{
	if (SomeProperty != InSomeProperty)
	{
		SomeProperty = InSomeProperty;
		_GetPublisher()->BroadcastSomePropertyChanged(SomeProperty);
	}
}
int32 UTbNamesNamEsImplementation::GetSomePoperty2() const
{
	return SomePoperty2;
}

void UTbNamesNamEsImplementation::SetSomePoperty2(int32 InSomePoperty2)
{
	if (SomePoperty2 != InSomePoperty2)
	{
		SomePoperty2 = InSomePoperty2;
		_GetPublisher()->BroadcastSomePoperty2Changed(SomePoperty2);
	}
}
ETbNamesEnum_With_Under_scores UTbNamesNamEsImplementation::GetEnumProperty() const
{
	return EnumProperty;
}

void UTbNamesNamEsImplementation::SetEnumProperty(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	if (EnumProperty != InEnumProperty)
	{
		EnumProperty = InEnumProperty;
		_GetPublisher()->BroadcastEnumPropertyChanged(EnumProperty);
	}
}

void UTbNamesNamEsImplementation::SomeFunction(bool bSomeParam)
{
	(void)bSomeParam;
	// do business logic here
}

void UTbNamesNamEsImplementation::SomeFunction2(bool bSomeParam)
{
	(void)bSomeParam;
	// do business logic here
}

void UTbNamesNamEsImplementation::_ResetProperties()
{
	if (bSwitch != false)
	{
		bSwitch = false;
		_GetPublisher()->BroadcastSwitchChanged(bSwitch);
	}
	if (SomeProperty != 0)
	{
		SomeProperty = 0;
		_GetPublisher()->BroadcastSomePropertyChanged(SomeProperty);
	}
	if (SomePoperty2 != 0)
	{
		SomePoperty2 = 0;
		_GetPublisher()->BroadcastSomePoperty2Changed(SomePoperty2);
	}
	if (EnumProperty != ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue)
	{
		EnumProperty = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
		_GetPublisher()->BroadcastEnumPropertyChanged(EnumProperty);
	}
}
