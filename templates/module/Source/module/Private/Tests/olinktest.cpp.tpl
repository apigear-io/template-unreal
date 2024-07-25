{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}

#include "OLink/{{$Iface}}.h"
#include "{{$ModuleName}}TestBase.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS 

{{- range .Interface.Properties }}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST({{$Class}}OLinkProperty{{ Camel .Name }}Test, F{{ $ModuleName }}TestBase, "{{$ModuleName}}.{{$IfaceName}}.OLink.Property.{{ Camel .Name }}", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool {{$Class}}OLinkProperty{{ Camel .Name }}Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<I{{$Iface}}Interface> test = GetGameInstance()->GetSubsystem<{{ $Class }}>();
{{- if not .IsReadOnly }}
	test->Execute_Set{{Camel .Name}}(test.GetObject(), {{ueDefault "" .}});
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_Get{{Camel .Name}}(test.GetObject()), {{ueDefault "" .}});
{{- else }}
	TestEqual(TEXT("Getter should return the default value"), test->Execute_Get{{Camel .Name}}(test.GetObject()), {{ueDefault "" .}});
{{- end }}

	CleanUp();
	return true;
}
{{- end }}
{{- range .Interface.Operations }}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST({{$Class}}OLinkOperation{{ Camel .Name }}Test, F{{ $ModuleName }}TestBase, "{{$ModuleName}}.{{$IfaceName}}.OLink.Operation.{{ Camel .Name }}", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool {{$Class}}OLinkOperation{{ Camel .Name }}Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<I{{$Iface}}Interface> test = GetGameInstance()->GetSubsystem<{{ $Class }}>();
	test->Execute_{{Camel .Name}}(test.GetObject()
		{{- range $i, $e := .Params -}}
		, {{ueDefault "" .}}
		{{- end -}}
	);

	CleanUp();
	return true;
}
{{- end }}

#endif // WITH_DEV_AUTOMATION_TESTS
