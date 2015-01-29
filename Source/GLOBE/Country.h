//
//  Country.h
//  FLAG3D
//
//  Created by Jonathan Boucher on 22/05/14.
//  Copyright (c) 2014 EpicGames. All rights reserved.
//

#pragma once

#include "Country.generated.h"



USTRUCT(BlueprintType)
struct FCapital
{
	GENERATED_USTRUCT_BODY()
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="iGLou_Country")
	FString Name;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="iGLou_Country")
	FVector2D GeoPt;
    
    bool operator==(const FCapital& rhs)
    {
        return (Name.Compare(rhs.Name) == 0);
    }
};


USTRUCT(BlueprintType)
struct FCountry
{
    enum COUNTRY_CODES { FIPS, ISO2, ISO3, ISON, TLD };
    
	GENERATED_USTRUCT_BODY()
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="iGLou_Country")
	FCapital Capital;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="iGLou_Country")
	TArray<FString> CountryCodes;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="iGLou_Country")
	FVector2D GeoPt;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="iGLou_Country")
	FVector4 GeoRectangle;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="iGLou_Country")
	FString Name;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="iGLou_Country")
	TArray<FString> Names;
    
    bool operator==(const FCountry& rhs)
    {
        return (Name.Compare(rhs.Name) == 0);
    }
};
