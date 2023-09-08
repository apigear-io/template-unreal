{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name) -}}
#include "{{$ModuleName}}LogCategories.h"

DEFINE_LOG_CATEGORY(Log{{$ModuleName}});
