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

#include "TbSimple/Generated/api/TbSimple_data.h"
#include "TbSimpleNoPropertiesInterfaceMsgBusMessages.generated.h"

USTRUCT()
struct FTbSimpleNoPropertiesInterfaceDiscoveryMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleNoPropertiesInterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;
};

USTRUCT()
struct FTbSimpleNoPropertiesInterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleNoPropertiesInterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleNoPropertiesInterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSimpleNoPropertiesInterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSimpleNoPropertiesInterfaceSigVoidSignalMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleNoPropertiesInterfaceSigBoolSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	bool bParamBool = false;
};

USTRUCT()
struct FTbSimpleNoPropertiesInterfaceFuncVoidRequestMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleNoPropertiesInterfaceFuncBoolRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	bool bParamBool = false;
};

USTRUCT()
struct FTbSimpleNoPropertiesInterfaceFuncBoolReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	bool Result = false;
};
