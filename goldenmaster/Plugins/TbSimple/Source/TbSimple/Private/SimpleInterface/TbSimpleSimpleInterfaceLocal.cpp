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

void UTbSimpleSimpleInterfaceLocalService::BroadcastSigBool_Implementation(bool bParamBool)
{
	SigBoolSignal.Broadcast(bParamBool);
}

FTbSimpleSimpleInterfaceSigBoolDelegate& UTbSimpleSimpleInterfaceLocalService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTbSimpleSimpleInterfaceLocalService::BroadcastSigInt_Implementation(int32 ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

FTbSimpleSimpleInterfaceSigIntDelegate& UTbSimpleSimpleInterfaceLocalService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTbSimpleSimpleInterfaceLocalService::BroadcastSigFloat_Implementation(float ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTbSimpleSimpleInterfaceSigFloatDelegate& UTbSimpleSimpleInterfaceLocalService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTbSimpleSimpleInterfaceLocalService::BroadcastSigString_Implementation(const FString& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

FTbSimpleSimpleInterfaceSigStringDelegate& UTbSimpleSimpleInterfaceLocalService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTbSimpleSimpleInterfaceLocalService::BroadcastPropBoolChanged_Implementation(bool bInPropBool)
{
	PropBoolChanged.Broadcast(bInPropBool);
}

bool UTbSimpleSimpleInterfaceLocalService::GetPropBool_Implementation() const
{
	return bPropBool;
}

void UTbSimpleSimpleInterfaceLocalService::SetPropBool_Implementation(bool bInPropBool)
{
	if (bPropBool != bInPropBool)
	{
		bPropBool = bInPropBool;
		Execute_BroadcastPropBoolChanged(this, bPropBool);
	}
}

FTbSimpleSimpleInterfacePropBoolChangedDelegate& UTbSimpleSimpleInterfaceLocalService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}
void UTbSimpleSimpleInterfaceLocalService::BroadcastPropIntChanged_Implementation(int32 InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

int32 UTbSimpleSimpleInterfaceLocalService::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleSimpleInterfaceLocalService::SetPropInt_Implementation(int32 InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute_BroadcastPropIntChanged(this, PropInt);
	}
}

FTbSimpleSimpleInterfacePropIntChangedDelegate& UTbSimpleSimpleInterfaceLocalService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}
void UTbSimpleSimpleInterfaceLocalService::BroadcastPropFloatChanged_Implementation(float InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

float UTbSimpleSimpleInterfaceLocalService::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTbSimpleSimpleInterfaceLocalService::SetPropFloat_Implementation(float InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		Execute_BroadcastPropFloatChanged(this, PropFloat);
	}
}

FTbSimpleSimpleInterfacePropFloatChangedDelegate& UTbSimpleSimpleInterfaceLocalService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}
void UTbSimpleSimpleInterfaceLocalService::BroadcastPropStringChanged_Implementation(const FString& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}

FString UTbSimpleSimpleInterfaceLocalService::GetPropString_Implementation() const
{
	return PropString;
}

void UTbSimpleSimpleInterfaceLocalService::SetPropString_Implementation(const FString& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		Execute_BroadcastPropStringChanged(this, PropString);
	}
}

FTbSimpleSimpleInterfacePropStringChangedDelegate& UTbSimpleSimpleInterfaceLocalService::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

bool UTbSimpleSimpleInterfaceLocalService::FuncBool_Implementation(bool bParamBool)
{
	(void)bParamBool;
	// do business logic here
	return false;
}
int32 UTbSimpleSimpleInterfaceLocalService::FuncInt_Implementation(int32 ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return 0;
}
float UTbSimpleSimpleInterfaceLocalService::FuncFloat_Implementation(float ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return 0.0f;
}
FString UTbSimpleSimpleInterfaceLocalService::FuncString_Implementation(const FString& ParamString)
{
	(void)ParamString;
	// do business logic here
	return FString();
}
