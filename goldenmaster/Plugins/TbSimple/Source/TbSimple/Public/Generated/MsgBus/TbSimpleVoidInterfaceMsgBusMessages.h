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
#include "TbSimpleVoidInterfaceMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETbSimpleVoidInterfaceDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTbSimpleVoidInterfaceDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSimpleVoidInterfaceDiscoveryMessageType Type = ETbSimpleVoidInterfaceDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTbSimpleVoidInterfaceServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleVoidInterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;
};

USTRUCT()
struct FTbSimpleVoidInterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleVoidInterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleVoidInterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSimpleVoidInterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSimpleVoidInterfaceSigVoidSignalMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleVoidInterfaceFuncVoidRequestMessage
{
	GENERATED_BODY()
};
