{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name ) -}}
{{- $ModuleName := Camel .Module.Name}}
#pragma once

#include "Generated/api/{{$ModuleName}}_data.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#if (ENGINE_MAJOR_VERSION >= 5)
#if (ENGINE_MINOR_VERSION >= 5)
inline constexpr EAutomationTestFlags {{$ModuleName}}TestFilterMask = EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#else
inline constexpr int {{$ModuleName}}TestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif
#else
constexpr int {{$ModuleName}}TestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif{{nl}}

{{- range .Module.Structs }}
{{- $class := printf "F%s%s" $ModuleName .Name }}
{{$class }} {{$API_MACRO}} createTest{{$class }}();

TArray<{{$class}}> {{$API_MACRO}} createTest{{$class }}Array();
{{ end }}
#endif // WITH_DEV_AUTOMATION_TESTS
