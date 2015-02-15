

#include "GLOBE.h"
#include "CountryController.h"
#include "Kismet/KismetMathLibrary.h"
#include "SystemToolkit.h"
#include "DataToolkit.h"
#include "Json.h"

UCountryController* UCountryController::CountryControllerInstance = nullptr;

UCountryController::UCountryController(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
    
}



UCountryController* UCountryController::CreateCountryController(FString JsonStringCountry, FString JsonStringRegion)
{
    CountryControllerInstance = NewObject<UCountryController>();
    
    if( CountryControllerInstance )
    {
		if (!JsonStringCountry.IsEmpty())
		{
			CountryControllerInstance->InitializeCountries(JsonStringCountry);

			CountryControllerInstance->SetRegion(TEXT("World"));

			if (!JsonStringRegion.IsEmpty())
			{
				CountryControllerInstance->InitializeRegions(JsonStringRegion);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("[UCountryController][CreateCountryController] Bad JsonStringRegion!"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[UCountryController][CreateCountryController] Bad CountryJsonStringCountry!"));
		}
			
        return CountryControllerInstance;
    }
    else
    {
        UE_LOG(LogTemp,Error,TEXT("[UCountryController][CreateCountryController] creating CountryController instance failed!"));
        return NULL;
    }
}


void UCountryController::InitializeCountries(FString JsonString)
{
    //CountryData = UDataToolkit::GetJsonObjectFromString(Country::InternalData);
    CountryData = UDataToolkit::GetJsonObjectFromString(JsonString);
   
    if( CountryData.IsValid() )
    {
        CountryData->Values.GenerateKeyArray(CountryKeys);               
    }
    else
        UE_LOG(LogTemp,Error,TEXT("[UCountryController][CreateCountryController] CountryController could not be initialized!"));
}


void UCountryController::InitializeRegions(FString JsonString)
{
	RegionData = UDataToolkit::GetJsonObjectFromString(JsonString);
}


void UCountryController::InitDraw(int32 DrawNum)
{
    GenerateRandomList(DrawNum);
}


int32 UCountryController::Num()
{
	return RegionKeys.Num();
	
}

int32 UCountryController::WorldNum()
{	
	if( CountryData.IsValid() )
	{
	return CountryData->Values.Num();
	}

	else
	return 0;
}


FCountry UCountryController::GetCountryByIndex(int32 index)
{
    FCountry Country;
	if (index < WorldNum())
    {
        TSharedPtr<FJsonObject> JsonObject = CountryData->Values.FindRef(CountryKeys[index])->AsObject();
       Country = CountryHelper::ExtractCountry( JsonObject );
    }
    else
        UE_LOG(LogTemp,Error,TEXT("[UCountryController][GetCountryByIndex] index is out of bounds!") );
    
    return Country;
}

FCountry UCountryController::GetCountryByKey(FString Key)
{
    FCountry Country;
    if( CountryData.IsValid() )
    {
        TSharedPtr<FJsonObject> JsonObject = CountryData->Values.FindRef(Key)->AsObject();
        if( JsonObject.IsValid() )
        {
            Country = CountryHelper::ExtractCountry( JsonObject );
        }
        else
            UE_LOG(LogTemp,Error,TEXT("[UCountryController][GetCountryByIndex] JsonObject is invalid!") );
        
    }
    else
        UE_LOG(LogTemp,Error,TEXT("[UCountryController][GetCountryByIndex] CountryData is invalid!") );
    
    return Country;
}


TArray<FCountry> UCountryController::GetCountriesByKeys(TArray<FString> Keys)
{
    TArray<FCountry> Countries;
    for(auto k : Keys)
    {
        Countries.Add(GetCountryByKey(k));
    }
    return Countries;
}


int32 UCountryController::GetCountryPosition(FCountry Country)
{
    FString CountryKey = Country.CountryCodes[FCountry::ISO2];
    
    return GetCountryPositionByKey(CountryKey);
}


int32 UCountryController::GetCountryPositionByKey(FString CountryKey)
{
    int32 counter = 0;
    for(auto s : CountryKeys)
    {
        if( CountryKey.Compare(s) == 0 )
        {
            return counter;
        }
        counter++;
    }
    return -1;
}


FRegion UCountryController::GetRegion(FString RegionKey)
{
	TSharedPtr<FJsonObject> JsonRegion = RegionData->Values.FindRef(RegionKey)->AsObject();
	return RegionHelper::ExtractRegion(JsonRegion);
}


void UCountryController::SetRegion(FString Region)
{
	bool RegionInit = false;

	if (Region.Compare(TEXT("World"))== 0 )
	{
		RegionKeys = CountryKeys;
		RegionInit = true;
	}	
	else if(RegionData->HasField(Region))
	{				
		RegionKeys = RegionHelper::ExtractRegion(RegionData->GetObjectField(Region)).RegionCodes;				
		RegionInit = true;
	}
	if (RegionInit)
	{
		CurrentRegion = Region;
		UE_LOG(LogTemp, Warning, TEXT("[UCountryController][SetRegion] Region set to %s. Success!"), *Region);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[UCountryController][SetRegion] No Region %s found in DataBase!"), *Region);
	}	
}


FString UCountryController::Step()
{
    CurrentCountryIdx = RandomList.Pop();
    if(CurrentCountryIdx >= Num())
    {
        UE_LOG(LogTemp, Error, TEXT("Index was out of bound!") );
        return FString();
    }
    else
		return RegionKeys[CurrentCountryIdx];
}


void UCountryController::GenerateRandomList(int32 Size)
{
    RandomList.Empty();
    
	TArray<int32> idxList;
    
    for(int32 i = 0 ; i < Size ; i++)
    {
        idxList.Add(i);
    }
    
	for(int32 i = 0 ; i <  Size ; i++)
	{
        
		int32 randomIdx = FMath::RandRange( 0, idxList.Num() - 1);
        
		int32 value = idxList[randomIdx];
        
		RandomList.Add(value);
        
        idxList.RemoveAt(randomIdx);
	}
}


int32 UCountryController::GetCountriesLeft()
{
    return RandomList.Num();
}


int32 UCountryController::GetStepNum()
{
    return RegionKeys.Num() - RandomList.Num();
}


TArray<int32> UCountryController::GenerateDrawIndices(int32 UpperBound)
{
	//Generate 4 random country indices
	TArray<int32> indices;
	indices.SetNum(4);
	bool	notfound = true;

	for (int32 i = 0; i < 4; i++)
	{
		int32 random = FMath::RandRange(0, UpperBound - 1);

		indices[i] = random;

		while (notfound)
		{
			for (int32 j = 0; j <= i; j++)
			{
				if (indices[j] == random && j != i)
				{
					random = FMath::RandRange(0, UpperBound - 1);
					j = -1;
				}
				else
				{
					notfound = false;
					indices[i] = random;
				}
			}
		}
		notfound = true;
	}
	//Generate random position in returned vector for the current country index
	int32 random = FMath::RandRange(0, 3);
	bool alreadyDrawn = false;

	for (int32 i = 0; i < 4; i++)
	{
		if (CurrentCountryIdx == indices[i])
			alreadyDrawn = true;
	}

	if (!alreadyDrawn)
		indices[random] = CurrentCountryIdx;

	return indices;
}


TArray<FString> UCountryController::GenerateAnswerIndices(int32 UpperBound)
{
	TArray <int32> indices = GenerateDrawIndices(UpperBound);
    TArray<FString> CountryRef;    
    for(auto i : indices)
    {
		//CountryRef.Add(CountryKeys[i]);
		CountryRef.Add(GetRegionKey(i));
    }
    return CountryRef;
}



FString UCountryController::GetRegionKey(int32 Index)
{
	if (Index < RegionKeys.Num())
	{
		return RegionKeys[Index];
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[UCOuntryColtroller][GetRegionKey] Index %d Out-Of-Bound of RegionKeys"), Index);

		return "";
	}
	
}



void UCountryController::SaveCountryKeysToFile(FString FileName)
{
     int32 counter = 0;
     FString KeyList;
     for(auto k : CountryKeys)
     {
     if(counter < CountryDraw)
     {
     KeyList += TEXT("\n");
     KeyList += k;
     UE_LOG(LogTemp, Error, TEXT("%d  %s"), counter, *k);
     }
     counter++;
     }
     USystemToolkit::SaveStringToFile(KeyList, TEXT("CountryKeys") );
}






















