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
#include "TbSame2SameEnum2InterfaceMsgBusMessages.generated.h"

USTRUCT()
struct FTbSame2SameEnum2InterfaceDiscoveryMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame2SameEnum2InterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	ETbSame2Enum1 Prop1 = ETbSame2Enum1::TS2E1_VALUE1;

	UPROPERTY()
	ETbSame2Enum2 Prop2 = ETbSame2Enum2::TS2E2_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum2InterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame2SameEnum2InterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame2SameEnum2InterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSame2SameEnum2InterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSame2SameEnum2InterfaceSig1SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame2Enum1 Param1 = ETbSame2Enum1::TS2E1_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum2InterfaceSig2SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame2Enum1 Param1 = ETbSame2Enum1::TS2E1_VALUE1;

	UPROPERTY()
	ETbSame2Enum2 Param2 = ETbSame2Enum2::TS2E2_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum2InterfaceSetProp1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame2Enum1 Prop1 = ETbSame2Enum1::TS2E1_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum2InterfaceProp1ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame2Enum1 Prop1 = ETbSame2Enum1::TS2E1_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum2InterfaceSetProp2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame2Enum2 Prop2 = ETbSame2Enum2::TS2E2_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum2InterfaceProp2ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame2Enum2 Prop2 = ETbSame2Enum2::TS2E2_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum2InterfaceFunc1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	ETbSame2Enum1 Param1 = ETbSame2Enum1::TS2E1_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum2InterfaceFunc1ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	ETbSame2Enum1 Result = ETbSame2Enum1::TS2E1_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum2InterfaceFunc2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	ETbSame2Enum1 Param1 = ETbSame2Enum1::TS2E1_VALUE1;

	UPROPERTY()
	ETbSame2Enum2 Param2 = ETbSame2Enum2::TS2E2_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum2InterfaceFunc2ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	ETbSame2Enum1 Result = ETbSame2Enum1::TS2E1_VALUE1;
};
