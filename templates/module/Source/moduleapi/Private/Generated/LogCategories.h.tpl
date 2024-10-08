{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name -}}
// Copyright Epic Games, Inc. All Rights Reserved
#pragma once

#include "Logging/LogMacros.h"

/// list of module specific but otherwise generic log categories
/// should be used instead of LogTemp or otherwise too specific categories

{{$API_MACRO}} DECLARE_LOG_CATEGORY_EXTERN(Log{{$ModuleName}}, Log, All);
