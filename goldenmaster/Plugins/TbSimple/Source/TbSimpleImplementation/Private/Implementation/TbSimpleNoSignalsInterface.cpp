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

#include "TbSimple/Implementation/TbSimpleNoSignalsInterface.h"

UTbSimpleNoSignalsInterface::~UTbSimpleNoSignalsInterface() = default;
bool UTbSimpleNoSignalsInterface::GetPropBool_Implementation() const
{
	return bPropBool;
}

void UTbSimpleNoSignalsInterface::SetPropBool_Implementation(bool bInPropBool)
{
	if (bPropBool != bInPropBool)
	{
		bPropBool = bInPropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(bPropBool);
	}
}
int32 UTbSimpleNoSignalsInterface::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleNoSignalsInterface::SetPropInt_Implementation(int32 InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
}

void UTbSimpleNoSignalsInterface::FuncVoid_Implementation()
{
	// do business logic here
}

bool UTbSimpleNoSignalsInterface::FuncBool_Implementation(bool bParamBool)
{
	(void)bParamBool;
	// do business logic here
	return false;
}
