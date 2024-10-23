{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
{{- $ModuleName := Camel .Module.Name}}
{{- $ModulePath := path .Module.Name}}
{{- $Category := printf "ApiGear%s" $ModuleName -}}
using UnrealBuildTool;
using System.IO;

public class {{$ModuleName}}Core : ModuleRules
{
	public {{$ModuleName}}Core(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		#if UE_5_2_OR_LATER 
			IWYUSupport = IWYUSupport.Full;
		#else
			bEnforceIWYU = true;
		#endif

		// Disable nlohmann::json exception handling
		PublicDefinitions.Add("JSON_NOEXCEPTION=1");

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
{{- if .Features.api }}
				"{{Camel .Module.Name}}API",
{{- end }}
{{- if .Features.apigear }}
				"ApiGear",
{{- end }}
				"Projects",
				"Engine",
{{- if .Features.msgbus }}
				"Messaging",
{{- end }}
				"JsonUtilities",
{{- if .Features.olink }}
				"ApiGearOLink",
				"OLinkProtocolLibrary",
{{- end }}
{{- range $idx, $elem := .Module.Imports }}
{{- if $idx}}, {{ end }}
				"{{Camel .Name}}Core"
{{- end }}
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
{{- range $idx, $elem := .Module.Imports }}
				"{{Camel .Name}}API",
{{- end }}
{{- if .Features.olink }}
				"ApiGearOLink",
				"OLinkProtocolLibrary"
{{- end }}
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
