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
#pragma once

#include "Generated/api/TbSimple_data.h"
#include "TbSimpleSimpleArrayInterfaceMsgBusMessages.generated.h"

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceDiscoveryMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 1000;

	UPROPERTY()
	TArray<bool> PropBool = TArray<bool>();

	UPROPERTY()
	TArray<int32> PropInt = TArray<int32>();

	UPROPERTY()
	TArray<int32> PropInt32 = TArray<int32>();

	UPROPERTY()
	TArray<int64> PropInt64 = TArray<int64>();

	UPROPERTY()
	TArray<float> PropFloat = TArray<float>();

	UPROPERTY()
	TArray<float> PropFloat32 = TArray<float>();

	UPROPERTY()
	TArray<double> PropFloat64 = TArray<double>();

	UPROPERTY()
	TArray<FString> PropString = TArray<FString>();

	UPROPERTY()
	FString PropReadOnlyString = FString();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSigBoolSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<bool> ParamBool = TArray<bool>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSigIntSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<int32> ParamInt = TArray<int32>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSigInt32SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<int32> ParamInt32 = TArray<int32>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSigInt64SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<int64> ParamInt64 = TArray<int64>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSigFloatSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<float> ParamFloat = TArray<float>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSigFloat32SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<float> ParamFloa32 = TArray<float>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSigFloat64SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<double> ParamFloat64 = TArray<double>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSigStringSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FString> ParamString = TArray<FString>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSetPropBoolRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<bool> PropBool = TArray<bool>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfacePropBoolChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<bool> PropBool = TArray<bool>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSetPropIntRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<int32> PropInt = TArray<int32>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfacePropIntChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<int32> PropInt = TArray<int32>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSetPropInt32RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<int32> PropInt32 = TArray<int32>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfacePropInt32ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<int32> PropInt32 = TArray<int32>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSetPropInt64RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<int64> PropInt64 = TArray<int64>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfacePropInt64ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<int64> PropInt64 = TArray<int64>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSetPropFloatRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<float> PropFloat = TArray<float>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfacePropFloatChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<float> PropFloat = TArray<float>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSetPropFloat32RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<float> PropFloat32 = TArray<float>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfacePropFloat32ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<float> PropFloat32 = TArray<float>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSetPropFloat64RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<double> PropFloat64 = TArray<double>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfacePropFloat64ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<double> PropFloat64 = TArray<double>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSetPropStringRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FString> PropString = TArray<FString>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfacePropStringChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FString> PropString = TArray<FString>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceSetPropReadOnlyStringRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FString PropReadOnlyString = FString();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfacePropReadOnlyStringChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FString PropReadOnlyString = FString();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncBoolRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<bool> ParamBool = TArray<bool>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncBoolReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<bool> Result = TArray<bool>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncIntRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<int32> ParamInt = TArray<int32>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncIntReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<int32> Result = TArray<int32>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncInt32RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<int32> ParamInt32 = TArray<int32>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncInt32ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<int32> Result = TArray<int32>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncInt64RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<int64> ParamInt64 = TArray<int64>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncInt64ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<int64> Result = TArray<int64>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncFloatRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<float> ParamFloat = TArray<float>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncFloatReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<float> Result = TArray<float>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncFloat32RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<float> ParamFloat32 = TArray<float>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncFloat32ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<float> Result = TArray<float>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncFloat64RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<double> ParamFloat = TArray<double>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncFloat64ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<double> Result = TArray<double>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncStringRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FString> ParamString = TArray<FString>();
};

USTRUCT()
struct FTbSimpleSimpleArrayInterfaceFuncStringReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FString> Result = TArray<FString>();
};
