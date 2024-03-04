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
#include "Kismet/BlueprintFunctionLibrary.h"
{{ if or (len .Module.Enums) (len .Module.Structs) -}}
#include "{{ $ModuleName }}_data.generated.h"
{{ end }}
{{- range .Module.Enums }}
{{- $moduleEnumName := printf "%s%s" $ModuleName .Name }}
{{- $class := printf "E%s%s" $ModuleName .Name }}
/**
 * Enumeration {{$class}}
 */
UENUM(BlueprintType)
enum class {{$class}} : uint8
{
{{- $hasZeroDefaultVal := false}}
{{- range $idx, $elem := .Members }}
	{{- if $idx}},{{end}}
	{{ abbreviate $moduleEnumName }}_{{ CAMEL .Name }} = {{.Value}} UMETA(Displayname = "{{.Name}}"){{if eq .Value 0}}{{$hasZeroDefaultVal = true}}{{end}}
{{- end }}
{{- if not $hasZeroDefaultVal}},{{nl}}	UNSPECIFIED = 0 UMETA(Hidden){{end}}
};
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

	/**
	 * {{$class}} to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 * 
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/** 
	 * {{$class}} to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * {{$class}} to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 * 
	 * @return FString 
	 */
	explicit operator FString() const;

	bool operator==(const {{$class}}& rhs) const;
	bool operator!=(const {{$class }}& rhs) const;
};
{{ end }}
{{- if or .Module.Structs .Module.Enums }}
/**
 * @brief BP Function library for data types
 */
UCLASS(meta = (BlueprintThreadSafe))
class {{$API_MACRO}} U{{ $ModuleName }}Library : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
{{- if .Module.Enums }}
{{- range $idx, $elem := .Module.Enums }}
{{- $moduleEnumName := printf "%s%s" $ModuleName .Name }}
{{- $class := printf "E%s%s" $ModuleName .Name }}
{{- if $idx}}{{nl}}{{end}}
	/* Convert from uint8 to {{$class}} @return true if successful */
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}")
	static bool to{{$moduleEnumName}}({{$class}}& ConvertedEnum, uint8 InValue);
{{- end }}
{{- if .Module.Structs }}{{nl}}{{ end }}
{{- end }}

{{- if .Module.Structs }}
{{- range $idx, $elem := .Module.Structs }}
{{- $class := printf "F%s%s" $ModuleName .Name }}
{{- $shortname := printf "%s%s" $ModuleName .Name }}
{{- if $idx}}{{nl}}{{end}}
	/* Returns true if {{ $shortname }} A is equal to {{ $shortname }} B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal ({{ $shortname }})", CompactNodeTitle = "==", Keywords = "== equal"), Category = "{{$Category}}")
	static bool EqualEqual_{{ $shortname }}{{ $shortname }}({{ $class }} A, {{ $class }} B);

	/* Returns true if {{ $shortname }} A is not equal to {{ $shortname }} B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal ({{ $shortname }})", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "{{$Category}}")
	static bool NotEqual_{{ $shortname }}{{ $shortname }}({{ $class }} A, {{ $class }} B);

	/** Converts a {{ $shortname }} to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON ({{ $shortname }})", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_{{ $shortname }}ToJSON(const {{ $class }}& In{{ $shortname }});

	/** Converts a {{ $shortname }} to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String ({{ $shortname }})", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_{{ $shortname }}ToString(const {{ $class }}& In{{ $shortname }});
{{- end }}
{{- end }}
};
{{- end }}
{{- if or .Module.Structs .Module.Enums }}{{nl}}{{ end -}}
