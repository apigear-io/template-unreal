// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class ApiGear : ModuleRules
{
	public ApiGear(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnforceIWYU = true;

		// Disable nlohmann::json exception handling
		PublicDefinitions.Add("JSON_NOEXCEPTION=1");

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));
       
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"WebSockets",
				"HTTP",
				"OLinkProtocolLibrary",
				"nlohmannJsonLibrary"
			}
			);
			
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				// modules below are needed for connection settings
				"InputCore",
				"Slate",
				"SlateCore"
			}
			);
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

		// if (Target.Platform == UnrealTargetPlatform.Win64)
		// {
		// 	// Add the import library
		// 	PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "Release", "apigear.lib"));

		// 	// Delay-load the DLL, so we can load it from the right place first
		// 	PublicDelayLoadDLLs.Add("apigear.dll");

		// 	// Ensure that the DLL is staged along with the executable
		// 	RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/apigear/Win64/apigear.dll");
        // }
        // else if (Target.Platform == UnrealTargetPlatform.Mac)
        // {
        //     PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Mac", "Release", "libapigear.dylib"));
        //     RuntimeDependencies.Add("$(PluginDir)/Source/ThirdParty/apigear/Mac/Release/libapigear.dylib");
        // }
	}
}

