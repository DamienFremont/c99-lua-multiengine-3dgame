// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyGameUnreal5Target : TargetRules
{
    public MyGameUnreal5Target(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
        ExtraModuleNames.Add("MyGameUnreal5");
    }
}
