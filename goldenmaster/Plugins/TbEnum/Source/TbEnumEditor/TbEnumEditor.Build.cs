namespace UnrealBuildTool.Rules
{
	public class TbEnumEditor : ModuleRules
	{
		public TbEnumEditor(ReadOnlyTargetRules Target) : base(Target)
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
