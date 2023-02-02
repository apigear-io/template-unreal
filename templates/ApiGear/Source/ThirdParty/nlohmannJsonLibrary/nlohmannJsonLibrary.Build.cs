// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class nlohmannJsonLibrary : ModuleRules
{
	public nlohmannJsonLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		// we have no sources to include, only the hpp file
		Type = ModuleType.External;

		bAddDefaultIncludePaths = false;
		bRequiresImplementModule = false;

		// Disable nlohmann::json exception handling
		PublicDefinitions.Add("JSON_NOEXCEPTION=1");

		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core"
			}
			);
			
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
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

