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

#include "TbSame2/Generated/api/TbSame2_data.h"
#include "TbSame2SameStruct1InterfaceMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETbSame2SameStruct1InterfaceDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTbSame2SameStruct1InterfaceDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame2SameStruct1InterfaceDiscoveryMessageType Type = ETbSame2SameStruct1InterfaceDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTbSame2SameStruct1InterfaceServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame2SameStruct1InterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	FTbSame2Struct1 Prop1 = FTbSame2Struct1();
};

USTRUCT()
struct FTbSame2SameStruct1InterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame2SameStruct1InterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame2SameStruct1InterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSame2SameStruct1InterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSame2SameStruct1InterfaceSig1SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbSame2Struct1 Param1 = FTbSame2Struct1();
};

USTRUCT()
struct FTbSame2SameStruct1InterfaceSetProp1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbSame2Struct1 Prop1 = FTbSame2Struct1();
};

USTRUCT()
struct FTbSame2SameStruct1InterfaceProp1ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbSame2Struct1 Prop1 = FTbSame2Struct1();
};

USTRUCT()
struct FTbSame2SameStruct1InterfaceFunc1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTbSame2Struct1 Param1 = FTbSame2Struct1();
};

USTRUCT()
struct FTbSame2SameStruct1InterfaceFunc1ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTbSame2Struct1 Result = FTbSame2Struct1();
};
