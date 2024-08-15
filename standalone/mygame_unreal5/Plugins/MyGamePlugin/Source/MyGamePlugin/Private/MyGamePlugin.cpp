// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyGamePlugin.h"

#if defined _WIN32 || defined _WIN64
	#include <Windows.h>
	#define EXAMPLELIBRARY_EXPORT __declspec(dllexport)
#else
	#include <stdio.h>
#endif

#ifndef EXAMPLELIBRARY_EXPORT
	#define EXAMPLELIBRARY_EXPORT
#endif

#define LOCTEXT_NAMESPACE "FMyGamePluginModule"

EXAMPLELIBRARY_EXPORT void Hello_StartupModule();
EXAMPLELIBRARY_EXPORT void ExampleLibraryFunction();

void FMyGamePluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	Hello_StartupModule();
}

void FMyGamePluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

EXAMPLELIBRARY_EXPORT void Hello_StartupModule()
{
#if defined _WIN32 || defined _WIN64
	MessageBox(NULL, TEXT("Loaded ExampleLibrary.dll from Third Party Plugin sample."), TEXT("Third Party Plugin"), MB_OK);
#else
	printf("Loaded ExampleLibrary from Third Party Plugin sample");
#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMyGamePluginModule, MyGamePlugin)