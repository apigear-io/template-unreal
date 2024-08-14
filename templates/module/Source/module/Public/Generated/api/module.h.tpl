{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name ) -}}
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

{{- $ModuleName := Camel .Module.Name}}
{{- if len .Module.Interfaces }}{{nl}}{{end}}
{{- range .Module.Interfaces }}
{{- $Class := printf "%s%s" $ModuleName (Camel .Name) }}
{{- $class := printf "%sInterface" $Class }}
#include "{{$class}}.h"
{{- end }}
