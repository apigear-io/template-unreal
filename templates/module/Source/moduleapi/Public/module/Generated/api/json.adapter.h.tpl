{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name -}}
#pragma once

#include "apigear.json.adapter.h"
#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}_data.h"
{{- range .Module.Externs }}
{{- $class := ueExtern . }}
{{- if $class.Include }}
#include "{{$class.Include}}"
{{- end }}
{{- end }}

{{- range .Module.Structs }}
{{- $class := printf "F%s%s" $ModuleName .Name }}

static void from_json(const nlohmann::json& j, {{$class}}& p)
{
{{- range .Fields}}
	p.{{.Name}} = j.at("{{.Name}}").get<{{ueReturn "" .}}>();
{{- end }}
}

static void to_json(nlohmann::json& j, const {{$class}}& p)
{
	j = nlohmann::json{
{{- range $idx, $elem := .Fields }}
	{{- if $idx}}, {{ end -}}        
	{"{{.Name}}", p.{{.Name}}}
{{- end -}}
	};
}
{{- end }}

{{- if len .Module.Externs }}

// do the specialization of the adl_serializer for the in the nlohmann namespace
// we do not want to modify the external namespace
namespace nlohmann
{
{{- end }}
{{- range $.Module.Externs }}
{{- $system:= $.System }}
{{- $module:= $.Module }}
{{- $ext := (ueExtern .) }}
{{- $class:= $ext.Name }}

template <>
struct {{$API_MACRO}} adl_serializer<{{if $ext.NameSpace }}{{ $ext.NameSpace }}::{{end}}{{$class}}>
{
	static {{if $ext.NameSpace }}{{ $ext.NameSpace }}::{{end}}{{$class}} from_json(const json& j);

	static void to_json(json& j, {{if $ext.NameSpace }}{{ $ext.NameSpace }}::{{end}}{{$class}} t);
};
{{- nl}}
{{- end }}
{{- if len .Module.Externs }}
} // namespace nlohmann
{{- end }}
