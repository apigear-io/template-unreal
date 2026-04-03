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

#include "TbStructArray/Generated/api/TbStructArray_data.h"
#include "TbStructArrayStructArrayFieldInterfaceMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETbStructArrayStructArrayFieldInterfaceDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbStructArrayStructArrayFieldInterfaceDiscoveryMessageType Type = ETbStructArrayStructArrayFieldInterfaceDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	FTbStructArrayStructWithArrayOfStructs PropStructArray = FTbStructArrayStructWithArrayOfStructs();

	UPROPERTY()
	FTbStructArrayStructWithArrayOfEnums PropEnumArray = FTbStructArrayStructWithArrayOfEnums();

	UPROPERTY()
	FTbStructArrayStructWithArrayOfInts PropIntArray = FTbStructArrayStructWithArrayOfInts();

	UPROPERTY()
	FTbStructArrayMixedStruct PropMixed = FTbStructArrayMixedStruct();
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceSigMixedSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbStructArrayMixedStruct ParamMixed = FTbStructArrayMixedStruct();
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceSigStructArraySignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbStructArrayStructWithArrayOfStructs ParamPoints = FTbStructArrayStructWithArrayOfStructs();
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceSetPropStructArrayRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbStructArrayStructWithArrayOfStructs PropStructArray = FTbStructArrayStructWithArrayOfStructs();
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfacePropStructArrayChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbStructArrayStructWithArrayOfStructs PropStructArray = FTbStructArrayStructWithArrayOfStructs();
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceSetPropEnumArrayRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbStructArrayStructWithArrayOfEnums PropEnumArray = FTbStructArrayStructWithArrayOfEnums();
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfacePropEnumArrayChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbStructArrayStructWithArrayOfEnums PropEnumArray = FTbStructArrayStructWithArrayOfEnums();
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceSetPropIntArrayRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbStructArrayStructWithArrayOfInts PropIntArray = FTbStructArrayStructWithArrayOfInts();
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfacePropIntArrayChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbStructArrayStructWithArrayOfInts PropIntArray = FTbStructArrayStructWithArrayOfInts();
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceSetPropMixedRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbStructArrayMixedStruct PropMixed = FTbStructArrayMixedStruct();
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfacePropMixedChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbStructArrayMixedStruct PropMixed = FTbStructArrayMixedStruct();
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceFuncMixedRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTbStructArrayMixedStruct ParamMixed = FTbStructArrayMixedStruct();
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceFuncMixedReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTbStructArrayMixedStruct Result = FTbStructArrayMixedStruct();
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceFuncStructArrayRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTbStructArrayStructWithArrayOfStructs ParamPoints = FTbStructArrayStructWithArrayOfStructs();
};

USTRUCT()
struct FTbStructArrayStructArrayFieldInterfaceFuncStructArrayReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTbStructArrayStructWithArrayOfStructs Result = FTbStructArrayStructWithArrayOfStructs();
};
