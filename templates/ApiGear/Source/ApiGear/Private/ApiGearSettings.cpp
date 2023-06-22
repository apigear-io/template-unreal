// Copyright Epic Games, Inc. All Rights Reserved
#include "ApiGearSettings.h"

UApiGearSettings::UApiGearSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, Tracer_URL(FString(TEXT("http://127.0.0.1:5905/monitor/desktop")))
	, Tracer_Enabled(false)
	, Tracer_EnableDebugLog(false)
	, bSaveRuntimeEdit(false)
	, OLINK_AutoStart(true)
	, OLINK_Port(8000)
{
}
