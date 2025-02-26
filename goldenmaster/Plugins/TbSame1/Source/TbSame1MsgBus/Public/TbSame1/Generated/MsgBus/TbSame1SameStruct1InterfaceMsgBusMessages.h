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
#include "TbSame1SameStruct1InterfaceMsgBusMessages.generated.h"

USTRUCT()
struct FTbSame1SameStruct1InterfaceDiscoveryMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame1SameStruct1InterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 1000;

	UPROPERTY()
	FTbSame1Struct1 Prop1 = FTbSame1Struct1();
};

USTRUCT()
struct FTbSame1SameStruct1InterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame1SameStruct1InterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame1SameStruct1InterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSame1SameStruct1InterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSame1SameStruct1InterfaceSig1SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbSame1Struct1 Param1 = FTbSame1Struct1();
};

USTRUCT()
struct FTbSame1SameStruct1InterfaceSetProp1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbSame1Struct1 Prop1 = FTbSame1Struct1();
};

USTRUCT()
struct FTbSame1SameStruct1InterfaceProp1ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbSame1Struct1 Prop1 = FTbSame1Struct1();
};

USTRUCT()
struct FTbSame1SameStruct1InterfaceFunc1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTbSame1Struct1 Param1 = FTbSame1Struct1();
};

USTRUCT()
struct FTbSame1SameStruct1InterfaceFunc1ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTbSame1Struct1 Result = FTbSame1Struct1();
};
