//
//  CountryHelper.h
//  GLOBE
//
//  Created by Jonathan Boucher on 22/05/14.
//  Copyright (c) 2014 EpicGames. All rights reserved.
//


#pragma once

#include "Json.h"
#include "Country.h"


class CountryHelper
{
public:
    static FCountry            ExtractCountry(TSharedPtr<FJsonObject> JsonCountry);
    static FCapital            ExtractCapital(TSharedPtr<FJsonObject> JsonCapital);
    static FVector2D           ExtractGeoPt(TSharedPtr<FJsonValue> JsonGeoPt);
    static TArray<FString>     ExtractCountryCodes(TSharedPtr<FJsonObject> JsonCountryCodes);
    static FVector4            ExtractGeoRectangle(TSharedPtr<FJsonObject> JsonGeoRectangle);
    static TArray<FString>     ExtractCountryNames(TSharedPtr<FJsonObject> JsonCountryNames);
    
    static void PrintCountry(FCountry Country);
};