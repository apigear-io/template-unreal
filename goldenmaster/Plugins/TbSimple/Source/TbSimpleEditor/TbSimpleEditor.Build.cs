namespace UnrealBuildTool.Rules
{
	public class TbSimpleEditor : ModuleRules
	{
		public TbSimpleEditor(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
			bEnforceIWYU = true;
			
			PrivateDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"CoreUObject",
					"UnrealEd",
				});

			PrivateIncludePaths.AddRange(
				new string[] {
					"TbSimpleEditor/Private",
				});		
				
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"TbSimple"
				}
				);
			}
	}
}
