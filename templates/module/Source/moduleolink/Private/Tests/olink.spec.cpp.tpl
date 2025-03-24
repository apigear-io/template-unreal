{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}

#include "OLinkCommon.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "{{$DisplayName}}OLinkFixture.h"
#include "{{$ModuleName}}/Implementation/{{$DisplayName}}.h"
#include "{{$ModuleName}}/Generated/OLink/{{$DisplayName}}OLinkClient.h"
#include "{{$ModuleName}}/Generated/OLink/{{$DisplayName}}OLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "{{$ModuleName}}/Tests/{{$ModuleName}}TestsCommon.h"
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Tests/{{Camel .Name}}TestsCommon.h"
{{- end }}
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace {{$ModuleName}}
{
namespace {{$IfaceName}}
{
namespace OLink
{
namespace Tests
{
BEGIN_DEFINE_SPEC({{$Class}}OLinkSpec, "{{$ModuleName}}.{{$IfaceName}}.OLink", {{$ModuleName}}TestFilterMask);

TUniquePtr<F{{$DisplayName}}OLinkFixture> ImplFixture;

END_DEFINE_SPEC({{$Class}}OLinkSpec);

void {{$Class}}OLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<F{{$DisplayName}}OLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<U{{$DisplayName}}>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		U{{$DisplayName}}OLinkClient* OLinkClient = Cast<U{{$DisplayName}}OLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddLambda([this, TestDone](bool bSubscribed)
			{
			if (bSubscribed)
			{
				TestDone.Execute();
			}
		});

		ImplFixture->Connection = OLinkFactory::Create(OLinkClient, "TestingConnection");
		ImplFixture->Connection->Configure("ws://127.0.0.1:8666/ws", false);

		OLinkClient->UseConnection(ImplFixture->Connection);
		ImplFixture->Connection->Connect();
	});

	AfterEach([this]()
		{
		ImplFixture->Connection->Disconnect();
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
} // namespace OLink
} // namespace {{$IfaceName}}
} // namespace {{$ModuleName}}

#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
