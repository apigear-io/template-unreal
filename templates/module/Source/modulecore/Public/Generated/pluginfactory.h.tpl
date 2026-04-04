{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%sCORE_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear%s" $ModuleName }}
{{- $class := printf "F%sModuleFactory" $ModuleName}}
#pragma once

#include "Logging/LogMacros.h"
#include "UObject/ScriptInterface.h"
#include "Runtime/Launch/Resources/Version.h"

class UGameInstance;
class FSubsystemCollectionBase;
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
class I{{$class}}Interface;
{{- end }}

// General Log
DECLARE_LOG_CATEGORY_EXTERN(Log{{$class}}, Log, All);

class {{ $API_MACRO }} {{$class}}
{
public:
	/** type of function for creating implementations*/
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
	using F{{$class}}FactoryFunction = TFunction<TScriptInterface<I{{$class}}Interface>(FSubsystemCollectionBase& Collection)>;
{{- end }}

	/** register factories for different types of implementations and interfaces */
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
	static bool RegisterFactory(FString TypeIdentifier, F{{$class}}FactoryFunction FactoryFunction);
{{- end }}

{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
	static TScriptInterface<I{{$class}}Interface> Get{{$class}}Implementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
{{- end }}

private:
{{- range .Module.Interfaces }}
{{- $iclass := printf "%s%s" $ModuleName (Camel .Name)}}
	static TMap<FString, {{$class}}::F{{$iclass}}FactoryFunction> {{$iclass}}Factories;
{{- end }}
};
