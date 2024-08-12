{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}

#include "{{$DisplayName}}Impl.spec.h"
#include "Implementation/{{$Iface}}.h"
#include "{{$DisplayName}}ImplFixture.h"
#include "{{$ModuleName}}TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void {{$Class}}ImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeUnique<F{{$DisplayName}}ImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
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

	{{- if not .IsReadOnly }}

	LatentIt("Property.{{ Camel .Name }}.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		{{ueType "" .}} TestValue = {{ueDefault "" .}}; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_Get{{Camel .Name}}(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		{{$Class}}Signals* {{$Iface}}Signals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		{{$Iface}}Signals->On{{Camel .Name}}Changed.AddDynamic(ImplFixture->GetHelper().Get(), &{{$Class}}ImplHelper::{{ Camel .Name }}PropertyCb);
		// use different test value
		{{- if .IsArray }}
		{{- if .IsPrimitive }}
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
		testDoneDelegate = TestDone;
		{{$Class}}Signals* {{$Iface}}Signals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		{{$Iface}}Signals->On{{Camel .Name}}Signal.AddDynamic(ImplFixture->GetHelper().Get(), &{{$Class}}ImplHelper::{{ Camel .Name }}SignalCb);

		// use different test value
		{{- range $i, $e := .Params -}}
		{{- if .IsArray }}
		{{- if .IsPrimitive }}
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
		{{- end }}
		{{$Iface}}Signals->Broadcast{{Camel .Name}}Signal(
			{{- range $i, $e := .Params -}}
			{{- if $i }}, {{ end }}{{ueVar "" .}}TestValue
			{{- end -}});
	});

{{- end }}
}

{{- range .Interface.Properties }}
{{- if not .IsReadOnly }}
{{- $type := printf "F%s%s" $ModuleName .Type }}

void {{$Class}}ImplSpec::{{ Camel .Name }}PropertyCb({{ueParam "In" .}})
{
	{{ueType "" .}} TestValue = {{ueDefault "" .}};
	// use different test value
	{{- if .IsArray }}
	{{- if .IsPrimitive }}
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
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), {{ueVar "In" .}}, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_Get{{Camel .Name}}(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}
{{- end }}
{{- end }}

{{- range .Interface.Signals }}

void {{$Class}}ImplSpec::{{ Camel .Name }}SignalCb({{ueParams "In" .Params}})
{
	// known test value
	{{- range $i, $e := .Params -}}
	{{- if .IsArray }}
	{{- if .IsPrimitive }}
	{{ueType "" .}} {{ueVar "" .}}TestValue = {{ueDefault "" .}}; // default value
	{{ueVar "" .}}TestValue.Add({{ ueTestValue "" .}});
	{{- else }}
	{{- $type := ""}}
	{{- if not (eq .Import "") }}
	{{- $type = printf "F%s%s" (Camel .Import) .Type }}
	{{- else }}
	{{- $type = printf "F%s%s" $ModuleName .Type }}
	{{- end }}
	{{ueType "" .}} {{ueVar "" .}}TestValue = createTest{{ $type }}Array();
	{{- end }}
	{{- else if and (not .IsPrimitive) (not (eq .KindType "enum"))}}
	{{ueType "" .}} {{ueVar "" .}}TestValue = createTest{{ ueType "" . }}();
	{{- else }}
	{{ueType "" .}} {{ueVar "" .}}TestValue = {{ ueTestValue "" . }};
	{{- end }}
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), {{ueVar "In" .}}, {{ueVar "" .}}TestValue);
	{{- end }}
	testDoneDelegate.Execute();
}
{{- end }}
#endif // WITH_DEV_AUTOMATION_TESTS
