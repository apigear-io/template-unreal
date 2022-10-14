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

#include "Testbed1StructArrayInterfaceLocal.h"

namespace Testbed1
{
namespace StructArrayInterface
{
namespace Private
{
LocalService::LocalService()
	: ITestbed1StructArrayInterfaceInterface()
	, PropBool(TArray<FTestbed1StructBool>())
	, PropInt(TArray<FTestbed1StructInt>())
	, PropFloat(TArray<FTestbed1StructFloat>())
	, PropString(TArray<FTestbed1StructString>())
{
}
LocalService::~LocalService()
{
}

FTestbed1StructArrayInterfaceSigBoolDelegate& LocalService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

FTestbed1StructArrayInterfaceSigIntDelegate& LocalService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

FTestbed1StructArrayInterfaceSigFloatDelegate& LocalService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

FTestbed1StructArrayInterfaceSigStringDelegate& LocalService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

TArray<FTestbed1StructBool> LocalService::GetPropBool_Implementation() const
{
	return PropBool;
}

void LocalService::SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		PropBoolChanged.Broadcast(PropBool);
	}
}

FTestbed1StructArrayInterfacePropBoolChangedDelegate& LocalService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}
TArray<FTestbed1StructInt> LocalService::GetPropInt_Implementation() const
{
	return PropInt;
}

void LocalService::SetPropInt_Implementation(const TArray<FTestbed1StructInt>& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		PropIntChanged.Broadcast(PropInt);
	}
}

FTestbed1StructArrayInterfacePropIntChangedDelegate& LocalService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}
TArray<FTestbed1StructFloat> LocalService::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void LocalService::SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		PropFloatChanged.Broadcast(PropFloat);
	}
}

FTestbed1StructArrayInterfacePropFloatChangedDelegate& LocalService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}
TArray<FTestbed1StructString> LocalService::GetPropString_Implementation() const
{
	return PropString;
}

void LocalService::SetPropString_Implementation(const TArray<FTestbed1StructString>& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		PropStringChanged.Broadcast(PropString);
	}
}

FTestbed1StructArrayInterfacePropStringChangedDelegate& LocalService::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

FTestbed1StructBool LocalService::FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return FTestbed1StructBool();
}
FTestbed1StructBool LocalService::FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return FTestbed1StructBool();
}
FTestbed1StructBool LocalService::FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return FTestbed1StructBool();
}
FTestbed1StructBool LocalService::FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString)
{
	(void)ParamString;
	// do business logic here
	return FTestbed1StructBool();
}

} // namespace Private
} // namespace StructArrayInterface
} // namespace Testbed1
