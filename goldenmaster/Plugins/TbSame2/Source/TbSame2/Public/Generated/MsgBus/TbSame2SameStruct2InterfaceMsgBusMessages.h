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
#include "TbSame2SameStruct2InterfaceMsgBusMessages.generated.h"

USTRUCT()
struct FTbSame2SameStruct2InterfaceDiscoveryMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame2SameStruct2InterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 1000;

	UPROPERTY()
	FTbSame2Struct2 Prop1 = FTbSame2Struct2();

	UPROPERTY()
	FTbSame2Struct2 Prop2 = FTbSame2Struct2();
};

USTRUCT()
struct FTbSame2SameStruct2InterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame2SameStruct2InterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSame2SameStruct2InterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSame2SameStruct2InterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSame2SameStruct2InterfaceSig1SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbSame2Struct1 Param1 = FTbSame2Struct1();
};

USTRUCT()
struct FTbSame2SameStruct2InterfaceSig2SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbSame2Struct1 Param1 = FTbSame2Struct1();

	UPROPERTY()
	FTbSame2Struct2 Param2 = FTbSame2Struct2();
};

USTRUCT()
struct FTbSame2SameStruct2InterfaceSetProp1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbSame2Struct2 Prop1 = FTbSame2Struct2();
};

USTRUCT()
struct FTbSame2SameStruct2InterfaceProp1ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbSame2Struct2 Prop1 = FTbSame2Struct2();
};

USTRUCT()
struct FTbSame2SameStruct2InterfaceSetProp2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbSame2Struct2 Prop2 = FTbSame2Struct2();
};

USTRUCT()
struct FTbSame2SameStruct2InterfaceProp2ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTbSame2Struct2 Prop2 = FTbSame2Struct2();
};

USTRUCT()
struct FTbSame2SameStruct2InterfaceFunc1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTbSame2Struct1 Param1 = FTbSame2Struct1();
};

USTRUCT()
struct FTbSame2SameStruct2InterfaceFunc1ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTbSame2Struct1 Result = FTbSame2Struct1();
};

USTRUCT()
struct FTbSame2SameStruct2InterfaceFunc2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTbSame2Struct1 Param1 = FTbSame2Struct1();

	UPROPERTY()
	FTbSame2Struct2 Param2 = FTbSame2Struct2();
};

USTRUCT()
struct FTbSame2SameStruct2InterfaceFunc2ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTbSame2Struct1 Result = FTbSame2Struct1();
};
