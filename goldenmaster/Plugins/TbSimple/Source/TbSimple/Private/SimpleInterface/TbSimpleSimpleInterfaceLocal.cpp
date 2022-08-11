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

namespace TbSimple {
namespace SimpleInterface {
namespace Private {
LocalService::LocalService()
    : ITbSimpleSimpleInterfaceInterface()
    , bPropBool(false)
    , PropInt(0)
    , PropFloat(0.0f)
    , PropString(FString())
{
}
LocalService::~LocalService()
{
}

FTbSimpleSimpleInterfaceSigBoolDelegate& LocalService::GetSigBoolSignalDelegate()
{
    return SigBoolSignal;
}

FTbSimpleSimpleInterfaceSigIntDelegate& LocalService::GetSigIntSignalDelegate()
{
    return SigIntSignal;
}

FTbSimpleSimpleInterfaceSigFloatDelegate& LocalService::GetSigFloatSignalDelegate()
{
    return SigFloatSignal;
}

FTbSimpleSimpleInterfaceSigStringDelegate& LocalService::GetSigStringSignalDelegate()
{
    return SigStringSignal;
}

bool LocalService::GetPropBool() const
{
    return bPropBool;
}

void LocalService::SetPropBool(bool bInPropBool)
{
    if(bPropBool != bInPropBool)
    {
        bPropBool = bInPropBool;
        PropBoolChanged.Broadcast(bPropBool);
    }
}

FTbSimpleSimpleInterfacePropBoolChangedDelegate& LocalService::GetPropBoolChangedDelegate()
{
    return PropBoolChanged;
}
int32 LocalService::GetPropInt() const
{
    return PropInt;
}

void LocalService::SetPropInt(int32 InPropInt)
{
    if(PropInt != InPropInt)
    {
        PropInt = InPropInt;
        PropIntChanged.Broadcast(PropInt);
    }
}

FTbSimpleSimpleInterfacePropIntChangedDelegate& LocalService::GetPropIntChangedDelegate()
{
    return PropIntChanged;
}
float LocalService::GetPropFloat() const
{
    return PropFloat;
}

void LocalService::SetPropFloat(float InPropFloat)
{
    if(PropFloat != InPropFloat)
    {
        PropFloat = InPropFloat;
        PropFloatChanged.Broadcast(PropFloat);
    }
}

FTbSimpleSimpleInterfacePropFloatChangedDelegate& LocalService::GetPropFloatChangedDelegate()
{
    return PropFloatChanged;
}
FString LocalService::GetPropString() const
{
    return PropString;
}

void LocalService::SetPropString(const FString& InPropString)
{
    if(PropString != InPropString)
    {
        PropString = InPropString;
        PropStringChanged.Broadcast(PropString);
    }
}

FTbSimpleSimpleInterfacePropStringChangedDelegate& LocalService::GetPropStringChangedDelegate()
{
    return PropStringChanged;
}

bool LocalService::FuncBool(bool bParamBool)
{
    (void) bParamBool;
    // do business logic here
    return false;
}
int32 LocalService::FuncInt(int32 ParamInt)
{
    (void) ParamInt;
    // do business logic here
    return 0;
}
float LocalService::FuncFloat(float ParamFloat)
{
    (void) ParamFloat;
    // do business logic here
    return 0.0f;
}
FString LocalService::FuncString(const FString& ParamString)
{
    (void) ParamString;
    // do business logic here
    return FString();
}

} // namespace Private
} // namespace SimpleInterface
} // namespace TbSimple
