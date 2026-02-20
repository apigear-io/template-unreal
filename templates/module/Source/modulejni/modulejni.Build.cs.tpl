{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
{{- $ModuleName := Camel .Module.Name}}
{{- $ModulePath := path .Module.Name}}
{{- $Category := printf "ApiGear%s" $ModuleName -}}
using UnrealBuildTool;
using System.IO;

public class {{$ModuleName}}Jni : ModuleRules
{
	public {{$ModuleName}}Jni(ReadOnlyTargetRules Target) : base(Target)
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
				"{{Camel .Module.Name}}Core",
				"Projects",
				"Engine",
				"JsonUtilities"
{{- if .Module.Imports }}, {{- end}}
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
{{- if .Features.stubs }}
				"{{Camel .Module.Name}}Core",
		{{- if len (.Module.Interfaces) }}
				"{{Camel .Module.Name}}Implementation",
		{{- end }}
{{- end }}
{{- range $idx, $elem := .Module.Imports }}
				"{{Camel .Name}}API",
{{- end }}
			}
			);

		if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PrivateDefinitions.Add("WITH_JNI=1");
            string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "{{Camel .Module.Name}}_JNI_UPL.xml"));

{{- if .Module.Imports }}
{{- nl }}
            PublicDependencyModuleNames.AddRange(
                new string[]
                {
{{- range $idx, $elem := .Module.Imports }}
{{- if $idx }}, {{ end }}
                    "{{Camel .Name}}Jni"
{{- end }}
                }
                );
{{- end }}

            PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });
        }
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
