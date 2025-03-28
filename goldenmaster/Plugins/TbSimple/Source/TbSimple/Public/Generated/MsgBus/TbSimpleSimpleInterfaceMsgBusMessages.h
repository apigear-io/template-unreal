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
#include "TbSimpleSimpleInterfaceMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETbSimpleSimpleInterfaceDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTbSimpleSimpleInterfaceDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSimpleSimpleInterfaceDiscoveryMessageType Type = ETbSimpleSimpleInterfaceDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleSimpleInterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	bool bPropBool = false;

	UPROPERTY()
	int32 PropInt = 0;

	UPROPERTY()
	int32 PropInt32 = 0;

	UPROPERTY()
	int64 PropInt64 = 0LL;

	UPROPERTY()
	float PropFloat = 0.0f;

	UPROPERTY()
	float PropFloat32 = 0.0f;

	UPROPERTY()
	double PropFloat64 = 0.0;

	UPROPERTY()
	FString PropString = FString();
};

USTRUCT()
struct FTbSimpleSimpleInterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleSimpleInterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleSimpleInterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSimpleSimpleInterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSigBoolSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	bool bParamBool = false;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSigIntSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 ParamInt = 0;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSigInt32SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 ParamInt32 = 0;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSigInt64SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int64 ParamInt64 = 0LL;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSigFloatSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	float ParamFloat = 0.0f;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSigFloat32SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	float ParamFloat32 = 0.0f;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSigFloat64SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double ParamFloat64 = 0.0;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSigStringSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FString ParamString = FString();
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSetPropBoolRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	bool bPropBool = false;
};

USTRUCT()
struct FTbSimpleSimpleInterfacePropBoolChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	bool bPropBool = false;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSetPropIntRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 PropInt = 0;
};

USTRUCT()
struct FTbSimpleSimpleInterfacePropIntChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 PropInt = 0;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSetPropInt32RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 PropInt32 = 0;
};

USTRUCT()
struct FTbSimpleSimpleInterfacePropInt32ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 PropInt32 = 0;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSetPropInt64RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int64 PropInt64 = 0LL;
};

USTRUCT()
struct FTbSimpleSimpleInterfacePropInt64ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int64 PropInt64 = 0LL;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSetPropFloatRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	float PropFloat = 0.0f;
};

USTRUCT()
struct FTbSimpleSimpleInterfacePropFloatChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	float PropFloat = 0.0f;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSetPropFloat32RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	float PropFloat32 = 0.0f;
};

USTRUCT()
struct FTbSimpleSimpleInterfacePropFloat32ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	float PropFloat32 = 0.0f;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSetPropFloat64RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double PropFloat64 = 0.0;
};

USTRUCT()
struct FTbSimpleSimpleInterfacePropFloat64ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double PropFloat64 = 0.0;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceSetPropStringRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FString PropString = FString();
};

USTRUCT()
struct FTbSimpleSimpleInterfacePropStringChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FString PropString = FString();
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncNoReturnValueRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	bool bParamBool = false;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncBoolRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	bool bParamBool = false;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncBoolReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	bool Result = false;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncIntRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	int32 ParamInt = 0;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncIntReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	int32 Result = 0;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncInt32RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	int32 ParamInt32 = 0;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncInt32ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	int32 Result = 0;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncInt64RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	int64 ParamInt64 = 0LL;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncInt64ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	int64 Result = 0LL;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncFloatRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	float ParamFloat = 0.0f;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncFloatReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	float Result = 0.0f;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncFloat32RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	float ParamFloat32 = 0.0f;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncFloat32ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	float Result = 0.0f;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncFloat64RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	double ParamFloat = 0.0;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncFloat64ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	double Result = 0.0;
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncStringRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FString ParamString = FString();
};

USTRUCT()
struct FTbSimpleSimpleInterfaceFuncStringReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FString Result = FString();
};
