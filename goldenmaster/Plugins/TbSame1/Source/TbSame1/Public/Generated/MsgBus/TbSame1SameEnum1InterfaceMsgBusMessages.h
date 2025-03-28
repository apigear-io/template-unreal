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

#include "Generated/api/TbSame1_data.h"
#include "TbSame1SameEnum1InterfaceMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETbSame1SameEnum1InterfaceDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTbSame1SameEnum1InterfaceDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame1SameEnum1InterfaceDiscoveryMessageType Type = ETbSame1SameEnum1InterfaceDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTbSame1SameEnum1InterfaceServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame1SameEnum1InterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	ETbSame1Enum1 Prop1 = ETbSame1Enum1::TS1E1_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum1InterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame1SameEnum1InterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame1SameEnum1InterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSame1SameEnum1InterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSame1SameEnum1InterfaceSig1SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame1Enum1 Param1 = ETbSame1Enum1::TS1E1_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum1InterfaceSetProp1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame1Enum1 Prop1 = ETbSame1Enum1::TS1E1_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum1InterfaceProp1ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame1Enum1 Prop1 = ETbSame1Enum1::TS1E1_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum1InterfaceFunc1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	ETbSame1Enum1 Param1 = ETbSame1Enum1::TS1E1_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum1InterfaceFunc1ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	ETbSame1Enum1 Result = ETbSame1Enum1::TS1E1_VALUE1;
};
