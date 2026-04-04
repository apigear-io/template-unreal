{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%sMONITOR_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName (Camel .Interface.Name) }}
{{- $DisplayName := printf "%s%sLoggingDecorator" $ModuleName (Camel .Interface.Name) }}
{{- $abstractclass := printf "UAbstract%s%s" (Camel .Module.Name) (Camel .Interface.Name) }}
{{- $Class := printf "U%s" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "{{$ModuleName}}/Generated/api/Abstract{{$Iface}}.h"
#include "{{$Iface}}LoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(Log{{$DisplayName}}, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public {{$abstractclass}}, public I{{$Iface}}SubscriberInterface
{
	GENERATED_BODY()

public:
	explicit {{$Class}}();
	virtual ~{{$Class}}();

	UFUNCTION(BlueprintCallable, Category = "{{$Category}}")
	void setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
{{- range .Interface.Properties }}
{{- if .Description }}
	/** {{.Description}} */
{{- end }}
	{{ueReturn "" .}} Get{{Camel .Name}}() const override;
{{- if not .IsReadOnly }}{{nl}}
	void Set{{Camel .Name}}({{ueParam "In" .}}) override;
{{- end }}
{{ end }}
	// operations
{{- range .Interface.Operations }}
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override;
{{ end }}
private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "{{$Category}}")
	TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> BackendService;

	// signals
{{- range $i, $e := .Interface.Signals }}
{{- if $i }}{{nl}}{{ end }}
	void On{{Camel .Name}}Signal({{ueParams "In" .Params}});
{{- end }}
{{- if len .Interface.Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
	void On{{Camel .Name}}Changed({{ueParam "In" .}});
{{- end }}
};
