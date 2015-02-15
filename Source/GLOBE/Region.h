//
//  Region.h
//  GLOBE
//
//  Created by Jonathan Boucher on 13/02/15.
//  Copyright (c) 2015 EpicGames. All rights reserved.
//


#pragma once
#include "Region.generated.h"

USTRUCT(BlueprintType)
struct FRegion
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iGLou_Region")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iGLou_Region")
	TArray<FString> RegionCodes;
	

	bool operator==(const FRegion& rhs)
	{
		return (Name.Compare(rhs.Name) == 0);
	}
};

