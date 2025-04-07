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
#include "Testbed1StructArray2InterfaceMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETestbed1StructArray2InterfaceDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTestbed1StructArray2InterfaceDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETestbed1StructArray2InterfaceDiscoveryMessageType Type = ETestbed1StructArray2InterfaceDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTestbed1StructArray2InterfaceServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed1StructArray2InterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	FTestbed1StructBoolWithArray PropBool = FTestbed1StructBoolWithArray();

	UPROPERTY()
	FTestbed1StructIntWithArray PropInt = FTestbed1StructIntWithArray();

	UPROPERTY()
	FTestbed1StructFloatWithArray PropFloat = FTestbed1StructFloatWithArray();

	UPROPERTY()
	FTestbed1StructStringWithArray PropString = FTestbed1StructStringWithArray();

	UPROPERTY()
	FTestbed1StructEnumWithArray PropEnum = FTestbed1StructEnumWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed1StructArray2InterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed1StructArray2InterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTestbed1StructArray2InterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTestbed1StructArray2InterfaceSigBoolSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructBoolWithArray ParamBool = FTestbed1StructBoolWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceSigIntSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructIntWithArray ParamInt = FTestbed1StructIntWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceSigFloatSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructFloatWithArray ParamFloat = FTestbed1StructFloatWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceSigStringSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructStringWithArray ParamString = FTestbed1StructStringWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceSetPropBoolRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructBoolWithArray PropBool = FTestbed1StructBoolWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfacePropBoolChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructBoolWithArray PropBool = FTestbed1StructBoolWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceSetPropIntRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructIntWithArray PropInt = FTestbed1StructIntWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfacePropIntChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructIntWithArray PropInt = FTestbed1StructIntWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceSetPropFloatRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructFloatWithArray PropFloat = FTestbed1StructFloatWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfacePropFloatChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructFloatWithArray PropFloat = FTestbed1StructFloatWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceSetPropStringRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructStringWithArray PropString = FTestbed1StructStringWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfacePropStringChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructStringWithArray PropString = FTestbed1StructStringWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceSetPropEnumRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructEnumWithArray PropEnum = FTestbed1StructEnumWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfacePropEnumChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructEnumWithArray PropEnum = FTestbed1StructEnumWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceFuncBoolRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed1StructBoolWithArray ParamBool = FTestbed1StructBoolWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceFuncBoolReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FTestbed1StructBool> Result = TArray<FTestbed1StructBool>();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceFuncIntRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed1StructIntWithArray ParamInt = FTestbed1StructIntWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceFuncIntReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FTestbed1StructInt> Result = TArray<FTestbed1StructInt>();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceFuncFloatRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed1StructFloatWithArray ParamFloat = FTestbed1StructFloatWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceFuncFloatReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FTestbed1StructFloat> Result = TArray<FTestbed1StructFloat>();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceFuncStringRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed1StructStringWithArray ParamString = FTestbed1StructStringWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceFuncStringReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FTestbed1StructString> Result = TArray<FTestbed1StructString>();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceFuncEnumRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed1StructEnumWithArray ParamEnum = FTestbed1StructEnumWithArray();
};

USTRUCT()
struct FTestbed1StructArray2InterfaceFuncEnumReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<ETestbed1Enum0> Result = TArray<ETestbed1Enum0>();
};
