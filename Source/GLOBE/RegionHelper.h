//
//  RegionHelper.h
//  GLOBE
//
//  Created by Jonathan Boucher on 13/02/15.
//  Copyright (c) 2015 EpicGames. All rights reserved.
//


#pragma once

#include "Json.h"
#include "Region.h"


class RegionHelper
{
public:
	static FRegion ExtractRegion(TSharedPtr<FJsonObject> JsonRegion);
	static TArray<FString> ExtractCountryCodes(TSharedPtr<FJsonValue> JsonCountryCodes);
};