{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $ConnecitonEnabled := or .Features.stubs .Features.olink }}
{{- $Category := printf "ApiGear%s" $ModuleName }}
#include "{{$ModuleName}}Settings.h"
#include "{{$ModuleName}}/Generated/{{$ModuleName}}Factory.h"
{{- if .Features.api }}
#include "{{$ModuleName}}/Generated/{{$ModuleName}}LogCategories.h"
{{- end }}
{{- if $.Features.apigear }}
#include "ApiGearConnectionsStore.h"
{{- end }}
#include "Engine/Engine.h"
#include "Misc/CoreDelegates.h"

{{- $factoryclass := printf "F%sModuleFactory" $ModuleName}}

U{{$ModuleName}}Settings::U{{$ModuleName}}Settings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FCoreDelegates::OnPostEngineInit.AddUObject(this, &U{{$ModuleName}}Settings::ValidateSettingsPostEngineInit);
}

void U{{$ModuleName}}Settings::ValidateSettingsPostEngineInit()
{
	check(GEngine);
{{- if $.Features.apigear }}
	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();
{{- end }}

{{- if $.Features.olink}}

	if (!AGCM->DoesConnectionExist(OLinkConnectionIdentifier))
	{
		UE_LOG(Log{{$ModuleName}}, Warning, TEXT("U{{$ModuleName}}Settings could not find connection %s."), *OLinkConnectionIdentifier);
		OLinkConnectionIdentifier = "";
	}
{{- end }}

{{- if $.Features.monitor }}

	// the local backend does not require configuration
	if (TracerServiceIdentifier == {{$ModuleName}}LocalBackendIdentifier)
	{
		return;
	}

	if (!AGCM->DoesConnectionExist(TracerServiceIdentifier))
	{
		UE_LOG(Log{{$ModuleName}}, Warning, TEXT("U{{$ModuleName}}Settings could not find connection %s, falling back to local backend."), *TracerServiceIdentifier);
		TracerServiceIdentifier = {{$ModuleName}}LocalBackendIdentifier;
	}
{{- end }}
}

{{- range .Module.Interfaces }}
{{- if $.Features.monitor }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
{{- $iclass := printf "I%sInterface" $class }}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Name) }}

TScriptInterface<I{{$class}}Interface> U{{$ModuleName}}Settings::Get{{$iclass}}ForLogging(FSubsystemCollectionBase& Collection)
{
{{- if or $.Features.stubs $.Features.olink }}
	U{{$ModuleName}}Settings* {{$ModuleName}}Settings = GetMutableDefault<U{{$ModuleName}}Settings>();

	FString BackendIdentifier = {{$ModuleName}}Settings->TracerServiceIdentifier;

{{- end }}

{{- if $.Features.stubs }}

	if ({{$ModuleName}}Settings->TracerServiceIdentifier == {{$ModuleName}}LocalBackendIdentifier)
	{
		return {{$factoryclass}}::Get{{$class}}Implementation({{$ModuleName}}LocalBackendIdentifier, Collection);
	}
{{- end }}
{{- if $.Features.olink }}

	if ({{$ModuleName}}Settings->TracerServiceIdentifier != {{$ModuleName}}LocalBackendIdentifier)
	{
		return {{$factoryclass}}::Get{{$class}}Implementation("olink", Collection);
	}
{{- end }}

	return nullptr;
}
{{- end }}
{{- end }}
