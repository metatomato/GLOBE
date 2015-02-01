

#pragma once

#include "Object.h"
#include "Json.h"
#include "DataToolkit.generated.h"

/**
 * 
 */
UCLASS()
class UDataToolkit : public UObject
{
	GENERATED_UCLASS_BODY()

    static TSharedPtr<FJsonObject> GetJsonObjectFromString(FString JsonString);
	
};
