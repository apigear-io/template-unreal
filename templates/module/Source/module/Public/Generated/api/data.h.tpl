{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name) -}}
{{- $Category := printf "ApiGear|%s" $ModuleName }}
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

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
{{ if or (len .Module.Enums) (len .Module.Structs) -}}
#include "{{ $ModuleName }}_data.generated.h"
{{ end }}
{{- range .Module.Enums }}
{{- $class := printf "E%s%s" $ModuleName .Name }}
/**
 * Enumeration {{$class}}
 */
UENUM(BlueprintType)
enum class {{$class}} : uint8
{
{{- range $idx, $elem := .Members }}
	{{- if $idx}},{{end}}
	{{ CAMEL .Name }} UMETA(Displayname = "{{.Name}}")
{{- end }}
};

/**
 * Convert from uint8 to {{$class}}
 */
bool toUE4Type({{$class}}& value, uint8 v);
{{ end }}
{{- range .Module.Structs }}
{{- $class := printf "F%s%s" $ModuleName .Name }}
/**
 * Struct {{$class}}
 */
USTRUCT(BlueprintType)
struct {{$API_MACRO}} {{$class }} : public FTableRowBase
{
	GENERATED_BODY()
{{- range .Fields }}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "{{$Category}}")
	{{ueType "" .}} {{.Name}}{ {{- ueDefault "" . -}} };
{{- end }}

	bool operator==(const {{$class}}& rhs) const;
	bool operator!=(const {{$class }}& rhs) const;
};
{{ end }}