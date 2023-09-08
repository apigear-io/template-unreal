namespace UnrealBuildTool.Rules
{
	public class TbEnumEditor : ModuleRules
	{
		public TbEnumEditor(ReadOnlyTargetRules Target) : base(Target)
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
					"ApiGearOLink",
					"InputCore",
					"PropertyEditor",
					"Slate",
					"SlateCore"
				});

			PrivateIncludePaths.AddRange(
				new string[] {
					"TbEnumEditor/Private",
				});		
				
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"TbEnum"
				}
				);
			}
	}
}
