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
#include "{{$DisplayName}}JniFixture.h"
#include "{{$ModuleName}}/Generated/Jni/{{$DisplayName}}JniClient.h"
#include "{{$ModuleName}}/Generated/Jni/{{$DisplayName}}JniAdapter.h"
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Tests/{{Camel .Name}}TestsCommon.h"
{{- end }}


#if PLATFORM_ANDROID

#include "Engine/Engine.h"
 #include "Android/AndroidJNI.h"
 #include "Android/AndroidApplication.h"

 #if USE_ANDROID_JNI
 #include <jni.h>
 #endif
#endif

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace {{$ModuleName}}
{
namespace {{$IfaceName}}
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC({{$Class}}JniSpec, "{{$ModuleName}}.{{$IfaceName}}.Jni", {{$ModuleName}}TestFilterMask);

TUniquePtr<F{{$DisplayName}}JniFixture> ImplFixture;

END_DEFINE_SPEC({{$Class}}JniSpec);

void {{$Class}}JniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<F{{$DisplayName}}JniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service =ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		U{{$DisplayName}}JniClient* JniClient = ImplFixture->GetClient();
		TestTrue("Check for valid Jni client", JniClient != nullptr);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		JniClient->_ConnectionStatusChanged.AddLambda([this, TestDone](bool bConnected)
			{
			if (bConnected)
			{
				TestDone.Execute();
			}
		});
		//Test packge name should start with name of the  pacakge declared by the test application in e.g. defaultEngine.ini in [/Script/AndroidRuntimeSettings.AndroidRuntimeSettings] section.
		{{- $projectName := .System.Name }}
		{{- $service_package_name := printf "com.%s" (camel $projectName) }} 
		FString servicePackage = "{{$service_package_name}}";
		JniClient->_bindToService(servicePackage, "TestConnectionId");
		#else
		TestDone.Execute();
		#endif
	});

	AfterEach([this]()
		{
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			U{{$DisplayName}}JniClient* JniClient =ImplFixture->GetClient();
			#endif
			ImplFixture.Reset();
	});
{{- range .Interface.Properties }}

	It("Property.{{ Camel .Name }}.Default", [this]()
		{
		// Do implement test here
		{{ueType "" .}} TestValue = {{ueDefault "" .}}; // default value
	{{- if not .IsReadOnly }}
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->Get{{Camel .Name}}(), TestValue);
	{{- else }}
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->Get{{Camel .Name}}(), {{ueDefault "" .}});
	{{- end }}
	});

	{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) (not (eq .KindType "interface"))}}

	LatentIt("Property.{{ Camel .Name }}.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		{{ueType "" .}} TestValue = {{ueDefault "" .}}; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->Get{{Camel .Name}}(), TestValue);

		{{$Class}}Publisher* {{$Iface}}Publisher = ImplFixture->GetClient()->_GetPublisher();
		{{$Iface}}Publisher->On{{Camel .Name}}Changed.AddLambda([this, TestDone]({{ueParam "In" .}})
			{
			{{ueType "" .}} TestValue = {{ueDefault "" .}};
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
			{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
			TestValue = createTest{{ ueType "" . }}();
			{{- else }}
			TestValue = {{ ueTestValue "" . }};
			{{- end }}
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), {{ueVar "In" .}}, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->Get{{Camel .Name}}(), TestValue);
			TestDone.Execute();
		});

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
		{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
		TestValue = createTest{{ ueType "" . }}();
		{{- else }}
		TestValue = {{ ueTestValue "" . }};
		{{- end }}
		ImplFixture->GetClient()->Set{{Camel .Name}}(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.{{ Camel .Name }}.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		{{ueType "" .}} DefaultValue = {{ueDefault "" .}}; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->Get{{Camel .Name}}(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{{$Class}}Publisher* {{$Iface}}Publisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		{{$Class}}Publisher* {{$Iface}}Publisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		{{$Iface}}Publisher->On{{Camel .Name}}Changed.AddLambda([this, DefaultValue, TestDone]({{ueParam "In" .}})
			{
			{{ueType "" .}} TestValue = {{ueDefault "" .}};
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
			{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
			TestValue = createTest{{ ueType "" . }}();
			{{- else }}
			TestValue = {{ ueTestValue "" . }};
			{{- end }}
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), {{ueVar "In" .}}, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->Get{{Camel .Name}}(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->Get{{Camel .Name}}(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->Get{{Camel .Name}}(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		{{ueType "" .}} TestValue = DefaultValue;
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
		{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
		TestValue = createTest{{ ueType "" . }}();
		{{- else }}
		TestValue = {{ ueTestValue "" . }};
		{{- end }}
		auto service = ImplFixture->GetLocalImplementation();
		service->Set{{Camel .Name}}(TestValue);
	});

	LatentIt("Property.{{ Camel .Name }}.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		{{ueType "" .}} StartValue =  ImplFixture->GetLocalImplementation()->Get{{Camel .Name}}();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->Get{{Camel .Name}}(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{{$Class}}Publisher* {{$Iface}}Publisher = ImplFixture->GetClient()->_GetPublisher();
		{{$Iface}}Publisher->On{{Camel .Name}}Changed.AddLambda([this, TestDone]({{ueParam "In" .}})
		#else
		{{$Class}}Publisher* {{$Iface}}Publisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		{{$Iface}}Publisher->On{{Camel .Name}}Changed.AddLambda([this, TestDone, StartValue]({{ueParam "In" .}})
		#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				{{ueType "" .}} TestValue = {{ueDefault "" .}};
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
				{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
				TestValue = createTest{{ ueType "" . }}();
				{{- else }}
				TestValue = {{ ueTestValue "" . }};
				{{- end }}
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), {{ueVar "In" .}}, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->Get{{Camel .Name}}(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->Get{{Camel .Name}}(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->Get{{Camel .Name}}(), StartValue);
				#endif
				// now set it to the default value
				TestValue = {{ueDefault "" .}}; // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->Set{{Camel .Name}}(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->Set{{Camel .Name}}(TestValue);
				#endif
			}
			else
			{
				{{ueType "" .}} TestValue = {{ueDefault "" .}}; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), {{ueVar "In" .}}, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->Get{{Camel .Name}}(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->Get{{Camel .Name}}(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		{{ueType "" .}} TestValue = StartValue;
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
		{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
		TestValue = createTest{{ ueType "" . }}();
		{{- else }}
		TestValue = {{ ueTestValue "" . }};
		{{- end }}
		auto service = ImplFixture->GetLocalImplementation();
		service->Set{{Camel .Name}}(TestValue);
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
			ImplFixture->GetClient()->{{Camel .Name}}(
				{{- range $i, $e := .Params -}}
				{{ if $i }}, {{end}}{{ueDefault "" .}}
				{{- end -}}
			);
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});
{{- end }}

{{- range .Interface.Signals }}

	LatentIt("Signal.{{ Camel .Name }}", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		{{$Class}}Publisher* Source{{$Iface}}Publisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{{$Class}}Publisher* {{$Iface}}Publisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		{{$Class}}Publisher* {{$Iface}}Publisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		{{$Iface}}Publisher->On{{Camel .Name}}Signal.AddLambda([this, TestDone]({{ueParams "In" .Params}})
			{
			// known test value
			{{- range $i, $e := .Params -}}
			{{- if not (eq .KindType "extern") }}
			{{- if .IsArray }}
			{{- if or .IsPrimitive (eq .KindType "enum") (eq .KindType "interface") }}
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
			{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
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
		{{- if or .IsPrimitive (eq .KindType "enum") (eq .KindType "interface") }}
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
		{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = createTest{{ ueType "" . }}();
		{{- else }}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = {{ ueTestValue "" . }};
		{{- end }}
		{{- else }}
		{{ ueType "" . }} {{ueVar "" .}}TestValue = {{ ueDefault "" . }};
		{{- end }}
		{{- end }}
		Source{{$Iface}}Publisher->Broadcast{{Camel .Name}}Signal(
			{{- range $i, $e := .Params -}}
			{{- if $i }}, {{ end }}{{ueVar "" .}}TestValue
			{{- end -}});
	});

{{- end }}
}
} // namespace Tests
} // namespace Jni
} // namespace {{$IfaceName}}
} // namespace {{$ModuleName}}

#endif // WITH_DEV_AUTOMATION_TESTS
