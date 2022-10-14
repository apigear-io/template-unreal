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

#include "Testbed1StructInterfaceLocal.h"

namespace Testbed1
{
namespace StructInterface
{
namespace Private
{
LocalService::LocalService()
	: ITestbed1StructInterfaceInterface()
	, PropBool(FTestbed1StructBool())
	, PropInt(FTestbed1StructInt())
	, PropFloat(FTestbed1StructFloat())
	, PropString(FTestbed1StructString())
{
}
LocalService::~LocalService()
{
}

FTestbed1StructInterfaceSigBoolDelegate& LocalService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

FTestbed1StructInterfaceSigIntDelegate& LocalService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

FTestbed1StructInterfaceSigFloatDelegate& LocalService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

FTestbed1StructInterfaceSigStringDelegate& LocalService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

FTestbed1StructBool LocalService::GetPropBool_Implementation() const
{
	return PropBool;
}

void LocalService::SetPropBool_Implementation(const FTestbed1StructBool& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		PropBoolChanged.Broadcast(PropBool);
	}
}

FTestbed1StructInterfacePropBoolChangedDelegate& LocalService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}
FTestbed1StructInt LocalService::GetPropInt_Implementation() const
{
	return PropInt;
}

void LocalService::SetPropInt_Implementation(const FTestbed1StructInt& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		PropIntChanged.Broadcast(PropInt);
	}
}

FTestbed1StructInterfacePropIntChangedDelegate& LocalService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}
FTestbed1StructFloat LocalService::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void LocalService::SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		PropFloatChanged.Broadcast(PropFloat);
	}
}

FTestbed1StructInterfacePropFloatChangedDelegate& LocalService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}
FTestbed1StructString LocalService::GetPropString_Implementation() const
{
	return PropString;
}

void LocalService::SetPropString_Implementation(const FTestbed1StructString& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		PropStringChanged.Broadcast(PropString);
	}
}

FTestbed1StructInterfacePropStringChangedDelegate& LocalService::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

FTestbed1StructBool LocalService::FuncBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return FTestbed1StructBool();
}
FTestbed1StructBool LocalService::FuncInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return FTestbed1StructBool();
}
FTestbed1StructFloat LocalService::FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return FTestbed1StructFloat();
}
FTestbed1StructString LocalService::FuncString_Implementation(const FTestbed1StructString& ParamString)
{
	(void)ParamString;
	// do business logic here
	return FTestbed1StructString();
}

} // namespace Private
} // namespace StructInterface
} // namespace Testbed1
