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

#include "Generated/api/Testbed2_data.h"
#include "Testbed2NestedStruct2InterfaceMsgBusMessages.generated.h"

USTRUCT()
struct FTestbed2NestedStruct2InterfaceDiscoveryMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed2NestedStruct2InterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 1000;

	UPROPERTY()
	FTestbed2NestedStruct1 Prop1 = FTestbed2NestedStruct1();

	UPROPERTY()
	FTestbed2NestedStruct2 Prop2 = FTestbed2NestedStruct2();
};

USTRUCT()
struct FTestbed2NestedStruct2InterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed2NestedStruct2InterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed2NestedStruct2InterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTestbed2NestedStruct2InterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTestbed2NestedStruct2InterfaceSig1SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct1 Param1 = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct2InterfaceSig2SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct1 Param1 = FTestbed2NestedStruct1();

	UPROPERTY()
	FTestbed2NestedStruct2 Param2 = FTestbed2NestedStruct2();
};

USTRUCT()
struct FTestbed2NestedStruct2InterfaceSetProp1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct1 Prop1 = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct2InterfaceProp1ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct1 Prop1 = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct2InterfaceSetProp2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct2 Prop2 = FTestbed2NestedStruct2();
};

USTRUCT()
struct FTestbed2NestedStruct2InterfaceProp2ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct2 Prop2 = FTestbed2NestedStruct2();
};

USTRUCT()
struct FTestbed2NestedStruct2InterfaceFunc1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed2NestedStruct1 Param1 = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct2InterfaceFunc1ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed2NestedStruct1 Result = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct2InterfaceFunc2RequestMessage
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
struct FTestbed2NestedStruct2InterfaceFunc2ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed2NestedStruct1 Result = FTestbed2NestedStruct1();
};
