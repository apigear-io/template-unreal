
{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sOLinkClient" $DisplayName}}
{{- $abstractclass := printf "UAbstract%s%s" (Camel .Module.Name) (Camel .Interface.Name) }}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "{{$Iface}}Interface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "unrealolinksink.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
#include "Templates/UniquePtr.h"
#else
#include "Templates/PimplPtr.h"
#endif
#include "{{$Iface}}OLinkClient.generated.h"

{{- if len .Interface.Properties }}

struct {{$Iface}}PropertiesData;
{{- end}}
DECLARE_LOG_CATEGORY_EXTERN(Log{{$Iface}}OLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public {{$abstractclass}}
{
	GENERATED_BODY()
public:
	explicit {{$Class}}();

	// only needed in 4.25 to use TUniquePtr<{{$Iface}}PropertiesData>
	{{$Class}}(FVTableHelper& Helper);
	virtual ~{{$Class}}();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
{{- range .Interface.Properties }}
	{{ueReturn "" .}} Get{{Camel .Name}}_Implementation() const override;
	void Set{{Camel .Name}}_Implementation({{ueParam "" .}}) override;
{{ end }}
	// operations
{{- range $i, $e := .Interface.Operations }}
{{- if $i }}{{nl}}{{ end }}
	{{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) override;
{{- end }}

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

{{- if len .Interface.Properties }}

	// member variable to store the last sent data
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	TUniquePtr<{{$Iface}}PropertiesData> _SentData;
#else
	TPimplPtr<{{$Iface}}PropertiesData> _SentData;
#endif
{{- end}}
	TScriptInterface<class IApiGearConnection> Connection;
};
