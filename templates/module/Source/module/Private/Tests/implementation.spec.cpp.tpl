{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}

#include "Implementation/{{$Iface}}.h"
#include "{{$ModuleName}}GameInstanceFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS 


BEGIN_DEFINE_SPEC({{$Class}}ImplementationSpec, "{{$ModuleName}}.{{$IfaceName}}.Implementation",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	TUniquePtr<F{{$ModuleName}}GameInstanceFixture> GameInstanceFixture;
	TScriptInterface<I{{$Iface}}Interface> testImplementation;

END_DEFINE_SPEC({{$Class}}ImplementationSpec);

void {{$Class}}ImplementationSpec::Define()
{
	BeforeEach([this]()
	{
		GameInstanceFixture = MakeUnique<F{{$ModuleName}}GameInstanceFixture>();
		TestTrue("Check for valid GameInstanceFixture", GameInstanceFixture.IsValid());
		
		testImplementation = GameInstanceFixture->GetGameInstance()->GetSubsystem<{{ $Class }}>();
		TestTrue("Check for valid testImplementation", testImplementation.GetInterface() != nullptr);
	});

	AfterEach([this]()
	{
		GameInstanceFixture.Reset();
	});
{{- range .Interface.Properties }}

	It("Property.{{ Camel .Name }}", [this]()
	{
		// Do implement test here
	{{- if not .IsReadOnly }}
		testImplementation->Execute_Set{{Camel .Name}}(testImplementation.GetObject(), {{ueDefault "" .}});
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_Get{{Camel .Name}}(testImplementation.GetObject()), {{ueDefault "" .}});
	{{- else }}
		TestEqual(TEXT("Getter should return the default value"), testImplementation->Execute_Get{{Camel .Name}}(testImplementation.GetObject()), {{ueDefault "" .}});
	{{- end }}
	});

{{- end }}

{{- range .Interface.Operations }}

	It("Operation.{{ Camel .Name }}", [this]()
	{
		// Do implement test here
		testImplementation->Execute_{{Camel .Name}}(testImplementation.GetObject()
			{{- range $i, $e := .Params -}}
			, {{ueDefault "" .}}
			{{- end -}}
		);
	});

{{- end }}
}

#endif // WITH_DEV_AUTOMATION_TESTS
