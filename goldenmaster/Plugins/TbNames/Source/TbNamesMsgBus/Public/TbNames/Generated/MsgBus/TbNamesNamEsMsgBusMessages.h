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

#include "TbNames/Generated/api/TbNames_data.h"
#include "TbNamesNamEsMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETbNamesNamEsDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTbNamesNamEsDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbNamesNamEsDiscoveryMessageType Type = ETbNamesNamEsDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTbNamesNamEsServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbNamesNamEsInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	bool bSwitch = false;

	UPROPERTY()
	int32 SomeProperty = 0;

	UPROPERTY()
	int32 SomePoperty2 = 0;

	UPROPERTY()
	ETbNamesEnum_With_Under_scores EnumProperty = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE;
};

USTRUCT()
struct FTbNamesNamEsClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbNamesNamEsServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbNamesNamEsPingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbNamesNamEsPongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbNamesNamEsSomeSignalSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	bool bSomeParam = false;
};

USTRUCT()
struct FTbNamesNamEsSomeSignal2SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	bool bSomeParam = false;
};

USTRUCT()
struct FTbNamesNamEsSetSwitchRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	bool bSwitch = false;
};

USTRUCT()
struct FTbNamesNamEsSwitchChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	bool bSwitch = false;
};

USTRUCT()
struct FTbNamesNamEsSetSomePropertyRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 SomeProperty = 0;
};

USTRUCT()
struct FTbNamesNamEsSomePropertyChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 SomeProperty = 0;
};

USTRUCT()
struct FTbNamesNamEsSetSomePoperty2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 SomePoperty2 = 0;
};

USTRUCT()
struct FTbNamesNamEsSomePoperty2ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 SomePoperty2 = 0;
};

USTRUCT()
struct FTbNamesNamEsSetEnumPropertyRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbNamesEnum_With_Under_scores EnumProperty = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE;
};

USTRUCT()
struct FTbNamesNamEsEnumPropertyChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbNamesEnum_With_Under_scores EnumProperty = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE;
};

USTRUCT()
struct FTbNamesNamEsSomeFunctionRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	bool bSomeParam = false;
};

USTRUCT()
struct FTbNamesNamEsSomeFunction2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	bool bSomeParam = false;
};
