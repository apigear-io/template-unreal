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
#include "Misc/ScopeRWLock.h"
{{- end}}

{{- $includes := getEmptyStringList}}
{{- range .Module.Interfaces }}
{{- range .Properties }}
    {{- if eq .KindType "interface"}}
        {{- $moduleName :=  "" }}
        {{- if ne .Import "" }}
            {{- $moduleName = Camel .Import }}
        {{- else }}
            {{- $moduleName = Camel .Module.Name }}
        {{- end }}
        {{- $includeName :=  printf "\"%s/Generated/api/%s%sInterface.h\"" $moduleName $moduleName .Type }}
        {{- $includes = (appendList $includes $includeName) }}
    {{- end }}
{{- end }}
{{- end }}

{{- $includes = unique $includes }}
{{- range $includes }}
#include {{ .}}
{{- end }}

{{- if (eq $anyProperties 1)}}
#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}_data.h"
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Generated/api/{{Camel .Name}}_data.h"
{{- end }}

{{- range .Module.Interfaces }}
{{- $IfaceName := Camel .Name }}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
{{- if len .Properties }}

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class {{ $API_MACRO }} {{$Iface}}PropertiesData
{
public:
{{- range $i, $e := .Properties }}
	{{- if ( ueIsStdSimpleType . ) }}
	std::atomic<{{ueReturn "" .}}> {{ueVar "" .}}{ {{- ueDefault "" . -}} };
	{{- else }}
	void Set{{ueVar "" .}}({{ueParam "In" .}});
	{{ueReturn "" .}} Get{{ueVar "" .}}() const;
	{{- end }}
{{- end }}

private:
{{- range $i, $e := .Properties }}
	{{- if not ( ueIsStdSimpleType . ) }}
	mutable FRWLock {{ueVar "" .}}Lock;
	{{ueReturn "" .}} {{ueVar "" .}}{ {{- ueDefault "" . -}} };
	{{- end }}
{{- end }}
};
{{- end }}
{{- end }}
{{- end }}
