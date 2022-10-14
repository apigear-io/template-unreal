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

#include "TbSimpleSimpleInterfaceLocal.h"
UTbSimpleSimpleInterfaceLocalService::UTbSimpleSimpleInterfaceLocalService()
	: ITbSimpleSimpleInterfaceInterface()
	, bPropBool(false)
	, PropInt(0)
	, PropFloat(0.0f)
	, PropString(FString())
{
}
UTbSimpleSimpleInterfaceLocalService::~UTbSimpleSimpleInterfaceLocalService()
{
}

FTbSimpleSimpleInterfaceSigBoolDelegate& UTbSimpleSimpleInterfaceLocalService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

FTbSimpleSimpleInterfaceSigIntDelegate& UTbSimpleSimpleInterfaceLocalService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

FTbSimpleSimpleInterfaceSigFloatDelegate& UTbSimpleSimpleInterfaceLocalService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

FTbSimpleSimpleInterfaceSigStringDelegate& UTbSimpleSimpleInterfaceLocalService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTbSimpleSimpleInterfaceLocalService::GetPropBool_Implementation(bool& ReturnValue) const
{
	ReturnValue = bPropBool;
}

void UTbSimpleSimpleInterfaceLocalService::SetPropBool_Implementation(bool bInPropBool)
{
	if (bPropBool != bInPropBool)
	{
		bPropBool = bInPropBool;
		PropBoolChanged.Broadcast(bPropBool);
	}
}

FTbSimpleSimpleInterfacePropBoolChangedDelegate& UTbSimpleSimpleInterfaceLocalService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}
void UTbSimpleSimpleInterfaceLocalService::GetPropInt_Implementation(int32& ReturnValue) const
{
	ReturnValue = PropInt;
}

void UTbSimpleSimpleInterfaceLocalService::SetPropInt_Implementation(int32 InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		PropIntChanged.Broadcast(PropInt);
	}
}

FTbSimpleSimpleInterfacePropIntChangedDelegate& UTbSimpleSimpleInterfaceLocalService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}
void UTbSimpleSimpleInterfaceLocalService::GetPropFloat_Implementation(float& ReturnValue) const
{
	ReturnValue = PropFloat;
}

void UTbSimpleSimpleInterfaceLocalService::SetPropFloat_Implementation(float InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		PropFloatChanged.Broadcast(PropFloat);
	}
}

FTbSimpleSimpleInterfacePropFloatChangedDelegate& UTbSimpleSimpleInterfaceLocalService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}
void UTbSimpleSimpleInterfaceLocalService::GetPropString_Implementation(FString& ReturnValue) const
{
	ReturnValue = PropString;
}

void UTbSimpleSimpleInterfaceLocalService::SetPropString_Implementation(const FString& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		PropStringChanged.Broadcast(PropString);
	}
}

FTbSimpleSimpleInterfacePropStringChangedDelegate& UTbSimpleSimpleInterfaceLocalService::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

void UTbSimpleSimpleInterfaceLocalService::FuncBool_Implementation(bool& Result, bool bParamBool)
{
	(void)bParamBool;
	// do business logic here
	Result = false;
}
void UTbSimpleSimpleInterfaceLocalService::FuncInt_Implementation(int32& Result, int32 ParamInt)
{
	(void)ParamInt;
	// do business logic here
	Result = 0;
}
void UTbSimpleSimpleInterfaceLocalService::FuncFloat_Implementation(float& Result, float ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	Result = 0.0f;
}
void UTbSimpleSimpleInterfaceLocalService::FuncString_Implementation(FString& Result, const FString& ParamString)
{
	(void)ParamString;
	// do business logic here
	Result = FString();
}
