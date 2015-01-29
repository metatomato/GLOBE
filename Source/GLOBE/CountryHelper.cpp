//
//  CountryHelper.cpp
//  FLAG3D
//
//  Created by Jonathan Boucher on 22/05/14.
//  Copyright (c) 2014 EpicGames. All rights reserved.
//

#include "FLAG3D.h"
#include "CountryHelper.h"
#include "Json.h"
#include "DataToolkit.h"


void CountryHelper::PrintCountry(FCountry Country)
{
    UE_LOG(LogTemp,Error,TEXT("Name         %s"), *Country.Name);
    UE_LOG(LogTemp,Error,TEXT("Capital      %s"), *Country.Capital.Name);
    UE_LOG(LogTemp,Error,TEXT("             %s"), *Country.Capital.GeoPt.ToString());
    UE_LOG(LogTemp,Error,TEXT("CountryCodes   ") );
    for(auto s : Country.CountryCodes)
    {
        UE_LOG(LogTemp,Error,TEXT("             %s"), *s);
    }
    UE_LOG(LogTemp,Error,TEXT("GeoPt        %s"), *Country.GeoPt.ToString());
    UE_LOG(LogTemp,Error,TEXT("GeoRectangle %s"), *Country.GeoRectangle.ToString());
    UE_LOG(LogTemp,Error,TEXT("Names        ") );
    for(auto s : Country.Names)
    {
        UE_LOG(LogTemp,Error,TEXT("             %s"), *s);
    }
}


FCountry CountryHelper::ExtractCountry(TSharedPtr<FJsonObject> JsonCountry)
{
    FCountry Country;
    
    if( JsonCountry.IsValid() )
    {
        Country.Name    = JsonCountry->GetStringField( TEXT("Name") );
        Country.Capital = ExtractCapital( JsonCountry->GetObjectField( TEXT("Capital") ) );
        Country.CountryCodes = ExtractCountryCodes( JsonCountry->GetObjectField( TEXT("CountryCodes") ) );
        Country.GeoPt = ExtractGeoPt( JsonCountry->Values.FindRef( TEXT("GeoPt") ) );
        Country.GeoRectangle = ExtractGeoRectangle( JsonCountry->GetObjectField( TEXT("GeoRectangle") ) );
        Country.Names = ExtractCountryNames( JsonCountry->GetObjectField( TEXT("Names") ) );
    }
    
    return Country;
}



FCapital CountryHelper::ExtractCapital(TSharedPtr<FJsonObject> JsonCapital)
{
    FCapital Capital;
    
    if ( JsonCapital.IsValid() )
    {
        Capital.Name = JsonCapital->GetStringField("Name");
        Capital.GeoPt = ExtractGeoPt( JsonCapital->Values.FindRef("GeoPt") );
        
    }
    return Capital;
}



FVector2D CountryHelper::ExtractGeoPt(TSharedPtr<FJsonValue> JsonGeoPt)
{
    FVector2D GeoPt;
    if( JsonGeoPt.IsValid() )
    {
        GeoPt.X = JsonGeoPt->AsArray()[0]->AsNumber();
        GeoPt.Y = JsonGeoPt->AsArray()[1]->AsNumber();
    }
    return GeoPt;
}



TArray<FString> CountryHelper::ExtractCountryCodes(TSharedPtr<FJsonObject> JsonCountryCodes)
{
    TArray<FString> CountryCodes;
    if ( JsonCountryCodes.IsValid() )
    {
        for(auto pair : JsonCountryCodes->Values)
        {
            CountryCodes.Add(pair.Value->AsString());
        }
    }
    return CountryCodes;
}


FVector4 CountryHelper::ExtractGeoRectangle(TSharedPtr<FJsonObject> JsonGeoRectangle)
{
    FVector4 GeoRectangle;
    
    if ( JsonGeoRectangle.IsValid() )
    {
        int counter = 0;
        for(auto pair : JsonGeoRectangle->Values)
        {
            GeoRectangle[counter] = pair.Value->AsNumber();
            counter++;
        }
    }
    return GeoRectangle;
}



TArray<FString> CountryHelper::ExtractCountryNames(TSharedPtr<FJsonObject> JsonCountryNames)
{
    TArray<FString> CountryNames;
    
    if ( JsonCountryNames.IsValid() )
    {
        for(auto pair : JsonCountryNames->Values)
        {
            CountryNames.Add(pair.Value->AsString());
        }
    }
    return CountryNames;
}
