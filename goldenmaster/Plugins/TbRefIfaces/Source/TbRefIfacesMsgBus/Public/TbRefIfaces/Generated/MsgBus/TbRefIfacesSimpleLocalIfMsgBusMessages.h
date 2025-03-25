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

#include "TbIfaceimport/Generated/api/TbIfaceimport_data.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_data.h"
#include "TbRefIfacesSimpleLocalIfMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETbRefIfacesSimpleLocalIfDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTbRefIfacesSimpleLocalIfDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbRefIfacesSimpleLocalIfDiscoveryMessageType Type = ETbRefIfacesSimpleLocalIfDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTbRefIfacesSimpleLocalIfServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefIfacesSimpleLocalIfInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	int32 IntProperty = 0;
};

USTRUCT()
struct FTbRefIfacesSimpleLocalIfClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefIfacesSimpleLocalIfServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefIfacesSimpleLocalIfPingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbRefIfacesSimpleLocalIfPongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbRefIfacesSimpleLocalIfIntSignalSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Param = 0;
};

USTRUCT()
struct FTbRefIfacesSimpleLocalIfSetIntPropertyRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 IntProperty = 0;
};

USTRUCT()
struct FTbRefIfacesSimpleLocalIfIntPropertyChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 IntProperty = 0;
};

USTRUCT()
struct FTbRefIfacesSimpleLocalIfIntMethodRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	int32 Param = 0;
};

USTRUCT()
struct FTbRefIfacesSimpleLocalIfIntMethodReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	int32 Result = 0;
};
