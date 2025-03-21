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
#include "TbSimpleNoOperationsInterfaceMsgBusMessages.generated.h"

USTRUCT()
struct FTbSimpleNoOperationsInterfaceDiscoveryMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleNoOperationsInterfaceInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 1000;

	UPROPERTY()
	bool bPropBool = false;

	UPROPERTY()
	int32 PropInt = 0;
};

USTRUCT()
struct FTbSimpleNoOperationsInterfaceClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleNoOperationsInterfaceServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleNoOperationsInterfacePingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSimpleNoOperationsInterfacePongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbSimpleNoOperationsInterfaceSigVoidSignalMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbSimpleNoOperationsInterfaceSigBoolSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	bool bParamBool = false;
};

USTRUCT()
struct FTbSimpleNoOperationsInterfaceSetPropBoolRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	bool bPropBool = false;
};

USTRUCT()
struct FTbSimpleNoOperationsInterfacePropBoolChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	bool bPropBool = false;
};

USTRUCT()
struct FTbSimpleNoOperationsInterfaceSetPropIntRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 PropInt = 0;
};

USTRUCT()
struct FTbSimpleNoOperationsInterfacePropIntChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 PropInt = 0;
};
