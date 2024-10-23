{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name -}}
#include "{{$ModuleName}}/Generated/{{$ModuleName}}LogCategories.h"

DEFINE_LOG_CATEGORY(Log{{$ModuleName}});
