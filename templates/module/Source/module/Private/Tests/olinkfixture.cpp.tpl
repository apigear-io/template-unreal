{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
#include "{{$DisplayName}}OLinkFixture.h"
#include "{{$ModuleName}}TestsCommon.h"
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Private/Tests/{{Camel .Name}}TestsCommon.h"
{{- end }}
#include "OLinkCommon.h"
#include "Generated/OLink/{{$DisplayName}}OLinkClient.h"
#include "Generated/OLink/{{$DisplayName}}OLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void {{$Class}}OLinkHelper::SetParentFixture(TWeakPtr<F{{ $DisplayName }}OLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void {{$Class}}OLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void {{$Class}}OLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}

void {{$Class}}OLinkHelper::{{ Camel .Name }}PropertyCb({{ueParam "In" .}})
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
	{{- else if and (not .IsPrimitive) (not (eq .KindType "enum"))}}
	TestValue = createTest{{ ueType "" . }}();
	{{- else }}
	TestValue = {{ ueTestValue "" . }};
	{{- end }}
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), {{ueVar "In" .}}, TestValue);
	if (TSharedPtr<F{{ $DisplayName }}OLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_Get{{Camel .Name}}(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void {{$Class}}OLinkHelper::{{ Camel .Name }}PropertyChangeLocalCheckRemoteCb({{ueParam "In" .}})
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
	{{- else if and (not .IsPrimitive) (not (eq .KindType "enum"))}}
	TestValue = createTest{{ ueType "" . }}();
	{{- else }}
	TestValue = {{ ueTestValue "" . }};
	{{- end }}
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), {{ueVar "In" .}}, TestValue);
	if (TSharedPtr<F{{ $DisplayName }}OLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_Get{{Camel .Name}}(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void {{$Class}}OLinkHelper::{{ Camel .Name }}PropertyChangeLocalChangeRemoteCb({{ueParam "In" .}})
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
		{{- else if and (not .IsPrimitive) (not (eq .KindType "enum"))}}
		TestValue = createTest{{ ueType "" . }}();
		{{- else }}
		TestValue = {{ ueTestValue "" . }};
		{{- end }}
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), {{ueVar "In" .}}, TestValue);
		if (TSharedPtr<F{{ $DisplayName }}OLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_Get{{Camel .Name}}(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = {{ueDefault "" .}}; // default value
		if (TSharedPtr<F{{ $DisplayName }}OLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_Set{{Camel .Name}}(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		{{ueType "" .}} TestValue = {{ueDefault "" .}}; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), {{ueVar "In" .}}, TestValue);
		if (TSharedPtr<F{{ $DisplayName }}OLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_Get{{Camel .Name}}(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}
{{- end }}
{{- end }}

{{- range .Interface.Signals }}

void {{$Class}}OLinkHelper::{{ Camel .Name }}SignalCb({{ueParams "In" .Params}})
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
	{{- else if and (not .IsPrimitive) (not (eq .KindType "enum"))}}
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

void {{$Class}}OLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

F{{ $DisplayName }}OLinkFixture::F{{ $DisplayName }}OLinkFixture()
{
	Helper = NewObject<{{$Class}}OLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<{{ $Class }}OLinkClient>();
}

F{{ $DisplayName }}OLinkFixture::~F{{ $DisplayName }}OLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<I{{$DisplayName}}Interface> F{{ $DisplayName }}OLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* F{{ $DisplayName }}OLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

U{{ $DisplayName }}OLinkAdapter* F{{ $DisplayName }}OLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<U{{ $DisplayName }}OLinkAdapter>();
}

TSoftObjectPtr<{{$Class}}OLinkHelper> F{{ $DisplayName }}OLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* F{{ $DisplayName }}OLinkFixture::GetGameInstance()
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

void F{{ $DisplayName }}OLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void {{$Class}}OLinkHelper::SetParentFixture(TWeakPtr<F{{ $DisplayName }}OLinkFixture> /*InFixture*/)
{
}

void {{$Class}}OLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void {{$Class}}OLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}

void {{$Class}}OLinkHelper::{{ Camel .Name }}PropertyCb({{ueParam "In" .}})
{
	(void){{ueVar "In" .}};
}

void {{$Class}}OLinkHelper::{{ Camel .Name }}PropertyChangeLocalCheckRemoteCb({{ueParam "In" .}})
{
	(void){{ueVar "In" .}};
}

void {{$Class}}OLinkHelper::{{ Camel .Name }}PropertyChangeLocalChangeRemoteCb({{ueParam "In" .}})
{
	(void){{ueVar "In" .}};
}
{{- end }}
{{- end }}

{{- range .Interface.Signals }}

void {{$Class}}OLinkHelper::{{ Camel .Name }}SignalCb({{ueParams "" .Params}})
{
	{{- range $i, $e := .Params }}
	(void){{ueVar "" .}};
	{{- end }}
}
{{- end }}

void {{$Class}}OLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
