{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
#pragma once

#include "Generated/api/{{$ModuleName}}_data.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS 

{{- range .Module.Structs }}
{{- $class := printf "F%s%s" $ModuleName .Name }}
{{$class }} createTest{{$class }}();

TArray<{{$class}}> createTest{{$class }}Array();
{{ end }}
#endif // WITH_DEV_AUTOMATION_TESTS
