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

#include "TbSimpleSimpleArrayInterfaceLocal.h"
UTbSimpleSimpleArrayInterfaceLocalService::UTbSimpleSimpleArrayInterfaceLocalService()
	: ITbSimpleSimpleArrayInterfaceInterface()
	, PropBool(TArray<bool>())
	, PropInt(TArray<int32>())
	, PropFloat(TArray<float>())
	, PropString(TArray<FString>())
{
}
UTbSimpleSimpleArrayInterfaceLocalService::~UTbSimpleSimpleArrayInterfaceLocalService()
{
}

FTbSimpleSimpleArrayInterfaceSigBoolDelegate& UTbSimpleSimpleArrayInterfaceLocalService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

FTbSimpleSimpleArrayInterfaceSigIntDelegate& UTbSimpleSimpleArrayInterfaceLocalService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

FTbSimpleSimpleArrayInterfaceSigFloatDelegate& UTbSimpleSimpleArrayInterfaceLocalService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

FTbSimpleSimpleArrayInterfaceSigStringDelegate& UTbSimpleSimpleArrayInterfaceLocalService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

TArray<bool> UTbSimpleSimpleArrayInterfaceLocalService::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTbSimpleSimpleArrayInterfaceLocalService::SetPropBool_Implementation(const TArray<bool>& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		PropBoolChanged.Broadcast(PropBool);
	}
}

FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& UTbSimpleSimpleArrayInterfaceLocalService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}
TArray<int32> UTbSimpleSimpleArrayInterfaceLocalService::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleSimpleArrayInterfaceLocalService::SetPropInt_Implementation(const TArray<int32>& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		PropIntChanged.Broadcast(PropInt);
	}
}

FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& UTbSimpleSimpleArrayInterfaceLocalService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}
TArray<float> UTbSimpleSimpleArrayInterfaceLocalService::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTbSimpleSimpleArrayInterfaceLocalService::SetPropFloat_Implementation(const TArray<float>& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		PropFloatChanged.Broadcast(PropFloat);
	}
}

FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& UTbSimpleSimpleArrayInterfaceLocalService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}
TArray<FString> UTbSimpleSimpleArrayInterfaceLocalService::GetPropString_Implementation() const
{
	return PropString;
}

void UTbSimpleSimpleArrayInterfaceLocalService::SetPropString_Implementation(const TArray<FString>& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		PropStringChanged.Broadcast(PropString);
	}
}

FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& UTbSimpleSimpleArrayInterfaceLocalService::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

TArray<bool> UTbSimpleSimpleArrayInterfaceLocalService::FuncBool_Implementation(const TArray<bool>& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return TArray<bool>();
}
TArray<int32> UTbSimpleSimpleArrayInterfaceLocalService::FuncInt_Implementation(const TArray<int32>& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return TArray<int32>();
}
TArray<float> UTbSimpleSimpleArrayInterfaceLocalService::FuncFloat_Implementation(const TArray<float>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<float>();
}
TArray<FString> UTbSimpleSimpleArrayInterfaceLocalService::FuncString_Implementation(const TArray<FString>& ParamString)
{
	(void)ParamString;
	// do business logic here
	return TArray<FString>();
}
