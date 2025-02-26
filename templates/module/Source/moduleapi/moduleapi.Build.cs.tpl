{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
{{- $ModuleName := Camel .Module.Name -}}
using UnrealBuildTool;
using System.IO;

public class {{$ModuleName}}API : ModuleRules
{
	public {{$ModuleName}}API(ReadOnlyTargetRules Target) : base(Target)
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
				"{{Camel .Name}}API"
{{- end }}
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
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
