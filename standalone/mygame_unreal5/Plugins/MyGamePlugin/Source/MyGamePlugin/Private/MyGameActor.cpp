// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameActor.h"

#if defined _WIN32 || defined _WIN64
#include <Windows.h>
#define EXAMPLELIBRARY_EXPORT __declspec(dllexport)
#else
#include <stdio.h>
#endif

#ifndef EXAMPLELIBRARY_EXPORT
#define EXAMPLELIBRARY_EXPORT
#endif

EXAMPLELIBRARY_EXPORT void Hello_BeginPlay();

// Sets default values
AMyGameActor::AMyGameActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyGameActor::BeginPlay()
{
	Super::BeginPlay();
	Hello_BeginPlay();
}

// Called every frame
void AMyGameActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

EXAMPLELIBRARY_EXPORT void Hello_BeginPlay()
{
#if defined _WIN32 || defined _WIN64
	MessageBox(NULL, TEXT("BeginPlay ExampleLibrary.dll from Third Party Plugin sample."), TEXT("Third Party Plugin"), MB_OK);
#else
	printf("Loaded ExampleLibrary from Third Party Plugin sample");
#endif
}

