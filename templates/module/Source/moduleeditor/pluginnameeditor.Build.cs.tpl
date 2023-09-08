{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" $ModuleName }}
{{- $Category := printf "ApiGear%s" $ModuleName -}}
{{- $ModulePath := (path .Module.Name)}}
{{- $class := printf "%sEditor" $ModuleName -}}
namespace UnrealBuildTool.Rules
{
	public class {{$class}} : ModuleRules
	{
		public {{$class}}(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
			#if UE_5_2_OR_LATER 
				IWYUSupport = IWYUSupport.Full;
			#else
				bEnforceIWYU = true;
			#endif
			
			PrivateDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"CoreUObject",
					"UnrealEd",
					// modules below are needed for connection settings
					"ApiGear",
{{- if $.Features.olink }}
					"ApiGearOLink",
{{- end }}
					"InputCore",
					"PropertyEditor",
					"Slate",
					"SlateCore"
				});

			PrivateIncludePaths.AddRange(
				new string[] {
					"{{$class}}/Private",
				});		
				
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"{{$ModuleName}}"
				}
				);
			}
	}
}
