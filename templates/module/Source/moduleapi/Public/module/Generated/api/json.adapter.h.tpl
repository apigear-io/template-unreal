{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name -}}
#pragma once

#include "apigear.json.adapter.h"
#include "{{$ModuleName}}/Generated/{{$ModuleName}}LogCategories.h"
#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}_data.h"
{{- range .Module.Interfaces }}
#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}{{Camel .Name}}Interface.h"
{{- end }}
{{- range .Module.Imports }}
{{- $ImportModuleName := Camel .Name }}
#include "{{$ImportModuleName}}/Generated/api/{{$ImportModuleName}}.json.adapter.h"
{{- end }}
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
{{- range $idx, $elem := .Fields}}
	{{- if $idx}}{{nl}}{{ end }}
	const auto {{.Name}}Iter = j.find("{{.Name}}");
	if ({{.Name}}Iter != j.end() && !{{.Name}}Iter->is_null(){{ " " }}
	{{- if .IsArray -}}
		&& {{.Name}}Iter->is_array()
	{{- else if eq .KindType "enum" -}}
		&& {{.Name}}Iter->is_number_integer()
	{{- else if .IsPrimitive -}}
		{{- if eq .Type "bool" -}}
		&& {{.Name}}Iter->is_boolean()
		{{- else if or (eq .Type "int") (eq .Type "int32") (eq .Type "int64") -}}
		&& {{.Name}}Iter->is_number_integer()
		{{- else if or (eq .Type "float") (eq .Type "float32") (eq .Type "float64") -}}
		&& {{.Name}}Iter->is_number()
		{{- else if eq .Type "string" -}}
		&& {{.Name}}Iter->is_string()
		{{- end }}
	{{- else -}}
		&& {{.Name}}Iter->is_object()
	{{- end }})
	{
		p.{{.Name}} = {{.Name}}Iter->get<{{ueReturn "" .}}>();
	}
	else
	{
		UE_LOG(Log{{$ModuleName}}, Error, TEXT("from_json: struct field '{{.Name}}' missing or type mismatch in {{$class}} -> using default value"));
	}
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

{{- range .Module.Interfaces }}
{{- $class := printf "I%s%sInterface" $ModuleName (Camel .Name) }}

static void from_json(const nlohmann::json& j, TScriptInterface<{{$class}}>& p)
{
	if (!p)
	{
		return;
	}

{{- if len .Properties}}{{nl}}{{- end}}
{{- range $idx, $elem := .Properties}}
{{- if not .IsReadOnly }}
	{{- if $idx}}{{nl}}{{ end }}
	const auto {{.Name}}Iter = j.find("{{.Name}}");
	if ({{.Name}}Iter != j.end() && !{{.Name}}Iter->is_null(){{ " " }}
	{{- if .IsArray -}}
		&& {{.Name}}Iter->is_array()
	{{- else if eq .KindType "enum" -}}
		&& {{.Name}}Iter->is_number_integer()
	{{- else if .IsPrimitive -}}
		{{- if eq .Type "bool" -}}
		&& {{.Name}}Iter->is_boolean()
		{{- else if or (eq .Type "int") (eq .Type "int32") (eq .Type "int64") -}}
		&& {{.Name}}Iter->is_number_integer()
		{{- else if or (eq .Type "float") (eq .Type "float32") (eq .Type "float64") -}}
		&& {{.Name}}Iter->is_number()
		{{- else if eq .Type "string" -}}
		&& {{.Name}}Iter->is_string()
		{{- end }}
	{{- else -}}
		&& {{.Name}}Iter->is_object()
	{{- end }})
	{
		Cast<{{$class}}>(p.GetObject())->Set{{Camel .Name}}({{.Name}}Iter->get<{{ueType "" .}}>());
	}
	else
	{
		UE_LOG(Log{{$ModuleName}}, Error, TEXT("from_json: interface property '{{.Name}}' missing or type mismatch in {{$class}} -> ignore"));
	}
{{- end }}
{{- end }}
}

static void to_json(nlohmann::json& j, const TScriptInterface<{{$class}}>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{
{{- range $idx, $elem := .Properties }}
{{- if not .IsReadOnly }}
	{{- if $idx}}, {{ end -}}
	{"{{.Name}}", Cast<{{$class}}>(p.GetObject())->Get{{Camel .Name}}()}
{{- end }}
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
