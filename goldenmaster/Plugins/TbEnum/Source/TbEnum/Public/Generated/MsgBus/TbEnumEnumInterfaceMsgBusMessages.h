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

#include "Generated/api/TbEnum_data.h"
#include "TbEnumEnumInterfaceMsgBusMessages.generated.h"

USTRUCT()
struct FTbEnumEnumInterfaceDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 ClientPingIntervalMS = 1000;
};

USTRUCT()
struct FTbEnumEnumInterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbEnumEnum0 Prop0 = ETbEnumEnum0::TEE0_VALUE0;

	UPROPERTY()
	ETbEnumEnum1 Prop1 = ETbEnumEnum1::TEE1_VALUE1;

	UPROPERTY()
	ETbEnumEnum2 Prop2 = ETbEnumEnum2::TEE2_VALUE2;

	UPROPERTY()
	ETbEnumEnum3 Prop3 = ETbEnumEnum3::TEE3_VALUE3;
};

USTRUCT()
struct FTbEnumEnumInterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbEnumEnumInterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbEnumEnumInterfaceSig0SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbEnumEnum0 Param0 = ETbEnumEnum0::TEE0_VALUE0;
};

USTRUCT()
struct FTbEnumEnumInterfaceSig1SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbEnumEnum1 Param1 = ETbEnumEnum1::TEE1_VALUE1;
};

USTRUCT()
struct FTbEnumEnumInterfaceSig2SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbEnumEnum2 Param2 = ETbEnumEnum2::TEE2_VALUE2;
};

USTRUCT()
struct FTbEnumEnumInterfaceSig3SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbEnumEnum3 Param3 = ETbEnumEnum3::TEE3_VALUE3;
};

USTRUCT()
struct FTbEnumEnumInterfaceSetProp0RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbEnumEnum0 Prop0 = ETbEnumEnum0::TEE0_VALUE0;
};

USTRUCT()
struct FTbEnumEnumInterfaceProp0ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbEnumEnum0 Prop0 = ETbEnumEnum0::TEE0_VALUE0;
};

USTRUCT()
struct FTbEnumEnumInterfaceSetProp1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbEnumEnum1 Prop1 = ETbEnumEnum1::TEE1_VALUE1;
};

USTRUCT()
struct FTbEnumEnumInterfaceProp1ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbEnumEnum1 Prop1 = ETbEnumEnum1::TEE1_VALUE1;
};

USTRUCT()
struct FTbEnumEnumInterfaceSetProp2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbEnumEnum2 Prop2 = ETbEnumEnum2::TEE2_VALUE2;
};

USTRUCT()
struct FTbEnumEnumInterfaceProp2ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbEnumEnum2 Prop2 = ETbEnumEnum2::TEE2_VALUE2;
};

USTRUCT()
struct FTbEnumEnumInterfaceSetProp3RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbEnumEnum3 Prop3 = ETbEnumEnum3::TEE3_VALUE3;
};

USTRUCT()
struct FTbEnumEnumInterfaceProp3ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbEnumEnum3 Prop3 = ETbEnumEnum3::TEE3_VALUE3;
};

USTRUCT()
struct FTbEnumEnumInterfaceFunc0RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;
	UPROPERTY()
	ETbEnumEnum0 Param0 = ETbEnumEnum0::TEE0_VALUE0;
};

USTRUCT()
struct FTbEnumEnumInterfaceFunc0ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;

	UPROPERTY()
	ETbEnumEnum0 Result = ETbEnumEnum0::TEE0_VALUE0;
};

USTRUCT()
struct FTbEnumEnumInterfaceFunc1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;
	UPROPERTY()
	ETbEnumEnum1 Param1 = ETbEnumEnum1::TEE1_VALUE1;
};

USTRUCT()
struct FTbEnumEnumInterfaceFunc1ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;

	UPROPERTY()
	ETbEnumEnum1 Result = ETbEnumEnum1::TEE1_VALUE1;
};

USTRUCT()
struct FTbEnumEnumInterfaceFunc2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;
	UPROPERTY()
	ETbEnumEnum2 Param2 = ETbEnumEnum2::TEE2_VALUE2;
};

USTRUCT()
struct FTbEnumEnumInterfaceFunc2ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;

	UPROPERTY()
	ETbEnumEnum2 Result = ETbEnumEnum2::TEE2_VALUE2;
};

USTRUCT()
struct FTbEnumEnumInterfaceFunc3RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;
	UPROPERTY()
	ETbEnumEnum3 Param3 = ETbEnumEnum3::TEE3_VALUE3;
};

USTRUCT()
struct FTbEnumEnumInterfaceFunc3ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;

	UPROPERTY()
	ETbEnumEnum3 Result = ETbEnumEnum3::TEE3_VALUE3;
};
