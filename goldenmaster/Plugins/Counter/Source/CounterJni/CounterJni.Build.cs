using UnrealBuildTool;
using System.IO;

public class CounterJni : ModuleRules
{
	public CounterJni(ReadOnlyTargetRules Target) : base(Target)
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
				"CounterAPI",
				"CounterCore",
				"Projects",
				"Engine",
				"JsonUtilities",
				"CustomTypesCore",
				"CustomTypesJni", 
				"ExternTypesCore",
				"ExternTypesJni"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"CounterCore",
				"CounterImplementation",
				"CustomTypesAPI",
				"ExternTypesAPI",
			}
			);

		if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PrivateDefinitions.Add("WITH_JNI=1");
            string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "Counter_JNI_UPL.xml"));

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
