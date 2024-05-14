{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
{{- $ModuleName := Camel .Module.Name}}
{{- $ModulePath := path .Module.Name}}
{{- $API_MACRO := printf "%s_API" $ModuleName }}
{{- $Category := printf "ApiGear%s" $ModuleName -}}
using UnrealBuildTool;
using System.IO;

public class {{$ModuleName}} : ModuleRules
{
	public {{$ModuleName}}(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		#if UE_5_2_OR_LATER 
			IWYUSupport = IWYUSupport.Full;
		#else
			bEnforceIWYU = true;
		#endif

		// Disable nlohmann::json exception handling
		PublicDefinitions.Add("JSON_NOEXCEPTION=1");
		
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
{{- if .Features.api }}
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Public/Generated/api"));
{{- end }}
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

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
				"Core",
{{- if .Features.apigear }}
				"ApiGear",
{{- end }}
				"Projects",
				"Engine",
				"JsonUtilities"
{{- if .Module.Imports }}, {{- end}}
{{- range $idx, $elem := .Module.Imports }}
{{- if $idx}}, {{ end }}
				"{{Camel .Name}}"
{{- end }}
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
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
