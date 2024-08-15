// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyGameUnreal5EditorTarget : TargetRules
{
    public MyGameUnreal5EditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
        ExtraModuleNames.Add("MyGameUnreal5");
    }
}
