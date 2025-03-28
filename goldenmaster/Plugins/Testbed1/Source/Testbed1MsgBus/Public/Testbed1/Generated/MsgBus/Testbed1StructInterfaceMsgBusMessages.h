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
#include "Testbed1StructInterfaceMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETestbed1StructInterfaceDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTestbed1StructInterfaceDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETestbed1StructInterfaceDiscoveryMessageType Type = ETestbed1StructInterfaceDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTestbed1StructInterfaceServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed1StructInterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	FTestbed1StructBool PropBool = FTestbed1StructBool();

	UPROPERTY()
	FTestbed1StructInt PropInt = FTestbed1StructInt();

	UPROPERTY()
	FTestbed1StructFloat PropFloat = FTestbed1StructFloat();

	UPROPERTY()
	FTestbed1StructString PropString = FTestbed1StructString();
};

USTRUCT()
struct FTestbed1StructInterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed1StructInterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed1StructInterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTestbed1StructInterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTestbed1StructInterfaceSigBoolSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructBool ParamBool = FTestbed1StructBool();
};

USTRUCT()
struct FTestbed1StructInterfaceSigIntSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructInt ParamInt = FTestbed1StructInt();
};

USTRUCT()
struct FTestbed1StructInterfaceSigFloatSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructFloat ParamFloat = FTestbed1StructFloat();
};

USTRUCT()
struct FTestbed1StructInterfaceSigStringSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructString ParamString = FTestbed1StructString();
};

USTRUCT()
struct FTestbed1StructInterfaceSetPropBoolRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructBool PropBool = FTestbed1StructBool();
};

USTRUCT()
struct FTestbed1StructInterfacePropBoolChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructBool PropBool = FTestbed1StructBool();
};

USTRUCT()
struct FTestbed1StructInterfaceSetPropIntRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructInt PropInt = FTestbed1StructInt();
};

USTRUCT()
struct FTestbed1StructInterfacePropIntChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructInt PropInt = FTestbed1StructInt();
};

USTRUCT()
struct FTestbed1StructInterfaceSetPropFloatRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructFloat PropFloat = FTestbed1StructFloat();
};

USTRUCT()
struct FTestbed1StructInterfacePropFloatChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructFloat PropFloat = FTestbed1StructFloat();
};

USTRUCT()
struct FTestbed1StructInterfaceSetPropStringRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructString PropString = FTestbed1StructString();
};

USTRUCT()
struct FTestbed1StructInterfacePropStringChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed1StructString PropString = FTestbed1StructString();
};

USTRUCT()
struct FTestbed1StructInterfaceFuncBoolRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed1StructBool ParamBool = FTestbed1StructBool();
};

USTRUCT()
struct FTestbed1StructInterfaceFuncBoolReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed1StructBool Result = FTestbed1StructBool();
};

USTRUCT()
struct FTestbed1StructInterfaceFuncIntRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed1StructInt ParamInt = FTestbed1StructInt();
};

USTRUCT()
struct FTestbed1StructInterfaceFuncIntReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed1StructInt Result = FTestbed1StructInt();
};

USTRUCT()
struct FTestbed1StructInterfaceFuncFloatRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed1StructFloat ParamFloat = FTestbed1StructFloat();
};

USTRUCT()
struct FTestbed1StructInterfaceFuncFloatReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed1StructFloat Result = FTestbed1StructFloat();
};

USTRUCT()
struct FTestbed1StructInterfaceFuncStringRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed1StructString ParamString = FTestbed1StructString();
};

USTRUCT()
struct FTestbed1StructInterfaceFuncStringReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed1StructString Result = FTestbed1StructString();
};
