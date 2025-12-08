{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%sCORE_API" (CAMEL .Module.Name) }}
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

{{- $anyProperties := 0 -}}
{{- $shouldIncludeAtomic := 0 -}}
{{- $shouldIncludeMutex := 0 -}}
{{- range .Module.Interfaces }}
{{- if len .Properties }}
{{- $anyProperties = 1 }}

{{- range $i, $e := .Properties }}
	{{- if ( ueIsStdSimpleType . ) }}
	{{- $shouldIncludeAtomic = 1}}
	{{- else}}
	{{- $shouldIncludeMutex = 1}}
	{{- end}}
{{- end}}
{{- end }}
{{- end }}
{{- if (eq $shouldIncludeAtomic  1) }}
#include <atomic>
{{- end}}
{{- if (eq $shouldIncludeMutex 1) }}
#include "HAL/CriticalSection.h"
{{- end}}

{{- if (eq $anyProperties 1)}}
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Generated/api/{{Camel .Name}}_apig.h"
{{- end }}

{{- range .Module.Interfaces }}
{{- $IfaceName := Camel .Name }}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
{{- if len .Properties }}

/**
	\brief data structure to hold the last sent property values
*/
struct {{$Iface}}PropertiesData
{
{{- range $i, $e := .Properties }}
	{{- if ( ueIsStdSimpleType . ) }}
	std::atomic<{{ueReturn "" .}}> {{ueVar "" .}}{ {{- ueDefault "" . -}} };
	{{- else }}
	FCriticalSection {{ueVar "" .}}Mutex;
	{{ueReturn "" .}} {{ueVar "" .}}{ {{- ueDefault "" . -}} };
	{{- end }}
{{- end }}
};
{{- end }}
{{- end }}
{{- end }}
