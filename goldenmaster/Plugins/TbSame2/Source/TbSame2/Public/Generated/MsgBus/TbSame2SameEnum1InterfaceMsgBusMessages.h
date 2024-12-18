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

#include "Generated/api/TbSame2_data.h"
#include "TbSame2SameEnum1InterfaceMsgBusMessages.generated.h"

USTRUCT()
struct FTbSame2SameEnum1InterfaceDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 ClientPingIntervalMS = 1000;
};

USTRUCT()
struct FTbSame2SameEnum1InterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame2Enum1 Prop1 = ETbSame2Enum1::TS2E1_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum1InterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame2SameEnum1InterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame2SameEnum1InterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSame2SameEnum1InterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSame2SameEnum1InterfaceSig1SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame2Enum1 Param1 = ETbSame2Enum1::TS2E1_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum1InterfaceSetProp1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame2Enum1 Prop1 = ETbSame2Enum1::TS2E1_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum1InterfaceProp1ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbSame2Enum1 Prop1 = ETbSame2Enum1::TS2E1_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum1InterfaceFunc1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	ETbSame2Enum1 Param1 = ETbSame2Enum1::TS2E1_VALUE1;
};

USTRUCT()
struct FTbSame2SameEnum1InterfaceFunc1ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	ETbSame2Enum1 Result = ETbSame2Enum1::TS2E1_VALUE1;
};