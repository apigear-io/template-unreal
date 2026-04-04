{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $Category := printf "ApiGear%s" $ModuleName }}
{{- $mclass := printf "F%sModuleFactory" $ModuleName}}

#include "{{$ModuleName}}/Generated/{{$ModuleName}}Factory.h"
#include "{{$ModuleName}}Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"
{{- range $i, $e := .Module.Interfaces -}}
{{- if eq $i 0 }}{{nl}}{{ end }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
TMap<FString, {{$mclass}}::F{{$class}}FactoryFunction> {{$mclass}}::{{$class}}Factories{};
{{- end }}

// General Log
DEFINE_LOG_CATEGORY(Log{{$mclass}});

{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
{{- $iclass := printf "I%sInterface" $class }}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Name) }}

bool {{$mclass}}::RegisterFactory(FString TypeIdentifier, F{{$class}}FactoryFunction FactoryFunction)
{
	if ({{$class}}Factories.Contains(TypeIdentifier))
	{
		UE_LOG(Log{{$mclass}}, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	{{$class}}Factories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<I{{$class}}Interface> {{$mclass}}::Get{{$class}}Implementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if ({{$class}}Factories.Contains(UniqueImplementationIdentifier))
	{
		return {{$class}}Factories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}
{{- end }}
