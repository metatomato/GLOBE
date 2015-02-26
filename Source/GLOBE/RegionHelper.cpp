//
//  CountryHelper.cpp
//  GLOBE
//
//  Created by Jonathan Boucher on 13/02/15.
//  Copyright (c) 2015 EpicGames. All rights reserved.
//

#include "GLOBE.h"
#include "RegionHelper.h"
#include "Json.h"
#include "DataToolkit.h"


FRegion RegionHelper::ExtractRegion(TSharedPtr<FJsonObject> JsonRegion)
{
	FRegion Region;

	if (JsonRegion.IsValid())
	{
		Region.Name = JsonRegion->GetStringField(TEXT("Name"));
		Region.RegionCodes = ExtractCountryCodes( JsonRegion->Values.FindRef( TEXT("CountryCodes") ) );
	}

	return Region;
}


TArray<FString> RegionHelper::ExtractCountryCodes(TSharedPtr<FJsonValue> JsonCountryCodes)
{
	TArray<FString> CountryCodes = TArray<FString>();

	if (JsonCountryCodes.IsValid())
	{		
		for (auto JsonValue : JsonCountryCodes->AsArray())
		{
			CountryCodes.Add(JsonValue->AsString());
			//UE_LOG(LogTemp, Warning, TEXT(" %s"), *(JsonValue->AsString()));
		}
	}

	return CountryCodes;
}