{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name -}}
#pragma once

#include "apigear.json.adapter.h"

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
