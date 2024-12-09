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
#include "Testbed2ManyParamInterfaceMsgBusMessages.generated.h"

USTRUCT()
struct FTestbed2ManyParamInterfaceDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 ClientPingIntervalMS = 1000;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Prop1 = 0;

	UPROPERTY()
	int32 Prop2 = 0;

	UPROPERTY()
	int32 Prop3 = 0;

	UPROPERTY()
	int32 Prop4 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed2ManyParamInterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTestbed2ManyParamInterfaceSig1SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Param1 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceSig2SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Param1 = 0;

	UPROPERTY()
	int32 Param2 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceSig3SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Param1 = 0;

	UPROPERTY()
	int32 Param2 = 0;

	UPROPERTY()
	int32 Param3 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceSig4SignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Param1 = 0;

	UPROPERTY()
	int32 Param2 = 0;

	UPROPERTY()
	int32 Param3 = 0;

	UPROPERTY()
	int32 Param4 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceSetProp1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Prop1 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceProp1ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Prop1 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceSetProp2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Prop2 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceProp2ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Prop2 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceSetProp3RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Prop3 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceProp3ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Prop3 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceSetProp4RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Prop4 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceProp4ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Prop4 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceFunc1RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;
	UPROPERTY()
	int32 Param1 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceFunc1ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;

	UPROPERTY()
	int32 Result = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceFunc2RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;
	UPROPERTY()
	int32 Param1 = 0;

	UPROPERTY()
	int32 Param2 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceFunc2ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;

	UPROPERTY()
	int32 Result = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceFunc3RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;
	UPROPERTY()
	int32 Param1 = 0;

	UPROPERTY()
	int32 Param2 = 0;

	UPROPERTY()
	int32 Param3 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceFunc3ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;

	UPROPERTY()
	int32 Result = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceFunc4RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;
	UPROPERTY()
	int32 Param1 = 0;

	UPROPERTY()
	int32 Param2 = 0;

	UPROPERTY()
	int32 Param3 = 0;

	UPROPERTY()
	int32 Param4 = 0;
};

USTRUCT()
struct FTestbed2ManyParamInterfaceFunc4ReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid RepsonseId;

	UPROPERTY()
	int32 Result = 0;
};
