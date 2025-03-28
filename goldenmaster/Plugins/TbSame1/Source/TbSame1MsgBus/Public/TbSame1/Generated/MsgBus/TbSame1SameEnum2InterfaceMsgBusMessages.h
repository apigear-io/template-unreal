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

#include "TbSame1/Generated/api/TbSame1_data.h"
#include "TbSame1SameEnum2InterfaceMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETbSame1SameEnum2InterfaceDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame1SameEnum2InterfaceDiscoveryMessageType Type = ETbSame1SameEnum2InterfaceDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	ETbSame1Enum1 Prop1 = ETbSame1Enum1::TS1E1_VALUE1;

	UPROPERTY()
	ETbSame1Enum2 Prop2 = ETbSame1Enum2::TS1E2_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame1SameEnum2InterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSame1SameEnum2InterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceSig1SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame1Enum1 Param1 = ETbSame1Enum1::TS1E1_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceSig2SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame1Enum1 Param1 = ETbSame1Enum1::TS1E1_VALUE1;

	UPROPERTY()
	ETbSame1Enum2 Param2 = ETbSame1Enum2::TS1E2_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceSetProp1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame1Enum1 Prop1 = ETbSame1Enum1::TS1E1_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceProp1ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame1Enum1 Prop1 = ETbSame1Enum1::TS1E1_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceSetProp2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame1Enum2 Prop2 = ETbSame1Enum2::TS1E2_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceProp2ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame1Enum2 Prop2 = ETbSame1Enum2::TS1E2_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceFunc1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	ETbSame1Enum1 Param1 = ETbSame1Enum1::TS1E1_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceFunc1ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	ETbSame1Enum1 Result = ETbSame1Enum1::TS1E1_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceFunc2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	ETbSame1Enum1 Param1 = ETbSame1Enum1::TS1E1_VALUE1;

	UPROPERTY()
	ETbSame1Enum2 Param2 = ETbSame1Enum2::TS1E2_VALUE1;
};

USTRUCT()
struct FTbSame1SameEnum2InterfaceFunc2ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	ETbSame1Enum1 Result = ETbSame1Enum1::TS1E1_VALUE1;
};
