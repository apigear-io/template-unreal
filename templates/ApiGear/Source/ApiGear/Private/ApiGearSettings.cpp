// Copyright Epic Games, Inc. All Rights Reserved
#include "ApiGearSettings.h"

UApiGearSettings::UApiGearSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, Tracer_URL(FString(TEXT("http://127.0.0.1:5905/monitor/desktop/")))
	, Tracer_Enabled(false)
	, Tracer_EnableDebugLog(false)
	, WAMP_URL(FString(TEXT("ws://127.0.0.1:8000/ws")))
	, WAMP_realm(FString(TEXT("realm1")))
	, WAMP_EnableDebugLog(false)
	, OLINK_URL(FString(TEXT("ws://127.0.0.1:8000/ws")))
	, OLINK_EnableDebugLog(false)
	, OLINK_AutoReconnectEnabled(false)
	, Simulation_URL(FString(TEXT("ws://127.0.0.1:5905/ws")))
	, Simulation_EnableDebugLog(false)
{
}
