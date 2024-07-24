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

	It("Property.{{ Camel .Name }}", [this]()
	{
		// Do implement test here
	{{- if not .IsReadOnly }}
		ImplFixture->GetImplementation()->Execute_Set{{Camel .Name}}(ImplFixture->GetImplementation().GetObject(), {{ueDefault "" .}});
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_Get{{Camel .Name}}(ImplFixture->GetImplementation().GetObject()), {{ueDefault "" .}});
	{{- else }}
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_Get{{Camel .Name}}(ImplFixture->GetImplementation().GetObject()), {{ueDefault "" .}});
	{{- end }}
	});

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
		{{- $type := printf "F%s%s" $ModuleName .Type }}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = createTest{{ $type }}Array();
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

{{- range .Interface.Signals }}

void {{$Class}}ImplSpec::{{ Camel .Name }}SignalCb({{ueParams "In" .Params}})
{
	// known test value
	{{- range $i, $e := .Params -}}
	{{- if .IsArray }}
	{{- $type := printf "F%s%s" $ModuleName .Type }}
	{{ ueType "" . }} {{ueVar "" .}}TestValue = createTest{{ $type }}Array();
	{{- else if and (not .IsPrimitive) (not (eq .KindType "enum"))}}
	{{ ueType "" . }} {{ueVar "" .}}TestValue = createTest{{ ueType "" . }}();
	{{- else }}
	{{ ueType "" . }} {{ueVar "" .}}TestValue = {{ ueTestValue "" . }};
	{{- end }}
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), {{ueVar "In" .}}, {{ueVar "" .}}TestValue);
	{{- end }}
	testDoneDelegate.Execute();
}
{{- end }}
#endif // WITH_DEV_AUTOMATION_TESTS
