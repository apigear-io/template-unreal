{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
#include "{{$ModuleName}}TestsCommon.h"
#include "Generated/api/{{$ModuleName}}_data.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS
{{- range .Module.Structs }}
{{- $class := printf "F%s%s" $ModuleName .Name }}
{{$class }} createTest{{$class }}()
{
	{{$class }} TestValue;
{{- nl}}
{{- range .Fields }}
	{{- if .IsArray }}
	{{- if and (not .IsPrimitive) (not (eq .KindType "enum")) }}
	{{- $type := printf "F%s%s" $ModuleName (Camel .Type) }}
	TestValue.{{.Name}} = createTest{{$type}}Array();
	{{- else }}
	TestValue.{{.Name}}.Add({{ ueTestValue "" . }});
	{{- end }}
	{{- else if and (not .IsPrimitive) (not (eq .KindType "enum"))}}
	TestValue.{{.Name}} = createTest{{ueType "" .}}();
	{{- else }}
	TestValue.{{.Name}} = {{ ueTestValue "" . }};
	{{- end }}
{{- end }}

	return TestValue;
}

TArray<{{$class}}> createTest{{$class }}Array()
{
	TArray<{{$class}}> TestValueArray;
{{- nl}}
	TestValueArray.Add(createTest{{$class }}());

	return TestValueArray;
}
{{ end }}
#endif // WITH_DEV_AUTOMATION_TESTS
