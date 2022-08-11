namespace UnrealBuildTool.Rules
{
	public class TbSame1Editor : ModuleRules
	{
		public TbSame1Editor(ReadOnlyTargetRules Target) : base(Target)
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
					"TbSame1Editor/Private",
				});		
				
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"TbSame1"
				}
				);
			}
	}
}
