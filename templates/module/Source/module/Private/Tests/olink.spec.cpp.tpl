{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}

#include "{{$DisplayName}}OLink.spec.h"
#include "Implementation/{{$Iface}}.h"
#include "{{$DisplayName}}OLinkFixture.h"
#include "Generated/OLink/{{$DisplayName}}OLinkClient.h"
#include "Generated/OLink/{{$DisplayName}}OLinkAdapter.h"
#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Private/Tests/{{Camel .Name}}TestsCommon.h"
{{- end }}
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void {{$Class}}OLinkSpec::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	// ImplFixture->testDoneDelegate.Execute();
	// InTestDoneDelegate.Execute();
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

void {{$Class}}OLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<F{{$DisplayName}}OLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<U{{$DisplayName}}>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		testDoneDelegate = TestDone;
		U{{$DisplayName}}OLinkClient* OLinkClient = Cast<U{{$DisplayName}}OLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &U{{$DisplayName}}OLinkHelper::_SubscriptionStatusChangedCb);

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

		testDoneDelegate = TestDone;
		{{$Class}}Signals* {{$Iface}}Signals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		{{$Iface}}Signals->On{{Camel .Name}}Changed.AddDynamic(ImplFixture->GetHelper().Get(), &{{$Class}}OLinkHelper::{{ Camel .Name }}PropertyCb);
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
			ImplFixture->GetImplementation()->Execute_{{Camel .Name}}(ImplFixture->GetImplementation().GetObject()
				{{- range $i, $e := .Params -}}
				, {{ueDefault "" .}}
				{{- end -}}
			);
			TestDone.Execute();
		});
	});
{{- end }}

{{- range .Interface.Signals }}

	LatentIt("Signal.{{ Camel .Name }}", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		{{$Class}}Signals* {{$Iface}}Signals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		{{$Iface}}Signals->On{{Camel .Name}}Signal.AddDynamic(ImplFixture->GetHelper().Get(), &{{$Class}}OLinkHelper::{{ Camel .Name }}SignalCb);

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

{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}
{{- $type := printf "F%s%s" $ModuleName .Type }}

void {{$Class}}OLinkSpec::{{ Camel .Name }}PropertyCb({{ueParam "In" .}})
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

void {{$Class}}OLinkSpec::{{ Camel .Name }}SignalCb({{ueParams "In" .Params}})
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
	testDoneDelegate.Execute();
}
{{- end }}
#endif // WITH_DEV_AUTOMATION_TESTS
