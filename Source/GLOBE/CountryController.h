//
//  CountryController.h
//  FLAG3D
//
//  Created by Jonathan Boucher on 22/05/14.
//  Copyright (c) 2014 EpicGames. All rights reserved.
//

#pragma once

#include "Country.h"
#include "Region.h"
#include "CountryHelper.h"
#include "RegionHelper.h"
#include "CountryController.generated.h"




UCLASS(Blueprintable, BlueprintType)
class UCountryController : public UObject
{
	GENERATED_UCLASS_BODY()

public:
    /**
	 * Create the instance of CountryController.
	 *
	 * @param	JsonString	A string containing the whole countries data, Json formatted.
     * @returns             A pointer to the CountryController instance created.
	 */
    UFUNCTION(BlueprintCallable,
              meta = (FriendlyName = "CreateCountryController", CompactNodeTitle = "CREATE", Keywords = "country create"),
              Category = iGLou_Country)
    
			  static UCountryController* CreateCountryController(FString JsonStringCountry, FString JsonStringRegion = "");
    
    
    /**
	 * Create Country Data (Key(String)/Value(FJsonObject))
     *
     * @param   JsonString      A string containing the whole countries data, Json formatted.
     *
	 */
    void InitializeCountries(FString JsonString);


	/**
	* Create Region Country Keys 
	*
	* @param   JsonString      A string containing the regions data, Json formatted.
	*
	*/
	void InitializeRegions(FString JsonString);
    
    
    /**
	 * Generate DrawNum draws filling RandomList list.
	 *
	 * @param	DrawNum     Number of draws (size of RandomList).
     *
	 */
    UFUNCTION(BlueprintCallable,
              meta = (FriendlyName = "InitCountryDraw", Keywords = "country Init Draw"),
              Category = iGLou_Country)
    
    void InitDraw(int32 DrawNum);
    
    
    /**
	 * Get the number of countries in current Region.
     *
     * @returns  The number of countries in current Region.
     *
	 */
	UFUNCTION(BlueprintCallable,
              meta = (FriendlyName = "Num", Keywords = "country number count total"),
              Category = iGLou_Country)
    
    int32 Num();
    

	/**
	* Get the number of total countries.
	*
	* @returns  The number of total countries.
	*
	*/
	UFUNCTION(BlueprintCallable,
		meta = (FriendlyName = "WorldNum", Keywords = "world country number count total"),
		Category = iGLou_Country)

	int32 WorldNum();

    /**
	 * Generate a random draw of four country indices with current country in.
     *
     * @param   UpperBound      The upper bound form random draw.
     * @returns                 The random interger array (4 integers), each ranges between 0 and countries numbers.
     *
	 */
	UFUNCTION(BlueprintCallable,
              meta = (FriendlyName = "GenerateAnswerIndices", Keywords = "country random indices"),
              Category = iGLou_Country)
    
    TArray<FString> GenerateAnswerIndices(int32 UpperBound);
    

	/**
	* Generate a random draw of four country indices with current country in.
	*
	* @param   UpperBound      The upper bound form random draw.
	* @returns                 The random interger array (4 integers), each ranges between 0 and countries numbers.
	*
	*/
	TArray<int32> GenerateDrawIndices(int32 UpperBound);

    /**
	 * Step forward, removing an entry in the RandomList.
     *
     * @returns     The country KeyValue corresponding to the last entry of RandomList.
     *
	 */
	UFUNCTION(BlueprintCallable,
              meta = (FriendlyName = "Step", Keywords = "country step RandomList"),
              Category = iGLou_Country)
    
    FString Step();
    
    /**
	 * Get the Country corresponding to the index position in the map.
     *
     * @param   Index   index of the KeyValue in CountryKeys.
     * @returns         The country at index.
     *
	 */
	UFUNCTION(BlueprintCallable,
              meta = (FriendlyName = "GetCountryByIndex", Keywords = "get country index"),
              Category = iGLou_Country)
    
    FCountry GetCountryByIndex(int32 Index);
    

    /**
	 * Get the Country corresponding to the KeyValue in the map.
     *
     * @param   Key     KeyValue.
     * @returns         The country for the KeyValue.
     *
	 */
	UFUNCTION(BlueprintCallable,
              meta = (FriendlyName = "GetCountryByKey", CompactNodeTitle = "GET", Keywords = "country key"),
              Category = iGLou_Country)
    
    FCountry GetCountryByKey(FString Key);
    
    /**
	 * Get the Country array corresponding to the KeyValue array in the map.
     *
     * @param   Keys     KeyValue array.
     * @returns         The countries for the KeyValue.
     *
	 */
	UFUNCTION(BlueprintCallable,
              meta = (FriendlyName = "GetCountriesByKeys", CompactNodeTitle = "GETs", Keywords = "country key"),
              Category = iGLou_Country)
    
    TArray<FCountry> GetCountriesByKeys(TArray<FString> Keys);
    
    /**
	 * Get the Country position in CountryKeys.
     *
     * @param   Country     Corresponding country for position query.
     * @returns             The position for the country.
     *
	 */
	UFUNCTION(BlueprintCallable,
              meta = (FriendlyName = "GetCountryPosition", Keywords = "country position"),
              Category = iGLou_Country)
    
    int32 GetCountryPosition(FCountry Country);
    
    /**
	 * Get the Country position in CountryKeys.
     *
     * @param   Country    Corresponding country key for position query.
     * @returns             The position for the country.
     *
	 */
	UFUNCTION(BlueprintCallable,
              meta = (FriendlyName = "GetCountryPositionByKey", Keywords = "country position"),
              Category = iGLou_Country)
    
    int32 GetCountryPositionByKey(FString CountryKey);
    

	/**
	* Get the Country position in CountryKeys.
	*
	* @param   Country    Corresponding country key for position query.
	* @returns             The position for the country.
	*
	*/
	UFUNCTION(BlueprintCallable,
		meta = (FriendlyName = "GetRegion", Keywords = "region get"),
		Category = iGLou_Country)

		FRegion GetRegion(FString RegionKey);


	/**
	* Set the current region
	*
	* @param             The name of the region.
	*
	*/
	UFUNCTION(BlueprintCallable,
		meta = (FriendlyName = "SetRegion", Keywords = "country step num"),
		Category = iGLou_Country)

		void SetRegion(FString Region);


    /**
	 * Get The Number Of Countries Left.
     *
     * @returns             The size of RandomList.
     *
	 */
	UFUNCTION(BlueprintCallable,
              meta = (FriendlyName = "GetCountriesLeft", Keywords = "country position"),
              Category = iGLou_Country)
    
    int32 GetCountriesLeft();
    

    /**
	 * Get The Number Of Steps Done.
     *
     * @returns             The size of RandomList.
     *
	 */
	UFUNCTION(BlueprintCallable,
              meta = (FriendlyName = "GetStepNum", Keywords = "country step num"),
              Category = iGLou_Country)
    
    int32 GetStepNum();
    

	
	/**
	* Get country key in the current region by index.
	*
	* @returns             The country key at index.
	*
	*/
	FString GetRegionKey(int32 Index);


private:
    /**
	 * Generate a random array of integers, length equals the countries number.
     *
     * @param       Size    Both the array size and the max value.
     * @returns             The random interger array, each ranges between 0 and Size parameter.
     *
	 */
    void GenerateRandomList(int32 Size);
    
    void SaveCountryKeysToFile(FString FileName);

private:
    //Country maximum draw
    int32 CountryDraw = 249;
    //Array of random integers ranged between 0 and country nunmber
    TArray<int32>        RandomList;
    //Last random draw indices
    TArray<FString>      CountryAnswers;
    //Current Country Idx
    int32                CurrentCountryIdx = -1;
	//Current Region
	FString				 CurrentRegion = "";
    
    
    //KeyValues of the country in the Country Map (FJsonObject->Values)
    TArray<FString>         CountryKeys;
    //Whole Country data contained in a FJsonObject
    TSharedPtr<FJsonObject> CountryData;
	//KeyValues of the country in the Region
	TArray<FString>         RegionKeys;
	//Whole Region data contained in a FJsonObject
	TSharedPtr<FJsonObject> RegionData;
    
    //Pointer to the instance of CountryController
    static UCountryController* CountryControllerInstance;
};









































