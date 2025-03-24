{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "{{$ModuleName}}/Tests/{{$ModuleName}}TestsCommon.h"
#include "{{$ModuleName}}/Implementation/{{$Iface}}.h"
#include "{{$DisplayName}}MsgBusFixture.h"
#include "{{$ModuleName}}/Generated/MsgBus/{{$DisplayName}}MsgBusClient.h"
#include "{{$ModuleName}}/Generated/MsgBus/{{$DisplayName}}MsgBusAdapter.h"
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Tests/{{Camel .Name}}TestsCommon.h"
{{- end }}

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace {{$ModuleName}}
{
namespace {{$IfaceName}}
{
namespace MsgBus
{
namespace Tests
{
BEGIN_DEFINE_SPEC({{$Class}}MsgBusSpec, "{{$ModuleName}}.{{$IfaceName}}.MsgBus", {{$ModuleName}}TestFilterMask);

TUniquePtr<F{{$DisplayName}}MsgBusFixture> ImplFixture;

END_DEFINE_SPEC({{$Class}}MsgBusSpec);

void {{$Class}}MsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<F{{$DisplayName}}MsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<U{{$DisplayName}}>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		U{{$DisplayName}}MsgBusClient* MsgBusClient = Cast<U{{$DisplayName}}MsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddLambda([this, TestDone](bool bConnected)
			{
			if (bConnected)
			{
				TestDone.Execute();
			}
		});

		MsgBusClient->_Connect();
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
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Get{{Camel .Name}}(), TestValue);
	{{- else }}
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Get{{Camel .Name}}(), {{ueDefault "" .}});
	{{- end }}
	});

	{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}

	LatentIt("Property.{{ Camel .Name }}.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		{{ueType "" .}} TestValue = {{ueDefault "" .}}; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Get{{Camel .Name}}(), TestValue);

		{{$Class}}Signals* {{$Iface}}Signals = ImplFixture->GetImplementation()->_GetSignals();
		{{$Iface}}Signals->On{{Camel .Name}}Changed.AddLambda([this, TestDone]({{ueParam "In" .}})
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
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Get{{Camel .Name}}(), TestValue);
			TestDone.Execute();
		});

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
		ImplFixture->GetImplementation()->Set{{Camel .Name}}(TestValue);
	});
	{{- end }}

{{- end }}

{{- range .Interface.Operations }}
{{- nl }}
	{{- if (eq .Return.KindType "extern")}}
	// Please implement serialization for {{ueType "" .Return}} before enabling the test.
	{{- end }}
	{{if (eq .Return.KindType "extern")}}x{{end}}LatentIt("Operation.{{ Camel .Name }}", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		{{- range $i, $e := .Params }}
		{{- if (eq .KindType "extern")}}
		// Please implement serialization for {{ueType "" .}} before testing.
		{{- end }}
		{{- end }}
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->{{Camel .Name}}(
				{{- range $i, $e := .Params -}}
				{{ if $i }}, {{end}}{{ueDefault "" .}}
				{{- end -}}
			);
			TestDone.Execute();
		});
	});
{{- end }}

{{- range .Interface.Signals }}

	LatentIt("Signal.{{ Camel .Name }}", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		{{$Class}}Signals* {{$Iface}}Signals = ImplFixture->GetImplementation()->_GetSignals();
		{{$Iface}}Signals->On{{Camel .Name}}Signal.AddLambda([this, TestDone]({{ueParams "In" .Params}})
			{
			// known test value
			{{- range $i, $e := .Params -}}
			{{- if not (eq .KindType "extern") }}
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
			{{- end }}
			TestDone.Execute();
		});

		// use different test value
		{{- range $i, $e := .Params -}}
		{{- if not (eq .KindType "extern") }}
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
} // namespace Tests
} // namespace MsgBus
} // namespace {{$IfaceName}}
} // namespace {{$ModuleName}}

#endif // WITH_DEV_AUTOMATION_TESTS
