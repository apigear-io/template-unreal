{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}

#include "Implementation/{{$Iface}}.h"
#include "{{$DisplayName}}ImplFixture.h"
#include "{{$ModuleName}}TestsCommon.h"
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Private/Tests/{{Camel .Name}}TestsCommon.h"
{{- end }}
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC({{$Class}}ImplSpec, "{{$ModuleName}}.{{$IfaceName}}.Impl", {{$ModuleName}}TestFilterMask);

TSharedPtr<F{{$DisplayName}}ImplFixture> ImplFixture;

END_DEFINE_SPEC({{$Class}}ImplSpec);

void {{$Class}}ImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<F{{$DisplayName}}ImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
		ImplFixture->GetHelper()->SetParentFixture(ImplFixture);
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});
{{- range .Interface.Properties }}

	It("Property.{{ Camel .Name }}.Default", [this]()
		{
		// Do implement test here
		{{ueType "" .}} TestValue = {{ueDefault "" .}}; // default value
	{{- if not .IsReadOnly }}
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_Get{{Camel .Name}}(ImplFixture->GetImplementation().GetObject()), TestValue);
	{{- else }}
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_Get{{Camel .Name}}(ImplFixture->GetImplementation().GetObject()), {{ueDefault "" .}});
	{{- end }}
	});

	{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}

	LatentIt("Property.{{ Camel .Name }}.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		{{ueType "" .}} TestValue = {{ueDefault "" .}}; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_Get{{Camel .Name}}(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		{{$Class}}Signals* {{$Iface}}Signals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		{{$Iface}}Signals->On{{Camel .Name}}Changed.AddDynamic(ImplFixture->GetHelper().Get(), &{{$Class}}ImplHelper::{{ Camel .Name }}PropertyCb);
		// use different test value
		{{- if .IsArray }}
		{{- if or .IsPrimitive (eq .KindType "enum") }}
		TestValue.Add({{ ueTestValue "" .}});
		{{- else }}
		{{- $type := ""}}
		{{- if not (eq .Import "") }}
		{{- $type = printf "F%s%s" (Camel .Import) .Type }}
		{{- else }}
		{{- $type = printf "F%s%s" $ModuleName .Type }}
		{{- end }}
		TestValue = createTest{{ $type }}Array();
		{{- end }}
		{{- else if and (not .IsPrimitive) (not (eq .KindType "enum"))}}
		TestValue = createTest{{ ueType "" . }}();
		{{- else }}
		TestValue = {{ ueTestValue "" . }};
		{{- end }}
		ImplFixture->GetImplementation()->Execute_Set{{Camel .Name}}(ImplFixture->GetImplementation().GetObject(), TestValue);
	});
	{{- end }}

{{- end }}

{{- range .Interface.Operations }}

	It("Operation.{{ Camel .Name }}", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_{{Camel .Name}}(ImplFixture->GetImplementation().GetObject()
			{{- range $i, $e := .Params -}}
			, {{ueDefault "" .}}
			{{- end -}}
		);
	});

{{- end }}

{{- range .Interface.Signals }}

	LatentIt("Signal.{{ Camel .Name }}", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		{{$Class}}Signals* {{$Iface}}Signals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		{{$Iface}}Signals->On{{Camel .Name}}Signal.AddDynamic(ImplFixture->GetHelper().Get(), &{{$Class}}ImplHelper::{{ Camel .Name }}SignalCb);

		// use different test value
		{{- range $i, $e := .Params -}}
		{{- if not (eq .KindType "extern") }}
		{{- if .IsArray }}
		{{- if or .IsPrimitive (eq .KindType "enum") }}
		{{ueType "" .}} {{ueVar "" .}}TestValue = {{ueDefault "" .}}; // default value
		{{ueVar "" .}}TestValue.Add({{ ueTestValue "" .}});
		{{- else }}
		{{- $type := ""}}
		{{- if not (eq .Import "") }}
		{{- $type = printf "F%s%s" (Camel .Import) .Type }}
		{{- else }}
		{{- $type = printf "F%s%s" $ModuleName .Type }}
		{{- end }}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = createTest{{ $type }}Array();
		{{- end }}
		{{- else if and (not .IsPrimitive) (not (eq .KindType "enum"))}}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = createTest{{ ueType "" . }}();
		{{- else }}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = {{ ueTestValue "" . }};
		{{- end }}
		{{- else }}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = {{ ueDefault "" . }};
		{{- end }}
		{{- end }}
		{{$Iface}}Signals->Broadcast{{Camel .Name}}Signal(
			{{- range $i, $e := .Params -}}
			{{- if $i }}, {{ end }}{{ueVar "" .}}TestValue
			{{- end -}});
	});

{{- end }}
}

#endif // WITH_DEV_AUTOMATION_TESTS
