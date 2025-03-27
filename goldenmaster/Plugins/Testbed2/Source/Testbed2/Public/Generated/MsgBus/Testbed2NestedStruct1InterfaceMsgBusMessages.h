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
#include "Testbed2NestedStruct1InterfaceMsgBusMessages.generated.h"

USTRUCT()
struct FTestbed2NestedStruct1InterfaceDiscoveryMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed2NestedStruct1InterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	FTestbed2NestedStruct1 Prop1 = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct1InterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed2NestedStruct1InterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed2NestedStruct1InterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTestbed2NestedStruct1InterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTestbed2NestedStruct1InterfaceSig1SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct1 Param1 = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct1InterfaceSetProp1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct1 Prop1 = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct1InterfaceProp1ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FTestbed2NestedStruct1 Prop1 = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct1InterfaceFunc1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed2NestedStruct1 Param1 = FTestbed2NestedStruct1();
};

USTRUCT()
struct FTestbed2NestedStruct1InterfaceFunc1ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FTestbed2NestedStruct1 Result = FTestbed2NestedStruct1();
};
