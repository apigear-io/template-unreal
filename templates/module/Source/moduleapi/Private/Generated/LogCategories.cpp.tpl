{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name -}}
#include "{{$ModuleName}}/Generated/{{$ModuleName}}LogCategories.h"

DEFINE_LOG_CATEGORY(Log{{$ModuleName}});
