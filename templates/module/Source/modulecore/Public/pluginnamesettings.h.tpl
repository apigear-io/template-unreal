{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%sCORE_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear%s" $ModuleName }}
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "{{$ModuleName}}Settings.generated.h"

const FString {{$ModuleName}}LocalBackendIdentifier = "Local";

class FSubsystemCollectionBase;
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
class I{{$class}}Interface;
{{- end }}

/**
 * Implements the settings for the {{$ModuleName}} plugin.
 */
UCLASS(Config = Engine, DefaultConfig)
class {{$API_MACRO}} U{{$ModuleName}}Settings : public UObject
{
	GENERATED_BODY()

	U{{$ModuleName}}Settings(const FObjectInitializer& ObjectInitializer);

public:
	/** Callback used to validate the settings once the engine is available */
	void ValidateSettingsPostEngineInit();

{{- if $.Features.monitor }}

	/** Choose the backend service for the logging decorator to use */
	UPROPERTY(EditAnywhere, config, Category = TracerServiceSetup)
	FString TracerServiceIdentifier;
{{- end}}

{{- if $.Features.olink }}

	/** Choose the olink connection to use */
	UPROPERTY(EditAnywhere, config, Category = OLinkConnectionSetup)
	FString OLinkConnectionIdentifier;
{{- end }}

{{- range .Module.Interfaces }}
{{- if $.Features.monitor }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
	static TScriptInterface<I{{$class}}Interface> GetI{{$class}}InterfaceForLogging(FSubsystemCollectionBase& Collection);
{{- end }}
{{- end }}

{{- if $.Features.msgbus }}

	/** Choose the heartbeat interval in milliseconds for the msgbus connection on the service side.
	 * On the service side this adjusts the heartbeat between client and service. The clients will receive the value from service.
	 * On the client side this adjusts how often discovery messages are sent until a service is connected.
	 */
	UPROPERTY(EditAnywhere, config, Category = MsgBusConnectionSetup, meta = (DisplayName = "Heartbeat interval (in milliseconds)"))
	uint32 MsgBusHeartbeatIntervalMS = 200;
{{- end }}
};
