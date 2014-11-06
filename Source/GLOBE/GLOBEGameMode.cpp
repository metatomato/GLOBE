// Fill out your copyright notice in the Description page of Project Settings.

#include "GLOBE.h"
#include "GLOBEGameMode.h"


AGLOBEGameMode::AGLOBEGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}


void AGLOBEGameMode::BeginPlay(){
	UE_LOG(LogTemp, Warning, TEXT("Welcome to M$, metatomato... Shame on you!"));
} 