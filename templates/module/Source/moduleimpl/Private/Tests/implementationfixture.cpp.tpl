{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
#include "{{$DisplayName}}ImplFixture.h"
#include "{{$ModuleName}}/Implementation/{{$DisplayName}}.h"
#include "{{$ModuleName}}/Tests/{{$ModuleName}}TestsCommon.h"
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Tests/{{Camel .Name}}TestsCommon.h"
{{- end }}
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void {{$Class}}ImplHelper::SetParentFixture(TWeakPtr<F{{ $DisplayName }}ImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void {{$Class}}ImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void {{$Class}}ImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}

void {{$Class}}ImplHelper::{{ Camel .Name }}PropertyCb({{ueParam "In" .}})
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
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), {{ueVar "In" .}}, TestValue);
	if (TSharedPtr<F{{ $DisplayName }}ImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Get{{Camel .Name}}(), TestValue);
	}
	testDoneDelegate.Execute();
}
{{- end }}
{{- end }}

{{- range .Interface.Signals }}

void {{$Class}}ImplHelper::{{ Camel .Name }}SignalCb({{ueParams "In" .Params}})
{
	// known test value
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
	{{ueType "" .}} {{ueVar "" .}}TestValue = createTest{{ $type }}Array();
	{{- end }}
	{{- else if and (not .IsPrimitive) (not (eq .KindType "enum")) (not (eq .KindType "interface"))}}
	{{ueType "" .}} {{ueVar "" .}}TestValue = createTest{{ ueType "" . }}();
	{{- else }}
	{{ueType "" .}} {{ueVar "" .}}TestValue = {{ ueTestValue "" . }};
	{{- end }}
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), {{ueVar "In" .}}, {{ueVar "" .}}TestValue);
	{{- end }}
	{{- end }}
	testDoneDelegate.Execute();
}
{{- end }}

F{{ $DisplayName }}ImplFixture::F{{ $DisplayName }}ImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<{{ $Class }}Implementation>();
	Helper = NewObject<{{$Class}}ImplHelper>();
}

F{{ $DisplayName }}ImplFixture::~F{{ $DisplayName }}ImplFixture()
{
	CleanUp();
}

TScriptInterface<I{{$DisplayName}}Interface> F{{ $DisplayName }}ImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<{{$Class}}ImplHelper> F{{ $DisplayName }}ImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* F{{ $DisplayName }}ImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>(GetTransientPackage());
		GameInstance->Init();
		// needed to prevent garbage collection and we can't use UPROPERTY on raw c++ objects
		GameInstance->AddToRoot();
	}

	return GameInstance.Get();
}

void F{{ $DisplayName }}ImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void {{$Class}}ImplHelper::SetParentFixture(TWeakPtr<F{{ $DisplayName }}ImplFixture> /*InFixture*/)
{
}

void {{$Class}}ImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void {{$Class}}ImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}

void {{$Class}}ImplHelper::{{ Camel .Name }}PropertyCb({{ueParam "" .}})
{
	(void){{ueVar "" .}};
}
{{- end }}
{{- end }}

{{- range .Interface.Signals }}

void {{$Class}}ImplHelper::{{ Camel .Name }}SignalCb({{ueParams "" .Params}})
{
	{{- range $i, $e := .Params }}
	(void){{ueVar "" .}};
	{{- end }}
}
{{- end }}
#endif // WITH_DEV_AUTOMATION_TESTS
