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

#include "Testbed2/Generated/api/Testbed2_data.h"
#include "Testbed2NestedStruct3InterfaceMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETestbed2NestedStruct3InterfaceDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETestbed2NestedStruct3InterfaceDiscoveryMessageType Type = ETestbed2NestedStruct3InterfaceDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	FTestbed2NestedStruct1 Prop1 = FTestbed2NestedStruct1();

	UPROPERTY()
	FTestbed2NestedStruct2 Prop2 = FTestbed2NestedStruct2();

	UPROPERTY()
	FTestbed2NestedStruct3 Prop3 = FTestbed2NestedStruct3();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed2NestedStruct3InterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTestbed2NestedStruct3InterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceSig1SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct1 Param1 = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceSig2SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct1 Param1 = FTestbed2NestedStruct1();

	UPROPERTY()
	FTestbed2NestedStruct2 Param2 = FTestbed2NestedStruct2();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceSig3SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct1 Param1 = FTestbed2NestedStruct1();

	UPROPERTY()
	FTestbed2NestedStruct2 Param2 = FTestbed2NestedStruct2();

	UPROPERTY()
	FTestbed2NestedStruct3 Param3 = FTestbed2NestedStruct3();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceSetProp1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct1 Prop1 = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceProp1ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct1 Prop1 = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceSetProp2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct2 Prop2 = FTestbed2NestedStruct2();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceProp2ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct2 Prop2 = FTestbed2NestedStruct2();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceSetProp3RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct3 Prop3 = FTestbed2NestedStruct3();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceProp3ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct3 Prop3 = FTestbed2NestedStruct3();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceFunc1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed2NestedStruct1 Param1 = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceFunc1ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed2NestedStruct1 Result = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceFunc2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed2NestedStruct1 Param1 = FTestbed2NestedStruct1();

	UPROPERTY()
	FTestbed2NestedStruct2 Param2 = FTestbed2NestedStruct2();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceFunc2ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed2NestedStruct1 Result = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceFunc3RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed2NestedStruct1 Param1 = FTestbed2NestedStruct1();

	UPROPERTY()
	FTestbed2NestedStruct2 Param2 = FTestbed2NestedStruct2();

	UPROPERTY()
	FTestbed2NestedStruct3 Param3 = FTestbed2NestedStruct3();
};

USTRUCT()
struct FTestbed2NestedStruct3InterfaceFunc3ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed2NestedStruct1 Result = FTestbed2NestedStruct1();
};
