

#pragma once

#include "EdGraph/EdGraphNode.h"
#include "BPToolkit.generated.h"

/**
 * 
 */
UCLASS()
class UBPToolkit : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

    //Function for object creation inside BP
	UFUNCTION(BlueprintPure, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", FriendlyName = "Create Object From Blueprint", CompactNodeTitle = "Create", Keywords = "new create blueprint"), Category = iGLou)
	static UObject* NewObjectFromBlueprint(UObject* WorldContextObject, TSubclassOf<UObject> UC);
	
};
