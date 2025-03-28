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

#include "Generated/api/Counter_data.h"
#include "Generated/api/CustomTypes_data.h"
#include "Generated/api/ExternTypes_data.h"
#include "CounterCounterMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ECounterCounterDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FCounterCounterDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ECounterCounterDiscoveryMessageType Type = ECounterCounterDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FCounterCounterServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FCounterCounterInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	FCustomTypesVector3D Vector = FCustomTypesVector3D();

	UPROPERTY()
	FVector ExternVector = FVector(0.f, 0.f, 0.f);

	UPROPERTY()
	TArray<FCustomTypesVector3D> VectorArray = TArray<FCustomTypesVector3D>();

	UPROPERTY()
	TArray<FVector> ExternVectorArray = TArray<FVector>();
};

USTRUCT()
struct FCounterCounterClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FCounterCounterServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FCounterCounterPingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FCounterCounterPongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FCounterCounterValueChangedSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FCustomTypesVector3D Vector = FCustomTypesVector3D();

	UPROPERTY()
	FVector ExternVector = FVector(0.f, 0.f, 0.f);

	UPROPERTY()
	TArray<FCustomTypesVector3D> VectorArray = TArray<FCustomTypesVector3D>();

	UPROPERTY()
	TArray<FVector> ExternVectorArray = TArray<FVector>();
};

USTRUCT()
struct FCounterCounterSetVectorRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FCustomTypesVector3D Vector = FCustomTypesVector3D();
};

USTRUCT()
struct FCounterCounterVectorChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FCustomTypesVector3D Vector = FCustomTypesVector3D();
};

USTRUCT()
struct FCounterCounterSetExternVectorRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FVector ExternVector = FVector(0.f, 0.f, 0.f);
};

USTRUCT()
struct FCounterCounterExternVectorChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FVector ExternVector = FVector(0.f, 0.f, 0.f);
};

USTRUCT()
struct FCounterCounterSetVectorArrayRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FCustomTypesVector3D> VectorArray = TArray<FCustomTypesVector3D>();
};

USTRUCT()
struct FCounterCounterVectorArrayChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FCustomTypesVector3D> VectorArray = TArray<FCustomTypesVector3D>();
};

USTRUCT()
struct FCounterCounterSetExternVectorArrayRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FVector> ExternVectorArray = TArray<FVector>();
};

USTRUCT()
struct FCounterCounterExternVectorArrayChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FVector> ExternVectorArray = TArray<FVector>();
};

USTRUCT()
struct FCounterCounterIncrementRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FVector Vec = FVector(0.f, 0.f, 0.f);
};

USTRUCT()
struct FCounterCounterIncrementReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FVector Result = FVector(0.f, 0.f, 0.f);
};

USTRUCT()
struct FCounterCounterIncrementArrayRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FVector> Vec = TArray<FVector>();
};

USTRUCT()
struct FCounterCounterIncrementArrayReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FVector> Result = TArray<FVector>();
};

USTRUCT()
struct FCounterCounterDecrementRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FCustomTypesVector3D Vec = FCustomTypesVector3D();
};

USTRUCT()
struct FCounterCounterDecrementReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	FCustomTypesVector3D Result = FCustomTypesVector3D();
};

USTRUCT()
struct FCounterCounterDecrementArrayRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FCustomTypesVector3D> Vec = TArray<FCustomTypesVector3D>();
};

USTRUCT()
struct FCounterCounterDecrementArrayReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<FCustomTypesVector3D> Result = TArray<FCustomTypesVector3D>();
};
