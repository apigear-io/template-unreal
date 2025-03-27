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

#include "Testbed1/Generated/api/Testbed1_data.h"
#include "Testbed1StructArrayInterfaceMsgBusMessages.generated.h"

USTRUCT()
struct FTestbed1StructArrayInterfaceDiscoveryMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed1StructArrayInterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	TArray<FTestbed1StructBool> PropBool = TArray<FTestbed1StructBool>();

	UPROPERTY()
	TArray<FTestbed1StructInt> PropInt = TArray<FTestbed1StructInt>();

	UPROPERTY()
	TArray<FTestbed1StructFloat> PropFloat = TArray<FTestbed1StructFloat>();

	UPROPERTY()
	TArray<FTestbed1StructString> PropString = TArray<FTestbed1StructString>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed1StructArrayInterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed1StructArrayInterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTestbed1StructArrayInterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTestbed1StructArrayInterfaceSigBoolSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FTestbed1StructBool> ParamBool = TArray<FTestbed1StructBool>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceSigIntSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FTestbed1StructInt> ParamInt = TArray<FTestbed1StructInt>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceSigFloatSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FTestbed1StructFloat> ParamFloat = TArray<FTestbed1StructFloat>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceSigStringSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FTestbed1StructString> ParamString = TArray<FTestbed1StructString>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceSetPropBoolRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FTestbed1StructBool> PropBool = TArray<FTestbed1StructBool>();
};

USTRUCT()
struct FTestbed1StructArrayInterfacePropBoolChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FTestbed1StructBool> PropBool = TArray<FTestbed1StructBool>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceSetPropIntRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FTestbed1StructInt> PropInt = TArray<FTestbed1StructInt>();
};

USTRUCT()
struct FTestbed1StructArrayInterfacePropIntChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FTestbed1StructInt> PropInt = TArray<FTestbed1StructInt>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceSetPropFloatRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FTestbed1StructFloat> PropFloat = TArray<FTestbed1StructFloat>();
};

USTRUCT()
struct FTestbed1StructArrayInterfacePropFloatChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FTestbed1StructFloat> PropFloat = TArray<FTestbed1StructFloat>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceSetPropStringRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FTestbed1StructString> PropString = TArray<FTestbed1StructString>();
};

USTRUCT()
struct FTestbed1StructArrayInterfacePropStringChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FTestbed1StructString> PropString = TArray<FTestbed1StructString>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceFuncBoolRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FTestbed1StructBool> ParamBool = TArray<FTestbed1StructBool>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceFuncBoolReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FTestbed1StructBool> Result = TArray<FTestbed1StructBool>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceFuncIntRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FTestbed1StructInt> ParamInt = TArray<FTestbed1StructInt>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceFuncIntReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FTestbed1StructInt> Result = TArray<FTestbed1StructInt>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceFuncFloatRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FTestbed1StructFloat> ParamFloat = TArray<FTestbed1StructFloat>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceFuncFloatReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FTestbed1StructFloat> Result = TArray<FTestbed1StructFloat>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceFuncStringRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FTestbed1StructString> ParamString = TArray<FTestbed1StructString>();
};

USTRUCT()
struct FTestbed1StructArrayInterfaceFuncStringReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FTestbed1StructString> Result = TArray<FTestbed1StructString>();
};
