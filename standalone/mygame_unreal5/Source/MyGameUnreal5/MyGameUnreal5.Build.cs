// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyGameUnreal5 : ModuleRules
{
    public MyGameUnreal5(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "MyGamePlugin" });
        PrivateDependencyModuleNames.AddRange(new string[] { "MyGamePlugin" });
    }
}
